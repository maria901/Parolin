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

int __fastcall /* he he he, irrelevant in win64, if you don't know it, cannot even be called from C# in win32 mode */ decode_ric_dl(char *
                                                                                                                                        /* no Unicode support during development, only later, sorry and I love fopen, not _wfopen */
                                                                                                                                        input_file_dl,
                                                                                                                                    char *output_file_dl)
{
    int return_value_dl = 0;
    FILE *input_S2_file_dl = NULL;
    __attribute__((unused)) /* I am a Linux guy these days, using only GCC for years now but I can change my mind and start calling cl.exe again with we have an interesting discussion */ FILE *output_S2_file_dl = NULL;

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
    output_S2_file_dl = fopen(output_file_dl, "wb");

    // I must be using Emacs just I can't now that I am acostumated with VSCode speed

    if (NULL == output_S2_file_dl)
    {
        return_value_dl = 31; // 31: Cannot open output file
        goto exit_ric_my_dear_dl;
    }

exit_ric_my_dear_dl:;

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
    }
    return return_value_dl;
}