#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif
/*criacao de codigo de leitura da velocidade do processador*/

/*programa exemplo com main */

#include <stdio.h>
#include <windows.h>


typedef struct _grande
{
   uint high;
   uint low;
}
grande;

#if 0
#ifdef NPRINTF
int
main ()
{




   __try
   {

      printf ("Aqui %s \n", getcpuspeed ());
      printf ("Aqui %s \n", getcpuspeed ());
      printf ("Aqui %s \n", getcpuspeed ());
      printf ("Aqui %s \n", getcpuspeed ());

   }
   __except (1)
   {
      ;
   }

}
#endif
#endif
