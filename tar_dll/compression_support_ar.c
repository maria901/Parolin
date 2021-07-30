//december 2020 amanda & ricardo

#ifdef _M_X64
#define MACHINE_ARP "64"
#else
#define MACHINE_ARP "32"
#endif

/**
 * It will init the required DLLs for the compression and
 * decompression
 *
 */
void __fastcall dllinit_arp(void)
{
     char copy_ar[1024];

     if(NULL == my_7z____dll)
     {
	  my_7z____dll = LoadLibraryA
	       (
		    "BE_7zip_r_" MACHINE_ARP ".DLL"
		    );

	  if(NULL == my_7z____dll)
	  {
	       fatal_exit_k = 123490;

	       sprintf(copy_ar, "Cannot find DLL BE_7zip_r_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

	       strcpy(error_message_k, copy_ar);

	       goto dll_error_arp;
			
	  }
	  else
	  {

	       compress_7zip_i_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "compress_7zip_i"
		    );

	       if(NULL == compress_7zip_i_func)
	       {
		    fatal_exit_k = 123491;

		    sprintf(copy_ar, "Cannot find function 'compress_7zip_i' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }
			
	       get_progress_7zip_i_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "get_progress_7zip_i"
		    );

	       if(NULL == get_progress_7zip_i_func)
	       {
		    fatal_exit_k = 123492;

		    sprintf(copy_ar, "Cannot find function 'get_progress_7zip_i' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }
	       pause_7zip_i_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "pause_7zip_i"
		    );

	       if(NULL == pause_7zip_i_func)
	       {
		    fatal_exit_k = 123493;

		    sprintf(copy_ar, "Cannot find function 'pause_7zip_i' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }
	       resume_7zip_i_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "resume_7zip_i"
		    );

	       if(NULL == resume_7zip_i_func)
	       {
		    fatal_exit_k = 123492;

		    sprintf(copy_ar, "Cannot find function 'resume_7zip_i' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }
	       cancel_7zip_i_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "cancel_7zip_i"
		    );

	       if(NULL == cancel_7zip_i_func)
	       {
		    fatal_exit_k = 123492;

		    sprintf(copy_ar, "Cannot find function 'cancel_7zip_i' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }

	       is_valid_7zip_i_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "is_valid_7zip_i"
		    );

	       if(NULL == is_valid_7zip_i_func)
	       {
		    fatal_exit_k = 123493;

		    sprintf(copy_ar, "Cannot find function 'is_valid_7zip_i' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }
	       
	       uncompress_7zip_i_list_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "uncompress_7zip_i"
		    );

	       if(NULL == uncompress_7zip_i_list_func)
	       {
		    fatal_exit_k = 123493;

		    sprintf(copy_ar, "Cannot find function 'uncompress_7zip_i' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }

	       get_tar_info_libarchive_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "get_tar_info_libarchive_i"
		    );

	       if(NULL == get_tar_info_libarchive_func)
	       {
		    fatal_exit_k = 123494;

		    sprintf(copy_ar, "Cannot find function 'get_tar_info_libarchive_i' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }
	       
	       uncompress_7zip_i_extraction_func = (void *) GetProcAddress(
		    my_7z____dll,
		    "uncompress_7zip_i_extraction"
		    );

	       if(NULL == uncompress_7zip_i_extraction_func)
	       {
		    fatal_exit_k = 123495;

		    sprintf(copy_ar, "Cannot find function 'uncompress_7zip_i_extraction' from BE_7zip_r_" MACHINE_ARP ".DLL");

		    strcpy(error_message_k, copy_ar);
	       }
	  }
     }
	
	
	if(NULL == my_libarchive_dll)
	{
		my_libarchive_dll = LoadLibraryA
			      (
			"BE_libarchive_" MACHINE_ARP ".DLL"
		              );

		if(NULL == my_libarchive_dll)
		{
			fatal_exit_k = 12345;

			sprintf(copy_ar, "Cannot find DLL BE_libarchive_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;
			
		}
		else
		{

			libarchive_create_archive_init_p_func = (void *) GetProcAddress(
				my_libarchive_dll,
				"libarchive_create_archive_init_p"
				);

			if(NULL == libarchive_create_archive_init_p_func)
			{
				fatal_exit_k = 123456;

				sprintf(copy_ar, "Cannot find function 'libarchive_create_archive_init_p' from BE_libarchive_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
			libarchive_process_p_func = (void *) GetProcAddress(
				my_libarchive_dll,
				"libarchive_process_p"
				);

			if(NULL == libarchive_process_p_func)
			{
				fatal_exit_k = 123456;

				sprintf(copy_ar, "Cannot find function 'libarchive_process_p' from BE_libarchive_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
			libarchive_close_p_func = (void *) GetProcAddress(
				my_libarchive_dll,
				"libarchive_close_p"
				);

			if(NULL == libarchive_close_p_func)
			{
				fatal_exit_k = 123456;

				sprintf(copy_ar, "Cannot find function 'libarchive_close_p' from BE_libarchive_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			set_progress_p_func = (void *) GetProcAddress(
			     my_libarchive_dll,
			     "set_progress_p"
			     );

			if(NULL == set_progress_p_func)
			{
			     fatal_exit_k = 123456;

			     sprintf(copy_ar, "Cannot find function 'set_progress_p' from BE_libarchive_" MACHINE_ARP ".DLL");

			     strcpy(error_message_k, copy_ar);
			}
			
			libarchive_list_entries_p_func = (void *) GetProcAddress(
			     my_libarchive_dll,
			     "libarchive_list_entries_p"
			     );

			if(NULL == libarchive_list_entries_p_func)
			{
			     fatal_exit_k = 123457;

			     sprintf(copy_ar, "Cannot find function 'libarchive_list_entries_p' from BE_libarchive_" MACHINE_ARP ".DLL");

			     strcpy(error_message_k, copy_ar);
			}

			get_tar_info_p_func = (void *) GetProcAddress(
			     my_libarchive_dll,
			     "get_tar_info_p"
			     );

			if(NULL == get_tar_info_p_func)
			{
			     fatal_exit_k = 123457;

			     sprintf(copy_ar, "Cannot find function 'get_tar_info_p' from BE_libarchive_" MACHINE_ARP ".DLL");

			     strcpy(error_message_k, copy_ar);
			}
			
			libarchive_extract_entries_p_func = (void *) GetProcAddress(
			     my_libarchive_dll,
			     "libarchive_extract_entries_p"
			     );

			if(NULL == libarchive_extract_entries_p_func)
			{
			     fatal_exit_k = 123457;

			     sprintf(copy_ar, "Cannot find function 'libarchive_extract_entries_p' from BE_libarchive_" MACHINE_ARP ".DLL");

			     strcpy(error_message_k, copy_ar);
			}
			
			progress_extract_i_func = (void *) GetProcAddress(
			     my_libarchive_dll,
			     "progress_extract_i"
			     );

			if(NULL == progress_extract_i_func)
			{
			     fatal_exit_k = 123457;

			     sprintf(copy_ar, "Cannot find function 'progress_extract_i' from BE_libarchive_" MACHINE_ARP ".DLL");

			     strcpy(error_message_k, copy_ar);
			}

			extract_to_file_i_func = (void *) GetProcAddress(
			     my_libarchive_dll,
			     "extract_to_file_i"
			     );

			if(NULL == extract_to_file_i_func)
			{
			     fatal_exit_k = 123458;

			     sprintf(copy_ar, "Cannot find function 'extract_to_file_i' from BE_libarchive_" MACHINE_ARP ".DLL");

			     strcpy(error_message_k, copy_ar);
			}
			
		}
	}
	
	if(NULL == my_gzip_dll)
	{
		my_gzip_dll = LoadLibraryA
			      (
			"rspgzip200_" MACHINE_ARP ".dll"
		              );

		if(NULL == my_gzip_dll)
		{
			fatal_exit_k = 30;

			sprintf(copy_ar, "Cannot find DLL rspgzip200_" MACHINE_ARP ".dll, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;
			
		}
		else
		{

			Compress_gzip_ar_func = (void *) GetProcAddress(
				my_gzip_dll,
				"CompressGzip_utf8_k"
				);

			if(NULL == Compress_gzip_ar_func)
			{
				fatal_exit_k = 31;

				sprintf(copy_ar, "Cannot find function 'CompressGzip_utf8_k' from rspgzip200_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}

			GetFinished_gzip_ar_func =(void *) GetProcAddress(
				my_gzip_dll,
				"GetFinished"
				);

			if(NULL == GetFinished_gzip_ar_func)
			{
				fatal_exit_k = 32;

				sprintf(copy_ar, "Cannot find function 'GetFinished' from rspgzip200_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}

			GetProgress_gzip_ar_func =(void *) GetProcAddress(
				my_gzip_dll,
				"GetProgress"
				);

			if(NULL == GetProgress_gzip_ar_func)
			{
				fatal_exit_k = 33;

				sprintf(copy_ar, "Cannot find function 'GetProgress' from rspgzip200_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}

			PauseExecution_gzip_ar_func =(void *) GetProcAddress(
				my_gzip_dll,
				"PauseExecution"
				);

			if(NULL == PauseExecution_gzip_ar_func)
			{
				fatal_exit_k = 34;

				sprintf(copy_ar, "Cannot find function 'PauseExecution' from rspgzip200_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}

			ResumeExecution_gzip_ar_func =(void *) GetProcAddress(
				my_gzip_dll,
				"ResumeExecution"
				);

			if(NULL == ResumeExecution_gzip_ar_func)
			{
				fatal_exit_k = 35;

				sprintf(copy_ar, "Cannot find function 'ResumeExecution' from rspgzip200_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}

			CancelExecution_gzip_ar_func =(void *) GetProcAddress(
				my_gzip_dll,
				"CancelExecution"
				);

			if(NULL == CancelExecution_gzip_ar_func)
			{
				fatal_exit_k = 36;

				sprintf(copy_ar, "Cannot find function 'CancelExecution' from rspgzip200_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}

			GetReturnValue_gzip_ar_func =(void *) GetProcAddress(
				my_gzip_dll,
				"GetReturnValue"
				);

			if(NULL == GetReturnValue_gzip_ar_func)
			{
				fatal_exit_k = 37;

				sprintf(copy_ar, "Cannot find function 'GetReturnValue' from rspgzip200_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}

			Uncompress_gzip_ar_func =(void *) GetProcAddress(
				my_gzip_dll,
				"UncompressGzip_utf8_k"
				);

			if(NULL == Uncompress_gzip_ar_func)
			{
				fatal_exit_k = 38;

				sprintf(copy_ar, "Cannot find function 'UncompressGzip_utf8_k' from rspgzip200_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}
		}
	}


	if(NULL == my_bz2__dll)
	{
		my_bz2__dll = LoadLibraryA
			      (
			"rspbzip2_" MACHINE_ARP ".dll"
		              );

		if(NULL == my_bz2__dll)
		{
			fatal_exit_k = 40;

			sprintf(copy_ar, "Cannot find DLL rspbzip2_" MACHINE_ARP ".dll, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;
		}
		else
		{

			Compress_bzip2_ar_func =(void *) GetProcAddress(
				my_bz2__dll,
				"Compress"
				);

			if(NULL == Compress_bzip2_ar_func)
			{
				fatal_exit_k = 41;

				sprintf(copy_ar, "Cannot find function 'Compress' from rspbzip2_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}
			GetStatus_bzip2_ar_func =(void *) GetProcAddress(
				my_bz2__dll,
				"GetStatus"
				);

			if(NULL == GetStatus_bzip2_ar_func)
			{
				fatal_exit_k = 42;

				sprintf(copy_ar, "Cannot find function 'GetStatus' from rspbzip2_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}
			GetProgress_bzip2_ar_func =(void *) GetProcAddress(
				my_bz2__dll,
				"GetProgress"
				);

			if(NULL == GetProgress_bzip2_ar_func)
			{
				fatal_exit_k = 43;

				sprintf(copy_ar, "Cannot find function 'GetProgress' from rspbzip2_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}
			PauseCompress_bzip2_ar_func =(void *) GetProcAddress(
				my_bz2__dll,
				"PauseCompress"
				);

			if(NULL == PauseCompress_bzip2_ar_func)
			{
				fatal_exit_k = 44;

				sprintf(copy_ar, "Cannot find function 'PauseCompress' from rspbzip2_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}
			ResumeCompress_bzip2_ar_func =(void *) GetProcAddress(
				my_bz2__dll,
				"ResumeCompress"
				);

			if(NULL == ResumeCompress_bzip2_ar_func)
			{
				fatal_exit_k = 45;

				sprintf(copy_ar, "Cannot find function 'ResumeCompress' from rspbzip2_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}
			CancelCompress_bzip2_ar_func =(void *) GetProcAddress(
				my_bz2__dll,
				"CancelCompress"
				);

			if(NULL == CancelCompress_bzip2_ar_func)
			{
				fatal_exit_k = 46;

				sprintf(copy_ar, "Cannot find function 'CancelCompress' from rspbzip2_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}
			Decompress_bzip2_ar_func =(void *) GetProcAddress(
				my_bz2__dll,
				"Decompress"
				);

			if(NULL == Decompress_bzip2_ar_func)
			{
				fatal_exit_k = 47;

				sprintf(copy_ar, "Cannot find function 'Decompress' from rspbzip2_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}

			GetReturnValue_bzip2_ar_func =(void *) GetProcAddress(
				my_bz2__dll,
				"GetReturnValue"
				);

			if(NULL == GetReturnValue_bzip2_ar_func)
			{
				fatal_exit_k = 48;

				sprintf(copy_ar, "Cannot find function 'GetReturnValue' from rspbzip2_" MACHINE_ARP ".dll");

				strcpy(error_message_k, copy_ar);
			}
		}
	}
	if(NULL == my_lzip__dll)
	{
		my_lzip__dll = LoadLibraryA
			       (
			"bw_lzip_aakp_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_lzip__dll)
		{
			fatal_exit_k = 300;

			sprintf(copy_ar, "Cannot find DLL bw_lzip_aakp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_lzip_rspk_ar_func = (void *) GetProcAddress(
				my_lzip__dll,
				"compress_lzip_rspk"
				);

			if(NULL == compress_lzip_rspk_ar_func)
			{
				fatal_exit_k = 310;

				sprintf(copy_ar, "Cannot find function 'compress_lzip_rspk' from bw_lzip_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_lzip_ar_func = (void *) GetProcAddress(
				my_lzip__dll,
				"get_progress_lzip"
				);

			if(NULL == get_progress_lzip_ar_func)
			{
				fatal_exit_k = 311;

				sprintf(copy_ar, "Cannot find function 'get_progress_lzip' from bw_lzip_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}


			uncompress_lzip_rspk_ar_func = (void *) GetProcAddress(
				my_lzip__dll,
				"uncompress_lzip_rspk"
				);

			if(NULL == uncompress_lzip_rspk_ar_func)
			{
				fatal_exit_k = 312;

				sprintf(copy_ar, "Cannot find function 'uncompress_lzip_rspk' from bw_lzip_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}


			pause_lzip_aakp_lzip_ar_func = (void *) GetProcAddress(
				my_lzip__dll,
				"pause_lzip_aakp"
				);

			if(NULL == pause_lzip_aakp_lzip_ar_func)
			{
				fatal_exit_k = 313;

				sprintf(copy_ar, "Cannot find function 'pause_lzip_aakp' from bw_lzip_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}


			resume_lzip_aakp_lzip_ar_func = (void *) GetProcAddress(
				my_lzip__dll,
				"resume_lzip_aakp"
				);

			if(NULL == resume_lzip_aakp_lzip_ar_func)
			{
				fatal_exit_k = 314;

				sprintf(copy_ar, "Cannot find function 'resume_lzip_aakp ;-)' from bw_lzip_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_lzip_aakp_lzip_ar_func = (void *) GetProcAddress(
				my_lzip__dll,
				"cancel_lzip_aakp"
				);

			if(NULL == cancel_lzip_aakp_lzip_ar_func)
			{
				fatal_exit_k = 315;

				sprintf(copy_ar, "Cannot find function 'cancel_lzip_aakp' from bw_lzip_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
		}
	}
	if(NULL == my_lzma__dll)
	{
		my_lzma__dll = LoadLibraryA
			       (
			"rsp_lzma_aakp_" MACHINE_ARP ".dll"
		               );

		if(NULL == my_lzma__dll)
		{
			fatal_exit_k = 400;

			sprintf(copy_ar, "Cannot find DLL rsp_lzma_aakp_" MACHINE_ARP ".dll, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_lzma_rspk_ar_func = (void *) GetProcAddress(
				my_lzma__dll,
				"compress_lzma_aakp_rspk"
				);

			if(NULL == compress_lzma_rspk_ar_func)
			{
				fatal_exit_k = 401;

				sprintf(copy_ar, "Cannot find function 'compress_lzma_aakp_rspk' from rsp_lzma_aakp_" MACHINE_ARP ".dLl");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_lzma_rspk_ar_func = (void *) GetProcAddress(
				my_lzma__dll,
				"uncompress_lzma_aakp_rspk"
				);

			if(NULL == uncompress_lzma_rspk_ar_func)
			{
				fatal_exit_k = 402;

				sprintf(copy_ar, "Cannot find function 'uncompress_lzma_aakp_rspk' from rsp_lzma_aakp_" MACHINE_ARP ".dLl");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_lzma_ar_func = (void *) GetProcAddress(
				my_lzma__dll,
				"Progress"
				);

			if(NULL == get_progress_lzma_ar_func)
			{
				fatal_exit_k = 403;

				sprintf(copy_ar, "Cannot find function 'Progress' from rsp_lzma_aakp_" MACHINE_ARP ".dLl");

				strcpy(error_message_k, copy_ar);
			}

			pause_lzma_aakp_lzma_ar_func = (void *) GetProcAddress(
				my_lzma__dll,
				"Pause"
				);

			if(NULL == pause_lzma_aakp_lzma_ar_func)
			{
				fatal_exit_k = 404;

				sprintf(copy_ar, "Cannot find function 'Pause' from rsp_lzma_aakp_" MACHINE_ARP ".dLl");

				strcpy(error_message_k, copy_ar);
			}

			resume_lzma_aakp_lzma_ar_func = (void *) GetProcAddress(
				my_lzma__dll,
				"Resume"
				);

			if(NULL == resume_lzma_aakp_lzma_ar_func)
			{
				fatal_exit_k = 405;

				sprintf(copy_ar, "Cannot find function 'Resume' from rsp_lzma_aakp_" MACHINE_ARP ".dLl");

				strcpy(error_message_k, copy_ar);
			}

			cancel_lzma_aakp_lzma_ar_func = (void *) GetProcAddress(
				my_lzma__dll,
				"Cancel"
				);

			if(NULL == cancel_lzma_aakp_lzma_ar_func)
			{
				fatal_exit_k = 406;

				sprintf(copy_ar, "Cannot find function 'Cancel' from rsp_lzma_aakp_" MACHINE_ARP ".dLl");

				strcpy(error_message_k, copy_ar);
			}
		}
	}

	if(NULL == my_xz____dll)
	{
		my_xz____dll = LoadLibraryA
			       (
			"rsp_xz_aakp_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_xz____dll)
		{
			fatal_exit_k = 700;

			sprintf(copy_ar, "Cannot find DLL rsp_xz_aakp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_xz___rspk_ar_func = (void *) GetProcAddress
				                     (
				my_xz____dll
				,
				"Compress"
			                             );

			if(NULL == compress_xz___rspk_ar_func)
			{
				fatal_exit_k = 701;

				sprintf(copy_ar, "Cannot find function 'Compress' from rsp_xz_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_xz___rspk_ar_func = (void *) GetProcAddress
				                       (
				my_xz____dll
				,
				"Uncompress"
			                               );

			if(NULL == uncompress_xz___rspk_ar_func)
			{
				fatal_exit_k = 702;

				sprintf(copy_ar, "Cannot find function 'Uncompress' from rsp_xz_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_xz___ar_func = (void *) GetProcAddress
				                    (
				my_xz____dll
				,
				"Progress"
			                            );

			if(NULL == get_progress_xz___ar_func)
			{
				fatal_exit_k = 703;

				sprintf(copy_ar, "Cannot find function 'Progress' from rsp_xz_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_xz___aakp_xz___ar_func = (void *) GetProcAddress
				                       (
				my_xz____dll
				,
				"Pause"
			                               );

			if(NULL == pause_xz___aakp_xz___ar_func)
			{
				fatal_exit_k = 704;

				sprintf(copy_ar, "Cannot find function 'Pause' from rsp_xz_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_xz___aakp_xz___ar_func = (void *) GetProcAddress
				                        (
				my_xz____dll
				,
				"Resume"
			                                );

			if(NULL == resume_xz___aakp_xz___ar_func)
			{
				fatal_exit_k = 705;

				sprintf(copy_ar, "Cannot find function 'Resume' from rsp_xz_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_xz___aakp_xz___ar_func = (void *) GetProcAddress
				                        (
				my_xz____dll
				,
				"Cancel"
			                                );

			if(NULL == cancel_xz___aakp_xz___ar_func)
			{
				fatal_exit_k = 706;

				sprintf(copy_ar, "Cannot find function 'Cancel' from rsp_xz_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
		}
	}

	if(NULL == my_co____dll)
	{
	     
		my_co____dll = LoadLibraryA
			       (
			"BE_compress_aakp_" MACHINE_ARP ".DLL"
		               );
		
		if(NULL == my_co____dll)
		{
			fatal_exit_k = 800;

			sprintf(copy_ar, "Cannot find DLL BE_compress_aakp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_co___rspk_ar_func = (void *) GetProcAddress(
				my_co____dll,
				"compress_co___rspk_ar"
				);

			if(NULL == compress_co___rspk_ar_func)
			{
				fatal_exit_k = 801;

				sprintf(copy_ar, "Cannot find function 'compress_co___rspk_ar' from BE_compress_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_co___rspk_ar_func = (void *) GetProcAddress(
				my_co____dll,
				"uncompress_co___rspk_ar"
				);

			if(NULL == uncompress_co___rspk_ar_func)
			{
				fatal_exit_k = 802;

				sprintf(copy_ar, "Cannot find function 'uncompress_co___rspk_ar' from BE_compress_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_co___ar_func = (void *) GetProcAddress(
				my_co____dll,
				"get_progress_co___ar"
				);

			if(NULL == get_progress_co___ar_func)
			{
				fatal_exit_k = 803;

				sprintf(copy_ar, "Cannot find function 'get_progress_co___ar' from BE_compress_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_co___aakp_co___ar_func = (void *) GetProcAddress(
				my_co____dll,
				"pause_co___aakp_co___ar"
				);

			if(NULL == pause_co___aakp_co___ar_func)
			{
				fatal_exit_k = 804;

				sprintf(copy_ar, "Cannot find function 'pause_co___aakp_co___ar' from BE_compress_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_co___aakp_co___ar_func = (void *) GetProcAddress(
				my_co____dll,
				"resume_co___aakp_co___ar"
				);

			if(NULL == resume_co___aakp_co___ar_func)
			{
				fatal_exit_k = 805;

				sprintf(copy_ar, "Cannot find function 'resume_co___aakp_co___ar' from BE_compress_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_co___aakp_co___ar_func = (void *) GetProcAddress(
				my_co____dll,
				"cancel_co___aakp_co___ar"
				);

			if(NULL == cancel_co___aakp_co___ar_func)
			{
				fatal_exit_k = 806;

				sprintf(copy_ar, "Cannot find function 'cancel_co___aakp_co___ar' from BE_compress_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

		}
	}

	if(NULL == my_ju____dll)
	{
		my_ju____dll = LoadLibraryA
			       (
			"BE_lzop_arp_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_ju____dll)
		{
			fatal_exit_k = 900;

			sprintf(copy_ar, "Cannot find DLL BE_lzop_arp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_ju___rspk_ar_func = (void *) GetProcAddress(
				my_ju____dll,
				"compress_ju___rspk_ar"
				);

			if(NULL == compress_ju___rspk_ar_func)
			{
				fatal_exit_k = 901;

				sprintf(copy_ar, "Cannot find function 'compress_ju___rspk_ar' from BE_lzop_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_ju___rspk_ar_func = (void *) GetProcAddress(
				my_ju____dll,
				"uncompress_ju___rspk_ar"
				);

			if(NULL == uncompress_ju___rspk_ar_func)
			{
				fatal_exit_k = 902;

				sprintf(copy_ar, "Cannot find function 'uncompress_ju___rspk_ar' from BE_lzop_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_ju___ar_func = (void *) GetProcAddress(
				my_ju____dll,
				"get_progress_ju___ar"
				);

			if(NULL == get_progress_ju___ar_func)
			{
				fatal_exit_k = 903;

				sprintf(copy_ar, "Cannot find function 'get_progress_ju___ar' from BE_lzop_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_ju___aakp_ju___ar_func = (void *) GetProcAddress(
				my_ju____dll,
				"pause_ju___aakp_ju___ar"
				);

			if(NULL == pause_ju___aakp_ju___ar_func)
			{
				fatal_exit_k = 904;

				sprintf(copy_ar, "Cannot find function 'pause_ju___aakp_ju___ar' from BE_lzop_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_ju___aakp_ju___ar_func = (void *) GetProcAddress(
				my_ju____dll,
				"resume_ju___aakp_ju___ar"
				);

			if(NULL == resume_ju___aakp_ju___ar_func)
			{
				fatal_exit_k = 905;

				sprintf(copy_ar, "Cannot find function 'resume_ju___aakp_ju___ar' from BE_lzop_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_ju___aakp_ju___ar_func = (void *) GetProcAddress(
				my_ju____dll,
				"cancel_ju___aakp_ju___ar"
				);

			if(NULL == cancel_ju___aakp_ju___ar_func)
			{
				fatal_exit_k = 906;

				sprintf(copy_ar, "Cannot find function 'cancel_ju___aakp_ju___ar' from BE_lzop_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

		}
	}

	if(NULL == my_l4____dll)
	{
		my_l4____dll = LoadLibraryA
			       (
			"rsp_lz4_arp_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_l4____dll)
		{
			fatal_exit_k = 1100;

			sprintf(copy_ar, "Cannot find DLL rsp_lz4_arp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_l4___rspk_ar_func = (void *) GetProcAddress(
				my_l4____dll,
				"compress_l4___rspk_ar"
				);

			if(NULL == compress_l4___rspk_ar_func)
			{
				fatal_exit_k = 1101;

				sprintf(copy_ar, "Cannot find function 'compress_l4___rspk_ar' from rsp_lz4_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_l4___rspk_ar_func = (void *) GetProcAddress(
				my_l4____dll,
				"uncompress_l4___rspk_ar"
				);

			if(NULL == uncompress_l4___rspk_ar_func)
			{
				fatal_exit_k = 1102;

				sprintf(copy_ar, "Cannot find function 'uncompress_l4___rspk_ar' from rsp_lz4_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_l4___ar_func = (void *) GetProcAddress(
				my_l4____dll,
				"get_progress_l4___ar"
				);

			if(NULL == get_progress_l4___ar_func)
			{
				fatal_exit_k = 1103;

				sprintf(copy_ar, "Cannot find function 'get_progress_l4___ar' from rsp_lz4_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_l4___aakp_l4___ar_func = (void *) GetProcAddress(
				my_l4____dll,
				"pause_l4___aakp_l4___ar"
				);

			if(NULL == pause_l4___aakp_l4___ar_func)
			{
				fatal_exit_k = 1104;

				sprintf(copy_ar, "Cannot find function 'pause_l4___aakp_l4___ar' from rsp_lz4_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_l4___aakp_l4___ar_func = (void *) GetProcAddress(
				my_l4____dll,
				"resume_l4___aakp_l4___ar"
				);

			if(NULL == resume_l4___aakp_l4___ar_func)
			{
				fatal_exit_k = 1105;

				sprintf(copy_ar, "Cannot find function 'resume_l4___aakp_l4___ar' from rsp_lz4_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_l4___aakp_l4___ar_func = (void *) GetProcAddress(
				my_l4____dll,
				"cancel_l4___aakp_l4___ar"
				);

			if(NULL == cancel_l4___aakp_l4___ar_func)
			{
				fatal_exit_k = 1106;

				sprintf(copy_ar, "Cannot find function 'cancel_l4___aakp_l4___ar' from rsp_lz4_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

		}
	}

	if(NULL == my_zs____dll)
	{
		my_zs____dll = LoadLibraryA
			       (
			"RSP_Zstandard_arp_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_zs____dll)
		{
			fatal_exit_k = 1200;

			sprintf(copy_ar, "Cannot find DLL RSP_Zstandard_arp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_zs___rspk_ar_func = (void *) GetProcAddress(
				my_zs____dll,
				"compress_zs___rspk_ar"
				);

			if(NULL == compress_zs___rspk_ar_func)
			{
				fatal_exit_k = 1201;

				sprintf(copy_ar, "Cannot find function 'compress_zs___rspk_ar' from RSP_Zstandard_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_zs___rspk_ar_func = (void *) GetProcAddress(
				my_zs____dll,
				"uncompress_zs___rspk_ar"
				);

			if(NULL == uncompress_zs___rspk_ar_func)
			{
				fatal_exit_k = 1202;

				sprintf(copy_ar, "Cannot find function 'uncompress_zs___rspk_ar' from RSP_Zstandard_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_zs___ar_func = (void *) GetProcAddress(
				my_zs____dll,
				"get_progress_zs___ar"
				);

			if(NULL == get_progress_zs___ar_func)
			{
				fatal_exit_k = 1203;

				sprintf(copy_ar, "Cannot find function 'get_progress_zs___ar' from RSP_Zstandard_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_zs___aakp_zs___ar_func = (void *) GetProcAddress(
				my_zs____dll,
				"pause_zs___aakp_zs___ar"
				);

			if(NULL == pause_zs___aakp_zs___ar_func)
			{
				fatal_exit_k = 1204;

				sprintf(copy_ar, "Cannot find function 'pause_zs___aakp_zs___ar' from RSP_Zstandard_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_zs___aakp_zs___ar_func = (void *) GetProcAddress(
				my_zs____dll,
				"resume_zs___aakp_zs___ar"
				);

			if(NULL == resume_zs___aakp_zs___ar_func)
			{
				fatal_exit_k = 1205;

				sprintf(copy_ar, "Cannot find function 'resume_zs___aakp_zs___ar' from RSP_Zstandard_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_zs___aakp_zs___ar_func = (void *) GetProcAddress(
				my_zs____dll,
				"cancel_zs___aakp_zs___ar"
				);

			if(NULL == cancel_zs___aakp_zs___ar_func)
			{
				fatal_exit_k = 1206;

				sprintf(copy_ar, "Cannot find function 'cancel_zs___aakp_zs___ar' from RSP_Zstandard_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

		}
	}

	if(NULL == my_br____dll)
	{
		my_br____dll = LoadLibraryA
			       (
			"rsp_brotli_arp_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_br____dll)
		{
			fatal_exit_k = 1300;

			sprintf(copy_ar, "Cannot find DLL rsp_brotli_arp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_br___rspk_ar_func = (void *) GetProcAddress(
				my_br____dll,
				"compress_br___rspk_ar"
				);

			if(NULL == compress_br___rspk_ar_func)
			{
				fatal_exit_k = 1301;

				sprintf(copy_ar, "Cannot find function 'compress_br___rspk_ar' from rsp_brotli_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_br___rspk_ar_func = (void *) GetProcAddress(
				my_br____dll,
				"uncompress_br___rspk_ar"
				);

			if(NULL == uncompress_br___rspk_ar_func)
			{
				fatal_exit_k = 1302;

				sprintf(copy_ar, "Cannot find function 'uncompress_br___rspk_ar' from rsp_brotli_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_br___ar_func = (void *) GetProcAddress(
				my_br____dll,
				"get_progress_br___ar"
				);

			if(NULL == get_progress_br___ar_func)
			{
				fatal_exit_k = 1303;

				sprintf(copy_ar, "Cannot find function 'get_progress_br___ar' from rsp_brotli_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_br___aakp_br___ar_func = (void *) GetProcAddress(
				my_br____dll,
				"pause_br___aakp_br___ar"
				);

			if(NULL == pause_br___aakp_br___ar_func)
			{
				fatal_exit_k = 1304;

				sprintf(copy_ar, "Cannot find function 'pause_br___aakp_br___ar' from rsp_brotli_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_br___aakp_br___ar_func = (void *) GetProcAddress(
				my_br____dll,
				"resume_br___aakp_br___ar"
				);

			if(NULL == resume_br___aakp_br___ar_func)
			{
				fatal_exit_k = 1305;

				sprintf(copy_ar, "Cannot find function 'resume_br___aakp_br___ar' from rsp_brotli_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_br___aakp_br___ar_func = (void *) GetProcAddress(
				my_br____dll,
				"cancel_br___aakp_br___ar"
				);

			if(NULL == cancel_br___aakp_br___ar_func)
			{
				fatal_exit_k = 1306;

				sprintf(copy_ar, "Cannot find function 'cancel_br___aakp_br___ar' from rsp_brotli_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

		}
	}

	if(NULL == my_g2____dll)
	{
		my_g2____dll = LoadLibraryA
			       (
			"rsp_gzip2_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_g2____dll)
		{
			fatal_exit_k = 1400;

			sprintf(copy_ar, "Cannot find DLL rsp_gzip2_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_g2___rspk_ar_func = (void *) GetProcAddress(
				my_g2____dll,
				"compress_g2___rspk_ar"
				);

			if(NULL == compress_g2___rspk_ar_func)
			{
				fatal_exit_k = 1401;

				sprintf(copy_ar, "Cannot find function 'compress_g2___rspk_ar' from rsp_gzip2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_g2___rspk_ar_func = (void *) GetProcAddress(
				my_g2____dll,
				"uncompress_g2___rspk_ar"
				);

			if(NULL == uncompress_g2___rspk_ar_func)
			{
				fatal_exit_k = 1402;

				sprintf(copy_ar, "Cannot find function 'uncompress_g2___rspk_ar' from rsp_gzip2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_g2___ar_func = (void *) GetProcAddress(
				my_g2____dll,
				"get_progress_g2___ar"
				);

			if(NULL == get_progress_g2___ar_func)
			{
				fatal_exit_k = 1403;

				sprintf(copy_ar, "Cannot find function 'get_progress_g2___ar' from rsp_gzip2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_g2___aakp_g2___ar_func = (void *) GetProcAddress(
				my_g2____dll,
				"pause_g2___aakp_g2___ar"
				);

			if(NULL == pause_g2___aakp_g2___ar_func)
			{
				fatal_exit_k = 1404;

				sprintf(copy_ar, "Cannot find function 'pause_g2___aakp_g2___ar' from rsp_gzip2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_g2___aakp_g2___ar_func = (void *) GetProcAddress(
				my_g2____dll,
				"resume_g2___aakp_g2___ar"
				);

			if(NULL == resume_g2___aakp_g2___ar_func)
			{
				fatal_exit_k = 1405;

				sprintf(copy_ar, "Cannot find function 'resume_g2___aakp_g2___ar' from rsp_gzip2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_g2___aakp_g2___ar_func = (void *) GetProcAddress(
				my_g2____dll,
				"cancel_g2___aakp_g2___ar"
				);

			if(NULL == cancel_g2___aakp_g2___ar_func)
			{
				fatal_exit_k = 1406;

				sprintf(copy_ar, "Cannot find function 'cancel_g2___aakp_g2___ar' from rsp_gzip2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

		}
	}

	if(NULL == my_b3____dll)
	{
		my_b3____dll = LoadLibraryA
			       (
			"rsp_bzip3_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_b3____dll)
		{
			fatal_exit_k = 1500;

			sprintf(copy_ar, "Cannot find DLL rsp_bzip3_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_b3___rspk_ar_func = (void *) GetProcAddress(
				my_b3____dll,
				"compress_b3___rspk_ar"
				);

			if(NULL == compress_b3___rspk_ar_func)
			{
				fatal_exit_k = 1501;

				sprintf(copy_ar, "Cannot find function 'compress_b3___rspk_ar' from rsp_bzip3_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_b3___rspk_ar_func = (void *) GetProcAddress(
				my_b3____dll,
				"uncompress_b3___rspk_ar"
				);

			if(NULL == uncompress_b3___rspk_ar_func)
			{
				fatal_exit_k = 1502;

				sprintf(copy_ar, "Cannot find function 'uncompress_b3___rspk_ar' from rsp_bzip3_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_b3___ar_func = (void *) GetProcAddress(
				my_b3____dll,
				"get_progress_b3___ar"
				);

			if(NULL == get_progress_b3___ar_func)
			{
				fatal_exit_k = 1503;

				sprintf(copy_ar, "Cannot find function 'get_progress_b3___ar' from rsp_bzip3_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_b3___aakp_b3___ar_func = (void *) GetProcAddress(
				my_b3____dll,
				"pause_b3___aakp_b3___ar"
				);

			if(NULL == pause_b3___aakp_b3___ar_func)
			{
				fatal_exit_k = 1504;

				sprintf(copy_ar, "Cannot find function 'pause_b3___aakp_b3___ar' from rsp_bzip3_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_b3___aakp_b3___ar_func = (void *) GetProcAddress(
				my_b3____dll,
				"resume_b3___aakp_b3___ar"
				);

			if(NULL == resume_b3___aakp_b3___ar_func)
			{
				fatal_exit_k = 1505;

				sprintf(copy_ar, "Cannot find function 'resume_b3___aakp_b3___ar' from rsp_bzip3_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_b3___aakp_b3___ar_func = (void *) GetProcAddress(
				my_b3____dll,
				"cancel_b3___aakp_b3___ar"
				);

			if(NULL == cancel_b3___aakp_b3___ar_func)
			{
				fatal_exit_k = 1506;

				sprintf(copy_ar, "Cannot find function 'cancel_b3___aakp_b3___ar' from rsp_bzip3_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
		}
	}
	
	if(NULL == my_l3____dll)
	{
		my_l3____dll = LoadLibraryA
			       (
			"rsp_lzop2_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_l3____dll)
		{
			fatal_exit_k = 1600;

			sprintf(copy_ar, "Cannot find DLL rsp_lzop2_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_l3___rspk_ar_func = (void *) GetProcAddress(
				my_l3____dll,
				"compress_l3___rspk_ar"
				);

			if(NULL == compress_l3___rspk_ar_func)
			{
				fatal_exit_k = 1601;

				sprintf(copy_ar, "Cannot find function 'compress_l3___rspk_ar' from rsp_lzop2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_l3___rspk_ar_func = (void *) GetProcAddress(
				my_l3____dll,
				"uncompress_l3___rspk_ar"
				);

			if(NULL == uncompress_l3___rspk_ar_func)
			{
				fatal_exit_k = 1602;

				sprintf(copy_ar, "Cannot find function 'uncompress_l3___rspk_ar' from rsp_lzop2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_l3___ar_func = (void *) GetProcAddress(
				my_l3____dll,
				"get_progress_l3___ar"
				);

			if(NULL == get_progress_l3___ar_func)
			{
				fatal_exit_k = 1603;

				sprintf(copy_ar, "Cannot find function 'get_progress_l3___ar' from rsp_lzop2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_l3___aakp_l3___ar_func = (void *) GetProcAddress(
				my_l3____dll,
				"pause_l3___aakp_l3___ar"
				);

			if(NULL == pause_l3___aakp_l3___ar_func)
			{
				fatal_exit_k = 1604;

				sprintf(copy_ar, "Cannot find function 'pause_l3___aakp_l3___ar' from rsp_lzop2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_l3___aakp_l3___ar_func = (void *) GetProcAddress(
				my_l3____dll,
				"resume_l3___aakp_l3___ar"
				);

			if(NULL == resume_l3___aakp_l3___ar_func)
			{
				fatal_exit_k = 1605;

				sprintf(copy_ar, "Cannot find function 'resume_l3___aakp_l3___ar' from rsp_lzop2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_l3___aakp_l3___ar_func = (void *) GetProcAddress(
				my_l3____dll,
				"cancel_l3___aakp_l3___ar"
				);

			if(NULL == cancel_l3___aakp_l3___ar_func)
			{
				fatal_exit_k = 1606;

				sprintf(copy_ar, "Cannot find function 'cancel_l3___aakp_l3___ar' from rsp_lzop2_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
		}
	}

	if(NULL == my_l5____dll)
	{
		my_l5____dll = LoadLibraryA
			       (
			"rsp_lz5_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_l5____dll)
		{
			fatal_exit_k = 1600;

			sprintf(copy_ar, "Cannot find DLL rsp_lz5_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_l5___rspk_ar_func = (void *) GetProcAddress(
				my_l5____dll,
				"compress_l5___rspk_ar"
				);

			if(NULL == compress_l5___rspk_ar_func)
			{
				fatal_exit_k = 1601;

				sprintf(copy_ar, "Cannot find function 'compress_l5___rspk_ar' from rsp_lz5_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_l5___rspk_ar_func = (void *) GetProcAddress(
				my_l5____dll,
				"uncompress_l5___rspk_ar"
				);

			if(NULL == uncompress_l5___rspk_ar_func)
			{
				fatal_exit_k = 1602;

				sprintf(copy_ar, "Cannot find function 'uncompress_l5___rspk_ar' from rsp_lz5_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_l5___ar_func = (void *) GetProcAddress(
				my_l5____dll,
				"get_progress_l5___ar"
				);

			if(NULL == get_progress_l5___ar_func)
			{
				fatal_exit_k = 1603;

				sprintf(copy_ar, "Cannot find function 'get_progress_l5___ar' from rsp_lz5_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_l5___aakp_l5___ar_func = (void *) GetProcAddress(
				my_l5____dll,
				"pause_l5___aakp_l5___ar"
				);

			if(NULL == pause_l5___aakp_l5___ar_func)
			{
				fatal_exit_k = 1604;

				sprintf(copy_ar, "Cannot find function 'pause_l5___aakp_l5___ar' from rsp_lz5_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_l5___aakp_l5___ar_func = (void *) GetProcAddress(
				my_l5____dll,
				"resume_l5___aakp_l5___ar"
				);

			if(NULL == resume_l5___aakp_l5___ar_func)
			{
				fatal_exit_k = 1605;

				sprintf(copy_ar, "Cannot find function 'resume_l5___aakp_l5___ar' from rsp_lz5_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_l5___aakp_l5___ar_func = (void *) GetProcAddress(
				my_l5____dll,
				"cancel_l5___aakp_l5___ar"
				);

			if(NULL == cancel_l5___aakp_l5___ar_func)
			{
				fatal_exit_k = 1606;

				sprintf(copy_ar, "Cannot find function 'cancel_l5___aakp_l5___ar' from rsp_lz5_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
		}
	}
	
	if(NULL == my_bb____dll)
	{
		my_bb____dll = LoadLibraryA
			       (
			"rsp_brotli2_arp_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_bb____dll)
		{
			fatal_exit_k = 2600;

			sprintf(copy_ar, "Cannot find DLL rsp_brotli2_arp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_bb___rspk_ar_func = (void *) GetProcAddress(
				my_bb____dll,
				"compress_bb___rspk_ar"
				);

			if(NULL == compress_bb___rspk_ar_func)
			{
				fatal_exit_k = 2601;

				sprintf(copy_ar, "Cannot find function 'compress_bb___rspk_ar' from rsp_brotli2_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_bb___rspk_ar_func = (void *) GetProcAddress(
				my_bb____dll,
				"uncompress_bb___rspk_ar"
				);

			if(NULL == uncompress_bb___rspk_ar_func)
			{
				fatal_exit_k = 2602;

				sprintf(copy_ar, "Cannot find function 'uncompress_bb___rspk_ar' from rsp_brotli2_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_bb___ar_func = (void *) GetProcAddress(
				my_bb____dll,
				"get_progress_bb___ar"
				);

			if(NULL == get_progress_bb___ar_func)
			{
				fatal_exit_k = 2603;

				sprintf(copy_ar, "Cannot find function 'get_progress_bb___ar' from rsp_brotli2_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_bb___aakp_bb___ar_func = (void *) GetProcAddress(
				my_bb____dll,
				"pause_bb___aakp_bb___ar"
				);

			if(NULL == pause_bb___aakp_bb___ar_func)
			{
				fatal_exit_k = 2604;

				sprintf(copy_ar, "Cannot find function 'pause_bb___aakp_bb___ar' from rsp_brotli2_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_bb___aakp_bb___ar_func = (void *) GetProcAddress(
				my_bb____dll,
				"resume_bb___aakp_bb___ar"
				);

			if(NULL == resume_bb___aakp_bb___ar_func)
			{
				fatal_exit_k = 2605;

				sprintf(copy_ar, "Cannot find function 'resume_bb___aakp_bb___ar' from rsp_brotli2_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_bb___aakp_bb___ar_func = (void *) GetProcAddress(
				my_bb____dll,
				"cancel_bb___aakp_bb___ar"
				);

			if(NULL == cancel_bb___aakp_bb___ar_func)
			{
				fatal_exit_k = 2606;

				sprintf(copy_ar, "Cannot find function 'cancel_bb___aakp_bb___ar' from rsp_brotli2_arp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
		}
	}
	
	if(NULL == my_c5____dll)
	{
		my_c5____dll = LoadLibraryA
			       (
			"BE_compress2_aakp_" MACHINE_ARP ".DLL"
		               );

		if(NULL == my_c5____dll)
		{
			fatal_exit_k = 3600;

			sprintf(copy_ar, "Cannot find DLL BE_compress2_aakp_" MACHINE_ARP ".DLL, it is required in the same path of the Tar DLL");

			strcpy(error_message_k, copy_ar);

			goto dll_error_arp;

		}
		else
		{

			compress_c5___rspk_ar_func = (void *) GetProcAddress(
				my_c5____dll,
				"compress_c5___rspk_ar"
				);

			if(NULL == compress_c5___rspk_ar_func)
			{
				fatal_exit_k = 3601;

				sprintf(copy_ar, "Cannot find function 'compress_c5___rspk_ar' from BE_compress2_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			uncompress_c5___rspk_ar_func = (void *) GetProcAddress(
				my_c5____dll,
				"uncompress_c5___rspk_ar"
				);

			if(NULL == uncompress_c5___rspk_ar_func)
			{
				fatal_exit_k = 3602;

				sprintf(copy_ar, "Cannot find function 'uncompress_c5___rspk_ar' from BE_compress2_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			get_progress_c5___ar_func = (void *) GetProcAddress(
				my_c5____dll,
				"get_progress_c5___ar"
				);

			if(NULL == get_progress_c5___ar_func)
			{
				fatal_exit_k = 3603;

				sprintf(copy_ar, "Cannot find function 'get_progress_c5___ar' from BE_compress2_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			pause_c5___aakp_c5___ar_func = (void *) GetProcAddress(
				my_c5____dll,
				"pause_c5___aakp_c5___ar"
				);

			if(NULL == pause_c5___aakp_c5___ar_func)
			{
				fatal_exit_k = 3604;

				sprintf(copy_ar, "Cannot find function 'pause_c5___aakp_c5___ar' from BE_compress2_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			resume_c5___aakp_c5___ar_func = (void *) GetProcAddress(
				my_c5____dll,
				"resume_c5___aakp_c5___ar"
				);

			if(NULL == resume_c5___aakp_c5___ar_func)
			{
				fatal_exit_k = 3605;

				sprintf(copy_ar, "Cannot find function 'resume_c5___aakp_c5___ar' from BE_compress2_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}

			cancel_c5___aakp_c5___ar_func = (void *) GetProcAddress(
				my_c5____dll,
				"cancel_c5___aakp_c5___ar"
				);

			if(NULL == cancel_c5___aakp_c5___ar_func)
			{
				fatal_exit_k = 3606;

				sprintf(copy_ar, "Cannot find function 'cancel_c5___aakp_c5___ar' from BE_compress2_aakp_" MACHINE_ARP ".DLL");

				strcpy(error_message_k, copy_ar);
			}
		}
	}
	
dll_error_arp:;
	return;
}
