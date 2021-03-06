/********************************************************************************
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
 ********************************************************************************
 
      E-mails:                                                                 
      maria@arsoftware.net.br                                                  
      pedro@locacaodiaria.com.br                                               

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito r?pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est? sempre ligado (eu acho...)                 *      
 *                                                                              *
 *******************************************************************************/

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

#include "win64.h"

extern int64_t max_memory_size_k__p;

#define CHUNK 131072 /* to never change again */
/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)

#define AMANDA__SIZE_ww ((32767 * 2) + 2)

/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

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
WCHAR *amanda_utf8towide_1_v27_no_october_2021(char *pUTF8);

wchar_t *
permissive_name_m_v28(const wchar_t *wname, WCHAR *ar_temp);

WCHAR *amanda_utf8towide_1_v28(char *pUTF8, WCHAR *ar_temp);

void pedro_dprintf(
    int amanda_level,
    char *format, ...);
#include "bzlib.h"
//#include                                 "zlib.h" for yout pleasure...
#include "stdio_v2.h"
#include "bzip3_structs_z.h"

extern bool is_multi_thread_z;
extern char temp_files_z[129][2048];
extern char temp_path_z[];
extern int finished;
extern int intcancel;
extern int intpause;
extern int intstatus;
extern int n_threads_z;
extern int thread_return_value_z;
extern int64_t bytes__read_thread_z[129];
extern int64_t totalbytes_z;
uint64_t bytes_in_each_slice_z[129];
uint64_t offset_of_each_slice_z[129];
#ifdef ARP_USE_ENHANCED_STDIO
extern FILE_z *files_to_close_z[129];
#endif

extern __INT32_OR_INT64 my_thread_handle[129];

extern int *cores_used_z;

#include "bzip3_thread.c"
__int64 lffilesize(const char *szFileName); //is utf-8
HANDLE lfopen(const char *szFileName, char *pMode);
void lfclose(HANDLE hFile);
int createtempfilename_and_keep_z(char *path1, char *out_z, WCHAR *signature_z);
int __valquiriacall compress2_uncompress_k_real_mt_z(char *input_z, char *output_z)
{
      my_thread_struct_z *ptr_my_struct_z;
      FILE *dest_z;
      HANDLE dest_2_z;
      FILE *input_file;
      FILE_z *temp_z;
      int ret_z;
      int ret2_z;
      int retvalue_z = 0;
      int n_threads_copy;
      int n_thread_counter;
      int ret_arp;
      int thread_counter = 0;
      int i_z;
      int64_t remaining_z;
      char signature_z[5] = "AR__";
      static char buffer[CHUNK];
      ar_data ar = {0};

      pedro_dprintf(-1, "dentro threads %d\n", n_threads_z);

      thread_return_value_z = 0; //initial thread error value

      totalbytes_z = lffilesize(input_z);

      //n_threads_copy = n_threads_z;

      n_thread_counter = 0;

      is_multi_thread_z = true;
      //primeiro precisa detectar quantos threads foram usados no arquivo compactado
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            input_file = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input_z, ar_temp), ar_temp2), L"rb");

            free(ar_temp);
            free(ar_temp2);
      }
      if (NULL == input_file)
      {
            return 1; //Cannot open input file
      }

      signature_z[3] = '_' - 2; // bzip2 multi-thread signature

      memset(&ar, 0, sizeof(ar));

      while (1)
      {

            ret_arp = fread(&ar, 1, sizeof(ar), input_file);

            if (0 == ret_arp)
            {
                  goto saida_z;
            }

            if (ret_arp != sizeof(ar))
            {
                  retvalue_z = 5;
                  goto saida_z;
            }
            pedro_dprintf(-1, "erro 7 %d %d\n", ar.string[0], signature_z[0]);
            if (0 != memcmp(ar.string, signature_z, 4))
            {
                  pedro_dprintf(-1, "erro 7 %s %s\n", ar.string, signature_z);
                  retvalue_z = 7;
                  goto saida_z;
            }

            ret_arp = fread(&remaining_z, 1, sizeof(remaining_z), input_file);

            if (sizeof(remaining_z) != ret_arp)
            {
                  retvalue_z = 5;
                  goto saida_z;
            }
            bytes_in_each_slice_z[thread_counter] = remaining_z;
            offset_of_each_slice_z[thread_counter] = _ftelli64(input_file);

            pedro_dprintf(-1, "itens %lld %lld\n",
                          bytes_in_each_slice_z[thread_counter],
                          offset_of_each_slice_z[thread_counter]);

            _fseeki64(input_file, remaining_z, SEEK_CUR);

            thread_counter++;
      }

saida_z:;

      fclose(input_file);

      pedro_dprintf(0, "count of threads %d\n", thread_counter);

      if (retvalue_z)
      {
            return 7;
      }
      pedro_dprintf(-1, "passou ok 1\n");
      //exit(27);

      n_threads_z = thread_counter;

      assert(cores_used_z);

      *cores_used_z = n_threads_z;

      pedro_dprintf(-1, "cores %d\n", *cores_used_z);

      n_threads_copy = thread_counter;

      while (n_threads_copy--)
      {
            pedro_dprintf(-1, "running thread %d\n", n_thread_counter);

            ptr_my_struct_z = calloc(1, sizeof(my_thread_struct_z));
            assert(ptr_my_struct_z);

            ptr_my_struct_z->thread_id_z = n_thread_counter;

            if (true)
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ptr_my_struct_z->input_file = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(input_z, ar_temp), ar_temp2), L"rb");

                  free(ar_temp);
                  free(ar_temp2);
            }

            intpause = 0;
            intcancel = 0;

            ptr_my_struct_z->intpause = &intpause;
            ptr_my_struct_z->intcancel = &intcancel;

            bytes__read_thread_z[n_thread_counter] = 0;

            ptr_my_struct_z->bytes_read_z =
                &bytes__read_thread_z[n_thread_counter];

            ptr_my_struct_z->size_of_input_file_z = ptr_my_struct_z->size_of_input_file_copy_z = bytes_in_each_slice_z[n_thread_counter];

            ptr_my_struct_z->offset_z =
                offset_of_each_slice_z[n_thread_counter];

            if (!createtempfilename_and_keep_z(temp_path_z, temp_files_z[n_thread_counter], L"LZ2"))
            {
                  if (0 == thread_return_value_z)
                  {
                        thread_return_value_z = 407; //Cannot create temp file
                  }
            }
            else
            {
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

                  if (NULL == ptr_my_struct_z->dest)
                  {
                        if (0 == thread_return_value_z)
                        {
                              thread_return_value_z = 405; //Cannot open output tempfile
                        }
                  }
            }

            my_thread_handle[n_thread_counter] = (__INT32_OR_INT64)_beginthreadex(NULL, 0, my_thread_function_v27, ptr_my_struct_z, 0, NULL);

            n_thread_counter++;
      }

      for (i_z = 0; i_z < n_threads_z; i_z++)
      {
            WaitForSingleObject((void *)my_thread_handle[i_z], INFINITE);
            CloseHandle((void *)my_thread_handle[i_z]);
            pedro_dprintf(-1, "Close next\n");
      }
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output_z, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);

            free(ar_temp);
            free(ar_temp2);
      }
      //abrir arquivo
      {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            dest_z = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(output_z, ar_temp), ar_temp2), L"wb");

            free(ar_temp);
            free(ar_temp2);
      }
      if (NULL == dest_z)
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
            if (dest_z)
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

                  if (temp_z)
                  {
                        //Mr. Do

                  volta_amanda:;
#ifdef ARP_USE_ENHANCED_STDIO
                        ret_z = fread_z(buffer, 1, CHUNK, temp_z);
#else
                        ret_z = fread(buffer, 1, CHUNK, temp_z);
#endif
                        if (0 > ret_z)
                        {
                              if (0 == thread_return_value_z)
                              {
                                    thread_return_value_z = 5; //Cannot read from input file
                              }
                        }
                        else if (0 == ret_z)
                        {
                              ; //just go by...
                        }
                        else
                        {

                              ret2_z = fwrite(buffer, 1, ret_z, dest_z);

                              if (ret2_z != ret_z)
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
            _wunlink(amanda_utf8towide_1_(temp_files_z[i_z]));
#endif
      }

#ifdef ARP_USE_ENHANCED_STDIO
      for (i_z = 0; i_z < n_threads_z; i_z++)
      {
            free_z(files_to_close_z[i_z]);
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  _wunlink(permissive_name_m_v28(amanda_utf8towide_1_v28(temp_files_z[i_z], ar_temp), ar_temp2));

                  free(ar_temp);
                  free(ar_temp2);
            }
      }
#endif

      //precisa setar isto antes de retornar
      finished = 1; //e depois return

      if (dest_z)
      {
            fclose(dest_z);
      }

      if (!thread_return_value_z)
      {
            dest_2_z = lfopen(output_z, "zb"); //to allow to write to it without deleting the contents
            ret_z = SetFileTime(dest_2_z,      // identifies the file
                                &ar.creation,  // time the file was created
                                NULL,          // time the file was last accessed
                                &ar.lwrite     // time the file was last written
            );
            assert(0 != ret_z);
            if (0 != dest_2_z)
                  lfclose(dest_2_z);
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ret_z = SetFileAttributesW(permissive_name_m_v28(amanda_utf8towide_1_v28(output_z, ar_temp), ar_temp2), ar.attrib);

                  free(ar_temp);
                  free(ar_temp2);
            }
      }
      intstatus = 0;

      pedro_dprintf(-1, "erro que deu %d\n", thread_return_value_z);

      return thread_return_value_z;

      pedro_dprintf(-1, "final amor...%s %d\n", temp_path_z, (int)thread_return_value_z);
      exit(27);
      return 0;
}