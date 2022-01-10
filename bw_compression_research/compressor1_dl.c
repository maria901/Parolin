/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*        Licensa de C�pia (C) <2022>  <Corpora��o do Trabalho Bin�rio>        *
*                                                                             *
*     Este  programa  � software livre: voc� pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como     10
*     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da      *
*     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.        *
*                                                                             *
*     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,      *
*     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de      *
*     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral P�blica para mais detalhes.                               *
*                                                                             *
*     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa P�blica Menor junto com este programa                           *
*     Se n�o, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

      E-mails:
      maria@arsoftware.net.br
      pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito r�pida) WhatsApp               *
*     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                *
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
 * @brief it will add and entry to the first linked list that will store strings that cannot be compressed and entries in the second linked list that holds the strings that repeat on the whole memory
 *
 */
void add_more_one_is__dl__update_dl(__attribute__((unused)) uint8_t *memory_for_string_dl,
                                    __attribute__((unused)) int len_of_memory_dl,
                                    __attribute__((unused)) int number_of_index_in_linked_list_dl, // if in linked list only need this, dont you agree?
                                    __attribute__((unused)) bool true_if_is_entry_in_the_linked_list_dl);

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

#define DL_SIZE__ (1L << 15)

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

     __attribute__((unused)) static uint8_t needle_buf_dl[513];

     __attribute__((unused)) int64_t result_dl;

     __attribute__((unused)) int has_itens_is__dl__update_dl_copy;

     __attribute__((unused)) int size_of_the_first_compressed_stream_dl;

     __attribute__((unused)) int size_of_the_second_compressed_stream_dl;

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

          initial_size_dl = 512; // more itens are based in this value

          initial_size_of_string_dl = initial_size_dl; // to be adjusted later...

          minha_struct.amor_assinatura_dl[0] = 'd';
          minha_struct.amor_assinatura_dl[1] = 'l';
          minha_struct.amor_assinatura_dl[2] = 'd';
          minha_struct.amor_assinatura_dl[3] = 'l';

          //
          /*

















          */

          // minha_struct.version_of_the_code = 2; // 3� version... initiated at 10 jan 2022 02:00:00

          minha_struct.version_of_the_code = 3; // 4� version... initiated at 10 jan 2022 10:05:00

          /* 4� version information, we will change the double linkd
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

          printf("\n\n");

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
               index_position_second_linked_list_dl = 0; // to keep track of the index of the second linked list
               bitposition_dl = 0;                       // to init the bit encode...
               last_byte_encoded_value_dl = 0;
               is_it_the_first_byte_to_encode_dl = true;

               delocador_fix_bug_in_version_2_0_dl = 0;

               // em search code, to detect where the code is
               len_dl_copy = len_dl;

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

          volta_aqui_mais_alto_mar:; // sim � alguem, duas mar...

               // se funcionar o contrario vai ser mais rapido mas ai sera versao 3 ok...
               if (update_me_dl < GetTickCount64())
               {
                    update_me_dl = GetTickCount64() + 50;
                    printf("Progress my fool ric -> % 4d\r", getpor(tamanho_dl, progress_dl));
                    fflush(stdout);
               }

               if (DEBUG_DL__)
                    pedro_dprintf(0, "iniciou novo cliclo ou reiniciou carregamento de dados");
               initial_size_of_string_dl = initial_size_dl;
               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "primeiros passos");
               }

               ; // //assert(0 <= len_dl_copy); // uma seguran�a a mais...

               if (0 == len_dl_copy)
               {
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "passo final agora � s� salvar os dados das duas linked lists");

                    if (DEBUG_DL__)
                    {
                         ; // //assert(0 && "last step");
                    }
                    // oque faz, tem que processar nao � isso?, sim, mas agora?, sim, entao ta...
                    /*

                         somente copia o conteudo das duas linked lists nao � isso ?, precisa dos dois dados ja na saida pra poder criar as duas entradas no header

                    */

                    {
                         __attribute__((unused)) struct my_struct_for_list_ar_is__dl__update_dl *my_ptr_ar;

                         __attribute__((unused)) struct my_struct_for_list_ar_is__dl__update_dl *my_ptr2_ar;

                         my_ptr2_ar = aak_inicio_is__dl__update_dl;

                         my_ptr_ar = aak_inicio_is__dl__update_dl;

                         size_of_the_first_compressed_stream_dl = 0;

                         has_itens_is__dl__update_dl_copy = has_itens_is__dl__update_dl;

                         if (0 == has_itens_is__dl__update_dl_copy)
                         {
                              copy_last_item_is_required__dl = false;
                         }

                    inicio_ar:;
                         if (!has_itens_is__dl__update_dl_copy)
                         {
                              if (DEBUG_DL__)
                                   pedro_dprintf(0, "loopeando na leitura da primeira linked list, pegando o tamanho de dados a serem salvos");

                              if (DEBUG_DL__)
                              {
                                   ; // //assert(0 && "primeira leitura da primeira linked list");
                              }
                              // has_itens_copy_is__dl__update_dl = 0;
                              goto exit_now_dl;
                         }
                         my_ptr2_ar = my_ptr_ar;
                         my_ptr_ar = my_ptr_ar->next_ar;

                         /*

                              here the process occur with the variable my_ptr2_ar

                              ok, next step? ric...

                              we need to gather the size of the compressed stream of the first linked list, go on

                         */

                         size_of_the_first_compressed_stream_dl += my_ptr2_ar->bytes_encoded_so_far_dl;

                         copy_last_item_is_required__dl = my_ptr2_ar->last_item_is_required_dl;

                         last_item_or_montagem_dl = my_ptr2_ar->montagem_dl_interno;

                         has_itens_is__dl__update_dl_copy--;
                         goto inicio_ar;

                         /*



                         you need to free the linked lists at the end of execution ric...



                         */

                    exit_now_dl:;
                         if (DEBUG_DL__)
                              pedro_dprintf(0, "ja tem o tamanho da primeira linked list -> %d", size_of_the_first_compressed_stream_dl);

                         if (DEBUG_DL__)
                         {
                              ; // //assert(0 && "ja pegou o tamanho da primeira linked list");
                         }
                         if (copy_last_item_is_required__dl) // se tiver isto adiciona o no buffer size ja esta certo
                         {
                              if (DEBUG_DL__)
                                   pedro_dprintf(0, "adicionando mais um byte porque o ultimo byte nao esta completo ainda");

                              if (DEBUG_DL__)
                              {
                                   ; // //assert(0 && "adicionando ultimo byte");
                              }
                              size_of_the_first_compressed_stream_dl++;
                         }
                         // here call the finish for the first linked list, since we need the value for the header we need to call it twice, in a near future we optimize it..., we will use encode to already define the size of the output first linked list, do it, during the first pass we already encode the data with 9 bits, go on
                    }

                    // concatena ou checa primeiro se comprime ? cheque primeiro
                    {

                         struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *my_ptr_ar;

                         struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *my_ptr2_ar;

                         my_ptr2_ar = aak_inicio_is___rcdl____update__rcdl__;

                         my_ptr_ar = aak_inicio_is___rcdl____update__rcdl__;

                         size_of_the_second_compressed_stream_dl = 0;
                         // pode reaproveitar este item ?, sim...
                         has_itens_is___rcdl____update__rcdl__ccopy = has_itens_is___rcdl____update__rcdl__;

                    inicio_arrrr2:;
                         if (!has_itens_is___rcdl____update__rcdl__ccopy)
                         {
                              if (DEBUG_DL__)
                                   pedro_dprintf(0, "loopeando na segunda linked list para pegar o tamanho dela ");

                              if (DEBUG_DL__)
                              {
                                   ; // //assert(0 && "leitura da segunda linked list");
                              }
                              // has_itens_copy_is___rcdl____update__rcdl__ = 0;
                              goto fim_rrr2;
                         }
                         my_ptr2_ar = my_ptr_ar;
                         my_ptr_ar = my_ptr_ar->next_ar;
                         /*
                         if (1 == has_itens_is___rcdl____update__rcdl__)
                         {
                              free(my_ptr2_ar->next_ar);
                         }
                         */

                         size_of_the_second_compressed_stream_dl += my_ptr2_ar->len_of_memory_dl + 4 + 4; // acho que � isso

                         // free(my_ptr2_ar->string_saved_dl); // ta aqui
                         // free(my_ptr2_ar);
                         has_itens_is___rcdl____update__rcdl__ccopy--;
                         goto inicio_arrrr2;

                    fim_rrr2:;
                         if (DEBUG_DL__)
                              pedro_dprintf(0, "ja pegou o tamanho da segunda linked list -> %d, esta nao tem byte adicional", size_of_the_second_compressed_stream_dl);

                         if (DEBUG_DL__)
                         {
                              ; // //assert(0 && "leitura da segunda linked list");
                         }
                    }

                    {
                         if (true || size_of_the_second_compressed_stream_dl + size_of_the_first_compressed_stream_dl < len_dl) //� so o primeiro tem que ver o segundo, sim � isso
                         {
                              // if (DEBUG_DL__)
                              printf("\n\nAchieved compression -> %d, uncompressed size -> %d\n", size_of_the_second_compressed_stream_dl + size_of_the_first_compressed_stream_dl, len_dl);

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
                              /*
                                                            minha_struct.linked_list_1_size_dl = size_of_the_first_compressed_stream_dl;
                                                            minha_struct.linked_list_2_size_dl = size_of_the_second_compressed_stream_dl;

                                                            fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);
                                                            */

                              uint8_t *buf_in_dl = malloc((len_dl * 2) + 10000);
                              uint8_t *ptr_in_buf = buf_in_dl;
                              uint8_t *buf_out_dl = malloc((len_dl * 2) + 10000);
                              // assert(0 && "1");
                              int bytes_in_dl = 0;

                              int bytes_out_dl = 0; // will be fixed later inside ari function

                              if (DEBUG_DL__)
                                   pedro_dprintf(0, "salvou as primeiras informacoes da estrutura");

                              if (DEBUG_DL__)
                              {
                                   ; // //assert(0 && "salvando estrutura");
                              }
                              {
                                   __attribute__((unused)) struct my_struct_for_list_ar_is__dl__update_dl *my_ptr_ar;

                                   __attribute__((unused)) struct my_struct_for_list_ar_is__dl__update_dl *my_ptr2_ar;

                                   my_ptr2_ar = aak_inicio_is__dl__update_dl;

                                   my_ptr_ar = aak_inicio_is__dl__update_dl;

                                   // size_of_the_first_compressed_stream_dl = 0;

                                   has_itens_is__dl__update_dl_copy = has_itens_is__dl__update_dl;

                              inicio_ar4:;
                                   if (!has_itens_is__dl__update_dl_copy)
                                   {
                                        if (DEBUG_DL__)
                                             pedro_dprintf(0, "loopeando na primeira linked lista para pegar os dados");

                                        if (DEBUG_DL__)
                                        {
                                             ; // //assert(0 && "loopeando na primeira linked list para salvar os dados");
                                        }
                                        // has_itens_copy_is__dl__update_dl = 0;
                                        goto exit_now_dl3;
                                   }
                                   my_ptr2_ar = my_ptr_ar;
                                   my_ptr_ar = my_ptr_ar->next_ar;

                                   /*

                                        here the process occur with the variable my_ptr2_ar

                                        ok, next step? ric...

                                        we need to gather the size of the compressed stream of the first linked list, go on

                                   */
                                   /*
                                                                      fwrite(my_ptr2_ar->output_memory_for_string_dl, 1, my_ptr2_ar->bytes_encoded_so_far_dl, out_file_dl);
                                                                      */

                                   memcpy(ptr_in_buf, my_ptr2_ar->output_memory_for_string_dl, my_ptr2_ar->bytes_encoded_so_far_dl);

                                   ptr_in_buf += my_ptr2_ar->bytes_encoded_so_far_dl;

                                   bytes_in_dl += my_ptr2_ar->bytes_encoded_so_far_dl;

                                   if (DEBUG_DL__)
                                        pedro_dprintf(0, "primeira linked list salvou %d bytes", my_ptr2_ar->bytes_encoded_so_far_dl);

                                   if (DEBUG_DL__)
                                   {
                                        ; // //assert(0 && "salvou dados");
                                   }

                                   has_itens_is__dl__update_dl_copy--;
                                   goto inicio_ar4;

                                   /*



                                   you need to free the linked lists at the end of execution ric...



                                   */

                              exit_now_dl3:;

                                   if (copy_last_item_is_required__dl) // se tiver isto adiciona o no buffer size ja esta certo
                                   {
                                        if (DEBUG_DL__)
                                             pedro_dprintf(0, "salvou o byte adicional");

                                        if (DEBUG_DL__)
                                        {
                                             ; // //assert(0 && "byte saved");
                                        }
                                        fwrite(&last_item_or_montagem_dl, 1, 1, out_file_dl);
                                   }
                                   // here call the finish for the first linked list, since we need the value for the header we need to call it twice, in a near future we optimize it..., we will use encode to already define the size of the output first linked list, do it, during the first pass we already encode the data with 9 bits, go on
                              }

                              // next ric
                              {

                                   struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *my_ptr_ar;

                                   struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *my_ptr2_ar;

                                   my_ptr2_ar = aak_inicio_is___rcdl____update__rcdl__;

                                   my_ptr_ar = aak_inicio_is___rcdl____update__rcdl__;

                                   // pode reaproveitar este item ?, sim...
                                   has_itens_is___rcdl____update__rcdl__ccopy = has_itens_is___rcdl____update__rcdl__;

                              inicio_arrrr22:;
                                   if (!has_itens_is___rcdl____update__rcdl__ccopy)
                                   {
                                        if (DEBUG_DL__)
                                             pedro_dprintf(0, "loopeando na segunda linked list para salvar os dados");

                                        if (DEBUG_DL__)
                                        {
                                             ; // //assert(0 && "looping second linked list");
                                        }
                                        // has_itens_copy_is___rcdl____update__rcdl__ = 0;
                                        goto fim_rrr22;
                                   }
                                   my_ptr2_ar = my_ptr_ar;
                                   my_ptr_ar = my_ptr_ar->next_ar;
                                   /*
                                   if (1 == has_itens_is___rcdl____update__rcdl__)
                                   {
                                        free(my_ptr2_ar->next_ar);
                                   }
                                   */
                                   /*
                                                                      fwrite(&my_ptr2_ar->index_of_linked_list_starting_from_0_dl, 1, 4, out_file_dl);
                                                                      fwrite(&my_ptr2_ar->len_of_memory_dl, 1, 4, out_file_dl);
                                                                      fwrite(my_ptr2_ar->string_saved_dl, 1, my_ptr2_ar->len_of_memory_dl, out_file_dl);
                                   */
                                   /*



                                   */
                                   memcpy(ptr_in_buf, &my_ptr2_ar->index_of_linked_list_starting_from_0_dl, 4);

                                   ptr_in_buf += 4;

                                   bytes_in_dl += 4;
                                   memcpy(ptr_in_buf, &my_ptr2_ar->len_of_memory_dl, 4);

                                   ptr_in_buf += 4;

                                   bytes_in_dl += 4;

                                   memcpy(ptr_in_buf, my_ptr2_ar->string_saved_dl, my_ptr2_ar->len_of_memory_dl);

                                   ptr_in_buf += my_ptr2_ar->len_of_memory_dl;

                                   bytes_in_dl += my_ptr2_ar->len_of_memory_dl;

                                   /*



                                   */

                                   if (DEBUG_DL__)
                                        pedro_dprintf(0, "saving in the second linked list %d bytes", my_ptr2_ar->len_of_memory_dl + 4 + 4);

                                   if (DEBUG_DL__)
                                   {
                                        ; // //assert(0 && "second linked list saving data");
                                   }

                                   // free(my_ptr2_ar->string_saved_dl); // ta aqui
                                   // free(my_ptr2_ar);
                                   has_itens_is___rcdl____update__rcdl__ccopy--;
                                   goto inicio_arrrr22;

                              fim_rrr22:;

                                   // just exit now...
                                   if (DEBUG_DL__)
                                        pedro_dprintf(0, "just exiting now, the process will restart");

                                   if (DEBUG_DL__)
                                   {
                                        ; // //assert(0 && "exiting...");
                                   }
                                   // assert(0 && 3);
                                   pass_memory_output_dl(buf_out_dl, &bytes_out_dl);
                                   pass_memory_input_dl(buf_in_dl, &bytes_in_dl);

                                   pedro_dprintf(0, "123 passou %d", bytes_in_dl);
                                   // assert(0 && 31);
                                   main_do_mr_do();

                                   pedro_dprintf(-1, "saiu %d", bytes_out_dl);

                                   // //assert(0);
                                   // assert(0 && 2);
                                   printf("\nTotal compressed size to save %d, before the compression %d\n", bytes_out_dl, size_of_the_first_compressed_stream_dl + size_of_the_second_compressed_stream_dl);

                                   printf("Linked list 1 %d Linked list 2 %d\n", size_of_the_first_compressed_stream_dl, size_of_the_second_compressed_stream_dl);

                                   minha_struct.linked_list_1_size_dl = size_of_the_first_compressed_stream_dl;
                                   minha_struct.linked_list_2_size_dl = size_of_the_second_compressed_stream_dl;
                                   minha_struct.compressed_size_dl = bytes_out_dl;
                                   fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);

                                   fwrite(buf_out_dl, 1, bytes_out_dl, out_file_dl);

                                   free(buf_in_dl);  // free memory
                                   free(buf_out_dl); // free memory

                                   goto continua_pro_proximo_buffer_a_ser_lido_dl;
                              }
                         }
                         else
                         {
                              printf("\n\nDon't got compression, the resulting compressed data is linked list 1 %d, linked list 2 %d, just will save ucompressed data, it is %d\n", size_of_the_first_compressed_stream_dl, size_of_the_second_compressed_stream_dl, len_dl);

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
                              goto continua_pro_proximo_buffer_a_ser_lido_dl;
                         }
                    }
               }

               if (len_dl_copy > initial_size_of_string_dl)
               {
                    ; // ok
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "important%% the size of limited size of string that can be up to 512 is below the size of the data, it is now %d", initial_size_of_string_dl);

                    if (DEBUG_DL__)
                    {
                         ; // //assert(0 && "size of the string during the first steps");
                    }
               }
               else
               {
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "the size of the string that can be up to 512 was adjusted to %d", len_dl_copy);

                    if (DEBUG_DL__)
                    {
                         ; // //assert(0 && "adjusting size");
                    }
                    initial_size_of_string_dl = len_dl_copy; // aqui ja corrige...
               }

          volta_aqui_ric:;
               if (DEBUG_DL__)
                    pedro_dprintf(0, "returning or initial process 2, because 512 is too much");

               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "returning or first pass, ric");
               }
               // pos_in_stream_dl

               memcpy(needle_buf_dl, hay_ptr_dl, initial_size_of_string_dl); // nao tem problema voltar porque foram reembolsados os dados para serem lidos devolta, ta certo isso? sim...

               // basta deslocar aqui..., certo...
               delocador_fix_bug_in_version_2_0_dl += initial_size_of_string_dl;
               progress_dl += initial_size_of_string_dl;

               hay_ptr_dl += initial_size_of_string_dl;

               len_dl_copy -= initial_size_of_string_dl;
               if (DEBUG_DL__)
                    pedro_dprintf(0, "copying %d bytes from the data read to see if it already exit or not?", initial_size_of_string_dl);

               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "reading data, first steps");
               }

               if (DEBUG_DL__)
                    pedro_dprintf(0, "second search mode, it will search on the iput data to see if it exist in the rest of the data, if yes it will be stored in the second linked list, if not it will be just added to the first linked list as plain data");

               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "inside function");
               }
               result_dl = mem_search_dl(hay_ptr_dl, len_dl_copy, needle_buf_dl, initial_size_of_string_dl, 0); // nao tem que ser aqui oque faz a primeira pesquisa , tem que ver primeiro no segundo linked list ric, antes desse, incrivel como � complicado isso...

               /*

               int version 3 we will mkae the next search start from the next point that is not the first position, this is a bug in version 2

               */

               if (-1 == result_dl)
               {
                    ; // try again
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "string not found, now it will try with a smaller size or just save it as it is i the fisrt linked list");

                    if (DEBUG_DL__)
                    {
                         ; // //assert(0 && "running");
                    }
                    if (initial_size_of_string_dl > 16)
                    {
                         delocador_fix_bug_in_version_2_0_dl -= initial_size_of_string_dl;
                         progress_dl -= initial_size_of_string_dl;
                         hay_ptr_dl -= initial_size_of_string_dl; // to try again...
                         len_dl_copy += initial_size_of_string_dl;

                         initial_size_of_string_dl -= 16; // nunca vai ser menor que 0 ric, nem nunca vai ser 0 depois disto, ok? nao quer dormir ?
                         if (DEBUG_DL__)
                              pedro_dprintf(0, "will try again with a smaller size , now it will be %d bytes", initial_size_of_string_dl);

                         if (DEBUG_DL__)
                         {
                              ; // //assert(0 && "running");
                         }
                         goto volta_aqui_ric;
                    }
                    else
                    {
                         ; // simplemente salva os dados no linked list e segue adiante
                         ; // pode ser 16 ate 0;, simplesmente salva os dados e segue adiante
                         // se esta tudo certo � s� salvar ric..., o primeiro linked list s� precisa dos bytes salvos, e ja que terao tambem a referencia ao linked list vamos seguir em frente, lembrando que mais tarde faremos melhorias nisto, nao agora, por agora s� queremos que funcione, vamos montar o primeiro linked list e colocar ele num arquivo fora, pra nao ficar muiot grande, fa�a isto
                         if (DEBUG_DL__)
                              pedro_dprintf(0, "smmaler size reached -> %d, then it will be stored as it is and start again the initial process", initial_size_of_string_dl);

                         if (DEBUG_DL__)
                         {
                              ; // //assert(0 && "running");
                         }
                         add_more_one_is__dl__update_dl(needle_buf_dl, initial_size_of_string_dl, -1, false); // depois a gente pensa no linked list 2

                         // e agora, mais um round nao � isso,
                         goto volta_aqui_mais_alto_mar; // perfect
                    }
               }
               else
               {
                    ; // process..ok, here add the item to the second linked list
                    ; //
                    // just add to the second linked list...
                    if (DEBUG_DL__)
                         pedro_dprintf(0, "just foud the string in the main data with the size -> %d, then it will be added to the second linked list to possible be reused", initial_size_of_string_dl);

                    if (DEBUG_DL__)
                    {
                         ; // //assert(0 && "running");
                    }

                    add_more_one_is___rcdl____update__rcdl__(needle_buf_dl, initial_size_of_string_dl);
                    goto volta_aqui_mais_alto_mar;
               }

               if (0 == 1)
               {
                    goto continua_pro_proximo_buffer_a_ser_lido_dl;
               }

          continua_pro_proximo_buffer_a_ser_lido_dl:;

               // aqui pode dar free nos linked lists, � isso mesmo
               if (DEBUG_DL__)
                    pedro_dprintf(0, "last step now it is only cleaning and freeing the memory of the two linked lists");

               if (DEBUG_DL__)
               {
                    ; // //assert(0 && "last step");
               }

               clean_list__ar_is__dl__update_dl();
               clean_list__ar_is___rcdl____update__rcdl__();
               /*


               */

               // fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);
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

     return 0;
}

// vamos l�

/*

in portuguese, translate it

primeiro vamos criar um linked list para manter a lista de strings analizadas

64 bits claro, depois a gente ve sobre como convertar pra x86

first we need to open a file that we want to compress, for this the ubiquitous 'make.exe'

bom, em lz77 e lzss e lz78 a informacao se baseia nos dados que vao sendo lidos no arquivo e marcacoes vao sendo feitas pra se saber se ja apareceram ou nao

primeiro teria que se desenvolver uma forma avancada para se colocar na memria e no arquivo comprimido uma forma satisfatoria de salvar as informacoes que serao necessarias para a reconstrucao do arquivo

pelo jeito a cada 32kb � reiniciado o processo pois se deslocar nao sera possivel reconstruir os dados

pois a informacao tera passado, sim, tem que ter uma tamanho predefinido, mas que seja aleatorio, concorda?

sim
vamos bater o bzip2 com facilidade e rapido

mais rapido e melhor que bzip2

precisamos de um texto de exemplo

da pra trabalhar com memoria de 32 kb nao d�?

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

se for abaixo de 256 entao � caractere se for acima � controle...

sim � facil de controlar, basta ir mandando os bits, e fim de papo

primeiro voce trabalha em cima depois salva, com dados de conpressao completos e crc32, ok ?

vamos la, comecando do inicio, transforma todos os bits para 9, e usa eles pra marcar oque for comprimido ou nao depois a gente melhora isso

precisamos comprimir

deste jeito ficou facil, vamos fazer...

*/

// precisamos de um conversor de bytes para 9 bytes...vai l�... na memoria, vamos trabalhar com ele neste 128 kb

/*

pra isso eu tenho um codigo rapido simplesmente converter os dados de int8 para int16, vamos la, um array

ok, vamos copiar os 8 bits para 16 e trabalhar em cima disso pra ser rapido, da pra acelerar o lzw dos caras com isso

now what...

we have two arrays, but we will work on it... no need to store it now...

voltando a programacao, temos um array de bytes e array de shorts, precisamos iniciar o escaneamento, nove bits esta de bom tamanho pra os itens de depois da pra colocar 9 bits apenas em 16 em 16 e assim por diante

vamos la...

pode ir alocando em linked list se nao sabe o tamanho que vai ter , ok, sim, � isso,

vamos comecar com 16 bytes, sim , � isso, copia 16 bytes ric,,,mas e depois , depois checa se os proximos 16 sao os mesmo ?

nao, voce ja tem a memoria toda, entao apenas copia 16 e depois verifica se os proximo 512 ? se repetem ?

so funciona pra tras ? acho que nao vai ser reconstruido pode ser pra tras e pra frente...

ele simplesmente diz em que ponto do arquivo ocorre, e pode ter que tamanho ?

em que se da a compressao amor ?
 repetir um memoria inteiro nao comprime aonde esta a compressao ?

 sim mas estes limites serao alterados mais tarde para otimizacao...

aonde se da a compressao: resposta na duplicacao com menos dados da mesma informacao, nao � isso ?

depois de testar 512 bytes pode ir abaixando de 16 em dezesseis e ir definindo se tem ou nao

longest match

come�a por ai

todos estes valores serao ajustados e controlados num loop que vai mostrar o melhor item deste todos

de 16 em 16 esta bom, diminuindo ate ter apenas 16, ok ?

vai...

hummmmmmmm, se existir copia os 512 bytes no stream e marca as duas posicoes como tendo a informacao, que ideia

sim, assim evita este problema, se nao tiver deixa como ta nao � isso, sim mas vai mudar as posicoes e dai ric querido ?

nao sei dua...

deixa pra colocar no final, nao � melhor pra nao dar problema ?

o markov chain talvez seja isso, mas voce vai criar algo melhor, sim vamos aprimorar a cada momento

nao da pra manter num linked list, em linked list nao vai ter posicao, ou vai, vai um index ?,

linked list parece uma boa, salva o index o tamanho cada item comeca contando de 0, entendeu, dai na marcacao simplesmente coloca o index e na reconstrucao esta tudo certo, para isto precisamos de packets?, sim , precisa saber o tamanho total do arquivo, saber aonde termina, no meio nao tem como porque esta tudo em linked list, mas se souber o tamanho comprimido da, ric, sim � isso

e cada pra salvar na struct inicial aonde comecam os linked lists, e linked lists nao precisam ser de 9 bits, so precisa de 9 bits no meio de linked lists e strings, vamos la

da pra salvar em que posicao comecam os linked lists e meios de salvar eles

sim ric...

it is not lz77 or lz78 or lzma

vai... come�a com 512 e vai baixando...

///////////////////////////////////////////////////////////////////////////////////////////////////////

ok, first we need to load the data, then start creating the compressed stream, start from 16 bytes increasing until 512

whats the matter?

just limited to the past data, this in a near future could be improved, dont you agree ?

we can read future strings

*/