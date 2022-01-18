void buffer_to_file_dl(char *file_dl,
                       uint8_t *buffer_dl,
                       uint32_t size_dl);

assert(4096 >= address__dl);

assert(18 >= string_size__dl);

if (false == using_previous_buffer_dl)
{
    temp_buffer_dl = ptr_for_current_uncompressed_buffer_initial_position;
}
else
{
    //exit(90);
    temp_buffer_dl = buffer_uncompressed_previous_dl;
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