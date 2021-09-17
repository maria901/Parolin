/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de C�pia (C) <2021>  <Corpora��o do Trabalho Bin�rio>         *
 *                                                                              *
 *     Este  programa  � software livre: voc� pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral P�blica como       8
 *     publicado  pela Funda��o  de Software  Livre, tanto a vers�o 3  da       *
 *     Licensa, ou (dependendo da sua op��o) qualquer vers�o posterior.         *
 *                                                                              *
 *     Este  programa � distribu�do na  esperan�a que isto vai  ser �til,       *
 *     mas SEM  QUALQUER GARANTIA; sem  at� mesmo a implicada garantia de       *
 *     COMERCIALIZA��O ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral P�blica para mais detalhes.                                *
 *                                                                              *
 *     Voc� deve ter recebido uma  c�pia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa P�blica Menor junto com este programa                            *
 *     Se n�o, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails:                                                                 *
 *     maria@arsoftware.net.br                                                  *
 *     pedro@locacaodiaria.com.br                                               *
 *                                                                              *
 *     contato imediato(para uma resposta muito r�pida) WhatsApp                *
 *     (+55)41 9627 1708 - isto est� sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

/**
 * It will dump a file or folder when the file being hadled is
 * a iso file
 *
 * @param name the entry name
 *
 * @param initial_path_ar the path for the destination file
 *
 *
 */
void dump_file_or_folder_iso(char const *name, char * initial_path_ar)
{
  DWORD attributes;
  char file_or_folder_to_process[1000] = { 0 };
  char file_or_folder_to_process_copy[1024] = { 0 };
  char tar_file_copy[1024] = { 0 };
  bool is_dir_ar = false;
  int fd_ar;

  strcpy(file_or_folder_to_process, initial_path_ar);

  if (strlen(file_or_folder_to_process))
    {
      if ('\\' != file_or_folder_to_process[strlen(file_or_folder_to_process) - 1])
        {
          strcat(file_or_folder_to_process, "\\");
        }
    }
  else
    {
      assert(0 && "path cannot be empty");
    }

  strcat(file_or_folder_to_process, name);

  strcpy(file_or_folder_to_process_copy, file_or_folder_to_process);

  trocadordebackslashtras(file_or_folder_to_process_copy);

  strtolower_ar(file_or_folder_to_process_copy);
  strcpy(tar_file_copy, archive_name_array_filename);
  strtolower_ar(tar_file_copy);

  if (0 == strcmp(tar_file_copy, file_or_folder_to_process_copy))
    {
      strcpy(warning_message_k, "Cannot add himself to the tar file, skipping...");
      add_more_one(warning_message_k);
      return;
    }

  trocadordebackslashfrente((char*)name);
  attributes = GetFileAttributesW(amanda_utf8towide_1_(file_or_folder_to_process));
  if (INVALID_FILE_ATTRIBUTES == attributes)
    {
      paths_with_invalid_attributes_arp++;
      sprintf(warning_message_k, "File %s has invalid attributes, skipping", file_or_folder_to_process);
      add_more_one(warning_message_k);

      return;
    }

  if (attributes & FILE_ATTRIBUTE_DIRECTORY)
    {
      is_dir_ar = true;
    }
  else
    {
      if ((attributes & FILE_ATTRIBUTE_READONLY) || //error here
          (attributes & FILE_ATTRIBUTE_HIDDEN) ||
          (attributes & FILE_ATTRIBUTE_SYSTEM) ||
          (attributes & FILE_ATTRIBUTE_ARCHIVE))
        {
          ;
        }
      else
        {
          paths_with_invalid_attributes_arp++;
          sprintf(warning_message_k, "File %s has invalid attributes, skipping...", file_or_folder_to_process);
          add_more_one(warning_message_k);
          return;
        }
    }

  if (true == is_dir_ar)
    {
      ;
    }
  else
    {
      fd_ar = _wopen(amanda_utf8towide_1_(file_or_folder_to_process), O_RDONLY | O_BINARY,
                     _S_IREAD);

      if (-1 == fd_ar)
        {
          files_that_cannot_be_read++;
          sprintf(warning_message_k, "Cannot open %s to write", file_or_folder_to_process);
          add_more_one(warning_message_k);
          return;
        }

      close(fd_ar);
    }
  sprintf(process_message_k, "Processing %s", file_or_folder_to_process);
  add_more_one(process_message_k);
}
