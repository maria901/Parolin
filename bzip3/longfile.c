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

#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#undef NDEBUG
#include <assert.h>

extern void __cdecl dprintf(char *format, ...);
extern int unicodemode;

#define AMANDA__SIZE_ww ((32767 * 2) + 2)

WCHAR *amanda_utf8towide_1_v28(char *pUTF8, WCHAR *ar_temp);

wchar_t *
permissive_name_m_v28(const wchar_t *wname, WCHAR *ar_temp);

HANDLE lfopen(const char *szFileName, char *pMode);
void lfclose(HANDLE hFile);
__int64 lfseek(HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell(HANDLE hFile);
__int64 lffilesize(const char *szFileName);
unsigned long lfread(void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite(void *pBuffer, unsigned long ulCount, HANDLE hFile);
int setendofile(HANDLE file, __int64 position);

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
WCHAR *amanda_utf8towide_1_v27_no_october_2021(const char *pUTF8);

HANDLE lfopen(const char *szFileName, char *pMode)
{

      HANDLE ret = 0;

      if (0 == strcmp(pMode, "rb+"))
      {
#ifdef NPRINTF
            dprintf("Usando rb+\n");
#endif

            if (unicodemode)
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ret = CreateFileW(permissive_name_m_v28(amanda_utf8towide_1_v28((void *)szFileName, ar_temp), ar_temp2), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

                  free(ar_temp);
                  free(ar_temp2);
            }
            else
            {

                  ret = CreateFile(szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
            }
            goto saida;
      }

      switch (pMode[0])
      {
      case 'r':

#ifdef NPRINTF
            dprintf("opening read file %s \n", szFileName);
#endif
            if (unicodemode)
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ret = CreateFileW(permissive_name_m_v28(amanda_utf8towide_1_v28((void *)szFileName, ar_temp), ar_temp2), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

                  free(ar_temp);
                  free(ar_temp2);
            }
            else
            {
                  ret = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
            }
            break;
      case 'w':
#ifdef NPRINTF
            dprintf("opening write file %s \n", szFileName);
#endif
            if (unicodemode)
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ret = CreateFileW(permissive_name_m_v28(amanda_utf8towide_1_v28((void *)szFileName, ar_temp), ar_temp2), GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);

                  free(ar_temp);
                  free(ar_temp2);
            }
            else
            {
                  ret = CreateFile(szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
            }
            break;
      case 'z':
#ifdef NPRINTF
            dprintf("opening write file %s \n", szFileName);
#endif
            if (unicodemode)
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ret = CreateFileW(permissive_name_m_v28(amanda_utf8towide_1_v28((void *)szFileName, ar_temp), ar_temp2), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

                  free(ar_temp);
                  free(ar_temp2);
            }
            else
            {
                  ret = CreateFile(szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
            }
            break;
      case 'a': //not tested, as far as I know it will not start from the end of the file as you can see below
            if (unicodemode)
            {
                  WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                  WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                  ret = CreateFileW(permissive_name_m_v28(amanda_utf8towide_1_v28((void *)szFileName, ar_temp), ar_temp2), GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

                  free(ar_temp);
                  free(ar_temp2);
            }
            else
            {
                  ret = CreateFile(szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
            }
            break;

      default:
            assert(0);
            break;
      }

saida:;

      if (INVALID_HANDLE_VALUE == ret)
      {
            ret = 0;
      }
      return ret;
}

void lfclose(HANDLE hFile)
{
      assert(CloseHandle(hFile));
}

__int64 lfseek(HANDLE hFile, __int64 iDistance, int iMode)
{
      LARGE_INTEGER li;
      int isft = -1;
      li.QuadPart = iDistance;
      li.LowPart = SetFilePointer(hFile, li.LowPart, &li.HighPart, iMode);
      if ((int)li.LowPart == (int)isft && GetLastError() != ERROR_SUCCESS)
            return -1;
      return (__int64)li.QuadPart;
}

__int64 lftell(HANDLE hFile)
{
      LARGE_INTEGER li;
      int isft = -1;
      li.QuadPart = 0;
      li.LowPart = SetFilePointer(hFile, 0, &li.HighPart, FILE_CURRENT);

      if ((int)li.LowPart == (int)isft && GetLastError() != ERROR_SUCCESS)
            return -1;

      return (__int64)li.QuadPart;
}

static __int64 fs_filesize(HANDLE hFile)
{
      LARGE_INTEGER li;

      li.QuadPart = 0;
      li.LowPart = GetFileSize(hFile, (LPDWORD)&li.HighPart);

      if (li.LowPart == 0xFFFFFFFF)
      {
            if (GetLastError() != ERROR_SUCCESS)
                  return 0;
      }

      return (__int64)li.QuadPart;
}

__int64 lffilesize(const char *szFileName)
{
      __int64 iResult;
      HANDLE hFile;

      if (unicodemode)
      {
#ifdef NPRINTF
            dprintf("arquivo %s\n", szFileName);
#endif
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            hFile = CreateFileW(permissive_name_m_v28(amanda_utf8towide_1_v28((void *)szFileName, ar_temp), ar_temp2), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

            free(ar_temp);
            free(ar_temp2);
      }
      else
      {
            hFile = CreateFile(szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
      }
      if (hFile == INVALID_HANDLE_VALUE)
            return 0;

      iResult = fs_filesize(hFile);
      CloseHandle(hFile);
      return iResult;
}

__int64 lffilesizeW(const WCHAR *szFileName)
{
      __int64 iResult;
      HANDLE hFile = CreateFileW(szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
      if (hFile == INVALID_HANDLE_VALUE)
            return 0;
      iResult = fs_filesize(hFile);
      CloseHandle(hFile);
      return iResult;
}
unsigned long lfread(void *pBuffer, unsigned long ulCount, HANDLE hFile)
{
      unsigned long ulRead;
      if (ReadFile(hFile, pBuffer, ulCount, &ulRead, NULL) == FALSE)
            return 0;
      else
            return ulRead;
}

unsigned long lfwrite(void *pBuffer, unsigned long ulCount, HANDLE hFile)
{
      unsigned long ulWritten;

      if (WriteFile(hFile, pBuffer, ulCount, &ulWritten, NULL) == FALSE)
            return 0;
      else
            return ulWritten;
}

int setendofile(HANDLE file, __int64 position)
{

      int ret;
      __int64 ret2;
      ret2 = lfseek(file, position, FILE_BEGIN);
      if (-1 == ret2)
      {
            return 0;
      }

      ret = SetEndOfFile(file);

      if (0 == ret)
      {
            return 0;
      }

      return 1;
}

/*
   by alladin
   C:\aoprojetoc\cdrtools\longfile.c
   11:58-quinta-feira, 1 de novembro de 2007
 */
