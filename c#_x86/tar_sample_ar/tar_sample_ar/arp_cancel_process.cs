/*
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 20/01/2021
 * Hora: 18:52
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
using System;
using System.Drawing;
using System.Windows.Forms;

namespace tar_sample_ar
{
	/// <summary>
	/// Description of arp_cancel_process.
	/// </summary>
	public partial class Progress_arp : Form
	{
		public Progress_arp()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		~Progress_arp()
		{
			util_ar.pedro_dprintf(-1, "finalizer of the form Progress_arp running...");
		}
		void Arp_cancel_processLoad(object sender, EventArgs e)
		{
			this.Icon = util_ar.pedro_get_icon();
		}
		
		void Button1Click(object sender, EventArgs e)
		{
			util_ar.cancel_arp = true;
			util_ar.copia_arp = null;
			this.Close();
		}
		
		void Progress_arpFormClosing(object sender, FormClosingEventArgs e)
		{
			util_ar.copia_arp = null;
		}
		
		public void Timer1Tick(object sender, EventArgs e)
		{
			our_progress_1.Value = util_ar.get_listview_progress_arp();
		}
	}
}
