//2021 June, amanda & MathMan

struct my_struct_for_list_ar_is_amanda_update_june_24 //for list only
{
    time_t atime_i;
    time_t mtime_i;
    time_t birthtime_i;
    int64_t filesize_i;
    int64_t file_offset_i;
    char *item_entry_i; //[1027];
    bool is_dir_i;
    bool in_use_i;
    bool nodata_z;
    int64_t attributes_i;
    // bool    played_z       ;
    //int64_t position        ;

    struct my_struct_for_list_ar_is_amanda_update_june_24 *next_ar;
};

struct my_struct_for_list_ar_is_amanda_update_june_24 *aak_is_amanda_update_june_24 = NULL;

struct my_struct_for_list_ar_is_amanda_update_june_24 *aak_inicio_is_amanda_update_june_24 = NULL;

struct my_struct_for_list_ar_is_amanda_update_june_24 *aak_pointer_is_amanda_update_june_24;

int has_itens_is_amanda_update_june_24 = 0;

int has_itens_copy_is_amanda_update_june_24 = 0;

void fix_string_i(char *data_i)
{

    trocadordebackslashtras(data_i);

    if (strlen(data_i))
    {
        if ('\\' == data_i[strlen(data_i) - 1])
        {
            data_i[strlen(data_i) - 1] = 0;
        }
    }

    return;
}

void __stdcall add_more_one_z_june_24(
    time_t atime_i,
    time_t mtime_i,
    time_t birthtime_i,
    int64_t filesize_i,
    int64_t file_offset_i,
    char *item_entry_i,
    bool is_dir_i,
    bool in_use_i,
    int64_t attributes_i)
{
    struct my_struct_for_list_ar_is_amanda_update_june_24 *aak_ptr;
    if (!has_itens_is_amanda_update_june_24)
    {
        aak_is_amanda_update_june_24 = calloc(1, sizeof(struct my_struct_for_list_ar_is_amanda_update_june_24));
        aak_inicio_is_amanda_update_june_24 = aak_is_amanda_update_june_24;
        aak_pointer_is_amanda_update_june_24 = aak_is_amanda_update_june_24;
        aak_is_amanda_update_june_24->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_amanda_update_june_24));

        aak_is_amanda_update_june_24->next_ar->nodata_z = true;

        //aak_is_amanda_update_june_24->position = 0;

        aak_is_amanda_update_june_24->atime_i = atime_i;
        aak_is_amanda_update_june_24->mtime_i = mtime_i;
        aak_is_amanda_update_june_24->birthtime_i = birthtime_i;
        aak_is_amanda_update_june_24->filesize_i = filesize_i;
        aak_is_amanda_update_june_24->file_offset_i = file_offset_i;
        aak_is_amanda_update_june_24->attributes_i = attributes_i;

        aak_is_amanda_update_june_24->item_entry_i = malloc(strlen(item_entry_i) + 1);

        strcpy(aak_is_amanda_update_june_24->item_entry_i, item_entry_i);

        //aqui ?...
        fix_string_i(aak_is_amanda_update_june_24->item_entry_i);

        aak_is_amanda_update_june_24->is_dir_i = is_dir_i;
        aak_is_amanda_update_june_24->in_use_i = in_use_i;

        aak_is_amanda_update_june_24->nodata_z = false;

        has_itens_is_amanda_update_june_24 = 1;
        has_itens_copy_is_amanda_update_june_24 = has_itens_is_amanda_update_june_24;
        aak_is_amanda_update_june_24 = aak_is_amanda_update_june_24->next_ar;
    }
    else
    {
        aak_ptr = aak_is_amanda_update_june_24;
        assert(aak_ptr);
        aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_amanda_update_june_24));
        aak_ptr->next_ar->nodata_z = true;
        aak_is_amanda_update_june_24 = aak_ptr->next_ar;
        //aak_ptr->position = has_itens_is_amanda_update_june_24;

        aak_ptr->atime_i = atime_i;
        aak_ptr->mtime_i = mtime_i;
        aak_ptr->birthtime_i = birthtime_i;
        aak_ptr->filesize_i = filesize_i;
        aak_ptr->file_offset_i = file_offset_i;
        aak_ptr->attributes_i = attributes_i;

        aak_ptr->item_entry_i = malloc(strlen(item_entry_i) + 1);

        strcpy(aak_ptr->item_entry_i, item_entry_i);

        fix_string_i(aak_ptr->item_entry_i);

        aak_ptr->is_dir_i = is_dir_i;
        aak_ptr->in_use_i = in_use_i;

        aak_ptr->nodata_z = false;
        has_itens_is_amanda_update_june_24++;
        has_itens_copy_is_amanda_update_june_24 = has_itens_is_amanda_update_june_24;
    }
}

int clean_list__ar_is_amanda_update_june_24(void);

int clean_list_itens_is_amanda_update_june_24(void)
{

    if (!has_itens_copy_is_amanda_update_june_24)
    {
        clean_list__ar_is_amanda_update_june_24();
        return 0;
    }

    aak_pointer_is_amanda_update_june_24 = aak_pointer_is_amanda_update_june_24->next_ar;
    has_itens_copy_is_amanda_update_june_24--;
    assert(has_itens_copy_is_amanda_update_june_24 >= 0);

    return 1;
}

int clean_list__ar_is_amanda_update_june_24(void)
{
    struct my_struct_for_list_ar_is_amanda_update_june_24 *my_ptr_ar;
    struct my_struct_for_list_ar_is_amanda_update_june_24 *my_ptr2_ar;
    my_ptr2_ar = aak_inicio_is_amanda_update_june_24;
    my_ptr_ar = aak_inicio_is_amanda_update_june_24;
inicio_ar:;
    if (!has_itens_is_amanda_update_june_24)
    {
        has_itens_copy_is_amanda_update_june_24 = 0;
        return 0;
    }
    free(my_ptr_ar->item_entry_i);
    my_ptr2_ar = my_ptr_ar;
    my_ptr_ar = my_ptr_ar->next_ar;

    if (1 == has_itens_is_amanda_update_june_24)
    {
        free(my_ptr2_ar->next_ar);
    }

    free(my_ptr2_ar);

    has_itens_is_amanda_update_june_24--;

    goto inicio_ar;
    return 1;
}

int __stdcall check_item_z_june_24(char *filename_utf8)
{

    char temp_i_1[1027];
    char temp_i_2[1027];
    int i_z;

    struct my_struct_for_list_ar_is_amanda_update_june_24 *my_ptr_ar;

    strcpy(temp_i_1, filename_utf8);

    strtolower_ar(temp_i_1);

    my_ptr_ar = aak_inicio_is_amanda_update_june_24;

    for (i_z = 0; i_z < has_itens_is_amanda_update_june_24; i_z++)
    {

        strcpy(temp_i_2, my_ptr_ar->item_entry_i);

        strtolower_ar(temp_i_2);

        if (0 == strcmp(temp_i_1, temp_i_2))
        {
            my_ptr_ar->in_use_i = false;
        }

        my_ptr_ar = my_ptr_ar->next_ar;
    }
    return 0;
}

int __stdcall init_playlist_z_june_24(void)
{

    while (clean_list_itens_is_amanda_update_june_24())
    {
        ;
    }
    assert(0 == has_itens_is_amanda_update_june_24);

    return 0;
}
