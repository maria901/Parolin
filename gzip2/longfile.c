/********************************************************************************
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
 ********************************************************************************
 
      E-mails:                                                                 
      maria@arsoftware.net.br                                                  
      pedro@locacaodiaria.com.br                                               

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 *******************************************************************************/

/* 
 modified 2020
*/
//2021 MathMan and amanda
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

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE_ww ((32767 * 2) + 2) /* having fun... */

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
WCHAR *amanda_utf8towide_1_v27_no_october_2021(const char *pUTF8);

WCHAR *amanda_utf8towide_1_v28(char *pUTF8, WCHAR *ar_temp);

wchar_t *
permissive_name_m_v28(const wchar_t *wname, WCHAR *ar_temp);

extern void __cdecl dprintf(char *format, ...);

extern int unicodemode; //if 1 the file is an utf-8 encoded Unicode string, if 0 it is a ansi string

HANDLE lfopen(const char *szFileName, char *pMode);
void lfclose(HANDLE hFile);
__int64 lfseek(HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell(HANDLE hFile);
__int64 lffilesize(const char *szFileName);
unsigned long lfread(void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite(void *pBuffer, unsigned long ulCount, HANDLE hFile);

/*

//for historical reasons...
HANDLE lfopen (const char *szFileName, char *pMode)
{


     HANDLE ret = 0;

     if (0 == strcmp (pMode, "rb+"))
       {
#ifdef NPRINTF
	    dprintf ("Usando rb+\n");
#endif


	    if (unicodemode)
	      {
		   utf8towide (szFileName, wpmode, 600);
		   ret = CreateFileW (wpmode, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	      }
	    else
	      {

		   ret = CreateFile (szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    goto saida;
       }

     switch (pMode[0])
       {
       case 'r':

#ifdef NPRINTF
	    dprintf ("opening read file %s \n", szFileName);
#endif
	    if (unicodemode)
	      {
		   utf8towide (szFileName, wpmode, 600);
		   ret = CreateFileW (wpmode, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	      }
	    else
	      {
		   ret = CreateFile (szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    break;
       case 'w':
#ifdef NPRINTF
	    dprintf ("opening write file %s \n", szFileName);
#endif
	    if (unicodemode)
	      {
		   utf8towide (szFileName, wpmode, 600);
		   ret = CreateFileW (wpmode, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    else
	      {
		   ret = CreateFile (szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    break;
       case 'a'://not tested, as far as I know it will not start from the end of the file as you can see below
	    if (unicodemode)
	      {
		   utf8towide (szFileName, wpmode, 600);
		   ret = CreateFileW (wpmode, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    else
	      {
		   ret = CreateFile (szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    break;

       default:
	    break;

       }

   saida:			//hack

     if (INVALID_HANDLE_VALUE == ret)
       {

	    ret = 0;
       }
     return ret;
}

*/
/*

void lfclose (HANDLE hFile)
{
//hummmmmmmm
     assert (CloseHandle (hFile));
}

*/

/*
__int64 lfseek (HANDLE hFile, __int64 iDistance, int iMode)
{
     LARGE_INTEGER li;

     int    isft = -1;


     li.QuadPart = iDistance;


     //tested modes FILE_END    FILE_CURRENT    FILE_BEGIN
     li.LowPart = SetFilePointer (hFile, li.LowPart, &li.HighPart, iMode);

     if (li.LowPart == isft && GetLastError () != ERROR_SUCCESS)
	  return -1;

     return (__int64) li.QuadPart;
}
*/
/*
__int64 lftell (HANDLE hFile)
{
     LARGE_INTEGER li;
     int    isft = -1;
     li.QuadPart = 0;
     li.LowPart = SetFilePointer (hFile, 0, &li.HighPart, FILE_CURRENT);

     if (li.LowPart == isft && GetLastError () != ERROR_SUCCESS)
	  return -1;

     return (__int64) li.QuadPart;
}
*/

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

__int64 lffilesize(const char *szFileName) //is utf-8
{
     __int64 iResult;
     HANDLE hFile;

     if (unicodemode)
     {

#ifdef NPRINTF
          dprintf("arquivo %s\n", szFileName);
#endif

          WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
          WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

          hFile = CreateFileW(permissive_name_m_v28(amanda_utf8towide_1_v28((void *)szFileName, ar_temp), ar_temp2), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

          free(ar_temp);
          free(ar_temp2);
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

__int64 lffilesizeW(const WCHAR *szFileName) //not in use
{
     __int64 iResult;
     HANDLE hFile = CreateFileW(szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
     if (hFile == INVALID_HANDLE_VALUE)
          return 0;

     iResult = fs_filesize(hFile);

     CloseHandle(hFile);

     return iResult;
}
/*

unsigned long lfread (void *pBuffer, unsigned long ulCount, HANDLE hFile)
{
     unsigned long ulRead;

     if (ReadFile (hFile, pBuffer, ulCount, &ulRead, NULL) == FALSE)
	  return 0;
     else
	  return ulRead;
}


unsigned long lfwrite (void *pBuffer, unsigned long ulCount, HANDLE hFile)
{
     unsigned long ulWritten;

     if (WriteFile (hFile, pBuffer, ulCount, &ulWritten, NULL) == FALSE)
	  return 0;
     else
	  return ulWritten;
}

*/