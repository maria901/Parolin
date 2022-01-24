

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

// https://github.com/maria901/Parolin/tree/main/bw_compression_research updated daily during this compression reserch (jan 2022)
// https://sourceforge.net/projects/parolin/

// distributed as part of the Parolin project in the subfolder
// bw_compression_research

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

// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
// defines

static unsigned temp_for_ric_amanda;

int mprintf_S2_com_retorno_se_for_6_eh_sim__arp(char *format, ...);

void mprintf_S2_sem_retorno__arp(char *format, ...);
int __fastcall /* very fast call, the others are slow __cdecl and __stdcall and __thiscall */ main_decoder_ari_amanda(
    FILE *input_S2_file_amanda__,
    FILE *output_S2_file_amanda__);

// 8888888888888888888888888888888888888888888888

/**
 * @brief return the next bit, or 2 if no more...
 *
 * @param clear_flag_amanda true if init call to reset variables
 * @param array_of_bits_as_byte_amanda
 * @return int
 */
int read_bit_amanda(__attribute__((unused)) bool clear_flag_amanda,
                __attribute__((unused)) uint8_t *array_of_bits_as_byte_amanda, __attribute__((unused)) main_amanda_struct_for_amanda_compressor *amanda__, uint16_t array_of_bits_as_bytes_len)
{
     int ret_amanda;
     int return_value_amanda = 2;
     uint8_t mask_amanda;
     (void)ret_amanda;
     if (clear_flag_amanda)
     {
          if (DEBUG_DEC_amanda__)
               pedro_dprintf(0, "cleaning flag running");
          (amanda__->bit_position_for_decoder_amanda) = 0;
          (amanda__->bytes_left_in_the_bits_array_amanda) = array_of_bits_as_bytes_len;

          amanda__->bit_array_pointer_amanda = array_of_bits_as_byte_amanda;
          /*
                    for (ret_amanda = 0; ret_amanda < array_of_bits_as_bytes_len; ret_amanda++)
                    {
                         pedro_dprintf(0, "value %i\n", (unsigned int)array_of_bits_as_byte_amanda[ret_amanda]);
                    }
                    exit(27);
          */
          return 2;
     }
     if (0 == amanda__->bytes_left_in_the_bits_array_amanda)
     {
          return 2;
     }

     switch (amanda__->bit_position_for_decoder_amanda)
     {
     case 0:
          mask_amanda = (1 << amanda__->bit_position_for_decoder_amanda);

          if (mask_amanda & (*(amanda__->bit_array_pointer_amanda)))
          {
               return_value_amanda = 1;
          }
          else
          {
               return_value_amanda = 0;
          }
          amanda__->bit_position_for_decoder_amanda++;
          break;
     case 1:
          mask_amanda = (1 << amanda__->bit_position_for_decoder_amanda);

          if (mask_amanda & (*(amanda__->bit_array_pointer_amanda)))
          {
               return_value_amanda = 1;
          }
          else
          {
               return_value_amanda = 0;
          }
          amanda__->bit_position_for_decoder_amanda++;
          break;
     case 2:
          mask_amanda = (1 << amanda__->bit_position_for_decoder_amanda);

          if (mask_amanda & (*(amanda__->bit_array_pointer_amanda)))
          {
               return_value_amanda = 1;
          }
          else
          {
               return_value_amanda = 0;
          }
          amanda__->bit_position_for_decoder_amanda++;
          break;
     case 3:
          mask_amanda = (1 << amanda__->bit_position_for_decoder_amanda);

          if (mask_amanda & (*(amanda__->bit_array_pointer_amanda)))
          {
               return_value_amanda = 1;
          }
          else
          {
               return_value_amanda = 0;
          }
          amanda__->bit_position_for_decoder_amanda++;
          break;
     case 4:
          mask_amanda = (1 << amanda__->bit_position_for_decoder_amanda);

          if (mask_amanda & (*(amanda__->bit_array_pointer_amanda)))
          {
               return_value_amanda = 1;
          }
          else
          {
               return_value_amanda = 0;
          }
          amanda__->bit_position_for_decoder_amanda++;
          break;
     case 5:
          mask_amanda = (1 << amanda__->bit_position_for_decoder_amanda);

          if (mask_amanda & (*(amanda__->bit_array_pointer_amanda)))
          {
               return_value_amanda = 1;
          }
          else
          {
               return_value_amanda = 0;
          }
          amanda__->bit_position_for_decoder_amanda++;
          break;
     case 6:
          mask_amanda = (1 << amanda__->bit_position_for_decoder_amanda);

          if (mask_amanda & (*(amanda__->bit_array_pointer_amanda)))
          {
               return_value_amanda = 1;
          }
          else
          {
               return_value_amanda = 0;
          }
          amanda__->bit_position_for_decoder_amanda++;
          break;
     case 7:
          mask_amanda = (1 << amanda__->bit_position_for_decoder_amanda);

          if (mask_amanda & (*(amanda__->bit_array_pointer_amanda)))
          {
               return_value_amanda = 1;
          }
          else
          {
               return_value_amanda = 0;
          }
          amanda__->bit_position_for_decoder_amanda = 0;
          amanda__->bit_array_pointer_amanda++;
          amanda__->bytes_left_in_the_bits_array_amanda--;
          // first weird bug of the decoder code, day 13 jan 2022 22:27 PM -- exit(27);
          break;
     }

     if (1 == return_value_amanda)
     {
          // assert(0);
     }

     return return_value_amanda;
}

void get_string_size_and_address_in_the_current_buffer_amanda(uint16_t input_data_composed_amanda,
                                                          uint16_t *string__size_amanda,
                                                          uint16_t *address__amanda)
{
     uint16_t string_size_amanda = 0;
     uint16_t address_amanda = 0;

     int deslocador_ric_amanda = 0;
     int counter_amanda = 12;
     unsigned int mask_amanda;
     unsigned int mask_amanda2;

     mask_amanda = (1 << 0);

     // for bit 0
     if (mask_amanda & input_data_composed_amanda)
     {
          string_size_amanda |= mask_amanda;
     }
     else
     {
          string_size_amanda &= ~(mask_amanda);
     }
     // for bit 1

     mask_amanda = (1 << 1);
     if (mask_amanda & input_data_composed_amanda)
     {
          string_size_amanda |= mask_amanda;
     }
     else
     {
          string_size_amanda &= ~(mask_amanda);
     }
     // for bit 2

     mask_amanda = (1 << 2);
     if (mask_amanda & input_data_composed_amanda)
     {
          string_size_amanda |= mask_amanda;
     }
     else
     {
          string_size_amanda &= ~(mask_amanda);
     }

     // for bit 3

     mask_amanda = (1 << 3);
     if (mask_amanda & input_data_composed_amanda)
     {
          string_size_amanda |= mask_amanda;
     }
     else
     {
          string_size_amanda &= ~(mask_amanda);
     }

     // adjusting
     string_size_amanda += 3;
     // now the address
     *string__size_amanda = string_size_amanda;
     // for bit 0
     deslocador_ric_amanda = 0;

     while (counter_amanda--)
     {

          mask_amanda2 = (1 << deslocador_ric_amanda);
          mask_amanda = (1 << (deslocador_ric_amanda + 4));
          if (mask_amanda & input_data_composed_amanda)
          {
               address_amanda |= mask_amanda2;
          }
          else
          {
               address_amanda &= ~(mask_amanda2);
          }
          deslocador_ric_amanda++;
     }

     *address__amanda = address_amanda;
}

// 11111111111111111111111111111111111111111111111111111111111111

int __fastcall decode_ric_amanda(char *

                                 input_file_amanda,
                             char *output_file_amanda)
{
     /* he he he, irrelevant in win64,
     if you don't know it, cannot even be
     called from C# in win32 mode */

     /* no Unicode support during development, only
     later, sorry and I love fopen, not _wfopen */

     // current decoder additional required variables...

     // will generate the memory as required, best option, since we already dont know the size

     // ok, lets go

     __attribute__((unused)) bool using_previous_buffer_amanda;

     int64_t tamanho_amanda = 0, tamanho_got_amanda = 0, progress_amanda = 0;

     __attribute__((unused)) int32_t aamandaer32_real = 28;

     __attribute__((unused)) ULONGLONG update_me_amanda = 0;

     unsigned int current_progress_amanda = -1;

     uint8_t temp_amanda[2];

     uint16_t *ptr_uint16_amanda;

     uint16_t string_size__amanda, address__amanda;

     ptr_uint16_amanda = (uint16_t *)&temp_amanda[0];

     uint16_t composed_pointer_and_string_size_16_amanda;

     uint16_t compressed_buffer_size_amanda, bits_array_buffer_size_amanda;

     unsigned int u_len_amanda;
     unsigned int len_amanda;

     static uint8_t temporary_bytes[MAX_STRING_SEARCH_SIZE_amanda__ + 3];

     uint8_t *buffer_a_amanda = NULL;
     uint8_t *buffer_0_amanda = NULL;

     uint32_t bytes_already_in_uncompressed_buffer;

     __attribute__((unused)) uint8_t *temp_buffer_amanda;

     __attribute__((unused)) uint8_t *ptr_for_current_uncompressed_buffer_initial_position;

     int bytes_left_in_compressed_buffer_amanda;

     uint8_t *buffer_uncompressed_current_amanda = malloc(8192);

     uint8_t *buffer_uncompressed_previous_amanda = calloc(8192, 1);

     __attribute__((unused)) uint32_t bytes_added_to_the_current_buffer_amanda;

     __attribute__((unused)) uint8_t *current_uncompressed_buffer_ptr_amanda;

     __attribute__((unused)) uint8_t *compressed_buffer_ptr_amanda;

     uint8_t *buffer_bits_array_amanda = NULL;

     main_amanda_struct_for_amanda_compressor *amanda_ = calloc(sizeof(main_amanda_struct_for_amanda_compressor), 1);

     static amanda_dados_salvos_querido_ric minha_struct;

     int return_value_amanda = 0;
     char temp_file_amanda[MAX_PATH + 1];

     FILE *input_S2_file_amanda = NULL;
     __attribute__((unused)) /* I am a Linux guy these days,
     using only GCC for years now but I can change my mind
     and start calling cl.exe again if we have an
     interesting discussion */

     FILE *uncompressed_file_amanda = NULL;

     FILE *output_S2_file_amanda = NULL;

     printf("\nVersion of the encoder/decoder -> " STRING_VERSION_amanda_COMPRESSOR "\n\n");
     printf("Uncompressing...\n");
     if (NULL == input_file_amanda || NULL == output_file_amanda)
     {
          assert(0 && "What are you doing !!!?...");
          exit(29);
     }

     input_S2_file_amanda = fopen(input_file_amanda, "rb");

     // I must be using Emacs just I can't now that I am acostumated with VSCode speed

     if (NULL == input_S2_file_amanda)
     {
          return_value_amanda = 30; // errors stars from 30 now, sorry, but 0 is no error (v9.c), 30: Cannot open input file
          goto exit_ric_my_dear_amanda;
     }

     strcpy(temp_file_amanda, output_file_amanda);
     strcat(temp_file_amanda, ".rsp$$$.tmp");
     output_S2_file_amanda = fopen(temp_file_amanda, "wb");

     // I must be using Emacs just I can't now that I am acostumated with VSCode speed

     if (NULL == output_S2_file_amanda)
     {
          return_value_amanda = 31; // 31: Cannot open output file
          goto exit_ric_my_dear_amanda;
     }

     uncompressed_file_amanda = fopen(output_file_amanda, "wb");

     if (NULL == uncompressed_file_amanda)
     {
          return_value_amanda = 49; // 31: Cannot open output file
          goto exit_ric_my_dear_amanda;
     }

     memset(&minha_struct, 0, sizeof(minha_struct));

     if (fread(&minha_struct, 1, sizeof(minha_struct), input_S2_file_amanda) != sizeof(minha_struct))
     {
          return_value_amanda = 32;
          goto exit_ric_my_dear_amanda;
     }

     if ('d' != minha_struct.amor_assinatura_amanda[0] ||
         'l' != minha_struct.amor_assinatura_amanda[1] ||
         'd' != minha_struct.amor_assinatura_amanda[2] ||
         'l' != minha_struct.amor_assinatura_amanda[3])
     {
          return_value_amanda = 33;
          goto exit_ric_my_dear_amanda;
     }

     // now version check...
     if (28 == 53)
          goto jump_rhere_rrric;

     if (THE_CURRENT_amanda_COMPRESSOR_VERSION_FOR_THIS_RELEASE___ != minha_struct.version_of_the_code)
     {
          if (THE_FIRST_RELEASE_WITH_A_DDECDER___ > minha_struct.version_of_the_code)
          {
               return_value_amanda = 34;
               goto exit_ric_my_dear_amanda;
          }
          else
          {
          jump_rhere_rrric:;
               temp_for_ric_amanda = mprintf_S2_com_retorno_se_for_6_eh_sim__arp("This file was compressed with a future version of amanda_compressor, you can extract it with Parolin version 13.0.7 or above or download the correct version that is listed in the readme.txt file of the GitHub project:\nhttps://github.com/maria901/Parolin/\nTo identify the correct future release of amanda_compressor search for 'char value == %i' in the https://github.com/maria901/Parolin/blob/main/bw_compression_research/readme.txt file of the project, and it will tell you what binary file you need to download to extract, touch YES if you want to visit the page of the developer\n", (unsigned int)minha_struct.version_of_the_code);
               return_value_amanda = 35;
               if (6 == temp_for_ric_amanda)
               {
                    ShellExecuteA(0, 0, "HTTPS://NOMADE.SOURCEFORGE.io/RIC/", 0, 0, SW_SHOW);
               }
          }
     }

     // finally, checking values...

     // need arithmetic uncompression, go there
assert(0);
exit(7);
    // if (main_decoder_ari_amanda(input_S2_file_amanda, output_S2_file_amanda))
     {
          return_value_amanda = 36;
          goto exit_ric_my_dear_amanda;
     }

     // got the file, now decompresses it ric...

     /*
          we need 4096 bytes buffers, 3 to be exact
     */

     fclose(output_S2_file_amanda), output_S2_file_amanda = NULL;

     output_S2_file_amanda = fopen(temp_file_amanda, "rb");

     if (output_S2_file_amanda)
     {

          _fseeki64(output_S2_file_amanda, 0, SEEK_END);

          tamanho_amanda = _ftelli64(output_S2_file_amanda);
          printf("Size %lld\n\n", tamanho_amanda);
          _fseeki64(output_S2_file_amanda, 0, SEEK_SET);
          // printf("Abriu arquivo pra leitura\n");

          // read
     reiniciar_ric_amanda:;

          u_len_amanda = fread(&compressed_buffer_size_amanda, 1, 2, output_S2_file_amanda);
          progress_amanda += u_len_amanda;
          if ((update_me_amanda < GetTickCount64()))
          {
               update_me_amanda = GetTickCount64() + 50;
               printf("Progress ric -> % 4d\r", current_progress_amanda = getpor(tamanho_amanda, progress_amanda));
               fflush(stdout);
          }

          if (0 == u_len_amanda)
          {
               /*

                finished at 14 jan 2022 - 22:43, with the bless of our God
                assert(0 && "terminou os dados do arquivo comprimido, saindo");

               */

               goto exit_ric_my_dear_amanda;
          }
          if (2 != u_len_amanda)
          {
               return_value_amanda = 38;
               goto exit_ric_my_dear_amanda;
          }

          if (8192 < compressed_buffer_size_amanda)
          {
               return_value_amanda = 39;
               goto exit_ric_my_dear_amanda;
          }

          if (0 == compressed_buffer_size_amanda)
          {
               return_value_amanda = 46;
               goto exit_ric_my_dear_amanda;
          }

          u_len_amanda = fread(&bits_array_buffer_size_amanda, 1, 2, output_S2_file_amanda);
          progress_amanda += u_len_amanda;
          if ((update_me_amanda < GetTickCount64()))
          {
               update_me_amanda = GetTickCount64() + 50;
               printf("Progress ric -> % 4d\r", current_progress_amanda = getpor(tamanho_amanda, progress_amanda));
               fflush(stdout);
          }
          if (2 != u_len_amanda)
          {
               return_value_amanda = 38;
               goto exit_ric_my_dear_amanda;
          }

          if (4096 < bits_array_buffer_size_amanda)
          {
               return_value_amanda = 40;
               goto exit_ric_my_dear_amanda;
          }

          if (buffer_a_amanda)
               free(buffer_a_amanda); // avoiding memory leaks...

          buffer_a_amanda = malloc(compressed_buffer_size_amanda);

          if (DEBUG_DEC_amanda__)
               pedro_dprintf(0, "tamanho do comprimido %d\n", (int)compressed_buffer_size_amanda);

          len_amanda = fread(buffer_a_amanda, 1, (int)compressed_buffer_size_amanda, output_S2_file_amanda);
          progress_amanda += len_amanda;
          if ((update_me_amanda < GetTickCount64()))
          {
               update_me_amanda = GetTickCount64() + 50;
               printf("Progress ric -> % 4d\r", current_progress_amanda = getpor(tamanho_amanda, progress_amanda));
               fflush(stdout);
          }
          if (len_amanda != (int)compressed_buffer_size_amanda)
          {
               return_value_amanda = 41;
               goto exit_ric_my_dear_amanda;
          }

          if (buffer_bits_array_amanda)
               free(buffer_bits_array_amanda);

          buffer_bits_array_amanda = malloc(bits_array_buffer_size_amanda + 1000 /* may be an invalid compressed file or tampered */);
          if (DEBUG_DEC_amanda__)
               pedro_dprintf(0, "tamanho do bit array in bytes %d\n", (int)bits_array_buffer_size_amanda);

          len_amanda = fread(buffer_bits_array_amanda, 1, (int)bits_array_buffer_size_amanda, output_S2_file_amanda);
          progress_amanda += len_amanda;
          if ((update_me_amanda < GetTickCount64()))
          {
               update_me_amanda = GetTickCount64() + 50;
               printf("Progress ric -> % 4d\r", current_progress_amanda = getpor(tamanho_amanda, progress_amanda));
               fflush(stdout);
          }
          if (len_amanda != (int)bits_array_buffer_size_amanda)
          {
               return_value_amanda = 42;
               goto exit_ric_my_dear_amanda;
          }

          read_bit_amanda(true,
                      buffer_bits_array_amanda,
                      amanda_,
                      bits_array_buffer_size_amanda);

          // now starts the processing
          // goto read_next_bit_amanda_jump;
          // exit(30);

          bytes_left_in_compressed_buffer_amanda = compressed_buffer_size_amanda;

          bytes_added_to_the_current_buffer_amanda = 0;

          ptr_for_current_uncompressed_buffer_initial_position = buffer_uncompressed_current_amanda;

          current_uncompressed_buffer_ptr_amanda = buffer_uncompressed_current_amanda; // at the beginning init all...

          compressed_buffer_ptr_amanda = buffer_a_amanda;

          bytes_already_in_uncompressed_buffer = 0;

     read_next_bit_amanda_jump:;

          len_amanda = read_bit_amanda(false,
                               NULL,
                               amanda_,
                               0);
          if (DEBUG_DEC_amanda__)
               pedro_dprintf(0, "bit %d", len_amanda);

          if (2 == len_amanda)
          {
               return_value_amanda = 43;
               goto exit_ric_my_dear_amanda;
          }

          if (0 == len_amanda) // the byte is normal byte stored in the compressed stream
          {

               (*current_uncompressed_buffer_ptr_amanda) = (*compressed_buffer_ptr_amanda);

               current_uncompressed_buffer_ptr_amanda++;

               compressed_buffer_ptr_amanda++; // adding data and ajusting pointers

               bytes_already_in_uncompressed_buffer++;

               bytes_added_to_the_current_buffer_amanda++;

               if (4096 < bytes_added_to_the_current_buffer_amanda)
               {
                    // too much data added to uncompressed buffer
                    return_value_amanda = 44;
                    goto exit_ric_my_dear_amanda;
               }

               bytes_left_in_compressed_buffer_amanda--;

               if (0 > bytes_left_in_compressed_buffer_amanda)
               {
                    return_value_amanda = 45;
                    goto exit_ric_my_dear_amanda;
               }

               if (0 == bytes_left_in_compressed_buffer_amanda)
               {

                    if (DEBUG_DEC_amanda__)
                         pedro_dprintf(0, "bytes left in bit array %d", amanda_->bytes_left_in_the_bits_array_amanda);

                    if (DEBUG_DEC_amanda__)
                         pedro_dprintf(0, "string processing -> bytes in bytes_already_in_uncompressed_buffer %d %d", bytes_already_in_uncompressed_buffer, bytes_left_in_compressed_buffer_amanda);

                    if (DEBUG_DEC_amanda__)
                    {
                         assert(0 && "1");
                    }

                    tamanho_got_amanda += bytes_already_in_uncompressed_buffer;
                    aamandaer32_real = adler32(aamandaer32_real,
                                                      ptr_for_current_uncompressed_buffer_initial_position,
                                                      bytes_already_in_uncompressed_buffer);
                    pedro_dprintf(-1, "2 bytes_already_in_uncompressed_buffer %d",
                                  bytes_already_in_uncompressed_buffer);
                    // assert(0);

                    if (4096 < bytes_already_in_uncompressed_buffer)
                    {
                         pedro_dprintf(0, "size 2 %d", bytes_already_in_uncompressed_buffer);
                         return_value_amanda = 52;
                         goto exit_ric_my_dear_amanda;
                    }

                    memcpy(buffer_uncompressed_previous_amanda,
                           ptr_for_current_uncompressed_buffer_initial_position,
                           bytes_already_in_uncompressed_buffer);

                    if (fwrite(ptr_for_current_uncompressed_buffer_initial_position,
                               1,
                               bytes_already_in_uncompressed_buffer,
                               uncompressed_file_amanda) != bytes_already_in_uncompressed_buffer)
                    {
                         return_value_amanda = 50;
                         goto exit_ric_my_dear_amanda;
                    }

                    goto reiniciar_ric_amanda;
               }
               goto read_next_bit_amanda_jump;
          }

          if (1 == len_amanda) // for version of 4096 compression searching buffer and 8192 bytes too this says that the bytes in the compressed stream are pointers, lets evaluate
          {

               if (0 == bytes_left_in_compressed_buffer_amanda)
               {
                    // error
                    return_value_amanda = 47;
                    goto exit_ric_my_dear_amanda;
               }
               temp_amanda[0] = (*compressed_buffer_ptr_amanda);

               compressed_buffer_ptr_amanda++;

               bytes_left_in_compressed_buffer_amanda--;

               if (0 == bytes_left_in_compressed_buffer_amanda)
               {
                    // error
                    return_value_amanda = 47;
                    goto exit_ric_my_dear_amanda;
               }

               temp_amanda[1] = (*compressed_buffer_ptr_amanda);

               compressed_buffer_ptr_amanda++;

               bytes_left_in_compressed_buffer_amanda--;

               composed_pointer_and_string_size_16_amanda = *ptr_uint16_amanda;

               // 16 jan 2022 for version v10 checking the next bit
               // to see if the current buffer or the previous buffer
               // was used

               // 0 is previous buffer lets get it

               // 1313131313131313131313131313131313

               len_amanda = read_bit_amanda(false,
                                    NULL,
                                    amanda_,
                                    0);
               if (DEBUG_DEC_amanda__)
                    pedro_dprintf(0, "bit %d", len_amanda);

               if (2 == len_amanda)
               {
                    return_value_amanda = 53;
                    goto exit_ric_my_dear_amanda;
               }

               if (0 == len_amanda)
               {
                    using_previous_buffer_amanda = true;
                    // assert(0);
               }
               else
               {
                    using_previous_buffer_amanda = false;
               }

               // now process it
               get_string_size_and_address_in_the_current_buffer_amanda(composed_pointer_and_string_size_16_amanda,
                                                                    &string_size__amanda,
                                                                    &address__amanda);
               assert(0 && "cannot decompress for the moment");

#include "mode_v10_amanda.c" /* old 4096 based sliding window */

               assert(0 && "you don't know what you are doing, are you? he he he");
               exit(1993);
             
               if (0 == bytes_left_in_compressed_buffer_amanda)
               {

                    tamanho_got_amanda += bytes_already_in_uncompressed_buffer;
                    aamandaer32_real = adler32(aamandaer32_real,
                                                      ptr_for_current_uncompressed_buffer_initial_position,
                                                      bytes_already_in_uncompressed_buffer);
                    pedro_dprintf(-1, "bytes_already_in_uncompressed_buffer %d",
                                  bytes_already_in_uncompressed_buffer);
                    // assert(0);

                    if (4096 < bytes_already_in_uncompressed_buffer)
                    {
                         pedro_dprintf(0, " bits as bytes left %d", amanda_->bytes_left_in_the_bits_array_amanda);
                         pedro_dprintf(0, "size 1 %d", bytes_already_in_uncompressed_buffer);
                         return_value_amanda = 52;
                         goto exit_ric_my_dear_amanda;
                    }

                    memcpy(buffer_uncompressed_previous_amanda,
                           ptr_for_current_uncompressed_buffer_initial_position,
                           bytes_already_in_uncompressed_buffer);

                    if (fwrite(ptr_for_current_uncompressed_buffer_initial_position,
                               1,
                               bytes_already_in_uncompressed_buffer,
                               uncompressed_file_amanda) != bytes_already_in_uncompressed_buffer)
                    {
                         return_value_amanda = 50;
                         goto exit_ric_my_dear_amanda;
                    }

                    goto reiniciar_ric_amanda;
               }

               goto read_next_bit_amanda_jump;
          }

          assert(0);
          /*

now work...

          */
     }
     else
     {
          return_value_amanda = 37;
          goto exit_ric_my_dear_amanda;
     }
     /*


     */

exit_ric_my_dear_amanda:;

     free(buffer_uncompressed_current_amanda);

     free(buffer_uncompressed_previous_amanda);

     free(amanda_);
     amanda_ = NULL;

     if (buffer_0_amanda)
     {
          free(buffer_0_amanda);
          buffer_0_amanda = NULL;
     }

     if (buffer_bits_array_amanda)
     {
          free(buffer_bits_array_amanda);
          buffer_bits_array_amanda = NULL;
     }

     if (buffer_a_amanda)
     {
          free(buffer_a_amanda);
          buffer_a_amanda = NULL;
     }
     // let we see if it is already working...

     if (input_S2_file_amanda)
     {
          fclose(input_S2_file_amanda);
          input_S2_file_amanda = NULL;
     }
     if (output_S2_file_amanda)
     {
          fclose(output_S2_file_amanda);
          output_S2_file_amanda = NULL; // for safety
     }
     if (uncompressed_file_amanda)
     {
          fclose(uncompressed_file_amanda);
          uncompressed_file_amanda = NULL;
     }

     unlink(temp_file_amanda);

     printf("Progress ric -> % 4d\r", 100);
     printf("\n");

     if (0 == return_value_amanda &&
         ((minha_struct.aamandaer32_of_the_uncompressed_data_amanda != aamandaer32_real) ||
          minha_struct.size_of_the_file_to_compress_amanda !=
              tamanho_got_amanda))
     {

          // printf("tamanhos %lld %lld\n", minha_struct.size_of_the_file_to_compress_amanda, tamanho_got_amanda);
          return_value_amanda = 51;
     }
     switch (return_value_amanda)
     {
     case 0:
          printf("Done\n");
          break; // just exit if 0
     case 30:
          printf("Error 30: Cannot open input file\n");
          break;
     case 31:
          printf("Error 31: Cannot open output file\n");
          break;
     case 32:
          printf("Error 32: Invalid amanda_compressor file, too small\n");
          break;
     case 33:
          printf("Error 33: Not a valid amanda_compressor file, the initial characters are not 'amandaamanda'\n");
          break;
     case 34:
          printf("Error 34: The first valid amanda_compressor decoder available was char version (53 + 0 + 0 + 0) - v9.c, it is below it, it will never decompress, sorry\n");
          break;
     case 35:
          printf("Error 35: Compressed file was created with a future version of amanda_compressor, but is a valid amanda_compressor file\n");
          break;
     case 36:
          printf("Error 36: Error in the erithmetic decompression\n");
          break;
     case 37:
          printf("Error 37: Cannot open temp file to read\n");
          break;
     case 38:
          printf("Error 38: Size of the compressed data is too small, less than 2\n");
          break;
     case 39:
          printf("Error 39: Too large the size of the compressed data, above 8192, while the correct value would need to be around 4096\n");
          break;
     case 40:
          printf("Error 40: Too large the size of the bits array in bytes, above 4096, while the correct value would need to be below 4096\n");
          break;
     case 41:
          printf("Error 41: Cannot read the compressed data from the temp file\n");
          break;
     case 42:
          printf("Error 42: Cannot read the array of bits as bytes from the temp file\n");
          break;
     case 43:
          printf("Error 43: Reading too much bits from the bits array or damaged compressed file\n");
          break;
     case 44:
          printf("Error 44: 1 Too much data added to uncompressed buffer\n");
          break;
     case 45:
          printf("Error 45: Too much data read from compressed buffer\n");
          break;
     case 46:
          printf("Error 46: Invalid compressed size, cannot be 0\n");
          break;
     case 47:
          printf("Error 47: No more data to process from the compressed buffer\n");
          break;
     case 48:
          printf("Error 48: 2 Too much data added to uncompressed buffer\n");
          break;
     case 49:
          printf("Error 49: Cannot open output file to write the uncompressed data\n");
          break;
     case 50:
          printf("Error 50: Cannot write data to destination uncompressed file\n");
          break;
     case 51:
          printf("Error 51: Invalid compressed file or unexpected error in the decoder\nThe resulting file is not the original\n");
          break;
     case 52:
          printf("Error 52: Size of buffer to write to disk is not 4096\n");
          break;
     case 53:
          printf("Error 53: Reading too much bits from the bits array or damaged compressed file in the read of pointer\n");
          break;
     default:
          assert(0 && "Programming error ric...");
          break;
     }

     return return_value_amanda;
}
// https://music.youtube.com/watch?v=mL2Evq3ge5A&list=RDAMVMwBfVsucRe1w