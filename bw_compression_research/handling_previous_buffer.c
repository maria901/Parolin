if (-1 != result_dl_b) // if found in the previous
{

    largest_size_found_on_previous_buffer_dl = size_of_the_neddle_dl2_b;

try_again_magician_ric1:;

    if (MAX_STRING_SEARCH_SIZE_DL__ > size_of_the_neddle_dl2_b)
    {
        size_of_the_neddle_dl2_b += STRING_PASS_SIZE_DL__;

        if (MAX_STRING_SEARCH_SIZE_DL__ < size_of_the_neddle_dl2_b)
        {
            size_of_the_neddle_dl2_b = MAX_STRING_SEARCH_SIZE_DL__;
        }

        memcpy(needle_buf_dl_copy, position_of_the_data_in_the_input__stream_dl_original, size_of_the_neddle_dl2_b);

        // now search again
        result_temp_dl = mem_search_dl(buf_dl_b, DL_SIZE__,
                                       needle_buf_dl_copy,
                                       size_of_the_neddle_dl2_b,
                                       0);

        if (-1 == result_temp_dl)
        {
            ; // go try the standard method, but we already have thje largest size got in previous buffer
        }
        else
        {

            ;                             // try again
            result_dl_b = result_temp_dl; // if found in the previous the result_dl_b this variable will always keep the largest found in previous buffer

            largest_size_found_on_previous_buffer_dl = size_of_the_neddle_dl2_b;

            goto try_again_magician_ric1;
        }
    }
    else
    {
        ; // largest_size_found_on_previous_buffer_dl got the largest size got from buffer previous (v8)
    }

    // now see the version 1

    if (-1 == result_dl) // not found on current buffer
    {

        assert(-1 != result_dl_b);

        past_position_location_dl = (uint16_t)result_dl_b;

        size_real_for_number_of_characters_up_to_259_dl = (uint16_t)largest_size_found_on_previous_buffer_dl;

        // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

        // adjusting
        // size_real_for_number_of_characters_up_to_259_dl -= 4;

        size_of_characters_adjusted_to_pass_dl = (int8_t)size_real_for_number_of_characters_up_to_259_dl;

        // here ric my brother...
        convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL, // irrelevant
                                                      0,    // irrelevant
                                                      true,
                                                      past_position_location_dl,
                                                      size_of_characters_adjusted_to_pass_dl,
                                                      true); // (v8) now you use 8192 searching bytes and not 4096 due to an enhancement that we did, and this is just the beginning

        if (DEBUG_DL__)
            pedro_dprintf(0, "vai reiniciar o loop, bytes remaining %d", len_dl_copy);

        if (DEBUG_DL__)
        {
            assert(0 && "parando");
        }

        goto volta_aqui_mais_alto_mar; // just reinitiate, is it?
    }
    else
    {
        // increase search

    try_again_3_dl:;
        if (MAX_STRING_SEARCH_SIZE_DL__ > size_of_the_neddle_dl2)
        {

            size_of_the_neddle_dl2 += STRING_PASS_SIZE_DL__; // mais tarde da para ajustar isso

            if (MAX_STRING_SEARCH_SIZE_DL__ < size_of_the_neddle_dl2)
            {
                size_of_the_neddle_dl2 = MAX_STRING_SEARCH_SIZE_DL__;
            }

            // try with more data, better keep it here
            size_of_the_neddle_dl3 = min(bytes_left_in_the_input_uncompressed_stream_dl_original, size_of_the_neddle_dl2);

            if (size_of_the_neddle_dl3 == size_of_the_neddle_dl2) // more itens found, need to adjust if found
            {
                ; // do

                memcpy(needle_buf_dl_copy, position_of_the_data_in_the_input__stream_dl_original, size_of_the_neddle_dl3);

                // now search
                if (DEBUG_DL__)
                    pedro_dprintf(0, "valor do size_of_already_saw_data_dl_original %d, neddle size %d", size_of_already_saw_data_dl_original, size_of_the_neddle_dl3);

                result_temp_dl = mem_search_dl(buf_dl, size_of_already_saw_data_dl_original,
                                               needle_buf_dl_copy, size_of_the_neddle_dl3,
                                               0);

                if (-1 == result_temp_dl)
                {
                    ; // if not found larger stop here
                }
                else
                {
                    ; // here adjust, if no more is found it is already ready to adjust
                    already_found_with_larger_size_dl = true;
                    difference_of_the_new_loaded_data_dl = (size_of_already_saw_data_dl_original + size_of_the_neddle_dl3) - size_of_already_saw_data_dl;
                    result_dl = result_temp_dl;
                    last_found_position_dl = result_dl;
                    size_of_last_found_position_dl = size_of_the_neddle_dl3;
                    goto try_again_3_dl;
                }
            }
            else
            {
                ; // lets go
            }
        }

        if (already_found_with_larger_size_dl)
        {
            if (largest_size_found_on_previous_buffer_dl > size_of_last_found_position_dl)
            {
                // save ...
                assert(-1 != result_dl_b);

                past_position_location_dl = (uint16_t)result_dl_b;

                size_real_for_number_of_characters_up_to_259_dl = (uint16_t)largest_size_found_on_previous_buffer_dl;

                // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                // adjusting
                // size_real_for_number_of_characters_up_to_259_dl -= 4;

                size_of_characters_adjusted_to_pass_dl = (int8_t)size_real_for_number_of_characters_up_to_259_dl;

                // here ric my brother...
                convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL, // irrelevant
                                                              0,    // irrelevant
                                                              true,
                                                              past_position_location_dl,
                                                              size_of_characters_adjusted_to_pass_dl,
                                                              true); // (v8) now you use 8192 searching bytes and not 4096 due to an enhancement that we did, and this is just the beginning

                if (DEBUG_DL__)
                    pedro_dprintf(0, "vai reiniciar o loop, bytes remaining %d", len_dl_copy);

                if (DEBUG_DL__)
                {
                    assert(0 && "parando");
                }

                goto volta_aqui_mais_alto_mar; // just reinitiate, is it?
            }
            else
            {
                past_position_location_dl = (uint16_t)last_found_position_dl;

                size_real_for_number_of_characters_up_to_259_dl = (uint16_t)size_of_last_found_position_dl;

                // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                // adjusting
                // size_real_for_number_of_characters_up_to_259_dl -= 4;

                size_of_characters_adjusted_to_pass_dl = (int8_t)size_real_for_number_of_characters_up_to_259_dl;

                // here ric my brother...
                convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL, // irrelevant
                                                              0,    // irrelevant
                                                              true,
                                                              past_position_location_dl,
                                                              size_of_characters_adjusted_to_pass_dl,
                                                              false); // (v8) now you use 8192 searching bytes and not 4096 due to an enhancement that we did, and this is just the beginning

                size_of_already_saw_data_dl += difference_of_the_new_loaded_data_dl;

                position_of_the_data_in_the_input__stream_dl += difference_of_the_new_loaded_data_dl;

                progress_dl += difference_of_the_new_loaded_data_dl;

                hay_ptr_dl += difference_of_the_new_loaded_data_dl;

                len_dl_copy -= difference_of_the_new_loaded_data_dl;

                assert(0 <= len_dl_copy);

                bytes_left_in_the_input_uncompressed_stream_dl -= difference_of_the_new_loaded_data_dl;

                already_found_with_larger_size_dl = false;
                // when searching just change the size of the needle, if already found

                if (DEBUG_DL__)
                    pedro_dprintf(0, "vai reiniciar o depois de usar modo com mais dados de string, current buffer, bytes remaining %d", len_dl_copy);

                if (DEBUG_DL__)
                {
                    assert(0 && "parando");
                }

                goto volta_aqui_mais_alto_mar;
            }
        }
        else
        {
            if (largest_size_found_on_previous_buffer_dl > size_of_the_neddle_dl)
            {
                assert(-1 != result_dl_b);

                past_position_location_dl = (uint16_t)result_dl_b;

                size_real_for_number_of_characters_up_to_259_dl = (uint16_t)largest_size_found_on_previous_buffer_dl;

                // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                // adjusting
                // size_real_for_number_of_characters_up_to_259_dl -= 4;

                size_of_characters_adjusted_to_pass_dl = (int8_t)size_real_for_number_of_characters_up_to_259_dl;

                // here ric my brother...
                convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL, // irrelevant
                                                              0,    // irrelevant
                                                              true,
                                                              past_position_location_dl,
                                                              size_of_characters_adjusted_to_pass_dl,
                                                              true); // (v8) now you use 8192 searching bytes and not 4096 due to an enhancement that we did, and this is just the beginning

                if (DEBUG_DL__)
                    pedro_dprintf(0, "vai reiniciar o loop, bytes remaining %d", len_dl_copy);

                if (DEBUG_DL__)
                {
                    assert(0 && "parando");
                }

                goto volta_aqui_mais_alto_mar; // just reinitiate, is it?
            }
            else
            {
                past_position_location_dl = (uint16_t)result_dl2;

                size_real_for_number_of_characters_up_to_259_dl = (uint16_t)size_of_the_neddle_dl;

                if (DEBUG_DL__)
                    pedro_dprintf(0, "size %d", size_of_the_neddle_dl);
                // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

                // size_real_for_number_of_characters_up_to_259_dl -= 4;

                size_of_characters_adjusted_to_pass_dl = (uint8_t)
                    size_real_for_number_of_characters_up_to_259_dl;

                convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL,
                                                              0,
                                                              true,
                                                              past_position_location_dl,
                                                              size_of_characters_adjusted_to_pass_dl,
                                                              false); // (v8)

                goto volta_aqui_mais_alto_mar;
            }
        }
    }

    // ok now what...
    if (DEBUG_DL__)
        pedro_dprintf(0, "definiu que o maior achado é %d", size_of_the_neddle_dl2);

    if (DEBUG_DL__)
    {
        assert(0 && "parando");
    }
}