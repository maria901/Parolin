// now entries for version 6, variables for version 5 and below we will removed only later, now we need to
// to implement features that run very well

int16_t past_position_location_dl;

int16_t size_real_for_number_of_characters_up_to_259_dl;

int8_t size_of_characters_adjusted_to_pass_dl;

int bit_buffer_left_dl; // can be used to check if not above the limit

int bit_buffer_left_dl_original; // dont change it ric...

int bit_position_11_jan_2022_v6_dl;

int bits_added_11_jan_2022_v6_dl;

uint8_t current_byte_being_generated_11_jan_2022_v6_byte_dl;

uint8_t *ptr_position_for_bit_memory_dl;

bool requires_last_byte_11_jan_2022_v6_dl;

uint8_t *position_of_the_data_in_the_output_stream_dl;

int compressed_and_encoded_bytes_available_11_jan_2022_v6_dl;

int number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl;

// The variables below the majority are from version 3 that was using two linked lists, version
// 4 and above use just memory, variables will be removed in a near future, what we want first is make this
// code compress well and fast using lz77 or something better for (1 << 15) slices of uncompressed data (old information)

int replacements_dl;

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

uint8_t prepare_byte_12_jan_2022_v6_dl(uint8_t string_size_dl_up_to_18, uint16_t position_on_the_passed_buffer_up_to_4096_12_bits_dl)
{
     int bit_position_12_jan_2022_v6_dl = 0;

     int mask_dl;

     int i_dl = 4;

     __attribute__((unused)) uint8_t exit_byte_dl = 0;

     __attribute__((unused)) uint8_t first__part_of_the_resulting_byte_the_string_size_dl = 0;

     __attribute__((unused)) uint8_t second_part_of_the_resulting_byte_the_position_in_the_input_buffer_dl = 0;

     assert(18 >= string_size_dl_up_to_18);

     assert(string_size_dl_up_to_18 >= 3);

     assert(4096 >= position_on_the_passed_buffer_up_to_4096_12_bits_dl);

     string_size_dl_up_to_18 -= 3; // it will be stored in the 4 bits

     for (i_dl = 0; i_dl < 4; i_dl++)
     {
          switch (i_dl)
          {

          case 0:

               mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    first__part_of_the_resulting_byte_the_string_size_dl |= mask_dl;
               }
               else
               {
                    first__part_of_the_resulting_byte_the_string_size_dl &= ~(mask_dl);
               }

               bit_position_12_jan_2022_v6_dl++;
               break;
          case 1:

               mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    first__part_of_the_resulting_byte_the_string_size_dl |= mask_dl;
               }
               else
               {
                    first__part_of_the_resulting_byte_the_string_size_dl &= ~(mask_dl);
               }

               bit_position_12_jan_2022_v6_dl++;
               break;
          case 2:

               mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    first__part_of_the_resulting_byte_the_string_size_dl |= mask_dl;
               }
               else
               {
                    first__part_of_the_resulting_byte_the_string_size_dl &= ~(mask_dl);
               }

               bit_position_12_jan_2022_v6_dl++;
               break;
          case 3:

               mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    first__part_of_the_resulting_byte_the_string_size_dl |= mask_dl;
               }
               else
               {
                    first__part_of_the_resulting_byte_the_string_size_dl &= ~(mask_dl);
               }

               bit_position_12_jan_2022_v6_dl++;
               break;
          }
     }

     
     for (i_dl = 0; i_dl < 12; i_dl++)
     {
          switch (i_dl)
          {

          case 0:

               mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    first__part_of_the_resulting_byte_the_string_size_dl |= mask_dl;
               }
               else
               {
                    first__part_of_the_resulting_byte_the_string_size_dl &= ~(mask_dl);
               }

               bit_position_12_jan_2022_v6_dl++;
               break;
          case 1:

               mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    first__part_of_the_resulting_byte_the_string_size_dl |= mask_dl;
               }
               else
               {
                    first__part_of_the_resulting_byte_the_string_size_dl &= ~(mask_dl);
               }

               bit_position_12_jan_2022_v6_dl++;
               break;
          case 2:

               mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    first__part_of_the_resulting_byte_the_string_size_dl |= mask_dl;
               }
               else
               {
                    first__part_of_the_resulting_byte_the_string_size_dl &= ~(mask_dl);
               }

               bit_position_12_jan_2022_v6_dl++;
               break;
          case 3:

               mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    first__part_of_the_resulting_byte_the_string_size_dl |= mask_dl;
               }
               else
               {
                    first__part_of_the_resulting_byte_the_string_size_dl &= ~(mask_dl);
               }

               bit_position_12_jan_2022_v6_dl++;
               break;
          }
     }
     
bit_position_12_jan_2022_v6_dl = 0;

     return exit_byte_dl;
}

/**
 * @brief It will add the bit to the array of bits that are required
 *
 * @param bit_value__11_jan_2022_v6_dl int it is 0 or 1 or an error will occur
 */
void encode_bit_11_jan_2022_v6_dl(int bit_value__11_jan_2022_v6_dl)
{
     uint8_t mask_dl;
     if (0 == bit_value__11_jan_2022_v6_dl)
     {
          ; // do nothing
     }
     else if (1 == bit_value__11_jan_2022_v6_dl)
     {
          ; // do nothing too
     }
     else
     {
          printf("Error 3738475657\n");
          pedro_dprintf(1001, "Error 3738475657, wrong bit value"); // same error value even if generated randonly in the keyboard, kkkkkkkkkkkkkkkkkkkkkkk, unbelievable...
          exit(27);
     }

     switch (bit_position_11_jan_2022_v6_dl)
     {
     case 0:

          mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

          if (1 == bit_value__11_jan_2022_v6_dl) // aqui agira vai ate 9
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl |= mask_dl;
          }
          else
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl &= ~(mask_dl);
          }
          requires_last_byte_11_jan_2022_v6_dl = true; // if incomplete last byte is required
          bits_added_11_jan_2022_v6_dl++;              // I dont know if will be used, but will keep it...
          bit_position_11_jan_2022_v6_dl++;            // advance to next bit
          break;
     case 1:

          mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

          if (1 == bit_value__11_jan_2022_v6_dl) // aqui agira vai ate 9
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl |= mask_dl;
          }
          else
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl &= ~(mask_dl);
          }
          requires_last_byte_11_jan_2022_v6_dl = true; // if incomplete last byte is required
          bits_added_11_jan_2022_v6_dl++;              // I dont know if will be used, but will keep it...
          bit_position_11_jan_2022_v6_dl++;            // advance to next bit
          break;
     case 2:

          mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

          if (1 == bit_value__11_jan_2022_v6_dl) // aqui agira vai ate 9
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl |= mask_dl;
          }
          else
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl &= ~(mask_dl);
          }
          requires_last_byte_11_jan_2022_v6_dl = true; // if incomplete last byte is required
          bits_added_11_jan_2022_v6_dl++;              // I dont know if will be used, but will keep it...
          bit_position_11_jan_2022_v6_dl++;            // advance to next bit
          break;
     case 3:

          mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

          if (1 == bit_value__11_jan_2022_v6_dl) // aqui agira vai ate 9
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl |= mask_dl;
          }
          else
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl &= ~(mask_dl);
          }
          requires_last_byte_11_jan_2022_v6_dl = true; // if incomplete last byte is required
          bits_added_11_jan_2022_v6_dl++;              // I dont know if will be used, but will keep it...
          bit_position_11_jan_2022_v6_dl++;            // advance to next bit
          break;
     case 4:

          mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

          if (1 == bit_value__11_jan_2022_v6_dl) // aqui agira vai ate 9
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl |= mask_dl;
          }
          else
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl &= ~(mask_dl);
          }
          requires_last_byte_11_jan_2022_v6_dl = true; // if incomplete last byte is required
          bits_added_11_jan_2022_v6_dl++;              // I dont know if will be used, but will keep it...
          bit_position_11_jan_2022_v6_dl++;            // advance to next bit
          break;
     case 5:

          mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

          if (1 == bit_value__11_jan_2022_v6_dl) // aqui agira vai ate 9
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl |= mask_dl;
          }
          else
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl &= ~(mask_dl);
          }
          requires_last_byte_11_jan_2022_v6_dl = true; // if incomplete last byte is required
          bits_added_11_jan_2022_v6_dl++;              // I dont know if will be used, but will keep it...
          bit_position_11_jan_2022_v6_dl++;            // advance to next bit
          break;
     case 6:

          mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

          if (1 == bit_value__11_jan_2022_v6_dl) // aqui agira vai ate 9
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl |= mask_dl;
          }
          else
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl &= ~(mask_dl);
          }
          requires_last_byte_11_jan_2022_v6_dl = true; // if incomplete last byte is required
          bits_added_11_jan_2022_v6_dl++;              // I dont know if will be used, but will keep it...
          bit_position_11_jan_2022_v6_dl++;            // advance to next bit
          break;
     case 7:

          mask_dl = (1 << bit_position_11_jan_2022_v6_dl);

          if (1 == bit_value__11_jan_2022_v6_dl) // aqui agira vai ate 9
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl |= mask_dl;
          }
          else
          {
               current_byte_being_generated_11_jan_2022_v6_byte_dl &= ~(mask_dl);
          }
          requires_last_byte_11_jan_2022_v6_dl = false; // if whole byte is filled no need for last byte being encode because there is no data on it yet
          bits_added_11_jan_2022_v6_dl++;               // I dont know if will be used, but will keep it...
          bit_position_11_jan_2022_v6_dl = 0;           // reset to 0 if above 7
          (*ptr_position_for_bit_memory_dl) = current_byte_being_generated_11_jan_2022_v6_byte_dl;
          ptr_position_for_bit_memory_dl++; // add byte to the buffer and advance to fill the next
          number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl++;
          break;
     }

     assert(0 <= bit_buffer_left_dl);
}
void __fastcall convert_8_bits_to_nine_bits_11_jan_2022_v6_dl(__attribute__((unused)) uint8_t *input_mem_dl,
                                                              __attribute__((unused)) uint8_t len_of_input_to_encode_as_you_may_expect_dl_, // limited to the maximum of 255 to avoid problems but can be used, what cannot be is 0
                                                              __attribute__((unused)) bool is_it_string_matched_in_past_buffer_dl,
                                                              __attribute__((unused)) uint16_t past_position_location_dl, // could be 15 bits instead of 16, but we will keep it, also can use 65 kb instead of 32 kb with ease for maximum compression later we will see it
                                                              __attribute__((unused)) uint8_t len_of_matched_string_dl)
{

     uint16_t len_of_input_to_encode_as_you_may_expect_dl = len_of_input_to_encode_as_you_may_expect_dl_;

     // len_of_input_to_encode_as_you_may_expect_dl += 4;

     /*

     in version 6 (11 jan 2022) we use

     one byte  (8  bits) to the size of the maximum string (255 it is ok for the moment)
     two bytes (16 bits) to the distance in the previous window buffer that is limited to 32 kb (1 << 15)

     it is enough for the moment, now encode it

     */
     uint8_t temp_ric_dl;
     uint16_t *ptr_uint16_dl;
     int i_dl;
     static uint8_t temp_dl[3 /* if in the future it was changed don't forget it ric... */];

     if (DEBUG_DL__)
          pedro_dprintf(0, "inside convert 8 a, size in input %d", len_of_input_to_encode_as_you_may_expect_dl);

     if (DEBUG_DL__)
          pedro_dprintf(0, "");

     if (DEBUG_DL__)
     {
          assert(0 && "parando");
     }

     if (false == is_it_string_matched_in_past_buffer_dl)
     {
          if (DEBUG_DL__)
               pedro_dprintf(0, "inside convert 8, mode is add plain string");

          if (DEBUG_DL__)
          {
               assert(0 && "inside function");
          }
          for (i_dl = 0; i_dl < len_of_input_to_encode_as_you_may_expect_dl; i_dl++)
          {
               // set the bit array with the required bits, one bit 0 for each plain character added
               encode_bit_11_jan_2022_v6_dl(0);
          }
     }
     else
     {
          replacements_dl++;
          encode_bit_11_jan_2022_v6_dl(1); // if encoded bit is one then it is a pointer to the previous data and size, each with 3 bytes

          if (DEBUG_DL__)
               pedro_dprintf(0, "inside convert 8, mode is add pointer");

          if (DEBUG_DL__)
          {
               assert(0 && "inside function");
          }
          assert(len_of_matched_string_dl);
          temp_dl[0] = len_of_matched_string_dl; //

          ptr_uint16_dl = (uint16_t *)&temp_dl[1];

          *ptr_uint16_dl = past_position_location_dl;

          len_of_input_to_encode_as_you_may_expect_dl = 3;
     }
     if (DEBUG_DL__)
          pedro_dprintf(0, "inside convert 8, size of data to add in the middle %d", len_of_input_to_encode_as_you_may_expect_dl);

     if (DEBUG_DL__)
     {
          assert(0 && "inside function");
     }
     for (i_dl = 0; i_dl < len_of_input_to_encode_as_you_may_expect_dl; i_dl++)
     {
          if (false == is_it_string_matched_in_past_buffer_dl)
          {
               ; //
               temp_ric_dl = input_mem_dl[i_dl];
          }
          else
          {
               ; //
               temp_ric_dl = temp_dl[i_dl];
          }
          (*position_of_the_data_in_the_output_stream_dl) = temp_ric_dl;
          position_of_the_data_in_the_output_stream_dl++;
     }
     compressed_and_encoded_bytes_available_11_jan_2022_v6_dl += len_of_input_to_encode_as_you_may_expect_dl;

     if (DEBUG_DL__)
          pedro_dprintf(0, "inside convert 8, size of buffer in exit %d", compressed_and_encoded_bytes_available_11_jan_2022_v6_dl);

     if (DEBUG_DL__)
     {
          assert(0 && "inside function");
     }

     return;
}
