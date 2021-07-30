ret = BZ2_bzDecompressInit (&strm, 0, 0);
	if (BZ_OK != ret)
	{
		retvalue = 121;// Cannot init decompression
		goto saida;
	}
	
	signature_z[3] = '_' - 2;
	
	intpause = 0;
	intcancel = 0;
	md5_starts (&ctx);
	bzip3percent = 0;
	totalbytes = lffilesize (input);
	source = lfopen (input, "rb");
	if (0 == source)
	{
		retvalue = 107;
		goto saida;
	}
	{
		WCHAR temp_w_k[300] = {0};
		utf8towide (output, temp_w_k, 300);
		ret = SetFileAttributesW (temp_w_k, FILE_ATTRIBUTE_ARCHIVE);
	}

	memset (&rsp, 0, sizeof (rsp));
	ret = lfread (&rsp, sizeof (rsp), source);

	if (ret != sizeof (rsp))
	{
		retvalue = 122;
		goto saida;
	}

	if (0 != memcmp (rsp.string, "RSPB", 4))
	{

		pedro_dprintf(-1, "arquivo nao é RSPB");
		if (0 == memcmp (rsp.string, "AR_2", 4))
		{
			is_sha512_file_k = 1;
			goto saida;
		}

		if (0 == memcmp (rsp.string, signature_z, 4))
		{
			is_sha512_file_k = 2;
			goto saida;
		}
		
		retvalue = 199;
		goto saida;

	}

	dest = lfopen (output, "wb");

	if (0 == dest)
	{
		retvalue = 108;
		goto saida;
	}
	for (;;)
	{
		while (intpause)
		{

			Sleep (50);

			if (intcancel)
			{
				goto saida;
			}

		}

		if (intcancel)
		{
			goto saida;
		}

		ret = lfread (buffer, CHUNK, source);

		if ((0 == ret) || done)
		{
			goto saida;
		}

		bytesread = bytesread + ret;

		bzip3percent = lgetpor (totalbytes, bytesread);

		strm.next_in = buffer;
		strm.avail_in = ret;

volta:

		strm.next_out = out;
		strm.avail_out = CHUNK;
		ret = BZ2_bzDecompress (&strm);
		writebytes = CHUNK - strm.avail_out;

		if (writebytes > 0)
		{
			md5_update (&ctx, (unsigned char *) out, writebytes);
			if (0 == (ret_arp = lfwrite (out, writebytes, dest)))
			{
				retvalue = 14; //Cannot write to output file
				goto saida;
			}
			if(ret_arp != writebytes)
			{
				retvalue = 14;
				goto saida;
			}
		}

		switch (ret)
		{
		case BZ_OK:

			if(0==strm.avail_out)
			{
				goto volta;
			}

			break;

		case BZ_DATA_ERROR:

			retvalue = 126;
			goto saida;
			break;

		case BZ_MEM_ERROR:

#ifdef NPRINTF
			dprintf ("BZ_MEM_ERROR \n");
#endif
			retvalue = 125;
			goto saida;
			break;

		case BZ_DATA_ERROR_MAGIC:

			retvalue = 198;
			goto saida;
			break;

		case BZ_STREAM_END:

			done = 1;
			break;
		default:
			assert (0);
			break;
		}
	}

saida:
	;

	if( 0 == is_sha512_file_k)
	{
		if ((0 == retvalue) && (totalbytes > sizeof (rsp)))
		{
			memset (md5sum, 0, 16);

			md5_finish (&ctx, md5sum);

			memcpy (&a, &md5sum[0], 4);

			memcpy (&b, &md5sum[4], 4);

			memcpy (&c, &md5sum[8], 4);

			memcpy (&d, &md5sum[12], 4);

			if ((a != rsp.a) || (b != rsp.b) || (c != rsp.c) || (d != rsp.d))
			{
#ifdef NPRINTF
				dprintf ("error de md5 \n");
#endif
				retvalue = 123;
			}
		}

		if (totalbytes > sizeof (rsp))
		{

#ifdef NPRINTF
			dprintf ("garanta que done é setafdo \n");
#endif
			if ((0 == done) && (0 == retvalue))
			{
				retvalue = 124;
			}
		}
	}
	bzip3percent = 10000;

	if (source)
	{
		lfclose (source);
		source = 0;
	}

	if (dest)
	{
		if (0 == retvalue)
		{
			ret = SetFileTime (dest, // identifies the file
			                   &rsp.creation, // time the file was created
			                   NULL, // time the file was last accessed
			                   &rsp.lwrite  // time the file was last written
			                   );
		}

		lfclose (dest);
		dest = 0;

	}

	if (intcancel)
	{
		retvalue = 119;
	}

	if (0 == retvalue)
	{

		{
			WCHAR temp_w_k[300] = {0};

			utf8towide (output, temp_w_k, 300);
			ret = SetFileAttributesW(temp_w_k, rsp.attrib);
		}
	}

#ifdef NPRINTF
	dprintf ("retvalue=%d \n", retvalue);
#endif
	if(0 == is_sha512_file_k)
		finished = 1;

	//intstatus = 0;

	assert (BZ_OK == BZ2_bzDecompressEnd (&strm));