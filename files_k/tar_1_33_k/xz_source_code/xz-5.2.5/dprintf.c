

/*

         ////////////////////////////////////////////////////////////////////
       //                                                                 ///
     //                     Empresa de Software de Samara e Ricardo      ////
    ///                     Mon Aug 06 19:41:00 2018, by morcego48:    //////
    ///                                                               ///////
    /// Author        :     Ricardo                                 /////////
    /// Author e-mail :     samara2@users.sourceforge.net         ///////////
    ///                     papagaio4@users.sourceforge.net     ///////////
    ///           WWW :     samararicardo.sourceforge.net     ///////////
    ///////////////////////////////////////////////////////////////////

 */
 
#include <stdio.h>
#include <windows.h>



void
dprintf (char *format, ...)
{
#ifndef NPRINTF
return;
#else
  {
    va_list args;
    static char buffer[1000000];//caralho
    int ret;
    va_start (args, format);
    ret = vsprintf (buffer, format, args);

    OutputDebugString (buffer);
  }
#endif
  return;
}

