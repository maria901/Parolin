/*
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 03/02/2021
 * Hora: 21:27
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace tar_sample_ar
{
	partial class arp_send_sftp
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.juliete_progress = new AmandarRicardo_Koci_Progress.progressbar();
			this.status_arp = new System.Windows.Forms.Label();
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.button3 = new System.Windows.Forms.Button();
			this.host_arp = new System.Windows.Forms.Label();
			this.user_arp = new System.Windows.Forms.Label();
			this.remote_path = new System.Windows.Forms.Label();
			this.file_arp = new System.Windows.Forms.Label();
			this.arp_timer = new System.Windows.Forms.Timer(this.components);
			this.arp_pwd = new System.Windows.Forms.Label();
			this.key_i = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// juliete_progress
			// 
			this.juliete_progress.Location = new System.Drawing.Point(15, 261);
			this.juliete_progress.Maximum = 10000;
			this.juliete_progress.Name = "juliete_progress";
			this.juliete_progress.Size = new System.Drawing.Size(612, 22);
			this.juliete_progress.TabIndex = 0;
			this.juliete_progress.Value = 0;
			// 
			// status_arp
			// 
			this.status_arp.Location = new System.Drawing.Point(13, 289);
			this.status_arp.Name = "status_arp";
			this.status_arp.Size = new System.Drawing.Size(613, 20);
			this.status_arp.TabIndex = 1;
			this.status_arp.Text = "Status: Sending...";
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(529, 221);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(97, 29);
			this.button1.TabIndex = 2;
			this.button1.Text = "Cancel";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(323, 221);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(97, 29);
			this.button2.TabIndex = 3;
			this.button2.Text = "Pause";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// button3
			// 
			this.button3.Location = new System.Drawing.Point(426, 221);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(97, 29);
			this.button3.TabIndex = 4;
			this.button3.Text = "Resume";
			this.button3.UseVisualStyleBackColor = true;
			this.button3.Click += new System.EventHandler(this.Button3Click);
			// 
			// host_arp
			// 
			this.host_arp.Location = new System.Drawing.Point(19, 22);
			this.host_arp.Name = "host_arp";
			this.host_arp.Size = new System.Drawing.Size(486, 14);
			this.host_arp.TabIndex = 5;
			this.host_arp.Text = "label1";
			// 
			// user_arp
			// 
			this.user_arp.Location = new System.Drawing.Point(19, 36);
			this.user_arp.Name = "user_arp";
			this.user_arp.Size = new System.Drawing.Size(401, 14);
			this.user_arp.TabIndex = 6;
			this.user_arp.Text = "label2";
			// 
			// remote_path
			// 
			this.remote_path.Location = new System.Drawing.Point(19, 50);
			this.remote_path.Name = "remote_path";
			this.remote_path.Size = new System.Drawing.Size(420, 14);
			this.remote_path.TabIndex = 7;
			this.remote_path.Text = "label3";
			// 
			// file_arp
			// 
			this.file_arp.Location = new System.Drawing.Point(19, 71);
			this.file_arp.Name = "file_arp";
			this.file_arp.Size = new System.Drawing.Size(607, 45);
			this.file_arp.TabIndex = 8;
			this.file_arp.Text = "File:";
			// 
			// arp_timer
			// 
			this.arp_timer.Interval = 50;
			this.arp_timer.Tick += new System.EventHandler(this.Arp_timerTick);
			// 
			// arp_pwd
			// 
			this.arp_pwd.Location = new System.Drawing.Point(20, 116);
			this.arp_pwd.Name = "arp_pwd";
			this.arp_pwd.Size = new System.Drawing.Size(607, 28);
			this.arp_pwd.TabIndex = 9;
			this.arp_pwd.Text = "pwd: ";
			// 
			// key_i
			// 
			this.key_i.Location = new System.Drawing.Point(19, 144);
			this.key_i.Name = "key_i";
			this.key_i.Size = new System.Drawing.Size(607, 28);
			this.key_i.TabIndex = 10;
			this.key_i.Text = "key: ";
			// 
			// arp_send_sftp
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(644, 314);
			this.Controls.Add(this.key_i);
			this.Controls.Add(this.arp_pwd);
			this.Controls.Add(this.file_arp);
			this.Controls.Add(this.remote_path);
			this.Controls.Add(this.user_arp);
			this.Controls.Add(this.host_arp);
			this.Controls.Add(this.button3);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.status_arp);
			this.Controls.Add(this.juliete_progress);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MaximizeBox = false;
			this.Name = "arp_send_sftp";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Sending to SFTP Server";
			this.Load += new System.EventHandler(this.Arp_send_sftpLoad);
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.Label key_i;
		private System.Windows.Forms.Label arp_pwd;
		private System.Windows.Forms.Timer arp_timer;
		private System.Windows.Forms.Label file_arp;
		private System.Windows.Forms.Label remote_path;
		private System.Windows.Forms.Label user_arp;
		private System.Windows.Forms.Label host_arp;
		private System.Windows.Forms.Button button3;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Label status_arp;
		private AmandarRicardo_Koci_Progress.progressbar juliete_progress;
	}
}
