//2021 amanda & ricardo [closed 02/February/2021 15:04]

/**
 * This function is the final function to updated a Tar or VAL file
 *
 * @param st the Tar struct with the required information to dump
 * a folder or file to disk, also for VAL file
 *
 */
void dump_file_or_folder_final_arp(struct tar_stat_info *st)
{
  VAL_data my_VAL_data = { 0 };

  __int64 can_seek_arp;
  int status;
  {
    char *temp_arp_1 = malloc(1024);
    char *temp_arp_2 = malloc(1024);
    char *temp_arp_3 = malloc(1024);
    int has_itens_is_amanda_update_internal = has_itens_is_amanda_update_;
    struct my_struct_for_list_ar_is_amanda_update_ *aak_ptr;
    aak_ptr = aak_inicio_is_amanda_update_;

    while (has_itens_is_amanda_update_internal--)
      {
        trocadordebackslashfrente(aak_ptr->filename_k);

        assert(1024 > strlen(aak_ptr->filename_k));

        if (mode_is_VAL_arp)
          strcpy(my_VAL_data.VAL_filename, aak_ptr->filename_k);

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
                char temp_ar[1024 + 1];

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
                my_VAL_data = aak_ptr->VAL_data__arp;
                my_VAL_data.VAL_is_dir = 1;

                dump_diretory_VAL_arp(&my_VAL_data);
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
                  static char my_copy_of_filename_ar[1024];
                  char only_filename_arp[1024 + 1];
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
                  SEEK_SET
                  );

                if (-1 == can_seek_arp)
                  {
                    fatal_exit_k = 10004;
                    strcpy(error_message_k, "Cannot seek on temporary file");
                    break;
                  }

                my_VAL_data.VAL_is_dir = 0;

                if (!mode_is_VAL_arp)
                  {
		    status = dump_regular_file(our_update_file_open__arp, st);
                    switch (status)
                      {
                      case dump_status_ok:
                      case dump_status_short:
                        ;
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
                    my_VAL_data = aak_ptr->VAL_data__arp;                            //feito
                    my_VAL_data.VAL_is_dir = 0;
                    if (dump_regular_file_VAL_arp(our_update_file_open__arp, &my_VAL_data))
                      {
                        sprintf(warning_message_k, "Cannot process file %s", aak_ptr->filename_k);
                        add_more_one(warning_message_k);
                      }
                  }

skip_amanda:    ;
              }
          }
        aak_ptr = aak_ptr->next_ar;
      }

    free(temp_arp_1), free(temp_arp_2), free(temp_arp_3);
  }
}
