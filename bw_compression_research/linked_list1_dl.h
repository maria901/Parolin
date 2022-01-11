// The variables below the majority are from version 3 that was using two linked lists, version
// 4 and above use just memory, variables will be removed in a near future, what we want forst is make this
//  code compress well and fast using lz77 or something better for (1 << 15) slices of uncompressed data

int replacements_dl;

int bytes_encoded_so_far_dl;
int size_of_the_neddle_dl;
int size_of_the_neddle_dl2;
int size_of_the_neddle_dl3;
int difference_of_the_new_loaded_data_dl;
int size_of_uncompressed_stream_dl;
int last_found_position_dl;
uint16_t size_of_last_found_position_dl;
bool last_item_is_required_dl;
bool already_found_with_larger_size_dl;
uint8_t *position_of_the_data_in_the_input__stream_dl;
uint8_t *position_of_the_data_in_the_input__stream_dl_copy;
uint8_t *position_of_the_data_in_the_input__stream_dl_original; // it start from here
uint8_t *position_of_the_data_in_the_output_stream_dl;
uint8_t montagem_last_byte_dl;

uint8_t best_match_dl[MAX_STRING_SEARCH_SIZE_DL__ + 10 /* for safety */];

int size_of_already_saw_data_dl;
int size_of_already_saw_data_dl_original;
int size_of_already_saw_data_dl2;

int bytes_left_in_the_input_uncompressed_stream_dl;
int bytes_left_in_the_input_uncompressed_stream_dl_original;

// here the encode from 8 bits to 9

bool copy_last_item_is_required__dl;
uint8_t last_item_or_montagem_dl;
uint8_t montagem_dl;
int bitposition_dl;
uint8_t deslocador_dl = 0;
uint8_t last_byte_encoded_value_dl; // only usefull for the encode, in the agregation the value will be in ht last byte of memory also in the linked list
bool is_it_the_first_byte_to_encode_dl;
void __fastcall convert_8_bits_to_nine_bits(__attribute__((unused)) uint8_t *input_mem_dl,
                                            __attribute__((unused)) int len_of_input_to_encode_as_you_may_expect_dl,
                                            __attribute__((unused)) bool is_it_string_matched_in_past_buffer_dl,
                                            __attribute__((unused)) int past_position_location_dl,
                                            __attribute__((unused)) uint16_t len_of_matched_string_dl)
{

     // int bitcount__dl = 0;
     // int16_t temp_16_dl;
     int deslocado_2_dl;

     int i_dl;

     static uint8_t temp_dl[30];

     int *ptr_int_dl;
     uint16_t *ptr_uint16_dl;

     static uint16_t meu_buf_16_dl[512];

     uint16_t *ptr_16_dl = meu_buf_16_dl;

     if (DEBUG_DL__)
          pedro_dprintf(0, "called convert_8_bits_to_nine_bits, on entering bytes on out buffer %d bytes", bytes_encoded_so_far_dl);

     if (DEBUG_DL__)
     {
          assert(0 && "parando");
     }

     if (false == is_it_string_matched_in_past_buffer_dl)
     {
          if (DEBUG_DL__)
               pedro_dprintf(0, "inside convert_8_bits_to_nine_bits, it is not an linked list entry");

          if (DEBUG_DL__)
          {
               ; // assert(0 && "inside function");
          }
          for (i_dl = 0; i_dl < len_of_input_to_encode_as_you_may_expect_dl; i_dl++)
          {
               meu_buf_16_dl[i_dl] = (int16_t)input_mem_dl[i_dl];
          }
     }
     else
     {
          if (DEBUG_DL__)
               pedro_dprintf(0, "inside convert_8_bits_to_nine_bits, it is an linked list entry");

          if (DEBUG_DL__)
          {
               ; // assert(0 && "inside function");
          }
          replacements_dl++;
          ptr_int_dl = (int *)&temp_dl[1];         // only 3 of the founr bytes are saved, since we will not address more than 16 million bytes
          ptr_uint16_dl = (uint16_t *)&temp_dl[4]; // need to check it for big endian or little endian support

          *ptr_int_dl = past_position_location_dl;

          *ptr_uint16_dl = len_of_matched_string_dl;

          len_of_input_to_encode_as_you_may_expect_dl = 1 + 3 + 2; // ok...

          for (i_dl = 0; i_dl < len_of_input_to_encode_as_you_may_expect_dl; i_dl++)
          {
               meu_buf_16_dl[i_dl] = (int16_t)temp_dl[i_dl];
          }
          meu_buf_16_dl[0] = 260; // this is ok...no need to change
     }

     if (is_it_the_first_byte_to_encode_dl)
     {
          is_it_the_first_byte_to_encode_dl = false;
          bitposition_dl = 0;
          //(*bitposition_dl_interno_for_your_pleasure__) = 0;
          montagem_dl = 0;
          deslocador_dl = 0;
          bytes_encoded_so_far_dl = 0;
          last_item_is_required_dl = false;
     }

     if (DEBUG_DL__)
          pedro_dprintf(0, "bytes to encode %d", len_of_input_to_encode_as_you_may_expect_dl);

     if (DEBUG_DL__)
     {
          assert(0 && "parando");
     }

     while (len_of_input_to_encode_as_you_may_expect_dl--)
     {
          deslocado_2_dl = 9;

          while (deslocado_2_dl--)
          {
               switch (bitposition_dl)
               {
               case 0:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl++;
                    break;
               case 1:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl++;
                    break;
               case 2:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl++;
                    break;
               case 3:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl++;
                    break;
               case 4:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl++;
                    break;
               case 5:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl++;
                    break;
               case 6:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl++;
                    break;
               case 7:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl++;
                    break;
               case 8:

                    if ((1 << bitposition_dl) & *ptr_16_dl) // aqui agira vai ate 9
                    {
                         montagem_dl |= (1 << deslocador_dl);
                    }
                    else
                    {
                         montagem_dl &= ~(1 << deslocador_dl);
                    }
                    montagem_last_byte_dl = montagem_dl;
                    deslocador_dl++;
                    last_item_is_required_dl = true;
                    if (8 == deslocador_dl)
                    {
                         bytes_encoded_so_far_dl++;
                         (*position_of_the_data_in_the_output_stream_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         position_of_the_data_in_the_output_stream_dl++;
                         deslocador_dl = 0;
                         last_item_is_required_dl = false;
                    }
                    bitposition_dl = 0;
                    break;
               }
          }
          ptr_16_dl++;
     }

     if (DEBUG_DL__)
          pedro_dprintf(0, "exiting convert_8_bits_to_nine_bits, bytes on out buffer %d bytes", bytes_encoded_so_far_dl);

     if (DEBUG_DL__)
     {
          assert(0 && "parando");
     }
     //(*bitposition_dl_interno_for_your_pleasure__) = bitposition_dl; // next bit to set when reconstructing the data
     return;
}
