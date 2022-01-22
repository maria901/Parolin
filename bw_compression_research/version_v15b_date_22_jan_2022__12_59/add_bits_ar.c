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

#ifndef _MSC_VER
#include  <stdbool.h>
#else 
#define bool	char
#define true	1
#define false	0

#define __attribute__(ricardo) /* unused */

#endif 
#include  <process.h>

void insert_bytes_and_bits_ar(__attribute__((unused)) uint8_t *data_ar,
                              __attribute__((unused)) int len_ar,
                              __attribute__((unused)) int bit_to_use_ar,
                              __attribute__((unused)) FILE *outfile_ar)
{
    bool already_pointer_ar = false;
    int i_ar;
    int i_ar2;
    __attribute__((unused)) unsigned int mask_dl;

        for (i_ar = 0; i_ar < len_ar; i_ar++)
        {

            /*






            */

            if (1 == bit_to_use_ar)
            {
                if (already_pointer_ar)
                {
                    goto pula_ric;
                }
            }

            already_pointer_ar = true;
            mask_dl = (1 << bit_deslocador_v12_ar);

            if (0 == bit_to_use_ar)
            {
                the_final_buffer_v12_ar &= ~(mask_dl);
            }
            else
            {
                the_final_buffer_v12_ar |= mask_dl;
            }
            count_of_bits_ar++;
            bit_deslocador_v12_ar++;
            if (8 == bit_deslocador_v12_ar)
            {
                putc(the_final_buffer_v12_ar,
                     outfile_ar);
                bit_deslocador_v12_ar = 0;
                the_final_buffer_v12_ar = 0;
            }
        pula_ric:;
            /*











            */

            for (i_ar2 = 0; i_ar2 < 8; i_ar2++)
            {
                /*






            */

                mask_dl = (1 << bit_deslocador_v12_ar);

                if (mask_dl & data_ar[i_ar]) // to set the bit 0 for a byte saved to the compressed stream
                {
                    the_final_buffer_v12_ar |= mask_dl;
                }
                else
                {
                    the_final_buffer_v12_ar &= ~(mask_dl);
                }
                count_of_bits_ar++;
                bit_deslocador_v12_ar++;
                if (8 == bit_deslocador_v12_ar)
                {
                    putc(the_final_buffer_v12_ar,
                         outfile_ar);
                    bit_deslocador_v12_ar = 0;
                    the_final_buffer_v12_ar = 0;
                }

                /*











                */
            }
        }
    
    return;
}
