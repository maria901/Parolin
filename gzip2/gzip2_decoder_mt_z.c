
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
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
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

#define CHUNK 131072 /* to never change again, or until someone change their mind... \
at least it is better than 0x1000 (faster than) */

int zuncompress_sha512_k_mt_decoding_multi_thread_z(__attribute__((unused)) FILE *source,
													__attribute__((unused)) FILE *dest,
													__attribute__((unused)) my_thread_struct_z *amanda)
{
	char signature_z[5] = "AR__";
	int64_t remaining_z;
	__int64 totalbytes = 0;
	int64_t infile_remaining;
	int done = 0;
	int ret_z = 0;
	int retvalue = 0;
	ar_data ar;
	char *buffer = malloc(CHUNK);
	char *out = malloc(CHUNK);
	z_stream strm;

	pedro_dprintf(-1, "decoder multi-thread\n");

	assert(NULL == dest);

	memset(&strm, 0, sizeof(strm));

	pauseflag = 0;
	cancelflag = 0;

	//exit(27);

	strm.zalloc = Z_NULL;
	strm.zfree = Z_NULL;
	strm.opaque = Z_NULL;
	strm.avail_in = 0;
	strm.next_in = Z_NULL;

	signature_z[3] = '_' - 1; //gzip2 signature

	if (-1 == signature_z[3]) //to make the compiler happy
	{
		pedro_dprintf(-1, "Test...\n");
	}

	ret_z = inflateInit(&strm);

	assert(ret_z == Z_OK);

	char *sha51_ptr = NULL;
	char sha512_temp_k[SHA512_DIGEST_LENGTH];

	sha51_ptr = sha512_init_k();

	amanda->size_of_input_file_copy_z = amanda->size_of_input_file_copy_z + sizeof(int64_t) + sizeof(ar);
	amanda->size_of_input_file_z = amanda->size_of_input_file_copy_z;
	totalbytes = amanda->size_of_input_file_z;

	//remaining_z = amanda->size_of_input_file_z;

	pedro_dprintf(-1, "seek to %lld\n", amanda->offset_z);

	assert(0 <= (int64_t)amanda->offset_z - (int64_t)sizeof(int64_t) - (int64_t)sizeof(ar));

	if (
		0 != _fseeki64(
				 amanda->input_file,
				 amanda->offset_z - sizeof(int64_t) - sizeof(ar),
				 SEEK_SET))
	{
		amanda->retvalue = 403; //File access error
		goto saida_12_march_2021__09_32_18;
	}

	memset(&ar, 0, sizeof(ar));
	ret_z = fread(&ar, 1, min(sizeof(ar), amanda->size_of_input_file_copy_z), amanda->input_file);

	if (ret_z != sizeof(ar))
	{

		retvalue = 9;
		goto saida_12_march_2021__09_32_18;
	}
	amanda->size_of_input_file_copy_z -= ret_z;
	if (0 != memcmp(ar.string, signature_z, 4))
	{

		retvalue = 90;
		goto saida_12_march_2021__09_32_18;
	}

	ret_z = fread(&remaining_z, 1, min(sizeof(remaining_z), amanda->size_of_input_file_copy_z), amanda->input_file);

	if (sizeof(remaining_z) != ret_z)
	{
		retvalue = 9;
		goto saida_12_march_2021__09_32_18;
	}

	amanda->size_of_input_file_copy_z -= ret_z;

	if (0 > remaining_z)
	{
		retvalue = 500;
		goto saida_12_march_2021__09_32_18;
	}

	if (amanda->size_of_input_file_copy_z != remaining_z)
	{
		retvalue = 500;
		goto saida_12_march_2021__09_32_18;
	}

	/*

	commented and kept for historical reasons, this is
	one of the most used undetected buggy code
	that we saw in 24 years...

	for (;; )
	{
		while (*(amanda->intpause))
		{

			Sleep (50);

			if (*(amanda->intcancel))
			{
				amanda->internal_error_arp = 119;
				goto saida;
			}

		}

		if (*(amanda->intcancel))
		{
			amanda->    internal_error_arp = 119;
			goto saida;
		}

		ret_z = fread (buffer, 1, min(CHUNK, remaining_z), amanda->input_file);

		if(0 > ret_z)
		{
			retvalue = 501;
			goto saida;
		}

		if ((0 == ret_z) || done)
		{

			goto saida;

		}
				
		remaining_z -= ret_z;
		*(amanda->bytes_read_z) += ret_z;
		bytesread = bytesread + ret_z;
		
		strm.avail_in = ret_z;

		strm.next_in = (void *) buffer;

devolta:

		strm.avail_out = CHUNK;
		strm.next_out = (void *) out;

		ret2_z = inflate (&strm, Z_NO_FLUSH);

		bytestosave = bytestosave + (CHUNK - strm.avail_out);

		writebytes = CHUNK - strm.avail_out; //existe um erro aqui

		if (writebytes > 0)
		{
			sha512_update_k(sha51_ptr, (void *) out, writebytes        );
			ret_z = fwrite_z (out, 1, writebytes, amanda->dest);
			if (writebytes != ret_z                                    )
			{
				amanda->internal_error_arp                          = 6;
				retvalue = 14;
				goto saida;
			}
		}

		switch (ret2_z)
		{

		case Z_OK:

			if (strm.avail_in)
			{
				goto devolta;
			}

			if(0==strm.avail_out)
			{
				goto devolta;
			}

			break;

		case Z_STREAM_END:

			done = 1;
			break;

		case Z_NEED_DICT:

			assert (0);
			break;

		case Z_STREAM_ERROR:

			assert (0);
			break;

		case Z_MEM_ERROR:

			assert (0);
			break;

		case Z_DATA_ERROR:

			retvalue = 21;
			goto saida;

			break;

		case Z_BUF_ERROR:

			assert (0);//here the decoding error appear...only for some files
			break;

		default:

			assert (0);
			break;

		}

	}

saida:
*/

	totalbytes = remaining_z;
	strm.next_in = (void *)buffer;
	strm.avail_in = 0;
	strm.next_out = (void *)out;
	strm.avail_out = CHUNK;
	infile_remaining = totalbytes;
	for (;;)
	{
		while (*(amanda->intpause))
		{

			Sleep(50);

			if (*(amanda->intcancel))
			{
				amanda->internal_error_arp = 119;
				goto saida_12_march_2021__09_32_18;
			}
		}

		if (*(amanda->intcancel))
		{
			amanda->internal_error_arp = 119;
			goto saida_12_march_2021__09_32_18;
		}

		int status;

		if (!strm.avail_in)
		{
			// Input buffer is empty, so read more bytes from input file.
			int64_t n_z = min(CHUNK, infile_remaining);

			if ((size_t)fread(buffer, 1, n_z, amanda->input_file) != (size_t)n_z)
			{
				retvalue = 9;
				goto saida_12_march_2021__09_32_18;
			}

			strm.next_in = (void *)buffer;
			strm.avail_in = n_z;
			infile_remaining -= n_z;
			*(amanda->bytes_read_z) += n_z;
		}

		status = inflate(&strm, Z_SYNC_FLUSH);

		if ((status == Z_STREAM_END) || (!strm.avail_out))
		{
			// Output buffer is full, or decompression is done, so write buffer to output file.
			uint n_z = CHUNK - strm.avail_out;

			if (fwrite_z(out, 1, n_z, amanda->dest) != n_z)
			{
				amanda->internal_error_arp = 6;
				retvalue = 14;
				goto saida_12_march_2021__09_32_18;
			}

			sha512_update_k(sha51_ptr, (void *)out, n_z);

			strm.next_out = (void *)out;
			strm.avail_out = CHUNK;
		}

		if (status == Z_STREAM_END)
		{
			done = 1;
			break;
		}
		else if (status != Z_OK)
		{
			//aqui

			switch (status)
			{
			case Z_STREAM_END:
				strcpy(zlib_error_z, "Z_STREAM_END");
				zlib_int_error_z = 528;
				break;
			case Z_NEED_DICT:
				strcpy(zlib_error_z, "Z_NEED_DICT");
				zlib_int_error_z = 529;
				break;
			case Z_STREAM_ERROR:
				strcpy(zlib_error_z, "Z_STREAM_ERROR");
				zlib_int_error_z = 530;
				break;
			case Z_MEM_ERROR:
				strcpy(zlib_error_z, "Z_MEM_ERROR");
				zlib_int_error_z = 531;
				break;
			case Z_DATA_ERROR:
				strcpy(zlib_error_z, "Z_DATA_ERROR");
				zlib_int_error_z = 532;
				break;
			case Z_BUF_ERROR: //isso da erro
				strcpy(zlib_error_z, "Z_BUF_ERROR");
				zlib_int_error_z = 533;
				break;
			default:
				strcpy(zlib_error_z, "unknown");
				zlib_int_error_z = 534;
				break;
			}

			pedro_dprintf(2, "inflate() failed with status %$ !\n", zlib_error_z);
			retvalue = zlib_int_error_z;
			goto saida_12_march_2021__09_32_18;
			//break; also work here
		}
	}

saida_12_march_2021__09_32_18:;

	if ((0 == retvalue) && ((int64_t)totalbytes > (int64_t)sizeof(ar)))
	{

		sha512_final_k(sha51_ptr, (void *)sha512_temp_k);

		if (0 != memcmp(sha512_temp_k, ar.sha512_k, SHA512_DIGEST_LENGTH))
		{
			pedro_dprintf(-1, "erro 20");
			retvalue = 20;
		}
	}

	if ((int64_t)totalbytes > (int64_t)sizeof(ar))
	{

		if ((0 == done) && (0 == retvalue))
		{

			retvalue = 18;
		}
	}

	(void)inflateEnd(&strm);

	if (cancelflag)
	{
		retvalue = 19;
	}
	*(amanda->bytes_read_z) = totalbytes_z;
	free(buffer);
	free(out);

	pedro_dprintf(-1, "erro que deu interno %d\n", retvalue);

	return retvalue;
}
