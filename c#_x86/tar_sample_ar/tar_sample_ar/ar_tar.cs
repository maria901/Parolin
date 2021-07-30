
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
using System.Threading;

using Microsoft.Win32;
using System.Runtime.InteropServices;

namespace tar_sample_ar
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		protected bool already_ar = false;
		int ret_arp;
		StringBuilder ver = new StringBuilder(300);
		
		void MainFormLoad(object sender, EventArgs e)
		{
			
			util_ar.get_cpu_data_z(warning_ar);
			cpu_z.Text = warning_ar.ToString();
			rspk_progress.SetProgressColor = System.Drawing.Color.DeepPink;
			if(!already_ar)
			{
				this.Top = 0;already_ar = true;
				this.Width = Screen.PrimaryScreen.WorkingArea.Width;// /2;
			}
			this.Icon = util_ar.pedro_get_icon();
			
			util_ar.ControlName(ver);
			
			if (IntPtr.Size == 4)
			{
				this.Text = "Tar sample project - " + ver.ToString();
			}
			else if (IntPtr.Size == 8)
			{
				this.Text = "Tar sample project - " + ver.ToString();
			}
			else
			{
				// The future is now!
			}
			
			mislaine_lv_.Width = this.Width - 42;
			aakp_progress_.Width = mislaine_lv_.Width;
			progress_information_ar.Width = mislaine_lv_.Width;
			ar_ch1.Width = mislaine_lv_.Width - ar_ch2.Width - ar_ch3.Width- ar_ch4.Width- ar_ch5.Width - 5;
			//ar_tar_file_.Text = @"C:\Ava\back\extract_k boleto ♥♥☺ (1).tar";
			
			#if DEBUG_ARP__
			
			ar_tar_file_.Text = @"C:\Ava\back\my_tar_file_ar_07_08.tar";
			my_selected_folder_ar.Text = @"C:\Ava\back\extract_k_que_coisa";
			
			#endif
		}
		internal static StringBuilder memory___z =         new StringBuilder    (1027);
		internal static StringBuilder filename_k =         new StringBuilder    (1027);
		internal static StringBuilder folder_k   =         new StringBuilder    (1027);
		internal static StringBuilder error_message_ar__ = new StringBuilder    (1027);
		internal static StringBuilder typeflag_ar_ =       new StringBuilder    (1027);
		internal static StringBuilder warning_ar =         new StringBuilder    (1027);
		internal static StringBuilder filename_ar =        new StringBuilder    (1027);
		internal static StringBuilder tar_format_arp =     new StringBuilder    (1027);
		
		int Numdir_k = 0;
		int	Numfiles_k = 0;
		
		string convert_to_utf_8_ar;
		void Button1Click(object sender, EventArgs e)
		{
			string password_i;
			int ret_ar;
			util_ar.clean_up_memory_p();
			//since now the uncompressor can run in multi-thread then set the number of threads to use
			util_ar.get__settings_arp("xz_threads", pega_pass, pega_pass.Capacity);
			
			if("" == pega_pass.ToString())
			{
				util_ar.set_thread_number(1);
			}
			else
			{
				if("auto" == pega_pass.ToString())
				{
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
								util_ar.set_thread_number(ret_arp);
								break;
							default:
								util_ar.pedro_dprintf(0, "Invalid thread value\n");
								util_ar.set_thread_number(1);//default
								break;
						}
						
					}
					catch
					{
						util_ar.set_thread_number(1);//default...
					}
				}
			}
			
			//button1.Enabled = false;
			button1.Text = "Working...";
			button1.Refresh();
			folders_ar.Text = "Folders";
			files_ar  .Text = "Files"  ;
			my_error_ar.Text  = "Error: <working...>";

			util_ar.get__settings_arp("the_password_arp", pega_pass, pega_pass.Capacity);
			//the password is only relevant if encryption is used, but always pass it...
			
			password_i = util_ar.tounicode(pega_pass.ToString());
			//testing
			util_ar.pass_password(password_i, util_ar.toutf8(password_i));
			
			convert_to_utf_8_ar = util_ar.toutf8(ar_tar_file_.Text.Trim());
			
			if(util_ar.is_parolin_p)
			{
				ret_ar = util_ar.list_tar_file_ar(convert_to_utf_8_ar);
			}
			else
			{
				ret_ar = util_ar.libarchive_list_tar_file_ar(convert_to_utf_8_ar);
			}
			
			if(0 == ret_ar)
			{
				tempo_ar.Enabled = true;
				util_ar.cancel_arp = false;
			}
			else if(1 == ret_ar)
			{
				MessageBox .Show ("Already running, wait for the end of execution or call cancel");
			}
			else if(2 == ret_ar)
			{
				my_error_ar.Text  = "Error: Error";
				button1.Text = "List";
				MessageBox .Show ("Path length larger than MAX_PATH");
			}
			else if(3 == ret_ar)
			{
				my_error_ar.Text  = "Error: Error";
				button1.Text = "List";
				MessageBox .Show ("Paths cannot be relative");
			}
			//button1.Text = "List";
			//button1.Enabled = true;
		}
		
		void MainFormResize(object sender, EventArgs e)
		{
			MainFormLoad(null, null);
		}
		StringBuilder pega_pass = new StringBuilder(300);
		void Button2Click(object sender, EventArgs e)
		{
			string password_i;
			int ret_ar;
			util_ar.clean_up_memory_p();
			//since now the uncompressor can run in multi-thread then set the number of threads to use
			util_ar.get__settings_arp("xz_threads", pega_pass, pega_pass.Capacity);
			
			if("" == pega_pass.ToString())
			{
				util_ar.set_thread_number(1);
			}
			else
			{
				if("auto" == pega_pass.ToString())
				{
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
								util_ar.set_thread_number(ret_arp);
								break;
							default:
								util_ar.pedro_dprintf(0, "Invalid thread value\n");
								util_ar.set_thread_number(1);//default
								break;
						}
						
					}
					catch
					{
						util_ar.set_thread_number(1);//default...
					}
				}
			}
			
			folders_ar.Text = "Folders ";
			files_ar.Text   =    "Files";
			my_error_ar.Text  = "Error: <working...>";
			progress_information_ar.Items.Clear();
						
			util_ar.get__settings_arp("the_password_arp", pega_pass, pega_pass.Capacity);
			//the password is only relevant if encryption is used, but always pass it...
			
			password_i = util_ar.tounicode(pega_pass.ToString());
			
			util_ar.pass_password(password_i, util_ar.toutf8(password_i));
			
			if(util_ar.is_parolin_p)
			{
				ret_ar = util_ar.extract_tar_file_ar(util_ar.toutf8(ar_tar_file_.Text.Trim()), util_ar.toutf8(my_selected_folder_ar.Text.Trim()));
			}
			else
			{
				ret_ar = util_ar.libarchive_extract_tar_file_ar(util_ar.toutf8(ar_tar_file_.Text.Trim()), util_ar.toutf8(my_selected_folder_ar.Text.Trim()));
			}
			
			if(0 == ret_ar)
			{
				tempo_extract_.Enabled = true;
				util_ar.cancel_arp = false;
			}
			else if(1 == ret_ar)
			{
				MessageBox.Show("Already running, wait or call cancel");
			}
			else if(2 == ret_ar)
			{
				MessageBox .Show ("Path length larger than MAX_PATH");
				my_error_ar.Text  = "Error: Error";
			}
			else if(3 == ret_ar)
			{
				MessageBox .Show ("Paths cannot be relative");
				my_error_ar.Text  = "Error: Error";
			}
		}
		
		void Button4Click(object sender, EventArgs e)
		{
			open_file_ar.FileName = "";
			DialogResult amanda_ = open_file_ar.ShowDialog ();
			if(DialogResult.OK  == amanda_ )
			{
				ar_tar_file_.Text = open_file_ar.FileName ;
			}
		}
		void Button3Click(object sender, EventArgs e)
		{
			DialogResult amanda_ = my_folder_ar .ShowDialog ();
			if(DialogResult.OK  == amanda_ )
			{
				my_selected_folder_ar.Text = my_folder_ar.SelectedPath;
			}
		}
		
		void Button5Click(object sender, EventArgs e)
		{
			ar_create_tar amanda = new ar_create_tar (true);
			amanda.Show();
		}
		internal void our_thread()
		{
			ListViewItem ar_listViewItem;
			int ret_ar;
			util_ar.create_form_arp();
			mislaine_lv_.Items.Clear();
			mislaine_lv_.BeginUpdate();
			aakp_progress_.Value = 9000;
			aakp_progress_.Refresh();
			int Isdir_k = 0;
			int	Second_k = 0;
			int Minute_k = 0;
			int Hour_k = 0;
			int Year_k = 0;
			int Month_k = 0;
			int Day_k = 0;
			long Size_k = 0;
			//char filename_k[1024];
			Numdir_k = 0;
			Numfiles_k = 0;
			again_amanda__:;
			util_ar.pedro_dprintf(-1, "antes");
			ret_ar = util_ar.get_list__itens__is_list_
				(
					filename_k,
					typeflag_ar_,
					out Isdir_k,
					out Second_k,
					out Minute_k,
					out Hour_k,
					out Year_k,
					out Month_k,
					out Day_k,
					out Size_k,
					out Numdir_k,
					out Numfiles_k,
					filename_k.Capacity
				);
			
			util_ar.pedro_dprintf(-1, "depois");
			if(0 != ret_ar)
			{
				/*
					counter_ar ++;
										
					if(0 == (counter_ar % 999))
					{
						this.Refresh();
						util_ar.pedro_dprintf(0, "atualizando o form");
					}*/
				util_ar.pedro_dprintf(-1, "size of '" + filename_k.ToString() + "' : " + Size_k);
				
				if(0 != Isdir_k)
				{
					ar_listViewItem = mislaine_lv_.Items.Add("d");
				}
				else
				{
					ar_listViewItem = mislaine_lv_.Items.Add("-");
				}
				
				convert_to_utf_8_ar = util_ar.tounicode (filename_k.ToString());//kkkkk esta foi legal...
				
				ar_listViewItem.SubItems.Add(convert_to_utf_8_ar);
				
				ar_listViewItem.SubItems.Add
					(
						Day_k.ToString("D2") + "/" +
						Month_k.ToString("D2") + "/" +
						Year_k.ToString() + " " +
						Hour_k.ToString("D2") + ":" +
						Minute_k.ToString("D2") + ":" +
						Second_k.ToString("D2")
					);
				
				ar_listViewItem.SubItems.Add
					(
						typeflag_ar_.ToString ()
					);
				ar_listViewItem.SubItems.Add
					(
						Size_k.ToString ()
					);
				util_ar.pedro_dprintf(-1, "passou");
				//this.Refresh();
			}
			if(0 != ret_ar && false == util_ar.cancel_arp)
			{
				goto again_amanda__;
			}
			aakp_progress_.Value = 10000;
			mislaine_lv_.EndUpdate();
			
			folders_ar.Text = "Folders : " + Numdir_k;
			files_ar  .Text = "Files : " + Numfiles_k  ;
			button1.Text = "List";
			
			ret_ar = util_ar.GetReturnValueFromList();
			
			if(0 == ret_ar)
			{
				my_error_ar.Text  = "Error: <none>";
			}
			else
			{
				util_ar.get_error_message(error_message_ar__);
				my_error_ar.Text  = "Error: " + util_ar.tounicode(error_message_ar__.ToString());
			}
			
			Thread arp_thread = new Thread(new ThreadStart(this.close_form));
			arp_thread.Start();
			
			util_ar.get_tar_format_arp(tar_format_arp);
			format_arp.Text = "tar format: " + tar_format_arp.ToString();
		}
		void Tempo_arTick(object sender, EventArgs e)
		{
			rspk_progress. Value = util_ar.Initial_Progress_z();//also on extraction mode
			aakp_progress_.Value = util_ar.GetListProgress_ar();
			
			//If the selection of the threads to use for compression and decompression
			//is not 1 it will show with how many threads the multi-thread decoder
			//is using to decompress the file, our tests show that for each core
			//a 2 to 10% speed improvement is got
			threads__z.Text = "Threads used in the decompression: " + util_ar.decompression_cores_used__z();
			
			if(0 == util_ar.IsListRunning())
			{
				tempo_ar.Enabled = false;
				our_thread();
			}
		}
		internal void our_thread_extract()
		{
			int Folders_ar = 0;
			int Files_ar = 0  ;
			int ret_ar;
			
			util_ar.create_form_arp();
			folders_ar.Text = "Folders : " + Folders_ar;
			files_ar  .Text = "Files : "   + Files_ar    ;
			aakp_progress_.Value = 10000;
			progress_information_ar.Items.Clear();
			progress_information_ar.BeginUpdate();
			again_amanda__:;
			
			ret_ar =	util_ar.get_last_process_information_ar_is_extract_
				(
					filename_ar,  //capacity 1027
					folder_k,     //capacity 1027
					warning_ar,
					out Folders_ar,
					out Files_ar
				);
			
			if(0 != ret_ar)
			{
				if(0 != warning_ar.ToString().Length)
				{
					progress_information_ar.Items.Add(warning_ar.ToString());
				}
				else if(0 != filename_ar.ToString().Length )
				{
					progress_information_ar.Items.Add("Extracting        : " + util_ar.tounicode(filename_ar.ToString()));
				}
				else
				{
					progress_information_ar.Items.Add("Creating folder : " + util_ar.tounicode(folder_k.ToString()+"/"));
				}
			}
			
			folders_ar.Text = "Folders : " + Folders_ar;
			files_ar  .Text = "Files : " + Files_ar    ;
			
			if(0 != ret_ar && false == util_ar.cancel_arp)
			{
				goto again_amanda__;
			}
			
			ret_ar = util_ar.GetReturnValueFromList();
			
			if(0 == ret_ar)
			{
				my_error_ar.Text  = "Error: <none>";
			}
			else
			{
				util_ar.get_error_message(error_message_ar__);
				my_error_ar.Text  = "Error: " + util_ar.tounicode(error_message_ar__.ToString());
			}
			progress_information_ar.EndUpdate();
			
			util_ar.get_tar_format_arp(tar_format_arp);
			format_arp.Text = "tar format: " + tar_format_arp.ToString();
			
			Thread arp_thread = new Thread(new ThreadStart(this.close_form));
			arp_thread.Start();
			
		}
		void close_form()
		{
			Thread.Sleep(500);
			try
			{
				util_ar.copia_arp.timer1.Tick -= new System.EventHandler(util_ar.copia_arp.Timer1Tick);
				util_ar.copia_arp.Close();
				//util_ar.copia_arp.Dispose();
				util_ar.copia_arp = null ;
				//util_ar.copia_arp.Hide();
			}
			catch(Exception p_e)
			{
				util_ar.pedro_dprintf(0, "error de try " + p_e.Message);
			}			
		}
		void Tempo_extract_Tick(object sender, EventArgs e)
		{
			rspk_progress. Value = util_ar.Initial_Progress_z     ();
			aakp_progress_.Value = util_ar.GetExtrationProgress_ar();
			
			//If the selection of the threads to use for compression and decompression
			//is not 1 it will show with how many threads the multi-thread decoder
			//is using to decompress the file
			threads__z.Text = "Threads used in the decompression: " + util_ar.decompression_cores_used__z();
			
			if(0 == util_ar.IsListRunning())
			{
				tempo_extract_.Enabled = false;
				our_thread_extract();
			}
		}
		
		void Button6Click(object sender, EventArgs e)
		{
			util_ar.ExtractPause_ar();
		}
		
		void Button8Click(object sender, EventArgs e)
		{
			util_ar.ExtractResume_ar();
		}
		
		void Button7Click(object sender, EventArgs e)
		{
			tempo_ar.Enabled = false;
			tempo_extract_.Enabled = false;
			util_ar.ExtractCancel_ar();
			util_ar.cancel_arp = true;
			aakp_progress_.Value = 10000;
			button1.Text = "List";
			my_error_ar.Text  = "Error: <none?>";
		}
		
		void MainFormFormClosing(object sender, FormClosingEventArgs e)
		{
			util_ar.cancel_arp = true;
		}
		
		void Button9Click(object sender, EventArgs e)
		{
			ar_create_tar amanda = new ar_create_tar (false);
			amanda.Show();
		}
		
		void OptionsToolStripMenuItemClick(object sender, EventArgs e)
		{
			arp_opcoes amanda_ = new arp_opcoes();
			amanda_.ShowDialog();
		}
		
		void Memoria_zTick(object sender, EventArgs e)
		{
			util_ar.memory_usage__z(memory___z);
			memory_z.Text = "Memory used: " + memory___z.ToString();
		}
	}
}
//thanks for using our software...
