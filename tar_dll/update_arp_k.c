// 2021 ricardo 07/jan/2022 17:23

struct my_struct_for_list_ar_is_amanda_update_dl // for list only
{

    char *filename_k;

    int has_next; // not in use

    struct my_struct_for_list_ar_is_amanda_update_dl *next_ar;
};

struct my_struct_for_list_ar_is_amanda_update_dl *aak_is_amanda_update_dl;
struct my_struct_for_list_ar_is_amanda_update_dl *aak_inicio_is_amanda_update_dl;

struct my_struct_for_list_ar_is_amanda_update_dl *aak_pointer_is_amanda_update_dl;

int has_itens_is_amanda_update_dl = 0;

int has_itens_copy_is_amanda_update_dl = 0;

void add_more_one_is_amanda_update_dl(char *memory_ric)
{
    struct my_struct_for_list_ar_is_amanda_update_dl *aak_ptr;
    if (!has_itens_is_amanda_update_dl)
    {
        aak_is_amanda_update_dl = calloc(1, sizeof(struct
                                                   my_struct_for_list_ar_is_amanda_update_dl));
        aak_inicio_is_amanda_update_dl = aak_is_amanda_update_dl;
        aak_pointer_is_amanda_update_dl = aak_is_amanda_update_dl;
        aak_is_amanda_update_dl->filename_k = memory_ric;

        aak_is_amanda_update_dl->next_ar = calloc(1, sizeof(struct
                                                            my_struct_for_list_ar_is_amanda_update_));

        has_itens_is_amanda_update_dl = 1;
        has_itens_copy_is_amanda_update_dl = has_itens_is_amanda_update_dl;

        aak_is_amanda_update_dl = aak_is_amanda_update_dl->next_ar;
    }
    else
    {
        aak_ptr = aak_is_amanda_update_dl;
        assert(aak_ptr);

        assert(8 < sizeof(struct my_struct_for_list_ar_is_amanda_update_dl));

        aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_amanda_update_dl));

        aak_ptr->filename_k = memory_ric;

        aak_is_amanda_update_dl = aak_ptr->next_ar;
        has_itens_is_amanda_update_dl++;
        has_itens_copy_is_amanda_update_dl = has_itens_is_amanda_update_dl;
    }
}

/**
 * To cleanup the linked list when it is not in use anymore
 *
 */
int clean_list__ar_is_amanda_update_dl(void)
{
    struct my_struct_for_list_ar_is_amanda_update_dl *my_ptr_ar;

    struct my_struct_for_list_ar_is_amanda_update_dl *my_ptr2_ar;

    my_ptr2_ar = aak_inicio_is_amanda_update_dl;
    my_ptr_ar = aak_inicio_is_amanda_update_dl;
inicio_ar:;
    if (!has_itens_is_amanda_update_dl)
    {
        has_itens_copy_is_amanda_update_dl = 0;
        return 0;
    }
    my_ptr2_ar = my_ptr_ar;
    my_ptr_ar = my_ptr_ar->next_ar;
    if (1 == has_itens_is_amanda_update_dl)
    {
        free(my_ptr2_ar->next_ar);
    }
    pedro_dprintf(-20220108, "dando free em endereco %p %s", my_ptr2_ar->filename_k, my_ptr2_ar->filename_k);
    free(my_ptr2_ar->filename_k); // ta aqui
    free(my_ptr2_ar);
    has_itens_is_amanda_update_dl--;
    goto inicio_ar;
    return 1;
}

/**
 * This function is the final function to updated a Tar or VAL file
 *
 * @param st the Tar struct with the required information to dump
 * a folder or file to disk, also for VAL file
 *
 */
void dump_file_or_folder_final_arp(struct tar_stat_info *st)
{
    // static VAL_data my_VAL_data;
    static VAL_data my_VAL_data2;

    int memoria_alocada_dl1 = 0;
    int memoria_alocada_dl2 = 0;

    __int64 can_seek_arp;
    int status;
    {
        char *temp_arp_1 = malloc(AMANDA__SIZE);
        char *temp_arp_2 = malloc(AMANDA__SIZE);
        char *temp_arp_3 = malloc(AMANDA__SIZE);
        int has_itens_is_amanda_update_internal = has_itens_is_amanda_update_;
        struct my_struct_for_list_ar_is_amanda_update_ *aak_ptr;
        aak_ptr = aak_inicio_is_amanda_update_;

        while (has_itens_is_amanda_update_internal--)
        {
            trocadordebackslashfrente(aak_ptr->filename_k);

            assert(AMANDA__SIZE > strlen(aak_ptr->filename_k));
            /*
                        if (mode_is_VAL_arp)
                        {
                            my_VAL_data.VAL_filename_dl = calloc(strlen(aak_ptr->filename_k) + 4, 1);

                            strcpy(my_VAL_data.VAL_filename_dl, aak_ptr->filename_k);
                            pedro_dprintf(-1, "depois de alocou ric");
                        }
            */
            if (aak_ptr->is_directory_arp)
            {
                struct timespec t;
                t.tv_sec = aak_ptr->mtime_tv_sec_arp;
                t.tv_nsec = 0;
                st->atime = t;
                st->mtime = t;
                st->ctime = t;

                assign_string(&st->file_name, aak_ptr->filename_k);

                if ('/' != st->file_name[strlen(st->file_name) - 1])
                {
                    static char temp_ar[AMANDA__SIZE];

                    strcpy(temp_ar, st->file_name);
                    strcat(temp_ar, "/");

                    assign_string(&st->file_name, temp_ar);
                    assign_string(&st->orig_file_name, temp_ar);

                    pedro_dprintf(-1, "pronto %s\n", st->file_name);
                }

                if (!mode_is_VAL_arp)
                {
                    dump_directory(st);
                }
                else
                {
                    my_VAL_data2 = aak_ptr->VAL_data__arp;
                    my_VAL_data2.VAL_is_dir = 1;
                    pedro_dprintf(-1, "antes diretorio %s freed %d", my_VAL_data2.VAL_filename_dl, my_VAL_data2.already_dl_freed);

                    if (true)
                    {
                        dump_diretory_VAL_arp(&my_VAL_data2);

                        pedro_dprintf(-1, "depois diretorio %s %p", my_VAL_data2.VAL_filename_dl, my_VAL_data2.VAL_filename_dl);
                        // free(my_VAL_data.VAL_filename_dl);
                        /*
                                                if (false == my_VAL_data2.already_dl_freed)
                                                {
                                                    pedro_dprintf(-1, "adicionado endereco %p", my_VAL_data2.VAL_filename_dl);
                                                    add_more_one_is_amanda_update_dl(my_VAL_data2.VAL_filename_dl);
                                                }
                        */

                        add_more_one_is_amanda_update_dl(my_VAL_data2.VAL_filename_dl);

                        my_VAL_data2.already_dl_freed = true;
                        // pedro_dprintf(-1, "depois diretorio free ");
                        // my_VAL_data2.VAL_filename_dl = NULL;
                    }
                }
                sprintf(process_message_k, "Processing %s", aak_ptr->filename_k);
                add_more_one(process_message_k);
            }
            else
            {
                if (strlen(aak_ptr->filename_k))
                {
                    trocadordebackslashfrente(aak_ptr->filename_k);
                    assign_string(&st->orig_file_name, aak_ptr->filename_k);
                    assign_string(&st->file_name, aak_ptr->filename_k);
                    {
                        static char my_copy_of_filename_ar[AMANDA__SIZE];
                        static char only_filename_arp[AMANDA__SIZE];
                        stripfilenameandpath_unix_arp(aak_ptr->filename_k, NULL, only_filename_arp);
                        strcpy(my_copy_of_filename_ar, only_filename_arp);
                        strtolower_ar(my_copy_of_filename_ar);
                        bool achei_o_match = false;
                        const char *my_str_literal = global_patern_ar;
                        char *token, *str, *tofree;
                        tofree = str = strdup(my_str_literal);
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

                        if (ARP_EXCLUDE_FILES == mode_is_include_or_exclude__)
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

                        if (!achei_o_match)
                        {
                            goto skip_amanda;
                        }
                    }
                    struct timespec t;
                    t.tv_sec = aak_ptr->mtime_tv_sec_arp;

                    {
                        void printf_time(time_t s_arp, char *file_arp);
                    }

                    t.tv_nsec = 0;
                    st->atime = t;
                    st->mtime = t;
                    st->ctime = t;
                    st->stat.st_size = aak_ptr->size_of_file_arp;
                    st->archive_file_size = st->stat.st_size;
                    bytes_left_in_the_update_file_arp = aak_ptr->size_of_file_arp;
                    can_seek_arp = _lseeki64(
                        our_update_file_open__arp,
                        aak_ptr->position_on_file_arp,
                        SEEK_SET);

                    if (-1 == can_seek_arp)
                    {
                        fatal_exit_k = 10004;
                        strcpy(error_message_k, "Cannot seek on temporary file");
                        break;
                    }

                    // my_VAL_data.VAL_is_dir = 0;

                    if (!mode_is_VAL_arp)
                    {
                        status = dump_regular_file(our_update_file_open__arp, st);
                        switch (status)
                        {
                        case dump_status_ok:
                        case dump_status_short:;
                            break;

                        case dump_status_fail:

                            sprintf(warning_message_k, "Cannot process file %s", aak_ptr->filename_k);
                            add_more_one(warning_message_k);

                            break;

                        case dump_status_not_implemented:
                            assert(0);
                        }
                        sprintf(process_message_k, "Processing %s", aak_ptr->filename_k);
                        add_more_one(process_message_k);
                    }
                    else
                    {
                        my_VAL_data2 = aak_ptr->VAL_data__arp; // feito
                        my_VAL_data2.VAL_is_dir = 0;

                        pedro_dprintf(-1, "antes file %s freed %d", my_VAL_data2.VAL_filename_dl, my_VAL_data2.already_dl_freed);
                        if (true)
                        {
                            if (dump_regular_file_VAL_arp(our_update_file_open__arp, &my_VAL_data2))
                            {
                                sprintf(warning_message_k, "Cannot process file %s", aak_ptr->filename_k);
                                add_more_one(warning_message_k);
                            }

                            pedro_dprintf(-1, "depois file  %s", my_VAL_data2.VAL_filename_dl);
                            // free(my_VAL_data2.VAL_filename_dl);

                            /*
                                                        if (false == my_VAL_data2.already_dl_freed)
                                                        {
                                                            pedro_dprintf(-1, "adicionado endereco %p", my_VAL_data2.VAL_filename_dl);
                                                            add_more_one_is_amanda_update_dl(my_VAL_data2.VAL_filename_dl);
                                                        }
                            */
                            add_more_one_is_amanda_update_dl(my_VAL_data2.VAL_filename_dl);
                            my_VAL_data2.already_dl_freed = true;
                            // pedro_dprintf(-1, "depois file free ");
                            // my_VAL_data2.VAL_filename_dl = NULL;
                        }
                    }

                skip_amanda:;
                }
            }
            aak_ptr = aak_ptr->next_ar;
        }

        free(temp_arp_1), free(temp_arp_2), free(temp_arp_3);
    }

    {
        clean_list__ar_is_amanda_update_dl();
    }
    pedro_dprintf(-1, "um e dois %d %d", memoria_alocada_dl1, memoria_alocada_dl2);
}
