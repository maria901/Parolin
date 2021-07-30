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

#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int
dectohex (uchar * buf, uchar * bufout, uint inputlen)
{
/*
        documentacao desta funcao

        buf , buf pode ser binario e nao string
        bufout sera a string in hexa notation
        inputlen o tamaho do buffer

        erros
        0  ok
        1  buf == NULL
        2  bufout == NULL


 */
	uint i;
	uchar *ptr;
	uchar *bufout1;

	ptr = buf;
	bufout1 = bufout;

	if (buf == NULL)
	{
		return 1;
	}

	if (inputlen == 0)
	{
		memset (bufout, 0, 1);
		return 0;
	}

	if (bufout == NULL)
	{
		return 2;
	}

	for (i = 0; i < inputlen; i++)
	{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
		sprintf ((char *)bufout1, "%0.2x", (uint) * ptr);
#pragma GCC diagnostic pop
		ptr++;
		bufout1 += 2;
	}

	return 0;

}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int
hextodec (uint initsize,uchar * buf, uchar * bufout, uint * buflen)
{

	/*
	   documentacao desta funcao

	   buf , o buffer em hexadecimal notation
	   bufout , o buffer de saida depois de reconstruido
	   buflen , pode ser NULL ou sera o numero de itens reconstruido
	   ou seja o tamanho du buffer inicial

	   errors

	   0 ok
	   1 buf == NULL
	   2 bufout == NULL
	   3 tamanho do buffer diferente de multiplo de dois
	   4 invalid hexadecimal character it need to be one of 0123456789abcdef

	 */
	uint ret;
	uchar tmpbuf[6];
	uchar *ptr;
	uint i;
	uint ii;
	uint ret2;

	if (buf == NULL)
	{
		return 1;
	}

	if (bufout == NULL)
	{
		return 2;
	}

	if (!strlen ((char *) buf))
	{
		memset (bufout, 0, 1);
		return 0;
	}

	ptr = buf;
	ret = initsize;

	ii = 0;
	if (ret % 2)
	{

		if (buflen != NULL)
		{
			*buflen = 0;
		}

		return 3;       // erro na string tem que ser multiplo de 2

	}
	else
	{
		;
	}

	for (i = 0; i < ret; i += 2)
	{

		memset (tmpbuf, 0, 5);
		memcpy (tmpbuf, ptr, 2);

		if ((tmpbuf[0] >= 'a' && tmpbuf[0] <= 'f')
		    || (tmpbuf[0] >= 'A' && tmpbuf[0] <= 'F') || (tmpbuf[0] >= '0'
		                                                  && tmpbuf[0] <=
		                                                  '9'))
		{

			;
		}
		else
		{
			return 4;
		}

		if ((tmpbuf[1] >= 'a' && tmpbuf[1] <= 'f')
		    || (tmpbuf[1] >= 'A' && tmpbuf[1] <= 'F') || (tmpbuf[1] >= '0'
		                                                  && tmpbuf[1] <=
		                                                  '9'))
		{

			;
		}
		else
		{
			return 4;
		}

		sscanf ((char *) tmpbuf, "%2x", &ret2);
		bufout[ii] = ret2;
		ii++;
		ptr += 2;

	}

	bufout[ii] = 0;

	if (buflen != NULL)
	{
		*buflen = ret / 2;
	}
	return 0;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

#ifdef RSPHEXADEBUG
int
main ()
{

	char original[255] = { 0, 2, 3, 4, 0, 6, 7 };
	char destination[255];
	char temp[255];
	int ret;
	uint tamamnho;

	tamamnho = 7;

	for (; tamamnho; tamamnho--)
	{

#ifdef NPRINTF
		dprintf ("Item %d = %d \n", original[tamamnho - 1], tamamnho - 1);
#endif

	}

	ret = dectohex (original, destination, 7);

	if (ret)
	{

#ifdef NPRINTF
		dprintf ("Erro na conversao \n");
#endif

	}
	else
	{

#ifdef NPRINTF
		dprintf ("valor de ret %d original -%s- \n", ret, original);
		dprintf ("destino -%s- \n", destination);
#endif

	}

	ret = hextodec (destination, temp, &tamamnho);

	if (ret)
	{

#ifdef NPRINTF
		dprintf ("Erro na conversao \n");
#endif

	}
	else
	{

#ifdef NPRINTF
		dprintf ("valor de ret %d depois de reconstruido -%s- \n", ret, temp);
#endif

	}

#ifdef NPRINTF
	dprintf ("Tamanho da string reconstruida %d \n", tamamnho);
#endif

	ret = hextodec (destination, temp, &tamamnho);

	if (ret)
	{
#ifdef NPRINTF
		dprintf ("Erro na conversao %d\n", ret);
#endif
	}
	else
	{
#ifdef NPRINTF
		dprintf ("valor de ret %d depois de reconstruido -%s- \n", ret, temp);
#endif

	}
#ifdef NPRINTF
	dprintf ("Tamanho da string reconstruida %d \n", tamamnho);
#endif

	for (; tamamnho; tamamnho--)
	{
#ifdef NPRINTF
		dprintf ("Item %d = %d \n", temp[tamamnho - 1], tamamnho - 1);
#endif
	}

	if (memcmp (original, temp, 7))
	{
#ifdef NPRINTF
		dprintf ("Deu erro na checagem final \n ");
#endif
	}
	else
	{
#ifdef NPRINTF
		dprintf ("Deu certo na checagem final \n ");
#endif
	}
	return 0;

}

#endif