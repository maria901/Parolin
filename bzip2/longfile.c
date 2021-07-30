/*
    Copyright (C) <2021>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
        and GNU LESSER GENERAL PUBLIC LICENSE along with this program.
        If not, see <http://www.gnu.org/licenses/>.

    support: https://arsoftware.net.br/binarywork _____________
    mirror :  http://nomade.sourceforge.net/?AR=true&ar_debug=1

        direct programmers e-mails:
        Ricardo: arsoftware25@gmail.com  ricardo@arsoftware.net.br
         Amanda: arsoftware10@gmail.com  amanda@arsoftware.net. br

        immediate contact(for a very fast answer) WhatsApp
        (+55)41 9627 1708 - it is always on
 */

#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>

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
int setendofile (HANDLE file, __int64 position);
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

saida:
	;

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
	if (li.LowPart == isft && GetLastError () != ERROR_SUCCESS)
		return -1;
	return (__int64) li.QuadPart;
}

__int64 lftell (HANDLE hFile)
{
	LARGE_INTEGER li;
	int isft = -1;
	li.QuadPart = 0;
	li.LowPart = SetFilePointer (hFile, 0, &li.HighPart, FILE_CURRENT);

	if (li.LowPart == isft && GetLastError () != ERROR_SUCCESS)
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

	if (WriteFile (hFile, pBuffer, ulCount, &ulWritten, NULL) == FALSE)
		return 0;
	else
		return ulWritten;
}

int setendofile (HANDLE file, __int64 position)
{

	int ret;
	__int64 ret2;
	ret2 = lfseek (file, position, FILE_BEGIN);
	if (-1 == ret2)
	{
		return 0;
	}

	ret = SetEndOfFile (file);

	if (0 == ret)
	{
		return 0;
	}

	return 1;
}

/*
   by alladin
   C:\aoprojetoc\cdrtools\longfile.c
   11:58-quinta-feira, 1 de novembro de 2007
 */
