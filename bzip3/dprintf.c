//our old 90s based debug rountines...
#include <stdio.h>
#include <windows.h>

extern int setdebuginformation (char *string);

void   dprintf (char *format, ...);

//
//void
//ddprintf (int value, char *format, ...)
//{
////#line 353
////#error  C2059: syntax error : '}'
////#ifdef RSPDEBUG
//
//   {
//
//      int rete;
//      va_list args;
//      static char buffer[10000];
//      int ret;
//
//      rete = GetLastError ();
//
//      va_start (args, format);
//      ret = vsprintf (buffer, format, args);
//      //OutputDebugString (buffer);
//      //printf (buffer);
//
//
//      dprintf (buffer);
//
//
//      {
//
//       {
//          int ret;
//          char *copy;
//          char *copy2;
//
//          copy = malloc (strlen (buffer) + 100);
//          copy2 = malloc (strlen (buffer) + 100);
//
//          strcpy (copy, buffer);
//
//          changecharacter (copy, '\r', '\n');
//
//        volta:
//          ret = pegaposicaosensitive (copy, "\n");
//
//          if (ret)
//            {
//
//               strcpy (copy2, &copy[ret]);
//               copy[ret - 1] = 0;
//               removedordeespaconoinicio (copy);
//               if (strlen (copy))
//                 {
//                    setmessage (value, copy);
//                    rspsendmessage ();
//                 }
//
//               strcpy (copy, copy2);
//               goto volta;
//
//            }
//          else
//            {
//               removedordeespaconoinicio (copy);
//               if (strlen (copy))
//                 {
//                    setmessage (value, copy);
//                    rspsendmessage ();
//                 }
//
//            }
//
//          free (copy);
//          copy = NULL;
//          free (copy2);
//          copy2 = NULL;
//       }
//
//      }
//
//      SetLastError (rete);
//
//   }
//
//   return;
//
//
//}

void dprintf (char *format, ...)
{
//#line 353
//#error  C2059: syntax error : '}'
#ifdef NPRINTF

     {

	  int    rete;
	  va_list args;
	  static char buffer[1000000];//no multi-thread support
	  int    ret;

	  rete = GetLastError ();

	  va_start (args, format);
	  ret = vsprintf (buffer, format, args);
	  OutputDebugString (buffer);
	  printf (buffer);//always printing also to stdout even if in a DLL

//setmessage (501, buffer);
//rspsendmessage ();

	  SetLastError (rete);

     }
#else

     return;
#endif

}