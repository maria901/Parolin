//2021 amanda & ricardo


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

#include "arp.h"
#include "arp_2.h"
//functions

void
trocadordebackslashfrente(char *path);

void
trocadordebackslashtras(char *path);

extern void
pedro_dprintf
(
  int amanda_level,
  char *format, ...
);

char *
strsep(char **stringp, const char *delim);

extern  enum mode_is_include_or_exclude mode_is_include_or_exclude__;
extern  bool recurse_on_subfolders_arp;
extern  char archive_name_array_filename                          [];
extern  char global_patern_ar                                     [];
extern  int fatal_exit_k;
extern  int archive;
extern  int64_t ricrdo_bytes_read;
extern  char error_message_k                                      [];
int64_t real_VAL_filesize;

__int64 _lseeki64(
  int fd,
  __int64 offset,
  int origin
  );

__int64 _telli64(
  int handle
  );

static int len_arp;

#define AMANDA_SIZE__ (1 << 16) * 2

extern int init_decoder_z;
extern FILE *              decoder_file_z;

/**
 * VAL based function, it will parse a VAL file and
 * make it ready to be used by the folder and file
 * extraction rountines
 *
 * @param my_VAL_data
 *
 * @return ARP_NOMORE if no more data is available or
 * ARP_DECODED if more data is available
 *
 */
int decode_VAL_arp(VAL_data * my_VAL_data)
{
  char buffer_in[1024] = { 0 };
  char flg_string_arp[300];
  char four_buffer_z[4];
  char identificador_arp[300];
  char int_value_arp[300];
  char slice_VAL;
  int counter_VAL;
  int flg_arp;
  int pass_VAL;
  int64_t int_converted;
  int64_t temp_long_arp;

  char * get_data = buffer_in;

  my_VAL_data->VAL_timestamp64 = 0;
  my_VAL_data->VAL_is_encrypted = 0;

  if (init_decoder_z)
    {
      len_arp = setvbuf(decoder_file_z, NULL,
                        _IOFBF, 4096);

      len_arp = fread(four_buffer_z, 1, 4, decoder_file_z);

      if (4 != len_arp)
        {
          return ARP_NOMORE;
        }

      init_decoder_z = 0;
    }

  counter_VAL = 0;

  len_arp = fread(&slice_VAL, 1, 1, decoder_file_z);

  if (0 > len_arp)
    {
      fatal_exit_k = 27010;
      strcpy(error_message_k, "Cannot read from VAL file");
      return ARP_NOMORE;
    }
  if (0 == len_arp)
    {
      return ARP_NOMORE;
    }

  *get_data++ = slice_VAL;

denovo_VAL:;

  len_arp = fread(&slice_VAL, 1, 1, decoder_file_z);

  if (0 > len_arp)
    {
      fatal_exit_k = 27011;
      strcpy(error_message_k, "Error reading from VAL file");
      return ARP_NOMORE;
    }
  if (0 == len_arp)
    {
      fatal_exit_k = 27012;
      strcpy(error_message_k, "Error reading from VAL file");
      return ARP_NOMORE;
    }

  *get_data++ = slice_VAL;

  if (0 == slice_VAL)
    {
      goto achou_VAL;
    }
  counter_VAL++;

  if (300 == counter_VAL)
    {
      fatal_exit_k = 27013;
      strcpy(error_message_k, "Invalid VAL file");
      return ARP_NOMORE;
    }
  goto denovo_VAL;

achou_VAL:;

  pedro_dprintf(-1, "saiu -> .%s.\n", buffer_in);
  pass_VAL = 0;
  char *token, *str, *tofree;

  tofree = str = strdup(buffer_in);

  identificador_arp[0] = 0;
  int_value_arp    [0] = 0;
  flg_string_arp   [0] = 0;
  while ((token = strsep(&str, " ")))
    {
      pass_VAL++;

      if (1 == pass_VAL)
        {
          strcpy(identificador_arp, token);
        }

      if (2 == pass_VAL)
        {
          strcpy(int_value_arp, token);
        }

      if (3 == pass_VAL)
        {
          strcpy(flg_string_arp, token);
        }

    }
  free(tofree);

  if (3 != pass_VAL)
    {
      fatal_exit_k = 27014;
      strcpy(error_message_k, " 27014 - Invalid VAL file");
      return ARP_NOMORE;
    }

  if (0 == strcmp("VAL_filename", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(0 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(my_VAL_data->VAL_filename, 1, int_converted, decoder_file_z);

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27015;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      trocadordebackslashfrente(my_VAL_data->VAL_filename);

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }

  if (0 == strcmp("VAL_attributes", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(0 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&my_VAL_data->VAL_attributes, 1, int_converted, decoder_file_z);

      assert(4 == int_converted);

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27015;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }

  if (0 == strcmp("VAL_encryption_method", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(0 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&my_VAL_data->VAL_encryption_method, 1, int_converted, decoder_file_z);
      assert(4 == int_converted);

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27015;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }

  if (0 == strcmp("VAL_timestamp", identificador_arp))
    {
      int time_t_old_arp;

      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(0 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&time_t_old_arp, 1, int_converted, decoder_file_z);

      assert(4 == int_converted);

      my_VAL_data->VAL_timestamp = time_t_old_arp;

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27016;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }
/////////////////////////////////////////////////////////////////////
//new entry to check the whole size of the VAL file

    if (0 == strcmp("VAL_p_file_size", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(0 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&real_VAL_filesize, 1, int_converted, decoder_file_z);
      assert(8 == int_converted);

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27016;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }
  
/////////////////////////////////////////////////////////////////////  
  if (0 == strcmp("VAL_timestamp64", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(0 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&my_VAL_data->VAL_timestamp64, 1, int_converted, decoder_file_z);
      assert(8 == int_converted);

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27016;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }
  if (0 == strcmp("VAL_is_dir", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(0 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&my_VAL_data->VAL_is_dir, 1, int_converted, decoder_file_z);
      assert(4 == int_converted);

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27017;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }
  if (0 == strcmp("VAL_is_encrypted", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(0 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&my_VAL_data->VAL_is_encrypted, 1, int_converted, decoder_file_z);
      assert(4 == int_converted);

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27017;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }
  if (0 == strcmp("Val_is_using_filetime", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(1 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&temp_long_arp, 1, int_converted, decoder_file_z);
      assert(8 == int_converted);          //viu?...começa errado fica errado

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27017;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      int_converted = 1;

      len_arp = fread(&my_VAL_data->Val_is_using_filetime, 1, int_converted, decoder_file_z);
      if (len_arp != int_converted)
        {
          fatal_exit_k = 27017;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      assert(true == my_VAL_data->Val_is_using_filetime);

      int_converted = sizeof(FILETIME);

      len_arp = fread(&my_VAL_data->CreationTime___junior, 1, int_converted, decoder_file_z);
      if (len_arp != int_converted)
        {
          fatal_exit_k = 27017;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      len_arp = fread(&my_VAL_data->LastAccessTime_junior, 1, int_converted, decoder_file_z);
      if (len_arp != int_converted)
        {
          fatal_exit_k = 27017;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      len_arp = fread(&my_VAL_data->LastWriteTime__junior, 1, int_converted, decoder_file_z);
      if (len_arp != int_converted)
        {
          fatal_exit_k = 27017;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      get_data = buffer_in;

      counter_VAL = 0;

      goto denovo_VAL;
    }
  if (0 == strcmp("VAL_file_size", identificador_arp))
    {
      flg_arp = strtoll(flg_string_arp, NULL, 10);
      assert(1 == flg_arp);
      int_converted = strtoll(int_value_arp, NULL, 10);

      len_arp = fread(&my_VAL_data->VAL_file_size, 1, int_converted, decoder_file_z);
      assert(8 == int_converted);

      if (len_arp != int_converted)
        {
          fatal_exit_k = 27017;
          strcpy(error_message_k, "Cannot read from VAL file");
          return ARP_NOMORE;
        }

      my_VAL_data->VAL_file_position = _ftelli64(decoder_file_z);

      return ARP_DECODED;
    }
  {
    int32_t deslocador__int;
    int64_t deslocador_long;
    flg_arp = strtoll(flg_string_arp, NULL, 10);
    assert(0 == flg_arp || 1 == flg_arp);

    int_converted = strtoll(int_value_arp, NULL, 10);

    if (0 == flg_arp)
      {
        _fseeki64(
          decoder_file_z,
          int_converted,
          SEEK_CUR
          );
      }
    else
      {
        if (4 == int_converted)
          {
            len_arp = fread(&deslocador__int, 1, int_converted, decoder_file_z);

            _fseeki64(
              decoder_file_z,
              deslocador__int,
              SEEK_CUR
              );
          }
        else if (8 == int_converted)
          {
            len_arp = fread(&deslocador_long, 1, int_converted, decoder_file_z);
            _fseeki64(
              decoder_file_z,
              deslocador_long,
              SEEK_CUR
              );
          }
        else
          {
            assert(0 && "Invalid VAL file");
            exit(1);
          }
      }

    get_data = buffer_in;

    counter_VAL = 0;

    goto denovo_VAL;
  }

  fatal_exit_k = 27018;
  strcpy(error_message_k, "Error in extract function due to bad VAL file");
  return ARP_NOMORE;
}
