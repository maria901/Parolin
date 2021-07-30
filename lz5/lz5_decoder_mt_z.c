//2021 amanda & MathMan

//#define CHUNK 131072 /* to never change again */

int zuncompress_sha512_k_mt_decoding_multi_thread_z (FILE * source, FILE * dest, my_thread_struct_z * amanda)
{
	ar_data   ar                                =   {0,};
	char      signature_z                   [5] = "AR__";
	char *    buffer = malloc                    (CHUNK);
	char *    out    = malloc                    (CHUNK);
	int       ret_arp                                   ;
	int       ret_z                                     ;
	int       retvalue                          =      0;
	int64_t   remaining_z                               ;

	pedro_dprintf(-1, "decoder multi-thread running\n" );

	assert(NULL == dest);

	intcancel                                 =      0;
	intpause                                  =      0;

	signature_z[3] = '_' - 9;//lz5 multi-thread

	pedro_dprintf(-1, "seek to %lld\n", amanda->offset_z);

	assert(0 <= amanda->offset_z - sizeof(int64_t) - sizeof(ar)     );

	amanda->size_of_input_file_copy_z += sizeof(int64_t) + sizeof(ar);

	if(
		0 != _fseeki64(
			amanda->input_file,
			amanda->offset_z - sizeof(int64_t) - sizeof(ar),
			SEEK_SET
			)
		)
	{
		amanda->retvalue = 403;  //File access error
		goto           saida_13_march_2021__21_02_12;
	}

	memset (&ar, 0, sizeof (ar));
	ret_z = fread (&ar, 1, min(sizeof (ar), amanda->size_of_input_file_copy_z), amanda->input_file);

	if (ret_z != sizeof (ar))
	{

		retvalue                     = 122;
		goto saida_13_march_2021__21_02_12;

	}
	amanda->size_of_input_file_copy_z -= ret_z;
	if (0 != memcmp (ar.string, signature_z, 4))
	{

		retvalue                     = 199;
		goto saida_13_march_2021__21_02_12;

	}

	ret_z = fread (&remaining_z, 1, min(sizeof (remaining_z), amanda->size_of_input_file_copy_z), amanda->input_file);

	if (sizeof (remaining_z) !=      ret_z)
	{
		retvalue                     = 122;
		goto saida_13_march_2021__21_02_12;
	}

	amanda->size_of_input_file_copy_z    -=
	ret_z;

	if(0 > remaining_z)
	{
		retvalue                     = 500;
		goto saida_13_march_2021__21_02_12;
	}

	if(amanda->size_of_input_file_copy_z != remaining_z)
	{
		pedro_dprintf(-1, "achou amor %lld %lld\n", amanda->size_of_input_file_copy_z, remaining_z);
		retvalue                     = 500;
		goto saida_13_march_2021__21_02_12;
	}

	amanda->size_of_input_file_copy_z = remaining_z;
	
	pedro_dprintf(-1, "size internal %lld\n", amanda->size_of_input_file_copy_z);
	
	//aqui...

	ret_arp = decompress_file(source, dest, amanda);

	if(119 == amanda->internal_error_arp)
	{
		retvalue = 119;
	}
	else if(6 == amanda->  internal_error_arp)
	{
		retvalue = amanda->internal_error_arp;
	}
	else
	{
		if(ret_arp)
		{
			pedro_dprintf(-1, "error 2 7 \n");
			retvalue = 7;                         //It isnot a valid compressed file
		}
	}

saida_13_march_2021__21_02_12:;

	pedro_dprintf(-1, "pulou e erro %d\n", retvalue);

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
