
unsigned __stdcall my_thread_function(void *my_argument_z);
unsigned __stdcall my_thread_function(void *my_argument_z)
{
    int64_t size_of_compressed_z = 0;

    my_thread_struct_z *ptr_my_struct_z = my_argument_z;

    if (NULL == ptr_my_struct_z)
    {
        exit(123);
    }

    assert(my_argument_z);

    bytes__read_thread_z[ptr_my_struct_z->thread_id_z] = 0x0;

    if (NULL == ptr_my_struct_z->input_file)
    {
        ptr_my_struct_z->retvalue = 7;
        goto saida_arp;
    }

    if (NULL == ptr_my_struct_z->dest) //ta ok
    {
        goto saida_arp;
    }

    pedro_dprintf(-1, "my thread running %x \n", my_argument_z);

    pedro_dprintf(-1, "offset %lld\n", ptr_my_struct_z->offset_z);

    if (0 != ptr_my_struct_z->offset_z)
    {
        if (
            0 != _fseeki64(
                     ptr_my_struct_z->input_file,
                     ptr_my_struct_z->offset_z,
                     SEEK_SET))
        {
            ptr_my_struct_z->retvalue = 403; //File access error
            goto saida;
        }
    }

    pedro_dprintf(-1, "slice %lld\n", ptr_my_struct_z->size_of_input_file_z);

    //veja_z += ptr_my_struct_z->size_of_input_file_z;

    //pedro_dprintf(-1, "tamanho apos slices %lld\n", veja_z);

    pedro_dprintf(-1, "position before %lld\n", _ftelli64(ptr_my_struct_z->dest));

    ptr_my_struct_z->ret = fwrite(&ptr_my_struct_z->ar, 1, sizeof(ptr_my_struct_z->ar), ptr_my_struct_z->dest);

    if (sizeof(ptr_my_struct_z->ar) != ptr_my_struct_z->ret)
    {
        ptr_my_struct_z->retvalue = 14; //unexpected error
        goto saida;
    }

    //deu...

    ptr_my_struct_z->ret = fwrite(&size_of_compressed_z, 1, sizeof(size_of_compressed_z), ptr_my_struct_z->dest);

    if (sizeof(size_of_compressed_z) != ptr_my_struct_z->ret)
    {
        ptr_my_struct_z->retvalue = 14; //unexpected error
        goto saida;
    }

    pedro_dprintf(-1, "position after %lld\n", _ftelli64(ptr_my_struct_z->dest));

    int64_t infile_remaining = ptr_my_struct_z->size_of_input_file_z;

    for (;;)
    {

        while (pauseflag)
        {

            Sleep(50);

            if (cancelflag)
            {
                goto saida;
            }
        }

        if (cancelflag)
        {
            goto saida;
        }

        // Input buffer is empty, so read more bytes from input file.
        int64_t n = min(CHUNK_k__p, infile_remaining);

        ptr_my_struct_z->ret = fread(ptr_my_struct_z->buffer, 1, n, ptr_my_struct_z->input_file);

        if (0 == ptr_my_struct_z->ret)
        {
            goto saida;
        }

        if (ptr_my_struct_z->ret != n)
        {
            ptr_my_struct_z->retvalue = 402; //Cannot read from input file
            goto saida;
        }

        if (0 > ptr_my_struct_z->ret)
        {
            ptr_my_struct_z->retvalue = 402; //Cannot read from input file
            goto saida;
        }
        /*
                if (0 == ptr_my_struct_z->ret)
                {
                        goto saida;
                }
 */

        infile_remaining -= n;
        //printf("Input bytes remaining: %u\n", infile_remaining);

        ptr_my_struct_z->bytesread = ptr_my_struct_z->bytesread + ptr_my_struct_z->ret;

        bytes__read_thread_z[ptr_my_struct_z->thread_id_z] = ptr_my_struct_z->bytesread;
    }

saida:;

    pedro_dprintf(-1, "saida %d bytes written %d\n", ptr_my_struct_z->retvalue, (int)size_of_compressed_z);

    if (ptr_my_struct_z->size_of_input_file_z && (0 == ptr_my_struct_z->retvalue))
    {
        if (0 != infile_remaining && (0 == cancelflag))
        {
            ptr_my_struct_z->retvalue = 160;
        }
    }

    if (ptr_my_struct_z->dest)
    {
        fclose(ptr_my_struct_z->dest);
        ptr_my_struct_z->dest = NULL;
    }

    if (0 == ptr_my_struct_z->retvalue)
    {
        if (unicodemode)
        {
            ptr_my_struct_z->dest = _wfopen(permissive_name_m_(amanda_utf8towide_1_(temp_files_z[ptr_my_struct_z->thread_id_z])), L"rb+");
        }

        if (0 == ptr_my_struct_z->dest)
        {
            ptr_my_struct_z->retvalue = 8;
        }
        else
        {

            ptr_my_struct_z->ret = fwrite(&ptr_my_struct_z->ar, 1, sizeof(ptr_my_struct_z->ar), ptr_my_struct_z->dest);

            if (ptr_my_struct_z->ret != sizeof(ptr_my_struct_z->ar))
            {
                ptr_my_struct_z->retvalue = 14;
            }

            ptr_my_struct_z->ret = fwrite(&size_of_compressed_z, 1, sizeof(size_of_compressed_z), ptr_my_struct_z->dest);

            if (ptr_my_struct_z->ret != sizeof(size_of_compressed_z))
            {
                ptr_my_struct_z->retvalue = 14;
            }
        }
    }

    if (ptr_my_struct_z->dest)
    {
        fclose(ptr_my_struct_z->dest);
        ptr_my_struct_z->dest = NULL;
    }

    if (cancelflag)
    {
        ptr_my_struct_z->retvalue = 19;
    }

saida_arp:;

    if (ptr_my_struct_z->dest)
    {

        fclose(ptr_my_struct_z->dest);
    }
    if (ptr_my_struct_z->input_file)
    {
        fclose(ptr_my_struct_z->input_file);
    }
    if (ptr_my_struct_z->buffer)
    {
        free(ptr_my_struct_z->buffer);
    }
    if (ptr_my_struct_z->out)
    {
        free(ptr_my_struct_z->out);
    }

    if (0 == thread_return_value_z)
    {
        thread_return_value_z = ptr_my_struct_z->retvalue;
    }
    pedro_dprintf(0, "veja %d %d\n", (int)thread_return_value_z, (int)ptr_my_struct_z->retvalue);
    free(my_argument_z);
    _endthreadex(0);

    return 0;
}
