/*programa exemplo com main */
#include <stdio.h>
#include <windows.h>

#ifndef dprintf
#define dprintf printf
#endif

typedef void *myfile;		// assim fica melhor de se usar o treco

// basta passar o endereco
int gzclose (myfile file);

myfile gzopen (char *path, char *mode);

int gzread (myfile file, char *buf, uint len);

int gzwrite (myfile file, const char *buf, uint len);

#define REGTYPE	 '0'		/* regular file */
#define AREGTYPE '\0'		/* regular file */
#define LNKTYPE  '1'		/* link */
#define SYMTYPE  '2'		/* reserved */
#define CHRTYPE  '3'		/* character special */
#define BLKTYPE  '4'		/* block special */
#define DIRTYPE  '5'		/* directory */
#define FIFOTYPE '6'		/* FIFO special */
#define CONTTYPE '7'		/* reserved */


#define BLOCKSIZE 512

struct tar_header
{				/* byte offset */
   char name[100];		/*   0 */
   char mode[8];		/* 100 */
   char uid[8];			/* 108 */
   char gid[8];			/* 116 */
   char size[12];		/* 124 */
   char mtime[12];		/* 136 */
   char chksum[8];		/* 148 */
   char typeflag;		/* 156 */
   char linkname[100];		/* 157 */
   char magic[6];		/* 257 */
   char version[2];		/* 263 */
   char uname[32];		/* 265 */
   char gname[32];		/* 297 */
   char devmajor[8];		/* 329 */
   char devminor[8];		/* 337 */
   char prefix[155];		/* 345 */
   /* 500 */
};

union tar_buffer
{
   char buffer[BLOCKSIZE];
   struct tar_header header;
};

int
tar (int action, char *filename)
{

/*

action 0 = list tar file
action = 1 , extract tar file

*/
   static char buffer[BLOCKSIZE + 1];
   myfile f = NULL;

   f = gzopen ("file.tar", "rb");

   if (f == NULL)
     {

	return 1;		// unable to open file       

     }
#ifdef NPRINTF
   dprintf ("Valor de f %d \n", f);
#endif

   len = gzread (myfile, &buffer, BLOCKSIZE);
   if (len < 0)
      error (gzerror (in, &err));

















   gzclose (f);

   return 0;

}


int
main ()
{

   tar ();
#ifdef NPRINTF
   dprintf ("Aqui \n");
#endif
   return 0;

}
