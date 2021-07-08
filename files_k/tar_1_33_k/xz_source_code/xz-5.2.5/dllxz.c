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
    mirror :  http://nomade.sourceforge.net/?AR=true&ar_debug=1 <link dead, we wonder why...>

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

#include <stdbool.h>

extern int threads_z;

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

WCHAR* __stdcall utf8towide (const char *pUTF8);

#ifdef _WIN64
#define __INT32_OR_INT64 __int64
#else
#define __INT32_OR_INT64 int
#endif

int thelevel=0;

int lgetpor (__int64 max, __int64 fatia)
{
/*

   2/27/2004 12:13PM modificacao para evitar divisao por 0, eu te amo...

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

char myoutfile[300];
char myinfile[300];
int comando = 0;
int intreturn = 0;


int running = 0;


int intpause=0;
int intcancel=0;

int porcentagem;
int
xz_compress(char*inputfile,char*outputfile, int level);



int
xz_uncompress(char*inputfile,char*outputfile);


int __stdcall
startapi (int parameter)
{
//0 compress 1 decompress




	running = 1;
	if (comando == 0)
	{
		intreturn = 0;
		intreturn = xz_compress (myinfile, myoutfile, thelevel);
	}

	if (1 == comando)
	{

		intreturn = 0;
		intreturn = xz_uncompress (myinfile, myoutfile);
	}
	running = 0;
	//dprintf ("Terminou a execucao \n");
	return 0;
}

///////////
BOOL WINAPI DllMain (HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("BW XZ Compressor - DLL_PROCESS_ATTACH " __DATE__ " " __TIME__ " _amanda_debug_\n");
		break;
	case DLL_THREAD_ATTACH:
		OutputDebugString ("DLL_THREAD_ATTACH \n");
		break;
	case DLL_THREAD_DETACH:
		OutputDebugString ("DLL_THREAD_DETACH \n");
		break;
	case DLL_PROCESS_DETACH:
		OutputDebugString ("DLL_PROCESS_DETACH \n");
		break;
	}
	return TRUE;
}



int __stdcall
execute (char *infile, char *outfile, int comando1)
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
	strcpy (myinfile, infile);
	strcpy (myoutfile, outfile);

	comando = comando1;     // 0 = compress 1 = decompress
	myhandle =
		CreateThread ((LPSECURITY_ATTRIBUTES) 0, (DWORD) 0, (LPTHREAD_START_ROUTINE) startapi,
		              (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 2;
}

int __stdcall
interface1 (__INT32_OR_INT64 argumento1, __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3, __INT32_OR_INT64 argumento4)
{

	static char inputfile[255];
	static char outputfile[255];

	if (!strcmp ((char *) argumento1, "compress"))
	{

		if (running)
		{
			return 1;
		}
		porcentagem = 0;
		intpause = 0;
		intcancel = 0;
		strcpy (inputfile, (char *) argumento2);
		strcpy (outputfile, (char *) argumento3);
		thelevel = (int) argumento4;
		execute (inputfile, outputfile, 0);       //0 compress 1 decompress

		return 0;
	}
	if (!strcmp ((char *) argumento1, "uncompress"))
	{


		if (running)
		{
			return 1;
		}
		porcentagem=0;
		intpause = 0;
		intcancel = 0;
		strcpy (inputfile, (char *) argumento2);
		strcpy (outputfile, (char *) argumento3);
		execute (inputfile, outputfile, 1);       //0 compress 1 decompress

		return 0;
	}




	if (!strcmp ((char *) argumento1, "resume"))
	{
		intpause = 0;
		return 0;

	}
	if (!strcmp ((char *) argumento1, "pause"))
	{
		intpause = 1;
		return 0;

	}
	if (!strcmp ((char *) argumento1, "cancel"))
	{

		intcancel = 1;

		return (0);
	}
	if (!strcmp ((char *) argumento1, "returnvalue"))
	{

		if(intcancel)
		{
			return -1;
		}

		return intreturn;
	}
	if (!strcmp ((char *) argumento1, "running"))
	{



		return running;
	}
	if (!strcmp ((char *) argumento1, "progress"))
	{

		int por = porcentagem;


		if(por<0)
		{
			por=0;
		}

		if(por>10000)
		{
			por=10000;
		}
		return por;
	}


	return 0;
}

int __stdcall Compress
(
	char*infile__aakp,
	char*outfile_rspk,
	int level_juliete,
	int threads_____z
)
{

	int ret_val_aakp;

	intpause  = 0;
	intcancel = 0;

	threads_z = threads_____z;

	ret_val_aakp = xz_compress (infile__aakp, outfile_rspk, level_juliete);


	if(intcancel)
	{
		return 119;//user abort
	}
	//return interface1((__INT32_OR_INT64)"compress",(__INT32_OR_INT64)infile,(__INT32_OR_INT64)outfile,(__INT32_OR_INT64)level);
	return ret_val_aakp;
}
int __stdcall Uncompress
(
	char*infile__aakp,
	char*outfile_rspk
)
{

	//vai lá...

	int ret_val_aakp;

	intpause  = 0;
	intcancel = 0;

	ret_val_aakp = xz_uncompress ( infile__aakp,
	                               outfile_rspk);

	//return interface1((__INT32_OR_INT64)"uncompress",(__INT32_OR_INT64)infile,(__INT32_OR_INT64)outfile,(__INT32_OR_INT64)0);

	if(intcancel)
	{
		return 119;//user abort
	}
	return ret_val_aakp;
}

int __stdcall Pause()
{

	return interface1((__INT32_OR_INT64)"pause",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}

int __stdcall Resume()
{

	return interface1((__INT32_OR_INT64)"resume",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}

int __stdcall Cancel()
{

	return interface1((__INT32_OR_INT64)"cancel",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}
int __stdcall Returnvalue()
{

	return interface1((__INT32_OR_INT64)"returnvalue",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}
int __stdcall Running()
{

	return interface1((__INT32_OR_INT64)"running",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);

}
int __stdcall Progress()
{
	int ret_val_aakp;
	ret_val_aakp = interface1((__INT32_OR_INT64)"progress",(__INT32_OR_INT64)0,(__INT32_OR_INT64)0,(__INT32_OR_INT64)0);
	pedro_dprintf(-1, "dentro %d", ret_val_aakp);
	return ret_val_aakp;
}
