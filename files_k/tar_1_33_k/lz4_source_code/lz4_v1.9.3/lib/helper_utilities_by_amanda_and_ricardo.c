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

        direct programmers e-mails:
        Ricardo: arsoftware25@gmail.com  ricardo@arsoftware.net.br
         Amanda: arsoftware10@gmail.com  amanda@arsoftware.net. br

        immediate contact(for a very fast answer) WhatsApp
        (+55)41 9627 1708 - it is always on
 */

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

int intpause___aakp = 0;
int intcancel__rspk = 0;

static __int64 tamanho____aakp = 0;
static __int64 processado_rspk = 0;

static int internal_error_arp;

int porcentagem_junior_ale_mislaine_thalia_aline_juliete_valquiria_maria_feline_pedro;

WCHAR* __stdcall utf8towide (const char *pUTF8)
{
/* nUSC2 is the number of characters, not chars */

	static int position = 0;
	if(0==position)
	{
		static WCHAR pUSC2[1024];
		MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, 1024);
		position=1;
		return pUSC2;
	}
	else
	{
		static WCHAR pUSC2[1024];
		MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, pUSC2, 1024);
		position=0;
		return pUSC2;
	}
	return NULL;
}

static __int64 getfilesize_aakp_plus_rspk (char *infile_utf8_valquiria)
{

	__int64 ret;

	FILE  *myfile;

	if ((myfile = _wfopen (utf8towide(infile_utf8_valquiria), L"rb")) == NULL)
	{
		//dprintf ("The file 'data' was not opened\n");
		return 0;
	}
	else
	{
		//dprintf ("The file 'data' was opened\n");
	}

	ret = _fseeki64 (myfile, 0, SEEK_END);

	ret = _ftelli64 (myfile);

	// dprintf ("tamanho do arquivo %d\n ", ret);

	fclose (myfile);

	// printf ("Tamanho do arquivo %s  %d \n", infile, ret);

	return ret;

}

int lgetpor (__int64 max_Amanda, __int64 fatia_Ricardo)
{
/*

   2/27/2004 12:13PM modificacao para evitar divisao por 0, eu te amo...

 */

	double maxa;
	double fatiaa;

	maxa =   (double)    max_Amanda;
	fatiaa = (double) fatia_Ricardo;

	if (max_Amanda == 0 || fatia_Ricardo == 0)
	{
		return 0;
	}

	maxa =  ((double) 10000 / maxa * fatiaa);

	return (int) maxa;

}