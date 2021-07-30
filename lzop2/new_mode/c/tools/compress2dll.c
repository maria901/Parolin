
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

/*
    <main dll interface>
    Copyright (C) BW
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

#include "stdio_v2.h"

//bool is_multi_thread_z                = false;

#define __amandacall                   __stdcall

int __amandacall get_multithread_progress(void);

int *cores_used_z                        = NULL;

extern bool is_multi_thread_z                  ;
char temp_path_z                         [1024];
int n_threads_z                             = 1; 

//#include "bzlib.h"

#include "aline_definitive_header_2_.h"

#ifdef _WIN64
#define __INT32_OR_INT64 __int64
#else
#define __INT32_OR_INT64 int
#endif

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

int utf8towide (const char *pUTF8, WCHAR * pUSC2, int nUSC2);
int __stdcall IsAMD64 (void);
int    compress2_uncompress (char *input, char *output);
int    compress2_compress (char *input, char *output, int levelin);
int    compress2_compress_k (char *input, char *output, int levelin);

void   removedordeespaconoinicio (char *path);
void   removedordeespaconofinal (char *path);
char  *getcpuname_k (void);
char  *getprocessorbrandstring_k (void);
char myinfile[255];
char myoutfile[255];
int comando;
char mylevel[255];
char library[255];
int intpause;
int intcancel;

int filesize;
int intfatia;
int intstatus;
int intreturn;

int modo = 0;
int levelok = 6;

extern int lzop2percent;

int unicodemode=0;

void   dprintf (char *format, ...);

int __stdcall pause ()
{
	intpause = 1;
	return 0;
}

int __stdcall cancel ()
{
	intcancel = 1;
	return 0;
}
int __stdcall bresume ()
{
	intpause = 0;
	return 0;
}

int __stdcall startapi (__attribute__((unused)) int parameter)
{
	if (comando == 0)
	{
		intreturn = 0;
		assert(0);//intreturn = bzip2compress (myinfile, myoutfile, mylevel);
	}
	if (1 == comando)
	{
		intreturn = 0;
		assert(0);//intreturn = bzip2decompress (myinfile, myoutfile);
	}
	if (2 == comando)
	{
		intreturn = 0;
		assert(0);//intreturn = lzop2compress (myinfile, myoutfile, levelok);
	}
	if (3 == comando)
	{
		intreturn = 0;
		intreturn = compress2_uncompress (myinfile, myoutfile);
	}
	if (4 == comando)
	{
		intreturn = 0;
		intreturn = compress2_compress_k (myinfile, myoutfile, levelok);
	}
	intstatus = 0;
	return 0;
}
/*
BOOL WINAPI DllMain (HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("BW LZ5 DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") _amanda_debug_ \n");

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
*/
int __stdcall execute (char *infile, char *outfile, char *level, int comando1)
{
	HANDLE myhandle;
	__INT32_OR_INT64 ThreadId;
	__INT32_OR_INT64 parameter = 1;
	strcpy (myinfile, infile);
	strcpy (myoutfile, outfile);
	strcpy (mylevel, level);
	comando = comando1;
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, (DWORD) 0, (void *) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 2;
}
static int getpor (int max, int fatia)
{
	float a;
	a = (float) max;
	
	if (max == 0)
	{
		return 0;
	}
	a = ((float) 100 / max) * fatia;
	return (int) a;
}
int __stdcall getprogress ()
{
	int ret;
	
	if(1)//hack
	{		
		ret = get_multithread_progress();
		pedro_dprintf(-1, "progress multithread %d\n", ret);
	}
	
	if (ret > 10000)
	{
		ret = 10000;
	}
	if (ret < 0)
	{
		ret = 0;
	}
	if (intstatus == 1)
	{

		if (ret > 9800)
		{
			ret = 9900;
		}

	}

	return ret;
}

int __stdcall status (int newvalue)
{
	if (newvalue == 1)
	{
		intstatus = 1;
		return 1;
	}
	return intstatus;
}

int __stdcall interface1 (__INT32_OR_INT64 argumento1, __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3, __INT32_OR_INT64 argumento4)
{
	static char inputfile[255];
	static char outputfile[255];
	if (!strcmp ((char *) argumento1, "compress"))
	{
		modo = 0;
		strcpy (inputfile, (char *) argumento2);
		strcpy (outputfile, (char *) argumento3);
		execute (inputfile, outputfile, (char *) argumento4, 0);  //0 compress 1 decompress
		return 1;
	}
	if (!strcmp ((char *) argumento1, "compressbzip3"))
	{
		modo = 1;
		strcpy (inputfile, (char *) argumento2);
		strcpy (outputfile, (char *) argumento3);
		execute (inputfile, outputfile, (char *) argumento4, 2);  //0 compress 1 decompress
		return 1;
	}

	if (!strcmp ((char *) argumento1, "compressbzip3_k"))
	{
		modo = 1;
		strcpy (inputfile, (char *) argumento2);
		strcpy (outputfile, (char *) argumento3);
		execute (inputfile, outputfile, (char *) argumento4, 4);  //0 compress 1 decompress
		return 1;
	}

	if (!strcmp ((char *) argumento1, "decompress"))
	{
		modo = 0;
		strcpy (inputfile, (char *) argumento2);
		strcpy (outputfile, (char *) argumento3);
		execute (inputfile, outputfile, (char *) argumento4, 1);  //0 compress 1 decompress
		return 1;
	}
	if (!strcmp ((char *) argumento1, "decompressbzip3"))
	{
		modo = 1;
		strcpy (inputfile, (char *) argumento2);
		strcpy (outputfile, (char *) argumento3);
		execute (inputfile, outputfile, (char *) argumento4, 3);  //0 compress 1 decompress
		return 1;
	}

	if (!strcmp ((char *) argumento1, "status"))
	{
		return (status (argumento2));
	}

	if (!strcmp ((char *) argumento1, "getprogress"))
	{
		return (getprogress ());
	}
	if (!strcmp ((char *) argumento1, "bresume"))
	{
		return (bresume ());
	}
	if (!strcmp ((char *) argumento1, "pause"))
	{
		return (pause ());
	}
	if (!strcmp ((char *) argumento1, "cancel"))
	{
		while (intstatus)
		{
#ifdef NPRINTF
			dprintf (" loopenado no cancel\n");
#endif
			cancel ();
			Sleep (50);
		};
		return (cancel ());
	}
	if (!strcmp ((char *) argumento1, "selectlibrary"))
	{
		strcpy (library, (char *) argumento2);
		return (3);
	}

	if (!strcmp ((char *) argumento1, "thestatus"))
	{
		return intstatus;
	}

	if (!strcmp ((char *) argumento1, "intreturn"))
	{
		return (intreturn);
	}

	if (!strcmp ((char *) argumento1, "setlevel"))
	{
		levelok = argumento2;
#ifdef NPRINTF
		dprintf ("compression level %d \n", levelok);
#endif
		return 0;
	}
	
	return 15;
}

double _time;
int __stdcall ControlName(char*data)
{
	strcpy(data,"BW Brotli2 DLL " AMARIC__VERSION
#ifdef _WIN64
	       " 64 bits ;-)"
#else
	       " 32 bits ;-)"
#endif
	       );
	return 0;
}
int __stdcall GetCPUVendor(char*data)
{
	interface1((__INT32_OR_INT64)"getcpuname", (__INT32_OR_INT64)data, 0, 0);
	return 0;
}

int __stdcall GetCPUBrandString(char*data)
{
	interface1((__INT32_OR_INT64)"getbrandstring", (__INT32_OR_INT64)data, 0, 0);
	return 0;
}

void mprintf2 (char *format, ...)
{
	int val;
	va_list args;
	static char buffer[50000];
	va_start (args, format);
	vsprintf (buffer, format, args);
	val = MessageBox (0, buffer, "BW", MB_OK | MB_TOPMOST);

	if (val != IDOK)//if amanda need to use it in a near future...
	{
		;
	}	
}

int __stdcall About()
{
	mprintf2("Win32 and Win64 DLL to compress files using compress2 compression methods");
	return 0;
}

int __stdcall Compress(char*Inputfile,char*OutPutFile,int CompressionLevel)
{
	char level[300];
	int ret;
	unicodemode=0;
	ret = interface1((__INT32_OR_INT64)"status", 0, 0, 0);
	if (1==ret)
	{
		return 7;
	}

	_time=(double)GetTickCount();

	if( (CompressionLevel > 9) || (CompressionLevel < 0) )
	{
		return 1;
	}

	sprintf(level,"w%d",CompressionLevel);

	ret = interface1((__INT32_OR_INT64)"status", 1, 0, 0);

	ret = interface1((__INT32_OR_INT64)"compress",(__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64)level);

	return 0;
}

int __stdcall GetStatus()
{
	return interface1((__INT32_OR_INT64)"status", 0, 0, 0);
}

int __stdcall GetReturnValue()
{
	return interface1((__INT32_OR_INT64)"intreturn", 0, 0, 0);
}

double
dgetval (double maxa, double porr)
{
	maxa = (maxa / 100) * porr;
	return maxa;
}

double                          // pegar o maximo a partir da porcentagem
dgetmax (double por, double fatia)
{
	double a;
	double b;
	a = (double) por;
	b = (double) fatia;
	if (por == 0.0)
	{
		return 0.0;
	}
	a = (b / a) * (float) 100.0;
	return (double) a;
}

double dgetpor (double maxa, double fatiaa)
{

	if (maxa == 0)
	{
		return 0;
	}

	maxa = ((double) 100.0 / maxa * fatiaa);

	return (double) maxa;

}

int
secondtostring (double value,char*data)
{
//[closed?]
	unsigned int frame;
	unsigned int ret;
	unsigned int seg;
	unsigned int min;
	unsigned int hour;
	ret = (unsigned int) value;
	frame = ret % 1000;
	ret = ret / 1000;
	seg = ret % 60;
	ret = ret / 60;         // minutos
	min = ret % 60;
	ret = ret / 60;         // horas
	hour = ret % 100;
	sprintf (data, "%02d:%02d:%02d:%03d", hour, min, seg, frame);
	return 0;
}

int __stdcall GetProgress();
int __stdcall GetTimeToFinish(char*data)
{
	void dprintf3 (char *format, ...);
	double dret;
	double dporcentagem;

	double desloca = (double)GetTickCount();

	dporcentagem=(double) GetProgress();

	dret=dgetmax(dporcentagem,desloca-_time);
#ifdef NPRINTF
	dprintf("valor %f\n",dret);
#endif
	dret=dret-(desloca-_time);

	secondtostring(dret,data);
#ifdef NPRINTF
	dprintf("valor2 %s\n",data);
#endif
	return 0;
}

int __stdcall GetProgress()
{
	return interface1((__INT32_OR_INT64)"getprogress", 0, 0, 0);
}

int __stdcall Compresscompress2_(char*Inputfile,char*OutPutFile,int CompressionLevel)
{
	char level[300];
	int ret;
	unicodemode=1;
	ret = interface1((__INT32_OR_INT64)"status", 0, 0, 0);

	if (1==ret) {

		return 7;
	}

	_time=(double)GetTickCount();

	if( (CompressionLevel > 9) || (CompressionLevel < 0) )
	{
		return 1;
	}

	sprintf(level,"w%d",CompressionLevel);

	interface1((__INT32_OR_INT64)"setlevel", CompressionLevel, CompressionLevel, CompressionLevel);

	ret = interface1((__INT32_OR_INT64)"status", 1, 0, 0);

	ret = interface1((__INT32_OR_INT64)"compressbzip3",(__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64)level);

	return 0;
}

int __stdcall Compresscompress2__k(char*Inputfile,char*OutPutFile,int CompressionLevel)
{
	char level[300];
	int ret;
	unicodemode=1;
	ret = interface1((__INT32_OR_INT64)"status", 0, 0, 0);

	if (1 == ret)
	{
		return 77;
	}
	/*
		_time=(double)GetTickCount();
	*/
	if( (CompressionLevel > 9) || (CompressionLevel < 0) )
	{
		return 100;
	}

	sprintf(level,"w%d",CompressionLevel);

	interface1((__INT32_OR_INT64)"setlevel", CompressionLevel, CompressionLevel, CompressionLevel);

	ret = interface1((__INT32_OR_INT64)"status", 1, 0, 0);

	ret = interface1((__INT32_OR_INT64)"compressbzip3_k",(__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64)level);


volta_arp:;

	ret = interface1((__INT32_OR_INT64)"status", 0, 0, 0);

		if (1 == ret) {

			Sleep(50);
			goto volta_arp;
		}

	return GetReturnValue();

}

int __stdcall PauseCompress()
{
	return interface1((__INT32_OR_INT64)"pause", 0, 0, 0);
}
int __stdcall ResumeCompress()
{
	return interface1((__INT32_OR_INT64)"bresume", 0, 0, 0);
}
int __stdcall CancelCompress()
{
	return interface1((__INT32_OR_INT64)"cancel", 0, 0, 0);
}

int __stdcall Decompress(char*Inputfile,char*OutPutFile)
{
	int ret;
	unicodemode=0;
	ret = interface1((__INT32_OR_INT64)"status", 0, 0, 0);

	if (1==ret) {

		return 7;
	}
	_time=(double)GetTickCount();
	ret = interface1((__INT32_OR_INT64)"status", 1, 0, 0);
	ret = interface1((__INT32_OR_INT64)"decompress",(__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64)"w9");
	return 0;
}

int __stdcall Decompresscompress2_(char*Inputfile,char*OutPutFile)
{
	int ret;
	unicodemode = 1;
	ret = interface1((__INT32_OR_INT64)"status", 0, 0, 0);

	if (1==ret) {

		return 77;
	}
	/*
	
		_time=(double)GetTickCount();
	
	*/
	ret = interface1((__INT32_OR_INT64)"status", 1, 0, 0);

	ret = interface1((__INT32_OR_INT64)"decompressbzip3",(__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64)"w9");


volta_arp:;

ret = interface1((__INT32_OR_INT64)"status", 0, 0, 0);

	if (1 == ret) {

		Sleep(50);
		goto volta_arp;
	}

return GetReturnValue();

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
	int i;
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return 0;
}

/**
* return values
23  = Input file read error
107 = Cannot open input file
108 = Cannot open output file
114 = Cannot write to output file
116 = Unexpected error
119 = User cancel
*
*
*/
int __stdcall compress_l3___rspk_ar(char * Input_amanda_file, char * OutPut_ricardo_File, int Compression_juliete_Level, int n_threads_z__, char *temp_path_z__)
{
	pedro_dprintf(-1, "dentro\n");
	is_multi_thread_z = false         ;
	n_threads_z = n_threads_z__       ;	
	strcpy(temp_path_z, temp_path_z__);
	return Compresscompress2__k(Input_amanda_file, OutPut_ricardo_File, Compression_juliete_Level);
}
/**
*
14  = Cannot write to output file

107 = Cannot open input file
108 = Cannot open output file
119 = User cancel
121 = Cannot init decompression
122 = Cannot read from input file
123 = md5 checksum error
124 = Unexpected error
125 = Memory error
126 = Invalid lzop2 stream
198 = Header magic error
199 = Invalid lzop2 file
300 = sha512 checksum error
*
*
*
*/
int __stdcall uncompress_l3___rspk_ar(char * Inputfile_arp, char * OutPutFile_arp, int n_threads_z__ /* number of threads to use */, char *temp_path_z_S2__, int * cores_used_z__)
{
	cores_used_z         = cores_used_z__;
	assert(cores_used_z);
	is_multi_thread_z             = false;
	n_threads_z = n_threads_z__          ;	
	strcpy(temp_path_z, temp_path_z_S2__);
	return Decompresscompress2_(Inputfile_arp, OutPutFile_arp);
}

int __stdcall get_progress_l3___ar(void)
{
	return GetProgress();
}

int __stdcall pause_l3___aakp_l3___ar(void)
{
	PauseCompress();
	return 0; 
}

int __stdcall resume_l3___aakp_l3___ar(void)
{
	ResumeCompress();
	return 0;
}

int __stdcall cancel_l3___aakp_l3___ar(void)
{
	CancelCompress();
	return 0;
}
