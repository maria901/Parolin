#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif
/*programa exemplo com main */
#include <stdio.h>
#include <windows.h>

#ifndef dprintf
#define dprintf printf
#endif

char *
decimalparabinarioprintf (uint value);


int
getcpuinfo (int aeax, int *oEAX, int *oEBX, int *oECX, int *oEDX)
{
   /*

      com esta funcao é possivel se pegar toda a informacao necessria
      para efetuar qualquer pesqueisa de informacao de processador

    */
   int retvalue = 0;
   int iebx = 0;
   int iecx = 0;
   int iedx = 0;
   int ieax = 0;


   __try
   {


      __asm
      {

	 mov eax, aeax;
	 cpuid;
	 mov ieax, eax;
	 mov iebx, ebx;
	 mov iedx, edx;
	 mov iecx, ecx;

      }

   }
   __except (1)
   {
     // dprintf ("Invalid CPU code \n");
      /*no cpuid available */
      retvalue = 1;
   }



   *oECX = iecx;
   *oEDX = iedx;
   *oEBX = iebx;
   *oEAX = ieax;

   return retvalue;

}


char *
getprocessorbrandstring ()
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
     
  

if(ieax < 0x80000004)
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



 final:
   return fixo;

}

int __stdcall 
getcputype (int *family, int *model, int *stepping)
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

   // aonde estao os valores ?

   /*em eax */


   *stepping = (ieax & 15);

   *model = ieax >> 4;
   *model = (*model & 15);


   *family = ieax >> 8;
   *family = (*family & 15);

   return 0;

}

char *
getcpuname ()
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



int __stdcall 
hasMMX ()
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


int __stdcall
hasSSE ()
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



int __stdcall
hasSSE2 ()
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


int __stdcall
has3DNOW ()
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

int __stdcall
has3DNOWExtensions ()
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


int __stdcall
IsAMD64 ()
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


int __stdcall
hasCMOV ()
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


int __stdcall
hasHyperThreading ()
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



int __stdcall
hasFPU ()
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



int __stdcall
OShasSSEsupport ()
{

__try
   {




__asm _emit 0x0f
__asm _emit 0x56
__asm _emit 0xC0 
//;; orps xmm0, xmm0


   }
   __except (1)
   {
     // dprintf ("Invalid CPU code \n");
      /*no cpuid available */
      return 0 ;
   }

return 1 ;

}








int __stdcall
getcpuextendedfeature (int *eisst, int *tm2, int *ci)
{

   /*
      Enhanced Intel SpeedStep technology. 

      Thermal Monitor 2.

      Context ID.
    */
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

#ifdef NPRINTF

int
main ()
{

   int iebx = 0;
   int iecx = 0;
   int iedx = 0;
   int ieax = 0;

   getcpuinfo (0, &ieax, &iebx, &iecx, &iedx);

   dprintf ("Valores eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx,
	    iedx);


   getcpuinfo (1, &ieax, &iebx, &iecx, &iedx);

   dprintf ("01 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

   getcpuinfo (2, &ieax, &iebx, &iecx, &iedx);

   dprintf ("02 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

   getcpuinfo (3, &ieax, &iebx, &iecx, &iedx);

   dprintf ("03 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

   getcpuinfo (0x80000000, &ieax, &iebx, &iecx, &iedx);

   dprintf ("0x80000000  eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx,
	    iecx, iedx);


   getcpuinfo (0x80000001, &ieax, &iebx, &iecx, &iedx);

   dprintf ("81 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);


   getcpuinfo (0x80000002, &ieax, &iebx, &iecx, &iedx);

   dprintf ("82 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);


   getcpuinfo (0x80000003, &ieax, &iebx, &iecx, &iedx);

   dprintf ("83 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

   getcpuinfo (0x80000004, &ieax, &iebx, &iecx, &iedx);

   dprintf ("84 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

   getcpuinfo (0x80000005, &ieax, &iebx, &iecx, &iedx);

   dprintf ("85 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);


   getcpuinfo (0x80000006, &ieax, &iebx, &iecx, &iedx);

   dprintf ("86 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

   getcpuinfo (0x80000007, &ieax, &iebx, &iecx, &iedx);

   dprintf ("87 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

   getcpuinfo (0x80000008, &ieax, &iebx, &iecx, &iedx);

   dprintf ("88 eax , ebx , ecx ,edx %x %x %x %x \n", ieax, iebx, iecx, iedx);

   dprintf ("Namoe do processador -%s- \n", getprocessorbrandstring ());

   dprintf ("Namoe do processador -%s- \n", getcpuname ());

   {
      int model;
      int family;
      int stepping;
      int ret;

//int getcputype( int *family , int *model , int *stepping)
      ret = getcputype (&family, &model, &stepping);

      if (ret)
	{
	   dprintf ("Error getting type of processor \n");
	}
      else
	{
	   dprintf ("Family %d \n", family);
	   dprintf ("Model %d \n", model);
	   dprintf ("Stepping %d \n", stepping);

	}

   }

// valor da mascara de ecx decimalparabinarioprintf((1<<1))

   dprintf ("Valor binarion %s \n", decimalparabinarioprintf (1 << 10));


   {

      int ss;
      int ci;
      int mt2;


      getcpuextendedfeature (&ss, &mt2, &ci);
   }

dprintf("Has MMX %d \n" , hasMMX());
dprintf("Has SSE %d \n" , hasSSE());
dprintf("Has SSE2 %d \n" , hasSSE2());
dprintf("Has CMOV %d \n" , hasCMOV());
dprintf("Has FPU %d \n" , hasFPU());
dprintf("Has 3DNOW! %d \n" , has3DNOW());
dprintf("Has 3DNOW! extensions  %d \n" , has3DNOWExtensions());
dprintf("Has IsAMD64  %d \n" , IsAMD64());
dprintf("Has OShasSSEsupport  %d \n" , OShasSSEsupport());
   return 0;
/*em materia de processadores , nos terminamos e paramos por aqui
Agora deve trabalhar no teu software  e procurar novos controles e novos 
ferramentas de programacao a serem geradas

E atualizadas
Assim vai poder seguir em frente na utilizacao destes systemas de
compressao e melhoramento de utilizacao de codigos e outros itens
em sequencia

Vamos em frente que ha muito que ser feito ainda


*/
}
#endif
#endif



/*


Com esta rotinas da para
descobrir se é opteron ou Athlon 64 o processador

Somente olhando estes itens da para identificar estes codigos
e suas utilidades

Da para adicionar , se for colocado identifica o processador
Sem risco de problemas

AMD Athlon™ 64 Model 4 0 0 1111b (0Fh) 0100b (04h) xxxxb
AMD Opteron™ Model 5 0 0 1111b (0Fh) 0101b (05h) xxxxb		
*/	
