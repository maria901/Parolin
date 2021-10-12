/********************************************************************************
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 ********************************************************************************
 
      E-mails:                                                                 
      maria@arsoftware.net.br                                                  
      pedro@locacaodiaria.com.br                                               

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 *******************************************************************************/

#define AMANDA__SIZE_ww ((32767 * 2) + 2)

char *valquiria_wide_to_utf8(WCHAR *pUSC2_maria, char *ar_temp_char);
wchar_t *
permissive_name_m_v28(const wchar_t *wname, WCHAR *ar_temp);
wchar_t *
remove_permissive_name_m_(wchar_t *wname, WCHAR *ar_temp);
WCHAR *amanda_utf8towide_1_v28(char *pUTF8, WCHAR *ar_temp);

void pedro_dprintf(
    int amanda_level,
    char *format, ...);

int intpause___aakp = 0;
int intcancel__rspk = 0;

__int64 tamanho____aakp = 0;
__int64 processado_rspk = 0;
int return_value_arp;

int porcentagem_junior_ale_mislaine_thalia_aline_juliete_valquiria_maria_feline_pedro;

static WCHAR *__stdcall utf8towide(const char *pUTF8)
{
     /* nUSC2 is the number of characters, not chars */

     static int position = 0;
     if (0 == position)
     {
          static WCHAR pUSC2[1024];
          MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, pUSC2, 1024);
          position = 1;
          return pUSC2;
     }
     else
     {
          static WCHAR pUSC2[1024];
          MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, pUSC2, 1024);
          position = 0;
          return pUSC2;
     }
     return NULL;
}

__int64 getfilesize_aakp_plus_rspk(char *infile_utf8_valquiria)
{

     __int64 ret;

     FILE *myfile;
     WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
     WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
     if ((myfile = _wfopen(permissive_name_m_v28(amanda_utf8towide_1_v28(infile_utf8_valquiria, ar_temp), ar_temp2), L"rb")) == NULL)
     {
          //dprintf ("The file 'data' was not opened\n");

          free(ar_temp);
          free(ar_temp2);
          return 0;
     }
     else
     {
          //dprintf ("The file 'data' was opened\n");
     }

     free(ar_temp);
     free(ar_temp2);
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