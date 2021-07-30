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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <io.h>

#undef NDEBUG
#include <assert.h>

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

   
   WCHAR* __stdcall utf8towide (const char *pUTF8)
{
/* nUSC2 is the number of characters, not chars */

static int position=0;
if(0==position)
{
    static WCHAR pUSC2[300];
    MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, 300);
	position=1;
    return pUSC2;
	}
	else
	{
	static WCHAR pUSC2[300];
    MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, 300);
	position=0;
    return pUSC2;
	}
	return NULL;
}
/*
        [DllImport("rspmp3ocx1.dll", CharSet = CharSet.Unicode)]
        extern static IntPtr widetoutf8(string unicode_filename);

        public static string wide2utf8(string unicode_filename)
        {
            IntPtr retVal = widetoutf8(unicode_filename);

            string val = Marshal.PtrToStringAnsi(retVal);
            return val;
        }
*/

__int64 _ftelli64_arab(FILE *stream);
int _fseeki64_arab(FILE *stream,__int64 offset,int origin);
		
int _fseeki64_arab(
        FILE *stream,
        __int64 offset,
        int origin
        )
{
	__int64 ret;
	ret=_lseeki64 (fileno(stream), offset, origin);
	if(-1!=ret)
	{
		return 0;
	}
	return 1;
}
__int64 _ftelli64_arab(
        FILE *stream
        )
{
	__int64 ret;
	ret = _telli64 (fileno(stream));
	return ret;
}
size_t fread_unbuffered(void *ptr, size_t size, size_t nelem, FILE *stream);
size_t fread_unbuffered(void *ptr, size_t size, size_t nelem, FILE *stream)
{
	int ret;
	assert(size);
	ret=_read(
	        fileno(stream),
	        ptr,
	        size* nelem
	        );
	return ret/size;
}
size_t fwrite_unbuffered(const void *ptr, size_t size, size_t nelem, FILE *stream);
size_t fwrite_unbuffered(const void *ptr, size_t size, size_t nelem, FILE *stream)
{
	int ret;
	assert(size);
	ret=_write(
	        fileno(stream),
	        ptr,
	        size* nelem
	        );
	return ret/size;
}
