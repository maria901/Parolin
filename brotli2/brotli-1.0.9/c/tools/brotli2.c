/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*                                                                             *
*        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>        *
*                                                                             *
*     Este  programa  é software livre: você pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     10
*     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opção) qualquer versão posterior.        *
*                                                                             *
*     Este  programa é distribuído na  esperança que isto vai  ser útil,      *
*     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de      *
*     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Pública para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Pública Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito rápida) WhatsApp               *
*     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort unsigned short
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
int64_t max_memory_size_k__p;
//#include "minilzo.h"

//#include "lz5.h"

#include "win64.h"

#define __amandacall __stdcall

int lz5uncompress_k_mt_z(char *input, char *output);

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

#define AMANDA__SIZE_ww ((32767 * 2) + 2)

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

wchar_t *
permissive_name_m_v28(const wchar_t *wname, WCHAR *ar_temp);
wchar_t *
remove_permissive_name_m_(wchar_t *wname, WCHAR *ar_temp);
WCHAR *amanda_utf8towide_1_v28(char *pUTF8, WCHAR *ar_temp);
char *valquiria_wide_to_utf8(WCHAR *pUSC2_maria, char *ar_temp_char);

wchar_t *
remove_permissive_name_m_(wchar_t *wname, WCHAR *ar_temp);

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we 
 *  . provide two functions that are exactly the same because someone may 
 * use it in multi-thread code 
 *
 * @param pUTF8 the input utf-8 encoded filename 
 *
 * @return the static allocated WCHAR array with the filename as wide string 
 *
 */
WCHAR *amanda_utf8towide_1_v27_no_oct(char *pUTF8);

char *valquiria_wide_to_utf8(WCHAR *pUSC2_maria, char *ar_temp_char)
{
     char *saida_utf8 = ar_temp_char;

     WideCharToMultiByte(CP_UTF8, 0, pUSC2_maria, -1, (LPSTR)saida_utf8, AMANDA__SIZE, 0, 0);
     return saida_utf8;
}

extern int unicodemode;
extern int intpause;
extern int intcancel;

void pedro_dprintf(int amanda_level,
                   char *format, ...);

int lz5uncompress_k(char *input, char *output);

uint32_t
tuklib_cpucores_z(void);

extern char temp_path_z[];

FILE *fopen_utf8_z(char *filename_z, char *mode);

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

void mprintf(char *format, ...);

extern void __cdecl mprintf(char *format, ...);

uint getpor(int max, uint fatia);

void dprintf(char *format, ...);
int __stdcall execute();
int start();
int start2();

HANDLE lfopen(const char *szFileName, char *pMode);
void lfclose(HANDLE hFile);
__int64 lfseek(HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell(HANDLE hFile);
__int64 lffilesize(const char *szFileName);
unsigned long lfread(void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite(void *pBuffer, unsigned long ulCount, HANDLE hFile);
int setendofile(HANDLE file, __int64 position);

static int lgetpor(__int64 max, __int64 fatia);

#define CHUNK (32768 * 2 * 2) /* it is a good slice of data */

int lzop2percent = 0;

static int lgetpor(__int64 max, __int64 fatia)
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
     maxa = ((double)10000 / maxa * fatiaa);
     return (int)maxa;
}

int createtempfilename_and_keep_z(char *path1, char *out_z, WCHAR *signature_z)
{

     int ret;

     char *path = malloc(AMANDA__SIZE);

     strcpy(path, path1);

     //removedordeespaconofinal (path);

     ret = strlen(path);

     if (path[ret - 1] != '\\')
     {
          path[ret] = '\\';
          path[ret + 1] = 0;
     }
     {
          WCHAR *fixo_w_ar = malloc(AMANDA__SIZE_ww);
          WCHAR *path_w_ar = malloc(AMANDA__SIZE_ww);

          WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
          WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

          wcscpy(path_w_ar, permissive_name_m_v28(amanda_utf8towide_1_v28((void *)path, ar_temp), ar_temp2));
          ret = GetTempFileNameW(path_w_ar, signature_z, 0, fixo_w_ar);

          if (ret == 0)
          {
               free(fixo_w_ar);
               free(path_w_ar);
               free(ar_temp);
               free(ar_temp2);
               free(path);
               return 0;
          }
          else
          {
               char *ar_temp3 = (void *)malloc(AMANDA__SIZE_ww);
               strcpy(out_z, valquiria_wide_to_utf8(remove_permissive_name_m_(fixo_w_ar, ar_temp), ar_temp3));
               free(path);
               free(ar_temp);
               free(ar_temp2);
               free(ar_temp3);
               free(fixo_w_ar);
               free(path_w_ar);
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

     char *buf_z = malloc(CHUNK);
     FILE *f_stream_z = NULL;
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

          if (0 >= len) //inverted to really learn
          {
               break;
          }

          crc = rsp32(crc, (uchar *)buf_z, len);
     }

     fclose(f_stream_z);
     free(buf_z);
     return crc;
}

#ifdef ARP_USE_ENHANCED_STDIO
FILE_z *files_to_close_z[129];
#endif
int64_t totalbytes_z;
int64_t bytes__read_thread_z[129];
int64_t offset_z__[129];
int64_t size_of_input_file_z__[129];
__INT32_OR_INT64 my_thread_handle[129];
char temp_files_z[129][2048];
int thread_return_value_z;

int64_t veja_z = 0;

//amanda 2
unsigned __stdcall my_thread_function(void *my_argument_z)
{
     compressResult_t return_amanda = {1, 0, 0};
     int64_t size_of_compressed_z = 0;

     my_thread_struct_z *ptr_my_struct_z = my_argument_z;

     if (NULL == ptr_my_struct_z)
     {
          exit(123);
     }

     assert(my_argument_z);

     bytes__read_thread_z[ptr_my_struct_z->thread_id_z] = 0x0;

     if (NULL == ptr_my_struct_z->input_file)
     {
          ptr_my_struct_z->retvalue = 1;
          goto saida_arp;
     }

     if (NULL == ptr_my_struct_z->dest)
     {
          goto saida_arp;
     }

     pedro_dprintf(-1, "my thread running %x \n", my_argument_z);

     pedro_dprintf(-1, "offset %lld\n", ptr_my_struct_z->offset_z);

     if (0 != ptr_my_struct_z->offset_z)
     {
          if (
              0 != _fseeki64(
                       ptr_my_struct_z->input_file,
                       ptr_my_struct_z->offset_z,
                       SEEK_SET))
          {
               ptr_my_struct_z->retvalue = 403; //File access error
               goto saida;
          }
     }

     pedro_dprintf(-1, "slice %lld\n", ptr_my_struct_z->size_of_input_file_z);
     ptr_my_struct_z->size_of_input_file_copy_z = ptr_my_struct_z->size_of_input_file_z;
     veja_z += ptr_my_struct_z->size_of_input_file_z;

     pedro_dprintf(-1, "tamanho apos slices %lld\n", veja_z);

     if (ptr_my_struct_z->dest)
     {
          pedro_dprintf(-1, "fechando dest\n");
#ifdef ARP_USE_ENHANCED_STDIO
          fclose_z(ptr_my_struct_z->dest);
#else
          fclose(ptr_my_struct_z->dest);
          ptr_my_struct_z->dest = NULL;
#endif
     }

#ifdef ARP_USE_ENHANCED_STDIO
     ptr_my_struct_z->ret = fwrite_z(&ptr_my_struct_z->ar, 1, sizeof(ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#else
     ptr_my_struct_z->ret = fwrite(&ptr_my_struct_z->ar, 1, sizeof(ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#endif

     if (sizeof(ptr_my_struct_z->ar) != ptr_my_struct_z->ret)
     {
          ptr_my_struct_z->retvalue = 400; //Cannot write to temporary file
          goto saida;
     }
     //deu...
#ifdef ARP_USE_ENHANCED_STDIO
     ptr_my_struct_z->ret = fwrite_z(&size_of_compressed_z, 1, sizeof(size_of_compressed_z), ptr_my_struct_z->dest);
#else
     ptr_my_struct_z->ret = fwrite(&size_of_compressed_z, 1, sizeof(size_of_compressed_z), ptr_my_struct_z->dest);
#endif
     if (sizeof(size_of_compressed_z) != ptr_my_struct_z->ret)
     {
          ptr_my_struct_z->retvalue = 400; //Cannot write to temporary file
          goto saida;
     }

     //aqui vai o codigo

     intpause = 0;
     intcancel = 0;

     ptr_my_struct_z->intpause = &intpause;
     ptr_my_struct_z->intcancel = &intcancel;

     ptr_my_struct_z->size_of_destination_file_z = 0;
     ptr_my_struct_z->bytes_read_z = &bytes__read_thread_z[ptr_my_struct_z->thread_id_z];
     /*
	pedro_dprintf(-1, "aqui in ptr_my_struct_z->size_of_input_file_copy_z == %lld\n", ptr_my_struct_z->size_of_input_file_copy_z);
	*/
     return_amanda = compress_file(ptr_my_struct_z->input_file, ptr_my_struct_z->dest, ptr_my_struct_z);
     size_of_compressed_z = ptr_my_struct_z->size_of_destination_file_z;
     if (119 == ptr_my_struct_z->internal_error_arp)
     {
          ptr_my_struct_z->retvalue = ptr_my_struct_z->internal_error_arp;
     }
     else if (6 == ptr_my_struct_z->internal_error_arp)
     {
          ptr_my_struct_z->retvalue = ptr_my_struct_z->internal_error_arp;
     }
     else
     {

          if (return_amanda.error)
          {
               ptr_my_struct_z->retvalue = 8; //Compression error
          }
     }
saida:

     if (0 == ptr_my_struct_z->retvalue)
     {
          if (unicodemode)
          {
               max_memory_size_k__p = 200000000 / n_threads_z;
#ifdef ARP_USE_ENHANCED_STDIO
               WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
               WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

               ptr_my_struct_z->dest = _wfopen_z(permissive_name_m_v28(amanda_utf8towide_1_v28(temp_files_z[ptr_my_struct_z->thread_id_z], ar_temp), ar_temp2), "rb+", max_memory_size_k__p, __FILE__, __LINE__, ptr_my_struct_z->dest);

               free(ar_temp);
               free(ar_temp2);
#else
               ptr_my_struct_z->dest = _wfopen(wpmode, L"rb+");
#endif
          }

          if (0 == ptr_my_struct_z->dest)
          {

               ptr_my_struct_z->retvalue = 405;
          }
          else
          {
#ifdef ARP_USE_ENHANCED_STDIO
               ptr_my_struct_z->ret = fwrite_z(&ptr_my_struct_z->ar, 1, sizeof(ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#else
               ptr_my_struct_z->ret = fwrite(&ptr_my_struct_z->ar, 1, sizeof(ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#endif
               if (ptr_my_struct_z->ret != sizeof(ptr_my_struct_z->ar))
               {

                    ptr_my_struct_z->retvalue = 400;
               }
#ifdef ARP_USE_ENHANCED_STDIO
               ptr_my_struct_z->ret = fwrite_z(&size_of_compressed_z, 1, sizeof(size_of_compressed_z), ptr_my_struct_z->dest);
#else
               ptr_my_struct_z->ret = fwrite(&size_of_compressed_z, 1, sizeof(size_of_compressed_z), ptr_my_struct_z->dest);
#endif
               if (ptr_my_struct_z->ret != sizeof(size_of_compressed_z))
               {

                    ptr_my_struct_z->retvalue = 400;
               }
          }
     }

     if (ptr_my_struct_z->dest)
     {
#ifndef ARP_USE_ENHANCED_STDIO
          fclose(ptr_my_struct_z->dest);
          ptr_my_struct_z->dest = NULL;
#endif
     }

     if (intcancel)
     {
          ptr_my_struct_z->retvalue = 119; //User abort
     }

saida_arp:;

     if (ptr_my_struct_z->dest)
     {
          pedro_dprintf(-1, "fechando dest\n");
#ifndef ARP_USE_ENHANCED_STDIO
          fclose(ptr_my_struct_z->dest);
#endif
     }
     if (ptr_my_struct_z->input_file)
     {
          fclose(ptr_my_struct_z->input_file);
     }

     if (0 == thread_return_value_z)
     {
          thread_return_value_z = ptr_my_struct_z->retvalue;
     }

     free(my_argument_z);
     _endthreadex(0);

     return 0;
}

//amanda 1
int lz5compress_k(char *input,
                  char *output, //the output value...
                  int levelin)  //level not in use
{

     static char buffer[CHUNK];
     FILE_z *temp_z = NULL;
     FILE *dest = NULL;
     int ret;
     int ret2;
     int64_t offset_z;
     int64_t remaining_z;
     int64_t slice_z;
     int first_step_z = 0;
     my_thread_struct_z *ptr_my_struct_z;
     int n_thread_counter;
     int n_threads_copy;
     int i_z;
     int64_t totalbytes;
     int level;
     thread_return_value_z = 0;

     intpause = 0;
     intcancel = 0;
     level = levelin;

     if (levelin <= 0)
     {
          level = 0;
     }

     if (levelin > 9)
     {
          level = 9;
     }

     pedro_dprintf(-1, "level amor brotli2 %d\n", level);

     veja_z = 0;

     totalbytes = lffilesize(input);
     totalbytes_z = totalbytes;

     is_multi_thread_z = true; //hack...

     if (1) //hack...
     {
          //aqui...
          if (0 == n_threads_z)
          {
               n_threads_z = tuklib_cpucores_z();

               if (0 == n_threads_z)
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

          if (128 < n_threads_z)
          {
               n_threads_z = 128;
          }

          for (i_z = 0; i_z < n_threads_z; i_z++)
          {
               bytes__read_thread_z[i_z] = 0;
          }

          is_multi_thread_z = true;

          //aqui , usa padding bytes com numero nao multiplo de 4

          //novo signature 0x5e5f5241

          n_threads_copy = n_threads_z;
          n_thread_counter = 0;
          while (n_threads_copy--)
          {
               ptr_my_struct_z = calloc(1, sizeof(my_thread_struct_z));
               assert(ptr_my_struct_z);
               pedro_dprintf(-1, "alocou\n");

               ptr_my_struct_z->thread_id_z = n_thread_counter;

               //ptr_my_struct_z->
               pedro_dprintf(-1, "temp path %s\n", temp_path_z);

               if (true)
               {
                    WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                    WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                    ptr_my_struct_z->input_file = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2), L"rb");

                    free(ar_temp);
                    free(ar_temp2);
               }

               if (NULL == ptr_my_struct_z->input_file)
               {
                    if (0 == thread_return_value_z)
                    {
                         thread_return_value_z = 1; //Cannot open input file = 107;
                    }
               }

               ptr_my_struct_z->dest = NULL;
               if (!createtempfilename_and_keep_z(temp_path_z, temp_files_z[n_thread_counter], L"BR2"))
               {
                    if (0 == thread_return_value_z)
                    {
                         thread_return_value_z = 407; //Cannot create temp file
                    }
               }
               else
               {
                    if (unicodemode)
                    {
                         max_memory_size_k__p = 200000000 / n_threads_z;
#ifdef ARP_USE_ENHANCED_STDIO
                         WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                         WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                         ptr_my_struct_z->dest = _wfopen_z(permissive_name_m_v28(amanda_utf8towide_1_v28(temp_files_z[n_thread_counter], ar_temp), ar_temp2), "wb", max_memory_size_k__p, __FILE__, __LINE__, NULL);
                         files_to_close_z[n_thread_counter] = ptr_my_struct_z->dest;

                         free(ar_temp);
                         free(ar_temp2);

#else
                         ptr_my_struct_z->dest = _wfopen(wpmode, L"wb");
#endif
                    }
                    else
                    {
                         max_memory_size_k__p = 200000000 / n_threads_z;
#ifdef ARP_USE_ENHANCED_STDIO
                         ptr_my_struct_z->dest = fopen_z(temp_files_z[n_thread_counter], "wb", max_memory_size_k__p, __FILE__, __LINE__, NULL);
                         files_to_close_z[n_thread_counter] = ptr_my_struct_z->dest;
#else

                         ptr_my_struct_z->dest = fopen(temp_files_z[n_thread_counter], "wb");
#endif
                    }

                    if (NULL == ptr_my_struct_z->dest)
                    {
                         if (0 == thread_return_value_z)
                         {
                              thread_return_value_z = 405; //Cannot open output tempfile
                         }
                    }
               }

               if (0 == first_step_z)
               {
                    pedro_dprintf(-1, "tamanho %lld\n", totalbytes);
                    slice_z = totalbytes / n_threads_z;
                    remaining_z = totalbytes;
                    offset_z = 0;
                    for (i_z = 0; i_z < n_threads_z; i_z++)
                    {
                         if (i_z == (n_threads_z - 1))
                         {
                              offset_z__[i_z] = offset_z;
                              size_of_input_file_z__[i_z] = remaining_z;
                         }
                         else
                         {
                              offset_z__[i_z] = offset_z;
                              size_of_input_file_z__[i_z] = slice_z;
                              offset_z += slice_z;
                              remaining_z -= slice_z;
                         }
                    }
                    first_step_z = 1;
               }

               ptr_my_struct_z->offset_z = offset_z__[n_thread_counter];
               ptr_my_struct_z->size_of_input_file_z = size_of_input_file_z__[n_thread_counter];

               //init...

               memset(&ptr_my_struct_z->ar, 0, sizeof(ar_data));

               memcpy(ptr_my_struct_z->ar.string, "AR__", 4); //aqui 2

               ptr_my_struct_z->ar.string[3] = '_' - 10; //signature for lz5 multi-thread

               pedro_dprintf(-1, "ai %x\n", *((int *)ptr_my_struct_z->ar.string));

               ptr_my_struct_z->level = level;

               if (true)
               {
                    WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                    WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                    ptr_my_struct_z->ar.attrib = GetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2));

                    free(ar_temp);
                    free(ar_temp2);
               }

               if ((int)0xFFFFFFFF == (int)ptr_my_struct_z->ar.attrib)
               {
                    ptr_my_struct_z->ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
               }

               bytes__read_thread_z[n_thread_counter] = 0;

               //ptr_my_struct_z->/* pure fun */ action = LZOP_RUN;

               my_thread_handle[n_thread_counter] = (__INT32_OR_INT64)_beginthreadex(NULL, 0, my_thread_function, ptr_my_struct_z, 0, NULL);

               n_thread_counter++;
          }

          for (i_z = 0; i_z < n_threads_z; i_z++)
          {
               WaitForSingleObject((void *)my_thread_handle[i_z], INFINITE);
               CloseHandle((void *)my_thread_handle[i_z]);
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

          if (true)
          {
               WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
               WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

               ret = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);

               free(ar_temp);
               free(ar_temp2);
          }

          //abrir arquivo

          if (true)
          {
               WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
               WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

               dest = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), L"wb");

               free(ar_temp);
               free(ar_temp2);
          }

          if (NULL == dest)
          {
               if (0 == thread_return_value_z)
               {
                    thread_return_value_z = 2; //Cannot open output file
               }
          }

          //depois de finalizar
          for (i_z = 0; i_z < n_threads_z; i_z++)
          {
               pedro_dprintf(-1, "arquivo temp a del %s\n", temp_files_z[i_z]);
               if (dest)
               {

                    if (true)
                    {
                         max_memory_size_k__p = 200000000 / n_threads_z;
#ifdef ARP_USE_ENHANCED_STDIO
                         WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                         WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                         temp_z = _wfopen_z(permissive_name_m_v28(amanda_utf8towide_1_v28(temp_files_z[i_z], ar_temp), ar_temp2), "rb", max_memory_size_k__p, __FILE__, __LINE__, files_to_close_z[i_z]);

                         free(ar_temp);
                         free(ar_temp2);
#else
                         temp_z = _wfopen(wpmode, L"rb");
#endif
                    }

                    if (temp_z)
                    {
                         //Mr. Do

                    volta_amanda:;
#ifdef ARP_USE_ENHANCED_STDIO
                         ret = fread_z(buffer, 1, CHUNK, temp_z);
#else
                         ret = fread(buffer, 1, CHUNK, temp_z);
#endif
                         if (0 > ret)
                         {
                              if (0 == thread_return_value_z)
                              {
                                   thread_return_value_z = 5; //Cannot read from input file
                              }
                         }
                         else if (0 == ret)
                         {
                              ; //just go by...
                         }
                         else
                         {

                              ret2 = fwrite(buffer, 1, ret, dest);

                              if (ret2 != ret)
                              {
                                   if (0 == thread_return_value_z)
                                   {
                                        thread_return_value_z = 6; //Cannot write to output file
                                   }
                                   goto exit_loop_z;
                              }

                              goto volta_amanda;
                         }

                    exit_loop_z:;
#ifndef ARP_USE_ENHANCED_STDIO
                         fclose(temp_z);
#endif
                    }
                    else
                    {
                         if (0 == thread_return_value_z)
                         {
                              thread_return_value_z = 405; //Cannot open temp file
                         }
                    }
               }
#ifndef ARP_USE_ENHANCED_STDIO
               _wunlink(amanda_utf8towide_1_v27(temp_files_z[i_z]));
#endif
          }

#ifdef ARP_USE_ENHANCED_STDIO
          for (i_z = 0; i_z < n_threads_z; i_z++)
          {
               free_z(files_to_close_z[i_z]);

               WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
               WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

               _wunlink(permissive_name_m_v28(amanda_utf8towide_1_v28(temp_files_z[i_z], ar_temp), ar_temp2));

               free(ar_temp);
               free(ar_temp2);
          }
#endif

          if (0 == thread_return_value_z)
          {
               pedro_dprintf(-1, "%lld %lld\n", veja_z, totalbytes);
               assert(veja_z == totalbytes);
          }

          //precisa setar isto antes de retornar
          finished = 1; //e depois return

          if (dest)
          {
               fclose(dest);
          }
          intstatus = 0;
          return thread_return_value_z;
     }
     intstatus = 0;
     return 0;
}

int lz5uncompress(char *input, char *output)
{
     return lz5uncompress_k_mt_z(input, output);
}

#include "brotli2_decoder_mt_z.c"

int lz5uncompress_k_mt_z(char *input, char *output)
{
     pedro_dprintf(-1, "dentro de decoder multi-thread\n");
     if (1 != n_threads_z)
     {
          if (0 == n_threads_z)
          {
               n_threads_z = tuklib_cpucores_z();

               if (1 == n_threads_z)
               {
                    goto single_thread_amanda;
               }
          }
          return compress2_uncompress_k_real_mt_z(input, output);
     }

single_thread_amanda:;

     pedro_dprintf(-1, "decoder single thread in multi-thread mode\n");

     FILE *dest = 0;
     FILE *source = 0;
     bool first_pass_z = false;
     __int64 bytesread = 0;
     __int64 totalbytes = 0;
     bytes__read_thread_z[0] = 0x0;
     totalbytes = lffilesize(input);
     totalbytes_z = totalbytes;

     my_thread_struct_z amanda = {
         0,
     };

     amanda.bytes_read_z = &bytes__read_thread_z[0];

     if (NULL == amanda.bytes_read_z)
     {
          exit(27);
          return 0;
     }

     n_threads_z = 1;

init_position_z:;
     int ret_arp;
     int64_t save_position_z;
     int64_t remaining_z;
     char signature_z[5] = "AR__";

     int ret = 0;
     int retvalue = 0;

     ar_data ar = {0};

     intstatus = 1;

     ////exit(27);

     intpause = 0;
     intcancel = 0;

     amanda.intpause = &intpause;
     amanda.intcancel = &intcancel;
     if (-1 == totalbytes || -1 == bytesread)
     {
          return 0;
     }

     if (!first_pass_z)
     {
          WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
          WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

          source = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2), L"rb");

          free(ar_temp);
          free(ar_temp2);

          if (NULL == source)
          {
               retvalue = 1;
               goto saida;
          }
     }
     {
          WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
          WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

          ret = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);

          free(ar_temp);
          free(ar_temp2);
     }
     memset(&ar, 0, sizeof(ar));
     ret = fread(&ar, 1, sizeof(ar), source);

     if (ret != sizeof(ar))
     {
          retvalue = 5;
          goto saida;
     }

     signature_z[3] = '_' - 10; //brotli2 multi-thread

     if (0 != memcmp(ar.string, signature_z, 4))
     {
          pedro_dprintf(-1, "erro 7\n");
          retvalue = 7;
          goto saida;
     }

     ret = fread(&remaining_z, 1, sizeof(remaining_z), source);

     if (sizeof(remaining_z) != ret)
     {
          retvalue = 5;
          goto saida;
     }

     if (!first_pass_z)
     {
          {
               WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
               WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

               dest = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), L"wb");

               free(ar_temp);
               free(ar_temp2);
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

     if (119 == amanda.internal_error_arp)
     {
          retvalue = 119;
     }
     else if (6 == amanda.internal_error_arp)
     {
          retvalue = amanda.internal_error_arp;
     }
     else
     {
          if (ret_arp)
          {
               pedro_dprintf(-1, "error 2 7 \n");
               retvalue = 7; //Decompression error
          }
     }

saida:

     if (0 == retvalue)
     {
          save_position_z = _ftelli64(source);
          ret = fread(&ar, 1, sizeof(ar), source);

          if (ret != sizeof(ar))
          {
               ; //pass through, just finish execution
          }
          else
          {
               _fseeki64(
                   source,
                   save_position_z,
                   SEEK_SET);

               assert(save_position_z == _ftelli64(source));

               pedro_dprintf(-1, "deve voltar agora, pos in file %lld\n", save_position_z);
               //assert(0 && "Continua");
               goto init_position_z;
          }
     }

     bytes__read_thread_z[0] = totalbytes_z;

     if (source)
     {
          fclose(source);
          source = NULL;
     }

     if (dest)
     {
          fclose(dest);
          dest = NULL;
     }

     if (intcancel)
     {
          retvalue = 119;
     }

     if (0 == retvalue)
     {
          WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
          WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

          ret = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), ar.attrib);

          free(ar_temp);
          free(ar_temp2);
     }

#ifdef NPRINTF
     dprintf("retvalue=%d \n", retvalue);
#endif
     finished = 1;
     intstatus = 0;

     return retvalue;
}

int __amandacall get_multithread_progress(void)
{
     pedro_dprintf(-1, "n_threads_z %d\n", n_threads_z);
     int ret_arp;
     switch (n_threads_z)
     {
     case 1:
          ret_arp = lgetpor(totalbytes_z, bytes__read_thread_z[0]);
          pedro_dprintf(-1, "Progress %d\n", ret_arp);
          return ret_arp;
          break;
     case 2:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + 0);

          break;

     case 3:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + 0);

          break;

     case 4:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + 0);

          break;

     case 5:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + 0);

          break;

     case 6:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + 0);

          break;

     case 7:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + 0);

          break;

     case 8:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + 0);

          break;

     case 9:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + 0);

          break;

     case 10:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + 0);

          break;

     case 11:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + 0);

          break;

     case 12:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + 0);

          break;

     case 13:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + 0);

          break;

     case 14:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + 0);

          break;

     case 15:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + 0);

          break;

     case 16:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + 0);

          break;

     case 17:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + 0);

          break;

     case 18:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + 0);

          break;

     case 19:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + 0);

          break;

     case 20:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + 0);

          break;

     case 21:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + 0);

          break;

     case 22:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + 0);

          break;

     case 23:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + 0);

          break;

     case 24:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + 0);

          break;

     case 25:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + 0);

          break;

     case 26:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + 0);

          break;

     case 27:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + 0);

          break;

     case 28:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + 0);

          break;

     case 29:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + 0);

          break;

     case 30:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + 0);

          break;

     case 31:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + 0);

          break;

     case 32:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + 0);

          break;

     case 33:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + 0);

          break;

     case 34:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + 0);

          break;

     case 35:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + 0);

          break;

     case 36:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + 0);

          break;

     case 37:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + 0);

          break;

     case 38:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + 0);

          break;

     case 39:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + 0);

          break;

     case 40:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + 0);

          break;

     case 41:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + 0);

          break;

     case 42:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + 0);

          break;

     case 43:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + 0);

          break;

     case 44:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + 0);

          break;

     case 45:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + 0);

          break;

     case 46:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + 0);

          break;

     case 47:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + 0);

          break;

     case 48:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + 0);

          break;

     case 49:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + 0);

          break;

     case 50:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + 0);

          break;

     case 51:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + 0);

          break;

     case 52:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + 0);

          break;

     case 53:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + 0);

          break;

     case 54:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + 0);

          break;

     case 55:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + 0);

          break;

     case 56:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + 0);

          break;

     case 57:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + 0);

          break;

     case 58:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + 0);

          break;

     case 59:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + 0);

          break;

     case 60:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + 0);

          break;

     case 61:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + 0);

          break;

     case 62:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + 0);

          break;

     case 63:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + 0);

          break;

     case 64:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + 0);

          break;

     case 65:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + 0);

          break;

     case 66:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + 0);

          break;

     case 67:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + 0);

          break;

     case 68:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + 0);

          break;

     case 69:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + 0);

          break;

     case 70:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + 0);

          break;

     case 71:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + 0);

          break;

     case 72:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + 0);

          break;

     case 73:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + 0);

          break;

     case 74:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + 0);

          break;

     case 75:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + 0);

          break;

     case 76:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + 0);

          break;

     case 77:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + 0);

          break;

     case 78:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + 0);

          break;

     case 79:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + 0);

          break;

     case 80:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + 0);

          break;

     case 81:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + 0);

          break;

     case 82:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + 0);

          break;

     case 83:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + 0);

          break;

     case 84:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + 0);

          break;

     case 85:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + 0);

          break;

     case 86:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + 0);

          break;

     case 87:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + 0);

          break;

     case 88:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + 0);

          break;

     case 89:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + 0);

          break;

     case 90:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + 0);

          break;

     case 91:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + 0);

          break;

     case 92:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + 0);

          break;

     case 93:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + 0);

          break;

     case 94:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + 0);

          break;

     case 95:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + 0);

          break;

     case 96:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + 0);

          break;

     case 97:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + 0);

          break;

     case 98:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + 0);

          break;

     case 99:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + 0);

          break;

     case 100:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + 0);

          break;

     case 101:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + 0);

          break;

     case 102:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + 0);

          break;

     case 103:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + 0);

          break;

     case 104:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + 0);

          break;

     case 105:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + 0);

          break;

     case 106:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + 0);

          break;

     case 107:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + 0);

          break;

     case 108:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + 0);

          break;

     case 109:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + 0);

          break;

     case 110:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + 0);

          break;

     case 111:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + 0);

          break;

     case 112:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + 0);

          break;

     case 113:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + 0);

          break;

     case 114:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + 0);

          break;

     case 115:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + 0);

          break;

     case 116:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + 0);

          break;

     case 117:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + 0);

          break;

     case 118:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + 0);

          break;

     case 119:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + 0);

          break;

     case 120:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + 0);

          break;

     case 121:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + bytes__read_thread_z[120] + 0);

          break;

     case 122:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + bytes__read_thread_z[120] + bytes__read_thread_z[121] + 0);

          break;

     case 123:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + bytes__read_thread_z[120] + bytes__read_thread_z[121] + bytes__read_thread_z[122] + 0);

          break;

     case 124:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + bytes__read_thread_z[120] + bytes__read_thread_z[121] + bytes__read_thread_z[122] + bytes__read_thread_z[123] + 0);

          break;

     case 125:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + bytes__read_thread_z[120] + bytes__read_thread_z[121] + bytes__read_thread_z[122] + bytes__read_thread_z[123] + bytes__read_thread_z[124] + 0);

          break;

     case 126:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + bytes__read_thread_z[120] + bytes__read_thread_z[121] + bytes__read_thread_z[122] + bytes__read_thread_z[123] + bytes__read_thread_z[124] + bytes__read_thread_z[125] + 0);

          break;

     case 127:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + bytes__read_thread_z[120] + bytes__read_thread_z[121] + bytes__read_thread_z[122] + bytes__read_thread_z[123] + bytes__read_thread_z[124] + bytes__read_thread_z[125] + bytes__read_thread_z[126] + 0);

          break;

     case 128:

          return lgetpor(totalbytes_z, bytes__read_thread_z[0] + bytes__read_thread_z[1] + bytes__read_thread_z[2] + bytes__read_thread_z[3] + bytes__read_thread_z[4] + bytes__read_thread_z[5] + bytes__read_thread_z[6] + bytes__read_thread_z[7] + bytes__read_thread_z[8] + bytes__read_thread_z[9] + bytes__read_thread_z[10] + bytes__read_thread_z[11] + bytes__read_thread_z[12] + bytes__read_thread_z[13] + bytes__read_thread_z[14] + bytes__read_thread_z[15] + bytes__read_thread_z[16] + bytes__read_thread_z[17] + bytes__read_thread_z[18] + bytes__read_thread_z[19] + bytes__read_thread_z[20] + bytes__read_thread_z[21] + bytes__read_thread_z[22] + bytes__read_thread_z[23] + bytes__read_thread_z[24] + bytes__read_thread_z[25] + bytes__read_thread_z[26] + bytes__read_thread_z[27] + bytes__read_thread_z[28] + bytes__read_thread_z[29] + bytes__read_thread_z[30] + bytes__read_thread_z[31] + bytes__read_thread_z[32] + bytes__read_thread_z[33] + bytes__read_thread_z[34] + bytes__read_thread_z[35] + bytes__read_thread_z[36] + bytes__read_thread_z[37] + bytes__read_thread_z[38] + bytes__read_thread_z[39] + bytes__read_thread_z[40] + bytes__read_thread_z[41] + bytes__read_thread_z[42] + bytes__read_thread_z[43] + bytes__read_thread_z[44] + bytes__read_thread_z[45] + bytes__read_thread_z[46] + bytes__read_thread_z[47] + bytes__read_thread_z[48] + bytes__read_thread_z[49] + bytes__read_thread_z[50] + bytes__read_thread_z[51] + bytes__read_thread_z[52] + bytes__read_thread_z[53] + bytes__read_thread_z[54] + bytes__read_thread_z[55] + bytes__read_thread_z[56] + bytes__read_thread_z[57] + bytes__read_thread_z[58] + bytes__read_thread_z[59] + bytes__read_thread_z[60] + bytes__read_thread_z[61] + bytes__read_thread_z[62] + bytes__read_thread_z[63] + bytes__read_thread_z[64] + bytes__read_thread_z[65] + bytes__read_thread_z[66] + bytes__read_thread_z[67] + bytes__read_thread_z[68] + bytes__read_thread_z[69] + bytes__read_thread_z[70] + bytes__read_thread_z[71] + bytes__read_thread_z[72] + bytes__read_thread_z[73] + bytes__read_thread_z[74] + bytes__read_thread_z[75] + bytes__read_thread_z[76] + bytes__read_thread_z[77] + bytes__read_thread_z[78] + bytes__read_thread_z[79] + bytes__read_thread_z[80] + bytes__read_thread_z[81] + bytes__read_thread_z[82] + bytes__read_thread_z[83] + bytes__read_thread_z[84] + bytes__read_thread_z[85] + bytes__read_thread_z[86] + bytes__read_thread_z[87] + bytes__read_thread_z[88] + bytes__read_thread_z[89] + bytes__read_thread_z[90] + bytes__read_thread_z[91] + bytes__read_thread_z[92] + bytes__read_thread_z[93] + bytes__read_thread_z[94] + bytes__read_thread_z[95] + bytes__read_thread_z[96] + bytes__read_thread_z[97] + bytes__read_thread_z[98] + bytes__read_thread_z[99] + bytes__read_thread_z[100] + bytes__read_thread_z[101] + bytes__read_thread_z[102] + bytes__read_thread_z[103] + bytes__read_thread_z[104] + bytes__read_thread_z[105] + bytes__read_thread_z[106] + bytes__read_thread_z[107] + bytes__read_thread_z[108] + bytes__read_thread_z[109] + bytes__read_thread_z[110] + bytes__read_thread_z[111] + bytes__read_thread_z[112] + bytes__read_thread_z[113] + bytes__read_thread_z[114] + bytes__read_thread_z[115] + bytes__read_thread_z[116] + bytes__read_thread_z[117] + bytes__read_thread_z[118] + bytes__read_thread_z[119] + bytes__read_thread_z[120] + bytes__read_thread_z[121] + bytes__read_thread_z[122] + bytes__read_thread_z[123] + bytes__read_thread_z[124] + bytes__read_thread_z[125] + bytes__read_thread_z[126] + bytes__read_thread_z[127] + 0);

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