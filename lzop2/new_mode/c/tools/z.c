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

#ifndef __amandacall
#define __amandacall __stdcall
#endif

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

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

#include "stdio_v2.h"
#include "stdio_v3.h"

typedef struct LZOP2_struct__
{
	char signature_z[4];
	int64_t compressed_size_z;
	int64_t uncompressed_size_z;
}LZOP2_data;

#define INTERNAL_SIZE____Z (32768 * 2 * 2)

int calc_out_size(int input)
{
	return (input + input / 16 + 64 + 3);
}

int lzo_decompress(char *buffer, int len, char*outbuf, lzo_uint * outlen, __attribute__((unused)) my_thread_struct_z * amanda)
{

	int r;

	r = lzo1x_decompress((unsigned char *) buffer, len, (unsigned char *) outbuf, outlen, NULL);

	if (r == LZO_E_OK)
		; //printf("decompressed %lu bytes back into %lu bytes\n",
	// (unsigned long) len, (unsigned long) *outlen);
	else
	{
		/* this should NEVER happen */
		//printf("internal error - decompression failed: %d\n", r);
		return 1;
	}
	return 0;
}
/**
 * Main modified lzo compression library without level support, only one level for the moment, 
 * but with full multithread support (26/sep/2021, 01:40)
 * 
 */
int lzo_compress(char*bufin, int bufinlen, char*outbuf, lzo_uint *outbuflen, my_thread_struct_z * amanda)
{
	int r;

	if(0 == bufinlen)
	{
		pedro_dprintf(-1, "tentando comprimir 0 bytes\n");
		*outbuflen = 0;
		return 0;
	}

	r = lzo1x_1_compress( (unsigned char *) bufin, bufinlen, (unsigned char *) outbuf, outbuflen, amanda->memory_z);

	//compressed_z += *outbuflen + sizeof(LZOP2_data        );

	if (r == LZO_E_OK)
		; //printf("compressed %lu bytes into %lu bytes\n",
	          //   (unsigned long) bufinlen, (unsigned long) *outbuflen);
	else
	{
		/* this should NEVER happen */
		//printf("internal error - compression failed: %d\n", r);
		return 2;
	}
	return 0;
}
#ifdef MAIN_Z
//#define CHUNK_Z      (50000)
/*
   char buffer_z[CHUNK_Z];
   char buffer_out_z[CHUNK_Z];
 */
int main(int argc,char**argv)
{
	int size_= 100000;

	int CHUNK_Z = size_;
	char buffer_z[size_];
	char buffer_out_z[size_];

	FILE * myfile    =     NULL;
	FILE *outtile    =     NULL;

	char wfile[1024];
	myfile=fopen(argv[1],
	             "rb");

	strcpy(wfile, argv[1]);
	strcat(wfile, ".lzo2");

	outtile=fopen(wfile,
	              "wb");

	{

		//compressed_z = 0;
		int bytes_compressed = 0;
		int done      =        0;
		int action    =   LZOP_RUN;
		int bytesread = 0;
		int tamanho;

		int ret_arp;
		int writebytes;
		LZOP_stream strm  =     {0,};

		assert(myfile);

		fseek(myfile, 0, SEEK_END);

		tamanho = ftell(myfile);

		fseek(myfile, 0, SEEK_SET);

		{
			ret_arp = LZOP2_bzCompressInit (&strm, 6, 4, 30);

			if(LZOP_OK == ret_arp)
			{
				pedro_dprintf(-1, "ok %d\n", ret_arp);
			}

		}
		for (;;)
		{

			ret_arp = fread (buffer_z, 1, CHUNK_Z, myfile);

			if (0 == ret_arp)
			{
				goto saida_b;
			}

			bytesread += ret_arp;

			if(bytesread == tamanho)
			{
				pedro_dprintf(-1, "setando action para LZOP_FINISH\n");
				action = LZOP_FINISH;
			}
			pedro_dprintf(-1, "leu bytes %d\n", ret_arp);
			strm.next_in = buffer_z;
			strm.avail_in = ret_arp;

volta_amanda:           ;

			strm.next_out = buffer_out_z;
			strm.avail_out = CHUNK_Z;
			pedro_dprintf(-1, "chamando LZOP2_bzCompress\n");
			ret_arp = LZOP2_bzCompress (&strm, action);

			writebytes = CHUNK_Z - strm.avail_out;

			if (writebytes > 0)
			{
				bytes_compressed +=                  writebytes;
				pedro_dprintf(-1, "saiu bytes %d\n", writebytes);

				if (0 == fwrite (buffer_out_z, 1, writebytes, outtile))
				{
					goto saida_b;
				}

			}
			switch (ret_arp)
			{
			case LZOP_RUN_OK:
				pedro_dprintf(-1, "LZOP_RUN_OK\n");
				if (action == LZOP_FLUSH)//never run this
				{
					action = LZOP_FINISH;
					goto volta_amanda;
				}

				if(0==strm.avail_out)
				{
					pedro_dprintf(-1, "LZOP_RUN_OK 0==strm.avail_out\n");
					goto volta_amanda;
				}

				if(false == strm.processed_input_z)
				{
					pedro_dprintf(-1, "LZOP_RUN_OK input not processed\n");
					goto volta_amanda;
				}

				break;
			case LZOP_FLUSH_OK:
				goto volta_amanda;
				break;
			case LZOP_FINISH_OK:

				pedro_dprintf(-1, "looping in the LZOP_FINISH_OK\n");
				goto volta_amanda;
				break;
			case LZOP_STREAM_END:
				pedro_dprintf(-1, "LZOP_STREAM_END\n");
				done = 1;
				goto saida_b;
				break;
			case LZOP_SEQUENCE_ERROR:
				assert (0);
				//exit(27);
				break;
			default:
				assert (0);
				break;
			}
		}

saida_b:        ;
		/*
		                pedro_dprintf(-1, "compressed %d %d\n", bytes_compressed,
		                                          compressed_z);
		 */

		fclose(myfile );
		fclose(outtile);

		LZOP2_bzCompressEnd (&strm);

		if(!done)
		{
			printf("Error\n");
			exit(27);
		}

	}
	{
		int ret_arp_v2;
		int retvalue      = 0;
		int writebytes    = 0;

		int tamanho;
		int done          = 0;
		int ret_arp;
		LZOP_stream strm              = { 0, };

		myfile=fopen(wfile,
		             "rb");

		assert(myfile);

		strcat(wfile, ".out");
		outtile=fopen(wfile,
		              "wb");

		assert(outtile);

		tamanho = ftell(myfile);
/*
        strcpy(wfile, argv[1]);
        strcat(wfile, ".lzo2");

        outtile=fopen(wfile,
                     "wb");
 */

		if(LZOP_OK != /*for your pleasure */ LZOP2_bzDecompressInit(&strm, 0, 0))
		{
			printf("Erro\n");
			exit(27);
		}

		pedro_dprintf(-1, "***********************************************************\n");
		pedro_dprintf(-1, "***********************************************************\n");
		CHUNK_Z = 9999;
		for (;;)
		{

			ret_arp = fread (buffer_z, 1, CHUNK_Z, myfile);

			if(0 > ret_arp)
			{
				goto saida;
			}

			if ((0 == ret_arp) || done)
			{
				goto saida;
			}
			pedro_dprintf(-1, "leu %d bytes\n", ret_arp);

			strm.next_in  = buffer_z;
			strm.avail_in = ret_arp;
volta_z:                ;

			strm.next_out = buffer_out_z;
			strm.avail_out = CHUNK_Z;
			pedro_dprintf(-1, "entrando\n");
			ret_arp = LZOP2_bzDecompress (&strm);

			writebytes = CHUNK_Z - strm.avail_out;

			pedro_dprintf(-1, "chegou no final\n");
			//exit(27);

			if (writebytes > 0)
			{
				if (0 == (ret_arp_v2 = fwrite (buffer_out_z, 1, writebytes, outtile)))
				{
					retvalue = 14; //Cannot write to output file
					goto saida;
				}
				if(ret_arp_v2 != writebytes)
				{
					retvalue = 14;
					goto saida;
				}
			}

			switch (ret_arp)
			{
			case LZOP_OK:
				pedro_dprintf(-1, "LZOP_OK\n");
				if(0==strm.avail_out)
				{
					goto volta_z;
				}
				if(strm.avail_in)
				{
					goto volta_z;
				}

				break;

			case LZOP_DATA_ERROR:
				pedro_dprintf(-1, "LZOP_DATA_ERROR\n");
				retvalue = 126;
				goto saida;
				break;

			case LZOP_MEM_ERROR:
				pedro_dprintf(-1, "LZOP_MEM_ERROR\n");
				retvalue = 125;
				goto saida;
				break;

			case LZOP_DATA_ERROR_MAGIC:
				pedro_dprintf(-1, "LZOP_DATA_ERROR_MAGIC\n");
				retvalue = 198;
				goto saida;
				break;

			case LZOP_STREAM_END:
				pedro_dprintf(-1, "LZOP_STREAM_END\n");
				done = 1;
				break;
			default:
				pedro_dprintf(-1, "default %d\n", ret_arp);
				assert (0);
				break;
			}



		}

saida:          ;

		ret_arp = LZOP2_bzDecompressEnd(&strm);

		if(LZOP_OK != ret_arp)
		{
			pedro_dprintf(-1, "erro na finalização\n");
		}

		if(-1 == writebytes)
		{
			goto volta_z;
		}
		if(myfile)
			fclose(myfile);
		if(outtile)
			fclose(outtile);
		return tamanho + writebytes + retvalue;

	}
	return 0;
}

#endif

#if 0
int LZOP2_bzCompressInit(LZOP_stream * strm, int level_z, int unused_a_z, int unused_b_z)
{
	assert(NULL == strm->memory_z);
	if (lzo_init() != LZO_E_OK    )
	{
		return LZOP_ERROR;
	}
	strm->max_in_bytes = INTERNAL_SIZE____Z;
	strm->internal_buffer = malloc(strm->max_in_bytes);
	strm->max_out_bytes = calc_out_size(strm->max_in_bytes);
	strm->internal_out_buffer = malloc(strm->max_out_bytes + sizeof(LZOP2_data));
	strm->memory_z = malloc(65536);
	if(strm->memory_z             )
	{
		return LZOP_OK;
	}
	return LZOP_ERROR;
}

int LZOP2_bzCompress (LZOP_stream * strm, int action_z)
{
	int bytes_antes;
	LZOP2_data * struct_data_z;
	int ret_arp;
	int ret_arp_v2;

	strm->processed_input_z = false;
	if(LZOP_RUN == action_z || LZOP_FINISH == action_z)
	{
		pedro_dprintf(-1, "dentro de salvamento de adicional\n");
		if(strm->has_more_data_to_save)
		{
			ret_arp = min(strm->bytes_remaining_z, strm->avail_out);

			memcpy(strm->next_out, strm->out_ptr_saved, ret_arp);

			strm->out_ptr_saved += ret_arp;

			strm->avail_out -= ret_arp;

			strm->bytes_remaining_z -= ret_arp;

			assert(0 <= strm->bytes_remaining_z);

			if(0 == strm->bytes_remaining_z)
			{
				pedro_dprintf(-1, "limpou strm->bytes_remaining_z\n");
				strm->has_more_data_to_save = 0;
			}
			pedro_dprintf(-1, "tinha dados\n");
			return LZOP_RUN_OK;
		}
	}

	strm->processed_input_z = true;

	if(LZOP_RUN == action_z)
	{
		assert(0 <= strm->avail_in);

		if(1)
		{
			if(NULL == strm->in_ptr)
			{
				strm->in_ptr = strm->internal_buffer;
				strm->bytes_input_remaining_z = strm->max_in_bytes;
			}

			ret_arp = min(strm->bytes_input_remaining_z, strm->avail_in);
			memcpy(strm->in_ptr, strm->next_in, ret_arp);

			strm->avail_in -= ret_arp;
			strm->next_in  += ret_arp;

			strm->bytes_input_remaining_z -= ret_arp;
			strm->in_ptr += ret_arp;

			assert(0 <= strm->avail_in);

			if(0 != strm->avail_in)
			{
				strm->processed_input_z = false;
			}

			if(0 == strm->bytes_input_remaining_z)
			{
				//compress
				ret_arp_v2 = lzo_compress(strm->internal_buffer, strm->max_in_bytes, strm->internal_out_buffer + sizeof(LZOP2_data), &strm->out_len_z, strm);
				if(ret_arp_v2 != LZO_E_OK)
				{
					pedro_dprintf(-1, "deu erro na compressao 1\n");
					return LZOP_SEQUENCE_ERROR;
				}
				if(0 != strm->out_len_z)
				{
					struct_data_z = (void *) strm->internal_out_buffer;

					struct_data_z->signature_z[0] = 'A';
					struct_data_z->signature_z[1] = 'R';
					struct_data_z->signature_z[2] = '_';
					struct_data_z->signature_z[3] = '_' - 5;//pra     sempre

					struct_data_z->compressed_size_z   = strm->out_len_z;
					struct_data_z->uncompressed_size_z = strm->max_in_bytes;

					strm->out_len_z += sizeof(LZOP2_data);
				}
				pedro_dprintf(-1, "saiu compressed %d bytes strm->out_len_z\n", strm->out_len_z);

				strm->in_ptr = strm->internal_buffer;
				strm->bytes_input_remaining_z = strm->max_in_bytes;

				ret_arp = min(strm->out_len_z, strm->avail_out);

				memcpy(strm->next_out, strm->internal_out_buffer, ret_arp);

				strm->avail_out -= ret_arp;
				strm->bytes_remaining_z = strm->out_len_z - ret_arp;
				strm->out_len_z -= ret_arp;

				pedro_dprintf(-1, "passo 1 strm->bytes_remaining_z %d\n", strm->bytes_remaining_z);
				if(strm->out_len_z > 0)
				{
					strm->has_more_data_to_save = 1;
					strm->out_ptr_saved = strm->internal_out_buffer;
					strm->out_ptr_saved += ret_arp;
					return LZOP_RUN_OK;
				}
				else if(0 == strm->out_len_z)
				{
					strm->has_more_data_to_save = 0;
					return LZOP_RUN_OK;
				}
			}
			return LZOP_RUN_OK;
		}
	}

	if(LZOP_FINISH == action_z)
	{
		assert(0 <= strm->avail_in);

		if(1)
		{
			if(NULL == strm->in_ptr)
			{
				strm->in_ptr = strm->internal_buffer;
				strm->bytes_input_remaining_z = strm->max_in_bytes;
			}

			ret_arp = min(strm->bytes_input_remaining_z, strm->avail_in);
			memcpy(strm->in_ptr, strm->next_in, ret_arp);

			strm->avail_in -= ret_arp;
			strm->next_in  += ret_arp;

			strm->bytes_input_remaining_z -= ret_arp;
			strm->in_ptr += ret_arp;

			assert(0 <= strm->avail_in);

			if(0 != strm->avail_in)
			{
				strm->processed_input_z = false;
			}
			else
			{
				if(1)
				{
					//compress
					ret_arp_v2 = lzo_compress(strm->internal_buffer, strm->max_in_bytes - strm->bytes_input_remaining_z, strm->internal_out_buffer + sizeof(LZOP2_data), &strm->out_len_z, strm);
					if(ret_arp_v2 != LZO_E_OK)
					{
						pedro_dprintf(-1, "deu erro na compressao 2\n");
						return LZOP_SEQUENCE_ERROR;
					}
					if(0 != strm->out_len_z)
					{
						struct_data_z = (void *) strm->internal_out_buffer;

						struct_data_z->signature_z[0] = 'A';
						struct_data_z->signature_z[1] = 'R';
						struct_data_z->signature_z[2] = '_';
						struct_data_z->signature_z[3] = '_' - 5;//pra     sempre

						struct_data_z->compressed_size_z   = strm->out_len_z;
						struct_data_z->uncompressed_size_z = strm->max_in_bytes - strm->bytes_input_remaining_z;

						strm->out_len_z += sizeof(LZOP2_data);
					}
					pedro_dprintf(-1, "2 saiu compressed %d bytes strm->out_len_z\n", strm->out_len_z);
					strm->in_ptr = strm->internal_buffer;
					strm->bytes_input_remaining_z = strm->max_in_bytes;

					pedro_dprintf(-1, "strm->avail_out antes %d\n", strm->avail_out);

					bytes_antes = strm->avail_out;

					ret_arp = min(strm->out_len_z, strm->avail_out);

					memcpy(strm->next_out, strm->internal_out_buffer, ret_arp);

					strm->avail_out -= ret_arp;
					strm->bytes_remaining_z = strm->out_len_z - ret_arp;
					strm->out_len_z -= ret_arp;

					pedro_dprintf(-1, "passo 2 strm->bytes_remaining_z %d\n", strm->bytes_remaining_z);
					if(strm->out_len_z > 0)
					{
						strm->has_more_data_to_save = 1;
						strm->out_ptr_saved = strm->internal_out_buffer;
						strm->out_ptr_saved += ret_arp;
						return LZOP_FINISH_OK;
					}
					else if(0 == strm->out_len_z)
					{
						strm->has_more_data_to_save = 0;

						pedro_dprintf(-1, "strm->avail_out depois %d\n", strm->avail_out);

						if(bytes_antes == strm->avail_out)
						{
							return LZOP_STREAM_END;
						}
						return LZOP_FINISH_OK;
					}
				}
			}

			if(0 == strm->bytes_input_remaining_z)
			{
				//compress
				ret_arp_v2 = lzo_compress(strm->internal_buffer, strm->max_in_bytes, strm->internal_out_buffer + sizeof(LZOP2_data), &strm->out_len_z, strm);
				if(ret_arp_v2 != LZO_E_OK)
				{
					pedro_dprintf(-1, "deu erro na compressao 3\n");
					return LZOP_SEQUENCE_ERROR;
				}
				if(0 != strm->out_len_z)
				{
					struct_data_z = (void *) strm->internal_out_buffer;

					struct_data_z->signature_z[0] = 'A';
					struct_data_z->signature_z[1] = 'R';
					struct_data_z->signature_z[2] = '_';
					struct_data_z->signature_z[3] = '_' - 5;//pra     sempre

					struct_data_z->compressed_size_z   = strm->out_len_z;
					struct_data_z->uncompressed_size_z = strm->max_in_bytes;

					strm->out_len_z += sizeof(LZOP2_data);
				}
				pedro_dprintf(-1, "3 saiu compressed %d bytes strm->out_len_z\n", strm->out_len_z);
				strm->in_ptr = strm->internal_buffer;
				strm->bytes_input_remaining_z = strm->max_in_bytes;

				ret_arp = min(strm->out_len_z, strm->avail_out);

				memcpy(strm->next_out, strm->internal_out_buffer, ret_arp);

				strm->avail_out -= ret_arp;

				strm->bytes_remaining_z = strm->out_len_z - ret_arp;

				strm->out_len_z -= ret_arp;

				pedro_dprintf(-1, "passo 3 strm->bytes_remaining_z %d\n", strm->bytes_remaining_z);
				if(strm->out_len_z > 0)
				{
					strm->has_more_data_to_save = 1;
					strm->out_ptr_saved = strm->internal_out_buffer;
					strm->out_ptr_saved += ret_arp;
					return LZOP_FINISH_OK;
				}
				else if(0 == strm->out_len_z)
				{
					strm->has_more_data_to_save = 0;
					return LZOP_FINISH_OK;
				}
			}
			return LZOP_FINISH_OK;
		}
	}
	return 0;
}
int LZOP2_bzCompressEnd(LZOP_stream * strm)
{
	if(strm)
	{
		if(strm->memory_z)
			free(strm->memory_z), pedro_dprintf(-1,            "free(strm->memory_z)\n");

		if(strm->internal_out_buffer)
			free(strm->internal_out_buffer), pedro_dprintf(-1, "free(strm->internal_out_buffer)\n");

		if(strm->internal_buffer)
			free(strm->internal_buffer), pedro_dprintf(-1,     "free(strm->internal_buffer)\n");
	}

	return LZOP_OK;//redundant...

}

int LZOP2_bzDecompressInit(LZOP_stream * strm, int unused_1_z, int unused_2_z)
{
	if (lzo_init() != LZO_E_OK    )
	{
		return LZOP_ERROR;
	}
	strm->out_bytes_z  =        0;
	strm->header_ptr_z =     NULL;
	strm->header_ptr_loaded_z = 0;
	strm->first_pass_decoder_z = true;
	strm->max_in_bytes = INTERNAL_SIZE____Z;//will never change...I promise
	strm->max_out_bytes = calc_out_size(strm->max_in_bytes);
	strm->internal_out_buffer = malloc(strm->max_out_bytes + sizeof(LZOP2_data));
	strm->internal_buffer = malloc(strm->max_out_bytes + sizeof(LZOP2_data));
	if(strm->internal_out_buffer && strm->internal_buffer)
	{
		return LZOP_OK;
	}
	return LZOP_ERROR;
}

int LZOP2_bzDecompress    (LZOP_stream * strm)
{
	int ret_arp;

	if(strm->out_bytes_z)
	{
		pedro_dprintf(-1, "despejando buffer strm->out_bytes_z == %d\n", strm->out_bytes_z);
		ret_arp = min(strm->out_bytes_z, strm->avail_out);
		memcpy(strm->next_out, strm->out_ptr, ret_arp   );
		strm->out_ptr     += ret_arp;
		strm->next_out    += ret_arp;
		strm->out_bytes_z -= ret_arp;
		strm->avail_out   -= ret_arp;

		assert(0 <= strm->out_bytes_z);
		return LZOP_OK;
	}
	if(true == strm->first_pass_decoder_z)
	{
		if(0 == strm->avail_in)
		{
			return LZOP_STREAM_END;//nao tem mais nada
		}

		//strm->avail_in = sizeof(LZOP2_data) / 2;

		if(strm->avail_in < sizeof(LZOP2_data))
		{
			pedro_dprintf(-1, "ponto 1\n");

			if(NULL == strm->header_ptr_z)
			{
				strm->header_ptr_z = (void *) &strm->header_z;
				strm->header_ptr_loaded_z = 0;
			}

			ret_arp = min((sizeof(LZOP2_data) - strm->header_ptr_loaded_z), strm->avail_in);

			memcpy(strm->header_ptr_z, strm->next_in, ret_arp);

			strm->header_ptr_z        += ret_arp;
			strm->avail_in            -= ret_arp;
			strm->next_in             += ret_arp;
			strm->header_ptr_loaded_z += ret_arp;

			assert(strm->header_ptr_loaded_z <= sizeof(LZOP2_data));

			if(strm->header_ptr_loaded_z < sizeof(LZOP2_data))
			{
				assert(0 == strm->avail_in);
				pedro_dprintf(-1, "ponto 2\n");
				return LZOP_OK;
			}

			if(sizeof(LZOP2_data) == strm->header_ptr_loaded_z)
			{
				strm->header_ptr_z = NULL;//libera a entrada
				strm->header_ptr_loaded_z = 0;//for safety...
				strm->first_pass_decoder_z = false;
				pedro_dprintf(-1, "ponto 3\n");

				if(strm->header_z.signature_z[0] != 'A' ||
				   strm->header_z.signature_z[1] != 'R' ||
				   strm->header_z.signature_z[2] != '_' ||
				   strm->header_z.signature_z[3] != '_' - 5)
				{
					pedro_dprintf(-1, "LZOP_DATA_ERROR internal 1 \n");
					return LZOP_DATA_ERROR;
				}
				strm->in_ptr = NULL;
				goto next_step_z;
			}
			/*
			   LZOP_OK
			 */
			assert(0);
			pedro_dprintf(-1, "LZOP_DATA_ERROR internal 2 \n");
			return LZOP_DATA_ERROR;
		}
		else
		{
			if(NULL == strm->header_ptr_z)
			{
				strm->header_ptr_z = (void *) &strm->header_z;
				strm->header_ptr_loaded_z = 0;
			}

			if(0 == strm->header_ptr_loaded_z)
			{
				pedro_dprintf(-1, "ponto 4\n");
				ret_arp = min((sizeof(LZOP2_data)), strm->avail_in);
				memcpy(strm->header_ptr_z, strm->next_in, ret_arp );
				strm->avail_in -= ret_arp;
				strm->next_in  += ret_arp;
				strm->first_pass_decoder_z = false;

				strm->header_ptr_z = NULL;//libera a entrada
				strm->header_ptr_loaded_z = 0;//for safety...

				if(strm->header_z.signature_z[0] != 'A' ||
				   strm->header_z.signature_z[1] != 'R' ||
				   strm->header_z.signature_z[2] != '_' ||
				   strm->header_z.signature_z[3] != '_' - 5)
				{
					pedro_dprintf(-1, "LZOP_DATA_ERROR internal 3 \n");
					return LZOP_DATA_ERROR;
				}
				strm->in_ptr = NULL;
				goto next_step_z;
			}
			else
			{
				pedro_dprintf(-1, "ponto 5\n");

				pedro_dprintf(-1, "strm->header_ptr_loaded_z antes %d total %d\n", strm->header_ptr_loaded_z, sizeof(LZOP2_data));

				ret_arp = min((sizeof(LZOP2_data) - strm->header_ptr_loaded_z), strm->avail_in);
				memcpy(strm->header_ptr_z, strm->next_in, ret_arp);
				strm->avail_in     -= ret_arp;
				strm->next_in      += ret_arp;
				strm->header_ptr_z += ret_arp;
				strm->first_pass_decoder_z = false;

				strm->header_ptr_loaded_z += ret_arp;

				pedro_dprintf(-1, "strm->header_ptr_loaded_z depois %d total %d\n", strm->header_ptr_loaded_z, sizeof(LZOP2_data));

				strm->header_ptr_z = NULL;//libera a entrada
				strm->header_ptr_loaded_z = 0;//for safety...

				if(strm->header_z.signature_z[0] != 'A' ||
				   strm->header_z.signature_z[1] != 'R' ||
				   strm->header_z.signature_z[2] != '_' ||
				   strm->header_z.signature_z[3] != '_' - 5)
				{
					pedro_dprintf(-1, "LZOP_DATA_ERROR internal 4 \n");
					return LZOP_DATA_ERROR;
				}
				strm->in_ptr = NULL;
				goto next_step_z;
			}
		}

		//memcpy(
		assert(0 && "nao pode chegar aqui\n");
	}

next_step_z:;

	if(false == strm->first_pass_decoder_z)
	{
		pedro_dprintf(-1, "inicio \n");
		assert(0 <= strm->avail_in);
		if(!strm->avail_in)
		{
			return LZOP_OK;
		}
		else
		{
			if(0 > strm->header_z.compressed_size_z)
			{
				pedro_dprintf(-1, "LZOP_DATA_ERROR internal 6 \n");
				return LZOP_DATA_ERROR;
			}
			if(0 > strm->header_z.uncompressed_size_z)
			{
				pedro_dprintf(-1, "LZOP_DATA_ERROR internal 7 \n");
				return LZOP_DATA_ERROR;
			}
			if(strm->header_z.compressed_size_z > strm->max_out_bytes + sizeof(LZOP2_data))
			{
				pedro_dprintf(-1, "LZOP_DATA_ERROR internal 8 \n");
				return LZOP_DATA_ERROR;
			}
			if(strm->header_z.uncompressed_size_z > strm->max_out_bytes + sizeof(LZOP2_data))
			{
				pedro_dprintf(-1, "LZOP_DATA_ERROR internal 9 \n");
				return LZOP_DATA_ERROR;
			}

			if(NULL == strm->in_ptr)
			{
				strm->in_ptr = strm->internal_buffer;
				strm->in_bytes_z = 0;
			}
			ret_arp = min(strm->avail_in, strm->header_z.compressed_size_z - strm->in_bytes_z);
			pedro_dprintf(-1, "ponto a\n");
			if(strm->in_bytes_z < strm->header_z.compressed_size_z)
			{
				pedro_dprintf(-1, "ponto b\n");
				memcpy(strm->in_ptr, strm->next_in, ret_arp);

				strm->avail_in    -= ret_arp;
				strm->in_ptr      += ret_arp;
				strm->next_in     += ret_arp;
				strm->in_bytes_z  += ret_arp;
			}
			pedro_dprintf(-1, "ponto c\n");
			assert(strm->in_bytes_z <= strm->header_z.compressed_size_z);

			if(strm->in_bytes_z == strm->header_z.compressed_size_z)
			{
				pedro_dprintf(-1, "antes de descompressor\n");
				ret_arp = lzo_decompress(strm->internal_buffer, strm->header_z.compressed_size_z,
				                         strm->internal_out_buffer, &strm->out_len_z, strm);

				if(ret_arp)
				{
					pedro_dprintf(-1, "Erro de descompressão\n");
					pedro_dprintf(-1, "LZOP_DATA_ERROR internal 10 \n");
					return LZOP_DATA_ERROR;
				}
				else
				{

					if(strm->out_len_z != strm->header_z.uncompressed_size_z)
					{
						pedro_dprintf(-1, "LZOP_DATA_ERROR internal 11 \n");
						return LZOP_DATA_ERROR;
					}

					pedro_dprintf(-1, "descomprimiu %d stored %lld\n", strm->out_len_z, strm->header_z.uncompressed_size_z);
				}
				strm->in_ptr = strm->internal_buffer;
				strm->in_bytes_z = 0;
				strm->first_pass_decoder_z = true;

				strm->out_bytes_z = strm->header_z.uncompressed_size_z;

				strm->out_ptr = strm->internal_out_buffer;

				ret_arp = min(strm->header_z.uncompressed_size_z, strm->avail_out);

				memcpy(strm->next_out, strm->out_ptr, ret_arp);

				strm->out_bytes_z -= ret_arp;
				strm->avail_out   -= ret_arp;
				strm->out_ptr     += ret_arp;
				strm->next_out    += ret_arp;

				pedro_dprintf(-1, "strm->out_bytes_z %d\n", strm->out_bytes_z);
				pedro_dprintf(-1, "strm->avail_out %d\n",   strm->avail_out  );
				/*
				        exit(27);
				 */
			}

			return LZOP_OK;

		}
	}

	return 0;
}

int LZOP2_bzDecompressEnd (LZOP_stream * strm)
{
	if(strm)
	{
		if(strm->internal_buffer)
		{
			free(strm->internal_buffer), pedro_dprintf(-1, "free 1\n");
		}
		if(strm->internal_out_buffer)
		{
			free(strm->internal_out_buffer), pedro_dprintf(-1, "free 2\n");
		}
	}
	return LZOP_OK;
}
#endif

int __amandacall compress_z(FILE *input_z, FILE_z* output_z, my_thread_struct_z * amanda)
{	
	lzo_uint saida_bytes_z                                             ;
	int    ret_arp                                                     ;
	int	   return_value_z                                           = 0;
	int    len_z                                                       ;
	char * deslocador_z                                                ;
	char * buffer_in  = malloc(INTERNAL_SIZE____Z                     );
	char * buffer_out = malloc(calc_out_size(INTERNAL_SIZE____Z        +
	sizeof(LZOP2_data))      );
	LZOP2_data * lzop_data_ptr = NULL;
	assert(buffer_in );
	assert(buffer_out);

	pedro_dprintf(-1, "entrou \n");

	if(NULL != lzop_data_ptr)
	{
		return -1;
	}

	assert(NULL == amanda->memory_z);

	amanda->memory_z = malloc(65536);

	assert(amanda->memory_z);
	
	lzo_init();
	
	//aqui amor...
	deslocador_z = buffer_out + sizeof(LZOP2_data);
	lzop_data_ptr = (void *)            buffer_out;
	
	//*((*amanda).bytes_read_z) 
	
	while((len_z = fread(buffer_in, 1, min(amanda->size_of_input_file_copy_z, INTERNAL_SIZE____Z) , input_z)))
	{
		amanda->size_of_input_file_copy_z -= len_z    ;		
		assert(0 <= amanda->size_of_input_file_copy_z);
		
		/*
		
			int lzo_compress(char*bufin, int bufinlen, char*outbuf, lzo_uint *outbuflen, my_thread_struct_z * amanda)
			
			int lzo_decompress(char *buffer, int len, char*outbuf, lzo_uint * outlen, my_thread_struct_z * amanda)
				
		*/
					
		if(lzo_compress(buffer_in, len_z, deslocador_z, &saida_bytes_z, amanda))
		{
			return_value_z = 1;
			goto saida_z;
		}
				
		lzop_data_ptr->signature_z[0] = 'm';
		lzop_data_ptr->signature_z[1] = 'i';
		lzop_data_ptr->signature_z[2] = 's';
		lzop_data_ptr->signature_z[3] = 'l';
		
		lzop_data_ptr->compressed_size_z   = saida_bytes_z;
		
		lzop_data_ptr->uncompressed_size_z = len_z        ;
		
		assert((int64_t)(saida_bytes_z + sizeof(LZOP2_data)) <= (int64_t) (calc_out_size(INTERNAL_SIZE____Z        +
		sizeof(LZOP2_data))));
		
		ret_arp = fwrite_z(buffer_out, 1, saida_bytes_z + sizeof(LZOP2_data), output_z);
		
		if((int) ret_arp != (int)(saida_bytes_z + sizeof(LZOP2_data)))
		{
			return_value_z             = 1;
			amanda->internal_error_arp = 6;
			goto                   saida_z;
		}
		
		amanda->size_of_destination_file_z += ret_arp;

		while(*((*amanda).intpause))
		{
			Sleep(50);
			if(*((*amanda).intcancel))
			{
				amanda->internal_error_arp = 119;
				return_value_z               = 1;
				goto                     saida_z;
			}
		}
		
		if(*((*amanda).intcancel))
		{
			amanda->internal_error_arp = 119;
			return_value_z               = 1;
			goto                     saida_z;
		}
		
		*((*amanda).bytes_read_z) +=   len_z;
				
		//break;
	}
	
saida_z:;
	
	pedro_dprintf(-1, "exitting \n");
	free(buffer_in );
	free(buffer_out);

	free(amanda->memory_z);
	amanda->memory_z = NULL;

	pedro_dprintf(-1, "saiu \n");

	return return_value_z;

}


int __amandacall uncompress_z(FILE *input_z, FILE* output_z, my_thread_struct_z * amanda)
{	
	int64_t   uncompressed_size_z                                      ;
	uint64_t  compressed_size_z                                        ;
	lzo_uint saida_bytes_z                                             ;
	int    ret_arp                                                     ;
	int	   return_value_z                                           = 0;
	int    len_z                                                       ;
	//char * deslocador_z                                              ;
	char * buffer_in  = malloc(calc_out_size(INTERNAL_SIZE____Z        +
		sizeof(LZOP2_data)));
	char * buffer_out = malloc(calc_out_size(INTERNAL_SIZE____Z        +
		sizeof(LZOP2_data)));
	LZOP2_data * lzop_data_ptr = NULL;

	lzop_data_ptr = (void *) buffer_in;

reinicio_z:;

	pedro_dprintf(-1, "************************************************ \n");

	while((len_z = fread(buffer_in, 1, min(amanda->size_of_input_file_copy_z, sizeof(LZOP2_data)), input_z)))
	{
		pedro_dprintf(-1, "dentro \n");
		while(*((*amanda).intpause))
		{
			Sleep(50);
			if(*((*amanda).intcancel))
			{
				pedro_dprintf(-1, "item 1\n"    );
				amanda->internal_error_arp = 119;
				return_value_z               = 1;
				goto                     saida_z;
			}
		}
		
		if(*((*amanda).intcancel))
		{
			pedro_dprintf(-1, "item 2\n"    );
			amanda->internal_error_arp = 119;
			return_value_z               = 1;
			goto                     saida_z;
		}
		
		*((*amanda).bytes_read_z)         += len_z;
		amanda->size_of_input_file_copy_z -= len_z;
		
		if(len_z != sizeof(LZOP2_data))
		{
			pedro_dprintf(-1, "item 3\n"    );
			return_value_z = 1;
			goto saida_z      ;
		}
				
		if('m' != lzop_data_ptr->signature_z[0]
		|| 'i' != lzop_data_ptr->signature_z[1]
		|| 's' != lzop_data_ptr->signature_z[2]
		|| 'l' != lzop_data_ptr->signature_z[3] 
		)
		{
			pedro_dprintf(-1, "item 4\n"    );
			return_value_z = 1;
			goto saida_z      ;
		}
		
		if(0 > lzop_data_ptr->compressed_size_z)
		{
			pedro_dprintf(-1, "item 5\n"    );
			return_value_z = 1;
			goto saida_z      ;
		}
		
		compressed_size_z   = lzop_data_ptr->   compressed_size_z;
		uncompressed_size_z = lzop_data_ptr-> uncompressed_size_z;
		
		if((int64_t) compressed_size_z > (int64_t) (calc_out_size(INTERNAL_SIZE____Z  +
		sizeof(LZOP2_data))))
		{
			pedro_dprintf(-1, "item 5.1\n"    );
			return_value_z = 1;
			goto saida_z      ;
		}
		
		pedro_dprintf(-1, "tamanho comprimido %lld\n", (int64_t) compressed_size_z                    );
		pedro_dprintf(-1, "tamanho restante   %lld\n", (int64_t) amanda->size_of_input_file_copy_z    );
		len_z = fread(buffer_in, 1, min(amanda->size_of_input_file_copy_z, compressed_size_z), input_z);
		
		pedro_dprintf(-1, "tamanho que pegou %d\n", len_z);
				
		*((*amanda).bytes_read_z)         += len_z;
		amanda->size_of_input_file_copy_z -= len_z;
		
		if((int) len_z < (int)compressed_size_z)
		{
			pedro_dprintf(-1, "item 6\n"    );
			return_value_z = 1;
			goto saida_z      ;
		}
		saida_bytes_z = 0;
		if(lzo_decompress(buffer_in, len_z, buffer_out, & /* for your pleasure */ saida_bytes_z,  amanda))
		{
			pedro_dprintf(-1, "item 7\n"    );
			return_value_z = 1;
			goto saida_z      ;
		}
		
		if((int64_t)uncompressed_size_z != (int64_t)saida_bytes_z)
		{
			pedro_dprintf(-1, "item 8\n"    );
			return_value_z = 1;
			goto saida_z      ;
		}
		
		if(amanda->dest_is_FILE_z)
		{
			
			assert(NULL == output_z);
			assert(amanda->dest    );
			ret_arp = fwrite_z(buffer_out, 1, saida_bytes_z, amanda->dest);
			
			if((int)ret_arp != (int)saida_bytes_z)
			{
				pedro_dprintf(-1, "item 9\n"    );
				amanda->internal_error_arp = 6;
				return_value_z             = 1;
				goto saida_z                  ;
			}
			
		}
		else
		{
			ret_arp = fwrite(buffer_out, 1, saida_bytes_z, output_z);
			
			if((int)ret_arp != (int)saida_bytes_z)
			{
				pedro_dprintf(-1, "item 9\n"    );
				amanda->internal_error_arp = 6;
				return_value_z             = 1;
				goto saida_z                  ;
			}
		}
		goto reinicio_z;
	}

saida_z:;
	
	pedro_dprintf(-1, "exitting \n");
	free(buffer_in );
	free(buffer_out);

	return return_value_z;
}

#ifdef MY_MAIN_Z
/*
int main(int argc_z, char ** argv_z)
{
	FILE * myfile_z    =     NULL;
	FILE *outtile_z    =     NULL;
	
	char wfile[1024];
	myfile_z = fopen(argv_z[1],
	                 "rb");
	
	{
	int pause_z                   = 0;
	int cancel_z                  = 0;
	int64_t dummy_z               = 0;
	my_thread_struct_z amanda = {0, };
	
	fseek(myfile_z, 0, SEEK_END);

	amanda.intpause =                                                       &pause_z;
	amanda.intcancel =                                                     &cancel_z;
	amanda.bytes_read_z                                                   = &dummy_z;
	amanda.size_of_input_file_copy_z = amanda.size_of_input_file_z = ftell(myfile_z);
	
	fseek(myfile_z, 0, SEEK_SET);

	strcpy(wfile, argv_z[1]);
	strcat(wfile, ".lzo2");

	outtile_z = fopen(wfile,
	                  "wb");

	//aqui
	compress_z(myfile_z, outtile_z, &amanda);

	pedro_dprintf(-1, "tamanho de bytes lidos %lld\n", dummy_z);
	pedro_dprintf(-1, "tamanho comprimido %lld\n", amanda.size_of_destination_file_z);

	fclose(myfile_z );
	fclose(outtile_z);
	
	}
	
	{
		int ret_arp                      ;
		int pause_z                   = 0;
		int cancel_z                  = 0;
		int64_t dummy_z               = 0;
		
		my_thread_struct_z amanda = {0, };
		myfile_z = fopen(wfile,
		"rb");

		strcat(wfile, ".uncompressed");

		outtile_z = fopen(wfile,
		"wb"); 

		fseek(myfile_z, 0, SEEK_END);
		amanda.intpause =                                                       &pause_z;
		amanda.intcancel =                                                     &cancel_z;
		amanda.bytes_read_z                                                   = &dummy_z;
		amanda.size_of_input_file_copy_z = amanda.size_of_input_file_z = ftell(myfile_z);

		fseek(myfile_z, 0, SEEK_SET);

		ret_arp = uncompress_z(myfile_z, outtile_z, &amanda);

		if(ret_arp)
		{
			pedro_dprintf(-1, "deu erro na descompressão\n");
		}
		else
		{
			pedro_dprintf(-1, "descomprimiu\n");
		}
		
		fclose(myfile_z );
		fclose(outtile_z);
	}
	
	return 0;
}
*/
#endif
