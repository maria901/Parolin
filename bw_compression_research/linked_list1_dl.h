// here the encode from 8 bits to 9
int8_t montagem_dl;
int bitposition_dl;
int8_t deslocador_dl = 0;
int8_t last_byte_encoded_value_dl; // only usefull for the encode, in the agregation the value will be in ht last byte of memory also in the linked list
bool is_it_the_first_byte_to_encode_dl;
void __fastcall convert_8_bits_to_nine_bits(__attribute__((unused)) int8_t *input_mem_dl,
											__attribute__((unused)) int len_of_input_to_encode_as_you_may_expect_dl,
											__attribute__((unused)) int8_t *output_mem_dl,
											__attribute__((unused)) int *bytes_encoded_so_far_dl, // a contagem é o tamanho dos dados ric, só isso, nao precisa processar duas vezes a cada processo vai salvando os dados que precisa, só precisa dar uma passagem rapida pra saber o tamanho dos dados, ok...
											__attribute__((unused)) int8_t *montagem_dl_interno,
											__attribute__((unused)) int8_t *bitposition_dl_interno_for_your_pleasure__)
{

	// int bitcount__dl = 0;
	// int16_t temp_16_dl;
	int8_t *ptr_dl = input_mem_dl;
	int i_dl;
	static int16_t meu_buf_16_dl[512];

	for (i_dl = 0; i_dl < len_of_input_to_encode_as_you_may_expect_dl; i_dl++)
	{
		meu_buf_16_dl[i_dl] = (int16_t)input_mem_dl[i_dl];
	}

	(*bytes_encoded_so_far_dl) = 0;

	if (is_it_the_first_byte_to_encode_dl)
	{
		is_it_the_first_byte_to_encode_dl = false;
		bitposition_dl = 0;
		(*bitposition_dl_interno_for_your_pleasure__) = 0;
		montagem_dl = 0;
		deslocador_dl = 0;
		(*montagem_dl_interno) = 0;
	}

	while (len_of_input_to_encode_as_you_may_expect_dl--)
	{

		switch (bitposition_dl)
		{
		case 0:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro..., ja foi prealocado do tamanho certo com multiplicacao por .2
				output_mem_dl++;
				deslocador_dl = 0;
			}
			bitposition_dl++;
			break;
		case 1:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro...
				output_mem_dl++;
				deslocador_dl = 0;
			}

			bitposition_dl++;
			break;
		case 2:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro...
				output_mem_dl++;
				deslocador_dl = 0;
			}
			bitposition_dl++;
			break;
		case 3:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro...
				output_mem_dl++;
				deslocador_dl = 0;
			}

			bitposition_dl++;
			break;
		case 4:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro...
				output_mem_dl++;
				deslocador_dl = 0;
			}

			bitposition_dl++;
			break;

		case 5:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro...
				output_mem_dl++;
				deslocador_dl = 0;
			}

			bitposition_dl++;
			break;
		case 6:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro...
				output_mem_dl++;
				deslocador_dl = 0;
			}

			bitposition_dl++;
			break;

		case 7:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro...
				output_mem_dl++;
				deslocador_dl = 0;
			}

			bitposition_dl++;
			break;
		case 8:

			if ((1 << deslocador_dl) & *ptr_dl++)
			{
				montagem_dl |= (1 << deslocador_dl);
			}
			else
			{
				montagem_dl &= ~(1 << deslocador_dl);
			}
			(*montagem_dl_interno) = montagem_dl;
			deslocador_dl++;

			if (8 == deslocador_dl)
			{
				(*bytes_encoded_so_far_dl)++;
				(*output_mem_dl) = montagem_dl; // quando encher um byte inteiro...
				output_mem_dl++;
				deslocador_dl = 0;
			}

			bitposition_dl = 0;
			break;
		}
	}
	(*bitposition_dl_interno_for_your_pleasure__) = bitposition_dl; // next bit to set when reconstructing the data
	return;
}

// this is the first linked list that will have the data referenced to recreate the original file
// it will have the strings and the references to the second linked list that will hold the plain strings on it if they are the same as the input string

struct my_struct_for_list_ar_is__dl__update_dl // for list only
{

	char *filename_k;
	int last_item_of_nine_bits_encode_dl; // complexo mas tudo bem, da para lidar mais tarde otimizamos isso, codifica tudo com 9 bits
	int bytes_encoded_so_far_dl;
	char *memory_for_string_dl;
	int len_of_memory_dl;
	int number_of_index_in_linked_list_dl;		 // if in linked list only need this, dont you agree?
	bool true_if_is_entry_in_the_linked_list_dl; // redundant but we will keep it...because if the memory is on it is not linked list, ok?
	int has_next;								 // not in use

	struct my_struct_for_list_ar_is__dl__update_dl *next_ar;
};

struct my_struct_for_list_ar_is__dl__update_dl *aak_is__dl__update_dl;
struct my_struct_for_list_ar_is__dl__update_dl *aak_inicio_is__dl__update_dl;

struct my_struct_for_list_ar_is__dl__update_dl *aak_pointer_is__dl__update_dl;

int has_itens_is__dl__update_dl = 0;

int has_itens_copy_is__dl__update_dl = 0;

void add_more_one_is__dl__update_dl(__attribute__((unused)) uint8_t *memory_for_string_dl,
									__attribute__((unused)) int len_of_memory_dl,
									__attribute__((unused)) int number_of_index_in_linked_list_dl, // if in linked list only need this, dont you agree?
									__attribute__((unused)) bool true_if_is_entry_in_the_linked_list_dl)
{
	double d_temp_dl;
	struct my_struct_for_list_ar_is__dl__update_dl *aak_ptr;
	if (!has_itens_is__dl__update_dl)
	{
		aak_is__dl__update_dl = calloc(1, sizeof(struct my_struct_for_list_ar_is__dl__update_dl));
		aak_inicio_is__dl__update_dl = aak_is__dl__update_dl;
		aak_pointer_is__dl__update_dl = aak_is__dl__update_dl;

		aak_is__dl__update_dl->len_of_memory_dl = len_of_memory_dl;

		aak_is__dl__update_dl->number_of_index_in_linked_list_dl = number_of_index_in_linked_list_dl;

		aak_is__dl__update_dl->true_if_is_entry_in_the_linked_list_dl = true_if_is_entry_in_the_linked_list_dl;

		if (memory_for_string_dl)
		{

			d_temp_dl = (double)len_of_memory_dl;

			d_temp_dl = d_temp_dl * .2;

			aak_is__dl__update_dl->memory_for_string_dl = malloc((int)d_temp_dl);
			memcpy(aak_is__dl__update_dl->memory_for_string_dl, memory_for_string_dl, len_of_memory_dl);
		}
		else
			aak_is__dl__update_dl->memory_for_string_dl = NULL;

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

		aak_ptr->len_of_memory_dl = len_of_memory_dl;

		aak_ptr->number_of_index_in_linked_list_dl = number_of_index_in_linked_list_dl;

		aak_ptr->true_if_is_entry_in_the_linked_list_dl = true_if_is_entry_in_the_linked_list_dl;

		if (memory_for_string_dl)
		{
			aak_ptr->memory_for_string_dl = malloc(len_of_memory_dl);
			memcpy(aak_ptr->memory_for_string_dl, memory_for_string_dl, len_of_memory_dl); // dont need plus one because it is memory not string, ok?
		}
		else
			aak_ptr->memory_for_string_dl = NULL;

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

	if (my_ptr2_ar->memory_for_string_dl)
		free(my_ptr2_ar->memory_for_string_dl); // ta aqui

	free(my_ptr2_ar);
	has_itens_is__dl__update_dl--;
	goto inicio_ar;
	return 1;
}
