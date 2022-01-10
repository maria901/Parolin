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

void pedro_dprintf(int amanda_level,
                   char *format, ...);

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

// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

int main()
{

#define DL_SIZE__ (1L << 17)

     __attribute__((unused)) int len_dl;

     __attribute__((unused)) int len_of_data_to_compress_dl;
     __attribute__((unused)) FILE *my_file_dl = NULL;
     __attribute__((unused)) FILE *out_file_dl = NULL;
     __attribute__((unused)) uint8_t *buf_dl = malloc(DL_SIZE__);
     __attribute__((unused)) uint16_t *buf16_dl = malloc(DL_SIZE__ * 2);

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

     unlink("make.dl.compressed");
     my_file_dl = fopen("make.exe", "rb");
     out_file_dl = fopen("make.dl.compressed", "wb");

     if (my_file_dl)
     {

          pedro_dprintf(0, "size %d\n", DL_SIZE__);

          pos_in_stream_dl = 0;

          initial_size_of_string_dl = 512; // to be adjusted later...

          minha_struct.amor_assinatura_dl[0] = 'd';
          minha_struct.amor_assinatura_dl[1] = 'l';
          minha_struct.amor_assinatura_dl[2] = 'd';
          minha_struct.amor_assinatura_dl[3] = 'l';

          minha_struct.version_of_the_code = 1; // second version

          while ((len_dl = fread(buf_dl, 1, DL_SIZE__, my_file_dl)))
          {
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

               // em search code, to detect where the code is
               len_dl_copy = len_dl;

               hay_ptr_dl = buf_dl;

               if (0 == 1)
               {
                    goto volta_aqui_mais_alto_mar; // to make the compiler happy...
               }

          volta_aqui_mais_alto_mar:; // sim é alguem, duas mar...

               assert(0 <= len_dl_copy); // uma segurança a mais...

               if (0 == len_dl_copy)
               {
                    // oque faz, tem que processar nao é isso?, sim, mas agora?, sim, entao ta...
                    /*

                         somente copia o conteudo das duas linked lists nao é isso ?, precisa dos dois dados ja na saida pra poder criar as duas entradas no header

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

                         if (copy_last_item_is_required__dl) // se tiver isto adiciona o no buffer size ja esta certo
                         {
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

                         size_of_the_second_compressed_stream_dl += my_ptr2_ar->len_of_memory_dl + 4 + 4; // acho que é isso

                         // free(my_ptr2_ar->string_saved_dl); // ta aqui
                         // free(my_ptr2_ar);
                         has_itens_is___rcdl____update__rcdl__ccopy--;
                         goto inicio_arrrr2;

                    fim_rrr2:;
                    }

                    {
                         if (size_of_the_second_compressed_stream_dl + size_of_the_first_compressed_stream_dl < len_dl) //é so o primeiro tem que ver o segundo, sim é isso
                         {
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

                              minha_struct.linked_list_1_size_dl = size_of_the_first_compressed_stream_dl;
                              minha_struct.linked_list_2_size_dl = size_of_the_second_compressed_stream_dl;

                              fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);

                              {
                                   __attribute__((unused)) struct my_struct_for_list_ar_is__dl__update_dl *my_ptr_ar;

                                   __attribute__((unused)) struct my_struct_for_list_ar_is__dl__update_dl *my_ptr2_ar;

                                   my_ptr2_ar = aak_inicio_is__dl__update_dl;

                                   my_ptr_ar = aak_inicio_is__dl__update_dl;

                                   size_of_the_first_compressed_stream_dl = 0;

                                   has_itens_is__dl__update_dl_copy = has_itens_is__dl__update_dl;

                              inicio_ar4:;
                                   if (!has_itens_is__dl__update_dl_copy)
                                   {

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

                                   fwrite(my_ptr2_ar->output_memory_for_string_dl, 1, my_ptr2_ar->bytes_encoded_so_far_dl, out_file_dl);

                                   has_itens_is__dl__update_dl_copy--;
                                   goto inicio_ar4;

                                   /*



                                   you need to free the linked lists at the end of execution ric...



                                   */

                              exit_now_dl3:;

                                   if (copy_last_item_is_required__dl) // se tiver isto adiciona o no buffer size ja esta certo
                                   {
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

                                   fwrite(&my_ptr2_ar->index_of_linked_list_starting_from_0_dl, 1, 4, out_file_dl);
                                   fwrite(&my_ptr2_ar->len_of_memory_dl, 1, 4, out_file_dl);
                                   fwrite(my_ptr2_ar->string_saved_dl, 1, my_ptr2_ar->len_of_memory_dl, out_file_dl);
                                   // free(my_ptr2_ar->string_saved_dl); // ta aqui
                                   // free(my_ptr2_ar);
                                   has_itens_is___rcdl____update__rcdl__ccopy--;
                                   goto inicio_arrrr22;

                              fim_rrr22:;

                                   // just exit now...
                                   goto continua_pro_proximo_buffer_a_ser_lido_dl;
                              }
                         }
                         else
                         {
                              // just save the uncompressed stream and go on to the next
                              minha_struct.got_compression_dl = false;

                              minha_struct.linked_list_1_size_dl = len_dl;
                              minha_struct.linked_list_2_size_dl = 0;

                              fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);

                              fwrite(buf_dl, 1, len_dl, out_file_dl);
                              
                              goto continua_pro_proximo_buffer_a_ser_lido_dl;
                         }
                    }
               }

               if (len_dl_copy > initial_size_of_string_dl)
               {
                    ; // ok
               }
               else
               {
                    initial_size_of_string_dl = len_dl_copy; // aqui ja corrige...
               }

          volta_aqui_ric:;
               // pos_in_stream_dl

               memcpy(needle_buf_dl, hay_ptr_dl, initial_size_of_string_dl); // nao tem problema voltar porque foram reembolsados os dados para serem lidos devolta, ta certo isso? sim...

               hay_ptr_dl += initial_size_of_string_dl;

               len_dl_copy -= initial_size_of_string_dl;

               // aqui procura primeiro nos linked lists, e qual a vantagem ?, ta vamos procurar, porque pode estar la, sim e esta se foi adicionado, em caso de lz77 ele vai adicionando marcadores que dizem aonde esta os itens, no nosso caso tem dois linked lists, no caso de lz77 ele so olha pra tras, o nosso pode olhar pra frente e nos linked lists, talvez seja isso que seja markov chain, poderia dar uma olhada
               {

                    struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *my_ptr_ar;

                    struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *my_ptr2_ar;

                    my_ptr2_ar = aak_inicio_is___rcdl____update__rcdl__;
                    my_ptr_ar = aak_inicio_is___rcdl____update__rcdl__;

                    has_itens_is___rcdl____update__rcdl__ccopy = has_itens_is___rcdl____update__rcdl__;

               inicio_arrrr:;
                    if (!has_itens_is___rcdl____update__rcdl__ccopy)
                    {
                         // has_itens_copy_is___rcdl____update__rcdl__ = 0;
                         goto fim_rrr;
                    }
                    my_ptr2_ar = my_ptr_ar;
                    my_ptr_ar = my_ptr_ar->next_ar;
                    /*
                    if (1 == has_itens_is___rcdl____update__rcdl__)
                    {
                         free(my_ptr2_ar->next_ar);
                    }
                    */

                    if (my_ptr2_ar->len_of_memory_dl == initial_size_of_string_dl)
                    {

                         result_dl = mem_search_dl(my_ptr2_ar->string_saved_dl, my_ptr2_ar->len_of_memory_dl, needle_buf_dl, initial_size_of_string_dl, 0);

                         if (-1 == result_dl)
                         {
                              ; // ta quase lá...
                         }
                         else
                         {
                              add_more_one_is__dl__update_dl((uint8_t *)"", 0, my_ptr2_ar->index_of_linked_list_starting_from_0_dl, true);

                              // e vai aonde agora? proximo item acima, se nao bater ele tenta todos que baterem o tamanho, interessante, sera dificil debugar isto....

                              goto volta_aqui_mais_alto_mar; // ta proximo do fim, agora basta concatenar os dados, quando acabar, veja lá...
                         }
                    }
                    // free(my_ptr2_ar->string_saved_dl); // ta aqui
                    // free(my_ptr2_ar);
                    has_itens_is___rcdl____update__rcdl__ccopy--;
                    goto inicio_arrrr;

               fim_rrr:;
               }

               result_dl = mem_search_dl(hay_ptr_dl, len_dl_copy, needle_buf_dl, initial_size_of_string_dl, 0); // nao tem que ser aqui oque faz a primeira pesquisa , tem que ver primeiro no segundo linked list ric, antes desse, incrivel como é complicado isso...

               if (-1 == result_dl)
               {
                    ; // try again

                    if (initial_size_of_string_dl > 16)
                    {
                         hay_ptr_dl -= initial_size_of_string_dl; // to try again...
                         len_dl_copy += initial_size_of_string_dl;

                         initial_size_of_string_dl -= 16; // nunca vai ser menor que 0 ric, nem nunca vai ser 0 depois disto, ok? nao quer dormir ?

                         goto volta_aqui_ric;
                    }
                    else
                    {
                         ; // simplemente salva os dados no linked list e segue adiante
                         ; // pode ser 16 ate 0;, simplesmente salva os dados e segue adiante
                         // se esta tudo certo é só salvar ric..., o primeiro linked list só precisa dos bytes salvos, e ja que terao tambem a referencia ao linked list vamos seguir em frente, lembrando que mais tarde faremos melhorias nisto, nao agora, por agora só queremos que funcione, vamos montar o primeiro linked list e colocar ele num arquivo fora, pra nao ficar muiot grande, faça isto

                         add_more_one_is__dl__update_dl(needle_buf_dl, initial_size_of_string_dl, -1, false); // depois a gente pensa no linked list 2

                         // e agora, mais um round nao é isso,
                         goto volta_aqui_mais_alto_mar; // perfect
                    }
               }
               else
               {
                    ; // process..ok, here add the item to the second linked list
                    ; //
                    // just add to the second linked list...

                    add_more_one_is___rcdl____update__rcdl__(needle_buf_dl, initial_size_of_string_dl);
                    goto volta_aqui_mais_alto_mar;
               }

               if (0 == 1)
               {
                    goto continua_pro_proximo_buffer_a_ser_lido_dl;
               }

          continua_pro_proximo_buffer_a_ser_lido_dl:;

               // aqui pode dar free nos linked lists, é isso mesmo
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
     free(buf16_dl);

     printf("Research running...");

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


*/