/*
    Copyright (C) <2021>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
        and GNU LESSER GENERAL PUBLIC LICENSE along with this program.
        If not, see <http://www.gnu.org/licenses/>.

    support: https://arsoftware.net.br/binarywork _____________
    mirror :  http://nomade.sourceforge.net/?AR=true&ar_debug=1

        direct programmers e-mails:
        Ricardo: arsoftware25@gmail.com  ricardo@arsoftware.net.br
         Amanda: arsoftware10@gmail.com  amanda@arsoftware.net. br

        immediate contact(for a very fast answer) WhatsApp
        (+55)41 9627 1708 - it is always on
 */

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

#include <stdbool.h>

#include "aline_definitive_header_2_.h"
#ifdef WIN64
#define MYCAST __int64
#else
#define MYCAST int
#endif

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

int *cores_used_z                        = NULL;

#define __amandacall __stdcall

char temp_path_z            [1024];

uint32_t
tuklib_cpucores_z           (void);

int n_threads_z                = 1; 

int __stdcall GetReturnValue(void);

int __amandacall get_multithread_progress(void);

extern int unicodemode;

extern bool is_multi_thread_z;

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
int64_t filesize;

int64_t fileread;
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
static int getpor (int64_t max, int64_t fatia)
{

	double maxa;
	double fatiaa;

	maxa = (double) max;
	fatiaa = (double) fatia;

	if (max == 0)
	{
		return 0;
	}

	maxa = ((double) 10000 / maxa * fatiaa);

	return (int) maxa;

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
	case DLL_PROCESS_ATTACH://Valor de returnvalue 0  _amanda_debug_

		OutputDebugString ("BW Gzip2 DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") _amanda_debug_\n");


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

uint __stdcall getporcentagem ()
{

	uint ret = 0;

	if(is_multi_thread_z)
	{
		ret = get_multithread_progress();
		pedro_dprintf(-1, "multi-thread progress %d\n", ret);
	}
	else
	{
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
	}

	if (ret > 10000)
	{
		ret = 10000;
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
	strcpy ((char *) intoutfile, outfile);

	strcpy ((char *) intinputfile, inputfile);

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

	strcpy ((char *) intoutfile, (char *) outfile2);

	strcpy ((char *) intinputfile, (char *) outfile);

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
	strcpy ((char *) intoutfile, outfile);
	strcpy ((char *) intinputfile, inputfile);
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
	strcpy ((char *) intoutfile, outfile);
	strcpy ((char *) intinputfile, inputfile);
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
	strcpy ((char *) intoutfile  , (char *) outfile2);
	strcpy ((char *) intinputfile, (char *) outfile );
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
	strcpy ((char *) intoutfile, outfile);
	strcpy ((char *) intinputfile, inputfile);
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
	strcpy ((char *) intoutfile  , (char *) outfile2);
	strcpy ((char *) intinputfile, (char *) outfile );
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0, (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 0;
}

int __stdcall startapi (int parameter)
{	

	if (0 == comando)
	{
		unicodemode = 0;
		intret = 0;//rspcompress ((char *) intinputfile, (char *) intoutfile);

	}

	if (1 == comando)
	{
		unicodemode = 0;
		intret = 0;//rspuncompress (intinputfile, intoutfile);
	}

	if (2 == comando)
	{

		intret = 0;//zcompress ((char *) intinputfile, (char *) intoutfile, compressionlevel);

	}

	if (3 == comando)
	{

		intret = zuncompress ((char *) intinputfile, (char *) intoutfile);

	}

	if (10000 == comando)
	{
		unicodemode = 1;
		intret = 0;//rspcompress ((char *) intinputfile, (char *) intoutfile);

	}

	if (10001 == comando)
	{
		unicodemode = 1;
		intret = 0;//rspuncompress ((uchar *) intinputfile, (uchar *) intoutfile);
	}

	if (10002 == comando)
	{
		unicodemode = 1;
		intret = zcompress_sha512_k ((char *) intinputfile, (char *) intoutfile, compressionlevel);
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
	static char inputfile[255*6]; //for Unicode sake, (utf-8)
	static char inputfile2[255*6];
	static char outputfile[255*6];
	static char key[255*6];
			
	if (!strcmp ((char *) argumento1, "compress"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);

		isgzip2 = 0;
		intstatus = 1;

		;

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);

		return tcompress (inputfile, inputfile2);

	}

	if (!strcmp ((char *) argumento1, "compressgzip2"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);

		isgzip2 = 1;
		intstatus = 1;

		;

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);

		return tcompressgzip2 (inputfile, inputfile2);

	}

	if (!strcmp ((char *) argumento1, "compressgzip2_sha512_k"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);

		isgzip2 = 1;
		intstatus = 1;

		;

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);

		return tcompressgzip2_sha512_k(inputfile, inputfile2);

	}

	if (!strcmp ((char *) argumento1, "compressgzip2_utf8_k"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);
		
		isgzip2 = 0;
		intstatus = 1;

		;

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);

		return tcompressgzip2_utf8_k (inputfile, inputfile2);
	}

	if (!strcmp ((char *) argumento1, "uncompress"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);

		;

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);
		intstatus = 1;
		isgzip2 = 0;
		
		return tuncompress ((uchar *) inputfile, (uchar *) inputfile2);

	}

	if (!strcmp ((char *) argumento1, "uncompressgzip2"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);

		;

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);
		intstatus = 1;
		isgzip2 = 1;
	
		return tuncompressgzip2 ((uchar *) inputfile, (uchar *) inputfile2);

	}

	if (!strcmp ((char *) argumento1, "uncompressgzip2_utf8_k"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);
		intstatus = 1;
		isgzip2 = 0;
		return tuncompressgzip2_utf8_k ((uchar *) inputfile, (uchar *) inputfile2);
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

int unicodemode=0;

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

	if (1)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{

			goto volta;
		}
	}

	return GetReturnValue();
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
int __stdcall GetFinished()
{
	return interface1((MYCAST)"getfinished",(MYCAST) " ", (MYCAST)" ", (MYCAST)" ");
}

int __stdcall GetReturnValue(void)
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

	if (1)
	{
		Sleep (50);
		if (0 == interface1 ((MYCAST) "getfinished", (MYCAST) " ", (MYCAST) " ", (MYCAST) " "))
		{

			goto volta;
		}
	}

	return GetReturnValue();
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
/**
* return values
7   cannot open input file
8   cannot open output file
14  cannot write to output file
16  unexpected error
19 (119) user cancel
*
*
*/
int __stdcall compress_g2___rspk_ar(char * Input_amanda_file, char * OutPut_ricardo_File, int Compression_juliete_Level, int n_threads_z__, char *temp_path_z__)
{
	is_multi_thread_z = false         ;
	n_threads_z = n_threads_z__       ;
	strcpy(temp_path_z, temp_path_z__);	
	return CompressGzip2_SHA512_k(Input_amanda_file, OutPut_ricardo_File, Compression_juliete_Level);
}
/**
*
10 = cannot open input file
11 = cannot open output file
9  = cannot read from input file
14 = cannot write to output file
15 = md5 checksum error
18 = unexpected error
19 (119) = User cancel
20 = sha512 checksum error
21 = zlib data stream error
90 = not a valid gzip2 file
*
*
*
*/
int __stdcall uncompress_g2___rspk_ar(char * Inputfile_arp, char * OutPutFile_arp,  int n_threads_z__ /* number of threads to use */, char *temp_path_z_S2__, int * cores_used_z__)
{
	n_threads_z = n_threads_z__          ;
	cores_used_z         = cores_used_z__;
	assert(cores_used_z);
	strcpy(temp_path_z, temp_path_z_S2__);
	is_multi_thread_z = false;
	return UncompressGzip2(Inputfile_arp, OutPutFile_arp);
}

int __stdcall get_progress_g2___ar(void)
{
	return GetProgress();
}

int __stdcall pause_g2___aakp_g2___ar(void)
{
	PauseExecution();
	return 0; 
}

int __stdcall resume_g2___aakp_g2___ar(void)
{
	ResumeExecution();
	return 0;
}

int __stdcall cancel_g2___aakp_g2___ar(void)
{
	CancelExecution();
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