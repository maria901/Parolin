
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

int
THE_DECOMPRESSOR_FUNCION_NAME_Z(fdin, fdout, amanda)
FILE * fdin;
FILE * fdout;
my_thread_struct_z * amanda;
{
	REG2 char_type               *stackp;
	REG3 code_int code;
	REG4 int finchar;
	REG5 code_int oldcode;
	REG6 code_int incode;
	REG7 int inbits;
	REG8 int posbits;
	REG9 int outpos;
	REG10 int insize;
	REG11 int bitmask;
	REG12 code_int free_ent;
	REG13 code_int maxcode;
	REG14 code_int maxmaxcode;
	REG15 int n_bits;
	REG16 int rsize;

	bytes_in = 0;
	bytes_out = 0;
	insize = 0;

	while (insize < 3 && (rsize = fread(inbuf+insize, 1, min(IBUFSIZ, amanda->size_of_input_file_copy_z), fdin)) > 0)
	{
		*((*amanda).bytes_read_z)         += rsize;
		amanda->size_of_input_file_copy_z -= rsize;
		insize += rsize;
		
		while(*((*amanda).intpause))
		{
			Sleep(50);
			if(*((*amanda).intcancel))
			{
				amanda->internal_error_arp = 119;
				return 1;
			}
		}
		
		if(*((*amanda).intcancel))
		{
			amanda->internal_error_arp = 119;
			return 1;
		}
		
	}

	if (insize < 3 || inbuf[0] != MAGIC_1 || inbuf[1] != MAGIC_2)
	{
		if (rsize < 0)
			return 5;

		if (insize > 0)
		{
			fprintf(stderr, "%s: not in compressed format\n",
			        (ifname[0] != '\0' ? ifname : "stdin"));
			exit_code = 1;
		}

		return 7;
	}

	maxbits = inbuf[2] & BIT_MASK;
	block_mode = inbuf[2] & BLOCK_MODE;

	if (maxbits > BITS)
	{
		fprintf(stderr,
		        "%s: compressed with %d bits, can only handle %d bits\n",
		        (*ifname != '\0' ? ifname : "stdin"), maxbits, BITS);
		exit_code = 4;
		return 7;
	}

	maxmaxcode = MAXCODE(maxbits);

	bytes_in = insize;
	maxcode = MAXCODE(n_bits = INIT_BITS)-1;
	bitmask = (1<<n_bits)-1;
	oldcode = -1;
	finchar = 0;
	outpos = 0;
	posbits = 3<<3;

	free_ent = ((block_mode) ? FIRST : 256);

	clear_tab_prefixof();           /* As above, initialize the first
	                                                           256 entries in the table. */

	for (code = 255; code >= 0; --code)
		tab_suffixof(code) = (char_type)code;

	do
	{
resetbuf:       ;
		{
			REG1 int i;
			int e;
			int o;

			o = posbits >> 3;
			e = o <= insize ? insize - o : 0;

			for (i = 0; i < e; ++i)
				inbuf[i] = inbuf[i+o];

			insize = e;
			posbits = 0;
		}

		if (insize < (int) (sizeof(inbuf)-IBUFSIZ))
		{
			if ((rsize = fread(inbuf+insize, 1, min(IBUFSIZ, amanda->size_of_input_file_copy_z), fdin)) < 0)
				return 5;
			/*
			processado_rspk += rsize;

			while(intpause___aakp)
			{
				Sleep(50);

				if(intcancel__rspk)
				{
					return 119;
				}
			}

			if(intcancel__rspk)
			{
				return 119;
			}
			*/
			
			while(*((*amanda).intpause))
			{
				Sleep(50);
				if(*((*amanda).intcancel))
				{
					amanda->internal_error_arp = 119;
					return 1;
				}
			}
			
			if(*((*amanda).intcancel))
			{
				amanda->internal_error_arp = 119;
				return 1;
			}
			
			*((*amanda).bytes_read_z)         += rsize;
			insize += rsize;			
			amanda->size_of_input_file_copy_z -= rsize;			
		}

		inbits = ((rsize > 0) ? (insize - insize%n_bits)<<3 :
		          (insize<<3)-(n_bits-1));

		while (inbits > posbits)
		{
			if (free_ent > maxcode)
			{
				posbits = ((posbits-1) + ((n_bits<<3) -
				                          (posbits-1+(n_bits<<3))%(n_bits<<3)));

				++n_bits;
				if (n_bits == maxbits)
					maxcode = maxmaxcode;
				else
					maxcode = MAXCODE(n_bits)-1;

				bitmask = (1<<n_bits)-1;
				goto resetbuf;
			}

			input(inbuf,posbits,code,n_bits,bitmask);

			if (oldcode == -1)
			{
				if (code >= 256) {
					pedro_dprintf(2, "oldcode:-1 code:%i\n", (int)(code));
					pedro_dprintf(2, "uncompress: corrupt input\n");
					//abort_compress();
					return 1;
				}
				outbuf[outpos++] = (char_type)(finchar = (int)(oldcode = code));
				continue;
			}

			if (code == CLEAR && block_mode)
			{
				clear_tab_prefixof();
				free_ent = FIRST - 1;
				posbits = ((posbits-1) + ((n_bits<<3) -
				                          (posbits-1+(n_bits<<3))%(n_bits<<3)));
				maxcode = MAXCODE(n_bits = INIT_BITS)-1;
				bitmask = (1<<n_bits)-1;
				goto resetbuf;
			}

			incode = code;
			stackp = de_stack;

			if (code >= free_ent)           /* Special case for KwKwK string.	*/
			{
				if (code > free_ent)
				{
					REG1 char_type          *p;

					posbits -= n_bits;
					p = &inbuf[posbits>>3];

					pedro_dprintf(2, "insize:%d posbits:%d inbuf:%02X %02X %02X %02X %02X (%d)\n", insize, posbits,
					        p[-1],p[0],p[1],p[2],p[3], (posbits&07));
					pedro_dprintf(2, "uncompress: corrupt input\n");
					//abort_compress();
					
					return 1;
					
				}

				*--stackp = (char_type)finchar;
				code = oldcode;
			}

			while ((cmp_code_int)code >= (cmp_code_int)256)
			{         /* Generate output characters in reverse order */
				*--stackp = tab_suffixof(code);
				code = tab_prefixof(code);
			}

			*--stackp =     (char_type)(finchar = tab_suffixof(code));

			/* And put them out in forward order */

			{
				REG1 int i;

				if (outpos+(i = (de_stack-stackp)) >= OBUFSIZ)
				{
					do
					{
						if (i > OBUFSIZ-outpos) i = OBUFSIZ-outpos;

						if (i > 0)
						{
							memcpy(outbuf+outpos, stackp, i);
							outpos += i;
						}

						if (outpos >= OBUFSIZ)
						{
							if(amanda->dest_is_FILE_z)
							{
								if ((int)fwrite_z(outbuf, 1, outpos, amanda->dest) != (int) outpos)
								{
									
									amanda->internal_error_arp = 6;
									return 6;
									
								}

							}
							else
							{
								if ((int)fwrite(outbuf, 1, outpos, fdout) != (int)outpos)
								{
									
									amanda->internal_error_arp = 6;
									return 6;
									
								}
							}
							amanda->size_of_destination_file_z += outpos;

							outpos = 0;
						}
						stackp+= i;
					}
					while ((i = (de_stack-stackp)) > 0);
				}
				else
				{
					memcpy(outbuf+outpos, stackp, i);
					outpos += i;
				}
			}

			if ((code = free_ent) < maxmaxcode)         /* Generate the new entry. */
			{
				tab_prefixof(code) = (unsigned short)oldcode;
				tab_suffixof(code) = (char_type)finchar;
				free_ent = code+1;
			}

			oldcode = incode;               /* Remember previous code.	*/
		}

		bytes_in += rsize;
	}
	while (rsize > 0);

	if(amanda->dest_is_FILE_z)
	{
		if (outpos > 0 && (int)fwrite_z(outbuf, 1, outpos, amanda->dest) != (int)outpos)
		{
			amanda->internal_error_arp = 6;
			return 6; //cannot write to output file
		}
	}
	else
	{
		if (outpos > 0 && (int)fwrite(outbuf, 1, outpos, fdout) != (int)outpos)
		{
			amanda->internal_error_arp = 6;
			return 6; //cannot write to output file
		}
	}
	amanda->size_of_destination_file_z += outpos;
	return 0;
}
