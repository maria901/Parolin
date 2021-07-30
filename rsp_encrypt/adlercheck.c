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

//Adler32 developed by Mark Adler from zlib.org, please visit
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

#   define AMANDA_TAMANHO     0x100000

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

HANDLE lfopen (const char *szFileName, char *pMode);
void   lfclose (HANDLE hFile);
__int64 lfseek (HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell (HANDLE hFile);
__int64 lffilesize (const char *szFileName);
unsigned long lfread (void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite (void *pBuffer, unsigned long ulCount, HANDLE hFile);

void
dprintf (char *format, ...);

#define BASE 65521L             /* largest prime smaller than 65536 */
#define NMAX 5552
/* NMAX is the largest n such that 255n(n+1)/2 + (n+1)(BASE-1) <= 2^32-1 */

#define DO1(buf,i)  {s1 += buf[i]; s2 += s1;}
#define DO2(buf,i)  DO1(buf,i); DO1(buf,i+1);
#define DO4(buf,i)  DO2(buf,i); DO2(buf,i+2);
#define DO8(buf,i)  DO4(buf,i); DO4(buf,i+4);
#define DO16(buf)   DO8(buf,0); DO8(buf,8);

/* ========================================================================= */
uint
adler32 (uint adler, const uchar * buf, uint len)
{
	unsigned long s1 = adler & 0xffff;
	unsigned long s2 = (adler >> 16) & 0xffff;
	int k;

	if (buf == NULL)
		return 1L;

	while (len > 0)
	{
		k = len < NMAX ? len : NMAX;
		len -= k;
		while (k >= 16)
		{
			DO16 (buf);
			buf += 16;
			k -= 16;
		}
		if (k != 0)
			do
			{
				s1 += *buf++;
				s2 += s1;
			}
			while (--k);
		s1 %= BASE;
		s2 %= BASE;
	}
	return (s2 << 16) | s1;
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static uint
checkfileexists (char *infile)
{
#pragma GCC diagnostic pop
	uint ret;

	FILE *myfile;

	if ((myfile = fopen (infile, "rb")) == NULL)
	{
		ret = 0;
	}
	else
	{
				ret = 1;
	}

	if (ret)
	{
		fclose (myfile);
	}
	return ret;
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static uint
getfilesize (char *infile)
{
#pragma GCC diagnostic pop
	uint ret;

	FILE *myfile;

	if ((myfile = fopen (infile, "rb")) == NULL)
	{
		return 0;
	}
	else
	{
	
	}

	ret = fseek (myfile, 0, SEEK_END);

	ret = ftell (myfile);

	fclose (myfile);

	return ret;

}

int
adler32filelong (uchar * inputfile)
{

	static uchar buf[AMANDA_TAMANHO];
	HANDLE stream;
	//uint ret;
	uint len;
	//uint j;
	//char output[65];
	uint crc;

	crc = 0;

	if ((stream = lfopen ((char *)inputfile, "rb")) != NULL)
	{

	}
	else
	{

#ifdef NPRINTF
		dprintf ("error opening input file \n");
#endif
		return 1;
	}

	while (1)
	{

		len = lfread (buf, AMANDA_TAMANHO, stream);

		if (len <= 0)
		{
			break;
		}

		crc = adler32 (crc, buf, len);

	}

	lfclose (stream);

	return crc;

}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static int
adler32file (uchar * inputfile, uchar * out)
{
#pragma GCC diagnostic pop
	uchar buf[4097];
	HANDLE stream;
	//uint ret;
	uint len;
	//uint j;
	char output[65];
	uint crc;

	crc = 0;

	if ((stream = lfopen ((char *) inputfile, "rb")) != NULL)
	{

	}
	else
	{
#ifdef NPRINTF
		dprintf ("error opening input file \n");
#endif
		return 1;
	}

	while (1)
	{

		len = lfread (buf,  4096, stream);

		if (len <= 0)
		{
			break;
		}

		crc = adler32 (crc, buf, len);

	}

	lfclose (stream);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
	sprintf (output, "%0.8x", crc);
#pragma GCC diagnostic pop
	strcpy ((char *) out, output);

	return 0;

}