/*
 * untgz.c -- Display contents and/or extract file from
 * a gzip'd TAR file
 * written by "Pedro A. Aranda Guti\irrez" <paag@tid.es>
 * adaptation to Unix by Jean-loup Gailly <jloup@gzip.org>

 */
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

#ifdef unix
# include <unistd.h>
#else
# include <direct.h>
# include <io.h>
#endif

#include "zlib.h"

#ifdef WIN32
#  ifndef F_OK
#    define F_OK (0)
#  endif
#  ifdef _MSC_VER
#    define mkdir(dirname,mode) _mkdir(dirname)
#    define strdup(str)         _strdup(str)
#    define unlink(fn)          _unlink(fn)
#    define access(path,mode)   _access(path,mode)
#  else
#    define mkdir(dirname,mode) _mkdir(dirname)
#  endif
#else
#  include <utime.h>
#endif

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

extern char errorstring[255];

extern void geterrorstringrspmakedir (int errorcode, char *path);

extern int rspmakedirUNIX (char *destination, char *path);

extern
void
adicionadordebackslashtras (char *path);

int
additem (uint isdir, uint second,
         uint minute, uint hour,
         uint year, uint month, uint day, char *filename, uint size);


int
getitem (int mode, uint * isdir, uint * second,
         uint * minute, uint * hour,
         uint * year, uint * month, uint * day, char *filename, uint * size);

char *rspgetcurrentdirectory ();
/* Values used in typeflag field.  */



int intfilename;
int intdirectory;




// estrutura  a ser usada










#define REGTYPE  '0'            /* regular file */
#define AREGTYPE '\0'           /* regular file */
#define LNKTYPE  '1'            /* link */
#define SYMTYPE  '2'            /* reserved */
#define CHRTYPE  '3'            /* character special */
#define BLKTYPE  '4'            /* block special */
#define DIRTYPE  '5'            /* directory */
#define FIFOTYPE '6'            /* FIFO special */
#define CONTTYPE '7'            /* reserved */


#define GNUTYPE_DUMPDIR 'D'

/* Identifies the *next* file on the tape as having a long linkname.  */
#define GNUTYPE_LONGLINK 'K'

/* Identifies the *next* file on the tape as having a long name.  */
#define GNUTYPE_LONGNAME 'L'

/* This is the continuation of a file that began on another volume.  */
#define GNUTYPE_MULTIVOL 'M'

/* For storing filenames that do not fit into the main header.  */
#define GNUTYPE_NAMES 'N'

/* This is for sparse files.  */
#define GNUTYPE_SPARSE 'S'

/* This file is a tape/volume header.  Ignore it on extraction.  */
#define GNUTYPE_VOLHDR 'V'

#define BLOCKSIZE 512

struct tar_header
{                               /* byte offset */
	char name[100];         /*   0 */
	char mode[8];           /* 100 */
	char uid[8];            /* 108 */
	char gid[8];            /* 116 */
	char size[12];          /* 124 */
	char mtime[12];         /* 136 */
	char chksum[8];         /* 148 */
	char typeflag;          /* 156 */
	char linkname[100];     /* 157 */
	char magic[6];          /* 257 */
	char version[2];        /* 263 */
	char uname[32];         /* 265 */
	char gname[32];         /* 297 */
	char devmajor[8];       /* 329 */
	char devminor[8];       /* 337 */
	char prefix[155];       /* 345 */
	/* 500 */
};

union tar_buffer
{
	char buffer[BLOCKSIZE];
	struct tar_header header;
};

enum
{ TGZ_EXTRACT = 0, TGZ_LIST };

static char *TGZfname OF ((const char *));
void TGZnotfound OF ((const char *));

int getoct OF ((char *, int));
char *strtime OF ((time_t *));
int ExprMatch OF ((char *, char *));

int makedir OF ((char *));
int matchname OF ((int, int, char **, char *));


int tar OF ((gzFile, int, int, int, char **));

void help OF ((int));


char *prog;

/* This will give a benign warning */

static char *TGZprefix[] = { "\0", ".tgz", ".tar.gz", ".tar", NULL };

/* Return the real name of the TGZ archive */
/* or NULL if it does not exist. */

char *rspopen (char *arquivo);

int rspmakedir (char *path);

int hasinfo = 0;

int flaglist = 0;

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/*variaveis do projeto*/

char rspdestino[255];

extern uint pauseflag;
extern uint cancelflag;
extern uint filesize;
extern uint fileread;

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

static char *TGZfname
OF ((const char *fname))
{
	static char buffer[1024];
	int origlen, i;

	strcpy (buffer, fname);
	origlen = strlen (buffer);

	return buffer;

}

/* help functions */

int
getoct (char *p, int width)
{
	int result = 0;
	char c;

	while (width--)
	{
		c = *p++;
		if (c == ' ')
			continue;
		if (c == 0)
			break;
		result = result * 8 + (c - '0');
	}
	return result;
}

char *
strtime (time_t * t)
{
	struct tm *local;
	static char result[32];

	local = localtime (t);
	sprintf (result, "%2d/%02d/%4d %02d:%02d:%02d",
	         local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
	         local->tm_hour, local->tm_min, local->tm_sec);
	return result;
}

/* regular expression matching */

#define ISSPECIAL(c) (((c) == '*') || ((c) == '/'))

int
ExprMatch (char *string, char *expr)
{
	while (1)
	{
		if (ISSPECIAL (*expr))
		{
			if (*expr == '/')
			{
				if (*string != '\\' && *string != '/')
					return 0;
				string++;
				expr++;
			}
			else if (*expr == '*')
			{
				if (*expr++ == 0)
					return 1;
				while (*++string != *expr)
					if (*string == 0)
						return 0;
			}
		}
		else
		{

			/*basicamente isto verifica se é exatamente igual
			   se for retorna 0 , se nao for retorna 1
			 */

			/*é aqui que deve adicionar aquele escaneador modificado */

			if (*string != *expr)
				return 0;
			if (*expr++ == 0)
				return 1;
			string++;
		}
	}
}

/*falta o criador de itens baseado naquilo que pegar*/

/*

   preciso criar o codigo de wildcard, para poder selecionar se o treco
   pode ou nao pode incluir arquivos completos ou nao

   Sem isto fica dificil de selecionar oque vai ou nao vai ser removido
   ou extraido

   No caso daquilo la ja esta certo porque ja ocorre na inicializacao
   Mas aqui ainda nao esta definido nada

   ë um selector de wildcard que '
   e preciso

 */

void trocadordebackslashtras (char *path);

int stripfilenameandpath (char *path, char *onlypath, char *onlyfilename);

int wildcardselection (const char *path, const char *string1);

int
rspexpression (char *path, char *expre)
{
	// basta chamar a funcao la fora

	return wildcardselection (path, expre);
}

int
matchname (int arg, int argc, char **argv, char *fname)
{
	if (arg == argc)        /* no arguments given (untgz tgzarchive) */
		return 1;

	while (arg < argc)
	{

		if (rspexpression (fname, argv[arg++]))
		{
			/*quando retorna 1 quer dizer que achou o item */
			;       //dprintf ("Vai retornar 1 ");
			// printf ("Dentro de matchname %s %s \n", fname, argv[arg - 1]);
			return 1;
		}
		else
		{

			// ;//dprintf ("Vai retornar 0 \n");
		}
	}

	return 0;               /* ignore this for the moment being */
}

/* Tar file list or extract */

int
tar (gzFile in, int action, int arg, int argc, char **argv)
{
	union tar_buffer buffer;
	int len;
	int err;
	int getheader = 1;
	int remaining = 0;
	FILE *outfile = NULL;
	char fname[BLOCKSIZE];
	time_t tartime;
	time_t tartime2;
	int erroint = 0;
	int already;

	if (action == TGZ_LIST)
		// printf ("     day      time     size                       file\n"
		// " ---------- -------- --------- -------------------------------------\n");
		;
	fileread = 0;
	while (1)
	{

		already = 0;
		if (pauseflag)
		{

			Sleep (50);

			if (cancelflag)
			{
				break;
			}

		}

		if (cancelflag)
		{
			break;
		}

reinicia:

		len = gzread (in, &buffer, BLOCKSIZE);
		if (len < 0)
		{
			;       //dprintf ("%s\n", gzerror (in, &err));
			break;
		}
		/*
		 * Always expect complete blocks to process
		 * the tar information.
		 */
		if (len != BLOCKSIZE)
		{
			;       //dprintf ("gzread: incomplete block read\n");
			erroint = 1;
			break;
		}

		fileread = fileread + len;

		/*
		 * If we have to get a tar header
		 */
		if (getheader == 1)
		{
			/*
			 * if we met the end of the tar
			 * or the end-of-tar block,
			 * we are done
			 */
			if ((len == 0) || (buffer.header.name[0] == 0))
			{
				break;
			}

			if (buffer.header.typeflag != '0'
			    && buffer.header.typeflag != '\0'
			    && buffer.header.typeflag != '1'
			    && buffer.header.typeflag != '2'
			    && buffer.header.typeflag != '3'
			    && buffer.header.typeflag != '4'
			    && buffer.header.typeflag != '5'
			    && buffer.header.typeflag != '6'
			    && buffer.header.typeflag != '7')
			{

				switch (buffer.header.typeflag)
				{
				/*aqui vai mostrar como se efetua a definicao de itens */

				case GNUTYPE_VOLHDR:
					//dprintf ("case GNUTYPE_VOLHDR at position %d \n",
					//fileread - BLOCKSIZE);

					goto reinicia;
					break;
				case GNUTYPE_SPARSE:
					//dprintf ("case GNUTYPE_SPARSE at position %d \n",
					//fileread - BLOCKSIZE);

					break;
				case GNUTYPE_NAMES:
					//  dprintf ("case GNUTYPE_NAMES at position %d \n",
					//fileread - BLOCKSIZE);

					break;
				case GNUTYPE_MULTIVOL:
					// dprintf ("case GNUTYPE_MULTIVOL at position %d \n",
					//fileread - BLOCKSIZE);

					break;
				case GNUTYPE_LONGNAME:
					//dprintf ("case GNUTYPE_LONGNAME at position %d \n",
					//fileread - BLOCKSIZE);

					//  dprintf ("Nome do arquivo antes %s \n",
					//buffer.header.name);
					len = gzread (in, fname, BLOCKSIZE);
					fileread = fileread + len;

					len = gzread (in, &buffer, BLOCKSIZE);
					fileread = fileread + len;
//strcpy(buffer.header.name,buffer2.header.name);

					already = 1;

					// dprintf ("Nome do arquivo depois %s \n", fname);

					//dprintf ("Nome do tipo depois %d %c \n",
					//buffer.header.typeflag,
					//(char) buffer.header.typeflag);

//buffer.header.typeflag=  REGTYPE;

//goto reinicio;

					break;
				case GNUTYPE_LONGLINK:
					//  dprintf ("case GNUTYPE_LONGLINK at position %d \n",
					//fileread - BLOCKSIZE);

					break;
				case GNUTYPE_DUMPDIR:
					// dprintf ("case GNUTYPE_DUMPDIR at position %d \n",
					//fileread - BLOCKSIZE);

					break;

				default:
					goto sai;
					break;

				}

				;
				goto cont;
				;
sai:
				;
				break;
				;
cont:

				;
			}

			tartime = (time_t) getoct (buffer.header.mtime, 12);

			if (already == 0)
			{
				strcpy (fname, buffer.header.name);
			}

			switch (buffer.header.typeflag)
			{
			case DIRTYPE:
				if (action == TGZ_LIST)
					; // printf (" %s     <dir> %s\n", strtime (&tartime), fname);
				if (action == TGZ_EXTRACT)
					//makedir(fname);

					if (rspmakedirUNIX (rspdestino, fname))
					{
						; //;//dprintf("....nao pode criar diretorio... %s \n" , fname);
					}

				break;
			case REGTYPE:
			case AREGTYPE:

				/*se nao tiver nada , aqui é zero */
				remaining = getoct (buffer.header.size, 12);
				if (action == TGZ_LIST)
					; // printf (" %s %9d %s\n", strtime (&tartime), remaining,
				//  fname);
				if (action == TGZ_EXTRACT)
				{
					if ((matchname (arg, argc, argv, fname)))
					{

						outfile = fopen (rspopen (fname), "wb");
						if (outfile == NULL)
						{
							/* try creating directory */
							char *p = strrchr (fname, '/');
							/*se tiver um diretorio é bom criar */
							if (p != NULL)
							{
								*p = '\0';
								//makedir(fname);

								if (rspmakedirUNIX (rspdestino, fname))
								{
									; //;//dprintf("....nao pode criar diretorio... %s \n" , fname);
								}

								/*recuperando depois para poder ser util na utilizacao */
								*p = '/';
								outfile = fopen (rspopen (fname), "wb");
							}
						}

						if (outfile == NULL)
						{
							// dprintf ("%s %s\n",
							//  (outfile) ? "Extracting" :
							// "Couldn't create", fname);
							;
						}
						else
						{
							;
						}

						;
						if (remaining == 0)

						{
							;
							if (outfile != NULL)
							{
								;
								fclose (outfile);

								outfile = NULL;
							}

						}

					}
					else
						outfile = NULL;
				}
				/*
				 * could have no contents
				 */
				getheader = (remaining) ? 0 : 1;
				break;
			default:
				if (action == TGZ_LIST)
					; // printf (" %s     <---> %s\n", strtime (&tartime), fname);
				break;
			}
		}

		else
		{
			unsigned int bytes =
				(remaining > BLOCKSIZE) ? BLOCKSIZE : remaining;

			if ((action == TGZ_EXTRACT) && (outfile != NULL))
			{
				if (fwrite (&buffer, sizeof (char), bytes, outfile) !=
				    bytes)
				{
					//dprintf ("%s : error writing %s skipping...\n", prog,
					//fname);
					fclose (outfile);
					outfile = NULL;
					unlink (fname);
				}
			}
			remaining -= bytes;
			if (remaining == 0)
			{
				getheader = 1;
				if ((action == TGZ_EXTRACT) && (outfile != NULL))
				{
#ifdef WIN32 //estamos em windows ou Linux?...amor
					HANDLE hFile;
					FILETIME ftm, ftLocal;
					SYSTEMTIME st;
					struct tm localt;

					fclose (outfile);
					outfile = NULL;
					localt = *localtime (&tartime);

					hFile =
						CreateFile (rspopen (fname),
						            GENERIC_READ | GENERIC_WRITE, 0,
						            NULL, OPEN_EXISTING, 0, NULL);

					st.wYear = (WORD) localt.tm_year + 1900;
					st.wMonth = (WORD) localt.tm_mon;
					st.wDayOfWeek = (WORD) localt.tm_wday;
					st.wDay = (WORD) localt.tm_mday;
					st.wHour = (WORD) localt.tm_hour;
					st.wMinute = (WORD) localt.tm_min;
					st.wSecond = (WORD) localt.tm_sec;
					st.wMilliseconds = 0;
					SystemTimeToFileTime (&st, &ftLocal);
					LocalFileTimeToFileTime (&ftLocal, &ftm);
					SetFileTime (hFile, &ftm, NULL, &ftm);
					CloseHandle (hFile);

					outfile = NULL;

#endif
				}
			}
		}
	}

	if (outfile != NULL)
	{
		fclose (outfile);
		outfile = NULL;
#ifdef NPRINTF
		dprintf ("estava aberto %s\n", fname);
#endif
	}
	else
	{
#ifdef NPRINTF
		dprintf ("nao estava aberto %s \n", fname);
#endif
	}

	if (gzclose (in) != Z_OK)
	{
#ifdef NPRINTF
		dprintf ("failed gzclose");
#endif
		return 3;
	}
	if (erroint)
	{
		return 8;
	}

	return 0;
}

int
listtar (gzFile in, int aaction, int arg, int argc, char **argv)
{
	static union tar_buffer buffer;
	static union tar_buffer buffer2;
	static int len;
	static int err;
	static int getheader = 1;
	static int remaining = 0;
	static FILE *outfile = NULL;
	static char fname[BLOCKSIZE];
	static time_t tartime;
	static time_t tartime2;
	static int erroint = 0;
	static int action = TGZ_LIST;

	int already;

	int deletelist ();
	int loaded = 0;

pedro_dprintf(0, "dentro de listtar");

	memset (&buffer, 0, BLOCKSIZE);

	memset (fname, 0, BLOCKSIZE);

	erroint = 0;

	action = TGZ_LIST;

	if (action == TGZ_LIST)
		// printf ("     day      time     size                       file\n"
		// " ---------- -------- --------- -------------------------------------\n");
		;
	fileread = 0;
	while (1)
	{

		already = 0;

reinicia:
		len = gzread (in, &buffer, BLOCKSIZE);

reinicio:

		if (len < 0)
		{

#ifdef NPRINTF
			dprintf ("Saiu porque terminou \n");
#endif
			;       //dprintf ("%s\n", gzerror (in, &err));
			break;
		}
		/*
		 * Always expect complete blocks to process
		 * the tar information.
		 */
		if (len != BLOCKSIZE)
		{
			;       //dprintf ("gzread: incomplete block read\n");
#ifdef NPRINTF
			pedro_dprintf ("Saiu porque o len é diferente de blocksize \n");
#endif

pedro_dprintf(0, "Saiu porque o len é diferente de blocksize \n");

			erroint = 1;
			break;
		}

		fileread = fileread + len;

		/*
		 * If we have to get a tar header
		 */
		if (getheader == 1)
		{
			/*
			 * if we met the end of the tar
			 * or the end-of-tar block,
			 * we are done
			 */
			if ((len == 0) || (buffer.header.name[0] == 0))
			{
#ifdef NPRINTF
				dprintf("Saiu porque len == 0 ou buffer.header.name[0] == 0 \n");
#endif
pedro_dprintf(0, "Saiu porque len == 0 ou buffer.header.name[0] == 0 \n");
				break;
			}


pedro_dprintf(0, "buffer.header.typeflag %d %c %s", buffer.header.typeflag, buffer.header.typeflag, buffer.header.magic);

			if (buffer.header.typeflag != '0'
			    && buffer.header.typeflag != '\0'
			    && buffer.header.typeflag != '1'
			    && buffer.header.typeflag != '2'
			    && buffer.header.typeflag != '3'
			    && buffer.header.typeflag != '4'
			    && buffer.header.typeflag != '5'
			    && buffer.header.typeflag != '6'
			    && buffer.header.typeflag != '7')
			{

pedro_dprintf(0, "achou algo");

				switch (buffer.header.typeflag)
				{
				/*aqui vai mostrar como se efetua a definicao de itens */

				case GNUTYPE_VOLHDR:
					// dprintf ("case GNUTYPE_VOLHDR at position %d \n",
					//fileread - BLOCKSIZE);
pedro_dprintf(0, "GNUTYPE_VOLHDR ");
					goto reinicia;
					break;
				case GNUTYPE_SPARSE:
					// dprintf ("case GNUTYPE_SPARSE at position %d \n",
					//fileread - BLOCKSIZE);
pedro_dprintf(0, "GNUTYPE_SPARSE ");
					break;
				case GNUTYPE_NAMES:
					// dprintf ("case GNUTYPE_NAMES at position %d \n",
					//fileread - BLOCKSIZE);
pedro_dprintf(0, "GNUTYPE_NAMES ");
					break;
				case GNUTYPE_MULTIVOL:
					//dprintf ("case GNUTYPE_MULTIVOL at position %d \n",
					//fileread - BLOCKSIZE);
pedro_dprintf(0, "GNUTYPE_MULTIVOL ");
					break;
				case GNUTYPE_LONGNAME:
					// dprintf ("case GNUTYPE_LONGNAME at position %d \n",
					//fileread - BLOCKSIZE);
pedro_dprintf(0, "GNUTYPE_LONGNAME ");
					pedro_dprintf(0, "Nome do arquivo antes %s \n", buffer.header.name);
					
					len = gzread (in, fname, BLOCKSIZE);
					fileread = fileread + len;

					len = gzread (in, &buffer, BLOCKSIZE);
					fileread = fileread + len;
//strcpy(buffer.header.name,buffer2.header.name);

					already = 1;

					//  dprintf ("Nome do arquivo depois %s \n", fname);

					// dprintf ("Nome do tipo depois %d %c \n",
					//buffer.header.typeflag,
					//(char) buffer.header.typeflag);

//buffer.header.typeflag=  REGTYPE;

//goto reinicio;

					break;
				case GNUTYPE_LONGLINK:
					// dprintf ("case GNUTYPE_LONGLINK at position %d \n",
					//fileread - BLOCKSIZE);
pedro_dprintf(0, "GNUTYPE_LONGLINK ");
					break;
				case GNUTYPE_DUMPDIR:
					// dprintf ("case GNUTYPE_DUMPDIR at position %d \n",
					//fileread - BLOCKSIZE);
pedro_dprintf(0, "GNUTYPE_DUMPDIR ");
					break;

				default:
				
				pedro_dprintf(0, "***saiu no default ");
				
					goto sai;
					break;

				}

				;
				goto cont;
				;
sai:
				;
				break;
				;
cont:

				;
			}

			tartime = (time_t) getoct (buffer.header.mtime, 12);

			if (already == 0)
			{
				strcpy (fname, buffer.header.name);
			}
			switch (buffer.header.typeflag)
			{
			case DIRTYPE:
				if (action == TGZ_LIST)
				{

					struct tm *local;

					local = localtime (&tartime);

/*
   local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
            local->tm_hour, local->tm_min, local->tm_sec);
   int
   additem (uint isdir , uint second ,
   uint minute , uint hour ,
   uint year ,uint month,
   uint day ,  char *filename)
 */

					additem (1, local->tm_sec, local->tm_min,
					         local->tm_hour, local->tm_year + 1900,
					         local->tm_mon + 1, local->tm_mday, fname, 0);

					intdirectory++;

					//  dprintf (" %s     <dir> %s\n", strtime (&tartime),
					//fname);

					break;

				}
				if (action == TGZ_EXTRACT)
				{
					break;
				}

			case REGTYPE:
			case AREGTYPE:

				/*se nao tiver nada , aqui é zero */
				remaining = getoct (buffer.header.size, 12);
				if (action == TGZ_LIST)

				{
					struct tm *local;

					local = localtime (&tartime);

					// dprintf (" %s %9d %s\n", strtime (&tartime), remaining,
					//fname);

					additem (0, local->tm_sec, local->tm_min,
					         local->tm_hour, local->tm_year + 1900,
					         local->tm_mon + 1, local->tm_mday, fname,
					         remaining);
					intfilename++;

				}
				if (action == TGZ_EXTRACT)
				{

				}
				/*
				 * could have no contents
				 */
				getheader = (remaining) ? 0 : 1;
				break;
			default:
				if (action == TGZ_LIST)
					//   dprintf (" %s     <---> %s\n", strtime (&tartime),
					//    fname);
					break;
			}
		}
		else
		{
			unsigned int bytes =
				(remaining > BLOCKSIZE) ? BLOCKSIZE : remaining;

			if ((action == TGZ_EXTRACT) && (outfile != NULL))
			{

			}
			remaining -= bytes;
			if (remaining == 0)
			{
				getheader = 1;
				if ((action == TGZ_EXTRACT) && (outfile != NULL))
				{

				}
			}
		}
	}

	if (outfile != NULL)
	{
		fclose (outfile);
		outfile = NULL;
#ifdef NPRINTF
		dprintf ("estava aberto %s\n", fname);
#endif
	}
	else
	{
#ifdef NPRINTF
		dprintf ("nao estava aberto %s \n", fname);
#endif
	}

	if (gzclose (in) != Z_OK)
	{
#ifdef NPRINTF
		dprintf ("failed gzclose");
#endif
		return 3;
	}
	if (erroint)
	{
		return 8;
	}

	return 0;
}

/*isto é que é escrever codigo livre de bugs*/

/* =========================================================== */

void
help (int exitval)
{
	fprintf (stderr,
	         "meu_programinha v 0.1\n"
	         " a sample application of zlib 1.0.4\n\n"
	         "Usage : untgz TGZfile            to extract all files\n"
	         "        untgz TGZfile fname ...  to extract selected files\n"
	         "        untgz -l TGZfile         to list archive contents\n"
	         "        untgz -h                 to display this help\n\n");

}

/* ====================================================================== */

int _CRT_glob = 0;              /* disable globbing of the arguments */

int
mainfinal (int argc, char **argv)
{
	int action = TGZ_EXTRACT;
	int arg = 1;
	char *TGZfile;
	gzFile *f;

	prog = strrchr (argv[0], '\\');
	if (prog == NULL)
	{
		prog = strrchr (argv[0], '/');
		if (prog == NULL)
		{
			prog = strrchr (argv[0], ':');
			if (prog == NULL)
				prog = argv[0];
			else
				prog++;
		}
		else
			prog++;
	}
	else
		prog++;

	if (argc == 1)
	{
		help (0);
		return 0;
	}
	if (strcmp (argv[arg], "-l") == 0)
	{
		action = TGZ_LIST;
		if (argc == ++arg)
		{
			help (0);
			return 0;
		}
	}
	else if (strcmp (argv[arg], "-h") == 0)
	{
		help (0);
		return 0;
	}

	if ((TGZfile = TGZfname (argv[arg])) == NULL)
	{
		;               //dprintf ("Arquivo nao existe \n");
		return 1;
	}

	++arg;
	if ((action == TGZ_LIST) && (arg != argc))
	{
		help (1);
		return 1;
	}

	if (flaglist)
	{
		action = TGZ_LIST;
	}

/*
 *  Process the TGZ file
 */
	switch (action)
	{
	case TGZ_LIST:
	case TGZ_EXTRACT:
	 
	pedro_dprintf(0, "vai abrir %s\n", TGZfile);
		f = gzopen (TGZfile, "rb");
		if (f == NULL)
		{
			pedro_dprintf(0, "%s: Couldn't gzopen %s\n", prog, TGZfile);
			return 5;
		}
		/*Aqui voce pode modificar para abrir nao somente tar gz mas somente arquivos tar tambem */

		if (action == TGZ_LIST)
		{
			
			//aqui 
			
			return (listtar (f, action, arg, argc, argv));
		}
		else
		{
			
			//e aqui
			
			return (tar (f, action, arg, argc, argv));
		}

		break;

	default:

		return (6);     // invalid arguments passed to the function
	}

	return 0;
}

#if 0
int
main ()
{

	int ret;
	char temp[255] = "meuexecutavel";
	char temp2[255] = "file22.tar";
	char temp3[255] = "*.*";
	char *argvv[4];

	strcpy (rspdestino, "c:\\backupfinal");

	ret = rspmakedir (rspdestino);

	if (ret)
	{
		;               //dprintf ("Unable to create the dest foldwer \n");
#ifdef NPRINTF
		dprintf ("Valor do erro %d\n", ret);
#endif
		return 1;
	}

	argvv[0] = temp;
	argvv[1] = temp2;
	argvv[2] = temp3;

	ret = mainfinal (3, argvv);

	return ret;

}

#endif

char *
rspopen (char *arquivo)
{
/*funcao magica trocadora de path inicial*/
	static char temp[255];
	static char temp2[255];
	memset (temp2, 0, 254);
	memset (temp, 0, 254);
	strcpy (temp2, arquivo);

	trocadordebackslashtras (temp2);

	if ((tolower (temp2[1]) == ':') && (tolower (temp2[2]) == '\\'))
	{

		return arquivo;
	}

	if (temp2[0] == '\\' && temp2[1] == '\\')
	{

		return arquivo;
	}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

	strcpy (temp, rspdestino);

	adicionadordebackslashtras (temp);

	strcat (temp, temp2);

	;                       //dprintf ("Path a ser usado %s \n", temp);

	return temp;
}

int
untar (char *filename, char *destination, char *selection)
{

	int ret;
	char temp[255] = "nosso_executavel";
	char temp2[255] = "file2.tar";
	char temp3[255] = "*.c";
	char *argvv[4];

	if (filename == NULL)
	{
		;               //dprintf ("Filename == NULL \n");
		return 2;
	}

	if (destination == NULL)
	{
		;               //dprintf ("destination == NULL \n");
		return 3;
	}

	if (selection == NULL)
	{
		;               //dprintf ("selection == NULL \n");
		return 4;
	}

	if (flaglist)//é isto? calma querido...
	{
		goto pula;
	}

	strcpy (rspdestino, destination);

	ret = rspmakedir (rspdestino);

	if (ret)
	{

		char temp[255];
		;               //dprintf ("Unable to create the dest folder \n");

#ifdef NPRINTF
		dprintf ("Valor do erro %d\n", ret);
#endif
		geterrorstringrspmakedir (ret, temp);

		strcpy (errorstring, temp);

		return 40 + ret;
	}

pula:

	strcpy (temp2, filename);
	strcpy (temp3, selection);
	argvv[0] = temp;
	argvv[1] = temp2;
	argvv[2] = temp3;

pedro_dprintf(0, "file in untar %s", filename);

	ret = mainfinal (3, argvv);

	return ret;

}
