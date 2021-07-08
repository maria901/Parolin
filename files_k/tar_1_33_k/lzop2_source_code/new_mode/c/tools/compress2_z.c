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

#ifndef __amandacall
#define __amandacall /* our own function call method */ __stdcall
#endif

int __amandacall compress_z(FILE *input_z, FILE_z* output_z, my_thread_struct_z * amanda);
int __amandacall uncompress_z(FILE *input_z, FILE* output_z, my_thread_struct_z * amanda);

extern int lgetpor (__int64 max_Amanda, __int64 fatia_Ricardo);
extern WCHAR* __stdcall utf8towide (const char *pUTF8);
extern __int64 getfilesize_aakp_plus_rspk (char *infile_utf8_valquiria);

extern __int64 tamanho____aakp;
extern __int64 processado_rspk;

extern int intpause___aakp ;
extern int intcancel__rspk ;
extern int return_value_arp;

compressResult_t
compress_file(FILE* f_in_z, FILE_z* f_out_z, my_thread_struct_z * amanda)
{
	int returnvalue_z = 0;//setting this to 0 is irrelevant

	compressResult_t result_z = {1, 0, 0};

	//aqui

	returnvalue_z = compress_z(f_in_z, f_out_z, amanda);

	if(0 == returnvalue_z)
	{
		result_z.error = 0;
	}

	return result_z;
}

/* @result : 1==error, 0==success */
int decompress_file(FILE* f_in_z, FILE* f_out_z, my_thread_struct_z * amanda)
{
	int retvalue_z = 0;//setting this to 0 is irrelevant
	
	retvalue_z = uncompress_z(f_in_z, f_out_z, amanda);

	if(retvalue_z     )
	{
		retvalue_z = 1;
	}
	
	return  retvalue_z;
}