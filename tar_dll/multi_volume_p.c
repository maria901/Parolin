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

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

///////////////////////////////
//defines

#define CHUNK_P (1 << 17)

int64_t slice_in_bytes_p = 0;

///////////////////////////////
//functions declared

char *
ar_gettemppath_z(void);

///////////////////////////////
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
/*
{
	static WCHAR ricardo_k[1024];

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, 1024);
	return ricardo_k;
}
*/
/**
 * To get the file size, filename is utf-8
 *
 * @param infile_ar the input file
 *
 * @return the size of the file or 0 in case of error or if the file is empty, if you need
 * to know whether the file do exist use ispathfile function
 *
 */
__int64
getfilesize_ar(char *infile_ar);
/*
{
	__int64 ret;
	FILE *myfile;

	if ((myfile = _wfopen(amanda_utf8towide_1_(infile_ar), L"rb")) == NULL)
	{
		return 0;
	}
	ret = _fseeki64(myfile, 0, SEEK_END);
	ret = _ftelli64(myfile);
	fclose(myfile);
	return ret;
}
*/
/**
 * It will return the last occurrence of a string inside the string
 *
 * @param s1 the string to search, example: strrstr("my string to search", "string") it will return the
 * initial address of 'string'
 *
 * @param s2 the string to search inside s1
 *
 * @return a pointer if the string was found or NULL otherwise
 *
 */
char *
strrstr(char *s1, char *s2);
/*
{
  char *sc2, *psc1, *ps1;
  if (*s2 == '\0')
    {
      return((char *)s1);
    }
  ps1 = s1 + strlen(s1);
  while (ps1 != s1)
    {
      --ps1;
      for (psc1 = ps1, sc2 = s2;;)
        {
          if (*(psc1++) != *(sc2++))
            {
              break;
            }
          else if (*sc2 == '\0')
            {
              return((char *)ps1);
            }
        }
    }
  return((char *)((void *)0));
}
*/

/**
 * It will split the path in folder and file (Windows based),
 * UNC capable too
 *
 * @param path the input path
 *
 * @param onlypath only the path, can be NULL if not required
 *
 * @param onlyfilename only the filename, can be NULL if not required
 *
 * @return always 0
 *
 */
int stripfilenameandpath(char *path, char *onlypath, char *onlyfilename);
/*
{
  char*ptr;

  ptr = strrstr(path, "\\");

  if (ptr)
    {
      if (onlypath)
        {
          strcpy(onlypath, path),
          onlypath[ptr - path] = 0;
        }

      if (onlyfilename)
        {
          strcpy(onlyfilename, &path[ptr - path + 1]);
        }
    }
  else
    {
      if (onlypath)
        {
          strcpy(onlypath, "");
        }
      if (onlyfilename)
        {
          strcpy(onlyfilename, path);
        }
    }

  return 0;
}
*/

void __fastcall get_extension_p(char *filename_p, char *extension_p)
{

	char *ptr_p;
	static char filename_copy_p[1027];
	static char filename_copy_2_p[1027];

	strcpy(filename_copy_2_p, filename_p);

	ptr_p = filename_copy_2_p;

	while (*ptr_p)
	{
		if ('/' == *ptr_p)
		{
			*ptr_p = '\\';
		}
		ptr_p++;
	}

	stripfilenameandpath(filename_copy_2_p, NULL, filename_copy_p);

	ptr_p = strrstr(filename_copy_p, ".");

	if (ptr_p)
	{
		strcpy(extension_p, ptr_p + 1);
	}
	else
	{
		extension_p[0] = 0;
	}

	return;
}

int __fastcall detect_multi_volume_p(char *filename_utf_8_p, char *adjusted_filename_in_temp_p)
{
	//int    position_p             ;
	//char * pointer_char_p         ;
	FILE *my_input_file = NULL;
	FILE *my_file_p = NULL;
	char *ptr_p;
	char *buf_p;
	static char constructed_chunk_p[AMANDA__SIZE];
	static char temp_folder_name_p[AMANDA__SIZE];
	static char first_chunk_p[AMANDA__SIZE];
	static char the_extension_p[AMANDA__SIZE];
	char temp_p[300];
	int i_p;
	int counter_p;
	int return_value_p = 0;
	int len_p;
	int check_write_p;
	bool found_p = false;
	bool did_p = false;
	/*

			vamos ver as extensoes primeiro...

	*/

	buf_p = malloc(CHUNK_P);
	adjusted_filename_in_temp_p[0] = 0;

	if (0 == constructed_chunk_p[0] && 1 == constructed_chunk_p[0])
	{
		return 0;
	}

	get_extension_p(filename_utf_8_p, the_extension_p);

	if (strlen(the_extension_p) && 3 == strlen(the_extension_p))
	{
		for (i_p = 1; i_p < 100; i_p++)
		{

			sprintf(temp_p, "%03d", i_p);

			if (0 == strcmp(the_extension_p, temp_p))
			{

				found_p = true;
				break;
			}
		}
	}

	if (found_p)
	{
		counter_p = 1;

		if (-1 == counter_p)
		{

			return false;
		}
	retorno_p:;

		strcpy(first_chunk_p, filename_utf_8_p);

		ptr_p = strrstr(first_chunk_p, ".");

		*ptr_p = 0;

		if (0 == strlen(adjusted_filename_in_temp_p))
		{

			stripfilenameandpath(first_chunk_p, NULL, adjusted_filename_in_temp_p);

			strcpy(temp_folder_name_p, ar_gettemppath_z());
			//strcat(temp_folder_name_p, "\\");

			if ('\\' != temp_folder_name_p[strlen(temp_folder_name_p) - 1])
			{
				strcat(temp_folder_name_p, "\\");
			}

			strcat(temp_folder_name_p, adjusted_filename_in_temp_p);
			strcpy(adjusted_filename_in_temp_p, temp_folder_name_p);

			pedro_dprintf(-1, "file in temp folder %s\n", adjusted_filename_in_temp_p);

			//vai abrir o arquivo...

			{
				WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
				WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

				my_file_p = _wfopen(permissive_name_m_(amanda_utf8towide_1_(adjusted_filename_in_temp_p, ar_temp), ar_temp2), L"wb");

				free(ar_temp);
				free(ar_temp2);
			}
			if (!my_file_p)
			{

				return_value_p = 5112;
				strcpy(error_message_k, "Cannot open temp file to write");
				goto saida_p;
			}
		}

		pedro_dprintf(-1, "ajustado %s\n", first_chunk_p);

		sprintf(first_chunk_p + strlen(first_chunk_p), ".%03d", counter_p);

		pedro_dprintf(-1, "final %s\n", first_chunk_p);
		{
			WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
			WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

			my_input_file = _wfopen(permissive_name_m_(amanda_utf8towide_1_(first_chunk_p, ar_temp), ar_temp2), L"rb");

			free(ar_temp);
			free(ar_temp2);
		}
		if (!my_input_file)
		{
			if (false == did_p)
			{

				return_value_p = 5113;
				pedro_dprintf(-1, "Cannot find first file to join\n");
				strcpy(error_message_k, "Cannot find first file to join");

				fclose(my_file_p);
				my_file_p = NULL;
				{
					WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
					WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

					_wunlink(permissive_name_m_(amanda_utf8towide_1_(adjusted_filename_in_temp_p, ar_temp), ar_temp2));

					free(ar_temp);
					free(ar_temp2);
				}
				//goto saida_p;
			}
			goto saida_p;
		}
		did_p = true;

	again_p:;

		len_p = fread(buf_p, 1, CHUNK_P, my_input_file);

		check_write_p = fwrite(buf_p, 1, len_p, my_file_p);

		if (check_write_p != len_p)
		{
			return_value_p = 5114;
			pedro_dprintf(-1, "Cannot write to temporary file\n");
			strcpy(error_message_k, "Cannot write to temporary file");
			goto saida_p;
		}

		if (len_p)
		{
			goto again_p;
		}

		fclose(my_input_file);
		my_input_file = NULL;
		counter_p++;
		goto retorno_p;
	}

	pedro_dprintf(-1, "ï¿½ multi-volume %d\n", (int)found_p);

	if (-1 == return_value_p)
	{
		goto saida_p;
	}

saida_p:;

	free(buf_p);
	if (my_file_p)
	{
		fclose(my_file_p);
	}
	if (my_input_file)
	{
		fclose(my_input_file);
	}
	if (0 == return_value_p && did_p)
	{

		return 1;
	}

	return return_value_p; //maybe an error
}

int __fastcall split_in_multiple_volumes_p(char *filename_utf_8_p)
{

	int len_p;
	int return_value_p = 0;
	int ret_arp_;
	int counter_p = 0;
	int check_write_p;
	int64_t remaining_p;
	int64_t remaining_slice_p;
	FILE *input__p = NULL;
	FILE *output_p = NULL;
	char out_file_p[AMANDA__SIZE];
	char *temp_data_p = NULL;
	/*
     {
	  char extension_p[300] = {0};
	  get_extension_p(filename_utf_8_p, extension_p);

	  pedro_dprintf(-1, "pegou extensao .%s.\n", extension_p);	  
     }
*/
	int64_t original_size_p = getfilesize_ar(filename_utf_8_p);

	if (NULL == output_p && NULL != output_p &&
		remaining_p && ret_arp_) //to make compiler happy
	{
		return -27;
	}
	pedro_dprintf(-1, "dentro, sizes %lld %lld\n",
				  slice_in_bytes_p,
				  original_size_p);

	if (0 != slice_in_bytes_p && 0 != original_size_p)
	{
		if (original_size_p > slice_in_bytes_p)
		{
			remaining_p = original_size_p;

			temp_data_p = malloc(CHUNK_P);
			{
				WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
				WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

				input__p = _wfopen(permissive_name_m_(amanda_utf8towide_1_(filename_utf_8_p, ar_temp), ar_temp2), L"rb");

				free(ar_temp);
				free(ar_temp2);
			}

			if (!input__p)
			{

				return_value_p = 5101;
				strcpy(error_message_k, "Cannot open output file to split");
				goto saida_p;
			}

			while (1)
			{
				counter_p++;

				strcpy(out_file_p, filename_utf_8_p);

				sprintf(out_file_p + strlen(out_file_p),
						".%03d",
						counter_p + 1);
				{
					WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
					WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

					_wunlink(permissive_name_m_v27(amanda_utf8towide_1_(out_file_p, ar_temp), ar_temp2));

					free(ar_temp);
					free(ar_temp2);
				}
				strcpy(out_file_p, filename_utf_8_p);

				sprintf(out_file_p + strlen(out_file_p),
						".%03d",
						counter_p);

				pedro_dprintf(-1, "saiu %s\n", out_file_p);
				{
					WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
					WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

					output_p = _wfopen(permissive_name_m_(amanda_utf8towide_1_(out_file_p, ar_temp), ar_temp2), L"wb");

					free(ar_temp);
					free(ar_temp2);
				}

				if (output_p)
				{
					remaining_slice_p = slice_in_bytes_p;

				more_data_p:;

					len_p = fread(temp_data_p, 1, min(remaining_slice_p, CHUNK_P), input__p);

					check_write_p = fwrite(temp_data_p, 1, len_p, output_p);

					if (check_write_p != len_p)
					{
						return_value_p = 5102;
						strcpy(error_message_k, "Cannot write to output file");
						goto saida_p;
					}

					remaining_slice_p -= len_p;
					remaining_p -= len_p;

					if (0 == remaining_p)
					{
						pedro_dprintf(-1, "terminou split \n");
						fclose(input__p);
						input__p = NULL;
						{
							WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
							WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

							_wunlink(permissive_name_m_(amanda_utf8towide_1_(filename_utf_8_p, ar_temp), ar_temp2));

							free(ar_temp);
							free(ar_temp2);
						}

						goto saida_p;
					}
					if (0 != len_p)
					{
						goto more_data_p;
					}

					fclose(output_p);
					output_p = NULL;
				}
				else
				{
					return_value_p = 5104;
					strcpy(error_message_k, "Cannot open output file to write");
					goto saida_p;
				}
				/*
		    if(10 == counter_p)
		    {
			 pedro_dprintf(-1, "limitado a dez chunks\n");
			 break;
		    }
		    */
			}
		}
	}

saida_p:;

	if (input__p)
	{
		fclose(input__p);
	}
	if (output_p)
	{
		fclose(output_p);
	}
	if (temp_data_p)
	{
		free(temp_data_p);
	}
	return return_value_p;
}

int __stdcall split_compressed_file_p(int64_t slice_in_bytes_p_)
{
	slice_in_bytes_p = slice_in_bytes_p_;

	if (0 > slice_in_bytes_p)
	{

		slice_in_bytes_p = 0;
	}

	return 0;
}
