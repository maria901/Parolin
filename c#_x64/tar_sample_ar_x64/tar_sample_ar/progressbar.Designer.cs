namespace AmandarRicardo_Koci_Progress
{
    partial class progressbar
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.fixo = new System.Windows.Forms.PictureBox();
            this.deslizante = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.fixo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.deslizante)).BeginInit();
            this.SuspendLayout();
            // 
            // fixo
            // 
            this.fixo.BackColor = System.Drawing.Color./*learning*/LightSteelBlue;
            this.fixo.Location = new System.Drawing.Point(3, 3);
            this.fixo.Name = "fixo";
            this.fixo.Size = new System.Drawing.Size(79, 22);
            this.fixo.TabIndex = 0;
            this.fixo.TabStop = false;
            this.fixo.MouseLeave += new System.EventHandler(this.fixo_MouseLeave);
            this.fixo.MouseDown += new System.Windows.Forms.MouseEventHandler(this.fixo_MouseDown);
            this.fixo.MouseEnter += new System.EventHandler(this.fixo_MouseEnter);
            // 
            // deslizante
            // 
            this.deslizante.BackColor = System.Drawing.Color.RoyalBlue;
            this.deslizante.Location = new System.Drawing.Point(3, 3);
            this.deslizante.Name = "deslizante";
            this.deslizante.Size = new System.Drawing.Size(79, 22);
            this.deslizante.TabIndex = 1;
            this.deslizante.TabStop = false;
            this.deslizante.Click += new System.EventHandler(this.deslizante_Click);
            this.deslizante.MouseDown += new System.Windows.Forms.MouseEventHandler(this.deslizante_MouseDown);
            this.deslizante.MouseEnter += new System.EventHandler(this.deslizante_MouseEnter);
            // 
            // progressbar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.deslizante);
            this.Controls.Add(this.fixo);
            this.Name = "progressbar";
            this.Size = new System.Drawing.Size(87, 30);
            this.Load += new System.EventHandler(this.progressbar_Load);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.progressbar_MouseDown);
            this.Resize += new System.EventHandler(this.progressbar_Resize);
            this.MouseEnter += new System.EventHandler(this.progressbar_MouseEnter);
            ((System.ComponentModel.ISupportInitialize)(this.fixo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.deslizante)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox fixo;
        private System.Windows.Forms.PictureBox deslizante;
    }
}
