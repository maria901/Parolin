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

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

# define SHA512_DIGEST_LENGTH    64 /*for your pleasure*/

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


#include "bzlib.h"

#include "md5.h"

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

void * sha512_init_k(void);
void sha512_update_k(void * ctx, unsigned char * buffer_k, unsigned int len_k);
void sha512_final_k(void * ctx, unsigned char *array_digest_64_bytes);

int utf8towide (const char *pUTF8, WCHAR * pUSC2, int nUSC2);

int bzip3uncompress_sha512_k (char *input, char *output);

extern uint intpause;
extern uint intcancel;

int finished = 0;

extern int intstatus;

typedef struct _rspdata
{
	char string[4];
	int a;
	int b;
	int c;
	int d;
	int attrib;

	FILETIME creation;
	FILETIME lwrite;
} rspdata;

typedef struct _ar_data
{
	char string[4];
	unsigned char digest_k[SHA512_DIGEST_LENGTH];
	int attrib;
	FILETIME creation;
	FILETIME lwrite;
} ar_data;

void   mprintf (char *format, ...);

extern void __cdecl mprintf (char *format, ...);

uint   getpor (int max, uint fatia);

void   dprintf (char *format, ...);
int __stdcall execute ();
int    start ();
int    start2 ();

HANDLE lfopen (const char *szFileName, char *pMode);
void   lfclose (HANDLE hFile);
__int64 lfseek (HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell (HANDLE hFile);
__int64 lffilesize (const char *szFileName);
unsigned long lfread (void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite (void *pBuffer, unsigned long ulCount, HANDLE hFile);
int    setendofile (HANDLE file, __int64 position);

int    lgetpor (__int64 max, __int64 fatia);

#define CHUNK 32768

int bzip3percent = 0;

int lgetpor (__int64 max, __int64 fatia)
{
/*

   2/27/2004 12:13PM modificacao para evitar divisao por 0

 */
	double maxa;
	double fatiaa;
	maxa = (double) max;
	fatiaa = (double) fatia;
	if (max == 0 || fatia == 0)
	{
		return 0;
	}
	maxa = ((double) 100 / maxa * fatiaa);
	return (int) maxa;
}

int bzip3compress (char *input, char *output, int levelin)
{
	HANDLE dest = 0;
	HANDLE source = 0;
	__int64 bytesread = 0;
	__int64 bytestosave = 0;
	__int64 len = 0;
	__int64 totalbytes = 0;
	int done = 0;
	int flush;
	int last = 0;
	int level = 0;
	int ret = 0;
	int ret2 = 0;
	int retvalue = 0;
	int time = 0;
	int writebytes = 0;
	md5_context ctx;
	rspdata rsp;
	static char buffer[CHUNK + 1];
	static char in[CHUNK];
	static char out[CHUNK + 1];
	unsigned char md5sum[16];
	unsigned have;
	bz_stream strm = { 0, };
	int action = BZ_RUN;
	FILE *myfile=NULL;
#ifdef NPRINTF
	dprintf ("%s\n%s \n", input, output);

	dprintf ("Level %d \n", levelin);
#endif
	intstatus = 1;

	memset (&strm, 0, sizeof (strm));

	intpause = 0;
	intcancel = 0;
	level = levelin;

	if (levelin <= 0)
	{

		level = 1;
	}

	if (levelin > 9)
	{

		level = 9;
	}

	ret = BZ2_bzCompressInit (&strm, level, 4, 30);

	if (BZ_OK != ret)
	{
		retvalue = 120;
		goto saida;
	}
#ifdef NPRINTF
	dprintf ("ok \n");
	dprintf ("compression level %d \n", level);
#endif
	md5_starts (&ctx);

	memset (&rsp, 0, sizeof (rsp));

	memcpy (rsp.string, "RSPB", 4);

#ifdef NPRINTF

	dprintf (" using level %d\n", level);
#endif

	bzip3percent = 0;

	totalbytes = lffilesize (input);
	{
		WCHAR temp_w_k[300] = {0};

		utf8towide (input, temp_w_k, 300);
		rsp.attrib = GetFileAttributesW (temp_w_k);
	}
#ifdef NPRINTF
	dprintf ("atributo %x \n", rsp.attrib);
#endif
	if (0xFFFFFFFF == rsp.attrib)
	{

		rsp.attrib = FILE_ATTRIBUTE_ARCHIVE;
	}

	source = lfopen (input, "rb");

	if (0 == source)
	{

		retvalue = 107;
		goto saida;

	}

	ret = GetFileTime (source, // identifies the file
	                   &rsp.creation, // address of creation time
	                   NULL, // address of last access time
	                   &rsp.lwrite  // address of last write time
	                   );

	assert (ret);
	{
		WCHAR temp_w_k[300] = {0};

		utf8towide (output, temp_w_k, 300);
		ret = SetFileAttributesW (temp_w_k, FILE_ATTRIBUTE_ARCHIVE);
	}
	dest = lfopen (output, "wb");

	if (0 == dest)
	{

		retvalue = 108;
		goto saida;

	}

	ret = lfwrite (&rsp, sizeof (rsp), dest);

	if (0 == ret)
	{
		retvalue = 114;

		goto saida;
	}

	for (;;)
	{

		while (intpause)
		{
			Sleep (50);

			if (intcancel)
			{
				goto saida;
			}
		}

		if (intcancel)
		{
			goto saida;
		}

		ret = lfread (buffer, CHUNK, source);

		if (0 == ret)
		{
			goto saida;
		}

		md5_update (&ctx, buffer, ret);

		bytesread = bytesread + ret;

		bzip3percent = lgetpor (totalbytes, bytesread);

		if (bytesread == totalbytes)
		{
			last = 1;
			action = BZ_FINISH; //BZ_FLUSH;
		}

		strm.next_in = buffer;
		strm.avail_in = ret;

volta:

		strm.next_out = out;
		strm.avail_out = CHUNK;

		ret = BZ2_bzCompress (&strm, action);
#ifdef NPRINTF
		dprintf ("strm.avail_in %d\n", strm.avail_in);
		dprintf ("strm.avail_out %d \n", strm.avail_out);
#endif
		writebytes = CHUNK - strm.avail_out;

		if (writebytes > 0)
		{
			if (0 == lfwrite (out, writebytes, dest))
			{
				retvalue = 114;
				goto saida;
			}
		}

		switch (ret)
		{
		case BZ_RUN_OK:
#ifdef NPRINTF
			dprintf ("BZ_RUN_OK\n");
#endif
			if (action == BZ_FLUSH)
			{
#ifdef NPRINTF
				dprintf ("Voltando final \n");
#endif
				action = BZ_FINISH;
				goto volta;
			}

			if(0==strm.avail_out)
			{
				goto volta;
			}

			break;
		case BZ_FLUSH_OK:
#ifdef NPRINTF
			dprintf ("BZ_FLUSH_OK \n");
#endif
			goto volta;
			break;
		case BZ_FINISH_OK:
#ifdef NPRINTF
			dprintf ("BZ_FINISH_OK \n");
#endif
			goto volta;
			break;
		case BZ_STREAM_END:
#ifdef NPRINTF
			dprintf ("stream end \n");
#endif
			done = 1;
			goto saida;
			break;
		case BZ_SEQUENCE_ERROR:
#ifdef NPRINTF
			dprintf ("sequence error \n");
#endif
			assert (0);
			break;
		default:
			assert (0);
			break;
		}
	}

saida:

	memset (md5sum, 0, 16);

	md5_finish (&ctx, md5sum);

	memcpy (&rsp.a, &md5sum[0], 4);
#ifdef NPRINTF
	dprintf ("valor de a %x \n", rsp.a);
#endif
	memcpy (&rsp.b, &md5sum[4], 4);
#ifdef NPRINTF
	dprintf ("valor de b %x \n", rsp.b);
#endif
	memcpy (&rsp.c, &md5sum[8], 4);
#ifdef NPRINTF
	dprintf ("valor de c %x \n", rsp.c);
#endif
	memcpy (&rsp.d, &md5sum[12], 4);
#ifdef NPRINTF
	dprintf ("valor de d %x \n", rsp.d);
#endif

	if (totalbytes && (0 == retvalue))
	{
		if (0 == done && (0 == intcancel))
		{
			retvalue = 116;
		}
	}

	bzip3percent = 100;

	if (source)
	{
		lfclose (source);
		source = 0;
	}

	if (dest)
	{
		lfclose (dest);
		dest = 0;
	}

//aqui agora atualiza o treco

	if (0 == retvalue)
	{
		dest = lfopen (output, "rb+");

		if (0 == dest)
		{
			retvalue = 108;
		}
		else
		{
			ret = lfwrite (&rsp, sizeof (rsp), dest);

			if (ret != sizeof (rsp))
			{
				retvalue = 114;
			}
		}
	}

	if (dest)
	{
		lfclose (dest);
		dest = 0;
	}

	if (intcancel)
	{
		retvalue = 119;
		{
			WCHAR temp_w_k[300] = {0};

			utf8towide (output, temp_w_k, 300);
			_wunlink(temp_w_k);
		}

	}

	assert (BZ_OK == BZ2_bzCompressEnd (&strm));
#ifdef NPRINTF
	dprintf ("retvalue=%d sizeof(rsp) %d\n", retvalue, sizeof (rsp));
#endif
	finished = 1;
	intstatus = 0;
	return retvalue;
}

int bzip3compress_sha512_k (char *input, char *output, int levelin)
{
	HANDLE dest = 0;
	HANDLE source = 0;
	__int64 bytesread = 0;
	__int64 bytestosave = 0;
	__int64 len = 0;
	__int64 totalbytes = 0;
	int done = 0;
	int flush;
	int last = 0;
	int level = 0;
	int ret = 0;
	int ret2 = 0;
	int retvalue = 0;
	int time = 0;
	int writebytes = 0;
	ar_data ar;
	char *sha512_ptr = NULL;
	static char buffer[CHUNK + 1];
	static char in[CHUNK];
	static char out[CHUNK + 1];
	unsigned char md5sum[16];
	unsigned have;
	bz_stream strm = { 0, };
	int action = BZ_RUN;
	FILE *myfile=NULL;
#ifdef NPRINTF
	dprintf ("%s\n%s \n", input, output);
	dprintf ("Level %d \n", levelin);
#endif
	intstatus = 1;
	memset (&strm, 0, sizeof (strm));
	intpause = 0;
	intcancel = 0;
	level = levelin;
	if (levelin <= 0)
	{

		level = 1;
	}
	if (levelin > 9)
	{
		level = 9;
	}

	ret = BZ2_bzCompressInit (&strm, level, 4, 30);

	if (BZ_OK != ret)
	{
		retvalue = 120;
		goto saida;
	}
#ifdef NPRINTF
	dprintf ("ok \n");
	dprintf ("compression level %d \n", level);
#endif

	sha512_ptr = sha512_init_k();
	memset (&ar, 0, sizeof (ar));
	memcpy (ar.string, "AR_2", 4);
#ifdef NPRINTF
	dprintf (" using level %d\n", level);
#endif

	bzip3percent = 0;
	totalbytes = lffilesize (input);
	{
		WCHAR temp_w_k[300] = {0};

		utf8towide (input, temp_w_k, 300);

		ar.attrib = GetFileAttributesW (temp_w_k);//utf-8 ?
	}
#ifdef NPRINTF
	dprintf ("atributo %x \n", ar.attrib);
#endif
	if (0xFFFFFFFF == ar.attrib)
	{
		ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
	}
	source = lfopen (input, "rb");
	if (0 == source)
	{

		retvalue = 107;
		goto saida;

	}

	ret = GetFileTime (source, // identifies the file
	                   &ar.creation, // address of creation time
	                   NULL, // address of last access time
	                   &ar.lwrite   // address of last write time
	                   );

	assert (ret);
	{
		WCHAR temp_w_k[300] = {0};
		utf8towide (output, temp_w_k, 300);
		ret = SetFileAttributesW (temp_w_k, FILE_ATTRIBUTE_ARCHIVE);
	}
	dest = lfopen (output, "wb");

	if (0 == dest)
	{
		retvalue = 108;
		goto saida;
	}

	ret = lfwrite (&ar, sizeof (ar), dest);

	if (0 == ret)
	{
		retvalue = 114; //unexpected error
		goto saida;
	}

	for (;;)
	{

		while (intpause)
		{

			Sleep (50);

			if (intcancel)
			{
				goto saida;
			}

		}

		if (intcancel)
		{
			goto saida;
		}

		ret = lfread (buffer, CHUNK, source);

		if (0 == ret)
		{
			goto saida;
		}

		sha512_update_k(sha512_ptr, buffer, ret);

		bytesread = bytesread + ret;

		bzip3percent = lgetpor (totalbytes, bytesread);

		if (bytesread == totalbytes)
		{
			last = 1;
			action = BZ_FINISH; //BZ_FLUSH;
		}

		strm.next_in = buffer;
		strm.avail_in = ret;

volta:

		strm.next_out = out;
		strm.avail_out = CHUNK;
		ret = BZ2_bzCompress (&strm, action);
#ifdef NPRINTF
		dprintf ("strm.avail_in %d\n", strm.avail_in);
		dprintf ("strm.avail_out %d \n", strm.avail_out);
#endif
		writebytes = CHUNK - strm.avail_out;
		if (writebytes > 0)
		{
			if (0 == lfwrite (out, writebytes, dest))
			{
				retvalue = 114;
				goto saida;
			}
		}

		switch (ret)
		{
		case BZ_RUN_OK:
#ifdef NPRINTF
			dprintf ("BZ_RUN_OK\n");
#endif
			if (action == BZ_FLUSH)
			{
#ifdef NPRINTF
				dprintf ("Voltando final \n");
#endif
				action = BZ_FINISH;
				goto volta;
			}
			if(0==strm.avail_out)
			{
				goto volta;
			}

			break;
		case BZ_FLUSH_OK:
#ifdef NPRINTF
			dprintf ("BZ_FLUSH_OK \n");
#endif
			goto volta;
			break;
		case BZ_FINISH_OK:
#ifdef NPRINTF
			dprintf ("BZ_FINISH_OK \n");
#endif
			goto volta;
			break;
		case BZ_STREAM_END:
#ifdef NPRINTF
			dprintf ("stream end \n");
#endif
			done = 1;
			goto saida;
			break;
		case BZ_SEQUENCE_ERROR:
#ifdef NPRINTF
			dprintf ("sequence error \n");
#endif
			assert (0);
			break;
		default:
			assert (0);
			break;
		}
	}

saida:

	sha512_final_k(sha512_ptr, ar.digest_k);

	if (totalbytes && (0 == retvalue))
	{
		if (0 == done && (0 == intcancel))
		{
			retvalue = 116;
		}
	}

	bzip3percent = 100;

	if (source)
	{
		lfclose (source);
		source = 0;
	}

	if (dest)
	{
		lfclose (dest);
		dest = 0;
	}

	if (0 == retvalue)
	{
		dest = lfopen (output, "rb+");

		if (0 == dest)
		{
			retvalue = 108;
		}
		else
		{
			ret = lfwrite (&ar, sizeof (ar), dest);
			if (ret != sizeof (ar))
			{
				retvalue = 114;
			}
		}
	}

	if (dest)
	{
		lfclose (dest);
		dest = 0;
	}

	if (intcancel)
	{
		retvalue = 119;
		{
			WCHAR temp_w_k[300] = {0};

			utf8towide (output, temp_w_k, 300);
			_wunlink(temp_w_k);
		}
	}

	assert (BZ_OK == BZ2_bzCompressEnd (&strm));
#ifdef NPRINTF
	dprintf ("retvalue=%d sizeof(rsp) %d\n", retvalue, sizeof (ar));
#endif
	finished = 1;
	intstatus = 0;
	return retvalue;
}

int bzip3uncompress (char *input, char *output)
{
	HANDLE dest = 0;
	HANDLE source = 0;
	__int64 bytesread = 0;
	__int64 bytestosave = 0;
	__int64 len = 0;
	__int64 totalbytes = 0;
	int a;
	int b;
	int c;
	int d;
	int done = 0;
	int flush;
	int last = 0;
	int level = 0;
	int ret = 0;
	int ret2 = 0;
	int retvalue = 0;
	int time = 0;
	int writebytes = 0;
	md5_context ctx;
	rspdata rsp;
	int is_sha512_file_k = 0;
	static char buffer[CHUNK + 1];
	static char in[CHUNK];
	static char out[CHUNK + 1];
	unsigned char md5sum[16];
	unsigned have;
	bz_stream strm = { 0, };
	intstatus = 1;
	memset (&strm, 0, sizeof (strm));
	ret = BZ2_bzDecompressInit (&strm, 0, 0);
	if (BZ_OK != ret)
	{
		retvalue = 121;
		goto saida;
	}
	intpause = 0;
	intcancel = 0;
	md5_starts (&ctx);
	bzip3percent = 0;
	totalbytes = lffilesize (input);
	source = lfopen (input, "rb");
	if (0 == source)
	{
		retvalue = 107;
		goto saida;
	}
	{
		WCHAR temp_w_k[300] = {0};
		utf8towide (output, temp_w_k, 300);
		ret = SetFileAttributesW (temp_w_k, FILE_ATTRIBUTE_ARCHIVE);
	}

	memset (&rsp, 0, sizeof (rsp));
	ret = lfread (&rsp, sizeof (rsp), source);

	if (ret != sizeof (rsp))
	{
		retvalue = 122;
		goto saida;
	}

	if (0 != memcmp (rsp.string, "RSPB", 4))
	{

		pedro_dprintf(-1, "arquivo nao é RSPB");
		if (0 == memcmp (rsp.string, "AR_2", 4))
		{
			is_sha512_file_k = 1;
			goto saida;
		}

		retvalue = 122;
		goto saida;

	}

	dest = lfopen (output, "wb");

	if (0 == dest)
	{
		retvalue = 108;
		goto saida;
	}
	for (;;)
	{
		while (intpause)
		{

			Sleep (50);

			if (intcancel)
			{
				goto saida;
			}

		}

		if (intcancel)
		{
			goto saida;
		}

		ret = lfread (buffer, CHUNK, source);

		if ((0 == ret) || done)
		{
			goto saida;
		}

		bytesread = bytesread + ret;

		bzip3percent = lgetpor (totalbytes, bytesread);

		strm.next_in = buffer;
		strm.avail_in = ret;

volta:

		strm.next_out = out;
		strm.avail_out = CHUNK;
		ret = BZ2_bzDecompress (&strm);
		writebytes = CHUNK - strm.avail_out;

		if (writebytes > 0)
		{
			md5_update (&ctx, out, writebytes);
			if (0 == lfwrite (out, writebytes, dest))
			{
				retvalue = 14;
				goto saida;
			}
		}

		switch (ret)
		{
		case BZ_OK:

			if(0==strm.avail_out)
			{
				goto volta;
			}

			break;

		case BZ_DATA_ERROR:

			retvalue = 126;
			goto saida;
			break;

		case BZ_MEM_ERROR:

#ifdef NPRINTF
			dprintf ("BZ_MEM_ERROR \n");
#endif
			retvalue = 125;
			goto saida;
			break;

		case BZ_DATA_ERROR_MAGIC:

			retvalue = 122;
			goto saida;
			break;

		case BZ_STREAM_END:

			done = 1;
			break;
		default:
			assert (0);
			break;
		}
	}

saida:
	;

	if( 0 == is_sha512_file_k)
	{
		if ((0 == retvalue) && (totalbytes > sizeof (rsp)))
		{
			memset (md5sum, 0, 16);

			md5_finish (&ctx, md5sum);

			memcpy (&a, &md5sum[0], 4);

			memcpy (&b, &md5sum[4], 4);

			memcpy (&c, &md5sum[8], 4);

			memcpy (&d, &md5sum[12], 4);

			if ((a != rsp.a) || (b != rsp.b) || (c != rsp.c) || (d != rsp.d))
			{
#ifdef NPRINTF
				dprintf ("error de md5 \n");
#endif
				retvalue = 123;
			}
		}

		if (totalbytes > sizeof (rsp))
		{

#ifdef NPRINTF
			dprintf ("garanta que done é setafdo \n");
#endif
			if ((0 == done) && (0 == retvalue))
			{
				retvalue = 124;
			}
		}
	}
	bzip3percent = 100;

	if (source)
	{
		lfclose (source);
		source = 0;
	}

	if (dest)
	{
		if (0 == retvalue)
		{
			ret = SetFileTime (dest, // identifies the file
			                   &rsp.creation, // time the file was created
			                   NULL, // time the file was last accessed
			                   &rsp.lwrite  // time the file was last written
			                   );
		}

		lfclose (dest);
		dest = 0;

	}

	if (intcancel)
	{
		retvalue = 119;
	}

	if (0 == retvalue)
	{

		{
			WCHAR temp_w_k[300] = {0};

			utf8towide (output, temp_w_k, 300);
			ret = SetFileAttributesW(temp_w_k, rsp.attrib);
		}

	}

#ifdef NPRINTF
	dprintf ("retvalue=%d \n", retvalue);
#endif
	if(0 == is_sha512_file_k)
		finished = 1;

	intstatus = 0;

	assert (BZ_OK == BZ2_bzDecompressEnd (&strm));

	if(is_sha512_file_k)
		return bzip3uncompress_sha512_k (input, output);

	return retvalue;
}

int bzip3uncompress_sha512_k (char *input, char *output)
{

	HANDLE dest = 0;
	HANDLE source = 0;
	__int64 bytesread = 0;
	__int64 bytestosave = 0;
	__int64 len = 0;
	__int64 totalbytes = 0;
	int a;
	int b;
	int c;
	int d;
	int done = 0;
	int flush;
	int last = 0;
	int level = 0;
	int ret = 0;
	int ret2 = 0;
	int retvalue = 0;
	int time = 0;
	int writebytes = 0;
	char * sha512_ptr = NULL;
	ar_data ar = {0};
	static char buffer[CHUNK + 1];
	static char in[CHUNK];
	static char out[CHUNK + 1];
	unsigned char md5sum[16];
	unsigned have;
	bz_stream strm = { 0, };
	intstatus = 1;
	memset (&strm, 0, sizeof (strm));
	ret = BZ2_bzDecompressInit (&strm, 0, 0);
	if (BZ_OK != ret)
	{
		retvalue = 121;
		goto saida;
	}
	intpause = 0;
	intcancel = 0;
	sha512_ptr = sha512_init_k();
	bzip3percent = 0;
	totalbytes = lffilesize (input);
	source = lfopen (input, "rb");

	if (0 == source)
	{
		retvalue = 107;
		goto saida;
	}

	{
		WCHAR temp_w_k[300] = {0};

		utf8towide (output, temp_w_k, 300);
		ret = SetFileAttributesW (temp_w_k, FILE_ATTRIBUTE_ARCHIVE);
	}

	memset (&ar, 0, sizeof (ar));
	ret = lfread (&ar, sizeof (ar), source);

	if (ret != sizeof (ar))
	{
		retvalue = 122;
		goto saida;
	}

	if (0 != memcmp (ar.string, "AR_2", 4))
	{
		retvalue = 122;
		goto saida;
	}
	dest = lfopen (output, "wb");
	if (0 == dest)
	{
		retvalue = 108;
		goto saida;
	}
	for (;;)
	{
		while (intpause)
		{

			Sleep (50);

			if (intcancel)
			{
				goto saida;
			}

		}

		if (intcancel)
		{
			goto saida;
		}

		ret = lfread (buffer, CHUNK, source);

		if ((0 == ret) || done)
		{
			goto saida;
		}

		bytesread = bytesread + ret;
		bzip3percent = lgetpor (totalbytes, bytesread);
		strm.next_in = buffer;
		strm.avail_in = ret;

volta:

		strm.next_out = out;
		strm.avail_out = CHUNK;
		ret = BZ2_bzDecompress (&strm);
		writebytes = CHUNK - strm.avail_out;
		if (writebytes > 0)
		{
			sha512_update_k(sha512_ptr, out, writebytes);
			if (0 == lfwrite (out, writebytes, dest))
			{
				retvalue = 14;
				goto saida;
			}
		}
		switch (ret)
		{
		case BZ_OK:

			if(0==strm.avail_out)
			{
				goto volta;
			}

			break;

		case BZ_DATA_ERROR:

			retvalue = 126;
			goto saida;
			break;

		case BZ_MEM_ERROR:
#ifdef NPRINTF
			dprintf ("BZ_MEM_ERROR \n");
#endif
			retvalue = 125;
			goto saida;
			break;

		case BZ_DATA_ERROR_MAGIC:
			retvalue = 122;
			goto saida;
			break;

		case BZ_STREAM_END:

			done = 1;
			break;
		default:
			assert (0);
			break;
		}
	}

saida:

	if ((0 == retvalue) && (totalbytes > sizeof (ar)))
	{

		unsigned char out_temp_digest[SHA512_DIGEST_LENGTH];

		sha512_final_k(sha512_ptr, out_temp_digest);

		if (0 != memcmp(out_temp_digest,ar.digest_k,SHA512_DIGEST_LENGTH))
		{
#ifdef NPRINTF
			dprintf ("error de sha512 \n");
#endif
			retvalue = 300;
		}

	}

	if (totalbytes > sizeof (ar))
	{

#ifdef NPRINTF
		dprintf ("garanta que done é setafdo \n");
#endif
		if ((0 == done) && (0 == retvalue))
		{
			retvalue = 124;
		}

	}

	bzip3percent = 100;

	if (source)
	{
		lfclose (source);
		source = 0;
	}

	if (dest)
	{
		if (0 == retvalue)
		{
			ret = SetFileTime (dest, // identifies the file
			                   &ar.creation, // time the file was created
			                   NULL, // time the file was last accessed
			                   &ar.lwrite   // time the file was last written
			                   );
		}
		lfclose (dest);
		dest = 0;
	}

	if (intcancel)
	{
		retvalue = 119;
	}

	if (0 == retvalue)
	{
		{
			WCHAR temp_w_k[300] = {0};
			utf8towide (output, temp_w_k, 300);
			ret = SetFileAttributesW (temp_w_k, ar.attrib);
		}
	}

#ifdef NPRINTF
	dprintf ("retvalue=%d \n", retvalue);
#endif
	finished = 1;
	intstatus = 0;
	assert (BZ_OK == BZ2_bzDecompressEnd (&strm));
	return retvalue;
}