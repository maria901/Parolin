if (-1 != result_dl) // if found in the previous
{

    past_position_location_dl = (uint16_t) result_dl;

    size_real_for_number_of_characters_up_to_259_dl = (uint16_t)max_size_string_from_buffer_current;

    // assert(4 <= size_real_for_number_of_characters_up_to_259_dl);

    // adjusting
    // size_real_for_number_of_characters_up_to_259_dl -= 4;

    size_of_characters_adjusted_to_pass_dl = (int8_t)size_real_for_number_of_characters_up_to_259_dl;

    // here ric my brother...
    convert_8_bits_to_nine_bits_12_jan_2022_v6_dl(NULL, // irrelevant
                                                  0,    // irrelevant
                                                  true,
                                                  past_position_location_dl,
                                                  size_of_characters_adjusted_to_pass_dl); // (v8) now you use 8192 searching bytes and not 4096 due to an enhancement that we did, and this is just the beginning

    // when searching just change the size of the needle, if already found

    if (DEBUG_DL__)
        pedro_dprintf(0, "vai reiniciar o depois de usar modo com mais dados de string, current buffer, bytes remaining %d", len_dl_copy);

    if (DEBUG_DL__)
    {
        assert(0 && "parando");
    }

    goto volta_aqui_mais_alto_mar;
}
