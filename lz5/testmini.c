/* testmini.c -- very simple test program for the miniLZO library

   This file is part of the LZO real-time data compression library.

   Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer
   All Rights Reserved.

   The LZO library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   The LZO library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the LZO library; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

   Markus F.X.J. Oberhumer
   <markus@oberhumer.com>
   http://www.oberhumer.com/opensource/lzo/
 */

#include <windows.h>
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

/*************************************************************************
   // This program shows the basic usage of the LZO library.
   // We will compress a block of data and decompress again.
   //
   // For more information, documentation, example programs and other support
   // files (like Makefiles and build scripts) please download the full LZO
   // package from
   //    http://www.oberhumer.com/opensource/lzo/
 **************************************************************************/

/* First let's include "minizo.h". */

#include "minilzo.h"


/* We want to compress the data block at 'in' with length 'IN_LEN' to
 * the block at 'out'. Because the input block may be incompressible,
 * we must provide a little more output space in case that compression
 * is not possible.
 */

#define IN_LEN      (128*1024ul)
#define OUT_LEN     (IN_LEN + IN_LEN / 16 + 64 + 3)

static unsigned char __LZO_MMODEL in  [ IN_LEN ];
static unsigned char __LZO_MMODEL out [ OUT_LEN ];

int calc_out_size(int input)
{
	return (input + input / 16 + 64 + 3);
}
/* Work-memory needed for compression. Allocate memory in units
 * of 'lzo_align_t' (instead of 'char') to make sure it is properly aligned.
 */

#define HEAP_ALLOC(var,size) \
	lzo_align_t __LZO_MMODEL var [ ((size) + (sizeof(lzo_align_t) - 1)) / sizeof(lzo_align_t) ]

static HEAP_ALLOC(wrkmem, LZO1X_1_MEM_COMPRESS);

static int size_of_wrkmen=((((unsigned long int) (16384L * ((unsigned)sizeof(unsigned char *))))) + (sizeof(lzo_align_t) - 1)) / sizeof(lzo_align_t);


/*************************************************************************
   //
 **************************************************************************/

int main2(int argc, char *argv[])
{
	int r;
	lzo_uint in_len;
	lzo_uint out_len;
	lzo_uint new_len;

	if (argc < 0 && argv == NULL) /* avoid warning about unused args */
		return 0;

	printf("\nLZO real-time data compression library (v%s, %s).\n",
	       lzo_version_string(), lzo_version_date());
	printf("Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer\nAll Rights Reserved.\n\n");


/*
 * Step 1: initialize the LZO library
 */
	if (lzo_init() != LZO_E_OK)
	{
		printf("internal error - lzo_init() failed !!!\n");
		printf("(this usually indicates a compiler bug - try recompiling\nwithout optimizations, and enable '-DLZO_DEBUG' for diagnostics)\n");
		return 3;
	}

/*
 * Step 2: prepare the input block that will get compressed.
 *         We just fill it with zeros in this example program,
 *         but you would use your real-world data here.
 */
	in_len = IN_LEN;
	lzo_memset(in,0,in_len);

/*
 * Step 3: compress from 'in' to 'out' with LZO1X-1
 */
	r = lzo1x_1_compress(in,in_len,out,&out_len,wrkmem);//wrkmen 8192
	if (r == LZO_E_OK)
		printf("compressed %lu bytes into %lu bytes\n",
		       (unsigned long) in_len, (unsigned long) out_len);
	else
	{
		/* this should NEVER happen */
		printf("internal error - compression failed: %d\n", r);
		return 2;
	}
	/* check for an incompressible block */
	if (out_len >= in_len)
	{
		printf("This block contains incompressible data.\n");
		return 0;
	}

/*
 * Step 4: decompress again, now going from 'out' to 'in'
 */
	new_len = in_len;
	r = lzo1x_decompress(out,out_len,in,&new_len,NULL);
	if (r == LZO_E_OK && new_len == in_len)
		printf("decompressed %lu bytes back into %lu bytes\n",
		       (unsigned long) out_len, (unsigned long) in_len);
	else
	{
		/* this should NEVER happen */
		printf("internal error - decompression failed: %d\n", r);
		return 1;
	}

	printf("\nminiLZO simple compression test passed.\n");


	printf("size of wrkmen %d\n",size_of_wrkmen);
	return 0;
}
int lzo_decompress(char *buffer, int len, char*outbuf, lzo_uint*outlen, bz_stream * strm)
{

	int r;
	
	if(NULL == strm)
	{
		if (lzo_init() != LZO_E_OK)
		{
			printf("internal error - lzo_init() failed !!!\n");
			printf("(this usually indicates a compiler bug - try recompiling\nwithout optimizations, and enable '-DLZO_DEBUG' for diagnostics)\n");
			return 3;
		}
	}
	
	r = lzo1x_decompress(buffer, len, outbuf, outlen, NULL);
	if (r == LZO_E_OK)
		printf("decompressed %lu bytes back into %lu bytes\n",
		       (unsigned long) len, (unsigned long) *outlen);
	else
	{
		/* this should NEVER happen */
		printf("internal error - decompression failed: %d\n", r);
		return 1;
	}
	return 0;
}
int lzo_compress(char*bufin, int bufinlen, char*outbuf, lzo_uint *outbuflen, bz_stream * strm)
{
	int r;
	lzo_uint in_len;
	lzo_uint out_len;
	lzo_uint new_len;

	if(NULL == strm)
	{
		if (lzo_init() != LZO_E_OK)
		{
			printf("internal error - lzo_init() failed !!!\n");
			printf("(this usually indicates a compiler bug - try recompiling\nwithout optimizations, and enable '-DLZO_DEBUG' for diagnostics)\n");
			return 3;
		}
	}
	if(NULL == strm)
	{
		r = lzo1x_1_compress(bufin, bufinlen, outbuf, outbuflen, wrkmem);//wrkmen 8192
	}
	else
	{
		r = lzo1x_1_compress(bufin, bufinlen, outbuf, outbuflen, strm->memory_z);//wrkmen 8192
	}

	if (r == LZO_E_OK)
		printf("compressed %lu bytes into %lu bytes\n",
		       (unsigned long) bufinlen, (unsigned long) *outbuflen);
	else
	{
		/* this should NEVER happen */
		printf("internal error - compression failed: %d\n", r);
		return 2;
	}
	return 0;
}
#if 1

int main(int argc,char**argv)
{
	FILE *outfile=NULL;
	char thefile[300]={0};
	int ret;
	int len=0;
	int tam;
	char *thebuffer=NULL;
	char *bufout=NULL;
	lzo_uint saiu=0;
	char *bufunc=NULL;

	FILE *myfile=NULL;
	lzo_uint result;
	assert(2==argc);
	printf("argc %d\n",argc);

	myfile=fopen(argv[1],"rb");

	assert(myfile);

	fseek(myfile,0,SEEK_END);

	printf("tamanho %d\n",tam=ftell(myfile));
	//int fseek(FILE *stream, long offset, int mode);

	tam=ftell(myfile);
	thebuffer=malloc(tam+1);
	assert(thebuffer);
	fseek(myfile,0,SEEK_SET);
	len=fread(thebuffer,1,tam,myfile);
	printf("valor de len %d %d\n",len,tam);

	bufout=malloc(calc_out_size(tam));
	printf("valor alocado de saida %d\n",calc_out_size(tam));
	//aqui
	ret= lzo_compress(thebuffer,tam, bufout,&result);
	if(ret!=LZO_E_OK)
	{
		printf("deu erro na compressao\n");
		goto saida;
	}
	printf("saiu estes bytes %d\n",(int)result);


	{

		strcpy(thefile,argv[1]);

	#ifdef _WIN64
		strcat(thefile,".w64");
	#else
		strcat(thefile,".w32");
	#endif
		printf("out file %s\n",thefile);

		outfile=fopen(thefile,"wb");
		assert(outfile);

		fwrite(bufout,1,result,outfile);

		fclose(outfile);
	}

	bufunc=malloc(tam);
	//descompressao
	assert(bufunc);
	ret= lzo_decompress(bufout,result,bufunc,&saiu);
	if(0!=ret)
	{
		printf("deu erro na descompressao 1 - %d\n",ret);
		goto saida;
	}
	printf("saiu %d\n",saiu);

	if(saiu!=tam)
	{
		printf("deu erro na descompressao 2, tamanho de saida nao bate com o original\n");
	}

	ret=memcmp(bufunc,thebuffer,tam);

	if(ret!=0)
	{
		printf("conteudo original e descomprimido nao eh igual\n");
	}
	else
	{
		printf("ok, conteudo original e descomprimido eh igual\n");
	}
saida:
	;
	fclose(myfile);

	if(thebuffer)
	{
		free(thebuffer);
	}
	if(bufout)
	{
		free(bufout);
	}
	if(bufunc)
	{
		free(bufunc);
	}
	return 0;
}

#endif
