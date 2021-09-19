/*
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 31/01/2021
 * Hora: 15:41
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
	/// Description of arp_opcoes.
	/// </summary>
	public partial class arp_opcoes : Form
	{
		public arp_opcoes()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		StringBuilder pega_pass = new StringBuilder(300);
		void Arp_opcoesLoad(object sender, EventArgs e)
		{
			int cores_128_k__p;
			if(!util_ar.is_parolin_p)
			{
				
				label1.Visible = false;
				enc_method_arp.Visible = false;
				group_enc_p.Visible = false;
				
			}
			this.Icon = util_ar.pedro_get_icon();
			use_encryption_arp_.Checked = false;
			if(true == util_ar.use_encryption_arp)
			{
				
				use_encryption_arp_.Checked = true;
				
			}
						
			enc_method_arp.Items.Add("AES 256 CTR");
			enc_method_arp.Items.Add("MARS");
			enc_method_arp.Items.Add("RC4");
			enc_method_arp.Items.Add("RC6");
			enc_method_arp.Items.Add("SERPENT");
			enc_method_arp.Items.Add("TWOFISH");
			
			//If you want any other encryption method please drop me a line
			
			util_ar.get__settings_arp("encryption_arp", pega_pass, pega_pass.Capacity);
			the_pass.Text = pega_pass.ToString();
			
			if("" == pega_pass.ToString())
			{
				util_ar.save_settings_arp("encryption_arp", "AES 256 CTR");
				enc_method_arp.Text = "AES 256 CTR";
			}
			else
			{
				enc_method_arp.Text = pega_pass.ToString();
			}
			
			util_ar.get__settings_arp("the_password_arp", pega_pass, pega_pass.Capacity);
						                      
			the_pass.Text = util_ar.tounicode(pega_pass.ToString());
			
			uses_sftp_arp.Checked = false;
			
			if(util_ar.use_sftp_______arp)
			{
				
				uses_sftp_arp.Checked = true;
				
			}
			
			util_ar.get__settings_arp("arp_host", pega_pass, pega_pass.Capacity);
			arp_host.Text = pega_pass.ToString();
			util_ar.get__settings_arp("arp_user", pega_pass, pega_pass.Capacity);
			arp_user.Text  = pega_pass.ToString();
			util_ar.get__settings_arp("arp_pass", pega_pass, pega_pass.Capacity);
			arp_pass.Text = pega_pass.ToString();
			util_ar.get__settings_arp("remote_path_arp", pega_pass, pega_pass.Capacity);
			remote_path_arp.Text = pega_pass.ToString();
									
			threads_z.Items.Add("auto");//will be detected at runtime
			
			for(cores_128_k__p = 1; cores_128_k__p<= 128; cores_128_k__p++)
			{
				threads_z.Items.Add(cores_128_k__p.ToString());
			}
			
			util_ar.get__settings_arp("xz_threads", pega_pass, pega_pass.Capacity);
			
			if("" == pega_pass.ToString())
			{
				threads_z.Text = "1";
				util_ar.save_settings_arp("xz_threads", "1");// read ar_create_tar.cs or readme.txt in the initial directory for the updated list of supported multi-thread modes, they are augmenting every day (04/March/2021)
			}
			else
			{
				threads_z.Text = pega_pass.ToString();
			}
			
			z_encryption_method.Items.Add("Old Mode");//it will encrypt the data before the compression, resulting in files larger than the original, only available for compatibility with older versions of the DLL
			z_encryption_method.Items.Add("New Mode (Recommended)");//it will encrypt the files after the compression, this is the correct mode to do it, this is why it is the recommended mode, also it will encrypt not only the data but the names of the files inside the val or tar file
		
			util_ar.get__settings_arp("z_encryption_method", pega_pass, pega_pass.Capacity);
			
			if("" == pega_pass.ToString ())
			{
				z_encryption_method.Text = "New Mode (Recommended)";				
			}
			else
			{
				z_encryption_method.Text = pega_pass.ToString();
			}
			
			bytes_p.Text = util_ar.size_of_each_file_slice_p.ToString();
		}
		
		void Button1Click(object sender, EventArgs e)
		{
			Close();
		}
		
		void Use_encryption_arp_MouseUp(object sender, MouseEventArgs e)
		{
			if(true == use_encryption_arp_.Checked)
			{
				util_ar.use_encryption_arp = true;
			}
			else
			{
				util_ar.use_encryption_arp = false;
			}
		}
		
		void Button2Click(object sender, EventArgs e)
		{
			string password_i;
			
			password_i = the_pass.Text.Trim();
			
			password_i = util_ar.toutf8(password_i);
									
			util_ar.save_settings_arp("the_password_arp", password_i);
			util_ar.save_settings_arp("encryption_arp"  , enc_method_arp.Text);
		}
		
		void Uses_sftp_arpMouseUp(object sender, MouseEventArgs e)
		{
			util_ar.use_sftp_______arp = true;
			if(false == uses_sftp_arp.Checked)
			{
				
				util_ar.use_sftp_______arp = false;
				
			}
		}
		
		void Sftp_saveClick(object sender, EventArgs e)
		{
			util_ar.save_settings_arp("arp_host", arp_host.Text.              Trim());
			util_ar.save_settings_arp("arp_user", arp_user.Text.              Trim());
			util_ar.save_settings_arp("arp_pass", arp_pass.Text.              Trim());
			util_ar.save_settings_arp("remote_path_arp", remote_path_arp.Text.Trim());
		}
		
		void Button3Click(object sender, EventArgs e)
		{
			;//util_ar.save_settings_arp("iso_mode_arp", iso_arp_mode.Text);
		}
		
		void Button4Click(object sender, EventArgs e)
		{
			util_ar.save_settings_arp("xz_threads", threads_z.Text);
		}
		
		void Button5Click(object sender, EventArgs e)
		{
			util_ar.save_settings_arp("z_encryption_method", z_encryption_method.Text/*perfect...*/);
		}
		
		void Button6Click(object sender, EventArgs e)
		{
			if(1 == util_ar.set_temp_folder_z(util_ar.toutf8(temp_z.Text)))
			{
				
				MessageBox.Show("Path passed is not valid as a temp folder");
				temp_z.Text = "";
			
			}
		}
		
		void Byte_slice_pClick(object sender, EventArgs e)
		{
			try
			{
				util_ar.size_of_each_file_slice_p = long.Parse(bytes_p.Text);
			}
			catch
			{
				bytes_p.Text = "0";
			}
		}
	}
}
