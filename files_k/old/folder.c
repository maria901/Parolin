#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif
/*

codigo travado em read only altamente debugado e testado
garantindo assim a sua funcionalidade e estabilidade
15/1/2004 13:12
futuramente , arquivos como este deverao ficar em maquinas a distancia , copiados somente
na hora da utilizacao do programa para fins especificos

*/

/*
daqui para frente todo o desenvolvimento deve seguir estas posicoes
pois aqui esta toda a definicao de itens que deve ser
efetuado em sequencia
sempre utilize dois arquivos para debugar alguma coisa
assim evita atropelos na finalizacao de algum codigo especifico
		
*/

//#define dprintf printf

#ifndef dprintf
#define dprintf printf
#endif

//#define rsptest 1
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

#include "folder.h"

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/*somente definicoes de funcoes*/


int pereira_koci_utf8towide_b(const char *pUTF8, WCHAR *pUSC2, int nUSC2);

int
pegaposicaoinsensitive (char *comando, char *string);
int validatefoldertocreate (char *path);
void removedordeespaconoinicio (char *path);
void removedordeespaconofinal (char *path);
////////////////////////////////////////////////////////////////////////////////////////

int pereira_koci_utf8towide_b(const char *pUTF8, WCHAR *pUSC2, int nUSC2)
{
	return MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, pUSC2, nUSC2);
}

////////////////////////////////////////////////////////////////////////////////////////
int
rspparser (char *instring, char *delimiter, char *returnstring, int comand)
{

   /*

      Codigo completo com teste esta no arquivo parser.c
      cheque o main para ver como usar esta funcao

      if command = 0 , then init parsing
      if comand = 1 retrieve the next item
      if comand = 2 finish execution

    */

   static char *temp = NULL;

   static char *inputstring = NULL;
   char *ptr;

   int ret;
   int i;

   static int posicao = 0;

   if (comand == 0)
     {

/*aqui vai o codigo*/

	if (inputstring != NULL)
	  {
	     free (inputstring);
	     inputstring = NULL;
	  }

	if (temp != NULL)
	  {
	     free (temp);
	     temp = NULL;
	  }

	posicao = 0;
	return 0;
     }

   if (comand == 1)
     {

/*vamos la */

/*
	o truque é escanear o treco e ir ate a posicao que tem o separador
	quando achar o separador , para , copia , e manda brasa na copia		
*/

	if (!strlen (instring))
	  {

	     returnstring = NULL;
	     posicao = 0;
	     return 1;		// invalid input string
	  }

	if (!strlen (delimiter))
	  {
	     returnstring = NULL;
	     posicao = 0;
	     return 2;		// invalid delimiter string
	  }

	if (inputstring != NULL)
	  {
	     free (inputstring);
	     inputstring = NULL;
	  }

	if (temp != NULL)
	  {
	     free (temp);
	     temp = NULL;
	  }

	inputstring = malloc (strlen (instring) * 2);

	if (inputstring == NULL)
	  {
	     return 5;
	  }

	temp = malloc (strlen (instring) * 2);

	if (temp == NULL)
	  {
	     return 5;
	  }

	strcpy (inputstring, instring);

	ptr = inputstring;

	ptr = ptr + posicao;

	ret = pegaposicaoinsensitive (ptr, delimiter);

	if (ret)
	  {
	     ;
	  }
	else
	  {

	     removedordeespaconoinicio (ptr);
	     removedordeespaconofinal (ptr);
	     strcpy (returnstring, ptr);
	     return 0;
	  }

	strcpy (temp, ptr);

	temp[ret - 1] = 0;

	removedordeespaconoinicio (temp);
	removedordeespaconofinal (temp);

	strcpy (returnstring, temp);

	posicao = posicao + ret + (strlen (delimiter) - 1);
	return 3;

     }

   if (inputstring != NULL)
     {
	free (inputstring);
	inputstring = NULL;
     }

   if (temp != NULL)
     {
	free (temp);
	temp = NULL;
     }

   posicao = 0;
   return 4;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int
stripfilenameandpath (char *path, char *onlypath, char *onlyfilename)
{
/*
documentacao

path = path com path e arquivo
onlypath = somente o path
onlyfilename = somente o arquivo sem o path

*/
   int ret;
   int i;
   int p;
   char temp[255];

   char *fixo;
#ifdef WIN32
   const int separator = '\\';
#else
   const int separator = '/';
#endif

   fixo = path;

   if (path == NULL)
     {

	if (onlypath != NULL)
	  {
	     memset (onlypath, 0, 1);
	  }

	if (onlyfilename != NULL)
	  {
	     memset (onlyfilename, 0, 1);
	  }

	return 1;
     }

   ret = strlen (path);

   if (!ret)
     {

	if (onlypath != NULL)
	  {
	     memset (onlypath, 0, 1);
	  }

	if (onlyfilename != NULL)
	  {
	     memset (onlyfilename, 0, 1);
	  }

	return 0;
     }

   for (i = 0; i < ret; i++)
     {

	if (path[i] == separator)
	  {
	     goto continua;
	  }

     }

/*aqui ocorre em caso que o path nao existe ou nao tem definicao de drive*/
   if (onlypath != NULL)
     {
	memset (onlypath, 0, 1);
     }

   if (onlyfilename != NULL)
     {
	strcpy (onlyfilename, path);
     }

   return 0;

   ;
 continua:
   ;

   strcpy (temp, path);

   p = 0;

   for (i = strlen (path); i > -1; i--)
     {

	if (temp[i] == separator)
	  {
	     temp[i + 1] = 0;
	     break;
	  }
	p++;
     }

   p = ret - p;

   fixo += p + 1;

   if (onlypath != NULL)
     {
	strcpy (onlypath, temp);
     }

   if (onlyfilename != NULL)
     {
	strcpy (onlyfilename, fixo);
     }

   return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int
octaltoint (char *p)
{

   /*
      it will convert a string with a octal number to a int                
    */
   int result = 0;
   char c;

   int ret;

   ret = strlen (p);


   if (!ret)
     {
	return 0;
     }

   while (ret--)
     {
	c = *p++;
	if (c == ' ')
	   continue;
	if (c == 0)
	   break;
	result = result * 8 + (c - '0');
     }
   return result;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
inttooctal (uint value, int numberofitens)
{
/*
	it will convert a int value to a octal string
	with the number of 0 as definied in numberofitens	
*/
   static char fixo[255];
   static char fixo2[255];
   static char final[255];

   int ret;


   memset (fixo2, 0, 254);
   memset (final, 0, 254);
   memset (fixo, 0, 254);

   // int sprintf(char *s, const char *format, ...); 
   sprintf (fixo, "%o", value);

   ret = strlen (fixo);

 retorno:

   if (ret < numberofitens)
     {

	strcat (fixo2, "0");

	ret = ret + 1;
	goto retorno;
     }

   strcpy (final, fixo2);
   strcat (final, fixo);

   return final;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int
getbits (uint value, uint bit)
{
/*pega o valor do bit na posicao definida em bit*/
   int ret;
   int mask;

   if (bit > 31)
     {
	return 0;
     }

   mask = 1 << bit;
   ret = mask & value;

   if (ret)
     {
	return 1;
     }

   return 0;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int
setbits (uint value, uint bit, uint bitvalue)
{
/*seta o bit na posicao definida em bit
limitado a 32 bits
*/
   int mask;

   if (bit > 31)
     {
	return value;
     }

   mask = 1 << bit;

   if (bitvalue == 0)
     {

	if (getbits (value, bit) == 1)
	  {

	     value = ~value;

	     value = value | mask;

	     value = ~value;

	     return value;
	  }

	return value;

     }
   else
     {

	return value | mask;
     }

}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



uint
binarioparadecimal (char *binval)
{
/*
	converte string binaria para decimal		
*/
   uint ret;
   uint fatia;
   uint intvalue;

   uint i = 0;
   intvalue = 0;

   ret = strlen (binval);

   for (; ret > 0; ret--)
     {
	fatia = binval[ret - 1] - 48;

	if (fatia != 0 && fatia != 1)
	  {
	     return 0;
	  }

	intvalue = intvalue + (fatia * (1 << i));
	i++;
     }

   return intvalue;

}


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
char *
decimalparabinarioprintf (uint value)
{

/*converte decimal para uma string 
binaria mas formata para impressao*/
   int i;
   uint mask;

   static char fixo[255];

   memset (fixo, 0, 254);

   for (i = 31; i > -1; i--)
     {

	mask = (1 << i);

	if (mask & value)
	  {
	     strcat (fixo, "1");

	     if ((i % 4 == 0) && i != 0)
	       {
		  strcat (fixo, "-");
	       }

	  }
	else
	  {
	     strcat (fixo, "0");
	     if ((i % 4 == 0) && i != 0)
	       {
		  strcat (fixo, "-");
	       }
	  }


     }

   return fixo;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////




char *
decimalparabinario (uint value)
{

/*
	converte um valor decimal para um string static em binario		
*/
   int i;
   uint mask;

   static char fixo[255];

   memset (fixo, 0, 254);

   for (i = 31; i > -1; i--)
     {

	mask = (1 << i);

	if (mask & value)
	  {
	     strcat (fixo, "1");
	  }
	else
	  {
	     strcat (fixo, "0");
	  }


     }

   return fixo;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/*funcao pegaultimocaracter*/

char
pegaultimocaracter (char *path)
{
   /*pega o ultimo caracter da string */
   int ret;

   ret = strlen (path);
   if (ret)
     {
	return path[ret - 1];
     }

   return 0;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

/*funcao de timer para debug*/

float
inittimer (uint comando)
{

/*

#include <timer.h>
	inittimer(0);
	Sleep(1234);
	Sleep(25);
	
	dprintf("Clock %f \n ", inittimer(1));
	*/

   static uint clock1;
   static uint clock2;

   if (comando == 0)
     {
	clock1 = clock ();
     }
   else
     {

	clock2 = clock ();

	return ((float) clock2 - (float) clock1);

     }

   return 0;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



int
rspgetdrivetype (char *path1)
{

   /*
      pega o drive pelo tipo

      DRIVE_UNKNOWN The drive type cannot be determined. 
      DRIVE_NO_ROOT_DIR The root directory does not exist. 
      DRIVE_REMOVABLE The disk can be removed from the drive. 
      DRIVE_FIXED The disk cannot be removed from the drive. 
      DRIVE_REMOTE The drive is a remote (network) drive. 
      DRIVE_CDROM The drive is a CD-ROM drive. 
      DRIVE_RAMDISK The drive is a RAM disk. 

    */



   static int rico;
   static char path[255];

   if (!strlen (path1))
     {
	return -1;
     }


   strcpy (path, path1);


   if (strlen (path) < 3)
     {


	return -1;
     }

   path[3] = 0;

   if (tolower (path[0]) < 'a')
     {
	return -1;
     }

   if (tolower (path[0]) > 'z')
     {
	return -1;
     }

   if (path[1] != ':')
     {
	return -1;
     }

   if (path[2] != '\\')
     {
	return -1;
     }

   return GetDriveType (path);

}



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
rspgetcomputername ()
{
   static int rico = 255;
   static char temp[255];
   memset (temp, 0, 254);
   GetComputerName ((LPTSTR) temp, (LPDWORD) & rico);
   return temp;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int
rspsetcurrentdirectory (char *path)
{
/*
seta o diretorio corrente
retorna 0 se der certo
retorna 1 se der errado

*/

   int ret;
//If the function succeeds, the return value is nonzero.
   ret = SetCurrentDirectory (path);

   if (ret)
     {
	return 0;
     }

   return 1;


}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
rspgetcurrentdirectory ()
{
   /*
      use o e ao inves de k                
    */
/*pega o diretorio corente*/
   static char temp[255];
   memset (temp, 0, 254);
   GetCurrentDirectory (255, temp);
   return temp;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
rspgetsystemdirectory ()
{

   static char temp[255];
   memset (temp, 0, 254);
   GetSystemDirectory (temp, 255);
   return temp;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

char *
rspgetwindowsdirectory ()
{

   static char temp[255];

   memset (temp, 0, 254);
   GetWindowsDirectory (temp, 255);

   return temp;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
rspgettemppath ()
{
   /*
      pega o diretorio temp                
    */

   static char temp[255];

   memset (temp, 0, 254);
   GetTempPath (255, temp);

   return temp;

}



////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

#ifdef rsptest
#ifdef NPRINTF
int
main ()
{
/*

DWORD GetFullPathName(
  LPCTSTR lpFileName,  // pointer to name of file to find path for
  DWORD nBufferLength, // size, in characters, of path buffer
  LPTSTR lpBuffer,     // pointer to path buffer
  LPTSTR *lpFilePart   // pointer to filename in path
);


*/

   char path[255];
   char *ifile;

   GetFullPathName ("c:\\back2", 255, path, &ifile);

   printf ("path e file %s %s \n", path, ifile);
   printf ("Linha %d %s %s \n", __LINE__, __TIME__, __FILE__);

}

#endif
#endif


////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
/*funcao de pegar tamanho de arquivo*/

int
getfilesize (char *infile)
{

   uint ret;

   FILE *myfile;

   if ((myfile = fopen (infile, "rb")) == NULL)
     {
	//dprintf ("The file 'data' was not opened\n");
	return 0;
     }
   else
     {
	//dprintf ("The file 'data' was opened\n");
     }

   ret = fseek (myfile, 0, SEEK_END);

   ret = ftell (myfile);

   // dprintf ("tamanho do arquivo %d\n ", ret);

   fclose (myfile);

   // printf ("Tamanho do arquivo %s  %d \n", infile, ret);

   return ret;


}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int
getfilesize_utf8 (char *infile_utf8)
{

   uint ret;

   FILE *myfile;
   {
	   
	   WCHAR wide_temp_k[300]={0};
	   pereira_koci_utf8towide_b(infile_utf8, wide_temp_k, 300);
   if ((myfile = _wfopen (wide_temp_k, L"rb")) == NULL)
     {
	//dprintf ("The file 'data' was not opened\n");
	return 0;
     }
   else
     {
	//dprintf ("The file 'data' was opened\n");
     }
   }

   
   ret = fseek (myfile, 0, SEEK_END);

   ret = ftell (myfile);

   // dprintf ("tamanho do arquivo %d\n ", ret);

   fclose (myfile);

   // printf ("Tamanho do arquivo %s  %d \n", infile, ret);

   return ret;


}////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

__int64
getfilesize_utf8_large_file_support_k (char *infile_utf8)
{

   __int64 ret;

   FILE *myfile;
   {
	   
	   WCHAR wide_temp_k[300]={0};
	   pereira_koci_utf8towide_b(infile_utf8, wide_temp_k, 300);
   if ((myfile = _wfopen (wide_temp_k, L"rb")) == NULL)
     {
	//dprintf ("The file 'data' was not opened\n");
	return 0;
     }
   else
     {
	//dprintf ("The file 'data' was opened\n");
     }
   }
   
   ret = _fseeki64 (myfile, 0, SEEK_END);

   ret = _ftelli64 (myfile);

   // dprintf ("tamanho do arquivo %d\n ", ret);

   fclose (myfile);

   // printf ("Tamanho do arquivo %s  %d \n", infile, ret);

   return ret;

}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


/*
 * aqui o codigo recebe o maximo , entra com uma porcentagem e
 * 
 * 
 * 
 * pega o valor referente a porcentagem passad
 * 
 * max = 10000 por = 70 result =
 * 
 */
uint
getval (int max, uint por)
{

   // a formula aqui é
   // max / 100 * por

   uint ret;
   double maxa;
   double porr;

   maxa = (double) max;
   porr = (double) por;

   maxa = (maxa / 100) * porr;

   return (uint) maxa;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////



/*
 * a formula aqui é (fatia/porcentagem) * 100 o resultado é sempre uma
 * porcentagem
 * 
 * por = 70 fatia = 10000 result = 142
 * 
 * basicamente é para saber o maximo a partir da fatria e da porcentagem
 * sera pouco utilizada esta funcao 
 */
uint				// pegar o maximo a partir da porcentagem
getmax (int por, uint fatia)
{

   uint ret;
   float a;
   float b;

   a = (float) por;
   b = (float) fatia;

   if (por == 0)
     {
	return 0;
     }

   a = (b / a) * (float) 100;



   return (uint) a;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


/*funcao de porcentagem*/

/*

a formula aqui é (100/max * fatia)
aqui é para saber a porcentagem referente ao valor passado em relacao ao maximo

max = 10000
fatia = 5000

*/
uint
getpor (int max, uint fatia)
{
/*

2/27/2004 12:13PM modificacao para evitar divisao por 0

*/

   double maxa;
   double fatiaa;

   maxa = (double) max;
   fatiaa = (double) fatia;

   if (max == 0 || fatia == 0)
     {
	return 0;
     }

   maxa = ((double) 100 / maxa * fatiaa);

   return (uint) maxa;

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


int
contastringinsensitive (char *comando, char *string)
{
/*
* retorna a contagem de strings achada 15/1/2004 12:52
*/


   char intcomando[1000];
   int ret;
   int sizeret;
   int i;
   int b;
   int c;
   int d;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

   c = 0;
   d = 0;

   strcpy (intcomando, comando);

   ret = strlen (intcomando);

   sizeret = strlen (string);


   if (sizeret > ret)
     {
	return 0;
     }


   if (ret && sizeret)
     {
/*
* aqui vai o codigo 
*/
	for (i = 0; i < ret; i++)
	  {
	     c = i;
	     if (tolower (intcomando[i]) == tolower (string[0]))
	       {
// dprintf ("Ta escaneando 1 \n");

		  for (b = 0; b < sizeret; b++)
		    {
// dprintf ("Ta escaneando 2 \n");
		       if ((tolower (intcomando[i + b]) !=
			    tolower (string[b])))
			 {
			    goto continua;
			 }

		    }
		  d++;

	       }
	     ;
	   continua:
	     ;

	  }

	return d;

     }
   else
     {
	return d;
     }
   ;

   return d;
   ;

   ;
   return d;
}

int
contastringsensitive (char *comando, char *string)
{

/*
* * retorna a contagem de strings achada 15/1/2004 12:52
*/


   char intcomando[1000];
   int ret;
   int sizeret;
   int i;
   int b;
   int c;
   int d;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


   c = 0;
   d = 0;

   strcpy (intcomando, comando);

   ret = strlen (intcomando);

   sizeret = strlen (string);

   if (sizeret > ret)
     {
	return 0;
     }
   if (ret && sizeret)
     {
/*
* aqui vai o codigo 
*/
	for (i = 0; i < ret; i++)
	  {
	     c = i;
	     if ((intcomando[i]) == (string[0]))
	       {
// dprintf ("Ta escaneando 1 \n");

		  for (b = 0; b < sizeret; b++)
		    {
// dprintf ("Ta escaneando 2 \n");
		       if (((intcomando[i + b]) != (string[b])))
			 {
			    goto continua;
			 }

		    }
		  d++;
	       }
	     ;
	   continua:
	     ;

	  }

	return d;

     }
   else
     {
	return d;
     }
   ;

   return d;
   ;

   ;
   return d;



}

/******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
******************************************************************************************/


int
pegaposicaoinsensitive (char *comando, char *string)
{
/*
* retorna a posicao em que achar o item ou 0 se nao achar
*/


   char intcomando[1000];
   int ret;
   int sizeret;
   int i;
   int b;
   int c;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

   c = 0;

   strcpy (intcomando, comando);

   ret = strlen (intcomando);

   sizeret = strlen (string);

   if (sizeret > ret)
     {
	return 0;
     }
   if (ret && sizeret)
     {
/*
* aqui vai o codigo 
*/
	for (i = 0; i < ret; i++)
	  {
	     c = i;
	     if (tolower (intcomando[i]) == tolower (string[0]))
	       {
// dprintf ("Ta escaneando 1 \n");

		  for (b = 0; b < sizeret; b++)
		    {
// dprintf ("Ta escaneando 2 \n");
		       if ((tolower (intcomando[i + b]) !=
			    tolower (string[b])))
			 {
			    goto continua;
			 }

		    }
		  goto achou;
	       }
	     ;
	   continua:
	     ;

	  }

	return 0;

     }
   else
     {
	return 0;
     }
   ;

   return 0;
   ;
 achou:
   ;
   return c + 1;
}

int
pegaposicaosensitive (char *comando, char *string)
{

/*
* retorna a posicao que achou ou 0 se nao achar 15/1/2004 12:51
*/


   char intcomando[1000];
   int ret;
   int sizeret;
   int i;
   int b;
   int c;
// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


   c = 0;
   strcpy (intcomando, comando);

   ret = strlen (intcomando);

   sizeret = strlen (string);

   if (sizeret > ret)
     {
	return 0;
     }

   if (ret && sizeret)
     {
/*
* aqui vai o codigo 
*/
	for (i = 0; i < ret; i++)
	  {
	     c = i;
	     if ((intcomando[i]) == (string[0]))
	       {
// dprintf ("Ta escaneando 1 \n");

		  for (b = 0; b < sizeret; b++)
		    {
// dprintf ("Ta escaneando 2 \n");
		       if (((intcomando[i + b]) != (string[b])))
			 {
			    goto continua;
			 }

		    }
		  goto achou;
	       }
	     ;
	   continua:
	     ;

	  }

	return 0;

     }
   else
     {
	return 0;
     }
   ;

   return 0;
   ;
 achou:
   ;
   return c + 1;



}

int
procuradordestringsensitive (char *comando, char *string)
{

/*procura a string , retorna 1 se achar ou 0 se nao*/

   char intcomando[1000];
   int ret;
   int sizeret;
   int i;
   int b;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

   strcpy (intcomando, comando);

   ret = strlen (intcomando);

   sizeret = strlen (string);

   if (sizeret > ret)
     {
	return 0;
     }
   if (ret && sizeret)
     {
/*
* aqui vai o codigo 
*/
	for (i = 0; i < ret; i++)
	  {

	     if ((intcomando[i]) == (string[0]))
	       {
// dprintf ("Ta escaneando 1 \n");

		  for (b = 0; b < sizeret; b++)
		    {
// dprintf ("Ta escaneando 2 \n");
		       if (((intcomando[i + b]) != (string[b])))
			 {
			    goto continua;
			 }

		    }
		  goto achou;
	       }
	     ;
	   continua:
	     ;

	  }

	return 0;

     }
   else
     {
	return 0;
     }
   ;

   return 0;
   ;
 achou:
   ;
   return 1;


}

int
procuradordestringinsensitive (char *comando, char *string)
{

/*procura a string , retorna 1 se achar ou 0 se nao*/

   char intcomando[1000];
   int ret;
   int sizeret;
   int i;
   int b;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

   strcpy (intcomando, comando);

   ret = strlen (intcomando);

   sizeret = strlen (string);
   if (sizeret > ret)
     {
	return 0;
     }

   if (ret && sizeret)
     {
/*
* aqui vai o codigo 
*/
	for (i = 0; i < ret; i++)
	  {

	     if (tolower (intcomando[i]) == tolower (string[0]))
	       {


		  for (b = 0; b < sizeret; b++)
		    {

		       if ((tolower (intcomando[i + b]) !=
			    tolower (string[b])))
			 {
			    goto continua;
			 }

		    }
		  goto achou;
	       }
	     ;
	   continua:
	     ;

	  }

	return 0;

     }
   else
     {
	return 0;
     }
   ;

   return 0;
   ;
 achou:
   ;
   return 1;


}

/******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
******************************************************************************************/


/*
* checa o tamanho maximo da string
*/
int
checkmaxsize (char *comando)
{

   if (strlen (comando) > 490)
     {
	return 1;

     }
   else
     {
	return 0;
     }

}


void
stripspace (char *intcomando)
{

/*remover de qualquer espao na string*/


   int ret;

   int i;

   char saida[1000];
   int deslocador = 0;

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


   memset (saida, 0, 999);

   ret = strlen (intcomando);



   if (ret)
     {
/*
* aqui vai o codigo 
*/
	for (i = 0; i < ret; i++)
	  {

	     if (intcomando[i] != ' ')
	       {

		  saida[deslocador] = intcomando[i];
		  deslocador++;
	       }

	  }





     }

   strcpy (intcomando, saida);


}









/******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
*******************************************************************************************
******************************************************************************************/



void
trocadordebackslashtras (char *path)
{
/*
* troca o backslash de / para \
* 
*/
   int ret;

   char aqui;

   int i;

   ret = strlen (path);

   if (ret)
     {


	for (i = 0; i < ret; i++)
	  {

	     aqui = path[i];
	     if (aqui == '/')
	       {
		  path[i] = '\\';
	       }

	  }

     }

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
trocadordebackslashfrente (char *path)
{
/*
* troca o backslash de \ para /
* 
*/
   int ret;

   char aqui;

   int i;

   ret = strlen (path);

   if (ret)
     {
/*
* executa 
*/

	for (i = 0; i < ret; i++)
	  {

	     aqui = path[i];
	     if (aqui == '\\')
	       {
		  path[i] = '/';
	       }

	  }

     }

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
adicionadordebackslashtras (char *path)
{
/*
* adiciona o character \ no final da string 
*/
   int ret;

   ret = strlen (path);

   if (ret)
     {

	if (path[(ret - 1)] != '\\')
	  {
	     path[ret] = '\\';
	     path[ret + 1] = 0;
	  }

     }

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
adicionadordebackslashfrente (char *path)
{
/*
* adiciona o character / no final da string 
*/
   int ret;
   ret = strlen (path);


   if (ret)
     {

	if (path[(ret - 1)] != '/')
	  {
	     path[ret] = '/';
	     path[ret + 1] = 0;
	  }

     }


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
removedordeespaconofinal (char *path)
{
/*
* vai remover os itens no final que sao ' ' e quantos mais tiver
*/

   int ret;

 inicio:

   ret = strlen (path);

   if (ret)
     {

	if (path[(ret - 1)] == ' ')
	  {

	     path[(ret - 1)] = 0;
	     goto inicio;

	  }
     }


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
removedordecaracternofinal (char *path, char caracter)
{
/*
* vai remover os itens no final que sao o caracter
mas vai retirar um unico item

*/

   int ret;



   ret = strlen (path);

   if (ret)
     {

	if (path[(ret - 1)] == caracter)
	  {

	     path[(ret - 1)] = 0;
// goto inicio;

	  }
     }


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////



void
removedordecaracternoinicio (char *path, char caracter)
{

/*vai remover no inicio os caracters que sao o caracter
mas tira somente um unico item*/
   int ret;
   char *ptr;

   char *ptrdesloca;

   ptrdesloca = path;
   ret = strlen (path);

   if (ret)
     {
	ptr = malloc (ret + 1);

	memset (ptr, 0, ret + 1);

	if (*ptrdesloca == caracter)
	  {
// assim vai tirar um unico item
	     ptrdesloca++;
	  }


	strcpy (ptr, ptrdesloca);
	memset (path, 0, ret);
	strcpy (path, ptr);

	free (ptr);
     }
}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
removedordeespaconoinicio (char *path)
{

/*retira o caracter ' ' no inicio , e quantos mais tiver em sequencia*/

   int ret;
   char *ptr;

   char *ptrdesloca;

   ptrdesloca = path;
   ret = strlen (path);

   if (ret)
     {
	ptr = malloc (ret + 1);

	memset (ptr, 0, ret + 1);

	while (*ptrdesloca == ' ')
	  {

	     ptrdesloca++;
	  }


	strcpy (ptr, ptrdesloca);
	memset (path, 0, ret);
	strcpy (path, ptr);

	free (ptr);
     }
}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
changecharacter (char *path, char itemtosearch, char finalcharacter)
{
/*
* changecharacter , funcao para trocar caracteres numa string
* itemtosearch , caracter para ser procurado e trocado finalcharacter
* , character final a ser usado 
*/



   int ret;

   ret = strlen (path);

   if (ret)
     {
	int i;
	for (i = 0; i < ret; i++)
	  {

	     if (path[i] == itemtosearch)
	       {
		  path[i] = finalcharacter;
	       }

	  }

     }

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


int
countitens (char *comand, char item)
{
/*

contador de itens , deve ser usada a funcao
contastringsensitive ou
contastringinsensitive , porque sao mais novas 

*/

   int ret;
   int i;
   int counter;

   counter = 0;

   ret = strlen (comand);

   if (!ret)
     {
	return 1;

     }

   for (i = 0; i < ret; i++)
     {
	if (comand[i] == item)
	  {
	     counter++;
	  }

     }

   return counter;

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
strtolower (char *path)
{
/*
* funcao para passar um tolower na string inteira
*/
   int ret;
   int i;

   ret = strlen (path);

   if (ret)
     {
	for (i = 0; i < ret; i++)
	  {

	     path[i] = tolower (path[i]);


	  }

	return;

     }


}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


void
strtoupper (char *path)
{
/*
* funcao para passar um toupper na string inteira
*/
   int ret;
   int i;

   ret = strlen (path);

   if (ret)
     {
	for (i = 0; i < ret; i++)
	  {

	     path[i] = toupper (path[i]);


	  }

	return;

     }


}



// /////////////////////

// #define dprintf printf


/*
* declaracoes 
 */

void removedordeespaconofinal (char *path);

int contastringinsensitive (char *comando, char *string);

/*
* aprovado para uso interno
*/
int
testdirectory (char *path)
{
/*

Esta funcao nao deve ser usada , ja que a funcao pathexist e ispathfolder
usam uma diferente implementacao desta funcao
e mais profissional
Deve ser usada somente se as outras nao funcionarem , mas felizmente funcionam
Retorna 1 se der certo e o path existir , retorna 0 se nao for
valido o path
15/1/2004 13:03
*/
   int ret;
   static char fixo[255];
   int ret2 = 0;

   ret = GetCurrentDirectory (255, fixo);

   ret2 = SetCurrentDirectory (path);

   ret = SetCurrentDirectory (fixo);

   if (ret2)
     {
	return 1;
     }
   else
     {
	return 0;
     }

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


/*
* aprovado , para uso interno
*/
int
createtestfilename (char *path1)
{
/*
* 
* retorna 1 se der para criar , retorna 0 se nao der
o arquivo é deletado na finalizacao

* 
*/
   int ret;
   static char fixo[255];

   static char path[255];


   strcpy (path, path1);



   removedordeespaconofinal (path);

   ret = strlen (path);

   if (path[ret - 1] != '\\')
     {

	path[ret] = '\\';
	path[ret + 1] = 0;

     }

   memset (fixo, 0, 254);
   ret = GetTempFileName (path, "rsp", 0, fixo);
   if (ret == 0)
     {

	return 0;
     }

   else
     {
	DeleteFile (fixo);
	return 1;
     }


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

/*
* aprovado 
*/
int
pathexists (char *path)
{
/*
* 
* retorna 1 se existir um diretorio ou arquivo no destino retorna 0 se 
* der erro ou o path ou arquivo nao existir
15/1/2004 13:03
* 
*/

   char x[300];
   int ret;

   strcpy (x, path);

   ret = strlen (x);


   if (!ret)
     {
	return 0;
     }

   if (ret < 2)
     {
	return 0;
     }


   if (x[0] == '\\' && x[1] == '\\')
     {

	goto UNC;
     }



   if (tolower (x[0]) < 'a')
     {
	return 0;

     }

   if (tolower (x[0]) > 'z')
     {
	return 0;

     }

   if (tolower (x[1]) != ':')
     {
	return 0;
     }









 UNC:

   if (0xffffffff != GetFileAttributes (x))
     {

	return 1;
     }
   else
     {
	return 0;
     }

}


// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

int
ispathreadonly (char *path)
{
/*
* retorna -1 se o path for invalido e der erro retorna 1 se for read
* only retorna 0 se nao for 
15/1/2004 13:04
*/

   char x[300];
   int ret;

   strcpy (x, path);

   ret = strlen (x);

   if (!ret)
     {
	return -1;
     }

   if (ret < 2)
     {
	return -1;
     }

   if (x[0] == '\\' && x[1] == '\\')
     {

	goto UNC;
     }



   if (tolower (x[0]) < 'a')
     {
	return -1;

     }

   if (tolower (x[0]) > 'z')
     {
	return -1;

     }

   if (tolower (x[1]) != ':')
     {
	return -1;
     }

 UNC:

   ret = GetFileAttributes (x);
   if (0xffffffff != ret)
     {

	if (FILE_ATTRIBUTE_DIRECTORY & ret)
	  {

	     if (createtestfilename (x))
	       {
		  return 0;
	       }
	     else
	       {
		  return 1;
	       }
	  }
	else
	  {
	     return -1;
	  }

     }
   else
     {


	return -1;
     }



}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


/*
* aprovado 
*/
int
ispathfolder (char *path)
{
/*
* retorna 1 se o path existir e for diretorio , 0 se for arquivo ou invalido path
*/
/*15/1/2004 13:05*/

   char x[300];
   int ret;
   strcpy (x, path);
   ret = strlen (x);

   if (!ret)
     {
	return 0;
     }

   if (ret < 2)
     {
	return 0;
     }

   if (x[0] == '\\' && x[1] == '\\')
     {

	goto UNC;
     }

   if (tolower (x[0]) < 'a')
     {
	return 0;

     }

   if (tolower (x[0]) > 'z')
     {
	return 0;

     }

   if (tolower (x[1]) != ':')
     {
	return 0;
     }


 UNC:

   ret = GetFileAttributes (x);

   if (0xffffffff != ret)
     {

	if (ret & (FILE_ATTRIBUTE_DIRECTORY))
	  {

	     return 1;
	  }
	else
	  {
	     return 0;
	  }

     }
   else
     {
	return 0;
     }

}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


int
ispathfile (char *path)
{
/*
* retorna 1 se for arquivo e 0 se der erro ou for path ou for invalido
*/

   char x[300];
   int ret;
   strcpy (x, path);
   ret = strlen (x);

   if (!ret)
     {
	return 0;
     }

   if (ret < 2)
     {
	return 0;
     }

   if (x[0] == '\\' && x[1] == '\\')
     {

	goto UNC;
     }

   if (tolower (x[0]) < 'a')
     {
	return 0;

     }

   if (tolower (x[0]) > 'z')
     {
	return 0;

     }

   if (tolower (x[1]) != ':')
     {
	return 0;
     }

 UNC:

   ret = GetFileAttributes (x);


   if (0xffffffff != ret)
     {

	if (ret & (FILE_ATTRIBUTE_DIRECTORY))
	  {

	     return 0;
	  }
	else
	  {
	     return 1;
	  }

     }
   else
     {
	return 0;
     }


}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////


void
geterrorstringrspmakedir (int errorcode, char *path)
{
/*

esta funcao pega uma string referente a utilizacao da 
funcao rsomakedir

com esta descricao é possivel saber qual foi o erro que 
impossibilitou a cracao do diretorio
15/1/2004 13:06


*/
   switch (errorcode)
     {
     case 0:
	strcpy (path, "No error\0");
	return;
     case 1:
	strcpy (path, "Path is empty");
	return;
     case 2:
	strcpy (path, "Path has invalid characters");
	return;
     case 3:
	strcpy (path,
		"The path is a file , thus it cannot be created in the destination as a path");
	return;
     case 4:
	strcpy (path,
		"Unable to create the destination directory , possible drive invalid or read only ");
	return;
     case 5:
	strcpy (path,
		"The UNC path is a file , thus it cannot be created in the destination as a path");
	return;
     case 6:
	strcpy (path,
		"Unable to create the destination directory , possible UNC path invalid or disconnected or read only ");
	return;

     case 7:
	strcpy (path,
		"You need at least two characters to a path like this a: ");
	return;
// ///

     case 8:
	strcpy (path, "Too many characters : on the path ");
	return;
     case 9:
	strcpy (path, "Invalid character ? on the path ");
	return;
     case 10:
	strcpy (path, "Invalid character * on the path ");
	return;
     case 11:
	strcpy (path, "Invalid character < on the path ");
	return;
     case 12:
	strcpy (path, "Invalid character > on the path ");
	return;
     case 13:
	strcpy (path, "Invalid character / on the path ");
	return;
     case 14:
	strcpy (path, "Invalid character \" on the path ");
	return;
     case 15:
	strcpy (path, "Path is read only ");
	return;
     case 16:
	strcpy (path, "Invalid character | on the path ");
	return;
//aqui vai ais um
     default:
	strcpy (path,
		"Unexpected return value to the function to create directories");
	return;
     }



}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////



int
rspmakedirUNIX (char *destination, char *path)
{
/*

funcao que cria diretorios , com suporte para UNIX
Requer destination alem do path a ser criado
A nao ser que o path ja seja completo

Se for completo destination = NULL

tem suporte para verificacao de qualquer possivel erro
antes da criacao do diretorio , evitando assim bugs inesperados 
na utilizacao da rotina de criacao e validcao de diretorio
espero nunca mais na vida ter que perder tempo
com esta funcao
evitando assim inumeros atropelos , com certeza

o valor de retorno pode ser usado para gerar uma string
com a descricao do erro ocorrido

15/1/2004 13:09		
*/
   int ret2;
   int ret;
   int i;
   char temp[500];


   if (destination != NULL)
     {
	strcpy (temp, destination);

	adicionadordebackslashtras (temp);
	trocadordebackslashtras (temp);

	strcat (temp, path);
     }
   else
     {
	strcpy (temp, path);
     }
   trocadordebackslashtras (temp);

   ret = strlen (temp);
   if (!ret)
     {
	return 1;
     }

   if (ret < 2)
     {
	return 7;
     }
// aqui verifica isto



/*por isto que tem que debugar estas coisas bem , um erro
invalida tudo e complica o meio de campo*/


// 

   if (ret != 3)
     {

	if (temp[ret - 1] == '\\')
	  {

	     temp[ret - 1] = 0;
	  }

     }


   ret = strlen (temp);
   if (temp[0] == '\\' && temp[1] == '\\')
     {
	goto unc;
     }

   if (tolower (temp[0]) < 'a' || tolower (temp[0]) > 'z' || temp[1] != ':')
     {
	return 2;		// path has invalid characters
     }



   if (ret)
     {

	for (i = 0; i < ret; i++)
	  {

	     if (temp[i] == '\\')
	       {
		  char temp1;
		  temp1 = temp[i + 1];
		  temp[i + 1] = 0;
// dprintf ("Criando diretorio -%s- \n", temp);
		  CreateDirectory (temp, NULL);
		  temp[i + 1] = temp1;
	       }


	  }

// dprintf ("Criando diretorio final -%s- \n", temp);
	CreateDirectory (temp, NULL);


     }
   //dprintf ("1Qual o path que vai checar ? -%s- \n", path);
   //dprintf ("2Qual o path que vai checar ? -%s- \n", temp);
   if (ispathfolder (temp))
     {

	if (!ispathreadonly (temp))
	  {
	     return 0;		// ok , nao é read only
	  }
	else
	  {
	     return 15;		// path is read only or unavailable  
	  }


     }
   else
     {
// dprintf ("Qual o path que vai checar ? -%s- \n", path);
	if (ispathfile (temp))
	  {
	     return 3;
	  }
	else
	  {
	     return 4;
	  }

     }

   return 0;
 unc:

   if (ret)
     {

	for (i = 0; i < ret; i++)
	  {

	     if (i == 0)
	       {
		  i = 2;
	       }

	     if (temp[i] == '\\')
	       {
		  char temp1;
		  temp1 = temp[i + 1];
		  temp[i + 1] = 0;

// dprintf ("Criando diretorio UNC -%s- \n", temp);

		  CreateDirectory (temp, NULL);

		  temp[i + 1] = temp1;
	       }


	  }
// dprintf ("Criando diretorio UNC final -%s- \n", temp);
	CreateDirectory (temp, NULL);

     }
// dprintf ("Qual o path que vai checar ? -%s- \n", path);
   if (ispathfolder (temp))
     {

	if (!ispathreadonly (temp))
	  {
	     return 0;		// ok , nao é read only
	  }
	else
	  {
	     return 15;		// path is read only or unavailable  
	  }

	return 0;
     }
   else
     {
// dprintf ("Qual o path que vai checar ? -%s- \n", path);
	if (ispathfile (temp))
	  {
	     return 5;
	  }
	else
	  {
	     return 6;
	  }

     }

   return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int
rspmakedir (char *path)
{
/*

funcao que cria diretorios

tem suporte para verificacao de qualquer possivel erro
antes da criacao do diretorio , evitando assim bugs inesperados 
na utilizacao da rotina de criacao e validcao de diretorio
espero nunca mais na vida ter que perder tempo
com esta funcao
evitando assim inumeros atropelos , com certeza

o valor de retorno pode ser usado para gerar uma string
com a descricao do erro ocorrido

15/1/2004 13:09		
*/
   int ret2;
   int ret;
   int i;
   char temp[500];
   strcpy (temp, path);

   ret = strlen (temp);
   if (!ret)
     {
	return 1;
     }

   if (ret < 2)
     {
	return 7;
     }
// aqui verifica isto

   ret2 = validatefoldertocreate (temp);


   if (ret2)
     {
// aqui efetua a mapeacao

	switch (ret2)
	  {
	  case 1:
	     return 8;
	  case 2:
	     return 13;
	  case 3:
	     return 10;
	  case 4:
	     return 9;
	  case 5:
	     return 11;
	  case 6:
	     return 12;
	  case 7:
	     return 14;
	  case 8:
	     return 16;
	  }

/*por isto que tem que debugar estas coisas bem , um erro
invalida tudo e complica o meio de campo*/

     }
// 

   if (ret != 3)
     {

	if (temp[ret - 1] == '\\')
	  {

	     temp[ret - 1] = 0;
	  }

     }


   ret = strlen (temp);
   if (temp[0] == '\\' && temp[1] == '\\')
     {
	goto unc;
     }

   if (tolower (temp[0]) < 'a' || tolower (temp[0]) > 'z' || temp[1] != ':')
     {
	return 2;		// path has invalid characters
     }



   if (ret)
     {

	for (i = 0; i < ret; i++)
	  {

	     if (temp[i] == '\\')
	       {
		  char temp1;
		  temp1 = temp[i + 1];
		  temp[i + 1] = 0;
// dprintf ("Criando diretorio -%s- \n", temp);
		  CreateDirectory (temp, NULL);
		  temp[i + 1] = temp1;
	       }


	  }

// dprintf ("Criando diretorio final -%s- \n", temp);
	CreateDirectory (temp, NULL);


     }
   //dprintf ("1Qual o path que vai checar ? -%s- \n", path);
   //dprintf ("2Qual o path que vai checar ? -%s- \n", temp);
   if (ispathfolder (temp))
     {

	if (!ispathreadonly (temp))
	  {
	     return 0;		// ok , nao é read only
	  }
	else
	  {
	     return 15;		// path is read only or unavailable  
	  }


     }
   else
     {
// dprintf ("Qual o path que vai checar ? -%s- \n", path);
	if (ispathfile (temp))
	  {
	     return 3;
	  }
	else
	  {
	     return 4;
	  }

     }

   return 0;
 unc:

   if (ret)
     {

	for (i = 0; i < ret; i++)
	  {

	     if (i == 0)
	       {
		  i = 2;
	       }

	     if (temp[i] == '\\')
	       {
		  char temp1;
		  temp1 = temp[i + 1];
		  temp[i + 1] = 0;

// dprintf ("Criando diretorio UNC -%s- \n", temp);

		  CreateDirectory (temp, NULL);

		  temp[i + 1] = temp1;
	       }


	  }
// dprintf ("Criando diretorio UNC final -%s- \n", temp);
	CreateDirectory (temp, NULL);

     }
// dprintf ("Qual o path que vai checar ? -%s- \n", path);
   if (ispathfolder (temp))
     {

	if (!ispathreadonly (temp))
	  {
	     return 0;		// ok , nao é read only
	  }
	else
	  {
	     return 15;		// path is read only or unavailable  
	  }

	return 0;
     }
   else
     {
// dprintf ("Qual o path que vai checar ? -%s- \n", path);
	if (ispathfile (temp))
	  {
	     return 5;
	  }
	else
	  {
	     return 6;
	  }

     }

   return 0;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

char *
validanomedearquivoerrorstring ()
{
   static char errorstring[] =
      "the file name has invalid characters | \\ \" > < ? * / or : ";
   return errorstring;
}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


int
validanomedearquivo (char *path)
{


/*
esta funcao verifica se um path passado
tem caracteres validos para um path
se tiver algum item que nao e valido para arquivo
retorna o valor de erro , se der tudo certo , retorna 0	
15/1/2004 13:11	
*/


   if ((contastringinsensitive (path, ":")))
     {

	return 1;
     }

   if ((contastringinsensitive (path, "/")))
     {

	return 2;
     }

   if ((contastringinsensitive (path, "*")))
     {

	return 3;
     }

   if ((contastringinsensitive (path, "?")))
     {

	return 4;
     }

   if ((contastringinsensitive (path, "<")))
     {

	return 5;
     }

   if ((contastringinsensitive (path, ">")))
     {

	return 6;
     }

   if ((contastringinsensitive (path, "\"")))
     {

	return 7;
     }

   if ((contastringinsensitive (path, "\\")))
     {

	return 8;
     }

   if ((contastringinsensitive (path, "|")))
     {

	return 9;
     }


   return 0;

}

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


char *
validatefoldertocreateerrorstring ()
{
   static char errorstring[] =
      "the path has invalid characters | \" > < ?	* / or :: ";
   return errorstring;
}

// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////

int
validatefoldertocreate (char *path)
{


/*
esta funcao verifica se um path passado
tem caracteres validos para um path
se tiver algum item que nao e valido para arquivo
retorna o valor de erro , se der tudo certo , retorna 0	
15/1/2004 13:11	
*/


   if ((contastringinsensitive (path, ":") > 1))
     {

	return 1;
     }

   if ((contastringinsensitive (path, "/")))
     {

	return 2;
     }

   if ((contastringinsensitive (path, "*")))
     {

	return 3;
     }

   if ((contastringinsensitive (path, "?")))
     {

	return 4;
     }

   if ((contastringinsensitive (path, "<")))
     {

	return 5;
     }

   if ((contastringinsensitive (path, ">")))
     {

	return 6;
     }

   if ((contastringinsensitive (path, "\"")))
     {

	return 7;
     }

   if ((contastringinsensitive (path, "|")))
     {

	return 8;
     }

   return 0;

}

/*
* int main5 () {
* 
* 
* 
* char temp[255] = "a:"; char temp1[255] = "a:\\"; char temp2[255] =
* "a:\\a"; char temp3[255] = "a:\\ao"; char temp4[255] = "a:\\as"; char
* temp5[255] = "a:\\ash"; char temp6[255] = "a:\\d"; char temp7[255] =
* "a:\\do"; char temp8[255] = "a:\\dro"; char temp9[255] = "a:\\ds"; char 
* temp10[255] = "a:\\dsh"; char temp11[255] = "a:\\\\"; char temp12[255]
* = "a:\\a\\"; char temp13[255] = "a:\\ao\\"; char temp14[255] =
* "a:\\as\\"; char temp15[255] = "a:\\ash\\"; char temp16[255] =
* "a:\\d\\"; char temp17[255] = "a:\\do\\"; char temp18[255] =
* "a:\\dro\\"; char temp19[255] = "a:\\ds\\"; char temp20[255] =
* "a:\\dsh\\"; char temp21[255] = "a:\\a\\\\"; char temp22[255] =
* "a:\\ao\\\\"; char temp23[255] = "a:\\as\\\\"; char temp24[255] =
* "a:\\ash\\\\"; char temp25[255] = "a:\\d\\\\"; char temp26[255] =
* "a:\\do\\\\"; char temp27[255] = "a:\\dro\\\\"; char temp28[255] =
* "a:\\ds\\\\"; char temp29[255] = "a:\\dsh\\\\"; char temp30[255] = "a:
* "; char temp31[255] = "a:\\ "; char temp32[255] = "a:\\a "; char
* temp33[255] = "a:\\ao "; char temp34[255] = "a:\\as "; char temp35[255] 
* = "a:\\ash "; char temp36[255] = "a:\\d "; char temp37[255] = "a:\\do
* "; char temp38[255] = "a:\\dro "; char temp39[255] = "a:\\ds "; char
* temp40[255] = "a:\\dsh "; char temp41[255] = "c:\\NTDETECT.COM";
* dprintf ("pathexists %s ? %d \n", temp, pathexists (temp)); dprintf
* ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp)); dprintf
* ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp1); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp2); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp3); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp4); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp5); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp6); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp7); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp8); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp9); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp10); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp11); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp12); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp13); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp14); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp15); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp16); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp17); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp18); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp19); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp20); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp21); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp22); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp23); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp24); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp25); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp26); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp27); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp28); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp29); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp30); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp31); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp32); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp33); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp34); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp35); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp36); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp37); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp38); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp39); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp40); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); strcpy (temp,
* temp41); dprintf ("pathexists %s ? %d \n", temp, pathexists (temp));
* dprintf ("ispathreadonly %s ? %d \n", temp, ispathreadonly (temp));
* dprintf ("ispathfolder %s ? %d \n", temp, ispathfolder (temp)); dprintf 
* ("ispathfile %s ? %d \n", temp, ispathfile (temp)); return 0; }
* 
* int main () {
* 
* int ret; char path[255];
* 
* ret = rspmakedir ("a::\\ricardo"); geterrorstringrspmakedir (ret,
* path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("a:\\ricardo>"); geterrorstringrspmakedir (ret,
* path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("a:\\ricardo<"); geterrorstringrspmakedir (ret,
* path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("a:\\ricardo?"); geterrorstringrspmakedir (ret,
* path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("a:\\ricardo\""); geterrorstringrspmakedir (ret,
* path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("a:\\ricardo*"); geterrorstringrspmakedir (ret,
* path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("a:\\ricardo/"); geterrorstringrspmakedir (ret,
* path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("a:\\ricardo2"); geterrorstringrspmakedir (ret,
* path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("\\\\bw\\backup\\meu path"); geterrorstringrspmakedir 
* (ret, path); dprintf ("Retorno %s \n", path);
* 
* ret = rspmakedir ("\\\\bw\\backup1\\meu path");
* geterrorstringrspmakedir (ret, path); dprintf ("Retorno %s \n", path);
* 
* return 0; }
* 
* int main7 () {
* 
* 
* uint ret; ret = rspmakedir ("\\\\bw\\backup\\my folder2\\my
* folder3\\myfolder4"); dprintf ("Ret criou 1 %d \n", ret); ret =
* rspmakedir ("\\\\bw2\\backup\\my folder\\"); dprintf ("Ret criou 2 %d
* \n", ret); ret = rspmakedir ("\\\\bw\\backup2\\my folder\\"); dprintf
* ("Ret criou 3 %d \n", ret); ret = rspmakedir
* ("a:\\rico2\\rico\\rico3\\rico5"); dprintf ("Ret criou 4 %d \n", ret);
* ret = rspmakedir ("a:\\rico3"); dprintf ("Ret criou 5 %d \n", ret); ret 
* = rspmakedir ("a:\\a"); dprintf ("Ret criou 6 %d \n", ret); ret =
* rspmakedir ("a:"); dprintf ("Ret criou 7 %d \n", ret); ret = rspmakedir 
* ("a:\\"); dprintf ("Ret criou 8 %d \n", ret); }
* 
* int main6 () {
* 
* char temp[255] = "\\\\bw"; char temp1[255] = "\\\\bw\\"; char
* temp2[255] = "\\\\bw\\\\"; char temp3[255] = "\\\\bw\\backup"; char
* temp4[255] = "\\\\bw\\backup\\"; char temp5[255] =
* "\\\\bw\\backup\\\\"; char temp6[255] = "\\\\bw\\backup\\test\\"; char
* temp7[255] = "\\\\bw\\backup\\test"; char temp8[255] =
* "\\\\bw\\backup\\arquivo"; char temp9[255] =
* "\\\\bw\\backup\\arquivo\\"; strcpy (temp, temp); dprintf ("pathexists
* %s ? %d \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d 
* \n", temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n",
* temp, ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp1); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp2); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp3); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp4); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp5); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp6); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp7); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp8); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp)); strcpy (temp, temp9); dprintf ("pathexists %s ? %d
* \n", temp, pathexists (temp)); dprintf ("ispathreadonly %s ? %d \n",
* temp, ispathreadonly (temp)); dprintf ("ispathfolder %s ? %d \n", temp, 
* ispathfolder (temp)); dprintf ("ispathfile %s ? %d \n", temp,
* ispathfile (temp));
* 
* return 0; }
* 
* int main4 (int argc, char **argv) {
* 
* WIN32_FIND_DATA fd; HANDLE h; char x[300]; uint ret; char temp[255] =
* "\\\\Bw\\backup\\arquivo";
* 
* if (argc > 1) { strcpy (temp, argv[1]); ret = GetFileAttributes (temp);
* if (ret != 0xffffffff) { if (ret & FILE_ATTRIBUTE_DIRECTORY) { dprintf
* ("Diretorio Retorno de ret %x -%s- \n", ret, temp); } else { dprintf
* ("Arquivo Retorno de ret %x -%s- \n", ret, temp); } } else { dprintf
* ("Path invalido %x -%s- \n", ret, temp); }
* 
* 
* 
* if ((h = FindFirstFile (temp, &fd)) == INVALID_HANDLE_VALUE) {
* 
* dprintf ("Invalid handle2 -%s- \n", temp); return 0; } else { dprintf
* ("Ok openning %s \n", temp); } FindClose (h); }
* 
* return 0; } 
*/


// //////////////////////////////////////////////////////////////////////////////////////
// //////////////////////////////////////////////////////////////////////////////////////
/*fim do arquivo 15/1/2004 13:11*/

//


//
///* FSEEK.C: This program opens the file FSEEK.OUT and
// * moves the pointer to the file's beginning.
// 
//SEEK_CUR Current position of file pointer
//
//SEEK_END End of file
//
//SEEK_SET Beginning of file
// 
//*/
//
//#include <stdio.h>
//
//void main( void )
//{
//   FILE *stream;
//   char line[81];
//   int  result;
//
//   stream = fopen( "fseek.out", "w+" );
//   if( stream == NULL )
//      printf( "The file fseek.out was not opened\n" );
//   else
//   {
//      fprintf( stream, "The fseek begins here: "
//                       "This is the file 'fseek.out'.\n" );
//      result = fseek( stream, 23L, SEEK_SET);
//      if( result )
//         perror( "Fseek failed" );
//      else
//      {
//         printf( "File pointer is set to middle of first line.\n" );
//         fgets( line, 80, stream );
//         printf( "%s", line );
//
//      }
//      fclose( stream );
//   }
//}
//
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//
///* FTELL.C: This program opens a file named FTELL.C
// * for reading and tries to read 100 characters. It
// * then uses ftell to determine the position of the
// * file pointer and displays this position.
// */
//
//#include <stdio.h>
//
//FILE *stream;
//
//void main( void )
//{
//   long position;
//   char list[100];
//   if( (stream = fopen( "ftell.c", "rb" )) != NULL )
//   {
//      /* Move the pointer by reading data: */
//      fread( list, sizeof( char ), 100, stream );
//      /* Get position after read: */
//      position = ftell( stream );
//      printf( "Position after trying to read 100 bytes: %ld\n",
//              position );
//      fclose( stream );
//   }
//}
//
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//
///* FOPEN.C: This program opens files named "data"
// * and "data2".It  uses fclose to close "data" and
// * _fcloseall to close all remaining files.
// */
//
//#include <stdio.h>
//
//FILE *stream, *stream2;
//
//void main( void )
//{
//   int numclosed;
//
//   /* Open for read (will fail if file "data" does not exist) */
//   if( (stream  = fopen( "data", "r" )) == NULL )
//      printf( "The file 'data' was not opened\n" );
//   else
//      printf( "The file 'data' was opened\n" );
//
//   /* Open for write */
//   if( (stream2 = fopen( "data2", "w+" )) == NULL )
//      printf( "The file 'data2' was not opened\n" );
//   else
//      printf( "The file 'data2' was opened\n" );
//
//   /* Close stream */
//   if( fclose( stream ) )
//      printf( "The file 'data' was not closed\n" );
//
//   /* All other files are closed: */
//   numclosed = _fcloseall( );
//   printf( "Number of files closed by _fcloseall: %u\n", numclosed );
//}
//
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//
///* FREAD.C: This program opens a file named FREAD.OUT and
// * writes 25 characters to the file. It then tries to open
// * FREAD.OUT and read in 25 characters. If the attempt succeeds,
// * the program displays the number of actual items read.
// */
//
//#include <stdio.h>
//
//void main( void )
//{
//   FILE *stream;
//   char list[30];
//   int  i, numread, numwritten;
//
//   /* Open file in text mode: */
//   if( (stream = fopen( "fread.out", "w+t" )) != NULL )
//   {
//      for ( i = 0; i < 25; i++ )
//         list[i] = (char)('z' - i);
//      /* Write 25 characters to stream */
//      numwritten = fwrite( list, sizeof( char ), 25, stream );
//      printf( "Wrote %d items\n", numwritten );
//      fclose( stream );
//
//   }
//   else
//      printf( "Problem opening the file\n" );
//
//   if( (stream = fopen( "fread.out", "r+t" )) != NULL )
//   {
//      /* Attempt to read in 25 characters */
//      numread = fread( list, sizeof( char ), 25, stream );
//      printf( "Number of items read = %d\n", numread );
//      printf( "Contents of buffer = %.25s\n", list );
//      fclose( stream );
//   }
//   else
//      printf( "File could not be opened\n" );
//}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//
///* FREAD.C: This program opens a file named FREAD.OUT and
// * writes 25 characters to the file. It then tries to open
// * FREAD.OUT and read in 25 characters. If the attempt succeeds,
// * the program displays the number of actual items read.
// */
//
//#include <stdio.h>
//
//void main( void )
//{
//   FILE *stream;
//   char list[30];
//   int  i, numread, numwritten;
//
//   /* Open file in text mode: */
//   if( (stream = fopen( "fread.out", "w+t" )) != NULL )
//   {
//      for ( i = 0; i < 25; i++ )
//         list[i] = (char)('z' - i);
//      /* Write 25 characters to stream */
//      numwritten = fwrite( list, sizeof( char ), 25, stream );
//      printf( "Wrote %d items\n", numwritten );
//      fclose( stream );
//
//   }
//   else
//      printf( "Problem opening the file\n" );
//
//   if( (stream = fopen( "fread.out", "r+t" )) != NULL )
//   {
//      /* Attempt to read in 25 characters */
//      numread = fread( list, sizeof( char ), 25, stream );
//      printf( "Number of items read = %d\n", numread );
//      printf( "Contents of buffer = %.25s\n", list );
//      fclose( stream );
//   }
//   else
//      printf( "File could not be opened\n" );
//}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//

int
rspposicaofixa (int mode, int value)
{

   static int valor = 0;

   if (mode == 0)
     {


	return valor;

     }

   if (mode == 1)
     {


	valor = value;
	return 0;
     }

   return 0;

}


int
wildcardselection (const char *path, const char *string1)
{
/*
	escaneia o path de acordo com o wildcard
	se for valido retorna 1 , se nao bater retorna 0
	
	se for vazio ou * o string1 , retorna 1 sempre
*/

   char filename[255];
   char temp[255];
   char string[255];
   char temp2[255];
   char temp3[255];
   int ret;
   int i;
   int p;
   int ret22;
   int ret2;

   int special = 0;

   strcpy (temp, path);
   strcpy (string, string1);
   trocadordebackslashtras (temp);

   stripfilenameandpath (temp, NULL, filename);

   if (strlen (filename) == 0)
     {

	return 0;
     }

   if (strlen (string1) == 0)
     {

	return 1;
     }


   if (strlen (string1) == 1 && string1[0] == '*')
     {

	return 1;
     }

   if (strlen (string1) == 3 && string1[0] == '*' && string1[1] == '.'
       && string1[2] == '*')
     {

	return 1;
     }


   ret = strlen (temp);

   if (ret)
     {

	ret = strlen (string);
	if (!ret)
	  {

	     return 0;

	  }

	p = 0;

	if (string[0] == '*')
	  {
	     p = 1;
	  }

	if (string[ret - 1] == '*')
	  {

	     if (p == 1)
	       {
		  p = 2;
	       }
	     else
	       {
		  p = 3;
	       }
	  }




//faca uma contagem de quantos itens * tem dentro
	ret2 = contastringinsensitive (string, "*");

	//dprintf ("Numero de * achados %d \n", ret2);


	if (p == 1 && ret2 != 1)
	  {
	     special = 1;

	     if (ret2 > 2)
	       {
		  return 0;
	       }

	     // dprintf ("Erro p==1 %d \n", ret2);
	  }

	if (p == 2 && ret2 != 2)
	  {

	     special = 1;
	     if (ret2 > 3)
	       {
		  return 0;
	       }

	     //  dprintf ("Erro p==2 %d \n", ret2);
	  }

	if (p == 3 && ret2 != 1)
	  {
	     special = 1;
	     if (ret2 > 2)
	       {
		  return 0;
	       }
	     //    dprintf ("Erro p==3 %d \n", ret2);
	  }

	if (p == 0 && ret2 != 0)
	  {
	     special = 1;
	     if (ret2 > 1)
	       {
		  return 0;
	       }
	     //   dprintf ("Erro p==0 %d \n", ret2);
	  }


	//dprintf ("Seguiu em frente \n");

// tem o especial case
// neste caso o asterisco pode estar no meio , e assim criar problemas
// pode ter mais de dois ** , e muitas outras coisas
// o bom mesmo seria criar um handler para tudo
// primeiro ache um meio de localizar aonde esta o *
// se nao for no inicio  assim m*.txt*
// need to have an m and the end need to be txt
// first characterneed to be m and extension need to be .txt
// acho que sao derivacoes das selecoes , por enquanto tem 4
// poderia ter mais
// depois na finalizacao faz o resto
// precisa somente de um divisor a mais , entendeu
// basta dividir a string em duas , e assim ter os itens colocados corretamente
// se a contagem for maior doque 1 a mais , entao esta em erro e deve sair fora sem
// extrair nada


// aqui verifica se é especial , efetua a divisao e segue em frente
	if (special)
	  {
/*oque , primeiro troca o primeiro e o ultimo se foreem * por ||*/

	     if (string[0] == '*')
	       {
		  string[0] = '|';
	       }

	     if (string[ret - 1] == '*')
	       {
		  string[ret - 1] = '|';
	       }


	     /*ok , aqui estamos prointo para dividir os itens e seguir em frente */

// somente chama o parser
	     ret22 = rspparser ("", "", NULL, 0);

	     ret22 = rspparser (string, "*", temp2, 1);

	     if (strlen (temp2))
	       {
		  ;		//  dprintf ("Item pego _%s_ \n", temp2);
	       }
	     else
	       {
		  return 0;

	       }
	     ret22 = rspparser (string, "*", temp3, 1);
	     if (strlen (temp3))
	       {
		  ;		// dprintf ("Item pego _%s_ \n", temp3);
	       }
	     else
	       {
		  return 0;
	       }

	     ret22 = rspparser ("", "", NULL, 2);

// void
//changecharacter (char *path, char itemtosearch, char finalcharacter)



	     changecharacter (temp2, '|', '*');
	     changecharacter (temp3, '|', '*');


	     strcat (temp2, "*");

	     {
		char temp4[255];

		strcpy (temp4, temp3);

		strcpy (temp3, "*");
		strcat (temp3, temp4);
	     }

	     ;			// dprintf ("Item pego _%s_ \n", temp2);
	     ;			// dprintf ("Item pego _%s_ \n", temp3);

// ok , agora verifica se precisa checar os dois ou nao

	     {

		int rret;
		int rret2;
		int arret;
		int brret2;
		int crret;
		int crret2;

		crret = contastringinsensitive (temp2, "*");
		crret2 = contastringinsensitive (temp3, "*");

		rret = wildcardselection (filename, temp2);
		arret = rspposicaofixa (0, 0);
		rret2 = wildcardselection (filename, temp3);
		brret2 = rspposicaofixa (0, 0);

		;		//dprintf ("valor de arret e brret %d %d \n", arret, brret2);

		if (crret == 2 && crret2 == 2)
		  {
/*vai precisar checar o retorno*/

		     if (arret > brret2)
		       {
			  return 0;

		       }


		     if (rret && rret2)
		       {
			  return 1;
		       }
		     else
		       {
			  return 0;
		       }


		  }
		else
		  {
		     if (rret && rret2)
		       {
			  return 1;
		       }
		     else
		       {
			  return 0;
		       }

		  }

	     }


	     /*estamos indo , agora no caso de temp 2 e temp 3 , tem que se saber a posicao que foi achado o item */
	     // porque nao pode ser maior que o segundo

	  }


	;			//dprintf ("String a procurar %s  %s \n", filename, string);

	if (p == 0)
	  {
	     rspposicaofixa (1, 0);
	     strtolower (string);
	     strtolower (filename);

	     if (strlen (string) != strlen (filename))
	       {

		  return 0;

	       }

	     ret = strlen (string);

	     for (i = 0; i < ret; i++)
	       {

		  if (string[i] != filename[i])
		    {

		       return 0;

		    }

	       }

	     return 1;

	  }

	if (p == 1)
	  {
	     rspposicaofixa (1, 0);
	     if (strlen (string) > (strlen (filename) + 1))
	       {

		  return 0;
	       }

	     strtolower (string);
	     strtolower (filename);

	     for (i = 0; i < (strlen (string) - 1); i++)
	       {

		  if (string[(strlen (string) - 1) - i] !=
		      filename[(strlen (filename) - 1) - i])
		    {
		       return 0;
		    }

	       }

	     return 1;
	  }


	if (p == 3)
	  {

	     rspposicaofixa (1, 0);

	     if (strlen (string) > (strlen (filename) + 1))
	       {

		  return 0;
	       }

	     strtolower (string);
	     strtolower (filename);

	     for (i = 0; i < (strlen (string) - 1); i++)
	       {

		  if (string[i] != filename[i])
		    {
		       return 0;
		    }

	       }

	     return 1;

	  }


	if (p == 2)
	  {
	     int ret;
	     strtolower (string);
	     strtolower (filename);
	     changecharacter (string, '*', ' ');
	     removedordecaracternofinal (string, ' ');
	     removedordecaracternoinicio (string, ' ');

	     ret = pegaposicaoinsensitive (filename, string);

	     rspposicaofixa (1, ret);

	     return procuradordestringinsensitive (filename, string);

	  }
	return 0;

     }
   return 0;
}









#ifdef rspdebugme1

//int
//wildcardselection (char *path, char *string)

int
main (int argc, char **argv)
{
   int ret;

   dprintf ("item %s\n", argv[1]);

   ret = wildcardselection ("c:\\back\\MeUpath", argv[1]);
   if (ret)
     {
	dprintf ("Achou \n");
     }
   else
     {
	dprintf ("Nao achou \n");
     }

}

#endif
