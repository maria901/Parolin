// this is the first linked list that will have the data referenced to recreate the original file
// it will have the strings and the references to the second linked list that will hold the plain strings on it if they are the same as the input string

struct my_struct_for_list_ar_is__dl__update_dl // for list only
{

	char *filename_k;

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
			aak_is__dl__update_dl->memory_for_string_dl = malloc(len_of_memory_dl);
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
