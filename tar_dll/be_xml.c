
//not complete... works only for simple read and write XML process, more code need to
//be added when possible

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

#include  <windows.h>
#include   <stdint.h>
#include    <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include     <time.h>
#include    <errno.h>
#include    <fcntl.h>
#include    <ctype.h>
#include     <math.h>
#include   <wctype.h>
#include    <wchar.h>
#include   <stdarg.h>
#include   <stddef.h>
#include   <setjmp.h>
#include   <locale.h>
#include   <signal.h>
#include   <limits.h>
#include    <float.h>
#include   <iso646.h>

#undef NDEBUG
#include   <assert.h>

#include  <stdbool.h>

enum feline_modes
  {

    FELINE_MODE_NORMAL,
    FELINE_MODE_DELETE_ROOT,
    FELINE_MODE_DELETE_NODE
    
  };

enum funny_mode
  {
    FELINE_MODE_INCLUDE_ = 1001,
    FELINE_MODE_EXCLUDE_       ,
  };

static int write_mode_feline = FELINE_MODE_NORMAL;

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
 );

#define Z_DEBUG

static int     lines_count_feline   ;
static int     valid_position_feline;
static int     root_position_feline ;
static int      item_position_feline;

enum
{
	MODE_IS_REPLACE__,
	MODE_IS_COUNT__,
};

/**
 * Function to replace or count the occurrences of the input string
 *
 * @param mode it is MODE_IS_REPLACE__ for string replace, only<br>
 * this mode for the moment
 * 
 *
 */
static int
replace_or_count_stringsensitive_arab (int mode, char *data, int datalen,
                                       char *search_string,
                                       int search_string_len, char *replace,
                                       int replace_len, int *count,
                                       char **output_string, int *output_len)
{
  int q;
  char *final = ((void *) 0);
  int ret;
  int sizeret;
  int deslocador = 0;
  int len = datalen;
  int size__ = 0;
  double a;
  double adest;
  double asrc;
  int i;
  int p;
  *output_len = 0;
  if (count)
    {
      *count = 0;
    }
  adest = (double) replace_len;
  if (0 == search_string_len)
    {
      asrc = (double) 1;
    }
  else
    {
      asrc = (double) search_string_len;
    }
  a = adest / asrc;
  size__ = (int) ceil (a);
  size__++;
  if (MODE_IS_REPLACE__ == mode)
    {
      final = calloc ((len * size__) + 10000, 1);//it had a bug here for 20 years...
      *output_string = final;
      if (NULL == final)
	{
	  return -1;
	}
    }

  ret = len;
  sizeret = search_string_len;
	
  if (sizeret > ret)
  {
       if (MODE_IS_REPLACE__ == mode)
       {
		
	    memcpy(*output_string, data, datalen);
	    (*output_string)[datalen] = 0;
	    *output_len = datalen;
	 
       }
       return 0;
  }

  for(i=0; i<datalen; i++)
    {
      if(data[i]==search_string[0])
	{
	  {
	    int deslocasize=i;
	 
	    for(p=0; p<search_string_len; p++)
	      {
		if(datalen<=deslocasize)
		  {
		    goto naoachou;
		  }
		if(data[deslocasize++]!=search_string[p])
		  {
		    goto naoachou;
		  }
	      }
			
	    for(q=0; q<replace_len; q++)
	      {				
		final[deslocador++]=replace[q];
	      }
	    i+=search_string_len-1;
	    goto vai;
	  naoachou:
	    ;
	  }
	  final[deslocador++]=data[i];
	}
      else
	{
	  final[deslocador++]=data[i];
	} vai :
      ;
    }
  final[deslocador]=0;
  *output_len=deslocador;
  ;
  return 0;
}
static int stringreplace(char *data,int data_len
                         ,char*search,
                         int searchlen,
                         char*replace,
                         int replacelen,
                         int*out_len,char**outdata)
{
	int ret;
	int count;
	ret = replace_or_count_stringsensitive_arab (MODE_IS_REPLACE__,
	                                             data,
	                                             data_len, search,
	                                             searchlen, replace, replacelen, &count,
	                                             outdata, out_len);
	return ret;
}

static int decode_data_feline(char * inputdata_feline, char *data_feline)
{
  int   out_len2           = 0   ;
  char *outdata2           = NULL;
  char *outdata3           = NULL;
  char *outdata4           = NULL;
  char *outdata5           = NULL;
  char *outdata_a_feline   = NULL;
  char *outdata_b_feline   = NULL;  
  char search              [ 300];
  char replace             [ 300];
  int returnvalue          =    0;
  
  strcpy(search,          "&gt;");
  strcpy(replace,            ">");
  stringreplace(inputdata_feline, strlen(inputdata_feline)
		, search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len2, &outdata_a_feline);
  if (NULL == outdata_a_feline)
    {
      returnvalue = 1;
      goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
  strcpy(search,"&lt;");
  strcpy(replace,"<");
  stringreplace(outdata_a_feline, strlen(outdata_a_feline)
		, search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len2, &outdata_b_feline);
  if (NULL == outdata_b_feline)
    {
      returnvalue = 1;
      goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
  strcpy(search,"&#13;");
  strcpy(replace,"\r");
  stringreplace(outdata_b_feline, strlen(outdata_b_feline)
		, search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len2, &outdata2);
  if (NULL == outdata2)
    {
      returnvalue = 1;
      goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
  strcpy(search,"&#10;");
  strcpy(replace,"\n");
  stringreplace(outdata2, out_len2
		, search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len2, &outdata3);
  if (NULL == outdata3)
    {
      returnvalue = 1;
      goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
  strcpy(search,"&#0;");
  replace[0] = 0;
  stringreplace(outdata3, out_len2
		, search,
		strlen(search),
		replace,
		1,
		&out_len2, &outdata4);
  if (NULL == outdata4)
    {
      returnvalue = 1;
      goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
  strcpy(search,"&amp;");
  strcpy(replace,"&");
  (void)stringreplace(outdata4, out_len2
		      , search,
		      strlen(search),
		      replace,
		      strlen(replace),
		      &out_len2, &outdata5);
  if (NULL == outdata5)
    {
      returnvalue = 1;
      goto saida;
    }
  /////////////////////////////////////////////////////////////////////////

  strcpy(data_feline , outdata5);

 saida:
  ;
  if(outdata_a_feline)
    {
      free(outdata_a_feline);
    }
  if(outdata_b_feline)
    {
      free(outdata_b_feline);
    }
  if(outdata2)
    free (outdata2);
  if(outdata3)
    free (outdata3);
  if(outdata4)
    free (outdata4);
  if(outdata5)
    free (outdata5);
  return returnvalue;
}

static int encode_data_feline(char * input_data_feline, char * output_data_feline)
{
  int   out_len                                     =     0;
  char *outdata                                     =  NULL;
  char *outdata2                                    =  NULL;
  char *outdata3                                    =  NULL;
  char *outdata4                                    =  NULL;
  char *outdata_a_feline = NULL, *outdata_b_feline  =  NULL;
  char  search                                      [  300];
  char  replace                                     [  300];
  int   returnvalue                                 =     0;
  /////////////////////////////////////////////////////////////////////////
  strcpy(search,                                       "&");
  strcpy(replace,                                  "&amp;");
  stringreplace(input_data_feline,
		strlen(input_data_feline)
		, search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len, &outdata);
  if (NULL == outdata)
    {
      returnvalue =1; goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
  search[0]=0;
  strcpy(replace,"&#0;");
  stringreplace(outdata,out_len
		,search,
		1,
		replace,
		strlen(replace),
		&out_len,&outdata2);
  if (NULL == outdata2)
    {
      returnvalue =1; goto saida;
    }
  /////////////////////////////////////////////////////////////////////////////
  search[0]='\n';
  strcpy(replace,"&#10;");
  stringreplace(outdata2,out_len
		,search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len,&outdata3);
  if (NULL == outdata3)
    {
      returnvalue =1; goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
  search[0]='\r';
  strcpy(replace,"&#13;");
  stringreplace(outdata3,out_len
		,search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len,&outdata4);
  if (NULL == outdata4)
    {
      returnvalue =1; goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
   search[0]='>';
  strcpy(replace,"&gt;");
  stringreplace(outdata4,out_len
		,search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len, &outdata_a_feline);
  if (NULL == outdata_a_feline)
    {
      returnvalue = 1; goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
  search[0]='<';
  strcpy(replace,"&lt;");
  stringreplace(outdata_a_feline,out_len
		,search,
		strlen(search),
		replace,
		strlen(replace),
		&out_len,&outdata_b_feline);
  if (NULL == outdata_b_feline)
    {
      returnvalue = 1; goto saida;
    }
  /////////////////////////////////////////////////////////////////////////
 
  strcpy(output_data_feline, outdata_b_feline);
 saida:
  ;
  if(outdata_a_feline)
    {
      free(outdata_a_feline);
    }
  if(outdata_b_feline)
    {
      free(outdata_b_feline);
    }
  if(outdata2)
    free (outdata2);
  if(outdata3)
    free (outdata3);
  if(outdata4)
    free (outdata4);
  return returnvalue;
}

/**
 * Function to replace a string in Windows, developed by me 24 years ago and the
 * bug was fixed during these years, now the number of bugs inside is low
 *
 */
static void amandaricardo_pereira_koci_string_replace(char*          data_feline,
					       char* search_string_feline,
					       char*    dest_string_feline
					       )
{
  int g;
  int p;
  int i;
  int size_of_dest  =   strlen(dest_string_feline);
  int size_of_search= strlen(search_string_feline);
	int size_of_data  =          strlen(data_feline);
	int data_position =                            0;
	char *data_large                                ;
	double asrc;
	double a;
	int size__;
	if (0 == size_of_search)
	{
		asrc = 1.;
	}
	else
	{
		asrc = (double) size_of_search;
	}
	a = size_of_dest / asrc;
	size__ = (int) ceil (a);
	data_large = calloc ((size_of_data * size__) + 1 + 100000, 1);//possible bug here...amanda
	for(i=0; i<size_of_data; i++)
	{
		if(data_feline[i] == search_string_feline[0])
		{
			int desloca                     = i;
			for(p = 0; p<size_of_search;    p++)
			{
				if(0==data_feline[ desloca])
				{
					goto    jump_inside;
				}
				if(data_feline[desloca++]!=search_string_feline[p])
				{
					goto    jump_inside;
				}
			}
		
			for(g = 0; g < size_of_dest; g++)
			{
				data_large[data_position] = dest_string_feline[g];
				data_position++;
			}
			i+=size_of_search-1;
		}
		else
		{
jump_inside:
			;
			data_large[data_position++]=data_feline[i];
		}
	}
	data_large[data_position]=0;
	/*
	if(100000<strlen(data_large))
	{
		printf("Erro 1015: Tamanho de entradas superior a 100000 bytes, terminando o programa, contate o programador e mande um printscreen");
		exit(25);
	}
	*/
	strcpy(data_feline, data_large);
	free(data_large);
	return;
}

static int replacestringsensitive2_feline(char *comando, char *source, char *dest)
{	
	amandaricardo_pereira_koci_string_replace(comando,   source, dest);
	return -27;
}

/**
 * To convert a utf-8 encoded filename to a wide string (WCHAR *)
 *
 * @param pUTF8 the input utf-8 encoded filename
 *
 * @return the static allocated WCHAR array with the filename as wide string
 *
 */
static WCHAR * amanda_utf8towide_1_(char *pUTF8)
{
	static WCHAR ricardo_k[1024];
	MultiByteToWideChar (CP_UTF8, 0, (LPCSTR) pUTF8, -1, ricardo_k, 1024);
	return ricardo_k;
}

/**
 * To remove the initial spaces including \r \n and \t
 *
 */
static void removespace_begin(char *path)
{
	int ret;
	char *ptr;
	char *ptrdesloca;
	ptrdesloca = path;
	ret = strlen(path);
	if (ret)
	{
		ptr = malloc(ret + 1);
		memset(ptr, 0, ret + 1);
		while ((*ptrdesloca == ' ') || (*ptrdesloca == '\r') || (*ptrdesloca == '\n') || (*ptrdesloca == '\t'))
		{
			ptrdesloca++;
		}
		strcpy(ptr, ptrdesloca);
		memset(path, 0, ret);
		strcpy(path, ptr);
		free(ptr);
	}
}
/**
 * To remove the end of string spaces including \r \n and \t
 *
 */
/*
static void removespace_end(char *path)
{
	int ret;
inicio:
	ret = strlen(path);
	if (ret)
	{
		if ((path[(ret - 1)] == ' ') || (path[(ret - 1)] == '\r') || (path[(ret - 1)] == '\n') || (path[(ret - 1)] == '\t'))
		{
			path[(ret - 1)] = 0;
			goto inicio;
		}
	}
}
*/
/**
 * Function to get our modified and limited xml implemented file... in 2021
 *
 * @param filename_utf8_feline the XML file as utf-8
 *
 * \param attribute_____feline the attibute to get, not implemented...but will in a near future
 *
 * @param node__________feline the node
 *
 * @param out_data______feline the output char * need to have space enough for the data
 * or an memory access error can occur
 *
 * @return 0 if no error, 1 if XML file is not valid, 2 if root not found
 *
 */
int feline_read_xml(char * filename_utf8_feline,
		    char * root__________feline,
		    char * node__________feline,
			__attribute__((unused)) char * attribute_____feline,
		    char * out_data______feline
		    )
{
  char * node__________feline_copy_a  ;
  char * node__________feline_copy_b  ;
  char * root__________feline_copy_a  ;
  bool   already_feline        = false;
  bool   is_valid_feline       = false;
  bool   root_found_feline     = false;
  int    xml_file_size_feline         ;
  int    returnvalue_feline    =     0;
  char * pointer_feline               ;
  char * pointer_2_feline             ;
  char * line_buf_feline              ;
  FILE * my_file_feline               ;
  FILE * compiler_happy_feline =  NULL;

  lines_count_feline    = -1 ;
  valid_position_feline = -1 ;
  root_position_feline  = -1 ;
  item_position_feline  = -1 ;

  if(NULL != out_data______feline)
  out_data______feline[0] = 0;

  root__________feline_copy_a = calloc(1, strlen(root__________feline) + 3);

  strcpy(root__________feline_copy_a, "<"                                 );
  strcat(root__________feline_copy_a, root__________feline                );
  strcat(root__________feline_copy_a, ">"                                 );
  
  node__________feline_copy_a = calloc(1, strlen(node__________feline) + 3);
  node__________feline_copy_b = calloc(1, strlen(node__________feline) + 4);
  
  strcpy(node__________feline_copy_a, "<"                                 );
  strcat(node__________feline_copy_a, node__________feline                );
  strcat(node__________feline_copy_a, ">"                                 );
  strcpy(node__________feline_copy_b, "</"                                );
  strcat(node__________feline_copy_b, node__________feline                );
  strcat(node__________feline_copy_b, ">"                                 );
  
  my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline)
			   ,L"rb"
			   );

  if(compiler_happy_feline == my_file_feline && compiler_happy_feline == my_file_feline)//as you can see the developer need to do things that can be embarassing
    {
      goto next_feline;
    }
  
 next_feline:;
  
  if(my_file_feline)
    {
      //mr. Do

      fseek(my_file_feline, 0,                            SEEK_END);
      xml_file_size_feline  =  ftell(               my_file_feline);
      fseek(my_file_feline, 0,                            SEEK_SET);

      line_buf_feline       = calloc(1,   xml_file_size_feline + 1);
      
      while(fgets(line_buf_feline, xml_file_size_feline, my_file_feline))
	{
	
	  if(0 == ftell(my_file_feline))
	    {
	      break;
	    }

	  if(-1 == lines_count_feline)
	    {
	      lines_count_feline = 0;
	    }

	  lines_count_feline++;
	  replacestringsensitive2_feline(line_buf_feline, "\r",                "");
	  replacestringsensitive2_feline(line_buf_feline, "\n",                "");
	  if(strlen(line_buf_feline))
	    {
	      removespace_begin(line_buf_feline                                  );
	      if(false == is_valid_feline)
		{
		  pointer_feline = strstr(line_buf_feline                         ,
					  "<?xml version=\"1.0\"?>"
					  );
		  if(pointer_feline)
		    is_valid_feline = true, valid_position_feline = lines_count_feline;
		}
	      else
		{
		  if(false == root_found_feline)
		    {
		      pointer_feline = strstr(line_buf_feline                         ,
					      root__________feline_copy_a
					      );
		      if(pointer_feline)
			root_found_feline = true, root_position_feline = lines_count_feline       ;
		    }
		  else
		    {
		      pointer_feline =  strstr(line_buf_feline, node__________feline_copy_a      );

		      if(pointer_feline && false == already_feline)
			{
			  already_feline = true;
			 
			  pointer_feline += strlen(node__________feline_copy_a                   );
			  
			  pointer_2_feline = strstr(pointer_feline,   node__________feline_copy_b);

			  if(pointer_2_feline)
			    {
			      pointer_2_feline[0]                                              = 0;
			    }
			  
			  if(NULL != out_data______feline                                            )
			    strcpy(out_data______feline,                              pointer_feline);

			  item_position_feline = lines_count_feline;
			 
			}		      
		    }
		}
	    }
	}

      free(line_buf_feline);
     
      fclose(my_file_feline);
    }
  else
    {
      returnvalue_feline = 3;
    }
  free(root__________feline_copy_a);
  free(node__________feline_copy_a);
  free(node__________feline_copy_b);

  if(3 == returnvalue_feline)
    {
      return 1;//Not a valid XML file
    }
  
  if(false == is_valid_feline)
    {
      return 1;//Not a valid XML file
    }

  if(false == root_found_feline)
    {
      return 2;//Root not found
    }

  if(NULL != out_data______feline)
    {
      
      decode_data_feline(out_data______feline, out_data______feline);
      
    }
  
  return 0;// Ok my love
}

/**
 * Function to write XML file
 *
 * @param filename_utf8_feline the XML file...
 *
 * @param root__________feline the root, if it don�t exist it will be created
 *
 * @param node__________feline the node, if it don�t exist it will be created
 *
 * @param attribute_____feline the attibute, not in use in this version but will in
 * the future
 *
 * @ in_data_______feline_     the input data to convert and save to the not standard
 * XML file
 *
 * @return 0 if no error, 1 if cannot write to the XML file or if the path is invalid
 *
 */
int feline_write_xml(char * filename_utf8_feline,
		     char * root__________feline,
		     char * node__________feline,
		     __attribute__((unused)) char * attribute_____feline,
		     char * in_data_______feline_
		     )
{
  bool   did_arp               = false;
  int    internal_mode_feline         ;
  int    returnvalue_feline    =     0;
  int    ret_arp                      ;
  int    xml_file_size_feline         ;
  char   signature_feline[] =  "<?xml version=\"1.0\"?>\n";
  char * line_buf_feline              ;
  char * line_buf_2_feline            ;
  char * in_data_______feline         ;
  char   adjusted_root_feline_a[ 1027];
  char   adjusted_root_feline_b[ 1027];
  char   adjusted_node_feline_a[ 1027];
  char   item_feline           =     0;
 
  FILE * my_file_feline               ;
  
  in_data_______feline = calloc(1, 20000); //limited to 10000 per entry... if you want modify it
  strncpy(in_data_______feline, in_data_______feline_, 9999);

  encode_data_feline(in_data_______feline, in_data_______feline);
  
  ret_arp = feline_read_xml(filename_utf8_feline,//nao muda mais, por favor
				    root__________feline,
				    node__________feline,
				    NULL/*for the moment*/,
				    NULL
				 );
  
  if(FELINE_MODE_DELETE_NODE == write_mode_feline)
    {
 
      if(-1 != valid_position_feline)
	{

	  strcpy(adjusted_root_feline_a, "<");
	  strcat(adjusted_root_feline_a, root__________feline);
	  strcat(adjusted_root_feline_a, ">");

	  strcpy(adjusted_root_feline_b, "</");
	  strcat(adjusted_root_feline_b, root__________feline);
	  strcat(adjusted_root_feline_b, ">");

	  strcpy(adjusted_node_feline_a, "<");
	  strcat(adjusted_node_feline_a, node__________feline);
	  strcat(adjusted_node_feline_a, ">");
	  	  
	  my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				   L"rb"
				   );
	  if(my_file_feline)
	    {
	      fseek(my_file_feline, 0,                            SEEK_END);
	      xml_file_size_feline  =  ftell(               my_file_feline);

	      if(xml_file_size_feline)
		{
		  fseek(my_file_feline, -1,                            SEEK_END);
		  fread(&item_feline, 1, 1, my_file_feline);
		}
	 
	      fseek(my_file_feline, 0,                            SEEK_SET);

	      line_buf_feline       = calloc(1,   xml_file_size_feline + 1);
	      line_buf_2_feline     = calloc(1,   xml_file_size_feline + (strlen(node__________feline)*2)+ 5 +
					     strlen(in_data_______feline) + 1000);//it is enough I supose, as usual...
	      lines_count_feline = 0;

	      internal_mode_feline = FELINE_MODE_INCLUDE_;
	      
	      while(fgets(line_buf_feline, xml_file_size_feline, my_file_feline))
		{
		  if(0 == ftell(my_file_feline))
		    {
		      break;
		    }
		  did_arp = true;
		  lines_count_feline++;

		  replacestringsensitive2_feline(line_buf_feline, "\r",                "");
		  replacestringsensitive2_feline(line_buf_feline, "\n",                "");


		  if(strstr(line_buf_feline, adjusted_root_feline_a) )
		    {
		      internal_mode_feline = FELINE_MODE_EXCLUDE_;
		    }
		 		  
		  if(FELINE_MODE_INCLUDE_ == internal_mode_feline)
		    {
		      strcat(line_buf_2_feline, line_buf_feline           );
		      strcat(line_buf_2_feline, "\n"                      );
		    }
		  else if(FELINE_MODE_EXCLUDE_ == internal_mode_feline)
		    {

		      if(strstr(line_buf_feline, adjusted_node_feline_a) )
			{
			}
		      else
			{
			  strcat(line_buf_2_feline, line_buf_feline           );
			  strcat(line_buf_2_feline, "\n"                      );
			}
		      ;//FOR your pleasure...
		    }

		   if(strstr(line_buf_feline, adjusted_root_feline_b) )
		    {
		      internal_mode_feline = FELINE_MODE_INCLUDE_;
		    }
	   }

	 if(did_arp)
	   {
	     line_buf_2_feline[strlen(line_buf_2_feline) - 1] = 0;//to remove last \n
	   }

	 if(10 == item_feline)
	   {
	     strcat(line_buf_2_feline, "\n");
	   }
	 
	 if(NULL == line_buf_2_feline && NULL != line_buf_2_feline)
	   {
	     return 27;
	   }
	 	
	 fclose(my_file_feline );

	 my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				  L"wb"
				  );

	 if(my_file_feline)
	   {
	     fwrite(line_buf_2_feline, 1, strlen(line_buf_2_feline), my_file_feline);
	     fclose(my_file_feline);
	     my_file_feline   = NULL;
	   }
	 free(line_buf_feline  );
	 free(line_buf_2_feline);

	 goto saida_feline;
       }
     else
       {
	 returnvalue_feline = 1; //Cannot open xml file to write
	 goto saida_feline;
       }
 
	}
      

      goto saida_feline     ;
    }

  if(FELINE_MODE_DELETE_ROOT == write_mode_feline)
    {
 
      if(-1 != valid_position_feline)
	{

	  strcpy(adjusted_root_feline_a, "<");
	  strcat(adjusted_root_feline_a, root__________feline);
	  strcat(adjusted_root_feline_a, ">");

	  strcpy(adjusted_root_feline_b, "</");
	  strcat(adjusted_root_feline_b, root__________feline);
	  strcat(adjusted_root_feline_b, ">");
	  
	  my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				   L"rb"
				   );
	  if(my_file_feline)
	    {
	      fseek(my_file_feline, 0,                            SEEK_END);
	      xml_file_size_feline  =  ftell(               my_file_feline);

	      if(xml_file_size_feline)
		{
		  fseek(my_file_feline, -1,                            SEEK_END);
		  fread(&item_feline, 1, 1, my_file_feline);
		}
	 
	      fseek(my_file_feline, 0,                            SEEK_SET);

	      line_buf_feline       = calloc(1,   xml_file_size_feline + 1);
	      line_buf_2_feline     = calloc(1,   xml_file_size_feline + (strlen(node__________feline)*2)+ 5 +
					     strlen(in_data_______feline) + 1000);//it is enough I supose
	      lines_count_feline = 0;

	      internal_mode_feline = FELINE_MODE_INCLUDE_;
	      
	      while(fgets(line_buf_feline, xml_file_size_feline, my_file_feline))
		{
		  if(0 == ftell(my_file_feline))
		    {
		      break;
		    }
		  did_arp = true;
		  lines_count_feline++;

		  replacestringsensitive2_feline(line_buf_feline, "\r",                "");
		  replacestringsensitive2_feline(line_buf_feline, "\n",                "");

		  if(strstr(line_buf_feline, adjusted_root_feline_a) )
		    {
		      internal_mode_feline = FELINE_MODE_EXCLUDE_;//fica salvo ate que ache o fim
		    }
		 		  
		  if(FELINE_MODE_INCLUDE_ == internal_mode_feline)
		    {
		      strcat(line_buf_2_feline, line_buf_feline           );
		      strcat(line_buf_2_feline, "\n"                      );
		    }
		  else if(FELINE_MODE_EXCLUDE_ == internal_mode_feline)
		    {
		      ;//FOR your pleasure
		    }

		   if(strstr(line_buf_feline, adjusted_root_feline_b) )
		    {
		      internal_mode_feline = FELINE_MODE_INCLUDE_;//habilita novamente a adi��o
		    }
	   }

	 if(did_arp)
	   {
	     line_buf_2_feline[strlen(line_buf_2_feline) - 1] = 0;//to remove last \n
	   }

	 if(10 == item_feline)
	   {
	     strcat(line_buf_2_feline, "\n");
	   }
	 
	 if(NULL == line_buf_2_feline && NULL != line_buf_2_feline)
	   {
	     return 27;
	   }

	 fclose(my_file_feline );

	 my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				  L"wb"
				  );

	 if(my_file_feline)
	   {
	     fwrite(line_buf_2_feline, 1, strlen(line_buf_2_feline), my_file_feline);
	     fclose(my_file_feline);
	     my_file_feline   = NULL;
	   }
	 free(line_buf_feline  );
	 free(line_buf_2_feline);

	 goto saida_feline;
       }
     else
       {
	 returnvalue_feline = 1; //Cannot open xml file to write
	 goto saida_feline;
       }

	}

      goto saida_feline     ;
    }
  
 if(-1 == valid_position_feline)
   {

     if(3 == ret_arp)
       {
	 my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				  L"wb"
				  );
       }
     else
       {
	 my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				  L"ab"
				  );
       }

	 if(my_file_feline)
	   {

	     fwrite(signature_feline, 1, strlen(signature_feline), my_file_feline);
	     fwrite("<", 1, 1, my_file_feline);
	     fwrite(root__________feline, 1, strlen(root__________feline), my_file_feline);
	     fwrite(">\n", 1, 2, my_file_feline);
	     fwrite("    ", 1, 4, my_file_feline);
	     fwrite("<", 1, 1, my_file_feline);
	     fwrite(node__________feline, 1, strlen(node__________feline), my_file_feline);
	     fwrite(">", 1, 1, my_file_feline);

	     //aqui converte a string...
	     fwrite(in_data_______feline, 1, strlen(in_data_______feline), my_file_feline);
	     fwrite("</", 1, 2, my_file_feline);
	     fwrite(node__________feline, 1, strlen(node__________feline), my_file_feline);
	     fwrite(">\n", 1, 2, my_file_feline);
	     fwrite("</", 1, 2, my_file_feline);
	     fwrite(root__________feline, 1, strlen(root__________feline), my_file_feline);
	     fwrite(">\n", 1, 2, my_file_feline);
	     fclose(my_file_feline);
	     my_file_feline  = NULL;
	     goto saida_feline     ;
	   }
	 else
	   {
	     returnvalue_feline = 1; //Cannot open xml file to write
	     goto saida_feline     ;
	   }
   }

 if(-1 != root_position_feline && -1 == item_position_feline)
   {
  
     my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
			      L"rb"
			      );
     if(my_file_feline)
       {
	 fseek(my_file_feline, 0,                            SEEK_END);
	 xml_file_size_feline  =  ftell(               my_file_feline);

	 if(xml_file_size_feline)
	   {
	     fseek(my_file_feline, -1,                            SEEK_END);
	     fread(&item_feline, 1, 1, my_file_feline);
	   }
	 
	 fseek(my_file_feline, 0,                            SEEK_SET);

	 line_buf_feline       = calloc(1,   xml_file_size_feline + 1);
	 line_buf_2_feline     = calloc(1,   xml_file_size_feline + (strlen(node__________feline)*2)+ 5 +
					strlen(in_data_______feline) + 1000);//it is enough I supose
	 lines_count_feline = 0;
	 
	 while(fgets(line_buf_feline, xml_file_size_feline, my_file_feline))
	   {
	     if(0 == ftell(my_file_feline))
	       {
	   
		 break;
	       }
	     did_arp = true;
	     lines_count_feline++;

	     replacestringsensitive2_feline(line_buf_feline, "\r",                "");
	     replacestringsensitive2_feline(line_buf_feline, "\n",                "");

	     strcat(line_buf_2_feline, line_buf_feline           );
	     strcat(line_buf_2_feline, "\n"                      );

	     if(lines_count_feline == root_position_feline        )
	       {

		 strcat(line_buf_2_feline, "    "                );
		 strcat(line_buf_2_feline, "<"                   );
		 strcat(line_buf_2_feline,
			node__________feline);
		 strcat(line_buf_2_feline, ">"                   );

	     //aqui converte a string...
		 strcat(line_buf_2_feline,   in_data_______feline);
		 strcat(line_buf_2_feline,                   "</");
		 strcat(line_buf_2_feline,   node__________feline);
		 strcat(line_buf_2_feline,">\n"                  );
		 
	       }
	     
	   }

	 if(did_arp)
	   {
	     line_buf_2_feline[strlen(line_buf_2_feline) - 1] = 0;//to remove last \n
	   }

	 if(10 == item_feline)
	   {
	     strcat(line_buf_2_feline, "\n");
	   }
	 
	 if(NULL == line_buf_2_feline && NULL != line_buf_2_feline)
	   {
	     return 27;
	   }
	
	 fclose(my_file_feline );

	 my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				  L"wb"
				  );

	 if(my_file_feline)
	   {
	     fwrite(line_buf_2_feline, 1, strlen(line_buf_2_feline), my_file_feline);
	     fclose(my_file_feline);
	     my_file_feline   = NULL;
	   }
	 free(line_buf_feline  );
	 free(line_buf_2_feline);

	 goto saida_feline;
       }
     else
       {
	 returnvalue_feline = 1; //Cannot open xml file to write
	 goto saida_feline;
       }

   }

 if(-1 != root_position_feline && -1 != item_position_feline)
   {
 
     my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
			      L"rb"
			      );
     if(my_file_feline)
       {
	 fseek(my_file_feline, 0,                            SEEK_END);
	 xml_file_size_feline  =  ftell(               my_file_feline);

	 if(xml_file_size_feline)
	   {
	     fseek(my_file_feline, -1,                            SEEK_END);
	     fread(&item_feline, 1, 1, my_file_feline);
	   }
	 
	 fseek(my_file_feline, 0,                            SEEK_SET);

	 line_buf_feline       = calloc(1,   xml_file_size_feline + 1);
	 line_buf_2_feline     = calloc(1,   xml_file_size_feline + (strlen(node__________feline)*2)+ 5 +
					strlen(in_data_______feline) + 1000);//it is enough I supose
	 lines_count_feline = 0;
	 
	 while(fgets(line_buf_feline, xml_file_size_feline, my_file_feline))
	   {
		    if(0 == ftell(my_file_feline))
	    {
	    
	    break;
		}
	     did_arp = true;
	     lines_count_feline++;

	     replacestringsensitive2_feline(line_buf_feline, "\r",                "");
	     replacestringsensitive2_feline(line_buf_feline, "\n",                "");

	     if(lines_count_feline == item_position_feline        )
	       {

		 strcat(line_buf_2_feline, "    "                );
		 strcat(line_buf_2_feline, "<"                   );
		 strcat(line_buf_2_feline,
			node__________feline                     );
		 strcat(line_buf_2_feline, ">"                   );

		 strcat(line_buf_2_feline,   in_data_______feline);
		 strcat(line_buf_2_feline,                   "</");
		 strcat(line_buf_2_feline,   node__________feline);
		 strcat(line_buf_2_feline,">\n"                  );
		 
	       }
	     else
	       {
		 strcat(line_buf_2_feline, line_buf_feline           );
		 strcat(line_buf_2_feline, "\n"                      );
	       }
	     
	   }

	 if(did_arp)
	   {
	     line_buf_2_feline[strlen(line_buf_2_feline) - 1] = 0;//to remove last \n
	   }

	 if(10 == item_feline)
	   {
	     strcat(line_buf_2_feline, "\n");//to add last \n if it was there...
	   }
	 
	 if(NULL == line_buf_2_feline && NULL != line_buf_2_feline)
	   {
	     return 27;
	   }
	 
	
	 fclose(my_file_feline );

	 my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				  L"wb"
				  );

	 if(my_file_feline)
	   {
	     fwrite(line_buf_2_feline, 1, strlen(line_buf_2_feline), my_file_feline);
	     fclose(my_file_feline);
	     my_file_feline   = NULL;
	   }
	 free(line_buf_feline  );
	 free(line_buf_2_feline);

	 goto saida_feline;
       }
     else
       {
	 returnvalue_feline = 1;
	 goto saida_feline;
       }
   }

 if(-1 == root_position_feline)
   {
    
     my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
			      L"rb"
			      );
     if(my_file_feline)
       {
	 fseek(my_file_feline, 0,                            SEEK_END);
	 xml_file_size_feline  =  ftell(               my_file_feline);

	 if(xml_file_size_feline)
	   {
	     fseek(my_file_feline, -1,                            SEEK_END);
	     fread(&item_feline, 1, 1, my_file_feline);
	   }
	 
	 fseek(my_file_feline, 0,                            SEEK_SET);

	 line_buf_feline       = calloc(1,   xml_file_size_feline + 1);
	 line_buf_2_feline     = calloc(1,   xml_file_size_feline + (strlen(node__________feline)*2)+ 5 +
					strlen(in_data_______feline) + 1000);//it is enough I supose
	 lines_count_feline = 0;
	 
	 while(fgets(line_buf_feline, xml_file_size_feline, my_file_feline))
	   {
	     if(0 == ftell(my_file_feline))
	       {
	    
		 break;
	       }
	     did_arp = true;
	     lines_count_feline++;

	     replacestringsensitive2_feline(line_buf_feline, "\r",                "");
	     replacestringsensitive2_feline(line_buf_feline, "\n",                "");

	     	 strcat(line_buf_2_feline, line_buf_feline           );
		 strcat(line_buf_2_feline, "\n"                      );

	     if(lines_count_feline == valid_position_feline      )
	       {
	
		 strcat(line_buf_2_feline,   "<");
		 strcat(line_buf_2_feline,root__________feline);
		 strcat(line_buf_2_feline, ">\n");
		 strcat(line_buf_2_feline,"    ");
		 strcat(line_buf_2_feline,   "<");
		 strcat(line_buf_2_feline,node__________feline);
		 strcat(line_buf_2_feline,   ">");
		 strcat(line_buf_2_feline,in_data_______feline);
		 strcat(line_buf_2_feline, "</");
		 strcat(line_buf_2_feline,node__________feline);
		 strcat(line_buf_2_feline,">\n");
		 strcat(line_buf_2_feline, "</");
		 strcat(line_buf_2_feline,root__________feline);
		 strcat(line_buf_2_feline,">\n");
		 
	       }	    
	   }

	 if(did_arp)
	   {
	     line_buf_2_feline[strlen(line_buf_2_feline) - 1] = 0;
	   }

	 if(10 == item_feline)
	   {
	     strcat(line_buf_2_feline, "\n");
	   }
	 
	 if(NULL == line_buf_2_feline && NULL != line_buf_2_feline)
	   {
	     return 27;
	   }
	
	 fclose(my_file_feline );

	 my_file_feline = _wfopen(amanda_utf8towide_1_(filename_utf8_feline),
				  L"wb"
				  );

	 if(my_file_feline)
	   {
	     fwrite(line_buf_2_feline, 1, strlen(line_buf_2_feline), my_file_feline);
	     fclose(my_file_feline);
	     my_file_feline   = NULL;
	   }
	 free(line_buf_feline  );
	 free(line_buf_2_feline);

	 goto saida_feline;
 
       }
     else
       {
	 returnvalue_feline = 1;
	 goto saida_feline;
       }
   }
 
 saida_feline:;
 if(in_data_______feline)
   {
     free(in_data_______feline);
   }
 return returnvalue_feline;
}

/**
 * Function to remove a node if you need to do it...
 *
 * @param filename_utf8_feline the XML file
 *
 * @param root__________feline the root
 *
 * @return 0 if no error, 1 otherwise
 *
 */
int feline_remove_root_xml(char * filename_utf8_feline,
					char * root__________feline				 
					)
{
  write_mode_feline = FELINE_MODE_DELETE_ROOT;
  
  feline_write_xml(filename_utf8_feline,
			   root__________feline,
			   "none",
			   NULL,
			   "none"
			   );
  write_mode_feline = FELINE_MODE_NORMAL;  
  return 0;
}

/**
 * Function to remove a node if you are a clean programmer...
 *
 * @param filename_utf8_feline the XML file
 *
 * @param root__________feline the root
 *
 * @param node__________feline the node to get rid from the XML file
 * 
 * @return 0 if no error, 1 otherwise, as you may expect...
 *
 */
int feline_remove_node_xml(char * filename_utf8_feline,
					char * root__________feline,
					char * node__________feline
					)
{
  write_mode_feline = FELINE_MODE_DELETE_NODE;
  
  feline_write_xml(filename_utf8_feline,
			   root__________feline,
			   node__________feline,
			   NULL,
			   "none"
			   );
  
  write_mode_feline = FELINE_MODE_NORMAL;  
  return 0;
}

#ifdef MAIN_FOR_DEBUG_FOR_FUTURE_feline

int main()
{
  int ret_arp;
  pedro_dprintf(0, "antes1\n");
  {
    char out_data_feline[1027];
    feline_read_xml("feline.mis",//nao muda mais, por favor
			    "Aline_Franciele_de_Andrade_settings",
			    "feline_node_test",
			    NULL/*for the moment*/,
			    out_data_feline
			    );

    printf("Saida .%s.\n", out_data_feline  );
    pedro_dprintf(0, "antes2\n");
    printf("Linhas %d posicao do item nas linhas, linha: %d, root position line: %d valid xml position line: %d\n",
	   lines_count_feline,
	   item_position_feline,
	   root_position_feline,
	   valid_position_feline);
  }
  {
    char out_data_feline[1027];
    ret_arp =  feline_read_xml("feline.mis",//nao muda mais, por favor
			    "Aline_Franciele_de_Andrade_settings",
			    "feline_node_test",
			    NULL/*for the moment*/,
			    out_data_feline
			    );
    pedro_dprintf(0, "antes3\n");
    printf("Saida .%s. return %d\n", out_data_feline, ret_arp );

    printf("Linhas %d posicao do item nas linhas, linha: %d, root position line: %d valid xml position line: %d\n",
	   lines_count_feline,
	   item_position_feline,
	   root_position_feline,
	   valid_position_feline);
  }
  
  ret_arp =  feline_write_xml("feline2.mis",//bug to solve in a few years...no problem
				      "feline_root",
				      "feline_node",
				      NULL,
				      "."
				      );
  
  printf("Return value of write %d\n", ret_arp);
  /*
  feline_remove_node_xml("feline2.mis",
			 "feline_root",
			 "feline_node"
			 );
  */
  {
    char out_data_feline[1027];
 feline_read_xml("feline2.mis",//nao muda mais, por favor
			    "feline_root",
			    "feline_node",
			    NULL/*for the moment*/,
			    out_data_feline
			    );
 printf("Saiu .%s.\n", out_data_feline);

 pedro_dprintf(0, "saiu armadilhas .%s.\n", out_data_feline);
 
  }
  return 0;
}

#endif
