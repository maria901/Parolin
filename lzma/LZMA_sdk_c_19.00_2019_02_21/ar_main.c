//december 2020, by bhond AND ava

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

#include "win64.h"

#include "aline_definitive_header_2_.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//defines...

char myinfile_ar[MAX_PATH + 1];
char myoutfile_ar[MAX_PATH + 1];

int intreturn_ar = 0;
int comando_ar = 0;
int running_ar = 0;
int intpause_ar = 0;
int intcancel_ar = 0;
int porcentagem_ar = 0;
int unicodemode_ar = 1; //always...
__int64 file_tamanho_ar = 0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pedro_dprintf(
    int amanda_level,
    char *format, ...);

int main_ar(int numArgs, char **);

char *__stdcall widetoutf8(WCHAR *pUSC2);

int lgetpor_ar(__int64 max, __int64 fatia);

__int64 lffilesize_ar(const char *szFileName);

static __int64 fs_filesize(HANDLE hFile);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////amanda/

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

/**
 * To make the path wide mode aware, stolen from libarchive
 * 
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond...
 *
 */
wchar_t *
permissive_name_m_(const wchar_t *wname)
{

	static wchar_t *wnp = NULL;
	wchar_t *wn;
	wchar_t *ws, *wsp;
	DWORD len, slen;
	int unc;

	if (NULL == wnp)
	{
		wnp = calloc((AMANDA__SIZE_w * 2) + 2, 1);
	}

	//wnp = malloc(AMANDA__SIZE * 2);

	wcscpy(wnp, wname);

	len = wcslen(wname);

	wn = wnp;

	if (wnp[0] == L'\\' && wnp[1] == L'\\' && // access to the wrong position in memory, fixed now
		wnp[2] == L'?' && wnp[3] == L'\\')
		/* We have already a permissive name. */
		return (wn);

	if (wnp[0] == L'\\' && wnp[1] == L'\\' &&
		wnp[2] == L'.' && wnp[3] == L'\\')
	{
		/* This is a device name */
		if (((wnp[4] >= L'a' && wnp[4] <= L'z') ||
			 (wnp[4] >= L'A' && wnp[4] <= L'Z')) &&
			wnp[5] == L':' && wnp[6] == L'\\')
			wnp[2] = L'?'; /* Not device name. */
		return (wn);
	}

	unc = 0;
	if (wnp[0] == L'\\' && wnp[1] == L'\\' && wnp[2] != L'\\')
	{
		wchar_t *p = &wnp[2];

		/* Skip server-name letters. */
		while (*p != L'\\' && *p != L'\0')
			++p;
		if (*p == L'\\')
		{
			wchar_t *rp = ++p;
			/* Skip share-name letters. */
			while (*p != L'\\' && *p != L'\0')
				++p;
			if (*p == L'\\' && p != rp)
			{
				/* Now, match patterns such as
				 * "\\server-name\share-name\" */
				wnp += 2;
				len -= 2;
				unc = 1;
			}
		}
	}

	slen = 4 + (unc * 4) + len + 1;
	ws = wsp = malloc(slen * sizeof(wchar_t));
	if (ws == NULL)
	{
		//free(wn);
		return (NULL);
	}
	/* prepend "\\?\" */
	wcsncpy(wsp, L"\\\\?\\", 4);
	wsp += 4;
	slen -= 4;
	if (unc)
	{
		/* append "UNC\" ---> "\\?\UNC\" */
		wcsncpy(wsp, L"UNC\\", 4);
		wsp += 4;
		slen -= 4;
	}
	wcsncpy(wsp, wnp, slen);
	wsp[slen - 1] = L'\0'; /* Ensure null termination. */
	//free(wn);

	wcscpy(wnp, ws);

	free(ws);

	return (wnp);
}

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we 
 *  . provide two functions that are exactly the same because someone may 
 * use it in multi-thread code 
 *
 * @param pUTF8 the input utf-8 encoded filename 
 *
 * @return the static allocated WCHAR array with the filename as wide string 
 *
 */
WCHAR *amanda_utf8towide_1_v27(char *pUTF8)
{
	static WCHAR ricardo_k[AMANDA__SIZE_w + 1];
	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, AMANDA__SIZE_w);
	return permissive_name_m_(ricardo_k);
}

int lgetpor_ar(__int64 max, __int64 fatia)
{
      /*

   2/27/2004 12:13PM modificacao para evitar divisao por 0

 */

      double maxa;
      double fatiaa;

      maxa = (double)max;
      fatiaa = (double)fatia;

      if (max == 0 || fatia == 0)
      {
            return 0;
      }

      maxa = ((double)10000 / maxa * fatiaa);

      return (int)maxa;
}

static __int64 fs_filesize(HANDLE hFile)
{
      LARGE_INTEGER li;

      li.QuadPart = 0;
      li.LowPart = GetFileSize(hFile, (LPDWORD)&li.HighPart);

      if (li.LowPart == 0xFFFFFFFF)
      {
            if (GetLastError() != ERROR_SUCCESS)
                  return 0;
      }

      return (__int64)li.QuadPart;
}

__int64 lffilesize_ar(const char *szFileName)
{
      __int64 iResult;
      HANDLE hFile;

      if (unicodemode_ar)
      {

#ifdef NPRINTF
            dprintf("arquivo %s\n", szFileName);
#endif
            {
                  hFile = CreateFileW(amanda_utf8towide_1_v27((void *) szFileName), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
            }
      }
      else
      {
            hFile = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
      }
      if (hFile == INVALID_HANDLE_VALUE)
            return 0;

      iResult = fs_filesize(hFile);
      CloseHandle(hFile);
      return iResult;
}

char *__stdcall widetoutf8(WCHAR *pUSC2)
{
      static int position = 0;
#define THESIZE (300 * 6)
      if (0 == position)

      {
            static char pUTF8[THESIZE];
            position = 1;

            WideCharToMultiByte(CP_UTF8, 0, pUSC2, -1, (LPSTR)pUTF8, THESIZE, 0, 0);
            return pUTF8;
      }
      else
      {
            static char pUTF8[THESIZE];
            position = 0;

            WideCharToMultiByte(CP_UTF8, 0, pUSC2, -1, (LPSTR)pUTF8, THESIZE, 0, 0);
            return pUTF8;
      }
      return NULL;
}

int soc_lzma_compress_ar(char *myinfile__ar, char *myoutfile__ar, __attribute__((unused)) int level_ar)
{

      int ret_ar = 0;
      static char *my_main_args[5];
      //static char *argvv[15];

      my_main_args[0] = "my_amanda_executable.exe";
      my_main_args[1] = "e";
      my_main_args[2] = myinfile__ar;
      my_main_args[3] = myoutfile__ar;

      ret_ar = main_ar(4, my_main_args);

      //free(my_main_args);

      return ret_ar;
}
int soc_lzma_uncompress_ar(char *myinfile__ar, char *myoutfile__ar)
{

      int ret_ar = 0;
      static char *my_main_args[5];
      //static char *argvv[15];

      //my_main_args = (char **) malloc(300);

      my_main_args[0] = "my_amanda_executable.exe";
      my_main_args[1] = "d";
      my_main_args[2] = myinfile__ar;
      my_main_args[3] = myoutfile__ar;

      ret_ar = main_ar(4, my_main_args);

      //free(my_main_args);

      return ret_ar;
}

int __stdcall compress_lzma_aakp_rspk(char *valquiria_input__file_utf_8,
                                      char *juliete___output_file_utf_8,
                                      int junior_compression_level___)
{
      int returnvalue_aakp;
      file_tamanho_ar = lffilesize_ar(valquiria_input__file_utf_8);

      porcentagem_ar = 0;
      intpause_ar = 0;
      intcancel_ar = 0;

      returnvalue_aakp = soc_lzma_compress_ar(valquiria_input__file_utf_8,
                                              juliete___output_file_utf_8,
                                              junior_compression_level___);

      if (intcancel_ar)
      {
            return 119;
      }

      return returnvalue_aakp;
}
int __stdcall uncompress_lzma_aakp_rspk(
    char *valquiria_input__file_utf_8,
    char *juliete___output_file_utf_8)
{
      int returnvalue_aakp;

      porcentagem_ar = 0;
      intpause_ar = 0;
      intcancel_ar = 0;

      file_tamanho_ar = lffilesize_ar(valquiria_input__file_utf_8);
      returnvalue_aakp = soc_lzma_uncompress_ar(
          valquiria_input__file_utf_8,
          juliete___output_file_utf_8);

      if (intcancel_ar)
      {
            return 119;
      }

      return returnvalue_aakp;
}
int __stdcall startapi_ar(__attribute__((unused)) int parameter_______ar)
{
      //0 compress 1 decompress

      running_ar = 1;
      if (comando_ar == 0)
      {
            intreturn_ar = 0;
            intreturn_ar = soc_lzma_compress_ar(myinfile_ar, myoutfile_ar, 6);
      }

      if (1 == comando_ar)
      {
            intreturn_ar = 0;
            intreturn_ar = soc_lzma_uncompress_ar(myinfile_ar, myoutfile_ar);
      }
      running_ar = 0;

      return 0;
}

int __stdcall execute_ar(char *infile, char *outfile, int comando1)
{

      /*
   char myinfile[255] ;
   char myoutfile[255] ;
   int comando ;
   char mylevel[255] ;
 */

      HANDLE myhandle;
      __INT32_OR_INT64 ThreadId;
      __INT32_OR_INT64 parameter = 1;
      strcpy(myinfile_ar, infile);
      strcpy(myoutfile_ar, outfile);

      comando_ar = comando1; // 0 = compress 1 = decompress

      running_ar = 1;

      myhandle =
          CreateThread((LPSECURITY_ATTRIBUTES)0, (DWORD)0, (void *)startapi_ar,
                       (LPVOID)parameter, (DWORD)0, (LPDWORD)&ThreadId);
      CloseHandle(myhandle);
      return 2;
}

int __stdcall ControlName(char *data)
{
      strcpy(data, "BW LZMA DLL " AMARIC__VERSION
#ifdef _WIN64
                   "    - 64 bits"
#else
                   "    - 32 bits"
#endif
      );
      return 0;
}

int __stdcall Compress(char *infile_ar, char *outfile_ar)
{

      if (running_ar)
      {
            return 1;
      }

      file_tamanho_ar = lffilesize_ar(infile_ar);

      porcentagem_ar = 0;
      intpause_ar = 0;
      intcancel_ar = 0;

      execute_ar(infile_ar, outfile_ar, 0);

      return 0; //interface1((__INT32_OR_INT64)"compress",(__INT32_OR_INT64)infile,(__INT32_OR_INT64)outfile,(__INT32_OR_INT64)0);
}
int __stdcall Uncompress(char *infile_ar, char *outfile_ar)
{

      if (running_ar)
      {
            return 1;
      }

      file_tamanho_ar = lffilesize_ar(infile_ar);

      porcentagem_ar = 0;
      intpause_ar = 0;
      intcancel_ar = 0;
      execute_ar(infile_ar, outfile_ar, 1);
      return 0; //interface1((__INT32_OR_INT64)"uncompress",(__INT32_OR_INT64)infile,(__INT32_OR_INT64)outfile,(__INT32_OR_INT64)0);
}

int __stdcall Resume()
{

      intpause_ar = 0;

      return 0;
}
int __stdcall Pause()
{

      intpause_ar = 1;
      return 0; //interface1((__INT32_OR_INT64)"pause",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);
}

int __stdcall Cancel()
{
      intcancel_ar = 1;
      return 0; //interface1((__INT32_OR_INT64)"cancel",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);
}

int __stdcall Returnvalue()
{

      if (intcancel_ar)
      {
            return -1;
      }

      return intreturn_ar;
      //return interface1((__INT32_OR_INT64)"returnvalue",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);
}

int __stdcall Running()
{

      return running_ar; //interface1((__INT32_OR_INT64)"running",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);
}

int __stdcall Progress()
{

      int por_ar = porcentagem_ar;
      pedro_dprintf(-1, "dentro %d\n", porcentagem_ar);
      if (por_ar < 0)
      {
            por_ar = 0;
      }

      if (por_ar > 10000)
      {
            por_ar = 10000;
      }
      return por_ar;

      //return interface1((__INT32_OR_INT64)"progress",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);
}

BOOL WINAPI DllMain(__attribute__((unused)) HINSTANCE hModule, DWORD ul_reason_for_call, __attribute__((unused)) LPVOID lpReserved)
{
      switch (ul_reason_for_call)
      {
      case DLL_PROCESS_ATTACH:
            OutputDebugString("BE LZMA DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") _amanda_debug_\n");

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