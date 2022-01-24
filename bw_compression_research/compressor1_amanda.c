
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*        Licensa de Copia (C) <2022>  <Corporacao do Trabalho Binario>        *
*                                                                             *
*     Este  programa  e software livre: voce pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     12
*     publicado  pela Fundacao  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opcao) qualquer versao posterior.        *
*                                                                             *
*     Este  programa e distribuido na  esperanca que isto vai  ser util,      *
*     mas SEM  QUALQUER GARANTIA; sem  ate mesmo a implicada garantia de      *
*     COMERCIALIZAcaO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Publica para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Publica Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: sourceforge.net github.com                                   *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

                                            amandaricardo@users.sourceforge.net

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     *     99627 1708                                                  *     *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

// 2022 ric - amanda

// version information and informations about modifications
// added to new release are always added to the file
// version_info_amanda.h

// the version defined for the encoder and decoder is also defined at
// version_info_amanda.h, each different version of the encoder/decoder
// can do it in a single pre defined version, if cannot it will point
// you to the place where the decoder can be found, just it

// https://github.com/maria901/Parolin/tree/main/bw_compression_research updated daily during this compression research (jan 2022)
// https://sourceforge.net/projects/parolin/

// distributed as part of the Parolin project in the subfolder
// bw_compression_research

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////ric
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

// BEGIN ---

// different modes for the compressor, all modes now
// are controled from here for ease of use
//

/*













*/

// END ---

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////amanda
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stamandaib.h>
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

// 88888888888888888888888888888888888888888888888888888888888888

// variables and functions defines or constants

bool is_it_little_ric_endian_ar; // First Endian support to our ric's software Factory  -- 21 jan 2022 11:00 AM Brasilia Time

/////////////////////////////////////////////////////////////////
/**
 * @brief the decoder call, need to receive a amanda_compressor based file that will be checked, of course and processd as you may expect
 *
 */
int __fastcall /* he he he, irrelevant in win64, if you don't know it, but I am a developer that passed the 50,  cannot even be called from C# in win32 mode, in 64 any calling convention is the same, the microsoft call, ricardo is teaching it for free, he he he */ decode_ric_amanda(char *
                                                                                                                                                                                                                                                                                           /* no Unicode support during development, only later, sorry and I love fopen, not _wfopen */
                                                                                                                                                                                                                                                                                           input_file_amanda,
                                                                                                                                                                                                                                                                                       char *output_file_amanda);

/**
 * @brief Will document it later... sorry
 *
 * @param size_of_header_amanda
 * @param memory_to_add_amanda
 * @param input_file_amanda
 * @param output_file_amanda
 * @return int
 */
int main_amanda(int size_of_header_amanda, char *memory_to_add_amanda, char *input_file_amanda, char *output_file_amanda);

void pedro_dprintf(int amanda_level,
                   char *format, ...);

int32_t __fastcall adler32(int32_t amanda,
                                      uint8_t *amanda_buf,
                                      int32_t amanda_len);

int main_rle(uint8_t *buf_ar, int len_ar, uint8_t *buf_out, int *len_out_ar);

/**
 * @brief just an Amanda wrapper
 *
 * @param input_file_amanda
 * @param output_file_amanda
 * @return int
 */
int main_amanda_THE_amanda(char *input_file_amanda, char *output_file_amanda);

int ra____file_size(unsigned char *ra____file);

int ra____files_size_char(char *ra____file)
{
     return ra____file_size((void *)ra____file);
}
void ra____dump_arrays_to_disk(unsigned char *ra____bytes_array_file,
                               unsigned char *ra____bits_array_file,
                               unsigned char *ra____pointers_array_file,
                               unsigned char *ra____file_out);
//                                  13131313131313

#define DEBUG_amanda__ 0
#define DEBUG2_amanda__ 0

#define DEBUG_DEC_amanda__ (0)

#define MAX_STRING_SEARCH_SIZE_REAL_amanda__ (18) /* max string size modified */
#define MAX_STRING_SEARCH_SIZE_amanda__ (18)      /* --- (v8 is this too) */
#define MIN_STRING_SEARCH_SIZE_amanda__ (3)       /* v19 */
#define STRING_PASS_SIZE_amanda__ (1)             /* this will change in the future just to speed up execution */

#if 1
#define amanda_SIZE__ (1L << 15) /* testing */
#define amanda_SIZE__ (1L << 15) /* testing */
#endif

// 88888888888888888888888888888888888888888888888

#define V9C_INTERNAL_BUFFER_SIZE_amanda_ (amanda_SIZE__) /* it says v9c but at this moment it is v14c */

// 88888888888888888888888888888888888888888888888888888888888888
#if 1
/**
 * @brief It will check whether the string is found in the haystack ( borrowed from php ;-) )
 *
 * @param haystack the main string
 * @param neeamandae the neeamandae that you are searching in the haystack
 * @param offset the position to start from
 * @return int64_t the position where it is found or -1 if not found
 */
int64_t mem_search_amanda(__attribute__((unused)) uint8_t *haystack,
                      __attribute__((unused)) int64_t haystack_len,
                      __attribute__((unused)) uint8_t *neeamandae,
                      __attribute__((unused)) int64_t neeamandae_len,
                      __attribute__((unused)) int64_t offset_amanda);
#endif

/*

*/

#include "linked_list1_amanda.h"
#include "linked_list2_amanda.h"

// it also work on GCC not only cl.exe but 'packet' is
// the correct mode to use it
#pragma pack(push, 1)
typedef struct amanda_dados_salvos_querido_ric__
{
     char amor_assinatura_amanda[4];
     char version_of_the_code;                    // requires push 1 or will see additional bytes in the header, and this is weird
     int32_t aamandaer32_of_the_uncompressed_data_amanda; // for the data to compress, to check after the decompression
     int64_t size_of_the_file_to_compress_amanda;
     int64_t number_of_bits_ar;
} amanda_dados_salvos_querido_ric;
#pragma pack(pop)

typedef struct main_amanda_struct_for_amanda_compressor__
{

     uint8_t *bit_array_pointer_amanda;
     int bit_position_for_decoder_amanda;
     int bytes_left_in_the_bits_array_amanda;

} main_amanda_struct_for_amanda_compressor;

// 88888888888888888888888888888888888888888888888888888888888888

// helper functions, please document it ric

/**
 * @brief It will check whether the string is found in the haystack ( borrowed from php ;-) )
 *
 * @param haystack the main string
 * @param neeamandae the neeamandae that you are searching in the haystack
 * @param offset the position to start from
 * @return int64_t the position where it is found or -1 if not found
 */
int64_t mem_search_amanda(__attribute__((unused)) uint8_t *haystack,
                      __attribute__((unused)) int64_t haystack_len,
                      __attribute__((unused)) uint8_t *neeamandae,
                      __attribute__((unused)) int64_t neeamandae_len,
                      __attribute__((unused)) int64_t offset_amanda)
{

     uint8_t *ptr_amanda;

     int64_t len_amanda, i_amanda, haystack_len_left;

     (void)len_amanda;

     haystack_len_left = haystack_len - offset_amanda;

     if (0 > haystack_len_left)
     {
          return -1;
     }

     if (neeamandae_len > haystack_len_left)
     {
          return -1;
     }

     for (i_amanda = offset_amanda; i_amanda < haystack_len; i_amanda++)
     {
          ; // ok...

          if (neeamandae_len > haystack_len_left)
          {
               return -1;
          }

          ptr_amanda = haystack;
          ptr_amanda += i_amanda;
          if (0 == memcmp(neeamandae, ptr_amanda, neeamandae_len))
          {
               return i_amanda;
          }

          haystack_len_left--;
     }

     return -1;

     return 0; // why it is here? today is 15 jan 2022 14:34
}
#define uint unsigned int

/**
 * @brief for required progress information, it can be handy for large files since in the research we don't care about speed improvements, at least for the moment (we are testing with make.bin, this is an old version of make.exe that we used for years, zlib can compress it to 85 kb
 *
 * @param max the total size of the data
 * @param fatia the slice (fatia in perfect portuguese) to be used in the calculation, I developed this function myself 26 years ago, no Googling for it, at that time Altavista was the search engine to be used or Yahoo search engine
 * @return uint the percentage, range from 0 to 100, can be more than 100 since it is not validated inside the function
 */
uint getpor(int64_t max, int64_t fatia)
{

     double maxa;
     double fatiaa;

     maxa = (double)max;
     fatiaa = (double)fatia;

     if (max == 0)
     {
          return 0;
     }

     maxa = ((double)100 / maxa * fatiaa);

     return (uint)maxa;
}

/**
 * It will return the last occurrence of a string inside the string (it is not obviously my code, if mine it would not be as good as this)
 *
 * @param s1 the string to search
 *
 * @param s2 the input string
 *
 * @return a pointer if the string was found or NULL otherwise
 *
 */
char *
strrstr(char *s1, char *s2)
{
     char *sc2, *psc1, *ps1;
     if (*s2 == '\0')
     {
          return ((char *)s1);
     }
     ps1 = s1 + strlen(s1);
     while (ps1 != s1)
     {
          --ps1;
          for (psc1 = ps1, sc2 = s2;;)
          {
               if (*(psc1++) != *(sc2++))
               {
                    break;
               }
               else if (*sc2 == '\0')
               {
                    return ((char *)ps1);
               }
          }
     }
     return ((char *)((void *)0));
}

// 10101010101010101010101010101010101010101010101010101010101010
/**
 * @brief our magic main entry point for our and your pleasure...
 *
 * @param arg_amanda_c the number of arguments for your use
 * @param arg_amanda_v the arguments passed to be openned as files this way -> arg_amanda_v[2];
 * @return int not 0 on error
 */
int main(int arg_amanda_c, char **arg_amanda_v)
{

     char file_exe_amanda[MAX_PATH + 1] = {0}; // Unicode will hanamandae later we it become part of Parolin compressors/uncompressors
     char *file_exe_amanda2;

     // printf("size amor -> 16 bits %d\n", (1 << 15)); exit(27);

     if (4 != arg_amanda_c)
     {
          goto exit_now_ric_amanda;
     }

     DetermineEndianess();

     if (0 == strcmp("e", arg_amanda_v[1]) || 0 == strcmp("E" /* if some weird developer use 'E' */, arg_amanda_v[1]))
     {
          ; // encoding
     }
     else
     {
          return decode_ric_amanda(arg_amanda_v[2], arg_amanda_v[3]);
     }

     __attribute__((unused)) int32_t aamandaer32_real = 28; // Aamandaer says 1, but we are not following the recommendation, could be 53 too as you already know

     __attribute__((unused)) int len_amanda, len_amanda2;

     __attribute__((unused)) int len_of_data_to_compress_amanda;

     __attribute__((unused)) FILE *my_file_amanda = NULL;
     __attribute__((unused)) FILE *my_file_amanda2 = NULL;
     __attribute__((unused)) FILE *my_file_amanda3 = NULL;

     out_file_amanda = NULL;
     out_file_amanda2 = NULL;
     out_file_amanda3 = NULL;

     __attribute__((unused)) int rle_len_mark_ar;

     __attribute__((unused)) uint8_t *buf_amanda_ptr;

     __attribute__((unused)) uint8_t *buf_amanda = malloc(amanda_SIZE__ * 2);

     __attribute__((unused)) uint8_t *buf_amandab = malloc(amanda_SIZE__ * 2);

     __attribute__((unused)) uint8_t *buf_amanda_0 = malloc(amanda_SIZE__ * 2);

     __attribute__((unused)) uint8_t *sliding_window_amanda = malloc((amanda_SIZE__ * 2) + MAX_STRING_SEARCH_SIZE_amanda__); // as you can see it is large enough, kkkkkk, dont be afraid in a near future (next week (jan 2022)) it will have only the real required size, thanks for your patience

     __attribute__((unused)) uint8_t *sliding_window_amanda2 = malloc(amanda_SIZE__ + MAX_STRING_SEARCH_SIZE_amanda__); // was used for passed versions below v14ca

     __attribute__((unused)) uint8_t *buf_amanda_1 = malloc(amanda_SIZE__);

     __attribute__((unused)) uint8_t *buf_amanda_2 = malloc(amanda_SIZE__);

     __attribute__((unused)) double size_d_amanda;

     size_d_amanda = (double)amanda_SIZE__;

     size_d_amanda = size_d_amanda + (size_d_amanda * .4); // more than enough for the moment, for version v4 and v13 too

     __attribute__((unused)) uint8_t *buf_amanda_compressed = malloc((int)size_d_amanda); // need to be certain that will not store more than 8 to 9 bits on it for the moment, please verify later (old information)

     size_d_amanda = (double)amanda_SIZE__;

     size_d_amanda = ceil((size_d_amanda * .2));

     assert(size_d_amanda < 65000); // here we may have a problem in a near future, better to keep it here

     /**
      * @brief Construct a new attribute object, querido ric, este é o limite para o array de bit as bytes (not in use anymore)
      *
      */
     __attribute__((unused)) uint16_t fixed_value_for_great_ric = size_d_amanda - 100;

     __attribute__((unused)) uint8_t *buf_amanda_bit_buffer = malloc((int)size_d_amanda); //

     bit_buffer_left_amanda_original = (int)size_d_amanda;

     bit_buffer_left_amanda = bit_buffer_left_amanda_original;

     __attribute__((unused)) uint8_t *ptr_amanda;

     __attribute__((unused)) int i_i_amanda;

     __attribute__((unused)) int pos_in_stream_amanda;

     __attribute__((unused)) int initial_size_of_string_amanda;

     __attribute__((unused)) int len_amanda_copy_2;

     __attribute__((unused)) uint8_t *hay_ptr_amanda_copy;

     __attribute__((unused)) static uint8_t neeamandae_buf_amanda[MAX_STRING_SEARCH_SIZE_amanda__ + 20 /*for safety */];

     __attribute__((unused)) static uint8_t neeamandae_buf_amanda_copy[MAX_STRING_SEARCH_SIZE_amanda__ + 20 /*for safety */];

     __attribute__((unused)) int64_t result_amanda, result_temp_amanda;

     __attribute__((unused)) int64_t result_amanda_0, result_amanda_1;

     __attribute__((unused)) int64_t result_amanda2;

     __attribute__((unused)) int has_itens_is__amanda__update_amanda_copy;

     __attribute__((unused)) amanda_dados_salvos_querido_ric minha_struct = {0};

     __attribute__((unused)) int has_itens_is___rcamanda____update__rcamanda__ccopy;

     __attribute__((unused)) int initial_size_amanda = -1; // to be adjusted later

     __attribute__((unused)) int delocador_fix_bug_in_version_2_0_amanda;

     int64_t tamanho_amanda, progress_amanda;

     __attribute__((unused)) ULONGLONG update_me_amanda = 0;

     unlink(arg_amanda_v[3]);
     my_file_amanda = fopen(arg_amanda_v[2], "rb");
     {
          strcpy(temp_file_amanda, arg_amanda_v[3]);

          strcat(temp_file_amanda, ".bw.tmp");
          out_file_amanda = fopen(temp_file_amanda, "wb");
     }
     {
          strcpy(temp_file_amanda2, arg_amanda_v[3]);

          strcat(temp_file_amanda2, ".bw.lzss_bytes.tmp"); // for the bytes array
          out_file_amanda2 = fopen(temp_file_amanda2, "wb");
     }
     {
          strcpy(temp_file_amanda3, arg_amanda_v[3]);

          strcat(temp_file_amanda3, ".bw.lzss_bits.tmp"); // for the bits array
          out_file_amanda3 = fopen(temp_file_amanda3, "wb");
     }
     {
          strcpy(temp_file_amanda4, arg_amanda_v[3]);

          strcat(temp_file_amanda4, ".bw.lzss_pointers.tmp"); // for the pointers array
          out_file_amanda4 = fopen(temp_file_amanda4, "wb");
     }
     {
          strcpy(temp_file_amanda5, arg_amanda_v[3]);

          strcat(temp_file_amanda5, ".bw.lzss+ari.tmp");
          // out_file_amanda5 = fopen(temp_file_amanda5, "wb");
     }
     {
          strcpy(temp_file_amanda6, arg_amanda_v[3]);

          strcat(temp_file_amanda6, ".bw.lzss_bytes+ari.tmp");
          // out_file_amanda6 = fopen(temp_file_amanda6, "wb");
     }
     {
          strcpy(temp_file_amanda7, arg_amanda_v[3]);

          strcat(temp_file_amanda7, ".bw.lzss_bits+ari.tmp");
          // out_file_amanda7 = fopen(temp_file_amanda7, "wb");
     }

     // bfpOut = MakeBitFile(out_file_amanda, BF_WRITE);

     if (NULL == bfpOut)
     {
          // printf("Cannot create bitfile, exiting...");
          // exit(27);
     }

     // adding initial checks (12 jan 2022 06:41)

     if (NULL == my_file_amanda || NULL == out_file_amanda)
     {
          printf("Cannot open input files, exiting...");
          exit(27);
     }

     if (DEBUG_amanda__) // this is our debug flag
     {
          ; // //assert(0 && "initial position");
     }

     _fseeki64(my_file_amanda, 0, SEEK_END);

     tamanho_amanda = _ftelli64(my_file_amanda);

     _fseeki64(my_file_amanda, 0, SEEK_SET); // we don't have time to use our standard size get function at this moment, time is important in research

     progress_amanda = 0; // progress may help when compressing files with research code that normally is not optimized for speed
     // assert(0);
     if (my_file_amanda)
     {
          // assert(0 && "2");
          if (DEBUG_amanda__)
               pedro_dprintf(0, "size %d\n", amanda_SIZE__);

          if (DEBUG_amanda__)
          {
               ; // //assert(0 && "already open the file");
          }

          pos_in_stream_amanda = 0;

          initial_size_amanda = MIN_STRING_SEARCH_SIZE_amanda__; // more itens are based in this value

          initial_size_of_string_amanda = initial_size_amanda; // to be adjusted later...

          minha_struct.amor_assinatura_amanda[0] = 'p'; // this signature will never change for any future version, this is a promise
          minha_struct.amor_assinatura_amanda[1] = 'k';
          minha_struct.amor_assinatura_amanda[2] = 'k';
          minha_struct.amor_assinatura_amanda[3] = 'p';

          minha_struct.number_of_bits_ar = 0;

#include "version_info_amanda.h"

          printf("\n\n");

          replacements_amanda = 0;

          // initializing the second buffer with character 0

          memset(buf_amanda, 0, amanda_SIZE__);

          memset(buf_amanda_0, 0, amanda_SIZE__);
          memset(buf_amanda_1, 0, amanda_SIZE__);
          memset(buf_amanda_2, 0, amanda_SIZE__);
          memset(sliding_window_amanda, ' ', amanda_SIZE__);
          memset(sliding_window_amanda2, 0, amanda_SIZE__);

          bit_deslocador_v12_ar = 0;
          the_final_buffer_v12_ar = 0;
          count_of_bits_ar = 0;
          ric_amanda_deslocador = 0;
          memset(&strings_found_ar, 0, sizeof(strings_found_ar));

          bytes_in_strings_buffer_ar = 0;

          contador_pra_baixo_ar = 0;
          contador_pra_baixo_2ar = 0;

          amanda_need_to_flush_ric = -0;

          requires_last_byte_11_jan_2022_v6_amanda = false;

          while (true)
          {

               if (DEBUG_amanda__)
                    pedro_dprintf(0, "initial buffer have %d bytes", len_amanda);

               if (DEBUG_amanda__)
               {
                    ; // //assert(0 && "file read data");
               }

               // like a cientist...

               compressed_and_encoded_bytes_available_11_jan_2022_v6_amanda = 0;

               number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_amanda = 0;

               bit_buffer_left_amanda = bit_buffer_left_amanda_original;

               ptr_position_for_bit_memory_amanda = buf_amanda_bit_buffer;

               bit_position_11_jan_2022_v6_amanda = 0;

               current_byte_being_generated_11_jan_2022_v6_byte_amanda = 0;

               bits_added_11_jan_2022_v6_amanda = 0;

               already_found_with_larger_size_amanda = false;

               is_it_the_first_byte_to_encode_amanda = true;

               size_of_already_saw_data_amanda = 0;

               position_of_the_data_in_the_output_stream_amanda = buf_amanda_compressed;

               if (DEBUG_amanda__)
                    pedro_dprintf(0, "zero init variables", len_amanda);

               if (DEBUG_amanda__)
               {
                    ; // //assert(0 && "first steps, zeroing data");
               }

               bytes_left_ar = 0;

               buf_amanda_ptr = buf_amandab;

               bytes_in_buffer_ar = fread(buf_amandab, 1, V9C_INTERNAL_BUFFER_SIZE_amanda_, my_file_amanda);

          volta_aqui_filho_da_mae___:; // Meu Tio Antoninho, avo da minha filha me berrou isso uma vez e eu nao apareci mais

               /* spent one hour to develop this code */
               if (bytes_in_buffer_ar < 36)
               {
                    if (alternating_buffer_amanda)
                    {
                         alternating_buffer_amanda = false;
                         len_temp = fread(buf_amanda_0, 1, V9C_INTERNAL_BUFFER_SIZE_amanda_, my_file_amanda);
                         aamandaer32_real = adler32(aamandaer32_real, // for future integrity check, not now v14c
                                                           buf_amanda_0,
                                                           len_temp);

                         memcpy(buf_amanda_2, buf_amanda_ptr, bytes_in_buffer_ar);

                         memcpy(buf_amandab, buf_amanda_2, bytes_in_buffer_ar);

                         memcpy(buf_amandab + bytes_in_buffer_ar, buf_amanda_0, len_temp);
                    }
                    else
                    {
                         alternating_buffer_amanda = true;
                         len_temp = fread(buf_amanda_1, 1, V9C_INTERNAL_BUFFER_SIZE_amanda_, my_file_amanda);
                         aamandaer32_real = adler32(aamandaer32_real,
                                                           buf_amanda_1,
                                                           len_temp);

                         memcpy(buf_amanda_2, buf_amanda_ptr, bytes_in_buffer_ar);

                         memcpy(buf_amandab, buf_amanda_2, bytes_in_buffer_ar);

                         memcpy(buf_amandab + bytes_in_buffer_ar, buf_amanda_1, len_temp);
                    }

                    bytes_in_buffer_ar += len_temp;

                    buf_amanda_ptr = buf_amandab;
               }

               if (0 == bytes_in_buffer_ar)
               {
                    goto final_ric_amanda;
               }
               position_of_the_data_in_the_input__stream_amanda = buf_amanda_ptr;

               // year 2000 compliant
               if (update_me_amanda < GetTickCount64())
               {
                    update_me_amanda = GetTickCount64() + 50;

                    if (current_progress_amanda != getpor(tamanho_amanda, progress_amanda))
                    {
                         printf("Progress ric -> % 4d\r", current_progress_amanda = getpor(tamanho_amanda, progress_amanda));
                         fflush(stdout);
                    }
               }

               if (DEBUG_amanda__)
                    pedro_dprintf(0, "iniciou novo cliclo ou reiniciou carregamento de dados");

               initial_size_of_string_amanda = initial_size_amanda; //

               size_real_for_number_of_characters_up_to_259_amanda = initial_size_amanda;
               // assert(0);
               pedro_dprintf(-1, "compressed buffer %d", amanda_need_to_flush_ric);

               if (number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_amanda)
                    pedro_dprintf(-1, "aqui  %d", number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_amanda);
               if (DEBUG_amanda__)
                    pedro_dprintf(0, "initial process");

               if (DEBUG_amanda__)
               {
                    assert(0 && "parando");
               }

               bytes_left_in_the_input_uncompressed_stream_amanda = bytes_in_buffer_ar;

               size_of_already_saw_data_amanda_original = size_of_already_saw_data_amanda;

               bytes_left_in_the_input_uncompressed_stream_amanda_original = bytes_left_in_the_input_uncompressed_stream_amanda; // dont and the rest
               position_of_the_data_in_the_input__stream_amanda_original = position_of_the_data_in_the_input__stream_amanda;     // done, now

               cannot_be_largest_string_size_amanda = false;

               size_of_the_nedamandae_amanda = min(bytes_left_in_the_input_uncompressed_stream_amanda, initial_size_of_string_amanda);
               size_got_of_nedamandae_amanda = size_of_the_nedamandae_amanda;
               memcpy(neeamandae_buf_amanda, position_of_the_data_in_the_input__stream_amanda, size_of_the_nedamandae_amanda);

               {
                    memcpy(largest_neeamandae_already_in_buffer_amanda, position_of_the_data_in_the_input__stream_amanda, min(bytes_left_in_the_input_uncompressed_stream_amanda, MAX_STRING_SEARCH_SIZE_amanda__));

                    largest_nedamandae_size_amanda = min(bytes_left_in_the_input_uncompressed_stream_amanda, MAX_STRING_SEARCH_SIZE_amanda__);
               }

               if (MAX_STRING_SEARCH_SIZE_REAL_amanda__ > min(bytes_left_in_the_input_uncompressed_stream_amanda, MAX_STRING_SEARCH_SIZE_REAL_amanda__))
               {
                    pedro_dprintf(0, "aqui 1");
                    cannot_be_largest_string_size_amanda = true; // will not be used in a few minutes v12
               }

               if (DEBUG_amanda__)
                    pedro_dprintf(0, "size of already saw data %d e deslocamento no buffer real %d", size_of_already_saw_data_amanda, size_of_already_saw_data_amanda + size_of_the_nedamandae_amanda);

               position_of_the_data_in_the_input__stream_amanda += 1;
               buf_amanda_ptr += 1;

               progress_amanda += 1; // we need the limit for , or it is hanamandaed by the first call ?

               bytes_in_buffer_ar -= 1;

               assert(0 <= bytes_in_buffer_ar);

               found_buffer_0_amanda = false;

               // here for buffer 0 for the moment
               if ((MIN_STRING_SEARCH_SIZE_amanda__ > size_got_of_nedamandae_amanda || cannot_be_largest_string_size_amanda))
               {
                    ; // if last item don't search in any memory, it will be deleted soon v12
               }
               else
               {
                    // for the moment just 0

                    pedro_dprintf(-1, "antes 1");

                    process_search_in_passed_buffers_at_once_amanda(sliding_window_amanda,
                                                                &found_buffer_0_amanda,
                                                                &max_size_string_from_buffer_0,
                                                                &position_found_buffer_0_amanda,
                                                                position_of_the_data_in_the_input__stream_amanda_original, &new_size_of_nedamandae_amanda);

                    pedro_dprintf(-1, "antes 2");

                    // just use current

                    if (found_buffer_0_amanda) // only used here...
                    {

                         assert(MIN_STRING_SEARCH_SIZE_amanda__ == size_of_the_nedamandae_amanda); // for safety and no hidden bugs (v8 fixed)
                    }
               }

               {

                    if (found_buffer_0_amanda)
                    {

                         if (true)
                         {

                              pedro_dprintf(-1, "max_size_string_from_buffer_0 %d new_size_of_nedamandae_amanda %d",
                                            max_size_string_from_buffer_0,
                                            new_size_of_nedamandae_amanda);
                              // assert(0);
                              past_position_location_amanda = position_found_buffer_0_amanda;

                              size_real_for_number_of_characters_up_to_259_amanda = (uint16_t)max_size_string_from_buffer_0;

                              size_of_characters_adjusted_to_pass_amanda = (int8_t)size_real_for_number_of_characters_up_to_259_amanda;
                              pedro_dprintf(-1, "size_of_characters_adjusted_to_pass_amanda ric %d", size_of_characters_adjusted_to_pass_amanda);
                              // here ric my brother...
                              convert_8_bits_to_nine_bits_12_jan_2022_v6_amanda(NULL, // irrelevant
                                                                            0,    // irrelevant
                                                                            true,
                                                                            past_position_location_amanda,
                                                                            size_of_characters_adjusted_to_pass_amanda,
                                                                            true /*,
                                                                             out_file_amanda*/
                              );                                                 // v12

                              for (i_a = 0; i_a < max_size_string_from_buffer_0; i_a++)
                              {

                                   sliding_window_amanda[contador_pra_baixo_ar++] = position_of_the_data_in_the_input__stream_amanda_original[i_a];

                                   if (amanda_SIZE__ == contador_pra_baixo_ar)
                                   {
                                        contador_pra_baixo_ar = 0;
                                   }
                              }

                              pedro_dprintf(-1, "size %d", new_size_of_nedamandae_amanda);

                              progress_amanda = progress_amanda + (new_size_of_nedamandae_amanda - 1); // we need the limit for, or it is hanamandaed by the first call ?

                              position_of_the_data_in_the_input__stream_amanda = position_of_the_data_in_the_input__stream_amanda + (new_size_of_nedamandae_amanda - 1);

                              buf_amanda_ptr = buf_amanda_ptr + (new_size_of_nedamandae_amanda - 1);

                              bytes_in_buffer_ar -= (new_size_of_nedamandae_amanda - 1);

                              assert(0 <= bytes_in_buffer_ar);

                              goto volta_aqui_filho_da_mae___; // isso foi que meu primeiro sogro disse no dia que fui conhecer minha filha Mislaine em 1990
                         }
                    }
               }

               if (DEBUG_amanda__)
                    pedro_dprintf(0, "size_of_the_nedamandae_amanda %d", size_of_the_nedamandae_amanda);

               if (DEBUG_amanda__)
               {
                    assert(0 && "parando");
               }

               // the_magic_begins_here__amanda:;

               if (true)
               {
                    pedro_dprintf(-1, "salvando byte");
                    if (DEBUG_amanda__)
                         pedro_dprintf(0, "nao encontrou entao vai salvar %d bytes, antes de chamar o so far alterado é %d e bits as the number of whole bytes encoded ate agora %d", 1, compressed_and_encoded_bytes_available_11_jan_2022_v6_amanda,
                                       number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_amanda);

                    if (DEBUG_amanda__)
                    {
                         assert(0 && "parando");
                    }

                    assert(MIN_STRING_SEARCH_SIZE_amanda__ >= 1);
                    size_real_for_number_of_characters_up_to_259_amanda = (uint16_t)1;

                    size_of_characters_adjusted_to_pass_amanda = (uint8_t)size_real_for_number_of_characters_up_to_259_amanda;

                    convert_8_bits_to_nine_bits_12_jan_2022_v6_amanda(largest_neeamandae_already_in_buffer_amanda, // it will be improved
                                                                  size_of_characters_adjusted_to_pass_amanda,
                                                                  false,
                                                                  2022 /* the value of this argument is irrelevant here */,
                                                                  0 /* here too */,
                                                                  false /*,
                                                                   out_file_amanda*/
                    );                                                  //

                    sliding_window_amanda[contador_pra_baixo_ar++] = largest_neeamandae_already_in_buffer_amanda[0];

                    if (V9C_INTERNAL_BUFFER_SIZE_amanda_ == contador_pra_baixo_ar)
                    {
                         contador_pra_baixo_ar = 0;
                    }

                    if (DEBUG_amanda__)
                         pedro_dprintf(0, "o so far agora é %d e array of bits as bytes size %d", compressed_and_encoded_bytes_available_11_jan_2022_v6_amanda,
                                       number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_amanda);

                    if (DEBUG_amanda__)
                    {
                         assert(0 && "parando");
                    }

                    goto volta_aqui_filho_da_mae___; // just start again (it is v6 based)
               }
               break;
          }
     final_ric_amanda:;

          if (28 == 53) // to make ricardo happy...
          {
               goto continua_pro_proximo_buffer_a_ser_lido_amanda;
          }
     continua_pro_proximo_buffer_a_ser_lido_amanda:;

          if (requires_last_byte_11_jan_2022_v6_amanda)
          {
               putc(1, out_file_amanda3);
          }
          else
               putc(0, out_file_amanda3);

          fclose(my_file_amanda);

          if (out_file_amanda)
          {
               fclose(out_file_amanda);
               out_file_amanda = NULL;
          }
     }

     if (out_file_amanda)
     {
          fclose(out_file_amanda);
          out_file_amanda = NULL;
     }
     if (out_file_amanda2)
     {
          fclose(out_file_amanda2);
          out_file_amanda2 = NULL;
     }
     if (out_file_amanda3)
     {
          fclose(out_file_amanda3);
          out_file_amanda3 = NULL;
     }
     if (out_file_amanda4)
     {
          fclose(out_file_amanda4);
          out_file_amanda4 = NULL;
     }

     free(buf_amanda), free(buf_amandab), free(buf_amanda_0), free(buf_amanda_1), free(buf_amanda_2),
         free(sliding_window_amanda),
         free(sliding_window_amanda2),
         free(buf_amanda_compressed), free(buf_amanda_bit_buffer);

     printf("Progress ric -> % 4d\n", 100);
     printf("Research running...\n");
     printf("Checksum of the file compressed %08x\n", aamandaer32_real);
     printf("Replacements %d\n", replacements_amanda);

     minha_struct.aamandaer32_of_the_uncompressed_data_amanda = aamandaer32_real;

     minha_struct.size_of_the_file_to_compress_amanda = tamanho_amanda;

     // main_amanda_THE_amanda()

     /*
          if (main_amanda(sizeof(minha_struct), (char *)&minha_struct, temp_file_amanda, arg_amanda_v[3]))
          {
               unlink(temp_file_amanda);
               printf("Error in the arithmetic compression, cannot open a file to read or write\n");
               return 27;
          }
     */

     ra____dump_arrays_to_disk((void *)temp_file_amanda2,
                               (void *)temp_file_amanda3,
                               (void *)temp_file_amanda4,
                               (void *)arg_amanda_v[3]);

     // main_amanda_THE_amanda((void *)"ra____temp.tmp", arg_amanda_v[3]);

     // cp("ra____temp.tmp", arg_amanda_v[3]);

     unlink(temp_file_amanda2);
     unlink(temp_file_amanda3);
     unlink(temp_file_amanda4);
     unlink(temp_file_amanda5);
     unlink(temp_file_amanda6);
     unlink(temp_file_amanda7);

     /*
          main_amanda_THE_amanda(temp_file_amanda4, temp_file_amanda5); // pointers
          main_amanda_THE_amanda(temp_file_amanda2, temp_file_amanda6); // bytes
          main_amanda_THE_amanda(temp_file_amanda3, temp_file_amanda7); // array of bits

          concatenate_files_from_ric_da_amandua(temp_file_amanda5, arg_amanda_v[3]);
          concatenate_files_from_ric_da_amandua(temp_file_amanda6, arg_amanda_v[3]);
          concatenate_files_from_ric_da_amandua(temp_file_amanda7, arg_amanda_v[3]);
     */
     // unlink(temp_file_amanda2);
     // unlink(temp_file_amanda3);
     // unlink(temp_file_amanda4);
     // unlink(temp_file_amanda5);
     // unlink(temp_file_amanda6);
     // unlink(temp_file_amanda7);
     //  unlink("ra____temp.tmp");
     /*
          concatenate_files_from_ric_da_amandua(temp_file_amanda2, arg_amanda_v[3]);
          concatenate_files_from_ric_da_amandua(temp_file_amanda3, arg_amanda_v[3]);
          concatenate_files_from_ric_da_amandua(temp_file_amanda4, arg_amanda_v[3]);

          unlink(temp_file_amanda2);
          unlink(temp_file_amanda3);
          unlink(temp_file_amanda4);
     */

     /*
      unlink(temp_file_amanda5);
      concatenate_files_from_ric_da_amandua(temp_file_amanda2, temp_file_amanda5);
      concatenate_files_from_ric_da_amandua(temp_file_amanda3, temp_file_amanda5);
      concatenate_files_from_ric_da_amandua(temp_file_amanda4, temp_file_amanda5);

      main_amanda_THE_amanda(temp_file_amanda5, arg_amanda_v[3]);

      unlink(temp_file_amanda2);
      unlink(temp_file_amanda3);
      unlink(temp_file_amanda4);
      unlink(temp_file_amanda5);
      unlink(temp_file_amanda6);
      unlink(temp_file_amanda7);
      */

     unlink(temp_file_amanda);
     printf("\nDiligent Compressor\n\nVersion of the encoder/decoder -> " STRING_VERSION_amanda_COMPRESSOR "\n");
     return 0;

exit_now_ric_amanda:;

     strcpy(file_exe_amanda, arg_amanda_v[0]);

     file_exe_amanda2 = strrstr(file_exe_amanda, "/"); // for Unix guys
     if (NULL == file_exe_amanda2)
          file_exe_amanda2 = strrstr(file_exe_amanda, "\\");

     if (file_exe_amanda2)
     {
     }
     else
     {
          file_exe_amanda2 = file_exe_amanda;
     }

     printf("\n\nDiligent Compressor\n\nVersion of the encoder/decoder -> " STRING_VERSION_amanda_COMPRESSOR "\n\n");
     printf("Usage: %s e <input_file> <output_file>            -- to encode a file\n", file_exe_amanda2 + 1);
     printf("Usage: %s d <input_file> <output_file>            -- to decode a file, simple as it...\n", file_exe_amanda2 + 1);
     printf("\nIn case of an erroneous decoder, newer or older it will point\n");
     printf("you to the correct version download area on GitHub or sf.net\n");
     printf("Each different version encodes and decodes a single version since v9.c\n");
     exit(27);
}

// it is 09:41 of 13 jan 2022 and the decoder code for amanda_compressor just started (first version with a decoder v9.c)

#include "amanda_compressor_decoder.c"

// vamos lá

/*

the information below talks about old research information that may have changed or are now irrelevant in v6 version and above






BEGIN ---


in portuguese, translate it

primeiro vamos criar um linked list para manter a lista de strings analizadas

64 bits claro, depois a gente ve sobre como convertar pra x86

first we need to open a file that we want to compress, for this the ubiquitous 'make.exe'

bom, em lz77 e lzss e lz78 a informacao se baseia nos dados que vao sendo lidos no arquivo e marcacoes vao sendo feitas pra se saber se ja apareceram ou nao

primeiro teria que se desenvolver uma forma avancada para se colocar na memria e no arquivo comprimido uma forma satisfatoria de salvar as informacoes que serao necessarias para a reconstrucao do arquivo

pelo jeito a cada 32kb é reiniciado o processo pois se deslocar nao sera possivel reconstruir os dados

pois a informacao tera passado, sim, tem que ter uma tamanho predefinido, mas que seja aleatorio, concorda?

sim
vamos bater o bzip2 com facilidade e rapido

mais rapido e melhor que bzip2

precisamos de um texto de exemplo

da pra trabalhar com memoria de 32 kb nao dá?

mas em que isto vai ser melhor que zlib?

200 mb de memoria ?

tem coisa demais...

//vamos ler de quanto em quanto ?

* * * * * * * * 16 caracteres ? de cada vez ? nao pode ser mais ou menos ?

ok, we have the information now store it,

1 - first we need to scan the data for data repeating it

primeiro precisa definir um meio certo de salvar as coisas no arquivo, tem que escolher um caracter e trocar ele

eu tenho uma outra visao de salvar isso em linked lists e depois de processado so colocar no arquivo, mas se nao for compressivel nao adianta

quando nao da para comprimir complica

tem que criar slices do arquivo inteiro , de um caracter ate 512, ok?

se nao for compressivel simplesmente deixa como esta ok, uma flag comprimido ou nao

entendi, tem que ler, salvar na nova memoria e manter uma copia original

certo...

to quase compreendendo...

precisa de um meio  de salvar na memoria ou arquivo a informacao de maneira simplificada e usando pouco espaco

nao da para usar aquela ideia de run lenght compression ?

repete o caracter e poe um controle...

precisa de um meio bem definido de como colocar as strings comprimidas no arquivo comprimido

poderia contar o caracter que menos repete, mas isso leva tempo...

zlib expande o arquivo se nao consegue comprimir dai aciona umma flag que faz com que seja a original em vez da versao comprimida que expande

pode usar 9 bits para cada 16 byes da memira assim nao sao todos ok?

numa sequencia de bytes no final usa 9 bits igual lzw, nao quer dar uma lida em lzw ?
se usar 16 bytes serao sempre multiplos de 16 para qualquer sequencia, pode ser bom

melhor dar uma lida primeiro em lzw

ok, usa 9 bits mas para todos os caracteres ? dai da para definir valores para outras coisas

se for abaixo de 256 entao é caractere se for acima é controle...

sim é facil de controlar, basta ir mandando os bits, e fim de papo

primeiro voce trabalha em cima depois salva, com dados de conpressao completos e crc32, ok ?

vamos la, comecando do inicio, transforma todos os bits para 9, e usa eles pra marcar oque for comprimido ou nao depois a gente melhora isso

precisamos comprimir

deste jeito ficou facil, vamos fazer...

*/

// precisamos de um conversor de bytes para 9 bytes...vai lá... na memoria, vamos trabalhar com ele neste 128 kb

/*

pra isso eu tenho um codigo rapido simplesmente converter os dados de int8 para int16, vamos la, um array

ok, vamos copiar os 8 bits para 16 e trabalhar em cima disso pra ser rapido, da pra acelerar o lzw dos caras com isso

now what...

we have two arrays, but we will work on it... no need to store it now...

voltando a programacao, temos um array de bytes e array de shorts, precisamos iniciar o escaneamento, nove bits esta de bom tamanho pra os itens de depois da pra colocar 9 bits apenas em 16 em 16 e assim por diante

vamos la...

pode ir alocando em linked list se nao sabe o tamanho que vai ter , ok, sim, é isso,

vamos comecar com 16 bytes, sim , é isso, copia 16 bytes ric,,,mas e depois , depois checa se os proximos 16 sao os mesmo ?

nao, voce ja tem a memoria toda, entao apenas copia 16 e depois verifica se os proximo 512 ? se repetem ?

so funciona pra tras ? acho que nao vai ser reconstruido pode ser pra tras e pra frente...

ele simplesmente diz em que ponto do arquivo ocorre, e pode ter que tamanho ?

em que se da a compressao amor ?
 repetir um memoria inteiro nao comprime aonde esta a compressao ?

 sim mas estes limites serao alterados mais tarde para otimizacao...

aonde se da a compressao: resposta na duplicacao com menos dados da mesma informacao, nao é isso ?

depois de testar 512 bytes pode ir abaixando de 16 em dezesseis e ir definindo se tem ou nao

longest match

começa por ai

todos estes valores serao ajustados e controlados num loop que vai mostrar o melhor item deste todos

de 16 em 16 esta bom, diminuindo ate ter apenas 16, ok ?

vai...

hummmmmmmm, se existir copia os 512 bytes no stream e marca as duas posicoes como tendo a informacao, que ideia

sim, assim evita este problema, se nao tiver deixa como ta nao é isso, sim mas vai mudar as posicoes e dai ric querido ?

nao sei dua...

deixa pra colocar no final, nao é melhor pra nao dar problema ?

o markov chain talvez seja isso, mas voce vai criar algo melhor, sim vamos aprimorar a cada momento

nao da pra manter num linked list, em linked list nao vai ter posicao, ou vai, vai um index ?,

linked list parece uma boa, salva o index o tamanho cada item comeca contando de 0, entendeu, dai na marcacao simplesmente coloca o index e na reconstrucao esta tudo certo, para isto precisamos de packets?, sim , precisa saber o tamanho total do arquivo, saber aonde termina, no meio nao tem como porque esta tudo em linked list, mas se souber o tamanho comprimido da, ric, sim é isso

e cada pra salvar na struct inicial aonde comecam os linked lists, e linked lists nao precisam ser de 9 bits, so precisa de 9 bits no meio de linked lists e strings, vamos la

da pra salvar em que posicao comecam os linked lists e meios de salvar eles

sim ric...

it is not lz77 or lz78 or lzma

vai... começa com 512 e vai baixando...

///////////////////////////////////////////////////////////////////////////////////////////////////////

ok, first we need to load the data, then start creating the compressed stream, start from 16 bytes increasing until 512

whats the matter?

just limited to the past data, this in a near future could be improved, dont you agree ?

we can read future strings

*/
