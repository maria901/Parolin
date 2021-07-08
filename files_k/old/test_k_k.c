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

#include <sys/stat.h>

#include <stdbool.h>

char * 
anytostr (intmax_t i, char *buf)
{
  char *p = buf + 60;
  *p = 0;

  if (i < 0)
    {
      do
        *--p = '0' - i % 10;
      while ((i /= 10) != 0);

      *--p = '-';
    }
  else
    {
      do
        *--p = '0' + i % 10;
      while ((i /= 10) != 0);
    }

  return p;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void *
x2nrealloc (void *p, size_t *pn, size_t s)
{
  size_t n = *pn;

  if (! p)
    {
      if (! n)
        {
          /* The approximate size to use for initial small allocation
             requests, when the invoking code specifies an old size of
             zero.  This is the largest "small" request for the GNU C
             library malloc.  */
          enum { DEFAULT_MXFAST = 64 * sizeof (size_t) / 4 };

          n = DEFAULT_MXFAST / s;
          n += !n;
        }
#if 0		
      if (xalloc_oversized (n, s))
        xalloc_die ();
#endif
    }
  else
    {
      /* Set N = floor (1.5 * N) + 1 so that progress is made even if N == 0.
         Check for overflow, so that N * S stays in both ptrdiff_t and
         size_t range.  The check may be slightly conservative, but an
         exact check isn't worth the trouble.  */
#if 0
      if ((PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : SIZE_MAX) / 3 * 2 / s
          <= n)
        xalloc_die ();
#endif

      n += n / 2 + 1;
    }

  *pn = n;
  return realloc (p, n * s);
}

int main()
{

char *saida_k = NULL;

int tamanho_k = 10;

saida_k = x2nrealloc (NULL, &tamanho_k, 1);

tamanho_k = 20;

saida_k = x2nrealloc (saida_k, &tamanho_k, 1);
printf("%I64d, %d\n", (__int64) saida_k, tamanho_k);// "oi", mypath_k);

return 0;

}