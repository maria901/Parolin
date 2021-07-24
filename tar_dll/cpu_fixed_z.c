
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *                                                                                *
  *      Licensa de C�pia (C) <202*>  <Corpora��o do Trabalho Bin�rio>             *
  *                                                                                *
  *   Este programa � software livre: voc� pode redistribuir isto e/ou modificar   *
  *   isto sobre os termos do GNU Licensa Geral P�blica como publicado pela        *
  *   Funda��o de Software Livre, tanto a vers�o 3 da Licensa, ou                  *
  *   (dependendo da sua op��o) qualquer vers�o posterior.                         *
  *                                                                                *
  *   Este programa � distribu�do na esperan�a que isto vai ser �til,              *
  *   mas SEM QUALQUER GARANTIA; sem at� mesmo a implicada garantia de             *
  *   COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
  *   Licensa Geral P�blica para mais detalhes.                                    *
  *                                                                                *
  *   Voc� deve ter recebido uma c�pia da LICENSA GERAL PUBLICA                    *
  *       e a GNU Licensa P�blica Menor junto com este programa                    *
  *       Se n�o, veja <http://www.gnu.org/licenses/>.                             *
  *                                                                                *
  *   Suporte: https://arsoftware.net.br/binarywork _____________                  *
  *                                                                                *
  *       e-mails direto dos felizes programadores:                                *
  *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
  *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
  *                                                                                *
  *       contato imediato(para uma resposta muita r�pida) WhatsApp                *
  *       (+55)41 9627 1708 - isto est� sempre ligado                              *
  *                                                                                *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif

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

int __stdcall hasSSE2 (void);
int __stdcall hasSSE (void);

char  *decimalparabinarioprintf (uint value);


/**
 * Internal function to retrieve CPU information for both x86
 * and x64
 *
 */
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

char  *getprocessorbrandstring_k (void)
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

	if (ieax < 0x80000004)
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

	if(hasSSE ())
	{
		strcat(fixo, ", SSE");
	}
	if(hasSSE2())
	{
		strcat(fixo, ", SSE2");
	}

final:
	return fixo;

}

int __stdcall getcputype (int *family, int *model, int *stepping)
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

char  *getcpuname_k (void)
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

int __stdcall hasMMX ()
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

int __stdcall hasSSE ()
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

int __stdcall hasSSE2 ()
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

int __stdcall has3DNOW ()
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

int __stdcall has3DNOWExtensions ()
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

int __stdcall IsAMD64 ()
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

int __stdcall hasCMOV ()
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

int __stdcall hasHyperThreading ()
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

int __stdcall hasFPU ()
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

int __stdcall getcpuextendedfeature (int *eisst, int *tm2, int *ci)
{

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

#if 0
int main ()
{

	int iebx = 0;
	int iecx = 0;
	int iedx = 0;
	int ieax = 0;

	getcpuinfo (0, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("Valores eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif

	getcpuinfo (1, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("01 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif
	getcpuinfo (2, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("02 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif
	getcpuinfo (3, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("03 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif
	getcpuinfo (0x80000000, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("0x80000000  eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif

	getcpuinfo (0x80000001, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("81 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif

	getcpuinfo (0x80000002, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("82 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif

	getcpuinfo (0x80000003, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("83 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif
	getcpuinfo (0x80000004, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("84 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif
	getcpuinfo (0x80000005, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("85 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif

	getcpuinfo (0x80000006, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("86 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif
	getcpuinfo (0x80000007, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("87 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);
#endif
	getcpuinfo (0x80000008, &ieax, &iebx, &iecx, &iedx);
#ifdef NPRINTF
	dprintf ("88 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

	dprintf ("Namoe do processador -%s- \n", getprocessorbrandstring ());

	dprintf ("Namoe do processador -%s- \n", getcpuname ());
#endif
	{
		int model;
		int family;
		int stepping;
		int ret;

		ret = getcputype (&family, &model, &stepping);

		if (ret)
		{
#ifdef NPRINTF
			dprintf ("Error getting type of processor \n");
#endif
		}
		else
		{
#ifdef NPRINTF
			dprintf ("Family %d \n", family);
			dprintf ("Model %d \n", model);
			dprintf ("Stepping %d \n", stepping);
#endif
		}

	}

#ifdef NPRINTF
	dprintf ("Valor binarion %s \n", decimalparabinarioprintf (1 << 10));
#endif

	{

		int ss;
		int ci;
		int mt2;

		getcpuextendedfeature (&ss, &mt2, &ci);
	}
#ifdef NPRINTF
	dprintf ("Has MMX %d \n", hasMMX ());
	dprintf ("Has SSE %d \n", hasSSE ());
	dprintf ("Has SSE2 %d \n", hasSSE2 ());
	dprintf ("Has CMOV %d \n", hasCMOV ());
	dprintf ("Has FPU %d \n", hasFPU ());
	dprintf ("Has 3DNOW! %d \n", has3DNOW ());
	dprintf ("Has 3DNOW! extensions  %d \n", has3DNOWExtensions ());
	dprintf ("Has IsAMD64  %d \n", IsAMD64 ());
	dprintf ("Has OShasSSEsupport  %d \n", OShasSSEsupport ());
#endif
	return 0;
}
#endif

/**
 * This function will get some relevant informations about
 * the processor
 *
 * @param the_data_z the string that will receive
 * the information
 *
 * @return 
 *
 */
int __amandacall get_cpu_data_z(char * the_data_z)
{
	static char out_z[300] = {0, };
	
	if(0 == strlen(out_z))
	{
		strcpy(out_z, getprocessorbrandstring_k());
		strcat(out_z, ", "                       );
		strcat(out_z, getcpuname_k()             );
		strcat(out_z, ", "                       );
		strcat(out_z, cpu_speed_z()              );
	}
		
	strcpy(the_data_z, out_z                     );
	return                                       0;
}
