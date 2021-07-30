/*
 * Criado por SharpDevelop.
 * Usuário: AAKP
 * Data: 22/12/2020
 * Hora: 2:35
 * 
 * Para alterar este modelo use Ferramentas | Opções | Codificação | Editar Cabeçalhos Padrão.
 */
using System;
using System.Windows.Forms;

namespace tar_sample_ar
{
	/// <summary>
	/// Class with program entry point.
	/// </summary>
	internal sealed class Program
	{		
		/// <summary>
		/// Program entry point.
		/// </summary>
		[STAThread]
		private static void Main(string[] args)
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			
			util_ar.pedro_dprintf(-1, "args " + args.Length);
			
			if(0 < args.Length)
			{				
				util_ar.tar_file_arp                      = args[0];
				util_ar.path_with_the_files_arp           = args[1];
				util_ar.recurse_on_subfolders_arp         = false  ;
				
				if("true" == args[2] || "True" == args[2])
				{
					util_ar.recurse_on_subfolders_arp      = true  ;
				}
				
				util_ar.include_the_files_or_wildcards_arp = args[3];
				util_ar.compression_mode_arp               = args[4];
				util_ar.destination_backup_path_arp        = args[5];
				
				util_ar.true_if_include__arp         = false  ;
				
				if("true" == args[6] || "True" == args[6])
				{
					util_ar.true_if_include__arp      = true  ;
				}
				
				Application.Run(new ar_create_tar(true))                ;
				
			}
			else
				Application.Run(new Select());
		}
		
	}
}
