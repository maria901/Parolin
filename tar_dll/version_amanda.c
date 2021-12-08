//2021 MathMan and amanda
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

#include "aline_definitive_header_2_.h"

int __stdcall ControlName(char *version_amanda)
{
	char ver_ric[300] = "BW Tar DLL " AMARIC__VERSION
	
#ifdef WIN64
	" 64 Bits - "
#else
	" 32 Bits - "
#endif

#if 0x0 == AMANDA_MODE
     " Basic "
#elif 0x1 == AMANDA_MODE
      " Full " 
#elif 0x2 == AMANDA_MODE
      " Minimalist " 
#endif

__DATE__ " " __TIME__ ;
	strcpy(version_amanda, ver_ric);

	return 27;
}