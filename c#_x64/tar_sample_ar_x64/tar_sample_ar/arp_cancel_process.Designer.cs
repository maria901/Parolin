/* cancel desginer... my love
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 20/01/2021
 * Hora: 18:52
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
namespace tar_sample_ar
{
	partial class Progress_arp
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
			this.our_progress_1 = new AmandarRicardo_Koci_Progress.progressbar();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.SuspendLayout();
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(141, 147);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(205, 52);
			this.button1.TabIndex = 0;
			this.button1.Text = "Cancel";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.Button1Click);
			// 
			// our_progress_1
			// 
			this.our_progress_1.Location = new System.Drawing.Point(26, 66);
			this.our_progress_1.Maximum = 10000;
			this.our_progress_1.Name = "our_progress_1";
			this.our_progress_1.Size = new System.Drawing.Size(427, 28);
			this.our_progress_1.TabIndex = 1;
			this.our_progress_1.Value = 0;
			// 
			// timer1
			// 
			this.timer1.Enabled = true;
			this.timer1.Interval = 50;
			this.timer1.Tick += new System.EventHandler(this.Timer1Tick);
			// 
			// Progress_arp
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(487, 262);
			this.Controls.Add(this.our_progress_1);
			this.Controls.Add(this.button1);
			this.Name = "Progress_arp";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Progress";
			this.TopMost = true;
			this.Load += new System.EventHandler(this.Arp_cancel_processLoad);
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Progress_arpFormClosing);
			this.ResumeLayout(false);
		}
		private AmandarRicardo_Koci_Progress.progressbar our_progress_1;
		public System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.Button button1;
	}
}
