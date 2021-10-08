/********************************************************************************
 *                                                                              *
 *        Licensa de C�pia (C) <2021>  <Corpora��o do Trabalho Bin�rio>         *
 *                                                                              *
 *     Este  programa  � software livre: voc� pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como       8
 *     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da       *
 *     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.         *
 *                                                                              *
 *     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de       *
 *     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P�blica para mais detalhes.                                *
 *                                                                              *
 *     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P�blica Menor junto com este programa                            *
 *     Se n�o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 ********************************************************************************
 
      E-mails:                                                                 
      maria@arsoftware.net.br                                                  
      pedro@locacaodiaria.com.br                                               

 ********************************************************************************
 *                                                                              *
 *     contato imediato(para uma resposta muito r�pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                 *      
 *                                                                              *
 *******************************************************************************/

int aesencrypt_maria(unsigned char *buf,
                     unsigned char *bufout,
                     unsigned char *key,
                     int keysize,
                     int *done,
                     my_thread_struct_z *ptr_my_struct_z)
{

    (void)ptr_my_struct_z;
    if (0 == *done)
    {
#ifdef NPRINTF
        dprintf("aes enc primeiro debug \n");
#endif

        aes_set_key(&ptr_my_struct_z->ctxxx, key, keysize);

        ptr_my_struct_z->ctxxx2 = ptr_my_struct_z->ctxxx;
        *done = 1;
        //already = 0;
    }
    else
    {

        //if (already == 0)
        {
#ifdef NPRINTF
            dprintf("aes enc segundo debug \n");
#endif
            //already = 1;
        }

        ptr_my_struct_z->ctxxx = ptr_my_struct_z->ctxxx2; //keeping for historical reasons because it is not required to have a copy of the struct
    }
    aes_encrypt(&ptr_my_struct_z->ctxxx, buf, bufout);
    return 0;
}

int __stdcall encryptstring2_pedro(uchar *buf, uchar *key, uchar *bufout, uint size, __attribute__((unused)) uint keysize, my_thread_struct_z *ptr_my_struct_z)
{

    //uchar lbuf[16];
    uchar *pchar;
    uchar *pchar2;
    //uint pointer;
    //uint i;
    //uchar tmpbuf[16];
    //struct rc4_state s;

    (void)ptr_my_struct_z;

    //static char countbuffer[17];
    /*
    static int *ptr1 = NULL;
    static int *ptr2 = NULL;
    static int *ptr3 = NULL;
    static int *ptr4 = NULL;
*/
    int *pptr1 = NULL;
    int *pptr2 = NULL;
    int *pptr3 = NULL;
    int *pptr4 = NULL;

    int *pttr1 = NULL;
    int *pttr2 = NULL;
    int *pttr3 = NULL;
    int *pttr4 = NULL;

    if (ptr_my_struct_z->init_aes)
    {

        memset(ptr_my_struct_z->countbuffer, 0, 16);
        ptr_my_struct_z->ptr1 = (int *)&ptr_my_struct_z->countbuffer[0];
        ptr_my_struct_z->ptr2 = (int *)&ptr_my_struct_z->countbuffer[4];
        ptr_my_struct_z->ptr3 = (int *)&ptr_my_struct_z->countbuffer[8];
        ptr_my_struct_z->ptr4 = (int *)&ptr_my_struct_z->countbuffer[12];
#ifdef NPRINTF
        dprintf("1itens %08x %08x %08x %08x \n", *ptr1, *ptr2, *ptr3, *ptr4);
#endif
        *(ptr_my_struct_z->ptr1) = crc32(0, key, 32);

        *(ptr_my_struct_z->ptr2) = crc32(*(ptr_my_struct_z->ptr1), key, 32);

        *(ptr_my_struct_z->ptr3) = crc32(*(ptr_my_struct_z->ptr2), key, 32);

        *(ptr_my_struct_z->ptr4) = crc32(*(ptr_my_struct_z->ptr3), key, 32);
#ifdef NPRINTF
        dprintf("2itens %08x %08x %08x %08x \n", *ptr1, *ptr2, *ptr3, *ptr4);
#endif
        ptr_my_struct_z->init_aes = 0;
    }

    pchar = bufout;
    pchar2 = buf;

    for (; size > 15; size = size - 16)
    {

        (*(ptr_my_struct_z->ptr1))++;
        (*(ptr_my_struct_z->ptr2))++;
        (*(ptr_my_struct_z->ptr3))++;
        (*(ptr_my_struct_z->ptr4))++;

        aesencrypt_maria((uchar *)ptr_my_struct_z->countbuffer,
                         pchar,
                         key,
                         256,
                         &ptr_my_struct_z->done2,
                         ptr_my_struct_z);

        pptr1 = (int *)&pchar[0];
        pptr2 = (int *)&pchar[4];
        pptr3 = (int *)&pchar[8];
        pptr4 = (int *)&pchar[12];

        pttr1 = (int *)&pchar2[0];
        pttr2 = (int *)&pchar2[4];
        pttr3 = (int *)&pchar2[8];
        pttr4 = (int *)&pchar2[12];

        *pptr1 = *pptr1 ^ *pttr1;
        *pptr2 = *pptr2 ^ *pttr2;
        *pptr3 = *pptr3 ^ *pttr3;
        *pptr4 = *pptr4 ^ *pttr4;

        pchar += 16;
        pchar2 += 16;
    }

    if (size != 0)
    {

        char ppchar2[255];
        char ppchar[255];

        memset(ppchar2, 0, 255);
#ifdef NPRINTF
        dprintf("Tamanho %d \n", size);
#endif
        memcpy(ppchar2, pchar2, size);

        (*(ptr_my_struct_z->ptr1))++;
        (*(ptr_my_struct_z->ptr2))++;
        (*(ptr_my_struct_z->ptr3))++;
        (*(ptr_my_struct_z->ptr4))++;

        pchar2 = (void *)ppchar2;

        aesencrypt_maria((uchar *)ptr_my_struct_z->countbuffer,
                         (uchar *)ppchar,
                         key,
                         256,
                         &ptr_my_struct_z->done2,
                         ptr_my_struct_z);

        pptr1 = (int *)&ppchar[0];
        pptr2 = (int *)&ppchar[4];
        pptr3 = (int *)&ppchar[8];
        pptr4 = (int *)&ppchar[12];

        pttr1 = (int *)&pchar2[0];
        pttr2 = (int *)&pchar2[4];
        pttr3 = (int *)&pchar2[8];
        pttr4 = (int *)&pchar2[12];
#ifdef NPRINTF
        dprintf("aitens %08x %08x %08x %08x \n", *pttr1, *pttr2, *pttr3, *pttr4);
        dprintf("bitens %08x %08x %08x %08x \n", *pptr1, *pptr2, *pptr3, *pptr4);
#endif

        *pptr1 = *pptr1 ^ *pttr1;
        *pptr2 = *pptr2 ^ *pttr2;
        *pptr3 = *pptr3 ^ *pttr3;
        *pptr4 = *pptr4 ^ *pttr4;
#ifdef NPRINTF
        dprintf("citens %08x %08x %08x %08x \n", *pttr1, *pttr2, *pttr3, *pttr4);
        dprintf("ditens %08x %08x %08x %08x \n", *pptr1, *pptr2, *pptr3, *pptr4);
#endif

        memcpy(pchar, ppchar, size);
    }

    return 0;
}

unsigned __stdcall my_thread_function(void *my_argument_z);
unsigned __stdcall my_thread_function(void *my_argument_z)
{
    int ret_m;
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

    SHA512_filelong_m_opened_file(ptr_my_struct_z->input_file,
                                  ptr_my_struct_z->size_of_input_file_z,
                                  ptr_my_struct_z->sha512_digest_k);

    int64_t infile_remaining = ptr_my_struct_z->size_of_input_file_z;

    /*
aqui amor?...
cafe?
suco
fwrite(&fatia, 1, 4, stream2);
          fwrite(sha512_digest_k, 1, 64, stream2);
          pedro_dprintf(-1, "salvando o tamanho do arquivo %lld\n", filesize);
          fwrite(&filesize, 1, 8, stream2);

          fatia_m = 0x706c6176 - 6; //proximo da lista
                              memcpy(ptr_my_struct_z->ar.string, &fatia_m, 4);

*/
    /*
    ptr_my_struct_z->ret = fwrite(ptr_my_struct_z->ar.string, 1, 4, ptr_my_struct_z->dest);

    if (4 != ptr_my_struct_z->ret)
    {
        ptr_my_struct_z->retvalue = 14; //unexpected error
        goto saida;
    }
*/
    ptr_my_struct_z->ret = fwrite(ptr_my_struct_z->sha512_digest_k, 1, 64, ptr_my_struct_z->dest);

    if (64 != ptr_my_struct_z->ret)
    {
        ptr_my_struct_z->retvalue = 14; //unexpected error
        goto saida;
    }

    /*
    ptr_my_struct_z->ret = fwrite(&ptr_my_struct_z->size_of_input_file_z, 1, 8, ptr_my_struct_z->dest);

    if (8 != ptr_my_struct_z->ret)
    {
        ptr_my_struct_z->retvalue = 14; //unexpected error
        goto saida;
    }
*/

    switch (ptr_my_struct_z->encryption_method_internal_arp)
    {
    case ARP_AES_MT:

        break;
    }

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
        size_of_compressed_z += n;

        if (bytes_read_arp)
        {
            *bytes_read_arp += n / 2;
        }

        bytes_read_z += n / 2;

        switch (ptr_my_struct_z->encryption_method_internal_arp)
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
                ptr_my_struct_z->retvalue = 14; //unexpected error
                goto saida;
            }
            break;
        }

        //printf("Input bytes remaining: %u\n", infile_remaining);

        ptr_my_struct_z->bytesread = ptr_my_struct_z->bytesread + ptr_my_struct_z->ret;

        bytes__read_thread_z[ptr_my_struct_z->thread_id_z] = ptr_my_struct_z->bytesread;
    }

saida:;

    pedro_dprintf(-1, "saida %d bytes written %d\n", ptr_my_struct_z->retvalue, (int)size_of_compressed_z);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"

    if (ptr_my_struct_z->size_of_input_file_z && (0 == ptr_my_struct_z->retvalue))
    {
        if (0 != infile_remaining && (0 == cancelflag))
        {
            ptr_my_struct_z->retvalue = 160;
        }
    }

#pragma GCC diagnostic pop

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