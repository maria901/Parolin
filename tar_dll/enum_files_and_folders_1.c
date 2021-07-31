
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

#define IS_DEBUG_APE__ /* kkkkkkkkkkkk */ (100001)
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

int amanda_s_smart_ape(__attribute__((unused)) char *initial_path_amanda_s_smart_ape,
                       bool recurse_on_subfolders_amanda_s_smart_ape)
{

     struct oi_amanda *oi_amanda_ptr = calloc(1, sizeof(struct oi_amanda));

     struct oi_amanda *oi_amanda_ptr_inicial = oi_amanda_ptr;

     struct oi_amanda *to_call_free______amanda_s_smart_ape;

     WIN32_FIND_DATA ffd   ;
     char szDir      [1027];
     char szDir_i    [1027];
     char lpcszFolder[1027];

     // keeping this here int debug_counter_amanda_s_smart_ape = 8;

     strcpy(lpcszFolder, "C:\\Ava\\back\\test_i");

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
     oi_amanda_ptr->current_hFind_amanda_s_smart_____ape = FindFirstFileA(szDir, &ffd);

     if (INVALID_HANDLE_VALUE == oi_amanda_ptr->current_hFind_amanda_s_smart_____ape)
     {
          pedro_dprintf(0, "INVALID_HANDLE_VALUE\n");
          pedro_dprintf(0, "path %s\n", szDir);
          if (oi_amanda_ptr == oi_amanda_ptr_inicial)
          {
               pedro_dprintf(0, "free forçado final on %x\n", oi_amanda_ptr);
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
               if ('.' != ffd.cFileName[0])
               {
 

                    ; //do
                    pedro_dprintf(-1, "dir  -> %s\n", ffd.cFileName);

                    if (INVALID_HANDLE_VALUE == oi_amanda_ptr->parent_hFind_amanda_s_smart______ape)
                    {
                         strcpy(oi_amanda_ptr->entry______i, ffd.cFileName);
                    }
                    else
                    {
                         strcpy(oi_amanda_ptr->entry______i, oi_amanda_ptr->whole_entry_above_i);
                         strcat(oi_amanda_ptr->entry______i, "\\");
                         strcat(oi_amanda_ptr->entry______i, ffd.cFileName);
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

                    pedro_dprintf(IS_DEBUG_APE__, "dir %s\n", oi_amanda_ptr->entry______i);
                    pedro_dprintf(IS_DEBUG_APE__, "dir %s\n", oi_amanda_ptr->whole_entry_i);
                    pedro_dprintf(IS_DEBUG_APE__, "*************************************\n");

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
                    pedro_dprintf(-1, ". ou .. \n");
                    continue;
               }
          }
          else
          {

               pedro_dprintf(-1, "file -> %s\n", ffd.cFileName);

               if (INVALID_HANDLE_VALUE == oi_amanda_ptr->parent_hFind_amanda_s_smart______ape)
               {
                    strcpy(oi_amanda_ptr->entry______i, ffd.cFileName);
               }
               else
               {
                    strcpy(oi_amanda_ptr->entry______i, oi_amanda_ptr->whole_entry_above_i);
                    strcat(oi_amanda_ptr->entry______i, "\\");
                    strcat(oi_amanda_ptr->entry______i, ffd.cFileName);
               }

               strcpy(szDir_i, lpcszFolder);
               strcat(szDir_i, "\\");
               strcat(szDir_i, oi_amanda_ptr->entry______i);

               strcpy(oi_amanda_ptr->whole_entry_i, szDir_i);

               pedro_dprintf(IS_DEBUG_APE__, "oi_amanda_ptr->current_hFind_amanda_s_smart_____ape == %x\n", oi_amanda_ptr->current_hFind_amanda_s_smart_____ape);

               pedro_dprintf(IS_DEBUG_APE__, "file %s\n", oi_amanda_ptr->entry______i);
               pedro_dprintf(IS_DEBUG_APE__, "file %s\n", oi_amanda_ptr->whole_entry_i);
               pedro_dprintf(IS_DEBUG_APE__, "*************************************\n");

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

     } while (FindNextFileA(oi_amanda_ptr->current_hFind_amanda_s_smart_____ape, &ffd) != 0);

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

     pedro_dprintf(0, "free final on %x\n", oi_amanda_ptr);
     free(oi_amanda_ptr);

no_entries_i:;

     return 0;
}

//////////////////////////////////////////////////////////////////////////////////////