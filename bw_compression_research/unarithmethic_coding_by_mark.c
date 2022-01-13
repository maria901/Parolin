//
//  UNARI.CPP
//
//  Mark Nelson
//  March 8, 1996
//  http://web2.airmail.net/markn
//
// DESCRIPTION
// -----------
//
//  This program performs an order-0 adaptive arithmetic decoding
//  function on an input file/stream, and sends the result to an
//  output file or stream.
//
//  This program contains the source code from the 1987 CACM
//  article by Witten, Neal, and Cleary.  I have taken the
//  source modules and combined them into this single file for
//  ease of distribution and compilation.  Other than that,
//  the code is essentially unchanged.
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
//  file system into binary mode.  g++ does this already, your UNIX
//  C++ compiler might also.
//
//  Borland C++ 4.5 16 bit    : bcc -w unari.cpp
//  Borland C++ 4.5 32 bit    : bcc32 -w unari.cpp
//  Microsoft Visual C++ 1.52 : cl /W4 unari.cpp
//  Microsoft Visual C++ 2.1  : cl /W4 unari.cpp
//  g++                       : g++ -o unari unari.cpp
//
// Typical Use
// -----------
//
//  unari < compressed-file | unrle | unmtf | unbwt | unrle > raw-file
//
//

// 2021 smart ape's mdifications...

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
#include <stdlib.h>
#include <fcntl.h>
#if !defined(unix)
#include <io.h>
#endif

static int return_value_dl;

static FILE *input_S2_file_dl;
static FILE *output_S2_file_dl;

/* THE SET OF SYMBOLS THAT MAY BE ENCODED. */

#define No_of_chars 256              /* Number of character symbols      */
#define EOF_symbol (No_of_chars + 1) /* Index of EOF symbol              */

#define No_of_symbols (No_of_chars + 1) /* Total number of symbols          */

/* TRANSLATION TABLES BETWEEN CHARACTERS AND SYMBOL INDEXES. */

static int char_to_index[No_of_chars];                 /* To index from character          */
static unsigned char index_to_char[No_of_symbols + 1]; /* To character from index    */

static int freq[No_of_symbols + 1];     /* Symbol frequencies                       */
static int cum_freq[No_of_symbols + 1]; /* Cumulative symbol frequencies            */

/* CUMULATIVE FREQUENCY TABLE. */

#define Max_frequency 16383 /* Maximum allowed frequency count  */

/* DECLARATIONS USED FOR ARITHMETIC ENCODING AND DECODING */

/* SIZE OF ARITHMETIC CODE VALUES. */

#define Code_value_bits 16 /* Number of bits in a code value   */
typedef long code_value;   /* Type of an arithmetic code value */

#define Top_value (((long)1 << Code_value_bits) - 1) /* Largest code value */

/* HALF AND QUARTER POINTS IN THE CODE VALUE RANGE. */

#define First_qtr (Top_value / 4 + 1) /* Point after first quarter        */
#define Half (2 * First_qtr)          /* Point after first half           */
#define Third_qtr (3 * First_qtr)     /* Point after third quarter        */

/* BIT INPUT ROUTINES. */

/* THE BIT BUFFER. */

static int buffer;       /* Bits waiting to be input                 */
static int bits_to_go;   /* Number of bits still in buffer           */
static int garbage_bits; /* Number of bits past end-of-file          */

/* INITIALIZE BIT INPUT. */

static void start_inputing_bits(void)
{
     bits_to_go = 0;   /* Buffer starts out with   */
     garbage_bits = 0; /* no bits in it.           */
}

/* INPUT A BIT. */

static int input_bit(void)
{
     int t;
     if (bits_to_go == 0)
     {                                     /* Read the next byte if no */
          buffer = getc(input_S2_file_dl); /* bits are left in buffer. */
          if (buffer == EOF)
          {
               garbage_bits += 1; /* Return arbitrary bits*/
               if (garbage_bits > Code_value_bits - 2)
               { /* after eof, but check */
                    /* for too many such.   */
                    return_value_dl = 30;
                    return 0;
                    // exit(-1);
               }
          }
          bits_to_go = 8;
     }
     t = buffer & 1; /* Return the next bit from */
     buffer >>= 1;   /* the bottom of the byte.  */
     bits_to_go -= 1;
     return t;
}

static void start_model(void);
static void start_decoding(void);
static int decode_symbol(int cum_freq[]);
static void update_model(int symbol);

static int __fastcall /* very fast call, the others are slow __cdecl and __stdcall and __thiscall */ main_decoder_ari_dl_internal(void)
{

     start_model(); /* Set up other modules.    */
     start_inputing_bits();
     start_decoding();

     if (return_value_dl)
     {
          return 30;
     }
     for (;;)
     { /* Loop through characters. */
          int ch;
          int symbol;
          symbol = decode_symbol(cum_freq); /* Decode next symbol.      */
          if (symbol == EOF_symbol)
               break;                 /* Exit loop if EOF symbol. */
          ch = index_to_char[symbol]; /* Translate to a character.*/

          putc((char)ch, output_S2_file_dl); /* Write that character.    */
          update_model(symbol);              /* Update the model.        */
     }
     // putc('\n', );
     return 0;
}

/* ARITHMETIC DECODING ALGORITHM. */

/* CURRENT STATE OF THE DECODING. */

static code_value value;     /* Currently-seen code value                */
static code_value low, high; /* Ends of current code region              */

/* START DECODING A STREAM OF SYMBOLS. */

static void start_decoding(void)
{
     int i;
     value = 0; /* Input bits to fill the   */
     for (i = 1; i <= Code_value_bits; i++)
     { /* code value.              */
          value = 2 * value + input_bit();

          if (return_value_dl)
          {
               return;
          }
     }
     low = 0; /* Full code range.         */
     high = Top_value;
}

/* DECODE THE NEXT SYMBOL. */

static int decode_symbol(int cum_freq[])
{
     long range; /* Size of current code region              */
     int cum;    /* Cumulative frequency calculated          */
     int symbol; /* Symbol decoded                           */
     range = (long)(high - low) + 1;
     cum = (int)/* Find cum freq for value. */
         ((((long)(value - low) + 1) * cum_freq[0] - 1) / range);
     for (symbol = 1; cum_freq[symbol] > cum; symbol++)
          ;                                                   /* Then find symbol. */
     high = low +                                             /* Narrow the code region   */
            (range * cum_freq[symbol - 1]) / cum_freq[0] - 1; /* to that allotted to this */
     low = low +                                              /* symbol.                  */
           (range * cum_freq[symbol]) / cum_freq[0];
     for (;;)
     { /* Loop to get rid of bits. */
          if (high < Half)
          {
               /* nothing */ /* Expand low half.         */
          }
          else if (low >= Half)
          { /* Expand high half.        */
               value -= Half;
               low -= Half; /* Subtract offset to top.  */
               high -= Half;
          }
          else if (low >= First_qtr /* Expand middle half.      */
                   && high < Third_qtr)
          {
               value -= First_qtr;
               low -= First_qtr; /* Subtract offset to middle*/
               high -= First_qtr;
          }
          else
               break; /* Otherwise exit loop.     */
          low = 2 * low;
          high = 2 * high + 1;             /* Scale up code range.     */
          value = 2 * value + input_bit(); /* Move in next input bit.  */
     }
     return symbol;
}

/* THE ADAPTIVE SOURCE MODEL */

/* INITIALIZE THE MODEL. */

static void start_model(void)
{
     int i;
     for (i = 0; i < No_of_chars; i++)
     {                                             /* Set up tables that       */
          char_to_index[i] = i + 1;                /* translate between symbol */
          index_to_char[i + 1] = (unsigned char)i; /* indexes and characters.  */
     }
     for (i = 0; i <= No_of_symbols; i++)
     {                                     /* Set up initial frequency */
          freq[i] = 1;                     /* counts to be one for all */
          cum_freq[i] = No_of_symbols - i; /* symbols.                 */
     }
     freq[0] = 0; /* Freq[0] must not be the  */
} /* same as freq[1].         */

/* UPDATE THE MODEL TO ACCOUNT FOR A NEW SYMBOL. */

static void update_model(int symbol)
{
     int i; /* New index for symbol                     */
     if (cum_freq[0] == Max_frequency)
     {             /* See if frequency counts  */
          int cum; /* are at their maximum.    */
          cum = 0;
          for (i = No_of_symbols; i >= 0; i--)
          {                                 /* If so, halve all the     */
               freq[i] = (freq[i] + 1) / 2; /* counts (keeping them     */
               cum_freq[i] = cum;           /* non-zero).               */
               cum += freq[i];
          }
     }
     for (i = symbol; freq[i] == freq[i - 1]; i--)
          ; /* Find symbol's new index. */
     if (i < symbol)
     {
          int ch_i, ch_symbol;
          ch_i = index_to_char[i];                     /* Update the translation   */
          ch_symbol = index_to_char[symbol];           /* tables if the symbol has */
          index_to_char[i] = (unsigned char)ch_symbol; /* moved.             */
          index_to_char[symbol] = (unsigned char)ch_i;
          char_to_index[ch_i] = symbol;
          char_to_index[ch_symbol] = i;
     }
     freq[i] += 1; /* Increment the frequency  */
     while (i > 0)
     {                      /* count for the symbol and */
          i -= 1;           /* update the cumulative    */
          cum_freq[i] += 1; /* frequencies.             */
     }
}

int __fastcall /* very fast call, the others are slow __cdecl and __stdcall and __thiscall */ main_decoder_ari_dl(
    FILE *input_S2_file_dl__,
    FILE *output_S2_file_dl__)
{

     return_value_dl = 0;

     input_S2_file_dl = input_S2_file_dl__;
     output_S2_file_dl = output_S2_file_dl__;
     main_decoder_ari_dl_internal();

     return return_value_dl;
}

void decompress_simple_dl(char *input_file_dl, char *output_file_dl)
{

     FILE *in__dl = fopen(input_file_dl, "rb");
     FILE *out_dl = fopen(output_file_dl, "wb");

     if (in__dl && out_dl)
     {
          main_decoder_ari_dl(in__dl, out_dl);
          fclose(in__dl);
          fclose(out_dl);
     }
}