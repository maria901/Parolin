
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
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Text;
using System.Diagnostics;
using System.Threading;

namespace tar_sample_ar
{
	/// <summary>
	/// Description of ar_create_tar.
	/// </summary>
	public partial class ar_create_tar : Form
	{
		string threads_used_z = "Threads: 1";
		bool show_message__z = false;
		bool mode_is_create;
		bool already_thread = false;
		bool has_multi_thread_support_p = false;
		public ar_create_tar(bool mode_is_create_)
		{
			mode_is_create = mode_is_create_;
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		~ar_create_tar()
		{
			util_ar.pedro_dprintf(-1, "finalizer of the form ar_create_tar running...");
		}
		internal static StringBuilder memory___z = new StringBuilder(1025);
		StringBuilder error_message_ar__         = new StringBuilder(1025);
		StringBuilder warning_message_ar__       = new StringBuilder(1025);
		StringBuilder process_message_ar__       = new StringBuilder(1025);
		StringBuilder process_info____ar__       = new StringBuilder(1025);
		void Ar_create_tarLoad(object sender, EventArgs e)
		{
			this.Icon = util_ar.pedro_get_icon();
			
			label3.Text = "Using Encryption: no";
			if(util_ar.use_encryption_arp)
			{
				label3.Text = "Using Encryption: yes";
			}
			
			if(mode_is_create)
				this.Text = "Create compressed file sample project";
			else
			{
				this.Text = "Update compressed file sample project";
				button1.Text = "Update compressed file";
			}
			
			if(util_ar.is_parolin_p)
			{
				this.Text = this.Text + " - Mode is Parolin";
				label3.Visible = true;
			}
			else
			{
				label3.Visible = false;
				this.Text = this.Text + " - Mode is libarchive";
				label4.Left = label4.Left - 100;
				compression_mode_ar_.Left = compression_mode_ar_.Left - 100;
				compression_mode_ar_.Width = compression_mode_ar_.Width + 100;
				
				level_p.Left -= 100;
				label5. Left -= 100;
				button1.Left -= 30 + 30;
				
			}
			
			ar_ch2.Width = mislaine_lv_.Width - 6 - 18;
			
			ar_tar_file_.Text = @"C:\Ava\back\my_tar_file_ar.tar";
			path_to_add_ar.Text = @"C:\Ava\back\extract_k";
			include_ar.Text = "* *.txt *.ini";
			compression_mode_ar_.Items.Clear();
			
			if(util_ar.is_parolin_p)
			{
				level_p.Visible = false;
				label5. Visible = false;
				compression_mode_ar_.Items.Add("tar");
				compression_mode_ar_.Items.Add("tar.gz");
				compression_mode_ar_.Items.Add("tar.gzip2");
				compression_mode_ar_.Items.Add("tar.bz2");
				compression_mode_ar_.Items.Add("tar.bzip3");
				compression_mode_ar_.Items.Add("tar.lz");
				compression_mode_ar_.Items.Add("tar.lzma");
				compression_mode_ar_.Items.Add("tar.xz");
				compression_mode_ar_.Items.Add("tar.Z");
				compression_mode_ar_.Items.Add("tar.Z2");//It is Unix compress as multi-thread
				compression_mode_ar_.Items.Add("tar.lzo");
				compression_mode_ar_.Items.Add("tar.lzo2");
				compression_mode_ar_.Items.Add("tar.lz4");
				compression_mode_ar_.Items.Add("tar.lz5");//LZ5 is LZ4 with multi-thread support
				compression_mode_ar_.Items.Add("tar.zst");//Zstandard https://en.wikipedia.org/wiki/Zstandard, it is the future of file compression and is already replacing .xz in the Linux distributions
				compression_mode_ar_.Items.Add("tar.br"); //Brotli https://en.wikipedia.org/wiki/Brotli is a data format specification for data streams compressed with a specific combination of the general-purpose LZ77 lossless compression algorithm, Huffman coding and 2nd order context modelling. Brotli is a compression algorithm developed by Google and works best for text compression.
				compression_mode_ar_.Items.Add("tar.br2");//Brotli2 is Brotli with multi-thread support
				compression_mode_ar_.Items.Add("val");//'val' means our new advanced tar extended format with full support to windows
				compression_mode_ar_.Items.Add("val.gz");
				compression_mode_ar_.Items.Add("val.gzip2");
				compression_mode_ar_.Items.Add("val.bz2");
				compression_mode_ar_.Items.Add("val.bzip3");
				compression_mode_ar_.Items.Add("val.lz");
				compression_mode_ar_.Items.Add("val.lzma");
				compression_mode_ar_.Items.Add("val.xz");
				compression_mode_ar_.Items.Add("val.Z");
				compression_mode_ar_.Items.Add("val.Z2");//It is Unix compress as multi-thread
				compression_mode_ar_.Items.Add("val.lzo");
				compression_mode_ar_.Items.Add("val.lzo2");
				compression_mode_ar_.Items.Add("val.lz4");
				compression_mode_ar_.Items.Add("val.lz5");//LZ5 is LZ4 with multi-thread support
				compression_mode_ar_.Items.Add("val.zst");
				compression_mode_ar_.Items.Add("val.br");
				compression_mode_ar_.Items.Add("val.br2");//Brotli2 is Brotli with multi-thread support
				//compression_mode_ar_.Items.Add("iso"); the iso was disable in Parolin because libarchive has support to it without executables mkisofs
				
				compression_mode_ar_.Text = "val";
			}
			else
			{
				compression_mode_ar_.Items.Add("zip no password");
				compression_mode_ar_.Items.Add("zip with ZipCrypto");
				compression_mode_ar_.Items.Add("zip with AES-128");
				compression_mode_ar_.Items.Add("zip with AES-256");
				compression_mode_ar_.Items.Add("7zip");
				compression_mode_ar_.Items.Add("7zip Encrypted");
				compression_mode_ar_.Items.Add("7zip Encrypted (Headers)");
				compression_mode_ar_.Items.Add("iso9660");
				compression_mode_ar_.Items.Add("tar mode ustar");
				compression_mode_ar_.Items.Add("tar mode gnutar");
				compression_mode_ar_.Items.Add("tar mode v7tar");
				compression_mode_ar_.Items.Add("tar mode ustar with gzip");
				compression_mode_ar_.Items.Add("tar mode ustar with bzip2");
				compression_mode_ar_.Items.Add("tar mode ustar with xz");
				compression_mode_ar_.Items.Add("tar mode gnutar with gzip");
				compression_mode_ar_.Items.Add("tar mode gnutar with bzip2");
				compression_mode_ar_.Items.Add("tar mode gnutar with xz");
				compression_mode_ar_.Items.Add("tar mode v7tar with gzip");
				compression_mode_ar_.Items.Add("tar mode v7tar with bzip2");
				compression_mode_ar_.Items.Add("tar mode v7tar with xz");
				compression_mode_ar_.Text = "zip no password";
				
				level_p.Items.Add("0");
				level_p.Items.Add("1");
				level_p.Items.Add("2");
				level_p.Items.Add("3");
				level_p.Items.Add("4");
				level_p.Items.Add("5");
				level_p.Items.Add("6");
				level_p.Items.Add("7");
				level_p.Items.Add("8");
				level_p.Items.Add("9");
				
				level_p.Text = "6";
			}
			if("" != util_ar.tar_file_arp)
			{
				button7.Visible = true;
				ar_tar_file_.Text         = util_ar.tar_file_arp;
				path_to_add_ar.Text       = util_ar.path_with_the_files_arp;
				include_ar.Text           = util_ar.include_the_files_or_wildcards_arp;
				compression_mode_ar_.Text = util_ar.compression_mode_arp;
				
				recurse_arp.Checked = false;
				if(util_ar.recurse_on_subfolders_arp)
				{
					recurse_arp.Checked = true;
				}
				if(util_ar.true_if_include__arp)
				{
					Include_arpMouseUp(null, null);
				}
				else
				{
					Exclude_arpMouseUp(null, null);
				}
			}
		}
		StringBuilder pega_pass = new StringBuilder(300);
		
		void mode_is_libarchive_create()
		{
			string password_i;
			int ret_arp;
			int recurse_int;
			mode_is_include_or_exclude in_or_ex;
			libarchive_compression_modes_AR my_mode_ar;
			/*
			if(false == mode_is_create)
			{
				
				MessageBox.Show("libarchive for the moment cannot update files, only create");
				return;
				
			}
			 */
			already_thread = false;
			util_ar.clean_up_memory_p();
			
			//pass the password...
			
			util_ar.get__settings_arp("the_password_arp", pega_pass, pega_pass.Capacity);
			//the password is only relevant if encryption is used, but always pass it...
			
			password_i = util_ar.tounicode(pega_pass.ToString());
			
			util_ar.pass_password(password_i, util_ar.toutf8(password_i));
			
			if("zip no password" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_ZIP__NO_PASSWORD;
			}
			else if("zip with ZipCrypto" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_ZIP__ZIPCRYPTO;
			}
			else if("zip with AES-128" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_ZIP__AES_128;
			}
			else if("zip with AES-256" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_ZIP__AES_256;
			}
			else if("7zip" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_7ZIP;
			}
			else if("7zip Encrypted" == compression_mode_ar_.Text)
			{
				util_ar.set_7zip_encryption_mode_i(0);//to don`t encrypt the headers, just the data
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_7ZIP_ENCRYPTED;
			}
			else if("7zip Encrypted (Headers)" == compression_mode_ar_.Text)
			{
				util_ar.set_7zip_encryption_mode_i(1);//to don`t only encrypt the data but also the headers, without the password files and folders cannot be listed
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_7ZIP_ENCRYPTED_ALSO_HEADERS;
			}
			else if("iso9660" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_ISO9660;
			}
			else if("tar mode ustar" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_TAR;
			}
			else if("tar mode gnutar" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_GNUTAR;
			}
			else if("tar mode v7tar" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_V7TAR;
			}
			else if("tar mode ustar with gzip" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_TAR_GZIP;
			}
			else if("tar mode ustar with bzip2" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_TAR_BZIP2;
			}
			else if("tar mode ustar with xz" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_TAR_XZ;
			}
			else if("tar mode gnutar with gzip" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_GNUTAR_GZIP;
			}
			else if("tar mode gnutar with bzip2" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_GNUTAR_BZIP2;
			}
			else if("tar mode gnutar with xz" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_GNUTAR_XZ;
			}
			
			else if("tar mode v7tar with gzip" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_V7TAR_GZIP;
			}
			else if("tar mode v7tar with bzip2" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_V7TAR_BZIP2;
			}
			else if("tar mode v7tar with xz" == compression_mode_ar_.Text)
			{
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_V7TAR_XZ;
			}
			else
			{
				MessageBox.Show("Invalid format!!!");
				Environment.Exit(27);
				my_mode_ar = libarchive_compression_modes_AR.P_MODE_IS_ZIP__NO_PASSWORD;//to make the compiler happy
			}
			my_error_ar.Text = "Error: <waiting...>";
			//button1.Text = "criando...";
			button1.Refresh();
			//util_ar.get_error_message(error_message_ar__);
			//my_error_ar.Text  = "Error: " + error_message_ar__.ToString();
			
			in_or_ex = mode_is_include_or_exclude.ARP_EXCLUDE_FILES;
			if(true == include_arp.Checked)
			{
				in_or_ex = mode_is_include_or_exclude.ARP_INCLUDE_FILES;
			}
			
			recurse_int = 0;
			if(true == recurse_arp.Checked)
			{
				recurse_int = 1;
			}
			
			util_ar.get__settings_arp("xz_threads", pega_pass, pega_pass.Capacity);
			
			//libarchive for the moment only xz compression can have defined how many threads are used, while Parolin allow many other compression methods to multi-thread
			
			if("" == pega_pass.ToString())
			{
				threads_used_z = "Threads: 1";
				util_ar.set_thread_number(1); // single thread, good progress information but slow
			}
			else
			{
				if("auto" == pega_pass.ToString())
				{
					threads_used_z = "Threads: auto";
					util_ar.set_thread_number(0); // auto detect the number of threads to be used based on the number of processors detected
				}
				else
				{
					try
					{
						ret_arp = int.Parse(pega_pass.ToString());
						
						switch(ret_arp)
						{
							case 1://single thread, default mode
							case 2:
							case 3:
							case 4:
							case 5:
							case 6:
							case 7:
							case 8:
								threads_used_z = "Threads: " + ret_arp;
								util_ar.set_thread_number(ret_arp);
								break;
							default:
								threads_used_z = "Threads: 1";
								util_ar.pedro_dprintf(0, "Invalid thread value\n");
								util_ar.set_thread_number(1);//default
								break;
						}
						
					}
					catch
					{
						threads_used_z = "Threads: 1";
						util_ar.set_thread_number(1);//default...
					}
				}
			}
			
			//if util_ar.size_of_each_file_slice_p is not 0 the resulting
			//file will be splitted in multiple chunks each with this
			//predefined syze in bytes, first file will be <file>.001 and
			//so on
			util_ar.split_compressed_file_p(util_ar.size_of_each_file_slice_p);
			
			if(false == mode_is_create)
			{
				//when updating files with libarchive multiple chunks are not supported
				util_ar.split_compressed_file_p(0);
				
				//for the moment no support to input files as multi-volumes (.001, .002 and so on..), only when listing or extracting, also the resulting file for update will not be splitted in multiples volumes but you can hack and modify the code at any moment , don`t you?
				
				ret_arp = util_ar.libarchive_update_archive_ar_v2
					(
						util_ar.toutf8(ar_tar_file_.Text.Trim()),
						util_ar.toutf8(path_to_add_ar.Text.Trim()),
						util_ar.toutf8(include_ar.Text.Trim()),
						my_mode_ar,
						recurse_int,
						in_or_ex,
						level_p.Text
					);
				
				if(0 == ret_arp)
				{
					tempo_ar.Enabled = true;
				}
				else if(2 == ret_arp)
				{
					MessageBox.Show("Path passed too large");
				}
				else if(4 == ret_arp)
				{
					MessageBox.Show("Already running, call 'Cancel' first");
					my_error_ar.Text = "Error: Already Running";
				}
				else
				{
					MessageBox.Show("libarchive update error number: " + ret_arp);
				}
				
				return;
			}
			else
			{
				
				ret_arp = util_ar.libarchive_create_archive_ar_v2
					(
						util_ar.toutf8(ar_tar_file_.Text.Trim()),
						util_ar.toutf8(path_to_add_ar.Text.Trim()),
						util_ar.toutf8(include_ar.Text.Trim()),
						my_mode_ar,
						recurse_int,
						in_or_ex	,
						level_p.Text
					);
				
			}
			
			if(3 == ret_arp)
			{
				MessageBox.Show("Cannot update iso files for the moment");
				my_error_ar.Text = "Error: Cannot update";
			}
			else if(2 == ret_arp)
			{
				MessageBox.Show("Path larger than MAX_PATH");
				my_error_ar.Text = "Error: Path too large";
				//button1.Text = "criando...";
			}
			else
				tempo_ar.Enabled = true;
			
			
		}
		
		void Button1Click(object sender, EventArgs e)
		{
			string password_i;
			int ret_arp;
			int recurse_int;
			mode_is_include_or_exclude in_or_ex;
			compression_modes_AR my_mode_ar;
			
			if(!util_ar.is_parolin_p)
			{
				util_ar.pedro_dprintf(0, "modo é libarchive");
				mode_is_libarchive_create();
				return;
			}
			
			util_ar.pedro_dprintf(0, "modo é parolin");
			
			already_thread = false;
			util_ar.clean_up_memory_p();
			util_ar.enable_encryption(0);//disable encryption
			if(util_ar.use_encryption_arp)
			{
				util_ar.enable_encryption(1);//if true then enable
			}
			
			//pass the password...
			
			util_ar.get__settings_arp("the_password_arp", pega_pass, pega_pass.Capacity);
			//the password is only relevant if encryption is used, but always pass it...
			
			password_i = util_ar.tounicode(pega_pass.ToString());
			
			util_ar.pass_password(password_i, util_ar.toutf8 (password_i));
			
			//even if no encryption used it is good to define what encryption to use
			
			util_ar.get__settings_arp("encryption_arp", pega_pass, pega_pass.Capacity);//encryption method to use
			
			util_ar.set_encryption_mode_z(pega_pass.ToString());
			
			// set the number of threads to be used
			// for the moment the compressors that have multi-thread support are:
			//
			// XZ
			// Zstandard
			// gzip2     (compression)
			// bzip3     (compression)
			// lzop2     (compression, decompression)
			// lz5       (compression)
			// brotli2   (compression)
			// compress2 (compression, decompression)
			//
			// soon all will have, make some tests to see how fast the
			// compression and decompression occurs when in multi-thread
			// mode
			util_ar.get__settings_arp("xz_threads", pega_pass, pega_pass.Capacity);
			
			if("" == pega_pass.ToString())
			{
				threads_used_z = "Threads: 1";
				util_ar.set_thread_number(1); // single thread, good progress information but slow
			}
			else
			{
				if("auto" == pega_pass.ToString())
				{
					threads_used_z = "Threads: auto";
					util_ar.set_thread_number(0); // auto detect the number of threads to be used based on the number of processors detected
				}
				else
				{
					try
					{
						ret_arp = int.Parse(pega_pass.ToString());
						
						switch(ret_arp)
						{
							case 1://single thread, default mode
							case 2:
							case 3:
							case 4:
							case 5:
							case 6:
							case 7:
							case 8:
								threads_used_z = "Threads: " + ret_arp;
								util_ar.set_thread_number(ret_arp);
								break;
							default:
								threads_used_z = "Threads: 1";
								util_ar.pedro_dprintf(0, "Invalid thread value\n");
								util_ar.set_thread_number(1);//default
								break;
						}
						
					}
					catch
					{
						threads_used_z = "Threads: 1";
						util_ar.set_thread_number(1);//default...
					}
				}
			}
			
			//now the encryption method, old or new, use the old method only if you really need a reason to it
			
			util_ar.get__settings_arp("z_encryption_method", pega_pass, pega_pass.Capacity);
			
			switch(pega_pass.ToString())
			{
				case "":
					util_ar.set_encryption_method_z(z_encryption_method.Z_NEW_MODE);
					break;
				case "Old Mode":
					util_ar.set_encryption_method_z(z_encryption_method.Z_OLD_MODE);
					break;
				case "New Mode (Recommended)":
					util_ar.set_encryption_method_z(z_encryption_method.Z_NEW_MODE);
					break;
				default:
					util_ar.set_encryption_method_z(z_encryption_method.Z_NEW_MODE);
					break;
			}
			
			if("tar" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR;
			}
			else if("tar.gz" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_GZIP;
			}
			else if("tar.gzip2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_GZIP2; //after 28/February/2021 with support to multi-thread
			}
			else if("tar.lz" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_LZIP;
			}
			else if("tar.lzma" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_LZMA;
			}
			else if("tar.xz" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_XZ;
			}
			else if("tar.Z" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_COMPRESS;
			}
			else if("tar.Z2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_COMPRESS2;
			}
			else if("tar.lzo" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_LZOP;
			}
			else if("tar.lzo2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_LZOP2;
			}
			else if("tar.lz4" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_LZ4;
			}
			
			else if("tar.lz5" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_LZ5;
			}
			
			else if("tar.zst" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_ZSTANDARD;
			}
			else if("tar.br" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_BROTLI;
			}
			else if("tar.br2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_BROTLI2;
			}
			else if("tar.bz2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_BZ2;
			}
			else if("tar.bzip3" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_TAR_BZIP3;
			}
			else if("val" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL;
			}
			else if("val.gz" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_GZIP;
			}
			else if("val.gzip2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_GZIP2; //after 28/February/2021 with support to multi-thread
			}
			else if("val.lz" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_LZIP;
			}
			else if("val.lzma" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_LZMA;
			}
			else if("val.xz" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_XZ;
			}
			else if("val.Z" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_COMPRESS;
			}
			else if("val.Z2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_COMPRESS2;
			}
			else if("val.lzo" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_LZOP;
			}
			else if("val.lzo2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_LZOP2;
			}
			else if("val.lz4" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_LZ4;
			}
			
			else if("val.lz5" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_LZ5;
			}
			
			else if("val.zst" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_ZSTANDARD;
			}
			else if("val.br" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_BROTLI;
			}
			else if("val.br2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_BROTLI2;
			}
			else if("val.bz2" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_BZ2;
			}
			else if("val.bzip3" == compression_mode_ar_.Text)
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_BZIP3;
			}/*
			else if("iso" == compression_mode_ar_.Text) iso files was disable in Prolin because libarchive have support to it
			{
				my_mode_ar = compression_modes_AR.AAKP_MODE_ISO;
			}*/
			else
			{
				MessageBox.Show("Invalid format!!!");
				Environment.Exit(27);
				my_mode_ar = compression_modes_AR.AAKP_MODE_VAL_BZ2;//to make the compiler happy
			}
			my_error_ar.Text = "Error: <waiting...>";
			//button1.Text = "criando...";
			button1.Refresh();
			//util_ar.get_error_message(error_message_ar__);
			//my_error_ar.Text  = "Error: " + error_message_ar__.ToString();
			
			in_or_ex = mode_is_include_or_exclude.ARP_EXCLUDE_FILES;
			if(true == include_arp.Checked)
			{
				in_or_ex = mode_is_include_or_exclude.ARP_INCLUDE_FILES;
			}
			
			recurse_int = 0;
			if(true == recurse_arp.Checked)
			{
				recurse_int = 1;
			}
			if(mode_is_create)
			{
				//if util_ar.size_of_each_file_slice_p is not 0 the resulting
				//file will be splitted in multiple chunks each with this
				//predefined syze in bytes, first file will be <file>.001 and
				//so on
				util_ar.split_compressed_file_p(util_ar.size_of_each_file_slice_p);
				
				ret_arp = util_ar.create_archive_ar_v2
					(
						util_ar.toutf8(ar_tar_file_.Text.Trim()),
						util_ar.toutf8(path_to_add_ar.Text.Trim()),
						util_ar.toutf8(include_ar.Text.Trim()),
						my_mode_ar,
						recurse_int,
						in_or_ex
					);
			}
			else
			{
				//when updating a file multi-volume support is not available, at
				//least for the moment
				util_ar.split_compressed_file_p(0);
				
				ret_arp = util_ar.update_archive_ar_v2
					(
						util_ar.toutf8(ar_tar_file_.Text.Trim()),
						util_ar.toutf8(path_to_add_ar.Text.Trim()),
						util_ar.toutf8(include_ar.Text.Trim()),
						my_mode_ar,
						recurse_int,
						in_or_ex
					);
			}
			if(4 == ret_arp)
			{
				MessageBox.Show("Already running, call 'Cancel' first");
				my_error_ar.Text = "Error: Already Running";
			}
			if(3 == ret_arp)
			{
				MessageBox.Show("Cannot update iso files for the moment");
				my_error_ar.Text = "Error: Cannot update";
			}
			else if(2 == ret_arp)
			{
				MessageBox.Show("Path larger than MAX_PATH");
				my_error_ar.Text = "Error: Path too large";
				//button1.Text = "criando...";
			}
			else
				tempo_ar.Enabled = true;
		}
		
		void Button2Click(object sender, EventArgs e)
		{
			util_ar.Pause_ar();
		}
		
		void Tempo_arTick(object sender, EventArgs e)
		{
			int ret_ar;
			
			ret_ar = util_ar.GetStatus_ar();
			
			if(util_ar.is_parolin_p)
				maria_progress.Value = util_ar.GetProgress_ar();
			else
				maria_progress.Value = util_ar.libarchive_get_progress_p();
			
			if(mode_is_create)
				button1.Text = "Creating... " + (maria_progress.Value / 100).ToString() + "% ";
			else
				button1.Text = "Updating... " + (maria_progress.Value / 100).ToString() + "% ";
			if(0 == ret_ar)
			{
				cannot_read_arp.Text   = "Files that cannot be read: "     + util_ar.get_cannot_read_warnings     ();
				invalid_paths_arp.Text = "Paths with invalid attributes: " + util_ar.paths_with_invalid_attributes();
				maria_progress.Value = 10000;
				
				if(mode_is_create)
					button1.Text = "Create Tar file";
				else
					button1.Text = "Update compressed file";
				
				ret_ar = util_ar.GetReturnValue_ar();
				
				if(0 == ret_ar)
				{
					my_error_ar.Text = "Error: <none>";
				}
				else
				{
					util_ar.get_error_message (error_message_ar__);
					my_error_ar.Text = "Error: " + error_message_ar__.ToString();
				}
				tempo_ar.Enabled = false;
				
				if(show_message__z)
				{
					this.WindowState = FormWindowState.Normal;
					MessageBox.Show("Finished...");
				}
				
				mislaine_lv_.Items.Clear();
				
				mislaine_lv_.BeginUpdate();
				retorna_aqui_ar:;
				
				ret_ar = util_ar.get_last_process_information_ar(process_info____ar__);
				
				if(0 != process_info____ar__.ToString().Length)
				{
					mislaine_lv_.Items.Add(util_ar.tounicode(process_info____ar__.ToString()));
				}
				if(0 != ret_ar)
				{
					
					goto retorna_aqui_ar;
					
				}
				mislaine_lv_.EndUpdate();
				
				ret_ar = util_ar.GetReturnValue_ar();
				
				if(0 == ret_ar)
				{
					
					if(util_ar.use_sftp_______arp)
					{
						
						arp_send_sftp amanda = new arp_send_sftp (ar_tar_file_.Text.Trim ());
						amanda.Show();
						
					}
					
				}
				
			}
		}
		
		void Button4Click(object sender, EventArgs e)
		{
			sf_ar_.FileName = "my_tar_file.tar";
			DialogResult aakp = sf_ar_.ShowDialog();
			if(DialogResult.OK == aakp)
			{
				ar_tar_file_.Text = sf_ar_.FileName;
			}
		}
		
		void Button3Click(object sender, EventArgs e)
		{
			fb_ar.SelectedPath = "";
			
			DialogResult aakp = fb_ar.ShowDialog();
			
			if(DialogResult.OK == aakp)
			{
				path_to_add_ar.Text = fb_ar.SelectedPath;
			}
		}
		
		void Button5Click(object sender, EventArgs e)
		{
			util_ar.Resume_ar();
		}
		
		void Button6Click(object sender, EventArgs e)
		{
			util_ar.Cancel_ar();
		}
		
		void Compression_mode_ar_SelectedIndexChanged(object sender, EventArgs e)
		{
			string temp_p = "zip";
			
			if(util_ar.is_parolin_p)
			{
				util_ar.replace_extension_arp(ar_tar_file_.Text, compression_mode_ar_.Text,
				                              process_info____ar__
				                             );
				ar_tar_file_.Text = process_info____ar__.ToString ();
			}
			else
			{
				if("zip no password" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "zip";
				}
				
				if("zip with ZipCrypto" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "zip";
				}
				
				if("zip with AES-128" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "zip";
				}
				
				if("zip with AES-256" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "zip";
				}
				
				if("7zip" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "7z";
				}
				
				if("7zip Encrypted" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "7z";
				}
				
				if("7zip Encrypted (Headers)" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "7z";
				}
				
				if("iso9660" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "iso";
				}
				
				if("tar mode ustar" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar";
				}
				
				if("tar mode gnutar" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar";
				}
				
				if("tar mode v7tar" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar";
				}
				
				if("tar mode ustar with gzip" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar.gz";
				}
				
				if("tar mode ustar with bzip2" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar.bz2";
				}
				
				if("tar mode ustar with xz" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = true;
					temp_p = "tar.xz";
				}
				
				if("tar mode gnutar with gzip" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar.gz";
				}
				
				if("tar mode gnutar with bzip2" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar.bz2";
				}
				
				if("tar mode gnutar with xz" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = true;
					temp_p = "tar.xz";
				}
				
				if("tar mode v7tar with gzip" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar.gz";
				}
				
				if("tar mode v7tar with bzip2" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = false;
					temp_p = "tar.bz2";
				}
				
				if("tar mode v7tar with xz" == compression_mode_ar_.Text)
				{
					has_multi_thread_support_p = true;
					temp_p = "tar.xz";
				}
				
				util_ar.replace_extension_arp(ar_tar_file_.Text, temp_p,
				                              process_info____ar__
				                             );
				ar_tar_file_.Text = process_info____ar__.ToString ();
			}
		}
		
		void Button7Click(object sender, EventArgs e)
		{
			Process process = new Process();
			process.StartInfo.FileName = @"C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Chico_backup_system_bw_arp\BE_backup\BE_backup\bin\Release\BE_backup.exe";
			process.StartInfo.Arguments = "\"" + util_ar.tar_file_arp + "\" \"" + util_ar.destination_backup_path_arp + "\"";
			//MessageBox.Show(process.StartInfo.Arguments);
			process.StartInfo.WindowStyle = ProcessWindowStyle.Normal;
			process.Start();
			//process.BeginOutputReadLine();
			//process.WaitForExit();
			/*
			try
			{
				System.IO.File.Delete(util_ar.tar_file_arp);
			}
			catch
			{
				
			}
			 */
		}
		
		void Include_arpMouseUp(object sender, MouseEventArgs e)
		{
			include_arp.Checked =   true;
			exclude_arp.Checked =  false;
		}
		
		void Exclude_arpMouseUp(object sender, MouseEventArgs e)
		{
			include_arp.Checked =  false;
			exclude_arp.Checked =   true;
		}
		
		void OpçõesToolStripMenuItemClick(object sender, EventArgs e)
		{
			arp_opcoes amanda___ = new arp_opcoes();
			amanda___.ShowDialog();
			label3.Text = "Using Encryption: no";
			if(util_ar.use_encryption_arp)
			{
				label3.Text = "Using Encryption: yes";
			}
			already_thread = false;
		}
		
		void Show_message_zMouseUp(object sender, MouseEventArgs e)
		{
			show_message__z = false;
			this.TopMost    = false;
			if(true == show_message_z.Checked )
			{
				show_message__z = true;
				this.TopMost    = true;
			}
		}
		
		void Memory_zTick(object sender, EventArgs e)
		{
			int ret_arp;
			string final_string_z = util_ar.our_empty_string_arp;
			
			if(!already_thread)
			{
				already_thread = true;
				util_ar.get__settings_arp("xz_threads", pega_pass, pega_pass.Capacity);
				
				if("" == pega_pass.ToString())
				{
					threads_used_z = "Threads: 1";
				}
				else
				{
					if("auto" == pega_pass.ToString())
					{
						threads_used_z = "Threads: auto";
					}
					else
					{
						try
						{
							ret_arp = int.Parse(pega_pass.ToString());
							
							switch(ret_arp)
							{
								case 1://single thread, default mode
								case 2:
								case 3:
								case 4:
								case 5:
								case 6:
								case 7:
								case 8:
									threads_used_z = "Threads: " + ret_arp;
									break;
								default:
									threads_used_z = "Threads: 1";
									break;
							}
							
						}
						catch
						{
							threads_used_z = "Threads: 1";
						}
					}
				}
				
			}
			
			switch(compression_mode_ar_.Text)
			{
				case "tar.gzip2":
					final_string_z = threads_used_z;
					break;
				case "tar.bzip3":
					final_string_z = threads_used_z;
					break;
				case "tar.xz":
					final_string_z = threads_used_z;
					break;
				case "tar.Z2":
					final_string_z = threads_used_z;
					break;
				case "tar.lzo2":
					final_string_z = threads_used_z;
					break;
				case "tar.lz5":
					final_string_z = threads_used_z;
					break;
				case "tar.zst":
					final_string_z = threads_used_z;
					break;
				case "tar.br2":
					final_string_z = threads_used_z;
					break;
					
					
				case "val.gzip2":
					final_string_z = threads_used_z;
					break;
				case "val.bzip3":
					final_string_z = threads_used_z;
					break;
				case "val.xz":
					final_string_z = threads_used_z;
					break;
				case "val.Z2":
					final_string_z = threads_used_z;
					break;
				case "val.lzo2":
					final_string_z = threads_used_z;
					break;
				case "val.lz5":
					final_string_z = threads_used_z;
					break;
				case "val.zst":
					final_string_z = threads_used_z;
					break;
				case "val.br2":
					final_string_z = threads_used_z;
					break;
			}
			util_ar.memory_usage__z(memory___z);
			
			if(util_ar.is_parolin_p)
			{
				memory__label_z/*for your pleasure */.Text = "Memory used: " + memory___z.ToString() + "  " + final_string_z;
			}
			else
			{
				if(has_multi_thread_support_p)
				{
					memory__label_z/*for your pleasure */.Text = "Memory used: " + memory___z.ToString() + "  " + threads_used_z;
				}
				else
				{
					memory__label_z/*for your pleasure */.Text = "Memory used: " + memory___z.ToString();// + "  " + threads_used_z;
				}
			}
		}
		
		void Ar_create_tarFormClosing(object sender, FormClosingEventArgs e)
		{
			//this.Close();
		}
	}
}