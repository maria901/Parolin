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

#ifndef AMANDA__SIZE_ww
#define AMANDA__SIZE_ww ((32767 * 2) + 2)
#endif

#ifndef AMANDA__SIZE_w
#define AMANDA__SIZE_w (32767)
#endif

#include "arp.h"
#include "arp_2.h"
//functions

//8888888888888888888888888888888888888888888888888888888
int size_of_WCHAR_mem_r(char *in_string);
//8888888888888888888888888888888888888888888888888888888
wchar_t *
permissive_name_m_(const wchar_t *wname, WCHAR *ar_temp);

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we
 * provide two functions that are exactly the same because someone may
 * use it in multi-thread code
 *
 * @param pUTF8 the input utf-8 encoded filename
 *
 * @return the static allocated WCHAR array with the filename as wide string
 *
 */
WCHAR *amanda_utf8towide_1_(char *pUTF8, WCHAR *ar_temp);

void trocadordebackslashfrente(char *path);

void trocadordebackslashtras(char *path);

extern void
pedro_dprintf(
    int amanda_level,
    char *format, ...);
// defines
extern bool first_pass_VAL_p;
extern bool enable_encryption_arp_;
extern enum z_encryption_method internal_encryption_z_method;
extern enum mode_is_include_or_exclude mode_is_include_or_exclude__;
extern bool recurse_on_subfolders_arp;
extern char archive_name_array_filename[];
extern char global_patern_ar[];
extern int fatal_exit_k;
extern int archive;
extern int64_t ricrdo_bytes_read;
extern char error_message_k[];

static int ret_arp_;
static bool ret_bool_arp_;
#define fseek _fseeki64
#define ftell _ftelli64

__int64 _lseeki64(
    int fd,
    __int64 offset,
    int origin);

__int64 _telli64(
    int handle);

static int time_t_arp;
static int len_arp;
static int ret_arp;
static char temp_arp[3000];
static int64_t temp_long_arp;

static int64_t VAL_p_file_size = 0;

#define AMANDA_SIZE__ (1 << 16) * 2

static char buffer_arp[AMANDA_SIZE__];

char ready_to_save_char_m_[AMANDA__SIZE];
WCHAR ready_to_save_WCHAR_m_[AMANDA__SIZE_w];

/**
 * VAL based function, it will write information about   
 * a folder to the destination VAL file
 *
 * @param my_VAL_data the struct with the VAL information
 *
 */
void dump_diretory_VAL_arp(VAL_data *my_VAL_data)
{

     if (0 == _telli64(archive))
     {
          ret_arp = _write(archive, "VALP", 4);

          if (4 != ret_arp)
          {
               fatal_exit_k = 27001;
               strcpy(error_message_k, "Cannot write to destination file");
          }
     }
     //////////////////////////////////////////////////////////////////////
     //aqui...
     if (first_pass_VAL_p)
     {
          //Mr. Do

          strcpy(temp_arp, "VAL_p_file_size ");

          sprintf(temp_arp + strlen(temp_arp), "%d 0", 8);

          len_arp = strlen(temp_arp) + 1;

          ret_arp = _write(archive, temp_arp, len_arp);
          if (ret_arp != len_arp)
          {
               fatal_exit_k = 27002;
               strcpy(error_message_k, "Cannot write to destination file");
          }

          len_arp = 8;

          ret_arp = _write(archive, &/*for your pleasure */ VAL_p_file_size, len_arp);
          if (ret_arp != len_arp)
          {
               fatal_exit_k = 27003;
               strcpy(error_message_k, "Cannot write to destination file");
          }

          first_pass_VAL_p = false;
     }

     /****************************************************************************************/

     strcpy(temp_arp, "VAL_filename ");

     strcpy(ready_to_save_char_m_, my_VAL_data->VAL_filename_dl);
     {
          int r_temp = size_of_WCHAR_mem_r(my_VAL_data->VAL_filename_dl);
          WCHAR *ar_temp = (void *)malloc(r_temp);

          wcscpy(ready_to_save_WCHAR_m_, amanda_utf8towide_1_(my_VAL_data->VAL_filename_dl, ar_temp));

          while ((MAX_PATH - 2) < wcslen(amanda_utf8towide_1_(ready_to_save_char_m_, ar_temp)))
          {
               ready_to_save_char_m_[strlen(ready_to_save_char_m_) - 1] = 0;
          }

          free(ar_temp);
     }
     sprintf(temp_arp + strlen(temp_arp), "%d 0", (int)strlen(ready_to_save_char_m_));

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     trocadordebackslashfrente(ready_to_save_char_m_);

     len_arp = strlen(ready_to_save_char_m_);

     ret_arp = _write(archive, ready_to_save_char_m_, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     /****************************************************************************************/
     /****************************************************************************************/
     //modified at 13/september/2021 23:30 to support long paths...
     strcpy(temp_arp, "VAL_filename_v27_v51 ");

     strcpy(ready_to_save_char_m_, my_VAL_data->VAL_filename_dl);

     sprintf(temp_arp + strlen(temp_arp), "%d 0", (int)strlen(ready_to_save_char_m_));

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     trocadordebackslashfrente(ready_to_save_char_m_);

     len_arp = strlen(ready_to_save_char_m_);

     ret_arp = _write(archive, ready_to_save_char_m_, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     /****************************************************************************************/
     strcpy(temp_arp, "VAL_attributes ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     ret_arp = _write(archive, &my_VAL_data->VAL_attributes, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_timestamp ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     time_t_arp = my_VAL_data->VAL_timestamp;

     ret_arp = _write(archive, &time_t_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_timestamp64 ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 8);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 8;

     ret_arp = _write(archive, &my_VAL_data->VAL_timestamp64, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_is_dir ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     time_t_arp = my_VAL_data->VAL_is_dir;

     ret_arp = _write(archive, &time_t_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_is_encrypted ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27035;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     time_t_arp = my_VAL_data->VAL_is_encrypted;

     ret_arp = _write(archive, &time_t_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27036;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "Val_is_using_filetime ");

     sprintf(temp_arp + strlen(temp_arp), "%d 1", 8);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27038;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_arp_ = sizeof(FILETIME);

     len_arp = 8;
     temp_long_arp = 1 + (ret_arp_ * 3);

     ret_arp = _write(archive, &temp_long_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_bool_arp_ = true;

     ret_arp = _write(archive, &ret_bool_arp_, 1);

     if (ret_arp != 1)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_arp = _write(archive, &my_VAL_data->CreationTime___junior, ret_arp_);

     if (ret_arp != ret_arp_)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_arp = _write(archive, &my_VAL_data->LastAccessTime_junior, ret_arp_);

     if (ret_arp != ret_arp_)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_arp = _write(archive, &my_VAL_data->LastWriteTime__junior, ret_arp_);

     if (ret_arp != ret_arp_)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_file_size ");

     sprintf(temp_arp + strlen(temp_arp), "%d 1", 8);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 8;

     ret_arp = _write(archive, &my_VAL_data->VAL_file_size, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }
}

/**
 * VAL based function, it will write to the destination VAL
 * file with the information on the my_VAL_data struct
 *
 * @param my_VAL_data this struct has all the information required
 * to write the VAL information on the destination file
 *
 * @return always 0, the error information and description goes in
 * the fatal_exit_k and error_message_k variables
 *
 */
int dump_regular_file_VAL_arp(int fd_arp, VAL_data *my_VAL_data)
{
     if (0 == _telli64(archive))
     {
          ret_arp = _write(archive, "VALP", 4);

          if (4 != ret_arp)
          {
               fatal_exit_k = 27001;
               strcpy(error_message_k, "Cannot write to destination file");
          }
     }
     /////////////////////////////////////////////////////////////////////
     //aqui

     if (first_pass_VAL_p)
     {
          strcpy(temp_arp, "VAL_p_file_size ");

          sprintf(temp_arp + strlen(temp_arp), "%d 0", 8);

          len_arp = strlen(temp_arp) + 1;

          ret_arp = _write(archive, temp_arp, len_arp);
          if (ret_arp != len_arp)
          {
               fatal_exit_k = 27002;
               strcpy(error_message_k, "Cannot write to destination file");
          }

          len_arp = 8;

          ret_arp = _write(archive, &VAL_p_file_size, len_arp);
          if (ret_arp != len_arp)
          {
               fatal_exit_k = 27003;
               strcpy(error_message_k, "Cannot write to destination file");
          }
          first_pass_VAL_p = false;
     }

     ////////////////////////////////////////////////////////////////////

     strcpy(temp_arp, "VAL_filename ");

     strcpy(ready_to_save_char_m_, my_VAL_data->VAL_filename_dl);
     {
          /**
           * @brief oi
           * 
           */
          int r_temp = size_of_WCHAR_mem_r(my_VAL_data->VAL_filename_dl);
          WCHAR *ar_temp = (void *)malloc(r_temp);

          wcscpy(ready_to_save_WCHAR_m_, amanda_utf8towide_1_(my_VAL_data->VAL_filename_dl, ar_temp));

          while ((MAX_PATH - 2) < wcslen(amanda_utf8towide_1_(ready_to_save_char_m_, ar_temp)))
          {
               ready_to_save_char_m_[strlen(ready_to_save_char_m_) - 1] = 0;
          }

          free(ar_temp);
     }
     sprintf(temp_arp + strlen(temp_arp), "%d 0", (int)strlen(ready_to_save_char_m_));

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = strlen(ready_to_save_char_m_);

     ret_arp = _write(archive, ready_to_save_char_m_, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }
     /************************************************************************************************************/

     strcpy(temp_arp, "VAL_filename_v27_v51 ");

     strcpy(ready_to_save_char_m_, my_VAL_data->VAL_filename_dl);

     sprintf(temp_arp + strlen(temp_arp), "%d 0", (int)strlen(ready_to_save_char_m_));

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     //trocadordebackslashfrente(ready_to_save_char_m_);

     len_arp = strlen(ready_to_save_char_m_);

     ret_arp = _write(archive, ready_to_save_char_m_, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     /************************************************************************************************************/

     strcpy(temp_arp, "VAL_attributes ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     ret_arp = _write(archive, &my_VAL_data->VAL_attributes, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_encryption_method ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     ret_arp = _write(archive, &my_VAL_data->VAL_encryption_method, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_timestamp ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     time_t_arp = my_VAL_data->VAL_timestamp;

     ret_arp = _write(archive, &time_t_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_timestamp64 ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 8);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 8;

     ret_arp = _write(archive, &my_VAL_data->VAL_timestamp64, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_is_dir ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     time_t_arp = my_VAL_data->VAL_is_dir; //redundant...

     ret_arp = _write(archive, &time_t_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_is_encrypted ");

     sprintf(temp_arp + strlen(temp_arp), "%d 0", 4);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27038;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 4;

     time_t_arp = my_VAL_data->VAL_is_encrypted;

     ret_arp = _write(archive, &time_t_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "Val_is_using_filetime ");

     sprintf(temp_arp + strlen(temp_arp), "%d 1", 8);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27038;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_arp_ = sizeof(FILETIME);

     len_arp = 8;
     temp_long_arp = 1 + (ret_arp_ * 3);

     ret_arp = _write(archive, &temp_long_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_bool_arp_ = true;

     ret_arp = _write(archive, &ret_bool_arp_, 1);

     if (ret_arp != 1)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_arp = _write(archive, &my_VAL_data->CreationTime___junior, ret_arp_);

     if (ret_arp != ret_arp_)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_arp = _write(archive, &my_VAL_data->LastAccessTime_junior, ret_arp_);

     if (ret_arp != ret_arp_)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     ret_arp = _write(archive, &my_VAL_data->LastWriteTime__junior, ret_arp_);

     if (ret_arp != ret_arp_)
     {
          fatal_exit_k = 27039;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     strcpy(temp_arp, "VAL_file_size ");

     sprintf(temp_arp + strlen(temp_arp), "%d 1", 8);

     len_arp = strlen(temp_arp) + 1;

     ret_arp = _write(archive, temp_arp, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27002;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     len_arp = 8;

     ret_arp = _write(archive, &my_VAL_data->VAL_file_size, len_arp);
     if (ret_arp != len_arp)
     {
          fatal_exit_k = 27003;
          strcpy(error_message_k, "Cannot write to destination file");
     }

     {

          int64_t remaining_arp = my_VAL_data->VAL_file_size;
          int len_arp;
          int len_arp_w;
          int len_fatia;

     return_aqui_arp:;

          len_fatia = min(remaining_arp, AMANDA_SIZE__);

          len_arp = _read(fd_arp, buffer_arp, len_fatia);

          if (-1 == len_arp)
          {
               fatal_exit_k = 27004;
               strcpy(error_message_k, "Cannot read from input file");
               goto saida_arp;
          }

          if (len_arp)
          {
               if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
               {
                    ricrdo_bytes_read += len_arp / 2;
               }
               else
               {
                    ricrdo_bytes_read += len_arp;
               }

               len_arp_w = _write(archive, buffer_arp, len_arp);

               if (len_arp_w != len_arp)
               {
                    fatal_exit_k = 27005;
                    strcpy(error_message_k, "Cannot write to VAL file");
                    goto saida_arp;
               }

               remaining_arp -= len_arp;
               goto return_aqui_arp;
          }
          else
          {
               if (0 != remaining_arp)
               {
                    fatal_exit_k = 27006;
                    strcpy(error_message_k, "Cannot read all data from input file\n");
               }
          }
     }

saida_arp:;

     return 0;
}
