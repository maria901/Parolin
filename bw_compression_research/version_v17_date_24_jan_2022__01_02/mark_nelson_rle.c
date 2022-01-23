//
//  RLE.CPP
//
//  Mark Nelson
//  March 8, 1996
//  http://web2.airmail.net/markn
//
// DESCRIPTION
// -----------
//
//  This program performs a Run Length Encoding function on an
//  input file/stream, and sends the result to an output file
//  or stream.  In the output stream, any two consecutive
//  characters with the same value flag a run.  A byte following
//  those two characters gives the count of *additional*
//  repeat characters, which can be anything from 0 to 255.
//
//  Using the RLE program as a front end to BWT avoids
//  pathologically slow sorts that occur when the input stream
//  has long sequences of identical characters. (Which means
//  comparison functions have to spend lots of time on a pair
//  of strings before deciding who is larger.)
//
//  This program takes two arguments: an input file and an output
//  file.  You can leave off one argument and send your output to
//  stdout.  Leave off two arguments and read your input from stdin
//  as well.
//
//  This program accompanies my article "Data Compression with the
//  Burrows-Wheeler Transform."
//
// Build Instructions
// ------------------
//
//  Define the constant unix for UNIX or UNIX-like systems.  The
//  use of this constant turns off the code used to force the MS-DOS
//  file system into binary mode. g++ already does this, your UNIX C++
//  compiler might also.
//
//  Borland C++ 4.5 16 bit    : bcc -w rle.cpp
//  Borland C++ 4.5 32 bit    : bcc32 -w rle.cpp
//  Microsoft Visual C++ 1.52 : cl /W4 rle.cpp
//  Microsoft Visual C++ 2.1  : cl /W4 rle.cpp
//  g++                       : g++ -o rle rle.cpp
//
// Typical Use
// -----------
//
//  rle < raw-file | bwt | mtf | rle | ari > compressed-file
//
//
// 2021 MathMan and amanda
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

#include <stdbool.h>

#include <stdio.h>
#if !defined(unix)
#include <io.h>
#include <fcntl.h>
#endif

int main_rle(uint8_t *buf_ar, int len_ar, uint8_t *buf_out, int *len_out_ar)
{

     (*len_out_ar) = 0;

     int last = 0;
     int c;
     if (len_ar > 2)
     {
          while (len_ar--)
          {
               assert(0 <= len_ar);
               c = (int)*buf_ar++;

               (*buf_out) = (int8_t)c;
               buf_out++;
               (*len_out_ar)++;

               if (0 == len_ar)
               {
                    break;
               }

               if (c == last)
               {
                    int count = 0;

                    if (3 > len_ar)
                    {
                         // exit(27);
                         goto nao;
                    }
                    while (count < 255 && (len_ar--))
                    {
                         c = (int)*buf_ar++;
                         if (c == last)
                         {
                              count++;
                         }
                         else
                         {
                              break;
                         }

                         if (3 > len_ar)
                         {
                              break;
                         }
                    }
               nao:;

                    {
                         pedro_dprintf(-1, "len out %d", (*len_out_ar));
                         (*buf_out) = (int8_t)count;
                         buf_out++;
                         (*len_out_ar)++;
                    }

                    if (count != 255 && c >= 0)
                    {
                         (*buf_out) = (int8_t)c;
                         buf_out++;
                         (*len_out_ar)++;
                    }
               }
               last = c;
          }
     }
     else
     {
          *len_out_ar = len_ar + 100;
     }
     return 0;
}
