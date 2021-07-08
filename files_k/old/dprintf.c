#include <stdio.h>
#include <windows.h>



void
dprintf (char *format, ...)
{
//#line 353
//#error  C2059: syntax error : '}'
#ifdef NPRINTF

  {
    va_list args;
    static char buffer[100000];
    int ret;
    va_start (args, format);
    ret = vsprintf (buffer, format, args);

    OutputDebugString (buffer);
  }
#else

  return;
#endif


}

