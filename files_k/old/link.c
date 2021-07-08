#ifndef INCLUDEUCHAR
#ifndef uchar
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
#define ushort  unsigned short
#endif
#endif
/*programa exemplo com main */

/*

   finalizacao de utilizacao de linked list

   Basta agora aplicar la e fim de papo
   esta feito o negocio

   este é um tipo de codigo que realemente tem que estar fora
   de qualquer outro source code

   Pois se estiver dentro da muita complicacao

 */

#include <stdio.h>

#include <windows.h>



typedef struct rsptest
{

	struct rsptest *next;
	char filename[255];
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int second;
	int isdir;
	int size;
} filesearch;

filesearch *inicio;
filesearch *inicio2;
filesearch *inicio3;
filesearch inicial;

int firstitem = 0;

int alocacoes = 0;



/*
   local->tm_mday, local->tm_mon + 1, local->tm_year + 1900,
            local->tm_hour, local->tm_min, local->tm_sec);
 */
int
additem (uint isdir, uint second,
         uint minute, uint hour,
         uint year, uint month, uint day, char *filename, uint size)
{

	//  dprintf ("dentro de additem \n");

	if (!firstitem)
	{
		/*aqui somente seta na primeira */
		inicio = &inicial;
		firstitem = 1;
	}
	inicio->next = malloc (sizeof (filesearch) + 1);
	alocacoes++;
	memset (inicio->next, 0, sizeof (filesearch) + 1);
	/*aqui poe a informacao */
	inicio->isdir = isdir;
	inicio->second = second;
	inicio->minute = minute;
	inicio->hour = hour;
	inicio->year = year;
	inicio->month = month;
	inicio->day = day;
	inicio->size = size;

	//  dprintf ("endereco %d \n", inicio);
	// dprintf ("additem arquivo %s \n", filename);

	strcpy (inicio->filename, filename);

	/*aqui move pro seguinte item */
	inicio = inicio->next;

	return 0;
}

int
deletelist ()
{
#ifdef NPRINTF
	dprintf ("dentro de deletelist \n");
	dprintf ("numero de alocacoes antes %d \n", alocacoes);
#endif

	if (firstitem == 0)
	{
		return 0;
	}

	inicio2 = &inicial;

	inicio2 = inicio2->next;

	while (inicio2)
	{

		filesearch *guarda;

		guarda = inicio2;

		inicio2 = inicio2->next;

		free (guarda);

		alocacoes--;
	}

	firstitem = 0;
#ifdef NPRINTF
	dprintf ("numero de alocacoes %d \n", alocacoes);
#endif
	return 0;

}


int
getitem (int mode, uint * isdir, uint * second,
         uint * minute, uint * hour,
         uint * year, uint * month, uint * day, char *filename, uint * size)
{


	//  dprintf ("dentro de getitem , mode %d\n", mode);
	if (mode == 0)
	{



		inicio2 = &inicial;

		//inicio2 = inicio2->next;
	}

	if (firstitem == 0)
	{
		return 0;
	}



	// dprintf ("valido getitem \n");
	// dprintf ("endereco %d \n", inicio2);
	while (inicio2)
	{

		filesearch *guarda;

		guarda = inicio2;
		inicio2 = inicio2->next;

		if (inicio2)
		{
			//   dprintf ("copiando valores validos %s \n", filename);
			//   dprintf ("copiando valores validos %d \n", guarda->day);
			strcpy (filename, guarda->filename);
			*day = guarda->day;
			*month = guarda->month;
			*year = guarda->year;
			*hour = guarda->hour;
			*minute = guarda->minute;
			*second = guarda->second;
			*isdir = guarda->isdir;
			*size = guarda->size;


			return 1;
		}
		else
		{
			return 0;
		}
	}


	return 0;

}

//#define rspdebug
#ifdef rspdebug
#ifdef NPRINTF
int
main ()
{
/*fazendo os testes precisos para que funcione a linked list*/
	int ret;
	int item;
	char temp[255];
	int i;

	uint isdir;
	uint second;

	uint minute;
	uint hour;

	uint year;
	uint month;

	uint day;
	char filename[255];
	uint size;

	for (i = 0; i < 2; i++)
	{

/*

   additem (uint isdir , uint second ,
   uint minute , uint hour ,
   uint year ,uint month,
   uint day ,  char *filename , uint size)

 */

		additem (1, 2, 3, 4, 5, 6, 7, "minha string", 8);
#ifdef NPRINTF
		dprintf ("Numero de alocacoes %d \n", alocacoes);
#endif
/*

   int
   getitem (int mode, uint * isdir, uint * second,
         uint * minute, uint * hour,
         uint * year, uint * month, uint * day, char *filename, uint * size)


 */


		ret = getitem (0, &isdir, &second, &minute, &hour, temp);

		if (ret == 1)
		{
			//   dprintf ("has item %d , %s\n", item, temp);

		}

		while (ret)
		{

			ret = getitem (1, &item, temp);
			if (ret)
			{
				//  dprintf ("has item %d , %s\n", item, temp);

			}
			else
			{
				//  dprintf ("No more item\n");
			}
		}


		deletelist ();
		deletelist ();
		deletelist ();
		deletelist ();

	}

	deletelist ();
#ifdef NPRINTF
	dprintf ("Numero de alocacoes %d \n", alocacoes);
#endif
}
#endif
#endif
