// The variables below the majority are from version 3 that was using two linked lists, version
// 4 and above use just memory, variables will be removed in a near future, what we want forst is make this
//  code compress well and fast using lz77 or something better for (1 << 15) slices of uncompressed data

int size_of_the_neddle_dl;
int size_of_uncompressed_stream_dl;
uint8_t *position_of_the_data_in_the_input__stream_dl;
uint8_t *position_of_the_data_in_the_output_stream_dl;

int size_of_alredy_saw_data_dl;

int bytes_left_in_the_input_uncompressed_stream_dl;

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
                                            __attribute__((unused)) int16_t len_of_matched_string_dl)
{

     // int bitcount__dl = 0;
     // int16_t temp_16_dl;
     int deslocado_2_dl;

     int i_dl;

     static uint8_t temp_dl[30];

     int *ptr_int_dl;

     static uint16_t meu_buf_16_dl[512];

     uint16_t *ptr_16_dl = meu_buf_16_dl;

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

          ptr_int_dl = (int *)&temp_dl[1];

          *ptr_int_dl = index_of_linked_list_starting_from_0_dl;

          len_of_input_to_encode_as_you_may_expect_dl = 1 + 1 + 1 + 1 + 1;

          for (i_dl = 0; i_dl < len_of_input_to_encode_as_you_may_expect_dl; i_dl++)
          {
               meu_buf_16_dl[i_dl] = (int16_t)temp_dl[i_dl];
          }
          meu_buf_16_dl[0] = 260;
     }

     (*bytes_encoded_so_far_dl) = 0;

     if (is_it_the_first_byte_to_encode_dl)
     {
          is_it_the_first_byte_to_encode_dl = false;
          bitposition_dl = 0;
          //(*bitposition_dl_interno_for_your_pleasure__) = 0;
          montagem_dl = 0;
          deslocador_dl = 0;
          (*montagem_dl_interno) = 0;
          (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl; // entao depois do ultimo item poe mais esta adicional, adiciona is itens pegos e adiciona mais o byte montagem, este é o final, e se for 0, precisa salvar o deslocador tambem pra nao saber se é 0, se deslocador for 0 nao precisa de montagem adicional
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl;
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl;
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl;
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl;
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl;
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl;
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl;
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
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
                    (*montagem_dl_interno) = montagem_dl;
                    deslocador_dl++;
                    (*last_item_is_required_dl) = true;
                    if (8 == deslocador_dl)
                    {
                         (*bytes_encoded_so_far_dl)++;
                         (*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
                         output_mem_dl++;
                         deslocador_dl = 0;
                         (*last_item_is_required_dl) = false;
                    }
                    bitposition_dl = 0;
                    break;
               }
          }
          ptr_16_dl++;
     }
     //(*bitposition_dl_interno_for_your_pleasure__) = bitposition_dl; // next bit to set when reconstructing the data
     return;
}
