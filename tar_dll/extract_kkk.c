///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////2021 z
//defines...

int encryption_detected_z = -1;

/**
 * It will retrieve the extraction information for each call,
 * see the sample project to see how to use it correctly
 *
 * @param warning_ar the warning information if any
 *
 * @param filename_ar the filename that was just extracted
 *
 * @param folder_feline if it was a folder
 *
 * @return always 0
 *
 */
int __stdcall get_extraction_progress_information_ar(
    char *warning_ar,
    char *filename_ar,
    char *folder_feline)
{
    strcpy(warning_ar, warning_info);
    strcpy(filename_ar, extracting_filename_ar);
    strcpy(folder_feline, creating_folder_maria);
    return 0;
}

typedef int (*tar_extractor_t)(char *file_name, int typeflag);

GLOBAL bool absolute_names_option = false;

#define IS_ABSOLUTE_PATH(P) ISSLASH((P)[0])
#define IS_PATH_WITH_DIR(P) (strchr(P, '/') != NULL)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////2021 z
//functions...

void extract_archive(void);

bool contains_dot_dot(char const *name);

static int
prepare_to_extract(char const *file_name, int typeflag, tar_extractor_t *fun);

static int
extract_file(char *file_name, int typeflag);

void trocadordebackslashtras(char *path);

int rspmakedir(char *path);

int ispathfolder(char *path);

int ispathreadonly(char *path);

int createtestfilename(char *path1);

char *
strrstr(char *s1, char *s2);

int ispathfile(char *path);

int rspmakedir_v2(char *path);

static int
extract_skip(char *file_name, int typeflag);

static int
extract_failure(char *file_name, int typeflag);

static int
open_output_file(char const *file_name, int typeflag, mode_t mode,
                 int file_created, mode_t *current_mode,
                 mode_t *current_mode_mask, char *constructed_filename_kp);

/**
 * Tar related function, version 1.34
 *
 */
static int
extract_failure(__attribute__((unused)) char *file_name, __attribute__((unused)) int typeflag)
{
    return 1;
}

/**
 * Tar related function, version 1.34
 *
 */
static int
extract_skip(__attribute__((unused)) char *file_name, __attribute__((unused)) int typeflag)
{
    skip_member();
    return 0;
}

/**
 * It will dump a dir to the disk, modified to windows
 *
 */
static int
extract_dir(char *file_name_in_arp, int typeflag)
{
    int status = 0;
    char file_name[MAX_PATH + 1] = {0};

    if (MAX_PATH < strlen(file_name_in_arp))
    {
        memcpy(file_name, file_name_in_arp, MAX_PATH - 2);
        strcpy(error_message_k, "Path came from Linux and is above MAX_PATH, aborting...");
        fatal_exit_k = 10002;
    }
    else
    {
        strcpy(file_name, file_name_in_arp);
    }

    if (typeflag == GNUTYPE_DUMPDIR)
        skip_member();

    if (mode_is_update_arp)
    {
        if (0 == strcmp(".", file_name))
        {
            return status;
        }

        if (0 == strcmp("..", file_name))
        {
            return status;
        }

        add_more_one_is_amanda_update_(
            file_name,
            0,
            current_stat_info.mtime.tv_sec,
            true,
            0,
            0,
            0,
            current_stat_info.mtime.tv_sec,
            NULL);
        return status;
    }

    char destination_folder_kp[1024];
    {
        strcpy(destination_folder_kp, extract_folder_final);
        strcat(destination_folder_kp, file_name);
        trocadordebackslashtras(destination_folder_kp);

        if (!mode_is_update_arp)
            rspmakedir_v2(destination_folder_kp);
    }
    warning_info[0] = 0;
    extracting_filename_ar[0] = 0;
    strcpy(creating_folder_maria, file_name);
    my_func_ar_(AAKP_EXTRACT_PROCESS);

    if (!mode_is_update_arp)
    {
        HANDLE hFile;
        FILETIME ftLocal;
        SYSTEMTIME st;
        struct tm tm_k;

        __time64_t s = current_stat_info.mtime.tv_sec;

        if (!_gmtime64(&s))
        {
            s = time(NULL);
        }
        tm_k = 1 ? *_gmtime64(&s) : *_localtime64(&s);

        hFile =
            CreateFileW(amanda_utf8towide_1_(destination_folder_kp),
                        GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                        NULL,
                        OPEN_EXISTING,
                        FILE_FLAG_BACKUP_SEMANTICS,
                        NULL);

        if (INVALID_HANDLE_VALUE != hFile)
        {
            st.wYear = (WORD)tm_k.tm_year + 1900;
            st.wMonth = (WORD)tm_k.tm_mon + 1;
            st.wDayOfWeek = (WORD)tm_k.tm_wday;
            st.wDay = (WORD)tm_k.tm_mday;
            st.wHour = (WORD)tm_k.tm_hour;
            st.wMinute = (WORD)tm_k.tm_min;
            st.wSecond = (WORD)tm_k.tm_sec;
            st.wMilliseconds = 0;
            SystemTimeToFileTime(&st, &ftLocal);
            SetFileTime(hFile, &ftLocal, NULL, &ftLocal);
            CloseHandle(hFile);
        }
        else
        {
            pedro_dprintf(2, "%s: Cannot set filetime on folder\n", file_name);
        }
    }

    return status;
}

/**
 * It will dump to disk a folder, in the extraction of a VAL file
 *
 * @param file_name_in_arp the folder to be generated
 *
 * @return always 0, the error if any will be in the global
 * variable fatal_exit_k and error_message_k
 *
 */
static int
extract_dir_VAL(char *file_name_in_arp)
{
    int status = 0;
    static char file_name[AMANDA__SIZE + 1];

    memset(file_name, 0, sizeof(file_name));

    if (AMANDA__SIZE < strlen(file_name_in_arp))
    {
        memcpy(file_name, file_name_in_arp, AMANDA__SIZE - 2);
        strcpy(error_message_k, "Path came from Linux and is above 32767, aborting...");
        fatal_exit_k = 10002;
    }
    else
    {
        strcpy(file_name, file_name_in_arp);
    }

    if (mode_is_update_arp)
    {
        if (0 == strcmp(".", file_name))
        {
            return status;
        }

        if (0 == strcmp("..", file_name))
        {
            return status;
        }

        add_more_one_is_amanda_update_(
            file_name,
            0,
            my_VAL_data_arp.VAL_timestamp,
            true,
            0,
            0,
            my_VAL_data_arp.VAL_is_encrypted,
            my_VAL_data_arp.VAL_timestamp64,
            &my_VAL_data_arp);
        return status;
    }

    static char destination_folder_kp[AMANDA__SIZE];

    {
        strcpy(destination_folder_kp, extract_folder_final);
        strcat(destination_folder_kp, file_name);
        trocadordebackslashtras(destination_folder_kp);

        if (!mode_is_update_arp)
            rspmakedir_v2(destination_folder_kp);
    }
    warning_info[0] = 0;
    extracting_filename_ar[0] = 0;
    strcpy(creating_folder_maria, file_name);
    my_func_ar_(AAKP_EXTRACT_PROCESS);

    if (!mode_is_update_arp)
    {
        HANDLE hFile;

        if (!my_VAL_data_arp.Val_is_using_filetime)
        {
            FILETIME ftLocal;
            SYSTEMTIME st;
            struct tm tm_k;

            __time64_t s;

            s = my_VAL_data_arp.VAL_timestamp64;

            if (0 == my_VAL_data_arp.VAL_timestamp64)
            {
                s = my_VAL_data_arp.VAL_timestamp;
            }

            if (!_gmtime64(&s))
            {
                s = time(NULL);
            }

            tm_k = 1 ? *_gmtime64(&s) : *_localtime64(&s);

            hFile =
                CreateFileW(permissive_name_m_(amanda_utf8towide_1_(destination_folder_kp)),
                            GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            FILE_FLAG_BACKUP_SEMANTICS,
                            NULL);

            if (INVALID_HANDLE_VALUE != hFile)
            {
                st.wYear = (WORD)tm_k.tm_year + 1900;
                st.wMonth = (WORD)tm_k.tm_mon + 1;
                st.wDayOfWeek = (WORD)tm_k.tm_wday;
                st.wDay = (WORD)tm_k.tm_mday;
                st.wHour = (WORD)tm_k.tm_hour;
                st.wMinute = (WORD)tm_k.tm_min;
                st.wSecond = (WORD)tm_k.tm_sec;
                st.wMilliseconds = 0;
                SystemTimeToFileTime(&st, &ftLocal);
                SetFileTime(hFile, &ftLocal, NULL, &ftLocal);
                CloseHandle(hFile);
            }
            else
            {
                pedro_dprintf(2, "%s: Cannot set filetime on folder\n", file_name);
            }
        }
        else
        {
            hFile =
                CreateFileW(permissive_name_m_(amanda_utf8towide_1_(destination_folder_kp)),
                            GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            FILE_FLAG_BACKUP_SEMANTICS,
                            NULL);

            if (INVALID_HANDLE_VALUE != hFile)
            {
                if (!SetFileTime(hFile, &my_VAL_data_arp.CreationTime___junior,
                                 &my_VAL_data_arp.LastAccessTime_junior,
                                 &my_VAL_data_arp.LastWriteTime__junior))
                {
                    ;
                }

                CloseHandle(hFile);
            }
            else
            {
                pedro_dprintf(2, "%s: Cannot set filetime on folder\n", file_name);
            }
        }
    }
    //assert(0);
    return status;
}

/**
 * It will test the utf-8 encoded path to see if it do exist and is a file
 *
 * @param path utf-8 encoded path to test
 *
 * @return 0 if the path is not a file or valid, 1 if it is a readable
 * file
 *
 */
int ispathfile(char *path)
{
    char x[1027];
    int ret;

    strcpy(x, path);
    ret = strlen(x);

    if (!ret)
    {
        return 0;
    }

    ret = GetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(x)));

    if ((int)0xffffffff != (int)ret)
    {
        if (ret & (0x00000010))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

/**
 * It will return the last occurrence of a string inside the string
 *
 * @param s1 the string to search
 *
 * @param s2 the input string
 *
 * @return a pointer if the string was found or NULL otherwise
 *
 */
char *
strrstr(char *s1, char *s2)
{
    char *sc2, *psc1, *ps1;
    if (*s2 == '\0')
    {
        return ((char *)s1);
    }
    ps1 = s1 + strlen(s1);
    while (ps1 != s1)
    {
        --ps1;
        for (psc1 = ps1, sc2 = s2;;)
        {
            if (*(psc1++) != *(sc2++))
            {
                break;
            }
            else if (*sc2 == '\0')
            {
                return ((char *)ps1);
            }
        }
    }
    return ((char *)((void *)0));
}

/**
 * It will split the path in folder and file (Unix based)
 *
 * @param path the input path
 *
 * @param onlypath only the path, can be NULL if not required
 *
 * @param onlyfilename only the filename, can be NULL if not required
 *
 * @return always 0
 *
 */
int stripfilenameandpath_unix_arp(char *path, char *onlypath, char *onlyfilename)
{
    char *ptr;

    ptr = strrstr(path, "/");

    if (ptr)
    {
        if (onlypath)
        {
            strcpy(onlypath, path),
                onlypath[ptr - path] = 0;
        }

        if (onlyfilename)
        {
            strcpy(onlyfilename, &path[ptr - path + 1]);
        }
    }
    else
    {
        if (onlypath)
        {
            strcpy(onlypath, "");
        }
        if (onlyfilename)
        {
            strcpy(onlyfilename, path);
        }
    }

    return 0;
}

/**
 * It will split the path in folder and file (Windows based),
 * UNC capable too
 *
 * @param path the input path
 *
 * @param onlypath only the path, can be NULL if not required
 *
 * @param onlyfilename only the filename, can be NULL if not required
 *
 * @return always 0
 *
 */
int stripfilenameandpath(char *path, char *onlypath, char *onlyfilename)
{
    char *ptr;

    ptr = strrstr(path, "\\");

    if (ptr)
    {
        if (onlypath)
        {
            strcpy(onlypath, path),
                onlypath[ptr - path] = 0;
        }

        if (onlyfilename)
        {
            strcpy(onlyfilename, &path[ptr - path + 1]);
        }
    }
    else
    {
        if (onlypath)
        {
            strcpy(onlypath, "");
        }
        if (onlyfilename)
        {
            strcpy(onlyfilename, path);
        }
    }

    return 0;
}

int __stdcall stripfilenameandpath_amanda_s_smart_ape(char *path, char *onlypath, char *onlyfilename)
{
    return stripfilenameandpath(path, onlypath, onlyfilename);
}

char *strrstr_ends_with(char *str, char *substr)
{
    char *ptr_i;

    ptr_i = strrstr(str, substr);

    if (ptr_i)
    {
        if (strlen(ptr_i) == strlen(substr))
        {
            return ptr_i;
        }
    }

    return NULL;
}

/**
 * It will read the extension to detect whether the file is a valid compressed
 * file
 *
 * @param filename_in_z the filename
 *
 * @return 0 if not compressed, 1 otherwise
 *
 */
bool __amandacall is_compressed_z(char *filename_in_z)
{
    char *whole_path_copy_arp = filename_in_z;
    char *ptr_arp;

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.Z2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.Z2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.gz")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.gzip2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.gzip2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.bzip3")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.bzip3")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzma")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.xz")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.Z")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzo")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz4")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.bz2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.br")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.zst")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.gz")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzma")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.xz")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.Z")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzo")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz4")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.bz2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.br")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.zst")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.gzip2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.bzip3")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzo2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.br2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz5")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.gzip2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.bzip3")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzo2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.br2")))
    {
        return 1;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz5")))
    {
        return 1;
    }

    return 0;
}

/**
 * It will just add to the filename_out_z the extension of the
 * filename_in_z, because some compression formats like lzma and
 * brotli needs always the correct extension to extrac or list
 * process
 *
 * @param filename_in_z the input filename
 *
 * @param filename_out_z the output file that will have the
 * extension adjusted
 *
 * @return void
 *
 */
void __amandacall adjust_extension_z(char *filename_in_z, char *filename_out_z)
{
    char *ptr_arp;
    char *whole_path_copy_arp = filename_in_z;

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.Z2")))
    {
        strcat(filename_out_z, ".tar.Z2");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.Z2")))
    {
        strcat(filename_out_z, ".val.Z2");
        return;
    }
    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzo2")))
    {
        strcat(filename_out_z, ".tar.lzo2");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.br2")))
    {
        strcat(filename_out_z, ".tar.br2");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz5")))
    {
        strcat(filename_out_z, ".tar.lz5");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzo2")))
    {
        strcat(filename_out_z, ".val.lzo2");
        return;
    }
    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.br2")))
    {
        strcat(filename_out_z, ".val.br2");
        return;
    }
    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz5")))
    {
        strcat(filename_out_z, ".val.lz5");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.gz")))
    {
        strcat(filename_out_z, ".tar.gz");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.gzip2")))
    {
        strcat(filename_out_z, ".tar.gzip2");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.gzip2")))
    {
        strcat(filename_out_z, ".val.gzip2");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.bzip3")))
    {
        strcat(filename_out_z, ".tar.bzip3");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.bzip3")))
    {
        strcat(filename_out_z, ".val.bzip3");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzma")))
    {
        strcat(filename_out_z, ".tar.lzma");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz")))
    {
        strcat(filename_out_z, ".tar.lz");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.xz")))
    {
        strcat(filename_out_z, ".tar.xz");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.Z")))
    {
        strcat(filename_out_z, ".tar.Z");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzo")))
    {
        strcat(filename_out_z, ".tar.lzo");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz4")))
    {
        strcat(filename_out_z, ".tar.lz4");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.bz2")))
    {
        strcat(filename_out_z, ".tar.bz2");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.br")))
    {
        strcat(filename_out_z, ".tar.br");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.zst")))
    {
        strcat(filename_out_z, ".tar.zst");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.gz")))
    {
        strcat(filename_out_z, ".val.gz");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzma")))
    {
        strcat(filename_out_z, ".val.lzma");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz")))
    {
        strcat(filename_out_z, ".val.lz");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.xz")))
    {
        strcat(filename_out_z, ".val.xz");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.Z")))
    {
        strcat(filename_out_z, ".val.Z");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzo")))
    {
        strcat(filename_out_z, ".val.lzo");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz4")))
    {
        strcat(filename_out_z, ".val.lz4");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.bz2")))
    {
        strcat(filename_out_z, ".val.bz2");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.br")))
    {
        strcat(filename_out_z, ".val.br");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.zst")))
    {
        strcat(filename_out_z, ".val.zst");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar")))
    {
        strcat(filename_out_z, ".tar");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val")))
    {
        strcat(filename_out_z, ".val");
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".iso")))
    {
        strcat(filename_out_z, ".iso");
        return;
    }

    return;
}

/**
 * It will replace the extension with a new one provided
 *
 * @param whole_path_arp the input path
 *
 * @param new_extension_arp the new extension
 *
 * @param out_data_arp the output file
 *
 */
void __stdcall replace_extension_arp(
    char *whole_path_arp,
    char *new_extension_arp,
    char *out_data_arp)
{
    char *ptr_arp;
    char whole_path_copy_arp[1024];

    strcpy(whole_path_copy_arp, whole_path_arp);

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".7z")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".zip")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz5")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz5")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.Z2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.Z2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzo2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzo2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.br2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.br2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.bzip3")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.bzip3")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.gzip2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.gzip2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }
    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.gz")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.gzip2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.gzip2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.bzip3")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.bzip3")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzma")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.xz")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.Z")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lzo")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.lz4")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.bz2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.br")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar.zst")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.gz")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzma")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.xz")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.Z")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lzo")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.lz4")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.bz2")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.br")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val.zst")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".tar")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".val")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    if ((ptr_arp = strrstr_ends_with(whole_path_copy_arp, ".iso")))
    {
        strcpy(ptr_arp, ".");
        strcat(ptr_arp, new_extension_arp);
        strcpy(out_data_arp, whole_path_copy_arp);
        return;
    }

    strcpy(out_data_arp, whole_path_arp);
    strcat(out_data_arp, ".");
    strcat(out_data_arp, new_extension_arp);
    return;
}

#define e_free free
#define e_malloc malloc

/**
 * It will create a test filename on the given path and delete
 * it just to see if it is writable
 *
 * @param path1 the folder where the file need to be created
 *
 * @return 0 on error, 1 otherwise
 *
 */
int createtestfilename(char *path1)
{
    int ret;
    static char path[AMANDA__SIZE];
    strcpy(path, path1);
    ret = strlen(path);
    if (path[ret - 1] != '\\')
    {
        path[ret] = '\\';
        path[ret + 1] = 0;
    }
    {
        static WCHAR fixo_w_ar[1024];
        static WCHAR path_w_ar[1024];
        wcscpy(path_w_ar, permissive_name_m_(amanda_utf8towide_1_(path)));
        ret = GetTempFileNameW(path_w_ar, L"BW_AR_", 0, fixo_w_ar);
        if (ret == 0)
        {
            return 0;
        }
        else
        {
            DeleteFileW(permissive_name_m_(fixo_w_ar));
            return 1;
        }
    }
}

/**
 * It will just create a windows based temp file using the
 * signature_z information
 *
 * @param path1 the path where it will create
 *
 * @param out_z the utf-8 encoded temp file
 *
 * @param signature_z the 3 characters to be used as the initial data
 * on the destination temp file
 *
 * @return 0 on error, 1 otherwise
 *
 */
int createtempfilename_and_keep_z(char *path1, char *out_z, WCHAR *signature_z)
{
    int ret;
    static char path[AMANDA__SIZE];
    strcpy(path, path1);
    ret = strlen(path);

    if (path[ret - 1] != '\\')
    {
        path[ret] = '\\';
        path[ret + 1] = 0;
    }
    {
        static WCHAR fixo_w_ar[AMANDA__SIZE_w + 1];
        static WCHAR path_w_ar[AMANDA__SIZE_w + 1];
        wcscpy(path_w_ar, amanda_utf8towide_1_(path));
        ret = GetTempFileNameW(permissive_name_m_(path_w_ar), signature_z, 0, fixo_w_ar);
        if (ret == 0)
        {
            return 0;
        }
        else
        {
            strcpy(out_z,
                   valquiria_wide_to_utf8(remove_permissive_name_m_(fixo_w_ar)));
            return 1;
        }
    }
}

/**
 * To know whether the path is read-only
 *
 * @param path the path to test
 *
 * @return 1 if the path is read-only, -1 on error and 0 otherwise (if not read-only)
 *
 */
int ispathreadonly(char *path)
{
    char x[1027];
    int ret;
    strcpy(x, path);
    ret = strlen(x);
    if (!ret)
    {
        return -1;
    }

    if (ret < 2)
    {
        return -1;
    }

    if (x[0] == '\\' && x[1] == '\\')
    {
        goto UNC;
    }

    if (tolower(x[0]) < 'a')
    {
        return -1;
    }

    if (tolower(x[0]) > 'z')
    {
        return -1;
    }

    if (tolower(x[1]) != ':')
    {
        return -1;
    }

UNC:

    ret = GetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(x)));
    if ((int)0xffffffff != (int)ret)
    {
        if (0x00000010 & ret)
        {
            if (createtestfilename(x))
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

/**
 * To know whether the path is valid and a folder
 *
 * @param path the path to test
 *
 * @return 0, if invalid or not a folder, 1 if it is a folder
 *
 */
int ispathfolder(char *path)
{
    char x[1027];
    int ret;
    strcpy(x, path);
    ret = strlen(x);

    if (!ret)
    {
        return 0;
    }

    if (ret < 2)
    {
        return 0;
    }

    if (x[0] == '\\' && x[1] == '\\')
    {
        goto UNC;
    }

    if (tolower(x[0]) < 'a')
    {
        return 0;
    }

    if (tolower(x[0]) > 'z')
    {
        return 0;
    }

    if (x[1] != ':')
    {
        return 0;
    }

UNC:

    ret = GetFileAttributesW(permissive_name_m_(
        amanda_utf8towide_1_(x)));

    if ((int)0xffffffff != (int)ret)
    {
        if (ret & (0x00000010))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

/**
 * Function to recursively create a path, it will try to create each subfolder
 * since the first one and not only the last subfolder
 *
 * @param path the path to create, cannot be relative (remember it)
 *
 * @return 0 if ok, an error otherwise
 *
 */
int rspmakedir(char *path)
{
    int ret;
    int i;
    char *temp;
    ret = strlen(path);
    if (!ret)
    {
        return 1;
    }
    temp = e_malloc(ret + 2);
    strcpy(temp, path);

    if (ret < 2)
    {
        e_free(temp);
        return 7;
    }

    if (ret != 3)
    {
        if (temp[ret - 1] == '\\')
        {
            temp[ret - 1] = 0;
        }
    }

    ret = strlen(temp);
    if (temp[0] == '\\' && temp[1] == '\\')
    {
        goto unc;
    }

    if (tolower(temp[0]) < 'a' || tolower(temp[0]) > 'z' || temp[1] != ':')
    {
        e_free(temp);
        return 2;
    }

    if (ret)
    {
        for (i = 0; i < ret; i++)
        {
            if (temp[i] == '\\')
            {
                char temp1;
                temp1 = temp[i + 1];
                temp[i + 1] = 0;

                if (0 == ispathfolder(temp))
                    CreateDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp)), ((void *)0));

                if (strlen(temp) != 3)
                {
                    char temp4[1024];

                    strcpy(temp4, temp);

                    temp4[strlen(temp4) - 1] = 0;
                }

                temp[i + 1] = temp1;
            }
        }

        if (0 == ispathfolder(temp))
            CreateDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp)), ((void *)0));
    }

    if (ispathfolder(temp))
    {
        if (!ispathreadonly(temp))
        {
            e_free(temp);
            return 0;
        }
        else
        {
            e_free(temp);
            return 15;
        }
    }
    else
    {
        if (ispathfile(temp))
        {
            e_free(temp);
            return 17;
        }
        else
        {
            e_free(temp);
            return 4;
        }
    }
    e_free(temp);
    return 0;
unc:

    if (ret)
    {
        for (i = 0; i < ret; i++)
        {
            if (i == 0)
            {
                i = 2;
            }

            if (temp[i] == '\\')
            {
                char temp1;
                temp1 = temp[i + 1];
                temp[i + 1] = 0;
                if (0 == ispathfolder(temp))
                    CreateDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp)), ((void *)0));

                if (strlen(temp) != 3)
                {
                    char temp4[1024];

                    strcpy(temp4, temp);

                    temp4[strlen(temp4) - 1] = 0;

                    if (ispathfile(temp4))
                    {
                        e_free(temp);
                        return 17;
                    }
                }

                temp[i + 1] = temp1;
            }
        }
        if (0 == ispathfolder(temp))
            CreateDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp)), ((void *)0));
    }

    if (ispathfolder(temp))
    {
        if (!ispathreadonly(temp))
        {
            e_free(temp);
            return 0;
        }
        else
        {
            e_free(temp);
            return 15;
        }

        e_free(temp);
        return 0;
    }
    else
    {
        if (ispathfile(temp))
        {
            e_free(temp);
            return 17;
        }
        else
        {
            e_free(temp);
            return 6;
        }
    }

    e_free(temp);
    return 0;
}

/**
 * Function to create the whole path, it will try to create each
 * subfolder until the end recursively
 *
 * @param path the path to create, cannot be relative (remember it)
 *
 * @return 0 if ok, an error otherwise
 *
 */
int rspmakedir_v2(char *path)
{
    int ret;
    int i;
    char *temp;

    ret = strlen(path);
    if (!ret)
    {
        return 1;
    }

    temp = e_malloc(ret + 2);

    strcpy(temp, path);

    if (ret < 2)
    {
        e_free(temp);
        return 7;
    }

    if (ret != 3)
    {
        if (temp[ret - 1] == '\\')
        {
            temp[ret - 1] = 0;
        }
    }

    ret = strlen(temp);
    if (temp[0] == '\\' && temp[1] == '\\')
    {
        goto unc;
    }

    if (tolower(temp[0]) < 'a' || tolower(temp[0]) > 'z' || temp[1] != ':')
    {
        e_free(temp);
        return 2;
    }

    if (ret)
    {
        for (i = 0; i < ret; i++)
        {
            if (temp[i] == '\\')
            {
                char temp1;
                temp1 = temp[i + 1];
                temp[i + 1] = 0;
                if (0 == ispathfolder(temp))
                    CreateDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp)), ((void *)0));

                if (strlen(temp) != 3)
                {
                    char temp4[1024];

                    strcpy(temp4, temp);

                    temp4[strlen(temp4) - 1] = 0;
                }

                temp[i + 1] = temp1;
            }
        }

        if (0 == ispathfolder(temp))
            CreateDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp)), ((void *)0));
    }

    return 0;
unc:

    if (ret)
    {
        for (i = 0; i < ret; i++)
        {
            if (i == 0)
            {
                i = 2;
            }

            if (temp[i] == '\\')
            {
                char temp1;
                temp1 = temp[i + 1];
                temp[i + 1] = 0;
                if (0 == ispathfolder(temp))
                    CreateDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp)), ((void *)0));

                if (strlen(temp) != 3)
                {
                    static char temp4[AMANDA__SIZE];

                    strcpy(temp4, temp);

                    temp4[strlen(temp4) - 1] = 0;

                    if (ispathfile(temp4))
                    {
                        e_free(temp);
                        return 17;
                    }
                }

                temp[i + 1] = temp1;
            }
        }
        if (0 == ispathfolder(temp))
            CreateDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp)), ((void *)0));
    }

    e_free(temp);
    return 0;
}

/**
 * It will replace character '/' with '\\' on the given path, very useful
 * to programmers converting code from Unix to Windows... not using cygwin
 *
 * @param path the path to replace the character
 *
 * @return void
 *
 */
void trocadordebackslashtras(char *path)
{
    int ret;
    char aqui;
    int i;

    ret = strlen(path);

    if (ret)
    {
        for (i = 0; i < ret; i++)
        {
            aqui = path[i];
            if (aqui == '/')
            {
                path[i] = '\\';
            }
        }
    }
}

/**
 * Tar related function, version 1.34, with small modifications for windows,
 * it will open the destination file
 *
 * @param file_name the entry filename
 *
 * @return the file opened or -1 on error
 *
 */
static int
open_output_file(char const *file_name, int typeflag, __attribute__((unused)) mode_t mode,
                 __attribute__((unused)) int file_created, __attribute__((unused)) mode_t *current_mode,
                 __attribute__((unused)) mode_t *current_mode_mask, char *constructed_filename_kp)
{
    constructed_filename_kp[0] = 0;
    int fd;

    int openflag = (O_WRONLY | O_BINARY | O_CREAT | O_TRUNC);

    if (typeflag == CONTTYPE)
    {
        static int conttype_diagnosed;

        if (!conttype_diagnosed)
        {
            conttype_diagnosed = 1;

            pedro_dprintf(2, "Extracting contiguous files as regular files");
            /********/ printf("Extracting contiguous files as regular files");
        }
    }

    {
        char destination_file_kp[1024];
        char path_to_create_kp[1024] = {0};

        strcpy(destination_file_kp, extract_folder_final);
        strcat(destination_file_kp, file_name);
        trocadordebackslashtras(destination_file_kp);
        assert('\\' != file_name[strlen(file_name) - 1]);
        stripfilenameandpath(destination_file_kp, path_to_create_kp, NULL);
        assert(strlen(path_to_create_kp) != strlen(destination_file_kp));
        rspmakedir_v2(path_to_create_kp);
        strcpy(constructed_filename_kp, destination_file_kp);

        fd = _wopen(amanda_utf8towide_1_(destination_file_kp), openflag, _S_IWRITE);
    }

    strcpy(extracting_filename_ar, file_name);

    if (-1 == fd)
    {
        got_a_warning_ar = 1;
        sprintf(warning_info, "Cannot open file %s to write", file_name);
    }
    else
    {
        warning_info[0] = 0;
    }

    while (extract_pause__flag)
    {
        if (extract_cancel_flag)
        {
            break;
        }
        Sleep(50);
    }
    creating_folder_maria[0] = 0;
    my_func_ar_(AAKP_EXTRACT_PROCESS);

    return fd;
}

/**
 * VAL based function, it will open the file to write
 *
 * @param file_name the filename to open as write access
 *
 * @return the opened file value or -1 on error
 *
 */
static int
open_output_file_VAL(char const *file_name,
                     __attribute__((unused)) int typeflag,
                     __attribute__((unused)) mode_t mode,
                     __attribute__((unused)) int file_created,
                     __attribute__((unused)) mode_t *current_mode,
                     __attribute__((unused)) mode_t *current_mode_mask,
                     __attribute__((unused)) char *constructed_filename_kp)
{
    constructed_filename_kp[0] = 0;
    int fd;

    int openflag = (O_WRONLY | O_BINARY | O_CREAT | O_TRUNC);

    {
        static char destination_file_kp[AMANDA__SIZE];
        static char path_to_create_kp[AMANDA__SIZE];

        memset(destination_file_kp, 0, sizeof(destination_file_kp));
        memset(path_to_create_kp, 0, sizeof(path_to_create_kp));

        strcpy(destination_file_kp, extract_folder_final);
        strcat(destination_file_kp, file_name);
        trocadordebackslashtras(destination_file_kp);
        assert('\\' != file_name[strlen(file_name) - 1]);
        stripfilenameandpath(destination_file_kp, path_to_create_kp, NULL);
        assert(strlen(path_to_create_kp) != strlen(destination_file_kp));
        rspmakedir_v2(path_to_create_kp);
        strcpy(constructed_filename_kp, destination_file_kp);

        if (!SetFileAttributesW(
                permissive_name_m_(amanda_utf8towide_1_(destination_file_kp)),
                FILE_ATTRIBUTE_ARCHIVE))
        {
            ;
        }

        fd = _wopen(permissive_name_m_(amanda_utf8towide_1_(destination_file_kp)),
                    openflag, _S_IWRITE);

        pedro_dprintf(0, "val %d abrindo arquivo com perm %s\n", fd, destination_file_kp);

        //assert(0);
    }

    strcpy(extracting_filename_ar, file_name);

    if (-1 == fd)
    {
        got_a_warning_ar = 1;
        sprintf(warning_info, "Cannot open file %s to write", file_name);
    }
    else
    {
        warning_info[0] = 0;
    }

    while (extract_pause__flag)
    {
        if (extract_cancel_flag)
        {
            break;
        }
        Sleep(50);
    }
    creating_folder_maria[0] = 0;
    my_func_ar_(AAKP_EXTRACT_PROCESS);

    return fd;
}

/**
 * Only for Tar files, it will check to see if in the file
 * the information stored during the encryption is available,
 * and if yes what is the encryption used, notice that for the
 * moment the only software capable of using these encryption
 * methods is the Parolin project, loading these encrypted files
 * with tar.exe or Winrar or 7zip will only report an invalid Tar
 * file
 *
 * @param file_arp_utf_8 the file to test, utf-8 based
 *
 * @return false if not encrypted, true otherwise
 */
bool is_encrypted_gnu_tar_arp(char *file_arp_utf_8)
{
    int64_t filesize_arp = getfilesize_ar(file_arp_utf_8);
    int64_t filesize_arp_b;
    char buffer_arp[300];
    FILE *amanda_file;
    int len_arp;

    amanda_file = _wfopen(amanda_utf8towide_1_(file_arp_utf_8), L"rb");
    if (amanda_file)
    {
        len_arp = fread(&ret_arp_, 1, 4, amanda_file);

        if (4 == len_arp)
        {

            if (
                0x706c6176 == ret_arp_ ||
                (0x706c6176 - 1) == ret_arp_ ||
                (0x706c6176 - 2) == ret_arp_ ||
                (0x706c6176 - 3) == ret_arp_ ||
                (0x706c6176 - 4) == ret_arp_ ||
                (0x706c6176 - 5) == ret_arp_)
            {

                len_arp = fread(buffer_arp, 1, 64, amanda_file);

                if (64 == len_arp)
                {

                    len_arp = fread(&filesize_arp_b, 1, 8, amanda_file);

                    if (8 == len_arp)
                    {

                        if (filesize_arp == (filesize_arp_b + 4 + 64 + 8))
                        {

                            switch (ret_arp_)
                            {
                            case 0x706c6176:
                                encryption_detected_z = ARP_AES;
                                break;

                            case 0x706c6176 - 1:
                                encryption_detected_z = ARP_RC4;
                                break;

                            case 0x706c6176 - 2:
                                encryption_detected_z = ARP_SERPENT;
                                break;

                            case 0x706c6176 - 3:
                                encryption_detected_z = ARP_MARS;
                                break;

                            case 0x706c6176 - 4:
                                encryption_detected_z = ARP_RC6;
                                break;

                            case 0x706c6176 - 5:
                                encryption_detected_z = ARP_TWOFISH;
                                break;
                            }

                            fclose(amanda_file);
                            return true;
                        }
                    }
                }
            }
        }

        fclose(amanda_file);
    }

    return false;
}

/**
 * It will extract an entry of the Tar
 * file to disk
 *
 * @param file_name_in_arp the utf8 based destination file
 *
 * @return
 */
static int
extract_file(char *file_name_in_arp, int typeflag)
{
    __int64 value_for_ftell = 0;
    char constructed_filename_kp[MAX_PATH + 1];
    int fd;
    int status;
    mode_t mode = 1;
    off_t size;
    size_t count;
    size_t written;
    time_t mtime_tv_sec_arp = 0;
    union block *data_block;
    char file_name[MAX_PATH + 1] = {0};

    if (MAX_PATH < strlen(file_name_in_arp))
    {
        memcpy(file_name, file_name_in_arp, MAX_PATH - 2);
        strcpy(error_message_k, "Path came from Linux and is above MAX_PATH, aborting...");
        fatal_exit_k = 10002;
    }
    else
    {
        strcpy(file_name, file_name_in_arp);
    }

    {
        int file_created = 0;

        if (!mode_is_update_arp)
        {

            fd = open_output_file(file_name, typeflag, mode,
                                  file_created, NULL,
                                  NULL, constructed_filename_kp);

            if (0 > fd)
            {
                skip_member();
                return 1;
            }

            setmode(fd, O_BINARY);
        }
        else
        {
            fd = our_update_file_open__arp;
            value_for_ftell = _telli64(fd);
        }
    }

    mv_begin_read(&current_stat_info);
    if (current_stat_info.is_sparse)
        sparse_extract_file(fd, &current_stat_info, &size);
    else
        for (size = current_stat_info.stat.st_size; size > 0;)
        {
            mv_size_left(size);

            data_block = find_next_block();
            if (!data_block)
            {
                pedro_dprintf(2, "Unexpected EOF in archive");
                break;
            }

            written = available_space_after(data_block);

            if (written > (size_t)size)
                written = size;
            errno = 0;
            count = blocking_write(fd, data_block->buffer, written);
            size -= written;

            set_next_block_after((union block *)(data_block->buffer + written - 1));
            if (count != written)
            {
                break;
            }
        }

    skip_file(size);

    mv_end();

    status = 0;

    if (!mode_is_update_arp)
        status = close(fd);
    if (!mode_is_update_arp)
    {
#if 0
      char temp_file_arp[1024];
      time_t s = current_stat_info.mtime.tv_sec;
      struct _utimbuf ut = { 0 };
      ut.actime = current_stat_info.mtime.tv_sec;
      ut.modtime = current_stat_info.mtime.tv_sec;
      _wutime(amanda_utf8towide_1_(constructed_filename_kp), &ut);
#else
        if (is_encrypted_gnu_tar_arp(constructed_filename_kp))
        {
            int64_t temp_arp;
            int64_t temp_2_arp;
            char temp_file_arp[1024];
            //4 � wrong password
            update_progress_arp(&temp_arp);

            strcpy(temp_file_arp, constructed_filename_kp);
            strcat(temp_file_arp, ".$_$arp.tmp");

            ret_arp_ = decrypt_arp(constructed_filename_kp, temp_file_arp, the_pass_arp, &temp_2_arp, encryption_method__i);

            if (0 == ret_arp_)
            {
                _wunlink(amanda_utf8towide_1_(constructed_filename_kp));

                _wrename(amanda_utf8towide_2_(temp_file_arp), amanda_utf8towide_1_(constructed_filename_kp));
            }
            else if (4 == ret_arp_)
            {
                _wunlink(amanda_utf8towide_1_(constructed_filename_kp));
                _wunlink(amanda_utf8towide_1_(temp_file_arp));
                fatal_exit_k = 28000;
                strcpy(error_message_k, "Wrong password used");
                return 1;
            }
            else
            {
                _wunlink(amanda_utf8towide_1_(constructed_filename_kp));
                _wunlink(amanda_utf8towide_1_(temp_file_arp));
                fatal_exit_k = 28001;
                strcpy(error_message_k, "Unexpected decryption error");
                return 1;
            }
        }
        void TimetToFileTime(time_t t, LPFILETIME pft);
        time_t s = current_stat_info.mtime.tv_sec;

        if (!gmtime(&s))
        {
            s = time(NULL);
        }

        HANDLE hFile;
        FILETIME ftime = {0};
        FILETIME ftime_in = {0};
        TimetToFileTime(s, &ftime_in);
        FileTimeToLocalFileTime(
            &ftime_in,
            &ftime);

        hFile =
            CreateFileW(amanda_utf8towide_1_(constructed_filename_kp),
                        GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                        NULL,
                        OPEN_EXISTING,
                        FILE_FLAG_BACKUP_SEMANTICS,
                        NULL);

        if (INVALID_HANDLE_VALUE != hFile)
        {
            SetFileTime(hFile, &ftime_in, NULL, &ftime_in);
            CloseHandle(hFile);
        }
        else
        {
            pedro_dprintf(2, "%s: Cannot set filetime on folder\n", file_name);
        }
#endif
    }
    else
        mtime_tv_sec_arp = current_stat_info.mtime.tv_sec;

    if (mode_is_update_arp)
    {
        add_more_one_is_amanda_update_(
            file_name,
            _telli64(fd) - value_for_ftell,
            mtime_tv_sec_arp,
            false,
            value_for_ftell,
            0,
            0,
            mtime_tv_sec_arp,
            NULL);
    }
    return status;
}

/**
 * It will extract an entry of the VAL file to disk
 *
 * @param file_name_in_arp the utf8 based file to extract
 *
 * return 0 if no error, an error value otherwise
 *
 */
static int
extract_file_VAL(char *file_name_in_arp)
{
    const int TAMANHO_AMANDA = (1 << 16) * 2;
    int remaining_arp = my_VAL_data_arp.VAL_file_size;
    int len_arp;
    char *buffer_arp = NULL;
    static char file_name[AMANDA__SIZE] = {
        0,
    };
    __time64_t mtime_tv_sec_arp;
    __int64 value_for_ftell;
    static char constructed_filename_kp[AMANDA__SIZE];
    int fd;
    int status;
    size_t count;
    mode_t mode = 1;

    if (AMANDA__SIZE < strlen(file_name_in_arp))
    {
        memset(file_name, 0, sizeof(file_name));
        memcpy(file_name, file_name_in_arp, AMANDA__SIZE - 2);
        strcpy(error_message_k, "Path is above 32767, aborting...");
        fatal_exit_k = 10002;
    }
    else
    {
        strcpy(file_name, file_name_in_arp);
    }

    int file_created = 0;

    if (!mode_is_update_arp)
    {

        fd = open_output_file_VAL(file_name, 0, mode,
                                  file_created, NULL,
                                  NULL, constructed_filename_kp);

        if (0 > fd)
        {
            if (my_VAL_data_arp.VAL_file_size)
            {
                _fseeki64(
                    decoder_file_z,
                    my_VAL_data_arp.VAL_file_size,
                    SEEK_CUR);
            }

            pedro_dprintf(2, "Skipping file %s\n", file_name);
            return 1;
        }
        value_for_ftell = 0;
        setmode(fd, O_BINARY);
    }
    else
    {
        fd = our_update_file_open__arp;
        value_for_ftell = _telli64(fd);
    }

    buffer_arp = malloc(TAMANHO_AMANDA);
    assert(buffer_arp);
    while (1)
    {
        while (extract_pause__flag)
        {
            Sleep(50);

            if (extract_cancel_flag)
            {
                fatal_exit_k = 119;
                strcpy(error_message_k, "User cancel");
                goto exit_now_arp;
            }
        }

        if (extract_cancel_flag)
        {
            fatal_exit_k = 119;
            strcpy(error_message_k, "User cancel");
            goto exit_now_arp;
        }

        len_arp = fread(buffer_arp, 1, min(TAMANHO_AMANDA, remaining_arp), decoder_file_z);
        if (0 > len_arp)
        {
            fatal_exit_k = 27020;
            strcpy(error_message_k, "Cannot read from VAL file");
            break;
        }

        if (0 == len_arp)
        {
            if (remaining_arp)
            {
                fatal_exit_k = 27021;
                strcpy(error_message_k, "Cannot read from VAL file");
            }
            break;
        }

        count = blocking_write(fd, buffer_arp, len_arp);

        if (0 > (int)count)
        {
            fatal_exit_k = 27022;
            strcpy(error_message_k, "Cannot write to destination file");
            break;
        }

        if ((int)count != (int)len_arp)
        {
            fatal_exit_k = 27023;
            strcpy(error_message_k, "Cannot write to destination file");
            break;
        }
        remaining_arp -= len_arp;
    }

exit_now_arp:;

    free(buffer_arp);
    status = 0;

    if (!mode_is_update_arp)
        status = close(fd);
    if (!mode_is_update_arp)
    {
        if (my_VAL_data_arp.VAL_is_encrypted)
        {
            int64_t temp_arp;
            int64_t temp_2_arp;
            static char temp_file_arp[AMANDA__SIZE];
            update_progress_arp(&temp_arp);
            strcpy(temp_file_arp, constructed_filename_kp);
            strcat(temp_file_arp, ".$_$arp.tmp");
            ret_arp_ = decrypt_arp(constructed_filename_kp, temp_file_arp, the_pass_arp, &temp_2_arp, encryption_method__i);

            if (0 == ret_arp_)
            {
                _wunlink(permissive_name_m_(amanda_utf8towide_1_(constructed_filename_kp)));
                _wrename(permissive_name_m_(amanda_utf8towide_2_(temp_file_arp)), permissive_name_m_v27(amanda_utf8towide_1_(constructed_filename_kp)));
            }
            else if (4 == ret_arp_)
            {
                _wunlink(permissive_name_m_(amanda_utf8towide_1_(constructed_filename_kp)));
                _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_file_arp)));
                fatal_exit_k = 28000;
                strcpy(error_message_k, "Wrong password used");
                return 1;
            }
            else
            {
                _wunlink(permissive_name_m_(amanda_utf8towide_1_(constructed_filename_kp)));
                _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_file_arp)));
                fatal_exit_k = 28001;
                strcpy(error_message_k, "Unexpected decryption error");
                return 1;
            }
        }

        if (!my_VAL_data_arp.Val_is_using_filetime)
        {
            void TimetToFileTime(time_t t, LPFILETIME pft);
            __time64_t s;

            s = my_VAL_data_arp.VAL_timestamp64;
            if (0 == my_VAL_data_arp.VAL_timestamp64)
            {
                s = my_VAL_data_arp.VAL_timestamp;
            }

            if (!_gmtime64(&s))
            {
                s = time(NULL);
            }

            HANDLE hFile;
            FILETIME ftLocal;
            SYSTEMTIME st;
            FILETIME ftime = {0};
            FILETIME ftime_in = {0};
            TimetToFileTime(s, &ftime_in);
            FileTimeToLocalFileTime(
                &ftime_in,
                &ftime);

            struct tm tm_k;
            tm_k = 1 ? *_gmtime64(&s) : *_localtime64(&s);

            hFile =
                CreateFileW(permissive_name_m_
                (amanda_utf8towide_1_
                (constructed_filename_kp)),
                            GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            FILE_FLAG_BACKUP_SEMANTICS,
                            NULL);

            if (INVALID_HANDLE_VALUE != hFile)
            {
                st.wYear = (WORD)tm_k.tm_year + 1900;
                st.wMonth = (WORD)tm_k.tm_mon + 1;
                st.wDayOfWeek = (WORD)tm_k.tm_wday;
                st.wDay = (WORD)tm_k.tm_mday;
                st.wHour = (WORD)tm_k.tm_hour;
                st.wMinute = (WORD)tm_k.tm_min;
                st.wSecond = (WORD)tm_k.tm_sec;
                st.wMilliseconds = 0;
                SystemTimeToFileTime(&st, &ftLocal);
                SetFileTime(hFile, &ftime_in, NULL, &ftime_in);
                CloseHandle(hFile);
            }
            else
            {
                pedro_dprintf(2, "%s: Cannot set filetime on file\n", file_name);
            }
        }
        else
        {
            HANDLE hFile;

            hFile =
                CreateFileW(permissive_name_m_(amanda_utf8towide_1_(constructed_filename_kp)),
                            GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            FILE_FLAG_BACKUP_SEMANTICS,
                            NULL);

            if (INVALID_HANDLE_VALUE != hFile)
            {
                SetFileTime(hFile, &my_VAL_data_arp.CreationTime___junior,
                            &my_VAL_data_arp.LastAccessTime_junior,
                            &my_VAL_data_arp.LastWriteTime__junior);

                CloseHandle(hFile);
            }
            else
            {
                pedro_dprintf(2, "%s: Cannot set filetime on file\n", file_name);
            }
        }

        if (!SetFileAttributesW(
                permissive_name_m_(amanda_utf8towide_1_(constructed_filename_kp)),
                my_VAL_data_arp.VAL_attributes))
        {
            ;
        }
    }

    mtime_tv_sec_arp = my_VAL_data_arp.VAL_timestamp64;

    if (0 == my_VAL_data_arp.VAL_timestamp64)
    {
        mtime_tv_sec_arp = my_VAL_data_arp.VAL_timestamp;
    }

    if (0 == my_VAL_data_arp.VAL_timestamp64)
    {
        my_VAL_data_arp.VAL_timestamp64 = my_VAL_data_arp.VAL_timestamp;
    }

    if (mode_is_update_arp)
    {
        add_more_one_is_amanda_update_(
            file_name,
            _telli64(fd) - value_for_ftell, //correct as usual...
            mtime_tv_sec_arp,
            false,
            value_for_ftell,
            my_VAL_data_arp.VAL_attributes,
            my_VAL_data_arp.VAL_is_encrypted,
            my_VAL_data_arp.VAL_timestamp64,
            &my_VAL_data_arp);
    }

    return status;
}

/**
 * Tar related function, version 1.34
 * Prepare to extract a file. Find extractor function.
 * Return zero if extraction should not proceed.
 *
 */
static int
prepare_to_extract(char const *file_name, int typeflag, tar_extractor_t *fun)
{
    int rc = 1;
    switch (typeflag)
    {
    case GNUTYPE_SPARSE:
        *fun = extract_file;
        rc = 1;
        break;

    case AREGTYPE:
    case REGTYPE:
    case CONTTYPE:
        if (current_stat_info.had_trailing_slash)
            *fun = extract_dir;
        else
        {
            *fun = extract_file;
            rc = 1;
        }
        break;

    case SYMTYPE:
        *fun = extract_skip;
        break;

    case LNKTYPE:
        *fun = extract_skip;
        break;

#if S_IFCHR
    case CHRTYPE:
        current_stat_info.stat.st_mode |= S_IFCHR;
        *fun = extract_skip;
        break;
#endif

#if S_IFBLK
    case BLKTYPE:
        *fun = extract_skip;
        break;
#endif

#if HAVE_MKFIFO || defined mkfifo
    case FIFOTYPE:
        *fun = extract_skip;
        break;
#endif

    case DIRTYPE:
    case GNUTYPE_DUMPDIR:
        *fun = extract_dir;
        break;

    case GNUTYPE_VOLHDR:
        *fun = extract_skip; //untested...
        break;

    case GNUTYPE_MULTIVOL:
        pedro_dprintf(2, "%s: Cannot extract -- file is continued from another volume\n", current_stat_info.file_name);

        *fun = extract_skip;
        break;

    case GNUTYPE_LONGNAME:
    case GNUTYPE_LONGLINK:

        pedro_dprintf(2, "Unexpected long name header");

        *fun = extract_failure;
        break;

    default:

        pedro_dprintf(2, "%s: Unknown file type '%c', extracted as normal file", file_name, typeflag);

        *fun = extract_file;
    }

    if (rc == 0)
        return 0;
    return 1;
}

/**
 * Tar related function, version 1.34
 * Return nonzero if NAME contains ".." as a file name component.
 *
 */
bool contains_dot_dot(char const *name)
{
    char const *p = name + FILE_SYSTEM_PREFIX_LEN(name);

    for (;; p++)
    {
        if (p[0] == '.' && p[1] == '.' && (ISSLASH(p[2]) || !p[2]))
            return 1;

        while (!ISSLASH(*p))
        {
            if (!*p++)
                return 0;
        }
    }
}
#if 1

/**
 * Tar related function, version 1.34
 * Extract a file from the archive.
 */
void extract_archive(void)
{
    char typeflag;
    tar_extractor_t fun = NULL;
    bool skip_dotdot_name;

    //fatal_exit_hook = extract_finish;

    set_next_block_after(current_header);

    skip_dotdot_name = (!absolute_names_option && contains_dot_dot(current_stat_info.orig_file_name));
    if (skip_dotdot_name)
    {
        /*
         ERROR ((0, 0, _("%s: Member name contains '..'"),
         quotearg_colon (current_stat_info.orig_file_name)));*/

        pedro_dprintf(2, "%s: Member name contains '..'\n", current_stat_info.orig_file_name);
    }

    if (!current_stat_info.file_name[0] || skip_dotdot_name)
    {
        skip_member();
        return;
    }

    typeflag = sparse_member_p(&current_stat_info) ? GNUTYPE_SPARSE : current_header->header.typeflag;

    if (prepare_to_extract(current_stat_info.file_name, typeflag, &fun))
    {
        if (fun && (*fun)(current_stat_info.file_name, typeflag))
        {
            ;
        }
    }
    else
        skip_member();
}

#endif
