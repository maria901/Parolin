/* ar.tar designer ric
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 22/12/2020
 * Hora: 2:35
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace tar_sample_ar
{
	partial class MainForm
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
			this.ar_tar_file_ = new System.Windows.Forms.TextBox();
			this.mislaine_lv_ = new System.Windows.Forms.ListView();
			this.ar_ch2 = new System.Windows.Forms.ColumnHeader();
			this.ar_ch1 = new System.Windows.Forms.ColumnHeader();
			this.ar_ch3 = new System.Windows.Forms.ColumnHeader();
			this.ar_ch4 = new System.Windows.Forms.ColumnHeader();
			this.ar_ch5 = new System.Windows.Forms.ColumnHeader();
			this.folders_ar = new System.Windows.Forms.Label();
			this.files_ar = new System.Windows.Forms.Label();
			this.my_error_ar = new System.Windows.Forms.Label();
			this.button2 = new System.Windows.Forms.Button();
			this.my_selected_folder_ar = new System.Windows.Forms.TextBox();
			this.button3 = new System.Windows.Forms.Button();
			this.dest_folder_ar = new System.Windows.Forms.Label();
			this.label1 = new System.Windows.Forms.Label();
			this.button4 = new System.Windows.Forms.Button();
			this.my_folder_ar = new System.Windows.Forms.FolderBrowserDialog();
			this.open_file_ar = new System.Windows.Forms.OpenFileDialog();
			this.progress_information_ar = new System.Windows.Forms.ListBox();
			this.button5 = new System.Windows.Forms.Button();
			this.tempo_ar = new System.Windows.Forms.Timer(this.components);
			this.tempo_extract_ = new System.Windows.Forms.Timer(this.components);
			this.aakp_progress_ = new AmandarRicardo_Koci_Progress.progressbar();
			this.button6 = new System.Windows.Forms.Button();
			this.button7 = new System.Windows.Forms.Button();
			this.button8 = new System.Windows.Forms.Button();
			this.button9 = new System.Windows.Forms.Button();
			this.format_arp = new System.Windows.Forms.Label();
			this.menuStrip1 = new System.Windows.Forms.MenuStrip();
			this.optionsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
			this.rspk_progress = new AmandarRicardo_Koci_Progress.progressbar();
			this.cpu_z = new System.Windows.Forms.Label();
			this.threads__z = new System.Windows.Forms.Label();
			this.memory_z = new System.Windows.Forms.Label();
			this.memoria_z = new System.Windows.Forms.Timer(this.components);
			this.menuStrip1.SuspendLayout();
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(12, 28);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(178, 23);
			this.button1.TabIndex = 0;
			this.button1.Text = "List";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// ar_tar_file_
			// 
			this.ar_tar_file_.Location = new System.Drawing.Point(12, 75);
			this.ar_tar_file_.Name = "ar_tar_file_";
			this.ar_tar_file_.Size = new System.Drawing.Size(699, 20);
			this.ar_tar_file_.TabIndex = 1;
			this.ar_tar_file_.Text = "C:\\Users\\AAKP\\Downloads\\k.tar";
			// 
			// mislaine_lv_
			// 
			this.mislaine_lv_.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
									this.ar_ch2,
									this.ar_ch1,
									this.ar_ch3,
									this.ar_ch4,
									this.ar_ch5});
			this.mislaine_lv_.FullRowSelect = true;
			this.mislaine_lv_.GridLines = true;
			this.mislaine_lv_.Location = new System.Drawing.Point(12, 101);
			this.mislaine_lv_.Name = "mislaine_lv_";
			this.mislaine_lv_.Size = new System.Drawing.Size(1326, 261);
			this.mislaine_lv_.TabIndex = 2;
			this.mislaine_lv_.UseCompatibleStateImageBehavior = false;
			this.mislaine_lv_.View = System.Windows.Forms.View.Details;
			// 
			// ar_ch2
			// 
			this.ar_ch2.Text = " ";
			this.ar_ch2.Width = 18;
			// 
			// ar_ch1
			// 
			this.ar_ch1.Text = "Item";
			this.ar_ch1.Width = 700;
			// 
			// ar_ch3
			// 
			this.ar_ch3.Text = "Timestamp";
			this.ar_ch3.Width = 150;
			// 
			// ar_ch4
			// 
			this.ar_ch4.Text = "Type";
			this.ar_ch4.Width = 180;
			// 
			// ar_ch5
			// 
			this.ar_ch5.Text = "Size";
			this.ar_ch5.Width = 150;
			// 
			// folders_ar
			// 
			this.folders_ar.Location = new System.Drawing.Point(12, 423);
			this.folders_ar.Name = "folders_ar";
			this.folders_ar.Size = new System.Drawing.Size(351, 20);
			this.folders_ar.TabIndex = 3;
			this.folders_ar.Text = "Folders";
			// 
			// files_ar
			// 
			this.files_ar.Location = new System.Drawing.Point(12, 443);
			this.files_ar.Name = "files_ar";
			this.files_ar.Size = new System.Drawing.Size(341, 20);
			this.files_ar.TabIndex = 4;
			this.files_ar.Text = "Files";
			// 
			// my_error_ar
			// 
			this.my_error_ar.Location = new System.Drawing.Point(12, 463);
			this.my_error_ar.Name = "my_error_ar";
			this.my_error_ar.Size = new System.Drawing.Size(1100, 20);
			this.my_error_ar.TabIndex = 5;
			this.my_error_ar.Text = "Error: <none>";
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(196, 28);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(178, 23);
			this.button2.TabIndex = 6;
			this.button2.Text = "Extract";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.Button2Click);
			// 
			// my_selected_folder_ar
			// 
			this.my_selected_folder_ar.Location = new System.Drawing.Point(798, 75);
			this.my_selected_folder_ar.Name = "my_selected_folder_ar";
			this.my_selected_folder_ar.Size = new System.Drawing.Size(459, 20);
			this.my_selected_folder_ar.TabIndex = 7;
			this.my_selected_folder_ar.Text = "C:\\Ava\\back\\extract_k";
			// 
			// button3
			// 
			this.button3.Location = new System.Drawing.Point(1263, 74);
			this.button3.Name = "button3";
			this.button3.Size = new System.Drawing.Size(75, 21);
			this.button3.TabIndex = 8;
			this.button3.Text = "select";
			this.button3.UseVisualStyleBackColor = true;
			this.button3.Click += new System.EventHandler(this.Button3Click);
			// 
			// dest_folder_ar
			// 
			this.dest_folder_ar.Location = new System.Drawing.Point(798, 55);
			this.dest_folder_ar.Name = "dest_folder_ar";
			this.dest_folder_ar.Size = new System.Drawing.Size(205, 17);
			this.dest_folder_ar.TabIndex = 9;
			this.dest_folder_ar.Text = "Destination folder";
			// 
			// label1
			// 
			this.label1.Location = new System.Drawing.Point(12, 55);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(205, 17);
			this.label1.TabIndex = 10;
			this.label1.Text = "Tar file";
			// 
			// button4
			// 
			this.button4.Location = new System.Drawing.Point(717, 74);
			this.button4.Name = "button4";
			this.button4.Size = new System.Drawing.Size(75, 21);
			this.button4.TabIndex = 11;
			this.button4.Text = "select";
			this.button4.UseVisualStyleBackColor = true;
			this.button4.Click += new System.EventHandler(this.Button4Click);
			// 
			// open_file_ar
			// 
			this.open_file_ar.FileName = "openFileDialog1";
			// 
			// progress_information_ar
			// 
			this.progress_information_ar.FormattingEnabled = true;
			this.progress_information_ar.Location = new System.Drawing.Point(14, 490);
			this.progress_information_ar.Name = "progress_information_ar";
			this.progress_information_ar.Size = new System.Drawing.Size(1324, 95);
			this.progress_information_ar.TabIndex = 12;
			// 
			// button5
			// 
			this.button5.Location = new System.Drawing.Point(1196, 6);
			this.button5.Name = "button5";
			this.button5.Size = new System.Drawing.Size(142, 29);
			this.button5.TabIndex = 13;
			this.button5.Text = "To create a Tar file";
			this.button5.UseVisualStyleBackColor = true;
			this.button5.Click += new System.EventHandler(this.Button5Click);
			// 
			// tempo_ar
			// 
			this.tempo_ar.Interval = 50;
			this.tempo_ar.Tick += new System.EventHandler(this.Tempo_arTick);
			// 
			// tempo_extract_
			// 
			this.tempo_extract_.Interval = 50;
			this.tempo_extract_.Tick += new System.EventHandler(this.Tempo_extract_Tick);
			// 
			// aakp_progress_
			// 
			this.aakp_progress_.Location = new System.Drawing.Point(12, 397);
			this.aakp_progress_.Maximum = 10000;
			this.aakp_progress_.Name = "aakp_progress_";
			this.aakp_progress_.Size = new System.Drawing.Size(1326, 23);
			this.aakp_progress_.TabIndex = 14;
			this.aakp_progress_.Value = 0;
			// 
			// button6
			// 
			this.button6.Location = new System.Drawing.Point(1118, 431);
			this.button6.Name = "button6";
			this.button6.Size = new System.Drawing.Size(70, 29);
			this.button6.TabIndex = 15;
			this.button6.Text = "Pause";
			this.button6.UseVisualStyleBackColor = true;
			this.button6.Click += new System.EventHandler(this.Button6Click);
			// 
			// button7
			// 
			this.button7.Location = new System.Drawing.Point(1270, 431);
			this.button7.Name = "button7";
			this.button7.Size = new System.Drawing.Size(70, 29);
			this.button7.TabIndex = 16;
			this.button7.Text = "Cancel";
			this.button7.UseVisualStyleBackColor = true;
			this.button7.Click += new System.EventHandler(this.Button7Click);
			// 
			// button8
			// 
			this.button8.Location = new System.Drawing.Point(1194, 431);
			this.button8.Name = "button8";
			this.button8.Size = new System.Drawing.Size(70, 29);
			this.button8.TabIndex = 17;
			this.button8.Text = "Resume";
			this.button8.UseVisualStyleBackColor = true;
			this.button8.Click += new System.EventHandler(this.Button8Click);
			// 
			// button9
			// 
			this.button9.Location = new System.Drawing.Point(1048, 6);
			this.button9.Name = "button9";
			this.button9.Size = new System.Drawing.Size(142, 29);
			this.button9.TabIndex = 18;
			this.button9.Text = "To update a Tar file";
			this.button9.UseVisualStyleBackColor = true;
			this.button9.Click += new System.EventHandler(this.Button9Click);
			// 
			// format_arp
			// 
			this.format_arp.Location = new System.Drawing.Point(1118, 467);
			this.format_arp.Name = "format_arp";
			this.format_arp.Size = new System.Drawing.Size(220, 16);
			this.format_arp.TabIndex = 19;
			this.format_arp.Text = "tar format: unknown";
			// 
			// menuStrip1
			// 
			this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
									this.optionsToolStripMenuItem});
			this.menuStrip1.Location = new System.Drawing.Point(0, 0);
			this.menuStrip1.Name = "menuStrip1";
			this.menuStrip1.Size = new System.Drawing.Size(1350, 24);
			this.menuStrip1.TabIndex = 20;
			this.menuStrip1.Text = "menuStrip1";
			// 
			// optionsToolStripMenuItem
			// 
			this.optionsToolStripMenuItem.Name = "optionsToolStripMenuItem";
			this.optionsToolStripMenuItem.Size = new System.Drawing.Size(61, 20);
			this.optionsToolStripMenuItem.Text = "Options";
			this.optionsToolStripMenuItem.Click += new System.EventHandler(this.OptionsToolStripMenuItemClick);
			// 
			// rspk_progress
			// 
			this.rspk_progress.Location = new System.Drawing.Point(12, 368);
			this.rspk_progress.Maximum = 10000;
			this.rspk_progress.Name = "rspk_progress";
			this.rspk_progress.Size = new System.Drawing.Size(1324, 23);
			this.rspk_progress.TabIndex = 21;
			this.rspk_progress.Value = 0;
			// 
			// cpu_z
			// 
			this.cpu_z.Location = new System.Drawing.Point(12, 592);
			this.cpu_z.Name = "cpu_z";
			this.cpu_z.Size = new System.Drawing.Size(675, 17);
			this.cpu_z.TabIndex = 22;
			this.cpu_z.Text = "label2";
			// 
			// threads__z
			// 
			this.threads__z.Location = new System.Drawing.Point(340, 423);
			this.threads__z.Name = "threads__z";
			this.threads__z.Size = new System.Drawing.Size(321, 12);
			this.threads__z.TabIndex = 23;
			this.threads__z.Text = "Threads used in the decompression";
			// 
			// memory_z
			// 
			this.memory_z.Location = new System.Drawing.Point(588, 423);
			this.memory_z.Name = "memory_z";
			this.memory_z.Size = new System.Drawing.Size(219, 18);
			this.memory_z.TabIndex = 24;
			this.memory_z.Text = "Memory";
			// 
			// memoria_z
			// 
			this.memoria_z.Enabled = true;
			this.memoria_z.Interval = 500;
			this.memoria_z.Tick += new System.EventHandler(this.Memoria_zTick);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(1350, 612);
			this.Controls.Add(this.memory_z);
			this.Controls.Add(this.threads__z);
			this.Controls.Add(this.cpu_z);
			this.Controls.Add(this.rspk_progress);
			this.Controls.Add(this.format_arp);
			this.Controls.Add(this.button9);
			this.Controls.Add(this.button8);
			this.Controls.Add(this.button7);
			this.Controls.Add(this.button6);
			this.Controls.Add(this.aakp_progress_);
			this.Controls.Add(this.button5);
			this.Controls.Add(this.progress_information_ar);
			this.Controls.Add(this.button4);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.dest_folder_ar);
			this.Controls.Add(this.button3);
			this.Controls.Add(this.my_selected_folder_ar);
			this.Controls.Add(this.button2);
			this.Controls.Add(this.my_error_ar);
			this.Controls.Add(this.files_ar);
			this.Controls.Add(this.folders_ar);
			this.Controls.Add(this.mislaine_lv_);
			this.Controls.Add(this.ar_tar_file_);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.menuStrip1);
			this.MainMenuStrip = this.menuStrip1;
			this.Name = "MainForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "tar_sample_ar";
			this.Load += new System.EventHandler(this.MainFormLoad);
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.MainFormFormClosing);
			this.Resize += new System.EventHandler(this.MainFormResize);
			this.menuStrip1.ResumeLayout(false);
			this.menuStrip1.PerformLayout();
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.Timer memoria_z;
		private System.Windows.Forms.Label memory_z;
		private System.Windows.Forms.Label threads__z;
		private System.Windows.Forms.Label cpu_z;
		private AmandarRicardo_Koci_Progress.progressbar rspk_progress;
		private System.Windows.Forms.ToolStripMenuItem optionsToolStripMenuItem;
		private System.Windows.Forms.MenuStrip menuStrip1;
		private System.Windows.Forms.Label format_arp;
		private System.Windows.Forms.Button button9;
		private System.Windows.Forms.Button button8;
		private System.Windows.Forms.Button button7;
		private System.Windows.Forms.Button button6;
		private AmandarRicardo_Koci_Progress.progressbar aakp_progress_;
		private System.Windows.Forms.Timer tempo_extract_;
		private System.Windows.Forms.Timer tempo_ar;
		private System.Windows.Forms.Button button5;
		private System.Windows.Forms.ListBox progress_information_ar;
		private System.Windows.Forms.TextBox my_selected_folder_ar;
		private System.Windows.Forms.OpenFileDialog open_file_ar;
		private System.Windows.Forms.FolderBrowserDialog my_folder_ar;
		private System.Windows.Forms.Button button4;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label dest_folder_ar;
		private System.Windows.Forms.Button button3;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.Label my_error_ar;
		private System.Windows.Forms.Label files_ar;
		private System.Windows.Forms.Label folders_ar;
		private System.Windows.Forms.ColumnHeader ar_ch2;
		private System.Windows.Forms.ColumnHeader ar_ch1;
		private System.Windows.Forms.ColumnHeader ar_ch3;
		private System.Windows.Forms.ColumnHeader ar_ch4;
		private System.Windows.Forms.ColumnHeader ar_ch5;
		private System.Windows.Forms.ListView mislaine_lv_;
		private System.Windows.Forms.TextBox ar_tar_file_;
		private System.Windows.Forms.Button button1;
	}
}
