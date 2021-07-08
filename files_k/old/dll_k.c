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

// definicao de uint e uchar
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

#include "win64.h"

#include "folder.h"

uint compressionlevel = 6;

uint intstatus = 0;

uint __stdcall rspcompress (char *inputfile, char *outfile);
uint __stdcall rspuncompress (uchar * outfile, uchar * outfile2);

typedef int (__stdcall * tar_list_function)(int clear_flag_k);

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

enum amanda_modes
{
	AR_INIT,
	AR_PROCESS,
	AR_END,
};

uint
getpor (int max, uint fatia);

int
deletelist (void);

int untar (char *filename, char *destination, char *selection);

#ifndef __MINGW32__
extern char *getcpuspeed ();


extern char *getprocessorbrandstring ();
extern char *getcpuname ();

#endif


extern int intfilename;
extern int intdirectory;


char errorstring[255];

void geterrorstringrspmakedir (int errorcode, char *path);


int
getitem (int mode, uint * isdir, uint * second,
         uint * minute, uint * hour,
         uint * year, uint * month, uint * day, char *filename, uint * size);

extern int flaglist;

static float
inittimer (uint comando)
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
	/*
	   inittimer(0);
	   Sleep(1234);
	   Sleep(25);

	   ;//dprintf("Clock %f \n ", inittimer(1));
	 */

};

uint getfilesize (char *infile);

typedef void *myfile;           // assim fica melhor de se usar o treco

// basta passar o endereco
int gzclose (myfile file);

myfile gzopen (char *path, char *mode);

int gzread (myfile file, char *buf, uint len);


int gzwrite (myfile file, const char *buf, uint len);

float inittimer (uint comando);


uint __stdcall rspvalidatefile (uchar * outfile2);

int __stdcall startapi (int parameter);



uchar intoutfile[255];
uchar intinputfile[255];
uchar intselection[255];
uint comando;


// variaveis globais do programa


uint pauseflag;
uint cancelflag;
uint filesize;

uint fileread;
uint intret;
uint finished;

/*
   aqui o codigo recebe o maximo , entra com uma porcentagem e



   pega o valor referente a porcentagem passad

   max = 10000
   por = 70
   result = 7000

 */


/*

   a formula aqui é (100/max * fatia)
   aqui é para saber a porcentagem referente ao valor passado em relacao ao maximo

   max = 10000
   fatia = 5000
   result = 50
 */


/*
   a formula aqui é (fatia/porcentagem) * 100
   o resultado é sempre uma porcentagem

   por = 70
   fatia = 10000
   result = 142

   basicamente é para saber o maximo a partir da fatria e da porcentagem
   sera pouco utilizada esta funcao
 */

//
//uint
//getfilesize (char *infile)
//{
//
//  uint ret;
//
//  FILE *myfile;
//
//  if ((myfile = fopen (infile, "rb")) == NULL)
//    {
//      ;//dprintf ("The file 'data' was not opened\n");
//      return 0;
//    }
//  else
//    {
//      ;//dprintf ("The file 'data' was opened\n");
//    }
//
//  ret = fseek (myfile, 0, SEEK_END);
//
//  ret = ftell (myfile);
//
//  ;//dprintf ("tamanho do arquivo %d\n ", ret);
//
//  fclose (myfile);
//
//  printf ("Tamanho do arquivo %s  %d \n", infile, ret);
//
//  return ret;
//
//
//}

//definicao de DLLMain
int __stdcall
DllMain (HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{


	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// Enable debug/logging?
		//      gs_bLogFile = GetPrivateProfileInt("Debug","WriteLogFile",gs_bLogFile,"lame_enc.ini");

		OutputDebugString ("tar.gz DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") \n");
		break;
	case DLL_THREAD_ATTACH:
		//OutputDebugString ("DLL_THREAD_ATTACH \n");
		break;
	case DLL_THREAD_DETACH:
		//OutputDebugString ("DLL_THREAD_DETACH \n");
		break;
	case DLL_PROCESS_DETACH:
		//OutputDebugString ("DLL_PROCESS_DETACH \n");
		break;
	}
	return TRUE;
}

#if 0

#ifdef NPRINTF
int
main ()
{

	int ret;
	int ret2;

	char inputfile[255] = "momento.txt";
	char outfile[255] = "momento.gz";
	char outfile2[255] = "momento2.txt";

	/* uint __stdcall
	   rspuncompress (uchar * outfile, uchar * outfile2) */
/*uint __stdcall
   rspcompress (char *inputfile, char *outfile)*/

	compressionlevel = 9;
	inittimer (0);
	ret = rspcompress (inputfile, outfile);
	printf (" Valode de ret com %d %f \n", ret, inittimer (1));
	inittimer (0);
	ret = rspuncompress (outfile, outfile2);
	printf (" Valode de ret descom %d %f\n", ret, inittimer (1));


#ifndef __MINGW32__

	printf ("Speed %s \n", getcpuspeed ());

#endif


/*
   if(system("fc /b momento.txt momento2.txt"))
   {
   printf("!!!!!!!!!!!!Deu erro \n");
   }
   else
   {
   printf(". \n");
   }
 */

}
#endif
#endif

uint
main2 ()
{

	int ret;
	int ret2;

	char inputfile[255] = "momento.txt";
	char outfile[255] = "momento.gz";
	char outfile2[255] = "momento2.txt";
	uchar buf[4097];

	FILE *input;
	myfile output;
	;                       //dprintf ("Estamos ai \n ");

	output = gzopen (outfile, "wb");


	if (output == NULL)
	{
		;               //dprintf ("Error openning gzip file for write \n ");
		return 0;

	}
	else
	{
		;               //dprintf ("OK openning gzip file for write \n ");
	}

	input = fopen (inputfile, "rb");

	if (input == NULL)
	{
		;               //dprintf ("Error openning input file for write \n ");
		return 0;
	}
	else
	{
		;               //dprintf ("OK openning input file for read \n ");
	}




	while (1)
	{

		ret = fread (buf, 1, 4096, input);


		if (ret <= 0)
		{
			break;
		}


// int __stdcall gzwrite (myfile  file , const char *buf , uint len ) ;
		ret2 = gzwrite (output, buf, ret);




	}



	fclose (input);

	gzclose (output);




	output = gzopen (outfile, "rb");


	if (output == NULL)
	{
		;               //dprintf ("Error openning gzip file for write \n ");
		return 0;

	}
	else
	{
		;               //dprintf ("OK openning gzip file for write \n ");
	}


	input = fopen (outfile2, "wb");

	if (input == NULL)
	{
		;               //dprintf ("Error openning input file for write \n ");
		return 0;
	}
	else
	{
		;               //dprintf ("OK openning input file for read \n ");
	}



	while (1)
	{
		//int __stdcall gzread ( myfile file , char  *buf , uint len) ;
		ret = gzread (output, buf, 4096);


		if (ret <= 0)
		{
			break;
		}


// int __stdcall gzwrite (myfile  file , const char *buf , uint len ) ;
		ret2 = fwrite (buf, 1, ret, input);




	}





	fclose (input);

	gzclose (output);

	return 0;

}







//def.def

uint __stdcall
rspuncompress (uchar * outfile, uchar * outfile2)
{
	int ret;
	int ret2;

//char inputfile[255] = "c:\\docs\\momento.txt" ;
//char outfile[255] = "c:\\docs\\momento.gz" ;

	uchar buf[4097];

	FILE *input;
	myfile output;
	;                       //dprintf ("Estamos ai \n ");

	// inittimer (0);


	pauseflag = 0;
	cancelflag = 0;


	filesize = getfilesize (outfile);

	if (rspvalidatefile (outfile))
	{
		finished = 1;
		return 9;       //invalid gzip file


	}

	output = gzopen (outfile, "rb");


	if (output == NULL)
	{
		finished = 1;
		;               //dprintf ("Error opening gzip file for write \n ");
		return 10;

	}
	else
	{
		;               //dprintf ("OK openning gzip file for write \n ");
	}


	input = fopen (outfile2, "wb");

	if (input == NULL)
	{
		finished = 1;
		;               //dprintf ("Error openning input file for write \n ");

		/*ta,bem falta fechar arquivo */
		gzclose (output);
		return 11;
	}
	else
	{
		;               //dprintf ("OK openning input file for read \n ");
	}

	fileread = 0;

	while (1)
	{



		if (pauseflag)
		{


			Sleep (50);

			if (cancelflag)
			{
				break;
			}


		}



		//int __stdcall gzread ( myfile file , char  *buf , uint len) ;
		ret = gzread (output, buf, 4096);


		if (ret <= 0)
		{
			break;
		}

		fileread = fileread + ret;

// int __stdcall gzwrite (myfile  file , const char *buf , uint len ) ;

		ret2 = fwrite (buf, 1, ret, input);

	}

	fclose (input);

	gzclose (output);

	//;//dprintf ("rspuncompress tempo  %f \n ", inittimer (1));
	finished = 1;
	return 0;



}

uint __stdcall
rspvalidatefile (uchar * outfile2)
{

	uchar buf[4097];
	int ret;

	FILE *input;
	myfile output;
	;                       //dprintf ("Estamos ai \n ");

	input = fopen (outfile2, "rb");

	if (input == NULL)
	{
		;               //dprintf ("Error openning input file for write \n ");
		return 3;
	}
	else
	{
		;               //dprintf ("OK openning input file for read \n ");
	}



	ret = fread (buf, 1, 4096, input);



	fclose (input);


	if (ret < 20)
	{
		return 1;       // file too small
	}

	if (buf[0] == 0x1f)
	{
		if (buf[1] == 0x8b)
		{
			if (buf[2] == 0x08)
			{
				return 0;
			}
			else
			{
				return 2;
			}
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 2;
	}

}


uint __stdcall
getporcentagem ()
{

	uint ret;

	if (filesize == 0)
	{

		return 0;

	}


	ret = getpor (filesize, fileread);

	// para evitar problemas maiores
	// agora deve gerar o treco para criar thread e aguardar a finalizacao
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


uint __stdcall
rspuntar (char *inputfile, char *outfile, char *outfile2)
{

// aqui tem que criar thread verifique

//uchar intoutfile[255] ;
//uchar intinputfile[255];
	HANDLE myhandle;
	int ThreadId;
	int parameter = 1;

	comando = 0;
	intret = 0;


	strcpy (intinputfile, inputfile);

	strcpy (intoutfile, outfile);

	strcpy (intselection, outfile2);

pedro_dprintf(0, "rspuntar");

	myhandle =
		CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0,
		              (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter,
		              (DWORD) 0, (LPDWORD) &ThreadId);

	CloseHandle (myhandle);
/*
   HANDLE CreateThread(
   LPSECURITY_ATTRIBUTES lpThreadAttributes,  // pointer to security attributes
   DWORD dwStackSize,                         // initial thread stack size
   LPTHREAD_START_ROUTINE lpStartAddress,     // pointer to thread function
   LPVOID lpParameter,                        // argument for new thread
   DWORD dwCreationFlags,                     // creation flags
   LPDWORD lpThreadId                         // pointer to receive thread ID
   );


 */
	return 0;

}

uint __stdcall
tuncompress (uchar * outfile, uchar * outfile2)
{

	HANDLE myhandle;
	int ThreadId;
	int parameter = 1;
	comando = 1;

	//uchar intoutfile[255] ;
//uchar intinputfile[255];

	intret = 0;

	strcpy (intoutfile, outfile2);

	strcpy (intinputfile, outfile);
// intinputfile[255];

	myhandle =
		CreateThread ((LPSECURITY_ATTRIBUTES) 0, 0,
		              (LPTHREAD_START_ROUTINE) startapi, (LPVOID) parameter,
		              (DWORD) 0, (LPDWORD) &ThreadId);

/*HANDLE CreateThread(
   LPSECURITY_ATTRIBUTES lpThreadAttributes,  // pointer to security attributes
   DWORD dwStackSize,                         // initial thread stack size
   LPTHREAD_START_ROUTINE lpStartAddress,     // pointer to thread function
   LPVOID lpParameter,                        // argument for new thread
   DWORD dwCreationFlags,                     // creation flags
   LPDWORD lpThreadId   */

	CloseHandle (myhandle);

	return 0;

}

int __stdcall
startapi (int parameter)
{
	// tem que receber as variaveis globais e mandar brasa
	;                       //dprintf ("parametro passado %d\n ", parameter);

//int untar(char *filename , char *destination , char *selection );
#ifdef NPRINTF
	dprintf ("arquivo 1 %s \n", intinputfile);
	dprintf ("arquivo 2 %s \n", intoutfile);
	dprintf ("arquivo 3 %s \n", intselection);
#endif
	pauseflag = 0;
	cancelflag = 0;

	filesize = getfilesize_utf8 (intinputfile); //pra não esquecer mais...

	intret = 0;

	intret = untar (intinputfile, intoutfile, intselection);

	intstatus = 0;

pedro_dprintf(0, "retornou %d de untar", intret);

	return intret;
}

int __stdcall
getintret ()
{

	return intret;

}

int __stdcall
getfinished ()
{

	return finished;

}

//funcao de timer para debug




int __stdcall
setfinished (uint newvalue)
{

	uint ret;
	;                       //dprintf ("Setando setfinished %d \n", newvalue);
	finished = newvalue;



	return 0;

}

// aqui agora entra a execucao da interface
/*

   E esta interface define o restante do servico e sua forma
   de execucao dentro dos limites de
   execucao

   Ok , inserindo agora a interface e terminando os itens de execucao

 */

int __stdcall
interface1 (__INT32_OR_INT64 argumento1, __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3, __INT32_OR_INT64 argumento4)
{
	int ret;
	static uchar inputfile[255];
	static uchar inputfile2[255];
	static uchar outputfile[255];
	static uchar key[257];
	static uchar key2[257];
	uint intsize;
	static uint devnum;

	uint intargci;

	static uint isdir = 0;
	static uint second = 0;
	static uint minute = 0;
	static uint hour = 0;
	static uint year = 0;
	static uint month = 0;
	static uint day = 0;
	static char filename[255];
	static uint size = 0;


	if (!strcmp ((char *) argumento1, "rspuntar"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);
		memset (key, 0, 256);
		// memset (key2, 0, 256);


		if (intstatus == 1)
		{
			return -1;
		}

		intstatus = 1;

		;               //dprintf ("compress\n");

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);

		return rspuntar (inputfile, inputfile2, (char *) argumento4);

	}

	if (!strcmp ((char *) argumento1, "uncompress"))
	{
		memset (inputfile, 0, 255);
		memset (outputfile, 0, 255);

		intstatus = 1;

		;               //dprintf ("uncompress\n");

		strcpy (inputfile, (char *) argumento2);

		strcpy (inputfile2, (char *) argumento3);


		;               //dprintf ("arquivo1 *%s* \n ", inputfile);
		;               //dprintf ("arquivo2 *%s* \n ", inputfile2);


		return tuncompress (inputfile, inputfile2);


	}



	if (!strcmp ((char *) argumento1, "setfinished"))
	{
//memset (inputfile, 0, 255);
		//   memset (outputfile, 0, 255);

		;               //dprintf ("setfinished\n");

		// strcpy (inputfile, (char *) argumento2);

		//  strcpy (inputfile2, (char *) argumento3);


//;//dprintf ("arquivo1 *%s* \n ", inputfile);
//;//dprintf ("arquivo2 *%s* \n ", inputfile2);

		setfinished (argumento2);


		return 0;


	}



	if (!strcmp ((char *) argumento1, "getfinished"))
	{
//memset (inputfile, 0, 255);
		//   memset (outputfile, 0, 255);

		;               //dprintf ("getfinished\n");

		// strcpy (inputfile, (char *) argumento2);

		//  strcpy (inputfile2, (char *) argumento3);


//;//dprintf ("arquivo1 *%s* \n ", inputfile);
//;//dprintf ("arquivo2 *%s* \n ", inputfile2);

		return getfinished ();





	}


	if (!strcmp ((char *) argumento1, "getporcentagem"))
	{
//memset (inputfile, 0, 255);
		//   memset (outputfile, 0, 255);

		;               //dprintf ("getporcentagem\n");

		// strcpy (inputfile, (char *) argumento2);

		//  strcpy (inputfile2, (char *) argumento3);


//;//dprintf ("arquivo1 *%s* \n ", inputfile);
//;//dprintf ("arquivo2 *%s* \n ", inputfile2);

		return getporcentagem ();





	}


	if (!strcmp ((char *) argumento1, "pause"))
	{
//memset (inputfile, 0, 255);
		//   memset (outputfile, 0, 255);

		;               //dprintf ("pause\n");

		pauseflag = 1;




		return 0;





	}

	if (!strcmp ((char *) argumento1, "resume"))
	{
//memset (inputfile, 0, 255);
		//   memset (outputfile, 0, 255);

		;               //dprintf ("pause\n");

		pauseflag = 0;




		return 0;





	}


	if (!strcmp ((char *) argumento1, "cancel"))
	{
//memset (inputfile, 0, 255);
		//   memset (outputfile, 0, 255);

		;               //dprintf ("pause\n");

		pauseflag = 1;
		cancelflag = 1;




		return 0;





	}


	if (!strcmp ((char *) argumento1, "getintret"))
	{
//memset (inputfile, 0, 255);
		//   memset (outputfile, 0, 255);

		;               //dprintf ("pause\n");

		return intret;


	}



	if (!strcmp ((char *) argumento1, "compressionlevel"))
	{
//memset (inputfile, 0, 255);
		//   memset (outputfile, 0, 255);

		;               //dprintf ("compressionlevel\n");


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


	if (!strcmp ((char *) argumento1, "cpuspeed"))
	{


#ifndef __MINGW32__
		strcpy ((char *) argumento2, getcpuspeed ());
#endif

		return 0;




	}


	if (!strcmp ((char *) argumento1, "getcpuname"))
	{
		int ret;

		char *temp;

#ifndef __MINGW32__

		temp = getcpuname ();

		if (strlen (temp))
		{
			strcpy ((char *) argumento2, temp);
		}
		else
		{
			strcpy ((char *) argumento2, "Unavailable");
		}


#endif

// para saber que valor usou na saida
		return (0);

	}



	if (!strcmp ((char *) argumento1, "getbrandstring"))
	{
		int ret;

#ifndef __MINGW32__
		char *temp;

		temp = getprocessorbrandstring ();

		if (strlen (temp))
		{
			strcpy ((char *) argumento2, temp);
		}
		else
		{
			strcpy ((char *) argumento2, "Unavailable");
		}
#endif


// para saber que valor usou na saida
		return (0);

	}



	if (!strcmp ((char *) argumento1, "geterrorstring"))
	{


		strcpy ((char *) argumento2, errorstring);

		return 0;


	}


	if (!strcmp ((char *) argumento1, "setflaglist"))
	{

		intfilename = 0;
		intdirectory = 0;

		flaglist = argumento2;

		return 0;


	}


	if (!strcmp ((char *) argumento1, "tarinfo"))
	{



//dprintf("dentro de tarinfo \n");
		return getitem (0, &isdir, &second, &minute, &hour, &year, &month,
		                &day, filename, &size);


	}



	if (!strcmp ((char *) argumento1, "tarinfo2"))
	{

//dprintf("dentro de tarinfo2 \n");
		return getitem (1, &isdir, &second, &minute, &hour, &year, &month,
		                &day, filename, &size);


	}


	if (!strcmp ((char *) argumento1, "tarinfoisdir"))
	{

		return isdir;

	}

	if (!strcmp ((char *) argumento1, "tarinfosecond"))
	{

		return second;

	}
	if (!strcmp ((char *) argumento1, "tarinfominute"))
	{

		return minute;

	}
	if (!strcmp ((char *) argumento1, "tarinfohour"))
	{

		return hour;

	}
	if (!strcmp ((char *) argumento1, "tarinfoyear"))
	{

		return year;

	}
	if (!strcmp ((char *) argumento1, "tarinfomonth"))
	{

		return month;

	}
	if (!strcmp ((char *) argumento1, "tarinfoday"))
	{

		return day;

	}
	if (!strcmp ((char *) argumento1, "tarinfofilename"))
	{


		strcpy ((char *) argumento2, filename);

		return 0;

	}
	if (!strcmp ((char *) argumento1, "tarinfosize"))
	{

		return size;

	}


	if (!strcmp ((char *) argumento1, "tarinfodelete"))
	{



		deletelist ();
		return 0;

	}


	if (!strcmp ((char *) argumento1, "getnumdir"))
	{

		return intdirectory;

	}

	if (!strcmp ((char *) argumento1, "getnumfiles"))
	{

		return intfilename;

	}

	return 0;

}

int Numdir_k = 0;// As Long
int Numfiles_k = 0;        // As Long

int Isdir_k = 0;
int Second_k = 0;               // As Long '= 0;
int Minute_k = 0;               // As Long '= 0;
int Hour_k = 0;                 // As Long '= 0;
int Year_k = 0;                 // As Long '= 0;
int Month_k = 0;                // As Long '= 0;
int Day_k = 0;                  // As Long '= 0;
char filename_k[1025] ={0};    // in Linux files can be up to 1024 bytes in size, of course this don't occur in Windows but here we are just showing the name of the files then it is ok
int Size_k = 0;                 // As Long '= 0;

//remove the spaces if you got time, Alladin


void __stdcall RetrieveTarInfo(int *Isdir__k, int *Year__k, int * Month__k,int * Day__k, int * Hour__k,int * Minute__k,int * Second__k,char * filename__k,int * Size__k,int * Numfiles__k, int * Numdir___k)
{

	strcpy(filename__k, filename_k);

	*Isdir__k    = Isdir_k;
	*Year__k     = Year_k;
	*Month__k    = Month_k;
	*Day__k      = Day_k;
	*Hour__k     = Hour_k;
	*Minute__k   = Minute_k;
	*Second__k   = Second_k;
	*Size__k     = Size_k;
	*Numfiles__k = Numfiles_k;
	*Numdir___k  = Numdir_k;

	return;

}


int __stdcall Status_k()
{
	return interface1((__INT32_OR_INT64)"status", 0, 0, 0);
}
/**
 * It will define the mode of the operation
 *
 * flag_k == 1 it will list, 0 it will uncompress
 *
 */
void __stdcall Setflaglist_k(int flag_k)
{
	interface1((__INT32_OR_INT64)"setflaglist", flag_k, 0, 0);
	return;
}

int __stdcall RSPListTarFile(char * filename_utf_8, tar_list_function the_function_k)
{
	FILE * myfile_k = NULL;
	int returnvalue_k = 0;
	if(!strlen(filename_utf_8))
	{
		returnvalue_k = 3;
		goto saida_k;
	}

	{
		WCHAR wide_temp_k[300] ={0};
		pereira_koci_utf8towide_b(filename_utf_8, wide_temp_k, 300);
		myfile_k = _wfopen(wide_temp_k, L"rb");
	}

	if(NULL == myfile_k)
	{
		returnvalue_k = 5;
		goto saida_k;
	}

	fclose(myfile_k);

	if(interface1((__INT32_OR_INT64)"status", 0, 0, 0))
	{
		returnvalue_k = 31;
		goto saida_k;
	}

	interface1((__INT32_OR_INT64)"setflaglist", 1, 0, 0);
	/*
	   Dim DestinationDir As String
	   DestinationDir = "c:\"
	   Dim FilesSelection As String

	   FilesSelection = "*.*"
	   ret = TGzip.CallWindow("rspuntar", TarFile, DestinationDir, FilesSelection)*/

	interface1((__INT32_OR_INT64)"rspuntar",(__INT32_OR_INT64) filename_utf_8,(__INT32_OR_INT64) "c:\\",(__INT32_OR_INT64)"*.*");

	while(Status_k())
	{
		pedro_dprintf(-1, "porque?");
		Sleep(10);
	}

	{

		int ret_k = 0;//

		ret_k = interface1((__INT32_OR_INT64)"tarinfo",(__INT32_OR_INT64) 0,(__INT32_OR_INT64) 0,(__INT32_OR_INT64) 0);

		//ret = TGzip.CallWindowLONG("tarinfo", 0, 0, 0)

/*


   enum amanda_modes
   {
        AR_INIT,
        AR_PROCESS,
        AR_END,
   };

 */
		the_function_k(AR_INIT);

		if(ret_k)
		{

pedro_dprintf(0, "dentro");

denovo_k:

			Isdir_k    = interface1((__INT32_OR_INT64)"tarinfoisdir",  0, 0, 0);
			Second_k   = interface1((__INT32_OR_INT64)"tarinfosecond", 0, 0, 0);
			Minute_k   = interface1((__INT32_OR_INT64)"tarinfominute", 0, 0, 0);;
			Hour_k     = interface1((__INT32_OR_INT64)"tarinfohour",   0, 0, 0);
			Year_k     = interface1((__INT32_OR_INT64)"tarinfoyear",   0, 0, 0);
			Month_k    = interface1((__INT32_OR_INT64)"tarinfomonth",  0, 0, 0);
			Day_k      = interface1((__INT32_OR_INT64)"tarinfoday",    0, 0, 0);
			Size_k     = interface1((__INT32_OR_INT64)"tarinfosize",   0, 0, 0);;
			filename_k[0] = 0;
			interface1((__INT32_OR_INT64)"tarinfofilename",(__INT32_OR_INT64) filename_k, (__INT32_OR_INT64) " ", 0);;

			Numdir_k   = interface1((__INT32_OR_INT64)"getnumdir",     0, 0, 0);
			Numfiles_k = interface1((__INT32_OR_INT64)"getnumfiles",   0, 0, 0);

			//(Isdir, Year, Month, Day, Hour, Minute, Second, filename, Size, Numfiles, Numdir)

			the_function_k(AR_PROCESS);

			ret_k   = interface1 ((__INT32_OR_INT64)"tarinfo2", 0, 0, 0);

			if(ret_k)
			{
				goto denovo_k;
			}

		}
		the_function_k(AR_END);
	}

saida_k:;

	return returnvalue_k;
}

#ifdef AMANDA_MAIN___

int __stdcall tar_list_function_k(const int clear_flag_k)
{


	int Numdir_1_k = 0;// As Long
	int Numfiles_1_k = 0; // As Long

	int Isdir_1_k = 0;
	int Second_1_k = 0;       // As Long '= 0;
	int Minute_1_k = 0;       // As Long '= 0;
	int Hour_1_k = 0;         // As Long '= 0;
	int Year_1_k = 0;         // As Long '= 0;
	int Month_1_k = 0;        // As Long '= 0;
	int Day_1_k = 0;          // As Long '= 0;
	static char filename_1_k[1025]; // in Linux files can be up to 1024 bytes in size, of course this don't occur in Windows but here we are just showing the name of the files then it is ok
	int Size_1_k = 0;


	if(AR_INIT == clear_flag_k)
	{
		printf("Inicio \n ");
	}

	if(AR_PROCESS == clear_flag_k)
	{

		RetrieveTarInfo(&Isdir_1_k, &Year_1_k, &Month_1_k, &Day_1_k, &Hour_1_k, &Minute_1_k, &Second_1_k, filename_1_k, &Size_1_k, &Numfiles_1_k, &Numdir_1_k);

		printf(" \n-----------------------------------\nArquivo:%s \nEh diretorio %d timestamp %02d/%02d/%04d %02d :%02d :%02d \nNumber of files %d, Number of Dirs %d ", filename_1_k, Isdir_1_k, Day_1_k, Month_1_k, Year_1_k, Hour_1_k, Minute_1_k, Second_1_k, Numfiles_1_k, Numdir_1_k);

	}

	if(AR_END == clear_flag_k)
	{
		printf("Fim \n ");
	}

	return 0;
}

int main()
{
	int returnvalue_k = 0;
	returnvalue_k = RSPListTarFile("taglib-1.11.1.tar.gz", tar_list_function_k);

	pedro_dprintf(0, "saiu %d ", returnvalue_k);

	return 0;
}

#endif
