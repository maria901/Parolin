
#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

#ifndef _MSC_VER
#include <stdbool.h>
#else
#define bool char
#define true 1
#define false 0

#define __attribute__(ricardo) /* unused */

#endif
#include <process.h>

// v14c variables (old version)

// v14b variables (old version)

// v13 variables (old version)

uint32_t amanda_need_to_flush_ric;

char temp_file_dl[MAX_PATH + 2]; // why not 1 ric?
char temp_file_dl2[MAX_PATH + 2];
char temp_file_dl3[MAX_PATH + 2];
char temp_file_dl4[MAX_PATH + 2];
char temp_file_dl5[MAX_PATH + 2];
char temp_file_dl6[MAX_PATH + 2];
char temp_file_dl7[MAX_PATH + 2];

FILE *out_file_dl = NULL;
FILE *out_file_dl2 = NULL;
FILE *out_file_dl3 = NULL;
FILE *out_file_dl4 = NULL;
FILE *out_file_dl5 = NULL;
FILE *out_file_dl6 = NULL;
FILE *out_file_dl7 = NULL;

/* wraps array index within array bounds (assumes value < 2 * limit) */ // borrowed
#define Wrap(value, limit) \
     (((value) < (limit)) ? (value) : ((value) - (limit)))

#include "bitfile.c" /* borrowed at once */

#define ENCODED 1 /* encoded string */
#define UNCODED 0 /* unencoded character */

//#define OFFSET_BITS 12
#define LENGTH_BITS 4

#define MAX_UNCODED (((2))) /* humble programmer */

bit_file_t *bfpOut;

int bytes_left_ar;
int bytes_in_buffer_ar;

int len_temp;

bool alternating_buffer_dl;

int8_t real_buf_ar[MAX_STRING_SEARCH_SIZE_DL__];
int8_t real_buf_temp_ar[MAX_STRING_SEARCH_SIZE_DL__];

int contador_pra_baixo_ar;
int contador_pra_baixo_2ar;

uint32_t bytes_in_strings_buffer_ar;

int ric_amanda_deslocador;

uint16_t ric_ready_to_be_encoded;

typedef struct ar_found_string_in_sliding_window__
{
     int8_t string_ar[18];
     int len_ricardo;
} ar_found_string_in_sliding_window;

ar_found_string_in_sliding_window strings_found_ar[V9C_INTERNAL_BUFFER_SIZE_DL_];

int8_t the_final_buffer_v12_ar;

int64_t count_of_bits_ar;

int bit_deslocador_v12_ar;

bool enable_desloca_a;

int i_a;

int pos_111_amanda;

int len_111_amanda;

int len_112_amanda;

int64_t achou_ric_amanda;

// v9 variables, for historical times, the embedded bugs too

int32_t adler_ar;

uint8_t temp_buffer_ar;

uint8_t slice_amanda_[MAX_STRING_SEARCH_SIZE_DL__];

int size_1_amanda, size_2_amanda, size_3_amanda;
//(old info, we are now in v14c)
uint8_t desloca_buffer_amanda4[V9C_INTERNAL_BUFFER_SIZE_DL_ + MAX_STRING_SEARCH_SIZE_DL__ /* will not use more than 3 for the moment (v12) */];

uint8_t desloca_buffer_amanda3[V9C_INTERNAL_BUFFER_SIZE_DL_ + MAX_STRING_SEARCH_SIZE_DL__ /* will not use more than 3 for the moment (v12) */];

uint8_t desloca_buffer_amanda2[V9C_INTERNAL_BUFFER_SIZE_DL_ + MAX_STRING_SEARCH_SIZE_DL__ /* will not use more than 3 for the moment (v12) */];

uint8_t desloca_buffer_amanda[(V9C_INTERNAL_BUFFER_SIZE_DL_ * 2) + MAX_STRING_SEARCH_SIZE_DL__ /* will not use more than 3 for the moment (v12) */];

uint8_t size_of_string_log_decode_dl(uint8_t index_dl);

uint8_t *ptr_1_amanda;

uint8_t *ptr_2_amanda;

uint8_t *ptr_3_amanda;

uint8_t largest_needle_already_in_buffer_dl[MAX_STRING_SEARCH_SIZE_DL__];

int largest_neddle_size_dl;

bool cannot_be_largest_string_size_dl;

int final_identifier_from_passed_buffers_dl; // current = 0, 0 = 1, 1 = 2 , 2 = 3, and so on

uint8_t adjusted_needle_dl;

uint32_t position_found_buffer_current_dl;
uint32_t position_found_buffer_0_dl;
uint32_t position_found_buffer_1_dl;
uint32_t position_found_buffer_2_dl;
uint8_t new_size_of_neddle_dl;
uint8_t new_size_of_neddle_dl1;
uint8_t max_size_string_from_buffer_final;
uint8_t max_size_string_from_buffer_current;
uint8_t max_size_string_from_buffer_0;
uint8_t max_size_string_from_buffer_1;
uint8_t max_size_string_from_buffer_2;
bool found_buffer_current_dl;
bool found_buffer_0_dl;
bool found_buffer_1_dl;
bool found_buffer_2_dl;

// now the magic begins the v8

int largest_size_found_on_previous_buffer_dl;
int size_of_the_neddle_dl2_b;

uint16_t bits_encoded_size_in_bytes_dl;
// variables for v7

unsigned int current_progress_dl = 0;

/**
 * @brief temp variable
 *
 */
int16_t size_of_compressed_buffer_dl;
int16_t size_of_compressed_buffer2_dl;
int size_of_compressed_buffer2_dl_int;

int size_got_of_neddle_dl;

// now entries for version 6, variables for version 5 and below we will removed only later, now we need to
// to implement features that run very well

int32_t past_position_location_dl;

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

uint32_t number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl;

// The variables below the majority are from version 3 that was using two linked lists, version
// 4 and above use just memory, variables will be removed in a near future, what we want first is make this
// code compress well and fast using lz77 or something better for (1 << 15) slices of uncompressed data (old information)

int replacements_dl;

int size_of_the_neddle_dl;
int size_of_the_neddle_dl2;
int size_of_the_neddle_dl3;
int difference_of_the_new_loaded_data_dl;
// int size_of_uncompressed_stream_dl;
int last_found_position_dl;
uint16_t size_of_last_found_position_dl;
bool last_item_is_required_dl;
bool already_found_with_larger_size_dl;
uint8_t *position_of_the_data_in_the_input__stream_dl;
uint8_t *position_of_the_data_in_the_input__stream_dl_copy_3;
uint8_t *position_of_the_data_in_the_input__stream_dl_copy;
uint8_t *position_of_the_data_in_the_input__stream_dl_original; // it start from here

uint8_t montagem_last_byte_dl;

uint8_t best_match_dl[MAX_STRING_SEARCH_SIZE_DL__ + 10 /* for safety */];

int size_of_already_saw_data_dl;
int size_of_already_saw_data_dl_original;
int size_of_already_saw_data_dl2;

int bytes_left_in_the_input_uncompressed_stream_dl, bytes_left_in_the_input_uncompressed_stream_dl_copy;
int bytes_left_in_the_input_uncompressed_stream_dl_original;

// here the encode from 8 bits to 9

bool copy_last_item_is_required__dl;
uint8_t last_item_or_montagem_dl;
uint8_t montagem_dl;
int bitposition_dl;
uint8_t deslocador_dl = 0;
uint8_t last_byte_encoded_value_dl; // only usefull for the encode, in the agregation the value will be in ht last byte of memory also in the linked list
bool is_it_the_first_byte_to_encode_dl;

// Borrowed from my own sources, the rspcutil

int invertbits32(int value)
{

     int out;
     char *input = (char *)&value;
     char *output = (char *)&out;
     output[0] = input[3];
     output[1] = input[2];
     output[2] = input[1];
     output[3] = input[0];
     return out;
}

short invertbits16(short value)
{

     short out;
     char *input = (char *)&value;
     char *output = (char *)&out;
     output[0] = input[1];
     output[1] = input[0];

     return out;
}

/**
 * @brief developed by me at jan 2022
 *
 * @param value
 * @return uint16_t
 */
uint16_t
invertbits16_uint16_t(uint16_t value)
{

     uint16_t out;
     char *input = (char *)&value;
     char *output = (char *)&out;
     output[0] = input[1];
     output[1] = input[0];

     return out;
}

uint16_t prepare_unsigned_short_int_12_jan_2022_v6_dl(uint8_t string_size_dl_up_to_18, uint32_t position_on_the_passed_buffer_up_to_4096_12_bits_dl

#if 1
                                                      ,
                                                      int *th13_bit_i,
                                                      int *th14_bit_i,
                                                      int *th15_bit_i,
                                                      int *th16_bit_i
#endif

)
{

     // assert(0 && "you are not authorized to use this function, period...");
     // exit
     int pois_eh_dl = 0;

     unsigned int mask_dl;

     int i_dl;

     uint16_t resulting_short_dl = 0;

     pedro_dprintf(-1, "address inside idiot %hi", position_on_the_passed_buffer_up_to_4096_12_bits_dl);

     assert(100 >= string_size_dl_up_to_18);

     assert(string_size_dl_up_to_18 >= 3);

     /*
          if(4095 < position_on_the_passed_buffer_up_to_4096_12_bits_dl)
          {
               position_on_the_passed_buffer_up_to_4096_12_bits_dl = 4095;
          }
     */

     pedro_dprintf(-1, "%d", position_on_the_passed_buffer_up_to_4096_12_bits_dl);
     // assert(V9C_INTERNAL_BUFFER_SIZE_DL_ >= position_on_the_passed_buffer_up_to_4096_12_bits_dl);

     string_size_dl_up_to_18 = size_of_string_log_decode_dl(string_size_dl_up_to_18);

     string_size_dl_up_to_18 -= 3; // keep it here forever, it will be stored in the 4 bits
     // pedro_dprintf(0, )

     for (i_dl = 0; i_dl <

#if 1
                    17 + 2 + 1 + 1 /* is it Ric son of Euclid? */
#endif

          ;
          i_dl++)
     {
          switch (i_dl)
          {

          case 0:

               mask_dl = (1 << pois_eh_dl);
               pedro_dprintf(-1, "valor de mask %d des %d", mask_dl, pois_eh_dl);
               if (mask_dl & string_size_dl_up_to_18)
               {
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 0 %04x", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 1:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 1 %04x", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 2:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 2 %04x", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 3:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & string_size_dl_up_to_18)
               {
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 3 %04x", resulting_short_dl);
               pois_eh_dl++;
               pois_eh_dl = 0;
               break;

               // 88888888888888888888888888888888888888888888888888888
               // next 12 bits

          case 4:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 4 %04x", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 5:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 5 %04x", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 6:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 6 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 7:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 7 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 8:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 8 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 9:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 9 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 10:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 10 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 11:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 11 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 12:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 12 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 13:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 13 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 14:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }
               pedro_dprintf(-2, "resulting short bit 14 %hi", resulting_short_dl);
               pois_eh_dl++;
               break;
          case 15:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl |= mask_dl;
               }
               else
               {
                    mask_dl = (1 << (pois_eh_dl + 4));
                    resulting_short_dl &= ~(mask_dl);
               }

               pois_eh_dl++;
               break;

#if 1

          case 16:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    *th13_bit_i = 1;
               }
               else
               {
                    *th13_bit_i = 0;
               }

               pois_eh_dl++;
               break;

          case 17:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    *th14_bit_i = 1;
               }
               else
               {
                    *th14_bit_i = 0;
               }

               pois_eh_dl++;
               break;
          case 18:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    *th15_bit_i = 1;
               }
               else
               {
                    *th15_bit_i = 0;
               }

               pois_eh_dl++;
               break;
          case 19:

               mask_dl = (1 << pois_eh_dl);

               if (mask_dl & position_on_the_passed_buffer_up_to_4096_12_bits_dl)
               {
                    *th16_bit_i = 1;
               }
               else
               {
                    *th16_bit_i = 0;
               }

               pois_eh_dl++;
               break;

#endif
          }
     }
     pedro_dprintf(-2, "resulting short f 2 %04x", resulting_short_dl);

     // return 0;
     return resulting_short_dl;
}

/**
 * @brief It will add the bit to the array of bits that are required
 *
 * @param bit_value__11_jan_2022_v6_dl int it is 0 or 1 or an error will occur
 */
void encode_bit_11_jan_2022_v6_dl(int bit_value__11_jan_2022_v6_dl)
{
     pedro_dprintf(-1, "entrou bem %d", bit_position_11_jan_2022_v6_dl);
     // assert(0);
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
                                                        // (*ptr_position_for_bit_memory_dl) = current_byte_being_generated_11_jan_2022_v6_byte_dl;
                                                        // ptr_position_for_bit_memory_dl++; // add byte to the buffer and advance to fill the next
          putc((int)current_byte_being_generated_11_jan_2022_v6_byte_dl, out_file_dl3);

          // number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl++;

          pedro_dprintf(-1, "viu %d", number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl);
          break;
     }
     // assert(0 && "saiu amor");
     assert(0 <= bit_buffer_left_dl);
}

void __fastcall convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(__attribute__((unused)) uint8_t *input_mem_dl,
                                                              __attribute__((unused)) uint8_t len_of_input_to_encode_as_you_may_expect_dl_, //
                                                              __attribute__((unused)) bool is_it_string_matched_in_past_buffer_dl,
                                                              __attribute__((unused)) uint32_t past_position_location_dl, //
                                                              __attribute__((unused)) uint8_t len_of_matched_string_dl,
                                                              __attribute__((unused)) bool using_previous_buffer_dl)
{

     int th13____, th14____, th15____, th16____;
     uint16_t len_of_input_to_encode_as_you_may_expect_dl = len_of_input_to_encode_as_you_may_expect_dl_;

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
     // assert(0);
     if (false == is_it_string_matched_in_past_buffer_dl)
     {
          if (DEBUG_DL__)
               pedro_dprintf(0, "inside convert 8, mode is add plain string, len %d", len_of_input_to_encode_as_you_may_expect_dl);

          if (DEBUG_DL__)
          {
               assert(0 && "inside function");
          }
          /*
                    BitFilePutBit(UNCODED, bfpOut);
                    BitFilePutChar((int)input_mem_dl[0], bfpOut);
                    */
          // return;

          assert(1 == len_of_input_to_encode_as_you_may_expect_dl);
          for (i_dl = 0; i_dl < len_of_input_to_encode_as_you_may_expect_dl; i_dl++)
          {
               // set the bit array with the required bits, one bit 0 for each plain character added
               encode_bit_11_jan_2022_v6_dl(0);
          }
          // assert(0 && "encode byte");
     }
     else
     {
          // return;
          replacements_dl++;
          encode_bit_11_jan_2022_v6_dl(1); // if encoded bit is one then it is a pointer to the previous data and size (v10 not working this moment)

          // encode_bit_11_jan_2022_v6_dl(1); // em honra do Deus r?

          if (DEBUG_DL__)
               pedro_dprintf(0, "inside convert 8, mode is add pointer");

          if (DEBUG_DL__)
          {
               assert(0 && "inside function");
          }
          // assert(len_of_matched_string_dl);
          // temp_dl[0] = len_of_matched_string_dl; //

          ptr_uint16_dl = (uint16_t *)&temp_dl[0];

          *ptr_uint16_dl = prepare_unsigned_short_int_12_jan_2022_v6_dl(len_of_matched_string_dl,
                                                                        past_position_location_dl

#if 1
                                                                        ,
                                                                        /*  */ &th13____,
                                                                        /*  */ &th14____,
                                                                        /*  */ &th15____,
                                                                        /*  */ &th16____
#endif

          );

          //
          // encode_bit_11_jan_2022_v6_dl(th13____);

#if 1
          encode_bit_11_jan_2022_v6_dl(th13____);
          encode_bit_11_jan_2022_v6_dl(th14____);
          encode_bit_11_jan_2022_v6_dl(th15____);
          // encode_bit_11_jan_2022_v6_dl(th16____);
#endif

          if (is_it_little_ric_endian_ar)
          {
               ; // just pass by
          }
          else
          {
               *ptr_uint16_dl = invertbits16_uint16_t(*ptr_uint16_dl);
          }

          pedro_dprintf(-1, "encoded int16_t to save %i len e address %d %d", *ptr_uint16_dl,
                        (int)len_of_matched_string_dl,
                        (int)past_position_location_dl);

          len_of_input_to_encode_as_you_may_expect_dl = 2;
          /*
                    unsigned int offset_ar = past_position_location_dl;
                    unsigned int adjustedLen = len_of_matched_string_dl;// - 3;

                    assert(3 <= adjustedLen);

                    BitFilePutBit(ENCODED, bfpOut);
                    BitFilePutBitsNum(bfpOut, &offset_ar, OFFSET_BITS,
                                      sizeof(unsigned int));
                    BitFilePutBitsNum(bfpOut, &adjustedLen, LENGTH_BITS,
                                      sizeof(unsigned int));

                    return;
                    */
     }
     if (DEBUG_DL__)
          pedro_dprintf(0, "inside convert 8, size of data to add in the middle %d", len_of_input_to_encode_as_you_may_expect_dl);

     if (DEBUG_DL__)
     {
          assert(0 && "inside function");
     }
     for (i_dl = 0; i_dl < len_of_input_to_encode_as_you_may_expect_dl; i_dl++)
     {
          uint8_t temp_ric_dl;
          if (false == is_it_string_matched_in_past_buffer_dl)
          {
               ; //
               temp_ric_dl = input_mem_dl[i_dl];
               putc((int)temp_ric_dl, out_file_dl2);
          }
          else
          {
               ; //
               temp_ric_dl = temp_dl[i_dl];
               putc((int)temp_ric_dl, out_file_dl4);
          }
          //(*position_of_the_data_in_the_output_stream_dl) = temp_ric_dl;
          // position_of_the_data_in_the_output_stream_dl++;

          // aqui ta resolvido

          // amanda_need_to_flush_ric++;
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

uint8_t size_of_string_log_get_dl(uint8_t index_dl)
{
     return index_dl;
     /*
     uint8_t array_in_dl[255] = {
     0,  // 0
     0,  // 1
     0,  // 2
     3,  // 3
     5,  // 4
     7,  // 5
     9,  // 6
     12, // 7
     15, // 8
     19, // 9
     24, // 10
     30, // 11
     38, // 12
     45, // 13
     55, // 14
     100 // 15
     };
     */
     switch (index_dl)
     {
          // case  0,  // 0
          //    0,  // 1
          //  0,  // 2
     case 3: //,  // 3

          return 3;

     case 4:
          return 4; //,  // 4

     case 5:
          return 5; //,        // 5
     case 6:

          return 6; //,    // 6
     case 7:

          return 12; //,       // 7
     case 8:

          return 15; //,   // 8
     case 9:

          return 19; //,   // 9
     case 10:

          return 24; //,        // 10
     case 11:

          return 30; //,        // 11
     case 12:

          return 38; //,    // 12
     case 13:

          return 45; //,        // 13
     case 14:

          return 55; //,        // 14
     case 15:

          return 100; //        // 15
     }
     return 3;
}

uint8_t size_of_string_log_decode_dl(uint8_t index_dl)
{
     return index_dl;
     /*
     uint8_t array_in_dl[255] = {
     0,  // 0
     0,  // 1
     0,  // 2
     3,  // 3
     5,  // 4
     7,  // 5
     9,  // 6
     12, // 7
     15, // 8
     19, // 9
     24, // 10
     30, // 11
     38, // 12
     45, // 13
     55, // 14
     100 // 15
     };
     */
     switch (index_dl)
     {
          // case  0,  // 0
          //    0,  // 1
          //  0,  // 2
     case 3: //,  // 3

          return 3;

     case 4:
          return 4; //,  // 4

     case 5:
          return 5; //,        // 5
     case 6:

          return 6; //,    // 6
     case 12:

          return 7; //,       // 7
     case 15:

          return 8; //,   // 8
     case 19:

          return 9; //,   // 9
     case 24:

          return 10; //,        // 10
     case 30:

          return 11; //,        // 11
     case 38:

          return 12; //,    // 12
     case 45:

          return 13; //,        // 13
     case 55:

          return 14; //,        // 14
     case 100:

          return 15; //        // 15
     }
     return 3;
}
/***************************************************************************
 * This data structure stores an encoded string in (offset, length) format.
 * The actual encoded string is stored using OFFSET_BITS for the offset and
 * LENGTH_BITS for the length.
 ***************************************************************************/
typedef struct encoded_string_t
{
     unsigned int offset; /* offset to start of longest match */
     unsigned int length; /* length of longest match */
} encoded_string_t;

/****************************************************************************
 *   Function   : FindMatch
 *   Description: This function will search through the slidingWindow
 *                dictionary for the longest sequence matching the MAX_CODED
 *                long string stored in uncodedLookahed.
 *   Parameters : windowHead - head of sliding window
 *                uncodedHead - head of uncoded lookahead buffer
 *   Effects    : None
 *   Returned   : The sliding window index where the match starts and the
 *                length of the match.  If there is no match a length of
 *                zero will be returned.
 ****************************************************************************/
encoded_string_t FindMatch(const unsigned int windowHead,
                           unsigned int uncodedHead, /*




                            */

                           /*




                           */
                           uint8_t *uncodedLookahead_amanda,
                           uint8_t *slidingWindow_ricardo)
{
     encoded_string_t matchData;
     unsigned int i;
     unsigned int j;

     matchData.length = 0;
     matchData.offset = 0;
     i = windowHead; /* start at the beginning of the sliding window */
     j = 0;

     while (12)
     {
          if (slidingWindow_ricardo[i] == uncodedLookahead_amanda[uncodedHead])
          {
               /* we matched one. how many more match? */
               j = 1;

               while (slidingWindow_ricardo[Wrap((i + j), (((V9C_INTERNAL_BUFFER_SIZE_DL_))))] ==
                      uncodedLookahead_amanda[Wrap((uncodedHead + j), ((MAX_STRING_SEARCH_SIZE_DL__) + MAX_UNCODED))])
               {
                    if (j >= ((MAX_STRING_SEARCH_SIZE_DL__) + MAX_UNCODED))
                    {
                         break;
                    }
                    j++;
               }

               if (j > matchData.length)
               {
                    matchData.length = j;
                    matchData.offset = i;
               }
          }

          if (j >= ((MAX_STRING_SEARCH_SIZE_DL__) + MAX_UNCODED))
          {
               matchData.length = ((MAX_STRING_SEARCH_SIZE_DL__) + MAX_UNCODED);
               break;
          }

          i = Wrap((i + 1), (V9C_INTERNAL_BUFFER_SIZE_DL_));
          if (i == windowHead)
          {
               /* we wrapped around */
               break;
          }
     }

     return matchData;
}

/**
 * @brief if found it will already return the largest possible size, ok (v8 fixed) (also v9)
 *
 * @param buffer_dl the input buffer being used, may range from 0 to 2 for the moment or also the current
 * @param found_dl if it was found or not
 * @param max_size_of_string_found_dl maximum size found, only important if found
 * @param position_found the position on the buffer where it was found, largest possible string size, of course, this is what this function does
 * @param pos_ori_current_buffer_dl the position where the needle need to be copied from the current buffer, to search, of course
 */
void process_search_in_passed_buffers_at_once_dl(uint8_t *buffer_dl,
                                                 bool *found_dl,
                                                 uint8_t *max_size_of_string_found_dl,
                                                 uint32_t *position_found,
                                                 uint8_t *pos_ori_current_buffer_dl,
                                                 uint8_t *new_size_of_neddle_dl)
{

     __attribute__((unused /*ricardo*/)) encoded_string_t
         matchData_ricava = FindMatch(/*





            */ 0,
                                      /*







                                      */
                                      0, pos_ori_current_buffer_dl,
                                      buffer_dl);

     if (3 <= matchData_ricava.length)
     {
          *position_found = matchData_ricava.offset;

          *found_dl = true;

          *max_size_of_string_found_dl = matchData_ricava.length; // correct, need to check (v8 fixed)

          *new_size_of_neddle_dl = matchData_ricava.length;
          return;
     }
     else
     {
          // *found_dl = true; sacanagem... como sempre
          *found_dl = false;
          return;
     }

     return; // for safety...
}
/**
 * @brief if found it will already return the largest possible size, ok (v8 fixed) (also v9)
 *
 * @param current_buffer_dl the input buffer being used, always need to be the current
 * @param found_dl if it was found or not
 * @param max_size_of_string_found_dl maximum size found, only important if found
 * @param position_found the position on the buffer where it was found, largest possible string size, of course, this is what this function does
 * @param pos_ori_current_buffer_dl the position where the needle need to be copied from the current buffer, to search, of course
 * @param already_saw_bytes_cannot_adjust_without_adding_it_dl the limit to search the neddle on the current buffer, cannot be adjusted without adding the bytes to the compressed stream
 * @param adjusted_needle_dl the value to adjust the pointers and variables
 */
void process_search_in_current_buffer_at_once_dl(uint8_t *current_buffer_dl,
                                                 bool *found_dl,
                                                 uint8_t *max_size_of_string_found_dl,
                                                 uint16_t *position_found,
                                                 uint8_t *pos_ori_current_buffer_dl,
                                                 int already_saw_bytes_cannot_adjust_without_adding_it_dl,
                                                 uint8_t *adjusted_needle_dl)
{

     static uint8_t needle_S2_buf_dl_copy[MAX_STRING_SEARCH_SIZE_DL__];

     uint8_t size_of_the_neddle_dl2_b = MIN_STRING_SEARCH_SIZE_DL__,
             size_of_the_neddle_dl2_b_real;

     *adjusted_needle_dl = MIN_STRING_SEARCH_SIZE_DL__;

     int got_value_to_fix_dl;

     int64_t result_S2_temp_dl = -1;

     *found_dl = false;

try_again_magician_ric1:;

     if (MAX_STRING_SEARCH_SIZE_DL__ > size_of_the_neddle_dl2_b)
     {
          size_of_the_neddle_dl2_b += STRING_PASS_SIZE_DL__;

          if (MAX_STRING_SEARCH_SIZE_DL__ < size_of_the_neddle_dl2_b) // perfet...
          {
               size_of_the_neddle_dl2_b = MAX_STRING_SEARCH_SIZE_DL__;
          }

          size_of_the_neddle_dl2_b_real = size_of_string_log_get_dl(size_of_the_neddle_dl2_b);

          memcpy(needle_S2_buf_dl_copy, pos_ori_current_buffer_dl, size_of_the_neddle_dl2_b_real);

          if (DEBUG_DL__)
               pedro_dprintf(0, "available size %d %d", (int)(pos_ori_current_buffer_dl - current_buffer_dl),
                             already_saw_bytes_cannot_adjust_without_adding_it_dl);

          got_value_to_fix_dl = (int)(pos_ori_current_buffer_dl - current_buffer_dl);

          got_value_to_fix_dl -= 2;

          if (0 > got_value_to_fix_dl)
          {
               got_value_to_fix_dl = 0;
          }

          if (DEBUG_DL__)
          {
               assert(0 && "parando");
          }

          // now search again
          result_S2_temp_dl = mem_search_dl(current_buffer_dl,
                                            got_value_to_fix_dl,
                                            needle_S2_buf_dl_copy,
                                            size_of_the_neddle_dl2_b_real,
                                            0);

          if (-1 == result_S2_temp_dl)
          {
               ; // go try the standard method, but we already have thje largest size got in previous buffer
          }
          else
          {

               *position_found = result_S2_temp_dl;

               *found_dl = true;

               *max_size_of_string_found_dl = size_of_the_neddle_dl2_b_real; // correct, need to check (v8 fixed)
               *adjusted_needle_dl = size_of_the_neddle_dl2_b_real;
               goto try_again_magician_ric1;
          }
     }
     else
     {
          ; // largest_size_found_on_previous_buffer_dl got the largest size got from buffer previous (v8)
     }

     if (false == *found_dl)
     {
          *adjusted_needle_dl = MIN_STRING_SEARCH_SIZE_DL__;
     }
     //*adjusted_needle_dl -= MIN_STRING_SEARCH_SIZE_DL__;
}

/**
 * To print a simple message
 *
 * @param format and ... the printf like parameters
 *
 */
int mprintf_S2_com_retorno_se_for_6_eh_sim__arp(char *format, ...)
{
     int return_value_dl;
     char *buffer = calloc(1, 10000); // for multithread sake
     va_list amanda_do_ricardo;

     va_start(amanda_do_ricardo, format);
     vsprintf(buffer, format, amanda_do_ricardo);
     va_end(amanda_do_ricardo);
     return_value_dl = MessageBox(0, buffer, "Ric Pergunta...", MB_YESNO | MB_ICONERROR | MB_SYSTEMMODAL);
     free(buffer);
     return return_value_dl;
}

/**
 * To print a simple message
 *
 * @param format and ... the printf like parameters
 *
 */
void mprintf_S2_sem_retorno__arp(char *format, ...)
{
     char *buffer = calloc(1, 10000); // for multithread sake
     va_list amanda_do_ricardo;

     va_start(amanda_do_ricardo, format);
     vsprintf(buffer, format, amanda_do_ricardo);
     va_end(amanda_do_ricardo);
     MessageBox(0, buffer, "Ric Informa...", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
     free(buffer);
}

/**
 * @brief will tell in pedro_dprintf if the files are equal, if not in what position it started to differ, my own
 *
 * @param file_1_dl
 * @param file_53_dl
 * @param min_size_dl -1 if whole file, size limit to check otherwise
 */
void is_equal_ric_file_to_file_dl(char *file_1_dl,
                                  char *file_53_dl,
                                  __attribute__((unused)) int64_t min_size_dl)
{

#define MY_SIZE_DL__14_JAN_ (1 << 17)

     // int return_value_dl = 0; will keep it

     int64_t size_1_dl, size_2_dl,
         position_dl = 0,
         limit_dl = min_size_dl;

     (void)limit_dl;

     uint8_t *buf1_dl = malloc(MY_SIZE_DL__14_JAN_);
     uint8_t *buf2_dl = malloc(MY_SIZE_DL__14_JAN_);

     uint8_t *ptr1_dl;
     uint8_t *ptr2_dl;

     uint32_t u_len1_dl, u_len2_dl, counter_dl;

     FILE *file_1_ric_dl = fopen(file_1_dl, "rb");
     FILE *file_2_ric_dl = fopen(file_53_dl, "rb");

     pedro_dprintf(0, "begin-------------------");
     //               "end---------------------"

     if (NULL == file_1_ric_dl)
     {
          pedro_dprintf(0, "Cannot open file 1 '%s'", file_1_dl);
          goto sai_1_dl;
     }
     if (NULL == file_2_ric_dl)
     {
          pedro_dprintf(0, "Cannot open file 2 '%s'", file_53_dl);
          goto sai_1_dl;
     }

     _fseeki64(file_1_ric_dl, 0, SEEK_END);

     size_1_dl = _ftelli64(file_1_ric_dl);

     _fseeki64(file_1_ric_dl, 0, SEEK_SET);

     pedro_dprintf(0, "file 1 size %lld", size_1_dl);

     _fseeki64(file_2_ric_dl, 0, SEEK_END);

     size_2_dl = _ftelli64(file_2_ric_dl);

     _fseeki64(file_2_ric_dl, 0, SEEK_SET);

     pedro_dprintf(0, "file 2 size %lld", size_2_dl);

     if (size_1_dl != size_2_dl)
     {
          goto sai_1_dl;
     }

     if (-1 == limit_dl)
     {
          limit_dl = size_1_dl;
     }

again_ric_my_frined_dl:;

     u_len1_dl = fread(buf1_dl, 1, min(limit_dl, MY_SIZE_DL__14_JAN_), file_1_ric_dl);

     if (0 == u_len1_dl)
     {
          if (0 != limit_dl)
               pedro_dprintf(0, "error readinf file 1");
          else
               pedro_dprintf(0, "files are equal");

          goto sai_1_dl;
     }
     u_len2_dl = fread(buf2_dl, 1, min(limit_dl, MY_SIZE_DL__14_JAN_), file_2_ric_dl);

     if (0 == u_len2_dl)
     {
          pedro_dprintf(0, "error, cannot be 0 here, error reading file 2");
          goto sai_1_dl;
     }

     limit_dl -= u_len1_dl;

     counter_dl = u_len1_dl;

     ptr1_dl = buf1_dl;

     ptr2_dl = buf2_dl;

     while (counter_dl--)
     {
          if (*ptr1_dl++ != *ptr2_dl++)
          {
               pedro_dprintf(0, "files don't match at position %lld", position_dl);
               goto sai_1_dl;
          }
          position_dl++;
     }

     goto again_ric_my_frined_dl;

sai_1_dl:;

     free(buf1_dl);
     buf1_dl = NULL;
     free(buf2_dl);
     buf2_dl = NULL;

     if (file_1_ric_dl)
          fclose(file_1_ric_dl);
     if (file_2_ric_dl)
          fclose(file_2_ric_dl);
     pedro_dprintf(0, "end---------------------");
     return;
}

/**
 * @brief dump buffer to disk
 *
 * @param file_dl
 * @param buffer_dl
 * @param size_dl
 */
void buffer_to_file_dl(char *file_dl,
                       uint8_t *buffer_dl,
                       uint32_t size_dl)
{

     FILE *file_1_ric_dl = fopen(file_dl, "wb");

     if (NULL == file_1_ric_dl)
     {
          pedro_dprintf(0, "file to save that failed %s", file_dl);
          assert(0 && "buffer to file failed");
     }

     fwrite(buffer_dl, 1, size_dl, file_1_ric_dl);
}

void remove_string_ar5(uint8_t *needle_a, int position_a, int needle_len_a, uint8_t *input_a, uint8_t *output_a)
{
     uint8_t *a_a;
     uint8_t *b_a;
     __attribute__((unused)) uint8_t *c_a = needle_a;
     // desloca_buffer_amanda

     int restantes_a = V9C_INTERNAL_BUFFER_SIZE_DL_;

     a_a = desloca_buffer_amanda;
     b_a = input_a;
     for (i_a = 0; i_a < position_a; i_a++)
     {
          a_a[i_a] = b_a[i_a];
     }
     a_a += position_a;
     b_a += position_a;
     b_a += needle_len_a;
     restantes_a -= position_a;
     restantes_a -= needle_len_a;

     for (i_a = 0; i_a < restantes_a; i_a++)
     {
          *a_a++ = *b_a++;
     }
     pedro_dprintf(-1, "2 tamanho %d %d", b_a - input_a, restantes_a);
     for (i_a = 0; i_a < needle_len_a; i_a++)
     {
          *a_a++ = *c_a++;
     }
     pedro_dprintf(-1, "tamanho %d", a_a - desloca_buffer_amanda);
     // assert(0);
     memcpy(output_a,
            desloca_buffer_amanda,
            V9C_INTERNAL_BUFFER_SIZE_DL_);
}
void remove_string_ar3(uint8_t *needle_a, __attribute__((unused)) int position_a, int needle_len_a, uint8_t *input_a, uint8_t *output_a)
{

     __attribute__((unused)) uint8_t *c_a = needle_a;
     // desloca_buffer_amanda

     __attribute__((unused)) int restantes_a = V9C_INTERNAL_BUFFER_SIZE_DL_;

     memcpy(desloca_buffer_amanda,
            input_a + needle_len_a, V9C_INTERNAL_BUFFER_SIZE_DL_);

     memcpy(desloca_buffer_amanda +
                (V9C_INTERNAL_BUFFER_SIZE_DL_ - needle_len_a),
            needle_a,
            needle_len_a);

     memcpy(output_a,
            desloca_buffer_amanda,
            V9C_INTERNAL_BUFFER_SIZE_DL_);
}

void remove_string_ar(uint8_t *needle_a, int needle_len_a, uint8_t *input_a, uint8_t *output_a)
{

     __attribute__((unused)) uint8_t *c_a = needle_a;
     // desloca_buffer_amanda

     __attribute__((unused)) int restantes_a = V9C_INTERNAL_BUFFER_SIZE_DL_;

     /*
          if (3500 < position_a)
          {
               // assert(0);
               return;
          }
     */

     memcpy(desloca_buffer_amanda,
            input_a + needle_len_a, V9C_INTERNAL_BUFFER_SIZE_DL_);

     memcpy(desloca_buffer_amanda +
                (V9C_INTERNAL_BUFFER_SIZE_DL_ - needle_len_a),
            needle_a,
            needle_len_a);

     memcpy(output_a,
            desloca_buffer_amanda,
            V9C_INTERNAL_BUFFER_SIZE_DL_);
}

int64_t __fastcall /* because the others are slow */
    concatenate_files_from_ric_da_amandua(char *input_file_dl,
                                          char *destino_do_ric_he_he_he)
{
     int len_hanoric;
     char *b1 = malloc(DL_SIZE__);
     FILE *my_small_file_in_rico_ou_pobre = fopen(input_file_dl,
                                                  "rb");
     FILE *my_small_file_out_rico_ou_pobre = fopen(destino_do_ric_he_he_he,
                                                   "ab");
     {
     }
     // Beep(1000, 100);
     if (NULL == my_small_file_in_rico_ou_pobre || NULL == my_small_file_out_rico_ou_pobre)
     {
          Beep(1000, 100);

          exit(27);
     }

     while ((len_hanoric = fread(b1, 1, DL_SIZE__, my_small_file_in_rico_ou_pobre)))
     {
          fwrite(b1,
                 1,
                 len_hanoric,
                 my_small_file_out_rico_ou_pobre);
     }
     fclose(my_small_file_in_rico_ou_pobre);
     fclose(my_small_file_out_rico_ou_pobre);
     return (25 - 1);
}

#include "add_bits_ar.c"

#include "mark_nelson_rle.c"