/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>        *
*                                                                             *
*     Este  programa  é software livre: você pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     10
*     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opção) qualquer versão posterior.        *
*                                                                             *
*     Este  programa é distribuído na  esperança que isto vai  ser útil,      *
*     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de      *
*     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Pública para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Pública Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

      E-mails:
      maria@arsoftware.net.br
      pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito rápida) WhatsApp               *
*     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

// 2022 ric - dl

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

// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

// variables and functions defines or constants

int main_dl(char *input_file_dl, char *output_file_dl);

void pedro_dprintf(int amanda_level,
                   char *format, ...);

#define DEBUG_DL__ 0
#define MAX_STRING_SEARCH_SIZE_DL__ (18) /* --- */
#define MIN_STRING_SEARCH_SIZE_DL__ (3)  /* 3 bytes is the smallest size that can be compressed, remember if the string input is less than 3 bytes just store the string without searching for a match, or it will try to add an entry to the pointers with less than 3 and it cannot be stored in our moved initial value that is 0 plus 3 to make 18 (15 max value) (v7) */
#define STRING_PASS_SIZE_DL__ (1)

#define DL_SIZE__ (1L << 12) /* 4096 */

// 88888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

/*

*/

#include "linked_list1_dl.h"
#include "linked_list2_dl.h"

typedef struct dl_dados_salvos_querido_ric__
{

     char amor_assinatura_dl[4];
     char version_of_the_code;
     bool got_compression_dl;
     int uncompressed_size_dl;
     int compressed_size_dl;
     int bits_encoded_size_in_bytes_dl;
     int linked_list_1_size_dl;
     int linked_list_2_size_dl;

} dl_dados_salvos_querido_ric;

// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

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

     return 0;
}
#define uint unsigned int

/**
 * @brief for required progress information, it can be handy for large files since in the research we don't care about speed improvements, at least for the moment (we are testing with make.bin, this is an old version of make.exe that we used for years, zlib can compress it to 85 kb, v6 can compress it to 111kb, but v7 may compress better)
 *
 * @param max the total size of the data
 * @param fatia the slice (fatia in perfect portuguese) to be used in the calculation, I developed this function myself 26 years ago, no Googling for it, at that time Altavista was the search engine to be used or Yahoo search engine
 * @return uint the percentage, range from 0 to 100, can be more than 100 since it is not validated inside the function
 */
uint getpor(int max, uint fatia)
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

// 888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
/**
 * @brief our magic main entry point for our pleasure...
 *
 * @param arg_dl_c the number of arguments for your use
 * @param arg_dl_v the arguments passed to be openned as files this way -> arg_dl_v[2];
 * @return int
 */
int main(int arg_dl_c, char **arg_dl_v)
{
     char temp_file_dl[MAX_PATH + 2];

     __attribute__((unused)) int len_dl;

     __attribute__((unused)) int len_of_data_to_compress_dl;
     __attribute__((unused)) FILE *my_file_dl = NULL;
     __attribute__((unused)) FILE *out_file_dl = NULL;
     __attribute__((unused)) uint8_t *buf_dl = malloc(DL_SIZE__);

     __attribute__((unused)) double size_d_dl;

     size_d_dl = (double)DL_SIZE__;

     size_d_dl = size_d_dl + (size_d_dl * .3); // more than enough for the moment, for version v4

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

     __attribute__((unused)) int len_dl_copy;

     __attribute__((unused)) uint8_t *hay_ptr_dl;

     __attribute__((unused)) static uint8_t needle_buf_dl[MAX_STRING_SEARCH_SIZE_DL__ + 20 /*for safety */];

     __attribute__((unused)) static uint8_t needle_buf_dl_copy[MAX_STRING_SEARCH_SIZE_DL__ + 20 /*for safety */];

     __attribute__((unused)) int64_t result_dl;

     __attribute__((unused)) int64_t result_dl2;

     __attribute__((unused)) int has_itens_is__dl__update_dl_copy;

     __attribute__((unused)) dl_dados_salvos_querido_ric minha_struct = {0};

     __attribute__((unused)) int has_itens_is___rcdl____update__rcdl__ccopy;

     __attribute__((unused)) int initial_size_dl = -1; // to be adjusted later

     __attribute__((unused)) int progress_dl, tamanho_dl, delocador_fix_bug_in_version_2_0_dl;

     __attribute__((unused)) ULONGLONG update_me_dl = 0;

     if (3 != arg_dl_c)
     {
          printf("Usage <input_file> <output_file>\n");
          exit(27);
     }

     unlink(arg_dl_v[2]);
     my_file_dl = fopen(arg_dl_v[1], "rb");

     strcpy(temp_file_dl, arg_dl_v[2]);

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

     fseek(my_file_dl, 0, SEEK_END);

     tamanho_dl = ftell(my_file_dl);

     fseek(my_file_dl, 0, SEEK_SET); // we don't have time to use our standard size get function at this moment, time is important in research

     progress_dl = 0; // progress may help when compressing files with research code that normally is not optimized for speed

     if (my_file_dl)
     {
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

          minha_struct.version_of_the_code = 7; // 8th version... initiated at 12 jan 2022 10:49:08
          /*

........... (10:49) I should be sleeping but just figured out that the rle
........... problem need to be solved yet today, because files
........... highly compressible don't compress well as pure rle
........... More on it in two hours

........... v8 development started (11:27), first we will make the code 
........... compress highly compressible files very well
........... I don't remember about the instrinsics of zlib 
........... but the sources talk about rle enconding and 
........... standard lzss and our modified lz77 compress 
........... up to 18 characters strings to two bytes plus a bit 
........... Working on it, for it we will add a very large high
........... compressible file and add to the tests 

........... (11:50) Even without rle on it the compressor can dimish a 30 kb file 
........... to 300 bytes, maybe it will not be a problem

........... Interesting tar_1_33.c:
...........                         zip          : 59kb
...........                         lzss + ari   : 74kb
...........                         dl_compressor: 83kb
........... A lot need to be enhanced yet
...........


          */
          minha_struct.version_of_the_code = 6; // 7th version... initiated at 12 jan 2022 05:35:02
          /*

          we have an idea of trying to compress 3 bytes in two using the standard lzss method of handling 4096
          bytes in the sliding window but in a lz77 method

          depending on the file it will achieve more compression than our v6 method that was not perfect but
          already can compress better than many compressors available in research papers

          as you may examinate the v6 method can compress up to 4 bytes in 3,
          this is the maximum for the minimum size
          and up to 255 characters in a string for maximum size but we saw that this is irrelevant to the majority
          of files, and standard lzss method encode at the maximum 18 characters string to 2 bytes and it is better than our v6 compressor

          well here now with version v7 we will try to compress using 12 bits for adressing (4096 bytes) and four bits (16 possible values startinr from the minimum size that is 3 gives 18 as the maximum size)

          this allow for a whole buffer like lz77 as 4096, lets see how it compresses...

          coding time... (05:42:09)

          to don't waste time we will keep for the moment the v6 variables in the code, even if not in use, blame us for this

          happilly developed with VSCode: (but we may be forced to use Emacs for windows for some unknown reason)

          begin ---

          VSCode Version: 1.63.2
          Commit: 899d46d82c4c95423fb7e10e68eba52050e30ba3
          Date: 2021-12-15T09:40:02.816Z
          Electron: 13.5.2
          Chromium: 91.0.4472.164
          Node.js: 14.16.0
          V8: 9.1.269.39-electron.0
          OS: Windows_NT x64 10.0.19042

          end ---

...........
........... From my point of view v7 need to compress as good as lzss,
........... since the idea was based on it, the size and method are
........... almost the same but without a sliding window only the
........... real input buffer from where the string to match are
........... searched
...........

            begin of modification, will adjust the buffers (07:03)

........... We did it (08:59), v6 compresses make.bin to 111 kb and version
........... v7 compresses to 92 kb, the original lzss compresses to
........... 90 kb and zip compresses to 85 kb, the difference is that
........... our code that is compressing to 92 kb now have a lot
........... of room to improve
...........
........... By tomorrow we will have a compressor better than lzss
...........
........... Now that the code is ready compare the v7 code with 'LZSS.c'
........... available in the subfolder './lzss to learn' and see what
........... version is more easy to be understood
...........
........... Notice that our code is not exactly lzss, it don't search on
........... a sliding window but on the input data to compress, from 0 to
........... the last byte (4096), and it is already compressing as good
........... as original lzss...
...........
........... Just will add the arithmetic compression to the code to
........... avoid the requirement of the call to ari.exe after the call
........... It will help, and will be a simple call without ari.exe
...........
........... Just removed the overhead of the additional struct and
........... the size of the compressed file now is 91 kb
...........
........... And now the arithmetic compressor is already inside, no need
........... to call ari.exe after the compression
...........
........... In one hour we will start the development of the v8
........... Need to rest for a while (10:28)
........... end of v7 updates...

          */

          // minha_struct.version_of_the_code = 5; // 6º version... initiated at 11 jan 2022 03:53:01

          /*

               After reading a few papers we saw that we are trying to compress to much large strings that are not common
               As an example our version 5 from yeasterday will try to compress strings up to 512 characters on it
               while lzss will compress up to 18 characters on a string, and compressed better than our implementation
               Also we are wasting too much space at this moment, while lzss will expand only one bit for each not compressible character and more 1 bit for position and lenght stored in two bytes for a maximum of
               4096 bytes sliding window addressable using 12 bits, plus for to the lenght

               we will try to use these ideas in our compressor, for the moment the size of the data to compress is slices of (1 << 15) 32 kb then we need more than 12 bits to make a position on the passed data

               Michael Dipperstein from https://michaeldipperstein.github.io/lzss.html have very interesting papers and code and advanced documentation about lzss and we will borrow some ideas

               also we will try to compress strings up to 3 bytes of size or four, and not 10 as the v5 code and below, also, we will not waste time searching for strings larger than 20 characters on it, indeed it will be the limit for the moment

               after the strings replaces arithmetic compression will be applied to gather some bytes on the final size

               so lets code (04:04:01 day 11 jan)

               first we will start modifying the function convert_8_bits_to_nine_bits to encode using the smallest possible size for a maximum window of (1 << 15)

               also we will borrow the idea from Michael to use bit encode as whole bytes and just pass it later to the stream in a predefined struct as header, this idea we used in 2009 in our advanced rle compressor modified

               to increase compression we will use the smallest possible size to store data as we learned with lzss

               now allocating memory to the arrays of bits as bytes it will be up to 1 bit more for each byte to encode the size = size + (size * .2) will be enough, let we implement it

               also the arithmetic compression can work on the whole file and not in the 32 kb slice for better
               compression, but we will take care of this later, first we need to create an advanced strings search and replace mode

               lets code...

               during debug for the moment we will use the external arithmetic compressor, no need to use it internally now, only later

               well, bit handling rountine was added, now what we will do is adapt a ls77 and lz77 together
               to see if it work, we will not use a sliding window but the current buffer so far to store
               the data encoded in the compressed stream with a sequence of encoded bytes that require plus one bit in the bit stream or a sequence of pointer to the passed data with position and size limited to a window of 32 kb perfectly

               lets code, first we need to generate the adjusts for the size of data to store in case of a pointer in the passed data

               lets go...



          */

          // minha_struct.version_of_the_code = 4; // 5º version... initiated at 10 jan 2022 15:54:01

          /*

          Version 4 was now fast but yet dont compress very well on not very compressible files, version 5 will enable
          arithmetic compression to see whether is more easy to make comparisons

          the zlib do huffman compression not only string search, interesting would be to see how it adjusts
          strings and how to compare it without additional compression, maybe disabling huffman in the compression in
          zlib

          more code...

          */
          // minha_struct.version_of_the_code = 3; // 4º version... initiated at 10 jan 2022 10:05:00

          /* 4º version information, we will change the double linkd
          list compression method that failed with a method that will
          try to locate the maximum size of the current string in
          the previous buffer, if found it will mark the size and position
          in the passed string, now it 10:07 hs, hope to have it working
          before 14:00 hs

          for this we will not use a linked list but preallocated memory for the required size that is slightly larger than the input uncompressed string, and will just be adding data to it in the processed form

          more code... (10:12), description of changes will follow

          added the resulting memory with the compressed data, in the function convert_8_bits_to_nine_bits the
          hard work will be done..., variable buf_dl_compressed holds the compressed stream, first we will focus on the compression, it need to compress, fast and well, then later we write the uncompressor

          for the moment we will just not use the arithmetic compression, because what we need is to achieve
          compression with the strings replacement, later we use it
          when working dl_compressor will be part of the Parolin project, the extension will be .dl

          more code...

          we will just go modifying code from version 3 to match version 4 requirements

          */

          // minha_struct.version_of_the_code = 2; // 3º version... initiated at 10 jan 2022 02:00:00

          printf("\n\n");

          replacements_dl = 0;

          while ((len_dl = fread(buf_dl, 1, DL_SIZE__, my_file_dl)))
          {
               if (DEBUG_DL__)
                    pedro_dprintf(0, "initial buffer have %d bytes", len_dl);

               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "file read data");
               }

               /*


                    char amor_assinatura_dl[4];
                    char version_of_the_code;
                    bool got_compression_dl;
                    int uncompressed_size_dl;
                    int linked_list_1_size_dl;
                    int linked_list_2_size_dl;



               */
               minha_struct.uncompressed_size_dl = len_dl;
               /*
                              for (i_i_dl = 0; i_i_dl < len_dl; i_i_dl++)
                              {
                                   buf16_dl[i_i_dl] = (int16_t)buf_dl[i_i_dl];
                              }
               */

               /*

               */

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

               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "primeiros passos");
               }

               ; // //assert(0 <= len_dl_copy); // uma segurança a mais...

               if (0 == len_dl_copy)
               {
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "passo final agora é só salvar os dados das duas linked lists");

                    if (DEBUG_DL__)
                    {
                         assert(0 && "last step");
                    }
                    // oque faz, tem que processar nao é isso?, sim, mas agora?, sim, entao ta...
                    /*

                         somente copia o conteudo das duas linked lists nao é isso ?, precisa dos dois dados ja na saida pra poder criar as duas entradas no header

                    */

                    {
                         if (true /* || size_of_the_second_compressed_stream_dl + size_of_the_first_compressed_stream_dl < len_dl*/) //é so o primeiro tem que ver o segundo, sim é isso
                         {
                              // if (DEBUG_DL__)
                              /*
                              printf("\n\nAchieved compression -> %d, uncompressed size -> %d\n", size_of_the_second_compressed_stream_dl + size_of_the_first_compressed_stream_dl, len_dl);
                              */
                              if (DEBUG_DL__)
                              {
                                   ; // //assert(0 && "conseguiu comprimir");
                              }
                              // got compression
                              /*

                                   char amor_assinatura_dl[4];//ok
                                   char version_of_the_code;
                                   bool got_compression_dl;
                                   int uncompressed_size_dl;
                                   int linked_list_1_size_dl;
                                   int linked_list_2_size_dl;

                              */
                              // first adjust the headers...
                              minha_struct.got_compression_dl = true;

                              minha_struct.compressed_size_dl = compressed_and_encoded_bytes_available_11_jan_2022_v6_dl;

                              minha_struct.bits_encoded_size_in_bytes_dl = number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl;

                              if (requires_last_byte_11_jan_2022_v6_dl)
                              {
                                   minha_struct.bits_encoded_size_in_bytes_dl++; // fixed already only need to save the last byte if required
                                   (*ptr_position_for_bit_memory_dl) = current_byte_being_generated_11_jan_2022_v6_byte_dl;
                                   ptr_position_for_bit_memory_dl++;
                                   // saving the last byte if required
                              }

                              size_of_compressed_buffer2_dl_int = compressed_and_encoded_bytes_available_11_jan_2022_v6_dl;

                              assert((1 << 15) > size_of_compressed_buffer2_dl_int);

                              size_of_compressed_buffer_dl = size_of_compressed_buffer2_dl_int;

                              size_of_compressed_buffer2_dl_int = minha_struct.bits_encoded_size_in_bytes_dl;

                              assert((1 << 15) > size_of_compressed_buffer2_dl_int);

                              size_of_compressed_buffer2_dl = size_of_compressed_buffer2_dl_int;
                              // fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);

                              {
                                   /*
                                   int input_size_dl = bytes_encoded_so_far_dl;
                                   int output_size_dl;
                                   uint8_t *out_buf_dl = malloc((bytes_encoded_so_far_dl * 2) + 10000);

                                   pass_memory_output_dl(out_buf_dl, &output_size_dl);

                                   pass_memory_input_dl(buf_dl_compressed, &input_size_dl);

                                   main_do_mr_do();
                                   */
                                   /*
                                    printf("Compressed size %d uncompressed %d ", number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl + compressed_and_encoded_bytes_available_11_jan_2022_v6_dl, len_dl);
                                    printf(" - Buffer bytes %d bits arrays size %d \n", compressed_and_encoded_bytes_available_11_jan_2022_v6_dl, number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl);

                                    fflush(stdout);
                                    */

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
                         else
                         {
                              printf("\n\nDon't got compression, size uncompressed %d\n", len_dl);
                              fflush(stdout);
                              if (DEBUG_DL__)
                              {
                                   ; // //assert(0 && "dont get compression");
                              }
                              // just save the uncompressed stream and go on to the next
                              minha_struct.got_compression_dl = false; // it is ok..., no compression occurred flag got_compression_dl solves the problem

                              minha_struct.linked_list_1_size_dl = len_dl;
                              minha_struct.linked_list_2_size_dl = 0;

                              fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);

                              fwrite(buf_dl, 1, len_dl, out_file_dl);
                              if (DEBUG_DL__)
                                   pedro_dprintf(0, "exiting, will restart again");

                              if (DEBUG_DL__)
                              {
                                   ; // //assert(0 && "exiting...");
                              }
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

               size_of_the_neddle_dl = min(bytes_left_in_the_input_uncompressed_stream_dl, initial_size_of_string_dl);
               size_got_of_neddle_dl = size_of_the_neddle_dl;
               memcpy(needle_buf_dl, position_of_the_data_in_the_input__stream_dl, size_of_the_neddle_dl);

               position_of_the_data_in_the_input__stream_dl += size_of_the_neddle_dl; // nao tem que lembrar isto em caso de nao achar ?, sim tem que voltar pra cá e com o tamanho certo, precisa de uma cópia, se der atualiza, vai la....

               progress_dl += size_of_the_neddle_dl;

               if (DEBUG_DL__)
                    pedro_dprintf(0, "size of already saw data %d e deslocamento no buffer real %d", size_of_already_saw_data_dl, size_of_already_saw_data_dl + size_of_the_neddle_dl);

               hay_ptr_dl += size_of_the_neddle_dl;

               len_dl_copy -= size_of_the_neddle_dl;

               assert(0 <= len_dl_copy);

               bytes_left_in_the_input_uncompressed_stream_dl -= size_of_the_neddle_dl;

               if (size_of_already_saw_data_dl < MIN_STRING_SEARCH_SIZE_DL__) // must be 0 at the begining in version v6, it works for strings very small? needs a small limit, at least 5 bytes
               {
                    // just add the data, call the
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "primeiro salvamento de uma olhada, size of the needle must be 4 %d", size_of_the_neddle_dl);
                    /*




                    */

                    // it will encode the string adding one bit for each character of the string in this initial case 4 (in v6)

                    size_real_for_number_of_characters_up_to_259_dl = (uint16_t)size_of_the_neddle_dl;

                    // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                    // size_real_for_number_of_characters_up_to_259_dl -= 4;

                    size_of_characters_adjusted_to_pass_dl = (uint8_t)size_real_for_number_of_characters_up_to_259_dl;

                    convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(needle_buf_dl,
                                                                  size_of_characters_adjusted_to_pass_dl,
                                                                  false,
                                                                  1969 + 2022, // just a joke..., this here is irrelevant, due to the 'false' in the past argument
                                                                  0);          //

                    size_of_already_saw_data_dl += size_of_the_neddle_dl; // adjusting even if first string added... (in v6)

                    if (DEBUG_DL__)
                         pedro_dprintf(0, "ja salvou");

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }
                    goto volta_aqui_mais_alto_mar;
               }

               if (DEBUG_DL__)
                    pedro_dprintf(0, "tamanho de size_of_already_saw_data_dl antes search 1 %d", size_of_already_saw_data_dl);

               result_dl = mem_search_dl(buf_dl, size_of_already_saw_data_dl, // nao pode incluir no search o item sendo buscado por isso tem que ser depois, isto tambem na versao v6, senao claro ele vai ser sempre encontrado, he he he
                                         needle_buf_dl, size_of_the_neddle_dl,
                                         0);

               if (DEBUG_DL__)
                    pedro_dprintf(0, "primeira search, achou %lld", result_dl);

               if (DEBUG_DL__)
               {
                    assert(0 && "parando");
               }

               size_of_already_saw_data_dl += size_of_the_neddle_dl; // adjusting the size of available bytes to the new copied neddle, or it will locate the current neddle being tested, it was a bug in versions of the past

               if (MIN_STRING_SEARCH_SIZE_DL__ > size_got_of_neddle_dl)
               {
                    result_dl = -1; // fix the bug, the code must work, lets test
               }

               if (-1 == result_dl)
               {

                    if (DEBUG_DL__)
                         pedro_dprintf(0, "nao encontrou entao vai salvar %d bytes, antes de chamar o so far alterado é %d e bits as the number of whole bytes encoded ate agora %d", size_of_the_neddle_dl, compressed_and_encoded_bytes_available_11_jan_2022_v6_dl,
                                       number_of_encoded_bytes_resulting_of_encoding_bits_requires_the_last_byte_in_some_cases_11_jan_2022_v6_dl);

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }

                    // if not found just store in the compressed stream as it is, addicional bit (0 as the value, 1 for pointers in the passed stream if this is the case) will be added for each character in the string
                    size_real_for_number_of_characters_up_to_259_dl = (uint16_t)size_of_the_neddle_dl;

                    // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                    // size_real_for_number_of_characters_up_to_259_dl -= 4;

                    size_of_characters_adjusted_to_pass_dl = (uint8_t)size_real_for_number_of_characters_up_to_259_dl;

                    convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(needle_buf_dl,
                                                                  size_of_characters_adjusted_to_pass_dl,
                                                                  false,
                                                                  2022 /* the value of this argument is irrelevant here */,
                                                                  0 /* here too */); //

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
                    goto volta_aqui_mais_alto_mar; // just start again (it is v6 based)
               }
               else
               {
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "encontrou entao agora vai tentar achar maior");

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }

                    /*


                    here try different ideas

                    */
                    if (0 == 1)
                    {
                         goto try_more_ric;
                    }

                    size_of_the_neddle_dl2 = size_of_the_neddle_dl;

                    result_dl2 = result_dl;

               try_more_ric:;

                    if (DEBUG_DL__)
                         pedro_dprintf(0, "retornando size current is %d", size_of_the_neddle_dl2);

                    if (DEBUG_DL__)
                    {
                         // assert(0 && "parando");
                    }

                    if (MAX_STRING_SEARCH_SIZE_DL__ > size_of_the_neddle_dl2)
                    {

                         size_of_the_neddle_dl2 += STRING_PASS_SIZE_DL__; // mais tarde da para ajustar isso

                         if (MAX_STRING_SEARCH_SIZE_DL__ < size_of_the_neddle_dl2)
                         {
                              size_of_the_neddle_dl2 = MAX_STRING_SEARCH_SIZE_DL__;
                         }
                         // try with more data, better keep it here
                         size_of_the_neddle_dl3 = min(bytes_left_in_the_input_uncompressed_stream_dl_original, size_of_the_neddle_dl2);

                         if (size_of_the_neddle_dl3 == size_of_the_neddle_dl2) // more itens found, need to adjust if found
                         {
                              ; // do

                              memcpy(needle_buf_dl_copy, position_of_the_data_in_the_input__stream_dl_original, size_of_the_neddle_dl3);

                              // now search
                              if (DEBUG_DL__)
                                   pedro_dprintf(0, "valor do size_of_already_saw_data_dl_original %d, neddle size %d", size_of_already_saw_data_dl_original, size_of_the_neddle_dl3);
                              result_dl = mem_search_dl(buf_dl, size_of_already_saw_data_dl_original,
                                                        needle_buf_dl_copy, size_of_the_neddle_dl3,
                                                        0);

                              if (-1 == result_dl)
                              {
                                   goto end_of_search_my_ric; // if not found larger stop here
                              }
                              else
                              {
                                   ; // here adjust, if no more is found it is already ready to adjust

                                   already_found_with_larger_size_dl = true;
                                   difference_of_the_new_loaded_data_dl = (size_of_already_saw_data_dl_original + size_of_the_neddle_dl3) - size_of_already_saw_data_dl;

                                   last_found_position_dl = result_dl;
                                   size_of_last_found_position_dl = size_of_the_neddle_dl3;
                                   goto try_more_ric;
                              }
                         }
                         else
                         {
                              goto end_of_search_my_ric;
                         }
                    }

                    if (DEBUG_DL__)
                         pedro_dprintf(0, "definiu que o maior achado é %d", size_of_the_neddle_dl2);

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }

               end_of_search_my_ric:;
                    if (already_found_with_larger_size_dl) // need to remove
                    {

                         past_position_location_dl = (uint16_t)last_found_position_dl;

                         size_real_for_number_of_characters_up_to_259_dl = (uint16_t)size_of_last_found_position_dl;

                         // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                         // adjusting
                         // size_real_for_number_of_characters_up_to_259_dl -= 4;

                         size_of_characters_adjusted_to_pass_dl = (int8_t)size_real_for_number_of_characters_up_to_259_dl;

                         // here ric my brother...
                         convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL, // irrelevant
                                                                       0,    // irrelevant
                                                                       true,
                                                                       past_position_location_dl,
                                                                       size_of_characters_adjusted_to_pass_dl);

                         size_of_already_saw_data_dl += difference_of_the_new_loaded_data_dl;

                         position_of_the_data_in_the_input__stream_dl += difference_of_the_new_loaded_data_dl;

                         progress_dl += difference_of_the_new_loaded_data_dl;

                         hay_ptr_dl += difference_of_the_new_loaded_data_dl;

                         len_dl_copy -= difference_of_the_new_loaded_data_dl;

                         assert(0 <= len_dl_copy);

                         bytes_left_in_the_input_uncompressed_stream_dl -= difference_of_the_new_loaded_data_dl;

                         already_found_with_larger_size_dl = false;
                         // when searching just change the size of the needle, if already found

                         if (DEBUG_DL__)
                              pedro_dprintf(0, "vai reiniciar o loop, bytes remaining %d", len_dl_copy);

                         if (DEBUG_DL__)
                         {
                              assert(0 && "parando");
                         }
                         goto volta_aqui_mais_alto_mar;
                    }

                    // oque há de errado?, ta tudo certo, se nao achar nada nao faz nada se achar vai reajustando a cada caminhada entendeu

                    if (DEBUG_DL__)
                         pedro_dprintf(0, "nao pode achar maior entao vai usar oque achou, size %d, pos %lld", size_of_the_neddle_dl, result_dl2);

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }

                    past_position_location_dl = (uint16_t)result_dl2;

                    size_real_for_number_of_characters_up_to_259_dl = (uint16_t)size_of_the_neddle_dl;

                    if (DEBUG_DL__)
                    pedro_dprintf(0, "size %d", size_of_the_neddle_dl);
                    // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                    // size_real_for_number_of_characters_up_to_259_dl -= 4;

                    size_of_characters_adjusted_to_pass_dl = (uint8_t)
                        size_real_for_number_of_characters_up_to_259_dl;

                    convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL,
                                                                  0,
                                                                  true,
                                                                  past_position_location_dl,
                                                                  size_of_characters_adjusted_to_pass_dl); // done (v6), now debug

                    goto volta_aqui_mais_alto_mar;
               }

               if (0 == 1)
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

     free(buf_dl), free(buf_dl_compressed), free(buf_dl_bit_buffer);

     printf("Progress ric -> % 4d\n", 100);
     printf("Research running...\n");
     printf("Replacements %d\n", replacements_dl);

     if (main_dl(temp_file_dl, arg_dl_v[2]))
     {
          unlink(temp_file_dl);
          printf("Error in the arithmetic compression, cannot open a file to read or write\n");
          return 27;
     }

     unlink(temp_file_dl);
     printf("\nVersion of the encoder -> v8 (12 jan 2022 11:29)\n");
     return 0;
}

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