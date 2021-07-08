//december 2020, by bhond
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

#include "win64.h"

#include "aline_definitive_header_2_.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//defines...

char myinfile_ar[ MAX_PATH+1];
char myoutfile_ar[MAX_PATH+1];

int intreturn_ar        = 0;
int comando_ar          = 0;
int running_ar          = 0;
int intpause_ar         = 0;
int intcancel_ar        = 0;
int porcentagem_ar      = 0;
int unicodemode_ar      = 1;//always...
__int64 file_tamanho_ar = 0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

int main_ar(int numArgs, char **);

char* __stdcall widetoutf8 (WCHAR * pUSC2);

int utf8towide (const char *pUTF8, WCHAR * pUSC2, int nUSC2);

int lgetpor_ar (__int64 max, __int64 fatia);

__int64 lffilesize_ar (const char *szFileName);

static __int64 fs_filesize (HANDLE hFile);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////amanda/

int utf8towide (const char *pUTF8, WCHAR * pUSC2, int nUSC2)
{
	return MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, nUSC2);
}

int lgetpor_ar (__int64 max, __int64 fatia)
{
/*

   2/27/2004 12:13PM modificacao para evitar divisao por 0

 */

	double maxa;
	double fatiaa;

	maxa = (double) max;
	fatiaa = (double) fatia;

	if (max == 0 || fatia == 0)
	{
		return 0;
	}

	maxa = ((double) 10000 / maxa * fatiaa);

	return (int) maxa;

}

static __int64 fs_filesize (HANDLE hFile)
{
	LARGE_INTEGER li;

	li.QuadPart = 0;
	li.LowPart = GetFileSize (hFile, (LPDWORD) &li.HighPart);

	if (li.LowPart == 0xFFFFFFFF)
	{
		if (GetLastError () != ERROR_SUCCESS)
			return 0;
	}

	return (__int64) li.QuadPart;
}

__int64 lffilesize_ar (const char *szFileName)
{
	__int64 iResult;
	HANDLE hFile;

	if (unicodemode_ar)
	{

#ifdef NPRINTF
		dprintf("arquivo %s\n",szFileName);
#endif
		{
			WCHAR wpmode[300];
			utf8towide (szFileName, wpmode, 300);
			hFile = CreateFileW (wpmode, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
		}
	}
	else
	{
		hFile = CreateFile (szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	}
	if (hFile == INVALID_HANDLE_VALUE)
		return 0;

	iResult = fs_filesize (hFile);
	CloseHandle (hFile);
	return iResult;
}

char* __stdcall widetoutf8 (WCHAR * pUSC2)
{
	static int position=0;
   #define THESIZE (300*6)
	if(0==position)

	{
		static char pUTF8[THESIZE];
		position=1;

		WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) pUTF8, THESIZE, 0, 0);
		return pUTF8;
	}
	else
	{
		static char pUTF8[THESIZE];
		position=0;

		WideCharToMultiByte (CP_UTF8, 0, pUSC2, -1, (LPSTR) pUTF8, THESIZE, 0, 0);
		return pUTF8;
	}
	return NULL;
}

int soc_lzma_compress_ar (char * myinfile__ar, char * myoutfile__ar, int level_ar)
{

	int ret_ar = 0;
	static char *my_main_args[5];
	//static char *argvv[15];

	my_main_args[0] = "my_amanda_executable.exe";
	my_main_args[1] = "e";
	my_main_args[2] = myinfile__ar;
	my_main_args[3] = myoutfile__ar;

	ret_ar = main_ar(4, my_main_args);

	//free(my_main_args);

	return ret_ar;
}
int soc_lzma_uncompress_ar (char * myinfile__ar, char * myoutfile__ar               )
{

	int ret_ar = 0;
	static char *my_main_args[5];
	//static char *argvv[15];

	//my_main_args = (char **) malloc(300);

	my_main_args[0] = "my_amanda_executable.exe";
	my_main_args[1] = "d";
	my_main_args[2] = myinfile__ar;
	my_main_args[3] = myoutfile__ar;

	ret_ar = main_ar(4, my_main_args);

	//free(my_main_args);

	return ret_ar;

}

int __stdcall compress_lzma_aakp_rspk
(
	char * valquiria_input__file_utf_8,
	char * juliete___output_file_utf_8,
	int junior_compression_level___
)
{
	int returnvalue_aakp;
	file_tamanho_ar = lffilesize_ar(valquiria_input__file_utf_8);
	
	porcentagem_ar = 0;
	intpause_ar = 0;
	intcancel_ar = 0;
	
	returnvalue_aakp = soc_lzma_compress_ar
		           (
		valquiria_input__file_utf_8,
		juliete___output_file_utf_8,
		junior_compression_level___
	                   );

	if(intcancel_ar)
	{
		return 119;
	}

	return returnvalue_aakp;

}
int __stdcall uncompress_lzma_aakp_rspk
(
	char * valquiria_input__file_utf_8,
	char * juliete___output_file_utf_8
)
{
	int returnvalue_aakp;
	
	porcentagem_ar = 0;
	intpause_ar = 0;
	intcancel_ar = 0;	
	
	file_tamanho_ar = lffilesize_ar(valquiria_input__file_utf_8);
	returnvalue_aakp= soc_lzma_uncompress_ar
		          (
		valquiria_input__file_utf_8,
		juliete___output_file_utf_8
	                  );

	if(intcancel_ar)
	{
		return 119;
	}

	return returnvalue_aakp;
}
int __stdcall
startapi_ar (int parameter_______ar)
{
//0 compress 1 decompress

	running_ar = 1;
	if (comando_ar == 0)
	{
		intreturn_ar = 0;
		intreturn_ar = soc_lzma_compress_ar (myinfile_ar, myoutfile_ar, 6);
	}

	if (1 == comando_ar)
	{
		intreturn_ar = 0;
		intreturn_ar = soc_lzma_uncompress_ar (myinfile_ar, myoutfile_ar);
	}
	running_ar = 0;

	return 0;
}

int __stdcall
execute_ar (char *infile, char *outfile, int comando1)
{

/*
   char myinfile[255] ;
   char myoutfile[255] ;
   int comando ;
   char mylevel[255] ;
 */

	HANDLE myhandle;
	__INT32_OR_INT64 ThreadId;
	__INT32_OR_INT64 parameter = 1;
	strcpy (myinfile_ar, infile);
	strcpy (myoutfile_ar, outfile);

	comando_ar = comando1;     // 0 = compress 1 = decompress

	running_ar = 1;

	myhandle =
		CreateThread ((LPSECURITY_ATTRIBUTES) 0, (DWORD) 0, (LPTHREAD_START_ROUTINE) startapi_ar,
		              (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 2;
}


int __stdcall
ControlName (char *data)
{
	strcpy (data, "BW LZMA DLL " AMARIC__VERSION
	#ifdef _WIN64
	        "    - 64 bits"
	#else
	        "    - 32 bits"
	#endif
	        );
	return 0;
}

int __stdcall Compress(char * infile_ar,char * outfile_ar)
{

	if (running_ar)
	{
		return 1;
	}

	file_tamanho_ar = lffilesize_ar(infile_ar);

	porcentagem_ar = 0;
	intpause_ar = 0;
	intcancel_ar = 0;

	execute_ar (infile_ar, outfile_ar, 0);

	return 0;//interface1((__INT32_OR_INT64)"compress",(__INT32_OR_INT64)infile,(__INT32_OR_INT64)outfile,(__INT32_OR_INT64)0);

}
int __stdcall Uncompress(char*infile_ar,char*outfile_ar)
{

	if (running_ar)
	{
		return 1;
	}

	file_tamanho_ar = lffilesize_ar(infile_ar);

	porcentagem_ar = 0;
	intpause_ar = 0;
	intcancel_ar = 0;
	execute_ar (infile_ar, outfile_ar, 1);
	return 0;//interface1((__INT32_OR_INT64)"uncompress",(__INT32_OR_INT64)infile,(__INT32_OR_INT64)outfile,(__INT32_OR_INT64)0);

}

int __stdcall Resume()
{

	intpause_ar = 0;

	return 0;

}
int __stdcall Pause()
{

	intpause_ar = 1;
	return 0;//interface1((__INT32_OR_INT64)"pause",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}

int __stdcall Cancel()
{
	intcancel_ar = 1;
	return 0;//interface1((__INT32_OR_INT64)"cancel",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}

int __stdcall Returnvalue()
{

	if(intcancel_ar)
	{
		return -1;
	}

	return intreturn_ar;
	//return interface1((__INT32_OR_INT64)"returnvalue",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}

int __stdcall Running()
{

	return running_ar;//interface1((__INT32_OR_INT64)"running",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}

int __stdcall Progress()
{

	int por_ar = porcentagem_ar;
	pedro_dprintf(-1, "dentro %d\n", porcentagem_ar);
	if(por_ar < 0)
	{
		por_ar = 0;
	}

	if(por_ar > 10000)
	{
		por_ar = 10000;
	}
	return por_ar;

	//return interface1((__INT32_OR_INT64)"progress",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}

BOOL WINAPI DllMain (HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("BE LZMA DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") _amanda_debug_\n");

#ifdef NPRINTF
		MessageBox (0, "Alladin debugging code", "BinaryWork Corp.", MB_OK | MB_TOPMOST);
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