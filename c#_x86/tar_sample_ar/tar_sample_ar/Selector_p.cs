/*
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 24/04/2021
 * Hora: 16:45
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
using System;
using System.Drawing;
using System.Windows.Forms;

namespace tar_sample_ar
{
	/// <summary>
	/// Description of Selector_p.
	/// </summary>
	public partial class Select : Form
	{
		public Select()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		void Button1Click(object sender, EventArgs e)
		{
			util_ar.is_parolin_p = true;
			MainForm amanda = new MainForm();
			amanda.Show();
			//this.WindowState = FormWindowState.Minimized;
		}
		
		void Button2Click(object sender, EventArgs e)
		{
			util_ar.is_parolin_p = false;
			MainForm amanda = new MainForm();
			amanda.Show();
			//this.WindowState = FormWindowState.Minimized;
		}
	}
}
