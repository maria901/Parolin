//2021 amanda & MathMan

//#define CHUNK 131072 /* to never change again */

int zuncompress_sha512_k_mt_decoding_multi_thread_z (FILE * source, FILE * dest, my_thread_struct_z * amanda)
{
	__int64   totalbytes                        =      0;
	ar_data   ar                                =   {0,};
	bz_stream strm                              =   {0,};
	char      sha512_temp_k       [SHA512_DIGEST_LENGTH];
	char      signature_z                   [5] = "AR__";
	char *    buffer = malloc                    (CHUNK);
	char *    out    = malloc                    (CHUNK);
	char *    sha512_ptr                        =   NULL;
	int       done                              =      0;
	int       ret_arp                                   ;
	int       ret_z                                     ;
	int       retvalue                          =      0;
	int       writebytes                                ;
	int64_t   remaining_z                               ;

	pedro_dprintf(-1, "decoder multi-thread running\n"  );

	assert(NULL == dest);

	intcancel                                 =      0;
	intpause                                  =      0;

	signature_z[3] = '_' - 2; //bzip3 multi-thread signature...

	ret_z = BZ2_bzDecompressInit         (&strm, 0, 0);

	if (BZ_OK != ret_z)
	{
		retvalue = 121;
		goto saida_13_march_2021__12_12_12;
	}

	sha512_ptr = sha512_init_k();

	amanda->size_of_input_file_copy_z = amanda->size_of_input_file_copy_z + sizeof(int64_t) + sizeof(ar);
	amanda->size_of_input_file_z      = amanda->size_of_input_file_copy_z;

	totalbytes = amanda->size_of_input_file_z;

	remaining_z = amanda->size_of_input_file_z;

	pedro_dprintf(-1, "seek to %lld\n", amanda->offset_z);

	assert(0 <= amanda->offset_z - sizeof(int64_t) - sizeof(ar));

	if(
		0 != _fseeki64(
			amanda->input_file,
			amanda->offset_z - sizeof(int64_t) - sizeof(ar),
			SEEK_SET
			)
		)
	{
		amanda->retvalue = 403;  //File access error
		goto           saida_13_march_2021__12_12_12;
	}

	memset (&ar, 0, sizeof (ar));
	ret_z = fread (&ar, 1, min(sizeof (ar), amanda->size_of_input_file_copy_z), amanda->input_file);

	if (ret_z != sizeof (ar))
	{

		retvalue                     = 122;
		goto saida_13_march_2021__12_12_12;

	}
	amanda->size_of_input_file_copy_z -= ret_z;
	if (0 != memcmp (ar.string, signature_z, 4))
	{

		retvalue                     = 199;
		goto saida_13_march_2021__12_12_12;

	}

	ret_z = fread (&remaining_z, 1, min(sizeof (remaining_z), amanda->size_of_input_file_copy_z), amanda->input_file);

	if (sizeof (remaining_z) !=      ret_z)
	{
		retvalue                     = 122;
		goto saida_13_march_2021__12_12_12;
	}

	amanda->size_of_input_file_copy_z    -=
	ret_z;

	if(0 > remaining_z)
	{
		retvalue                     = 500;
		goto saida_13_march_2021__12_12_12;
	}

	if(amanda->size_of_input_file_copy_z != remaining_z)
	{
		retvalue                     = 500;
		goto saida_13_march_2021__12_12_12;
	}

for (;;)
	{
		while (*(amanda->intpause))
		{

			Sleep (50);

			if (*(amanda->intcancel))
			{
				amanda->  internal_error_arp = 119;
				goto saida_13_march_2021__12_12_12;
			}

		}

		if (*(amanda->intcancel))
		{
			amanda->    internal_error_arp = 119;
			goto   saida_13_march_2021__12_12_12;
		}

		ret_z = fread(buffer, 1, min(CHUNK, remaining_z), amanda->input_file);
		//ret = fread (buffer, 1, min(CHUNK, remaining_z), source);

		if(0 > ret_z)
		{
			retvalue                  =    122;
			goto saida_13_march_2021__12_12_12;
		}

		if ((0 == ret_z) ||               done)
		{
			goto saida_13_march_2021__12_12_12;
		}
		*(amanda->bytes_read_z)      +=  ret_z;
		remaining_z                  -=  ret_z;
		strm.next_in                  = buffer;
		strm.avail_in                 =  ret_z;

volta:

		strm.next_out = out;
		strm.avail_out = CHUNK;
		ret_z = BZ2_bzDecompress (&strm);
		writebytes = CHUNK - strm.avail_out;
		if (writebytes > 0)
		{
			sha512_update_k(sha512_ptr, (unsigned char *) out, writebytes );
			if (0 == (ret_arp = fwrite_z(out, 1, writebytes, amanda->dest)))
			{
				amanda->internal_error_arp    =  6;
				retvalue                      = 14;
				goto saida_13_march_2021__12_12_12;
			}
			if(ret_arp != writebytes)
			{
				amanda->internal_error_arp    =  6;
				retvalue                      = 14;
				goto saida_13_march_2021__12_12_12;
			}
		}
		switch (ret_z)
		{
		case BZ_OK:

			if(0==strm.avail_out)
			{
				goto volta;
			}

			break;

		case BZ_DATA_ERROR:

			retvalue = 126;
			goto saida_13_march_2021__12_12_12;
			break;

		case BZ_MEM_ERROR:
#ifdef NPRINTF
			dprintf ("BZ_MEM_ERROR \n");
#endif
			retvalue = 125;
			goto saida_13_march_2021__12_12_12;
			break;

		case BZ_DATA_ERROR_MAGIC:
			retvalue = 198;
			goto saida_13_march_2021__12_12_12;
			break;

		case BZ_STREAM_END:

			done = 1;
			break;
		default:
			assert (0);
			break;
		}
	}

saida_13_march_2021__12_12_12:;

	if ((0 == retvalue) && (totalbytes > sizeof (ar)))
	{

		sha512_final_k(sha512_ptr, (void *) sha512_temp_k);

		if (0 != memcmp(sha512_temp_k, ar.digest_k, SHA512_DIGEST_LENGTH))
		{
			pedro_dprintf(-1, "erro 20");
			retvalue = 300;
		}
	}

	if (totalbytes > sizeof (ar))
	{

		if ((0 == done) && (0 == retvalue))
		{

			retvalue = 124; // who did it?....

		}

	}

	assert (BZ_OK == BZ2_bzDecompressEnd (&strm));

	if (*(amanda->intcancel))
	{
		retvalue = 119;
	}
	*(amanda->bytes_read_z) = totalbytes_z;
	free(buffer);
	free(out);

	pedro_dprintf(-1, "erro que deu interno %d\n", retvalue);

	return retvalue;
}
