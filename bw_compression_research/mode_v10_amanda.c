void buffer_to_file_amanda(char *file_amanda,
                       uint8_t *buffer_amanda,
                       uint32_t size_amanda);

assert(4096 >= address__amanda);

assert(18 >= string_size__amanda);

if (false == using_previous_buffer_amanda)
{
    temp_buffer_amanda = ptr_for_current_uncompressed_buffer_initial_position;
}
else
{
    //exit(90);
    temp_buffer_amanda = buffer_uncompressed_previous_amanda;
}

temp_buffer_amanda += address__amanda;

memcpy(temporary_bytes, temp_buffer_amanda, (int)string_size__amanda);

memcpy(current_uncompressed_buffer_ptr_amanda, temporary_bytes, (int)string_size__amanda);

current_uncompressed_buffer_ptr_amanda += (int)string_size__amanda;

bytes_already_in_uncompressed_buffer += (int)string_size__amanda;

if (4096 < bytes_already_in_uncompressed_buffer)
{
    // too much data added to uncompressed buffer
    return_value_amanda = 48;
    goto exit_ric_my_dear_amanda;
}

if (DEBUG_DEC_amanda__)
    pedro_dprintf(0, "pointer processing -> bytes in bytes_already_in_uncompressed_buffer %d %d string size", bytes_already_in_uncompressed_buffer,
                  (int)string_size__amanda);

if (DEBUG_DEC_amanda__)
{
    // assert(0 && "1");
}