
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
 
// definicao de uint e uchar, but why?...
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
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

#include "aline_definitive_header_2_.h"
#ifdef WIN64
#define MYCAST __int64
#else
#define MYCAST int
#endif

extern int unicodemode;

uint compressionlevel = 6;

uint intstatus = 0;

int erroglobal = 0;

int isgzip2 = 0;

extern int zlibpercent;

__int64 lffilesize (const char *szFileName);

uint __stdcall rspcompress (char *inputfile, char *outfile);
int zcompress_sha512_k (char *input, char *output, int levelin);
uint __stdcall rspuncompress (uchar * outfile, uchar * outfile2);

int    zuncompress (char *input, char *output);
int    zcompress (char *input, char *output, int level);

int utf8towide (const char *pUTF8, WCHAR * pUSC2, int nUSC2);

WCHAR* utf8towide_v2 (const char *pUTF8)
{
	static WCHAR pUSC2[300];
	MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, 300);
	return pUSC2;
}

static float inittimer (uint comando)
{

	static uint clock1;
	static uint clock2;

	if (comando == 0)
	{
		clock1 = clock ();
		return 0;

	}
	else
	{

		clock2 = clock ();

		return ((float) clock2 - (float) clock1) / 1000;

	}

};

typedef void *myfile;

int    gzclose (myfile file);

myfile gzopen (char *path_now_as_utf8, char *mode);

int    gzread (myfile file, char *buf, uint len);

char  *gzerror (myfile file, int *errnum);

int    gzwrite (myfile file, const char *buf, uint len);

float  inittimer (uint comando);

void   dprintf (char *format, ...);

uint __stdcall rspvalidatefile (uchar * outfile2);

int __stdcall startapi (int parameter);

uchar intoutfile[255];
uchar intinputfile[255];
uint comando;

uint pauseflag;
uint cancelflag;
uint filesize;

uint fileread;
uint intret;
uint finished;

uint getval (int max, uint por)
{

	double maxa;
	double porr;

	maxa = (double) max;
	porr = (double) por;

	maxa = (maxa / 100) * porr;

	return (uint) maxa;

}

/*

   a formula aqui é (100/max * fatia)
   aqui é para saber a porcentagem referente ao valor passado em relacao ao maximo

   max = 10000
   fatia = 5000
   result = 50
 */
static uint getpor (int max, uint fatia)
{

	double maxa;
	double fatiaa;

	maxa = (double) max;
	fatiaa = (double) fatia;

	if (max == 0)
	{
		return 0;
	}

	maxa = ((double) 100 / maxa * fatiaa);

	return (uint) maxa;

}

/*
   a formula aqui é (fatia/porcentagem) * 100
   o resultado é sempre uma porcentagem

   por = 70
   fatia = 10000
   result = 142

   basicamente é para saber o maximo a partir da fatia e da porcentagem
   sera pouco utilizada esta funcao
 */
uint
getmax (int por, uint fatia)
{

	float a;
	float b;

	a = (float) por;
	b = (float) fatia;

	if (por == 0)
	{
		return 0;
	}

	a = (b / a) * (float) 100;

	return (uint) a;

}

BOOL WINAPI DllMain (HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("Gzip DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") \n");


#ifdef NPRINTF
		MessageBox (0, "Bhond debugging code", "BW", MB_OK | MB_TOPMOST);
#endif
		break;
	case DLL_THREAD_ATTACH:
		
		break;
	case DLL_THREAD_DETACH:
		
		break;
	case DLL_PROCESS_DETACH:
		
		break;
	}
	return TRUE;
}

uint __stdcall rspcompress (char *inputfile, char *outfile)
{

	int returnvalue = 0;

	int ret;

	int ret3 = 0;

	uchar buf[4097];

	FILE  *input;
	myfile output;

	pauseflag = 0;
	cancelflag = 0;

	filesize = lffilesize (inputfile);

#ifdef NPRINTF
	dprintf("certeira \n");
	dprintf("Compression level %d\n",compressionlevel);
#endif

	switch (compressionlevel)
	{

	case 0:
		output = gzopen (outfile, "wb0h");
		break;

	case 1:
		output = gzopen (outfile, "wb1h");
		break;
	case 2:
		output = gzopen (outfile, "wb2h");
		break;
	case 3:
		output = gzopen (outfile, "wb3h");
		break;
	case 4:
		output = gzopen (outfile, "wb4h");
		break;
	case 5:
		output = gzopen (outfile, "wb5h");
		break;
	case 6:
		output = gzopen (outfile, "wb6f");
		break;
	case 7:
		output = gzopen (outfile, "wb7f");
		break;
	case 8:
		output = gzopen (outfile, "wb8f");
		break;
	case 9:
#ifdef NPRINTF
		dprintf("Usou modo 9 \n");
#endif
		output = gzopen (outfile, "wb9f");
		break;
	default:
		output = gzopen (outfile, "wb6f");
		break;
	}

	if (output == NULL)
	{

		finished = 1;
		
		return 8;

	}
	else
	{
		;
	}
	if(unicodemode)
	{
		WCHAR wpmode[300] ={0,};
		utf8towide (inputfile, wpmode, 300);
		input = _wfopen (wpmode, L"rb");
	}
	else
		input = fopen (inputfile, "rb");

	if (input == NULL)
	{
		finished = 1;
		gzclose (output);
		return 7;
	}
	else
	{
		;
	}

	fileread = 0;

#ifdef NPRINTF
	dprintf ("verificando \n");
#endif

	while (1)
	{

		while (pauseflag)
		{

			Sleep (50);

			if (cancelflag)
			{
				returnvalue = 19;
				goto saida;
			}

		}

		if (cancelflag)
		{
			returnvalue = 19;
			goto saida;
		}

		ret = fread (buf, 1, 4096, input);

		if (ret <= 0)
		{
			break;
		}

		fileread = fileread + ret;

		gzwrite (output, (void *) buf, ret);

		//string = gzerror (output, &ret3);

		if (ret3)
		{
			returnvalue = 14;

		}

	}

saida:

	fclose (input);

	gzclose (output);
	
	finished = 1;

	return returnvalue;

}

uint __stdcall rspuncompress (uchar * outfile, uchar * outfile2)
{

	int ret;

	int returnvalue = 0;
	int ret3 = 0;
	
	uchar buf[4097];

	FILE  *input;
	myfile output;
	
	pauseflag = 0;
	cancelflag = 0;

	filesize = lffilesize ((void *) outfile);

	output = gzopen ((void *) outfile, "rb");

	if (output == NULL)
	{
		finished = 1;
		return 10;
	}
	else
	{
		;
	}

	if(unicodemode)
	{
		WCHAR wpmode[300] ={0,};
		utf8towide ((void *) outfile2, wpmode, 300);
		input = _wfopen (wpmode, L"wb");
	}
	else
	     input = fopen ((void *) outfile2, "wb");

	if (input == NULL)
	{
		finished = 1;
		
		gzclose (output);
		return 11;
	}
	else
	{
		;
	}

	fileread = 0;

	while (1)
	{

		while (pauseflag)
		{

			Sleep (50);

			if (cancelflag)
			{
				returnvalue = 19;
				goto saida;
			}

		}

		if (cancelflag)
		{
			returnvalue = 19;
			goto saida;
		}

		ret = gzread (output, (void *) buf, 4096);

		gzerror (output, &ret3);

#ifdef NPRINTF
		dprintf ("%d .%s. \n", ret3, string);
#endif

		if ((ret3 != 0) && (ret3 != 1))
		{
			returnvalue = 15;
		}

		if (ret <= 0)
		{
			break;
		}

		fileread = fileread + ret;

		fwrite (buf, 1, ret, input);

	}

saida:

	fclose (input);

	gzclose (output);

	finished = 1;
	return returnvalue;

}

uint __stdcall getporcentagem ()
{

	uint ret;

	if (isgzip2)
	{
		ret = zlibpercent;
	}
	else
	{
		if (filesize == 0)
		{

			return 0;

		}

		ret = getpor (filesize, fileread);
	}
	
	if (ret > 100)
	{
		ret = 100;
	}

	if (ret < 0)
	{
		ret = 0;
	}

	return ret;

}

uint __stdcall tcompress (char *inputfile, char *outfile)
{

	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;

	comando = 0;
	intret = 0;
	strcpy ((void *) intoutfile, outfile);

	strcpy ((void *) intinputfile, inputfile);

	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, (SIZE_T)0, (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);

	CloseHandle (myhandle);

	return 0;

}

uint __stdcall tuncompress (uchar * outfile, uchar * outfile2)
{

	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;
	comando = 1;

	intret = 0;

	strcpy ((void *) intoutfile, (void *) outfile2);

	strcpy ((void *) intinputfile, (void *) outfile);

	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0, (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);

	CloseHandle (myhandle);

	return 0;

}

uint __stdcall tcompressgzip2 (char *inputfile, char *outfile)
{
	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;
	comando = 2;
	intret = 0;
	strcpy ((void *) intoutfile, (void *) outfile);
	strcpy ((void *) intinputfile, (void *) inputfile);
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0, (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 0;
}

uint __stdcall tcompressgzip2_sha512_k (char *inputfile, char *outfile)
{
	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;
	comando = 10002;
	intret = 0;
	strcpy ((void *) intoutfile, (void *) outfile);
	strcpy ((void *) intinputfile, (void *) inputfile);
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0, (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 0;
}

uint __stdcall tuncompressgzip2 (uchar * outfile, uchar * outfile2)
{

	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;
	comando = 3;
	intret = 0;
	strcpy ((void *) intoutfile, (void *) outfile2);
	strcpy ((void *) intinputfile, (void *) outfile);
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0, (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 0;
}

uint __stdcall tcompressgzip2_utf8_k (char *inputfile, char *outfile)
{
	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;
	comando = 10000;
	intret = 0;
	strcpy ((void *) intoutfile, (void *) outfile);
	strcpy ((void *) intinputfile, (void *) inputfile);
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0, (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 0;
}

uint __stdcall tuncompressgzip2_utf8_k (uchar * outfile, uchar * outfile2)
{

	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;
	comando = 10001;
	intret = 0;
	strcpy ((void *) intoutfile, (void *) outfile2);
	strcpy ((void *) intinputfile, (void *) outfile);
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0, (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 0;
}

int __stdcall startapi (int parameter)
{	

	if (0 == comando)
	{
		unicodemode = 0;
		intret = rspcompress ((void *) intinputfile, (void *) intoutfile);

	}

	if (1 == comando)
	{
		unicodemode = 0;
		intret = rspuncompress ((void *) intinputfile, (void *) intoutfile);
	}

	if (2 == comando)
	{

		intret = zcompress ((void *) intinputfile, (void *) intoutfile, compressionlevel);

	}

	if (3 == comando)
	{

		intret = zuncompress ((void *) intinputfile, (void *) intoutfile);

	}

	if (10000 == comando)
	{
		unicodemode = 1;
		intret = rspcompress ((void *) intinputfile, (void *) intoutfile);

	}

	if (10001 == comando)
	{
		unicodemode = 1;
		intret = rspuncompress ((void *) intinputfile, (void *) intoutfile);
	}

	if (10002 == comando)
	{
		unicodemode = 1;
		intret = zcompress_sha512_k ((void *) intinputfile, (void *) intoutfile, compressionlevel);
	}

	intstatus = 0;
	return intret;

}

int __stdcall getintret ()
{

	return intret;

}

int __stdcall getfinished ()
{

	return finished;

}

int __stdcall setfinished (uint newvalue)
{

	finished = newvalue;

	return 0;

}

#ifdef WIN64
int __stdcall interface1 (__int64 argumento1, __int64 argumento2, __int64 argumento3, __int64 argumento4)
{
#else
int __stdcall interface1 (int argumento1, int argumento2, int argumento3, int argumento4)
{
#endif

	static uchar inputfile[255*6]; //for Unicode sake, (utf-8)
	static uchar inputfile2[255*6];
	static uchar outputfile[255*6];
	static uchar key[255*6];
	
	if (!strcmp ((char *) argumento1, "compress"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);

		isgzip2 = 0;
		intstatus = 1;

		;

		strcpy ((void *) inputfile, (char *) argumento2);

		strcpy ((void *) inputfile2, (char *) argumento3);

		return tcompress ((void *) inputfile, (void *) inputfile2);

	}


	if (!strcmp ((char *) argumento1, "compressgzip2"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);

		isgzip2 = 1;
		intstatus = 1;

		;

		strcpy ((void *) inputfile, (char *) argumento2);

		strcpy ((void *) inputfile2, (char *) argumento3);

		return tcompressgzip2 ((void *) inputfile, (void *) inputfile2);

	}

	if (!strcmp ((char *) argumento1, "compressgzip2_sha512_k"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);

		isgzip2 = 1;
		intstatus = 1;

		;

		strcpy ((void *) inputfile, (char *) argumento2);

		strcpy ((void *) inputfile2, (char *) argumento3);

		return tcompressgzip2_sha512_k((void *) inputfile, (void *) inputfile2);

	}

	if (!strcmp ((char *) argumento1, "compressgzip2_utf8_k"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);
		
		isgzip2 = 0;
		intstatus = 1;

		;

		strcpy ((void *) inputfile, (char *) argumento2);

		strcpy ((void *) inputfile2, (char *) argumento3);

		return tcompressgzip2_utf8_k ((void *) inputfile, (void *) inputfile2);
	}

	if (!strcmp ((char *) argumento1, "uncompress"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);

		;

		strcpy ((void *) inputfile, (char *) argumento2);

		strcpy ((void *) inputfile2, (char *) argumento3);
		intstatus = 1;
		isgzip2 = 0;
		
		return tuncompress ((void *) inputfile, (void *) inputfile2);

	}

	if (!strcmp ((char *) argumento1, "uncompressgzip2"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);

		;

		strcpy ((void *) inputfile, (char *) argumento2);

		strcpy ((void *) inputfile2, (char *) argumento3);
		intstatus = 1;
		isgzip2 = 1;
	
		return tuncompressgzip2 ((void *) inputfile, (void *) inputfile2);

	}

	if (!strcmp ((char *) argumento1, "uncompressgzip2_utf8_k"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);

		strcpy ((void *) inputfile, (char *) argumento2);

		strcpy ((void *) inputfile2, (char *) argumento3);
		intstatus = 1;
		isgzip2 = 0;
		return tuncompressgzip2_utf8_k ((void *) inputfile, (void *) inputfile2);
	}

	if (!strcmp ((char *) argumento1, "setfinished"))
	{

		setfinished (argumento2);

		return 0;

	}

	if (!strcmp ((char *) argumento1, "getfinished"))
	{

		return getfinished ();

	}


	if (!strcmp ((char *) argumento1, "getporcentagem"))
	{

		return getporcentagem ();

	}


	if (!strcmp ((char *) argumento1, "pause"))
	{

		pauseflag = 1;

		return 0;

	}

	if (!strcmp ((char *) argumento1, "resume"))
	{

		pauseflag = 0;

		return 0;

	}


	if (!strcmp ((char *) argumento1, "cancel"))
	{

		pauseflag = 1;
		cancelflag = 1;

		while (intstatus)
		{
#ifdef NPRINTF
			dprintf ("Loopeando no cancel \n");
#endif
			Sleep (50);

		}

		return 0;

	}

	if (!strcmp ((char *) argumento1, "getintret"))
	{

		return getintret ();

	}

	if (!strcmp ((char *) argumento1, "compressionlevel"))
	{

		switch (argumento2)
		{

		case 0:
			break;

		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;

		default:

			return 1;

		}

		compressionlevel = argumento2;

		return 0;

	}

	if (!strcmp ((char *) argumento1, "status"))
	{

		return intstatus;

	}

	assert(0);
	return 0;

}

int unicodemode = 0;

void mprintf2 (char *format, ...)
{
	{	
		va_list args;
		static char buffer[500000];
		va_start (args, format);
		vsprintf (buffer, format, args);
		MessageBox (0, buffer, "BW", MB_OK | MB_TOPMOST);
		/*
			if (val != IDOK)
			{
				
			}
		*/
		va_end(args);
	}
}

int __stdcall ControlName (char *data)
{
	strcpy (data, "BW Gzip DLL " AMARIC__VERSION
	 #ifdef WIN64
	        " 64 bits"
	 #else
	        " 32 bits"
	 #endif
	        );
	return 0;
}

int __stdcall About ()
{
	mprintf2 ("Brazilian Win32 and Win64 DLL to compress or uncompress gzip and gzip2 files, now with SHA512 support...");
	return 0;
}

int wait = 0;

int __stdcall WaitExecution (int val)
{
	wait = val;
	return 0;
}

void __stdcall PauseExecution()
{
	pauseflag = 1;
}
void __stdcall ResumeExecution()
{
	pauseflag = 0;
}
void __stdcall CancelExecution()
{
	pauseflag = 1;
	cancelflag = 1;

	while (intstatus)
	{
#ifdef NPRINTF
		dprintf ("Loopeando no cancel \n");
#endif
		Sleep (50);
	}
}

int __stdcall Compress (char *Inputfile, char *OutPutFile, int CompressionLevel)
{

	if (0 != interface1 ((MYCAST) "status", 0, 0, 0))
	{
		return 13;
	}

	if (0 != interface1 ((MYCAST) "compressionlevel", (MYCAST) CompressionLevel, 0, 0))
	{

		return 12;
	}

	interface1 ((MYCAST) "setfinished", 0, 0, 0);

	interface1 ((MYCAST) "compress", (MYCAST) Inputfile, (MYCAST) OutPutFile, (MYCAST) "file3");

volta:

	if (wait)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{

			goto volta;
		}

	}
	return 0;
}

int __stdcall CompressGzip2(char* Inputfile, char* OutPutFile, int CompressionLevel )
{
	unicodemode=1;
	if(0!=interface1((MYCAST)"status", 0, 0, 0))
	{
		return 13;
	}

	if(0!=interface1((MYCAST)"compressionlevel", (MYCAST)CompressionLevel, 0, 0))
	{
		return 12;
	}

	interface1((MYCAST) "setfinished", 0, 0, 0);

	interface1((MYCAST) "compressgzip2", (MYCAST)Inputfile, (MYCAST)OutPutFile, (MYCAST)"file3");

volta:

	if (wait)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{
			goto volta;
		}
	}

	return 0;
}

int __stdcall CompressGzip2_SHA512_k(char* Inputfile, char* OutPutFile, int CompressionLevel )
{
	unicodemode=1;
	if(0!=interface1((MYCAST)"status", 0, 0, 0))
	{
		return 13;
	}

	if(0!=interface1((MYCAST)"compressionlevel", (MYCAST)CompressionLevel, 0, 0))
	{
		return 12;
	}

	interface1((MYCAST) "setfinished", 0, 0, 0);

	interface1((MYCAST) "compressgzip2_sha512_k", (MYCAST)Inputfile, (MYCAST)OutPutFile, (MYCAST)"file3");

volta:

	if (wait)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{

			goto volta;
		}
	}

	return 0;
}
int __stdcall CompressGzip_utf8_k(char* Inputfile, char* OutPutFile, int CompressionLevel )
{

	if(0!=interface1((MYCAST)"status", 0, 0, 0))
	{
		return 13;
	}

	if(0!=interface1((MYCAST)"compressionlevel", (MYCAST)CompressionLevel, 0, 0))
	{
		return 12;
	}

	compressionlevel = CompressionLevel;

	interface1((MYCAST) "setfinished", 0, 0, 0);

	interface1((MYCAST) "compressgzip2_utf8_k", (MYCAST)Inputfile, (MYCAST)OutPutFile, (MYCAST)"file3");

volta:

	if (wait)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{

			goto volta;
		}
	}

	return 0;
}
int __stdcall GetFinished()//retorna 0 se nao terminou ainda
{
	return interface1((MYCAST)"getfinished",(MYCAST) " ", (MYCAST)" ", (MYCAST)" ");
}

int __stdcall GetReturnValue()
{
	return interface1((MYCAST)"getintret", (MYCAST)" ", (MYCAST)" ", (MYCAST)" ");
}

int __stdcall GetProgress()
{

	return interface1((MYCAST)"getporcentagem", (MYCAST)" ", (MYCAST)" ", (MYCAST)" ");
	return 0;
}

int __stdcall Uncompress(char* Inputfile, char* OutPutFile)
{

	if(0!=interface1((MYCAST)"status", 0, 0, 0) )
	{
		return 13;
	}

	interface1((MYCAST) "setfinished", 0, 0, 0);

	interface1((MYCAST) "uncompress", (MYCAST)Inputfile, (MYCAST)OutPutFile, (MYCAST)"file3");

volta:

	if (wait)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{

			goto volta;
		}
	}

	return 0;

}

int __stdcall UncompressGzip2(char* Inputfile, char* OutPutFile )
{

	unicodemode=1;
	if(interface1((MYCAST)"status", 0, 0, 0) )
	{

		return 13;

	}

	interface1((MYCAST) "setfinished", 0, 0, 0);
	interface1((MYCAST) "uncompressgzip2", (MYCAST)Inputfile, (MYCAST)OutPutFile, (MYCAST)"file3");

volta:

	if (wait)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{

			goto volta;
		}
	}

	return 0;
}

int __stdcall UncompressGzip_utf8_k(char* Inputfile, char* OutPutFile )
{

	unicodemode=1;
	if(interface1((MYCAST)"status", 0, 0, 0) )
	{

		return 13;

	}

	interface1((MYCAST) "setfinished", 0, 0, 0);
	interface1((MYCAST) "uncompressgzip2_utf8_k", (MYCAST)Inputfile, (MYCAST)OutPutFile, (MYCAST)"file3");

volta:

	if (wait)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{

			goto volta;
		}
	}

	return 0;
}

int __stdcall stringtobyte (unsigned char *dest, unsigned char *src, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	return 0;
}
int __stdcall bytetostring (unsigned char *dest, unsigned char *src, int len)
{
	int i;	for (i = 0; i < len; i++)	{dest[i] = src[i];	}dest[i] = 0;return 0;
}
//for your pleasure...
