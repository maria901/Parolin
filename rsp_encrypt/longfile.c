
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
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
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

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

extern void __cdecl dprintf (char *format, ...);

extern int unicodemode;

WCHAR wpmode[600];

HANDLE lfopen (const char *szFileName, char *pMode);
void   lfclose (HANDLE hFile);
__int64 lfseek (HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell (HANDLE hFile);
__int64 lffilesize (const char *szFileName);
unsigned long lfread (void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite (void *pBuffer, unsigned long ulCount, HANDLE hFile);

int utf8towide (const char *pUTF8, WCHAR * pUSC2, int nUSC2)
{
	return MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, nUSC2);
}

int widetoutf8 (WCHAR * pUSC2, char *pUTF8, int nUTF8)
{
	return WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) pUTF8, nUTF8, 0, 0);
}


HANDLE lfopen (const char *szFileName, char *pMode)
{

	HANDLE ret = 0;
	assert(1 == unicodemode);

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
	case 'a':
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

saida:  //hack

	if (INVALID_HANDLE_VALUE == ret)
	{
		ret = 0;
	}
	return ret;
}

void lfclose (HANDLE hFile)
{
	assert (CloseHandle (hFile));
}

__int64 lfseek (HANDLE hFile, __int64 iDistance, int iMode)
{
	LARGE_INTEGER li;
	int isft = -1;
	li.QuadPart = iDistance;	
	li.LowPart = SetFilePointer (hFile, li.LowPart, &li.HighPart, iMode);
	if ((int)(li.LowPart) == (int)isft && GetLastError () != ERROR_SUCCESS)
		return -1;
	return (__int64) li.QuadPart;
}
__int64 lftell (HANDLE hFile)
{
	LARGE_INTEGER li;
	int isft = -1;
	li.QuadPart = 0;
	li.LowPart = SetFilePointer (hFile, 0, &li.HighPart, FILE_CURRENT);

	if ((int)(li.LowPart) == (int)isft && GetLastError () != ERROR_SUCCESS)
		return -1;
	return (__int64) li.QuadPart;
}

static __int64 fs_filesize (HANDLE hFile)
{
	LARGE_INTEGER li;

	li.QuadPart = 0;
	li.LowPart = GetFileSize (hFile, (LPDWORD) &li.HighPart);

	if (li.LowPart == 0xFFFFFFFF)
	{
		if (GetLastError () != ERROR_SUCCESS)
			return 0;
	}

	return (__int64) li.QuadPart;
}

__int64 lffilesize (const char *szFileName)
{
	__int64 iResult;
	HANDLE hFile;

	if (unicodemode)
	{
		utf8towide (szFileName, wpmode, 600);

#ifdef NPRINTF
		dprintf("arquivo %s\n",szFileName);
#endif

		hFile = CreateFileW (wpmode, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	}
	else
	{
		hFile = CreateFile (szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	}
	if (hFile == INVALID_HANDLE_VALUE)
		return 0;

	iResult = fs_filesize (hFile);

	CloseHandle (hFile);

	return iResult;
}

__int64 lffilesizeW (const WCHAR * szFileName)
{
	__int64 iResult;
	HANDLE hFile = CreateFileW (szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return 0;

	iResult = fs_filesize (hFile);

	CloseHandle (hFile);

	return iResult;
}

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

	pedro_dprintf(-1, "bytes written %d\n", ulCount);
	if (WriteFile (hFile, pBuffer, ulCount, &ulWritten, NULL) == FALSE)
		return 0;
	else
		return ulWritten;
}