

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

// version information and informations about modifications
// added to new release are always added to the file
// version_info_dl.h

// the version defined for the encoder and decoder is also defined at
// version_info_dl.h, each different version of the encoder/decoder
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

#include <stdbool.h>

// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
// defines

static unsigned temp_for_ric_dl;

int mprintf_S2_com_retorno_se_for_6_eh_sim__arp(char *format, ...);

void mprintf_S2_sem_retorno__arp(char *format, ...);
int __fastcall /* very fast call, the others are slow __cdecl and __stdcall and __thiscall */ main_decoder_ari_dl(
    FILE *input_S2_file_dl__,
    FILE *output_S2_file_dl__);

// 8888888888888888888888888888888888888888888888

/**
 * @brief return the next bit, or 2 if no more...
 *
 * @param clear_flag_dl true if init call to reset variables
 * @param array_of_bits_as_byte_dl
 * @return int
 */
int read_bit_dl(__attribute__((unused)) bool clear_flag_dl,
                __attribute__((unused)) uint8_t *array_of_bits_as_byte_dl, __attribute__((unused)) main_dl_struct_for_dl_compressor *dl__, uint16_t array_of_bits_as_bytes_len)
{
     int ret_dl;
     int return_value_dl = 2;
     uint8_t mask_dl;
     (void)ret_dl;
     if (clear_flag_dl)
     {
          if (DEBUG_DEC_DL__)
               pedro_dprintf(0, "cleaning flag running");
          (dl__->bit_position_for_decoder_dl) = 0;
          (dl__->bytes_left_in_the_bits_array_dl) = array_of_bits_as_bytes_len;

          dl__->bit_array_pointer_dl = array_of_bits_as_byte_dl;
          /*
                    for (ret_dl = 0; ret_dl < array_of_bits_as_bytes_len; ret_dl++)
                    {
                         pedro_dprintf(0, "value %i\n", (unsigned int)array_of_bits_as_byte_dl[ret_dl]);
                    }
                    exit(27);
          */
          return 2;
     }
     if (0 == dl__->bytes_left_in_the_bits_array_dl)
     {
          return 2;
     }

     switch (dl__->bit_position_for_decoder_dl)
     {
     case 0:
          mask_dl = (1 << dl__->bit_position_for_decoder_dl);

          if (mask_dl & (*(dl__->bit_array_pointer_dl)))
          {
               return_value_dl = 1;
          }
          else
          {
               return_value_dl = 0;
          }
          dl__->bit_position_for_decoder_dl++;
          break;
     case 1:
          mask_dl = (1 << dl__->bit_position_for_decoder_dl);

          if (mask_dl & (*(dl__->bit_array_pointer_dl)))
          {
               return_value_dl = 1;
          }
          else
          {
               return_value_dl = 0;
          }
          dl__->bit_position_for_decoder_dl++;
          break;
     case 2:
          mask_dl = (1 << dl__->bit_position_for_decoder_dl);

          if (mask_dl & (*(dl__->bit_array_pointer_dl)))
          {
               return_value_dl = 1;
          }
          else
          {
               return_value_dl = 0;
          }
          dl__->bit_position_for_decoder_dl++;
          break;
     case 3:
          mask_dl = (1 << dl__->bit_position_for_decoder_dl);

          if (mask_dl & (*(dl__->bit_array_pointer_dl)))
          {
               return_value_dl = 1;
          }
          else
          {
               return_value_dl = 0;
          }
          dl__->bit_position_for_decoder_dl++;
          break;
     case 4:
          mask_dl = (1 << dl__->bit_position_for_decoder_dl);

          if (mask_dl & (*(dl__->bit_array_pointer_dl)))
          {
               return_value_dl = 1;
          }
          else
          {
               return_value_dl = 0;
          }
          dl__->bit_position_for_decoder_dl++;
          break;
     case 5:
          mask_dl = (1 << dl__->bit_position_for_decoder_dl);

          if (mask_dl & (*(dl__->bit_array_pointer_dl)))
          {
               return_value_dl = 1;
          }
          else
          {
               return_value_dl = 0;
          }
          dl__->bit_position_for_decoder_dl++;
          break;
     case 6:
          mask_dl = (1 << dl__->bit_position_for_decoder_dl);

          if (mask_dl & (*(dl__->bit_array_pointer_dl)))
          {
               return_value_dl = 1;
          }
          else
          {
               return_value_dl = 0;
          }
          dl__->bit_position_for_decoder_dl++;
          break;
     case 7:
          mask_dl = (1 << dl__->bit_position_for_decoder_dl);

          if (mask_dl & (*(dl__->bit_array_pointer_dl)))
          {
               return_value_dl = 1;
          }
          else
          {
               return_value_dl = 0;
          }
          dl__->bit_position_for_decoder_dl = 0;
          dl__->bit_array_pointer_dl++;
          dl__->bytes_left_in_the_bits_array_dl--;
          // first weird bug of the decoder code, day 13 jan 2022 22:27 PM -- exit(27);
          break;
     }

     if (1 == return_value_dl)
     {
          // assert(0);
     }

     return return_value_dl;
}

void get_string_size_and_address_in_the_current_buffer_dl(uint16_t input_data_composed_dl,
                                                          uint16_t *string__size_dl,
                                                          uint16_t *address__dl)
{
     uint16_t string_size_dl = 0;
     uint16_t address_dl = 0;

     int deslocador_ric_dl = 0;
     int counter_dl = 12;
     unsigned int mask_dl;
     unsigned int mask_dl2;

     mask_dl = (1 << 0);

     // for bit 0
     if (mask_dl & input_data_composed_dl)
     {
          string_size_dl |= mask_dl;
     }
     else
     {
          string_size_dl &= ~(mask_dl);
     }
     // for bit 1

     mask_dl = (1 << 1);
     if (mask_dl & input_data_composed_dl)
     {
          string_size_dl |= mask_dl;
     }
     else
     {
          string_size_dl &= ~(mask_dl);
     }
     // for bit 2

     mask_dl = (1 << 2);
     if (mask_dl & input_data_composed_dl)
     {
          string_size_dl |= mask_dl;
     }
     else
     {
          string_size_dl &= ~(mask_dl);
     }

     // for bit 3

     mask_dl = (1 << 3);
     if (mask_dl & input_data_composed_dl)
     {
          string_size_dl |= mask_dl;
     }
     else
     {
          string_size_dl &= ~(mask_dl);
     }

     // adjusting
     string_size_dl += 3;
     // now the address
     *string__size_dl = string_size_dl;
     // for bit 0
     deslocador_ric_dl = 0;

     while (counter_dl--)
     {

          mask_dl2 = (1 << deslocador_ric_dl);
          mask_dl = (1 << (deslocador_ric_dl + 4));
          if (mask_dl & input_data_composed_dl)
          {
               address_dl |= mask_dl2;
          }
          else
          {
               address_dl &= ~(mask_dl2);
          }
          deslocador_ric_dl++;
     }

     *address__dl = address_dl;
}

// 11111111111111111111111111111111111111111111111111111111111111

int __fastcall decode_ric_dl(char *

                                 input_file_dl,
                             char *output_file_dl)
{
     /* he he he, irrelevant in win64,
     if you don't know it, cannot even be
     called from C# in win32 mode */

     /* no Unicode support during development, only
     later, sorry and I love fopen, not _wfopen */

     // current decoder additional required variables...

     // will generate the memory as required, best option, since we already dont know the size

     // ok, lets go

     int64_t tamanho_dl = 0, tamanho_got_dl = 0, progress_dl = 0;

     __attribute__((unused)) int32_t adler32_real = 28;

     __attribute__((unused)) ULONGLONG update_me_dl = 0;

     unsigned int current_progress_dl = -1;

     uint8_t temp_dl[2];

     uint16_t *ptr_uint16_dl;

     uint16_t string_size__dl, address__dl;

     ptr_uint16_dl = (uint16_t *)&temp_dl[0];

     uint16_t composed_pointer_and_string_size_16_dl;

     uint16_t compressed_buffer_size_dl, bits_array_buffer_size_dl;

     unsigned int u_len_dl;
     unsigned int len_dl;

     static uint8_t temporary_bytes[MAX_STRING_SEARCH_SIZE_DL__ + 3];

     uint8_t *buffer_a_dl = NULL;
     uint8_t *buffer_0_dl = NULL;

     uint32_t bytes_already_in_uncompressed_buffer;

     __attribute__((unused)) uint8_t *temp_buffer_dl;

     __attribute__((unused)) uint8_t *ptr_for_current_uncompressed_buffer_initial_position;

     int bytes_left_in_compressed_buffer_dl;

     uint8_t *buffer_uncompressed_current_dl = malloc(8192);
     uint8_t *buffer_uncompressed_previous_dl = calloc(8192, 1);

     __attribute__((unused)) uint32_t bytes_added_to_the_current_buffer_dl;

     __attribute__((unused)) uint8_t *current_uncompressed_buffer_ptr_dl;

     __attribute__((unused)) uint8_t *compressed_buffer_ptr_dl;

     uint8_t *buffer_bits_array_dl = NULL;

     main_dl_struct_for_dl_compressor *dl_ = calloc(sizeof(main_dl_struct_for_dl_compressor), 1);

     static dl_dados_salvos_querido_ric minha_struct;

     int return_value_dl = 0;
     char temp_file_dl[MAX_PATH + 1];

     FILE *input_S2_file_dl = NULL;
     __attribute__((unused)) /* I am a Linux guy these days,
     using only GCC for years now but I can change my mind
     and start calling cl.exe again if we have an
     interesting discussion */

     FILE *uncompressed_file_dl = NULL;

     FILE *output_S2_file_dl = NULL;

     printf("\nVersion of the encoder/decoder -> " STRING_VERSION_DL_COMPRESSOR "\n\n");
     printf("Uncompressing...\n");
     if (NULL == input_file_dl || NULL == output_file_dl)
     {
          assert(0 && "What are you doing !!!?...");
          exit(29);
     }

     input_S2_file_dl = fopen(input_file_dl, "rb");

     // I must be using Emacs just I can't now that I am acostumated with VSCode speed

     if (NULL == input_S2_file_dl)
     {
          return_value_dl = 30; // errors stars from 30 now, sorry, but 0 is no error (v9.c), 30: Cannot open input file
          goto exit_ric_my_dear_dl;
     }

     strcpy(temp_file_dl, output_file_dl);
     strcat(temp_file_dl, ".rsp$$$.tmp");
     output_S2_file_dl = fopen(temp_file_dl, "wb");

     // I must be using Emacs just I can't now that I am acostumated with VSCode speed

     if (NULL == output_S2_file_dl)
     {
          return_value_dl = 31; // 31: Cannot open output file
          goto exit_ric_my_dear_dl;
     }

     uncompressed_file_dl = fopen(output_file_dl, "wb");

     if (NULL == uncompressed_file_dl)
     {
          return_value_dl = 49; // 31: Cannot open output file
          goto exit_ric_my_dear_dl;
     }

     memset(&minha_struct, 0, sizeof(minha_struct));

     if (fread(&minha_struct, 1, sizeof(minha_struct), input_S2_file_dl) != sizeof(minha_struct))
     {
          return_value_dl = 32;
          goto exit_ric_my_dear_dl;
     }

     if ('d' != minha_struct.amor_assinatura_dl[0] ||
         'l' != minha_struct.amor_assinatura_dl[1] ||
         'd' != minha_struct.amor_assinatura_dl[2] ||
         'l' != minha_struct.amor_assinatura_dl[3])
     {
          return_value_dl = 33;
          goto exit_ric_my_dear_dl;
     }

     // now version check...
     if (28 == 53)
          goto jump_rhere_rrric;

     if (THE_CURRENT_DL_COMPRESSOR_VERSION_FOR_THIS_RELEASE___ != minha_struct.version_of_the_code)
     {
          if (THE_FIRST_RELEASE_WITH_A_DDECDER___ > minha_struct.version_of_the_code)
          {
               return_value_dl = 34;
               goto exit_ric_my_dear_dl;
          }
          else
          {
          jump_rhere_rrric:;
               temp_for_ric_dl = mprintf_S2_com_retorno_se_for_6_eh_sim__arp("This file was compressed with a future version of dl_compressor, you can extract it with Parolin version 13.0.7 or above or download the correct version that is listed in the readme.txt file of the GitHub project:\nhttps://github.com/maria901/Parolin/\nTo identify the correct future release of dl_compressor search for 'char value == %i' in the https://github.com/maria901/Parolin/blob/main/bw_compression_research/readme.txt file of the project, and it will tell you what binary file you need to download to extract, touch YES if you want to visit the page of the developer\n", (unsigned int)minha_struct.version_of_the_code);
               return_value_dl = 35;
               if (6 == temp_for_ric_dl)
               {
                    ShellExecuteA(0, 0, "HTTPS://NOMADE.SOURCEFORGE.io/RIC/", 0, 0, SW_SHOW);
               }
          }
     }

     // finally, checking values...

     // need arithmetic uncompression, go there

     if (main_decoder_ari_dl(input_S2_file_dl, output_S2_file_dl))
     {
          return_value_dl = 36;
          goto exit_ric_my_dear_dl;
     }

     // got the file, now decompresses it ric...

     /*
          we need 4096 bytes buffers, 3 to be exact
     */

     fclose(output_S2_file_dl), output_S2_file_dl = NULL;

     output_S2_file_dl = fopen(temp_file_dl, "rb");

     if (output_S2_file_dl)
     {

          _fseeki64(output_S2_file_dl, 0, SEEK_END);

          tamanho_dl = _ftelli64(output_S2_file_dl);
          printf("Size %lld\n\n", tamanho_dl);
          _fseeki64(output_S2_file_dl, 0, SEEK_SET);
          // printf("Abriu arquivo pra leitura\n");

          // read
     reiniciar_ric_dl:;

          u_len_dl = fread(&compressed_buffer_size_dl, 1, 2, output_S2_file_dl);
          progress_dl += u_len_dl;
          if ((update_me_dl < GetTickCount64()))
          {
               update_me_dl = GetTickCount64() + 50;
               printf("Progress ric -> % 4d\r", current_progress_dl = getpor(tamanho_dl, progress_dl));
               fflush(stdout);
          }

          if (0 == u_len_dl)
          {
               /*

                finished at 14 jan 2022 - 22:43, with the bless of our God
                assert(0 && "terminou os dados do arquivo comprimido, saindo");

               */

               goto exit_ric_my_dear_dl;
          }
          if (2 != u_len_dl)
          {
               return_value_dl = 38;
               goto exit_ric_my_dear_dl;
          }

          if (8192 < compressed_buffer_size_dl)
          {
               return_value_dl = 39;
               goto exit_ric_my_dear_dl;
          }

          if (0 == compressed_buffer_size_dl)
          {
               return_value_dl = 46;
               goto exit_ric_my_dear_dl;
          }

          u_len_dl = fread(&bits_array_buffer_size_dl, 1, 2, output_S2_file_dl);
          progress_dl += u_len_dl;
          if ((update_me_dl < GetTickCount64()))
          {
               update_me_dl = GetTickCount64() + 50;
               printf("Progress ric -> % 4d\r", current_progress_dl = getpor(tamanho_dl, progress_dl));
               fflush(stdout);
          }
          if (2 != u_len_dl)
          {
               return_value_dl = 38;
               goto exit_ric_my_dear_dl;
          }

          if (4096 < bits_array_buffer_size_dl)
          {
               return_value_dl = 40;
               goto exit_ric_my_dear_dl;
          }

          if (buffer_a_dl)
               free(buffer_a_dl); // avoiding memory leaks...

          buffer_a_dl = malloc(compressed_buffer_size_dl);

          if (DEBUG_DEC_DL__)
               pedro_dprintf(0, "tamanho do comprimido %d\n", (int)compressed_buffer_size_dl);

          len_dl = fread(buffer_a_dl, 1, (int)compressed_buffer_size_dl, output_S2_file_dl);
          progress_dl += len_dl;
          if ((update_me_dl < GetTickCount64()))
          {
               update_me_dl = GetTickCount64() + 50;
               printf("Progress ric -> % 4d\r", current_progress_dl = getpor(tamanho_dl, progress_dl));
               fflush(stdout);
          }
          if (len_dl != (int)compressed_buffer_size_dl)
          {
               return_value_dl = 41;
               goto exit_ric_my_dear_dl;
          }

          if (buffer_bits_array_dl)
               free(buffer_bits_array_dl);

          buffer_bits_array_dl = malloc(bits_array_buffer_size_dl + 1000 /* may be an invalid compressed file or tampered */);
          if (DEBUG_DEC_DL__)
               pedro_dprintf(0, "tamanho do bit array in bytes %d\n", (int)bits_array_buffer_size_dl);

          len_dl = fread(buffer_bits_array_dl, 1, (int)bits_array_buffer_size_dl, output_S2_file_dl);
          progress_dl += len_dl;
          if ((update_me_dl < GetTickCount64()))
          {
               update_me_dl = GetTickCount64() + 50;
               printf("Progress ric -> % 4d\r", current_progress_dl = getpor(tamanho_dl, progress_dl));
               fflush(stdout);
          }
          if (len_dl != (int)bits_array_buffer_size_dl)
          {
               return_value_dl = 42;
               goto exit_ric_my_dear_dl;
          }

          read_bit_dl(true,
                      buffer_bits_array_dl,
                      dl_,
                      bits_array_buffer_size_dl);

          // now starts the processing
          // goto read_next_bit_dl_jump;
          // exit(30);

          bytes_left_in_compressed_buffer_dl = compressed_buffer_size_dl;

          bytes_added_to_the_current_buffer_dl = 0;

          ptr_for_current_uncompressed_buffer_initial_position = buffer_uncompressed_current_dl;

          current_uncompressed_buffer_ptr_dl = buffer_uncompressed_current_dl; // at the beginning init all...

          compressed_buffer_ptr_dl = buffer_a_dl;

          bytes_already_in_uncompressed_buffer = 0;

     read_next_bit_dl_jump:;

          len_dl = read_bit_dl(false,
                               NULL,
                               dl_,
                               0);
          if (DEBUG_DEC_DL__)
               pedro_dprintf(0, "bit %d", len_dl);

          /*
                    if (2 != len_dl)
                    {
                         // goto again_dl;
                    }
          */

          if (2 == len_dl)
          {
               return_value_dl = 43;
               goto exit_ric_my_dear_dl;
          }

          if (0 == len_dl) // the byte is normal byte stored in the compressed stream
          {

               (*current_uncompressed_buffer_ptr_dl) = (*compressed_buffer_ptr_dl);

               current_uncompressed_buffer_ptr_dl++;

               compressed_buffer_ptr_dl++; // adding data and ajusting pointers

               bytes_already_in_uncompressed_buffer++;

               bytes_added_to_the_current_buffer_dl++;

               if (4096 < bytes_added_to_the_current_buffer_dl)
               {
                    // too much data added to uncompressed buffer
                    return_value_dl = 44;
                    goto exit_ric_my_dear_dl;
               }

               bytes_left_in_compressed_buffer_dl--;

               if (0 > bytes_left_in_compressed_buffer_dl)
               {
                    return_value_dl = 45;
                    goto exit_ric_my_dear_dl;
               }

               if (0 == bytes_left_in_compressed_buffer_dl)
               {

                    if (DEBUG_DEC_DL__)
                         pedro_dprintf(0, "bytes left in bit array %d", dl_->bytes_left_in_the_bits_array_dl);

                    if (DEBUG_DEC_DL__)
                         pedro_dprintf(0, "string processing -> bytes in bytes_already_in_uncompressed_buffer %d %d", bytes_already_in_uncompressed_buffer, bytes_left_in_compressed_buffer_dl);

                    if (DEBUG_DEC_DL__)
                    {
                         assert(0 && "1");
                    }
                    tamanho_got_dl += bytes_already_in_uncompressed_buffer;
                    adler32_real = dl_adler32_wrapper(adler32_real,
                                                      ptr_for_current_uncompressed_buffer_initial_position,
                                                      bytes_already_in_uncompressed_buffer);

                    if (fwrite(ptr_for_current_uncompressed_buffer_initial_position,
                               1,
                               bytes_already_in_uncompressed_buffer,
                               uncompressed_file_dl) != bytes_already_in_uncompressed_buffer)
                    {
                         return_value_dl = 50;
                         goto exit_ric_my_dear_dl;
                    }
                    // fwrite here

                    // assert(0 && "vai sair, terminou no bit 0 ");

                    // exit(27);

                    goto reiniciar_ric_dl;
               }
               goto read_next_bit_dl_jump;
          }

          if (1 == len_dl) // for version of 4096 compression searching buffer and 8192 bytes too this says that the bytes in the compressed stream are pointers, lets evaluate
          {

               if (0 == bytes_left_in_compressed_buffer_dl)
               {
                    // error
                    return_value_dl = 47;
                    goto exit_ric_my_dear_dl;
               }
               temp_dl[0] = (*compressed_buffer_ptr_dl);

               compressed_buffer_ptr_dl++;

               bytes_left_in_compressed_buffer_dl--;

               if (0 == bytes_left_in_compressed_buffer_dl)
               {
                    // error
                    return_value_dl = 47;
                    goto exit_ric_my_dear_dl;
               }

               temp_dl[1] = (*compressed_buffer_ptr_dl);

               compressed_buffer_ptr_dl++;

               bytes_left_in_compressed_buffer_dl--;

               composed_pointer_and_string_size_16_dl = *ptr_uint16_dl;

               // now process it
               get_string_size_and_address_in_the_current_buffer_dl(composed_pointer_and_string_size_16_dl,
                                                                    &string_size__dl,
                                                                    &address__dl);

#if DL_ENCODER_DECODER_MODE_ == DL_MODE_INITIAL_LZ77_PLUS_LZSS_LIMITED_BUFFER_SIZE_OF_4096

#include "mode_basic_4096_buf_size_dl.c"

#elif DL_ENCODER_DECODER_MODE_ == DL_MODE_EXTENDED_LZ77_PLUS_LZSS_AUGMENTED_THE_4096_BUFFER_TO_8192
#include "mode_basic_4096_buf_size_dl.c"
#else

#error Ric, value not handled, please check...

#endif

               if (0 == bytes_left_in_compressed_buffer_dl)
               {
                    tamanho_got_dl += bytes_already_in_uncompressed_buffer;
                    adler32_real = dl_adler32_wrapper(adler32_real,
                                                      ptr_for_current_uncompressed_buffer_initial_position,
                                                      bytes_already_in_uncompressed_buffer);
                    if (fwrite(ptr_for_current_uncompressed_buffer_initial_position,
                               1,
                               bytes_already_in_uncompressed_buffer,
                               uncompressed_file_dl) != bytes_already_in_uncompressed_buffer)
                    {
                         return_value_dl = 50;
                         goto exit_ric_my_dear_dl;
                    }

                    goto reiniciar_ric_dl;
               }

               goto read_next_bit_dl_jump;
          }

          assert(0);
          /*

now work...

          */
     }
     else
     {
          return_value_dl = 37;
          goto exit_ric_my_dear_dl;
     }
     /*


     */

exit_ric_my_dear_dl:;

     free(buffer_uncompressed_current_dl);

     free(buffer_uncompressed_previous_dl);

     free(dl_);
     dl_ = NULL;

     if (buffer_0_dl)
     {
          free(buffer_0_dl);
          buffer_0_dl = NULL;
     }

     if (buffer_bits_array_dl)
     {
          free(buffer_bits_array_dl);
          buffer_bits_array_dl = NULL;
     }

     if (buffer_a_dl)
     {
          free(buffer_a_dl);
          buffer_a_dl = NULL;
     }
     // let we see if it is already working...

     if (input_S2_file_dl)
     {
          fclose(input_S2_file_dl);
          input_S2_file_dl = NULL;
     }
     if (output_S2_file_dl)
     {
          fclose(output_S2_file_dl);
          output_S2_file_dl = NULL; // for safety
     }
     if (uncompressed_file_dl)
     {
          fclose(uncompressed_file_dl);
          uncompressed_file_dl = NULL;
     }

     unlink(temp_file_dl);

     printf("Progress ric -> % 4d\r", 100);
     printf("\n");

     if (0 == return_value_dl &&
         ((minha_struct.adler32_of_the_uncompressed_data_dl != adler32_real) ||
          minha_struct.size_of_the_file_to_compress_dl !=
              tamanho_got_dl))
     {

          // printf("tamanhos %lld %lld\n", minha_struct.size_of_the_file_to_compress_dl, tamanho_got_dl);
          return_value_dl = 51;
     }
     switch (return_value_dl)
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
          printf("Error 32: Invalid dl_compressor file, too small\n");
          break;
     case 33:
          printf("Error 33: Not a valid dl_compressor file, the initial characters are not 'dldl'\n");
          break;
     case 34:
          printf("Error 34: The first valid dl_compressor decoder available was char version (53 + 0 + 0 + 0) - v9.c, it is below it, it will never decompress, sorry\n");
          break;
     case 35:
          printf("Error 35: Compressed file was created with a future version of dl_compressor, but is a valid dl_compressor file\n");
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
     default:
          assert(0 && "Programming error ric...");
          break;
     }

     return return_value_dl;
}
