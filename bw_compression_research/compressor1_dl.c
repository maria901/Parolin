/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>        *
*                                                                             *
*     Este  programa  é software livre: você pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     10
*     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opção) qualquer versão posterior.        *
*                                                                             *
*     Este  programa é distribuído na  esperança que isto vai  ser útil,      *
*     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de      *
*     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Pública para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Pública Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito rápida) WhatsApp               *
*     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

// 2022 ric - dl

#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

#include <stdbool.h>

#include <process.h>

// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

// variables and functions defines or constants

void pedro_dprintf(int amanda_level,
				   char *format, ...);

// 8888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888

/*














We will start with an enhacement over zlib to use less memory and run faster if possible
giving better compression

instead using huffman we will use range code or an optimized version of it, this is a good starting point, huffman is never better than arithmetic coding

































*/

struct my_struct_for_list_ar_is__dl__update_dl // for list only
{

	char *filename_k;

	int has_next; // not in use

	struct my_struct_for_list_ar_is__dl__update_dl *next_ar;
};

struct my_struct_for_list_ar_is__dl__update_dl *aak_is__dl__update_dl;
struct my_struct_for_list_ar_is__dl__update_dl *aak_inicio_is__dl__update_dl;

struct my_struct_for_list_ar_is__dl__update_dl *aak_pointer_is__dl__update_dl;

int has_itens_is__dl__update_dl = 0;

int has_itens_copy_is__dl__update_dl = 0;

void add_more_one_is__dl__update_dl(char *memory_ric)
{
	struct my_struct_for_list_ar_is__dl__update_dl *aak_ptr;
	if (!has_itens_is__dl__update_dl)
	{
		aak_is__dl__update_dl = calloc(1, sizeof(struct my_struct_for_list_ar_is__dl__update_dl));
		aak_inicio_is__dl__update_dl = aak_is__dl__update_dl;
		aak_pointer_is__dl__update_dl = aak_is__dl__update_dl;
		aak_is__dl__update_dl->filename_k = memory_ric;

		aak_is__dl__update_dl->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is__dl__update_dl));

		has_itens_is__dl__update_dl = 1;
		has_itens_copy_is__dl__update_dl = has_itens_is__dl__update_dl;

		aak_is__dl__update_dl = aak_is__dl__update_dl->next_ar;
	}
	else
	{
		aak_ptr = aak_is__dl__update_dl;
		assert(aak_ptr);

		assert(8 < sizeof(struct my_struct_for_list_ar_is__dl__update_dl));

		aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is__dl__update_dl));

		aak_ptr->filename_k = memory_ric;

		aak_is__dl__update_dl = aak_ptr->next_ar;
		has_itens_is__dl__update_dl++;
		has_itens_copy_is__dl__update_dl = has_itens_is__dl__update_dl;
	}
}

/**
 * To cleanup the linked list when it is not in use anymore
 *
 */
int clean_list__ar_is__dl__update_dl(void)
{
	struct my_struct_for_list_ar_is__dl__update_dl *my_ptr_ar;

	struct my_struct_for_list_ar_is__dl__update_dl *my_ptr2_ar;

	my_ptr2_ar = aak_inicio_is__dl__update_dl;
	my_ptr_ar = aak_inicio_is__dl__update_dl;
inicio_ar:;
	if (!has_itens_is__dl__update_dl)
	{
		has_itens_copy_is__dl__update_dl = 0;
		return 0;
	}
	my_ptr2_ar = my_ptr_ar;
	my_ptr_ar = my_ptr_ar->next_ar;
	if (1 == has_itens_is__dl__update_dl)
	{
		free(my_ptr2_ar->next_ar);
	}
	// pedro_dprintf(-20220108, "dando free em endereco %p %s", my_ptr2_ar->filename_k, my_ptr2_ar->filename_k);
	// free(my_ptr2_ar->filename_k); // ta aqui
	free(my_ptr2_ar);
	has_itens_is__dl__update_dl--;
	goto inicio_ar;
	return 1;
}

typedef struct dl_dados_salvos_querido_ric__
{

	char amor_assinatura_dl[4];
	int tamanho_da_slice_dl;

} dl_dados_salvos_querido_ric;

int main()
{

	// vamos lá

	/*

	in portuguese, translate it

	primeiro vamos criar um linked list para manter a lista de strings analizadas

	64 bits claro, depois a gente ve sobre como convertar pra x86

first we need to open a file that we want to compress, for this the ubiquitous 'make.exe'

bom, em lz77 e lzss e lz78 a informacao se baseia nos dados que vao sendo lidos no arquivo e marcacoes vao sendo feitas pra se saber se ja apareceram ou nao

primeiro teria que se desenvolver uma forma avancada para se colocar na memria e no arquivo comprimido uma forma satisfatoria de salvar as informacoes que serao necessarias para a reconstrucao do arquivo

pelo jeito a cada 32kb é reiniciado o processo pois se deslocar nao sera possivel reconstruir os dados

pois a informacao tera passado, sim, tem que ter uma tamanho predefinido, mas que seja aleatorio, concorda?

sim
vamos bater o bzip2 com facilidade e rapido

mais rapido e melhor que bzip2

precisamos de um texto de exemplo

da pra trabalhar com memoria de 32 kb nao dá?

mas em que isto vai ser melhor que zlib?

200 mb de memoria ?

tem coisa demais...



	*/
#define DL_SIZE__ (1L << 17)
	__attribute__((unused)) int len_dl;

	__attribute__((unused)) int len_of_data_to_compress_dl;
	__attribute__((unused)) FILE *my_file_dl = NULL;
	__attribute__((unused)) FILE *out_file_dl = NULL;
	__attribute__((unused)) char *buf_dl = malloc(DL_SIZE__);

	__attribute__((unused)) char *ptr_dl;

	unlink("make.dl.compressed");
	my_file_dl = fopen("make.exe", "rb");
	out_file_dl = fopen("make.dl.compressed", "wb");

	if (my_file_dl)
	{
		/*
		//vamos ler de quanto em quanto ?

		* * * * * * * * 16 caracteres ? de cada vez ? nao pode ser mais ou menos ?
		*/
		pedro_dprintf(0, "size %d\n", DL_SIZE__);
		while ((len_dl = fread(buf_dl, 1, DL_SIZE__, my_file_dl)))
		{
			dl_dados_salvos_querido_ric minha_struct = {0};

			minha_struct.amor_assinatura_dl[0] = 'd';
			minha_struct.amor_assinatura_dl[1] = 'l';
			minha_struct.amor_assinatura_dl[2] = 'd';
			minha_struct.amor_assinatura_dl[3] = 'l';

			minha_struct.tamanho_da_slice_dl = len_dl;

			fwrite(&minha_struct, 1, sizeof(minha_struct), out_file_dl);

			len_of_data_to_compress_dl = len_dl;

			ptr_dl = buf_dl;
			while (len_dl--)
			{
				fwrite(ptr_dl, 1, 1, out_file_dl);
				ptr_dl++;
			}
		}

		fclose(my_file_dl);

		if (out_file_dl)
		{
			fclose(out_file_dl);
			out_file_dl = NULL;
		}
	}

	if (out_file_dl)
	{
		fclose(out_file_dl);
		out_file_dl = NULL;
	}

	printf("Research running...");

	return 0;
}