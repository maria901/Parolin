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

void pedro_dprintf(int amanda_level,
				   char *format, ...);

int intpause___aakp = 0;
int intcancel__rspk = 0;

static __int64 tamanho____aakp = 0;
__int64 processado_rspk = 0;
int return_value_arp;

int porcentagem_junior_ale_mislaine_thalia_aline_juliete_valquiria_maria_feline_pedro;

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

/**
 * To make the path wide mode aware, stolen from libarchive
 * 
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond...
 *
 */
wchar_t *
permissive_name_m_(const wchar_t *wname)
{

	static wchar_t *wnp = NULL;
	wchar_t *wn;
	wchar_t *ws, *wsp;
	DWORD len, slen;
	int unc;

	if (NULL == wnp)
	{
		wnp = calloc((AMANDA__SIZE_w * 2) + 2, 1);
	}

	//wnp = malloc(AMANDA__SIZE * 2);

	wcscpy(wnp, wname);

	len = wcslen(wname);

	wn = wnp;

	if (wnp[0] == L'\\' && wnp[1] == L'\\' && // access to the wrong position in memory, fixed now
		wnp[2] == L'?' && wnp[3] == L'\\')
		/* We have already a permissive name. */
		return (wn);

	if (wnp[0] == L'\\' && wnp[1] == L'\\' &&
		wnp[2] == L'.' && wnp[3] == L'\\')
	{
		/* This is a device name */
		if (((wnp[4] >= L'a' && wnp[4] <= L'z') ||
			 (wnp[4] >= L'A' && wnp[4] <= L'Z')) &&
			wnp[5] == L':' && wnp[6] == L'\\')
			wnp[2] = L'?'; /* Not device name. */
		return (wn);
	}

	unc = 0;
	if (wnp[0] == L'\\' && wnp[1] == L'\\' && wnp[2] != L'\\')
	{
		wchar_t *p = &wnp[2];

		/* Skip server-name letters. */
		while (*p != L'\\' && *p != L'\0')
			++p;
		if (*p == L'\\')
		{
			wchar_t *rp = ++p;
			/* Skip share-name letters. */
			while (*p != L'\\' && *p != L'\0')
				++p;
			if (*p == L'\\' && p != rp)
			{
				/* Now, match patterns such as
				 * "\\server-name\share-name\" */
				wnp += 2;
				len -= 2;
				unc = 1;
			}
		}
	}

	slen = 4 + (unc * 4) + len + 1;
	ws = wsp = malloc(slen * sizeof(wchar_t));
	if (ws == NULL)
	{
		//free(wn);
		return (NULL);
	}
	/* prepend "\\?\" */
	wcsncpy(wsp, L"\\\\?\\", 4);
	wsp += 4;
	slen -= 4;
	if (unc)
	{
		/* append "UNC\" ---> "\\?\UNC\" */
		wcsncpy(wsp, L"UNC\\", 4);
		wsp += 4;
		slen -= 4;
	}
	wcsncpy(wsp, wnp, slen);
	wsp[slen - 1] = L'\0'; /* Ensure null termination. */
	//free(wn);

	wcscpy(wnp, ws);

	free(ws);

	return (wnp);
}

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we 
 *  . provide two functions that are exactly the same because someone may 
 * use it in multi-thread code 
 *
 * @param pUTF8 the input utf-8 encoded filename 
 *
 * @return the static allocated WCHAR array with the filename as wide string 
 *
 */
WCHAR *amanda_utf8towide_1_v27(char *pUTF8)
{
	static WCHAR ricardo_k[AMANDA__SIZE_w + 1];
	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, AMANDA__SIZE_w);
	return permissive_name_m_(ricardo_k);
}

static __int64 getfilesize_aakp_plus_rspk(char *infile_utf8_valquiria)
{

	__int64 ret;

	FILE *myfile;

	if ((myfile = _wfopen(amanda_utf8towide_1_v27(infile_utf8_valquiria), L"rb")) == NULL)
	{
		//dprintf ("The file 'data' was not opened\n");
		return 0;
	}
	else
	{
		//dprintf ("The file 'data' was opened\n");
	}

	ret = _fseeki64(myfile, 0, SEEK_END);

	ret = _ftelli64(myfile);

	// dprintf ("tamanho do arquivo %d\n ", ret);

	fclose(myfile);

	// printf ("Tamanho do arquivo %s  %d \n", infile, ret);

	return ret;
}

int lgetpor(__int64 max_Amanda, __int64 fatia_Ricardo)
{
	/*

   2/27/2004 12:13PM modificacao para evitar divisao por 0, eu te amo...

 */

	double maxa;
	double fatiaa;

	maxa = (double)max_Amanda;
	fatiaa = (double)fatia_Ricardo;

	if (max_Amanda == 0 || fatia_Ricardo == 0)
	{
		return 0;
	}

	maxa = ((double)10000 / maxa * fatiaa);

	return (int)maxa;
}