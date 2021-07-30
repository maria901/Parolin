//2021 by amanda & MathMan
int zuncompress_sha512_k_mt_decoding_multi_thread_z (FILE * source, FILE * dest, my_thread_struct_z * amanda);

unsigned __stdcall my_thread_function_v27(void * my_argument_z   )
{
	my_thread_struct_z * ptr_my_struct_z = (void *) my_argument_z;
	assert(ptr_my_struct_z);
	if(NULL == ptr_my_struct_z->dest)
	{
		goto saida_amanda;
	}
	
	pedro_dprintf(-1, "bytes to extract %lld\n", ptr_my_struct_z->size_of_input_file_copy_z);
	
	/*
	if(0 != ptr_my_struct_z->offset_z)
	{
		
		pedro_dprintf(-1, "seek to %lld\n", ptr_my_struct_z->offset_z);
		
		if(
			0 != _fseeki64(
				ptr_my_struct_z->input_file,
				ptr_my_struct_z->offset_z,
				SEEK_SET
				)
			)
		{
			ptr_my_struct_z->retvalue = 403;  //File access error
			goto saida_amanda;
		}
	}
	*/
	
	//aqui amor...
	
	ptr_my_struct_z->dest_is_FILE_z = true;
	
	ptr_my_struct_z->retvalue = zuncompress_sha512_k_mt_decoding_multi_thread_z(ptr_my_struct_z->input_file, NULL, ptr_my_struct_z);

	if(119 == ptr_my_struct_z->internal_error_arp)
	{
		ptr_my_struct_z->retvalue = 119;
	}
	else if(6 == ptr_my_struct_z->internal_error_arp)
	{
		ptr_my_struct_z->retvalue = ptr_my_struct_z->internal_error_arp;
	}
	else
	{
		if(ptr_my_struct_z->retvalue)
		{
			pedro_dprintf(-1, "error 2 7 \n");
			ptr_my_struct_z->retvalue = 7;                         //Decompression error
		}
	}
	
saida_amanda:;
	
	if (*(ptr_my_struct_z->intcancel))
	{
		ptr_my_struct_z->retvalue = 119;//User abort
	}
	
	if(ptr_my_struct_z->input_file        )
	{
		fclose(ptr_my_struct_z->input_file);
	}
		
	if(0 == thread_return_value_z)
	{
		thread_return_value_z = ptr_my_struct_z->retvalue;
	}
	
	//Sleep(2000);
	
	free(my_argument_z);
	_endthreadex(0);

	return 27+51;
}