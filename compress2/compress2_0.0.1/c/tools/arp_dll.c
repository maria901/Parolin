/*
    Copyright (C) <2022>  <BinaryWork Corp.>

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

        direct programmers e-mails:
        MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br
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

#include "helper_utilities_by_amanda_and_ricardo.c"

BOOL WINAPI DllMain (HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("RSP Compress2 DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") _amanda_debug_\n");

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

