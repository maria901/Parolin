/* Copyright 2014 Google Inc. All Rights Reserved, modified by MathMan from BinaryWork

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT
 */

/* Command line interface for Brotli library. */
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

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

//#define ARP_DEBUG__ 0x1001

#include "stdio_v2.h"
#include "stdio_v3.h"

int
compress(
FILE * fdin   ,
FILE_z * fdout,
my_thread_struct_z * amanda);
int
compress_thread_1(
FILE * fdin   ,
FILE_z * fdout,
my_thread_struct_z * amanda);
int
compress_thread_2(
FILE * fdin   ,
FILE_z * fdout,
my_thread_struct_z * amanda);
int
compress_thread_3(
FILE * fdin   ,
FILE_z * fdout,
my_thread_struct_z * amanda);
int
compress_thread_4(
FILE * fdin   ,
FILE_z * fdout,
my_thread_struct_z * amanda);
int
compress_thread_5(
FILE * fdin   ,
FILE_z * fdout,
my_thread_struct_z * amanda);
int
compress_thread_6(
FILE * fdin   ,
FILE_z * fdout,
my_thread_struct_z * amanda);
int
compress_thread_7(
FILE * fdin   ,
FILE_z * fdout,
my_thread_struct_z * amanda);

int
decompress(
FILE * fdin                 ,
FILE * fdout                ,
my_thread_struct_z * amanda);

int
decompress_thread_1(
FILE * fdin                 ,
FILE * fdout                ,
my_thread_struct_z * amanda);

int
decompress_thread_2(
FILE * fdin                 ,
FILE * fdout                ,
my_thread_struct_z * amanda);

int
decompress_thread_3(
FILE * fdin                 ,
FILE * fdout                ,
my_thread_struct_z * amanda);

int
decompress_thread_4(
FILE * fdin                 ,
FILE * fdout                ,
my_thread_struct_z * amanda);

int
decompress_thread_5(
FILE * fdin                 ,
FILE * fdout                ,
my_thread_struct_z * amanda);

int
decompress_thread_6(
FILE * fdin                 ,
FILE * fdout                ,
my_thread_struct_z * amanda);

int
decompress_thread_7(
FILE * fdin                 ,
FILE * fdout                ,
my_thread_struct_z * amanda);

extern int lgetpor (__int64 max_Amanda, __int64 fatia_Ricardo);
extern WCHAR* __stdcall utf8towide (const char *pUTF8);
extern __int64 getfilesize_aakp_plus_rspk (char *infile_utf8_valquiria);

extern __int64 tamanho____aakp;
extern __int64 processado_rspk;

extern int intpause___aakp ;
extern int intcancel__rspk ;
extern int return_value_arp;

compressResult_t
compress_file(FILE* f_in, FILE_z* f_out, my_thread_struct_z * amanda)
{
	int returnvalue_z = 0;
		
	compressResult_t result_z = {1, 0, 0};
	
	switch(amanda->thread_id_z)
	{
		case 0:
		returnvalue_z = compress(amanda->input_file, amanda->dest, amanda);
		break;
		case 1:
		returnvalue_z = compress_thread_1(amanda->input_file, amanda->dest, amanda);
		break;
		case 2:
		returnvalue_z = compress_thread_2(amanda->input_file, amanda->dest, amanda);
		break;
		case 3:
		returnvalue_z = compress_thread_3(amanda->input_file, amanda->dest, amanda);
		break;
		case 4:
		returnvalue_z = compress_thread_4(amanda->input_file, amanda->dest, amanda);
		break;
		case 5:
		returnvalue_z = compress_thread_5(amanda->input_file, amanda->dest, amanda);
		break;
		case 6:
		returnvalue_z = compress_thread_6(amanda->input_file, amanda->dest, amanda);
		break;
		case 7:
		returnvalue_z = compress_thread_7(amanda->input_file, amanda->dest, amanda);
		break;
		default:		
		pedro_dprintf(2, "Invalid value for compress2 thread\n");
		exit(27);
		
		break;
	}
	if(0 == returnvalue_z)
	{
		result_z.error = 0;
	}
	
	return result_z;
}

/* @result : 1==error, 0==success */
int decompress_file(FILE* f_in, FILE* f_out, my_thread_struct_z * amanda)
{
	int retvalue_z = 0;
		
	switch(amanda->thread_id_z)
	{
		case 0:
		retvalue_z = decompress(f_in, f_out, amanda);
		break;
		case 1:
		retvalue_z = decompress_thread_1(f_in, f_out, amanda);
		break;
		case 2:
		retvalue_z = decompress_thread_2(f_in, f_out, amanda);
		break;
		case 3:
		retvalue_z = decompress_thread_3(f_in, f_out, amanda);
		break;
		case 4:
		retvalue_z = decompress_thread_4(f_in, f_out, amanda);
		break;
		case 5:
		retvalue_z = decompress_thread_5(f_in, f_out, amanda);
		break;
		case 6:
		retvalue_z = decompress_thread_6(f_in, f_out, amanda);
		break;
		case 7:
		retvalue_z = decompress_thread_7(f_in, f_out, amanda);
		break;
		default:		
		pedro_dprintf(2, "Invalid value for decompress thread\n");
		exit(27);
		
		break;
	}

	if(retvalue_z     )
	{
		retvalue_z = 1;
	}
	
	return  retvalue_z;
}