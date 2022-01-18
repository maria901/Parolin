void buffer_to_file_dl(char *file_dl,
                       uint8_t *buffer_dl,
                       uint32_t size_dl);

assert(4096 >= address__dl);

assert(18 >= string_size__dl);

if (0 == bit_0_dl && 0 == bit_1_dl)
{
    temp_buffer_dl = ptr_for_current_uncompressed_buffer_initial_position;
}
else if(1 == bit_0_dl && 0 == bit_1_dl)
{
    //exit(90);
    temp_buffer_dl = buf_dl_0;
}
else if(0 == bit_0_dl && 1 == bit_1_dl)
{
    //exit(90);
    temp_buffer_dl = buf_dl_1;
}
else if(1 == bit_0_dl && 1 == bit_1_dl)
{
    //exit(90);
    temp_buffer_dl = buf_dl_2;
}
else
{
    assert(0 && "invalid bit value, ric...");
    temp_buffer_dl = NULL;
}

temp_buffer_dl += address__dl;

memcpy(temporary_bytes, temp_buffer_dl, (int)string_size__dl);

memcpy(current_uncompressed_buffer_ptr_dl, temporary_bytes, (int)string_size__dl);

current_uncompressed_buffer_ptr_dl += (int)string_size__dl;

bytes_already_in_uncompressed_buffer += (int)string_size__dl;

if (4096 < bytes_already_in_uncompressed_buffer)
{
    // too much data added to uncompressed buffer
    return_value_dl = 48;
    goto exit_ric_my_dear_dl;
}

if (DEBUG_DEC_DL__)
    pedro_dprintf(0, "pointer processing -> bytes in bytes_already_in_uncompressed_buffer %d %d string size", bytes_already_in_uncompressed_buffer,
                  (int)string_size__dl);

if (DEBUG_DEC_DL__)
{
    // assert(0 && "1");
}