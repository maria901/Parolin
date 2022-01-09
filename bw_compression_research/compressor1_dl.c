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

	char amor_assinatura_dl[6];
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
	__attribute__((unused)) uint8_t *buf_dl = malloc(DL_SIZE__);
	__attribute__((unused)) uint16_t *buf16_dl = malloc(DL_SIZE__ * 2);

	__attribute__((unused)) uint8_t *ptr_dl;

	__attribute__((unused)) int i_i_dl;

	unlink("make.dl.compressed");
	my_file_dl = fopen("make.exe", "rb");
	out_file_dl = fopen("make.dl.compressed", "wb");

	if (my_file_dl)
	{

		pedro_dprintf(0, "size %d\n", DL_SIZE__);
		while ((len_dl = fread(buf_dl, 1, DL_SIZE__, my_file_dl)))
		{
			dl_dados_salvos_querido_ric minha_struct = {0};

			minha_struct.amor_assinatura_dl[0] = 'd';
			minha_struct.amor_assinatura_dl[1] = 'l';
			minha_struct.amor_assinatura_dl[2] = 'd';
			minha_struct.amor_assinatura_dl[3] = 'l';
			minha_struct.amor_assinatura_dl[4] = 1; // second version version
			minha_struct.amor_assinatura_dl[5] = 1; // compressed or not

			minha_struct.tamanho_da_slice_dl = len_dl;

			for (i_i_dl = 0; i_i_dl < len_dl; i_i_dl++)
			{
				buf16_dl[i_i_dl] = (int16_t)buf_dl[i_i_dl];
			}

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

	free(buf_dl);
	free(buf16_dl);

	printf("Research running...");

	return 0;
}

/*
//vamos ler de quanto em quanto ?

* * * * * * * * 16 caracteres ? de cada vez ? nao pode ser mais ou menos ?

ok, we have the information now store it,

1 - first we need to scan the data for data repeating it

primeiro precisa definir um meio certo de salvar as coisas no arquivo, tem que escolher um caracter e trocar ele

eu tenho uma outra visao de salvar isso em linked lists e depois de processado so colocar no arquivo, mas se nao for compressivel nao adianta

quando nao da para comprimir complica

tem que criar slices do arquivo inteiro , de um caracter ate 512, ok?

se nao for compressivel simplesmente deixa como esta ok, uma flag comprimido ou nao

entendi, tem que ler, salvar na nova memoria e manter uma copia original

certo...

to quase compreendendo...

precisa de um meio  de salvar na memoria ou arquivo a informacao de maneira simplificada e usando pouco espaco

nao da para usar aquela ideia de run lenght compression ?

repete o caracter e poe um controle...

precisa de um meio bem definido de como colocar as strings comprimidas no arquivo comprimido

poderia contar o caracter que menos repete, mas isso leva tempo...

zlib expande o arquivo se nao consegue comprimir dai aciona umma flag que faz com que seja a original em vez da versao comprimida que expande

pode usar 9 bits para cada 16 byes da memira assim nao sao todos ok?

numa sequencia de bytes no final usa 9 bits igual lzw, nao quer dar uma lida em lzw ?
se usar 16 bytes serao sempre multiplos de 16 para qualquer sequencia, pode ser bom

melhor dar uma lida primeiro em lzw

ok, usa 9 bits mas para todos os caracteres ? dai da para definir valores para outras coisas

se for abaixo de 256 entao é caractere se for acima é controle...

sim é facil de controlar, basta ir mandando os bits, e fim de papo

primeiro voce trabalha em cima depois salva, com dados de conpressao completos e crc32, ok ?

vamos la, comecando do inicio, transforma todos os bits para 9, e usa eles pra marcar oque for comprimido ou nao depois a gente melhora isso

precisamos comprimir

deste jeito ficou facil, vamos fazer...

*/

// precisamos de um conversor de bytes para 9 bytes...vai lá... na memoria, vamos trabalhar com ele neste 128 kb

/*

pra isso eu tenho um codigo rapido simplesmente converter os dados de int8 para int16, vamos la, um array

ok, vamos copiar os 8 bits para 16 e trabalhar em cima disso pra ser rapido, da pra acelerar o lzw dos caras com isso

now what...

we have two arrays, but we will work on it... no need to store it now...

voltando a programacao, temos um array de bytes e array de shorts, precisamos iniciar o escaneamento, nove bits esta de bom tamanho pra os itens de depois da pra colocar 9 bits apenas em 16 em 16 e assim por diante

vamos la...

pode ir alocando em linked list se nao sabe o tamanho que vai ter , ok, sim, é isso,

vamos comecar com 16 bytes, sim , é isso, copia 16 bytes ric,,,mas e depois , depois checa se os proximos 16 sao os mesmo ?

nao, voce ja tem a memoria toda, entao apenas copia 16 e depois verifica se os proximo 512 ? se repetem ?

so funciona pra tras ? acho que nao vai ser reconstruido pode ser pra tras e pra frente...

ele simplesmente diz em que ponto do arquivo ocorre, e pode ter que tamanho ?

em que se da a compressao amor ?
 repetir um memoria inteiro nao comprime aonde esta a compressao ?

 sim mas estes limites serao alterados mais tarde para otimizacao...

aonde se da a compressao: resposta na duplicacao com menos dados da mesma informacao, nao é isso ?

depois de testar 512 bytes pode ir abaixando de 16 em dezesseis e ir definindo se tem ou nao

longest match

começa por ai

todos estes valores serao ajustados e controlados num loop que vai mostrar o melhor item deste todos

de 16 em 16 esta bom, diminuindo ate ter apenas 16, ok ?

vai...

hummmmmmmm, se existir copia os 512 bytes no stream e marca as duas posicoes como tendo a informacao, que ideia

sim, assim evita este problema, se nao tiver deixa como ta nao é isso, sim mas vai mudar as posicoes e dai ric querido ?

nao sei dua...

deixa pra colocar no final, nao é melhor pra nao dar problema ?

o markov chain talvez seja isso, mas voce vai criar algo melhor, sim vamos aprimorar a cada momento

nao da pra manter num linked list, em linked list nao vai ter posicao, ou vai, vai um index ?, 

linked list parece uma boa, salva o index o tamanho cada item comeca contando de 0, entendeu, dai na marcacao simplesmente coloca o index e na reconstrucao esta tudo certo, para isto precisamos de packets?, sim , precisa saber o tamanho total do arquivo, saber aonde termina, no meio nao tem como porque esta tudo em linked list, mas se souber o tamanho comprimido da, ric, sim é isso

e cada 

*/