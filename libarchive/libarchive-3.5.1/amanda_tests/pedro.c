
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *                                                                                *
  *      Licensa de Cópia (C) <202*>  <Corporação do Trabalho Binário>             *
  *                                                                                *
  *   Este programa é software livre: você pode redistribuir isto e/ou modificar   *
  *   isto sobre os termos do GNU Licensa Geral Pública como publicado pela        *
  *   Fundação de Software Livre, tanto a versão 3 da Licensa, ou                  *
  *   (dependendo da sua opção) qualquer versão posterior.                         *
  *                                                                                *
  *   Este programa é distribuído na esperança que isto vai ser útil,              *
  *   mas SEM QUALQUER GARANTIA; sem até mesmo a implicada garantia de             *
  *   COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
  *   Licensa Geral Pública para mais detalhes.                                    *
  *                                                                                *
  *   Você deve ter recebido uma cópia da LICENSA GERAL PUBLICA                    *
  *       e a GNU Licensa Pública Menor junto com este programa                    *
  *       Se não, veja <http://www.gnu.org/licenses/>.                             *
  *                                                                                *
  *   Suporte: https://arsoftware.net.br/binarywork ____________________           *
  *   Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/           *
  *             http://nomade.sourceforge.net/binarywork/ ______________            *
  *                                                                                *
  *       e-mails direto dos felizes programadores:                                *
  *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
  *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
  *                                                                                *
  *       contato imediato(para uma resposta muita rápida) WhatsApp                *
  *       (+55)41 9627 1708 - isto está sempre ligado                              *
  *                                                                                *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include  <windows.h>
#include   <stdint.h>
#include    <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include     <time.h>
#include    <errno.h>
#include    <fcntl.h>
#include    <ctype.h>
#include     <math.h>
#include   <wctype.h>
#include    <wchar.h>
#include   <stdarg.h>
#include   <stddef.h>
#include   <setjmp.h>
#include   <locale.h>
#include   <signal.h>
#include   <limits.h>
#include    <float.h>
#include   <iso646.h>

#undef NDEBUG
#include   <assert.h>

#include  <stdbool.h>

#include  <process.h>

extern int debug_mode_i;

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
)
{
     if(debug_mode_i)
     {
	  return;
     }
     //return;
     if(-1 < amanda_level)
     {
	  va_list  amanda;
	  char *   buffer_kp = malloc(20000);
	  char *   ptr_z;
	  va_start (amanda, format);
	  vsprintf (buffer_kp, format, amanda);
	  if(strlen(buffer_kp))
	  {
	       ptr_z = buffer_kp;

	       while(* ptr_z)
	       {
		    if('\n' == *ptr_z || '\r' == *ptr_z)
		    {

			 *ptr_z = ' ';
			 
		    }
		    ptr_z++;
	       }
	  }
	  strcat(buffer_kp," _amanda_debug_");
	  OutputDebugString (buffer_kp);
	  free(buffer_kp);
	  va_end(amanda);
	  //fixed...my love
     }
	return;
}

/**
 * Function to send a formatted string to OutputDebugString as a wide string that
 * can be captured by DebugView or the installed debugger
 *
 * @param amanda_level if above -1 it will show the string
 *
 * @param format the formatted string to show
 *
 */
void pedro_dprintfW( //para imprimir wide string use %ls ok?, te amo...
	int amanda_level,
	const wchar_t *format, ...)
{
     if(debug_mode_i)
     {
	  return;
     }
     if (-1 < amanda_level)
     {

//since we don´t use the standard mingw for the moment we can use only this
//part of the code
#if 1

//int vswprintf (wchar_t * ws, size_t len, const wchar_t * format, va_list arg );

	     wchar_t * buffer_kp = malloc(      40000);
	     wchar_t * ptr_z                          ;
	     va_list   args                                                                              ;
	     va_start(args, format)                   ;
	     vswprintf(buffer_kp, 20000, format, args);
	     if(wcslen(buffer_kp))
	     {
		  ptr_z = buffer_kp;

		  while(* ptr_z)
		  {
		       if('\n' == *ptr_z || '\r' == *ptr_z)
		       {

			    *ptr_z = ' ';
			 
		       }
		       ptr_z++;
		  }
	     }
	     wcscat(buffer_kp, L" _amanda_debug_");
	     OutputDebugStringW(buffer_kp        );
	     free(buffer_kp);
	     va_end(args)   ;

#else
	     wchar_t buffer[20000];
	     va_list args;
	     va_start(args, format);
	     vswprintf(buffer, format, args);
	     if ('\n' == buffer[wcslen(buffer) - 1])
	     {
		  buffer[wcslen(buffer) - 1] = ' ';
	     }
	     wcscat(buffer, L" _amanda_debug_");
	     OutputDebugStringW(buffer);
	     va_end(args);
#endif
	}
	return;
}
