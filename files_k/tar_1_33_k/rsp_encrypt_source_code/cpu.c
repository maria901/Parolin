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

#include <cpuid.h>

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

char *
decimalparabinarioprintf (uint value);

int
getcpuinfo (int aeax, int *oEAX, int *oEBX, int *oECX, int *oEDX);

int getcpuinfo (int aeax, int *oEAX, int *oEBX, int *oECX, int *oEDX)
{
	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

/*

        //for historical reasons
        __try
        {


                __asm
                {

                        mov    eax, aeax;
                        cpuid;
                        mov    ieax, eax;
                        mov    iebx, ebx;
                        mov    iedx, edx;
                        mov    iecx, ecx;

                }

        }
        __except (1)
        {
                // dprintf ("Invalid CPU code \n");

                retvalue = 1;
        }
 */

	__cpuid(aeax, ieax, iebx, iecx, iedx);

	*oECX = iecx;
	*oEDX = iedx;
	*oEBX = iebx;
	*oEAX = ieax;

	return 0;

}

char *
getprocessorbrandstring ()
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;
	static char fixo[255];

	memset (fixo, 0, 254);

	if (getcpuinfo (0x80000000, &ieax, &iebx, &iecx, &iedx))
	{
		strcpy (fixo, "Unavailable");
		goto final;
	}

	if(ieax < 0x80000004)
	{
		strcpy (fixo, "Unavailable");
		goto final;
	}

	if (getcpuinfo (0x80000002, &ieax, &iebx, &iecx, &iedx))
	{
		strcpy (fixo, "Unavailable");
		goto final;
	}
	else
	{
		memcpy (&fixo[0], &ieax, 4);
		memcpy (&fixo[4], &iebx, 4);
		memcpy (&fixo[8], &iecx, 4);
		memcpy (&fixo[12], &iedx, 4);
	}

	if (getcpuinfo (0x80000003, &ieax, &iebx, &iecx, &iedx))
	{
		strcpy (fixo, "Unavailable");
		goto final;
	}
	else
	{
		memcpy (&fixo[16], &ieax, 4);
		memcpy (&fixo[20], &iebx, 4);
		memcpy (&fixo[24], &iecx, 4);
		memcpy (&fixo[28], &iedx, 4);
	}

	if (getcpuinfo (0x80000004, &ieax, &iebx, &iecx, &iedx))
	{
		strcpy (fixo, "Unavailable");
		goto final;
	}
	else
	{
		memcpy (&fixo[32], &ieax, 4);
		memcpy (&fixo[36], &iebx, 4);
		memcpy (&fixo[40], &iecx, 4);
		memcpy (&fixo[44], &iedx, 4);
	}

final:
	return fixo;

}

int __stdcall
getcputype (int *family, int *model, int *stepping)
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (1, &ieax, &iebx, &iecx, &iedx))
	{

		*family = 0;
		*model = 0;
		*stepping = 0;
		return 1;

	}

	*stepping = (ieax & 15);
	*model = ieax >> 4;
	*model = (*model & 15);
	*family = ieax >> 8;
	*family = (*family & 15);

	return 0;

}

char *
getcpuname ()
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;
	static char fixo[255];

	memset (fixo, 0, 254);

	if (getcpuinfo (0, &ieax, &iebx, &iecx, &iedx))
	{
		strcpy (fixo, "Unavailable");
	}
	else
	{
		memcpy (&fixo[0], &iebx, 4);
		memcpy (&fixo[4], &iedx, 4);
		memcpy (&fixo[8], &iecx, 4);
	}
	return fixo;
}

int __stdcall
hasMMX ()
{
	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;
	if (getcpuinfo (1, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}
	if (iedx & (1 << 23))
	{
		return 1;
	}
	return 0;
}

int __stdcall
hasSSE ()
{
	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (1, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}

	if (iedx & (1 << 25))
	{
		return 1;
	}
	return 0;
}

int __stdcall
hasSSE2 ()
{
	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;
	if (getcpuinfo (1, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}
	if (iedx & (1 << 26))
	{
		return 1;
	}
	return 0;
}

int __stdcall
has3DNOW ()
{
	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (0x80000001, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}

	if (iedx & (1 << 31))
	{
		return 1;
	}
	
	return 0;

}

int __stdcall
has3DNOWExtensions ()
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (0x80000001, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}

	if (iedx & (1 << 30))
	{
		return 1;
	}
	return 0;

}

int __stdcall
IsAMD64 ()
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (0x80000001, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}

	if (iedx & (1 << 29))
	{
		return 1;
	}
	return 0;

}

int __stdcall
hasCMOV ()
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (1, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}

	if (iedx & (1 << 15))
	{
		return 1;
	}
	return 0;

}

int __stdcall
hasHyperThreading ()
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (1, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}

	if (iedx & (1 << 28))
	{
		return 1;
	}
	return 0;

}

int __stdcall
hasFPU ()
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (1, &ieax, &iebx, &iecx, &iedx))
	{
		return 0;
	}

	if (iedx & (1))
	{
		return 1;
	}
	return 0;

}

int __stdcall
OShasSSEsupport ()
{
	return 1;//kkkkkk
}

int __stdcall
getcpuextendedfeature (int *eisst, int *tm2, int *ci)
{

	/*
	   Enhanced Intel SpeedStep technology.

	   Thermal Monitor 2.

	   Context ID.
	 */
	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	if (getcpuinfo (1, &ieax, &iebx, &iecx, &iedx))
	{
		return 1;
	}

	*eisst = 0;

	if (iecx & (1 << 7))
	{
		*eisst = 1;
	}

	*tm2 = 0;

	if (iecx & (1 << 8))
	{
		*tm2 = 1;
	}

	*ci = 0;

	if (iecx & (1 << 10))
	{
		*ci = 1;
	}

	return 0;

}