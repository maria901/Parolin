//
//  ARI.CPP
//
//  Mark Nelson
//  March 8, 1996
//  http://web2.airmail.net/markn
//
// DESCRIPTION
// -----------
//
//  This program performs an order-0 adaptive arithmetic encoding
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
//  file system into binary mode.  g++ already does this, and your
//  UNIX C++ compiler might also.
//
//  Borland C++ 4.5 16 bit    : bcc -w ari.cpp
//  Borland C++ 4.5 32 bit    : bcc32 -w ari.cpp
//  Microsoft Visual C++ 1.52 : cl /W4 ari.cpp
//  Microsoft Visual C++ 2.1  : cl /W4 ari.cpp
//  g++                       : g++ -o ari ari.cpp
//
// Typical Use
// -----------
//
//  rle < raw-file | bwt | mtf | rle | ari > compressed-file
//
//
// 2022 dl & ric
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

#include <process.h>

#include <stdio.h>
#include <stdlib.h>
#if !defined(unix)
#include <io.h>
#endif
#include <fcntl.h>

void pedro_dprintf(int amanda_level,
                   char *format, ...);

static FILE *in_file_dl2;
static FILE *out_file_dl2;

int __cdecl getc_ric(void)
{
    return getc(in_file_dl2);
}

int __cdecl putc_ric(int _Ch, FILE *_File)
{
    (void)_File;
    return putc(_Ch, out_file_dl2);
}

#define No_of_chars 256              /* Number of character symbols      */
#define EOF_symbol (No_of_chars + 1) /* Index of EOF symbol              */

#define No_of_symbols (No_of_chars + 1) /* Total number of symbols          */

/* TRANSLATION TABLES BETWEEN CHARACTERS AND SYMBOL INDEXES. */

int char_to_index[No_of_chars];                 /* To index from character          */
unsigned char index_to_char[No_of_symbols + 1]; /* To character from index    */

/* ADAPTIVE SOURCE MODEL */

int freq[No_of_symbols + 1];     /* Symbol frequencies                       */
int cum_freq[No_of_symbols + 1]; /* Cumulative symbol frequencies            */

/* DECLARATIONS USED FOR ARITHMETIC ENCODING AND DECODING */

/* SIZE OF ARITHMETIC CODE VALUES. */

#define Code_value_bits 16 /* Number of bits in a code value   */
typedef long code_value;   /* Type of an arithmetic code value */

#define Top_value (((long)1 << Code_value_bits) - 1) /* Largest code value */

/* HALF AND QUARTER POINTS IN THE CODE VALUE RANGE. */

#define First_qtr (Top_value / 4 + 1) /* Point after first quarter        */
#define Half (2 * First_qtr)          /* Point after first half           */
#define Third_qtr (3 * First_qtr)     /* Point after third quarter        */

/* CUMULATIVE FREQUENCY TABLE. */

#define Max_frequency 16383 /* Maximum allowed frequency count  */

extern int cum_freq[No_of_symbols + 1]; /* Cumulative symbol frequencies    */

void start_model(void);
void start_encoding(void);
void encode_symbol(int symbol, int cum_freq[]);
void update_model(int symbol);
void done_encoding(void);
void done_outputing_bits(void);

/* BIT OUTPUT ROUTINES. */

/* THE BIT BUFFER. */

int buffer;     /* Bits buffered for output                 */
int bits_to_go; /* Number of bits free in buffer            */

/* INITIALIZE FOR BIT OUTPUT. */

void start_outputing_bits(void)
{
    buffer = 0;     /* Buffer is empty to start */
    bits_to_go = 8; /* with.                    */
}

/* OUTPUT A BIT. */

inline void output_bit(int bit)
{
    buffer >>= 1;
    if (bit)
        buffer |= 0x80; /* Put bit in top of buffer.*/
    bits_to_go -= 1;
    if (bits_to_go == 0)
    {                                   /* Output buffer if it is   */
        putc_ric((char)buffer, stdout); /* now full.                */
        bits_to_go = 8;
    }
}

/* FLUSH OUT THE LAST BITS. */

void done_outputing_bits(void)
{
    putc_ric((char)(buffer >> bits_to_go), stdout);
}

/* CURRENT STATE OF THE ENCODING. */

code_value low, high; /* Ends of the current code region          */
long bits_to_follow;  /* Number of opposite bits to output after  */
                      /* the next bit.                            */
/* OUTPUT BITS PLUS FOLLOWING OPPOSITE BITS. */

void bit_plus_follow(int bit)
{
    output_bit(bit); /* Output the bit.          */
    while (bits_to_follow > 0)
    {
        output_bit(!bit);    /* Output bits_to_follow    */
        bits_to_follow -= 1; /* opposite bits. Set       */
    }                        /* bits_to_follow to zero.  */
}

int main_do_mr_do(void)
{
    // int ticker = 0;
    bits_to_follow = 0;
    // fprintf(stderr, "Arithmetic coding on ");

    start_model(); /* Set up other modules.    */
    start_outputing_bits();
    start_encoding();
    for (;;)
    { /* Loop through characters. */

        pedro_dprintf(-20220110, "begiN...");
        int ch;
        int symbol;
        /*
        if ((ticker++ % 1024) == 0)
            putc('.', stderr);
            */
        ch = getc_ric(); /* Read the next character. */
        pedro_dprintf(-20220110, "1...");
        if (ch == EOF)
            break; /* Exit loop on end-of-file.*/
        pedro_dprintf(-20220110, "2...%d", ch);
        symbol = char_to_index[ch]; /* Translate to an index.   */
        pedro_dprintf(-20220110, "3...");
        encode_symbol(symbol, cum_freq); /* Encode that symbol.      */
        pedro_dprintf(-20220110, "4...");
        update_model(symbol); /* Update the model.        */
        pedro_dprintf(-20220110, "enD...");
    }
    pedro_dprintf(-20220110, "enD real...");
    encode_symbol(EOF_symbol, cum_freq); /* Encode the EOF symbol.   */
    done_encoding();                     /* Send the last few bits.  */
    done_outputing_bits();
    // putc('\n', stderr);
    pedro_dprintf(-20220110, "last call in the function...");
    return 0;
}

/* ARITHMETIC ENCODING ALGORITHM. */

/* START ENCODING A STREAM OF SYMBOLS. */

void start_encoding(void)
{
    low = 0; /* Full code range.         */
    high = Top_value;
    bits_to_follow = 0; /* No bits to follow next.  */
}

/* ENCODE A SYMBOL. */

void encode_symbol(int symbol, int cum_freq[])
{
    long range; /* Size of the current code region          */
    range = (long)(high - low) + 1;
    high = low +                                             /* Narrow the code region   */
           (range * cum_freq[symbol - 1]) / cum_freq[0] - 1; /* to that allotted to this */
    low = low +                                              /* symbol.                  */
          (range * cum_freq[symbol]) / cum_freq[0];
    for (;;)
    { /* Loop to output bits.     */
        if (high < Half)
        {
            bit_plus_follow(0); /* Output 0 if in low half. */
        }
        else if (low >= Half)
        { /* Output 1 if in high half.*/
            bit_plus_follow(1);
            low -= Half;
            high -= Half; /* Subtract offset to top.  */
        }
        else if (low >= First_qtr /* Output an opposite bit   */
                 && high < Third_qtr)
        { /* later if in middle half. */
            bits_to_follow += 1;
            low -= First_qtr; /* Subtract offset to middle*/
            high -= First_qtr;
        }
        else
            break; /* Otherwise exit loop.     */
        low = 2 * low;
        high = 2 * high + 1; /* Scale up code range.     */
    }
}

/* FINISH ENCODING THE STREAM. */

void done_encoding(void)
{
    bits_to_follow += 1; /* Output two bits that     */
    if (low < First_qtr)
        bit_plus_follow(0); /* select the quarter that  */
    else
        bit_plus_follow(1); /* the current code range   */
} /* contains.                */

/* THE ADAPTIVE SOURCE MODEL */

/* INITIALIZE THE MODEL. */

void start_model(void)
{
    int i;
    for (i = 0; i < No_of_chars; i++)
    {                                            /* Set up tables that       */
        char_to_index[i] = i + 1;                /* translate between symbol */
        index_to_char[i + 1] = (unsigned char)i; /* indexes and characters.  */
    }
    for (i = 0; i <= No_of_symbols; i++)
    {                                    /* Set up initial frequency */
        freq[i] = 1;                     /* counts to be one for all */
        cum_freq[i] = No_of_symbols - i; /* symbols.                 */
    }
    freq[0] = 0; /* Freq[0] must not be the  */
} /* same as freq[1].         */

/* UPDATE THE MODEL TO ACCOUNT FOR A NEW SYMBOL. */

void update_model(int symbol)
{
    int i; /* New index for symbol                     */
    if (cum_freq[0] == Max_frequency)
    {            /* See if frequency counts  */
        int cum; /* are at their maximum.    */
        cum = 0;
        for (i = No_of_symbols; i >= 0; i--)
        {                                /* If so, halve all the     */
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
        index_to_char[i] = (unsigned char)ch_symbol; /* moved.                   */
        index_to_char[symbol] = (unsigned char)ch_i;
        char_to_index[ch_i] = symbol;
        char_to_index[ch_symbol] = i;
    }
    freq[i] += 1; /* Increment the frequency  */
    while (i > 0)
    {                     /* count for the symbol and */
        i -= 1;           /* update the cumulative    */
        cum_freq[i] += 1; /* frequencies.             */
    }
}

/**
 * @brief Amazing day... just creted something interesting he he he, well this will mkae the final
 * pass on the v7 and above compressor with arithmetic coding, thanks for uing our software
 *
 * @return int
 */
int main_dl(__attribute__((unused)) int size_of_header_dl, __attribute__((unused)) char *memory_to_add_dl, char *input_file_dl, char *output_file_dl)
{
    int return_value_dl = 0;
    FILE *in_file_dl = fopen(input_file_dl, "rb");

    if (in_file_dl)
    {

        FILE *out_file_dl = fopen(output_file_dl, "wb");
        {
            if (out_file_dl)
            {
                in_file_dl2 = in_file_dl;
                out_file_dl2 = out_file_dl;

                fwrite(memory_to_add_dl, 1, size_of_header_dl, out_file_dl);

                main_do_mr_do();
                return_value_dl = 0;
                fclose(out_file_dl);
            }
            else
            {
                printf("Cannot open output file\n");
                return_value_dl = 27;
            }
        }
        fclose(in_file_dl);
    }
    else
    {
        printf("Cannot open input file\n");
        return_value_dl = 28;
    }

    return return_value_dl;
}


/**
 * @brief Amazing day... just creted something interesting he he he, well this will mkae the final
 * pass on the v7 and above compressor with arithmetic coding, thanks for uing our software
 *
 * @return int
 */
int main_dl_pure(char *input_file_dl, char *output_file_dl)
{
    int return_value_dl = 0;
    FILE *in_file_dl = fopen(input_file_dl, "rb");

    if (in_file_dl)
    {

	 FILE *out_file_dl = fopen(output_file_dl, "wb");
	 {
	      if (out_file_dl)
	      {              
		   in_file_dl2 = in_file_dl;
		   out_file_dl2 = out_file_dl;
		
		   main_do_mr_do();
		   return_value_dl = 0;
		   fclose(out_file_dl);
	      }
	      else
	      {
		   printf("Cannot open output file\n");
		   return_value_dl = 27;
	      }
	 }
	 fclose(in_file_dl);
    }
    else
    {
        printf("Cannot open input file\n");
        return_value_dl = 28;
    }

    return return_value_dl;
}
