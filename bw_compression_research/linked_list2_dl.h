
struct my_struct_for_list_ar_is___rcdl____update__rcdl__ // for list only
{

	char *filename_k;

//int16_t 

	int has_next; // not in use

	struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *next_ar;
};

struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *aak_is___rcdl____update__rcdl__;
struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *aak_inicio_is___rcdl____update__rcdl__;

struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *aak_pointer_is___rcdl____update__rcdl__;

int has_itens_is___rcdl____update__rcdl__ = 0;

int has_itens_copy_is___rcdl____update__rcdl__ = 0;

void add_more_one_is___rcdl____update__rcdl__(char *memory_ric)
{
	struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *aak_ptr;
	if (!has_itens_is___rcdl____update__rcdl__)
	{
		aak_is___rcdl____update__rcdl__ = calloc(1, sizeof(struct my_struct_for_list_ar_is___rcdl____update__rcdl__));
		aak_inicio_is___rcdl____update__rcdl__ = aak_is___rcdl____update__rcdl__;
		aak_pointer_is___rcdl____update__rcdl__ = aak_is___rcdl____update__rcdl__;
		aak_is___rcdl____update__rcdl__->filename_k = memory_ric;

		aak_is___rcdl____update__rcdl__->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is___rcdl____update__rcdl__));

		has_itens_is___rcdl____update__rcdl__ = 1;
		has_itens_copy_is___rcdl____update__rcdl__ = has_itens_is___rcdl____update__rcdl__;

		aak_is___rcdl____update__rcdl__ = aak_is___rcdl____update__rcdl__->next_ar;
	}
	else
	{
		aak_ptr = aak_is___rcdl____update__rcdl__;
		assert(aak_ptr);

		assert(8 < sizeof(struct my_struct_for_list_ar_is___rcdl____update__rcdl__));

		aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is___rcdl____update__rcdl__));

		aak_ptr->filename_k = memory_ric;

		aak_is___rcdl____update__rcdl__ = aak_ptr->next_ar;
		has_itens_is___rcdl____update__rcdl__++;
		has_itens_copy_is___rcdl____update__rcdl__ = has_itens_is___rcdl____update__rcdl__;
	}
}

/**
 * To cleanup the linked list when it is not in use anymore
 *
 */
int clean_list__ar_is___rcdl____update__rcdl__(void)
{
	struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *my_ptr_ar;

	struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *my_ptr2_ar;

	my_ptr2_ar = aak_inicio_is___rcdl____update__rcdl__;
	my_ptr_ar = aak_inicio_is___rcdl____update__rcdl__;
inicio_ar:;
	if (!has_itens_is___rcdl____update__rcdl__)
	{
		has_itens_copy_is___rcdl____update__rcdl__ = 0;
		return 0;
	}
	my_ptr2_ar = my_ptr_ar;
	my_ptr_ar = my_ptr_ar->next_ar;
	if (1 == has_itens_is___rcdl____update__rcdl__)
	{
		free(my_ptr2_ar->next_ar);
	}
	// pedro_dprintf(-20220108, "dando free em endereco %p %s", my_ptr2_ar->filename_k, my_ptr2_ar->filename_k);
	// free(my_ptr2_ar->filename_k); // ta aqui
	free(my_ptr2_ar);
	has_itens_is___rcdl____update__rcdl__--;
	goto inicio_ar;
	return 1;
}
