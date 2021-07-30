//amanda & MathMan 2021 May

 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *                                                                                *
  *      Licensa de Cópia (C) <202*>  <Corporação do Trabalho Binário>             *
  *                                                                                *
  *   Este programa é software livre: você pode redistribuir isto e/ou modificar   *
  *   isto sobre os termos do GNU Licensa Geral Pública como publicado pela        *
  *   Fundação de Software Livre, tanto a versão 3 da Licensa, ou                  *
  *   (dependendo da sua opção) qualquer versão posterior.                         *
  *                                                                                *
  *   Este programa é distribuído na esperança que isto vai ser útil,              *
  *   mas SEM QUALQUER GARANTIA; sem até mesmo a implicada garantia de             *
  *   COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
  *   Licensa Geral Pública para mais detalhes.                                    *
  *                                                                                *
  *   Você deve ter recebido uma cópia da LICENSA GERAL PUBLICA                    *
  *       e a GNU Licensa Pública Menor junto com este programa                    *
  *       Se não, veja <http://www.gnu.org/licenses/>.                             *
  *                                                                                *
  *   Suporte: https://arsoftware.net.br/binarywork ____________________           *
  *   Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/           *
  *             http://nomade.sourceforge.net/binarywork/ ______________            *
  *                                                                                *
  *       e-mails direto dos felizes programadores:                                *
  *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
  *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
  *                                                                                *
  *       contato imediato(para uma resposta muita rápida) WhatsApp                *
  *       (+55)41 9627 1708 - isto está sempre ligado                              *
  *                                                                                *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include  <windows.h>
#include   <stdint.h>
#include    <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include     <time.h>
#include    <errno.h>
#include    <fcntl.h>
#include    <ctype.h>
#include     <math.h>
#include   <wctype.h>
#include    <wchar.h>
#include   <stdarg.h>
#include   <stddef.h>
#include   <setjmp.h>
#include   <locale.h>
#include   <signal.h>
#include   <limits.h>
#include    <float.h>
#include   <iso646.h>

#undef NDEBUG
#include   <assert.h>

#include  <stdbool.h>

#include  <process.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

#include "pedro.c"

enum amanda_commands {
	AAKP_CLEAR,
	AAKP_LIST_PROCESS,
	AAKP_LIST_FINISH,
	AAKP_EXTRACT_PROCESS,
	AAKP_EXTRACT_FINISH,
	AAKP_ERROR,
	AAKP_CREATE_ERROR,
	AAKP_CREATE_WARNING,
	AAKP_CREATE_FINISH,
	AAKP_CREATE_PROCESS
};

int       * Isdir_k_ar_p       = NULL;
int       * Second_k_ar_p      = NULL;
int       * Minute_k_ar_p      = NULL;
int       * Hour_k_ar_p        = NULL;
int       * Year_k_ar_p        = NULL;
int       * Month_k_ar_p       = NULL;
int       * Day_k_ar_p         = NULL;
__int64   * Size_k_ar_p        = NULL;
char      * filename_k_ar_p    = NULL;
int       * Numdir_k_ar_p      = NULL;
int       * Numfiles_k_ar_p    = NULL;
char      * typeflag_ar__p     = NULL;

int __stdcall get_tar_info_libarchive_i
(
	int       * Isdir_k_ar,
	int       * Second_k_ar,
	int       * Minute_k_ar,
	int       * Hour_k_ar,
	int       * Year_k_ar,
	int       * Month_k_ar,
	int       * Day_k_ar,
	__int64   * Size_k_ar,
	char      * filename_k_ar,
	int       * Numdir_k_ar,
	int       * Numfiles_k_ar,
	char      * typeflag_ar_
)
{

     Isdir_k_ar_p      = Isdir_k_ar    ;
     Second_k_ar_p     = Second_k_ar   ;
     Minute_k_ar_p     = Minute_k_ar   ;
     Hour_k_ar_p       = Hour_k_ar     ;
     Year_k_ar_p       = Year_k_ar     ;
     Month_k_ar_p      = Month_k_ar    ;
     Day_k_ar_p        = Day_k_ar      ;
     Size_k_ar_p       = Size_k_ar     ;
     filename_k_ar_p   = filename_k_ar ;
     Numdir_k_ar_p     = Numdir_k_ar   ;
     Numfiles_k_ar_p   = Numfiles_k_ar ;
     typeflag_ar__p    = typeflag_ar_  ;

     return 0;
}


static void
trocadordebackslashfrente(char *path);

extern int is_encrypted_i;
extern char zip_description_i[];

static bool mode_is_extract_i = false;

int seven_zip_errors_i;

int64_t recurse_on_subfolders__i;

extern int        Numdir_k_ar_;
extern int        Numfiles_k_ar_;

typedef int (__stdcall * tar_list_function_ar)(int clear_flag_k);

static int * files_i   = NULL;
static int * folders_i = NULL;

static char * extracting_filename_i;
static char * warning_info_i;
static char * creating_folder_maria_i;

bool * extract_pause__flag_i = NULL;
bool * extract_cancel_flag_i = NULL;

tar_list_function_ar tar_list_function_i_global = NULL;
tar_list_function_ar tar_list_function_i_extract = NULL;

int __stdcall set_info_libarchive_i
(
	int        Isdir_k_ar,
	int        Second_k_ar,
	int        Minute_k_ar,
	int        Hour_k_ar,
	int        Year_k_ar,
	int        Month_k_ar,
	int        Day_k_ar,
	__int64    Size_k_ar,
	char    *  filename_k_ar,
	int        Numdir_k_ar,
	int        Numfiles_k_ar,
	char    *  typeflag_ar_
)
{

     trocadordebackslashfrente(filename_k_ar);
     if(false == mode_is_extract_i)
     {
     
	  if(NULL != tar_list_function_i_global)
	  {
	       (*Isdir_k_ar_p)      = Isdir_k_ar    ;
	       (*Second_k_ar_p)     = Second_k_ar   ;
	       (*Minute_k_ar_p)     = Minute_k_ar   ;
	       (*Hour_k_ar_p)       = Hour_k_ar     ;
	       (*Year_k_ar_p)       = Year_k_ar     ;
	       (*Month_k_ar_p)      = Month_k_ar    ;
	       (*Day_k_ar_p)        = Day_k_ar      ;
	       (*Size_k_ar_p)       = Size_k_ar     ;

	       if(Isdir_k_ar)
	       {
		    if('/' != filename_k_ar[strlen(filename_k_ar) -1])
		    {

			 strcat(filename_k_ar, "/");
					
		    }
	       }
	       
	       strcpy(filename_k_ar_p, filename_k_ar);
	       (*Numdir_k_ar_p)     = Numdir_k_ar   ;
	       (*Numfiles_k_ar_p)   = Numfiles_k_ar ;
	       strcpy(typeflag_ar__p, typeflag_ar_) ;
	  
	       tar_list_function_i_global(AAKP_LIST_PROCESS);
	  }
     
     }
     else
     {
	  
	  if(Isdir_k_ar)
	  {
	       /*
	       if('/' != filename_k_ar[strlen(filename_k_ar) -1])
	       {

		    strcat(filename_k_ar, "/");
					
	       }
	       */
	       
	       strcpy(extracting_filename_i, "");
	       strcpy(warning_info_i       , "");
	       strcpy(creating_folder_maria_i, filename_k_ar);

	       (* folders_i) ++;
	       
	  }
	  else
	  {
	       
	       (* files_i) ++;
	       
	       strcpy(extracting_filename_i,   filename_k_ar);
	       strcpy(warning_info_i       ,   "");
	       strcpy(creating_folder_maria_i, "");
	      
	  }
	 
	  tar_list_function_i_extract(AAKP_EXTRACT_PROCESS);
	  
     }
     
     return 0;
}

extern int64_t total_size_i;
extern int64_t slice_processed_i;
extern int64_t old_value_i;

extern bool    pause_i          ;
extern bool    cancel_i         ;

int __cdecl main(int , char **);

typedef void (*add_more_one_func) (char *);

add_more_one_func pedro_i = NULL;

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
static WCHAR * amanda_utf8towide_1_(char *pUTF8)
{
	static WCHAR ricardo_k[1024];

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, 1024);
	return ricardo_k;
}

/**
 * It will test the utf-8 encoded path to see if it do exist and is a file
 *
 * @param path utf-8 encoded path to test
 *
 * @return 0 if the path is not a file or valid, 1 if it is a readable
 * file
 *
 */
static int
ispathfile(char *path)
{
  char x[1027];
  int ret;

  strcpy(x, path);
  ret = strlen(x);

  if (!ret)
    {
      return 0;
    }

  ret = GetFileAttributesW(amanda_utf8towide_1_(x));

  if (0xffffffff != ret)
    {
      if (ret & (0x00000010))
        {
          return 0;
        }
      else
        {
          return 1;
        }
    }
  else
    {
      return 0;
    }
}

int __stdcall process_7zip_by_BE(char * command_i)
{

     //not in use this moment...
     
     return 0;
}

void send_data_i(char * data_i)
{
     char temp_i[1027];

     strcpy(temp_i, "Processing ");
     strcat(temp_i, data_i);
     pedro_i(temp_i);
     return;
     
}

bool __stdcall is_valid_7zip_i(char * file_utf8)
{
     bool is_valid_i       =                false;
     FILE * our_file_i;
     char buf_i      [300] =                {0, };

     char signature_i[300] = "7z\xBC\xAF\x27\x1C";
     
     if(ispathfile(file_utf8))
     {

	  our_file_i = _wfopen(amanda_utf8towide_1_(file_utf8), L"rb");

	  if(our_file_i)
	  {
	       fread(buf_i, 1, 6, our_file_i);

	       if(0 == memcmp(buf_i, signature_i, 6))
	       {
		    //pedro_dprintf(0, "é 7zip %s\n", file_utf8);
		    is_valid_i = true;
	       }
	       
	       fclose(our_file_i);
	  }
	  
     }
     //pedro_dprintf(0, "nao é 7zip\n");
     return is_valid_i;
}

static char patern_ar_7zip_i_[20000];
bool   true_if_include_7zip_i_;
int __stdcall  compress_7zip_i(char * tar_filename_ar_7zip_i       ,
			       char * path_with_the_files_ar_7zip_i,
			       char * patern_ar_7zip_i             ,
			       int    recurse_7zip_i               ,
			       bool   true_if_include_7zip_i       ,
			       char * compression_level_7zip_i     ,
			       int    threads_7zip_i               ,
			       char * error_message_k              ,
			       add_more_one_func my_func_i         ,
                               bool   use_encryption_i_            ,
                               char * password_i_                  ,
			       bool also_encrypt_headers_i         )
{
     int  deslocador_i    =        0;
     char pass_internal   [300     ];
     int  return_value_valquiria = 0;

     seven_zip_errors_i = 0;
/*
  freopen("C:\\Ava\\back\\temp\\amanda_compression_stdout.ava",  "w", stdout);
  freopen("C:\\Ava\\back\\temp\\amanda_compression_stderr.ava",  "w", stderr);
*/
     
     strcpy(error_message_k, "<nothing>");

     if(ispathfile(tar_filename_ar_7zip_i))
     {
	  if(false == is_valid_7zip_i(tar_filename_ar_7zip_i))
	  {
	       strcpy(error_message_k, "File passed is not a valid 7zip file");
	       return_value_valquiria = 50027;
	       goto sai_agora_i;
	  }
     }
     
     if(use_encryption_i_)
     {
	  if(!strlen(password_i_))
	  {
	       strcpy(error_message_k, "Since you want to encrypt you need to provide a password, click \'Options\' and set it");
	       return_value_valquiria = 50001;
	       goto sai_agora_i;
	  }
     }
     
     strcpy(pass_internal, "-p");
     strcat(pass_internal, password_i_);
     pedro_dprintf(-1, " pass -%s-\n", pass_internal);
     true_if_include_7zip_i_ = true_if_include_7zip_i;
     strcpy(patern_ar_7zip_i_, patern_ar_7zip_i);
     
     pedro_dprintf(-1, "7zip file %s\n", tar_filename_ar_7zip_i);

     pedro_i = my_func_i;
     total_size_i      =     0;
     old_value_i       =     0;
     slice_processed_i =     0;
     pause_i           = false;
     cancel_i          = false;
     if('\\' != path_with_the_files_ar_7zip_i[strlen(path_with_the_files_ar_7zip_i) - 1])
     {
	  strcat(path_with_the_files_ar_7zip_i, "\\");
     }

     strcat(path_with_the_files_ar_7zip_i, "*");

     static char *my_main_args  [10];

     recurse_on_subfolders__i = recurse_7zip_i;

     if(1)//hack
     {

	  if(use_encryption_i_)
	  {
	       
	       my_main_args[deslocador_i++] = "7zip_main_maria.exe"        ;
	       my_main_args[deslocador_i++] = "a"                          ;
	       my_main_args[deslocador_i++] = "-r"                         ;

	       if(also_encrypt_headers_i)
	       {
		    my_main_args[deslocador_i++] = "-mhe=on"               ;
	       }
	       
	       my_main_args[deslocador_i++] = pass_internal                ;
	       my_main_args[deslocador_i++] = "-sccUTF-8";//UTF-8|WIN|DOS}
	       my_main_args[deslocador_i++] = tar_filename_ar_7zip_i       ;
	       my_main_args[deslocador_i++] = path_with_the_files_ar_7zip_i;

	       return_value_valquiria = main(deslocador_i, (char **) my_main_args);
	       pedro_dprintf(-1, "recurse\n");
	  
	  }
	  else
	  {
	       my_main_args[deslocador_i++] = "7zip_main_maria.exe"        ;
	       my_main_args[deslocador_i++] = "a"                          ;
	       my_main_args[deslocador_i++] = "-r"                         ;
	       my_main_args[deslocador_i++] = "-sccUTF-8";//UTF-8|WIN|DOS}
	       my_main_args[deslocador_i++] = tar_filename_ar_7zip_i       ;
	       my_main_args[deslocador_i++] = path_with_the_files_ar_7zip_i;

	       return_value_valquiria = main(deslocador_i, (char **) my_main_args);
	       pedro_dprintf(-1, "recurse\n");
	  }
     }
     else
     {
	  
	  if(use_encryption_i_)
	  {
	       my_main_args[deslocador_i++] = "7zip_main_maria.exe"        ;
	       my_main_args[deslocador_i++] = "a"                          ;
	       my_main_args[deslocador_i++] = pass_internal                ;
	       
	       if(also_encrypt_headers_i)
	       {
		    my_main_args[deslocador_i++] = "-mhe=on"               ;
	       }
	       
	       my_main_args[deslocador_i++] = "-sccUTF-8";//|WIN|DOS}
	       my_main_args[deslocador_i++] = tar_filename_ar_7zip_i       ;
	       my_main_args[deslocador_i++] = path_with_the_files_ar_7zip_i;
	       return_value_valquiria = main(deslocador_i, (char **) my_main_args);

	       pedro_dprintf(-1, "not recurse\n");
	  }
	  else
	  {
	       my_main_args[deslocador_i++] = "7zip_main_maria.exe"        ;
	       my_main_args[deslocador_i++] = "a"                          ;
	       my_main_args[deslocador_i++] = "-sccUTF-8";//|WIN|DOS}
	       my_main_args[deslocador_i++] = tar_filename_ar_7zip_i       ;
	       my_main_args[deslocador_i++] = path_with_the_files_ar_7zip_i;
	       return_value_valquiria = main(deslocador_i, (char **) my_main_args);

	       pedro_dprintf(-1, "not recurse\n");
	  }
     
     }

     if(70027 == seven_zip_errors_i)
     {

	  strcpy(error_message_k, "Cannot open encrypted archive. Wrong password?");
	  
     }
     else if(0 != return_value_valquiria)
     {
	  return_value_valquiria += 70005;
	  strcpy(error_message_k, "Unexpected compression error");
     }

     pedro_dprintf(-1, "ret %d %s\n", return_value_valquiria, tar_filename_ar_7zip_i);
     pedro_dprintf(-1, "path %s\n", path_with_the_files_ar_7zip_i);
sai_agora_i:;

     if(cancel_i)
     {
	  return_value_valquiria = 119;
	  strcpy(error_message_k, "User cancel");	  
     }
     return return_value_valquiria;
}

static int
getpor_10000_int64_t_ar(int64_t max, int64_t fatia)
{
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

int __stdcall get_progress_7zip_i(void)
{
     int return_value_i = 0;

     return_value_i = getpor_10000_int64_t_ar(total_size_i, slice_processed_i + old_value_i);

     if(0 > return_value_i)
     {
	  return 0;
     }

     if(10000 < return_value_i)
     {

	  return 10000;
	  
     }
     return return_value_i;
}

int __stdcall pause_7zip_i(void)
{
     pause_i = true;
     return 0;
}

int __stdcall resume_7zip_i(void)
{
     pause_i = false;
     return 0;
}

int __stdcall cancel_7zip_i(void)
{
     cancel_i = true;
     return 0;
}
/**
 * Function that matches input str with
 * given wildcard pattern, it is amazing and
 * case sensitive but it is easy to convert to
 * case insensitive
 *
 * @param str the input filename
 *
 * @param pattern the wildcard or filename
 *
 * @param n the size of str
 *
 * @param m the size of pattern
 *
 * @return true if it matchs, false otherwise
 *
 */
static bool strmatch(char str[], char pattern[], int n, int m)
{
  // empty pattern can only match with
  // empty string
  if (m == 0)
    return(n == 0);

  // lookup table for storing results of
  // subproblems
  bool lookup[n + 1][m + 1];

  // initailze lookup table to false
  memset(lookup, false, sizeof(lookup));

  // empty pattern can match with empty string
  lookup[0][0] = true;

  // Only '*' can match with empty string
  for (int j = 1; j <= m; j++)
    if (pattern[j - 1] == '*')
      lookup[0][j] = lookup[0][j - 1];

  // fill the table in bottom-up fashion
  for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
        {
          // Two cases if we see a '*'
          // a) We ignore ‘*’ character and move
          //    to next  character in the pattern,
          //     i.e., ‘*’ indicates an empty sequence.
          // b) '*' character matches with ith
          //     character in input
          if (pattern[j - 1] == '*')
            lookup[i][j]
              = lookup[i][j - 1] || lookup[i - 1][j];

          // Current characters are considered as
          // matching in two cases
          // (a) current character of pattern is '?'
          // (b) characters actually match
          else if (pattern[j - 1] == '?'
                   || str[i - 1] == pattern[j - 1])
            lookup[i][j] = lookup[i - 1][j - 1];

          // If characters don't match
          else
            lookup[i][j] = false;
        }
    }

  return lookup[n][m];
}

/**
 * This function is required to explode a string by delimiters, a Linux fnmatch like function requires it
 *
 */
static char *
strsep(char **stringp, const char *delim)
{
	char *begin, *end;
	begin = *stringp;
	if (begin == NULL)
		return NULL;
	/* Find the end of the token.  */
	end = begin + strcspn(begin, delim);
	if (*end)
	{
		/* Terminate the token and set *STRINGP past NUL character.  */
		*end++ = '\0';
		*stringp = end;
	}
	else
		/* No more delimiters; this is the last token.  */
		*stringp = NULL;
	return begin;
}

/**
 * Function to apply a tolower in th  whole string
 *
 * @param path the string to apply the tolower
 *
 * @return void
 *
 */
static void strtolower_ar(char *path)
{
/*
 * funcao para passar um tolower na string inteira, september 1992
 */
  int ret;
  int i;

  ret = strlen(path);
  if (ret)
    {
      for (i = 0; i < ret; i++)
        {
          path[i] = tolower(path[i]);
        }
      return;
    }
}

static char *
strrstr(char *s1, char *s2);

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
static int
stripfilenameandpath(char *path, char *onlypath, char *onlyfilename)
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
/**
 * It will replace character '/' with '\\' on the given path, very useful
 * to programmers converting code from Unix to Windows... not using cygwin
 *
 * @param path the path to replace the character
 *
 * @return void
 *
 */
static void
trocadordebackslashtras(char *path)
{
  int ret;
  char aqui;
  int i;

  ret = strlen(path);

  if (ret)
    {
      for (i = 0; i < ret; i++)
        {
          aqui = path[i];
          if (aqui == '/')
            {
              path[i] = '\\';
            }
        }
    }
}

static void
trocadordebackslashfrente(char *path)
{
  int ret;
  char aqui;
  int i;

  ret = strlen(path);

  if (ret)
    {
      for (i = 0; i < ret; i++)
        {
          aqui = path[i];
          if (aqui == '\\')
            {
              path[i] = '/';
            }
        }
    }
}


/**
 * It will return the last occurrence of a string inside the string
 *
 * @param s1 the string to search
 *
 * @param s2 the input string
 *
 * @return a pointer if the string was found or NULL otherwise
 *
 */
static char *
strrstr(char *s1, char *s2)
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

bool match_i(char * filename_i)
{

     char my_copy_of_filename_ar[1024];
     char temp_i[1027];
     
     trocadordebackslashtras(filename_i);
     
     strcpy(my_copy_of_filename_ar, filename_i);

     stripfilenameandpath(my_copy_of_filename_ar, NULL, temp_i);

     strcpy(my_copy_of_filename_ar, temp_i);
     
     strtolower_ar(my_copy_of_filename_ar);
     strtolower_ar(patern_ar_7zip_i_);
     {
	  bool achei_o_match = false;
	  const char *my_str_literal = patern_ar_7zip_i_; //"* *.txt *.ini";
	  char *token, *str, *tofree;

	  tofree = str = strdup(my_str_literal);         // We own str's memory now.
	  while ((token = strsep(&str, " ")))
	  {
	       if (strlen(token))
	       {
		    achei_o_match = strmatch(my_copy_of_filename_ar, token,
					     strlen(my_copy_of_filename_ar), strlen(token));
	       }
	       if (achei_o_match)
	       {
		    break;
	       }
	  }

	  free(tofree);

	  if (false == true_if_include_7zip_i_)
	  {
	       if (achei_o_match)
	       {
		    achei_o_match = false;
	       }
	       else
	       {
		    achei_o_match = true;
	       }
	  }

	  if (achei_o_match)
	  {
	       return true;
	  }
     }

     return false;
     
}

int __stdcall uncompress_7zip_i(char *filename_utf_8_p, tar_list_function_ar our_function_list_p, char * error_message_p, char * archive_format_p, char * password_i_)
{
  
     int return_value_valquiria = 0;
     static char *my_main_args  [10];
     char pass_internal[300];

     recurse_on_subfolders__i = 1;
     
     Numdir_k_ar_   = 0;
     Numfiles_k_ar_ = 0;

     is_encrypted_i = 0;
     
     strcpy(zip_description_i, "");
     
     strcpy(archive_format_p, "7zip");
     strcpy(error_message_p , "Everything working my love...");

     seven_zip_errors_i = 0;

     if(our_function_list_p)
     {
     our_function_list_p(AAKP_CLEAR);
     tar_list_function_i_global = our_function_list_p;
     }
     else
     {
	  tar_list_function_i_global = NULL;
     }
     strcpy(pass_internal, "-p");
     if(0 == strlen(password_i_))
     {
	  strcat(pass_internal,  "rico");
     }
     else
	  strcat(pass_internal, password_i_);

/*
 -sa{a|e|s} : set Archive name mode
  -scc{UTF-8|WIN|DOS} : set charset for for console input/output
  -scs{UTF-8|UTF-16LE|UTF-16BE|WIN|DOS|{id}} : set charset for list files
  -scrc[CRC32|CRC64|SHA1|SHA256|*] : set hash function for x, e, h commands
  -sdel : delete files after compression

 */

     
/*
  freopen("C:\\Ava\\back\\temp\\amanda.ava",  "w", stdout);
  freopen("C:\\Ava\\back\\temp\\amanda2.ava", "w", stderr);
*/
     
     
     my_main_args[0] = "7zip_main_maria.exe"        ;
     my_main_args[1] = "l"                          ;
     my_main_args[2] = pass_internal                ;
     my_main_args[3] = "-sccUTF-8";//UTF-8|WIN|DOS}
     my_main_args[4] = /*"d:\\Ava\\back\\my_tar_file_ar222.7z";//*/filename_utf_8_p;

     return_value_valquiria = main(5, (char **) my_main_args);

     if(70027 == seven_zip_errors_i)
     {

	  strcpy(error_message_p, "Cannot open encrypted archive. Wrong password?");
	  
     }
     else if(0 != return_value_valquiria)
     {
	  return_value_valquiria += 70101;
	  strcpy(error_message_p, "Unexpected list error");
     }
     pedro_dprintf(-1, "ret value %d\n", return_value_valquiria);

     if(strlen(zip_description_i))
     {
	  strcat(archive_format_p, " ");
	  strcat(archive_format_p, zip_description_i);
     }
     
     return return_value_valquiria;
     
}
//now extract...

int __stdcall uncompress_7zip_i_extraction (char *filename_utf_8_p, char * password_p, tar_list_function_ar our_function_p, char * error_message_p, char * archive_format_p, char * dir_to_extract_i, char * extracting_filename_ar, char * warning_info, char * creating_folder_maria, bool * extract_pause__flag, bool * extract_cancel_flag, int * folders_ar, int * files_ar)
{

     int return_value_valquiria =     0;
     static char *my_main_args  [10   ];
     char pass_internal         [300  ];
     char path_internal_i       [1027 ];

     seven_zip_errors_i = 0;
     
     recurse_on_subfolders__i = 1;
     
     extract_pause__flag_i = extract_pause__flag;
     
     extract_cancel_flag_i = extract_cancel_flag;     

     (*  extract_pause__flag_i)          = false;
     (*  extract_cancel_flag_i)          = false;
     mode_is_extract_i                   =  true;
     
     our_function_p(AAKP_CLEAR);

     tar_list_function_i_extract = our_function_p       ;

     extracting_filename_i   = extracting_filename_ar   ;
     warning_info_i          = warning_info             ;
     creating_folder_maria_i = creating_folder_maria    ;
     pedro_dprintf(-1, "aqui ok 1\n");

     folders_i = folders_ar;
     files_i   = files_ar  ;

     (* folders_i)      = 0;
     (* files_i  )      = 0;
     
     return_value_valquiria = uncompress_7zip_i(filename_utf_8_p, NULL, error_message_p, archive_format_p, password_p);
     pedro_dprintf(-1, "aqui ok 2\n");

     if(0 == return_value_valquiria)
     {
     	  
	  old_value_i        = 0;
	  slice_processed_i  = 0;
	  total_size_i = 0;

/*
  freopen("C:\\Ava\\back\\temp\\amanda_real_extraction_stdout.ava", "w", stdout);
  freopen("C:\\Ava\\back\\temp\\amanda_real_extraction_stderr.ava", "w", stderr);
*/
     
	  strcpy(pass_internal, "-p");
	  if(0 == strlen(password_p))
	  {
	       strcat(pass_internal,  "rico");
	  }
	  else
	       strcat(pass_internal, password_p);

	  strcpy(path_internal_i, "-o");
	  strcat(path_internal_i, dir_to_extract_i);
     
	  my_main_args[0] = "7zip_main_maria.exe"        ;
	  my_main_args[1] = "x"                          ;//fixed forever...
	  my_main_args[2] = pass_internal                ;
	  my_main_args[3] = path_internal_i              ;
	  my_main_args[4] = "-y"                         ;
	  my_main_args[5] = "-sccUTF-8"                  ;//UTF-8|WIN|DOS}
	  my_main_args[6] = filename_utf_8_p             ;
     
	  return_value_valquiria = main(7, (char **) my_main_args);
	  if(return_value_valquiria)
	  {
	       return_value_valquiria += 80001;
	       strcpy(error_message_p, "Unexpected extraction error");
	  }
     }
     mode_is_extract_i = false;

     if((*  extract_cancel_flag_i))
     {
	  return_value_valquiria = 119;
	  strcpy(error_message_p, "User cancel");
     }
     
     if(90001 == seven_zip_errors_i)
     {
	  return_value_valquiria = 90001;
	  strcpy(error_message_p, "Unsupported compression method, for the moment only LZMA and LZMA2 are implemented in this version");
     }
     
     return return_value_valquiria;
     
}
