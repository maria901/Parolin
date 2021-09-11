
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de C�pia (C) <2021>  <Corpora��o do Trabalho Bin�rio>         *
 *                                                                              *
 *     Este  programa  � software livre: voc� pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como       8
 *     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da       *
 *     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.         *
 *                                                                              *
 *     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de       *
 *     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P�blica para mais detalhes.                                *
 *                                                                              *
 *     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P�blica Menor junto com este programa                            *
 *     Se n�o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita r�pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                 *      
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

#include "stdio_v2.h"

#include <process.h>

bool is_multi_thread_z = false;

#include "bzlib.h"

#include "md5.h"

#include "win64.h"

#define ARP_USE_ENHANCED_STDIO

#define __amandacall __stdcall

int bzip3uncompress_sha512_k_mt_z (char *input, char *output);

extern int unicodemode;
extern int intpause;
extern int intcancel;

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

#include "bzip3_structs_z.h"

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
	maxa = ((double) 10000 / maxa * fatiaa);
	return (int) maxa;
}

int bzip3compress (char *input, char *output, int levelin)
{
	HANDLE dest = 0;
	HANDLE source = 0;
	__int64 bytesread = 0;
	__int64 totalbytes = 0;
	int done = 0;
	int level = 0;
	int ret = 0;
	int retvalue = 0;
	int writebytes = 0;
	md5_context ctx;
	rspdata rsp;
	static char buffer[CHUNK + 1];
	static char out[CHUNK + 1];
	unsigned char md5sum[16];
	bz_stream strm = { 0, };
	int action = BZ_RUN;
	
#ifdef NPRINTF

	Me and amanda will not remove these old debug informations

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
	if ((int) 0xFFFFFFFF == (int) rsp.attrib)
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

		md5_update (&ctx, (uint8 *) buffer, ret);

		bytesread = bytesread + ret;

		bzip3percent = lgetpor (totalbytes, bytesread);

		if (bytesread == totalbytes)
		{
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
			if (action == BZ_FLUSH)//never run this
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

	bzip3percent = 10000;

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
	int ret_arp;
	int64_t size_of_compressed_z = 0;
	int64_t remaining_bytes_z;
	my_thread_struct_z * ptr_my_struct_z = my_argument_z;

	if(NULL == ptr_my_struct_z)
	{
		exit(123);
	}

	assert(my_argument_z);

	bytes__read_thread_z[ptr_my_struct_z->thread_id_z] = 0x0;

	remaining_bytes_z = ptr_my_struct_z->size_of_input_file_z;

	if(NULL == ptr_my_struct_z->input_file)
	{
		ptr_my_struct_z->retvalue = 7;
		goto saida_arp;
	}

	if(NULL == ptr_my_struct_z->dest)
	{
		goto saida_arp;
	}
	
	if(NULL == ptr_my_struct_z->dest)
	{
		goto saida_arp;
	}

	if(!ptr_my_struct_z->ret_init_bzip3)
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

	pedro_dprintf(-1, "slice %lld\n", ptr_my_struct_z->size_of_input_file_z);

	veja_z += ptr_my_struct_z->size_of_input_file_z;

	pedro_dprintf(-1, "tamanho apos slices %lld\n", veja_z);

	//ta faltando aqui...
#ifdef ARP_USE_ENHANCED_STDIO
	pedro_dprintf(-1, "position before %lld\n", _ftelli64_z(ptr_my_struct_z->dest));
#else
	pedro_dprintf(-1, "position before %lld\n", _ftelli64(ptr_my_struct_z->dest));
#endif

#ifdef ARP_USE_ENHANCED_STDIO
	ptr_my_struct_z->ret = fwrite_z (&ptr_my_struct_z->ar, 1, sizeof (ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#else
	ptr_my_struct_z->ret = fwrite (&ptr_my_struct_z->ar, 1, sizeof (ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#endif

	if (sizeof (ptr_my_struct_z->ar) != ptr_my_struct_z->ret)
	{
		ptr_my_struct_z->retvalue = 114;  //unexpected error
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
		ptr_my_struct_z->retvalue = 14;  //unexpected error
		goto saida;
	}
#ifdef ARP_USE_ENHANCED_STDIO
	pedro_dprintf(-1, "position after %lld\n", _ftelli64_z(ptr_my_struct_z->dest));
#else
	pedro_dprintf(-1, "position after %lld\n", _ftelli64(ptr_my_struct_z->dest));
#endif
	
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
		ptr_my_struct_z->ret = fread (ptr_my_struct_z->buffer, 1, min(CHUNK, remaining_bytes_z), ptr_my_struct_z->input_file);
		
		if(0 > ptr_my_struct_z->ret)
		{
			ptr_my_struct_z->retvalue = 23;
			goto saida;
		}
		
		if (0 == ptr_my_struct_z->ret)
		{
			goto saida;
		}

		sha512_update_k(ptr_my_struct_z->sha51_ptr, (void *) ptr_my_struct_z->buffer, ptr_my_struct_z->ret);

		ptr_my_struct_z->bytesread = ptr_my_struct_z->bytesread + ptr_my_struct_z->ret;

		pedro_dprintf(-1, "bytes read inside %lld\n", ptr_my_struct_z->bytesread);

		bytes__read_thread_z[ptr_my_struct_z->thread_id_z] = ptr_my_struct_z->bytesread;

		remaining_bytes_z -= ptr_my_struct_z->ret;

		if (ptr_my_struct_z->bytesread == ptr_my_struct_z->size_of_input_file_z)
		{
			ptr_my_struct_z->action = BZ_FINISH; 
		}
		
		ptr_my_struct_z->strm.next_in = (void *) ptr_my_struct_z->buffer;
		ptr_my_struct_z->strm.avail_in = ptr_my_struct_z->ret;

volta:

		ptr_my_struct_z->strm.next_out = ptr_my_struct_z->out;
		ptr_my_struct_z->strm.avail_out = CHUNK;
		ptr_my_struct_z->ret = BZ2_bzCompress (&ptr_my_struct_z->strm, ptr_my_struct_z->action);

		ptr_my_struct_z->writebytes = CHUNK - ptr_my_struct_z->strm.avail_out;
		if (ptr_my_struct_z->writebytes > 0)
		{
#ifdef ARP_USE_ENHANCED_STDIO
			if (0 == (ret_arp = fwrite_z (ptr_my_struct_z->out, 1, ptr_my_struct_z->writebytes, ptr_my_struct_z->dest)))
			{
				ptr_my_struct_z->retvalue = 114; // Cannot write to output file
				goto saida;
			}
#else
			if (0 == (ret_arp = fwrite (ptr_my_struct_z->out, 1, ptr_my_struct_z->writebytes, ptr_my_struct_z->dest)))
			{
				ptr_my_struct_z->retvalue = 114; // Cannot write to output file
				goto saida;
			}
#endif
			if(ret_arp != ptr_my_struct_z->writebytes)//isto nao � redundante? duvida cruel...
			{
				ptr_my_struct_z->retvalue = 114;
				goto saida;
			}
			size_of_compressed_z += ptr_my_struct_z->writebytes;
		}

		switch (ptr_my_struct_z->ret)
		{
		case BZ_RUN_OK:
			if (ptr_my_struct_z->action == BZ_FLUSH)
			{
				ptr_my_struct_z->action = BZ_FINISH;
				goto volta;
			}
			if(0==ptr_my_struct_z->strm.avail_out)
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
			ptr_my_struct_z->done = 1;
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

	sha512_final_k(ptr_my_struct_z->sha51_ptr, ptr_my_struct_z->ar.digest_k);

	if (ptr_my_struct_z->size_of_input_file_z && (0 == ptr_my_struct_z->retvalue))
	{

		if (0 == ptr_my_struct_z->done && (0 == intcancel))
		{

			ptr_my_struct_z->retvalue = 116;

		}

	}
	
	assert (BZ_OK == BZ2_bzCompressEnd (&ptr_my_struct_z->strm));

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

			ptr_my_struct_z->retvalue = 108;

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

				ptr_my_struct_z->retvalue = 114;

			}
#ifdef ARP_USE_ENHANCED_STDIO
			ptr_my_struct_z->ret = fwrite_z (&size_of_compressed_z, 1, sizeof (size_of_compressed_z), ptr_my_struct_z->dest);
#else
			ptr_my_struct_z->ret = fwrite (&size_of_compressed_z, 1, sizeof (size_of_compressed_z), ptr_my_struct_z->dest);
#endif
			if (ptr_my_struct_z->ret != sizeof (size_of_compressed_z))
			{

				ptr_my_struct_z->retvalue = 114;

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
		ptr_my_struct_z->retvalue = 119;
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
	if(ptr_my_struct_z->buffer)
	{
		free(ptr_my_struct_z->buffer);
	}
	if(ptr_my_struct_z->out)
	{
		free(ptr_my_struct_z->out);
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
int bzip3compress_sha512_k (char *input, char *output, int levelin)
{
	
#ifdef ARP_USE_ENHANCED_STDIO
	FILE_z * temp_z    = NULL;
#else
	FILE * temp_z    = NULL;
#endif
	my_thread_struct_z * ptr_my_struct_z;
	int first_step_z                 = 0;
	int i_z                             ;
	int n_threads_copy                  ;
	int n_thread_counter                ;
	HANDLE source_handle                ;
	FILE * dest = 0                     ;
	FILE * source = 0                   ;
	__int64 bytesread = 0               ;
	__int64 totalbytes = 0              ;
	int ret_arp                         ;
	int done = 0                        ;
	int level = 0                       ;
	int ret = 0                         ;
	int ret2                            ;
	int retvalue = 0                    ;
	int writebytes = 0                  ;
	ar_data ar                          ;
	char *sha512_ptr = NULL             ;
	static char buffer       [CHUNK + 1];//why this my love?...for safety
	static char out          [CHUNK + 1];
	bz_stream strm              = { 0, };
	int action =                  BZ_RUN;
	
	int64_t slice_z                     ;
	int64_t remaining_z                 ;
	int64_t offset_z                    ;
	thread_return_value_z = 0           ;
	
#ifdef NPRINTF
	dprintf ("%s\n%s \n", input, output);
	dprintf ("Level %d \n", levelin);
#endif
	intstatus                        = 1;
	memset     (&strm, 0, sizeof (strm));
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
	pedro_dprintf(-1, "bzip3 threads %d\n", n_threads_z);

		totalbytes = lffilesize(input);
		totalbytes_z = totalbytes;

		if(1000 > totalbytes)
		{
			pedro_dprintf(-1, "below 1000 \n");
			goto single_thread_z;
		}
		is_multi_thread_z = false;

		if(1 != n_threads_z)
		{
			//aqui...
			if(0 == n_threads_z)
			{
				n_threads_z = tuklib_cpucores_z();

				if(0 == n_threads_z)
				{
					goto single_thread_z;
				}
				if(1 == n_threads_z)
				{
					goto single_thread_z;
				}
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
						thread_return_value_z = 107; //Cannot open input file = 107;
					}
				}

				ptr_my_struct_z->dest = NULL;
				if(!createtempfilename_and_keep_z(temp_path_z, temp_files_z[n_thread_counter], L"BZ3"))
				{
					if(0 == thread_return_value_z)
					{
						thread_return_value_z = 401; //cannot create temp file
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
							thread_return_value_z = 109; //cannot open output tempfile
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

				ptr_my_struct_z->buffer = calloc(1, CHUNK + 1);
				assert(ptr_my_struct_z->buffer);
				ptr_my_struct_z->out    = calloc(1, CHUNK);
				assert(ptr_my_struct_z->out);

				ptr_my_struct_z->sha51_ptr = sha512_init_k();

				memset (&ptr_my_struct_z->ar, 0, sizeof (ar_data));

				memcpy (ptr_my_struct_z->ar.string, "AR__", 4);                //aqui 2

				ptr_my_struct_z->ar.string[3] = '_' - 2;                //signature for gzip2 multi-thread

				pedro_dprintf(-1, "ai %x\n", *((int*)ptr_my_struct_z->ar.string));

				memset (&ptr_my_struct_z->strm, 0, sizeof (ptr_my_struct_z->strm));

				ptr_my_struct_z->level = level;

				ptr_my_struct_z->ret = BZ2_bzCompressInit (&ptr_my_struct_z->strm, ptr_my_struct_z->level, 4, 30);
				
				ptr_my_struct_z->ret_init_bzip3 = 1;
				if (BZ_OK != ptr_my_struct_z->ret)
				{
					ptr_my_struct_z->ret_init_bzip3 = 0;
					ptr_my_struct_z->retvalue = 120;		
				}

				if(unicodemode)
				{
					WCHAR wpmode[300] ={0,};
					utf8towide (input, wpmode, 300);
					ptr_my_struct_z->ar.attrib = GetFileAttributesW (wpmode);
				}
				else
					ptr_my_struct_z->ar.attrib = GetFileAttributes (input);

				if ((int) 0xFFFFFFFF == (int) ar.attrib)
				{
					ptr_my_struct_z->ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
				}

				source_handle = lfopen (input, "rb");

				//assert(0 != source_handle);

				GetFileTime (source_handle, // identifies the file
				&ptr_my_struct_z->ar.creation, // address of creation time
				NULL, // address of last access time
				&ptr_my_struct_z->ar.lwrite   // address of last write time
				);

				if(0 != source_handle)
				{
					lfclose(source_handle);
				}

				bytes__read_thread_z[n_thread_counter] = 0;

				ptr_my_struct_z->    action = BZ_RUN;

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
					thread_return_value_z = 108;//Cannot open output file
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
								thread_return_value_z = 402; //Cannot read from input file
							}
						}
						else if(0 == ret)
						{
							;//just go by...
						}
						else
						{

							ret2 = fwrite(buffer, 1, ret, dest);

							if(ret2 != ret)
							{
								if(0 == thread_return_value_z)
								{
									thread_return_value_z = 14; //Cannot write to output file
								}
								goto exit_loop_z;
							}

							goto volta_amanda;
						}

exit_loop_z:                                    ;
#ifndef ARP_USE_ENHANCED_STDIO
						fclose(temp_z);
#endif
					}
					else
					{
						if(0 == thread_return_value_z)
						{
							thread_return_value_z = 404; //Cannot open temp file
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
			finished = 1;//e depois return

			if(dest)
			{
				fclose(dest);
			}

			return thread_return_value_z;
		}
		//aqui...
		
	single_thread_z:;
//////////////already
	ret = BZ2_bzCompressInit (&strm, level, 4, 30);

	if (BZ_OK != ret)
	{
		retvalue = 120;
		goto saida;
	}
//////////////////////////
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
	if ((int) 0xFFFFFFFF == (int) ar.attrib)
	{
		ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
	}
		
	{
		WCHAR temp_w_k[300] = {0};
		utf8towide (input, temp_w_k, 300);
		source = _wfopen (temp_w_k, L"rb");
	}
	
	if (NULL == source)
	{

		retvalue = 107;
		goto saida;

	}

	source_handle = lfopen (input, "rb");

	//assert(0 != source_handle);

	ret = GetFileTime (source_handle, // identifies the file
	                   &ar.creation, // address of creation time
	                   NULL, // address of last access time
	                   &ar.lwrite   // address of last write time
	                   );

	if(0 != source_handle)
	{
		lfclose(source_handle);
	}

	assert (ret);
	{
		WCHAR temp_w_k[300] = {0};
		utf8towide (output, temp_w_k, 300);
		ret = SetFileAttributesW (temp_w_k, FILE_ATTRIBUTE_ARCHIVE);
		dest = _wfopen (temp_w_k, L"wb");
	}
	
	if (NULL == dest)
	{
		retvalue = 108;
		goto saida;
	}

	ret = fwrite (&ar, 1, sizeof (ar), dest);

	if (0 == ret || 0 > ret)
	{
		retvalue = 114; //Cannot write to output file
		goto saida;
	}

	for (;;)
	{

		pedro_dprintf(-1, "begin for()\n");

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

		ret = fread (buffer, 1, CHUNK, source);
		
		if(0 > ret)
		{
			retvalue = 23;
			goto saida;
		}
		
		if (0 == ret)
		{
			goto saida;
		}

		pedro_dprintf(-1, "fread, bytes %d\n", ret);

		sha512_update_k(sha512_ptr, (unsigned char *) buffer, ret);

		bytesread = bytesread + ret;

		bzip3percent = lgetpor (totalbytes, bytesread);

		if (bytesread == totalbytes)
		{
			pedro_dprintf(-1, "setting action = BZ_FINISH\n");
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
			if (0 == (ret_arp = fwrite (out, 1, writebytes, dest)))
			{
				retvalue = 114; // Cannot write to output file
				goto saida;
			}
			if(ret_arp != writebytes)//isto nao � redundante? duvida cruel...
			{
				retvalue = 114;
				goto saida;
			}
		}

		switch (ret)
		{
		case BZ_RUN_OK:
		
		pedro_dprintf(-1, "BZ_RUN_OK \n");

			if (action == BZ_FLUSH)
			{
				pedro_dprintf(-1, "inside BZ_RUN_OK setting action to BZ_FINISH\n");
				action = BZ_FINISH;
				goto volta;
			}
			if(0==strm.avail_out)
			{
				pedro_dprintf(-1, "inside BZ_RUN_OK going to volta because 0==strm.avail_out\n");
				goto volta;
			}

			break;
		case BZ_FLUSH_OK:
			pedro_dprintf(-1, "inside BZ_FLUSH_OK going to volta\n");
			goto volta;
			break;
		case BZ_FINISH_OK:
			pedro_dprintf(-1, "inside BZ_FINISH_OK going to volta\n");
			goto volta;
			break;
		case BZ_STREAM_END:
			done = 1;
			pedro_dprintf(-1, "inside BZ_STREAM_END going to saida\n");
			goto saida;
			break;
		case BZ_SEQUENCE_ERROR:
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
			retvalue = 116; //Unexpected error
		}
	}

	bzip3percent = 10000;

	if (source)
	{
		fclose (source);
		source = NULL;
	}

	if (dest)
	{
		fclose (dest);
		dest = NULL;
	}

	if (0 == retvalue)
	{
		{
			WCHAR temp_w_k[300] = {0};
			utf8towide (output, temp_w_k, 300);			
			dest = _wfopen (temp_w_k, L"rb+");
		}
		
		if (NULL == dest)
		{
			retvalue = 108;
		}
		else
		{
			ret = fwrite (&ar, 1, sizeof (ar), dest);
			if (ret != sizeof (ar))
			{
				retvalue = 114;
			}
		}
	}

	if (dest)
	{
		fclose (dest);
		dest = NULL;
	}

	if (intcancel)
	{
		retvalue = 119;//user cancel
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
	
	return retvalue;
}

int bzip3uncompress (char *input, char *output)
{
	char signature_z[5] = "AR__";
	HANDLE dest = 0;
	HANDLE source = 0;
	__int64 bytesread = 0;
	__int64 totalbytes = 0;
	int ret_arp;
	int a;
	int b;
	int c;
	int d;
	int done = 0;
	int ret = 0;
	int retvalue = 0;
	int writebytes = 0;
	md5_context ctx;
	rspdata rsp;
	int is_sha512_file_k = 0;
	static char buffer[CHUNK + 1];
	static char out[CHUNK + 1];
	unsigned char md5sum[16];
	bz_stream strm = { 0, };
	intstatus = 1;
	memset (&strm, 0, sizeof (strm));
	ret = BZ2_bzDecompressInit (&strm, 0, 0);
	if (BZ_OK != ret)
	{
		retvalue = 121;// Cannot init decompression
		goto saida;
	}
	
	signature_z[3] = '_' - 2;
	
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

		pedro_dprintf(-1, "arquivo nao � RSPB");
		if (0 == memcmp (rsp.string, "AR_2", 4))
		{
			is_sha512_file_k = 1;
			goto saida;
		}

		if (0 == memcmp (rsp.string, signature_z, 4))
		{
			is_sha512_file_k = 2;
			goto saida;
		}
		
		retvalue = 199;
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
			md5_update (&ctx, (unsigned char *) out, writebytes);
			if (0 == (ret_arp = lfwrite (out, writebytes, dest)))
			{
				retvalue = 14; //Cannot write to output file
				goto saida;
			}
			if(ret_arp != writebytes)
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

			retvalue = 198;
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
			dprintf ("garanta que done � setafdo \n");
#endif
			if ((0 == done) && (0 == retvalue))
			{
				retvalue = 124;
			}
		}
	}
	bzip3percent = 10000;

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

	//intstatus = 0;

	assert (BZ_OK == BZ2_bzDecompressEnd (&strm));

	if(1 == is_sha512_file_k)
		return bzip3uncompress_sha512_k (input, output);
	
	if(2 == is_sha512_file_k)
		return bzip3uncompress_sha512_k_mt_z (input, output);

	return retvalue;
}

int bzip3uncompress_sha512_k (char *input, char *output)
{

	HANDLE dest = 0;
	HANDLE source = 0;
	__int64 bytesread = 0;
	__int64 totalbytes = 0;
	int ret_arp;
	int done = 0;
	int ret = 0;
	int retvalue = 0;
	int writebytes = 0;
	char * sha512_ptr = NULL;
	ar_data ar = {0};
	static char buffer[CHUNK + 1];
	static char out[CHUNK + 1];
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
		retvalue = 199;
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
			sha512_update_k(sha512_ptr, (unsigned char *) out, writebytes);
			if (0 == (ret_arp = lfwrite (out, writebytes, dest)))
			{
				retvalue = 14;
				goto saida;
			}
			if(ret_arp != writebytes)
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
			retvalue = 198;
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
		dprintf ("garanta que done � setafdo \n");
#endif
		if ((0 == done) && (0 == retvalue))
		{
			retvalue = 124;
		}

	}

	bzip3percent = 10000;

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

#include "bzip3_decoder_mt_z.c"

int bzip3uncompress_sha512_k_mt_z (char *input, char *output)
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
	
//aqui...

	FILE * dest                    = 0;
	FILE * source                  = 0;
	
	bool first_pass_z          = false;
	__int64 bytesread              = 0;
	
	init_position_z:;
	int64_t save_position_z           ;
	HANDLE dest_2 = NULL              ;
	int64_t remaining_z               ;
	char signature_z[5]       = "AR__";
	__int64 totalbytes             = 0;
	int ret_arp                       ;
	int done                       = 0;
	int ret                        = 0;
	int retvalue                   = 0;
	int writebytes                 = 0;
	char * sha512_ptr           = NULL;
	ar_data ar                   = {0};
	static char buffer     [CHUNK + 1];
	static char out        [CHUNK + 1];
	bz_stream strm            = { 0, };
	intstatus                      = 1;
	memset (&strm, 0,   sizeof (strm));
	ret = BZ2_bzDecompressInit (&strm, 0, 0);
	if (BZ_OK != ret)
	{
		retvalue = 121;
		goto saida;
	}
	
	////exit(27);
	
	intpause                            =      0;
	intcancel                           =      0;
	sha512_ptr                 = sha512_init_k();
	bzip3percent                        =      0;
	totalbytes              = lffilesize (input);
	
	if(!first_pass_z)
	{
		{
			WCHAR wpmode[300]             = {0,};
			utf8towide (input, wpmode,      300);
			source = _wfopen (wpmode,     L"rb");
		}
		
		if (NULL == source)
		{
			retvalue = 107;
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
		retvalue = 122;
		goto saida;
	}

	signature_z[3] = '_' - 2;

	if (0 != memcmp (ar.string, signature_z, 4))
	{
		retvalue = 199;
		goto saida;
	}
	
	ret = fread (&remaining_z, 1, sizeof (remaining_z), source);

	if (sizeof (remaining_z) != ret)
	{
		retvalue = 122;
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
			retvalue = 108;
			goto saida;
		}		
		first_pass_z = true;
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

		ret = fread (buffer, 1, min(CHUNK, remaining_z), source);

		if(0 > ret)
		{
			retvalue = 122;
			goto saida;			
		}

		if ((0 == ret) || done)
		{
			goto saida;
		}
		
		remaining_z -= ret;
		
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
			sha512_update_k(sha512_ptr, (unsigned char *) out, writebytes);
			if (0 == (ret_arp = fwrite (out, 1, writebytes, dest)))
			{
				retvalue = 14;
				goto saida;
			}
			if(ret_arp != writebytes)
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
			retvalue = 198;
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
		dprintf ("garanta que done � setafdo \n");
#endif
		if ((0 == done) && (0 == retvalue))
		{
			retvalue = 124;
		}

	}

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

	bzip3percent = 10000;

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
		
	dest_2 = lfopen(output,"zb");//to allow to write to it without deleting the contents	
	
	ret =  SetFileTime (dest_2, // identifies the file
						&ar.creation, // time the file was created
						NULL, // time the file was last accessed
						&ar.lwrite   // time the file was last written
						);
						
	assert(0 != ret);
	if(0 != dest_2)
	lfclose(dest_2);
	
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

int __amandacall get_multithread_progress(void)
{
	switch(n_threads_z)
	{
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