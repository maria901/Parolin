/*
    Copyright (C) <2022>  <BinaryWork Corp.>

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
   
        direct programmers e-mails:
        Ricardo: arsoftware25@gmail.com  ricardo@arsoftware.net.br
         Amanda: arsoftware10@gmail.com  amanda@arsoftware.net. br

        immediate contact(for a very fast answer) WhatsApp
        (+55)41 9627 1708 - it is always on
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

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

#include "lz5.h"

int calc_out_size(int input)
{
	return (input + input / 16 + 64 + 3);
}

enum error_lz5_
{
	LZO_E_OK ,
	LZO_E_ERR,
};

int lzo_compress(char*bufin, int bufinlen, char*outbuf, lzo_uint *outbuflen, LZOP_stream * strm)
{
	int r = 0;
	
	if(0 == bufinlen)
	{
		pedro_dprintf(-1, "tentando comprimir 0 bytes\n");
		*outbuflen = 0;
		return 0;
	}

	{
		/*
		r = lzo1x_1_compress( (unsigned char *) bufin, bufinlen, (unsigned char *) outbuf, outbuflen, strm->memory_z);
		*/
	}

	//compressed_z += *outbuflen + sizeof(LZOP2_data        );

	if (r == LZO_E_OK)
		;//printf("compressed %lu bytes into %lu bytes\n",
		    //   (unsigned long) bufinlen, (unsigned long) *outbuflen);
	else
	{
		/* this should NEVER happen */
		//printf("internal error - compression failed: %d\n", r);
		return 2;
	}
	return 0;
}

int lzo_decompress(char *buffer, int len, char*outbuf, lzo_uint * outlen, LZOP_stream * strm)
{

	int r = 0;
	/*
		r = lzo1x_decompress((unsigned char *) buffer, len, (unsigned char *) outbuf, outlen, NULL);
	*/
	if (r == LZO_E_OK)
		;//printf("decompressed %lu bytes back into %lu bytes\n",
		      // (unsigned long) len, (unsigned long) *outlen);
	else
	{
		/* this should NEVER happen */
		//printf("internal error - decompression failed: %d\n", r);
		return 1;
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
			case LZOP_STREAM_END: //compression...
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

saida_b:;
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
		int ret_arp_v2       ;
		int retvalue      = 0;
		int writebytes    = 0;
		
		int tamanho          ;
		int done          = 0;
		int ret_arp          ;
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
			strm.avail_in = ret_arp ;
volta_z:;
			
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
 
 saida:;
	done = 1;
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

int LZOP2_bzCompressInit(LZOP_stream * strm, int level_z, int unused_a_z, int unused_b_z)
{
	assert(NULL == strm->memory_z);

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
				ret_arp_v2 = lzo_compress(strm->internal_buffer, strm->max_in_bytes, strm->internal_out_buffer, &strm->out_len_z, strm);
				if(ret_arp_v2 != LZO_E_OK)
				{
					pedro_dprintf(-1, "deu erro na compressao 1\n");
					return LZOP_SEQUENCE_ERROR;
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
					ret_arp_v2 = lzo_compress(strm->internal_buffer, strm->max_in_bytes - strm->bytes_input_remaining_z, strm->internal_out_buffer, &strm->out_len_z, strm);
					if(ret_arp_v2 != LZO_E_OK)
					{
						pedro_dprintf(-1, "deu erro na compressao 2\n");
						return LZOP_SEQUENCE_ERROR;
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
							//basta fazer aqui.. nao é?
							
							return LZOP_STREAM_END;
						}
						return LZOP_FINISH_OK;
					}
				}
			}

			if(0 == strm->bytes_input_remaining_z)
			{
				//compress
				ret_arp_v2 = lzo_compress(strm->internal_buffer, strm->max_in_bytes, strm->internal_out_buffer, &strm->out_len_z, strm);
				if(ret_arp_v2 != LZO_E_OK)
				{
					pedro_dprintf(-1, "deu erro na compressao 3\n");
					return LZOP_SEQUENCE_ERROR;
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
		strm->out_ptr     += ret_arp                     ;
		strm->next_out    += ret_arp                     ;
		strm->out_bytes_z -= ret_arp                     ;
		strm->avail_out   -= ret_arp                     ;
		
		assert(0 <= strm->out_bytes_z)                   ;
		return                                      LZOP_OK;
	}
		
	if(1)
	{
		pedro_dprintf(-1, "inicio \n");
		assert(0 <= strm->avail_in);
		if(!strm->avail_in)
		{
			return LZOP_OK;
		}
		else
		{			
			if(NULL == strm->in_ptr)
			{
				strm->in_ptr = strm->internal_buffer;
				strm->in_bytes_z = 0;
			}
			ret_arp = min(strm->avail_in, strm->compressed_size_z - strm->in_bytes_z);
			pedro_dprintf(-1, "ponto a\n");
			if(strm->in_bytes_z < strm->compressed_size_z)
			{
				pedro_dprintf(-1, "ponto b\n");
				memcpy(strm->in_ptr, strm->next_in, ret_arp);
				
				strm->avail_in    -= ret_arp;
				strm->in_ptr      += ret_arp;
				strm->next_in     += ret_arp; 
				strm->in_bytes_z  += ret_arp;
			}
			pedro_dprintf(-1, "ponto c\n");
			assert(strm->in_bytes_z <= strm->compressed_size_z);//basta usar in_bytes_z no ultimo decompressor
			
			if(strm->in_bytes_z == strm->compressed_size_z)
			{
				pedro_dprintf(-1, "antes de descompressor\n");
				ret_arp = lzo_decompress(strm->internal_buffer, strm->compressed_size_z,
				strm->internal_out_buffer, &strm->out_len_z, strm);	
				
				if(ret_arp)
				{
					pedro_dprintf(-1, "Erro de descompressão\n");
					pedro_dprintf(-1, "LZOP_DATA_ERROR internal 10 \n");
					return LZOP_DATA_ERROR;
				}
				else
				{
					/*
						if(strm->out_len_z != strm->header_z.uncompressed_size_z)
						{
							pedro_dprintf(-1, "LZOP_DATA_ERROR internal 11 \n");
							return LZOP_DATA_ERROR;
						}
					*/

				}
				strm->in_ptr = strm->internal_buffer;
				strm->in_bytes_z = 0;
				strm->first_pass_decoder_z = true;
				
				strm->out_bytes_z = strm->out_len_z;
				
				strm->out_ptr = strm->internal_out_buffer;
				
				ret_arp = min(strm->out_len_z, strm->avail_out);
								
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
			free(strm->internal_out_buffer) , pedro_dprintf(-1, "free 2\n");
		}		
	}
	return LZOP_OK;
}