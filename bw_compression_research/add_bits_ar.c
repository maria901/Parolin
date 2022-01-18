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

void insert_bytes_and_bits_ar(__attribute__((unused)) uint8_t *data_ar,
                              __attribute__((unused)) int len_ar,
                              __attribute__((unused)) int bit_to_use_ar,
                              __attribute__((unused)) FILE *outfile_ar)
{
    bool already_pointer_ar = false;
    int i_ar;
    int i_ar2;
    __attribute__((unused)) unsigned int mask_dl;

    if (0 == bit_to_use_ar)
    {
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
    }
    return;
}

void __fastcall convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(__attribute__((unused)) uint8_t *input_mem_dl,
                                                              __attribute__((unused)) uint8_t len_of_input_to_encode_as_you_may_expect_dl_, //
                                                              __attribute__((unused)) bool is_it_string_matched_in_past_buffer_dl,
                                                              __attribute__((unused)) uint16_t past_position_location_dl, //
                                                              __attribute__((unused)) uint8_t len_of_matched_string_dl,
                                                              __attribute__((unused)) bool using_previous_buffer_dl,
                                                              __attribute__((unused)) FILE *outfile_ar)
{

    uint16_t len_of_input_to_encode_as_you_may_expect_dl = len_of_input_to_encode_as_you_may_expect_dl_;
    uint16_t *ptr_uint16_dl;
    static uint8_t temp_dl[3 /* if in the future it was changed don't forget it ric... */];

    if (DEBUG_DL__)
        pedro_dprintf(0, "inside convert 8 a, size in input %d", len_of_input_to_encode_as_you_may_expect_dl);

    if (DEBUG_DL__)
        pedro_dprintf(0, "");

    if (DEBUG_DL__)
    {
        assert(0 && "parando");
    }

    if (false == is_it_string_matched_in_past_buffer_dl) // false é byte
    {
        if (DEBUG_DL__)
            pedro_dprintf(0, " len %d", len_of_input_to_encode_as_you_may_expect_dl);

        if (DEBUG_DL__)
        {
            assert(0 && "inside function");
        }

        insert_bytes_and_bits_ar(input_mem_dl,
                                 len_of_input_to_encode_as_you_may_expect_dl_,
                                 0,
                                 outfile_ar);
        return;
    }
    else
    {
        replacements_dl++;

        if (DEBUG_DL__)
            pedro_dprintf(0, "inside convert 8, mode is add pointer");

        if (DEBUG_DL__)
        {
            assert(0 && "inside function");
        }

        ptr_uint16_dl = (uint16_t *)&temp_dl[0];

        *ptr_uint16_dl = prepare_unsigned_short_int_12_jan_2022_v6_dl(len_of_matched_string_dl,
                                                                      past_position_location_dl);
        pedro_dprintf(-1, "encoded int16_t to save %i len e address %d %d", *ptr_uint16_dl,
                      (int)len_of_matched_string_dl,
                      (int)past_position_location_dl);

        len_of_input_to_encode_as_you_may_expect_dl = 2;
        insert_bytes_and_bits_ar(temp_dl,
                                 2,
                                 1,
                                 outfile_ar);
        return;
    }

    return;
}