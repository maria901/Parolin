void buffer_to_file_dl(char *file_dl,
                       uint8_t *buffer_dl,
                       uint32_t size_dl);

assert(4096 >= address__dl);

assert(18 >= string_size__dl);

// ptr_for_current_uncompressed_buffer_initial_position

// bytes_already_in_uncompressed_buffer

temp_buffer_dl = ptr_for_current_uncompressed_buffer_initial_position;

temp_buffer_dl += address__dl;

// pedro_dprintf(0, "endereco %hd for size", address__dl);

//memset(temporary_bytes, 0, MAX_STRING_SEARCH_SIZE_DL__ + 3);

memcpy(temporary_bytes, temp_buffer_dl, (int)string_size__dl);

/*
              pedro_dprintf(0, "endereco %hd for size %d for data copied -%s-", address__dl,
              (int)string_size__dl,
              temporary_bytes);
*/

/*
    buffer_to_file_dl("antes.iu",buffer_uncompressed_current_dl,bytes_already_in_uncompressed_buffer);
*/

memcpy(current_uncompressed_buffer_ptr_dl, temporary_bytes, (int)string_size__dl);

current_uncompressed_buffer_ptr_dl += (int)string_size__dl;

bytes_already_in_uncompressed_buffer += (int)string_size__dl;

//buffer_to_file_dl("depois.iu", buffer_uncompressed_current_dl, //bytes_already_in_uncompressed_buffer);

if (4096 < bytes_already_in_uncompressed_buffer)
{
    // too much data added to uncompressed buffer
    return_value_dl = 48;
    goto exit_ric_my_dear_dl;
}

// assert(0 && "processed pointer, continue? ");

if (DEBUG_DEC_DL__)
    pedro_dprintf(0, "pointer processing -> bytes in bytes_already_in_uncompressed_buffer %d %d string size", bytes_already_in_uncompressed_buffer,
                  (int)string_size__dl);

if (DEBUG_DEC_DL__)
{
    // assert(0 && "1");
}