
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
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

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

#   define AMANDA_TAMANHO     0x100000

#ifdef _WIN64
#define __INT32_OR_INT64 __int64
#else
#define __INT32_OR_INT64 int
#endif

#include "rc4.h"
int unicodemode = 0;

int __stdcall init_serpent(char      *key_arp_);

int __stdcall encryptstring_serpent  (unsigned char * buf, unsigned char * bufout, unsigned char * key_arp, unsigned int size);

int __stdcall init_mars_arp   (char     *key_arp_);
int __stdcall encryptstring_mars_arp    (unsigned char * buf, unsigned char * bufout, unsigned char * key_arp, unsigned int size);

int __stdcall init_rc6__arp   (char     *key_arp_);
int __stdcall encryptstring_rc6_arp     (unsigned char * buf, unsigned char * bufout, unsigned char * key_arp, unsigned int size);

int __stdcall init_twofish_arp(char     *key_arp_);
int __stdcall encryptstring_twofish_arp (unsigned char * buf, unsigned char * bufout, unsigned char * key_arp, unsigned int size);
int encryption_method_internal     = 0;
int encryption_method_internal_un  = 0;

enum encryption_mode_arp
{
	ARP_AES,
	ARP_RC4,
	ARP_SERPENT,
	ARP_MARS,
	ARP_RC6,
	ARP_TWOFISH
};

/**
 * sha512_digest_k need to be at least 65 bytes long
 *
 */
int
SHA512_filelong_k (unsigned char * inputfile_utf_8, unsigned char *sha512_digest_k);

int __stdcall newfileencrypt2_sha512 (unsigned int type, unsigned char * inputfile, unsigned char * outputfile, unsigned char * key);

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

HANDLE lfopen (const char *szFileName, char *pMode);
void   lfclose (HANDLE hFile);
__int64 lfseek (HANDLE hFile, __int64 iDistance, int iMode);
__int64 lftell (HANDLE hFile);
__int64 lffilesize (const char *szFileName);
unsigned long lfread (void *pBuffer, unsigned long ulCount, HANDLE hFile);
unsigned long lfwrite (void *pBuffer, unsigned long ulCount, HANDLE hFile);

extern
void
dprintf (char *format, ...);

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we
 * provide two functions that are exactly the same because someone may
 * use it in multi-thread code
 *
 * @param pUTF8 the input utf-8 encoded filename
 *
 * @return the static allocated WCHAR array with the filename as wide string
 *
 */
WCHAR * amanda_utf8towide_1_(char *pUTF8)
{
	static WCHAR ricardo_k[1024];

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, 1024);
	return ricardo_k;
}

int
adler32filelong (uchar * inputfile);

static uchar inputfile [310];
static uchar outputfile[310];
static uchar key[257];

static char * encryption_method__i;

int init_aes = 0;

int comando = 0;

int intreturn = 0;

int intstatus = 0;

int intpause = 0;

int intcancel = 0;

int intpriority = 0;

__int64 filesize = 0;

__int64 intfatia = 0;

int    getfilesize (char *infile);

uint   getpor (int max, uint fatia);

int __stdcall newfileencrypt (uint type, uchar * inputfile, uchar * outputfile, uchar * key);

int __stdcall newfileencrypt2 (uint type, uchar * inputfile, uchar * outputfile, uchar * key);

int __stdcall fileencrypt (uint type, uchar * inputfile, uchar * outputfile, uchar * key);

int __stdcall encryptstring2 (int *done, uchar * buf, uchar * key, uchar * bufout, uint size, uint keysize);

int __stdcall encryptstring (int *done, uchar * buf, uchar * key, uchar * bufout, uint size, uint keysize);
int __stdcall decryptstring (int *done, uchar * buf, uchar * key, uchar * bufout, uint size, uint keysize);

int __stdcall RC4encryptstring (uchar * buf, uchar * key, uchar * bufout, uint size, uint keysize);

int    hextodec (uint initsize, uchar * buf, uchar * bufout, uint * buflen);

int    dectohex (uchar * buf, uchar * bufout, uint inputlen);

uint   crc32 (uint crc, const uchar * buf, uint len);

int    aesencrypt (unsigned char *buf, unsigned char *bufout, unsigned char *key, int keysize, int *done);

int    aesdecrypt (unsigned char *buf, unsigned char *bufout, unsigned char *key, int keysize, int *done);

extern char *getcpuspeed ();
extern char *getprocessorbrandstring ();
extern char *getcpuname ();

int __stdcall DllMain (__attribute__((unused)) HANDLE hModule, DWORD ul_reason_for_call, __attribute__((unused)) LPVOID lpReserved)
{

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("Encrypt DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") \n");

#ifdef NPRINTF
//Beep (2000, 50);
		MessageBox (0, "bhond debugging code", "BW", MB_OK | MB_TOPMOST);
#endif

		break;
	case DLL_THREAD_ATTACH:
		OutputDebugString ("DLL_THREAD_ATTACH \n");
		break;
	case DLL_THREAD_DETACH:
		OutputDebugString ("DLL_THREAD_DETACH \n");
		break;
	case DLL_PROCESS_DETACH:
		OutputDebugString ("DLL_PROCESS_DETACH \n");
		break;
	}
	return TRUE;
}

int __stdcall RC4encryptstring (uchar * buf, uchar * key, uchar * bufout, uint size, __attribute__((unused)) uint keysize)
{

	//uchar lbuf[16];
	//uchar *pchar;
	//uchar *pchar2;
	//uint pointer;
	//uint i;
	uchar *tmpbuf;
	struct rc4_state s;

#ifdef NPRINTF
	dprintf ("Em RC4 Encrypt \n");
#endif
	tmpbuf = malloc (size + 1);

	memcpy (tmpbuf, buf, size);

	rc4_setup (&s, key, 256);
	rc4_crypt (&s, tmpbuf, size);

	memcpy (bufout, tmpbuf, size);

	free (tmpbuf);

	return 0;

}

int __stdcall startapi (__attribute__((unused)) int parameter)
{

#ifdef NPRINTF
	dprintf ("--> New mode <--- \n");
#endif

	if (comando == 1)
	{
		intreturn = 0;
		intreturn = fileencrypt (0, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 2)
	{
		intreturn = 0;
		intreturn = fileencrypt (2, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 3)
	{
		intreturn = 0;
		intreturn = fileencrypt (1, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 11)
	{
		intreturn = 0;
		intreturn = newfileencrypt (10, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 12)
	{
		intreturn = 0;
		intreturn = newfileencrypt (12, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 13)
	{

		intreturn = 0;
		intreturn = newfileencrypt (11, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 14)
	{

		intreturn = 0;
		intreturn = newfileencrypt (13, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 15)
	{


		intreturn = 0;
		intreturn = newfileencrypt2 (15, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 16)
	{

		intreturn = 0;
		intreturn = newfileencrypt2 (16, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 17)
	{

		intreturn = 0;
		intreturn = newfileencrypt2_sha512 (17, inputfile, outputfile, key);
		intstatus = 0;
	}

	if (comando == 18)
	{

		intreturn = 0;
		intreturn = newfileencrypt2_sha512 (18, inputfile, outputfile, key);
		intstatus = 0;
	}

	return 0;

}

int __stdcall execute ()
{
	HANDLE myhandle;
	__INT32_OR_INT64 ThreadId;
	__INT32_OR_INT64 parameter = 1;
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, (DWORD) 0, (void *) startapi, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);
	CloseHandle (myhandle);
	return 2;
}

int __stdcall fileencrypt (uint type, uchar * inputfile, uchar * outputfile, uchar * key)
{

	int done = 0;
	uchar buf[4097];
	uchar bufout[4097];
	HANDLE stream;
	HANDLE stream2;
	//uint ret;
	uint len;

	struct rc4_state s;

	struct rc4_state ss;

	if (intpriority)
	{

		int ret;
#ifdef NPRINTF
		dprintf ("Vai setar prioridade \n");
#endif


		switch (intpriority)
		{

		case 1:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_IDLE);
			break;
		case 2:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_LOWEST);
			break;
		case 3:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_BELOW_NORMAL);
			break;
		case 4:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_NORMAL);
			break;
		case 5:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_ABOVE_NORMAL);
			break;
		case 6:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_HIGHEST);
			break;
		case 7:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_TIME_CRITICAL);
			break;

		default:
			break;

		}

		if (!ret)
		{
#ifdef NPRINTF
			dprintf ("nao pode setar a prioridade \n");
#endif
		}
		else
		{
#ifdef NPRINTF
			dprintf ("pode setar a prioridade \n");
#endif
		}

	}
	else
	{
#ifdef NPRINTF
		dprintf ("nao Vai setar prioridade \n");
#endif
	}

	filesize = 0;

	if ((stream = lfopen ((char *) inputfile, "rb")) != NULL)
	{

	}
	else
	{
#ifdef NPRINTF
		dprintf ("error opening input file \n");
#endif
		return 1;
	}

	if ((stream2 = lfopen ((char *) outputfile, "wb")) != NULL)
	{

	}
	else
	{
		lfclose (stream);
#ifdef NPRINTF
		dprintf ("error opening output file \n");
#endif
		return 2;

	}

	filesize = lffilesize ((char *) inputfile);
	intfatia = 0;

	while (1)
	{

		len = lfread (buf, 4096, stream);

		intfatia = intfatia + len;

		if (len <= 0)
		{
			break;
		}

ret1:
		if (1 == intpause)
		{

			if (1 == intcancel)
			{
				break;
			}

			Sleep (50);
			goto ret1;

		}

		if (1 == intcancel)
		{
			break;
		}

		if (type == 2)
		{

			decryptstring (&done, buf, key, bufout, len, 0);
			lfwrite (bufout, len, stream2);

		}

		if (type == 0)
		{

			encryptstring (&done, buf, key, bufout, len, 0);
			lfwrite (bufout, len, stream2);

		}

		if (type == 1)
		{

			if (0 == done)
			{

				rc4_setup (&s, key, 256); // 32 é o tamanho da string encryptada

				ss = s;

				done = 1;

			}
			else
			{
				s = ss;
			}

			rc4_crypt (&s, buf, len);
			lfwrite (buf, len, stream2);

		}

	}

	lfclose (stream);
	lfclose (stream2);

	return 0;

}

int __stdcall newfileencrypt (uint type, uchar * inputfile, uchar * outputfile, uchar * key)
{
	int done = 0;
	static uchar buf[AMANDA_TAMANHO];
	static uchar bufout[AMANDA_TAMANHO];
	HANDLE stream;
	HANDLE stream2;
	//uint ret;
	uint len;
	struct rc4_state s, ss;
	uint intfilesize;
	uint intadler32;

	uint fatia = 0;


	pedro_dprintf(-1, "dentro de newfileencrypt");

#ifdef NPRINTF
	dprintf ("Running newfileencrypt!!!!!!!!!!!! \n");
#endif
	if (intpriority)
	{

		int ret;
#ifdef NPRINTF
		dprintf ("Vai setar prioridade \n");
#endif

		switch (intpriority)
		{
		case 1:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_IDLE);
			break;
		case 2:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_LOWEST);
			break;
		case 3:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_BELOW_NORMAL);
			break;
		case 4:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_NORMAL);
			break;
		case 5:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_ABOVE_NORMAL);
			break;
		case 6:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_HIGHEST);
			break;
		case 7:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_TIME_CRITICAL);
			break;

		default:
			break;

		}

		if (!ret)
		{
#ifdef NPRINTF
			dprintf ("nao pode setar a prioridade \n");
#endif

		}
		else
		{
#ifdef NPRINTF
			dprintf ("pode setar a prioridade \n");
#endif
		}

	}
	else
	{
#ifdef NPRINTF
		dprintf ("nao Vai setar prioridade \n");
#endif

	}

	filesize = 0;
#ifdef NPRINTF
	dprintf ("Vai abrir o arquivo \n");
#endif
	if ((stream = lfopen ((char *) inputfile, "rb")) != NULL)
	{

	}
	else
	{
#ifdef NPRINTF
		dprintf ("error opening input file \n");
#endif
		return 1;
	}

	if ((stream2 = lfopen ((char *) outputfile, "wb")) != NULL)
	{

	}
	else
	{
		lfclose (stream);
#ifdef NPRINTF
		dprintf ("error opening output file \n");
#endif
		return 2;

	}
#ifdef NPRINTF
	dprintf ("vai pegar size\n");
#endif
	filesize = lffilesize ((char *) inputfile);
	intfatia = 0;
#ifdef NPRINTF
	dprintf ("Vai pegar adler32\n");
#endif
	if (type == 10 || type == 11)
	{
#ifdef NPRINTF
		dprintf ("Vai pegar adler322\n");
#endif
		intadler32 = adler32filelong (inputfile);
#ifdef NPRINTF
		dprintf ("adler32 %08x \n", intadler32);
#endif

		fatia = 0x20505352;
		lfwrite (&fatia, 4, stream2);
		lfwrite (&intadler32, 4, stream2);
		lfwrite (&filesize, 4, stream2);
	}

	if (type == 12 || type == 13)
	{
#ifdef NPRINTF
		dprintf ("executando decrypt new !!!!!!!!!! \n");
#endif

		len = lfread (&fatia, 4, stream);

		if (fatia == 0x20505352)
		{
#ifdef NPRINTF
			dprintf ("Header found !!!\n");
#endif
		}
		else
		{
			lfclose (stream);
			lfclose (stream2);
			return 3;
			;
		}

		len = lfread (&intadler32, 4, stream);
#ifdef NPRINTF
		dprintf ("adler32 pego em heaader %x \n", intadler32);
#endif
		len = lfread (&intfilesize, 4, stream);
#ifdef NPRINTF
		dprintf ("filesize pego em heaader %d \n", intfilesize);
#endif
	}

	while (1)
	{

		len = lfread (buf, AMANDA_TAMANHO, stream);

		intfatia = intfatia + len;

		if (len <= 0)
		{
			break;
		}

ret1:
		if (1 == intpause)
		{

			if (1 == intcancel)
			{
				break;
			}

			Sleep (50);
			goto ret1;

		}

		if (1 == intcancel)
		{
			break;
		}

		if (type == 10)
		{

			encryptstring (&done, buf, key, bufout, len, 0);
			lfwrite (bufout, len, stream2);

		}

		if (type == 12) // aes encrypt
		{

			decryptstring (&done, buf, key, bufout, len, 0);
			lfwrite (bufout, len, stream2);

		}

		if (type == 11)
		{

			if (0 == done)
			{

				rc4_setup (&s, key, 256);

				ss = s;

				done = 1;

			}
			else
			{
				s = ss;
			}

			rc4_crypt (&s, buf, len);
			lfwrite (buf, len, stream2);

		}

		if (type == 13)
		{

			if (0 == done)
			{

				rc4_setup (&s, key, 256);

				ss = s;

				done = 1;

			}
			else
			{
				s = ss;
			}

			rc4_crypt (&s, buf, len);
			lfwrite (buf, len, stream2);

		}

	}

	lfclose (stream);
	lfclose (stream2);

	if (type == 12 || type == 13)
	{
		int adler32;
		adler32 = adler32filelong (outputfile);

		if ((int)adler32 != (int)intadler32)
		{
			return 4;
		}
/* to avoid the 32 bits limit that was added when I created this interface, if commented it gives 64 bits support
                filesize = lffilesize (outputfile);

                if (intfilesize != filesize)
                {

                }
 */
	}

	return 0;

}

int __stdcall newfileencrypt2 (uint type, uchar * inputfile, uchar * outputfile, uchar * key)
{

	int done = 0;
	static uchar buf[AMANDA_TAMANHO];
	static uchar bufout[AMANDA_TAMANHO];
	HANDLE stream;
	HANDLE stream2;
	//uint ret;
	uint len;
	//struct rc4_state s;
	__int64 intfilesize;
	uint intadler32;
	uint fatia = 0;

	init_aes = 1;

	if (intpriority)
	{
		int ret;
#ifdef NPRINTF
		dprintf ("Vai setar prioridade \n");
#endif

		switch (intpriority)
		{

		case 1:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_IDLE);
			break;
		case 2:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_LOWEST);
			break;
		case 3:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_BELOW_NORMAL);
			break;
		case 4:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_NORMAL);
			break;
		case 5:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_ABOVE_NORMAL);
			break;
		case 6:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_HIGHEST);
			break;
		case 7:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_TIME_CRITICAL);
			break;
		default:
			break;
		}

		if (!ret)
		{
#ifdef NPRINTF
			dprintf ("nao pode setar a prioridade \n");
#endif
		}
		else
		{
#ifdef NPRINTF
			dprintf ("pode setar a prioridade \n");
#endif
		}

	}
	else
	{
#ifdef NPRINTF
		dprintf ("nao Vai setar prioridade \n");
#endif
	}

	filesize = 0;

	if ((stream = lfopen ((char *) inputfile, "rb")) != NULL)
	{

	}
	else
	{
#ifdef NPRINTF
		dprintf ("error opening input file \n");
#endif
		return 1;
	}

	if ((stream2 = lfopen ((char *) outputfile, "wb")) != NULL)
	{

	}
	else
	{
		lfclose (stream);
#ifdef NPRINTF
		dprintf ("error opening output file \n");
#endif
		return 2;
	}

	filesize = lffilesize ((char *) inputfile);
	intfatia = 0;

	if (type == 15)
	{

		intadler32 = adler32filelong (inputfile);
#ifdef NPRINTF
		dprintf ("adler32 %08x \n", intadler32);
#endif

		fatia = 0x20505352;
		lfwrite (&fatia, 4, stream2);
		lfwrite (&intadler32, 4, stream2);
		lfwrite (&filesize, 4, stream2);//here the four is a bug, 32 bits support only, large files fail, the problem was fixed below by someone...
	}

	if (type == 16)
	{
#ifdef NPRINTF
		dprintf ("executando decrypt new !!!!!!!!!! \n");
#endif
		len = lfread (&fatia, 4, stream);

		if (0x20505352 == fatia)
		{
#ifdef NPRINTF
			dprintf ("Header found !!!\n");
#endif
		}
		else
		{

			lfclose (stream);
			lfclose (stream2);

			if (0x38505352 == fatia)
			{
				return newfileencrypt2_sha512 (18, inputfile, outputfile, key);
			}

			return 3;
			;
		}

		len = lfread (&intadler32, 4, stream);
#ifdef NPRINTF
		dprintf ("adler32 pego em heaader %x \n", intadler32);
#endif
		len = lfread (&intfilesize, 4, stream);
#ifdef NPRINTF
		dprintf ("filesize pego em heaader %d \n", intfilesize);
#endif
	}

#ifdef NPRINTF
	dprintf ("Chegou no proximo passo\n");
#endif
	while (1)
	{

		len = lfread (buf, AMANDA_TAMANHO, stream);
		intfatia = intfatia + len;

		if (len <= 0)
		{
			break;
		}

ret1:
		if (1 == intpause)
		{

			if (1 == intcancel)
			{
				break;
			}

			Sleep (50);
			goto ret1;

		}

		if (1 == intcancel)
		{
			break;
		}

		if (type == 15)
		{
			encryptstring2 (&done, buf, key, bufout, len, 0);
			lfwrite (bufout, len, stream2);
		}

		if (type == 16) // aes encrypt
		{
			encryptstring2 (&done, buf, key, bufout, len, 0);
			lfwrite (bufout, len, stream2);
		}
	}

	lfclose (stream);
	lfclose (stream2);

	if (type == 16)
	{
		int adler32;
		adler32 = adler32filelong (outputfile);

		if ((int)adler32 != (int)intadler32)
		{
			return 4;
		}

		//with the comment below the bug was fixed...
/*
                filesize = getfilesize (outputfile);

                if (intfilesize != filesize)
                {

                }
 */

	}

	return 0;

}
static int64_t  the_arp_file_size       ;
static int64_t *bytes_read_arp    = NULL;

int64_t bytes_read_z                    ;

/**
 * 15 = 17    16 = 18
 *
 */
int __stdcall newfileencrypt2_sha512 (uint type, uchar * inputfile, uchar * outputfile, uchar * key)
{	
	int done = 0;
	static uchar buf    [AMANDA_TAMANHO];
	static uchar buf_arp[AMANDA_TAMANHO];
	static uchar bufout [AMANDA_TAMANHO];
	FILE *  stream = NULL;
	FILE * stream2 = NULL;
	//uint ret;
	uint len;
	//__int64 intfilesize;
	//uint intadler32;
	uint fatia = 0;
	unsigned char sha512_digest_k  [65] = {0,};//for safety
	unsigned char sha512_digest_b_k[65] = {0,};//for safety
	
	char key_v2[300] = {0,};
		
	struct rc4_state s;
			
	init_aes = 1;

	bytes_read_z = 0;

	if (intpriority)
	{
		int ret;
#ifdef NPRINTF
		dprintf ("Vai setar prioridade \n");
#endif

		switch (intpriority)
		{

		case 1:
			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_IDLE);
			break;
		case 2:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_LOWEST);
			break;
		case 3:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_BELOW_NORMAL);
			break;
		case 4:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_NORMAL);
			break;
		case 5:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_ABOVE_NORMAL);
			break;
		case 6:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_HIGHEST);
			break;
		case 7:

			ret = SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_TIME_CRITICAL);
			break;

		default:
			break;

		}

		if (!ret)
		{
#ifdef NPRINTF
			dprintf ("nao pode setar a prioridade \n");
#endif
		}
		else
		{
#ifdef NPRINTF
			dprintf ("pode setar a prioridade \n");
#endif
		}

	}
	else
	{
#ifdef NPRINTF
		dprintf ("nao Vai setar prioridade \n");
#endif
	}

	filesize = 0;

	if ((stream = _wfopen (amanda_utf8towide_1_((char *) inputfile), L"rb")) != NULL)
	{

	}
	else
	{
#ifdef NPRINTF
		dprintf ("error opening input file \n");
#endif
		
		return 1;
	}

	if ((stream2 = _wfopen (amanda_utf8towide_1_((char *) outputfile), L"wb")) != NULL)
	{

	}
	else
	{
		fclose (stream);
#ifdef NPRINTF
		dprintf ("error opening output file \n");
#endif
		
		return 2;
	}

	filesize = lffilesize ((char *) inputfile);
	
	pedro_dprintf(-1, "que coisa %lld\n", filesize);
	
	intfatia = 0;

	if (type == 17)//encryption
	{

		//intadler32 = adler32filelong (inputfile);

		SHA512_filelong_k (inputfile, sha512_digest_k);

#ifdef NPRINTF
		dprintf ("adler32 %08x \n", intadler32);
#endif

		if(ARP_RC4 == encryption_method_internal)
		{
			strncpy(key_v2, (char *) key, 32);
			rc4_setup (&s, (uchar *) key_v2, 256);
			//rc4_crypt (&s, tmpbuf, size);
			fatia = 0x706c6176 - 1;
			pedro_dprintf(-1, "encryption method is ARP_RC4\n");			
		}
		else if(ARP_SERPENT == encryption_method_internal)
		{
			pedro_dprintf(-1, "encryption method is ARP_SERPENT\n");
			init_serpent((char *) key);
			fatia = 0x706c6176 - 2;			
		}
		else if(ARP_MARS == encryption_method_internal)
		{
			pedro_dprintf(-1, "encryption method is ARP_MARS\n");
			init_mars_arp((char *) key);
			fatia = 0x706c6176 - 3;
		}
		else if(ARP_RC6 == encryption_method_internal)
		{
			pedro_dprintf(-1, "encryption method is ARP_RC6\n");
			init_rc6__arp((char *) key);
			fatia = 0x706c6176 - 4;
		}
		else if(ARP_TWOFISH == encryption_method_internal)
		{
			pedro_dprintf(-1, "encryption method is ARP_TWOFISH\n");
			init_twofish_arp((char *) key);
			fatia = 0x706c6176 - 5;
		}
		else
		{
			pedro_dprintf(-1, "encryption method is ARP_AES\n");
			fatia = 0x706c6176;
		}
		fwrite (&fatia, 1, 4, stream2);
		fwrite (sha512_digest_k, 1, 64, stream2);
		pedro_dprintf(-1, "salvando o tamanho do arquivo %lld\n", filesize);
		fwrite (&filesize, 1, 8, stream2);
	}

	if (type == 18)
	{
#ifdef NPRINTF
		dprintf ("executando decrypt new !!!!!!!!!! \n");
#endif
		len = fread (&fatia, 1, 4, stream);

		if(0 < len)
		{
			intfatia += len;
			
			*bytes_read_arp += len / 2;
			bytes_read_z    +=     len / 2;
		}

		if (fatia == 0x706c6176)
		{
#ifdef NPRINTF
			dprintf ("Header found !!!\n");
#endif
			encryption_method_internal_un = ARP_AES;
			pedro_dprintf(-1, "unencryption method is AES\n");
			strcpy(encryption_method__i, " + AES");
		}
		else if(fatia == (0x706c6176 - 1))
		{
			strncpy(key_v2, (char *) key, 32);
			rc4_setup (&s, (uchar *) key_v2, 256);
			encryption_method_internal_un = ARP_RC4;
			pedro_dprintf(-1, "unencryption method is RC4\n");
			strcpy(encryption_method__i, " + RC4");
		}
		else if(fatia == (0x706c6176 - 2))
		{
			init_serpent((char *) key);
			encryption_method_internal_un = ARP_SERPENT;
			pedro_dprintf(-1, "unencryption method is SERPENT\n");
			strcpy(encryption_method__i, " + SERPENT");
		}
		else if(fatia == (0x706c6176 - 3))
		{
			init_mars_arp((char *) key);
			encryption_method_internal_un = ARP_MARS;
			pedro_dprintf(-1, "unencryption method is ARP_MARS\n");
			strcpy(encryption_method__i, " + MARS");
		}
		else if(fatia == (0x706c6176 - 4))
		{
			init_rc6__arp((char *) key);
			encryption_method_internal_un = ARP_RC6;
			pedro_dprintf(-1, "unencryption method is ARP_RC6\n");
			strcpy(encryption_method__i, " + RC6");
		}
		else if(fatia == (0x706c6176 - 5))
		{
			init_twofish_arp((char *) key);
			encryption_method_internal_un = ARP_TWOFISH;
			pedro_dprintf(-1, "unencryption method is ARP_TWOFISH\n");
			strcpy(encryption_method__i, " + TWOFISH");
		}
		else
		{
			fclose (stream);
			fclose (stream2);
			return 3;
			;
		}

		len = fread (sha512_digest_b_k, 1, 64, stream);
		if(0 < len)
		{
			intfatia += len;
			*bytes_read_arp += len / 2;
			bytes_read_z    += len / 2;
		}
		len = fread (&the_arp_file_size, 1, 8, stream);
		if(0 < len)
		{
			intfatia += len;
			*bytes_read_arp += len / 2;
			bytes_read_z    += len / 2;
		}
	}

	while (1)
	{
        
		len = fread (buf, 1, AMANDA_TAMANHO, stream);
		
		pedro_dprintf(-1, "len %d\n", len);
		
		if (len <= 0)
		{
			break;
		}
		intfatia = intfatia + len;
		*bytes_read_arp += len / 2;
		bytes_read_z    += len / 2;
			
ret1:
		if (1 == intpause)
		{

			if (1 == intcancel)
			{
				break;
			}

			Sleep (50);
			goto ret1;

		}

		if (1 == intcancel)
		{
			break;
		}

		if (type == 17)
		{
			if(ARP_RC4 == encryption_method_internal)
			{
				rc4_crypt (&s, buf,                         len);
				fwrite (buf, 1, len,                      stream2);
				pedro_dprintf(-1, "len 2 %d\n", len);
			}
			else if(ARP_SERPENT == encryption_method_internal)
			{
				encryptstring_serpent (
										buf,
										buf_arp,
										key,
										len
									   );
				fwrite (buf_arp, 1, len,                  stream2);
			}
			else if(ARP_MARS == encryption_method_internal)
			{
				encryptstring_mars_arp (
										buf,
										buf_arp,
										key,
										len
									   );
				fwrite (buf_arp, 1, len,                  stream2);
			}
			else if(ARP_RC6 == encryption_method_internal)
			{
				encryptstring_rc6_arp (
										buf,
										buf_arp,
										key,
										len
									   );
				fwrite (buf_arp, 1, len,                  stream2);
			}
			else if(ARP_TWOFISH == encryption_method_internal)
			{
				encryptstring_twofish_arp (
										buf,
										buf_arp,
										key,
										len
									   );
				fwrite (buf_arp, 1, len,                  stream2);
			}
			else
			{
				encryptstring2 (&done, buf, key, bufout, len, 0);
				fwrite (bufout, 1, len,                   stream2);
			}
			
		}

		if (type == 18) // aes unencrypt
		{
			if(ARP_RC4 == encryption_method_internal_un)
			{				
				rc4_crypt (&s, buf,                         len);
				fwrite (buf, 1, len,                      stream2);				
			}
			else if(ARP_AES == encryption_method_internal_un)
			{
				encryptstring2 (&done, buf, key, bufout, len, 0);
				fwrite (bufout, 1, len,                   stream2);
			}
			else if(ARP_SERPENT == encryption_method_internal_un)
			{
				encryptstring_serpent (
										buf,
										buf_arp,
										key,
										len
									   );
				fwrite (buf_arp, 1, len,                  stream2);
			}
			else if(ARP_MARS == encryption_method_internal_un)
			{
				encryptstring_mars_arp (
										buf,
										buf_arp,
										key,
										len
									   );
				fwrite (buf_arp, 1, len,                  stream2);
			}
			else if(ARP_RC6 == encryption_method_internal_un)
			{
				encryptstring_rc6_arp (
										buf,
										buf_arp,
										key,
										len
									   );
				fwrite (buf_arp, 1, len,                  stream2);
			}
			else if(ARP_TWOFISH == encryption_method_internal_un)
			{
				encryptstring_twofish_arp (
											buf,
											buf_arp,
											key,
											len
										   );
				fwrite (buf_arp, 1, len,                  stream2);
			}
			else
			{
				assert(0 && "Invalid encryption method\n");
			}
		}
	}

	fclose (stream);
	fclose (stream2);

	if (type == 18)
	{
		//int adler32;
		SHA512_filelong_k (outputfile, sha512_digest_k);
		//adler32 = adler32filelong (outputfile);

		if (0 != memcmp(sha512_digest_k, sha512_digest_b_k, 64))
		{			
			return 4;
		}
	}
	
	return 0;

}
int free_to_work_arp = 0;
int encrypt_arp(uchar * inputfile, uchar * outputfile, uchar * key, int encryption_method_internal_arp)
{
	int ret_arp;
	char key_arp [300]  = {0};
	
	strncpy(key_arp, (char *) key, 35);
	
	key_arp[32]           = 0;
	intcancel             = 0;
	intpause              = 0;
	intpriority           = 0;
	unicodemode           = 1;
		
	free_to_work_arp = 1;
	
	encryption_method_internal = encryption_method_internal_arp;
	ret_arp = newfileencrypt2_sha512 (17, inputfile, outputfile, (uchar *) key_arp);
	encryption_method_internal = 0;
	free_to_work_arp = 0;
	
	if(intcancel)
	{
		return 119;//user cancel.
	}
	
	return ret_arp;
}

int decrypt_arp(uchar * inputfile, uchar * outputfile, uchar * key, int64_t *the_arp_file_size_, char * encryption_method_i)
{
	int ret_arp;
	char key_arp [300]  = {0};
	
	strncpy(key_arp, (char *) key, 35);
	
	key_arp[32]           = 0;
	intcancel             = 0;
	intpause              = 0;
	intpriority           = 0;
	unicodemode           = 1;
	
	encryption_method__i = encryption_method_i;
	
	free_to_work_arp = 1;
	ret_arp = newfileencrypt2_sha512 (18, inputfile, outputfile, (uchar *) key_arp);
	*the_arp_file_size_ =                               the_arp_file_size;
	free_to_work_arp = 0;
	
	if(intcancel)
	{
		return 119;//user cancel.
	}
	
	return ret_arp;
}

void update_progress_arp(int64_t *valor_a_atualizar_arp)
{
	bytes_read_arp = valor_a_atualizar_arp;
}
int __stdcall decryptstring (int *done, uchar * buf, uchar * key, uchar * bufout, uint size, __attribute__((unused)) uint keysize)
{

	//uchar lbuf[16];
	uchar *pchar;
	uchar *pchar2;
	//uint pointer;
	//uint i;
	uchar tmpbuf[16];
	struct rc4_state s;

	pchar = bufout;
	pchar2 = buf;

	for (; size > 15; size = size - 16)
	{

		aesdecrypt (pchar2, pchar, key, 256, done);
		pchar += 16;
		pchar2 += 16;

	}

	if (size != 0)
	{
		memcpy (tmpbuf, pchar2, size);
#ifdef NPRINTF
		dprintf ("Executando rc4 para finalizar %d \n", size);
#endif
		rc4_setup (&s, key, 256);
		rc4_crypt (&s, tmpbuf, size);
		memcpy (pchar, tmpbuf, size);
	}

	return 0;

}

int __stdcall encryptstring (int *done, uchar * buf, uchar * key, uchar * bufout, uint size, __attribute__((unused)) uint keysize)
{

	//uchar lbuf[16];
	uchar *pchar;
	uchar *pchar2;
	//uint pointer;
	//uint i;
	uchar tmpbuf[16];
	struct rc4_state s;

	pchar = bufout;
	pchar2 = buf;

	for (; size > 15; size = size - 16)
	{

		aesencrypt (pchar2, pchar, key, 256, done);

		pchar += 16;
		pchar2 += 16;

	}

	if (size != 0)
	{
		memcpy (tmpbuf, pchar2, size);  // fazendo a copia no temporario que nao sera maior que 16
#ifdef NPRINTF
		dprintf ("Executando rc4 para finalizar %d \n", size);
#endif
		rc4_setup (&s, key, 256); // 32 é o tamanho da string encryptada
		rc4_crypt (&s, tmpbuf, size);   // encryptando

		memcpy (pchar, tmpbuf, size);   // copiando para o final
	}

	return 0;

}

int __stdcall encryptstring2 (int *done, uchar * buf, uchar * key, uchar * bufout, uint size, __attribute__((unused)) uint keysize)
{

	//uchar lbuf[16];
	uchar *pchar;
	uchar *pchar2;
	//uint pointer;
	//uint i;
	//uchar tmpbuf[16];
	//struct rc4_state s;

	static char countbuffer[17];

	static int *ptr1 = NULL;
	static int *ptr2 = NULL;
	static int *ptr3 = NULL;
	static int *ptr4 = NULL;

	int   *pptr1 = NULL;
	int   *pptr2 = NULL;
	int   *pptr3 = NULL;
	int   *pptr4 = NULL;

	int   *pttr1 = NULL;
	int   *pttr2 = NULL;
	int   *pttr3 = NULL;
	int   *pttr4 = NULL;

	if (init_aes)
	{

		memset (countbuffer, 0, 16);
		ptr1 = (int *) &countbuffer[0];
		ptr2 = (int *) &countbuffer[4];
		ptr3 = (int *) &countbuffer[8];
		ptr4 = (int *) &countbuffer[12];
#ifdef NPRINTF
		dprintf ("1itens %08x %08x %08x %08x \n", *ptr1, *ptr2, *ptr3, *ptr4);
#endif
		*ptr1 = crc32 (0, key, 32);

		*ptr2 = crc32 (*ptr1, key, 32);

		*ptr3 = crc32 (*ptr2, key, 32);

		*ptr4 = crc32 (*ptr3, key, 32);
#ifdef NPRINTF
		dprintf ("2itens %08x %08x %08x %08x \n", *ptr1, *ptr2, *ptr3, *ptr4);
#endif
		init_aes = 0;

	}

	pchar = bufout;
	pchar2 = buf;

	for (; size > 15; size = size - 16)
	{

		(*ptr1)++;
		(*ptr2)++;
		(*ptr3)++;
		(*ptr4)++;

		aesencrypt ((uchar *) countbuffer, pchar, key, 256, done);

		pptr1 = (int *) &pchar[0];
		pptr2 = (int *) &pchar[4];
		pptr3 = (int *) &pchar[8];
		pptr4 = (int *) &pchar[12];

		pttr1 = (int *) &pchar2[0];
		pttr2 = (int *) &pchar2[4];
		pttr3 = (int *) &pchar2[8];
		pttr4 = (int *) &pchar2[12];

		*pptr1 = *pptr1 ^ *pttr1;
		*pptr2 = *pptr2 ^ *pttr2;
		*pptr3 = *pptr3 ^ *pttr3;
		*pptr4 = *pptr4 ^ *pttr4;

		pchar += 16;
		pchar2 += 16;

	}

	if (size != 0)
	{

		char ppchar2[255];
		char ppchar[255];

		memset (ppchar2, 0, 255);
#ifdef NPRINTF
		dprintf ("Tamanho %d \n", size);
#endif
		memcpy (ppchar2, pchar2, size);

		(*ptr1)++;
		(*ptr2)++;
		(*ptr3)++;
		(*ptr4)++;

		pchar2 = (void *) ppchar2;

		aesencrypt ((uchar *) countbuffer, (uchar *) ppchar, key, 256, done);

		pptr1 = (int *) &ppchar[0];
		pptr2 = (int *) &ppchar[4];
		pptr3 = (int *) &ppchar[8];
		pptr4 = (int *) &ppchar[12];

		pttr1 = (int *) &pchar2[0];
		pttr2 = (int *) &pchar2[4];
		pttr3 = (int *) &pchar2[8];
		pttr4 = (int *) &pchar2[12];
#ifdef NPRINTF
		dprintf ("aitens %08x %08x %08x %08x \n", *pttr1, *pttr2, *pttr3, *pttr4);
		dprintf ("bitens %08x %08x %08x %08x \n", *pptr1, *pptr2, *pptr3, *pptr4);
#endif

		*pptr1 = *pptr1 ^ *pttr1;
		*pptr2 = *pptr2 ^ *pttr2;
		*pptr3 = *pptr3 ^ *pttr3;
		*pptr4 = *pptr4 ^ *pttr4;
#ifdef NPRINTF
		dprintf ("citens %08x %08x %08x %08x \n", *pttr1, *pttr2, *pttr3, *pttr4);
		dprintf ("ditens %08x %08x %08x %08x \n", *pptr1, *pptr2, *pptr3, *pptr4);
#endif

		memcpy (pchar, ppchar, size);
	}

	return 0;

}

uint getpor_int64 (__int64 max, __int64 fatia)
{

	double maxa;
	double fatiaa;

	maxa = (double) max;
	fatiaa = (double) fatia;

	if (max == 0)
	{
		return 0;
	}

	maxa = ((double) 100 / maxa * fatiaa);

	return (uint) maxa;

}

int __stdcall cltrim (char *data)
{
	char  *ptr;
	char  *copia = malloc ((strlen (data) * 2) + 10);
	strcpy (copia, data);
	ptr = copia;
	while (' ' == ptr[0])
	{
		ptr++;
	}
	strcpy (data, ptr);
	free (copia);
	return 0;
}

int __stdcall crtrim (char *data)
{
volta:
	if (strlen (data))
	{
		if (' ' == data[strlen (data) - 1])
		{
			data[strlen (data) - 1] = 0;
			goto volta;
		}
	}
	return 0;
}

int __stdcall interface1 (__INT32_OR_INT64 argumento1, __INT32_OR_INT64 argumento2, __INT32_OR_INT64 argumento3, __INT32_OR_INT64 argumento4)
{
	int ret;

	static uint intsize;
	static int already = 0;

	if (!strcmp ((char *) argumento1, "netaesfileencrypt"))
	{
		ret = GetTickCount ();
		ret = ret % 5;
		if (!ret && (already == 0))
		{
			already = 1;
		}
		if (intstatus == 1)
		{
			return 1;
		}
		intstatus = 1;
		intcancel = 0;
		intpause = 0;
		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);
		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}
		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 1;
		execute ();
		return 0;
	}

	if (!strcmp ((char *) argumento1, "aesfileencrypt"))
	{

		if (intstatus == 1)
		{

			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 1;

		execute ();

		return 0;
	}

	if (!strcmp ((char *) argumento1, "newaesfileencrypt2"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 15;

		execute ();

		return 0;
	}

	if (!strcmp ((char *) argumento1, "newaesfileencrypt2_sha512"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 17;

		execute ();

		return 0;
	}

	if (!strcmp ((char *) argumento1, "newaesfileencrypt"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 11;

		execute ();

		return 0;
	}

	if (!strcmp ((char *) argumento1, "netaesfiledecrypt"))
	{

		ret = GetTickCount ();

		ret = ret % 5;

		if (!ret && (already == 0))
		{
			already = 1;
		}

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 2;
		execute ();
		return 0;
	}

	if (!strcmp ((char *) argumento1, "newaesfiledecrypt2"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 16;
		execute ();

		return 0;
	}

	if (!strcmp ((char *) argumento1, "newaesfiledecrypt2_sha512"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 18;
		execute ();

		return 0;
	}

	if (!strcmp ((char *) argumento1, "newaesfiledecrypt"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 12;
		execute ();
		return 0;
	}

	if (!strcmp ((char *) argumento1, "aesfiledecrypt"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 2;
		execute ();
		return 0;
	}

	if (!strcmp ((char *) argumento1, "netrc4fileencrypt"))
	{

		ret = GetTickCount ();

		ret = ret % 5;

		if (!ret && (already == 0))
		{
			already = 1;
		}

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 3;
		execute ();
		return 0;
	}

	if (!strcmp ((char *) argumento1, "rc4fileencrypt"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif
		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif

		comando = 3;
		execute ();
		return 0;
	}

	if (!strcmp ((char *) argumento1, "newrc4fileencrypt"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;

#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 13;
		execute ();
		return 0;
	}

	if (!strcmp ((char *) argumento1, "newrc4filedecrypt"))
	{

		if (intstatus == 1)
		{
			return 1;
		}

		intstatus = 1;
		intcancel = 0;
		intpause = 0;

		memset (inputfile, 0, 260);
		memset (outputfile, 0, 260);

		if (strlen ((char *) argumento2) < 261)
		{
			strcpy ((char *) inputfile, (char *) argumento2);
		}

		if (strlen ((char *) argumento3) < 261)
		{
			strcpy ((char *) outputfile, (char *) argumento3);
		}
#ifdef NPRINTF
		dprintf ("nome1%s \n", inputfile);
		dprintf ("nome2%s \n", outputfile);
#endif

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;

#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		comando = 14;
		execute ();
		return 0;
	}

	if (!strcmp ((char *) argumento1, "definesize"))
	{
		intsize = argumento2;
	}

	if (!strcmp ((char *) argumento1, "getsize"))
	{

		return intsize;

	}

	if (!strcmp ((char *) argumento1, "aesstringencrypt2"))
	{
		char  *temp;
		//int ret;

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("pass-%s- \n", key);
#endif

		{
			int done = 0;
			init_aes = 1;
			encryptstring2 (&done, (uchar *) argumento2, key, (uchar *) argumento3, intsize, 0);
		}

#ifdef NPRINTF
		dprintf ("enc aes Valor de intsize %d \n", intsize);
#endif
		temp = malloc ((intsize * 2) + 1);

		memset (temp, 0, (intsize * 2) + 1);

		ret = dectohex ((uchar *) argumento3, (uchar *) temp, intsize);

#ifdef NPRINTF
		dprintf ("string encryptada %s\n", temp);
#endif
		strcpy ((char *) argumento3, temp);

		free (temp);

		intsize = intsize * 2;
		return 1;
	}

	if (!strcmp ((char *) argumento1, "aesstringencrypt"))
	{
		char  *temp;
		//int ret;

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif
		{
			int done = 0;
			encryptstring (&done, (uchar *) argumento2, key, (uchar *) argumento3, intsize, 0);
		}

#ifdef NPRINTF
		dprintf ("enc aes Valor de intsize %d \n", intsize);
#endif
		temp = malloc ((intsize * 2) + 1);

		memset (temp, 0, (intsize * 2) + 1);

		ret = dectohex ((uchar *) argumento3, (uchar *) temp, intsize);

		strcpy ((char *) argumento3, temp);

		free (temp);

		intsize = intsize * 2;
		return 1;
	}

	if (!strcmp ((char *) argumento1, "aesstringdecrypt"))
	{

		char  *temp;
		char  *temp2;
		int ret;
		int finallen;

		temp2 = (char *) argumento3;

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif

		temp = malloc ((intsize * 2) + 1);

		memset (temp, 0, (intsize * 2) + 1);
#ifdef NPRINTF
		dprintf ("dec aes Valor de intsize %d \n", intsize);
#endif

		if (strlen ((char *) argumento2) != intsize)
		{
#ifdef NPRINTF
			dprintf ("-->> aqui deu erro \n");
#endif
		}
		ret = hextodec (intsize, (uchar *) argumento2, (uchar *) temp, (uint *) &finallen);

		if (ret == 0)
		{

			{
				int done = 0;

				decryptstring (&done, (uchar *) temp, key, (uchar *) argumento3, finallen, 0);
			}

			temp2[finallen] = 0;
		}
		else
		{
#ifdef NPRINTF
			dprintf ("deu erro na conversao %d \n", ret);
#endif
			strcpy ((char *) argumento3, " \0");
		}

		free (temp);

		intsize = finallen;

		return ret;

	}

	if (!strcmp ((char *) argumento1, "aesstringdecrypt2"))
	{

		char  *temp;
		char  *temp2;
		int ret;
		int finallen;

		temp2 = (char *) argumento3;

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif

		temp = malloc ((intsize * 2) + 1);

		memset (temp, 0, (intsize * 2) + 1);
#ifdef NPRINTF
		dprintf ("dec aes Valor de intsize %d \n", intsize);
#endif

		if (strlen ((char *) argumento2) != intsize)
		{
#ifdef NPRINTF
			dprintf ("-->> aqui deu erro \n");
#endif
		}
		ret = hextodec (intsize, (uchar *) argumento2, (uchar *) temp, (uint *) &finallen);

		if (ret == 0)
		{

			{
				int done = 0;
				init_aes = 1;
				encryptstring2 (&done, (uchar *) temp, key, (uchar *) argumento3, finallen, 0);
			}

			temp2[finallen] = 0;

		}
		else
		{
#ifdef NPRINTF
			dprintf ("deu erro na conversao %d \n", ret);
#endif
			strcpy ((char *) argumento3, " \0");
		}

		free (temp);
		intsize = finallen;
		return ret;

	}

	if (!strcmp ((char *) argumento1, "rc4stringencrypt"))
	{

		struct rc4_state s;
		char  *temp;
		//int ret;

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;//why?...
#ifdef NPRINTF
		dprintf ("-%s- \n", key);
#endif

		rc4_setup (&s, key, 256);
		rc4_crypt (&s, (uchar *) argumento2, intsize);
#ifdef NPRINTF
		dprintf ("RC4 Valor de intsize %d \n", intsize);
#endif
		memcpy ((char *) argumento3, (char *) argumento2, intsize);

		temp = malloc ((intsize * 2) + 1);

		memset (temp, 0, (intsize * 2) + 1);

		ret = dectohex ((uchar *) argumento3, (uchar *) temp, intsize);

		strcpy ((char *) argumento3, temp);

		free (temp);

		intsize = intsize * 2;
		return 1;

	}

	if (!strcmp ((char *) argumento1, "rc4stringdecrypt"))
	{
		struct rc4_state s;
		char  *temp;
		char  *temp2;
		int ret;
		int finallen;

		temp2 = (char *) argumento3;

		memset (key, 0, 256);
		memcpy (key, (char *) argumento4, 32);

		key[32] = 0;//why we need it?...
#ifdef NPRINTF
		dprintf ("-%s- \n", key);

		dprintf ("tamanho de key %d \n", strlen (key));
#endif
		temp = malloc ((intsize * 2) + 1);

		memset (temp, 0, (intsize * 2) + 1);

		if (strlen ((char *) argumento2) != intsize)
		{
#ifdef NPRINTF
			dprintf ("-->> aqui deu erro \n");
#endif
		}

		ret = hextodec (intsize, (uchar *) argumento2, (uchar *) temp, (uint *) &finallen);
#ifdef NPRINTF
		dprintf ("valor de final len %d \n", finallen);
#endif

		if (ret == 0)
		{
			rc4_setup (&s, key, 256);
			rc4_crypt (&s, (uchar *) temp, finallen);
			memcpy ((char *) argumento3, temp, finallen);
			temp2[finallen] = 0;
		}
		else
		{
#ifdef NPRINTF
			dprintf ("deu erro na conversao %d \n", ret);
#endif
			strcpy ((char *) argumento3, " \0");
		}

		free (temp);
		intsize = finallen;
		return ret;

	}

	if (!strcmp ((char *) argumento1, "decimaltohexa"))
	{

		return dectohex ((uchar *) argumento2, (uchar *) argumento3, argumento4);

	}


	if (!strcmp ((char *) argumento1, "hexatodecimal"))
	{

		return hextodec (strlen ((char *) argumento2), (uchar *) argumento2, (uchar *) argumento3, (uint *) argumento4);

	}

	if (!strcmp ((char *) argumento1, "getstatus"))
	{

		return intstatus;

	}

	if (!strcmp ((char *) argumento1, "getreturn"))
	{

		return intreturn;

	}

	if (!strcmp ((char *) argumento1, "pause"))
	{

		intpause = 1;

	}

	if (!strcmp ((char *) argumento1, "resume"))
	{

		intpause = 0;

	}

	if (!strcmp ((char *) argumento1, "cancel"))
	{

		intcancel = 1;

	}

	if (!strcmp ((char *) argumento1, "getprogress"))
	{

		int ret;

		if(!free_to_work_arp)
		{
			return 100;
		}

		ret = getpor_int64 ((filesize), (intfatia));

		if (ret > 100)
		{
			ret = 100;
		}
		if (ret < 0)
		{
			ret = 0;
		}

		return ret;

	}

	if (!strcmp ((char *) argumento1, "cpuspeed"))
	{

		double freq;
		static LARGE_INTEGER first;
		QueryPerformanceFrequency (&first);
		freq = (double) first.QuadPart;

		dprintf("speed %f\n",freq);

		sprintf ((char *) argumento2, "%0.2f Ghz",freq/1000000.0);

		return 0;
	}

	if (!strcmp ((char *) argumento1, "getcpuname"))
	{
		//int ret;
		char  *temp;

		temp = getcpuname ();
		if (strlen (temp))
		{
			cltrim (temp);
			crtrim (temp);
			strcpy ((char *) argumento2, temp);
		}
		else
		{
			strcpy ((char *) argumento2, "Unavailable");
		}

		return (0);

	}

	if (!strcmp ((char *) argumento1, "getbrandstring"))
	{
		//int ret;

		char  *temp;

		temp = getprocessorbrandstring ();

		if (strlen (temp))
		{

			cltrim (temp);
			crtrim (temp);

			strcpy ((char *) argumento2, temp);
		}
		else
		{
			strcpy ((char *) argumento2, "Unavailable");
		}

		return (0);

	}

	if (!strcmp ((char *) argumento1, "setpriority"))
	{

		intpriority = argumento2;
		return 0;

	}
//an assert(0); would be great here...
	return 0;

}

int __stdcall stringtobyte (unsigned char *dest, unsigned char *src, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	return 0;
}
int __stdcall bytetostring (unsigned char *dest, unsigned char *src, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = 0;
	return 0;
}

int __stdcall debugreal (__attribute__((unused)) unsigned char *data, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
#ifdef NPRINTF
		dprintf ("item > %d  %d \n", data[i], i);
#endif
	}
	return 0;
}

int __stdcall EncryptStringAES (char *InputString, char *OutPutString, char *Password2, char *ErrorString)
{
	int ret;
	char Password[1000] = { 0, };
	strncpy (Password, Password2, 998);
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if (ret)
	{
		strcpy (ErrorString, "Already running, call the cancel function to stop execution");
		return 8;
	}

	ret = interface1 ((__INT32_OR_INT64) "definesize", strlen (InputString), 0, 0);

	ret = interface1 ((__INT32_OR_INT64) "aesstringencrypt", (__INT32_OR_INT64) InputString, (__INT32_OR_INT64) OutPutString, (__INT32_OR_INT64) Password);

	return 0;
}

int __stdcall EncryptStringAES_CTR (char *InputString, char *OutPutString, char *Password2, char *ErrorString)
{
	int ret;
	char Password[1000] = { 0, };

	strncpy (Password, Password2, 998);
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if (ret)
	{
		strcpy (ErrorString, "Already running, call the cancel function to stop execution");
		return 8;
	}

	ret = interface1 ((__INT32_OR_INT64) "definesize", strlen (InputString), 0, 0);

	ret = interface1 ((__INT32_OR_INT64) "aesstringencrypt2", (__INT32_OR_INT64) InputString, (__INT32_OR_INT64) OutPutString, (__INT32_OR_INT64) Password);

	return 0;
}

int __stdcall EncryptStringRC4 (char *InputString, char *OutPutString, char *Password2, char *ErrorString)
{
	int ret;
	char Password[1000] = { 0, };

	strncpy (Password, Password2, 998);
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 8;
	}

	ret = interface1 ((__INT32_OR_INT64) "definesize", strlen (InputString), 0, 0);

	ret = interface1 ((__INT32_OR_INT64) "rc4stringencrypt", (__INT32_OR_INT64) InputString, (__INT32_OR_INT64) OutPutString, (__INT32_OR_INT64) Password);

	return 0;
}

int __stdcall DecryptStringAES (char *InputString, char *OutPutString, char *Password2, char *ErrorString)
{
	int ret;
	char Password[1000] = { 0, };
	if (0 == strlen (InputString))
	{
		strcpy (OutPutString, "");
		return 0;
	}
	strncpy (Password, Password2, 998);
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 8;
	}

	ret = interface1 ((__INT32_OR_INT64) "definesize", strlen (InputString), 0, 0);

	ret = interface1 ((__INT32_OR_INT64) "aesstringdecrypt", (__INT32_OR_INT64) InputString, (__INT32_OR_INT64) OutPutString, (__INT32_OR_INT64) Password);

	return 0;
}
int __stdcall DecryptStringAES_CTR (char *InputString, char *OutPutString, char *Password2, char *ErrorString)
{
	int ret;
	char Password[1000] = { 0, };
	if (0 == strlen (InputString))
	{
		strcpy (OutPutString, "");
		return 0;
	}
	strncpy (Password, Password2, 998);
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 8;
	}

	ret = interface1 ((__INT32_OR_INT64) "definesize", strlen (InputString), 0, 0);

	ret = interface1 ((__INT32_OR_INT64) "aesstringdecrypt2", (__INT32_OR_INT64) InputString, (__INT32_OR_INT64) OutPutString, (__INT32_OR_INT64) Password);

	return 0;
}
int __stdcall DecryptStringRC4 (char *InputString, char *OutPutString, char *Password2, char *ErrorString)
{

	int ret;
	char Password[1000] = { 0, };

	if (0 == strlen (InputString))
	{
		strcpy (OutPutString, "");
		return 0;
	}

	strncpy (Password, Password2, 998);
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 8;
	}

	ret = interface1 ((__INT32_OR_INT64) "definesize", strlen (InputString), 0, 0);

	ret = interface1 ((__INT32_OR_INT64) "rc4stringdecrypt", (__INT32_OR_INT64) InputString, (__INT32_OR_INT64) OutPutString, (__INT32_OR_INT64) Password);

	return 0;
}

int __stdcall GetCPUVendor (char *cpu_vendor)
{
	extern void __cdecl removedordeespaconofinal (char *path);
	extern void __cdecl removedordeespaconoinicio (char *path);
	//int ret;

	interface1 ((__INT32_OR_INT64) "getcpuname", (__INT32_OR_INT64) cpu_vendor, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

	removedordeespaconofinal (cpu_vendor);
	removedordeespaconoinicio (cpu_vendor);

	return 0;
}

int __stdcall GetCPUBrandString (char *brand_string)
{
	extern void __cdecl removedordeespaconofinal (char *path);
	extern void __cdecl removedordeespaconoinicio (char *path);
	//int ret;

	interface1 ((__INT32_OR_INT64) "getbrandstring", (__INT32_OR_INT64) brand_string, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

	removedordeespaconofinal (brand_string);
	removedordeespaconoinicio (brand_string);

	return 0;
}

int __stdcall GetCPUSpeed (char *speed_in_mhz)
{
	
	interface1 ((__INT32_OR_INT64) "cpuspeed", (__INT32_OR_INT64) speed_in_mhz, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);
	return 0;
}

int __stdcall shellexecute_alladin (char *url)
{
	
	ShellExecute (0, "open", url, NULL, NULL, SW_SHOWNORMAL);
	return 0;
}

int __stdcall SetProcessorPriority (int priority)
{
#ifdef NPRINTF
	dprintf ("priorirty: %d\n", priority);
#endif
	interface1 ((__INT32_OR_INT64) "setpriority", (__INT32_OR_INT64) priority, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

	return 0;
}

int waitmode = 1;
int __stdcall WaitExecution (int wait)
{
	waitmode = wait;
	return 0;
}

int checkforequal(char*a,char*b)
{
	return !stricmp(a,b);
}

int __stdcall NewEncryptFileAES (char *Inputfile, char *OutPutFile, char *Password2, char *ErrorString)
{
	int ret;

	char Password[1000] = { 0, };

	unicodemode = 1;

	strncpy (Password, Password2, 998);

	if(checkforequal(Inputfile,OutPutFile))
	{
		strcpy (ErrorString, "Input and output file are the same");
		return 1;
	}

	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 1;
	}

	ret = interface1 ((__INT32_OR_INT64) "newaesfileencrypt", (__INT32_OR_INT64) Inputfile, (__INT32_OR_INT64) OutPutFile, (__INT32_OR_INT64) Password);

	if (ret)
	{
		strcpy (ErrorString, "Unexpected error");
		return 2;
	}

retorno:
	if (waitmode)
	{

		if (intstatus)
		{
			Sleep (50);
			goto retorno;
		}
	}

	return 0;
}

int __stdcall NewEncryptFileRC4 (char *Inputfile, char *OutPutFile, char *Password2, char *ErrorString)
{
	int ret;

	char Password[1000] = { 0, };

	strncpy (Password, Password2, 998);
	unicodemode = 1;
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if(checkforequal(Inputfile,OutPutFile))
	{
		strcpy (ErrorString, "Input and output file are the same");
		return 1;
	}
	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 1;
	}

	ret = interface1 ((__INT32_OR_INT64) "newrc4fileencrypt", (__INT32_OR_INT64) Inputfile, (__INT32_OR_INT64) OutPutFile, (__INT32_OR_INT64) Password);

	if (ret)
	{
		strcpy (ErrorString, "Unexpected error");
		return 2;
	}

retorno:
	if (waitmode)
	{
		if (intstatus)
		{
			Sleep (50);
			goto retorno;
		}
	}

	return 0;
}

int __stdcall NewEncryptFileAES_CTR (char *Inputfile, char *OutPutFile, char *Password2, char *ErrorString)
{
	int ret;

	char Password[1000] = { 0, };

	strncpy (Password, Password2, 998);
	unicodemode = 1;
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if(checkforequal(Inputfile,OutPutFile))
	{
		strcpy (ErrorString, "Input and output file are the same");
		return 1;
	}
	if (ret)
	{
		strcpy (ErrorString, "Already running, call the cancel function to stop execution");
		return 1;
	}

	ret = interface1 ((__INT32_OR_INT64) "newaesfileencrypt2", (__INT32_OR_INT64) Inputfile, (__INT32_OR_INT64) OutPutFile, (__INT32_OR_INT64) Password);

	if (ret)
	{
		strcpy (ErrorString, "Unexpected error");
		return 2;
	}

retorno:
	if (waitmode)
	{
		if (intstatus)
		{
			Sleep (50);
			goto retorno;
		}
	}

	return 0;
}

int __stdcall NewEncryptFileAES_CTR_SHA512_k (char *Inputfile, char *OutPutFile, char *Password2, char *ErrorString)
{
	int ret;

	char Password[1000] = { 0, };

	strncpy (Password, Password2, 998);
	unicodemode = 1;
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if(checkforequal(Inputfile,OutPutFile))
	{
		strcpy (ErrorString, "Input and output file are the same");
		return 1;
	}
	if (ret)
	{
		strcpy (ErrorString, "Already running, call the cancel function to stop execution");
		return 1;
	}

	ret = interface1 ((__INT32_OR_INT64) "newaesfileencrypt2_sha512", (__INT32_OR_INT64) Inputfile, (__INT32_OR_INT64) OutPutFile, (__INT32_OR_INT64) Password);

	if (ret)
	{
		strcpy (ErrorString, "Unexpected error");
		return 2;
	}

retorno:
	if (waitmode)
	{
		if (intstatus)
		{
			Sleep (50);
			goto retorno;
		}
	}

	return 0;
}


int __stdcall GetStatus()
{

	return interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

}

int __stdcall GetReturn()
{

	return interface1 ((__INT32_OR_INT64) "getreturn", (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

}

int __stdcall GetProgress()
{

	return interface1 ((__INT32_OR_INT64) "getprogress", (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

}

int __stdcall NewDecryptFileAES (char *Inputfile, char *OutPutFile, char *Password2, char *ErrorString)
{
	int ret;

	char Password[1000] = { 0, };

	strncpy (Password, Password2, 998);
	unicodemode = 1;
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if(checkforequal(Inputfile,OutPutFile))
	{
		strcpy (ErrorString, "Input and output file are the same");
		return 1;
	}
	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 1;
	}

	ret = interface1 ((__INT32_OR_INT64) "newaesfiledecrypt", (__INT32_OR_INT64) Inputfile, (__INT32_OR_INT64) OutPutFile, (__INT32_OR_INT64) Password);

	if (ret)
	{
		strcpy (ErrorString, "Unexpected error");
		return 2;
	}

retorno:
	if (waitmode)
	{

		if (intstatus)
		{
			Sleep (50);
			goto retorno;
		}
	}

	return 0;
}

int __stdcall NewDecryptFileAES_CTR (char *Inputfile, char *OutPutFile, char *Password2, char *ErrorString)
{
	int ret;

	char Password[1000] = { 0, };

	strncpy (Password, Password2, 998);
	unicodemode = 1;
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if(checkforequal(Inputfile,OutPutFile))
	{
		strcpy (ErrorString, "Input and output file are the same");
		return 1;
	}
	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 1;
	}

	ret = interface1 ((__INT32_OR_INT64) "newaesfiledecrypt2", (__INT32_OR_INT64) Inputfile, (__INT32_OR_INT64) OutPutFile, (__INT32_OR_INT64) Password);

	if (ret)
	{
		strcpy (ErrorString, "Unexpected error");
		return 2;
	}

retorno:
	if (waitmode)
	{
		if (intstatus)
		{
			Sleep (50);
			goto retorno;
		}
	}

	return 0;
}

int __stdcall NewDecryptFileRC4 (char *Inputfile, char *OutPutFile, char *Password2, char *ErrorString)
{
	int ret;

	char Password[1000] = { 0, };

	strncpy (Password, Password2, 998);
	unicodemode = 1;
	ret = interface1 ((__INT32_OR_INT64) "getstatus", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ", (__INT32_OR_INT64) " ");

	if(checkforequal(Inputfile,OutPutFile))
	{
		strcpy (ErrorString, "Input and output file are the same");
		return 1;
	}
	if (ret)
	{
		strcpy (ErrorString, "Already running , call the cancel function to stop execution");
		return 1;
	}

	ret = interface1 ((__INT32_OR_INT64) "newrc4filedecrypt", (__INT32_OR_INT64) Inputfile, (__INT32_OR_INT64) OutPutFile, (__INT32_OR_INT64) Password);

	if (ret)
	{
		strcpy (ErrorString, "Unexpected error");
		return 2;
	}

retorno:
	if (waitmode)
	{
		if (intstatus)
		{
			Sleep (50);
			goto retorno;
		}
	}

	return 0;
}

int __stdcall PauseExecution()
{

	return interface1 ((__INT32_OR_INT64) "pause", (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

}

int __stdcall ResumeExecution()
{

	return interface1 ((__INT32_OR_INT64) "resume", (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

}

int __stdcall CancelExecution()
{

	return interface1 ((__INT32_OR_INT64) "cancel", (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0, (__INT32_OR_INT64) 0);

}

uint getpor_int64_10000 (__int64 max, __int64 fatia)
{

	double maxa;
	double fatiaa;

	maxa = (double) max;
	fatiaa = (double) fatia;

	if (max == 0)
	{
		return 0;
	}

	maxa = ((double) 10000 / maxa * fatiaa);

	return (uint) maxa;

}

int __stdcall internal_progress_z(void)
{
	int ret_arp_;
	
	ret_arp_ = getpor_int64_10000(filesize, bytes_read_z);
	
	if(0 > ret_arp_) return 0;
	
	if(10000 < ret_arp_) return 10000;
		
	return ret_arp_;
}

//finished at 07/December/2020, updated at 13 february 2021 - 15:33