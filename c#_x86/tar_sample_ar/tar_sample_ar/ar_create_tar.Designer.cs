/*
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 23/12/2020
 * Hora: 0:22
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace tar_sample_ar
{
	partial class ar_create_tar
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
			this.button1 = new System.Windows.Forms.Button();
			this.mislaine_lv_ = new System.Windows.Forms.ListView();
			this.ar_ch2 = new System.Windows.Forms.ColumnHeader();
			this.my_error_ar = new System.Windows.Forms.Label();
			this.tempo_ar = new System.Windows.Forms.Timer(this.components);
			this.label1 = new System.Windows.Forms.Label();
			this.ar_tar_file_ = new System.Windows.Forms.TextBox();
			this.button4 = new System.Windows.Forms.Button();
			this.label2 = new System.Windows.Forms.Label();
			this.path_to_add_ar = new System.Windows.Forms.TextBox();
			this.button3 = new System.Windows.Forms.Button();
			this.include_ar = new System.Windows.Forms.TextBox();
			this.sf_ar_ = new System.Windows.Forms.SaveFileDialog();
			this.fb_ar = new System.Windows.Forms.FolderBrowserDialog();
			this.maria_progress = new AmandarRicardo_Koci_Progress.progressbar();
			this.button2 = new System.Windows.Forms.Button();
			this.button5 = new System.Windows.Forms.Button();
			this.button6 = new System.Windows.Forms.Button();
			this.compression_mode_ar_ = new System.Windows.Forms.ComboBox();
			this.label4 = new System.Windows.Forms.Label();
			this.button7 = new System.Windows.Forms.Button();
			this.include_arp = new System.Windows.Forms.CheckBox();
			this.exclude_arp = new System.Windows.Forms.CheckBox();
			this.recurse_arp = new System.Windows.Forms.CheckBox();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.opçõesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.label3 = new System.Windows.Forms.Label();
			this.cannot_read_arp = new System.Windows.Forms.Label();
			this.invalid_paths_arp = new System.Windows.Forms.Label();
			this.show_message_z = new System.Windows.Forms.CheckBox();
			this.memory_z = new System.Windows.Forms.Timer(this.components);
			this.memory__label_z = new System.Windows.Forms.Label();
			this.level_p = new System.Windows.Forms.ComboBox();
			this.label5 = new System.Windows.Forms.Label();
			this.level_new_ava = new System.Windows.Forms.ComboBox();
			this.level_label = new System.Windows.Forms.Label();
			this.menuStrip1.SuspendLayout();
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(208, 21);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(175, 29);
			this.button1.TabIndex = 0;
			this.button1.Text = "Create Tar file";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// mislaine_lv_
			// 
			this.mislaine_lv_.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
									this.ar_ch2});
			this.mislaine_lv_.FullRowSelect = true;
			this.mislaine_lv_.GridLines = true;
			this.mislaine_lv_.Location = new System.Drawing.Point(12, 173);
			this.mislaine_lv_.Name = "mislaine_lv_";
			this.mislaine_lv_.Size = new System.Drawing.Size(763, 133);
			this.mislaine_lv_.TabIndex = 3;
			this.mislaine_lv_.UseCompatibleStateImageBehavior = false;
			this.mislaine_lv_.View = System.Windows.Forms.View.Details;
			// 
			// ar_ch2
			// 
			this.ar_ch2.Text = " ";
			this.ar_ch2.Width = 18;
			// 
			// my_error_ar
			// 
			this.my_error_ar.Location = new System.Drawing.Point(8, 406);
			this.my_error_ar.Name = "my_error_ar";
			this.my_error_ar.Size = new System.Drawing.Size(765, 20);
			this.my_error_ar.TabIndex = 6;
			this.my_error_ar.Text = "Error: <none>";
			// 
			// tempo_ar
			// 
			this.tempo_ar.Interval = 50;
			this.tempo_ar.Tick += new System.EventHandler(this.Tempo_arTick);
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 49);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(205, 17);
			this.label1.TabIndex = 12;
			this.label1.Text = "Tar file";
			// 
			// ar_tar_file_
			// 
			this.ar_tar_file_.Location = new System.Drawing.Point(12, 69);
			this.ar_tar_file_.Name = "ar_tar_file_";
			this.ar_tar_file_.Size = new System.Drawing.Size(682, 20);
			this.ar_tar_file_.TabIndex = 11;
			this.ar_tar_file_.Text = "C:\\Users\\AAKP\\Downloads\\my_tar_file.tar";
			// 
			// button4
			// 
			this.button4.Location = new System.Drawing.Point(700, 68);
			this.button4.Name = "button4";
			this.button4.Size = new System.Drawing.Size(75, 21);
			this.button4.TabIndex = 13;
			this.button4.Text = "select";
			this.button4.UseVisualStyleBackColor = true;
			this.button4.Click += new System.EventHandler(this.Button4Click);
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(10, 96);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(205, 17);
			this.label2.TabIndex = 15;
			this.label2.Text = "Path with the files to add to Tar file";
			// 
			// path_to_add_ar
			// 
			this.path_to_add_ar.Location = new System.Drawing.Point(12, 112);
			this.path_to_add_ar.Name = "path_to_add_ar";
			this.path_to_add_ar.Size = new System.Drawing.Size(582, 20);
			this.path_to_add_ar.TabIndex = 14;
			this.path_to_add_ar.Text = "C:\\Ava\\back\\extract_k";
			// 
			// button3
			// 
			this.button3.Location = new System.Drawing.Point(600, 110);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(75, 21);
			this.button3.TabIndex = 16;
			this.button3.Text = "select";
			this.button3.UseVisualStyleBackColor = true;
			this.button3.Click += new System.EventHandler(this.Button3Click);
			// 
			// include_ar
			// 
			this.include_ar.Location = new System.Drawing.Point(682, 141);
			this.include_ar.Name = "include_ar";
			this.include_ar.Size = new System.Drawing.Size(92, 20);
			this.include_ar.TabIndex = 17;
			this.include_ar.Text = "* *.txt *.ini";
			// 
			// maria_progress
			// 
			this.maria_progress.Location = new System.Drawing.Point(12, 335);
			this.maria_progress.Maximum = 10000;
			this.maria_progress.Name = "maria_progress";
			this.maria_progress.Size = new System.Drawing.Size(763, 22);
			this.maria_progress.TabIndex = 19;
			this.maria_progress.Value = 0;
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(592, 310);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(57, 22);
			this.button2.TabIndex = 20;
			this.button2.Text = "Pause";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// button5
			// 
			this.button5.Location = new System.Drawing.Point(655, 310);
			this.button5.Name = "button5";
			this.button5.Size = new System.Drawing.Size(57, 22);
			this.button5.TabIndex = 21;
			this.button5.Text = "Resume";
			this.button5.UseVisualStyleBackColor = true;
			this.button5.Click += new System.EventHandler(this.Button5Click);
			// 
			// button6
			// 
			this.button6.Location = new System.Drawing.Point(718, 310);
			this.button6.Name = "button6";
			this.button6.Size = new System.Drawing.Size(57, 22);
			this.button6.TabIndex = 22;
			this.button6.Text = "Cancel";
			this.button6.UseVisualStyleBackColor = true;
			this.button6.Click += new System.EventHandler(this.Button6Click);
			// 
			// compression_mode_ar_
			// 
			this.compression_mode_ar_.FormattingEnabled = true;
			this.compression_mode_ar_.Location = new System.Drawing.Point(647, 37);
			this.compression_mode_ar_.Name = "compression_mode_ar_";
			this.compression_mode_ar_.Size = new System.Drawing.Size(126, 21);
			this.compression_mode_ar_.TabIndex = 23;
			this.compression_mode_ar_.SelectedIndexChanged += new System.EventHandler(this.Compression_mode_ar_SelectedIndexChanged);
			// 
			// label4
			// 
			this.label4.Location = new System.Drawing.Point(647, 17);
			this.label4.Name = "label4";
			this.label4.Size = new System.Drawing.Size(205, 17);
			this.label4.TabIndex = 24;
			this.label4.Text = "Compression mode";
			// 
			// button7
			// 
			this.button7.Location = new System.Drawing.Point(79, 23);
			this.button7.Name = "button7";
			this.button7.Size = new System.Drawing.Size(106, 25);
			this.button7.TabIndex = 25;
			this.button7.Text = "Backup";
			this.button7.UseVisualStyleBackColor = true;
			this.button7.Visible = false;
			this.button7.Click += new System.EventHandler(this.Button7Click);
			// 
			// include_arp
			// 
			this.include_arp.Checked = true;
			this.include_arp.CheckState = System.Windows.Forms.CheckState.Checked;
			this.include_arp.Location = new System.Drawing.Point(562, 137);
			this.include_arp.Name = "include_arp";
			this.include_arp.Size = new System.Drawing.Size(114, 18);
			this.include_arp.TabIndex = 26;
			this.include_arp.Text = "Include the files";
			this.include_arp.UseVisualStyleBackColor = true;
			this.include_arp.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Include_arpMouseUp);
			// 
			// exclude_arp
			// 
			this.exclude_arp.Location = new System.Drawing.Point(562, 152);
			this.exclude_arp.Name = "exclude_arp";
			this.exclude_arp.Size = new System.Drawing.Size(114, 18);
			this.exclude_arp.TabIndex = 27;
			this.exclude_arp.Text = "Exclude the files";
			this.exclude_arp.UseVisualStyleBackColor = true;
			this.exclude_arp.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Exclude_arpMouseUp);
			// 
			// recurse_arp
			// 
			this.recurse_arp.Checked = true;
			this.recurse_arp.CheckState = System.Windows.Forms.CheckState.Checked;
			this.recurse_arp.Location = new System.Drawing.Point(12, 152);
			this.recurse_arp.Name = "recurse_arp";
			this.recurse_arp.Size = new System.Drawing.Size(149, 18);
			this.recurse_arp.TabIndex = 28;
			this.recurse_arp.Text = "Recurse on subfolders";
			this.recurse_arp.UseVisualStyleBackColor = true;
			// 
			// menuStrip1
			// 
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
									this.opçõesToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(787, 24);
			this.menuStrip1.TabIndex = 29;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// opçõesToolStripMenuItem
			// 
			this.opçõesToolStripMenuItem.Name = "opçõesToolStripMenuItem";
			this.opçõesToolStripMenuItem.Size = new System.Drawing.Size(59, 20);
			this.opçõesToolStripMenuItem.Text = "Opções";
			this.opçõesToolStripMenuItem.Click += new System.EventHandler(this.OpçõesToolStripMenuItemClick);
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(289, 156);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(194, 16);
			this.label3.TabIndex = 30;
			this.label3.Text = "Using Encryption: no";
			// 
			// cannot_read_arp
			// 
			this.cannot_read_arp.Location = new System.Drawing.Point(8, 386);
			this.cannot_read_arp.Name = "cannot_read_arp";
			this.cannot_read_arp.Size = new System.Drawing.Size(765, 20);
			this.cannot_read_arp.TabIndex = 31;
			this.cannot_read_arp.Text = "Files that cannot be read: 0";
			// 
			// invalid_paths_arp
			// 
			this.invalid_paths_arp.Location = new System.Drawing.Point(8, 366);
			this.invalid_paths_arp.Name = "invalid_paths_arp";
			this.invalid_paths_arp.Size = new System.Drawing.Size(215, 20);
			this.invalid_paths_arp.TabIndex = 32;
			this.invalid_paths_arp.Text = "Paths with invalid attributes: 0";
			// 
			// show_message_z
			// 
			this.show_message_z.Location = new System.Drawing.Point(589, 363);
			this.show_message_z.Name = "show_message_z";
			this.show_message_z.Size = new System.Drawing.Size(220, 17);
			this.show_message_z.TabIndex = 33;
			this.show_message_z.Text = "Show message box when complete";
			this.show_message_z.UseVisualStyleBackColor = true;
			this.show_message_z.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Show_message_zMouseUp);
			// 
			// memory_z
			// 
			this.memory_z.Enabled = true;
			this.memory_z.Interval = 500;
			this.memory_z.Tick += new System.EventHandler(this.Memory_zTick);
			// 
			// memory__label_z
			// 
			this.memory__label_z.Location = new System.Drawing.Point(297, 363);
			this.memory__label_z.Name = "memory__label_z";
			this.memory__label_z.Size = new System.Drawing.Size(269, 14);
			this.memory__label_z.TabIndex = 34;
			this.memory__label_z.Text = "Memory";
			// 
			// level_p
			// 
			this.level_p.FormattingEnabled = true;
			this.level_p.Location = new System.Drawing.Point(505, 37);
			this.level_p.Name = "level_p";
			this.level_p.Size = new System.Drawing.Size(126, 21);
			this.level_p.TabIndex = 35;
			// 
			// label5
			// 
			this.label5.Location = new System.Drawing.Point(502, 17);
			this.label5.Name = "label5";
			this.label5.Size = new System.Drawing.Size(59, 17);
			this.label5.TabIndex = 36;
			this.label5.Text = "Level";
			// 
			// level_new_ava
			// 
			this.level_new_ava.FormattingEnabled = true;
			this.level_new_ava.Location = new System.Drawing.Point(505, 37);
			this.level_new_ava.Name = "level_new_ava";
			this.level_new_ava.Size = new System.Drawing.Size(126, 21);
			this.level_new_ava.TabIndex = 37;
			this.level_new_ava.Visible = false;
			// 
			// level_label
			// 
			this.level_label.Location = new System.Drawing.Point(502, 17);
			this.level_label.Name = "level_label";
			this.level_label.Size = new System.Drawing.Size(59, 17);
			this.level_label.TabIndex = 38;
			this.level_label.Text = "Level";
			this.level_label.Visible = false;
			// 
			// ar_create_tar
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(787, 432);
			this.Controls.Add(this.level_label);
			this.Controls.Add(this.level_new_ava);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.level_p);
			this.Controls.Add(this.memory__label_z);
			this.Controls.Add(this.show_message_z);
			this.Controls.Add(this.invalid_paths_arp);
			this.Controls.Add(this.cannot_read_arp);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.recurse_arp);
			this.Controls.Add(this.exclude_arp);
			this.Controls.Add(this.include_arp);
			this.Controls.Add(this.button7);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.compression_mode_ar_);
			this.Controls.Add(this.button6);
			this.Controls.Add(this.button5);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.maria_progress);
			this.Controls.Add(this.include_ar);
			this.Controls.Add(this.button3);
			this.Controls.Add(this.path_to_add_ar);
			this.Controls.Add(this.button4);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.ar_tar_file_);
			this.Controls.Add(this.my_error_ar);
			this.Controls.Add(this.mislaine_lv_);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.menuStrip1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
			this.MainMenuStrip = this.menuStrip1;
			this.Name = "ar_create_tar";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "ar_create_tar";
			this.Load += new System.EventHandler(this.Ar_create_tarLoad);
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Ar_create_tarFormClosing);
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.Label level_label;
		private System.Windows.Forms.ComboBox level_new_ava;
		private System.Windows.Forms.Label label5;
		private System.Windows.Forms.ComboBox level_p;
		private System.Windows.Forms.Label memory__label_z;
		private System.Windows.Forms.Timer memory_z;
		private System.Windows.Forms.CheckBox show_message_z;
		private System.Windows.Forms.Label invalid_paths_arp;
		private System.Windows.Forms.Label cannot_read_arp;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.ToolStripMenuItem opçõesToolStripMenuItem;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.CheckBox recurse_arp;
		private System.Windows.Forms.CheckBox exclude_arp;
		private System.Windows.Forms.CheckBox include_arp;
		private System.Windows.Forms.Button button7;
		private System.Windows.Forms.Label label4;
		private System.Windows.Forms.ComboBox compression_mode_ar_;
		private System.Windows.Forms.Button button6;
		private System.Windows.Forms.Button button5;
		private System.Windows.Forms.Button button2;
		private AmandarRicardo_Koci_Progress.progressbar maria_progress;
		private System.Windows.Forms.FolderBrowserDialog fb_ar;
		private System.Windows.Forms.SaveFileDialog sf_ar_;
		private System.Windows.Forms.TextBox include_ar;
		private System.Windows.Forms.TextBox path_to_add_ar;
		private System.Windows.Forms.Button button3;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Button button4;
		private System.Windows.Forms.TextBox ar_tar_file_;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Timer tempo_ar;
		private System.Windows.Forms.Label my_error_ar;
		private System.Windows.Forms.ColumnHeader ar_ch2;
		private System.Windows.Forms.ListView mislaine_lv_;
		private System.Windows.Forms.Button button1;
	}
}
