
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
 
using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

using Microsoft.Win32;

namespace tar_sample_ar
{

	public enum mode_is_include_or_exclude
	{
		ARP_INCLUDE_FILES,
		ARP_EXCLUDE_FILES,
	}
	public enum amanda_commands
	{
		AAKP_CLEAR,
		AAKP_LIST_PROCESS,
		AAKP_LIST_FINISH,
		AAKP_EXTRACT_PROCESS,
		AAKP_EXTRACT_FINISH,
		AAKP_ERROR,
		AAKP_CREATE_ERROR,
		AAKP_CREATE_WARNING,
		AAKP_CREATE_FINISH,
		AAKP_CREATE_PROCESS,
	};
	
	public enum libarchive_compression_modes_AR
	{
		P_MODE_IS_ZIP__NO_PASSWORD,
		P_MODE_IS_ZIP__ZIPCRYPTO  ,
		P_MODE_IS_ZIP__AES_128    ,
		P_MODE_IS_ZIP__AES_256    ,
		P_MODE_IS_7ZIP            ,
		P_MODE_IS_ISO9660         ,
		P_MODE_IS_TAR             ,
		P_MODE_IS_GNUTAR          ,
		P_MODE_IS_V7TAR           ,
		P_MODE_IS_TAR_GZIP        ,
		P_MODE_IS_TAR_BZIP2       ,
		P_MODE_IS_TAR_XZ          ,
		P_MODE_IS_GNUTAR_GZIP     ,
		P_MODE_IS_GNUTAR_BZIP2    ,
		P_MODE_IS_GNUTAR_XZ       ,
		P_MODE_IS_V7TAR_GZIP      ,
		P_MODE_IS_V7TAR_BZIP2     ,
		P_MODE_IS_V7TAR_XZ        ,
		P_MODE_IS_7ZIP_ENCRYPTED  ,		
		P_MODE_IS_7ZIP_ENCRYPTED_ALSO_HEADERS ,
	}
	public enum compression_modes_AR
	{
		AAKP_MODE_TAR,
		AAKP_MODE_TAR_GZIP,
		AAKP_MODE_TAR_BZ2,
		AAKP_MODE_TAR_LZIP,
		AAKP_MODE_TAR_LZMA,
		AAKP_MODE_TAR_XZ,
		AAKP_MODE_TAR_COMPRESS,
		AAKP_MODE_TAR_LZOP,
		AAKP_MODE_TAR_LZ4,
		AAKP_MODE_TAR_ZSTANDARD,
		AAKP_MODE_TAR_BROTLI,
		AAKP_MODE_VAL, //'VAL' is our new homemade file archiving format to replace tar in windows or Unix now or in 1000 years from now
		AAKP_MODE_VAL_GZIP,
		AAKP_MODE_VAL_BZ2,
		AAKP_MODE_VAL_LZIP,
		AAKP_MODE_VAL_LZMA,
		AAKP_MODE_VAL_XZ,
		AAKP_MODE_VAL_COMPRESS,
		AAKP_MODE_VAL_LZOP,
		AAKP_MODE_VAL_LZ4,
		AAKP_MODE_VAL_ZSTANDARD,
		AAKP_MODE_VAL_BROTLI,
		AAKP_MODE_ISO,     //not in use anymore (22/May/2021), iso is handled by libarchive now, in the past iso was supported by Parolin using external executables (Linux package compiled for Windows mkisofs.exe), but not anymore, now no external executables are required for Parolin and libarchive
		AAKP_MODE_TAR_GZIP2,
		AAKP_MODE_VAL_GZIP2,
		AAKP_MODE_TAR_BZIP3,
		AAKP_MODE_VAL_BZIP3,
		AAKP_MODE_TAR_LZOP2,
		AAKP_MODE_VAL_LZOP2,
		AAKP_MODE_TAR_LZ5,
		AAKP_MODE_VAL_LZ5,
		AAKP_MODE_TAR_BROTLI2,
		AAKP_MODE_VAL_BROTLI2,
		AAKP_MODE_TAR_COMPRESS2,
		AAKP_MODE_VAL_COMPRESS2
	};
		
	public enum z_encryption_method
	{
		Z_OLD_MODE,
		Z_NEW_MODE,
	};
	
	public class util_ar
	{
		public util_ar()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		internal static bool   is_parolin_p          = false;
		public   static long   size_of_each_file_slice_p = 0;
		internal static bool   use_sftp_______arp    = false;
		internal static bool   use_encryption_arp    = false;
		internal static        Progress_arp copia_arp = null;
		internal static bool   cancel_arp;
		internal static string our_empty_string_arp = "";
		internal static string tar_file_arp = our_empty_string_arp;
		internal static string path_with_the_files_arp = our_empty_string_arp;
		internal static bool   recurse_on_subfolders_arp = false;
		internal static string include_the_files_or_wildcards_arp = our_empty_string_arp;
		internal static string compression_mode_arp = our_empty_string_arp;
		internal static string destination_backup_path_arp = our_empty_string_arp;
		internal static bool   true_if_include__arp = false;
		public delegate int tar_callback_ar(amanda_commands value);
		
		internal static System.Drawing.Icon pedro_get_icon()
		{
			return new System.Drawing.Icon("ar_v2.ico");
		}
		
		[DllImportAttribute("kernel32.dll", EntryPoint = "SetProcessWorkingSetSize", ExactSpelling = true, CharSet =
		                    CharSet.Ansi, SetLastError = true)]

		private static extern int SetProcessWorkingSetSize(IntPtr process, int minimumWorkingSetSize, int
		                                                   maximumWorkingSetSize);

		[DllImport("kernel32.dll", CharSet = CharSet.None, ExactSpelling = false)]
		private static extern void OutputDebugString(string lpOutputString);

		/**
		 * It will define the encryption method to use, it can be Z_OLD_MODE or
		 * Z_NEW_MODE, recommended to use the new mode Z_NEW_MODE
		 *
		 * @return always 0
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			set_encryption_method_z (z_encryption_method method_z);
		
		/**
		 * It will define whether the compressed file will be splitted in chunks of the
		 * selected bytes, 0 for no split, first file will be <file.extension>.001
		 * 
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			split_compressed_file_p(long slice_in_bytes_p);
	
		/**
		 * Function to retrieve the Tar file informations
		 *
		 * @param filename_k_ar the name of the file inside the Tar file, utf-8 encoded
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern void get_tar_info_ar
			(
				ref int   Isdir_k_ar,
				ref int   Second_k_ar,
				ref int   Minute_k_ar,
				ref int   Hour_k_ar,
				ref int   Year_k_ar,
				ref int   Month_k_ar,
				ref int   Day_k_ar,
				ref int Size_k_ar,
				StringBuilder  filename_k_ar,
				ref int   Numdir_k_ar,
				ref int   Numfiles_k_ar,
				StringBuilder typeflag_ar_
			);

		/**
		 * It will return the Tar format of the loaded file
		 *
		 * @param format_arp the variable that will return the string
		 * with the format description, it is very informative
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int get_tar_format_arp(StringBuilder format_arp        );
		
		/**
		 * To pass the password to the DLL, if it is not called the password will be "" or an empty string
		 *
		 * @param the_pass_arp_ the input password
		 * 
		 * @param the_pass_arp_as_utf_8 the input password as utf-8, for the moment the 7zip mode requires the password as full unicode, then it is passed as utf-8, all other methods use Ansi strings, the first option but you can modify the code at any moment, don`t you?
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			void pass_password(string the_pass_arp_, string the_pass_arp_as_utf_8);

		/**
		 * To enable or disable the encryption, if possible use the new encryption mode...
		 *
		 * <br><br>Notice that encryption in libarchive mode is defined in the format selection<br>
		 * 
		 * @param enable_arp to enable or disable
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			void enable_encryption(int enable_arp);

		/**
		 * It will replace the extension with a new one provided
		 *
		 * @param whole_path_arp the input path
		 *
		 * @param new_extension_arp the new extension
		 *
		 * @param out_data_arp the output file
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			void
			replace_extension_arp
			(
				string whole_path_arp,
				string new_extension_arp,
				StringBuilder out_data_arp
			);
		
		/**
		 * It will return the progress of the libarchive based execution
		 * 
		 * @return the progress position
		 * 
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int  libarchive_get_progress_p();
		
		/**
		 * Function to retrieve the warning information, see
		 * the sample for more information
		 *
		 * @param message_ar the output string information
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			void get_create_warning_ar(StringBuilder message_ar);

		/**
		 * Function to retrieve the create message, see
		 * the sample project to see where it is required
		 *
		 * @param message_ar the output string
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			void get_create_process_ar(StringBuilder message_ar);

		/**
		 * The internal function that will create a Tar or VAL file, old version, use create_archive_ar instead
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int create_archive_ar
			(
				string tar_filename_ar,
				string path_with_the_files_ar,
				string patern_ar,
				compression_modes_AR compression_ar_mode
			);
		
		/**
		 * This is the function to update a Tar file (or VAL) with new entries or deletion of entries
		 *
		 * @param tar_filename_ar the Tar (or VAL) file to update
		 *
		 * @return 0 if no error, if not the error and a string with the
		 * description of the error can be accessed, after a call to this function
		 * you need to call GetStatus_ar() to wait for the end of the execution and
		 * and GetReturnValue_ar() to know whether the update occurred without
		 * problems and if problems occurred you can call get_error_message to get
		 * the error information
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int update_archive_ar_v2
			(
				string tar_filename_ar,
				string path_with_the_files_ar,
				string patern_ar, //see the 'the__patern_ar__mode' below
				compression_modes_AR compression_ar_mode,
				int recurse_in_subfolders_arp,
				mode_is_include_or_exclude the__patern_ar__mode
			);
		
		/**
		 * This is the function to update a libarchive based compressed file with new entries or removal of entries
		 *
		 * @param tar_filename_ar the libarchive compressed file to update
		 *
		 * @return 0 if no error, if not the error and a string with the
		 * description of the error can be accessed, after a call to this function
		 * you need to call GetStatus_ar() to wait for the end of the execution and
		 * and GetReturnValue_ar() to know whether the update occurred without
		 * problems and if problems occurred you can call get_error_message to get
		 * the error information
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int libarchive_update_archive_ar_v2
			(
				string tar_filename_ar,
				string path_with_the_files_ar,
				string patern_ar, //see the 'the__patern_ar__mode' below
				libarchive_compression_modes_AR compression_ar_mode,
				int recurse_in_subfolders_arp,
				mode_is_include_or_exclude the__patern_ar__mode,
				string compression_level_i
			);

		/**
		 * This function will define the encryption method to
		 * be used, valid values are "AES 256 CTR", "RC4", "SERPENT",
		 * "MARS", "RC6", "TWOFISH"
		 *<br><br>Notice that it don`t affect libarchive based compressed files or code, this is irrelevant to libarchive
		 * 
		 * @param method_arp the string with the selected method,
		 * if it don`t match the valid values the encryption method
		 * will be "AES 256 CTR" for ARP_AES
		 *
		 * @return always 0
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			set_encryption_mode_z(string method_arp);

		/**
		 * To save the settings on the ar_tar_process.ini file (now XML file ar_tar_process.mis), it is located in the same path of the DLL
		 *
		 * @param key_arp the key name
		 *
		 * @param data_arp the data to save
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			save_settings_arp(string key_arp, string data_arp);
		
		/**
		 * To make a call to the SFTP code, sending a local file to the remote path
		 *
		 * @param remote_path_z the remote path (don`t include the remote file to save, it will be detected from the local file name)
		 * @param user_name_z   the SFTP session user name
		 * @param password_z    the SFTP session password
		 * @param host_z        the SFTP host, example:   web.sf.net
		 * @param local_file    the local file to upload
		 *
		 * @return it will return 0 if ok, 0 otherwise, notice that you
		 * need to call get_sftp_return_value_z() to know what is the
		 * return value for the SFTP upload progress, see the sample
		 * project to an example
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int pass_sftp_data_z
			(
				string remote_path_z  ,
				string user_name_z    ,
				string password_z     ,
				string host_z         ,
				string local_file
			);
		
		/**
		 * It will return the error code returned by the call to the main SFTP function call
		 *
		 * @return the error value, 0 if ok
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int get_sftp_return_value_z
			();

		/**
		 * After a call to pass_sftp_data_z it will return a value indicating whether the SFTP code is sending the file or if it was finished
		 *
		 * @return 0 if not running, 1 otherwise
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int is_sftp_running_z
			();
		
		/**
		 * To pause the SFTP process, if paused for a long time the server may close the connection
		 *
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int pause_sftp
			();

		/**
		 * To resume the SFTP process
		 *
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int resume_sftp
			();

		/**
		 * To cancel the SFTP process
		 *
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int cancel_sftp
			();

		/**
		 * To retrieve the current position of the SFTP upload process
		 *
		 * @return 0 to 10000, 10000 = 100%, it was not 100 because 100 slices of the progress bar may not provide a very accurate position of the progress information, 10000 is enough
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int progress_sftp
			();
		
		/**
		 * It will return the current remote path, just to know whether the correct path was selected
		 *
		 * @param path_z the variable that will receive the remote path information, this is just informative
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int get_remote_directory_z(StringBuilder path_z);
		
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int get_key_fingerprint_z(StringBuilder key_z);
		
		/**
		 * To set the temp folder, if the path is invalid it will return an error
		 *
		 * @param folder_z the new temp folder
		 *
		 * @return 0 if no error, or the error value (in this case 1)
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			set_temp_folder_z(string folder_z);

		/**
		 * This function will get some relevant informations about
		 * the processor
		 *
		 * @param the_data_z the string that will receive
		 * the information
		 *
		 * @return
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			get_cpu_data_z(StringBuilder the_data_z);

		/**
		 * It will retrieve the settings from the ar_tar_process.ini (now XML file .mis)
		 *
		 * @param key_arp_z the ini key name
		 *
		 * @param output_len_z the available single bytes to write in the
		 * output StringBuilder
		 * @return 0 if ok
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			get__settings_arp(string key_arp_z, StringBuilder data_arp_z, int output_len_z);

		/**
		 * This function will define whether not only the data but also the headers of the 7zip file will be encrypted
		 * 
		 * @param also_encrypt_headers_i_ 1 to encrypt the headers, 0 to don`t
		 *
		 * @return always 0
		 *  
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			set_7zip_encryption_mode_i(int also_encrypt_headers_i_);
		
		/**
		 * This is the function that will create a Tar or VAL file
		 *
		 * @param tar_filename_ar the destination Tar file
		 *
		 * @param path_with_the_files_ar from where the files will be searched and added
		 *
		 * @param patern_ar the patern to search as an example: "*.ini *.txt", notice that
		 * to include all you need to use "*" and not "*.*"
		 *
		 * @return 0 if no error, or any value if otherwise
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int create_archive_ar_v2
			(
				string tar_filename_ar,
				string path_with_the_files_ar,
				string patern_ar, //see the 'the__patern_ar__mode' below
				compression_modes_AR compression_ar_mode,
				int recurse_in_subfolders_arp,
				mode_is_include_or_exclude the__patern_ar__mode
			);

		/**
		 * This is the function that will create a libarchive compressed file
		 *
		 * @param archive_filename_ar the destination compressed file
		 *
		 * @param path_with_the_files_ar from where the files will be searched and added
		 *
		 * @param patern_ar the patern to search as an example: "*.ini *.txt", notice that
		 * to include all you need to use "*" and not "*.*" or it will not include files without extension, this is the Linux mode to see files and folders
		 *
		 * @param compression_ar_mode the compression method to use
		 * 
		 * @param recurse_in_subfolders_arp whether it will recurse on subfolders
		 * 
		 * @param the__patern_ar__mode whether it will include or exclude the patern (patern_ar argument variable) above
		 * 
		 * @param compression_level_p the compression level to use , use "9" for maximum compression level for the majority of formats
		 * 
		 * @return 0 if no error, or any value if otherwise
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int libarchive_create_archive_ar_v2
			(
				string archive_filename_ar,
				string path_with_the_files_ar,
				string patern_ar, //see the 'the__patern_ar__mode' below
				libarchive_compression_modes_AR compression_ar_mode,
				int recurse_in_subfolders_arp,
				mode_is_include_or_exclude the__patern_ar__mode,
				string compression_level_p
			);
		
		/**
		 * It will retrieve the Tar or libarchive creation status
		 *
		 * @return 0 if not running, 1 otherwise
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int GetStatus_ar();

		/**
		 * It will return the return value for the creation process
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int GetReturnValue_ar();

		/**
		 * It will return the progress position for the creation of Tar (VAL) file or libarchive based file,
		 * it ranges from 0 to 10000, 10000 == 100%
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int GetProgress_ar();

		/**
		 * It will resume the creation process, is it was paused
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int Resume_ar();

		/**
		 * It will pause the creation process
		 *
		 * @return always 0
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int Pause_ar();

		/**
		 * It will cancel the creation process immediatelly, notice that
		 * for the moment XZ and Zstandard multi-thread cannot be cancelled,
		 * will be fixed soon, (this means when we got more time)
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int Cancel_ar();
		
		/**
		 * 	It will return the amount of memory that is being used by the whole
		 * application using the Tar DLL
		 *
		 * @param data_z the string that will receive the information
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int memory_usage__z(StringBuilder data_z);
		
		/**
		 * It will return the current threads or cores decompressing a file, only
		 * usefull at runtime during a extraction, notice that if the file was
		 * compressed with 3 cores then it will decompress with 3 cores even if you
		 * have 8 or more, notice that libarchive don`t use this method that it is
		 * irrelevant to libarchive even when xz multi-thread decompression is used
		 * for the moment, maybe later we are not sure, anyway in this case it will
		 * always return 1
		 *
		 * @return the cores or threads
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			decompression_cores_used__z();
		
		/**
		 * This is the api call that will pass to the DLL the
		 * number of threads to use, limited to 8 threads at this moment
		 * <br><br>In case of libarchive it only affect xz compression while
		 * in Parolin it affects several compression methods listed in readme.txt
		 * some originally developed by us, take a look on it, even in decompression
		 * mode
		 * 
		 * @param value_z the number of threads
		 *
		 * @return always 0
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			set_thread_number(int number_of_threads);

		/**
		 * It will return the number of files that cannot be
		 * read during the last creation process, only affects Parolin, for
		 * the moment it is irrelevant for libarchive mode
		 *
		 * @return the number of files that cannot be read
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			get_cannot_read_warnings();
		
		/**
		 * Return the number of paths that have invalid attributes for the
		 * last creation process, it works for libarchive and Parolin in the same
		 * way
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			paths_with_invalid_attributes();

		/**
		 * Function to get an item from the linked list
		 *
		 * @param data_out_ar the string with the information
		 * on exit
		 *
		 * @return 0 if no more items, or 1 otherwise
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int get_last_process_information_ar(StringBuilder data_out_ar);

		/**
		 * It will retrieve the extraction progress
		 *
		 * @return the value that can be a slice of 0 to 10000, 10000 == 100%
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int GetExtrationProgress_ar();
		
		/**
		 * To get the return value for the list process
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int GetReturnValueFromList();
		
		/**
		 * If the file is compressed by one of the 16 compressors supported
		 * this function will return the progress of the initial uncompression
		 * call, don`t work for libarchive for the moment, only for Parolin
		 * mode
		 *
		 * @return the 0 to 10000 value referred to the progress, 10000 == 100%
		 *
		 */
		[DllImport("ar_tar_process.DLL" /* CallingConvention = CallingConvention.FastCall this don´t work */, CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int
			/* __fastcall */ Initial_Progress_z()/* for your pleasure... */;
		
		/**
		 * It will return the progress of the list process, 0 for the moment, maybe
		 * later, this occurs because the list process is always the initial pass,
		 * if you have suggestions please drop us a line
		 *
		 * @return 0 for the moment
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int GetListProgress_ar();
		
		/**
		 * To know whether the list process is running
		 * 
		 * @return 1 if running, 0 otherwise
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int IsListRunning();
		
		/**
		 * To get the progress value for the ListView being populated
		 *
		 * This is required because in some cases the sample application requires more time
		 * to populate the ListView than compressing or decompressing and the user need to wait
		 * untill it have finished loading data, if you know a faster way please drop us a
		 * line
		 * 
		 * @return the progress value, 100% == 10000
		 * 
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int get_listview_progress_arp();
		
		/**
		 * To retrieve the data after a list process
		 *		 
		 * 
		 * @param filename_k_ar the filename
		 *
		 * @param typeflag_ar_ the kind of the entry, a dir or a file, as a string
		 *
		 * @param Isdir_k_ar if it is a dir
		 *
		 * @param Second_k_ar the second of the file
		 *
		 * @param Minute_k_ar the minute
		 *
		 * @param Hour_k_ar the hour
		 * 
		 * @param Year_k_ar the year
		 * 
		 * @param Month_k_ar the month
		 * 
		 * @param Day_k_ar the day
		 * 
		 * @param Size_k_ar the entry size as bytes, notice that in some formats a folder may have size, this
		 * is wrong and will be fixed soon (if we remember it)
		 * @param Numdir_k_ar number of dirs detected, it will increase until the end of the
		 * code running, please take a look
		 * @param Numfiles_k_ar the number of normal files, it may increase during these calls
		 * 
		 * @param output_len_z the maximum size of the StringBuilders used, no more than this size will be copied to
		 * these variables, 1027 is enough for the moment
		 * 
		 * @return 1 if it have more data
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int get_list__itens__is_list_(
			StringBuilder filename_k_ar,
			StringBuilder typeflag_ar_,
			out int Isdir_k_ar,
			out int Second_k_ar,
			out int Minute_k_ar,
			out int Hour_k_ar,
			out int Year_k_ar,
			out int Month_k_ar,
			out int Day_k_ar,
			out long Size_k_ar,
			out int Numdir_k_ar,
			out int Numfiles_k_ar,
			int output_len_z
		);
		
		/**
		 * It will pause the extraction process
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int ExtractPause_ar();
		
		/**
		 * It will resume the extraction process
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int ExtractResume_ar();
		
		/**
		 * It will cancel the extraction process
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int ExtractCancel_ar();
		
		/**
		 * To retrieve the last error message, all errors have a description that can help debug the problem
		 *
		 * @return void, nothing is returned...
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern void get_error_message(StringBuilder data_ar);
		
		/**
		 * It will extract the tar file 'tar_file_ar' an utf-8 encoded file
		 *
		 * @param tar_file_ar the tar file
		 *
		 * @param destination_folder_ar the destination path, if it doesnot exist it will be created
		 *
		 * @return 1 or 2 on error, 0 otherwise, notice that it spawns a thread that will do the hard job, take a look in the
		 * sample project to see how it works
		 * 
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int extract_tar_file_ar
			(
				string tar_file_ar,
				string destination_folder_ar
			);
		
		/**
		 * It will extract the file 'compressed_file_ar' an utf-8 encoded file using the libarchive
		 * 		 *
		 * @param compressed_file_ar the compressed file
		 *
		 * @param destination_folder_ar the destination path, if it doesnot exist it will be created
		 * 
		 * @return 1 or 2 on error, 0 otherwise, notice that it spawns a thread that will do the hard job, take a look in the
		 * sample project to see how it works
		 * 
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int libarchive_extract_tar_file_ar
			(
				string compressed_file_ar,
				string destination_folder_ar
			);
		
		/**
		 * To get one item from the linked list
		 *
		 * @param extracting_filename_ar__ the filename as utf-8
		 * @param folder_ar_______________ the folder, if the entry was a folder utf8 encoded as the filename
		 * @param warning_info____________ the warning if it was generated by the process, empty string otherwise
		 * @param Folders_ar               the folders got
		 * @param Files_ar                 the files got
		 * @return 1 if it has more items, 0 otherwise
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int get_last_process_information_ar_is_extract_
			(
				StringBuilder extracting_filename_ar__,
				StringBuilder folder_ar_______________,
				StringBuilder warning_info____________,
				out int Folders_ar,
				out int Files_ar
			);
		
		/**
		 * (Not in use at this moment, and if used it will just slowdown code
		 * execution) It will retrieve the extraction information for each call,
		 * see the sample project to see how to use it correctly
		 *
		 * @return always 0
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern int get_extraction_progress_information_ar
			(
				StringBuilder warning_ar,
				StringBuilder filename_ar
			);
		
		/**
		 * This function will list the information for a given Tar file
		 *
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int list_tar_file_ar
			(
				string tar_file_ar
			);
		
		/**
		 * This function will list the information for a given libarchive based file
		 *
		 * @return 0 if no error
		 * 
		 */
		[DllImport("ar_tar_process.DLL", CharSet = CharSet.None, ExactSpelling = false)]
		internal static extern
			int libarchive_list_tar_file_ar
			(
				string tar_file_ar
			);
		
		/**
		 * Internal debug function ;-)
		 * 
		 */
		internal static void pedro_dprintf
			(
				int    amanda_level,
				string maria_data
			)
		{
			if (amanda_level > -1)
			{//07-08-2020
				maria_data += " _amanda_debug_ c# " + amanda_level;
				
				OutputDebugString
					(
						maria_data
					);
				
			}
			return;
		}
		[DllImport("ar_tar_process.DLL")]
		public static extern int
			stringtobyte(ref byte dest, string src, int len);

		[DllImport("ar_tar_process.DLL")]
		public static extern int
			ControlName(StringBuilder version_amanda);
		
		//stringtobyte bytetostring
		[DllImport("ar_tar_process.DLL")]
		public static extern int
			bytetostring(StringBuilder dest, ref byte src, int len);
		public static string bytetostring_csharp(byte[] data)
		{
			StringBuilder _out = new StringBuilder(data.Length + 1);
			if (0 == data.Length)
			{
				return "";
			}
			bytetostring(_out, ref data[0], data.Length);
			return _out.ToString();
		}
		private static byte[] stringtobyte_csharp(string data)
		{
			byte[] _out = new byte[data.Length];
			stringtobyte(ref _out[0], data, data.Length);
			return _out;
		}
		
		public static string toutf8(string data)
		{
			UTF8Encoding encoder = new UTF8Encoding();
			byte[] bytes = Encoding.UTF8.GetBytes(data);

			return bytetostring_csharp(bytes);
		}
		public static string tounicode(string data)
		{
			UTF8Encoding encoder = new UTF8Encoding();

			if (0 == data.Length)
			{
				return "";
			}

			byte[] array = stringtobyte_csharp(data);
			return encoder.GetString(array);
		}
		internal static void our_thread()
		{
			if(null == copia_arp)
			{
				copia_arp = new Progress_arp();//maybe we have a problem here...
			}
			copia_arp.ShowDialog();
		}
		public static void create_form_arp()
		{
			Thread amandaricardo_koci_t = new Thread(new ThreadStart(our_thread));
			amandaricardo_koci_t.Start();
		}
		
		/**
		 * This function will shrink the memory used, at least for
		 * informative purposes here or in the taskmanager, this is just
		 * a mistery about how it can do it but works, it helps in detection
		 * of memory leaks because the memory usage of C# is to high and absurd that
		 * memory leaks go undetected
		 *  
		 */ 
		internal static void clean_up_memory_p()
		{
			GC.Collect();
			GC.WaitForPendingFinalizers();
			if (Environment.OSVersion.Platform == PlatformID.Win32NT)
			{
				SetProcessWorkingSetSize(System.Diagnostics.Process.
				                         GetCurrentProcess().Handle, -1, -1);
			}
		}
	}
}