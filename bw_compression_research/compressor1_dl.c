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

void pass_memory_output_dl(uint8_t *mem_dl, int *bytes_out);

void pass_memory_input_dl(uint8_t *mem_dl, int *bytes_in);

int main_do_mr_do(void);

void pedro_dprintf(int amanda_level,
                   char *format, ...);

#define DEBUG_DL__ 0
#define MAX_STRING_SEARCH_SIZE_DL__ (512)
#define MIN_STRING_SEARCH_SIZE_DL__ (10)
#define STRING_PASS_SIZE_DL__ (1)

#define DL_SIZE__ (1L << 15)

// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

/*

We will start with an enhacement over zlib to use less memory and run faster if possible
giving better compression

instead using huffman we will use range code or an optimized version of it, this is a good starting point, huffman is never better than arithmetic coding

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

int main(int arg_dl_c, char **arg_dl_v)
{

     __attribute__((unused)) int len_dl;

     __attribute__((unused)) int len_of_data_to_compress_dl;
     __attribute__((unused)) FILE *my_file_dl = NULL;
     __attribute__((unused)) FILE *out_file_dl = NULL;
     __attribute__((unused)) uint8_t *buf_dl = malloc(DL_SIZE__);

     __attribute__((unused)) double size_d_dl;

     size_d_dl = (double)DL_SIZE__;

     size_d_dl = size_d_dl + (size_d_dl * .3); // more than enough for the moment, for version v4

     __attribute__((unused)) uint8_t *buf_dl_compressed = malloc((int)size_d_dl); // need to be certain that will not store more than 8 to 9 bits on it for the moment, please verify later

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
     out_file_dl = fopen(arg_dl_v[2], "wb");

     if (DEBUG_DL__)
     {
          ; // //assert(0 && "initial position");
     }

     fseek(my_file_dl, 0, SEEK_END);

     tamanho_dl = ftell(my_file_dl);

     fseek(my_file_dl, 0, SEEK_SET);

     progress_dl = 0;

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

          minha_struct.amor_assinatura_dl[0] = 'd';
          minha_struct.amor_assinatura_dl[1] = 'l';
          minha_struct.amor_assinatura_dl[2] = 'd';
          minha_struct.amor_assinatura_dl[3] = 'l';

          //
          /*

          */
          minha_struct.version_of_the_code = 4; // 5º version... initiated at 10 jan 2022 15:54:01

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
                    printf("Progress my fool ric -> % 4d\r", getpor(tamanho_dl, progress_dl));
                    fflush(stdout);
               }

               if (DEBUG_DL__)
                    pedro_dprintf(0, "iniciou novo cliclo ou reiniciou carregamento de dados");

               initial_size_of_string_dl = initial_size_dl; // this will not be used ric...but we will keep, the main search is below, but if restarted it will be here

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

                              minha_struct.compressed_size_dl = bytes_encoded_so_far_dl;

                              minha_struct.uncompressed_size_dl = len_dl;

                              fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);

                              {

                                   int input_size_dl = bytes_encoded_so_far_dl;
                                   int output_size_dl;
                                   uint8_t *out_buf_dl = malloc((bytes_encoded_so_far_dl * 2) + 10000);

                                   pass_memory_output_dl(out_buf_dl, &output_size_dl);

                                   pass_memory_input_dl(buf_dl_compressed, &input_size_dl);

                                   main_do_mr_do();
                                   printf("\n\nCompressed size %d after ari %d uncompressed %d \n", bytes_encoded_so_far_dl, output_size_dl, len_dl);
                                   fflush(stdout);
                                   fwrite(out_buf_dl, 1, output_size_dl, out_file_dl);

                                   free(out_buf_dl);
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

               memcpy(needle_buf_dl, position_of_the_data_in_the_input__stream_dl, size_of_the_neddle_dl);

               position_of_the_data_in_the_input__stream_dl += size_of_the_neddle_dl; // nao tem que lembrar isto em caso de nao achar ?, sim tem que voltar pra cá e com o tamanho certo, precisa de uma cópia, se der atualiza, vai la....

               progress_dl += size_of_the_neddle_dl;

               if (DEBUG_DL__)
                    pedro_dprintf(0, "size of already saw data %d e deslocamento no buffer real %d", size_of_already_saw_data_dl, size_of_already_saw_data_dl + size_of_the_neddle_dl);

               hay_ptr_dl += size_of_the_neddle_dl;

               len_dl_copy -= size_of_the_neddle_dl;

               assert(0 <= len_dl_copy);

               bytes_left_in_the_input_uncompressed_stream_dl -= size_of_the_neddle_dl;

               if (size_of_already_saw_data_dl < MIN_STRING_SEARCH_SIZE_DL__)
               {
                    // just add the data, call the
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "primeiro salvamento de uma olhada");
                    convert_8_bits_to_nine_bits(needle_buf_dl,
                                                size_of_the_neddle_dl,
                                                false, 1969, 2022); // simplesmente adiciona porque é o inicio, agora vamos para as melhorias, primeiro tem que copiar o needle, tem que ter a memoria pra ler tambem,
                    //é  buf_dl mais size_of_already_saw_data_dl, certo?
                    size_of_already_saw_data_dl += size_of_the_neddle_dl;

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

               result_dl = mem_search_dl(buf_dl, size_of_already_saw_data_dl, // nao pode incluir no search o item sendo buscado por isso tem que ser depois
                                         needle_buf_dl, size_of_the_neddle_dl,
                                         0);

               if (DEBUG_DL__)
                    pedro_dprintf(0, "primeira search, achou %lld", result_dl);

               if (DEBUG_DL__)
               {
                    assert(0 && "parando");
               }

               size_of_already_saw_data_dl += size_of_the_neddle_dl;

               // ok, if found it will be added as a position and size

               /*

               int version 3 we will mkae the next search start from the next point that is not the first position, this is a bug in version 2

               */

               if (-1 == result_dl)
               {

                    if (DEBUG_DL__)
                         pedro_dprintf(0, "nao encontrou entao vai salvar %d bytes, antes de chamar o so far é %d ", size_of_the_neddle_dl, bytes_encoded_so_far_dl);

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }

                    convert_8_bits_to_nine_bits(needle_buf_dl,
                                                size_of_the_neddle_dl,
                                                false, 1969, 2022); // simplesmente adiciona porque é o inicio, agora vamos para as melhorias, primeiro tem que copiar o needle, tem que ter a memoria pra ler tambem,
                                                                    //é  buf_dl mais size_of_already_saw_data_dl, certo?

                    if (DEBUG_DL__)
                         pedro_dprintf(0, "o so far agora é %d ", bytes_encoded_so_far_dl);

                    if (DEBUG_DL__)
                    {
                         assert(0 && "parando");
                    }
                    if (0 == 1)
                    // to make the compiler happy
                    {
                         goto volta_aqui_ric;
                    }
                    goto volta_aqui_mais_alto_mar; // perfect
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
                         // here ric my brother...
                         convert_8_bits_to_nine_bits(needle_buf_dl,         // irrelevant
                                                     size_of_the_neddle_dl, // irrelevant
                                                     true,
                                                     last_found_position_dl,
                                                     size_of_last_found_position_dl);

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

                    convert_8_bits_to_nine_bits(needle_buf_dl,
                                                size_of_the_neddle_dl,
                                                true,
                                                result_dl2,
                                                size_of_the_neddle_dl); // done

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

     free(buf_dl);
     free(buf_dl_compressed);

     printf("Progress my fool ric -> % 4d\n", 100);
     printf("\nResearch running...\n");
     printf("\nReplacements %d...\n", replacements_dl);

     return 0;
}

// vamos lá

/*

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