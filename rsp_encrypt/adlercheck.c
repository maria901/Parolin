
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

#define AMANDA_TAMANHO 0x100000

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort unsigned short
#endif
#endif

HANDLE lfopen(const char *szFileName, char *pMode);
void lfclose(HANDLE hFile);
__int64 lfseek(HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell(HANDLE hFile);
__int64 lffilesize(const char *szFileName);
unsigned long lfread(void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite(void *pBuffer, unsigned long ulCount, HANDLE hFile);

void dprintf(char *format, ...);

/*********************************************************************************************/

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
 * Ricardo helper function...just it, without it no large paths support
 * 
 * ****************************************************************************************/
wchar_t *
permissive_name_m_(const wchar_t *wname);

wchar_t *
permissive_name_m_v27(const wchar_t *wname);
/*******************************************************************************************/
#define BASE 65521L /* largest prime smaller than 65536 */
#define NMAX 5552
/* NMAX is the largest n such that 255n(n+1)/2 + (n+1)(BASE-1) <= 2^32-1 */

#define DO1(buf, i)   \
	{                 \
		s1 += buf[i]; \
		s2 += s1;     \
	}
#define DO2(buf, i) \
	DO1(buf, i);    \
	DO1(buf, i + 1);
#define DO4(buf, i) \
	DO2(buf, i);    \
	DO2(buf, i + 2);
#define DO8(buf, i) \
	DO4(buf, i);    \
	DO4(buf, i + 4);
#define DO16(buf) \
	DO8(buf, 0);  \
	DO8(buf, 8);

/* ========================================================================= */
uint adler32(uint adler, const uchar *buf, uint len)
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
			DO16(buf);
			buf += 16;
			k -= 16;
		}
		if (k != 0)
			do
			{
				s1 += *buf++;
				s2 += s1;
			} while (--k);
		s1 %= BASE;
		s2 %= BASE;
	}
	return (s2 << 16) | s1;
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static uint
checkfileexists(char *infile)
{
#pragma GCC diagnostic pop
	uint ret;

	FILE *myfile;

	///missing Unicode and large paths support...
	if ((myfile = fopen(infile, "rb")) == NULL)
	{
		ret = 0;
	}
	else
	{
		ret = 1;
	}

	if (ret)
	{
		fclose(myfile);
	}
	return ret;
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static uint
getfilesize(char *infile)
{
#pragma GCC diagnostic pop
	uint ret;

	FILE *myfile;

	if ((myfile = fopen(infile, "rb")) == NULL)
	{
		return 0;
	}
	else
	{
	}

	ret = fseek(myfile, 0, SEEK_END);

	ret = ftell(myfile);

	fclose(myfile);

	return ret;
}

int adler32filelong(uchar *inputfile)
{

	static uchar buf[AMANDA_TAMANHO];
	HANDLE stream;
	//uint ret;
	uint len;
	//uint j;
	//char output[65];
	uint crc;

	crc = 0;

	if ((stream = lfopen((char *)inputfile, "rb")) != NULL)
	{
	}
	else
	{

#ifdef NPRINTF
		dprintf("error opening input file \n");
#endif
		return 1;
	}

	while (1)
	{

		len = lfread(buf, AMANDA_TAMANHO, stream);

		if (len <= 0)
		{
			break;
		}

		crc = adler32(crc, buf, len);
	}

	lfclose(stream);

	return crc;
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
static int
adler32file(uchar *inputfile, uchar *out)
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

	if ((stream = lfopen((char *)inputfile, "rb")) != NULL)
	{
	}
	else
	{
#ifdef NPRINTF
		dprintf("error opening input file \n");
#endif
		return 1;
	}

	while (1)
	{

		len = lfread(buf, 4096, stream);

		if (len <= 0)
		{
			break;
		}

		crc = adler32(crc, buf, len);
	}

	lfclose(stream);
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
	sprintf(output, "%0.8x", crc);
#pragma GCC diagnostic pop
	strcpy((char *)out, output);

	return 0;
}