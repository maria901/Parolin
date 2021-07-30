//sample code to debug this mess...

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

int __stdcall compress_lzip_rspk
(
char * inputfile_utf_8,
char * outputfile_utf_8,
int level_aakp
);


int main()
{
	
	int ret_k;
	
	ret_k = compress_lzip_rspk("C:\\Ava\\back\\K_P_optimized libav.zip", "C:\\Ava\\back\\K_P_optimized libav.zip.lz", 6);
	
	printf("Return value from lzip %d\n", ret_k);
	
	return 0;
}