int index_position_second_linked_list_dl;

struct my_struct_for_list_ar_is___rcdl____update__rcdl__ // for list only
{

     // int16_t

     uint8_t *string_saved_dl;

     int len_of_memory_dl; // dont need to be 9 bits because you have control over it...

     int index_of_linked_list_starting_from_0_dl;

     struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *next_ar;
};

struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *aak_is___rcdl____update__rcdl__;
struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *aak_inicio_is___rcdl____update__rcdl__;

struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *aak_pointer_is___rcdl____update__rcdl__;

int has_itens_is___rcdl____update__rcdl__ = 0;

int has_itens_copy_is___rcdl____update__rcdl__ = 0;

void add_more_one_is___rcdl____update__rcdl__(uint8_t *string_saved_dl, int len_of_memory_dl)
{
     struct my_struct_for_list_ar_is___rcdl____update__rcdl__ *aak_ptr;
     if (!has_itens_is___rcdl____update__rcdl__)
     {

          aak_is___rcdl____update__rcdl__ = calloc(1, sizeof(struct my_struct_for_list_ar_is___rcdl____update__rcdl__));
          aak_inicio_is___rcdl____update__rcdl__ = aak_is___rcdl____update__rcdl__;
          aak_pointer_is___rcdl____update__rcdl__ = aak_is___rcdl____update__rcdl__;

          aak_is___rcdl____update__rcdl__->string_saved_dl = malloc(len_of_memory_dl);

          memcpy(aak_is___rcdl____update__rcdl__->string_saved_dl, string_saved_dl, len_of_memory_dl);
          aak_is___rcdl____update__rcdl__->len_of_memory_dl = len_of_memory_dl;
          aak_is___rcdl____update__rcdl__->index_of_linked_list_starting_from_0_dl = index_position_second_linked_list_dl;
          if (DEBUG_DL__)
               pedro_dprintf(0, "inside function add_more_one_is___rcdl____update__rcdl__, adding %d bytes with the index %d", len_of_memory_dl, index_position_second_linked_list_dl);

          if (DEBUG_DL__)
          {
               ;//assert(0 && "inside function");
          }

          index_position_second_linked_list_dl++;

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

          /*


          */
          aak_ptr->string_saved_dl = malloc(len_of_memory_dl);
          memcpy(aak_ptr->string_saved_dl, string_saved_dl, len_of_memory_dl);
          aak_ptr->len_of_memory_dl = len_of_memory_dl;
          aak_ptr->index_of_linked_list_starting_from_0_dl = index_position_second_linked_list_dl;
          if (DEBUG_DL__)
               pedro_dprintf(0, "inside function add_more_one_is___rcdl____update__rcdl__, adding %d bytes with the index %d", len_of_memory_dl, index_position_second_linked_list_dl);

          if (DEBUG_DL__)
          {
               ;//assert(0 && "inside function");
          }

          index_position_second_linked_list_dl++;
          /*


          */

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

     free(my_ptr2_ar->string_saved_dl); // ta aqui
     free(my_ptr2_ar);
     has_itens_is___rcdl____update__rcdl__--;
     goto inicio_ar;
     return 1;
}
