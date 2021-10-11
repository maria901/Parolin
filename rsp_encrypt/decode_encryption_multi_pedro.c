/********************************************************************************
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 ********************************************************************************
 
      E-mails:                                                                 
      maria@arsoftware.net.br                                                  
      pedro@locacaodiaria.com.br                                               

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 *******************************************************************************/

static uint64_t bytes_in_each_slice_z[129];
static uint64_t offset_of_each_slice_z[129];
static unsigned char the_sha512_got_maria[129][64];

static int detected_encryption_method_p;

unsigned __stdcall my_thread_function_v270(void *my_argument_z)
{
    char *rc6_buffer = NULL;
    char *twofish_buffer = NULL;

    char key_v2[300] = {
        0,
    };
    int64_t datasaved_m = 0;
    int ret_m, n, infile_remaining;
    my_thread_struct_z *ptr_my_struct_z = (void *)my_argument_z;
    assert(ptr_my_struct_z);
    if (NULL == ptr_my_struct_z->dest)
    {
        goto saida_amanda;
    }

    pedro_dprintf(-1, "bytes to extract %lld\n", ptr_my_struct_z->size_of_input_file_copy_z);

    if (0 != ptr_my_struct_z->offset_z)
    {

        pedro_dprintf(-1, "seek to %lld\n", ptr_my_struct_z->offset_z);

        if (
            0 != _fseeki64(
                     ptr_my_struct_z->input_file,
                     ptr_my_struct_z->offset_z,
                     SEEK_SET))
        {
            ptr_my_struct_z->retvalue = 4019; //File access error
            goto saida_amanda;
        }
    }

    //aqui amor...

    ptr_my_struct_z->dest_is_FILE_z = true;

    /*
      ptr_my_struct_z->retvalue = zuncompress_sha512_k_mt_decoding_multi_thread_z(ptr_my_struct_z->input_file, NULL, ptr_my_struct_z);
*/
    ptr_my_struct_z->buffer = malloc(CHUNK_k__p);
    ptr_my_struct_z->out = malloc(CHUNK_k__p);
    ptr_my_struct_z->init_aes = 1;

    switch (detected_encryption_method_p)
    {
    case ARP_AES_MT:

        break;
    case ARP_RC4_MT:
        strncpy(key_v2, (char *)ptr_my_struct_z->key_k__p, 32);
        rc4_setup(&ptr_my_struct_z->rc4s, (uchar *)key_v2, 256);
        break;
    case ARP_SERPENT_MT:
        init_serpent_v27((char *)ptr_my_struct_z->key_k__p,
                         ptr_my_struct_z);
        break;
    case ARP_MARS_MT:
        init_mars_arp_v27((char *)ptr_my_struct_z->key_k__p,
                          ptr_my_struct_z);
        break;
    case ARP_RC6_MT:
        /*
          init_mars_arp_v27((char *)ptr_my_struct_z->key_k__p,
          ptr_my_struct_z);
          */

        rc6_buffer = calloc(get_size_minha_struct_m(), 1);

        init_rc6__arp_v27((char *)ptr_my_struct_z->key_k__p,
                          rc6_buffer);

        break;
    case ARP_TWOFISH_MT:

        twofish_buffer = calloc(get_size_of_struct_twofish_m(), 1);

        init_twofish_arp_maria_v27((char *)ptr_my_struct_z->key_k__p,
                                   twofish_buffer);

        break;
    default:
        pedro_dprintf(1001, "Invalid format or method\n");
        exit(27);
        break;
    }

    infile_remaining = ptr_my_struct_z->size_of_input_file_z;

    for (;;)
    {
        ;

        n = min(infile_remaining, CHUNK_k__p);

        ptr_my_struct_z->ret = fread(ptr_my_struct_z->buffer, 1, n, ptr_my_struct_z->input_file);

        if (0 == ptr_my_struct_z->ret)
        {
            goto saida_amanda;
        }

        if (ptr_my_struct_z->ret != n)
        {
            ptr_my_struct_z->retvalue = 4020; //Cannot read from input file
            goto saida_amanda;
        }

        infile_remaining -= n;

        if (bytes_read_arp)
        {
            *bytes_read_arp += n / 2;
        }

        bytes_read_z += n / 2;

        switch (detected_encryption_method_p)
        {
        case ARP_AES_MT:
            encryptstring2_pedro((void *)ptr_my_struct_z->buffer,
                                 (void *)ptr_my_struct_z->key_k__p,
                                 (void *)ptr_my_struct_z->out,
                                 n,
                                 0,
                                 ptr_my_struct_z);
            ret_m = fwrite(ptr_my_struct_z->out, 1, n, ptr_my_struct_z->dest);

            if (ret_m != n)
            {
                ptr_my_struct_z->retvalue = 4030; //File access error
                goto saida_amanda;
            }

            datasaved_m += n;

            break;
        case ARP_RC4_MT:
            rc4_crypt(&ptr_my_struct_z->rc4s, (void *)ptr_my_struct_z->buffer, n);
            ret_m = fwrite((void *)ptr_my_struct_z->buffer, 1, n, ptr_my_struct_z->dest);

            if (ret_m != n)
            {
                ptr_my_struct_z->retvalue = 4030; //File access error
                goto saida_amanda;
            }
            break;
        case ARP_SERPENT_MT:
            encryptstring_serpent_v27((void *)ptr_my_struct_z->buffer,
                                      (void *)ptr_my_struct_z->out,
                                      (void *)ptr_my_struct_z->key_k__p,
                                      n,
                                      ptr_my_struct_z);

            ret_m = fwrite(ptr_my_struct_z->out, 1, n, ptr_my_struct_z->dest);

            if (ret_m != n)
            {
                ptr_my_struct_z->retvalue = 4030; //File access error
                goto saida_amanda;
            }
            break;
        case ARP_MARS_MT:
            encryptstring_mars_arp_v27((void *)ptr_my_struct_z->buffer,
                                       (void *)ptr_my_struct_z->out,
                                       (void *)ptr_my_struct_z->key_k__p,
                                       n,
                                       ptr_my_struct_z);

            ret_m = fwrite(ptr_my_struct_z->out, 1, n, ptr_my_struct_z->dest);

            if (ret_m != n)
            {
                ptr_my_struct_z->retvalue = 4030; //File access error
                goto saida_amanda;
            }
            break;
        case ARP_RC6_MT:
            encryptstring_rc6_arp_v27((void *)ptr_my_struct_z->buffer,
                                      (void *)ptr_my_struct_z->out,
                                      (void *)ptr_my_struct_z->key_k__p,
                                      n,
                                      rc6_buffer);
            ret_m = fwrite(ptr_my_struct_z->out, 1, n, ptr_my_struct_z->dest);
            if (ret_m != n)
            {
                ptr_my_struct_z->retvalue = 4030; //File access error
                goto saida_amanda;
            }
            break;
        case ARP_TWOFISH_MT:
            encryptstring_twofish_arp_maria_v27((void *)ptr_my_struct_z->buffer,
                                                (void *)ptr_my_struct_z->out,
                                                (void *)ptr_my_struct_z->key_k__p,
                                                n,
                                                twofish_buffer);
            ret_m = fwrite(ptr_my_struct_z->out, 1, n, ptr_my_struct_z->dest);
            if (ret_m != n)
            {
                ptr_my_struct_z->retvalue = 4030; //File access error
                goto saida_amanda;
            }
            break;
        }
        while ((*(ptr_my_struct_z->intpause)))
        {
            Sleep(50);
            if (*(ptr_my_struct_z->intcancel))
            {
                ptr_my_struct_z->retvalue = 119; //User abort
                goto saida_amanda;
            }
        }
        if (*(ptr_my_struct_z->intcancel))
        {
            ptr_my_struct_z->retvalue = 119; //User abort
            goto saida_amanda;
        }
    }

saida_amanda:;

    if (ptr_my_struct_z->dest)
    {
        fclose(ptr_my_struct_z->dest);
        ptr_my_struct_z->dest = NULL;
    }

    if (*(ptr_my_struct_z->intcancel))
    {
        ptr_my_struct_z->retvalue = 119; //User abort
    }

    if (ptr_my_struct_z->input_file)
    {
        fclose(ptr_my_struct_z->input_file);
    }

    if (0 == thread_return_value_z)
    {
        thread_return_value_z = ptr_my_struct_z->retvalue;
    }
    if (ptr_my_struct_z->buffer)
    {
        free(ptr_my_struct_z->buffer);
    }

    if (ptr_my_struct_z->out)
    {
        free(ptr_my_struct_z->out);
    }

    if (twofish_buffer)
    {
        free(twofish_buffer);
    }

    if (rc6_buffer)
    {
        free(rc6_buffer);
    }

    pedro_dprintf(-1, "&&&&Data saved %lld\n", datasaved_m);

    //Sleep(2000);

    free(my_argument_z);
    _endthreadex(0);

    return 27 + 51;
}

__int64
getfilesize_ar(char *infile_ar)
{
    __int64 ret;
    FILE *myfile;
    {

        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
        WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
        if ((myfile = _wfopen(permissive_name_m_(amanda_utf8towide_1_(infile_ar, ar_temp), ar_temp2), L"rb")) == NULL)
        {
            free(ar_temp);
            free(ar_temp2);
            return 0;
        }
        ret = _fseeki64(myfile, 0, SEEK_END);
        ret = _ftelli64(myfile);
        fclose(myfile);

        free(ar_temp);
        free(ar_temp2);
    }
    return ret;
}
int __fastcall unencrypt_multi_thread_m(char *input_z,
                                        char *output_z,
                                        char *password_v_,
                                        int *cores_S2__)
{
    my_thread_struct_z *ptr_my_struct_z;
    FILE *dest_z;
    FILE *input_file;
    FILE *temp_z;
    int ret_z;
    int ret2_z;
    int retvalue_z = 0;
    int n_threads_copy;
    int n_thread_counter;
    int ret_arp;
    int thread_counter = 0;
    int i_z;
    int *ptr_int_m;
    int64_t remaining_z;
    static char buffer[CHUNK_k__p];
    unsigned char sha512buf_m[64] = {0};
    uchar sha512_internal_maria[64];
    ar_data ar = {0};

    cores___S2_ = cores_S2__;

    bytes_read_z = 0;

    pedro_dprintf(-1, "ok dentro threads %d\n", n_threads_z);

    thread_return_value_z = 0; //initial thread error value

    totalbytes_z = lffilesize(input_z);

    //n_threads_copy = n_threads_z;

    n_thread_counter = 0;

    //is_multi_thread_z = true;
    //primeiro precisa detectar quantos threads foram usados no arquivo compactado

    if (1)
    {
        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
        WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
        input_file = _wfopen(permissive_name_m_(amanda_utf8towide_1_(input_z, ar_temp), ar_temp2), L"rb");
        free(ar_temp);
        free(ar_temp2);
    }
    else
        input_file = fopen(input_z, "rb"); //never will be called, don´t be afraid

    if (NULL == input_file)
    {
        return 1; //Cannot open input file
    }

    memset(&ar, 0, sizeof(ar));

    while (1)
    {

        ret_arp = fread(&ar, 1, sizeof(ar), input_file);

        if (0 == ret_arp)
        {
            goto saida_z;
        }

        if (ret_arp != sizeof(ar))
        {
            retvalue_z = 5;
            goto saida_z;
        }
        /*
        pedro_dprintf(-1, "erro 7 %d %d\n", ar.string[0], signature_z[0]);
        if (0 != memcmp(ar.string, signature_z, 4))
        {
            pedro_dprintf(-1, "erro 7 %s %s\n", ar.string, signature_z);
            retvalue_z = 7;
            goto saida_z;
        }
        */
        ptr_int_m = (int *)&ar.string[0];

        switch (*ptr_int_m)
        {
        case 0x706c6176 - 6:
            pedro_dprintf(-11102021, "ok 1");
            detected_encryption_method_p = ARP_AES_MT;
            break;
        case 0x706c6176 - 7:
            pedro_dprintf(-11102021, "ok 2");
            detected_encryption_method_p = ARP_RC4_MT;
            break;
        case 0x706c6176 - 8:
            pedro_dprintf(-11102021, "ok 3");
            detected_encryption_method_p = ARP_SERPENT_MT;
            break;
        case 0x706c6176 - 9:
            pedro_dprintf(-11102021, "ok 4");
            detected_encryption_method_p = ARP_MARS_MT;
            break;
        case 0x706c6176 - 10:
            pedro_dprintf(-11102021, "ok 5");
            detected_encryption_method_p = ARP_RC6_MT;
            break;
        case 0x706c6176 - 11:
            pedro_dprintf(-11102021, "ok 6");
            detected_encryption_method_p = ARP_TWOFISH_MT;
            break;
        default:
            pedro_dprintf(-11102021, "erro 7 metodo de encryptacao invalido\n");
            retvalue_z = 7;
            goto saida_z;
            break;
        }
        ret_arp = fread(&remaining_z, 1, sizeof(remaining_z), input_file);

        if (sizeof(remaining_z) != ret_arp)
        {
            retvalue_z = 5;
            goto saida_z;
        }
        bytes_in_each_slice_z[thread_counter] = remaining_z;

        ret_arp = fread(sha512buf_m, 1, 64, input_file);
        memcpy(&the_sha512_got_maria[thread_counter][0], sha512buf_m, 64);
        pedro_dprintf(-11102021, "val -> %d\n", (int)sha512buf_m[0]);

        if (64 != ret_arp)
        {
            retvalue_z = 5;
            goto saida_z;
        }

        offset_of_each_slice_z[thread_counter] = _ftelli64(input_file);

        pedro_dprintf(-11102021, "itens %lld %lld\n",
                      bytes_in_each_slice_z[thread_counter],
                      offset_of_each_slice_z[thread_counter]);

        _fseeki64(input_file, remaining_z, SEEK_CUR);

        pedro_dprintf(-11102021, "depois de seek %lld", _ftelli64(input_file));

        thread_counter++;
    }

saida_z:;

    fclose(input_file);

    pedro_dprintf(-11102021, "count of threads %d", thread_counter);
    pedro_dprintf(-11102021, "retval m %d", retvalue_z);
    //exit(27);

    if (retvalue_z)
    {
        return retvalue_z;
    }
    pedro_dprintf(-1, "passou ok 1\n");
    //exit(27);

    //*cores___S2_ = n_threads_z;

    n_threads_z = thread_counter;

    n_threads_copy = thread_counter;

    *cores___S2_ = n_threads_copy;

    while (n_threads_copy--)
    {
        pedro_dprintf(-1, "running thread %d\n", n_thread_counter);

        ptr_my_struct_z = calloc(1, sizeof(my_thread_struct_z));
        assert(ptr_my_struct_z);

        ptr_my_struct_z->thread_id_z = n_thread_counter;

        if (1)
        {
            WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
            WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

            ptr_my_struct_z->input_file = _wfopen(permissive_name_m_(amanda_utf8towide_1_(input_z, ar_temp), ar_temp2), L"rb");

            free(ar_temp);
            free(ar_temp2);
        }
        else
            ptr_my_struct_z->input_file = fopen(input_z, "rb"); //never will be called, don´t be afraid

        pauseflag = 0;
        cancelflag = 0;

        ptr_my_struct_z->intpause = (void *)&pauseflag;
        ptr_my_struct_z->intcancel = (void *)&cancelflag;

        bytes__read_thread_z[n_thread_counter] = 0;

        ptr_my_struct_z->bytes_read_z =
            &bytes__read_thread_z[n_thread_counter];

        ptr_my_struct_z->size_of_input_file_z = ptr_my_struct_z->size_of_input_file_copy_z = bytes_in_each_slice_z[n_thread_counter];

        ptr_my_struct_z->offset_z =
            offset_of_each_slice_z[n_thread_counter];

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_files_z[n_thread_counter], L"AR2"))
        {
            if (0 == thread_return_value_z)
            {
                thread_return_value_z = 407; //Cannot create temp file
            }
        }
        else
        {
            {
#ifdef ARP_USE_ENHANCED_STDIO
                ptr_my_struct_z->dest = _wfopen_z(amanda_utf8towide_1_v27(temp_files_z[n_thread_counter]), "wb", /*MAX_MEMORY_SIZE_Z*/ max_memory_size_j, __FILE__, __LINE__, NULL);
                files_to_close_z[n_thread_counter] = ptr_my_struct_z->dest;

#else
                WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                ptr_my_struct_z->dest = _wfopen(permissive_name_m_(amanda_utf8towide_1_(temp_files_z[n_thread_counter], ar_temp), ar_temp2), L"wb");

                free(ar_temp);
                free(ar_temp2);
#endif
            }

            if (NULL == ptr_my_struct_z->dest)
            {
                if (0 == thread_return_value_z)
                {
                    thread_return_value_z = 405; //Cannot open output tempfile
                }
            }
        }
        pedro_dprintf(-1, "criando thread %lld", (int64_t)n_thread_counter);

        strncpy_z(ptr_my_struct_z->key_k__p, password_v_, 299);

        my_thread_handle[n_thread_counter] = (__INT32_OR_INT64)_beginthreadex(NULL, 0, my_thread_function_v270, ptr_my_struct_z, 0, NULL);

        n_thread_counter++;
    }

    for (i_z = 0; i_z < n_threads_z; i_z++)
    {
        WaitForSingleObject((void *)my_thread_handle[i_z], INFINITE);
        CloseHandle((void *)my_thread_handle[i_z]);
        pedro_dprintf(-1, "Close next\n");
    }
    {
        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
        WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

        SetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(output_z, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);

        free(ar_temp);
        free(ar_temp2);
    }
    {
        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
        WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

        dest_z = _wfopen(permissive_name_m_(amanda_utf8towide_1_(output_z, ar_temp), ar_temp2), L"wb");

        free(ar_temp);
        free(ar_temp2);
    }
    if (NULL == dest_z)
    {
        if (0 == thread_return_value_z)
        {
            thread_return_value_z = 2; //Cannot open output file
        }
    }

    //depois de finalizar
    for (i_z = 0; i_z < n_threads_z; i_z++)
    {
        pedro_dprintf(-1, "arquivo temp a del %s\n", temp_files_z[i_z]);

        pedro_dprintf(-11102021, "888Size -> %lld\n", getfilesize_ar(temp_files_z[i_z]));

        if (dest_z)
        {

            {
#ifdef ARP_USE_ENHANCED_STDIO

                max_memory_size_j = 200000000 / n_threads_z;

                temp_z = _wfopen_z(amanda_utf8towide_1_v27(temp_files_z[i_z]), "rb", max_memory_size_j, __FILE__, __LINE__, files_to_close_z[i_z]);
#else
                WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                temp_z = _wfopen(permissive_name_m_(amanda_utf8towide_1_(temp_files_z[i_z], ar_temp), ar_temp2), L"rb");

                free(ar_temp);
                free(ar_temp2);
#endif
            }

            if (temp_z)
            {
                //Mr. Do

                SHA512_filelong_m_opened_file(temp_z,
                                              bytes_in_each_slice_z[i_z],
                                              sha512_internal_maria);

                if (0 != memcmp(sha512_internal_maria, &the_sha512_got_maria[i_z][0], 64))
                {

                    thread_return_value_z = 4;
                }
                pedro_dprintf(-11102021, "thread %d %d size %lld", (int)sha512_internal_maria[0], the_sha512_got_maria[i_z][0], bytes_in_each_slice_z[i_z]);

            volta_amanda:;
#ifdef ARP_USE_ENHANCED_STDIO
                ret_z = fread_z(buffer, 1, CHUNK, temp_z);
#else
                ret_z = fread(buffer, 1, CHUNK_k__p, temp_z);
#endif
                if (0 > ret_z)
                {
                    if (0 == thread_return_value_z)
                    {
                        thread_return_value_z = 5; //Cannot read from input file
                    }
                }
                else if (0 == ret_z)
                {
                    ; //just go by...
                }
                else
                {

                    ret2_z = fwrite(buffer, 1, ret_z, dest_z);

                    if (ret2_z != ret_z)
                    {
                        if (0 == thread_return_value_z)
                        {
                            thread_return_value_z = 6; //Cannot write to output file
                        }
                        goto exit_loop_z;
                    }

                    goto volta_amanda;
                }

            exit_loop_z:;
#ifndef ARP_USE_ENHANCED_STDIO
                fclose(temp_z);
#endif
            }
            else
            {
                if (0 == thread_return_value_z)
                {
                    thread_return_value_z = 405; //Cannot open temp file
                }
            }
        }
#ifndef ARP_USE_ENHANCED_STDIO
        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
        WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

        _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_files_z[i_z], ar_temp), ar_temp2));

        free(ar_temp);
        free(ar_temp2);
#endif
    }

#ifdef ARP_USE_ENHANCED_STDIO
    for (i_z = 0; i_z < n_threads_z; i_z++)
    {
        free_z(files_to_close_z[i_z]);
        _wunlink(amanda_utf8towide_1_v27(temp_files_z[i_z]));
    }
#endif

    if (dest_z)
    {
        fclose(dest_z);
    }

    if (0 == thread_return_value_z)
    {
        WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
        WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

        ret_z = SetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(output_z, ar_temp), ar_temp2), ar.attrib);

        free(ar_temp);
        free(ar_temp2);
    }

    pedro_dprintf(-11102021, "unencrypt multi, erro que deu %d\n", thread_return_value_z);

    return thread_return_value_z;

    exit(27);
    return 0;
}