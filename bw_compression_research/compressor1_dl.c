
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

// 2022 ric - dl

// version information and informations about modifications
// added to new release are always added to the file
// version_info_dl.h

// the version defined for the encoder and decoder is also defined at
// version_info_dl.h, each different version of the encoder/decoder
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
/**
 * @brief this is the mode where the buffer searched for matching string is the current buffer that is composed by the bytes being added, when searching on this current buffer if the maximum possible string for the needle is found the address and size is stored in the destination compressed buffer, so if the bytes loaded are 100 then you have 100 bytes in the searching buffer for the moment up to the maximum loaded bytes of 4096 bytes, this is lz77 like approuch, not lzss that have a sliding window that get bytes shifted all the time, for our method the buffer to search is the already loaded bytes, for this reason lzss gives a better compression ratio, lzss starts with a sliding window always of 4096 of space (character 32), in our method the bytes available in the searching code is the input buffer limited to the number of byes already processed, it don't compress better than lzss + ari from Doctor Haruhiko
 *
 */
#define DL_MODE_INITIAL_LZ77_PLUS_LZSS_LIMITED_BUFFER_SIZE_OF_4096 (1001)

/**
 * @brief this is the method that we will implement in a few minutes (now is 19:41 15/jan/2022), in this enhanced method we extend the 4096 maximum searching dictionary from 4096 to 8192 bytes, how? just adding an addicional bit that selects whether the buffer being searched is the current buffer or the last passed buffer, then it at least increases the required space in one bit for each string that need to be reconstructed using the two bytes storeage 4 bits for string size and 12 for the 4096 maximum address position, did you got it?
 * Well using this additional bit it expands the searching possibilies to the double, but will also require more space to store the compressed data, but as you will see it allows better compression, well now we will add the code to it
 *
 */
#define DL_MODE_EXTENDED_LZ77_PLUS_LZSS_AUGMENTED_THE_4096_BUFFER_TO_8192 (1002)

/**
 * @brief will define the mode to use
 */
#define DL_ENCODER_DECODER_MODE_ (DL_MODE_EXTENDED_LZ77_PLUS_LZSS_AUGMENTED_THE_4096_BUFFER_TO_8192)

// END ---

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////DL
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

#include <stdbool.h>

#include <process.h>

// 88888888888888888888888888888888888888888888888888888888888888

// variables and functions defines or constants

/**
 * @brief the decoder call, need to receive a dl_compressor based file that will be checked, of course and processd as you may expect
 *
 */
int __fastcall /* he he he, irrelevant in win64, if you don't know it, but I am a developer that passed the 50,  cannot even be called from C# in win32 mode, in 64 any calling convention is the same, the microsoft call, ricardo is teaching it for free, he he he */ decode_ric_dl(char *
                                                                                                                                                                                                                                                                                           /* no Unicode support during development, only later, sorry and I love fopen, not _wfopen */
                                                                                                                                                                                                                                                                                           input_file_dl,
                                                                                                                                                                                                                                                                                       char *output_file_dl);

/**
 * @brief Will document it later... sorry
 *
 * @param size_of_header_dl
 * @param memory_to_add_dl
 * @param input_file_dl
 * @param output_file_dl
 * @return int
 */
int main_dl(int size_of_header_dl, char *memory_to_add_dl, char *input_file_dl, char *output_file_dl);

void pedro_dprintf(int amanda_level,
                   char *format, ...);

int32_t __fastcall dl_adler32_wrapper(int32_t dl,
                                      uint8_t *dl_buf,
                                      int32_t dl_len);

// 9999999999999999999999999999999999999999999999999999999999999

#define DEBUG_DL__ 0
#define DEBUG2_DL__ 0

#define DEBUG_DEC_DL__ (0)

#define MAX_STRING_SEARCH_SIZE_REAL_DL__ (18) /* max string size modified */
#define MAX_STRING_SEARCH_SIZE_DL__ (18)      /* --- (v8 is this too) */
#define MIN_STRING_SEARCH_SIZE_DL__ (3)       /* 3 bytes is the smallest size that can be compressed, remember if the string input is less than 3 bytes just store the string without searching for a match, or it will try to add an entry to the pointers with less than 3 and it cannot be stored in our moved initial value that is 0 plus 3 to make 18 (15 max value) (v7) (v8 in this version this don't change again)*/
#define STRING_PASS_SIZE_DL__ (1)             /* this will change in the future just to speed up execution */

#define DL_SIZE__ (1L << 12) /* 4096 */

// 88888888888888888888888888888888888888888888888

#define V9C_INTERNAL_BUFFER_SIZE_DL_ (DL_SIZE__)

// 88888888888888888888888888888888888888888888888888888888888888

/**
 * @brief It will check whether the string is found in the haystack ( borrowed from php ;-) )
 *
 * @param haystack the main string
 * @param needle the needle that you are searching in the haystack
 * @param offset the position to start from
 * @return int64_t the position where it is found or -1 if not found
 */
int64_t mem_search_dl(__attribute__((unused)) uint8_t *haystack,
                      __attribute__((unused)) int64_t haystack_len,
                      __attribute__((unused)) uint8_t *needle,
                      __attribute__((unused)) int64_t needle_len,
                      __attribute__((unused)) int64_t offset_dl);

/*

*/

#include "linked_list1_dl.h"
#include "linked_list2_dl.h"

// it also work on GCC not only cl.exe but 'packet' is
// the correct mode to use it
#pragma pack(push, 1)
typedef struct dl_dados_salvos_querido_ric__
{
     char amor_assinatura_dl[4];
     char version_of_the_code;                    // requires push 1 or will see additional bytes in the header, and this is weird
     int32_t adler32_of_the_uncompressed_data_dl; // for the data to compress, to check after the decompression
     int64_t size_of_the_file_to_compress_dl;
     int64_t number_of_bits_ar;
} dl_dados_salvos_querido_ric;
#pragma pack(pop)

typedef struct main_dl_struct_for_dl_compressor__
{

     uint8_t *bit_array_pointer_dl;
     int bit_position_for_decoder_dl;
     int bytes_left_in_the_bits_array_dl;

} main_dl_struct_for_dl_compressor;

// 88888888888888888888888888888888888888888888888888888888888888

// helper functions, please document it ric

/**
 * @brief It will check whether the string is found in the haystack ( borrowed from php ;-) )
 *
 * @param haystack the main string
 * @param needle the needle that you are searching in the haystack
 * @param offset the position to start from
 * @return int64_t the position where it is found or -1 if not found
 */
int64_t mem_search_dl(__attribute__((unused)) uint8_t *haystack,
                      __attribute__((unused)) int64_t haystack_len,
                      __attribute__((unused)) uint8_t *needle,
                      __attribute__((unused)) int64_t needle_len,
                      __attribute__((unused)) int64_t offset_dl)
{

     uint8_t *ptr_dl;

     int64_t len_dl, i_dl, haystack_len_left;

     (void)len_dl;

     haystack_len_left = haystack_len - offset_dl;

     if (0 > haystack_len_left)
     {
          return -1;
     }

     if (needle_len > haystack_len_left)
     {
          return -1;
     }

     for (i_dl = offset_dl; i_dl < haystack_len; i_dl++)
     {
          ; // ok...

          if (needle_len > haystack_len_left)
          {
               return -1;
          }

          ptr_dl = haystack;
          ptr_dl += i_dl;
          if (0 == memcmp(needle, ptr_dl, needle_len))
          {
               return i_dl;
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
 * @param arg_dl_c the number of arguments for your use
 * @param arg_dl_v the arguments passed to be openned as files this way -> arg_dl_v[2];
 * @return int not 0 on error
 */
int main(int arg_dl_c, char **arg_dl_v)
{

     char file_exe_dl[MAX_PATH + 1] = {0}; // Unicode will handle later we it become part of Parolin compressors/uncompressors
     char *file_exe_dl2;

     if (4 != arg_dl_c)
     {
          goto exit_now_ric_dl;
     }

     if (0 == strcmp("e", arg_dl_v[1]) || 0 == strcmp("E" /* if some weird developer use 'E' */, arg_dl_v[1]))
     {
          ; // encoding
     }
     else
     {
          return decode_ric_dl(arg_dl_v[2], arg_dl_v[3]);
     }

     char temp_file_dl[MAX_PATH + 2];

     __attribute__((unused)) int32_t adler32_real = 28; // Adler says 1, but we are not following the recommendation

     __attribute__((unused)) int len_dl;

     __attribute__((unused)) int len_of_data_to_compress_dl;

     __attribute__((unused)) FILE *my_file_dl = NULL;

     __attribute__((unused)) FILE *out_file_dl = NULL;

     __attribute__((unused)) uint8_t *buf_dl = malloc(DL_SIZE__);

     __attribute__((unused)) uint8_t *buf_dl_0 = malloc(DL_SIZE__);

     __attribute__((unused)) uint8_t *sliding_window_amanda = malloc(DL_SIZE__ + MAX_STRING_SEARCH_SIZE_DL__);

     __attribute__((unused)) uint8_t *buf_dl_1 = malloc(DL_SIZE__);

     __attribute__((unused)) uint8_t *buf_dl_2 = malloc(DL_SIZE__);

     __attribute__((unused)) double size_d_dl;

     size_d_dl = (double)DL_SIZE__;

     size_d_dl = size_d_dl + (size_d_dl * .4); // more than enough for the moment, for version v4

     __attribute__((unused)) uint8_t *buf_dl_compressed = malloc((int)size_d_dl); // need to be certain that will not store more than 8 to 9 bits on it for the moment, please verify later (old information)

     size_d_dl = (double)DL_SIZE__;

     size_d_dl = ceil((size_d_dl * .2));

     __attribute__((unused)) uint8_t *buf_dl_bit_buffer = malloc((int)size_d_dl); //

     bit_buffer_left_dl_original = (int)size_d_dl;

     bit_buffer_left_dl = bit_buffer_left_dl_original;

     __attribute__((unused)) uint8_t *ptr_dl;

     __attribute__((unused)) int i_i_dl;

     __attribute__((unused)) int pos_in_stream_dl;

     __attribute__((unused)) int initial_size_of_string_dl;

     __attribute__((unused)) int len_dl_copy, len_dl_copy_2;

     __attribute__((unused)) uint8_t *hay_ptr_dl, *hay_ptr_dl_copy;

     __attribute__((unused)) static uint8_t needle_buf_dl[MAX_STRING_SEARCH_SIZE_DL__ + 20 /*for safety */];

     __attribute__((unused)) static uint8_t needle_buf_dl_copy[MAX_STRING_SEARCH_SIZE_DL__ + 20 /*for safety */];

     __attribute__((unused)) int64_t result_dl, result_temp_dl;

     __attribute__((unused)) int64_t result_dl_0, result_dl_1;

     __attribute__((unused)) int64_t result_dl2;

     __attribute__((unused)) int has_itens_is__dl__update_dl_copy;

     __attribute__((unused)) dl_dados_salvos_querido_ric minha_struct = {0};

     __attribute__((unused)) int has_itens_is___rcdl____update__rcdl__ccopy;

     __attribute__((unused)) int initial_size_dl = -1; // to be adjusted later

     __attribute__((unused)) int delocador_fix_bug_in_version_2_0_dl;

     int64_t tamanho_dl, progress_dl;

     __attribute__((unused)) ULONGLONG update_me_dl = 0;

     unlink(arg_dl_v[3]);
     my_file_dl = fopen(arg_dl_v[2], "rb");

     strcpy(temp_file_dl, arg_dl_v[3]);

     strcat(temp_file_dl, ".bw.tmp");

     out_file_dl = fopen(temp_file_dl, "wb");

     // adding initial checks (12 jan 2022 06:41)

     if (NULL == my_file_dl || NULL == out_file_dl)
     {
          printf("Cannot open input files, exiting...");
          exit(27);
     }

     if (DEBUG_DL__) // this is our debug flag
     {
          ; // //assert(0 && "initial position");
     }

     _fseeki64(my_file_dl, 0, SEEK_END);

     tamanho_dl = _ftelli64(my_file_dl);

     _fseeki64(my_file_dl, 0, SEEK_SET); // we don't have time to use our standard size get function at this moment, time is important in research

     progress_dl = 0; // progress may help when compressing files with research code that normally is not optimized for speed
     // assert(0);
     if (my_file_dl)
     {
          // assert(0 && "2");
          if (DEBUG_DL__)
               pedro_dprintf(0, "size %d\n", DL_SIZE__);

          if (DEBUG_DL__)
          {
               ; // //assert(0 && "already open the file");
          }

          pos_in_stream_dl = 0;

          initial_size_dl = MIN_STRING_SEARCH_SIZE_DL__; // more itens are based in this value

          initial_size_of_string_dl = initial_size_dl; // to be adjusted later...

          minha_struct.amor_assinatura_dl[0] = 'd'; // this signature will never change for any future version, this is a promise
          minha_struct.amor_assinatura_dl[1] = 'l';
          minha_struct.amor_assinatura_dl[2] = 'd';
          minha_struct.amor_assinatura_dl[3] = 'l';

          minha_struct.number_of_bits_ar = 0;

#include "version_info_dl.h"

          printf("\n\n");

          replacements_dl = 0;

          // initializing the second buffer with character 0

          memset(buf_dl, 0, DL_SIZE__);

          memset(buf_dl_0, 0, DL_SIZE__);
          memset(buf_dl_1, 0, DL_SIZE__);
          memset(buf_dl_2, 0, DL_SIZE__);
          memset(sliding_window_amanda, 0, DL_SIZE__);

          bit_deslocador_v12_ar = 0;
          the_final_buffer_v12_ar = 0;
          count_of_bits_ar = 0;

          while ((len_dl = fread(buf_dl, 1, (227 * 18), my_file_dl)))
          {
               adler32_real = dl_adler32_wrapper(adler32_real,
                                                 buf_dl,
                                                 len_dl);

               // memcpy(sliding_window_amanda, buf_dl, len_dl);

               if (DEBUG_DL__)
                    pedro_dprintf(0, "initial buffer have %d bytes", len_dl);

               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "file read data");
               }

               // like a cientist...

               compressed_and_encoded_bytes_available_11_jan_2022_v6_dl = 0;

               number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl = 0;

               bit_buffer_left_dl = bit_buffer_left_dl_original;

               ptr_position_for_bit_memory_dl = buf_dl_bit_buffer;

               bit_position_11_jan_2022_v6_dl = 0;

               requires_last_byte_11_jan_2022_v6_dl = false;

               current_byte_being_generated_11_jan_2022_v6_byte_dl = 0;

               bits_added_11_jan_2022_v6_dl = 0;

               already_found_with_larger_size_dl = false;

               is_it_the_first_byte_to_encode_dl = true;

               size_of_already_saw_data_dl = 0;

               size_of_uncompressed_stream_dl = len_dl;

               position_of_the_data_in_the_input__stream_dl = buf_dl;

               position_of_the_data_in_the_output_stream_dl = buf_dl_compressed;

               // em search code, to detect where the code is
               len_dl_copy = len_dl;

               bytes_left_in_the_input_uncompressed_stream_dl = len_dl; // sempre que avancar diminui isto

               hay_ptr_dl = buf_dl;
               if (DEBUG_DL__)
                    pedro_dprintf(0, "zero init variables", len_dl);

               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "first steps, zeroing data");
               }
               if (0 == 1)
               {
                    goto volta_aqui_mais_alto_mar; // to make the compiler happy...
               }

          volta_aqui_mais_alto_mar:; // sim é alguem, duas mar...

               // se funcionar o contrario vai ser mais rapido mas ai sera versao 3 ok...
               if (update_me_dl < GetTickCount64())
               {
                    update_me_dl = GetTickCount64() + 50;

                    if (current_progress_dl != getpor(tamanho_dl, progress_dl))
                    {
                         printf("Progress ric -> % 4d\r", current_progress_dl = getpor(tamanho_dl, progress_dl));
                         fflush(stdout);
                    }
               }

               if (DEBUG_DL__)
                    pedro_dprintf(0, "iniciou novo cliclo ou reiniciou carregamento de dados");

               initial_size_of_string_dl = initial_size_dl; //

               size_real_for_number_of_characters_up_to_259_dl = initial_size_dl;

               if (0 == len_dl_copy)
               {
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "passo final agora é só salvar os dados das duas linked lists");

                    if (DEBUG_DL__)
                    {
                         assert(0 && "last step");
                    }

                    {
                         if (true)
                         {

                              bits_encoded_size_in_bytes_dl = number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl;

                              if (requires_last_byte_11_jan_2022_v6_dl)
                              {
                                   bits_encoded_size_in_bytes_dl++; // fixed already only need to save the last byte if required
                                   (*ptr_position_for_bit_memory_dl) = current_byte_being_generated_11_jan_2022_v6_byte_dl;
                                   ptr_position_for_bit_memory_dl++;
                                   // saving the last byte if required
                              }

                              size_of_compressed_buffer2_dl_int = compressed_and_encoded_bytes_available_11_jan_2022_v6_dl;

                              assert((1 << 15) > size_of_compressed_buffer2_dl_int);

                              size_of_compressed_buffer_dl = size_of_compressed_buffer2_dl_int;

                              size_of_compressed_buffer2_dl_int = bits_encoded_size_in_bytes_dl;

                              assert((1 << 15) > size_of_compressed_buffer2_dl_int);

                              size_of_compressed_buffer2_dl = size_of_compressed_buffer2_dl_int;

                              pedro_dprintf(-1, "buf 0 %i", size_of_compressed_buffer_dl);
                              pedro_dprintf(-1, "buf 1 %i", size_of_compressed_buffer2_dl);
                              // assert(0);
                              
                              {
                                   fwrite(&size_of_compressed_buffer_dl, 1, 2, out_file_dl);

                                   fwrite(&size_of_compressed_buffer2_dl, 1, 2, out_file_dl);

                                   fwrite(buf_dl_compressed, 1, size_of_compressed_buffer_dl, out_file_dl);

                                   fwrite(buf_dl_bit_buffer, 1, size_of_compressed_buffer2_dl, out_file_dl);
                              }
                              
                              if (DEBUG_DL__)
                                   pedro_dprintf(0, "salvou os dados e imprimiu dados na tela");

                              if (DEBUG_DL__)
                              {
                                   assert(0 && "parando");
                              }
                              // next ric
                         }

                         goto continua_pro_proximo_buffer_a_ser_lido_dl;
                    }
               }

          volta_aqui_ric:;
               if (DEBUG_DL__)
                    pedro_dprintf(0, "initial process");

               if (DEBUG_DL__)
               {
                    assert(0 && "parando");
               }
               size_of_already_saw_data_dl_original = size_of_already_saw_data_dl;

               bytes_left_in_the_input_uncompressed_stream_dl_original = bytes_left_in_the_input_uncompressed_stream_dl; // dont and the rest
               position_of_the_data_in_the_input__stream_dl_original = position_of_the_data_in_the_input__stream_dl;     // done, now

               cannot_be_largest_string_size_dl = false;

               size_of_the_neddle_dl = min(bytes_left_in_the_input_uncompressed_stream_dl, initial_size_of_string_dl);
               size_got_of_neddle_dl = size_of_the_neddle_dl;
               memcpy(needle_buf_dl, position_of_the_data_in_the_input__stream_dl, size_of_the_neddle_dl);

               {
                    memcpy(largest_needle_already_in_buffer_dl, position_of_the_data_in_the_input__stream_dl, min(bytes_left_in_the_input_uncompressed_stream_dl, MAX_STRING_SEARCH_SIZE_DL__));

                    largest_neddle_size_dl = min(bytes_left_in_the_input_uncompressed_stream_dl, MAX_STRING_SEARCH_SIZE_DL__);
               }

               if (MAX_STRING_SEARCH_SIZE_REAL_DL__ > min(bytes_left_in_the_input_uncompressed_stream_dl, MAX_STRING_SEARCH_SIZE_REAL_DL__))
               {
                    cannot_be_largest_string_size_dl = true; // will not be used in a few minutes v12
               }

               // nao tem que lembrar isto em caso de nao achar ?, sim tem que voltar pra cá e com o tamanho certo, precisa de uma cópia, se der atualiza, vai la....

               if (DEBUG_DL__)
                    pedro_dprintf(0, "size of already saw data %d e deslocamento no buffer real %d", size_of_already_saw_data_dl, size_of_already_saw_data_dl + size_of_the_neddle_dl);

               /*



use the copy, and now
if ok it will be the minimum size if reached there but check
               */

               position_of_the_data_in_the_input__stream_dl += 1;

               progress_dl += 1; // we need the limit for , or it is handled by the first call ?

               hay_ptr_dl += 1;

               len_dl_copy -= 1;

               assert(0 <= len_dl_copy);

               bytes_left_in_the_input_uncompressed_stream_dl -= 1;

               /*








               */

               found_buffer_0_dl = false;

               // here for buffer 0 for the moment
               if ((MIN_STRING_SEARCH_SIZE_DL__ > size_got_of_neddle_dl || cannot_be_largest_string_size_dl))
               {
                    ; // if last item don't search in any memory, it will be deleted soon v12
               }
               else
               {
                    // for the moment just 0

                    process_search_in_passed_buffers_at_once_dl(sliding_window_amanda,
                                                                &found_buffer_0_dl,
                                                                &max_size_string_from_buffer_0,
                                                                &position_found_buffer_0_dl,
                                                                position_of_the_data_in_the_input__stream_dl_original, &new_size_of_neddle_dl);

                    // just use current

                    if (found_buffer_0_dl) // only used here...
                    {

                         assert(MIN_STRING_SEARCH_SIZE_DL__ == size_of_the_neddle_dl); // for safety and no hidden bugs (v8 fixed)
                    }
               }

               /*

               */

               {
                    /*
                                        process_search_in_current_buffer_at_once_dl(buf_dl,
                                                                                    &found_buffer_current_dl,
                                                                                    &max_size_string_from_buffer_current,
                                                                                    &position_found_buffer_current_dl,
                                                                                    position_of_the_data_in_the_input__stream_dl_original,
                                                                                    size_of_already_saw_data_dl,
                                                                                    &adjusted_needle_dl);
                    */
                    // found_buffer_current_dl = false;

                    // size_of_already_saw_data_dl += MIN_STRING_SEARCH_SIZE_DL__;
                    if (found_buffer_0_dl)
                    {

                         if (true)
                         {

                              pedro_dprintf(-1, "max_size_string_from_buffer_0 %d new_size_of_neddle_dl %d",
                                            max_size_string_from_buffer_0,
                                            new_size_of_neddle_dl);
                              // assert(0);
                              past_position_location_dl = (uint16_t)position_found_buffer_0_dl;

                              size_real_for_number_of_characters_up_to_259_dl = (uint16_t)max_size_string_from_buffer_0;

                              size_of_characters_adjusted_to_pass_dl = (int8_t)size_real_for_number_of_characters_up_to_259_dl;

                              // here ric my brother...
                              convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL, // irrelevant
                                                                            0,    // irrelevant
                                                                            true,
                                                                            past_position_location_dl,
                                                                            size_of_characters_adjusted_to_pass_dl,
                                                                            true/*,
                                                                            out_file_dl*/); // v12

                              /*


                              */

                              progress_dl = progress_dl + (new_size_of_neddle_dl - 1); // we need the limit for, or it is handled by the first call ?

                              hay_ptr_dl = hay_ptr_dl + (new_size_of_neddle_dl - 1);

                              position_of_the_data_in_the_input__stream_dl = position_of_the_data_in_the_input__stream_dl + (new_size_of_neddle_dl - 1);

                              len_dl_copy -= (new_size_of_neddle_dl - 1);

                              assert(0 <= len_dl_copy);
                              bytes_left_in_the_input_uncompressed_stream_dl -= (new_size_of_neddle_dl - 1);

                              /*

aqui vamos mover pra frente o item encontrado, ok...vai la

                              */

                              pedro_dprintf(-1, "pos %d",
                                            position_found_buffer_0_dl);
                              {

                                   void remove_string_ar(uint8_t * needle_a,
                                                         int position_a,
                                                         int needle_len_a,
                                                         uint8_t *input_a,
                                                         uint8_t *output_a);

                                   memcpy(slice_amanda_, sliding_window_amanda + position_found_buffer_0_dl,
                                          max_size_string_from_buffer_0);

                                   remove_string_ar(slice_amanda_, position_found_buffer_0_dl, max_size_string_from_buffer_0, sliding_window_amanda, sliding_window_amanda);
                              }
                              goto volta_aqui_mais_alto_mar;

                              /*


                              */
                         }
                    }
               }

               if (DEBUG_DL__)
                    pedro_dprintf(0, "size_of_the_neddle_dl %d", size_of_the_neddle_dl);

               if (DEBUG_DL__)
               {
                    assert(0 && "parando");
               }

               // pula_pra_ca_se_ajustar_size_of_already_saw_data_dl:;

               // adjusting the size of available bytes to the new copied neddle, or it will locate the current neddle being tested, it was a bug in versions of the past

               // the_magic_begins_here__dl:;

               if (true)
               {
                    pedro_dprintf(-1, "salvando byte");
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "nao encontrou entao vai salvar %d bytes, antes de chamar o so far alterado é %d e bits as the number of whole bytes encoded ate agora %d", 1, compressed_and_encoded_bytes_available_11_jan_2022_v6_dl,
                                       number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl);

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }

                    assert(MIN_STRING_SEARCH_SIZE_DL__ >= 1);
                    size_real_for_number_of_characters_up_to_259_dl = (uint16_t)1;

                    // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                    // size_real_for_number_of_characters_up_to_259_dl -= 4;

                    size_of_characters_adjusted_to_pass_dl = (uint8_t)size_real_for_number_of_characters_up_to_259_dl;

                    convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(largest_needle_already_in_buffer_dl, // it will be improved
                                                                  size_of_characters_adjusted_to_pass_dl,
                                                                  false,
                                                                  2022 /* the value of this argument is irrelevant here */,
                                                                  0 /* here too */,
                                                                  false/*,
                                                                  out_file_dl*/); //

                    {

                         memcpy(desloca_buffer_amanda,
                                sliding_window_amanda + 1,
                                V9C_INTERNAL_BUFFER_SIZE_DL_ - 1);

                         desloca_buffer_amanda[V9C_INTERNAL_BUFFER_SIZE_DL_ - 1] = largest_needle_already_in_buffer_dl[0];

                         memcpy(sliding_window_amanda,
                                desloca_buffer_amanda,
                                V9C_INTERNAL_BUFFER_SIZE_DL_);
                    }

                    if (DEBUG_DL__)
                         pedro_dprintf(0, "o so far agora é %d e array of bits as bytes size %d", compressed_and_encoded_bytes_available_11_jan_2022_v6_dl,
                                       number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl);

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }
                    if (0 == 1)
                    // to make the compiler happy
                    {
                         goto volta_aqui_ric;
                    }

                    /*

                    // add the byte dear ric


                    */

                    goto volta_aqui_mais_alto_mar; // just start again (it is v6 based)
               }

               if (0 == 1) // to always make compiler happy
               {
                    goto continua_pro_proximo_buffer_a_ser_lido_dl;
               }

          continua_pro_proximo_buffer_a_ser_lido_dl:;
          }

          fclose(my_file_dl);

          if (out_file_dl)
          {
               fclose(out_file_dl);
               out_file_dl = NULL;
          }
     }

     if (out_file_dl)
     {
          fclose(out_file_dl);
          out_file_dl = NULL;
     }

     free(buf_dl), free(buf_dl_0), free(buf_dl_1), free(buf_dl_2),
         free(sliding_window_amanda), free(buf_dl_compressed), free(buf_dl_bit_buffer);

     printf("Progress ric -> % 4d\n", 100);
     printf("Research running...\n");
     printf("Checksum of the file compressed %08x\n", adler32_real);
     printf("Replacements %d\n", replacements_dl);

     minha_struct.adler32_of_the_uncompressed_data_dl = adler32_real;

     minha_struct.size_of_the_file_to_compress_dl = tamanho_dl;

     if (main_dl(sizeof(minha_struct), (char *)&minha_struct, temp_file_dl, arg_dl_v[3]))
     {
          unlink(temp_file_dl);
          printf("Error in the arithmetic compression, cannot open a file to read or write\n");
          return 27;
     }

     // unlink(temp_file_dl);
     printf("\nDiligent Compressor\n\nVersion of the encoder/decoder -> " STRING_VERSION_DL_COMPRESSOR "\n");
     return 0;

exit_now_ric_dl:;

     strcpy(file_exe_dl, arg_dl_v[0]);

     file_exe_dl2 = strrstr(file_exe_dl, "/"); // for Unix guys
     if (NULL == file_exe_dl2)
          file_exe_dl2 = strrstr(file_exe_dl, "\\");

     if (file_exe_dl2)
     {
     }
     else
     {
          file_exe_dl2 = file_exe_dl;
     }

     printf("\n\nDiligent Compressor\n\nVersion of the encoder/decoder -> " STRING_VERSION_DL_COMPRESSOR "\n\n");
     printf("Usage: %s e <input_file> <output_file>            -- to encode a file\n", file_exe_dl2 + 1);
     printf("Usage: %s d <input_file> <output_file>            -- to decode a file, simple as it...\n", file_exe_dl2 + 1);
     printf("\nIn case of an erroneous decoder, newer or older it will point\n");
     printf("you to the correct version download area on GitHub or sf.net\n");
     printf("Each different version encodes and decodes a single version since v9.c\n");
     exit(27);
}

// it is 09:41 of 13 jan 2022 and the decoder code for dl_compressor just started (first version with a decoder v9.c)

#include "dl_compressor_decoder.c"

// vamos lá

/*

the information below talks about old research information that may have changed or are now irrelevant in v6 version and above



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
