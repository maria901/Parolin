
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de C?pia (C) <2021>  <Corpora??o do Trabalho Bin?rio>         *
 *                                                                              *
 *     Este  programa  ? software livre: voc? pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P?blica como       8
 *     publicado  pela Funda??o  de Software  Livre, tanto a vers?o 3  da       *
 *     Licensa, ou (dependendo da sua op??o) qualquer vers?o posterior.         *
 *                                                                              *
 *     Este  programa ? distribu?do na  esperan?a que isto vai  ser ?til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at? mesmo a implicada garantia de       *
 *     COMERCIALIZA??O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P?blica para mais detalhes.                                *
 *                                                                              *
 *     Voc? deve ter recebido uma  c?pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P?blica Menor junto com este programa                            *
 *     Se n?o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita r?pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est? sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

#define SHA512_DIGEST_LENGTH 64

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

void pedro_dprintf(
	int amanda_level,
	char *format, ...);

#include "zlib.h"

#include "md5.h"

extern int unicodemode;
extern uint pauseflag;
extern uint cancelflag;

extern int finished;

typedef struct _rspdata
{

	char string[4];
	int a;
	int b;
	int c;
	int d;
	int attrib;

} rspdata;

typedef struct _ar_data
{

	char string[4];
	unsigned char sha512_k[SHA512_DIGEST_LENGTH];
	int attrib;

} ar_data;

int zuncompress_sha512_k(char *input, char *output);

void *sha512_init_k(void);

void sha512_update_k(void *ctx, unsigned char *buffer_k, unsigned int len_k);

void sha512_final_k(void *ctx, unsigned char *array_digest_64_bytes);

int utf8towide(const char *pUTF8, WCHAR *pUSC2, int nUSC2);
extern void __cdecl mprintf(char *format, ...);
uint getpor(int max, uint fatia);
void dprintf(char *format, ...);
int __stdcall execute();
int start();
int start2();

__int64 lffilesize(const char *szFileName);

int lgetpor(__int64 max, __int64 fatia);

#define CHUNK 1638400

int zlibpercent = 0;

int lgetpor(__int64 max, __int64 fatia)
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

	maxa = ((double)100 / maxa * fatiaa);

	return (int)maxa;
}

int zcompress(char *input, char *output, int levelin)
{
	FILE *dest = NULL;
	FILE *source = NULL;
	__int64 bytesread = 0;
	__int64 bytestosave = 0;
	__int64 totalbytes = 0;
	int done = 0;
	int flush;
	int last = 0;
	int level = Z_DEFAULT_COMPRESSION;
	int ret = 0;
	int ret2 = 0;
	int retvalue = 0;
	int writebytes = 0;
	md5_context ctx;
	rspdata rsp;
	static char buffer[CHUNK + 1];
	static char out[CHUNK];
	unsigned char md5sum[16];
	z_stream strm;

	pauseflag = 0;
	cancelflag = 0;
	level = levelin;

	if (levelin <= 0)
	{

		level = 1;
	}

	if (levelin > 9)
	{

		level = 9;
	}

#ifdef NPRINTF
	dprintf("->compression level %d \n", level);
#endif

	md5_starts(&ctx);

	memset(&rsp, 0, sizeof(rsp));

	memcpy(rsp.string, "RSPG", 4);

	memset(&strm, 0, sizeof(strm));

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;

#ifdef NPRINTF
	dprintf(" using level %d\n", level);
#endif

	ret = deflateInit(&strm, level);
	assert(ret == Z_OK);

	switch (level)
	{
	case 0:
		deflateParams(&strm, Z_NO_COMPRESSION, Z_DEFAULT_STRATEGY);
		break;
	case 1:
		deflateParams(&strm, Z_NO_COMPRESSION, Z_DEFAULT_STRATEGY);
		break;
	case 2:
		deflateParams(&strm, level, Z_HUFFMAN_ONLY);
		break;
	case 3:
		deflateParams(&strm, level, Z_HUFFMAN_ONLY);
		break;
	case 4:
		deflateParams(&strm, level, Z_HUFFMAN_ONLY);
		break;
	case 5:
		deflateParams(&strm, level, Z_HUFFMAN_ONLY);
		break;
	case 6:
		deflateParams(&strm, level, Z_FILTERED);
		break;
	case 7:
		deflateParams(&strm, level, Z_FILTERED);
		break;
	case 8:
		deflateParams(&strm, level, Z_FILTERED);
		break;
	case 9:
		deflateParams(&strm, level, Z_FILTERED);
		break;
	}

	zlibpercent = 0;

	totalbytes = lffilesize(input);
	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(input, wpmode, 300);
		rsp.attrib = GetFileAttributesW(wpmode);
	}
	else
		rsp.attrib = GetFileAttributes(input);

#ifdef NPRINTF
	dprintf("atributo %x \n", rsp.attrib);
#endif

	if ((int)0xFFFFFFFF == (int)rsp.attrib)
	{
		rsp.attrib = FILE_ATTRIBUTE_ARCHIVE;
	}
	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(input, wpmode, 300);
		source = _wfopen(wpmode, L"rb");
	}
	else
		source = fopen(input, "rb");

	if (NULL == source)
	{

		retvalue = 7;

		goto saida;
	}
	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(output, wpmode, 300);
		ret = SetFileAttributesW(wpmode, FILE_ATTRIBUTE_ARCHIVE);
	}
	else
		ret = SetFileAttributes(output, FILE_ATTRIBUTE_ARCHIVE);

	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(output, wpmode, 300);
		dest = _wfopen(wpmode, L"wb");
	}
	else
		dest = fopen(output, "wb");

	if (NULL == dest)
	{

		retvalue = 8;

		goto saida;
	}

	ret = fwrite(&rsp, 1, sizeof(rsp), dest);

	if (0 == ret)
	{
		retvalue = 14; //unexpected error
		goto saida;
	}

	for (;;)
	{

		while (pauseflag)
		{

			Sleep(50);

			if (cancelflag)
			{
				goto saida;
			}
		}

		if (cancelflag)
		{
			goto saida;
		}

		ret = fread(buffer, 1, CHUNK, source);

		if (0 == ret)
		{

			//  dprintf ("read =0 %I64d %I64d \n", bytesread, totalbytes);
			goto saida;
		}

		md5_update(&ctx, (void *)buffer, ret);

		bytesread = bytesread + ret;

		zlibpercent = lgetpor(totalbytes, bytesread);

		if (bytesread == totalbytes)
		{

			// dprintf ("last chunck %d \n", ret);
			last = 1;
		}

		strm.avail_in = ret;

		if (last)
		{
			flush = Z_FINISH;
		}
		else
		{

			flush = Z_NO_FLUSH; //Z_NO_FLUSH
		}

		strm.next_in = (void *)buffer;

	devolta:

		strm.avail_out = CHUNK;
		strm.next_out = (void *)out;

		ret2 = deflate(&strm, flush);	/* no bad return value */
		assert(ret2 != Z_STREAM_ERROR); /* state not clobbered */

		bytestosave = bytestosave + (CHUNK - strm.avail_out);

		writebytes = CHUNK - strm.avail_out;

		if (writebytes > 0)
		{

			if (0 == fwrite(out, 1, writebytes, dest))
			{

				retvalue = 14;

				goto saida;
			}
		}

		switch (ret2)
		{

		case Z_OK:

			if (last || strm.avail_in)
			{
				goto devolta;
			}

			if (0 == strm.avail_out)
			{
				goto devolta;
			}

			break;

		case Z_STREAM_END:

			done = 1;
			break;

		case Z_STREAM_ERROR:

			assert(0);
			break;

		case Z_BUF_ERROR:

			assert(0);
			break;

		default:

			assert(0);
			break;
		}
	}

saida:

	memset(md5sum, 0, 16);

	md5_finish(&ctx, md5sum);

	memcpy(&rsp.a, &md5sum[0], 4);
#ifdef NPRINTF
	dprintf("valor de a %x \n", rsp.a);
#endif
	memcpy(&rsp.b, &md5sum[4], 4);
#ifdef NPRINTF
	dprintf("valor de b %x \n", rsp.b);
#endif
	memcpy(&rsp.c, &md5sum[8], 4);
#ifdef NPRINTF
	dprintf("valor de c %x \n", rsp.c);
#endif
	memcpy(&rsp.d, &md5sum[12], 4);
#ifdef NPRINTF
	dprintf("valor de d %x \n", rsp.d);
#endif

	if (totalbytes && (0 == retvalue))
	{

		if (0 == done && (0 == cancelflag))
		{

			retvalue = 16;
		}
	}

	(void)deflateEnd(&strm);

	zlibpercent = 100;

	if (source)
	{
		fclose(source);
		source = 0;
	}

	if (dest)
	{
		fclose(dest);
		dest = 0;
	}

	//aqui agora atualiza o treco

	if (0 == retvalue)
	{
		if (unicodemode)
		{
			WCHAR wpmode[300] = {
				0,
			};
			utf8towide(output, wpmode, 300);
			dest = _wfopen(wpmode, L"rb+");
		}
		else
			dest = fopen(output, "rb+");

		if (0 == dest)
		{

			retvalue = 8;
		}
		else
		{
			ret = fwrite(&rsp, 1, sizeof(rsp), dest);

			if (ret != sizeof(rsp))
			{

				retvalue = 14;
			}
		}
	}

	if (dest)
	{

		fclose(dest);
		dest = 0;
	}

	if (cancelflag)
	{
		retvalue = 19;
	}
#ifdef NPRINTF
	dprintf("retvalue=%d sizeof(rsp) %d\n", retvalue, sizeof(rsp));
#endif
	finished = 1;
	return retvalue;
}

int zcompress_sha512_k(char *input, char *output, int levelin)
{
	FILE *dest = NULL;
	FILE *source = NULL;
	__int64 bytesread = 0;
	__int64 bytestosave = 0;
	__int64 totalbytes = 0;
	int done = 0;
	int flush;
	int last = 0;
	int level = Z_DEFAULT_COMPRESSION;
	int ret = 0;
	int ret2 = 0;
	int retvalue = 0;
	int writebytes = 0;
	ar_data ar;
	static char buffer[CHUNK + 1];
	static char out[CHUNK];
	z_stream strm;
	char *sha51_ptr = NULL;

	pauseflag = 0;
	cancelflag = 0;
	level = levelin;

	if (levelin <= 0)
	{

		level = 1;
	}

	if (levelin > 9)
	{

		level = 9;
	}

#ifdef NPRINTF
	dprintf("->compression level %d \n", level);
#endif

	sha51_ptr = sha512_init_k();

	memset(&ar, 0, sizeof(ar_data));

	memcpy(ar.string, "AR__", 4);

	memset(&strm, 0, sizeof(strm));

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;

#ifdef NPRINTF
	dprintf(" using level %d\n", level);
#endif

	ret = deflateInit(&strm, level);
	assert(ret == Z_OK);

	switch (level)
	{
	case 0:
		deflateParams(&strm, Z_NO_COMPRESSION, Z_DEFAULT_STRATEGY);
		break;
	case 1:
		deflateParams(&strm, Z_NO_COMPRESSION, Z_DEFAULT_STRATEGY);
		break;
	case 2:
		deflateParams(&strm, level, Z_HUFFMAN_ONLY);
		break;
	case 3:
		deflateParams(&strm, level, Z_HUFFMAN_ONLY);
		break;
	case 4:
		deflateParams(&strm, level, Z_HUFFMAN_ONLY);
		break;
	case 5:
		deflateParams(&strm, level, Z_HUFFMAN_ONLY);
		break;
	case 6:
		deflateParams(&strm, level, Z_FILTERED);
		break;
	case 7:
		deflateParams(&strm, level, Z_FILTERED);
		break;
	case 8:
		deflateParams(&strm, level, Z_FILTERED);
		break;
	case 9:
		deflateParams(&strm, level, Z_FILTERED);
		break;
	}

	zlibpercent = 0;

	totalbytes = lffilesize(input);
	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(input, wpmode, 300);
		ar.attrib = GetFileAttributesW(wpmode);
	}
	else
		ar.attrib = GetFileAttributes(input);

#ifdef NPRINTF
	dprintf("atributo %x \n", ar.attrib); //%x requer um int, tem que usar %p
#endif

	if ((int)0xFFFFFFFF == (int)ar.attrib)
	{
		ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
	}
	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(input, wpmode, 300);
		source = _wfopen(wpmode, L"rb");
	}
	else
		source = fopen(input, "rb");

	if (NULL == source)
	{

		retvalue = 7;

		goto saida;
	}
	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(output, wpmode, 300);
		ret = SetFileAttributesW(wpmode, FILE_ATTRIBUTE_ARCHIVE);
	}
	else
		ret = SetFileAttributes(output, FILE_ATTRIBUTE_ARCHIVE);

	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(output, wpmode, 300);
		dest = _wfopen(wpmode, L"wb");
	}
	else
		dest = fopen(output, "wb");

	if (NULL == dest)
	{

		retvalue = 8;

		goto saida;
	}

	ret = fwrite(&ar, 1, sizeof(ar), dest);

	if (0 == ret)
	{
		retvalue = 14; //unexpected error
		goto saida;
	}

	for (;;)
	{

		while (pauseflag)
		{

			Sleep(50);

			if (cancelflag)
			{
				goto saida;
			}
		}

		if (cancelflag)
		{
			goto saida;
		}

		ret = fread(buffer, 1, CHUNK, source);

		if (0 == ret)
		{

			//  dprintf ("read =0 %I64d %I64d \n", bytesread, totalbytes);
			goto saida;
		}

		//md5_update (&ctx, buffer, ret);

		sha512_update_k(sha51_ptr, (void *)buffer, ret);

		bytesread = bytesread + ret;

		zlibpercent = lgetpor(totalbytes, bytesread);

		if (bytesread == totalbytes)
		{

			// dprintf ("last chunck %d \n", ret);
			last = 1;
		}

		strm.avail_in = ret;

		if (last)
		{
			flush = Z_FINISH;
		}
		else
		{

			flush = Z_NO_FLUSH; //Z_NO_FLUSH
		}

		strm.next_in = (void *)buffer;

	devolta:

		strm.avail_out = CHUNK;
		strm.next_out = (void *)out;

		ret2 = deflate(&strm, flush);	/* no bad return value */
		assert(ret2 != Z_STREAM_ERROR); /* state not clobbered */

		bytestosave = bytestosave + (CHUNK - strm.avail_out);

		writebytes = CHUNK - strm.avail_out;

		if (writebytes > 0)
		{

			if (0 == fwrite(out, 1, writebytes, dest))
			{

				retvalue = 14;

				goto saida;
			}
		}

		switch (ret2)
		{

		case Z_OK:

			if (last || strm.avail_in)
			{
				goto devolta;
			}

			if (0 == strm.avail_out)
			{
				goto devolta;
			}

			break;

		case Z_STREAM_END:

			done = 1;
			break;

		case Z_STREAM_ERROR:

			assert(0);
			break;

		case Z_BUF_ERROR:

			assert(0);
			break;

		default:

			assert(0);
			break;
		}
	}

saida:

	//memset (md5sum, 0, 16);

	//md5_finish (&ctx, md5sum);

	sha512_final_k(sha51_ptr, ar.sha512_k);

	if (totalbytes && (0 == retvalue))
	{

		if (0 == done && (0 == cancelflag))
		{

			retvalue = 16;
		}
	}

	(void)deflateEnd(&strm);

	zlibpercent = 100;

	if (source)
	{
		fclose(source);
		source = 0;
	}

	if (dest)
	{
		fclose(dest);
		dest = 0;
	}

	//aqui agora atualiza o treco

	if (0 == retvalue)
	{
		if (unicodemode)
		{
			WCHAR wpmode[300] = {
				0,
			};
			utf8towide(output, wpmode, 300);
			dest = _wfopen(wpmode, L"rb+");
		}
		else
			dest = fopen(output, "rb+");

		if (0 == dest)
		{

			retvalue = 8;
		}
		else
		{
			ret = fwrite(&ar, 1, sizeof(ar), dest);

			if (ret != sizeof(ar))
			{

				retvalue = 14;
			}
		}
	}

	if (dest)
	{

		fclose(dest);
		dest = 0;
	}

	if (cancelflag)
	{
		retvalue = 19;
	}
#ifdef NPRINTF
	dprintf("retvalue=%d sizeof(rsp) %d\n", retvalue, sizeof(rsp));
#endif
	finished = 1;
	return retvalue;
}

/******************************************************************************************
******************************************************************************************
******************************************************************************************
******************************************************************************************
******************************************************************************************/

int zuncompress(char *input, char *output)
{

	FILE *dest = NULL;
	FILE *source = NULL;
	__int64 bytesread = 0;
	__int64 bytestosave = 0;
	__int64 totalbytes = 0;
	int a;
	int b;
	int c;
	int d;
	int done = 0;
	int ret = 0;
	int ret2 = 0;
	int retvalue = 0;
	int writebytes = 0;
	md5_context ctx;
	rspdata rsp;
	static char buffer[CHUNK + 1];
	static char out[CHUNK];
	unsigned char md5sum[16];
	z_stream strm;
	char is_ar_file_k = 0;

	memset(&strm, 0, sizeof(strm));

	pauseflag = 0;
	cancelflag = 0;

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;
	ret = inflateInit(&strm);
	assert(ret == Z_OK);

	md5_starts(&ctx);

	zlibpercent = 0;

	totalbytes = lffilesize(input);

	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(input, wpmode, 300);
		source = _wfopen(wpmode, L"rb");
	}
	else
		source = fopen(input, "rb");

	if (NULL == source)
	{

		retvalue = 10;

		goto saida;
	}

	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(output, wpmode, 300);
		ret = SetFileAttributesW(wpmode, FILE_ATTRIBUTE_ARCHIVE);
	}
	else
		ret = SetFileAttributes(output, FILE_ATTRIBUTE_ARCHIVE);

	dest = fopen(output, "wb");

	if (NULL == dest)
	{

		retvalue = 11;

		goto saida;
	}

	memset(&rsp, 0, sizeof(rsp));
	ret = fread(&rsp, 1, sizeof(rsp), source);

	if (ret != sizeof(rsp))
	{

		retvalue = 9;
		goto saida;
	}

	if (0 != memcmp(rsp.string, "RSPG", 4))
	{

		if (0 == memcmp(rsp.string, "AR__", 4))
		{

			is_ar_file_k = 1;
			goto saida;
		}

		retvalue = 9;
		goto saida;
	}

	for (;;)
	{
		while (pauseflag)
		{

			Sleep(50);

			if (cancelflag)
			{
				goto saida;
			}
		}

		if (cancelflag)
		{
			goto saida;
		}

		ret = fread(buffer, 1, CHUNK, source);

		if ((0 == ret) || done)
		{

			goto saida;
		}

		bytesread = bytesread + ret;

		zlibpercent = lgetpor(totalbytes, bytesread);

		strm.avail_in = ret;

		strm.next_in = (void *)buffer;

	devolta:

		strm.avail_out = CHUNK;
		strm.next_out = (void *)out;

		ret2 = inflate(&strm, Z_NO_FLUSH);

		bytestosave = bytestosave + (CHUNK - strm.avail_out);

		writebytes = CHUNK - strm.avail_out; //existe um erro aqui

		if (writebytes > 0)
		{

			md5_update(&ctx, (void *)out, writebytes);

			if (0 == fwrite(out, 1, writebytes, dest))
			{

				retvalue = 14;
				goto saida;
			}
		}

		switch (ret2)
		{

		case Z_OK:

			if (strm.avail_in)
			{
				goto devolta;
			}

			if (0 == strm.avail_out)
			{
				goto devolta;
			}

			break;

		case Z_STREAM_END:

			done = 1;
			break;

		case Z_NEED_DICT:

			assert(0);
			break;

		case Z_STREAM_ERROR:

			assert(0);
			break;

		case Z_MEM_ERROR:

			assert(0);
			break;

		case Z_DATA_ERROR:

			retvalue = 21;
			goto saida;

			break;

		case Z_BUF_ERROR:

			assert(0);
			break;

		default:

			assert(0);
			break;
		}
	}

saida:

	if ((0 == retvalue) && ((int64_t)totalbytes > (int64_t)sizeof(rsp)))
	{
		memset(md5sum, 0, 16);

		md5_finish(&ctx, md5sum);

		memcpy(&a, &md5sum[0], 4);

		memcpy(&b, &md5sum[4], 4);

		memcpy(&c, &md5sum[8], 4);

		memcpy(&d, &md5sum[12], 4);

		if ((a != rsp.a) || (b != rsp.b) || (c != rsp.c) || (d != rsp.d))
		{
#ifdef NPRINTF
			dprintf("error de md5 \n");
#endif
			retvalue = 15;
		}
	}

	if ((int64_t)totalbytes > (int64_t)sizeof(rsp))
	{
		if ((0 == done) && (0 == retvalue))
		{

			retvalue = 18;
		}
	}

	(void)inflateEnd(&strm);

	if (0 == is_ar_file_k)
		zlibpercent = 100;

	if (source)
	{
		fclose(source);
		source = 0;
	}

	if (dest)
	{
		fclose(dest);
		dest = 0;
	}

	if (cancelflag)
	{
		retvalue = 19;
	}

	if (0 == is_ar_file_k)
	{
		if (0 == retvalue)
		{
			if (unicodemode)
			{
				WCHAR wpmode[300] = {
					0,
				};
				utf8towide(output, wpmode, 300);
				ret = SetFileAttributesW(wpmode, rsp.attrib);
			}
			else
				ret = SetFileAttributes(output, rsp.attrib);
		}
	}
#ifdef NPRINTF
	dprintf("retvalue=%d \n", retvalue);
#endif

	if (0 == is_ar_file_k)
		finished = 1;

	if (is_ar_file_k)
		return zuncompress_sha512_k(input, output);

	return retvalue;
}
int zuncompress_sha512_k(char *input, char *output)
{

	FILE *dest = NULL;
	FILE *source = NULL;
	__int64 bytesread = 0;
	__int64 bytestosave = 0;
	__int64 totalbytes = 0;
	int done = 0;
	int ret = 0;
	int ret2 = 0;
	int retvalue = 0;
	int writebytes = 0;
	ar_data ar;
	static char buffer[CHUNK + 1];
	static char out[CHUNK];
	z_stream strm;

	memset(&strm, 0, sizeof(strm));

	pauseflag = 0;
	cancelflag = 0;

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;
	ret = inflateInit(&strm);
	assert(ret == Z_OK);

	char *sha51_ptr = NULL;
	char sha512_temp_k[SHA512_DIGEST_LENGTH];

	sha51_ptr = sha512_init_k();

	zlibpercent = 0;

	totalbytes = lffilesize(input);

	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(input, wpmode, 300);
		source = _wfopen(wpmode, L"rb");
	}
	else
		source = fopen(input, "rb");

	if (NULL == source)
	{

		retvalue = 10;

		goto saida;
	}

	if (unicodemode)
	{
		WCHAR wpmode[300] = {
			0,
		};
		utf8towide(output, wpmode, 300);
		ret = SetFileAttributesW(wpmode, FILE_ATTRIBUTE_ARCHIVE);
	}
	else
		ret = SetFileAttributes(output, FILE_ATTRIBUTE_ARCHIVE);

	dest = fopen(output, "wb");

	if (NULL == dest)
	{

		retvalue = 11;

		goto saida;
	}

	memset(&ar, 0, sizeof(ar));
	ret = fread(&ar, 1, sizeof(ar), source);

	if (ret != sizeof(ar))
	{

		retvalue = 9;
		goto saida;
	}

	if (0 != memcmp(ar.string, "AR__", 4))
	{

		retvalue = 9;
		goto saida;
	}

	for (;;)
	{
		while (pauseflag)
		{

			Sleep(50);

			if (cancelflag)
			{
				goto saida;
			}
		}

		if (cancelflag)
		{
			goto saida;
		}

		ret = fread(buffer, 1, CHUNK, source);

		if ((0 == ret) || done)
		{

			goto saida;
		}

		bytesread = bytesread + ret;

		zlibpercent = lgetpor(totalbytes, bytesread);

		strm.avail_in = ret;

		strm.next_in = (void *)buffer;

	devolta:

		strm.avail_out = CHUNK;
		strm.next_out = (void *)out;

		ret2 = inflate(&strm, Z_NO_FLUSH);

		bytestosave = bytestosave + (CHUNK - strm.avail_out);

		writebytes = CHUNK - strm.avail_out; //existe um erro aqui

		if (writebytes > 0)
		{

			//md5_update (&ctx, out, writebytes);
			sha512_update_k(sha51_ptr, (void *)out, writebytes);

			if (0 == fwrite(out, 1, writebytes, dest))
			{

				retvalue = 14;
				goto saida;
			}
		}

		switch (ret2)
		{

		case Z_OK:

			if (strm.avail_in)
			{
				goto devolta;
			}

			if (0 == strm.avail_out)
			{
				goto devolta;
			}

			break;

		case Z_STREAM_END:

			done = 1;
			break;

		case Z_NEED_DICT:

			assert(0);
			break;

		case Z_STREAM_ERROR:

			assert(0);
			break;

		case Z_MEM_ERROR:

			assert(0);
			break;

		case Z_DATA_ERROR:

			retvalue = 21;
			goto saida;

			break;

		case Z_BUF_ERROR:

			assert(0);
			break;

		default:

			assert(0);
			break;
		}
	}

saida:

	if ((0 == retvalue) && ((int64_t)totalbytes > (int64_t)sizeof(ar)))
	{

		sha512_final_k(sha51_ptr, (void *)sha512_temp_k);

		if (0 != memcmp(sha512_temp_k, ar.sha512_k, SHA512_DIGEST_LENGTH))
		{
#ifdef NPRINTF
			dprintf("error de md5 \n");
#endif

			pedro_dprintf(-1, "erro 20");
			retvalue = 20;
		}
	}

	if ((int64_t)totalbytes > (int64_t)sizeof(ar))
	{

		if ((0 == done) && (0 == retvalue))
		{

			retvalue = 18;
		}
	}

	(void)inflateEnd(&strm);

	zlibpercent = 100;

	if (source)
	{
		fclose(source);
		source = 0;
	}

	if (dest)
	{
		fclose(dest);
		dest = 0;
	}

	if (cancelflag)
	{
		retvalue = 19;
	}

	if (0 == retvalue)
	{
		if (unicodemode)
		{
			WCHAR wpmode[300] = {
				0,
			};
			utf8towide(output, wpmode, 300);
			ret = SetFileAttributesW(wpmode, ar.attrib);
		}
		else
			ret = SetFileAttributes(output, ar.attrib);
	}

#ifdef NPRINTF
	dprintf("retvalue=%d \n", retvalue);
#endif

	finished = 1;

	return retvalue;
}
