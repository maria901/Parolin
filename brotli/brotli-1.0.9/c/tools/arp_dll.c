/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails:                                                                 *
 *     maria@arsoftware.net.br                                                  *
 *     pedro@locacaodiaria.com.br                                               *
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

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

#include "helper_utilities_by_amanda_and_ricardo.c"

extern int main(int const argCount, const char **argv);

int __stdcall compress_br___rspk_ar(char *Input_amanda_file_utf_8, char *OutPut_ricardo_File_utf_8,
                                    __attribute__((unused)) int Compression_juliete_Level_unused___)
{

      int return_value_valquiria = 0;
      intpause___aakp = 0;
      intcancel__rspk = 0;
      tamanho____aakp = getfilesize_aakp_plus_rspk(Input_amanda_file_utf_8);
      processado_rspk = 0;
      porcentagem_junior_ale_mislaine_thalia_aline_juliete_valquiria_maria_feline_pedro = 0;
      return_value_arp = 0;
      /*
	                for the binary decode of the file.

	                [51] hex magic 0xfd2fb528 0xfd2fb528  _amanda_debug_
	                [27] ZSTD_MAGIC_SKIPPABLE_MASK = 0xfffffff0 ZSTD_MAGIC_SKIPPABLE_START = 0x184d2a50  _amanda_debug_

	 */

      //./test_arp.exe -f ./test_arp.exe -o ./test_arp.zst

      static char *my_main_args[6];

      my_main_args[0] = "test_arp.exe";
      my_main_args[1] = "-f";
      my_main_args[2] = "-9";
      my_main_args[3] = Input_amanda_file_utf_8;
      my_main_args[4] = "-o";
      my_main_args[5] = OutPut_ricardo_File_utf_8;

      return_value_valquiria = main(6, (const char **)my_main_args);

      if (return_value_valquiria)
      {
            return_value_valquiria = 8;
      }
      if (8 == return_value_arp)
      {
            return_value_valquiria = 8;
      }
      if (1 == return_value_arp)
      {
            return_value_valquiria = 1;
      }
      if (2 == return_value_arp)
      {
            return_value_valquiria = 2;
      }
      if (119 == return_value_arp)
      {
            return_value_valquiria = 119;
      }
      //return_value_valquiria = compress(fd_aakp, fd_valquiria_aakp);

      //5 cannot read from input file...., no
      //6 cannot write to output file , no, because if it occurs it need to close the application, it is ok to close (call exit(1))
      //8 compression error
      //first argument need to be 'test_arp.exe'

      //2;        //cannot open output file
      //1;        //cannot open input file
      //119       //user abort

      pedro_dprintf(-1, "return value %d\n", return_value_valquiria);
      return return_value_valquiria; //119 user cancel
}
int __stdcall uncompress_br___rspk_ar(char *Input_amanda_file_utf_8, char *OutPut_ricardo_File_utf_8)
{
      int return_value_valquiria = 0;
      intpause___aakp = 0;
      intcancel__rspk = 0;
      tamanho____aakp = getfilesize_aakp_plus_rspk(Input_amanda_file_utf_8);
      processado_rspk = 0;
      porcentagem_junior_ale_mislaine_thalia_aline_juliete_valquiria_maria_feline_pedro = 0;
      return_value_arp = 0;

      static char *my_main_args[6];

      my_main_args[0] = "test_arp.exe";
      my_main_args[1] = "-d";
      my_main_args[2] = "-f";
      my_main_args[3] = Input_amanda_file_utf_8;
      my_main_args[4] = "-o";
      my_main_args[5] = OutPut_ricardo_File_utf_8;

      return_value_valquiria = main(6, (const char **)my_main_args);

      if (return_value_valquiria)
      {
            return_value_valquiria = 7;
      }
      if (7 == return_value_arp)
      {
            return_value_valquiria = 7;
      }
      if (1 == return_value_arp)
      {
            return_value_valquiria = 1;
      }
      if (2 == return_value_arp)
      {
            return_value_valquiria = 2;
      }
      if (119 == return_value_arp)
      {
            return_value_valquiria = 119;
      }

      //return_value_valquiria = decompress(fd_aakp, fd_valquiria_aakp);
      //uncompress
      //5 cannot read from input file...., no
      //6 cannot write to output file , no
      //7 not a valid compressed file, ok solved
      //return_value_valquiria = 2;        //cannot open output file
      //return_value_valquiria = 1;        //cannot open input file

      pedro_dprintf(-1, "return value %d\n", return_value_valquiria);
      return return_value_valquiria; //119 user cancel
}
int __stdcall get_progress_br___ar(void)
{
      int ret_val_aakp_rspk_;

      ret_val_aakp_rspk_ = lgetpor(
          tamanho____aakp,
          processado_rspk);

      if (10000 < ret_val_aakp_rspk_)
      {
            return 10000;
      }
      if (0 > ret_val_aakp_rspk_)
      {
            return 0;
      }
      return ret_val_aakp_rspk_;
}

int __stdcall pause_br___aakp_br___ar(void)
{
      intpause___aakp = 1;
      return 0;
}
int __stdcall resume_br___aakp_br___ar(void)
{
      intpause___aakp = 0;
      return 0;
}
int __stdcall cancel_br___aakp_br___ar(void)
{
      intcancel__rspk = 1;
      return 0;
}

BOOL WINAPI DllMain(__attribute__((unused)) HINSTANCE hModule, __attribute__((unused)) DWORD ul_reason_for_call, __attribute__((unused)) LPVOID lpReserved)
{
      switch (ul_reason_for_call)
      {
      case DLL_PROCESS_ATTACH:
            OutputDebugString("BW Brotli DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") _amanda_debug_\n");

#ifdef NPRINTF
            MessageBox(0, "Alladin debugging code", "BinaryWork Corp.", MB_OK | MB_TOPMOST);
#endif
            break;
      case DLL_THREAD_ATTACH:

            break;
      case DLL_THREAD_DETACH:

            break;
      case DLL_PROCESS_DETACH:

            break;
      }
      return TRUE;
}
