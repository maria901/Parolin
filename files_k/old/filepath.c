#include <stdio.h>
#include <windows.h>

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
	return 1;
     }

   ret = strlen (path);

   if (!ret)
     {
	return 0;
     }

   for (i = 0; i < ret; i++)
     {

	if (path[i] == separator)
	  {
	     goto continua;
	  }

     }

   return 2;

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

#ifdef RSPDEBUGFILEPATH
#ifdef NPRINTF
int
main ()
{

/*seguindo em frente*/

/*
criar o stripador de path e estricador de arquivo
para assim criar os diretorios de acordo com aquilo que pegar

*/
   int ret;
   char temp[255];
   char temp2[255];
   ret =
      stripfilenameandpath ("c:\\meu path to remove\\filename", temp, temp2);

   if (!ret)
     {
	printf ("Path |%s| \n", temp);
	printf ("Filename |%s| \n", temp2);
     }

}

/*Click here to set the regexp*/
#endif
#endif

//I am in a hurry, I dont know why , Alladin
