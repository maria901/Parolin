/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de C�pia (C) <2021>  <Corpora��o do Trabalho Bin�rio>         *
 *                                                                              *
 *     Este  programa  � software livre: voc� pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como       8
 *     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da       *
 *     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.         *
 *                                                                              *
 *     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de       *
 *     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P�blica para mais detalhes.                                *
 *                                                                              *
 *     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P�blica Menor junto com este programa                            *
 *     Se n�o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails:                                                                 *
 *     maria@arsoftware.net.br                                                  *
 *     pedro@locacaodiaria.com.br                                               *
 *                                                                              *
 *     contato imediato(para uma resposta muito r�pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

int intpause___aakp     = 0;
int intcancel__rspk     = 0;

__int64 tamanho____aakp = 0;
__int64 processado_rspk = 0;
int     return_value_arp;

int porcentagem_junior_ale_mislaine_thalia_aline_juliete_valquiria_maria_feline_pedro;

static WCHAR* __stdcall utf8towide (const char *pUTF8)
{
/* nUSC2 is the number of characters, not chars */

	static int position=0;
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

__int64 getfilesize_aakp_plus_rspk (char *infile_utf8_valquiria)
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