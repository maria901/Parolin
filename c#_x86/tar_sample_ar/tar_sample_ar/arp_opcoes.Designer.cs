/*
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 31/01/2021
 * Hora: 15:41
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace tar_sample_ar
{
	partial class arp_opcoes
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
			this.groupBox1 = new System.Windows.Forms.GroupBox();
			this.enc_method_arp = new System.Windows.Forms.ComboBox();
			this.button2 = new System.Windows.Forms.Button();
			this.the_pass = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.use_encryption_arp_ = new System.Windows.Forms.CheckBox();
			this.label2 = new System.Windows.Forms.Label();
			this.button1 = new System.Windows.Forms.Button();
			this.groupBox2 = new System.Windows.Forms.GroupBox();
			this.remote_path_arp = new System.Windows.Forms.TextBox();
			this.label6 = new System.Windows.Forms.Label();
			this.sftp_save = new System.Windows.Forms.Button();
			this.arp_pass = new System.Windows.Forms.TextBox();
			this.label4 = new System.Windows.Forms.Label();
			this.arp_host = new System.Windows.Forms.TextBox();
			this.label3 = new System.Windows.Forms.Label();
			this.arp_user = new System.Windows.Forms.TextBox();
			this.uses_sftp_arp = new System.Windows.Forms.CheckBox();
			this.label5 = new System.Windows.Forms.Label();
			this.groupBox4 = new System.Windows.Forms.GroupBox();
			this.threads_z = new System.Windows.Forms.ComboBox();
			this.button4 = new System.Windows.Forms.Button();
			this.group_enc_p = new System.Windows.Forms.GroupBox();
			this.z_encryption_method = new System.Windows.Forms.ComboBox();
			this.button5 = new System.Windows.Forms.Button();
			this.groupBox6 = new System.Windows.Forms.GroupBox();
			this.temp_z = new System.Windows.Forms.ComboBox();
			this.button6 = new System.Windows.Forms.Button();
			this.groupBox7 = new System.Windows.Forms.GroupBox();
			this.label9 = new System.Windows.Forms.Label();
			this.label8 = new System.Windows.Forms.Label();
			this.bytes_p = new System.Windows.Forms.TextBox();
			this.byte_slice_p = new System.Windows.Forms.Button();
			this.groupBox1.SuspendLayout();
			this.groupBox2.SuspendLayout();
			this.groupBox4.SuspendLayout();
			this.group_enc_p.SuspendLayout();
			this.groupBox6.SuspendLayout();
			this.groupBox7.SuspendLayout();
			this.SuspendLayout();
			// 
			// groupBox1
			// 
			this.groupBox1.Controls.Add(this.enc_method_arp);
			this.groupBox1.Controls.Add(this.button2);
			this.groupBox1.Controls.Add(this.the_pass);
			this.groupBox1.Controls.Add(this.label1);
			this.groupBox1.Controls.Add(this.use_encryption_arp_);
			this.groupBox1.Controls.Add(this.label2);
			this.groupBox1.Location = new System.Drawing.Point(27, 23);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new System.Drawing.Size(349, 118);
			this.groupBox1.TabIndex = 0;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Security";
			// 
			// enc_method_arp
			// 
			this.enc_method_arp.FormattingEnabled = true;
			this.enc_method_arp.Location = new System.Drawing.Point(130, 88);
			this.enc_method_arp.Name = "enc_method_arp";
			this.enc_method_arp.Size = new System.Drawing.Size(134, 21);
			this.enc_method_arp.TabIndex = 5;
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(274, 58);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(62, 20);
			this.button2.TabIndex = 4;
			this.button2.Text = "Apply";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// the_pass
			// 
			this.the_pass.Location = new System.Drawing.Point(10, 58);
			this.the_pass.Name = "the_pass";
			this.the_pass.Size = new System.Drawing.Size(254, 20);
			this.the_pass.TabIndex = 2;
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(6, 91);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(297, 16);
			this.label1.TabIndex = 1;
			this.label1.Text = "The encryption method is AES 256 CTR";
			// 
			// use_encryption_arp_
			// 
			this.use_encryption_arp_.Location = new System.Drawing.Point(11, 19);
			this.use_encryption_arp_.Name = "use_encryption_arp_";
			this.use_encryption_arp_.Size = new System.Drawing.Size(293, 23);
			this.use_encryption_arp_.TabIndex = 0;
			this.use_encryption_arp_.Text = "Encrypt files";
			this.use_encryption_arp_.UseVisualStyleBackColor = true;
			this.use_encryption_arp_.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Use_encryption_arp_MouseUp);
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(8, 41);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(297, 16);
			this.label2.TabIndex = 3;
			this.label2.Text = "Password";
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(696, 549);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(76, 24);
			this.button1.TabIndex = 5;
			this.button1.Text = "Exit";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// groupBox2
			// 
			this.groupBox2.Controls.Add(this.remote_path_arp);
			this.groupBox2.Controls.Add(this.label6);
			this.groupBox2.Controls.Add(this.sftp_save);
			this.groupBox2.Controls.Add(this.arp_pass);
			this.groupBox2.Controls.Add(this.label4);
			this.groupBox2.Controls.Add(this.arp_host);
			this.groupBox2.Controls.Add(this.label3);
			this.groupBox2.Controls.Add(this.arp_user);
			this.groupBox2.Controls.Add(this.uses_sftp_arp);
			this.groupBox2.Controls.Add(this.label5);
			this.groupBox2.Location = new System.Drawing.Point(399, 23);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new System.Drawing.Size(373, 237);
			this.groupBox2.TabIndex = 5;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "SFTP Support";
			// 
			// remote_path_arp
			// 
			this.remote_path_arp.Location = new System.Drawing.Point(15, 196);
			this.remote_path_arp.Name = "remote_path_arp";
			this.remote_path_arp.Size = new System.Drawing.Size(254, 20);
			this.remote_path_arp.TabIndex = 11;
			// 
			// label6
			// 
			this.label6.Location = new System.Drawing.Point(13, 179);
			this.label6.Name = "label6";
			this.label6.Size = new System.Drawing.Size(297, 16);
			this.label6.TabIndex = 12;
			this.label6.Text = "Remote Path";
			// 
			// sftp_save
			// 
			this.sftp_save.Location = new System.Drawing.Point(286, 196);
			this.sftp_save.Name = "sftp_save";
			this.sftp_save.Size = new System.Drawing.Size(62, 20);
			this.sftp_save.TabIndex = 10;
			this.sftp_save.Text = "Apply";
			this.sftp_save.UseVisualStyleBackColor = true;
			this.sftp_save.Click += new System.EventHandler(this.Sftp_saveClick);
			// 
			// arp_pass
			// 
			this.arp_pass.Location = new System.Drawing.Point(14, 155);
			this.arp_pass.Name = "arp_pass";
			this.arp_pass.Size = new System.Drawing.Size(254, 20);
			this.arp_pass.TabIndex = 8;
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(12, 138);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(297, 16);
			this.label4.TabIndex = 9;
			this.label4.Text = "Password";
			// 
			// arp_host
			// 
			this.arp_host.Location = new System.Drawing.Point(14, 79);
			this.arp_host.Name = "arp_host";
			this.arp_host.Size = new System.Drawing.Size(254, 20);
			this.arp_host.TabIndex = 5;
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(12, 62);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(297, 16);
			this.label3.TabIndex = 6;
			this.label3.Text = "Host";
			// 
			// arp_user
			// 
			this.arp_user.Location = new System.Drawing.Point(14, 115);
			this.arp_user.Name = "arp_user";
			this.arp_user.Size = new System.Drawing.Size(254, 20);
			this.arp_user.TabIndex = 2;
			// 
			// uses_sftp_arp
			// 
			this.uses_sftp_arp.Location = new System.Drawing.Point(15, 19);
			this.uses_sftp_arp.Name = "uses_sftp_arp";
			this.uses_sftp_arp.Size = new System.Drawing.Size(293, 23);
			this.uses_sftp_arp.TabIndex = 0;
			this.uses_sftp_arp.Text = "Send to SFTP server";
			this.uses_sftp_arp.UseVisualStyleBackColor = true;
			this.uses_sftp_arp.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Uses_sftp_arpMouseUp);
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(12, 98);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(297, 16);
			this.label5.TabIndex = 3;
			this.label5.Text = "User";
			// 
			// groupBox4
			// 
			this.groupBox4.Controls.Add(this.threads_z);
			this.groupBox4.Controls.Add(this.button4);
			this.groupBox4.Location = new System.Drawing.Point(27, 161);
			this.groupBox4.Name = "groupBox4";
			this.groupBox4.Size = new System.Drawing.Size(349, 105);
			this.groupBox4.TabIndex = 14;
			this.groupBox4.TabStop = false;
			this.groupBox4.Text = "Thread number for compressors with multi-thread support";
			// 
			// threads_z
			// 
			this.threads_z.FormattingEnabled = true;
			this.threads_z.Location = new System.Drawing.Point(20, 30);
			this.threads_z.Name = "threads_z";
			this.threads_z.Size = new System.Drawing.Size(154, 21);
			this.threads_z.TabIndex = 11;
			// 
			// button4
			// 
			this.button4.Location = new System.Drawing.Point(259, 57);
			this.button4.Name = "button4";
			this.button4.Size = new System.Drawing.Size(62, 20);
			this.button4.TabIndex = 10;
			this.button4.Text = "Apply";
			this.button4.UseVisualStyleBackColor = true;
			this.button4.Click += new System.EventHandler(this.Button4Click);
			// 
			// group_enc_p
			// 
			this.group_enc_p.Controls.Add(this.z_encryption_method);
			this.group_enc_p.Controls.Add(this.button5);
			this.group_enc_p.Location = new System.Drawing.Point(398, 298);
			this.group_enc_p.Name = "group_enc_p";
			this.group_enc_p.Size = new System.Drawing.Size(374, 105);
			this.group_enc_p.TabIndex = 15;
			this.group_enc_p.TabStop = false;
			this.group_enc_p.Text = "Encryption Mode";
			// 
			// z_encryption_method
			// 
			this.z_encryption_method.FormattingEnabled = true;
			this.z_encryption_method.Location = new System.Drawing.Point(20, 30);
			this.z_encryption_method.Name = "z_encryption_method";
			this.z_encryption_method.Size = new System.Drawing.Size(197, 21);
			this.z_encryption_method.TabIndex = 11;
			// 
			// button5
			// 
			this.button5.Location = new System.Drawing.Point(287, 61);
			this.button5.Name = "button5";
			this.button5.Size = new System.Drawing.Size(62, 20);
			this.button5.TabIndex = 10;
			this.button5.Text = "Apply";
			this.button5.UseVisualStyleBackColor = true;
			this.button5.Click += new System.EventHandler(this.Button5Click);
			// 
			// groupBox6
			// 
			this.groupBox6.Controls.Add(this.temp_z);
			this.groupBox6.Controls.Add(this.button6);
			this.groupBox6.Location = new System.Drawing.Point(27, 291);
			this.groupBox6.Name = "groupBox6";
			this.groupBox6.Size = new System.Drawing.Size(349, 105);
			this.groupBox6.TabIndex = 15;
			this.groupBox6.TabStop = false;
			this.groupBox6.Text = "Temp Folder";
			// 
			// temp_z
			// 
			this.temp_z.FormattingEnabled = true;
			this.temp_z.Location = new System.Drawing.Point(20, 30);
			this.temp_z.Name = "temp_z";
			this.temp_z.Size = new System.Drawing.Size(301, 21);
			this.temp_z.TabIndex = 11;
			// 
			// button6
			// 
			this.button6.Location = new System.Drawing.Point(259, 57);
			this.button6.Name = "button6";
			this.button6.Size = new System.Drawing.Size(62, 20);
			this.button6.TabIndex = 10;
			this.button6.Text = "Apply";
			this.button6.UseVisualStyleBackColor = true;
			this.button6.Click += new System.EventHandler(this.Button6Click);
			// 
			// groupBox7
			// 
			this.groupBox7.Controls.Add(this.label9);
			this.groupBox7.Controls.Add(this.label8);
			this.groupBox7.Controls.Add(this.bytes_p);
			this.groupBox7.Controls.Add(this.byte_slice_p);
			this.groupBox7.Location = new System.Drawing.Point(399, 415);
			this.groupBox7.Name = "groupBox7";
			this.groupBox7.Size = new System.Drawing.Size(374, 118);
			this.groupBox7.TabIndex = 16;
			this.groupBox7.TabStop = false;
			this.groupBox7.Text = "Multi-volume";
			// 
			// label9
			// 
			this.label9.Location = new System.Drawing.Point(168, 72);
			this.label9.Name = "label9";
			this.label9.Size = new System.Drawing.Size(48, 17);
			this.label9.TabIndex = 13;
			this.label9.Text = "Bytes";
			// 
			// label8
			// 
			this.label8.Location = new System.Drawing.Point(10, 21);
			this.label8.Name = "label8";
			this.label8.Size = new System.Drawing.Size(333, 46);
			this.label8.TabIndex = 12;
			this.label8.Text = "Split the destination file in multiple volumes each with the size as defined belo" +
			"w in bytes, 0 to don´t split, first file will be <file>.001 and so on";
			// 
			// bytes_p
			// 
			this.bytes_p.Location = new System.Drawing.Point(13, 70);
			this.bytes_p.Name = "bytes_p";
			this.bytes_p.Size = new System.Drawing.Size(152, 20);
			this.bytes_p.TabIndex = 11;
			this.bytes_p.Text = "0";
			// 
			// byte_slice_p
			// 
			this.byte_slice_p.Location = new System.Drawing.Point(286, 74);
			this.byte_slice_p.Name = "byte_slice_p";
			this.byte_slice_p.Size = new System.Drawing.Size(62, 20);
			this.byte_slice_p.TabIndex = 10;
			this.byte_slice_p.Text = "Apply";
			this.byte_slice_p.UseVisualStyleBackColor = true;
			this.byte_slice_p.Click += new System.EventHandler(this.Byte_slice_pClick);
			// 
			// arp_opcoes
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(784, 585);
			this.Controls.Add(this.groupBox7);
			this.Controls.Add(this.groupBox6);
			this.Controls.Add(this.group_enc_p);
			this.Controls.Add(this.groupBox4);
			this.Controls.Add(this.groupBox2);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.groupBox1);
			this.Name = "arp_opcoes";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Tar Options";
			this.Load += new System.EventHandler(this.Arp_opcoesLoad);
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			this.groupBox4.ResumeLayout(false);
			this.group_enc_p.ResumeLayout(false);
			this.groupBox6.ResumeLayout(false);
			this.groupBox7.ResumeLayout(false);
			this.groupBox7.PerformLayout();
			this.ResumeLayout(false);
		}
		private System.Windows.Forms.GroupBox group_enc_p;
		private System.Windows.Forms.Button byte_slice_p;
		private System.Windows.Forms.Label label9;
		private System.Windows.Forms.TextBox bytes_p;
		private System.Windows.Forms.Label label8;
		private System.Windows.Forms.GroupBox groupBox7;
		private System.Windows.Forms.Button button6;
		private System.Windows.Forms.ComboBox temp_z;
		private System.Windows.Forms.GroupBox groupBox6;
		private System.Windows.Forms.Button button5;
		private System.Windows.Forms.ComboBox z_encryption_method;
		private System.Windows.Forms.Button button4;
		private System.Windows.Forms.ComboBox threads_z;
		private System.Windows.Forms.GroupBox groupBox4;
		private System.Windows.Forms.ComboBox enc_method_arp;
		private System.Windows.Forms.Label label6;
		private System.Windows.Forms.TextBox remote_path_arp;
		private System.Windows.Forms.CheckBox uses_sftp_arp;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.TextBox arp_user;
		private System.Windows.Forms.TextBox arp_host;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.TextBox arp_pass;
		private System.Windows.Forms.Button sftp_save;
		private System.Windows.Forms.GroupBox groupBox2;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.CheckBox use_encryption_arp_;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox the_pass;
		private System.Windows.Forms.GroupBox groupBox1;
	}
}
