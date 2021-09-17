/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails:                                                                 *
 *     maria@arsoftware.net.br                                                  *
 *     pedro@locacaodiaria.com.br                                               *
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////z
//defines...

bool also_encrypt_headers_i = false;

bool use_encryption_i = false;
char tar_filename_ar_7zip_maria[AMANDA__SIZE];
char path_with_the_files_ar_7zip_maria[AMANDA__SIZE];
char patern_ar_7zip_maria[20000];
/**
  Testes amor...
 */
bool is_7zip_maria = false;
int recurse_7zip_maria = 0;
bool true_if_include_7zip_maria = false;
char compression_level_7zip_maria[300];

int amanda_s_smart_ape(__attribute__((unused)) char *initial_path_amanda_s_smart_ape,
                       bool recurse_on_subfolders_amanda_s_smart_ape, enum amanda__mode amanda_mode);

void get_timestamp_arp(char *file_arp, __time64_t *s_arp, VAL_data *VAL_data_arp);

enum libarchive_compression_modes_AR compression_mode_p = P_MODE_IS_ZIP__NO_PASSWORD;

int64_t bytes_read_p = 0; //oi

bool first_pass_VAL_p;

bool mode_is_parolin_p = true;

int __fastcall split_in_multiple_volumes_p(char *filename_utf_8_p);

#define SHOW_DEBUG_SPEED_Z show_debug_z

/**
 * Function to retrieve the elapsed time very accurate
 * as milliseconds, useful for benchmarks
 *
 */
double
get_bucaneiro_tick()
{
    LARGE_INTEGER first;
    LARGE_INTEGER second;
    QueryPerformanceFrequency(&first);
    double a = first.QuadPart;
    QueryPerformanceCounter(&second);
    double b = second.QuadPart;
    return b / a;
}

int first_step = 0;

enum z_encryption_method internal_encryption_z_method = Z_NEW_MODE; //default to the new method, obviously

/**
 * New function to encrypt files, this is the preferred mode to
 * encrypt files because the old mode was generating uncompressible
 * files (my mistake)
 *
 * @param original_filename_z the original file to encrypt
 *
 * @return 0 if ok, 1 if an error occur, error_message_k has
 * the error information
 */
int encryption_process_new_mode_21_february_2021_z(char *original_filename_z)
{
    int ret_arp_ = 0;
    char temp_file_in_z[1024];
    static int64_t temp_long_long;

    first_step = 2;
    if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
    {
        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_file_in_z, L"EN_"))
        {
            fatal_exit_k = 30004;
            strcpy(error_message_k, "Cannot create final encrypted file\n");
            return 1;
        }

        update_progress_arp(&temp_long_long);

        if (ARP_AES == encryption_method_to_create)
        {
            ret_arp_ = encrypt_arp(original_filename_z,
                                   temp_file_in_z,
                                   the_pass_arp,
                                   ARP_AES);
        }
        else if (ARP_RC4 == encryption_method_to_create)
        {
            pedro_dprintf(-1, "method rc4\n");
            ret_arp_ = encrypt_arp(original_filename_z,
                                   temp_file_in_z,
                                   the_pass_arp,
                                   ARP_RC4);
        }
        else if (ARP_SERPENT == encryption_method_to_create)
        {
            ret_arp_ = encrypt_arp(original_filename_z,
                                   temp_file_in_z,
                                   the_pass_arp,
                                   ARP_SERPENT);
        }
        else if (ARP_MARS == encryption_method_to_create)
        {
            ret_arp_ = encrypt_arp(original_filename_z,
                                   temp_file_in_z,
                                   the_pass_arp,
                                   ARP_MARS);
        }
        else if (ARP_RC6 == encryption_method_to_create)
        {
            ret_arp_ = encrypt_arp(original_filename_z,
                                   temp_file_in_z,
                                   the_pass_arp,
                                   ARP_RC6);
        }
        else if (ARP_TWOFISH == encryption_method_to_create)
        {
            ret_arp_ = encrypt_arp(original_filename_z,
                                   temp_file_in_z,
                                   the_pass_arp,
                                   ARP_TWOFISH);
        }
        else
        {
            assert(0 && "Unsupported encryption method\n");
            exit(27);
        }

        _wunlink(amanda_utf8towide_1_(original_filename_z));
        _wrename(amanda_utf8towide_2_(temp_file_in_z), amanda_utf8towide_1_(original_filename_z));

        if (119 == ret_arp_)
        {
            _wunlink(amanda_utf8towide_1_(original_filename_z));
        }
    }

    return 0;
}

int threads_z = 1;

/**
 * This is the api call that will pass to the DLL the
 * number of threads to use, limited to 8 threads at this moment,
 * if 0 then the number of cores will be detected and used
 *
 * @param value_z the number of threads
 *
 * @return always 0
 *
 */
int __stdcall set_thread_number(int value_z)
{
    if (0 > value_z)
    {
        value_z = 0; //will be based on the number of cpus detected
    }

    if (8 < value_z)
    {
        value_z = 8; //limit
    }

    number_of_threads_p = value_z;

    threads_z = value_z;
    return 0;
}

int time_point_arp = 0;
bool flag_iso_arp = false;

int files_that_cannot_be_read;
int files_that_cannot_be_read_update;
int paths_with_invalid_attributes_arp;
HANDLE hMapFile_arp = NULL;

#pragma pack(push, 1)

typedef struct _amanda_
{
    char global_patern_ar[1024];
    int recurse_on_subfolders_arp;
    int mode_is_include_or_exclude__;
    //int files_that_cannot_read    ;
    char extract_file_arp[1024];
    int progress_arp;
    int pause____arp;
    int cancel___arp;
} our_map_arp;

#pragma pack(pop)

our_map_arp global_our_map_arp = {0};
our_map_arp *global_ptr_our_map_arp = NULL;
our_map_arp *global_ptr_our_map_arp_v27 = NULL;
char temp_encrypted_file_arp[AMANDA__SIZE];

int dump_regular_file_VAL_arp(int fd_arp, VAL_data *my_VAL_data);
void dump_diretory_VAL_arp(VAL_data *my_VAL_data);
int __cdecl create_archive_internal_ar_VAL(char *path_with_the_files_ar);
int64_t amanda_pereira_total_size;
int64_t ricrdo_bytes_read;

static union block *
write_ustar_long_name(const char *name);

void xheader_store(char const *keyword, struct tar_stat_info *st,
                   void const *data);

enum mode_is_include_or_exclude mode_is_include_or_exclude__ = ARP_INCLUDE_FILES;

int compression_mode_ar = AAKP_MODE_TAR;

char pause_flag_ar = 0;
char warning_flag = 0;

int64_t files_count;
int64_t folders_count;

struct my_struct_for_list_ar
{
    char *filename_ar;
    struct my_struct_for_list_ar *next_ar;
    int has_next;
};

struct my_struct_for_list_ar *aak_;
struct my_struct_for_list_ar *aak_inicio_;

struct my_struct_for_list_ar *aak_pointer_;

int has_itens = 0;

int has_itens_copy = 0;

/**
 * Function to add an item to the linked list (internal use), fixed for large paths Ricardo...
 *
 * @param data_ar the data entering
 *
 * @return void
 *
 */
void add_more_one(char *data_ar)
{
    struct my_struct_for_list_ar *aak_ptr;

    if (!has_itens)
    {
        aak_ = calloc(1, sizeof(struct my_struct_for_list_ar));
        aak_inicio_ = aak_;
        aak_pointer_ = aak_;
        aak_->filename_ar = malloc(strlen(data_ar) + 1);
        strcpy(aak_->filename_ar, data_ar);
        aak_->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar));
        has_itens = 1;
        has_itens_copy = has_itens;
        aak_ = aak_->next_ar;
    }
    else
    {
        aak_ptr = aak_;
        pedro_dprintf(-1, "em uso memoria %p\n", aak_ptr);
        assert(aak_ptr);
        assert(8 < sizeof(struct my_struct_for_list_ar));
        aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar));
        aak_ptr->filename_ar = malloc(strlen(data_ar) + 1);
        strcpy(aak_ptr->filename_ar, data_ar);
        aak_ = aak_ptr->next_ar;
        has_itens++;
        has_itens_copy = has_itens;
    }
}

int clean_list__ar(void);

/**
 * Function to get an item from the linked list (internal), 
 * notice that after 13/September/2021 support to paths above MAX_PATH 
 * was added, long paths already checked Ric...
 *
 * @param data_out_ar the string with the information
 * on exit
 *
 * @return 0 if no more items, or 1 otherwise
 *
 */
int get_list_itens(char *data_out_ar)
{
    if (!has_itens_copy)
    {
        clean_list__ar();
        return 0;
    }
    strcpy(data_out_ar, aak_pointer_->filename_ar);
    aak_pointer_ = aak_pointer_->next_ar;
    has_itens_copy--;
    assert(has_itens_copy >= 0);
    return 1;
}

/**
 * Function to get an item from the linked list
 *
 * @param data_out_ar the string with the information
 * on exit
 *
 * @return 0 if no more items, or 1 otherwise
 *
 */
int __stdcall get_last_process_information_ar(char *data_out_ar)
{
    data_out_ar[0] = 0;
    pedro_dprintf(-1, "antes");
    return get_list_itens(data_out_ar);
}

/**
 * Function to cleanup the linked list and make it
 * ready for the next call
 *
 */
int clean_list__ar(void)
{
    struct my_struct_for_list_ar *my_ptr_ar;
    struct my_struct_for_list_ar *my_ptr2_ar;

    my_ptr2_ar = aak_inicio_;
    my_ptr_ar = aak_inicio_;
inicio_ar:;
    if (!has_itens)
    {
        has_itens_copy = 0;
        return 0;
    }
    my_ptr2_ar = my_ptr_ar;
    my_ptr_ar = my_ptr_ar->next_ar;

    if (1 == has_itens)
    {
        free(my_ptr2_ar->next_ar);
    }
    free(my_ptr2_ar->filename_ar);
    free(my_ptr2_ar);

    has_itens--;

    goto inicio_ar;
    return 1;
}

char warning_message_k[AMANDA__SIZE];

/**
 * Function to retrieve the warning information, see
 * the sample for more information
 *
 * @param message_ar the output string information
 *
 */
void __stdcall get_create_warning_ar(char *message_ar)
{
    strcpy(message_ar, warning_message_k);
    return;
}

char process_message_k[AMANDA__SIZE];

/**
 * Function to retrieve the create message, see
 * the sample project to see where it is required
 *
 * @param message_ar the output string
 *
 */
void __stdcall get_create_process_ar(char *message_ar)
{
    strcpy(message_ar, process_message_k);
    return;
}

/**
 * Function to get timestamp information
 *
 * @param st the input _stat information
 *
 * @return the timestamp value
 *
 */
long int
get_stat_ctime_ns(__attribute__((unused)) struct _stat const *st)
{
#if defined STAT_TIMESPEC
    return STAT_TIMESPEC(st, st_ctim).tv_nsec;
#elif defined STAT_TIMESPEC_NS
    return STAT_TIMESPEC_NS(st, st_ctim);
#else
    return 0;
#endif
}

/**
 * Function to get timestamp information
 *
 * @param st the input _stat information
 *
 * @return the timestamp value
 *
 */
struct timespec
get_stat_ctime(struct _stat const *st)
{
#ifdef STAT_TIMESPEC
    return STAT_TIMESPEC(st, st_ctim);
#else
    struct timespec t;
    t.tv_sec = st->st_ctime;
    t.tv_nsec = get_stat_ctime_ns(st);
    return t;
#endif
}

/**
 * Function to get timestamp information
 *
 * @param st the input _stat information
 *
 * @return the timestamp value
 *
 */
long int
get_stat_mtime_ns(__attribute__((unused)) struct _stat const *st)
{
#if defined STAT_TIMESPEC
    return STAT_TIMESPEC(st, st_mtim).tv_nsec;
#elif defined STAT_TIMESPEC_NS
    return STAT_TIMESPEC_NS(st, st_mtim);
#else
    return 0;
#endif
}

/**
 * Function to get timestamp information
 *
 * @param st the input _stat information
 *
 * @return the timestamp value
 *
 */
struct timespec
get_stat_mtime(struct _stat const *st)
{
#ifdef STAT_TIMESPEC
    return STAT_TIMESPEC(st, st_mtim);
#else
    struct timespec t;
    t.tv_sec = st->st_mtime;
    t.tv_nsec = get_stat_mtime_ns(st);
    return t;
#endif
}

/**
 * Function to get timestamp information
 *
 * @param st the input _stat information
 *
 * @return the timestamp value
 *
 */
long int
get_stat_atime_ns(__attribute__((unused)) struct _stat const *st)
{
#if defined STAT_TIMESPEC
    return STAT_TIMESPEC(st, st_atim).tv_nsec;
#elif defined STAT_TIMESPEC_NS
    return STAT_TIMESPEC_NS(st, st_atim);
#else
    return 0;
#endif
}

/**
 * Function to get timestamp information
 *
 * @param st the input _stat information
 *
 * @return the timestamp value
 *
 */
struct timespec
get_stat_atime(struct _stat const *st)
{
#ifdef STAT_TIMESPEC
    return STAT_TIMESPEC(st, st_atim);
#else
    struct timespec t;
    t.tv_sec = st->st_atime;
    t.tv_nsec = get_stat_atime_ns(st);
    return t;
#endif
}

void close_archive(void);

union block *
write_extended(bool global, struct tar_stat_info *st, union block *old_header);

void dump_file_new_ar(struct tar_stat_info *parent, char const *name, char *initial_path_ar);

static bool
to_chars(int negative, uintmax_t value, size_t valsize,
         uintmax_t (*substitute)(int *),
         char *where, size_t size, const char *type);

/* Override actual mtime if set to FORCE_MTIME or CLAMP_MTIME */
GLOBAL enum set_mtime_option_mode set_mtime_option = USE_FILE_MTIME;

void tar_copy_str(char *dst, const char *src, size_t len);

/**
 * Function to apply a tolower in th  whole string
 *
 * @param path the string to apply the tolower
 *
 * @return void
 *
 */
void strtolower_ar(char *path)
{
    /*
 * funcao para passar um tolower na string inteira, september 1992
 */
    int ret;
    int i;

    ret = strlen(path);
    if (ret)
    {
        for (i = 0; i < ret; i++)
        {
            path[i] = tolower(path[i]);
        }
        return;
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
string_to_chars(char const *str, char *p, size_t s)
{
    tar_copy_str(p, str, s);
    p[s - 1] = '\0';
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
to_chars(int negative, uintmax_t value, size_t valsize,
         uintmax_t (*substitute)(int *),
         char *where, size_t size, const char *type);

/**
 * Tar related function, version 1.34
 *
 */
static uintmax_t
uid_substitute(int *negative)
{
    uid_t r;

#ifdef UID_NOBODY
    r = UID_NOBODY;
#else
    static uid_t uid_nobody;
    if (!uid_nobody && !0)
        uid_nobody = -2;
    r = uid_nobody;
#endif
    *negative = r < 0;
    return r;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
uintmax_to_chars(uintmax_t v, char *p, size_t s)
{
    return to_chars(0, v, sizeof v, 0, p, s, "uintmax_t");
}

/**
 * Tar related function, version 1.34
 *
 */
void simple_finish_header(union block *header)
{
    size_t i;
    int sum;
    char *p;

    memcpy(header->header.chksum, CHKBLANKS, sizeof header->header.chksum);

    sum = 0;
    p = header->buffer;
    for (i = sizeof *header; i-- != 0;)
        /* We can't use unsigned char here because of old compilers, e.g. V7.  */
        sum += 0xFF & *p++;

    /* Fill in the checksum field.  It's formatted differently from the
     other fields: it has [6] digits, a null, then a space -- rather than
     digits, then a null.  We use to_chars.
     The final space is already there, from
     checksumming, and to_chars doesn't modify it.

     This is a fast way to do:

     sprintf(header->header.chksum, "%6o", sum);  */

    uintmax_to_chars((uintmax_t)sum, header->header.chksum, 7);
    pedro_dprintf(-1, "veja !!!");
    set_next_block_after(header);
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
union block *
write_extended(__attribute__((unused)) bool global, struct tar_stat_info *st, union block *old_header)
{
    union block *header = NULL;
    if (st->xhdr.buffer || st->xhdr.stk == NULL)
        return old_header;
    assert(0);
    return header;
}

/**
 * Tar related function, version 1.34
 *
 */
bool string_ascii_p(char const *p)
{
    for (; *p; p++)
        if (*p & ~0x7f)
            return false;
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
uid_to_chars(int v, char *p, size_t s)
{
    return to_chars(v < 0, (uintmax_t)v, sizeof v, uid_substitute, p, s, "uid_t");
}

/**
 * Tar related function, version 1.34
 *
 */
static uintmax_t
gid_substitute(int *negative)
{
    int r;

#ifdef GID_NOBODY
    r = GID_NOBODY;
#else
#if 0
  static gid_t gid_nobody;
  if (!gid_nobody && !gname_to_gid("nobody", &gid_nobody))
    gid_nobody = -2;
  r = gid_nobody;
#endif

    r = 1;
#endif
    *negative = r < 0;
    return r;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
gid_to_chars(int v, char *p, size_t s)
{
    return to_chars(v < 0, (uintmax_t)v, sizeof v, gid_substitute, p, s, "gid_t");
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
mode_to_chars(mode_t v, char *p, size_t s)
{
    /* In the common case where the internal and external mode bits are the same,
     and we are not using POSIX or GNU format,
     propagate all unknown bits to the external mode.
     This matches historical practice.
     Otherwise, just copy the bits we know about.  */
    int negative;
    uintmax_t u;
    int vv = (int)v;
#if 1
    if (S_ISUID == TSUID && S_ISGID == TSGID && S_ISVTX == TSVTX && S_IRUSR == TUREAD && S_IWUSR == TUWRITE && S_IXUSR == TUEXEC && S_IRGRP == TGREAD && S_IWGRP == TGWRITE && S_IXGRP == TGEXEC && S_IROTH == TOREAD && S_IWOTH == TOWRITE && S_IXOTH == TOEXEC && archive_format != POSIX_FORMAT && archive_format != USTAR_FORMAT && archive_format != GNU_FORMAT)
    {
        negative = vv < 0;
        u = v;
    }
    else
#endif
    {
        negative = 0;
        u = ((v & S_ISUID ? TSUID : 0) | (v & S_ISGID ? TSGID : 0) | (v & S_ISVTX ? TSVTX : 0) | (v & S_IRUSR ? TUREAD : 0) | (v & S_IWUSR ? TUWRITE : 0) | (v & S_IXUSR ? TUEXEC : 0) | (v & S_IRGRP ? TGREAD : 0) | (v & S_IWGRP ? TGWRITE : 0) | (v & S_IXGRP ? TGEXEC : 0) | (v & S_IROTH ? TOREAD : 0) | (v & S_IWOTH ? TOWRITE : 0) | (v & S_IXOTH ? TOEXEC : 0));
    }
    return to_chars(negative, u, sizeof v, 0, p, s, "mode_t");
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
to_chars(int negative, uintmax_t value, size_t valsize,
         uintmax_t (*substitute)(int *),
         char *where, size_t size, const char *type);

/**
 * Tar related function, version 1.34
 *
 */
bool time_to_chars(time_t v, char *p, size_t s)
{
    return to_chars(v < 0, (uintmax_t)v, sizeof v, 0, p, s, "time_t");
}

GLOBAL enum archive_format archive_format = GNU_FORMAT;

/* List of keyword patterns set by delete= option */
static struct keyword_list *keyword_pattern_list;

/* List of keyword/value pairs set by 'keyword=value' option */
static struct keyword_list *keyword_global_override_list;

int __stdcall create_archive_ar(char *tar_filename_ar, char *path_with_the_files_ar, char *patern_ar, int compression_mode_external_ar);

void buffer_write_global_xheader(void);

void dump_file(struct tar_stat_info *parent, char const *name,
               char const *fullname);

static bool
to_chars(int negative, uintmax_t value, size_t valsize,
         uintmax_t (*substitute)(int *),
         char *where, size_t size, const char *type);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if (2 <= __GNUC__ || (1210 <= __IBMC__ && defined __IBM__TYPEOF__) || (0x5110 <= __SUNPRO_C && !__STDC__))
#define _GL_HAVE___TYPEOF__ 1
#else
#define _GL_HAVE___TYPEOF__ 0
#endif

/* Return 1 if the integer type or expression T might be signed.  Return 0
   if it is definitely unsigned.  This macro does not evaluate its argument,
   and expands to an integer constant expression.  */
#if _GL_HAVE___TYPEOF__
//# define _GL_SIGNED_TYPE_OR_EXPR(t) TYPE_SIGNED(__typeof__ (t))
#else
#define _GL_SIGNED_TYPE_OR_EXPR(t) 1
#endif

/* Bound on length of the string representing an unsigned integer
   value representable in B bits.  log10 (2.0) < 146/485.  The
   smallest value of B where this bound is not tight is 2621.  */
#define INT_BITS_STRLEN_BOUND(b) (((b)*146 + 484) / 485)

/* Bound on length of the string representing an integer type or expression T.
   Subtract 1 for the sign bit if T is signed, and then add 1 more for
   a minus sign if needed.

   Because _GL_SIGNED_TYPE_OR_EXPR sometimes returns 0 when its argument is
   signed, this macro may overestimate the true bound by one byte when
   applied to unsigned types of size 2, 4, 16, ... bytes.  */

/*
#define INT_STRLEN_BOUND(t)                                     \
  (INT_BITS_STRLEN_BOUND(TYPE_WIDTH(t) - _GL_SIGNED_TYPE_OR_EXPR(t)) \
   + _GL_SIGNED_TYPE_OR_EXPR(t))
*/

/**
 * Tar related function, version 1.34
 *
 */
char *
umaxtostr(uintmax_t i, char *buf)
{

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-overflow="

    char *p = buf + INT_STRLEN_BOUND(uintmax_t);

    *p = 0;

    if ((int)i < 0)
    {
        do
            *--p = '0' - i % 10;
        while ((i /= 10) != 0);

        *--p = '-';
    }
    else
    {
        do
            *--p = '0' + i % 10;
        while ((i /= 10) != 0);
    }

    return p;

#pragma GCC diagnostic pop
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
to_chars_subst(int negative, int gnu_format, uintmax_t value, size_t valsize,
               uintmax_t (*substitute)(int *),
               char *where, size_t size, const char *type)
{
    uintmax_t maxval = (gnu_format
                            ? MAX_VAL_WITH_DIGITS(size - 1, LG_256)
                            : MAX_VAL_WITH_DIGITS(size - 1, LG_8));
    char valbuf[5000 + 1];
    char minbuf[5000 + 1];

    if (gnu_format)
    {
        uintmax_t m = maxval + 1 ? maxval + 1 : maxval / 2 + 1;
        char *p = STRINGIFY_BIGINT(m, minbuf + 1);
        *--p = '-';
        //minval_string = p;
    }
    else
    {
        ; //minval_string = "0";
    }
    if (negative)
    {
        char *p = STRINGIFY_BIGINT(-value, valbuf + 1);
        *--p = '-';
        //value_string = p;
    }
    else
    {
        ; //value_string = STRINGIFY_BIGINT (value, valbuf);
    }

    if (substitute)
    {
        int negsub;
        uintmax_t sub = substitute(&negsub) & maxval;
        /* NOTE: This is one of the few places where GNU_FORMAT differs from
         OLDGNU_FORMAT.  The actual differences are:

         1. In OLDGNU_FORMAT all strings in a tar header end in \0
         2. Incremental archives use oldgnu_header.

         Apart from this they are completely identical. */
        uintmax_t s = (negsub &= archive_format == GNU_FORMAT) ? -sub : sub;
        char subbuf[5000 + 1];
        char *sub_string = STRINGIFY_BIGINT(s, subbuf + 1);
        if (negsub)
            *--sub_string = '-';

        pedro_dprintf(2, "value out of range");

        return to_chars(negsub, s, valsize, 0, where, size, type);
    }
    else
    {
        pedro_dprintf(2, "value out of range ***************** cheque");
        return false;
    }
}

/* Convert NEGATIVE VALUE to a base-256 representation suitable for
   tar headers.  NEGATIVE is 1 if VALUE was negative before being cast
   to uintmax_t, 0 otherwise.  Output to buffer WHERE with size SIZE.
   The result is undefined if SIZE is 0 or if VALUE is too large to
   fit.  */

/**
 * Tar related function, version 1.34
 *
 */
void to_base256(int negative, uintmax_t value, char *where, size_t size)
{
    uintmax_t v = value;
    uintmax_t propagated_sign_bits =
        ((uintmax_t)-negative << (CHAR_BIT * sizeof v - LG_256));
    size_t i = size;

    do
    {
        where[--i] = v & ((1 << LG_256) - 1);
        v = propagated_sign_bits | (v >> LG_256);
    } while (i);
}

/* Convert VALUE to an octal representation suitable for tar headers.
   Output to buffer WHERE with size SIZE.
   The result is undefined if SIZE is 0 or if VALUE is too large to fit.  */

/**
 * Tar related function, version 1.34
 *
 */
void to_octal(uintmax_t value, char *where, size_t size)
{
    uintmax_t v = value;
    size_t i = size;

    do
    {
        where[--i] = '0' + (v & ((1 << LG_8) - 1));
        v >>= LG_8;
    } while (i);
}

/**
 * Tar related function, version 1.34
 *
 */
bool to_chars(int negative, uintmax_t value, size_t valsize,
              uintmax_t (*substitute)(int *),
              char *where, size_t size, const char *type)
{
    int gnu_format = (archive_format == GNU_FORMAT || archive_format == OLDGNU_FORMAT);

    /* Generate the POSIX octal representation if the number fits.  */
    if (!negative && value <= MAX_VAL_WITH_DIGITS(size - 1, LG_8))
    {
        where[size - 1] = '\0';
        to_octal(value, where, size - 1);
        return true;
    }
    else if (gnu_format)
    {
        /* Try to cope with the number by using traditional GNU format
         methods */

        /* Generate the base-256 representation if the number fits.  */
        if (((negative ? -1 - value : value) <= MAX_VAL_WITH_DIGITS(size - 1, LG_256)))
        {
            where[0] = negative ? -1 : 1 << (LG_256 - 1);
            to_base256(negative, value, where + 1, size - 1);
            return true;
        }

        /* Otherwise, if the number is negative, and if it would not cause
         ambiguity on this host by confusing positive with negative
         values, then generate the POSIX octal representation of the value
         modulo 2**(field bits).  The resulting tar file is
         machine-dependent, since it depends on the host word size.  Yuck!
         But this is the traditional behavior.  */
        else if (negative && valsize * CHAR_BIT <= (size - 1) * LG_8)
        {
            static int warned_once;
            if (!warned_once)
            {
                warned_once = 1;
            }
            where[size - 1] = '\0';
            to_octal(value & MAX_VAL_WITH_DIGITS(valsize * CHAR_BIT, 1),
                     where, size - 1);
            return true;
        }
        /* Otherwise fall back to substitution, if possible: */
    }
    else
        substitute = NULL; /* No substitution for formats, other than GNU */

    return to_chars_subst(negative, gnu_format, value, valsize, substitute,
                          where, size, type);
}

/**
 * Tar related function, version 1.34
 *
 */
bool off_to_chars(off_t v, char *p, size_t s)
{
    return to_chars(v < 0, (uintmax_t)v, sizeof v, 0, p, s, "off_t");
}

/**
 * Tar related function, version 1.34
 *
 */
void tar_stat_init(struct tar_stat_info *st)
{
    memset(st, 0, sizeof(*st));
}

/**
 * Tar related function, version 1.34
 *
 */
void xheader_write_global(struct xheader *xhdr)
{
    if (keyword_global_override_list)
    {
        pedro_dprintf(-1, "item 1 call ");
#if 1
        struct keyword_list *kp;

        xheader_init(xhdr);
        for (kp = keyword_global_override_list; kp; kp = kp->next)
            code_string(kp->value, kp->pattern, xhdr);
#endif
    }
    if (xhdr->stk)
    {
        pedro_dprintf(-1, "item 1 call ");
#if 1
        char *name;

        xheader_finish(xhdr);
        name = xheader_ghdr_name();
        xheader_write(XGLTYPE, name, start_time.tv_sec, xhdr);
        free(name);
#endif
    }
}

static struct tar_stat_info dummy;

/**
 * Tar related function, version 1.34
 *
 */
void buffer_write_global_xheader(void)
{
    xheader_write_global(&dummy.xhdr);
}
/* Compute and return the block ordinal at current_block.  */

/**
 * Tar related function, version 1.34
 *
 */
off_t current_block_ordinal(void)
{
    return record_start_block + (current_block - record_start);
}

/* Copy at most LEN bytes from the string SRC to DST.  Terminate with
   NUL unless SRC is LEN or more bytes long.  */

/**
 * Tar related function, version 1.34
 *
 */
void tar_copy_str(char *dst, const char *src, size_t len)
{
    size_t i;

    for (i = 0; i < len; i++)
        if (!(dst[i] = src[i]))
            break;
}

/* Same as tar_copy_str, but always terminate with NUL if using
   is OLDGNU format */

/**
 * Tar related function, version 1.34
 *
 */
void tar_name_copy_str(char *dst, const char *src, size_t len)
{
    tar_copy_str(dst, src, len);
    if (archive_format == OLDGNU_FORMAT)
        dst[len - 1] = 0;
}

/* Given GID, find the corresponding GNAME.  */

/**
 * Tar related function, version 1.34
 *
 */
void gid_to_gname(__attribute__((unused)) int gid, char **gname)
{
    *gname = strdup("");
    return;
}

/* Create a new header and store there at most NAME_FIELD_SIZE bytes of
   the file name */

/**
 * Tar related function, version 1.34
 *
 */
union block *
write_short_name(struct tar_stat_info *st)
{
    union block *header = find_next_block();

    memset(header->buffer, 0, sizeof(union block));
    tar_name_copy_str(header->header.name, st->file_name, NAME_FIELD_SIZE);
    return header;
}

/* Write a GNUTYPE_LONGLINK or GNUTYPE_LONGNAME block.  */

/**
 * Tar related function, version 1.34
 *
 */
static void
write_gnu_long_link(struct tar_stat_info *st, const char *p, char type)
{
    size_t size = strlen(p) + 1;
    size_t bufsize;
    union block *header;

    header = start_private_header("././@LongLink", size, 0);

#if 1
    if (!numeric_owner_option)
    {
        static char *uname, *gname;
        if (!uname)
        {
            uid_to_uname(0, &uname);
            gid_to_gname(0, &gname);
        }
        UNAME_TO_CHARS(uname, header->header.uname);
        GNAME_TO_CHARS(gname, header->header.gname);
    }
#endif

    strcpy(header->buffer + offsetof(struct posix_header, magic),
           OLDGNU_MAGIC);
    header->header.typeflag = type;
    finish_header(st, header, -1);

    header = find_next_block();

    bufsize = available_space_after(header);

    while (bufsize < size)
    {
        memcpy(header->buffer, p, bufsize);
        p += bufsize;
        size -= bufsize;
        set_next_block_after(header + (bufsize - 1) / BLOCKSIZE);
        header = find_next_block();
        bufsize = available_space_after(header);
    }
    memcpy(header->buffer, p, size);
    memset(header->buffer + size, 0, bufsize - size);
    set_next_block_after(header + (size - 1) / BLOCKSIZE);
}

/**
 * Tar related function, version 1.34
 *
 */
static union block *
write_ustar_long_name(const char *name)
{
    size_t length = strlen(name);
    size_t i, nlen;
    union block *header;

    if (length > PREFIX_FIELD_SIZE + NAME_FIELD_SIZE + 1)
    {
        pedro_dprintf(2, "%s: file name is too long (max %d); not dumped",
                      name, PREFIX_FIELD_SIZE + NAME_FIELD_SIZE + 1);
        return NULL;
    }

    i = split_long_name(name, length);
    if (i == 0 || (nlen = length - i - 1) > NAME_FIELD_SIZE || nlen == 0)
    {
        pedro_dprintf(2, "%s: file name is too long (cannot be split); not dumped",
                      name);
        return NULL;
    }

    header = find_next_block();
    memset(header->buffer, 0, sizeof(header->buffer));
    memcpy(header->header.prefix, name, i);
    memcpy(header->header.name, name + i + 1, length - i - 1);

    return header;
}

/**
 * Tar related function, version 1.34
 *
 */
static union block *
write_long_name(struct tar_stat_info *st)
{
    switch (archive_format)
    {
    case POSIX_FORMAT:
        xheader_store("path", st, NULL);
        break;

    case V7_FORMAT:
        if (strlen(st->file_name) > NAME_FIELD_SIZE - 1)
        {
            return NULL;
        }
        break;

#if 1
    case USTAR_FORMAT:
    case STAR_FORMAT:

        return write_ustar_long_name(st->file_name);
#endif
    case OLDGNU_FORMAT:
    case GNU_FORMAT:
        write_gnu_long_link(st, st->file_name, GNUTYPE_LONGNAME);
        break;

    default:
        abort(); /*FIXME*/ //ok, we will fix it
    }
    return write_short_name(st);
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void dump_directory(struct tar_stat_info *st)
{
    union block *blk = NULL;
    off_t block_ordinal = current_block_ordinal();
    st->stat.st_size = 0; /* force 0 size on dir */
    blk = start_header(st);
    if (!blk)
    {
        return;
    }
    blk->header.typeflag = DIRTYPE;
    finish_header(st, blk, block_ordinal);
    return;
}

/**
 * It will convert '\\' to '/' on the given string
 *
 */
void trocadordebackslashfrente(char *path)
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
            if (aqui == '\\')
            {
                path[i] = '/';
            }
        }
    }
}

/**
 * Tar related function, version 1.34
 *
 */
size_t
blocking_read(int fd, void *buf, size_t count)
{
    int bytes;

    if (mode_is_update_arp)
    {
        bytes = read(fd, buf, min(count, bytes_left_in_the_update_file_arp));
        if (0 <= (int)bytes)
        {
            bytes_left_in_the_update_file_arp -= bytes;
        }
    }
    else
        bytes = read(fd, buf, count);
#if defined F_SETFL && O_NONBLOCK
    if (bytes == SAFE_READ_ERROR && errno == EAGAIN)
    {
        int flags = fcntl(fd, F_GETFL);
        if (0 <= flags && flags & O_NONBLOCK && fcntl(fd, F_SETFL, flags & ~O_NONBLOCK) != -1)
            bytes = safe_read(fd, buf, count);
    }
#endif
    return bytes;
}

/**
 * Tar related function, version 1.34
 *
 */
void pad_archive(off_t size_left)
{
    union block *blk;

    while (size_left > 0)
    {
        blk = find_next_block();
        memset(blk->buffer, 0, BLOCKSIZE);
        set_next_block_after(blk);
        size_left -= BLOCKSIZE;
    }
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
static enum dump_status
dump_regular_file(int fd, struct tar_stat_info *st)
{
    off_t size_left = st->stat.st_size;
    off_t block_ordinal;
    union block *blk;

    block_ordinal = current_block_ordinal();
    blk = start_header(st);
    if (!blk)
    {
        pedro_dprintf(-1, "error in dump_regular_file\n");
        return dump_status_fail;
    }
#if 1
    /* Mark contiguous files, if we support them.  */
    if (archive_format != V7_FORMAT && S_ISCTG(st->stat.st_mode))
        blk->header.typeflag = CONTTYPE;
#endif
    finish_header(st, blk, block_ordinal);

    mv_begin_write(st->file_name, st->stat.st_size, st->stat.st_size);
    while (size_left > 0)
    {
        size_t bufsize, count, count2 = -1;

        int icount;

        blk = find_next_block();
        bufsize = available_space_after(blk);

        if ((int64_t)size_left < (int64_t)bufsize)
        {
            /* Last read -- zero out area beyond.  */
            bufsize = size_left;
            count = bufsize % BLOCKSIZE;
            if (count)
                memset(blk->buffer + size_left, 0, BLOCKSIZE - count);
        }

        icount = count = (fd <= 0) ? bufsize : blocking_read(fd, blk->buffer, bufsize);

        if (0 < icount)
        {
            if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
            {
                ricrdo_bytes_read += count / 2;
            }
            else
            {
                ricrdo_bytes_read += count;
            }
        }

        if (count2 == count)
        {
            pad_archive(size_left);
            return dump_status_short;
        }
        size_left -= count;
        set_next_block_after(blk + (bufsize - 1) / BLOCKSIZE);

        if (count != bufsize)
        {
            memset(blk->buffer + count, 0, bufsize - count);
            pedro_dprintf(2, "File shrank by a few bytes\n");
            pad_archive(size_left - (bufsize - count));
            return dump_status_short;
        }
    }
    return dump_status_ok;
}

#include "libarchive_update_i.c"

/**
 * This is the function that handle the dump of the dir and file information
 * for Tar and VAL format, full support to wide paths...
 *
 * @param st the main struct for the Tar file and also VAL format
 *
 * @param initial_path_ar the path where the files are located
 *
 * @param girlfriend_name the entry name (a folder or a file), also Amanda
 *
 */
void dump_file_or_folder(struct tar_stat_info *st,
                         char const *girlfriend_name,
                         char *initial_path_ar)
{
    static VAL_data my_VAL_data;
    static VAL_data my_VAL_data_copy_i;

    HANDLE hFile;
    enum dump_status status;
    DWORD attributes;
    __time64_t mtime_tv_sec_arp = 0;
    static char filename_k_arp[AMANDA__SIZE];
    static char file_or_folder_to_process[AMANDA__SIZE];
    static char file_or_folder_to_process_copy[AMANDA__SIZE];
    static char tar_file_copy[AMANDA__SIZE];
    bool is_dir_ar = false;
    int fd_ar;

    memset(filename_k_arp, 0, sizeof(filename_k_arp));
    memset(file_or_folder_to_process, 0, sizeof(file_or_folder_to_process));
    memset(file_or_folder_to_process_copy, 0, sizeof(file_or_folder_to_process_copy));
    memset(tar_file_copy, 0, sizeof(tar_file_copy));

    memset(&my_VAL_data, 0, sizeof(my_VAL_data));
    memset(&my_VAL_data_copy_i, 0, sizeof(my_VAL_data_copy_i));

    strcpy(file_or_folder_to_process, initial_path_ar);

    if (strlen(file_or_folder_to_process))
    {
        if ('\\' != file_or_folder_to_process[strlen(file_or_folder_to_process) - 1])
        {
            strcat(file_or_folder_to_process, "\\");
        }
    }
    else
    {
        assert(0 && "path cannot be empty");
    }

    strcat(file_or_folder_to_process, girlfriend_name);

    pedro_dprintf(-1, "***************************\n");
    pedro_dprintf(-1, " folder e name %s %s\n", initial_path_ar, girlfriend_name);
    pedro_dprintf(-1, " total %s\n", file_or_folder_to_process);

    strcpy(file_or_folder_to_process_copy, file_or_folder_to_process);
    trocadordebackslashtras(file_or_folder_to_process_copy);
    strtolower_ar(file_or_folder_to_process_copy);
    strcpy(tar_file_copy, archive_name_array_filename);
    strtolower_ar(tar_file_copy);
    if (0 == strcmp(tar_file_copy, file_or_folder_to_process_copy))
    {
        strcpy(warning_message_k, "Cannot add himself to the tar(VAL) file, skipping...");
        add_more_one(warning_message_k);
        return;
    }

    strcpy(my_VAL_data.VAL_filename, girlfriend_name);
    trocadordebackslashfrente((char *)girlfriend_name);
    assign_string(&st->orig_file_name, girlfriend_name);
    assign_string(&st->file_name, girlfriend_name);
    attributes = GetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(file_or_folder_to_process)));

    if (INVALID_FILE_ATTRIBUTES == attributes)
    {
        paths_with_invalid_attributes_arp++;
        sprintf(warning_message_k, "File %s has invalid attributes, skipping", file_or_folder_to_process);
        add_more_one(warning_message_k);
        return;
    }
    if (attributes & FILE_ATTRIBUTE_DIRECTORY)
    {
        is_dir_ar = true;
        pedro_dprintf(-1, "is dir -> true\n");
    }
    else
    {
        if ((attributes & FILE_ATTRIBUTE_NORMAL) ||
            (attributes & FILE_ATTRIBUTE_READONLY) ||
            (attributes & FILE_ATTRIBUTE_HIDDEN) ||
            (attributes & FILE_ATTRIBUTE_ENCRYPTED) ||
            (attributes & FILE_ATTRIBUTE_COMPRESSED) ||
            (attributes & FILE_ATTRIBUTE_SYSTEM) ||
            (attributes & FILE_ATTRIBUTE_ARCHIVE))
        {
            my_VAL_data.VAL_attributes = attributes;
            pedro_dprintf(-1, "is dir -> false\n");
        }
        else
        {
            paths_with_invalid_attributes_arp++;
            sprintf(warning_message_k, "File %s has invalid attributes, skipping...", file_or_folder_to_process);
            add_more_one(warning_message_k);
            return;
        }
    }

    if (true == is_dir_ar)
    {
        my_VAL_data.VAL_is_dir = true;
        if (ARP_MODE_IS_FIRST_STEP == step_for_create_arp)
        {
            strcpy(filename_k_arp, st->file_name);
        }

        if ('/' != st->file_name[strlen(st->file_name) - 1])
        {
            static char temp_ar[AMANDA__SIZE];
            strcpy(temp_ar, st->file_name);
            strcat(temp_ar, "/");
            assign_string(&st->file_name, temp_ar);
            assign_string(&st->orig_file_name, temp_ar);
            pedro_dprintf(-1, "pronto %s\n", st->file_name);
        }
        FILETIME lpCreationTime___jumior;
        FILETIME lpLastAccessTime_junior;
        FILETIME lpLastWriteTime__junior;

        hFile =
            CreateFileW(permissive_name_m_(amanda_utf8towide_1_(file_or_folder_to_process)),
                        /*
                    GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
                    NULL,
                    OPEN_EXISTING,
                    FILE_FLAG_BACKUP_SEMANTICS,
                    NULL);
		    */
                        GENERIC_READ,
                        FILE_SHARE_READ, NULL,
                        OPEN_EXISTING,
                        FILE_FLAG_BACKUP_SEMANTICS,
                        NULL);

        if (INVALID_HANDLE_VALUE != hFile)
        {
            if (GetFileTime(
                    hFile,
                    &lpCreationTime___jumior,
                    &lpLastAccessTime_junior,
                    &lpLastWriteTime__junior))
            {
                my_VAL_data.CreationTime___junior = lpCreationTime___jumior;
                my_VAL_data.LastAccessTime_junior = lpLastAccessTime_junior;
                my_VAL_data.LastWriteTime__junior = lpLastWriteTime__junior;

                {
                    struct timespec t;

                    //ret_ar = 0;
                    {
                        __time64_t s_arp_3;
                        get_timestamp_arp(/* already have permissive_name_m_ call */ file_or_folder_to_process, &s_arp_3, &my_VAL_data_copy_i);

                        t.tv_sec = s_arp_3;
                        my_VAL_data.VAL_timestamp = s_arp_3;
                        my_VAL_data.VAL_timestamp64 = s_arp_3;
                        mtime_tv_sec_arp = t.tv_sec;
                        t.tv_nsec = 0;
                        st->atime = t;
                        st->mtime = t;
                        st->ctime = t;
                    }
                }
            }
            else
            {
                pedro_dprintf(2, "Cannot access timestamp of %s\n", file_or_folder_to_process);
            }

            CloseHandle(hFile);
        }
        else
        {
            pedro_dprintf(2, "%s: Cannot get filetime on folder\n", file_or_folder_to_process);
        }

        if (ARP_MODE_NORMAL == step_for_create_arp)
        {
            if (!mode_is_VAL_arp)
            {
                dump_directory(st); //Later we extend the Tar format to long paths...
            }
            else
            {
                //aqui
                if (mode_is_parolin_p)
                {
                    dump_diretory_VAL_arp(&my_VAL_data);
                }
                else
                {
                    //SetCurrentDirectoryW(amanda_utf8towide_1_(initial_path_ar));
                    libarchive_process_p_func((my_VAL_data.VAL_filename), file_or_folder_to_process);
                    //SetCurrentDirectoryW(amanda_path);
                }
            }
        }
        if (ARP_MODE_IS_FIRST_STEP == step_for_create_arp)
        {
            int found_arp = 0;
            char *temp_arp_1 = malloc(AMANDA__SIZE);
            char *temp_arp_2 = malloc(AMANDA__SIZE);
            char *temp_arp_3 = malloc(AMANDA__SIZE);
            int has_itens_is_amanda_update_internal = has_itens_is_amanda_update_internal_b_arp;
            struct my_struct_for_list_ar_is_amanda_update_ *aak_ptr;
            aak_ptr = aak_inicio_is_amanda_update_;
            trocadordebackslashfrente(filename_k_arp);
            strcpy(temp_arp_3, filename_k_arp);
            strtolower_ar(filename_k_arp);

            while (has_itens_is_amanda_update_internal--)
            {
                trocadordebackslashfrente(aak_ptr->filename_k);
                strcpy(temp_arp_1, aak_ptr->filename_k);
                strtolower_ar(temp_arp_1);

                if (0 == strcmp(temp_arp_1, filename_k_arp))
                {
                    found_arp++;
                    break;
                }
                aak_ptr = aak_ptr->next_ar;
            }

            if (!found_arp)
            {
                if (0 == my_VAL_data.VAL_timestamp64)
                {
                    my_VAL_data.VAL_timestamp64 = mtime_tv_sec_arp;
                }
                add_more_one_is_amanda_update_(
                    temp_arp_3,
                    0,
                    mtime_tv_sec_arp,
                    true,
                    0,
                    0,
                    0,
                    my_VAL_data.VAL_timestamp64,
                    &my_VAL_data);
            }

            free(temp_arp_1), free(temp_arp_2), free(temp_arp_3);
        }
    }
    else
    {
        {
            void get_timestamp_arp(char *file_arp, __time64_t *s_arp, VAL_data *VAL_data_arp);
            __time64_t s_arp_3;

            _wstat(permissive_name_m_(amanda_utf8towide_1_(file_or_folder_to_process)), &st->stat);
            mtime_tv_sec_arp = st->mtime.tv_sec;
            get_timestamp_arp(file_or_folder_to_process, &s_arp_3, &my_VAL_data);
            mtime_tv_sec_arp = s_arp_3;
            st->atime.tv_sec = s_arp_3;
            st->atime.tv_nsec = 0;
            st->mtime.tv_sec = s_arp_3; //only this is relevant
            st->mtime.tv_nsec = 0;
            st->ctime.tv_sec = s_arp_3;
            st->ctime.tv_nsec = 0;
            my_VAL_data.VAL_timestamp = s_arp_3;
            my_VAL_data.VAL_timestamp64 = s_arp_3;
            my_VAL_data.VAL_file_size = getfilesize_ar(file_or_folder_to_process);
            my_VAL_data.VAL_is_dir = false;
            my_VAL_data.VAL_is_encrypted = false;
            if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
            {
                my_VAL_data.VAL_is_encrypted = true;
                my_VAL_data.VAL_file_size += 4 + 64 + 8;
            }
        }

        if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
        {
            st->stat.st_size += 4 + 64 + 8; //magic value...
        }

        st->archive_file_size = st->stat.st_size;
        if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
        {
            update_progress_arp_func(&ricrdo_bytes_read);

            if (ARP_AES == encryption_method_to_create)
            {
                my_VAL_data.VAL_encryption_method = ARP_AES;
                ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                       temp_encrypted_file_arp,
                                       the_pass_arp,
                                       ARP_AES);
            }
            else if (ARP_RC4 == encryption_method_to_create)
            {
                my_VAL_data.VAL_encryption_method = ARP_RC4;
                ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                       temp_encrypted_file_arp,
                                       the_pass_arp,
                                       ARP_RC4);
            }
            else if (ARP_SERPENT == encryption_method_to_create)
            {
                my_VAL_data.VAL_encryption_method = ARP_SERPENT;
                ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                       temp_encrypted_file_arp,
                                       the_pass_arp,
                                       ARP_SERPENT);
            }
            else if (ARP_MARS == encryption_method_to_create)
            {
                my_VAL_data.VAL_encryption_method = ARP_MARS;
                ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                       temp_encrypted_file_arp,
                                       the_pass_arp,
                                       ARP_MARS);
            }
            else if (ARP_RC6 == encryption_method_to_create)
            {
                my_VAL_data.VAL_encryption_method = ARP_RC6;
                ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                       temp_encrypted_file_arp,
                                       the_pass_arp,
                                       ARP_RC6);
            }
            else if (ARP_TWOFISH == encryption_method_to_create)
            {
                my_VAL_data.VAL_encryption_method = ARP_TWOFISH;
                ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                       temp_encrypted_file_arp,
                                       the_pass_arp,
                                       ARP_TWOFISH);
            }
            else
            {
                assert(0 && "Unsupported encryption method\n");
            }
            fd_ar = _wopen(permissive_name_m_(amanda_utf8towide_1_(temp_encrypted_file_arp)), O_RDONLY | O_BINARY,
                           _S_IREAD);
        }
        else
            fd_ar = _wopen(permissive_name_m_(amanda_utf8towide_1_(file_or_folder_to_process)), O_RDONLY | O_BINARY,
                           _S_IREAD);

        if (-1 == fd_ar)
        {
            files_that_cannot_be_read++;
            pedro_dprintf(2, "Error openning %s\n", file_or_folder_to_process);
        }

        if (ARP_MODE_IS_FIRST_STEP == mode_is_update_arp)
        {
            {
                int found_arp = 0;
                char *temp_arp_1 = malloc(AMANDA__SIZE);
                char *temp_arp_2 = malloc(AMANDA__SIZE);
                char *temp_arp_3 = malloc(AMANDA__SIZE);
                int has_itens_is_amanda_update_internal = has_itens_is_amanda_update_internal_b_arp;
                struct my_struct_for_list_ar_is_amanda_update_ *aak_ptr;
                aak_ptr = aak_inicio_is_amanda_update_;
                strcpy(filename_k_arp, st->file_name);
                strcpy(temp_arp_3, filename_k_arp);
                strtolower_ar(filename_k_arp);
                while (has_itens_is_amanda_update_internal--)
                {
                    trocadordebackslashfrente(aak_ptr->filename_k);
                    strcpy(temp_arp_1, aak_ptr->filename_k);
                    strtolower_ar(temp_arp_1);

                    if (0 == strcmp(temp_arp_1, filename_k_arp))
                    {
                        strcpy(aak_ptr->filename_k, "");
                        found_arp++;
                        break;
                    }
                    aak_ptr = aak_ptr->next_ar;
                }

                if (1)
                {
                    add_more_one_is_amanda_update_(
                        st->file_name,
                        st->archive_file_size,
                        mtime_tv_sec_arp,
                        false,
                        _telli64(our_update_file_open__arp),
                        my_VAL_data.VAL_attributes,
                        my_VAL_data.VAL_is_encrypted,
                        my_VAL_data.VAL_timestamp64,
                        &my_VAL_data);
                }
                free(temp_arp_1), free(temp_arp_2), free(temp_arp_3);
            }
        }

        if (-1 == fd_ar)
        {
            if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
            {
                _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_encrypted_file_arp)));
            }
            pedro_dprintf(0, "Cannot open size %d\n", strlen(file_or_folder_to_process));
            sprintf(warning_message_k, "Cannot open %s to write", file_or_folder_to_process);
            add_more_one(warning_message_k);
            return;
        }

        if (ARP_MODE_NORMAL == step_for_create_arp)
        {
            if (!mode_is_VAL_arp)
            {
                pedro_dprintf(-1, "ddd\n");
                status = dump_regular_file(fd_ar, st);
                switch (status)
                {
                case dump_status_ok:
                case dump_status_short:;
                    break;

                case dump_status_fail:

                    sprintf(warning_message_k, "Cannot process file %s", file_or_folder_to_process);
                    add_more_one(warning_message_k);

                    break;

                case dump_status_not_implemented:
                    assert(0);
                }
            }
            else
            {

                //aqui
                if (mode_is_parolin_p)
                {
                    if (dump_regular_file_VAL_arp(fd_ar, &my_VAL_data))
                    {
                        sprintf(warning_message_k, "Cannot process file %s", file_or_folder_to_process);
                        add_more_one(warning_message_k);
                    }
                }
                else
                {

                    libarchive_process_p_func((my_VAL_data.VAL_filename), file_or_folder_to_process);
                }
            }
        }

        close(fd_ar);

        if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
        {
            _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_encrypted_file_arp)));
        }

        if (ARP_MODE_IS_FIRST_STEP == mode_is_update_arp)
        {
            int salvou_arp = 0;
#define AMANDA_SIZE__ 500000
            char *buf_arp = malloc(AMANDA_SIZE__);
            assert(buf_arp);

            int len_arp;
            assert(-1 != our_update_file_open__arp);

            if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
            {
                int64_t ricrdo_bytes_read_ = 0;
                update_progress_arp_func(&ricrdo_bytes_read_);

                if (ARP_AES == encryption_method_to_create)
                {
                    ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                           temp_encrypted_file_arp,
                                           the_pass_arp,
                                           ARP_AES);
                }
                else if (ARP_RC4 == encryption_method_to_create)
                {
                    ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                           temp_encrypted_file_arp,
                                           the_pass_arp,
                                           ARP_RC4);
                }
                else if (ARP_SERPENT == encryption_method_to_create)
                {
                    ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                           temp_encrypted_file_arp,
                                           the_pass_arp,
                                           ARP_SERPENT);
                }
                else if (ARP_MARS == encryption_method_to_create)
                {
                    ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                           temp_encrypted_file_arp,
                                           the_pass_arp,
                                           ARP_MARS);
                }
                else if (ARP_RC6 == encryption_method_to_create)
                {
                    ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                           temp_encrypted_file_arp,
                                           the_pass_arp,
                                           ARP_RC6);
                }
                else if (ARP_TWOFISH == encryption_method_to_create)
                {
                    ret_arp_ = encrypt_arp(file_or_folder_to_process,
                                           temp_encrypted_file_arp,
                                           the_pass_arp,
                                           ARP_TWOFISH);
                }
                else
                {
                    assert(0 && "Unsupported encryption method\n");
                }
                fd_ar = _wopen(permissive_name_m_(amanda_utf8towide_1_(temp_encrypted_file_arp)), O_RDONLY | O_BINARY,
                               _S_IREAD);
            }
            else
                fd_ar = _wopen(permissive_name_m_(amanda_utf8towide_1_(file_or_folder_to_process)), O_RDONLY | O_BINARY,
                               _S_IREAD);
            if (-1 != fd_ar)
            {
                while (0 < (len_arp = read(fd_ar, buf_arp, AMANDA_SIZE__)))
                {
                    if (0 > len_arp) //it is not redundant? maybe...
                    {
                        break;
                    }
                    salvou_arp += _write(
                        our_update_file_open__arp,
                        buf_arp,
                        len_arp);
                }

                free(buf_arp);
                close(fd_ar);
            }
            if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
            {
                _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_encrypted_file_arp)));
            }
        }
    }
    if (ARP_MODE_NORMAL == step_for_create_arp)
    {
        //aqui name
        if (use_name_i)
        {
            sprintf(process_message_k, "Processing %s", girlfriend_name);
        }
        else
            sprintf(process_message_k, "Processing %s", file_or_folder_to_process);
        add_more_one(process_message_k);
    }
}

#include "iso_support_arp.c"
#include "update_arp_k.c"

/**
 * This is the function that will call the function dump_file_or_folder for the
 * dump of files and folders to the disk
 *
 * @param name the entry name (a file or a folder)
 *
 * @param initial_path_ar the path where the entry is located
 *
 * @return void
 *
 */
void dump_file_new_ar(struct tar_stat_info *parent, char const *name, char *initial_path_ar)
{
    struct tar_stat_info st;
    tar_stat_init(&st);
    st.parent = parent;
    dump_file_or_folder(&st, name, initial_path_ar);
    tar_stat_destroy(&st);
}

/**
 * This is the function that will finish the update of a Tar or VAL file
 *
 * @param parent the entry input struct
 *
 * @return void
 *
 */
void dump_file_new_arp(struct tar_stat_info *parent)
{
    struct tar_stat_info st;
    tar_stat_init(&st);
    st.parent = parent;
    dump_file_or_folder_final_arp(&st);
    tar_stat_destroy(&st);
}

/* Write the EOT block(s).  Zero at least two blocks, through the end
   of the record.  Old tar, as previous versions of GNU tar, writes
   garbage after two zeroed blocks.  */

/**
 * Tar related function, version 1.34
 *
 */
void write_eot(void)
{
    union block *pointer = find_next_block();
    memset(pointer->buffer, 0, BLOCKSIZE);
    set_next_block_after(pointer);
    pointer = find_next_block();
    memset(pointer->buffer, 0, available_space_after(pointer));
    set_next_block_after(pointer);
}

/**
 * Function that matches input str with
 * given wildcard pattern, it is amazing and
 * case sensitive but it is easy to convert to
 * case insensitive
 *
 * @param str the input filename
 *
 * @param pattern the wildcard or filename
 *
 * @param n the size of str
 *
 * @param m the size of pattern
 *
 * @return true if it matchs, false otherwise
 *
 */
bool strmatch(char str[], char pattern[], int n, int m)
{
    // empty pattern can only match with
    // empty string
    if (m == 0)
        return (n == 0);

    // lookup table for storing results of
    // subproblems
    bool lookup[n + 1][m + 1];

    // initailze lookup table to false
    memset(lookup, false, sizeof(lookup));

    // empty pattern can match with empty string
    lookup[0][0] = true;

    // Only '*' can match with empty string
    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];

    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // Two cases if we see a '*'
            // a) We ignore â€˜*â€™ character and move
            //    to next  character in the pattern,
            //     i.e., â€˜*â€™ indicates an empty sequence.
            // b) '*' character matches with ith
            //     character in input
            if (pattern[j - 1] == '*')
                lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];

            // Current characters are considered as
            // matching in two cases
            // (a) current character of pattern is '?'
            // (b) characters actually match
            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
                lookup[i][j] = lookup[i - 1][j - 1];

            // If characters don't match
            else
                lookup[i][j] = false;
        }
    }

    return lookup[n][m];
}

char fixo_path_ar[AMANDA__SIZE];
char final_file_or_folder_ar[AMANDA__SIZE];

/**
 * This function will adjust corretly the exit_path_ar with
 * the path information
 *
 * @param initial_path the initial path
 *
 * @param composed_path the composed path from where the
 * information will be used
 *
 * @param exit_path_ar the output path information
 *
 */
void fix_path_ar(char *initial_path, char *composed_path, char *exit_path_ar)
{
    char temp_ar[1024];
    strcpy(temp_ar, &composed_path[strlen(initial_path) + 1]);
    strcpy(exit_path_ar, temp_ar);
}

__int64 amanda_itens;
__int64 ricard0_itens_processed;

/**
 * This function will scan the disk for files and folders in the selected 
 * folder, non recursive search, and will call the function to dump the data 
 * to disk creating a Tar file or VAL file 
 *
 * @param lpcszFolder_ar the folder being search 
 *
 * @param first_call whether it is the first call 
 *
 * @param only_get_number_of_files_ar if we only want to get 
 * the number of files and folders 
 *
 * @return true if ok, false if it need to stop searching 
 *
 */
bool EnumerateFolder(char *lpcszFolder_ar, __attribute__((unused)) int first_call, bool only_get_number_of_files_ar)
{
    char *szDir = malloc(AMANDA__SIZE);
    char *lpcszFolder = malloc(AMANDA__SIZE);

    strcpy(lpcszFolder, lpcszFolder_ar);
    trocadordebackslashtras(lpcszFolder);

    if (strlen(lpcszFolder))
    {
        if ('\\' == lpcszFolder[strlen(lpcszFolder) - 1])
        {
            lpcszFolder[strlen(lpcszFolder) - 1] = 0;
        }
    }

    memset(fixo_path_ar, 0, sizeof(fixo_path_ar));
    strcpy(fixo_path_ar, lpcszFolder);

    if (':' == fixo_path_ar[1] && '\\' == fixo_path_ar[2])
    {
        goto ok_ar_v27;
    }

    if ('\\' == fixo_path_ar[0] && '\\' == fixo_path_ar[1])
    {
        goto ok_ar_v27;
    }

    fatal_exit_k = 101;
    strcpy(error_message_k, "Invalid path");

    free(szDir);
    free(lpcszFolder);

    return false;

ok_ar_v27:;

    only_get_number_of_files_ar_v27 = only_get_number_of_files_ar;

    amanda_s_smart_ape(fixo_path_ar,
                       recurse_on_subfolders_arp, I_MODE_IS_ENUMFOLDER_1);

    free(szDir);
    free(lpcszFolder);

    return true;
}

#ifdef WIN64
#define MYCAST __int64
#else
#define MYCAST int
#endif

int running_ar = 0;
int return_value_ar = 0;

char tar_filename__ar[AMANDA__SIZE];
char path_with_the_files__ar[AMANDA__SIZE];
char patern__ar[20000];
tar_list_function_ar my_func_2__;
int __stdcall create_archive_internal_ar(char *tar_filename_ar, char *path_with_the_files_ar, char *patern_ar);

int __stdcall startapi(int parameter);

/**
 * This is the function that will create a Tar or VAL file
 *
 * @param tar_filename_ar the destination Tar file
 *
 * @param path_with_the_files_ar from where the files will be searched and added
 *
 * @param patern_ar the patern to search as an example: "*.ini *.txt", notice that
 * to include all you need to use "*" and not "*.*"
 *
 * @param compression_mode_external_ar the compression method
 * to use, see arp.h for valid modes, it is the enum
 * compression_modes_AR
 *
 * @param patern_ar the wildcards or filenames to include like
 * "*.txt *.ini *makefile*" it will include all *.txt *.ini and
 * all files that match *makefile*
 *
 * @param recurse_in_subfolders_arp if one it will recurse on
 * subfolders, 0 otherwise
 *
 * @param the__patern_ar__mode to include or exclude files, valid modes
 * are ARP_INCLUDE_FILES or ARP_EXCLUDE_FILES to obvious process
 *
 * @return 0 if no error, or any value if otherwise
 *
 */
int __stdcall create_archive_ar_v2(char *tar_filename_ar,
                                   char *path_with_the_files_ar,
                                   char *patern_ar,
                                   int compression_mode_external_ar,
                                   int recurse_in_subfolders_arp,
                                   enum mode_is_include_or_exclude the__patern_ar__mode)
{
    if (AMANDA__SIZE < strlen(tar_filename_ar)) //aqui?...
    {
        running_update = 0;
        return 2;
    }
    if (AMANDA__SIZE < strlen(path_with_the_files_ar))
    {
        running_update = 0;
        return 2;
    }
    if (19999 < strlen(patern_ar))
    {
        running_update = 0;
        return 2;
    }
    if (running_ar)
    {
        running_update = 0;
        return 1;
    }
    mode_is_include_or_exclude__ = the__patern_ar__mode;
    recurse_on_subfolders_arp = false;
    if (recurse_in_subfolders_arp)
    {
        recurse_on_subfolders_arp = true;
    }
    mode_is_parolin_p = true;
    return create_archive_ar(tar_filename_ar, path_with_the_files_ar, patern_ar, compression_mode_external_ar);
}

/**
 * This is the new function added in version 5.3.8 that allow the utilization of the embedded
 * libarchive library (https://libarchive.org/), notice that we have introduced a lot of modifications on the library
 * to make it better, take a look in the C# sample project to see the allowed formats supported by
 * our version
 *
 * @param tar_filename_ar the compressed file to be created, cannot be a relative path
 *
 * @param path_with_the_files_ar from where the files will be added
 * 
 * @param patern_ar the files to be added or wildcards, to add all ini and txt files use '*.txt *.ini'
 *
 * @param compression_mode_external_ar the compression mode to be used, for the moment the allowe are:<br><br>
 * P_MODE_IS_ZIP__NO_PASSWORD<br> 
 * P_MODE_IS_ZIP__ZIPCRYPTO  <br>
 * P_MODE_IS_ZIP__AES_128    <br>
 * P_MODE_IS_ZIP__AES_256    <br>
 * P_MODE_IS_7ZIP            <br>
 * P_MODE_IS_ISO9660         <br>
 * P_MODE_IS_TAR             <br>
 * P_MODE_IS_GNUTAR          <br>
 * P_MODE_IS_V7TAR           <br>
 * P_MODE_IS_TAR_GZIP        <br>
 * P_MODE_IS_TAR_BZIP2       <br>
 * P_MODE_IS_TAR_XZ          <br>
 * P_MODE_IS_GNUTAR_GZIP     <br>
 * P_MODE_IS_GNUTAR_BZIP2    <br>
 * P_MODE_IS_GNUTAR_XZ       <br>
 * P_MODE_IS_V7TAR_GZIP      <br>
 * P_MODE_IS_V7TAR_BZIP2     <br>
 * P_MODE_IS_V7TAR_XZ        <br>
 * P_MODE_IS_7ZIP_ENCRYPTED  <br>
 *
 * @param recurse_in_subfolders_arp it will define whether the DLL will recurse on subfolders
 *
 * @param the__patern_ar__mode if the patern passed above will define the files to include or
 * exclude, see the sample project running, allowed values are:<br><br>
 * ARP_INCLUDE_FILES   <br>
 * ARP_EXCLUDE_FILES   <br><br>
 *
 * @param compression_level_p_ string representation of the compression level "9" for
 * maximum compression
 *
 * @return 0 if no error, or a value in case of error, it will return an error
 * if you try to call the function while the DLL is already running
 *
 */
int __stdcall libarchive_create_archive_ar_v2(char *tar_filename_ar,
                                              char *path_with_the_files_ar,
                                              char *patern_ar,
                                              int compression_mode_external_ar,
                                              int recurse_in_subfolders_arp,
                                              enum mode_is_include_or_exclude the__patern_ar__mode,
                                              char * /* for your pleasure... */ compression_level_p_)
{

    if (MAX_PATH < strlen(tar_filename_ar))
    {
        dont_delete_7zip_file_i = false;
        running_update = 0;
        return 2;
    }
    if (MAX_PATH < strlen(path_with_the_files_ar))
    {
        dont_delete_7zip_file_i = false;
        running_update = 0;
        return 2;
    }

    if (19999 < strlen(patern_ar))
    {
        dont_delete_7zip_file_i = false;
        running_update = 0;
        return 2;
    }

    if (running_ar)
    {
        running_update = 0;
        return 1;
    }

    is_7zip_maria = false;
    if (P_MODE_IS_7ZIP == compression_mode_external_ar ||
        P_MODE_IS_7ZIP_ENCRYPTED == compression_mode_external_ar ||
        P_MODE_IS_7ZIP_ENCRYPTED_ALSO_HEADERS == compression_mode_external_ar)
    {
        is_7zip_maria = true;

        use_encryption_i = false;

        if (P_MODE_IS_7ZIP_ENCRYPTED == compression_mode_external_ar || P_MODE_IS_7ZIP_ENCRYPTED_ALSO_HEADERS ==
                                                                            compression_mode_external_ar)
        {
            use_encryption_i = true;
        }

        strcpy(tar_filename_ar_7zip_maria, tar_filename_ar);
        strcpy(path_with_the_files_ar_7zip_maria, path_with_the_files_ar);
        strcpy(patern_ar_7zip_maria, patern_ar);

        recurse_7zip_maria = recurse_in_subfolders_arp;

        true_if_include_7zip_maria = true;

        if (ARP_INCLUDE_FILES != the__patern_ar__mode)
        {
            true_if_include_7zip_maria = false;
        }

        strcpy(compression_level_7zip_maria, compression_level_p_);
    }

    mode_is_include_or_exclude__ = the__patern_ar__mode;
    recurse_on_subfolders_arp = false;
    if (recurse_in_subfolders_arp)
    {
        recurse_on_subfolders_arp = true;
    }

    compression_mode_p = compression_mode_external_ar;
    mode_is_parolin_p = false;

    enable_encryption(0);

    strcpy(compression_level_p, compression_level_p_);

    return create_archive_ar(tar_filename_ar, path_with_the_files_ar, patern_ar, AAKP_MODE_VAL);
}

/**
 * The internal function that will create a Tar or VAL file, old version, use create_archive_ar_v2 instead
 *
 */
int __stdcall create_archive_ar(char *tar_filename_ar,
                                char *path_with_the_files_ar,
                                char *patern_ar,
                                int compression_mode_external_ar)
{
    if (AMANDA__SIZE < strlen(tar_filename_ar))
    {
        is_7zip_maria = false;
        running_update = 0;
        return 2;
    }
    if (AMANDA__SIZE < strlen(path_with_the_files_ar))
    {
        is_7zip_maria = false;
        running_update = 0;
        return 2;
    }
    if (19999 < strlen(patern_ar))
    {
        is_7zip_maria = false;
        running_update = 0;
        return 2;
    }
    if (running_ar)
    {
        is_7zip_maria = false;
        running_update = 0;
        return 1;
    }
    running_ar = 1;
    running_update = 0;
    strcpy(tar_filename__ar, tar_filename_ar);
    strcpy(path_with_the_files__ar, path_with_the_files_ar);
    strcpy(patern__ar, patern_ar);
    compression_mode_ar = compression_mode_external_ar;

    HANDLE myhandle;
    MYCAST ThreadId;
    MYCAST parameter = 1;

    myhandle = CreateThread((LPSECURITY_ATTRIBUTES)0, //nao agora...amor...
                            (SIZE_T)0,
                            (void *)startapi,
                            (LPVOID)parameter,
                            (DWORD)0,
                            (LPDWORD)&ThreadId);

    CloseHandle(myhandle);
    return 0;
}

/**
 * This function is called when a call to create a Tar file is done, 
 * it ran in another thread
 *
 * @param parameter ignored parameter
 *
 * @return always 0 as you may expect...
 *
 */
int __stdcall startapi(__attribute__((unused)) int parameter)
{
    static char exit_data_ar[AMANDA__SIZE];
    if (is_7zip_maria)
    {
        dllinit_arp();
        init_rsp_arp_encrypt_arp();

        while (get_list_itens(exit_data_ar))
        {
            ;
        }

        if (dont_delete_7zip_file_i)
        {
            ; //nothing to do
        }
        else
        {
            _wunlink(amanda_utf8towide_1_(tar_filename_ar_7zip_maria));
        }

        return_value_ar = compress_7zip_i_func(tar_filename_ar_7zip_maria,
                                               path_with_the_files_ar_7zip_maria,
                                               patern_ar_7zip_maria,
                                               recurse_7zip_maria,
                                               true_if_include_7zip_maria,
                                               compression_level_7zip_maria,
                                               8,
                                               error_message_k,
                                               (void *)add_more_one,
                                               use_encryption_i,
                                               the_pass_arp_utf8_i,
                                               also_encrypt_headers_i);

        SetFileApisToANSI();

        ; //return_value_ar
    }
    else
    {

        //exit(0);

        return_value_ar = create_archive_internal_ar(tar_filename__ar, path_with_the_files__ar, patern__ar);
    }

    if (0 == return_value_ar)
    {
        pedro_dprintf(-1, "vai chamar\n");
        return_value_ar = split_in_multiple_volumes_p(tar_filename__ar);
    }

    //remove_temp_folder_i();

    mode_is_parolin_p = true;
    use_name_i = false;
    running_ar = 0;
    is_7zip_maria = false;
    dont_delete_7zip_file_i = false;
    return 0;
}

/**
 * It will retrieve the Tar creation status
 *
 * @return 0 if not running, 1 otherwise
 *
 */
int __stdcall GetStatus_ar(void)
{
    if (2 == (running_ar + running_update)) //hack as usual...
    {
        return 1;
    }
    return running_ar + running_update;
}

/**
 * It will return the return value for the creation process
 *
 * @return 0 if no error, other value otherwise
 *
 */
int __stdcall GetReturnValue_ar(void)
{
    return return_value_ar;
}

/**
 * It will return the percentage of the given value not as 100 but
 * 10000, 10000 == 100%
 *
 */
int getpor_10000(int max, int fatia)
{
    double maxa;
    double fatiaa;
    maxa = (double)max;
    fatiaa = (double)fatia;
    if (max == 0 || fatia == 0)
    {
        return 0;
    }
    maxa = ((double)10000 / maxa * fatiaa);
    return (int)maxa;
}

/**
 * It will return the progress position for the creation of Tar (VAL) file,
 * it ranges from 0 to 10000, 10000 == 100% for more granularity in the
 * progress bar because each pixels can have a single value giving more
 * smooth deslocation
 *
 */
int __stdcall GetProgress_ar(void)
{
    int val_ar;

    if (AAKP_MODE_TAR == compression_mode_ar || AAKP_MODE_VAL == compression_mode_ar)
    {
        if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
        {
            if (0 == first_step)
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }
            else
            {
                val_ar = 5000 + (internal_progress_z() / 2);
            }
        }
        else
        {
            val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size, ricrdo_bytes_read);
        }

        if (0 > val_ar)
        {
            val_ar = 0;
        }

        if (10000 < val_ar)
        {
            val_ar = 10000;
        }

        return val_ar;
    }
    else if (AAKP_MODE_TAR_GZIP == compression_mode_ar || AAKP_MODE_VAL_GZIP == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.33333)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }
            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (GetProgress_gzip_ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)GetProgress_gzip_ar_func() * (double)33.3333));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (GetProgress_gzip_ar_func() * 50);
                }
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_GZIP2 == compression_mode_ar || AAKP_MODE_VAL_GZIP2 == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_g2___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_g2___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_g2___ar_func() / 2);
                }
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_LZIP == compression_mode_ar || AAKP_MODE_VAL_LZIP == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }
            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_lzip_ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_lzip_ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_lzip_ar_func() / 2);
                }
                pedro_dprintf(-1, "prog %d\n", get_progress_lzip_ar_func());
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_LZMA == compression_mode_ar || AAKP_MODE_VAL_LZMA == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_lzma_ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_lzma_ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_lzma_ar_func() / 2);
                }
                pedro_dprintf(-1, "prog %d\n", get_progress_lzma_ar_func());
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_XZ == compression_mode_ar || AAKP_MODE_VAL_XZ == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_xz___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_xz___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_xz___ar_func() / 2);
                }

                pedro_dprintf(-1, "prog %d\n", get_progress_xz___ar_func());
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_COMPRESS == compression_mode_ar || AAKP_MODE_VAL_COMPRESS == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }
            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_co___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_co___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_co___ar_func() / 2);
                }

                pedro_dprintf(-1, "prog %d\n", get_progress_co___ar_func());
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_LZOP == compression_mode_ar || AAKP_MODE_VAL_LZOP == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_ju___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_ju___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_ju___ar_func() / 2);
                }

                pedro_dprintf(-1, "prog %d\n", get_progress_ju___ar_func());
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_LZ4 == compression_mode_ar || AAKP_MODE_VAL_LZ4 == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_l4___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_l4___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_l4___ar_func() / 2);
                }

                pedro_dprintf(-1, "prog %d\n", get_progress_l4___ar_func());
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_ZSTANDARD == compression_mode_ar || AAKP_MODE_VAL_ZSTANDARD == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_zs___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_zs___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_zs___ar_func() / 2);
                }

                pedro_dprintf(-1, "prog %d\n", get_progress_zs___ar_func());
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_BROTLI == compression_mode_ar || AAKP_MODE_VAL_BROTLI == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_br___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_br___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_br___ar_func() / 2);
                }

                pedro_dprintf(-1, "prog %d\n", get_progress_br___ar_func());
                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }
    else if (AAKP_MODE_TAR_BZ2 == compression_mode_ar || AAKP_MODE_VAL_BZ2 == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (GetProgress_bzip2_ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)((double)GetProgress_bzip2_ar_func() *
                                                                (double)100.0) /
                                                       (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (GetProgress_bzip2_ar_func() * 50);
                }

                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }

    else if (AAKP_MODE_TAR_BZIP3 == compression_mode_ar || AAKP_MODE_VAL_BZIP3 == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_b3___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_b3___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_b3___ar_func() / 2);
                }

                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }

    else if (AAKP_MODE_TAR_LZOP2 == compression_mode_ar || AAKP_MODE_VAL_LZOP2 == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_l3___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_l3___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_l3___ar_func() / 2);
                }

                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }

    else if (AAKP_MODE_TAR_LZ5 == compression_mode_ar || AAKP_MODE_VAL_LZ5 == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_l5___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_l5___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_l5___ar_func() / 2);
                }

                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }

    else if (AAKP_MODE_TAR_BROTLI2 == compression_mode_ar || AAKP_MODE_VAL_BROTLI2 == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_bb___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_bb___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_bb___ar_func() / 2);
                }

                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }

    else if (AAKP_MODE_TAR_COMPRESS2 == compression_mode_ar || AAKP_MODE_VAL_COMPRESS2 == compression_mode_ar)
    {
        if (0 == first_step)
        {
            if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
            {
                val_ar = getpor_10000_int64_t_ar((int64_t)((double)((double)amanda_pereira_total_size *
                                                                    (double)3.0)),
                                                 ricrdo_bytes_read);
            }
            else
            {
                val_ar = getpor_10000_int64_t_ar(amanda_pereira_total_size * 2, ricrdo_bytes_read);
            }

            if (0 > val_ar)
            {
                val_ar = 0;
            }

            if (10000 < val_ar)
            {
                val_ar = 10000;
            }

            return val_ar;
        }
        else
        {
            if (get_progress_c5___ar_func)
            {
                if (enable_encryption_arp_ && Z_NEW_MODE == internal_encryption_z_method)
                {
                    if (1 == first_step)
                    {
                        val_ar = 3333 + ((int)(double)((double)get_progress_c5___ar_func() / (double)3.0));
                    }
                    else
                    {
                        val_ar = 6666 + ((int)(double)((double)internal_progress_z() / (double)3.0));
                    }
                }
                else
                {
                    val_ar = 5000 + (get_progress_c5___ar_func() / 2);
                }

                if (0 > val_ar)
                {
                    val_ar = 0;
                }

                if (10000 < val_ar)
                {
                    val_ar = 10000;
                }

                return val_ar;
            }
            return 0;
        }
    }

    else if (AAKP_MODE_ISO == compression_mode_ar)
    {

        assert(0 && "Cannot handle iso anymore in Parolin, only libarchive");
        /*
      if (global_ptr_our_map_arp)
        {
          static int old_value_arp = 0;

          if (time_point_arp < (int) GetTickCount())
            {
              time_point_arp = GetTickCount() + 50;
              old_value_arp = global_ptr_our_map_arp->progress_arp;
              return old_value_arp;
            }
          return old_value_arp;
        }
	*/

        return 0;
    }
    else
    {
        pedro_dprintf(2, "Invalid format, file: %s, line: %d\n", __FILE__, __LINE__);
        exit(27);
    }
    return 0;
}

/**
 * It will pause the creation process, if for some unknown reason you
 * need to do it...
 *
 * @return always 0
 *
 */
int __stdcall Pause_ar(void)
{
    if (PauseExecution_gzip_ar_func)
    {
        PauseExecution_gzip_ar_func();
        PauseCompress_bzip2_ar_func();
        pause_lzip_aakp_lzip_ar_func();
        pause_lzma_aakp_lzma_ar_func();
        pause_xz___aakp_xz___ar_func();
        pause_co___aakp_co___ar_func();
        pause_ju___aakp_ju___ar_func();
        pause_l4___aakp_l4___ar_func();
        pause_zs___aakp_zs___ar_func();
        pause_br___aakp_br___ar_func();
        pause_g2___aakp_g2___ar_func();
        pause_b3___aakp_b3___ar_func();
        pause_l3___aakp_l3___ar_func();
        pause_l5___aakp_l5___ar_func();
        pause_bb___aakp_bb___ar_func();
        pause_c5___aakp_c5___ar_func();
    }

    init_rsp_arp_encrypt_arp();
    PauseExecution__arp_func();

    extract_pause__flag = true;

    pause_flag_ar = 1;

    if (global_ptr_our_map_arp)
    {
        global_ptr_our_map_arp->pause____arp = 1;
    }

    if (pause_7zip_i_func)
    {
        pause_7zip_i_func();
    }

    return 0;
}

/**
 * It will resume the creation process, is it was paused, notice that
 * is difficult to understand why someone will need to pause a compression
 * en encryption process, but it is here anyway
 *
 */
int __stdcall Resume_ar(void)
{
    if (ResumeExecution_gzip_ar_func)
    {
        ResumeExecution_gzip_ar_func();
        ResumeCompress_bzip2_ar_func();
        resume_lzip_aakp_lzip_ar_func();
        resume_lzma_aakp_lzma_ar_func();
        resume_xz___aakp_xz___ar_func();
        resume_co___aakp_co___ar_func();
        resume_ju___aakp_ju___ar_func();
        resume_l4___aakp_l4___ar_func();
        resume_zs___aakp_zs___ar_func();
        resume_br___aakp_br___ar_func();
        resume_g2___aakp_g2___ar_func();
        resume_b3___aakp_b3___ar_func();
        resume_l3___aakp_l3___ar_func();
        resume_l5___aakp_l5___ar_func();
        resume_bb___aakp_bb___ar_func();
        resume_c5___aakp_c5___ar_func();
    }

    init_rsp_arp_encrypt_arp();
    ResumeExecution_arp_func();

    extract_pause__flag = false;

    if (global_ptr_our_map_arp)
    {
        global_ptr_our_map_arp->pause____arp = 0;
    }
    pause_flag_ar = 0;

    if (resume_7zip_i_func)
    {
        resume_7zip_i_func();
    }

    return 0;
}

/**
 * It will cancel the creation process immediatelly, notice that
 * for the moment XZ and Zstandard multi-thread cannot be cancelled,
 * will be fixed soon, they was not developed by us
 *
 */
int __stdcall Cancel_ar(void)
{
    if (CancelExecution_gzip_ar_func)
    {
        CancelExecution_gzip_ar_func();
        CancelCompress_bzip2_ar_func();
        cancel_lzip_aakp_lzip_ar_func();
        cancel_lzma_aakp_lzma_ar_func();
        cancel_xz___aakp_xz___ar_func();
        cancel_co___aakp_co___ar_func();
        cancel_ju___aakp_ju___ar_func();
        cancel_l4___aakp_l4___ar_func();
        cancel_zs___aakp_zs___ar_func();
        cancel_br___aakp_br___ar_func();
        cancel_g2___aakp_g2___ar_func();
        cancel_b3___aakp_b3___ar_func();
        cancel_l3___aakp_l3___ar_func();
        cancel_l5___aakp_l5___ar_func();
        cancel_bb___aakp_bb___ar_func();
        cancel_c5___aakp_c5___ar_func();
    }

    init_rsp_arp_encrypt_arp();
    CancelExecution_arp_func();

    extract_cancel_flag = true;

    if (global_ptr_our_map_arp)
    {
        global_ptr_our_map_arp->cancel___arp = 1;
    }

    if (cancel_7zip_i_func)
    {
        cancel_7zip_i_func();
    }

    pause_flag_ar = 0;
    strcpy(error_message_k, "User cancel");
    fatal_exit_k = 27;
    return 0;
}

/**
 * It will cleanup the resources used by the VAL creation
 * process (internal use only...), __fastcall is an enhanced mode
 * for an API call not common but usefull because it is faster,
 * notice that in x64 only one api call do exist so __fastcall,
 * __cdecl and __stdcall are just the same windows call, if you
 * donÂ´t know assembly just ignore this information...
 *
 */
void __fastcall clean_up_update_ARP(void)
{
    if (mode_is_update_arp)
    {
        mode_is_update_arp = false;
        if (our_update_file_fopen_arp)
        {
            fclose(our_update_file_fopen_arp);
            our_update_file_fopen_arp = NULL;
        }
        if (-1 != our_update_file_open__arp)
        {
            close(our_update_file_open__arp);
            our_update_file_open__arp = -1;
        }
        if (strlen(update_filename_arp))
        {
            _wunlink(permissive_name_m_(amanda_utf8towide_1_(update_filename_arp)));
        }
    }
}

/**
 * Return the number of paths that have invalid attributes for the
 * last creation process
 *
 */
int __stdcall paths_with_invalid_attributes(void)
{
    return paths_with_invalid_attributes_arp;
}

/**
 * It will return the number of files that cannot be
 * read during the last creation process
 *
 * @return the number of files that cannot be read
 *
 */
int __stdcall get_cannot_read_warnings(void)
{

    int ret_val_i;
    ret_val_i = files_that_cannot_be_read + files_that_cannot_be_read_update;
    files_that_cannot_be_read_update = 0;

    return ret_val_i;
}
/**
 *  To see whether the path looks valid
 * 
 * 
 */
bool check_valid_path_i(char *data_i)
{

    if (4 > strlen(data_i))
    {

        if (3 != strlen(data_i))
        {
            return false;
        }

        if (('a' <= tolower(data_i[0]) && 'z' >= tolower(data_i[0])) && (':' == data_i[1]) && ('\\' == data_i[2] || '/' == data_i[2]))
        {
            return true;
        }

        if (('\\' == data_i[0]) && ('\\' == data_i[1]))
        {
            return true;
        }

        return false;
    }

    if (('a' <= tolower(data_i[0]) && 'z' >= tolower(data_i[0])) && (':' == data_i[1]) && ('\\' == data_i[2] || '/' == data_i[2]))
    {
        return true;
    }

    if (('\\' == data_i[0]) && ('\\' == data_i[1]))
    {
        return true;
    }

    return false;
}

/**
 * This is the internal function to create a Tar or VAL file
 *
 * @param tar_filename_ar the filename to be created
 *
 * @param path_with_the_files_ar the path to scan the files for
 *
 * @param patern_ar this is the information that will select what files
 * to include or exclude, as an example to include all ini and txt files use
 * "*.ini *.txt" the space is the delimiter, I hope you understand and notice
 * that "*.*" will not include files without an extension, to include all use
 * "*" a la Unix way
 *
 * @return 0 if no error, or other value otherwise
 *
 */
int __stdcall create_archive_internal_ar(char *tar_filename_ar, char *path_with_the_files_ar, char *patern_ar)
{
    static int64_t bytes_read_p_amandinha;
    FILE *my_val_file_p;
    int64_t file_size_p;
    paths_with_invalid_attributes_arp = 0;
    files_that_cannot_be_read = 0;
    mode_is_VAL_arp = false;
    static char original_destination_tar_file[AMANDA__SIZE];
    static char copy_ar[AMANDA__SIZE];
    DWORD attributes;
    static char exit_data_ar[AMANDA__SIZE];
    bool delete_temp_folder_z = false;
    amanda_pereira_total_size = 0;
    ricrdo_bytes_read = 0;

    memset(original_destination_tar_file, 0, sizeof(original_destination_tar_file));
    memset(copy_ar, 0, sizeof(copy_ar));
    memset(exit_data_ar, 0, sizeof(exit_data_ar));
    if (mode_is_update_libarchive_v27)
    {
        FILE *temp_file_i = NULL;
        FILE *writ_file_i = NULL;

        int64_t remaining_i;
        int len_i;

        char *buf_i;

        static char temp_i[AMANDA__SIZE];
        static char temp_i_f[AMANDA__SIZE];

        memset(temp_i, 0, sizeof(temp_i));
        memset(temp_i_f, 0, sizeof(temp_i_f));

        mode_is_update_libarchive_v27 = false;

        while (get_list_itens(exit_data_ar))
        {
            ;
        }

        dllinit_arp();

        fatal_exit_k = 0;

        if (false == check_valid_path_i(tar_filename_ar))
        {

            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
                mode_is_update_arp = false;
            }

            strcpy(error_message_k, "Invalid file to create, cannot be relative");
            init_playlist_z_june_24();
            _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_file_update_i)));
            return 1001;
        }

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"GZ_"))
        {

            strcpy(error_message_k, "Cannot create temporary file");
            mode_is_VAL_arp = false;

            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
                mode_is_update_arp = false;
            }

            init_playlist_z_june_24();
            _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_file_update_i)));
            return 30003;
        }

        bytes_read_p_amandinha = 0;
        set_progress_p_func(&bytes_read_p_amandinha);

        ret_arp_ = libarchive_create_archive_init_p_func(compression_mode_p, archive_name_array_filename, the_pass_arp, compression_level_p, number_of_threads_p);

        if (1 == ret_arp_)
        {
            fatal_exit_k = 200001;
            strcpy(error_message_k, "Invalid compression mode for a libarchive format for the moment");
            //clean_up_update_ARP();
            mode_is_VAL_arp = false;

            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
                mode_is_update_arp = false;
            }

            init_playlist_z_june_24();
            _wunlink(amanda_utf8towide_1_(temp_file_update_i));
            return fatal_exit_k;
        }

        if (2 == ret_arp_)
        {
            fatal_exit_k = 200002;
            strcpy(error_message_k, "Missing the password for the zip compressed file (cannot be empty), click 'Options' and set the password");
            //clean_up_update_ARP();
            mode_is_VAL_arp = false;

            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
                mode_is_update_arp = false;
            }

            init_playlist_z_june_24();
            _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_file_update_i)));
            return fatal_exit_k;
        }

        if (3 == ret_arp_)
        {
            fatal_exit_k = 200003;
            strcpy(error_message_k, "Invalid compression level for this format");
            //clean_up_update_ARP();
            mode_is_VAL_arp = false;

            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
                mode_is_update_arp = false;
            }
            init_playlist_z_june_24();
            _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_file_update_i)));
            return fatal_exit_k;
        }

        //aqui...

        //tem que ;lopear nos arquivos e diretorios
        //vejamos

        //libarchive_process_p_func((my_VAL_data.VAL_filename), file_or_folder_to_process);

        strcpy(temp_i, ar_gettemppath_z());
        strcat(temp_i, "d");
        _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_i)));

        rspmakedir_v2(temp_i);

        strcpy(temp_i_f, ar_gettemppath_z());
        strcat(temp_i_f, "a");

        if (!SetFileAttributesW(permissive_name_m_(
                                    amanda_utf8towide_1_(temp_i_f)),
                                FILE_ATTRIBUTE_ARCHIVE))
        {
            ;

            //exit(27);
        }

        temp_file_i = _wfopen(permissive_name_m_(amanda_utf8towide_1_(temp_file_update_i)), L"rb");

        if (NULL == temp_file_i)
        {
            init_playlist_z_june_24();
            fatal_exit_k = 300007;
            strcpy(error_message_k, "Cannot open temp file");
            goto exit_amanda;
        }

        {
            struct my_struct_for_list_ar_is_amanda_update_june_24 *my_ptr_ar;
            int i_z;

            my_ptr_ar = aak_inicio_is_amanda_update_june_24;
            for (i_z = 0; i_z < has_itens_is_amanda_update_june_24; i_z++)
            {

                progress_lib_v27 = getpor_10000(has_itens_is_amanda_update_june_24, i_z);

                if (my_ptr_ar->in_use_i)
                {

                    sprintf(process_message_k, "Processing %s", my_ptr_ar->item_entry_i);
                    add_more_one(process_message_k);

                    if (my_ptr_ar->is_dir_i)
                    {
                        void TimetToFileTime(time_t t, LPFILETIME pft);
                        //aqui amor...

                        {
                            time_t s = my_ptr_ar->mtime_i;

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
                                CreateFileW(permissive_name_m_(amanda_utf8towide_1_(temp_i)),
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
                        }

                        libarchive_process_p_func(my_ptr_ar->item_entry_i, temp_i);
                    }
                    else
                    {
                        _fseeki64(
                            temp_file_i,
                            my_ptr_ar->file_offset_i,
                            SEEK_SET);

                        writ_file_i = _wfopen(permissive_name_m_(amanda_utf8towide_1_(temp_i_f)), L"wb");

                        if (NULL == writ_file_i)
                        {
                            init_playlist_z_june_24();
                            fatal_exit_k = 300008;
                            strcpy(error_message_k, "Cannot open temp file to write");
                            progress_is_libarchive_v27 = false;
                            goto exit_amanda;
                        }
                        {
                            buf_i = malloc((1 << 17));
                            remaining_i = my_ptr_ar->filesize_i;
                            while ((len_i = fread(buf_i, 1, min(remaining_i, (1 << 17)), temp_file_i)))
                            {

                                fwrite(buf_i, 1, len_i, writ_file_i);
                                remaining_i -= len_i;
                            }

                            free(buf_i);

                            fclose(writ_file_i);
                        }

                        {
                            void TimetToFileTime(time_t t, LPFILETIME pft);
                            time_t s = my_ptr_ar->mtime_i;

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
                                CreateFileW(permissive_name_m_(amanda_utf8towide_1_(temp_i_f)),
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
                        }

                        if (!SetFileAttributesW(permissive_name_m_(
                                                    amanda_utf8towide_1_(temp_i_f)),
                                                my_ptr_ar->attributes_i))
                        {
                            ;

                            //exit(27);
                        }

                        libarchive_process_p_func(my_ptr_ar->item_entry_i, temp_i_f);

                        if (!SetFileAttributesW(
                                permissive_name_m_(amanda_utf8towide_1_(temp_i_f)),
                                FILE_ATTRIBUTE_ARCHIVE))
                        {
                            ;

                            //exit(27);
                        }
                    }
                }

                my_ptr_ar = my_ptr_ar->next_ar;
            }
        }

        ret_arp_ = libarchive_close_p_func();

        if (1 == ret_arp_)
        {
            fatal_exit_k = 200007;
            strcpy(error_message_k, "Fatal error in the compression function, can be a wrong combination of the number of threads and compression level, please verify");
        }
        if (0 == ret_arp_)
        {

            _wunlink(permissive_name_m_(amanda_utf8towide_1_(tar_filename_ar)));

            _wrename(permissive_name_m_(amanda_utf8towide_2_(archive_name_array_filename)), permissive_name_m_v27(amanda_utf8towide_1_(tar_filename_ar)));
        }

    exit_amanda:;

        mode_is_VAL_arp = false;

        if (mode_is_update_arp)
        {
            clean_up_update_ARP();
            mode_is_update_arp = false;
        }

        init_playlist_z_june_24();

        if (temp_file_i)
        {
            fclose(temp_file_i);
        }

        _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_file_update_i)));

        if (writ_file_i)
        {
            fclose(writ_file_i);
            writ_file_i = NULL;
        }

        _wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_i_f)));
        progress_is_libarchive_v27 = false;
        RemoveDirectoryW(permissive_name_m_(amanda_utf8towide_1_(temp_i)));
        return fatal_exit_k;
    }

    while (get_list_itens(exit_data_ar))
    {
        ;
    }

    if (false == check_valid_path_i(tar_filename_ar))
    {

        if (mode_is_update_arp)
        {
            clean_up_update_ARP();
        }

        strcpy(error_message_k, "Invalid file to create, cannot be relative");

        return 1001;
    }

    if (false == check_valid_path_i(path_with_the_files_ar))
    {

        if (mode_is_update_arp)
        {
            clean_up_update_ARP();
        }

        strcpy(error_message_k, "Invalid folder with files, cannot be relative");

        return 1002;
    }

    first_step = 0;

    amanda_itens = 0;
    ricard0_itens_processed = 0;
    strncpy_z(global_patern_ar, patern_ar, 19999);

    strtolower_ar(global_patern_ar);
    warning_flag = 0;
    pause_flag_ar = 0;
    files_count = 0;
    folders_count = 0;
    error_message_k[0] = 0;

    blocking_factor = DEFAULT_BLOCKING;
    record_size = DEFAULT_BLOCKING * BLOCKSIZE;
    record_index = 0;
    read_full_records = read_full_records_option;
    hit_eof = false;
    record_start_block = 0;
    error_message_k[0] = 0;

    if (AAKP_MODE_ISO == compression_mode_ar)
    {
        fatal_exit_k = 0;
        if (mode_is_update_arp)
        {
            strcpy(error_message_k, "Cannot update already existent ISO file for the moment, only in the future");
            clean_up_update_ARP();
            return 28001;
        }
        assert(0 && "Don't support ISO anymore, only in libarchive mode");
        return 0;
    }

    if (AAKP_MODE_TAR == compression_mode_ar)
    {
        strcpy(archive_name_array_filename, tar_filename_ar);
    }

    else if (AAKP_MODE_TAR_GZIP == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);
        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"GZ_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_TAR_GZIP2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"G2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_GZIP == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"GZ_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_VAL_GZIP2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"G2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }

        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_BZIP3 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"B3_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_BZIP3 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"B3_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_LZOP2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"L2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_LZOP2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"L2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_LZ5 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"L5_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_LZ5 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"L5_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_BROTLI2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"BB_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_BROTLI2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"B2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_COMPRESS2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"C2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_COMPRESS2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"C2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_LZIP == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"LZ_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }
    else if (AAKP_MODE_VAL_LZIP == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"LZ_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_LZMA == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"LM_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_LZMA == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"LM_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_XZ == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"XZ_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_XZ == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"XZ_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }
    else if (AAKP_MODE_TAR_COMPRESS == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"CO_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_COMPRESS == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"CO_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_LZOP == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"LP_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_LZOP == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"LP_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_LZ4 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"L4_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_LZ4 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"L4_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_ZSTANDARD == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"ZS_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_ZSTANDARD == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"ZS_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_TAR_BROTLI == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"BR_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_BROTLI == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"BR_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }
    else if (AAKP_MODE_TAR_BZ2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"B2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
    }

    else if (AAKP_MODE_VAL_BZ2 == compression_mode_ar)
    {
        delete_temp_folder_z = true;
        strcpy(original_destination_tar_file, tar_filename_ar);

        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), archive_name_array_filename, L"B2_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        mode_is_VAL_arp = true;
    }

    else if (AAKP_MODE_VAL == compression_mode_ar)
    {
        mode_is_VAL_arp = true;
        strcpy(archive_name_array_filename, tar_filename_ar);
    }

    else
    {
        assert(0 && "Unknown file format");
        exit(27);
    }

    if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
    {
        if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_encrypted_file_arp, L"EN_"))
        {
            if (mode_is_update_arp)
            {
                clean_up_update_ARP();
            }

            if (delete_temp_folder_z)
                _wunlink(permissive_name_m_(amanda_utf8towide_1_(archive_name_array_filename)));

            strcpy(error_message_k, "Cannot create temporary file");
            return 30003;
        }
        init_rsp_arp_encrypt_arp();
    }

    fatal_exit_k = 0;

    archive = -1;

    attributes = GetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(path_with_the_files_ar)));

    if (INVALID_FILE_ATTRIBUTES == attributes)
    {
        fatal_exit_k = 13;
        sprintf(copy_ar, "Path %s is invalid", path_with_the_files_ar);
        strcpy(error_message_k, copy_ar);
        clean_up_update_ARP();
        mode_is_VAL_arp = false;
        return fatal_exit_k;
    }
    else
    {
        if ((attributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
        {
            fatal_exit_k = 14;
            sprintf(copy_ar, "Path %s is valid but not a directory", path_with_the_files_ar);
            strcpy(error_message_k, copy_ar);
            clean_up_update_ARP();
            mode_is_VAL_arp = false;
            return fatal_exit_k;
        }
    }

    dllinit_arp();

    //pedro_dprintfW(0, L"amanda path %ls\n", amanda_path);

    if (fatal_exit_k)
    {
        clean_up_update_ARP();
        mode_is_VAL_arp = false;
        return fatal_exit_k;
    }

    open_archive(ACCESS_WRITE);
    if (fatal_exit_k)
    {
        snprintf(copy_ar, 600, " %d, %s\n", (int)fatal_exit_k, error_message_k);
        strcpy(error_message_k, copy_ar);
        if (-1 != archive)
        {
            close(archive);
            archive = -1;
        }
        clean_up_update_ARP();
        mode_is_VAL_arp = false;
        return fatal_exit_k;
    }

    if (!mode_is_parolin_p)
    {
        if (-1 != archive)
        {
            close(archive);
            archive = -1;
        }

        set_progress_p_func(&bytes_read_p);

        ret_arp_ = libarchive_create_archive_init_p_func(compression_mode_p, archive_name_array_filename, the_pass_arp, compression_level_p, number_of_threads_p);

        if (1 == ret_arp_)
        {
            fatal_exit_k = 200001;
            strcpy(error_message_k, "Invalid compression mode for a libarchive format for the moment");
            clean_up_update_ARP();
            mode_is_VAL_arp = false;
            return fatal_exit_k;
        }

        if (2 == ret_arp_)
        {
            fatal_exit_k = 200002;
            strcpy(error_message_k, "Missing the password for the zip compressed file (cannot be empty), click 'Options' and set the password");
            clean_up_update_ARP();
            mode_is_VAL_arp = false;
            return fatal_exit_k;
        }

        if (3 == ret_arp_)
        {
            fatal_exit_k = 200003;
            strcpy(error_message_k, "Invalid compression level for this format");
            clean_up_update_ARP();
            mode_is_VAL_arp = false;
            return fatal_exit_k;
        }
    }

    amanda_itens = 0;
    ricard0_itens_processed = 0;
    if (!mode_is_update_arp)
    {
        step_for_create_arp = ARP_MODE_NORMAL;
    }
    else
    {
        step_for_create_arp = ARP_MODE_IS_FIRST_STEP;
    }

    if (mode_is_VAL_arp)
    {
        first_pass_VAL_p = true;
    }

    EnumerateFolder(path_with_the_files_ar, 1, true);
    if (0 == fatal_exit_k)
    {
        EnumerateFolder(path_with_the_files_ar, 1, false);
        if (mode_is_update_arp)
        {
            assert(-1 != our_update_file_open__arp);
            close(our_update_file_open__arp);
            amanda_pereira_total_size += getfilesize_ar(update_filename_arp);
            our_update_file_open__arp = _wopen(amanda_utf8towide_1_(update_filename_arp), O_RDONLY | O_BINARY,
                                               _S_IREAD);
            if (-1 == our_update_file_open__arp)
            {
                fatal_exit_k = 10003;
                strcpy(error_message_k, "Cannot open temporary file to the update process");
                goto pula_arp;
            }
            dump_file_new_arp(NULL);
        }
    }

pula_arp:;
    if (!mode_is_VAL_arp)
    {
        write_eot();
    }

    close_archive();

    if (!mode_is_parolin_p)
    {
        ret_arp_ = libarchive_close_p_func();

        if (1 == ret_arp_)
        {

            fatal_exit_k = 200007;
            strcpy(error_message_k, "Fatal error in the compression function, can be a wrong combination of the number of threads and compression level, please verify");
        }
    }

#define fseek _fseeki64
#define ftell _ftelli64

    if (!mode_is_VAL_arp)
    {
        if (enable_encryption_arp_ && Z_OLD_MODE == internal_encryption_z_method)
        {
            int64_t file_size_arp;
            FILE *amanda_file;
            file_size_arp = getfilesize_ar(archive_name_array_filename);

            if (512 < file_size_arp)
            {
                amanda_file = _wfopen(amanda_utf8towide_1_(archive_name_array_filename), L"rb+");
                if (amanda_file)
                {
                    if (ARP_RC4 == encryption_method_to_create)
                    {
                        fseek(amanda_file, file_size_arp - 5, SEEK_SET);
                        char buf_amanda[1];
                        buf_amanda[0] = ARP_RC4;
                        fwrite(buf_amanda, 1, 1, amanda_file);
                    }
                    if (ARP_SERPENT == encryption_method_to_create)
                    {
                        fseek(amanda_file, file_size_arp - 5, SEEK_SET);
                        char buf_amanda[1];
                        buf_amanda[0] = ARP_SERPENT;
                        fwrite(buf_amanda, 1, 1, amanda_file);
                    }
                    if (ARP_MARS == encryption_method_to_create)
                    {
                        fseek(amanda_file, file_size_arp - 5, SEEK_SET);
                        char buf_amanda[1];
                        buf_amanda[0] = ARP_MARS;
                        fwrite(buf_amanda, 1, 1, amanda_file);
                    }
                    if (ARP_RC6 == encryption_method_to_create)
                    {
                        fseek(amanda_file, file_size_arp - 5, SEEK_SET);
                        char buf_amanda[1];
                        buf_amanda[0] = ARP_RC6;
                        fwrite(buf_amanda, 1, 1, amanda_file);
                    }
                    if (ARP_TWOFISH == encryption_method_to_create)
                    {
                        fseek(amanda_file, file_size_arp - 5, SEEK_SET);
                        char buf_amanda[1];
                        buf_amanda[0] = ARP_TWOFISH;
                        fwrite(buf_amanda, 1, 1, amanda_file);
                    }

                    fseek(amanda_file, file_size_arp - 4, SEEK_SET);
                    fwrite("misl", 1, 4, amanda_file);
                    fclose(amanda_file);
                }
            }
        }
    }

    if (0 == fatal_exit_k)
    {

        if (mode_is_parolin_p) // se nao for libarchive
        {
            if (mode_is_VAL_arp)
            {
                //aqui

                file_size_p = getfilesize_ar(archive_name_array_filename);
                my_val_file_p = _wfopen(amanda_utf8towide_1_(archive_name_array_filename), L"rb+");

                if (my_val_file_p)
                {
                    _fseeki64(my_val_file_p, 24, SEEK_SET);
                    fwrite(&file_size_p, 1, 8, my_val_file_p);
                    fclose(my_val_file_p);
                }
                else
                {
                    fatal_exit_k = 5117;
                    strcpy(error_message_k, "Cannot write the file size in VAL file");
                }
            }
        }
    }

    if (AAKP_MODE_TAR == compression_mode_ar || AAKP_MODE_VAL == compression_mode_ar)
    {
        ; //fascinante....
        first_step = 1;
        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(archive_name_array_filename);
        else
        {
            _wunlink(amanda_utf8towide_1_(archive_name_array_filename));
        }
    }
    else if (AAKP_MODE_TAR_GZIP == compression_mode_ar || AAKP_MODE_VAL_GZIP == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            Compress_gzip_ar_func(archive_name_array_filename, original_destination_tar_file, 6);
            while (0 == GetFinished_gzip_ar_func())
            {
                Sleep(5);
            }
            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "gzip compressed required %.3f seconds\n", inittimer2(1));
            returnvalue_ar = GetReturnValue_gzip_ar_func();
            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 7:
                fatal_exit_k = 52;
                strcpy(error_message_k, "Cannot open file to read");
                break;

            case 8:
                fatal_exit_k = 51;
                strcpy(error_message_k, "Cannot open file to write");
                break;

            case 14:
                fatal_exit_k = 54;
                strcpy(error_message_k, "Unable to write to output file");
                break;

            case 19:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User cancel");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }
    else if (AAKP_MODE_TAR_GZIP2 == compression_mode_ar || AAKP_MODE_VAL_GZIP2 == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;

        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_g2___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        6,
                                                        threads_z,
                                                        ar_gettemppath_z());

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "gzip2 compressed required %.3f seconds\n", inittimer2(1));
            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 7:
                fatal_exit_k = 1407;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 8:
                fatal_exit_k = 1408;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 14:
                fatal_exit_k = 1409;
                strcpy(error_message_k, "Unable to write to output file");
                break;

            case 16:
                fatal_exit_k = 1410;
                strcpy(error_message_k, "Unexpected error");
                break;

            case 19:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User cancel");
                break;

            case 401:
                fatal_exit_k = 1395;
                strcpy(error_message_k, "Cannot create temp file");
                break;

            case 402:
                fatal_exit_k = 1396;
                strcpy(error_message_k, "Cannot read from input file");
                break;

            case 403:
                fatal_exit_k = 1397;
                strcpy(error_message_k, "File access error");
                break;

            case 404:
                fatal_exit_k = 1398;
                strcpy(error_message_k, "Cannot open temp file");
                break;

            case 527:
                fatal_exit_k = 1399;
                strcpy(error_message_k, "deflate() failed");
                break;

            case 528:
                fatal_exit_k = 1423;
                strcpy(error_message_k, "inflate error Z_STREAM_END");
                break;

            case 529:
                fatal_exit_k = 1425;
                strcpy(error_message_k, "inflate error Z_NEED_DICT");
                break;

            case 530:
                fatal_exit_k = 1426;
                strcpy(error_message_k, "inflate error Z_STREAM_ERROR");
                break;

            case 531:
                fatal_exit_k = 1427;
                strcpy(error_message_k, "inflate error Z_MEM_ERROR");
                break;

            case 532:
                fatal_exit_k = 1428;
                strcpy(error_message_k, "inflate error Z_DATA_ERROR");
                break;

            case 533:
                fatal_exit_k = 1429;
                strcpy(error_message_k, "inflate error Z_BUF_ERROR ;-) ");
                break;

            case 534:
                fatal_exit_k = 1430;
                strcpy(error_message_k, "inflate error 'uknown'");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_BZIP3 == compression_mode_ar || AAKP_MODE_VAL_BZIP3 == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;

        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_b3___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        6,
                                                        threads_z,
                                                        ar_gettemppath_z());

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "bzip3 compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 23:
                fatal_exit_k = 1507;
                strcpy(error_message_k, "Input file read error");
                break;

            case 107:
                fatal_exit_k = 1508;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 108:
                fatal_exit_k = 1509;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 109:
                fatal_exit_k = 1509;
                strcpy(error_message_k, "Cannot open output temp file");
                break;

            case 114:
                fatal_exit_k = 1510;
                strcpy(error_message_k, "Cannot write to output file");
                break;

            case 116:
                fatal_exit_k = 1511;
                strcpy(error_message_k, "Unexpected error");
                break;

            case 119:
                fatal_exit_k = 1512;
                strcpy(error_message_k, "User cancel");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_LZOP2 == compression_mode_ar || AAKP_MODE_VAL_LZOP2 == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;

        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_l3___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        6,
                                                        threads_z,
                                                        ar_gettemppath_z());

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lzop2 compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 5108;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 5109;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 3:
                fatal_exit_k = 5110;
                strcpy(error_message_k, "Cannot close the input file");
                break;

            case 4:
                fatal_exit_k = 5111;
                strcpy(error_message_k, "Cannot close output file");
                break;

            case 5:
                fatal_exit_k = 5112;
                strcpy(error_message_k, "Cannot read from input file");
                break;

            case 6:
                fatal_exit_k = 5113;
                strcpy(error_message_k, "Cannot write to output file");
                break;

            case 7:
                fatal_exit_k = 5114;
                strcpy(error_message_k, "It isnot a valid compressed file");
                break;

            case 8:
                fatal_exit_k = 5115;
                strcpy(error_message_k, "Compression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            case 400:
                fatal_exit_k = 5116;
                strcpy(error_message_k, "Cannot write to temporary file");
                break;

            case 403:
                fatal_exit_k = 5117;
                strcpy(error_message_k, "File access error");
                break;

            case 405:
                fatal_exit_k = 5118;
                strcpy(error_message_k, "Cannot open temporary file");
                break;

            case 407:
                fatal_exit_k = 5119;
                strcpy(error_message_k, "Cannot create temp file");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_LZ5 == compression_mode_ar || AAKP_MODE_VAL_LZ5 == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;

        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_l5___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        6,
                                                        threads_z,
                                                        ar_gettemppath_z());

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lz5 compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 1108;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 1109;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 3:
                fatal_exit_k = 1110;
                strcpy(error_message_k, "Cannot close the input file");
                break;

            case 4:
                fatal_exit_k = 1111;
                strcpy(error_message_k, "Cannot close output file");
                break;

            case 5:
                fatal_exit_k = 1112;
                strcpy(error_message_k, "Cannot read from input file");
                break;

            case 6:
                fatal_exit_k = 1113;
                strcpy(error_message_k, "Cannot write to output file");
                break;

            case 7:
                fatal_exit_k = 1114;
                strcpy(error_message_k, "It isnot a valid compressed file");
                break;

            case 8:
                fatal_exit_k = 1115;
                strcpy(error_message_k, "Compression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            case 400:
                fatal_exit_k = 1116;
                strcpy(error_message_k, "Cannot write to temporary file");
                break;

            case 403:
                fatal_exit_k = 1117;
                strcpy(error_message_k, "File access error");
                break;

            case 405:
                fatal_exit_k = 1118;
                strcpy(error_message_k, "Cannot open temporary file");
                break;

            case 407:
                fatal_exit_k = 1119;
                strcpy(error_message_k, "Cannot create temp file");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_BROTLI2 == compression_mode_ar || AAKP_MODE_VAL_BROTLI2 == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;

        if (0 == fatal_exit_k)
        {
            first_step = 1;

            inittimer2(0);

            returnvalue_ar = compress_bb___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        6,
                                                        threads_z,
                                                        ar_gettemppath_z());

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "brotli2 compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 2108;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 2109;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 3:
                fatal_exit_k = 2110;
                strcpy(error_message_k, "Cannot close the input file");
                break;

            case 4:
                fatal_exit_k = 2111;
                strcpy(error_message_k, "Cannot close output file");
                break;

            case 5:
                fatal_exit_k = 2112;
                strcpy(error_message_k, "Cannot read from input file");
                break;

            case 6:
                fatal_exit_k = 2113;
                strcpy(error_message_k, "Cannot write to output file");
                break;

            case 7:
                fatal_exit_k = 2114;
                strcpy(error_message_k, "It isnot a valid compressed file");
                break;

            case 8:
                fatal_exit_k = 2115;
                strcpy(error_message_k, "Compression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            case 400:
                fatal_exit_k = 2116;
                strcpy(error_message_k, "Cannot write to temporary file");
                break;

            case 403:
                fatal_exit_k = 2117;
                strcpy(error_message_k, "File access error");
                break;

            case 405:
                fatal_exit_k = 2118;
                strcpy(error_message_k, "Cannot open temporary file");
                break;

            case 407:
                fatal_exit_k = 2119;
                strcpy(error_message_k, "Cannot create temp file");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_COMPRESS2 == compression_mode_ar || AAKP_MODE_VAL_COMPRESS2 == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;

        if (0 == fatal_exit_k)
        {
            first_step = 1;

            inittimer2(0);

            returnvalue_ar = compress_c5___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        6,
                                                        threads_z,
                                                        ar_gettemppath_z());

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "compress2 compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 2108;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 2109;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 3:
                fatal_exit_k = 2110;
                strcpy(error_message_k, "Cannot close the input file");
                break;

            case 4:
                fatal_exit_k = 2111;
                strcpy(error_message_k, "Cannot close output file");
                break;

            case 5:
                fatal_exit_k = 2112;
                strcpy(error_message_k, "Cannot read from input file");
                break;

            case 6:
                fatal_exit_k = 2113;
                strcpy(error_message_k, "Cannot write to output file");
                break;

            case 7:
                fatal_exit_k = 2114;
                strcpy(error_message_k, "It isnot a valid compressed file");
                break;

            case 8:
                fatal_exit_k = 2115;
                strcpy(error_message_k, "Compression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            case 400:
                fatal_exit_k = 2116;
                strcpy(error_message_k, "Cannot write to temporary file");
                break;

            case 403:
                fatal_exit_k = 2117;
                strcpy(error_message_k, "File access error");
                break;

            case 405:
                fatal_exit_k = 2118;
                strcpy(error_message_k, "Cannot open temporary file");
                break;

            case 407:
                fatal_exit_k = 2119;
                strcpy(error_message_k, "Cannot create temp file");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_LZIP == compression_mode_ar || AAKP_MODE_VAL_LZIP == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_lzip_rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        6);
            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lzip compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 302;
                strcpy(error_message_k, "Error in the lzip compressor");
                break;

            case 2:
                fatal_exit_k = 303;
                strcpy(error_message_k, "Corrupt or invalid lzip file");
                break;

            case 3:
                fatal_exit_k = 304;
                strcpy(error_message_k, "Internal lzip compressor error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_LZMA == compression_mode_ar || AAKP_MODE_VAL_LZMA == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_lzma_rspk_ar_func(archive_name_array_filename, original_destination_tar_file, 6);
            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lzma compressed required %.3f seconds\n", inittimer2(1));
            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 600;
                strcpy(error_message_k, "Error openning file for LZMA handling");
                break;

            case 3:
                fatal_exit_k = 601;
                strcpy(error_message_k, "LZMA memory error");
                break;

            case 4:
                fatal_exit_k = 602;
                strcpy(error_message_k, "LZMA data error");
                break;

            case 5:
                fatal_exit_k = 603;
                strcpy(error_message_k, "Unexpected LZMA error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_XZ == compression_mode_ar || AAKP_MODE_VAL_XZ == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;

        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_xz___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        6,
                                                        threads_z);
            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "xz compressed required %.3f seconds\n", inittimer2(1));
            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 707;
                strcpy(error_message_k, "Error openning file for read");
                break;

            case 2:
                fatal_exit_k = 708;
                strcpy(error_message_k, "Error openning file for write");
                break;

            case 3:
                fatal_exit_k = 709;
                strcpy(error_message_k, "XZ compression internal error");
                break;

            case 4:
                fatal_exit_k = 710;
                strcpy(error_message_k, "XZ decompression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_COMPRESS == compression_mode_ar || AAKP_MODE_VAL_COMPRESS == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_co___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        1001 /* nights... */);
            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "compress compressed required %.3f seconds\n", inittimer2(1));
            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 808;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 809;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 3:
                fatal_exit_k = 810;
                strcpy(error_message_k, "Cannot close the input file");
                break;

            case 4:
                fatal_exit_k = 811;
                strcpy(error_message_k, "Cannot close output file");
                break;

            case 5:
                fatal_exit_k = 812;
                strcpy(error_message_k, "Cannot read from input file");
                break;

            case 6:
                fatal_exit_k = 813;
                strcpy(error_message_k, "Cannot write to output file");
                break;

            case 7:
                fatal_exit_k = 814;
                strcpy(error_message_k, "It isnot a valid compressed file");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_LZOP == compression_mode_ar || AAKP_MODE_VAL_LZOP == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);

            returnvalue_ar = compress_ju___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        9);

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lzop compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 907;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 908;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 3:
                fatal_exit_k = 909;
                strcpy(error_message_k, "Compression error");
                break;

            case 4:
                fatal_exit_k = 910;
                strcpy(error_message_k, "Uncompression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_LZ4 == compression_mode_ar || AAKP_MODE_VAL_LZ4 == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_l4___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        9);

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lz4 compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 1108;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 1109;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 3:
                fatal_exit_k = 1110;
                strcpy(error_message_k, "Cannot close the input file");
                break;

            case 4:
                fatal_exit_k = 1111;
                strcpy(error_message_k, "Cannot close output file");
                break;

            case 5:
                fatal_exit_k = 1112;
                strcpy(error_message_k, "Cannot read from input file");
                break;

            case 6:
                fatal_exit_k = 1113;
                strcpy(error_message_k, "Cannot write to output file");
                break;

            case 7:
                fatal_exit_k = 1114;
                strcpy(error_message_k, "It isnot a valid compressed file");
                break;

            case 8:
                fatal_exit_k = 1115;
                strcpy(error_message_k, "Compression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_ZSTANDARD == compression_mode_ar || AAKP_MODE_VAL_ZSTANDARD == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_zs___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        9,
                                                        threads_z);

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "zstandard compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 1208;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 1209;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 7:
                fatal_exit_k = 1214;
                strcpy(error_message_k, "It isnot a valid compressed file");
                break;

            case 8:
                fatal_exit_k = 1215;
                strcpy(error_message_k, "Compression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and not handled correctly by the programmer", returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_BROTLI == compression_mode_ar || AAKP_MODE_VAL_BROTLI == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            returnvalue_ar = compress_br___rspk_ar_func(archive_name_array_filename,
                                                        original_destination_tar_file,
                                                        9);

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "brotli compressed required %.3f seconds\n", inittimer2(1));

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 1:
                fatal_exit_k = 1308;
                strcpy(error_message_k, "Cannot open input file");
                break;

            case 2:
                fatal_exit_k = 1309;
                strcpy(error_message_k, "Cannot open output file");
                break;

            case 7:
                fatal_exit_k = 1314;
                strcpy(error_message_k, "It isnot a valid compressed file");
                break;

            case 8:
                fatal_exit_k = 1315;
                strcpy(error_message_k, "Compression error");
                break;

            case 119:
                fatal_exit_k = 119;
                strcpy(error_message_k, "User abort");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else if (AAKP_MODE_TAR_BZ2 == compression_mode_ar || AAKP_MODE_VAL_BZ2 == compression_mode_ar)
    {
        volatile int returnvalue_ar = 0;
        if (0 == fatal_exit_k)
        {
            first_step = 1;
            inittimer2(0);
            Compress_bzip2_ar_func(archive_name_array_filename, original_destination_tar_file, 6);

            while (GetStatus_bzip2_ar_func())
            {
                Sleep(5);
            }

            pedro_dprintf(SHOW_DEBUG_SPEED_Z, "bzip2 compressed required %.3f seconds\n", inittimer2(1));

            returnvalue_ar = GetReturnValue_bzip2_ar_func();

            switch (returnvalue_ar)
            {
            case 0:;
                break;

            case 8:
                fatal_exit_k = 60;
                strcpy(error_message_k, "Cannot open file to read");
                break;

            case 9:
                fatal_exit_k = 61;
                strcpy(error_message_k, "Cannot open file to write");
                break;

            case 10:
                fatal_exit_k = 62;
                strcpy(error_message_k, "Cannot write to output file");
                break;

            case 11:
                fatal_exit_k = 63;
                strcpy(error_message_k, "Cannot initialize bzip2 compressor");
                break;

            case 119:
                fatal_exit_k = 64;
                strcpy(error_message_k, "User cancel");
                break;

            default:
                sprintf(my_error_as_a_programmer_z, "Error %d reported by the compressor and "
                                                    "not handled correctly by the programmer",
                        returnvalue_ar);
                strcpy(error_message_k, my_error_as_a_programmer_z);
                fatal_exit_k = returnvalue_ar;
                break;
            }
        }
        _wunlink(amanda_utf8towide_1_(archive_name_array_filename));

        if (0 == fatal_exit_k)
            encryption_process_new_mode_21_february_2021_z(original_destination_tar_file);
        else
        {
            _wunlink(amanda_utf8towide_1_(original_destination_tar_file));
        }
    }

    else
    {
        assert(0 && "Invalid format");
        exit(27);
    }

    if (0 == fatal_exit_k)
    {

        if (28 == warning_flag)
        {
            char temp___files_ar[1024] = " ";
            char temp_folders_ar[1024] = " ";
            strcpy(error_message_k, warning_message_k);
            if (0 == files_count)
            {
            }
            else if (1 == files_count)
            {
                sprintf(temp___files_ar, " 1 file ");
            }
            else
            {
                sprintf(temp___files_ar, " %d files ", (int)files_count);
            }

            if (0 == folders_count)
            {
            }
            else if (1 == folders_count)
            {
                sprintf(temp_folders_ar, " 1 folder ");
            }
            else
            {
                sprintf(temp_folders_ar, " %d folders ", (int)folders_count);
            }

            if ((1 < strlen(temp___files_ar)) && (1 < strlen(temp_folders_ar)))
            {
                snprintf(error_message_k, 600, "At least%sand%swas skipped because the path "
                                               "was larger than MAX_PATH (260)",
                         temp___files_ar, temp_folders_ar);
            }
            else
            {
                if (1 == strlen(temp___files_ar))
                {
                    temp___files_ar[0] = 0;
                }
                if (1 == strlen(temp_folders_ar))
                {
                    temp_folders_ar[0] = 0;
                }
                snprintf(error_message_k, 600, "At least%s%swas skipped because the path "
                                               "was larger than MAX_PATH (260)",
                         temp___files_ar, temp_folders_ar);
            }

            fatal_exit_k = warning_flag;
        }
    }
    clean_up_update_ARP();
    mode_is_VAL_arp = false;
    return fatal_exit_k;
}

/**
 * It will define the encryption method to use, it can be Z_OLD_MODE or
 * Z_NEW_MODE, recommended to use the new mode Z_NEW_MODE, read arp.h to
 * the description of these enum values
 *
 * @return always 0
 *
 */
int __amandacall set_encryption_method_z(enum z_encryption_method method_z)
{
    if (Z_OLD_MODE == method_z)
    {
        internal_encryption_z_method = Z_OLD_MODE;
        return 0;
    }
    if (Z_NEW_MODE == method_z)
    {
        internal_encryption_z_method = Z_NEW_MODE;
        return 0;
    }
    internal_encryption_z_method = Z_NEW_MODE;
    return 0;
}

/**
 * This function will define the encryption method to
 * be used, valid values are "AES 256 CTR", "RC4", "SERPENT",
 * "MARS", "RC6", "TWOFISH"
 *
 * @param method_arp the string with the selected method,
 * if it donÂ´t match the valid values the encryption method
 * will be "AES 256 CTR" for ARP_AES
 *
 * @return always 0
 *
 */
int __stdcall set_encryption_mode_z(char *method_arp)
{
    encryption_method_to_create = ARP_AES;
    if (0 == strcmp("AES 256 CTR", method_arp))
    {
        encryption_method_to_create = ARP_AES;
    }
    if (0 == strcmp("RC4", method_arp))
    {
        encryption_method_to_create = ARP_RC4;
    }
    if (0 == strcmp("SERPENT", method_arp))
    {
        encryption_method_to_create = ARP_SERPENT;
    }
    if (0 == strcmp("MARS", method_arp))
    {
        encryption_method_to_create = ARP_MARS;
    }
    if (0 == strcmp("RC6", method_arp))
    {
        encryption_method_to_create = ARP_RC6;
    }
    if (0 == strcmp("TWOFISH", method_arp))
    {
        encryption_method_to_create = ARP_TWOFISH;
    }
    return 0;
}

/**
 * It will copy the src to dest without setting the 0 string
 * end value as usual for C strings
 *
 */
int __stdcall stringtobyte(unsigned char *dest, unsigned char *src, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    return 0;
}

/**
 * It will just copy src to dest as a C string
 *
 * @return always 0
 *
 */
int __stdcall bytetostring(unsigned char *dest, unsigned char *src, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = 0;
    return 0;
}
/**
 * It will return the progress position
 *
 *
 */
int __stdcall libarchive_get_progress_p(void)
{
    int64_t arp_p;

    if (progress_is_libarchive_v27)
    {

        return progress_lib_v27;
    }

    if (is_7zip_maria)
    {
        dllinit_arp();
        return get_progress_7zip_i_func();
    }
    arp_p = getpor_10000_int64_t_ar(amanda_pereira_total_size, bytes_read_p);

    if (0 > arp_p)
    {
        return 0;
    }
    if (10000 < arp_p)
    {
        return 10000;
    }

    return arp_p;
}

int __stdcall set_7zip_encryption_mode_i(int also_encrypt_headers_i_)
{
    also_encrypt_headers_i = false;
    if (also_encrypt_headers_i_)
    {
        also_encrypt_headers_i = true;
    }
    return 0;
}
