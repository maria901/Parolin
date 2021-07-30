/*
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 03/02/2021
 * Hora: 21:27
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;

namespace tar_sample_ar
{
	/// <summary>
	/// Description of arp_send_sftp.
	/// </summary>
	public partial class arp_send_sftp : Form
	{
		public arp_send_sftp(string filename_arp_)
		{
			filename_arp = filename_arp_;
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		StringBuilder pega_pass = new StringBuilder(1024);
		internal  string filename_arp;
		protected string arp_host;
		protected string arp_user;
		protected string arp_pass;
		protected string remote__path_arp;
		int ret_arp_;
		void Arp_send_sftpLoad(object sender, EventArgs e)
		{
			this.Icon = util_ar.pedro_get_icon();
			juliete_progress.SetProgressColor = System.Drawing.Color.Green;
			
			util_ar.get__settings_arp("arp_host", pega_pass, pega_pass.Capacity);
			
			arp_host = pega_pass.ToString();
			host_arp.Text = "Host   : " + arp_host;
			
			util_ar.get__settings_arp("arp_user", pega_pass, pega_pass.Capacity);
			arp_user = pega_pass.ToString();
			user_arp.Text = "User   : " + arp_user;
			
			util_ar.get__settings_arp("arp_pass", pega_pass, pega_pass.Capacity);
			arp_pass = pega_pass.ToString();
			
			util_ar.get__settings_arp("remote_path_arp", pega_pass, pega_pass.Capacity);
			remote__path_arp = pega_pass.ToString();
			
			remote_path.Text = "Remote Path: " /* for your pleasure */+ remote__path_arp;
			
			file_arp.Text = "Local File: " + filename_arp;
			
			ret_arp_ = util_ar.pass_sftp_data_z
				(
					remote__path_arp,
					arp_user,
					arp_pass,
					arp_host,
					filename_arp
				);
			
			if(0 == ret_arp_)
			{
				
				arp_timer.Enabled = true;
				
			}
			else
			{
				status_arp.Text = "Status: Initial Error " + ret_arp_.ToString();
			}
		}
		
		void Arp_timerTick(object sender, EventArgs e)
		{
			ret_arp_ = util_ar.is_sftp_running_z();
			juliete_progress.Value = util_ar.progress_sftp();
			
			util_ar.get_remote_directory_z(pega_pass);
			
			//the remote working directory being used, returned by pwd command
			arp_pwd.Text = "pwd: " + pega_pass.ToString();
						
			util_ar.get_key_fingerprint_z(pega_pass);
			
			//the key fingerprint
			key_i.Text = "key: " + pega_pass.ToString();
			
			if(0 == ret_arp_)
			{
				juliete_progress.Value = 10000;
				arp_timer.Enabled = false;
				
				ret_arp_ = util_ar.get_sftp_return_value_z();
				
				
				//status_arp.Text = "Status: Error " + ret_arp_.ToString();
				
				switch(ret_arp_)
				{
					case 0:
						status_arp.Text = "Status: <no error>";
						break;
					case 1:
					case 2:
						status_arp.Text = "Status: Unexpected error";
						break;
					case 6:
						status_arp.Text = "Status: Connection error";
						break;
					case 7:
						status_arp.Text = "Status: SFTP init error";
						break;
					case 8:
						status_arp.Text = "Status: Invalid remote path";
						break;
					case 9:
						status_arp.Text = "Status: Cannot open local file to read";
						break;
					case 27:
						status_arp.Text = "Status: User cancel";
						break;
					default:
						status_arp.Text = "Status: Unknown error";
						break;
				}
				
			}
		}
		
		void Button2Click(object sender, EventArgs e)
		{
			util_ar.pause_sftp();
		}
		
		void Button3Click(object sender, EventArgs e)
		{
			util_ar.resume_sftp();
		}
		
		void Button1Click(object sender, EventArgs e)
		{
			util_ar.cancel_sftp();
		}
	}
}
