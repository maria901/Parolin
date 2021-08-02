
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/

#define IS_DEBUG_APE__ /* kkkkkkkkkkkk */ (-1)
#include /* amanda's smart ape */ <windows.h>
#include /* amanda's smart ape  */ <stdint.h>
#include /* amanda's smart ape   */ <stdio.h>
#include /* amanda's smart ape  */ <stdlib.h>
#include /* amanda's smart ape  */ <string.h>
#include /* amanda's smart ape    */ <time.h>
#include /* amanda's smart ape   */ <errno.h>
#include /* amanda's smart ape   */ <fcntl.h>
#include /* amanda's smart ape   */ <ctype.h>
#include /* amanda's smart ape    */ <math.h>
#include /* amanda's smart ape  */ <wctype.h>
#include /* amanda's smart ape   */ <wchar.h>
#include /* amanda's smart ape  */ <stdarg.h>
#include /* amanda's smart ape  */ <stddef.h>
#include /* amanda's smart ape  */ <setjmp.h>
#include /* amanda's smart ape  */ <locale.h>
#include /* amanda's smart ape  */ <signal.h>
#include /* amanda's smart ape  */ <limits.h>
#include /* amanda's smart ape   */ <float.h>
#include /* amanda's smart ape  */ <iso646.h>

#undef NDEBUG
#include /* amanda's smart ape  */ <assert.h>
#include /* amanda's smart ape */ <stdbool.h>
#include /* amanda's smart ape */ <process.h>

//////////////////////////////////////////////////////////////////////////////////////
//oie...

struct oi_amanda
{
     char entry______i       [1027];
     char whole_entry_i      [1027];
     char whole_entry_above_i[1027];
     char whole_path_above_i [1027];
     struct oi_amanda *next_amanda_s_smart_ape;
     struct oi_amanda *previous_amanda_s_smart_ape;
     struct oi_amanda *subfolder_amanda_s_smart_ape;
     HANDLE parent_hFind_amanda_s_smart______ape;
     HANDLE current_hFind_amanda_s_smart_____ape;
};

bool cancel_me_amanda_smart_ape = false;

char entry_______i               [1027];
char whole_entry_i               [1027];

int amanda_s_smart_ape(__attribute__((unused)) char *initial_path_amanda_s_smart_ape,
                       bool recurse_on_subfolders_amanda_s_smart_ape, enum amanda__mode amanda_mode)
{

     struct oi_amanda *oi_amanda_ptr = calloc(1, sizeof(struct oi_amanda));

     struct oi_amanda *oi_amanda_ptr_inicial = oi_amanda_ptr;

     struct oi_amanda *to_call_free______amanda_s_smart_ape;

     WIN32_FIND_DATAW ffd ={0};
     char szDir      [1027];
     char szDir_i    [1027];
     char lpcszFolder[1027];

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//for ScanFolder
	static   __time64_t s_arp_3;
	static   VAL_data VAL_data_i;
	int64_t  size_i;
	__attribute__((unused)) int len_i;
	if(I_MODE_IS_SCANFOLDER == amanda_mode)
	{
		files_that_cannot_be_read_update = 0;
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     // keeping this here int debug_counter_amanda_s_smart_ape = 8;

     strcpy(lpcszFolder, initial_path_amanda_s_smart_ape);//"C:\\Ava\\back\\test_i");

     //strcpy(lpcszFolder, "C:\\");

     //strcpy(lpcszFolder, "C:\\Program Files");//deu? sim querida...

     if (strlen(lpcszFolder))
     {
          if ('\\' == lpcszFolder[strlen(lpcszFolder) - 1])
          {
               lpcszFolder[strlen(lpcszFolder) - 1] = 0;
          }
     }

     //    strcpy(oi_amanda_ptr->whole_path_i, lpcszFolder);
     strcpy(szDir, lpcszFolder);
     strcat(szDir, "\\*");

     oi_amanda_ptr->parent_hFind_amanda_s_smart______ape = INVALID_HANDLE_VALUE;

     oi_amanda_ptr->previous_amanda_s_smart_ape = NULL;

loop_again_amanda_s_smart_ape:;

     if (1 == 0)
     {
          goto loop_again_amanda_s_smart_ape;
     }

     pedro_dprintf(IS_DEBUG_APE__, "path total %s\n", szDir);
     //assert(0 && "mais amor?...");

     pedro_dprintf(IS_DEBUG_APE__, "endereco da struct na entrada %p\n", oi_amanda_ptr);
     oi_amanda_ptr->current_hFind_amanda_s_smart_____ape = FindFirstFileW(amanda_utf8towide_1_(szDir), &ffd);
	 pedro_dprintf(-1, "ok1 \n");
     if (INVALID_HANDLE_VALUE == oi_amanda_ptr->current_hFind_amanda_s_smart_____ape)
     {
          pedro_dprintf(-1, "INVALID_HANDLE_VALUE\n");
          pedro_dprintf(-1, "path %s\n", szDir);
          if (oi_amanda_ptr == oi_amanda_ptr_inicial)
          {
               pedro_dprintf(-1, "free forçado final on %x\n", oi_amanda_ptr);
               free(oi_amanda_ptr);
               oi_amanda_ptr = NULL;
               goto no_entries_i; //se é um subdiretorio tem . e .. experimente
          }

          goto keep_running_amanda_s_smart_ape;
     }

     do
     {

          if (cancel_me_amanda_smart_ape)
          {
               pedro_dprintf(IS_DEBUG_APE__, "Called cancel \n");
               goto exit_me_forced_amanda_s_smart_ape;
          }

          if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
          {
               if ('.' != (valquiria_wide_to_utf8(ffd.cFileName))[0])
               {
 

                    ; //do
                    pedro_dprintf(-1, "2 dir  -> %s\n", valquiria_wide_to_utf8(ffd.cFileName));

                    if (INVALID_HANDLE_VALUE == oi_amanda_ptr->parent_hFind_amanda_s_smart______ape)
                    {
                         strcpy(oi_amanda_ptr->entry______i, valquiria_wide_to_utf8(ffd.cFileName));
                    }
                    else
                    {
                         strcpy(oi_amanda_ptr->entry______i, oi_amanda_ptr->whole_entry_above_i);
                         strcat(oi_amanda_ptr->entry______i, "\\");
                         strcat(oi_amanda_ptr->entry______i, valquiria_wide_to_utf8(ffd.cFileName));
                    }

                    if (recurse_on_subfolders_amanda_s_smart_ape)
                    {
                         oi_amanda_ptr->subfolder_amanda_s_smart_ape = calloc(1, sizeof(struct oi_amanda));

                         oi_amanda_ptr->subfolder_amanda_s_smart_ape->previous_amanda_s_smart_ape = oi_amanda_ptr;

                         strcpy(oi_amanda_ptr->subfolder_amanda_s_smart_ape->whole_entry_above_i,
                                oi_amanda_ptr->entry______i);

                         oi_amanda_ptr->subfolder_amanda_s_smart_ape->parent_hFind_amanda_s_smart______ape =
                             oi_amanda_ptr->current_hFind_amanda_s_smart_____ape;
                    }

                    strcpy(szDir, lpcszFolder);
                    strcat(szDir, "\\"       );
                    strcat(szDir, oi_amanda_ptr->entry______i);

                    strcpy(oi_amanda_ptr->whole_entry_i, szDir);

                    /*


aqui tem a entrada inteira...

dir ->

oi_amanda_ptr->whole_entry_i -- com path inicial
oi_amanda_ptr->entry______i  -- so a entrada....

//vamos converter para utf-8?...

*/

                    strcat(szDir, "\\*");
                    //assert(0 && "3");

                    pedro_dprintf(IS_DEBUG_APE__, "oi_amanda_ptr->current_hFind_amanda_s_smart_____ape == %x\n", oi_amanda_ptr->current_hFind_amanda_s_smart_____ape);

                    pedro_dprintf(IS_DEBUG_APE__, "dir %s\n", oi_amanda_ptr->entry______i );
                    pedro_dprintf(IS_DEBUG_APE__, "dir %s\n", oi_amanda_ptr->whole_entry_i);
                    pedro_dprintf(IS_DEBUG_APE__, "*************************************\n");

					if (recurse_on_subfolders_amanda_s_smart_ape)
                    {
						/*
						setor de folders
						*/
						strcpy(whole_entry_i, oi_amanda_ptr->whole_entry_i);
						strcpy(entry_______i, oi_amanda_ptr->entry______i );
						
						if(I_MODE_IS_SCANFOLDER == amanda_mode)
						{
						
							check_item_z_june_24(entry_______i);
							get_timestamp_arp(whole_entry_i, &s_arp_3, & VAL_data_i);

							 add_more_one_z_june_24
							  (
								   atime_i                         ,
								   mtime_i                         ,
								   ctime_i                         ,
								   0                               ,
								   _ftelli64(my___temp_file_i)     ,
								   entry_______i         ,
								   true                            ,
								   true                            ,
								   0
								   );
						}
					}


                    if (recurse_on_subfolders_amanda_s_smart_ape)
                    {
                         oi_amanda_ptr = oi_amanda_ptr->subfolder_amanda_s_smart_ape;
                    }

                    pedro_dprintf(IS_DEBUG_APE__, "endereco da struct na passagem %p\n", oi_amanda_ptr);

                    if (recurse_on_subfolders_amanda_s_smart_ape)
                    {
                         goto loop_again_amanda_s_smart_ape;
                    }
               }
               else
               {
                    pedro_dprintf(-1, "3 . ou .. \n");
                    continue;
               }
          }
          else
          {

               pedro_dprintf(-1, "4 file -> %s\n", valquiria_wide_to_utf8(ffd.cFileName));

               if (INVALID_HANDLE_VALUE == oi_amanda_ptr->parent_hFind_amanda_s_smart______ape)
               {
                    strcpy(oi_amanda_ptr->entry______i, valquiria_wide_to_utf8(ffd.cFileName));
               }
               else
               {
                    strcpy(oi_amanda_ptr->entry______i, oi_amanda_ptr->whole_entry_above_i);
                    strcat(oi_amanda_ptr->entry______i, "\\");
                    strcat(oi_amanda_ptr->entry______i, valquiria_wide_to_utf8(ffd.cFileName));
               }

               strcpy(szDir_i, lpcszFolder);
               strcat(szDir_i, "\\");
               strcat(szDir_i, oi_amanda_ptr->entry______i);

               strcpy(oi_amanda_ptr->whole_entry_i, szDir_i);

               pedro_dprintf(IS_DEBUG_APE__, "oi_amanda_ptr->current_hFind_amanda_s_smart_____ape == %x\n", oi_amanda_ptr->current_hFind_amanda_s_smart_____ape);

               pedro_dprintf(IS_DEBUG_APE__, "file %s\n", oi_amanda_ptr->entry______i);
               pedro_dprintf(IS_DEBUG_APE__, "file %s\n", oi_amanda_ptr->whole_entry_i);
               pedro_dprintf(IS_DEBUG_APE__, "*************************************\n");

			   {
				   /*
				   setor de arquivo
				   */
				   
				   strcpy(whole_entry_i, oi_amanda_ptr->whole_entry_i);
				   strcpy(entry_______i, oi_amanda_ptr->entry______i );
				   
				   
				   if(I_MODE_IS_SCANFOLDER == amanda_mode)						
				   {
								   
						{
						 static char my_copy_of_filename_ar[1024];
						 strcpy(my_copy_of_filename_ar, valquiria_wide_to_utf8(ffd.cFileName));
						 strtolower_ar(my_copy_of_filename_ar);
						 {
							  bool achei_o_match = false;
							  const char *my_str_literal = global_patern_ar; //"* *.txt *.ini";
							  char *token, *str, *tofree;
							  tofree = str = strdup(my_str_literal);         // We own str's memory now.
							  while ((token = strsep(&str, " ")))
							  {
							   if (strlen(token))
							   {
								achei_o_match = strmatch(my_copy_of_filename_ar, token,
											    strlen(my_copy_of_filename_ar), strlen(token));
							   }
							   if (achei_o_match)
							   {
								break;
							   }
							  }
							  free(tofree);

							  if (false == true_if_include_i)
							  {
							   if (achei_o_match)
							   {
								achei_o_match = false;
							   }
							   else
							   {
								achei_o_match = true;
							   }
							  }

							  if (achei_o_match)
							  {                        
/*
							   strcpy(temp_del_entry_i, fixo_path_ar);
							   strcat(temp_del_entry_i, "\\");
							   strcat(temp_del_entry_i, final_file_or_folder_ar);
*/
						   							   
							   {
/*
								strcpy(dest_entry_i, global_temp_folder_i);
								strcat(dest_entry_i, "\\");
								strcat(dest_entry_i, final_file_or_folder_ar);
*/
								//if(check_temp_folder_passed_i(global_temp_folder_i, whole_entry_i))
								{
									/*
									 stripfilenameandpath(dest_entry_i, dir_out_entry_i, NULL);

									 rspmakedir_v2(dir_out_entry_i);
							
									 file_copy_i(temp_del_entry_i, dest_entry_i);
							
									 stripfilenameandpath(temp_del_entry_i, dir_out_entry_2_i, NULL);

									 set_folder_time(dir_out_entry_2_i, dir_out_entry_i);
									 */
								}

								if(is_update_i)
								{
									 
									 get_timestamp_arp(whole_entry_i, &s_arp_3, & VAL_data_i);
							 
									 attributes_i  =  GetFileAttributesW(
									  amanda_utf8towide_1_(whole_entry_i)
									  );

/*

  I will keep this for historical reasons...

  {

  int64_t a_i = -1;
  int     b_i = -1;

  if(a_i == b_i)
  {
	  
  }

  }
*/
									 if(INVALID_FILE_ATTRIBUTES != attributes_i)
									 {
									  ;
									 }
									 else
									 {
									  attributes_i = 0x20;						  
									 }
									 

			//					     [12608] temp_del_entry_i C:\Ava\back\extract_k\taglib-1.11.1\bindings\CMakeLists.txt  _amanda_debug_
			 
									 {

			#define THE_SIZE_I (1 << 17)

									  char * buf_i = malloc(THE_SIZE_I);
									  __attribute__((unused)) int len_i;
									  FILE * the_file_i;

									  the_file_i = _wfopen(amanda_utf8towide_1_(whole_entry_i), L"rb");
									  
									  if(the_file_i)
									  {
										  check_item_z_june_24(entry_______i);
										  add_more_one_z_june_24
										  (
											   atime_i                         ,
											   mtime_i                         ,
											   ctime_i                         ,
											   getfilesize_ar(whole_entry_i),
											   _ftelli64(my___temp_file_i)     ,
											   entry_______i         ,
											   false                           ,
											   true                            ,
											   attributes_i);
											   size_i = 0;							   
											   while((len_i = fread(buf_i, 1, THE_SIZE_I, the_file_i)))
											   {
												   ;
												   if((fwrite(buf_i, 1, len_i, my___temp_file_i)) != (size_t)len_i)
												   {
													   fatal_exit_k = 12345100;
												   }
												   size_i += len_i;
											   }
																			   
											   fclose(the_file_i);
									  }
									  else
									  {
										  files_that_cannot_be_read_update++;//precisa melhorar isto e mostrar uma lista de arquivos que nao puderam ser lidos...
									  }
									  
									  free(buf_i);
									 }
									 
								}
								
							   }
							  }
						 }
							 
						}
						

				   }
				   
				   
				   
			   }

               /*

oi_amanda_ptr->entry______i  -- entrada
oi_amanda_ptr->whole_entry_i -- com diretorio

*/
          }

          //porque nao amor?...da pelo menos pra testar isto

     entrada_again_smart_ape_from_amanda:;

          if (1 == 0)
          {
               goto entrada_again_smart_ape_from_amanda;
          }

     } while (FindNextFileW(oi_amanda_ptr->current_hFind_amanda_s_smart_____ape, &ffd) != 0);

exit_me_forced_amanda_s_smart_ape:;

     pedro_dprintf(IS_DEBUG_APE__, "endereco da struct na saida %p\n", oi_amanda_ptr);

     pedro_dprintf(-1, "previous %p\n", oi_amanda_ptr->previous_amanda_s_smart_ape);

     FindClose(oi_amanda_ptr->current_hFind_amanda_s_smart_____ape);

keep_running_amanda_s_smart_ape:; //one less bug..

     if (oi_amanda_ptr_inicial != oi_amanda_ptr)
     {

          pedro_dprintf(IS_DEBUG_APE__, "nao é tem que processar\n");
          //vamos lá...debugar isto bem amor... /* here for historical reasons 

          assert(NULL != oi_amanda_ptr->previous_amanda_s_smart_ape);

          pedro_dprintf(IS_DEBUG_APE__, "free on %x\n", oi_amanda_ptr);
          
          to_call_free______amanda_s_smart_ape = oi_amanda_ptr;

          oi_amanda_ptr = oi_amanda_ptr->previous_amanda_s_smart_ape;

          free(to_call_free______amanda_s_smart_ape);

          pedro_dprintf(IS_DEBUG_APE__, "novo endereco de oi_amanda_ptr %x\n", oi_amanda_ptr);

          goto entrada_again_smart_ape_from_amanda;
     }

     pedro_dprintf(-1, "free final on %x\n", oi_amanda_ptr);
     free(oi_amanda_ptr);

no_entries_i:;

     return 0;
}

//////////////////////////////////////////////////////////////////////////////////////