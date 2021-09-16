/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de C�pia (C) <2021>  <Corpora��o do Trabalho Bin�rio>         *
 *                                                                              *
 *     Este  programa  � software livre: voc� pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como       8
 *     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da       *
 *     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.         *
 *                                                                              *
 *     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de       *
 *     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P�blica para mais detalhes.                                *
 *                                                                              *
 *     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P�blica Menor junto com este programa                            *
 *     Se n�o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails:                                                                 *
 *     maria@arsoftware.net.br                                                  *
 *     pedro@locacaodiaria.com.br                                               *
 *                                                                              *
 *     contato imediato(para uma resposta muito r�pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                 *      
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

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows, 
 * it is an approximation, in bytes
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

/**
 * Ricardo helper function...just it, without it no large paths support
 * 
 * ****************************************************************************************/
wchar_t *
permissive_name_m_(const wchar_t *wname);

wchar_t *
permissive_name_m_v27(const wchar_t *wname);
/*******************************************************************************************/

void pedro_dprintf(
	int amanda_level,
	char *format, ...);

extern void __cdecl dprintf(char *format, ...);

extern int unicodemode;

HANDLE lfopen(const char *szFileName, char *pMode);
void lfclose(HANDLE hFile);
__int64 lfseek(HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell(HANDLE hFile);
__int64 lffilesize(const char *szFileName);
unsigned long lfread(void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite(void *pBuffer, unsigned long ulCount, HANDLE hFile);

int utf8towide(const char *pUTF8, WCHAR *pUSC2, int nUSC2)
{
	return MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, pUSC2, nUSC2);
}

int widetoutf8(WCHAR *pUSC2, char *pUTF8, int nUTF8)
{
	return WideCharToMultiByte(CP_UTF8, 0, pUSC2, -1, (LPSTR)pUTF8, nUTF8, 0, 0);
}

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we
 * provide two functions that are exactly the same because someone may
 * use it in multi-thread code
 *
 * @param pUTF8 the input utf-8 encoded filename
 *
 * @return the static allocated WCHAR array with the filename as wide string
 *
 */
WCHAR *amanda_utf8towide_1_(char *pUTF8);

HANDLE lfopen(const char *szFileName, char *pMode)
{

	HANDLE ret = 0;
	assert(1 == unicodemode);

	if (0 == strcmp(pMode, "rb+"))
	{
#ifdef NPRINTF
		dprintf("Usando rb+\n");
#endif

		if (unicodemode)
		{
			ret = CreateFileW(permissive_name_m_(amanda_utf8towide_1_((void *)szFileName)), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
		else
		{
			ret = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
		goto saida;
	}

	switch (pMode[0])
	{
	case 'r':

#ifdef NPRINTF
		dprintf("opening read file %s \n", szFileName);
#endif
		if (unicodemode)
		{
			ret = CreateFileW(permissive_name_m_(amanda_utf8towide_1_((void *)szFileName)), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
		else
		{
			ret = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
		break;
	case 'w':
#ifdef NPRINTF
		dprintf("opening write file %s \n", szFileName);
#endif
		if (unicodemode)
		{
			ret = CreateFileW(permissive_name_m_(amanda_utf8towide_1_((void *)szFileName)), GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
		else
		{
			ret = CreateFile(szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
		break;
	case 'a':
		if (unicodemode)
		{
			ret = CreateFileW(permissive_name_m_(amanda_utf8towide_1_((void *)szFileName)), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
		else
		{
			ret = CreateFile(szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
		break;

	default:
		break;
	}

saida: //hack

	if (INVALID_HANDLE_VALUE == ret)
	{
		ret = 0;
	}
	return ret;
}

void lfclose(HANDLE hFile)
{
	assert(CloseHandle(hFile));
}

__int64 lfseek(HANDLE hFile, __int64 iDistance, int iMode)
{
	LARGE_INTEGER li;
	int isft = -1;
	li.QuadPart = iDistance;
	li.LowPart = SetFilePointer(hFile, li.LowPart, &li.HighPart, iMode);
	if ((int)(li.LowPart) == (int)isft && GetLastError() != ERROR_SUCCESS)
		return -1;
	return (__int64)li.QuadPart;
}
__int64 lftell(HANDLE hFile)
{
	LARGE_INTEGER li;
	int isft = -1;
	li.QuadPart = 0;
	li.LowPart = SetFilePointer(hFile, 0, &li.HighPart, FILE_CURRENT);

	if ((int)(li.LowPart) == (int)isft && GetLastError() != ERROR_SUCCESS)
		return -1;
	return (__int64)li.QuadPart;
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

__int64 lffilesize(const char *szFileName)
{
	__int64 iResult;
	HANDLE hFile;

	if (unicodemode)
	{
		//utf8towide(szFileName, wpmode, 600);

#ifdef NPRINTF
		dprintf("arquivo %s\n", szFileName);
#endif

		hFile = CreateFileW(permissive_name_m_(amanda_utf8towide_1_((void *)szFileName)), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
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

__int64 lffilesizeW(const WCHAR *szFileName)
{
	__int64 iResult;
	HANDLE hFile = CreateFileW(permissive_name_m_(szFileName), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return 0;

	iResult = fs_filesize(hFile);

	CloseHandle(hFile);

	return iResult;
}

unsigned long lfread(void *pBuffer, unsigned long ulCount, HANDLE hFile)
{
	unsigned long ulRead;

	if (ReadFile(hFile, pBuffer, ulCount, &ulRead, NULL) == FALSE)
		return 0;
	else
		return ulRead;
}

unsigned long lfwrite(void *pBuffer, unsigned long ulCount, HANDLE hFile)
{
	unsigned long ulWritten;

	pedro_dprintf(-1, "bytes written %d\n", ulCount);
	if (WriteFile(hFile, pBuffer, ulCount, &ulWritten, NULL) == FALSE)
		return 0;
	else
		return ulWritten;
}