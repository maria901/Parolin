
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
 *     E-mails:                                                                 *
 *     maria@arsoftware.net.br                                                  *
 *     pedro@locacaodiaria.com.br                                               *
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

/* 
 modified 2021 May
*/

/*  ainda falta alguns testes , vamos la   */

#include <windows.h>
#include <winioctl.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// #define NDEBUG

#undef NDEBUG
#include <assert.h>

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

extern void __cdecl dprintf(char *format, ...);

extern int unicodemode; //if 1 the file is an utf-8 encoded Unicode string, if 0 it is a ansi string

HANDLE lfopen(const char *szFileName, char *pMode);
void lfclose(HANDLE hFile);
__int64 lfseek(HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell(HANDLE hFile);
__int64 lffilesize(const char *szFileName);
unsigned long lfread(void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite(void *pBuffer, unsigned long ulCount, HANDLE hFile);

int utf8towide(const char *pUTF8, WCHAR *pUSC2, int nUSC2)
{
        return MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, pUSC2, nUSC2);
}

int widetoutf8(WCHAR *pUSC2, char *pUTF8, int nUTF8)
{
        return WideCharToMultiByte(CP_UTF8, 0, pUSC2, -1, (LPSTR)pUTF8, nUTF8, 0, 0);
}

/*

//for historical reasons...
HANDLE lfopen (const char *szFileName, char *pMode)
{


     HANDLE ret = 0;

     if (0 == strcmp (pMode, "rb+"))
       {
#ifdef NPRINTF
	    dprintf ("Usando rb+\n");
#endif


	    if (unicodemode)
	      {
		   utf8towide (szFileName, wpmode, 600);
		   ret = CreateFileW (wpmode, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	      }
	    else
	      {

		   ret = CreateFile (szFileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    goto saida;
       }

     switch (pMode[0])
       {
       case 'r':

#ifdef NPRINTF
	    dprintf ("opening read file %s \n", szFileName);
#endif
	    if (unicodemode)
	      {
		   utf8towide (szFileName, wpmode, 600);
		   ret = CreateFileW (wpmode, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);

	      }
	    else
	      {
		   ret = CreateFile (szFileName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    break;
       case 'w':
#ifdef NPRINTF
	    dprintf ("opening write file %s \n", szFileName);
#endif
	    if (unicodemode)
	      {
		   utf8towide (szFileName, wpmode, 600);
		   ret = CreateFileW (wpmode, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    else
	      {
		   ret = CreateFile (szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    break;
       case 'a'://not tested, as far as I know it will not start from the end of the file as you can see below
	    if (unicodemode)
	      {
		   utf8towide (szFileName, wpmode, 600);
		   ret = CreateFileW (wpmode, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    else
	      {
		   ret = CreateFile (szFileName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
	      }
	    break;

       default:
	    break;

       }

   saida:			//hack

     if (INVALID_HANDLE_VALUE == ret)
       {

	    ret = 0;
       }
     return ret;
}

*/
/*

void lfclose (HANDLE hFile)
{
//hummmmmmmm
     assert (CloseHandle (hFile));
}

*/

/*
__int64 lfseek (HANDLE hFile, __int64 iDistance, int iMode)
{
     LARGE_INTEGER li;

     int    isft = -1;


     li.QuadPart = iDistance;


     //tested modes FILE_END    FILE_CURRENT    FILE_BEGIN
     li.LowPart = SetFilePointer (hFile, li.LowPart, &li.HighPart, iMode);

     if (li.LowPart == isft && GetLastError () != ERROR_SUCCESS)
	  return -1;

     return (__int64) li.QuadPart;
}
*/
/*
__int64 lftell (HANDLE hFile)
{
     LARGE_INTEGER li;
     int    isft = -1;
     li.QuadPart = 0;
     li.LowPart = SetFilePointer (hFile, 0, &li.HighPart, FILE_CURRENT);

     if (li.LowPart == isft && GetLastError () != ERROR_SUCCESS)
	  return -1;

     return (__int64) li.QuadPart;
}
*/

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

__int64 lffilesize(const char *szFileName) //is utf-8
{
        __int64 iResult;
        HANDLE hFile;

        if (unicodemode)
        {

#ifdef NPRINTF
                dprintf("arquivo %s\n", szFileName);
#endif

                hFile = CreateFileW(amanda_utf8towide_1_v27((void *)szFileName), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
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
        HANDLE hFile = CreateFileW(permissive_name_m_(szFileName), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, NULL);
        if (hFile == INVALID_HANDLE_VALUE)
                return 0;

        iResult = fs_filesize(hFile);

        CloseHandle(hFile);

        return iResult;
}
/*

unsigned long lfread (void *pBuffer, unsigned long ulCount, HANDLE hFile)
{
     unsigned long ulRead;

     if (ReadFile (hFile, pBuffer, ulCount, &ulRead, NULL) == FALSE)
	  return 0;
     else
	  return ulRead;
}


unsigned long lfwrite (void *pBuffer, unsigned long ulCount, HANDLE hFile)
{
     unsigned long ulWritten;

     if (WriteFile (hFile, pBuffer, ulCount, &ulWritten, NULL) == FALSE)
	  return 0;
     else
	  return ulWritten;
}

*/
