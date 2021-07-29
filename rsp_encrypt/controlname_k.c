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

int __stdcall ControlName (char *data)
{
	strcpy (data, "BW Encrypt DLL " AMARIC__VERSION

	 #ifdef _WIN64
	        "  -  64 bits"
	 #else
	        "  -  32 bits"
	 #endif

	        );
	return 0;
}