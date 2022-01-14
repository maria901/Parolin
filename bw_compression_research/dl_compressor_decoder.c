

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

// 888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

int __fastcall decode_ric_dl(char *

                                 input_file_dl,
                             char *output_file_dl)
{
     /* he he he, irrelevant in win64,
     if you don't know it, cannot even be
     called from C# in win32 mode */

     /* no Unicode support during development, only
     later, sorry and I love fopen, not _wfopen */

     /*




     */

     // current decoder additional required variables...

     // lets add

     // will generate the memory as required, best option, since we already dont know the size

     // ok, lets go

     char *buffer_a_dl = NULL;

     /*




     */
     static dl_dados_salvos_querido_ric minha_struct;

     int return_value_dl = 0;
     char temp_file_dl[MAX_PATH + 1];
     FILE *input_S2_file_dl = NULL;
     __attribute__((unused)) /* I am a Linux guy these days,
 using only GCC for years now but I can change my mind
 and start calling cl.exe again if we have an
 interesting discussion */
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

     /*





































     */

exit_ric_my_dear_dl:;

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
          printf("Error 33: Not a valid dl_compressor file, the initial characters are not 'dldl', in 2025, december I tell you whats this dl means...\n");
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
     default:
          assert(0 && "Programming error ric...");
          break;
     }

     return return_value_dl;
}
