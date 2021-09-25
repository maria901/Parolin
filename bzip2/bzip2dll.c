
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
    <main dll interface>
    Copyright (C) BW
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

#include "bzlib.h"

#include "aline_definitive_header_2_.h"

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

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

#ifdef _WIN64
#define __INT32_OR_INT64 __int64
#else
#define __INT32_OR_INT64 int
#endif

int utf8towide(const char *pUTF8, WCHAR *pUSC2, int nUSC2);
int __stdcall IsAMD64(void);

void removedordeespaconoinicio(char *path);
void removedordeespaconofinal(char *path);
char *getcpuname_k(void);
char *getprocessorbrandstring_k(void);
char myinfile[255];
char myoutfile[255];
int comando;
char mylevel[255];
char library[255];
int intpause;
int intcancel;

int64_t filesize;
int64_t intfatia;
int intstatus;
int intreturn;

int modo = 0;
int levelok = 6;

extern int bzip3percent;

int unicodemode = 0;

void dprintf(char *format, ...);

/**
 * wide path aware my love...
 * 
 */
__int64
getfilesize_ar(char *infile_ar)
{
      __int64 ret_z;
      FILE *myfile; // = NULL;
      {
            if ((myfile = _wfopen(amanda_utf8towide_1_v27(infile_ar), L"rb")) == NULL)
            {
                  return 0;
            }
      }
      ret_z = _fseeki64(myfile, 0, SEEK_END);
      ret_z = _ftelli64(myfile);
      fclose(myfile);
      return ret_z;
}

/**
 * Julian old compression function 
 * 
 * 
 */
int __stdcall bzip2compress(char *infile, char *outfile, char *levelch)
{
      char *fn_r = NULL;
      char *fn_w = NULL;

      int len;
      char buff[0x10001];

      int returnvalue = 0;
      BZFILE *BZ2fp_w = NULL;
      FILE *fp_r = NULL;
      int ret;
      int berr = 0;

      fn_r = infile;
      fn_w = outfile;

      intpause = 0;
      intcancel = 0;
      intstatus = 1;

      unicodemode = 1;

      ret = SetFileAttributesW(amanda_utf8towide_1_v27(outfile), FILE_ATTRIBUTE_ARCHIVE);

      filesize = getfilesize_ar(infile);

      {
            if (fn_r)
            {
                  if ((fp_r = _wfopen(amanda_utf8towide_1_v27(fn_r), L"rb")) == NULL)
                  {
                        intstatus = 0;
                        return (8);
                  }
            }
      }
      intfatia = 0;

      pedro_dprintf(-1, "Level %s\n", levelch);
      
      if ((fn_w != NULL && (BZ2fp_w = BZ2_bzopen(fn_w, levelch)) == NULL))
      {
            fclose(fp_r);
            intstatus = 0;
            return (9);
      }

      berr = 0;
      BZ2_bzerror(BZ2fp_w, &berr);

      if (0 != berr)
      {

            returnvalue = 11;
            goto saida;
      }

      while ((len = fread(buff, 1, 0x10000, fp_r)) > 0)
      {

            while (intpause)
            {

                  if (intcancel)
                  {
                        intfatia = filesize;

                        break;
                  }

                  Sleep(50);
            }

            if (intcancel)
            {
                  intfatia = filesize;

                  break;
            }

            intfatia = intfatia + len;

            ret = BZ2_bzwrite(BZ2fp_w, buff, len);

            if (-1 == ret)
            {
                  returnvalue = 10;
                  break;
            }

            berr = 0;
            BZ2_bzerror(BZ2fp_w, &berr);

            if (0 != berr)
            {

                  returnvalue = 11;
                  goto saida;
            }
      }

saida:

      if (BZ2fp_w)
      {
            BZ2_bzclose(BZ2fp_w);
      }

      if (fp_r)
      {
            fclose(fp_r);
      }

      if ((0 == returnvalue) && intcancel)
      {

            returnvalue = 119;

            unlink(outfile);
      }

      intstatus = 0;

      return returnvalue;
}

int __stdcall bzip2decompress(char *infile, char *outfile)
{

      int executed = 0;

      char *fn_r = NULL;
      char *fn_w = NULL;

      int len;
      char buff[0x10001];
      int berr = 0;

      BZFILE *BZ2fp_r = NULL;
      FILE *fp_w = NULL;
      int returnvalue = 0;

      FILE *myfile = NULL;
      unicodemode = 1;
      intpause = 0;
      intcancel = 0;

      intstatus = 1;

      fn_w = outfile;
      fn_r = infile;
      {
            SetFileAttributesW(amanda_utf8towide_1_v27(outfile), FILE_ATTRIBUTE_ARCHIVE);
      }
      {
            if ((myfile = _wfopen(amanda_utf8towide_1_v27(infile), L"rb")) == NULL)
            {
                  intstatus = 0;
                  return 8;
            }
      }

      {
            char temp[300];
            fread(temp, 1, 4, myfile);
            if (0 != memcmp(temp, "BZh", 3))
            {
                  fclose(myfile);
                  myfile = NULL;
                  returnvalue = 14;
                  goto saida;
            }
      }

      filesize = getfilesize_ar(infile);
      intfatia = 0;
      if (fn_w)
      {
            {
                  if ((fp_w = _wfopen(amanda_utf8towide_1_v27(fn_w), L"wb")) == NULL)
                  {
                        intstatus = 0;
                        return (9);
                  }
            }
      }

      if ((fn_r != NULL && (BZ2fp_r = BZ2_bzopen(fn_r, "rb")) == NULL))
      {
            fclose(fp_w);
            intstatus = 0;
            return (8);
      }
      berr = 0;
      BZ2_bzerror(BZ2fp_r, &berr);
      if (0 != berr)
      {
            returnvalue = 12;
            goto saida;
      }
      while ((len = BZ2_bzread(BZ2fp_r, buff, 0x10000)) > 0)
      {
            executed = 1;
            berr = 0;
            BZ2_bzerror(BZ2fp_r, &berr);
            if (0 != berr)
            {
                  returnvalue = 12;
                  goto saida;
            }
            intfatia = intfatia + len;
            while (intpause)
            {

                  if (intcancel)
                  {
                        intfatia = filesize;
                        break;
                  }

                  Sleep(50);
            }

            if (intcancel)
            {
                  intfatia = filesize;
                  break;
            }

            fwrite(buff, 1, len, fp_w);
      }

      if (-1 == len)
      {
            returnvalue = 15;
      }

saida:;
      if (myfile)
      {
            fclose(myfile);
      }

      if (BZ2fp_r)
      {
            BZ2_bzclose(BZ2fp_r);
      }

      if (fp_w)
      {
            fclose(fp_w);
      }

      if ((0 == returnvalue) && (filesize > 100) && (0 == executed))
      {
            returnvalue = 13;
      }

      if ((0 == returnvalue) && intcancel)
      {
            returnvalue = 119;
      }

      intstatus = 0;
      return returnvalue;
}

int __stdcall pause(void)
{
      intpause = 1;
      return 0;
}

int __stdcall cancel(void)
{
      intcancel = 1;
      return 0;
}
int __stdcall bresume(void)
{
      intpause = 0;
      return 0;
}

int __stdcall startapi(__attribute__((unused)) int parameter)
{
      if (comando == 0)
      {
            intreturn = 0;
            intreturn = bzip2compress(myinfile, myoutfile, mylevel);
      }
      if (1 == comando)
      {
            intreturn = 0;
            intreturn = bzip2decompress(myinfile, myoutfile);
      }
      if (2 == comando)
      {
            intreturn = 0;
            intreturn = 0; //bzip3compress (myinfile, myoutfile, levelok);
      }
      if (3 == comando)
      {
            intreturn = 0;
            intreturn = 0; //bzip3uncompress (myinfile, myoutfile);
      }
      if (4 == comando)
      {
            intreturn = 0;
            intreturn = 0; //bzip3compress_sha512_k (myinfile, myoutfile, levelok);
      }
      return 0;
}

BOOL WINAPI DllMain(__attribute__((unused)) HINSTANCE hModule,
                    __attribute__((unused)) DWORD ul_reason_for_call,
                    __attribute__((unused)) LPVOID lpReserved)
{
      switch (ul_reason_for_call)
      {
      case DLL_PROCESS_ATTACH:
            OutputDebugString("Bzip3 DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") \n");

#ifdef NPRINTF
            MessageBox(0, "Alladin debugging code", "BinaryWork Corp.", MB_OK | MB_TOPMOST);
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

int __stdcall execute(char *infile, char *outfile, char *level, int comando1)
{
      HANDLE myhandle;
      __INT32_OR_INT64 ThreadId;
      __INT32_OR_INT64 parameter = 1;
      strcpy(myinfile, infile);
      strcpy(myoutfile, outfile);
      strcpy(mylevel, level);
      comando = comando1;
      myhandle = CreateThread((LPSECURITY_ATTRIBUTES)0, (DWORD)0, (void *)startapi, (LPVOID)parameter, (DWORD)0, (LPDWORD)&ThreadId);
      CloseHandle(myhandle);
      return 2;
}
static int getpor(int64_t max, int64_t fatia)
{
      double a;
      a = (double)max;
      if (max == 0)
      {
            return 0;
      }
      a = ((double)100 / max) * fatia;
      return (int)a;
}
int __stdcall getprogress()
{
      int ret = 0;
      if (1 == modo)
      {
            //ret = bzip3percent;
      }
      else
      {
            ret = getpor(filesize, intfatia);
      }

      if (ret > 100)
      {
            ret = 100;
      }
      if (ret < 0)
      {
            ret = 0;
      }
      if (intstatus == 1)
      {

            if (ret > 98)
            {
                  ret = 99;
            }
      }

      return ret;
}

int __stdcall status(int newvalue)
{
      if (newvalue == 1)
      {
            intstatus = 1;
            return 1;
      }
      return intstatus;
}

int __stdcall interface1(__INT32_OR_INT64 argumento1, __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3, __INT32_OR_INT64 argumento4)
{
      static char inputfile[AMANDA__SIZE];
      static char outputfile[AMANDA__SIZE];
      if (!strcmp((char *)argumento1, "compress"))
      {
            modo = 0;
            strcpy(inputfile, (char *)argumento2);
            strcpy(outputfile, (char *)argumento3);
            execute(inputfile, outputfile, (char *)argumento4, 0); //0 compress 1 decompress
            return 1;
      }
      if (!strcmp((char *)argumento1, "compressbzip3"))
      {
            modo = 1;
            strcpy(inputfile, (char *)argumento2);
            strcpy(outputfile, (char *)argumento3);
            execute(inputfile, outputfile, (char *)argumento4, 2); //0 compress 1 decompress
            return 1;
      }

      if (!strcmp((char *)argumento1, "compressbzip3_sha512_k"))
      {
            modo = 1;
            strcpy(inputfile, (char *)argumento2);
            strcpy(outputfile, (char *)argumento3);
            execute(inputfile, outputfile, (char *)argumento4, 4); //0 compress 1 decompress
            return 1;
      }

      if (!strcmp((char *)argumento1, "decompress"))
      {
            modo = 0;
            strcpy(inputfile, (char *)argumento2);
            strcpy(outputfile, (char *)argumento3);
            execute(inputfile, outputfile, (char *)argumento4, 1); //0 compress 1 decompress
            return 1;
      }
      if (!strcmp((char *)argumento1, "decompressbzip3"))
      {
            modo = 1;
            strcpy(inputfile, (char *)argumento2);
            strcpy(outputfile, (char *)argumento3);
            execute(inputfile, outputfile, (char *)argumento4, 3); //0 compress 1 decompress
            return 1;
      }

      if (!strcmp((char *)argumento1, "status"))
      {
            return (status(argumento2));
      }

      if (!strcmp((char *)argumento1, "getprogress"))
      {
            return (getprogress());
      }
      if (!strcmp((char *)argumento1, "bresume"))
      {
            return (bresume());
      }
      if (!strcmp((char *)argumento1, "pause"))
      {
            return (pause());
      }
      if (!strcmp((char *)argumento1, "cancel"))
      {
            while (intstatus)
            {
#ifdef NPRINTF
                  dprintf(" loopenado no cancel\n");
#endif
                  cancel();
                  Sleep(50);
            };
            return (cancel());
      }
      if (!strcmp((char *)argumento1, "selectlibrary"))
      {
            strcpy(library, (char *)argumento2);
            return (3);
      }

      if (!strcmp((char *)argumento1, "thestatus"))
      {
            return intstatus;
      }

      if (!strcmp((char *)argumento1, "intreturn"))
      {
            return (intreturn);
      }

      if (!strcmp((char *)argumento1, "setlevel"))
      {
            levelok = argumento2;
#ifdef NPRINTF
            dprintf("compression level %d \n", levelok);
#endif
            return 0;
      }

      if (!strcmp((char *)argumento1, "getcpuname"))
      {
            strcpy((char *)argumento2, getcpuname_k());
            return (0);
      }
      if (!strcmp((char *)argumento1, "getbrandstring"))
      {
            strcpy((char *)argumento2, getprocessorbrandstring_k());
            return (0);
      }
      return 15;
}

double _time;
int __stdcall ControlName(char *data)
{
      strcpy(data, "BW Bzip2 DLL " AMARIC__VERSION
#ifdef _WIN64
                   " 64 bits"
#else
                   " 32 bits"
#endif
      );
      return 0;
}
int __stdcall GetCPUVendor(char *data)
{
      interface1((__INT32_OR_INT64) "getcpuname", (__INT32_OR_INT64)data, 0, 0);
      return 0;
}

int __stdcall GetCPUBrandString(char *data)
{
      interface1((__INT32_OR_INT64) "getbrandstring", (__INT32_OR_INT64)data, 0, 0);
      return 0;
}

void mprintf2(char *format, ...)
{
      int val;
      va_list args;
      static char buffer[50000];
      va_start(args, format);
      vsprintf(buffer, format, args);
      val = MessageBox(0, buffer, "BW", MB_OK | MB_TOPMOST);
      if (val != IDOK)
      {
            ;
      }
}

int __stdcall About()
{
      mprintf2("Win32 and Win64 DLL to compress files using bzip2 or bzip3 compression methods");
      return 0;
}

int __stdcall Compress(char *Inputfile, char *OutPutFile, int CompressionLevel)
{
      char level[300];
      int ret;
      unicodemode = 0;
      ret = interface1((__INT32_OR_INT64) "status", 0, 0, 0);
      if (1 == ret)
      {
            return 7;
      }

      _time = (double)GetTickCount();

      if ((CompressionLevel > 9) || (CompressionLevel < 0))
      {
            return 1;
      }
      intreturn = 0;
      sprintf(level, "w%d", CompressionLevel);

      ret = interface1((__INT32_OR_INT64) "status", 1, 0, 0);

      ret = interface1((__INT32_OR_INT64) "compress", (__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64)level);

      return 0;
}

int __stdcall GetStatus() //retorna 1 se estiver executando
{
      return interface1((__INT32_OR_INT64) "status", 0, 0, 0);
}

int __stdcall GetReturnValue()
{
      return interface1((__INT32_OR_INT64) "intreturn", 0, 0, 0);
}
/**
* pegor o valor da porcentagem
*
*/
double
dgetval(double maxa, double porr)
{
      maxa = (maxa / 100) * porr;
      return maxa;
}

/**
* pegar o maximo a partir da porcentagem
*/
double
dgetmax(double por, double fatia)
{
      double a;
      double b;
      a = (double)por;
      b = (double)fatia;
      if (por == 0.0)
      {
            return 0.0;
      }
      a = (b / a) * (float)100.0;
      return (double)a;
}

double dgetpor(double maxa, double fatiaa)
{

      if (maxa == 0)
      {
            return 0;
      }

      maxa = ((double)100.0 / maxa * fatiaa);

      return (double)maxa;
}

int secondtostring(double value, char *data)
{
      //[closed]
      unsigned int frame;
      unsigned int ret;
      unsigned int seg;
      unsigned int min;
      unsigned int hour;
      ret = (unsigned int)value;
      frame = ret % 1000;
      ret = ret / 1000;
      seg = ret % 60;
      ret = ret / 60; // minutos
      min = ret % 60;
      ret = ret / 60; // horas
      hour = ret % 100;
      sprintf(data, "%02d:%02d:%02d:%03d", hour, min, seg, frame);
      return 0;
}

int __stdcall GetProgress();
int __stdcall GetTimeToFinish(char *data)
{
      void dprintf3(char *format, ...);
      double dret;
      double dporcentagem;

      double desloca = (double)GetTickCount();

      dporcentagem = (double)GetProgress();

      dret = dgetmax(dporcentagem, desloca - _time);
#ifdef NPRINTF
      dprintf("valor %f\n", dret);
#endif
      dret = dret - (desloca - _time);

      secondtostring(dret, data);
#ifdef NPRINTF
      dprintf("valor2 %s\n", data);
#endif
      return 0;
}

int __stdcall GetProgress()
{
      return interface1((__INT32_OR_INT64) "getprogress", 0, 0, 0);
}

int __stdcall CompressBzip3(char *Inputfile, char *OutPutFile, int CompressionLevel)
{
      char level[300];
      int ret;
      unicodemode = 1;
      ret = interface1((__INT32_OR_INT64) "status", 0, 0, 0);

      if (1 == ret)
      {

            return 7;
      }

      _time = (double)GetTickCount();

      if ((CompressionLevel > 9) || (CompressionLevel < 0))
      {
            return 1;
      }

      sprintf(level, "w%d", CompressionLevel);

      interface1((__INT32_OR_INT64) "setlevel", CompressionLevel, CompressionLevel, CompressionLevel);

      ret = interface1((__INT32_OR_INT64) "status", 1, 0, 0);

      ret = interface1((__INT32_OR_INT64) "compressbzip3", (__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64)level);

      return 0;
}

int __stdcall CompressBzip3_SHA512_k(char *Inputfile, char *OutPutFile, int CompressionLevel)
{
      char level[300];
      int ret;
      unicodemode = 1;
      ret = interface1((__INT32_OR_INT64) "status", 0, 0, 0);

      if (1 == ret)
      {

            return 7;
      }

      _time = (double)GetTickCount();

      if ((CompressionLevel > 9) || (CompressionLevel < 0))
      {
            return 1;
      }

      sprintf(level, "w%d", CompressionLevel);

      interface1((__INT32_OR_INT64) "setlevel", CompressionLevel, CompressionLevel, CompressionLevel);

      ret = interface1((__INT32_OR_INT64) "status", 1, 0, 0);

      ret = interface1((__INT32_OR_INT64) "compressbzip3_sha512_k", (__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64)level);

      return 0;
}

int __stdcall PauseCompress()
{
      return interface1((__INT32_OR_INT64) "pause", 0, 0, 0);
}

int __stdcall ResumeCompress()
{
      return interface1((__INT32_OR_INT64) "bresume", 0, 0, 0);
}

int __stdcall CancelCompress()
{
      return interface1((__INT32_OR_INT64) "cancel", 0, 0, 0);
}

int __stdcall Decompress(char *Inputfile, char *OutPutFile)
{
      int ret;
      unicodemode = 0;
      ret = interface1((__INT32_OR_INT64) "status", 0, 0, 0);

      if (1 == ret)
      {

            return 7;
      }
      _time = (double)GetTickCount();
      intreturn = 0;
      ret = interface1((__INT32_OR_INT64) "status", 1, 0, 0);
      ret = interface1((__INT32_OR_INT64) "decompress", (__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64) "w9");
      return 0;
}

int __stdcall DecompressBzip3(char *Inputfile, char *OutPutFile)
{
      int ret;
      unicodemode = 1;
      ret = interface1((__INT32_OR_INT64) "status", 0, 0, 0);

      if (1 == ret)
      {
            return 7;
      }
      _time = (double)GetTickCount();
      ret = interface1((__INT32_OR_INT64) "status", 1, 0, 0);
      ret = interface1((__INT32_OR_INT64) "decompressbzip3", (__INT32_OR_INT64)Inputfile, (__INT32_OR_INT64)OutPutFile, (__INT32_OR_INT64) "w9");
      return 0;
}

int __stdcall stringtobyte(unsigned char *dest, unsigned char *src, int len)
{
      int i;
      for (i = 0; i < len; i++)
      {
            dest[i] = src[i];
      }
      return 0;
}
int __stdcall bytetostring(unsigned char *dest, unsigned char *src, int len)
{
      int i;
      for (i = 0; i < len; i++)
      {
            dest[i] = src[i];
      }
      dest[i] = 0;
      return 0;
}