/*programa exemplo com main */
#include <stdio.h>
#include <windows.h>

#ifndef dprintf
#define dprintf printf
#endif

extern void removedordeespaconofinal (char *path);

extern void removedordeespaconoinicio (char *path);

extern int pegaposicaoinsensitive (char *comando, char *string);

int
rspparser (char *instring, char *delimiter, char *returnstring, int comand)
{

   /*
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

#if 0
int
main ()
{
/*
aqui tem um problema , o temp pode ser nao grande o suficiente para 
manter todos os itens dentro
*/
   char temp[255];
   int ret;

   /*inicia para limpar os itens e preparar o terreno na funcao */
   ret = rspparser ("", "", NULL, 0);

   /*aqui ele vai lopear ate terminar de achar os itens */
 retorno:
   memset (temp, 0, 255);
   ret = rspparser (" item1 , item2 , item2 , item3      ,", ",", temp, 1);

   /*ret aqui so pode ser 3 ou 0
      0 se nao tiver mais
      3 se tiver mais
      qualquer valor diferente é um erro
    */

   if (strlen (temp))
     {

	/*aqui é o ponto que aje na utilizacao */
#ifdef NPRINTF
	dprintf ("Item retornado .%s. \n", temp);
#endif
     }
   else
     {

	/*se é null , entao é invalido e nao pode ser utilizado */
	//dprintf ("Valor de string retornado é null  \n");
     }

   if (ret == 3)
     {
	/*se e 3 entao tem mais , senao esta pronto para terminar */
	goto retorno;
     }

/*finalizador para limpar as alocacoes*/
   ret = rspparser ("", "", NULL, 2);

   if (ret)
     {
#ifdef NPRINTF
	dprintf (" verificando \n ");
#endif
     }

   return 0;

}

#endif
