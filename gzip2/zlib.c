/********************************************************************************
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
 ********************************************************************************
 
      E-mails:                                                                 
      maria@arsoftware.net.br                                                  
      pedro@locacaodiaria.com.br                                               

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 *******************************************************************************/

#define ARP_USE_ENHANCED_STDIO

#define SHA512_DIGEST_LENGTH 64

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort unsigned short
#endif
#endif

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

char zlib_error_z[1024];
int zlib_int_error_z;
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

#include "stdio_v2.h"

#include <process.h>

#include "win64.h"

#define __amandacall __stdcall

int64_t max_memory_size_j = 0;

/**
 * To convert an input wide string to a utf-8 encoded filename on return
 *
 * @param pUSC2_maria the wide string to be converted
 *
 * @return it will return the static allocated char * string with the utf-8 encoded filename
 *
 */
char *valquiria_wide_to_utf8_no_october_2021(WCHAR *pUSC2_maria)
{
      static char saida_utf8[AMANDA__SIZE];

      WideCharToMultiByte(CP_UTF8, 0, pUSC2_maria, -1, (LPSTR)saida_utf8, AMANDA__SIZE, 0, 0);
      return saida_utf8;
}

/**
 * To convert an input wide string to a utf-8 encoded filename on return
 *
 * @param pUSC2_maria the wide string to be converted
 *
 * @return it will return the static allocated char * string with the utf-8 encoded filename
 *
 */
char *valquiria_wide_to_utf8(WCHAR *pUSC2_maria, char *ar_temp_char)
{
      char *saida_utf8 = ar_temp_char;

      WideCharToMultiByte(CP_UTF8, 0, pUSC2_maria, -1, (LPSTR)saida_utf8, AMANDA__SIZE, 0, 0);
      return saida_utf8;
}

wchar_t *
remove_permissive_name_m_no_october_2021(wchar_t *wname)
{

      /**
 * oi amor...
 */
      static wchar_t wname_copy[AMANDA__SIZE_w + 1];

      wchar_t *wname_copy_v27 = wname_copy;

      wcscpy(wname_copy, wname);

      if (3 < wcslen(wname_copy))
      {

            if ('\\' == wname_copy[0] &&
                '\\' == wname_copy[1] &&
                '?' == wname_copy[2])
            {
                  wname_copy_v27++;
                  wname_copy_v27++;
                  wname_copy_v27++;
                  wname_copy_v27++;
                  return wname_copy_v27;
            }
            else
            {
                  return wname;
            }
      }
      else
      {
            return wname;
      }
}

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
WCHAR *amanda_utf8towide_1_v27_no_october_2021__time_14_24_24(char *pUTF8);

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE_ww ((32767 * 2) + 2)

WCHAR *amanda_utf8towide_1_v28(char *pUTF8, WCHAR *ar_temp);

wchar_t *
permissive_name_m_v28(const wchar_t *wname, WCHAR *ar_temp);

bool is_multi_thread_z = false;

int __fastcall compress2_uncompress_k_real_mt_z(char *input_z, char *output_z);
int zuncompress_sha512_k_mt_z(char *input, char *output);

int __amandacall get_multithread_progress(void);

extern int n_threads_z;

extern char temp_path_z[];

uint32_t
tuklib_cpucores_z(void);

int print(void);

void pedro_dprintf(
    int amanda_level,
    char *format, ...);

#include "miniz.h"
//#include "zlib.h"

//#include "md5.h"

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

#include "gzip2_include.h"

int zuncompress_sha512_k(char *input, char *output);

void *sha512_init_k(void);

void sha512_update_k(void *ctx, unsigned char *buffer_k, unsigned int len_k);

void sha512_final_k(void *ctx, unsigned char *array_digest_64_bytes);

extern void __cdecl mprintf(char *format, ...);
uint getpor(int max, uint fatia);
void dprintf(char *format, ...);
int __stdcall execute();
int start();
int start2();

wchar_t *
remove_permissive_name_m_(wchar_t *wname, WCHAR *ar_temp)
{

      /**
 * oi amor...
 */
      wchar_t *wname_copy = ar_temp;

      wchar_t *wname_copy_v27 = wname_copy;

      wcscpy(wname_copy, wname);

      if (3 < wcslen(wname_copy))
      {

            if ('\\' == wname_copy[0] &&
                '\\' == wname_copy[1] &&
                '?' == wname_copy[2])
            {
                  wname_copy_v27++;
                  wname_copy_v27++;
                  wname_copy_v27++;
                  wname_copy_v27++;
                  return wname_copy_v27;
            }
            else
            {
                  return wname;
            }
      }
      else
      {
            return wname;
      }
}

/**
 * wide aware..my love
 * 
 * 
 * 
 */
__int64 lffilesize(const char *szFileName);

int lgetpor(__int64 max, __int64 fatia);

#define CHUNK 131072

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

            memset(fixo_w_ar, 0, AMANDA__SIZE_ww);
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  wcscpy(path_w_ar, permissive_name_m_v28(amanda_utf8towide_1_v28(path, ar_temp), ar_temp2));
                  ret = GetTempFileNameW(path_w_ar, signature_z, 0, fixo_w_ar);

                  free(ar_temp);
                  free(ar_temp2);
            }
            if (ret == 0)
            {
                  free(fixo_w_ar);
                  free(path_w_ar);
                  free(path);
                  return 0;
            }
            else
            {
                  {

                        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                        //WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
                        char *ar_temp3 = (void *)malloc(AMANDA__SIZE);
                        strcpy(out_z, valquiria_wide_to_utf8(remove_permissive_name_m_(fixo_w_ar, ar_temp), ar_temp3));

                        free(ar_temp);
                        free(ar_temp3);
                  }
                  free(fixo_w_ar);
                  free(path_w_ar);
                  free(path);
                  return 1;
            }
      }
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

unsigned __stdcall my_thread_function(void *my_argument_z)
{
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
            ptr_my_struct_z->retvalue = 7;
            goto saida_arp;
      }

      if (NULL == ptr_my_struct_z->dest) //ta ok
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

      veja_z += ptr_my_struct_z->size_of_input_file_z;

      pedro_dprintf(-1, "tamanho apos slices %lld\n", veja_z);

      ptr_my_struct_z->ret = deflateInit(&ptr_my_struct_z->strm, ptr_my_struct_z->level);

      assert(ptr_my_struct_z->ret == Z_OK);

      //ta faltando aqui...
#ifdef ARP_USE_ENHANCED_STDIO
      pedro_dprintf(-1, "position before %lld\n", _ftelli64_z(ptr_my_struct_z->dest));
#else
      pedro_dprintf(-1, "position before %lld\n", _ftelli64(ptr_my_struct_z->dest));
#endif

#ifdef ARP_USE_ENHANCED_STDIO
      ptr_my_struct_z->ret = fwrite_z(&ptr_my_struct_z->ar, 1, sizeof(ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#else
      ptr_my_struct_z->ret = fwrite(&ptr_my_struct_z->ar, 1, sizeof(ptr_my_struct_z->ar), ptr_my_struct_z->dest);
#endif

      if (sizeof(ptr_my_struct_z->ar) != ptr_my_struct_z->ret)
      {
            ptr_my_struct_z->retvalue = 14; //unexpected error
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
            ptr_my_struct_z->retvalue = 14; //unexpected error
            goto saida;
      }
#ifdef ARP_USE_ENHANCED_STDIO
      pedro_dprintf(-1, "position after %lld\n", _ftelli64_z(ptr_my_struct_z->dest));
#else
      pedro_dprintf(-1, "position after %lld\n", _ftelli64(ptr_my_struct_z->dest));
#endif

      int status = 0;

      int64_t infile_remaining = ptr_my_struct_z->size_of_input_file_z;

      ptr_my_struct_z->strm.next_in = (void *)ptr_my_struct_z->buffer;
      ptr_my_struct_z->strm.avail_in = 0;
      ptr_my_struct_z->strm.next_out = (void *)ptr_my_struct_z->out;
      ptr_my_struct_z->strm.avail_out = CHUNK;

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

            if (!ptr_my_struct_z->strm.avail_in)
            {
                  // Input buffer is empty, so read more bytes from input file.
                  int64_t n = min(CHUNK, infile_remaining);

                  ptr_my_struct_z->ret = fread(ptr_my_struct_z->buffer, 1, n, ptr_my_struct_z->input_file);

                  if (ptr_my_struct_z->ret != n)
                  {
                        ptr_my_struct_z->retvalue = 402; //Cannot read from input file
                        goto saida;
                  }

                  if (0 > ptr_my_struct_z->ret)
                  {
                        ptr_my_struct_z->retvalue = 402; //Cannot read from input file
                        goto saida;
                  }
                  /*
                if (0 == ptr_my_struct_z->ret)
                {
                        goto saida;
                }
 */
                  ptr_my_struct_z->strm.next_in = (void *)ptr_my_struct_z->buffer;
                  ptr_my_struct_z->strm.avail_in = n;

                  infile_remaining -= n;
                  //printf("Input bytes remaining: %u\n", infile_remaining);

                  sha512_update_k(ptr_my_struct_z->sha51_ptr, (void *)ptr_my_struct_z->buffer, ptr_my_struct_z->ret);

                  ptr_my_struct_z->bytesread = ptr_my_struct_z->bytesread + ptr_my_struct_z->ret;

                  pedro_dprintf(-1, "bytes read inside %lld\n", ptr_my_struct_z->bytesread);

                  bytes__read_thread_z[ptr_my_struct_z->thread_id_z] = ptr_my_struct_z->bytesread;
            }

            status = deflate(&ptr_my_struct_z->strm, infile_remaining ? Z_NO_FLUSH : Z_FINISH);

            if ((status == Z_STREAM_END) || (!ptr_my_struct_z->strm.avail_out))
            {
                  // Output buffer is full, or compression is done, so write buffer to output file.
                  int n = CHUNK - ptr_my_struct_z->strm.avail_out;

                  size_of_compressed_z += n;
                  ptr_my_struct_z->bytestosave += n;

                  ptr_my_struct_z->writebytes = n;

                  if (fwrite_z(ptr_my_struct_z->out, 1, ptr_my_struct_z->writebytes, ptr_my_struct_z->dest) != n)
                  {

                        ptr_my_struct_z->retvalue = 14;

                        goto saida;
                  }
                  ptr_my_struct_z->strm.next_out = (void *)ptr_my_struct_z->out;
                  ptr_my_struct_z->strm.avail_out = CHUNK;
            }

            if (status == Z_STREAM_END)
            {
                  ptr_my_struct_z->done = 1;
                  break;
            }
            else if (status != Z_OK)
            {

                  switch (status)
                  {
                  case Z_STREAM_END:
                        strcpy(zlib_error_z, "Z_STREAM_END");
                        zlib_int_error_z = 528;
                        break;
                  case Z_NEED_DICT:
                        strcpy(zlib_error_z, "Z_NEED_DICT");
                        zlib_int_error_z = 529;
                        break;
                  case Z_STREAM_ERROR:
                        strcpy(zlib_error_z, "Z_STREAM_ERROR");
                        zlib_int_error_z = 530;
                        break;
                  case Z_MEM_ERROR:
                        strcpy(zlib_error_z, "Z_MEM_ERROR");
                        zlib_int_error_z = 531;
                        break;
                  case Z_DATA_ERROR:
                        strcpy(zlib_error_z, "Z_DATA_ERROR");
                        zlib_int_error_z = 532;
                        break;
                  case Z_BUF_ERROR: //isso da erro
                        strcpy(zlib_error_z, "Z_BUF_ERROR");
                        zlib_int_error_z = 533;
                        break;
                  default:
                        strcpy(zlib_error_z, "unknown");
                        zlib_int_error_z = 534;
                        break;
                  }

                  /*
			   case Z_BUF_ERROR://isso da erro

			   assert (0);
			   break;
			 */

                  pedro_dprintf(2, "deflate() failed with status %$ !\n", zlib_error_z);
                  ptr_my_struct_z->retvalue = zlib_int_error_z;
                  goto saida;
            }
      }

saida:;

      pedro_dprintf(-1, "saida %d bytes written %d\n", ptr_my_struct_z->retvalue, (int)size_of_compressed_z);

      sha512_final_k(ptr_my_struct_z->sha51_ptr, ptr_my_struct_z->ar.sha512_k);

      if (ptr_my_struct_z->size_of_input_file_z && (0 == ptr_my_struct_z->retvalue))
      {

            if (0 == ptr_my_struct_z->done && (0 == cancelflag))
            {

                  ptr_my_struct_z->retvalue = 16;
            }
      }

      (void)deflateEnd(&ptr_my_struct_z->strm);

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

      if (0 == ptr_my_struct_z->retvalue)
      {
            if (unicodemode)
            {
#ifdef ARP_USE_ENHANCED_STDIO

                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  pedro_dprintf(-1, "2 memory size %lld", max_memory_size_j);
                  ptr_my_struct_z->dest = _wfopen_z(permissive_name_m_v28(amanda_utf8towide_1_v28(temp_files_z[ptr_my_struct_z->thread_id_z], ar_temp), ar_temp2), "rb+", max_memory_size_j, __FILE__, __LINE__, ptr_my_struct_z->dest);

                  free(ar_temp);
                  free(ar_temp2);

#else
                  ptr_my_struct_z->dest = _wfopen(wpmode, L"rb+");
#endif
            }
            if (ptr_my_struct_z->dest)
            {
                  switch (ptr_my_struct_z->dest->internal_error_m)
                  {
                  case P_MODE_CANNOT_OPEN_INTERNAL_FILE:
                        ptr_my_struct_z->retvalue = 97001; //Cannot open required temp file
                        break;
                  case P_MODE_IS_IN_ERROR:

                        break;
                  case P_MODE_OK:

                        break;
                  }
            }
            if (0 == ptr_my_struct_z->dest)
            {
                  ptr_my_struct_z->retvalue = 8;
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

                        ptr_my_struct_z->retvalue = 14;
                  }
#ifdef ARP_USE_ENHANCED_STDIO
                  ptr_my_struct_z->ret = fwrite_z(&size_of_compressed_z, 1, sizeof(size_of_compressed_z), ptr_my_struct_z->dest);
#else
                  ptr_my_struct_z->ret = fwrite(&size_of_compressed_z, 1, sizeof(size_of_compressed_z), ptr_my_struct_z->dest);
#endif
                  if (ptr_my_struct_z->ret != sizeof(size_of_compressed_z))
                  {

                        ptr_my_struct_z->retvalue = 14;
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

      if (cancelflag)
      {
            ptr_my_struct_z->retvalue = 19;
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
      if (ptr_my_struct_z->buffer)
      {
            free(ptr_my_struct_z->buffer);
      }
      if (ptr_my_struct_z->out)
      {
            free(ptr_my_struct_z->out);
      }

      if (0 == thread_return_value_z)
      {
            thread_return_value_z = ptr_my_struct_z->retvalue;
      }
      pedro_dprintf(-1, "veja %d %d\n", (int)thread_return_value_z, (int)ptr_my_struct_z->retvalue);
      free(my_argument_z);
      _endthreadex(0);

      return 0;
}

int zcompress_sha512_k(char *input, char *output, int levelin) //levelin not in use, just trying to wonder why...
{
      int i_z;
      FILE *dest = NULL;
      FILE *source = NULL;

#ifdef ARP_USE_ENHANCED_STDIO
      FILE_z *temp_z = NULL;
#else
      FILE *temp_z = NULL;
#endif
      __int64 bytesread = 0;
      __int64 bytestosave = 0;
      __int64 totalbytes = 0;
      int64_t infile_remaining = 0;
      int done = 0;
      int level = Z_DEFAULT_COMPRESSION;
      int ret_z = 0;
      int ret2 = 0;
      int retvalue = 0;
      int writebytes = 0;
      ar_data ar;
      static char buffer[CHUNK /* + 1 why?...*/];
      static char out[CHUNK];
      z_stream strm = {
          0,
      };
      char *sha51_ptr = NULL;
      int n_threads_copy;
      int n_thread_counter;
      int status = 0;
      int first_step_z = 0;
      int64_t bytes_processed_z = 0;
      int64_t slice_z;
      int64_t remaining_z;
      int64_t offset_z;
      thread_return_value_z = 0;
      my_thread_struct_z *ptr_my_struct_z;
      pauseflag = 0;
      cancelflag = 0;
      level = levelin;
      veja_z = 0;
      if (levelin <= 0)
      {
            level = 0;
      }

      if (levelin > 9)
      {
            level = 9;
      }

      {

            pedro_dprintf(-1, "gzip2 threads %d\n", n_threads_z);

            totalbytes = lffilesize(input);
            totalbytes_z = totalbytes;

            if (1000 > totalbytes)
            {
                  pedro_dprintf(-1, "below 1000 \n");
                  goto single_thread_z;
            }

            is_multi_thread_z = false;

            if (1 != n_threads_z)
            {
                  //aqui...
                  if (0 == n_threads_z)
                  {
                        n_threads_z = tuklib_cpucores_z();

                        if (0 == n_threads_z)
                        {
                              goto single_thread_z;
                        }
                        if (1 == n_threads_z)
                        {
                              //in the creatioon is not a problem, the problem is in the extraction, then it need to check
                              //the header...need to think in everything
                              goto single_thread_z;
                        }
                  }

                  if (128 < n_threads_z)
                  {
                        n_threads_z = 128; //correcting it for maximum threads...
                  }
                  //aqui...
                  max_memory_size_j = 200000000 / n_threads_z;

                  pedro_dprintf(-1, "1 memory size %lld", max_memory_size_j);

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

                        if (unicodemode)
                        {

                              WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                              WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                              ptr_my_struct_z->input_file = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2), L"rb");

                              free(ar_temp);
                              free(ar_temp2);
                        }
                        else
                              ptr_my_struct_z->input_file = fopen(input, "rb");

                        if (NULL == ptr_my_struct_z->input_file)
                        {
                              if (0 == thread_return_value_z)
                              {
                                    thread_return_value_z = 7; //cannot open input file
                              }
                        }

                        ptr_my_struct_z->dest = NULL;
                        if (!createtempfilename_and_keep_z(temp_path_z, temp_files_z[n_thread_counter], L"GZ2"))
                        {
                              if (0 == thread_return_value_z)
                              {
                                    thread_return_value_z = 401; //cannot create temp file
                              }
                        }
                        else
                        {
                              if (unicodemode)
                              {
#ifdef ARP_USE_ENHANCED_STDIO

                                    WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                                    WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                                    pedro_dprintf(-1, "4 memory size %lld", max_memory_size_j);
                                    ptr_my_struct_z->dest = _wfopen_z(permissive_name_m_v28(amanda_utf8towide_1_v28(temp_files_z[n_thread_counter], ar_temp), ar_temp2), "wb", max_memory_size_j, __FILE__, __LINE__, NULL);
                                    files_to_close_z[n_thread_counter] = ptr_my_struct_z->dest;

                                    free(ar_temp);
                                    free(ar_temp2);

#else
                                    ptr_my_struct_z->dest = _wfopen(wpmode, L"wb");
#endif
                              }

                              if (NULL == ptr_my_struct_z->dest)
                              {
                                    if (0 == thread_return_value_z)
                                    {
                                          thread_return_value_z = 8; //cannot open output file
                                    }
                              }
                        }

                        if (0 == first_step_z)
                        {
                              pedro_dprintf(-1, "tamanho %lld\n", totalbytes);
                              slice_z = totalbytes / n_threads_z;
                              remaining_z = totalbytes;
                              offset_z = 0;

                              pedro_dprintf(-1, "!!!!! n_threads_z %d", n_threads_z);

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

                        ptr_my_struct_z->buffer = calloc(1, CHUNK + 1);
                        assert(ptr_my_struct_z->buffer);
                        ptr_my_struct_z->out = calloc(1, CHUNK);
                        assert(ptr_my_struct_z->out);

                        ptr_my_struct_z->sha51_ptr = sha512_init_k();

                        memset(&ptr_my_struct_z->ar, 0, sizeof(ar_data));

                        memcpy(ptr_my_struct_z->ar.string, "AR__", 4); //aqui 2

                        ptr_my_struct_z->ar.string[3] = '_' - 1; //signature for gzip2 multi-thread

                        pedro_dprintf(-1, "ai %x\n", *((int *)ptr_my_struct_z->ar.string));

                        memset(&ptr_my_struct_z->strm, 0, sizeof(ptr_my_struct_z->strm));

                        ptr_my_struct_z->strm.zalloc = Z_NULL;
                        ptr_my_struct_z->strm.zfree = Z_NULL;
                        ptr_my_struct_z->strm.opaque = Z_NULL;

                        ptr_my_struct_z->level = level;
                        pedro_dprintf(-1, "level my dear %d\n", level);
                        if (unicodemode)
                        {

                              WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                              WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                              ptr_my_struct_z->ar.attrib = GetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2));

                              free(ar_temp);
                              free(ar_temp2);
                        }
                        else
                              ptr_my_struct_z->ar.attrib = GetFileAttributes(input);

                        if ((int)0xFFFFFFFF == (int)ar.attrib)
                        {
                              ptr_my_struct_z->ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
                        }

                        bytes__read_thread_z[n_thread_counter] = 0;

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
                  {
                        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                        WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                        ret_z = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);

                        free(ar_temp);
                        free(ar_temp2);
                  }
                  //abrir arquivo

                  if (unicodemode)
                  {
                        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                        WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                        dest = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp), L"wb");

                        free(ar_temp);
                        free(ar_temp2);
                  }
                  else
                        dest = fopen(output, "wb");

                  if (NULL == dest)
                  {
                        if (0 == thread_return_value_z)
                        {
                              thread_return_value_z = 8; //Cannot open output file
                        }
                  }

                  //depois de finalizar
                  for (i_z = 0; i_z < n_threads_z; i_z++)
                  {
                        pedro_dprintf(-1, "arquivo temp a del %s\n", temp_files_z[i_z]);
                        if (dest)
                        {

                              if (unicodemode)
                              {
#ifdef ARP_USE_ENHANCED_STDIO
                                    WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                                    WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                                    pedro_dprintf(-1, "a memory size %lld", max_memory_size_j);
                                    temp_z = _wfopen_z(permissive_name_m_v28(amanda_utf8towide_1_v28(temp_files_z[i_z], ar_temp), ar_temp2), "rb", max_memory_size_j, __FILE__, __LINE__, files_to_close_z[i_z]);

                                    free(ar_temp);
                                    free(ar_temp2);
#else
                                    temp_z = _wfopen(wpmode, L"rb");
#endif
                              }
                              if (temp_z)
                              {
                                    switch (temp_z->internal_error_m)
                                    {
                                    case P_MODE_CANNOT_OPEN_INTERNAL_FILE:
                                          thread_return_value_z = 97001; //Cannot open required temp file
                                          break;
                                    case P_MODE_IS_IN_ERROR:

                                          break;
                                    case P_MODE_OK:

                                          break;
                                    }
                              }
                              if (temp_z)
                              {
                                    //Mr. Do

                              volta_amanda:;
                                    if (97001 == thread_return_value_z)
                                    {
                                          ret_z = 0;
                                    }
                                    else
                                          ret_z = fread_z(buffer, 1, CHUNK, temp_z);

                                    if (0 > ret_z) //Never will occur...but I will keep it here for historical reasons...
                                    {
                                          if (0 == thread_return_value_z)
                                          {
                                                thread_return_value_z = 402; //Cannot read from input file
                                          }
                                    }
                                    else if (0 == ret_z)
                                    {
                                          ; //just go by...
                                    }
                                    else
                                    {

                                          ret2 = fwrite(buffer, 1, ret_z, dest);

                                          if (ret2 != ret_z)
                                          {
                                                if (0 == thread_return_value_z)
                                                {
                                                      thread_return_value_z = 14; //Cannot write to output file
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
                                          thread_return_value_z = 404; //Cannot open temp file
                                    }
                              }
                        }
#ifndef ARP_USE_ENHANCED_STDIO
                        _wunlink(amanda_utf8towide_1_(temp_files_z[i_z]));
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
                        assert(veja_z == totalbytes);
                  }

                  //precisa setar isto antes de retornar
                  finished = 1; //e depois return

                  if (dest)
                  {
                        fclose(dest);
                  }

                  pedro_dprintf(-1, "vejamos %d\n", thread_return_value_z);

                  return thread_return_value_z;
            }
      }

single_thread_z:;
      pedro_dprintf(-1, "Single thread mode creation\n");

      sha51_ptr = sha512_init_k();

      memset(&ar, 0, sizeof(ar_data));

      memcpy(ar.string, "AR__", 4);

      memset(&strm, 0, sizeof(strm));

      strm.zalloc = Z_NULL;
      strm.zfree = Z_NULL;
      strm.opaque = Z_NULL;
      /*
    pedro_dprintf(-1, "cores %d arg address %x\n", tuklib_cpucores_z(), &my_arg);

        my_thread_handle[0] = (__INT32_OR_INT64) _beginthreadex(NULL, 0, my_thread_function, &my_arg, 0, NULL);

        assert(0 != my_thread_handle[0]);

        WaitForSingleObject((void *) my_thread_handle[0], INFINITE);

        pedro_dprintf(-1, "seguindo\n");

        CloseHandle((void *) my_thread_handle[0]);
 */

      pedro_dprintf(-1, "single thread level my dear %d\n", level);

      ret_z = deflateInit(&strm, level);

      assert(ret_z == Z_OK);

      zlibpercent = 0;

      totalbytes = lffilesize(input);
      pedro_dprintf(-1, "original input size %lld\n", (int64_t)totalbytes);
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            ar.attrib = GetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2));

            free(ar_temp);
            free(ar_temp2);
      }
#ifdef NPRINTF
      dprintf("atributo %x \n", ar.attrib); //%x requer um int, tem que usar %p
#endif

      if ((int)0xFFFFFFFF == (int)ar.attrib)
      {
            ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
      }
      if (unicodemode)
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            source = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2), L"rb");

            free(ar_temp);
            free(ar_temp2);
      }
      else
            source = fopen(input, "rb");

      if (NULL == source)
      {

            retvalue = 7;

            goto saida;
      }
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            ret_z = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);

            free(ar_temp);
            free(ar_temp2);
      }
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            dest = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), L"wb");

            free(ar_temp);
            free(ar_temp2);
      }
      if (NULL == dest)
      {

            retvalue = 8;

            goto saida;
      }

      ret_z = fwrite(&ar, 1, sizeof(ar), dest);

      if (0 == ret_z)
      {
            retvalue = 14; //unexpected error
            goto saida;
      }

      infile_remaining = totalbytes;
      strm.next_in = (void *)buffer;
      strm.avail_in = 0;
      strm.next_out = (void *)out;
      strm.avail_out = CHUNK;

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

            if (!strm.avail_in)
            {
                  // Input buffer is empty, so read more bytes from input file.
                  int64_t n_z = min(CHUNK, infile_remaining);

                  ret_z = fread(buffer, 1, n_z, source);

                  if (ret_z != n_z)
                  {
                        retvalue = 402; //Cannot read from input file
                        goto saida;
                  }

                  bytesread += ret_z;

                  zlibpercent = lgetpor(totalbytes, bytesread);
                  if (0 > ret_z)
                  {
                        retvalue = 402; //Cannot read from input file
                        goto saida;
                  }

                  strm.next_in = (void *)buffer;
                  strm.avail_in = n_z;

                  infile_remaining -= n_z;
                  //printf("Input bytes remaining: %u\n", infile_remaining);
                  bytes_processed_z += ret_z;
                  sha512_update_k(sha51_ptr, (void *)buffer, ret_z);
            }

            status = deflate(&strm, infile_remaining ? Z_NO_FLUSH : Z_FINISH);

            if ((status == Z_STREAM_END) || (!strm.avail_out))
            {
                  // Output buffer is full, or compression is done, so write buffer to output file.
                  uint n = CHUNK - strm.avail_out;

                  bytestosave += n;

                  writebytes = n;

                  if (fwrite(out, 1, writebytes, dest) != n)
                  {

                        retvalue = 14;

                        goto saida;
                  }
                  strm.next_out = (void *)out;
                  strm.avail_out = CHUNK;
            }

            if (status == Z_STREAM_END)
            {
                  done = 1;
                  break;
            }
            else if (status != Z_OK)
            {
                  switch (status)
                  {
                  case Z_STREAM_END:
                        strcpy(zlib_error_z, "Z_STREAM_END");
                        zlib_int_error_z = 528;
                        break;
                  case Z_NEED_DICT:
                        strcpy(zlib_error_z, "Z_NEED_DICT");
                        zlib_int_error_z = 529;
                        break;
                  case Z_STREAM_ERROR:
                        strcpy(zlib_error_z, "Z_STREAM_ERROR");
                        zlib_int_error_z = 530;
                        break;
                  case Z_MEM_ERROR:
                        strcpy(zlib_error_z, "Z_MEM_ERROR");
                        zlib_int_error_z = 531;
                        break;
                  case Z_DATA_ERROR:
                        strcpy(zlib_error_z, "Z_DATA_ERROR");
                        zlib_int_error_z = 532;
                        break;
                  case Z_BUF_ERROR: //isso da erro
                        strcpy(zlib_error_z, "Z_BUF_ERROR");
                        zlib_int_error_z = 533;
                        break;
                  default:
                        strcpy(zlib_error_z, "unknown");
                        zlib_int_error_z = 534;
                        break;
                  }

                  /*
			   case Z_BUF_ERROR://isso da erro

			   assert (0);
			   break;
			 */

                  pedro_dprintf(2, "deflate() failed with status %$ !\n", zlib_error_z);
                  retvalue = zlib_int_error_z;
                  goto saida;
            }
      }

saida:;

      //assert(bytes_processed_z == totalbytes);

      sha512_final_k(sha51_ptr, ar.sha512_k);

      if (totalbytes && (0 == retvalue))
      {

            if (0 == done && (0 == cancelflag))
            {

                  retvalue = 16;
            }
      }

      (void)deflateEnd(&strm);

      zlibpercent = 10000;

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
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  dest = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), L"rb+");

                  free(ar_temp);
                  free(ar_temp2);
            }
            if (NULL == dest)
            {

                  retvalue = 8;
            }
            else
            {
                  ret_z = fwrite(&ar, 1, sizeof(ar), dest);
                  pedro_dprintf(-1, "salvou o    check512\n");
                  if (ret_z != sizeof(ar))
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
      char signature_z[5] = "AR__";
      FILE *dest = NULL;
      FILE *source = NULL;
      int ret = 0;
      int retvalue = 0;

      rspdata rsp;

      char is_ar_file_k = 0;

      pauseflag = 0;
      cancelflag = 0;
      signature_z[3] = '_' - 1;

      zlibpercent = 0;
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            source = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2), L"rb");

            free(ar_temp);
            free(ar_temp2);
      }
      if (NULL == source)
      {

            retvalue = 10;

            goto saida;
      }
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            ret = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);

            free(ar_temp);
            free(ar_temp2);
      }
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            dest = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), L"wb");

            free(ar_temp);
            free(ar_temp2);
      }
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

      if (0 == memcmp(rsp.string, "AR__", 4))
      {

            is_ar_file_k = 1;
            goto saida;
      }
      if (0 == memcmp(rsp.string, signature_z, 4))
      {

            is_ar_file_k = 2;
            goto saida;
      }

      retvalue = 90;
      goto saida;

saida:;

      if (source)
            fclose(source);

      if (dest)
            fclose(dest);

      if (0 == is_ar_file_k)
            finished = 1;

      if (1 == is_ar_file_k)
            return zuncompress_sha512_k(input, output);

      if (2 == is_ar_file_k)
            return zuncompress_sha512_k_mt_z(input, output);

      return retvalue;
}
int zuncompress_sha512_k(char *input, char *output)
{
      FILE *dest = NULL;
      FILE *source = NULL;
      __int64 bytesread = 0;
      __int64 totalbytes = 0;
      int64_t infile_remaining = 0;
      int done = 0;
      int ret = 0;
      int retvalue = 0;
      ar_data ar = {
          0,
      };
      static char buffer[CHUNK];
      static char out[CHUNK];
      z_stream strm = {
          0,
      };

      pauseflag = 0;
      cancelflag = 0;

      ret = inflateInit(&strm);

      pedro_dprintf(-1, "decoder single-thread\n");

      assert(ret == Z_OK);

      char *sha51_ptr = NULL;
      char sha512_temp_k[SHA512_DIGEST_LENGTH];

      sha51_ptr = sha512_init_k();

      zlibpercent = 0;

      totalbytes = lffilesize(input) - sizeof(ar);

      if (0 > totalbytes)
      {
            pedro_dprintf(-1, "probrema aqui\n");
            totalbytes = 0;
      }
      {

            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            source = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2), L"rb");

            free(ar_temp);
            free(ar_temp2);
      }
      if (NULL == source)
      {
            retvalue = 10;
            goto _to_never_forget___;
      }
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            ret = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);
            dest = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), L"wb");

            free(ar_temp);
            free(ar_temp2);
      }
      if (NULL == dest)
      {
            retvalue = 11;

            goto _to_never_forget___;
      }

      memset(&ar, 0, sizeof(ar));
      ret = fread(&ar, 1, sizeof(ar), source);

      if (ret != sizeof(ar))
      {

            retvalue = 9;
            goto _to_never_forget___;
      }

      if (0 != memcmp(ar.string, "AR__", 4))
      {

            retvalue = 90;
            goto _to_never_forget___;
      }

      strm.next_in = (void *)buffer;
      strm.avail_in = 0;
      strm.next_out = (void *)out;
      strm.avail_out = CHUNK;
      infile_remaining = totalbytes;

      pedro_dprintf(-1, "tamanho da data %lld\n", infile_remaining);

      for (;;)
      {
            while (pauseflag)
            {

                  Sleep(50);

                  if (cancelflag)
                  {
                        goto _to_never_forget___;
                  }
            }

            if (cancelflag)
            {
                  goto _to_never_forget___;
            }

            int status;

            if (!strm.avail_in)
            {
                  // Input buffer is empty, so read more bytes from input file.
                  int64_t n = min(CHUNK, infile_remaining);

                  if ((size_t)fread(buffer, 1, n, source) != (size_t)n)
                  {
                        retvalue = 9;
                        goto _to_never_forget___;
                  }

                  strm.next_in = (void *)buffer;
                  strm.avail_in = n;
                  infile_remaining -= n;
                  bytesread += n;
                  zlibpercent = lgetpor(totalbytes, bytesread);
            }
            //decoder single-thread
            status = inflate(&strm, Z_SYNC_FLUSH);

            if ((status == Z_STREAM_END) || (!strm.avail_out))
            {
                  // Output buffer is full, or decompression is done, so write buffer to output file.
                  int64_t n_z = CHUNK - strm.avail_out;

                  if ((size_t)fwrite(out, 1, n_z, dest) != (size_t)n_z)
                  {
                        retvalue = 14;
                        goto _to_never_forget___;
                  }
                  strm.next_out = (void *)out;
                  strm.avail_out = CHUNK;

                  sha512_update_k(sha51_ptr, (void *)out, n_z);
            }

            if (status == Z_STREAM_END)
            {
                  done = 1;
                  break;
            }
            else if (status != Z_OK)
            {
                  //aqui

                  switch (status)
                  {
                  case Z_STREAM_END:
                        strcpy(zlib_error_z, "Z_STREAM_END");
                        zlib_int_error_z = 528;
                        break;
                  case Z_NEED_DICT:
                        strcpy(zlib_error_z, "Z_NEED_DICT");
                        zlib_int_error_z = 529;
                        break;
                  case Z_STREAM_ERROR:
                        strcpy(zlib_error_z, "Z_STREAM_ERROR");
                        zlib_int_error_z = 530;
                        break;
                  case Z_MEM_ERROR:
                        strcpy(zlib_error_z, "Z_MEM_ERROR");
                        zlib_int_error_z = 531;
                        break;
                  case Z_DATA_ERROR:
                        strcpy(zlib_error_z, "Z_DATA_ERROR");
                        zlib_int_error_z = 532;
                        break;
                  case Z_BUF_ERROR: //isso da erro
                        strcpy(zlib_error_z, "Z_BUF_ERROR");
                        zlib_int_error_z = 533;
                        break;
                  default:
                        strcpy(zlib_error_z, "unknown");
                        zlib_int_error_z = 534;
                        break;
                  }

                  /*
			   case Z_BUF_ERROR://isso da erro

			   assert (0);
			   break;
			 */

                  pedro_dprintf(2, "inflate() failed with status %$ !\n", zlib_error_z);
                  retvalue = zlib_int_error_z;
                  goto _to_never_forget___;
            }
      }

_to_never_forget___:;

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

      zlibpercent = 10000;

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
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ret = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), ar.attrib);

                  free(ar_temp);
                  free(ar_temp2);
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

#include "gzip2_decoder_mt_z.c"

int zuncompress_sha512_k_mt_z(char *input, char *output)
{
      /*



	 */

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

      FILE *dest = NULL;
      FILE *source = NULL;
      bool first_pass_z = false;
      __int64 bytesread = 0;
      int64_t total_global_bytes = 0;
      zlibpercent = 0;

      total_global_bytes = lffilesize(input);

init_position_z:;

      int64_t save_position_z;
      char signature_z[5] = "AR__";
      int64_t remaining_z;

      //__int64 bytestosave               =      0;
      __int64 totalbytes = 0;
      int64_t infile_remaining = 0;
      int done = 0;
      int ret = 0;
      int retvalue = 0;
      ar_data ar;
      static char buffer[CHUNK /* + 1 */]; //precisa alterar
      static char out[CHUNK];
      z_stream strm;

      memset(&strm, 0, sizeof(strm));

      pauseflag = 0;
      cancelflag = 0;

      //exit(27);

      strm.zalloc = Z_NULL;
      strm.zfree = Z_NULL;
      strm.opaque = Z_NULL;
      strm.avail_in = 0;
      strm.next_in = Z_NULL;

      signature_z[3] = '_' - 1;

      if (-1 == signature_z[3]) //to make the compiler happy
      {
            pedro_dprintf(-1, "Test...\n");
      }

      ret = inflateInit(&strm);

      assert(ret == Z_OK);

      char *sha51_ptr = NULL;
      char sha512_temp_k[SHA512_DIGEST_LENGTH];

      sha51_ptr = sha512_init_k();

      //totalbytes = lffilesize (input);

      if (!first_pass_z)
      {
            //first_pass_z = true;
            if (unicodemode)
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  source = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input, ar_temp), ar_temp2), L"rb");

                  free(ar_temp);
                  free(ar_temp2);
            }
            else
                  source = fopen(input, "rb");

            if (NULL == source)
            {
                  retvalue = 10;
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
                  if (-1 == retvalue)
                  {
                        goto init_position_z;
                  }
                  retvalue = 11;
                  goto saida;
            }
            first_pass_z = true;
      }

      memset(&ar, 0, sizeof(ar));
      ret = fread(&ar, 1, sizeof(ar), source);

      if (ret != sizeof(ar))
      {

            retvalue = 9;
            goto saida;
      }
      bytesread += ret;
      if (0 != memcmp(ar.string, signature_z, 4))
      {

            retvalue = 90;
            goto saida;
      }

      ret = fread(&remaining_z, 1, sizeof(remaining_z), source);

      if (sizeof(remaining_z) != ret)
      {
            retvalue = 9;
            goto saida;
      }
      bytesread += ret;
      if (0 > remaining_z)
      {
            retvalue = 500;
            goto saida;
      }

      totalbytes = remaining_z;
      strm.next_in = (void *)buffer;
      strm.avail_in = 0;
      strm.next_out = (void *)out;
      strm.avail_out = CHUNK;
      infile_remaining = totalbytes;
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

            int status;

            if (!strm.avail_in)
            {
                  // Input buffer is empty, so read more bytes from input file.
                  int64_t n = min(CHUNK, infile_remaining);

                  if ((size_t)fread(buffer, 1, n, source) != (size_t)n)
                  {
                        retvalue = 9;
                        goto saida;
                  }

                  strm.next_in = (void *)buffer;
                  strm.avail_in = n;
                  infile_remaining -= n;
                  bytesread += n;
                  zlibpercent = lgetpor(total_global_bytes, bytesread);
            }

            status = inflate(&strm, Z_SYNC_FLUSH);

            if ((status == Z_STREAM_END) || (!strm.avail_out))
            {
                  // Output buffer is full, or decompression is done, so write buffer to output file.
                  int64_t n_z = CHUNK - strm.avail_out;

                  if ((size_t)fwrite(out, 1, n_z, dest) != (size_t)n_z)
                  {
                        retvalue = 14;
                        goto saida;
                  }
                  strm.next_out = (void *)out;
                  strm.avail_out = CHUNK;
                  sha512_update_k(sha51_ptr, (void *)out, n_z);
            }

            if (status == Z_STREAM_END)
            {
                  done = 1;
                  break;
            }
            else if (status != Z_OK)
            {
                  //aqui

                  switch (status)
                  {
                  case Z_STREAM_END:
                        strcpy(zlib_error_z, "Z_STREAM_END");
                        zlib_int_error_z = 528;
                        break;
                  case Z_NEED_DICT:
                        strcpy(zlib_error_z, "Z_NEED_DICT");
                        zlib_int_error_z = 529;
                        break;
                  case Z_STREAM_ERROR:
                        strcpy(zlib_error_z, "Z_STREAM_ERROR");
                        zlib_int_error_z = 530;
                        break;
                  case Z_MEM_ERROR:
                        strcpy(zlib_error_z, "Z_MEM_ERROR");
                        zlib_int_error_z = 531;
                        break;
                  case Z_DATA_ERROR:
                        strcpy(zlib_error_z, "Z_DATA_ERROR");
                        zlib_int_error_z = 532;
                        break;
                  case Z_BUF_ERROR: //isso da erro
                        strcpy(zlib_error_z, "Z_BUF_ERROR");
                        zlib_int_error_z = 533;
                        break;
                  default:
                        strcpy(zlib_error_z, "unknown");
                        zlib_int_error_z = 534;
                        break;
                  }

                  /*
			   case Z_BUF_ERROR://isso da erro

			   assert (0);
			   break;
			 */

                  pedro_dprintf(2, "inflate() failed with status %$ !\n", zlib_error_z);
                  retvalue = zlib_int_error_z;
                  goto saida;
            }
      }

saida:;

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

      if (cancelflag)
      {
            retvalue = 19;
      }

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
      zlibpercent = 10000;

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

      if (0 == retvalue)
      {
            if (unicodemode)
            {
                  
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ret = SetFileAttributesW(permissive_name_m_v28( amanda_utf8towide_1_v28(output, ar_temp), ar_temp2), ar.attrib);
                  
                  free(ar_temp);
                  free(ar_temp2);
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

int __amandacall get_multithread_progress(void)
{
      /*
      static char temp_Pk[1000000];
      int i_k__p, i_k__p2;
      {
            FILE *hack_k__p = fopen("C:\\Ava\\back\\coisa_k__p.c", "wb");

            if (hack_k__p)
            {

                  i_k__p = 2;
                  for (; i_k__p < 129; i_k__p++)
                  {

                        strcpy(temp_Pk, "case ");

                        sprintf(temp_Pk + strlen(temp_Pk), "%d:\r\n\r\n", i_k__p);
                        strcat(temp_Pk, "return lgetpor(totalbytes_z, ");

                        for (i_k__p2 = 0; i_k__p2 < i_k__p; i_k__p2++)
                        {
                              strcat(temp_Pk, "bytes__read_thread_z[");
                              sprintf(temp_Pk + strlen(temp_Pk), "%d] + ", i_k__p2);
                        }
                        strcat(temp_Pk, " 0);\r\n\r\nbreak;\r\n\r\n");
                        fwrite(temp_Pk, 1, strlen(temp_Pk), hack_k__p);
                  }

                  fclose(hack_k__p);
            }
      }

      exit(27);
      */
      switch (n_threads_z)
      {
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