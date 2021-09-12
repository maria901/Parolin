
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

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

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

#include "stdio_v2.h"
#include "stdio_v3.h"


#include <process.h>

bool is_multi_thread_z = false;

#include "minilzo.h"

//#include "lz5.h"

#include "win64.h"

#define __amandacall __stdcall

int lz5uncompress_k_mt_z (char *input, char *output);

extern int unicodemode;
extern int intpause;
extern int intcancel;

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

int utf8towide (const char *pUTF8, WCHAR * pUSC2, int nUSC2);

int lz5uncompress_k (char *input, char *output);

uint32_t
tuklib_cpucores_z  (void);

extern char temp_path_z[];

char * valquiria_wide_to_utf8(WCHAR * pUSC2_maria)
{
	static char saida_utf8[1024];
	WideCharToMultiByte (CP_UTF8, 0, pUSC2_maria, -1, (LPSTR) saida_utf8, 1024, 0, 0);
	return saida_utf8;
}

WCHAR * amanda_utf8towide_1_(char *pUTF8)
{
	static WCHAR ricardo_k[1024];
	MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, ricardo_k, 1024);
	return ricardo_k;
}

FILE * fopen_utf8_z(char * filename_z, char * mode);

int finished = 0;

extern int intstatus;

extern int n_threads_z;

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

#define CHUNK (32768 * 2 * 2) /* it is a good slice of data */

int lzop2percent = 0;

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
	maxa = ((double) 10000 / maxa * fatiaa);
	return (int) maxa;
}

int
createtempfilename_and_keep_z (char *path1, char *out_z, WCHAR *signature_z)
{

	int ret;

	static char path[1024];

	strcpy (path, path1);

	//removedordeespaconofinal (path);

	ret = strlen (path);

	if (path[ret - 1] != '\\')
	{
		path[ret] = '\\';
		path[ret + 1] = 0;
	}
	{
		WCHAR fixo_w_ar[1024]={0};
		WCHAR path_w_ar[1024]={0};

		wcscpy(path_w_ar, amanda_utf8towide_1_(path));
		ret = GetTempFileNameW (path_w_ar, signature_z, 0, fixo_w_ar);

		if (ret == 0)
		{
			return 0;
		}
		else
		{
			strcpy(out_z,  valquiria_wide_to_utf8(fixo_w_ar));
			return 1;
		}
	}
}

unsigned int rsp32(unsigned int adler, const unsigned char *buf, unsigned int len)
{
	uchar s1 = adler & 0xff;
	uchar s2 = (adler >> 8) & 0xff;
	uchar s3 = (adler >> 16) & 0xff;
	uchar s4 = (adler >> 24) & 0xff;
	int svansa = 0;
	int ok12 = len;

	if (buf == NULL)
	{
		return 1L;
	}

	while (ok12)
	{
		s1 += buf[svansa++];
		s2 += s1;
		s3 += s2;
		s4 += s3;
		ok12--;
	}

	return s1 + (s2 << 8) + (s3 << 16) + (s4 << 24);
}

uint __amandacall rsp32file_z(char *inputfile)
{

	char *  buf_z = malloc (CHUNK);
	FILE *  f_stream_z      = NULL;
	uint len;
	uint crc;

	crc = 0;

	if ((f_stream_z = fopen_utf8_z(inputfile, "rb")) != NULL)
	{

	}
	else
	{
		free(buf_z);
		return 1;
	}

	while (1)
	{
		len = fread(buf_z, 1, CHUNK, f_stream_z);

		if (0 >= len)//inverted to really learn
		{
			break;
		}

		crc = rsp32(crc, (uchar *) buf_z, len);
	}

	fclose(f_stream_z);
	free(buf_z);
	return crc;
}

#ifdef ARP_USE_ENHANCED_STDIO
FILE_z * files_to_close_z[10];
#endif
int64_t totalbytes_z;
int64_t bytes__read_thread_z[10];
int64_t offset_z__[10];
int64_t size_of_input_file_z__[10];
__INT32_OR_INT64 my_thread_handle[10];
char temp_files_z[10][1024];
int thread_return_value_z;

int64_t veja_z = 0;

//amanda 2
unsigned __stdcall my_thread_function(void * my_argument_z)
{
	compressResult_t return_amanda           = { 1, 0, 0 };
	int64_t size_of_compressed_z                       = 0;

	my_thread_struct_z * ptr_my_struct_z   = my_argument_z;

	if(NULL == ptr_my_struct_z)
	{
		exit(123);
	}

	assert(my_argument_z);

	bytes__read_thread_z[ptr_my_struct_z->thread_id_z] = 0x0;

	if(NULL == ptr_my_struct_z->input_file)
	{
		ptr_my_struct_z->retvalue = 1;
		goto saida_arp;
	}

	if(NULL == ptr_my_struct_z->dest)
	{
		goto saida_arp;
	}

	pedro_dprintf(-1, "my thread running %x \n", my_argument_z);

	pedro_dprintf(-1, "offset %lld\n", ptr_my_struct_z->offset_z);

	if(0 != ptr_my_struct_z->offset_z)
	{
		if(
			0 != _fseeki64(
				ptr_my_struct_z->input_file,
				ptr_my_struct_z->offset_z,
				SEEK_SET
				)
			)
		{
			ptr_my_struct_z->retvalue = 403;  //File access error
			goto saida;
		}
	}

	pedro_dprintf(-1, "slice %lld\n", ptr_my_struct_z->size_of_input_file_z          );
	ptr_my_struct_z->size_of_input_file_copy_z = ptr_my_struct_z->size_of_input_file_z;
	veja_z += ptr_my_struct_z->size_of_input_file_z;

	pedro_dprintf(-1, "tamanho apos slices %lld\n", veja_z);

	if(ptr_my_struct_z->dest)
	{
		pedro_dprintf(-1, "fechando dest\n");
#ifdef ARP_USE_ENHANCED_STDIO
		fclose_z(ptr_my_struct_z->dest      );
#else
		fclose(ptr_my_struct_z->dest      );
		ptr_my_struct_z->dest        = NULL;
#endif

	}

#ifdef ARP_USE_ENHANCED_STDIO
	ptr_my_struct_z->ret = fwrite_z (&ptr_my_struct_z->ar, 1, sizeof (ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#else
	ptr_my_struct_z->ret = fwrite (&ptr_my_struct_z->ar, 1, sizeof (ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#endif

	if (sizeof (ptr_my_struct_z->ar) != ptr_my_struct_z->ret)
	{
		ptr_my_struct_z->retvalue = 400;  //Cannot write to temporary file
		goto saida;
	}
	//deu...
#ifdef ARP_USE_ENHANCED_STDIO
	ptr_my_struct_z->ret = fwrite_z (&size_of_compressed_z, 1, sizeof (size_of_compressed_z), ptr_my_struct_z->dest);
#else
	ptr_my_struct_z->ret = fwrite (&size_of_compressed_z, 1, sizeof (size_of_compressed_z), ptr_my_struct_z->dest);
#endif
	if (sizeof (size_of_compressed_z) != ptr_my_struct_z->ret)
	{
		ptr_my_struct_z->retvalue = 400;  //Cannot write to temporary file
		goto saida;
	}

//aqui vai o codigo

	intpause = 0;
	intcancel = 0;

	ptr_my_struct_z->intpause  =                                              &intpause;
	ptr_my_struct_z->intcancel =                                             &intcancel;

	ptr_my_struct_z->size_of_destination_file_z                                     = 0;
	ptr_my_struct_z->bytes_read_z = &bytes__read_thread_z[ptr_my_struct_z->thread_id_z];
	return_amanda = compress_file(ptr_my_struct_z->input_file, ptr_my_struct_z->dest, ptr_my_struct_z);
	size_of_compressed_z = ptr_my_struct_z->size_of_destination_file_z                 ;
	if(119 == ptr_my_struct_z->internal_error_arp)
	{
		ptr_my_struct_z->retvalue = ptr_my_struct_z->internal_error_arp;
	}
	else if(6 == ptr_my_struct_z->internal_error_arp)
	{
		ptr_my_struct_z->retvalue = ptr_my_struct_z->internal_error_arp;
	}
	else
	{

		if(return_amanda.error)
		{
			ptr_my_struct_z->retvalue = 8;//Compression error
		}

	}
saida:

	if (0 == ptr_my_struct_z->retvalue)
	{
		if(unicodemode)
		{
			WCHAR wpmode[300] ={0,};

			pedro_dprintf(-1, "arquivo a escrever final %s\n", temp_files_z[ptr_my_struct_z->thread_id_z]);

			utf8towide (temp_files_z[ptr_my_struct_z->thread_id_z], wpmode, 300);
#ifdef ARP_USE_ENHANCED_STDIO
			ptr_my_struct_z->dest = _wfopen_z (wpmode, "rb+", MAX_MEMORY_SIZE_Z, __FILE__, __LINE__, ptr_my_struct_z->dest);
#else
			ptr_my_struct_z->dest = _wfopen (wpmode, L"rb+");
#endif
		}
		else
		{
#ifdef ARP_USE_ENHANCED_STDIO
			ptr_my_struct_z->dest = fopen_z (temp_files_z[ptr_my_struct_z->thread_id_z], "rb+", MAX_MEMORY_SIZE_Z, __FILE__, __LINE__, ptr_my_struct_z->dest);
#else
			ptr_my_struct_z->dest = fopen (temp_files_z[ptr_my_struct_z->thread_id_z], "rb+");
#endif
		}
		if (0 == ptr_my_struct_z->dest)
		{

			ptr_my_struct_z->retvalue = 405;

		}
		else
		{
#ifdef ARP_USE_ENHANCED_STDIO
			ptr_my_struct_z->ret = fwrite_z (&ptr_my_struct_z->ar, 1, sizeof (ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#else
			ptr_my_struct_z->ret = fwrite (&ptr_my_struct_z->ar, 1, sizeof (ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#endif
			if (ptr_my_struct_z->ret != sizeof (ptr_my_struct_z->ar))
			{

				ptr_my_struct_z->retvalue = 400;

			}
#ifdef ARP_USE_ENHANCED_STDIO
			ptr_my_struct_z->ret = fwrite_z (&size_of_compressed_z, 1, sizeof (size_of_compressed_z), ptr_my_struct_z->dest);
#else
			ptr_my_struct_z->ret = fwrite (&size_of_compressed_z, 1, sizeof (size_of_compressed_z), ptr_my_struct_z->dest);
#endif
			if (ptr_my_struct_z->ret != sizeof (size_of_compressed_z))
			{

				ptr_my_struct_z->retvalue = 400;

			}
		}
	}

	if (ptr_my_struct_z->dest)
	{
#ifndef ARP_USE_ENHANCED_STDIO
		fclose (ptr_my_struct_z->dest);
		ptr_my_struct_z->dest = NULL;
#endif
	}

	if (intcancel)
	{
		ptr_my_struct_z->retvalue = 119;//User abort
	}

saida_arp:;

	if(ptr_my_struct_z->dest)
	{
		pedro_dprintf(-1, "fechando dest\n");
#ifndef ARP_USE_ENHANCED_STDIO
		fclose(ptr_my_struct_z->dest      );
#endif
	}
	if(ptr_my_struct_z->input_file        )
	{
		fclose(ptr_my_struct_z->input_file);
	}

	if(0 == thread_return_value_z)
	{
		thread_return_value_z = ptr_my_struct_z->retvalue;
	}

	free(my_argument_z);
	_endthreadex(0);

	return 0;
}

//amanda 1
int lz5compress_k (char *input, char *output, int levelin)//level not in use
{

	static char buffer[CHUNK];
	FILE_z *temp_z                = NULL;
	FILE  * dest                  = NULL;
	int ret;
	int ret2;
	int64_t offset_z;
	int64_t remaining_z;
	int64_t slice_z;
	int first_step_z                 = 0;
	my_thread_struct_z * ptr_my_struct_z;
	int n_thread_counter;
	int n_threads_copy;
	int i_z;
	int64_t totalbytes;
	int level;
	thread_return_value_z = 0;

	intpause                         = 0;
	intcancel                        = 0;
	level =                      levelin;

	if (levelin                     <= 0)
	{
		level =                        1;
	}
	if (levelin                      > 9)
	{
		level =                        9;
	}
	veja_z = 0;

	totalbytes = lffilesize(input);
	totalbytes_z = totalbytes;

	is_multi_thread_z = true;        //hack...

	if(1)        //hack...
	{
		//aqui...
		if(0 == n_threads_z)
		{
			n_threads_z = tuklib_cpucores_z();

			if(0 == n_threads_z)
			{
				n_threads_z = 1;
			}

			/*

			        if(1 == n_threads_z)
			        {
			                //goto single_thread_z;
			        }

			 */
		}

		if(8 < n_threads_z)
		{
			n_threads_z = 8;
		}

		for(i_z = 0; i_z < n_threads_z; i_z++)
		{
			bytes__read_thread_z[i_z] = 0;
		}

		is_multi_thread_z = true;

		//aqui , usa padding bytes com numero nao multiplo de 4

		//novo signature 0x5e5f5241

		n_threads_copy = n_threads_z;
		n_thread_counter = 0;
		while(n_threads_copy--)
		{
			ptr_my_struct_z = calloc(1, sizeof(my_thread_struct_z));
			assert(ptr_my_struct_z);
			pedro_dprintf(-1, "alocou\n");

			ptr_my_struct_z->thread_id_z = n_thread_counter;

			//ptr_my_struct_z->
			pedro_dprintf(-1, "temp path %s\n", temp_path_z);

			if(unicodemode)
			{
				WCHAR wpmode[300] ={0,};
				utf8towide (input, wpmode, 300);
				ptr_my_struct_z->input_file = _wfopen (wpmode, L"rb");
			}
			else
				ptr_my_struct_z->input_file = fopen (input, "rb");

			if(NULL == ptr_my_struct_z->input_file)
			{
				if(0 == thread_return_value_z)
				{
					thread_return_value_z = 1;         //Cannot open input file = 107;
				}
			}

			ptr_my_struct_z->dest = NULL;
			if(!createtempfilename_and_keep_z(temp_path_z, temp_files_z[n_thread_counter], L"BZ3"))
			{
				if(0 == thread_return_value_z)
				{
					thread_return_value_z = 407;         //Cannot create temp file
				}
			}
			else
			{
				if(unicodemode)
				{
					WCHAR wpmode[300] = {0,};
					utf8towide (temp_files_z[n_thread_counter], wpmode, 300);
#ifdef ARP_USE_ENHANCED_STDIO
					ptr_my_struct_z->dest = _wfopen_z (wpmode, "wb", MAX_MEMORY_SIZE_Z, __FILE__, __LINE__, NULL);
					files_to_close_z[n_thread_counter] = ptr_my_struct_z->dest;

#else
					ptr_my_struct_z->dest = _wfopen (wpmode, L"wb");
#endif
				}
				else
				{
#ifdef ARP_USE_ENHANCED_STDIO
					ptr_my_struct_z->dest = fopen_z (temp_files_z[n_thread_counter], "wb", MAX_MEMORY_SIZE_Z, __FILE__, __LINE__, NULL);
					files_to_close_z[n_thread_counter] = ptr_my_struct_z->dest;
#else

					ptr_my_struct_z->dest = fopen (temp_files_z[n_thread_counter], "wb");
#endif
				}

				if (NULL == ptr_my_struct_z->dest)
				{
					if(0 == thread_return_value_z)
					{
						thread_return_value_z = 405;         //Cannot open output tempfile
					}
				}
			}

			if(0 == first_step_z)
			{
				pedro_dprintf(-1, "tamanho %lld\n", totalbytes);
				slice_z =             totalbytes / n_threads_z;
				remaining_z                       = totalbytes;
				offset_z                                   = 0;
				for(i_z = 0; i_z < n_threads_z; i_z++)
				{
					if(i_z == (n_threads_z - 1))
					{
						offset_z__[i_z] = offset_z;
						size_of_input_file_z__[i_z] = remaining_z;
					}
					else
					{
						offset_z__[i_z] = offset_z;
						size_of_input_file_z__[i_z] = slice_z;
						offset_z        += slice_z;
						remaining_z     -= slice_z;
					}
				}
				first_step_z = 1;
			}

			ptr_my_struct_z->offset_z = offset_z__[n_thread_counter];
			ptr_my_struct_z->size_of_input_file_z = size_of_input_file_z__[n_thread_counter];

			//init...

			memset (&ptr_my_struct_z->ar, 0, sizeof (ar_data));

			memcpy (ptr_my_struct_z->ar.string, "AR__", 4);                        //aqui 2

			ptr_my_struct_z->ar.string[3] = '_' - 9;                        //signature for lz5 multi-thread

			pedro_dprintf(-1, "ai %x\n", *((int*)ptr_my_struct_z->ar.string));

			ptr_my_struct_z->level = level;

			if(unicodemode)
			{
				WCHAR wpmode[300] ={0,};
				utf8towide (input, wpmode, 300);
				ptr_my_struct_z->ar.attrib = GetFileAttributesW (wpmode);
			}
			else
				ptr_my_struct_z->ar.attrib = GetFileAttributes (input);

			if ((int)0xFFFFFFFF == (int)ptr_my_struct_z->ar.attrib)
			{
				ptr_my_struct_z->ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
			}

			bytes__read_thread_z[n_thread_counter] = 0;

			//ptr_my_struct_z->/* pure fun */ action = LZOP_RUN;

			my_thread_handle[n_thread_counter] = (__INT32_OR_INT64) _beginthreadex(NULL, 0, my_thread_function, ptr_my_struct_z, 0, NULL);

			n_thread_counter++;
		}

		for(i_z = 0; i_z < n_threads_z; i_z++)
		{
			WaitForSingleObject((void *) my_thread_handle[i_z], INFINITE);
			CloseHandle((void *) my_thread_handle[i_z]);
		}
		/*
		   //to finished the code
		   if(unicodemode)
		   {
		        WCHAR wpmode[300] ={0,};
		        utf8towide (input, wpmode, 300);
		        ar.attrib = GetFileAttributesW (wpmode);
		   }
		   else
		        ar.attrib = GetFileAttributes (input);

		   if (0xFFFFFFFF == ar.attrib)
		   {
		        ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
		   }
		 */

		if(unicodemode)
		{
			WCHAR wpmode[300] ={0,};
			utf8towide (output, wpmode, 300);
			ret = SetFileAttributesW (wpmode, FILE_ATTRIBUTE_ARCHIVE);
		}
		else
			ret = SetFileAttributes (output, FILE_ATTRIBUTE_ARCHIVE);

		//abrir arquivo

		if(unicodemode)
		{
			WCHAR wpmode[300] = {0,        };
			utf8towide (output, wpmode, 300);
			dest = _wfopen (wpmode, L"wb"  );
		}
		else
			dest = fopen (output, "wb");

		if (NULL == dest)
		{
			if(0 == thread_return_value_z)
			{
				thread_return_value_z = 2;        //Cannot open output file
			}
		}

		//depois de finalizar
		for(i_z = 0; i_z < n_threads_z; i_z++)
		{
			pedro_dprintf(-1, "arquivo temp a del %s\n",  temp_files_z[i_z]);
			if(dest)
			{

				if(unicodemode)
				{
					WCHAR wpmode[300] = {0,        };
					utf8towide (temp_files_z[i_z], wpmode, 300);
#ifdef ARP_USE_ENHANCED_STDIO
					temp_z = _wfopen_z (wpmode, "rb", MAX_MEMORY_SIZE_Z, __FILE__, __LINE__, files_to_close_z[i_z]);
#else
					temp_z = _wfopen (wpmode, L"rb"  );
#endif
				}
				else
				{
#ifdef ARP_USE_ENHANCED_STDIO
					temp_z = fopen_z (temp_files_z[i_z], "rb", MAX_MEMORY_SIZE_Z, __FILE__, __LINE__, files_to_close_z[i_z]);
#else
					temp_z = fopen (temp_files_z[i_z], "rb");
#endif
				}
				if(temp_z)
				{
					//Mr. Do

volta_amanda:
					;
#ifdef ARP_USE_ENHANCED_STDIO
					ret = fread_z(buffer, 1, CHUNK, temp_z);
#else
					ret = fread(buffer, 1, CHUNK, temp_z);
#endif
					if(0 > ret)
					{
						if(0 == thread_return_value_z)
						{
							thread_return_value_z = 5;         //Cannot read from input file
						}
					}
					else if(0 == ret)
					{
						;        //just go by...
					}
					else
					{

						ret2 = fwrite(buffer, 1, ret, dest);

						if(ret2 != ret)
						{
							if(0 == thread_return_value_z)
							{
								thread_return_value_z = 6;         //Cannot write to output file
							}
							goto exit_loop_z;
						}

						goto volta_amanda;
					}

exit_loop_z:                            ;
#ifndef ARP_USE_ENHANCED_STDIO
					fclose(temp_z);
#endif
				}
				else
				{
					if(0 == thread_return_value_z)
					{
						thread_return_value_z = 405;         //Cannot open temp file
					}
				}
			}
#ifndef ARP_USE_ENHANCED_STDIO
			_wunlink(amanda_utf8towide_1_(temp_files_z[i_z]));
#endif
		}

#ifdef ARP_USE_ENHANCED_STDIO
		for(i_z = 0; i_z < n_threads_z; i_z++)
		{
			free_z(files_to_close_z[i_z]);
			_wunlink(amanda_utf8towide_1_(temp_files_z[i_z]));
		}
#endif

		if(0 == thread_return_value_z)
		{
			pedro_dprintf(-1, "%lld %lld\n", veja_z, totalbytes);
			assert(veja_z == totalbytes);
		}

		//precisa setar isto antes de retornar
		finished = 1;        //e depois return

		if(dest)
		{
			fclose(dest);
		}
		intstatus = 0;
		return thread_return_value_z;
	}
	intstatus = 0;
	return 0;
}

int lz5uncompress (char *input, char *output)
{
	return lz5uncompress_k_mt_z(input, output);
}

#include "lz5_decoder_mt_z.c"

int lz5uncompress_k_mt_z (char *input, char *output)
{
	pedro_dprintf(-1, "dentro de decoder multi-thread\n");
	if(1 != n_threads_z)
	{
		if(0 == n_threads_z)
		{
			n_threads_z = tuklib_cpucores_z();

			if(1 == n_threads_z)
			{
				goto single_thread_amanda;
			}
		}
		return compress2_uncompress_k_real_mt_z (input, output);
	}

single_thread_amanda:;

	
	pedro_dprintf(-1, "decoder single thread in multi-thread mode\n");

	FILE * dest                    = 0;
	FILE * source                  = 0;
	bool first_pass_z          = false;
	__int64 bytesread              = 0;
	__int64 totalbytes             = 0;
	bytes__read_thread_z[0] = 0x0;
	totalbytes   = lffilesize (input);
	totalbytes_z = totalbytes;

	my_thread_struct_z amanda   = {0,};

	amanda.bytes_read_z = &bytes__read_thread_z[0];

	if(NULL == amanda.bytes_read_z)
	{
		exit(27);
		return 0;
	}

	n_threads_z = 1;

init_position_z:;
	int ret_arp;
	int64_t save_position_z;
	int64_t remaining_z;
	char signature_z[5]    = "AR__";

	int ret                        = 0;
	int retvalue                   = 0;

	ar_data ar                   = {0};

	intstatus                      = 1;

	////exit(27);

	intpause = 0;
	intcancel = 0;

	amanda.intpause  = &intpause;
	amanda.intcancel = &intcancel;
	if(-1 == totalbytes || -1 == bytesread)
	{
		return 0;
	}

	if(!first_pass_z)
	{
		{
			WCHAR wpmode[300] ={0,};
			utf8towide (input, wpmode, 300);
			source = _wfopen (wpmode, L"rb");
		}

		if (NULL == source)
		{
			retvalue = 1;
			goto saida;
		}

	}

	{
		WCHAR temp_w_k[300] = {0};
		utf8towide (output, temp_w_k, 300);
		ret = SetFileAttributesW (temp_w_k, FILE_ATTRIBUTE_ARCHIVE);
	}

	memset (&ar, 0, sizeof (ar));
	ret = fread (&ar, 1, sizeof (ar), source);

	if (ret != sizeof (ar))
	{
		retvalue = 5;
		goto saida;
	}

	signature_z[3] = '_' - 9;//lz5 multi-thread

	if (0 != memcmp (ar.string, signature_z, 4))
	{
		pedro_dprintf(-1, "erro 7\n");
		retvalue = 7;
		goto saida;
	}

	ret = fread (&remaining_z, 1, sizeof (remaining_z), source);

	if (sizeof (remaining_z) != ret)
	{
		retvalue = 5;
		goto saida;
	}

	if(!first_pass_z)
	{
		{
			WCHAR wpmode[300] ={0,};
			utf8towide (output, wpmode, 300);
			dest = _wfopen (wpmode, L"wb");
		}

		if (NULL == dest)
		{
			retvalue = 2;
			goto saida;
		}
		first_pass_z = true;
	}

	amanda.size_of_input_file_copy_z = remaining_z;
	//aqui...

	ret_arp = decompress_file(source, dest, &amanda);

	if(119 == amanda.internal_error_arp)
	{
		retvalue = 119;
	}
	else if(6 == amanda.internal_error_arp)
	{
		retvalue = amanda.internal_error_arp;
	}
	else
	{
		if(ret_arp)
		{
			pedro_dprintf(-1, "error 2 7 \n");
			retvalue = 7;                         //Decompression error
		}
	}

saida:

	if(0 == retvalue)
	{
		save_position_z = _ftelli64(source);
		ret = fread(&ar, 1, sizeof(ar), source);

		if(ret != sizeof(ar))
		{
			;//pass through, just finish execution
		}
		else
		{
			_fseeki64(
				source,
				save_position_z,
				SEEK_SET
				);

			assert(save_position_z == _ftelli64(source));

			pedro_dprintf(-1, "deve voltar agora, pos in file %lld\n", save_position_z);
			//assert(0 && "Continua");
			goto init_position_z;
		}

	}

	bytes__read_thread_z[0] = totalbytes_z;

	if (source)
	{
		fclose (source);
		source = NULL;
	}

	if(dest)
	{
		fclose (dest);
		dest = NULL;
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

	return retvalue;
}

int __amandacall get_multithread_progress(void)
{
	pedro_dprintf(-1, "n_threads_z %d\n", n_threads_z);
	int ret_arp;
	switch(n_threads_z)
	{
	case 1:

		
		ret_arp = lgetpor (totalbytes_z, bytes__read_thread_z[0] );
		pedro_dprintf(-1, "Progress %d\n", ret_arp                );
		return ret_arp                                            ;
		break;
	case 2:

		return lgetpor (totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1]);

		break;
	case 3:

		return lgetpor (totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1]
		                + bytes__read_thread_z[2]
		                );

		break;
	case 4:

		return lgetpor (totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1]
		                + bytes__read_thread_z[2] + bytes__read_thread_z[3]);

		break;
	case 5:

		return lgetpor (totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1]
		                + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4]);

		break;
	case 6:

		return lgetpor (totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1]
		                + bytes__read_thread_z[2] + bytes__read_thread_z[3]   + bytes__read_thread_z[4]
		                + bytes__read_thread_z[5]);

		break;
	case 7:

		return lgetpor (totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1]
		                + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4]
		                + bytes__read_thread_z[5] + bytes__read_thread_z[6]);

		break;
	case 8:

		return lgetpor (totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1]
		                + bytes__read_thread_z[2] + bytes__read_thread_z[3]   + bytes__read_thread_z[4]
		                + bytes__read_thread_z[5] + bytes__read_thread_z[6] +  bytes__read_thread_z[7]);

		break;
	}
	return 0;
}

/**
 * Borrowed from XZ compression
 *
 *
 */
uint32_t
tuklib_cpucores_z(void)
{
	uint32_t ret = 0;
	SYSTEM_INFO sysinfo;
	GetSystemInfo(&sysinfo);
	ret = sysinfo.dwNumberOfProcessors;
	return ret;
}