//dureza...

#ifdef _M_X64
#define Print_Long_ARP "ll"
#else
#define Print_Long_ARP "I64"
#endif

#include "obstack.h"
#include "verify.h"

#ifndef S_ISCTG
#ifdef S_IFCTG
#define S_ISCTG(mode) (((mode)&S_IFMT) == S_IFCTG)
#else
#define S_ISCTG(mode) 0
#endif
#endif

#define CHKBLANKS "        "

#define UNAME_FIELD_SIZE 32
#define GNAME_FIELD_SIZE 32

#define NAME_FIELD_SIZE 100
#define PREFIX_FIELD_SIZE 155

#define GLOBAL_HEADER_TEMPLATE "/GlobalHead.%p.%n"

#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif

#define DEFAULT_ALIGNMENT MAX(__alignof__(long double),   \
                              MAX(__alignof__(uintmax_t), \
                                  __alignof__(void *)))
#define DEFAULT_ROUNDING MAX(sizeof(long double),   \
                             MAX(sizeof(uintmax_t), \
                                 sizeof(void *)))
static struct fmttab
{
    char const *name;
    enum archive_format fmt;
} const fmttab[] = {
    {"v7", V7_FORMAT},
    {"oldgnu", OLDGNU_FORMAT},
    {"ustar", USTAR_FORMAT},
    {"posix", POSIX_FORMAT},
#if 0 /* not fully supported yet */
  { "star", STAR_FORMAT },
#endif
    {"gnu", GNU_FORMAT},
    {"pax", POSIX_FORMAT}, /* An alias for posix */
    {NULL, 0}};

enum
{
    TIMESPEC_HZ = 1000000000
};
enum set_mtime_option_mode
{
    USE_FILE_MTIME,
    FORCE_MTIME,
    CLAMP_MTIME,
};

static time_t exthdr_mtime;
static char *exthdr_mtime_option /*arp*/;
static char *globexthdr_mtime_option;
static time_t globexthdr_mtime;

/* Number of global headers written so far.                   */
static size_t global_header_count;

/* Template for the name field of a 'g' type header           */
static char *globexthdr_name;
/* Override actual mtime if set to FORCE_MTIME or CLAMP_MTIME */
GLOBAL enum set_mtime_option_mode set_mtime_option;

/* If positive, save the user and root xattrs.  */
GLOBAL int xattrs_option;

/* If positive, save the SELinux context.  */
GLOBAL int selinux_context_option;

/* If positive, save the ACLs.  */
GLOBAL int acls_option;

/* Special operations flags.  */
enum
{
    /* For the sentinel at the end of the mode changes array.  */
    MODE_DONE,

    /* The typical case.  */
    MODE_ORDINARY_CHANGE,

    /* In addition to the typical case, affect the execute bits if at
     least one execute bit is set already, or if the file is a
     directory.  */
    MODE_X_IF_ANY_X,

    /* Instead of the typical case, copy some existing permissions for
     u, g, or o onto the other two.  Which of u, g, or o is copied
     is determined by which bits are set in the 'value' field.  */
    MODE_COPY_EXISTING
};

#define FILE_SYSTEM_PREFIX_LEN(P) 0
#define ISSLASH(C) ((C) == '/')
/*
 #define uid_t int
 #define gid_t int
 */

typedef int gid_t;
typedef int uid_t;

static bool
mode_to_chars(mode_t v, char *p, size_t s);

static bool
uid_to_chars(int v, char *p, size_t s);

static bool
gid_to_chars(int v, char *p, size_t s);

bool off_to_chars(off_t v, char *p, size_t s);

bool time_to_chars(time_t v, char *p, size_t s);

static bool
major_to_chars(major_t v, char *p, size_t s);

static bool
minor_to_chars(minor_t v, char *p, size_t s);

static void
string_to_chars(char const *str, char *p, size_t s);

#define UNAME_TO_CHARS(name, buf) string_to_chars(name, buf, sizeof(buf))
#define GNAME_TO_CHARS(name, buf) string_to_chars(name, buf, sizeof(buf))
#define MINOR_TO_CHARS(val, where) minor_to_chars(val, where, sizeof(where))
#define MAJOR_TO_CHARS(val, where) major_to_chars(val, where, sizeof(where))
#define MODE_TO_CHARS(val, where) mode_to_chars(val, where, sizeof(where))
#define UID_TO_CHARS(val, where) uid_to_chars(val, where, sizeof(where))
#define GID_TO_CHARS(val, where) gid_to_chars(val, where, sizeof(where))
#define S_ISUID 04000
#define S_ISGID 02000
#define S_ISVTX 01000
#define S_IRGRP (S_IRUSR >> 3)
#define S_IWGRP (S_IWUSR >> 3)
#define S_IXGRP (S_IXUSR >> 3)
#if 0
#define S_IROTH (S_IRUSR >> 6)
#define S_IWOTH (S_IWUSR >> 6)
#define S_IXOTH (S_IXUSR >> 6)
#endif
#define MODE_WXUSR (S_IWUSR | S_IXUSR)
#define MODE_R (S_IRUSR | S_IRGRP | S_IROTH)
#define MODE_RW (S_IWUSR | S_IWGRP | S_IWOTH | MODE_R)
#define MODE_RWX (S_IXUSR | S_IXGRP | S_IXOTH | MODE_RW)
#define MODE_ALL (S_ISUID | S_ISGID | S_ISVTX | MODE_RWX)
#if 0
#define S_IRWXG (S_IRGRP | S_IWGRP | S_IXGRP)
#define S_IRWXO (S_IROTH | S_IWOTH | S_IXOTH)
#endif
#define CHMOD_MODE_BITS \
    (S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO)

#define STRINGIFY_BIGINT(i, b) umaxtostr(i, b)

#define LG_8 3
#define LG_64 6
#define LG_256 8

/* The maximum uintmax_t value that can be represented with DIGITS digits,
   assuming that each digit is BITS_PER_DIGIT wide.  */
#define MAX_VAL_WITH_DIGITS(digits, bits_per_digit)             \
    ((digits) * (bits_per_digit) < sizeof(uintmax_t) * CHAR_BIT \
         ? ((uintmax_t)1 << ((digits) * (bits_per_digit))) - 1  \
         : (uintmax_t)-1)

/* The maximum uintmax_t value that can be represented with octal
   digits and a trailing NUL in BUFFER.  */
#define MAX_OCTAL_VAL(buffer) MAX_VAL_WITH_DIGITS(sizeof(buffer) - 1, LG_8)

#define OFF_TO_CHARS(val, where) off_to_chars(val, where, sizeof(where))
#define TIME_TO_CHARS(val, where) time_to_chars(val, where, sizeof(where))

/* The maximum uintmax_t value that can be represented with DIGITS digits,
   assuming that each digit is BITS_PER_DIGIT wide.  */
#define MAX_VAL_WITH_DIGITS(digits, bits_per_digit)             \
    ((digits) * (bits_per_digit) < sizeof(uintmax_t) * CHAR_BIT \
         ? ((uintmax_t)1 << ((digits) * (bits_per_digit))) - 1  \
         : (uintmax_t)-1)

GLOBAL uid_t owner_option;
GLOBAL gid_t group_option;
GLOBAL bool absolute_names_option;
GLOBAL char const *owner_name_option;
GLOBAL char const *group_name_option;
GLOBAL mode_t initial_umask;
typedef size_t (*Hash_hasher)(const void *, size_t);
typedef bool (*Hash_comparator)(const void *, const void *);
typedef void (*Hash_data_freer)(void *);
typedef bool (*Hash_processor)(void *, void *);

typedef struct hash_tuning Hash_tuning;

struct hash_table;

typedef struct hash_table Hash_table;

struct hash_entry
{
    void *data;
    struct hash_entry *next;
};

struct hash_table
{
    /* The array of buckets starts at BUCKET and extends to BUCKET_LIMIT-1,
     for a possibility of N_BUCKETS.  Among those, N_BUCKETS_USED buckets
     are not empty, there are N_ENTRIES active entries in the table.  */
    struct hash_entry *bucket;
    struct hash_entry const *bucket_limit;
    size_t n_buckets;
    size_t n_buckets_used;
    size_t n_entries;

    /* Tuning arguments, kept in a physically separate structure.  */
    const Hash_tuning *tuning;

    /* Three functions are given to 'hash_initialize', see the documentation
     block for this function.  In a word, HASHER randomizes a user entry
     into a number up from 0 up to some maximum minus 1; COMPARATOR returns
     true if two user entries compare equally; and DATA_FREER is the cleanup
     function for a user entry.  */
    Hash_hasher hasher;
    Hash_comparator comparator;
    Hash_data_freer data_freer;

    /* A linked list of freed struct hash_entry structs.  */
    struct hash_entry *free_entry_list;

#if USE_OBSTACK
    /* Whenever obstacks are used, it is possible to allocate all overflowed
     entries into a single stack, so they all can be freed in a single
     operation.  It is not clear if the speedup is worth the trouble.  */
    struct obstack entry_stack;
#endif
};

struct hash_tuning
{
    /* This structure is mainly used for 'hash_initialize', see the block
     documentation of 'hash_reset_tuning' for more complete comments.  */

    float shrink_threshold; /* ratio of used buckets to trigger a shrink */
    float shrink_factor;    /* ratio of new smaller size to original size */
    float growth_threshold; /* ratio of used buckets to trigger a growth */
    float growth_factor;    /* ratio of new bigger size to original size */
    bool is_n_buckets;      /* if CANDIDATE really means table size */
};

/* If an insertion makes the ratio of nonempty buckets to table size larger
   than the growth threshold (a number between 0.0 and 1.0), then increase
   the table size by multiplying by the growth factor (a number greater than
   1.0).  The growth threshold defaults to 0.8, and the growth factor
   defaults to 1.414, meaning that the table will have doubled its size
   every second time 80% of the buckets get used.  */
#define DEFAULT_GROWTH_THRESHOLD 0.8f
#define DEFAULT_GROWTH_FACTOR 1.414f

/* If a deletion empties a bucket and causes the ratio of used buckets to
   table size to become smaller than the shrink threshold (a number between
   0.0 and 1.0), then shrink the table by multiplying by the shrink factor (a
   number greater than the shrink threshold but smaller than 1.0).  The shrink
   threshold and factor default to 0.0 and 1.0, meaning that the table never
   shrinks.  */
#define DEFAULT_SHRINK_THRESHOLD 0.0f
#define DEFAULT_SHRINK_FACTOR 1.0f

/* Use this to initialize or reset a TUNING structure to
   some sensible values. */

static const Hash_tuning default_tuning =
    {
        DEFAULT_SHRINK_THRESHOLD,
        DEFAULT_SHRINK_FACTOR,
        DEFAULT_GROWTH_THRESHOLD,
        DEFAULT_GROWTH_FACTOR,
        false};

static Hash_table *prefix_table[2];

static Hash_table *owner_map;

struct mapentry
{
    uintmax_t orig_id;
    uintmax_t new_id;
    char *new_name;
};

static Hash_table *group_map;

/* Description of a mode change.  */
struct mode_change
{
    char op;          /* One of "=+-".  */
    char flag;        /* Special operations flag.  */
    mode_t affected;  /* Set for u, g, o, or a.  */
    mode_t value;     /* Bits to add/remove.  */
    mode_t mentioned; /* Bits explicitly mentioned.  */
};

GLOBAL struct mode_change *mode_option;

GLOBAL struct timespec mtime_option;

struct tar_sparse_file
{
    int fd;                               /* File descriptor */
    bool seekable;                        /* Is fd seekable? */
    off_t offset;                         /* Current offset in fd if seekable==false.
                                       Otherwise unused */
    off_t dumped_size;                    /* Number of bytes actually written
                                       to the archive */
    struct tar_stat_info *stat_info;      /* Information about the file */
    struct tar_sparse_optab const *optab; /* Operation table */
    void *closure;                        /* Any additional data optab calls might
                                       require */
};

//////////////////////////////////////////////////////////////////////////

static size_t
split_long_name(const char *name, size_t length);

static void
oldgnu_store_sparse_info(struct tar_sparse_file *file, size_t *pindex,
                         struct sparse *sp, size_t sparse_size);
union block *
write_extended(bool global, struct tar_stat_info *st, union block *old_header);

void finish_header(struct tar_stat_info *st,
                   union block *header, off_t block_ordinal);
void _obstack_newchunk(struct obstack *h, _OBSTACK_SIZE_T length);

static void *
call_chunkfun(struct obstack *h, size_t size);

static int
_obstack_begin_worker(struct obstack *h,
                      _OBSTACK_SIZE_T size, _OBSTACK_SIZE_T alignment);

int _obstack_begin(struct obstack *h,
                   _OBSTACK_SIZE_T size, _OBSTACK_SIZE_T alignment,
                   void *(*chunkfun)(size_t),
                   void (*freefun)(void *));

;
char *
last_component(char const *name);

void simple_finish_header(union block *header);

void tar_name_copy_str(char *dst, const char *src, size_t len);

union block *
start_private_header(const char *name, size_t size, time_t t);

void xheader_write(char type, char *name, time_t t, struct xheader *xhdr);

char *
xheader_ghdr_name(void);
static void
code_string(char const *string, char const *keyword, struct xheader *xhdr);

static struct keyword_list *keyword_global_override_list = {0};
static struct keyword_list *keyword_pattern_list = {0};
/* List of keyword/value pairs set by 'keyword:=value' option */
static struct keyword_list *keyword_override_list = {0};

void xheader_finish(struct xheader *xhdr);

static void
x_obstack_1grow(struct xheader *xhdr, char c);

static void
x_obstack_blank(struct xheader *xhdr, size_t length);

static void
x_obstack_grow(struct xheader *xhdr, const char *ptr, size_t length);

void xheader_string_add(struct xheader *xhdr, char const *s);

void xheader_string_begin(struct xheader *xhdr);

void finish_header(struct tar_stat_info *st,
                   union block *header, off_t block_ordinal);

void gid_to_gname(int gid, char **gname);

void uid_to_uname(uid_t uid, char **uname);

int timespec_cmp(struct timespec a, struct timespec b);

mode_t
mode_adjust(mode_t oldmode, bool dir, mode_t umask_value,
            struct mode_change const *changes, mode_t *pmode_bits);

void *
hash_lookup(const Hash_table *table, const void *entry);

int group_map_translate(gid_t gid, gid_t *new_gid, char const **new_name);

int owner_map_translate(uid_t uid, uid_t *new_uid, char const **new_name);

static union block *
write_long_name(struct tar_stat_info *st);

static union block *
write_short_name(struct tar_stat_info *st);

bool string_ascii_p(char const *p);

static union block *
write_header_name(struct tar_stat_info *st);

union block *
start_header(struct tar_stat_info *st);

static union block *
pax_start_header(struct tar_stat_info *st);

char *
stpcpy(char *dest, const char *src);

static struct hash_entry *
allocate_entry(Hash_table *table);

static bool
transfer_entries(Hash_table *dst, Hash_table *src, bool safe);

bool hash_rehash(Hash_table *table, size_t candidate);

static void
free_entry(Hash_table *table, struct hash_entry *entry);

static struct hash_entry *
safe_hasher(const Hash_table *table, const void *key);

static void *
hash_find_entry(Hash_table *table, const void *entry,
                struct hash_entry **bucket_head, bool delete);

int hash_insert_if_absent(Hash_table *table, void const *entry,
                          void const **matched_ent);

void *
hash_insert(Hash_table *table, void const *entry);

/* Compare two strings for equality.  */
static bool
hash_string_compare(void const *name1, void const *name2);

size_t
hash_string(const char *string, size_t n_buckets);

static size_t
hash_string_hasher(void const *name, size_t n_buckets);

static bool
is_prime(size_t candidate);

static size_t
next_prime(size_t candidate);

static size_t
compute_bucket_size(size_t candidate, const Hash_tuning *tuning);

static bool
check_tuning(Hash_table *table);

static bool
raw_comparator(const void *a, const void *b);

size_t
rotr_sz(size_t x, int n);

static size_t
raw_hasher(const void *data, size_t n);

Hash_table *
hash_initialize(size_t candidate, const Hash_tuning *tuning,
                Hash_hasher hasher, Hash_comparator comparator,
                Hash_data_freer data_freer);
static bool
hash_string_insert_prefix(Hash_table **table, char const *string, size_t len,
                          const char **return_prefix);

char *
safer_name_suffix(char const *file_name, bool link_target,
                  bool absolute_names);

char *
mdir_name(char const *file);

char *
dir_name(char const *file);

char *
xheader_format_name(struct tar_stat_info *st, const char *fmt, size_t n);

static bool
xheader_keyword_override_p(const char *keyword);

GLOBAL unsigned tar_sparse_major;
GLOBAL unsigned tar_sparse_minor;

static void
xheader_init(struct xheader *xhdr);

void xheader_store(char const *keyword, struct tar_stat_info *st,
                   void const *data);

bool xheader_keyword_deleted_p(const char *kw);

static struct xhdr_tab const *
locate_handler(char const *keyword);

/**
 * Tar related function, version 1.34
 *
 */
static uintmax_t
strtoumax(char const *ptr, char **endptr, int base)
{
    return strtoul(ptr, endptr, base);
}

/**
 * Tar related function, version 1.34
 *
 */
static intmax_t
strtoimax(char const *ptr, char **endptr, int base)
{
    return strtol(ptr, endptr, base);
}

#define ISDIGIT(c) ((unsigned)(c) - '0' <= 9)

#define xalloc_oversized(n, s) \
    ((size_t)(PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : SIZE_MAX - 1) / (s) < (n))

#define _GL_ADD_OVERFLOW(a, b, min, max) \
    __builtin_add_overflow_p(a, b, (__typeof__((a) + (b)))0)

#define _GL_BINARY_OP_OVERFLOW(a, b, op_result_overflow)       \
    op_result_overflow(a, b,                                   \
                       _GL_INT_MINIMUM(_GL_INT_CONVERT(a, b)), \
                       _GL_INT_MAXIMUM(_GL_INT_CONVERT(a, b)))

#define INT_ADD_OVERFLOW(a, b) \
    _GL_BINARY_OP_OVERFLOW(a, b, _GL_ADD_OVERFLOW)

enum oldgnu_add_status
{
    add_ok,
    add_finish,
    add_fail
};

enum sparse_scan_state
{
    scan_begin,
    scan_block,
    scan_end
};

struct tar_sparse_optab
{
    bool (*init)(struct tar_sparse_file *);
    bool (*done)(struct tar_sparse_file *);
    bool (*sparse_member_p)(struct tar_sparse_file *);
    bool (*dump_header)(struct tar_sparse_file *);
    bool (*fixup_header)(struct tar_sparse_file *);
    bool (*decode_header)(struct tar_sparse_file *);
    bool (*scan_block)(struct tar_sparse_file *, enum sparse_scan_state,
                       void *);
    bool (*dump_region)(struct tar_sparse_file *, size_t);
    bool (*extract_region)(struct tar_sparse_file *, size_t);
};

static bool
star_sparse_member_p(struct tar_sparse_file *file __attribute__((unused)));

static bool
star_fixup_header(struct tar_sparse_file *file);

static bool
star_get_sparse_info(struct tar_sparse_file *file);

static bool
sparse_extract_region(struct tar_sparse_file *file, size_t i);

static struct tar_sparse_optab const star_optab = {
    NULL, /* No init function */
    NULL, /* No done function */
    star_sparse_member_p,
    NULL,
    star_fixup_header,
    star_get_sparse_info,
    NULL, /* No scan_block function */
    NULL, /* No dump region function */
    sparse_extract_region,
};

static bool
sparse_dump_region(struct tar_sparse_file *file, size_t i);

/* Convert old GNU format sparse data to internal representation */
static bool
oldgnu_get_sparse_info(struct tar_sparse_file *file);

static bool
oldgnu_fixup_header(struct tar_sparse_file *file);

static bool
oldgnu_dump_header(struct tar_sparse_file *file);

static bool
oldgnu_sparse_member_p(struct tar_sparse_file *file __attribute__((unused)));

static struct tar_sparse_optab const oldgnu_optab = {
    NULL, /* No init function */
    NULL, /* No done function */
    oldgnu_sparse_member_p,
    oldgnu_dump_header,
    oldgnu_fixup_header,
    oldgnu_get_sparse_info,
    NULL, /* No scan_block function */
    sparse_dump_region,
    sparse_extract_region,
};

static bool
pax_sparse_member_p(struct tar_sparse_file *file);

static bool
pax_dump_header(struct tar_sparse_file *file);

static bool
pax_decode_header(struct tar_sparse_file *file);

static struct tar_sparse_optab const pax_optab = {
    NULL, /* No init function */
    NULL, /* No done function */
    pax_sparse_member_p,
    pax_dump_header,
    NULL,
    pax_decode_header,
    NULL, /* No scan_block function */
    sparse_dump_region,
    sparse_extract_region,
};

enum dump_status
sparse_extract_file(int fd, struct tar_stat_info *st, off_t *size);

static bool
tar_sparse_init(struct tar_sparse_file *file);

static bool
sparse_select_optab(struct tar_sparse_file *file);

static bool
tar_sparse_decode_header(struct tar_sparse_file *file);

static bool
tar_sparse_extract_region(struct tar_sparse_file *file, size_t i);

static bool
tar_sparse_done(struct tar_sparse_file *file);

static bool
to_chars(int negative, uintmax_t value, size_t valsize,
         uintmax_t (*substitute)(int *),
         char *where, size_t size, const char *type);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Tar related function, version 1.34
 *
 */
const char *
archive_format_string(enum archive_format fmt)
{
    struct fmttab const *p;

    for (p = fmttab; p->name; p++)
        if (p->fmt == fmt)
            return p->name;
    return "unknown?";
}

/**
 * Tar related function, version 1.34
 *
 */
static size_t
split_long_name(const char *name, size_t length)
{
    size_t i;

    if (length > PREFIX_FIELD_SIZE + 1)
        length = PREFIX_FIELD_SIZE + 1;
    else if (ISSLASH(name[length - 1]))
        length--;
    for (i = length - 1; i > 0; i--)
        if (ISSLASH(name[i]))
            break;
    return i;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
oldgnu_store_sparse_info(struct tar_sparse_file *file, size_t *pindex,
                         struct sparse *sp, size_t sparse_size)
{
    for (; *pindex < file->stat_info->sparse_map_avail && sparse_size > 0; sparse_size--, sp++, ++*pindex)
    {
        OFF_TO_CHARS(file->stat_info->sparse_map[*pindex].offset,
                     sp->offset);
        OFF_TO_CHARS(file->stat_info->sparse_map[*pindex].numbytes,
                     sp->numbytes);
    }
}

/**
 * Tar related function, version 1.34
 *
 */
void finish_header(struct tar_stat_info *st,
                   union block *header, __attribute__((unused)) off_t block_ordinal)
{
    /* Note: It is important to do this before the call to write_extended(),
     so that the actual ustar header is printed */
    /*
     if (verbose_option
      && header->header.typeflag != GNUTYPE_LONGLINK
      && header->header.typeflag != GNUTYPE_LONGNAME
      && header->header.typeflag != XHDTYPE
      && header->header.typeflag != XGLTYPE)
     {
      // FIXME: This global is used in print_header, sigh.
      current_format = archive_format;
      print_header (st, header, block_ordinal);
     }
   */
    header = write_extended(false, st, header);
    simple_finish_header(header);
}

/* Call functions with either the traditional malloc/free calling
   interface, or the mmalloc/mfree interface (that adds an extra first
   argument), based on the value of use_extra_arg.  */

/**
 * Tar related function, version 1.34
 *
 */
static void *
call_chunkfun(struct obstack *h, size_t size)
{
    if (h->use_extra_arg)
        return h->chunkfun.extra(h->extra_arg, size);
    else
        return h->chunkfun.plain(size);
}

/* Initialize an obstack H for use.  Specify chunk size SIZE (0 means default).
   Objects start on multiples of ALIGNMENT (0 means use default).

   Return nonzero if successful, calls obstack_alloc_failed_handler if
   allocation fails.  */

/**
 * Tar related function, version 1.34
 *
 */
static int
_obstack_begin_worker(struct obstack *h,
                      _OBSTACK_SIZE_T size, _OBSTACK_SIZE_T alignment)
{
    struct _obstack_chunk *chunk; /* points to new chunk */

    if (alignment == 0)
        alignment = DEFAULT_ALIGNMENT;
    if (size == 0)
    /* Default size is what GNU malloc can fit in a 4096-byte block.  */
    {
        /* 12 is sizeof (mhead) and 4 is EXTRA from GNU malloc.
         Use the values for range checking, because if range checking is off,
         the extra bytes won't be missed terribly, but if range checking is on
         and we used a larger request, a whole extra 4096 bytes would be
         allocated.

         These number are irrelevant to the new GNU malloc.  I suspect it is
         less sensitive to the size of the request.  */
        int extra = ((((12 + DEFAULT_ROUNDING - 1) & ~(DEFAULT_ROUNDING - 1)) + 4 + DEFAULT_ROUNDING - 1) & ~(DEFAULT_ROUNDING - 1));
        size = 4096 - extra;
    }

    h->chunk_size = size;
    h->alignment_mask = alignment - 1;

    chunk = h->chunk = call_chunkfun(h, h->chunk_size);
    if (!chunk)
    {
        assert(0 && "Malloc problems");
        exit(27);
    }
    h->next_free = h->object_base = __PTR_ALIGN((char *)chunk, chunk->contents,
                                                alignment - 1);
    h->chunk_limit = chunk->limit = (char *)chunk + h->chunk_size;
    chunk->prev = 0;
    /* The initial chunk now contains no empty object.  */
    h->maybe_empty_object = 0;
    h->alloc_failed = 0;
    return 1;
}

/**
 * Tar related function, version 1.34
 *
 */
int _obstack_begin(struct obstack *h,
                   _OBSTACK_SIZE_T size, _OBSTACK_SIZE_T alignment,
                   void *(*chunkfun)(size_t),
                   void (*freefun)(void *))
{
    h->chunkfun.plain = chunkfun;
    h->freefun.plain = freefun;
    h->use_extra_arg = 0;
    return _obstack_begin_worker(h, size, alignment);
}

/* Return the address of the last file name component of NAME.  If
   NAME has no relative file name components because it is a file
   system root, return the empty string.  */

/**
 * Tar related function, version 1.34
 *
 */
char *
last_component(char const *name)
{
    char const *base = name + FILE_SYSTEM_PREFIX_LEN(name);
    char const *p;
    bool saw_slash = false;

    while (ISSLASH(*base))
        base++;

    for (p = base; *p; p++)
    {
        if (ISSLASH(*p))
            saw_slash = true;
        else if (saw_slash)
        {
            base = p;
            saw_slash = false;
        }
    }

    return (char *)base;
}

/* Write a "private" header */

/**
 * Tar related function, version 1.34
 *
 */
union block *
start_private_header(const char *name, size_t size, time_t t)
{
    union block *header = find_next_block();

    memset(header->buffer, 0, sizeof(union block));

    tar_name_copy_str(header->header.name, name, NAME_FIELD_SIZE);
    OFF_TO_CHARS(size, header->header.size);

    TIME_TO_CHARS(t < 0 ? 0 : min(t, MAX_OCTAL_VAL(header->header.mtime)),
                  header->header.mtime);
    MODE_TO_CHARS(S_IFREG | S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH, header->header.mode);
    UID_TO_CHARS(0, header->header.uid);
    GID_TO_CHARS(0, header->header.gid);
    memcpy(header->header.magic, TMAGIC, TMAGLEN);
    memcpy(header->header.version, TVERSION, TVERSLEN);
    return header;
}

/**
 * Tar related function, version 1.34
 *
 */
void xheader_write(char type, char *name, time_t t, struct xheader *xhdr)
{
    union block *header;
    size_t size;
    char *p;

    size = xhdr->size;
    switch (type)
    {
    case XGLTYPE:
        if (globexthdr_mtime_option)
            t = globexthdr_mtime;
        break;

    case XHDTYPE:
        if (exthdr_mtime_option)
            t = exthdr_mtime;
        break;
    }
    header = start_private_header(name, size, t);
    header->header.typeflag = type;

    simple_finish_header(header);

    p = xhdr->buffer;

    do
    {
        size_t len;

        header = find_next_block();
        len = BLOCKSIZE;
        if (len > size)
            len = size;
        memcpy(header->buffer, p, len);
        if (len < BLOCKSIZE)
            memset(header->buffer + len, 0, BLOCKSIZE - len);
        p += len;
        size -= len;
        set_next_block_after(header);
    } while (size > 0);
    xheader_destroy(xhdr);

    if (type == XGLTYPE)
        global_header_count++;
}

/**
 * Tar related function, version 1.34
 *
 */
char *
xheader_ghdr_name(void)
{
    if (!globexthdr_name)
    {
        size_t len;
        const char *tmp = getenv("TMPDIR");
        if (!tmp)
            tmp = "/tmp";
        len = strlen(tmp) + sizeof(GLOBAL_HEADER_TEMPLATE); /* Includes nul */
        globexthdr_name = xmalloc(len);
        strcpy(globexthdr_name, tmp);
        strcat(globexthdr_name, GLOBAL_HEADER_TEMPLATE);
    }

    return xheader_format_name(NULL, globexthdr_name, global_header_count + 1);
}

/**
 * Tar related function, version 1.34
 *
 */
void xheader_finish(struct xheader *xhdr)
{
    struct keyword_list *kp;

    for (kp = keyword_override_list; kp; kp = kp->next)
        code_string(kp->value, kp->pattern, xhdr);

    xhdr->buffer = obstack_finish(xhdr->stk);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
x_obstack_blank(struct xheader *xhdr, size_t length)
{
    obstack_blank(xhdr->stk, length);
    xhdr->size += length;
}

/**
 * Tar related function, version 1.34
 *
 */
bool xheader_string_end(struct xheader *xhdr, char const *keyword)
{
    uintmax_t len;
    uintmax_t p;
    uintmax_t n = 0;
    size_t size;
    char nbuf[UINTMAX_STRSIZE_BOUND];
    char const *np;
    char *cp;

    if (xhdr->buffer)
        return false;
    xheader_init(xhdr);

    len = strlen(keyword) + xhdr->string_length + 3; /* ' ' + '=' + '\n' */

    do
    {
        p = n;
        np = umaxtostr(len + p, nbuf);
        n = nbuf + sizeof nbuf - 1 - np;
    } while (n != p);

    p = strlen(keyword) + n + 2;
    size = p;
    if (size != p)
    {
#if 0
      ERROR((0, 0,
             _("Generated keyword/value pair is too long (keyword=%s, length=%s)"),
             keyword, nbuf));
#endif

        pedro_dprintf(2, "Generated keyword/value pair is too long (keyword=%s, length=%s)", keyword, nbuf);
        obstack_free(xhdr->stk, obstack_finish(xhdr->stk));
        return false;
    }
    x_obstack_blank(xhdr, p);
    x_obstack_1grow(xhdr, '\n');
    cp = (char *)obstack_next_free(xhdr->stk) - xhdr->string_length - p - 1;
    memmove(cp + p, cp, xhdr->string_length);
    cp = stpcpy(cp, np);
    *cp++ = ' ';
    cp = stpcpy(cp, keyword);
    *cp++ = '=';
    return true;
}

/* Buildable strings */

/**
 * Tar related function, version 1.34
 *
 */
void xheader_string_add(struct xheader *xhdr, char const *s)
{
    if (xhdr->buffer)
        return;
    xheader_init(xhdr);
    xhdr->string_length += strlen(s);
    x_obstack_grow(xhdr, s, strlen(s));
}

/**
 * Tar related function, version 1.34
 *
 */
void xheader_string_begin(struct xheader *xhdr)
{
    xhdr->string_length = 0;
}

/* Given UID, find the corresponding UNAME.  */

/**
 * Tar related function, version 1.34, modified for windows
 *
 */
void uid_to_uname(__attribute__((unused)) uid_t uid, char **uname)
{
#if 1
    *uname = xstrdup(""); //little memory leak
    return;
#else
    struct passwd *passwd;

    if (uid != 0 && uid == cached_no_such_uid)
    {
        *uname = xstrdup("");
        return;
    }

    if (!cached_uname || uid != cached_uid)
    {
        passwd = getpwuid(uid);
        if (passwd)
        {
            cached_uid = uid;
            assign_string(&cached_uname, passwd->pw_name);
        }
        else
        {
            cached_no_such_uid = uid;
            *uname = xstrdup("");
            return;
        }
    }
    *uname = xstrdup(cached_uname);
#endif
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
minor_to_chars(minor_t v, char *p, size_t s)
{
    return to_chars(v < 0, (uintmax_t)v, sizeof v, 0, p, s, "minor_t");
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
major_to_chars(major_t v, char *p, size_t s)
{
    return to_chars(v < 0, (uintmax_t)v, sizeof v, 0, p, s, "major_t");
}

/**
 * Tar related function, version 1.34
 *
 */
int timespec_cmp(struct timespec a, struct timespec b)
{
    if (a.tv_sec < b.tv_sec)
        return -1;
    if (a.tv_sec > b.tv_sec)
        return 1;

    /* Pacify gcc -Wstrict-overflow (bleeding-edge circa 2017-10-02).  See:
     https://lists.gnu.org/r/bug-gnulib/2017-10/msg00006.html  */
    assume(-1 <= a.tv_nsec && a.tv_nsec <= 2 * TIMESPEC_HZ);
    assume(-1 <= b.tv_nsec && b.tv_nsec <= 2 * TIMESPEC_HZ);

    return a.tv_nsec - b.tv_nsec;
}

/* Return the file mode bits of OLDMODE (which is the mode of a
   directory if DIR), assuming the umask is UMASK_VALUE, adjusted as
   indicated by the list of change operations CHANGES.  If DIR, the
   type 'X' change affects the returned value even if no execute bits
   were set in OLDMODE, and set user and group ID bits are preserved
   unless CHANGES mentioned them.  If PMODE_BITS is not null, store into
 * PMODE_BITS a mask denoting file mode bits that are affected by
   CHANGES.

   The returned value and *PMODE_BITS contain only file mode bits.
   For example, they have the S_IFMT bits cleared on a standard
   Unix-like host.  */

/**
 * Tar related function, version 1.34
 *
 */
mode_t
mode_adjust(mode_t oldmode, bool dir, mode_t umask_value,
            struct mode_change const *changes, mode_t *pmode_bits)
{
    /* The adjusted mode.  */
    mode_t newmode = oldmode & CHMOD_MODE_BITS;

    /* File mode bits that CHANGES cares about.  */
    mode_t mode_bits = 0;

    for (; changes->flag != MODE_DONE; changes++)
    {
        mode_t affected = changes->affected;
        mode_t omit_change =
            (dir ? S_ISUID | S_ISGID : 0) & ~changes->mentioned;
        mode_t value = changes->value;

        switch (changes->flag)
        {
        case MODE_ORDINARY_CHANGE:
            break;

        case MODE_COPY_EXISTING:
            /* Isolate in 'value' the bits in 'newmode' to copy.  */
            value &= newmode;

            /* Copy the isolated bits to the other two parts.  */
            value |= ((value & (S_IRUSR | S_IRGRP | S_IROTH)
                           ? S_IRUSR | S_IRGRP | S_IROTH
                           : 0) |
                      (value & (S_IWUSR | S_IWGRP | S_IWOTH)
                           ? S_IWUSR | S_IWGRP | S_IWOTH
                           : 0) |
                      (value & (S_IXUSR | S_IXGRP | S_IXOTH)
                           ? S_IXUSR | S_IXGRP | S_IXOTH
                           : 0));
            break;

        case MODE_X_IF_ANY_X:
            /* Affect the execute bits if execute bits are already set
             or if the file is a directory.  */
            if ((newmode & (S_IXUSR | S_IXGRP | S_IXOTH)) | dir)
                value |= S_IXUSR | S_IXGRP | S_IXOTH;
            break;
        }

        /* If WHO was specified, limit the change to the affected bits.
         Otherwise, apply the umask.  Either way, omit changes as
         requested.  */
        value &= (affected ? affected : ~umask_value) & ~omit_change;

        switch (changes->op)
        {
        case '=':
            /* If WHO was specified, preserve the previous values of
             bits that are not affected by this change operation.
             Otherwise, clear all the bits.  */
            {
                mode_t preserved = (affected ? ~affected : 0) | omit_change;
                mode_bits |= CHMOD_MODE_BITS & ~preserved;
                newmode = (newmode & preserved) | value;
                break;
            }

        case '+':
            mode_bits |= value;
            newmode |= value;
            break;

        case '-':
            mode_bits |= value;
            newmode &= ~value;
            break;
        }
    }

    if (pmode_bits)
        *pmode_bits = mode_bits;
    return newmode;
}

/* If ENTRY matches an entry already in the hash table, return the
   entry from the table.  Otherwise, return NULL.  */

/**
 * Tar related function, version 1.34
 *
 */
void *
hash_lookup(const Hash_table *table, const void *entry)
{
    struct hash_entry const *bucket = safe_hasher(table, entry);
    struct hash_entry const *cursor;

    if (bucket->data == NULL)
        return NULL;

    for (cursor = bucket; cursor; cursor = cursor->next)
        if (entry == cursor->data || table->comparator(entry, cursor->data))
            return cursor->data;

    return NULL;
}

/**
 * Tar related function, version 1.34
 *
 */
int group_map_translate(gid_t gid, gid_t *new_gid, char const **new_name)
{
    int rc = 1;

    if (group_map)
    {
        struct mapentry ent, *res;

        ent.orig_id = gid;
        res = hash_lookup(group_map, &ent);
        if (res)
        {
            *new_gid = res->new_id;
            *new_name = res->new_name;
            return 0;
        }
    }

    if (group_option != (uid_t)-1)
    {
        *new_gid = group_option;
        rc = 0;
    }
    if (group_name_option)
    {
        *new_name = group_name_option;
        rc = 0;
    }

    return rc;
}

/**
 * Tar related function, version 1.34
 *
 */
int owner_map_translate(uid_t uid, uid_t *new_uid, char const **new_name)
{
    int rc = 1;

    if (owner_map)
    {
        struct mapentry ent, *res;

        ent.orig_id = uid;
        res = hash_lookup(owner_map, &ent);
        if (res)
        {
            *new_uid = res->new_id;
            *new_name = res->new_name;
            return 0;
        }
    }

    if (owner_option != (uid_t)-1)
    {
        *new_uid = owner_option;
        rc = 0;
    }
    if (owner_name_option)
    {
        *new_name = owner_name_option;
        rc = 0;
    }

    return rc;
}

/**
 * Tar related function, version 1.34
 *
 */
static union block *
write_header_name(struct tar_stat_info *st)
{
    if (archive_format == POSIX_FORMAT && !string_ascii_p(st->file_name))
    {
        xheader_store("path", st, NULL);
        return write_short_name(st);
    }
    else if (NAME_FIELD_SIZE - (archive_format == OLDGNU_FORMAT) < strlen(st->file_name))
        return write_long_name(st);
    else
        return write_short_name(st);
}

/* Make a header block for the file whose stat info is st,
   and return its address.  */

/**
 * Tar related function, version 1.34
 *
 */
union block *
start_header(struct tar_stat_info *st)
{
    union block *header;
    char const *uname = NULL;
    char const *gname = NULL;

    header = write_header_name(st);
    if (!header)
        return NULL;

    /* Override some stat fields, if requested to do so.  */
    owner_map_translate(st->stat.st_uid, (uid_t *)&st->stat.st_uid, &uname);
    group_map_translate(st->stat.st_gid, (uid_t *)&st->stat.st_gid, &gname);

    if (mode_option)
        st->stat.st_mode =
            ((st->stat.st_mode & ~MODE_ALL) | mode_adjust(st->stat.st_mode, S_ISDIR(st->stat.st_mode) != 0,
                                                          initial_umask, mode_option, NULL));

    /* Paul Eggert tried the trivial test ($WRITER cf a b; $READER tvf a)
     for a few tars and came up with the following interoperability
     matrix:

              WRITER
        1 2 3 4 5 6 7 8 9   READER
        . . . . . . . . .   1 = SunOS 4.2 tar
   # . . # # . . # #   2 = NEC SVR4.0.2 tar
        . . . # # . . # .   3 = Solaris 2.1 tar
        . . . . . . . . .   4 = GNU tar 1.11.1
        . . . . . . . . .   5 = HP-UX 8.07 tar
        . . . . . . . . .   6 = Ultrix 4.1
        . . . . . . . . .   7 = AIX 3.2
        . . . . . . . . .   8 = Hitachi HI-UX 1.03
        . . . . . . . . .   9 = Omron UNIOS-B 4.3BSD 1.60Beta

             . = works
   # = "impossible file type"

     The following mask for old archive removes the '#'s in column 4
     above, thus making GNU tar both a universal donor and a universal
     acceptor for Paul's test.  */

    if (archive_format == V7_FORMAT || archive_format == USTAR_FORMAT)
        MODE_TO_CHARS(st->stat.st_mode & MODE_ALL, header->header.mode);
    else
        MODE_TO_CHARS(st->stat.st_mode, header->header.mode);

    {
        uid_t uid = st->stat.st_uid;
        if (archive_format == POSIX_FORMAT && (int)(MAX_OCTAL_VAL(header->header.uid)) < uid)
        {
            xheader_store("uid", st, NULL);
            uid = 0;
        }
        if (!UID_TO_CHARS(uid, header->header.uid))
            return NULL;
    }

    {
        gid_t gid = st->stat.st_gid;
        if (archive_format == POSIX_FORMAT && (int)(MAX_OCTAL_VAL(header->header.gid)) < gid)
        {
            xheader_store("gid", st, NULL);
            gid = 0;
        }
        if (!GID_TO_CHARS(gid, header->header.gid))
            return NULL;
    }

    {
        off_t size = st->stat.st_size;
        if (archive_format == POSIX_FORMAT && (long int)(MAX_OCTAL_VAL(header->header.size)) < size)
        {
            xheader_store("size", st, NULL);
            size = 0;
        }
        if (!OFF_TO_CHARS(size, header->header.size))
            return NULL;
    }

    {
        struct timespec mtime;

        switch (set_mtime_option)
        {
        case USE_FILE_MTIME:
            mtime = st->mtime;
            break;

        case FORCE_MTIME:
            mtime = mtime_option;
            break;

        case CLAMP_MTIME:
            mtime = timespec_cmp(st->mtime, mtime_option) > 0
                        ? mtime_option
                        : st->mtime;
            break;
        }

        if (archive_format == POSIX_FORMAT)
        {
            if ((time_t)(MAX_OCTAL_VAL(header->header.mtime)) < mtime.tv_sec || mtime.tv_nsec != 0)
                xheader_store("mtime", st, &mtime);
            if ((time_t)(MAX_OCTAL_VAL(header->header.mtime)) < mtime.tv_sec)
                mtime.tv_sec = 0;
        }
        if (!TIME_TO_CHARS(mtime.tv_sec, header->header.mtime))
            return NULL;
    }

    /* FIXME */
    if (S_ISCHR(st->stat.st_mode) || S_ISBLK(st->stat.st_mode))
    {
        major_t devmajor = major(st->stat.st_rdev);
        minor_t devminor = minor(st->stat.st_rdev);

        if (archive_format == POSIX_FORMAT && (int)(MAX_OCTAL_VAL(header->header.devmajor)) < devmajor)
        {
            xheader_store("devmajor", st, NULL);
            devmajor = 0;
        }
        if (!MAJOR_TO_CHARS(devmajor, header->header.devmajor))
            return NULL;

        if (archive_format == POSIX_FORMAT && (int)(MAX_OCTAL_VAL(header->header.devminor)) < devminor)
        {
            xheader_store("devminor", st, NULL);
            devminor = 0;
        }
        if (!MINOR_TO_CHARS(devminor, header->header.devminor))
            return NULL;
    }
    else if (archive_format != GNU_FORMAT && archive_format != OLDGNU_FORMAT)
    {
        if (!(MAJOR_TO_CHARS(0, header->header.devmajor) && MINOR_TO_CHARS(0, header->header.devminor)))
            return NULL;
    }

    if (archive_format == POSIX_FORMAT)
    {
        xheader_store("atime", st, NULL);
        xheader_store("ctime", st, NULL);
    }
    else if (incremental_option)
        if (archive_format == OLDGNU_FORMAT || archive_format == GNU_FORMAT)
        {
            TIME_TO_CHARS(st->atime.tv_sec, header->oldgnu_header.atime);
            TIME_TO_CHARS(st->ctime.tv_sec, header->oldgnu_header.ctime);
        }

    header->header.typeflag = archive_format == V7_FORMAT ? AREGTYPE : REGTYPE;

    switch (archive_format)
    {
    case V7_FORMAT:
        break;

    case OLDGNU_FORMAT:
    case GNU_FORMAT: /*FIXME?*/
        /* Overwrite header->header.magic and header.version in one blow.  */
        strcpy(header->buffer + offsetof(struct posix_header, magic),
               OLDGNU_MAGIC);
        break;

    case POSIX_FORMAT:
    case USTAR_FORMAT:
        memcpy(header->header.magic, TMAGIC, TMAGLEN);
        memcpy(header->header.version, TVERSION, TVERSLEN);
        break;

    default:
        abort();
    }

    if (archive_format == V7_FORMAT || numeric_owner_option)
    {
        /* header->header.[ug]name are left as the empty string.  */
    }
    else
    {
        if (uname)
            st->uname = xstrdup(uname);
        else
            uid_to_uname(st->stat.st_uid, &st->uname);

        if (gname)
            st->gname = xstrdup(gname);
        else
            gid_to_gname(st->stat.st_gid, &st->gname);

        if (archive_format == POSIX_FORMAT && (strlen(st->uname) > UNAME_FIELD_SIZE || !string_ascii_p(st->uname)))
            xheader_store("uname", st, NULL);
        UNAME_TO_CHARS(st->uname, header->header.uname);

        if (archive_format == POSIX_FORMAT && (strlen(st->gname) > GNAME_FIELD_SIZE || !string_ascii_p(st->gname)))
            xheader_store("gname", st, NULL);
        GNAME_TO_CHARS(st->gname, header->header.gname);
    }

    if (archive_format == POSIX_FORMAT)
    {
        if (acls_option > 0)
        {
            if (st->acls_a_ptr)
                xheader_store("SCHILY.acl.access", st, NULL);
            if (st->acls_d_ptr)
                xheader_store("SCHILY.acl.default", st, NULL);
        }
        if ((selinux_context_option > 0) && st->cntx_name)
            xheader_store("RHT.security.selinux", st, NULL);
        if (xattrs_option > 0)
        {
            size_t scan_xattr = 0;
            struct xattr_array *xattr_map = st->xattr_map;

            while (scan_xattr < st->xattr_map_size)
            {
                xheader_store(xattr_map[scan_xattr].xkey, st, &scan_xattr);
                ++scan_xattr;
            }
        }
    }

    return header;
}

/* Start a header that uses the effective (shrunken) file size.  */

/**
 * Tar related function, version 1.34
 *
 */
static union block *
pax_start_header(struct tar_stat_info *st)
{
    off_t realsize = st->stat.st_size;
    union block *blk;

    st->stat.st_size = st->archive_file_size;
    blk = start_header(st);
    st->stat.st_size = realsize;
    return blk;
}

/* Get a new hash entry for a bucket overflow, possibly by recycling a
   previously freed one.  If this is not possible, allocate a new one.  */

/**
 * Tar related function, version 1.34
 *
 */
static struct hash_entry *
allocate_entry(Hash_table *table)
{
    struct hash_entry *new;

    if (table->free_entry_list)
    {
        new = table->free_entry_list;
        table->free_entry_list = new->next;
    }
    else
    {
#if USE_OBSTACK
        new = obstack_alloc(&table->entry_stack, sizeof *new);
#else
        new = malloc(sizeof *new);
#endif
    }

    return new;
}

/* Internal helper, to move entries from SRC to DST.  Both tables must
   share the same free entry list.  If SAFE, only move overflow
   entries, saving bucket heads for later, so that no allocations will
   occur.  Return false if the free entry list is exhausted and an
   allocation fails.  */

/**
 * Tar related function, version 1.34
 *
 */
static bool
transfer_entries(Hash_table *dst, Hash_table *src, bool safe)
{
    struct hash_entry *bucket;
    struct hash_entry *cursor;
    struct hash_entry *next;

    for (bucket = src->bucket; bucket < src->bucket_limit; bucket++)
        if (bucket->data)
        {
            void *data;
            struct hash_entry *new_bucket;

            /* Within each bucket, transfer overflow entries first and
           then the bucket head, to minimize memory pressure.  After
           all, the only time we might allocate is when moving the
           bucket head, but moving overflow entries first may create
           free entries that can be recycled by the time we finally
           get to the bucket head.  */
            for (cursor = bucket->next; cursor; cursor = next)
            {
                data = cursor->data;
                new_bucket = safe_hasher(dst, data);

                next = cursor->next;

                if (new_bucket->data)
                {
                    /* Merely relink an existing entry, when moving from a
                   bucket overflow into a bucket overflow.  */
                    cursor->next = new_bucket->next;
                    new_bucket->next = cursor;
                }
                else
                {
                    /* Free an existing entry, when moving from a bucket
                   overflow into a bucket header.  */
                    new_bucket->data = data;
                    dst->n_buckets_used++;
                    free_entry(dst, cursor);
                }
            }
            /* Now move the bucket head.  Be sure that if we fail due to
           allocation failure that the src table is in a consistent
           state.  */
            data = bucket->data;
            bucket->next = NULL;
            if (safe)
                continue;
            new_bucket = safe_hasher(dst, data);

            if (new_bucket->data)
            {
                /* Allocate or recycle an entry, when moving from a bucket
               header into a bucket overflow.  */
                struct hash_entry *new_entry = allocate_entry(dst);

                if (new_entry == NULL)
                    return false;

                new_entry->data = data;
                new_entry->next = new_bucket->next;
                new_bucket->next = new_entry;
            }
            else
            {
                /* Move from one bucket header to another.  */
                new_bucket->data = data;
                dst->n_buckets_used++;
            }
            bucket->data = NULL;
            src->n_buckets_used--;
        }
    return true;
}

/* For an already existing hash table, change the number of buckets through
   specifying CANDIDATE.  The contents of the hash table are preserved.  The
   new number of buckets is automatically selected so as to _guarantee_ that
   the table may receive at least CANDIDATE different user entries, including
   those already in the table, before any other growth of the hash table size
   occurs.  If TUNING->IS_N_BUCKETS is true, then CANDIDATE specifies the
   exact number of buckets desired.  Return true iff the rehash succeeded.  */

/**
 * Tar related function, version 1.34
 *
 */
bool hash_rehash(Hash_table *table, size_t candidate)
{
    Hash_table storage;
    Hash_table *new_table;
    size_t new_size = compute_bucket_size(candidate, table->tuning);

    if (!new_size)
        return false;
    if (new_size == table->n_buckets)
        return true;
    new_table = &storage;
    new_table->bucket = calloc(new_size, sizeof *new_table->bucket);
    if (new_table->bucket == NULL)
        return false;
    new_table->n_buckets = new_size;
    new_table->bucket_limit = new_table->bucket + new_size;
    new_table->n_buckets_used = 0;
    new_table->n_entries = 0;
    new_table->tuning = table->tuning;
    new_table->hasher = table->hasher;
    new_table->comparator = table->comparator;
    new_table->data_freer = table->data_freer;

    /* In order for the transfer to successfully complete, we need
     additional overflow entries when distinct buckets in the old
     table collide into a common bucket in the new table.  The worst
     case possible is a hasher that gives a good spread with the old
     size, but returns a constant with the new size; if we were to
     guarantee table->n_buckets_used-1 free entries in advance, then
     the transfer would be guaranteed to not allocate memory.
     However, for large tables, a guarantee of no further allocation
     introduces a lot of extra memory pressure, all for an unlikely
     corner case (most rehashes reduce, rather than increase, the
     number of overflow entries needed).  So, we instead ensure that
     the transfer process can be reversed if we hit a memory
     allocation failure mid-transfer.  */

    /* Merely reuse the extra old space into the new table.  */
#if USE_OBSTACK
    new_table->entry_stack = table->entry_stack;
#endif
    new_table->free_entry_list = table->free_entry_list;

    if (transfer_entries(new_table, table, false))
    {
        /* Entries transferred successfully; tie up the loose ends.  */
        free(table->bucket);
        table->bucket = new_table->bucket;
        table->bucket_limit = new_table->bucket_limit;
        table->n_buckets = new_table->n_buckets;
        table->n_buckets_used = new_table->n_buckets_used;
        table->free_entry_list = new_table->free_entry_list;
        /* table->n_entries and table->entry_stack already hold their value.  */
        return true;
    }

    /* We've allocated new_table->bucket (and possibly some entries),
     exhausted the free list, and moved some but not all entries into
     new_table.  We must undo the partial move before returning
     failure.  The only way to get into this situation is if new_table
     uses fewer buckets than the old table, so we will reclaim some
     free entries as overflows in the new table are put back into
     distinct buckets in the old table.

     There are some pathological cases where a single pass through the
     table requires more intermediate overflow entries than using two
     passes.  Two passes give worse cache performance and takes
     longer, but at this point, we're already out of memory, so slow
     and safe is better than failure.  */
    table->free_entry_list = new_table->free_entry_list;
    if (!(transfer_entries(table, new_table, true) && transfer_entries(table, new_table, false)))
        abort();
    /* table->n_entries already holds its value.  */
    free(new_table->bucket);
    return false;
}

/* Free a hash entry which was part of some bucket overflow,
   saving it for later recycling.  */

/**
 * Tar related function, version 1.34
 *
 */
static void
free_entry(Hash_table *table, struct hash_entry *entry)
{
    entry->data = NULL;
    entry->next = table->free_entry_list;
    table->free_entry_list = entry;
}

/* Hash KEY and return a pointer to the selected bucket.
   If TABLE->hasher misbehaves, abort.  */

/**
 * Tar related function, version 1.34
 *
 */
static struct hash_entry *
safe_hasher(const Hash_table *table, const void *key)
{
    size_t n = table->hasher(key, table->n_buckets);

    if (!(n < table->n_buckets))
        abort();
    return table->bucket + n;
}

/* This private function is used to help with insertion and deletion.  When
   ENTRY matches an entry in the table, return a pointer to the corresponding
   user data and set *BUCKET_HEAD to the head of the selected bucket.
   Otherwise, return NULL.  When DELETE is true and ENTRY matches an entry in
   the table, unlink the matching entry.  */

/**
 * Tar related function, version 1.34
 *
 */
static void *
hash_find_entry(Hash_table *table, const void *entry,
                struct hash_entry **bucket_head, bool delete)
{
    struct hash_entry *bucket = safe_hasher(table, entry);
    struct hash_entry *cursor;

    *bucket_head = bucket;

    /* Test for empty bucket.  */
    if (bucket->data == NULL)
        return NULL;

    /* See if the entry is the first in the bucket.  */
    if (entry == bucket->data || table->comparator(entry, bucket->data))
    {
        void *data = bucket->data;

        if (delete)
        {
            if (bucket->next)
            {
                struct hash_entry *next = bucket->next;

                /* Bump the first overflow entry into the bucket head, then save
                 the previous first overflow entry for later recycling.  */
                *bucket = *next;
                free_entry(table, next);
            }
            else
            {
                bucket->data = NULL;
            }
        }

        return data;
    }

    /* Scan the bucket overflow.  */
    for (cursor = bucket; cursor->next; cursor = cursor->next)
    {
        if (entry == cursor->next->data || table->comparator(entry, cursor->next->data))
        {
            void *data = cursor->next->data;

            if (delete)
            {
                struct hash_entry *next = cursor->next;

                /* Unlink the entry to delete, then save the freed entry for later
                 recycling.  */
                cursor->next = next->next;
                free_entry(table, next);
            }

            return data;
        }
    }

    /* No entry found.  */
    return NULL;
}

/* Insert ENTRY into hash TABLE if there is not already a matching entry.

   Return -1 upon memory allocation failure.
   Return 1 if insertion succeeded.
   Return 0 if there is already a matching entry in the table,
   and in that case, if MATCHED_ENT is non-NULL, set *MATCHED_ENT
   to that entry.

   This interface is easier to use than hash_insert when you must
   distinguish between the latter two cases.  More importantly,
   hash_insert is unusable for some types of ENTRY values.  When using
   hash_insert, the only way to distinguish those cases is to compare
   the return value and ENTRY.  That works only when you can have two
   different ENTRY values that point to data that compares "equal".  Thus,
   when the ENTRY value is a simple scalar, you must use
   hash_insert_if_absent.  ENTRY must not be NULL.  */

/**
 * Tar related function, version 1.34
 *
 */
int hash_insert_if_absent_version_1_32(Hash_table *table, void const *entry,
                                       void const **matched_ent)
{
    void *data;
    struct hash_entry *bucket;

    /* The caller cannot insert a NULL entry, since hash_lookup returns NULL
     to indicate "not found", and hash_find_entry uses "bucket->data == NULL"
     to indicate an empty bucket.  */
    if (!entry)
        abort();

    /* If there's a matching entry already in the table, return that.  */
    if ((data = hash_find_entry(table, entry, &bucket, false)) != NULL)
    {
        if (matched_ent)
            *matched_ent = data;
        return 0;
    }

    /* If the growth threshold of the buckets in use has been reached, increase
     the table size and rehash.  There's no point in checking the number of
     entries:  if the hashing function is ill-conditioned, rehashing is not
     likely to improve it.  */

    if (table->n_buckets_used > table->tuning->growth_threshold * table->n_buckets)
    {
        /* Check more fully, before starting real work.  If tuning arguments
         became invalid, the second check will rely on proper defaults.  */
        check_tuning(table);
        if (table->n_buckets_used > table->tuning->growth_threshold * table->n_buckets)
        {
            const Hash_tuning *tuning = table->tuning;
            float candidate =
                (tuning->is_n_buckets
                     ? (table->n_buckets * tuning->growth_factor)
                     : (table->n_buckets * tuning->growth_factor * tuning->growth_threshold));

            if (SIZE_MAX <= candidate)
                return -1;

            /* If the rehash fails, arrange to return NULL.  */
            if (!hash_rehash(table, candidate))
                return -1;

            /* Update the bucket we are interested in.  */
            if (hash_find_entry(table, entry, &bucket, false) != NULL)
                abort();
        }
    }

    /* ENTRY is not matched, it should be inserted.  */

    if (bucket->data)
    {
        struct hash_entry *new_entry = allocate_entry(table);

        if (new_entry == NULL)
            return -1;

        /* Add ENTRY in the overflow of the bucket.  */

        new_entry->data = (void *)entry;
        new_entry->next = bucket->next;
        bucket->next = new_entry;
        table->n_entries++;
        return 1;
    }

    /* Add ENTRY right in the bucket head.  */

    bucket->data = (void *)entry;
    table->n_entries++;
    table->n_buckets_used++;

    return 1;
}

/**
 * Tar related function, version 1.34
 *
 */
int hash_insert_if_absent(Hash_table *table, void const *entry,
                          void const **matched_ent)
{
    void *data;
    struct hash_entry *bucket;

    /* The caller cannot insert a NULL entry, since hash_lookup returns NULL
     to indicate "not found", and hash_find_entry uses "bucket->data == NULL"
     to indicate an empty bucket.  */
    if (!entry)
        abort();

    /* If there's a matching entry already in the table, return that.  */
    if ((data = hash_find_entry(table, entry, &bucket, false)) != NULL)
    {
        if (matched_ent)
            *matched_ent = data;
        return 0;
    }

    /* If the growth threshold of the buckets in use has been reached, increase
     the table size and rehash.  There's no point in checking the number of
     entries:  if the hashing function is ill-conditioned, rehashing is not
     likely to improve it.  */

    if (table->n_buckets_used > table->tuning->growth_threshold * table->n_buckets)
    {
        /* Check more fully, before starting real work.  If tuning arguments
         became invalid, the second check will rely on proper defaults.  */
        check_tuning(table);
        if (table->n_buckets_used > table->tuning->growth_threshold * table->n_buckets)
        {
            const Hash_tuning *tuning = table->tuning;
            float candidate =
                (tuning->is_n_buckets
                     ? (table->n_buckets * tuning->growth_factor)
                     : (table->n_buckets * tuning->growth_factor * tuning->growth_threshold));

            if ((float)SIZE_MAX <= candidate)
                return -1;

            /* If the rehash fails, arrange to return NULL.  */
            if (!hash_rehash(table, candidate))
                return -1;

            /* Update the bucket we are interested in.  */
            if (hash_find_entry(table, entry, &bucket, false) != NULL)
                abort();
        }
    }

    /* ENTRY is not matched, it should be inserted.  */

    if (bucket->data)
    {
        struct hash_entry *new_entry = allocate_entry(table);

        if (new_entry == NULL)
            return -1;

        /* Add ENTRY in the overflow of the bucket.  */

        new_entry->data = (void *)entry;
        new_entry->next = bucket->next;
        bucket->next = new_entry;
        table->n_entries++;
        return 1;
    }

    /* Add ENTRY right in the bucket head.  */

    bucket->data = (void *)entry;
    table->n_entries++;
    table->n_buckets_used++;

    return 1;
}

/* If ENTRY matches an entry already in the hash table, return the pointer
   to the entry from the table.  Otherwise, insert ENTRY and return ENTRY.
   Return NULL if the storage required for insertion cannot be allocated.
   This implementation does not support duplicate entries or insertion of
   NULL.  */

/**
 * Tar related function, version 1.34
 *
 */
void *
hash_insert(Hash_table *table, void const *entry)
{
    void const *matched_ent;
    int err = hash_insert_if_absent(table, entry, &matched_ent);

    return (err == -1
                ? NULL
                : (void *)(err == 0 ? matched_ent : entry));
}

/* Compare two strings for equality.  */

/**
 * Tar related function, version 1.34
 *
 */
static bool
hash_string_compare(void const *name1, void const *name2)
{
    return strcmp(name1, name2) == 0;
}

/* Return a hash index for a NUL-terminated STRING between 0 and N_BUCKETS-1.
   This is a convenience routine for constructing other hashing functions.  */

#if USE_DIFF_HASH

/* About hashings, Paul Eggert writes to me (FP), on 1994-01-01: "Please see
   B. J. McKenzie, R. Harries & T. Bell, Selecting a hashing algorithm,
   Software--practice & experience 20, 2 (Feb 1990), 209-224.  Good hash
   algorithms tend to be domain-specific, so what's good for [diffutils'] io.c
   may not be good for your application."  */

/**
 * Tar related function, version 1.34
 *
 */
size_t
hash_string(const char *string, size_t n_buckets)
{
#define HASH_ONE_CHAR(Value, Byte) \
    ((Byte) + rotl_sz(Value, 7))

    size_t value = 0;
    unsigned char ch;

    for (; (ch = *string); string++)
        value = HASH_ONE_CHAR(value, ch);
    return value % n_buckets;

#undef HASH_ONE_CHAR
}

#else /* not USE_DIFF_HASH */

/* This one comes from 'recode', and performs a bit better than the above as
   per a few experiments.  It is inspired from a hashing routine found in the
   very old Cyber 'snoop', itself written in typical Greg Mansfield style.
   (By the way, what happened to this excellent man?  Is he still alive?)  */

/**
 * Tar related function, version 1.34
 *
 */
size_t
hash_string(const char *string, size_t n_buckets)
{
    size_t value = 0;
    unsigned char ch;

    for (; (ch = *string); string++)
        value = (value * 31 + ch) % n_buckets;
    return value;
}

#endif /* not USE_DIFF_HASH */

/* Calculate the hash of a string.  */

/**
 * Tar related function, version 1.34
 *
 */
static size_t
hash_string_hasher(void const *name, size_t n_buckets)
{
    return hash_string(name, n_buckets);
}

/* Return true if CANDIDATE is a prime number.  CANDIDATE should be an odd
   number at least equal to 11.  */

/**
 * Tar related function, version 1.34
 *
 */
static bool
is_prime(size_t candidate)
{
    size_t divisor = 3;
    size_t square = divisor * divisor;

    while (square < candidate && (candidate % divisor))
    {
        divisor++;
        square += 4 * divisor;
        divisor++;
    }

    return (candidate % divisor ? true : false);
}

/**
 * Tar related function, version 1.34
 *
 */
static size_t
next_prime(size_t candidate)
{
    /* Skip small primes.  */
    if (candidate < 10)
        candidate = 10;

    /* Make it definitely odd.  */
    candidate |= 1;

    while (SIZE_MAX != candidate && !is_prime(candidate))
        candidate += 2;

    return candidate;
}

/**
 * Tar related function, version 1.34
 *
 */
static size_t
compute_bucket_size(size_t candidate, const Hash_tuning *tuning)
{
    if (!tuning->is_n_buckets)
    {
        float new_candidate = candidate / tuning->growth_threshold;
        if ((float)SIZE_MAX <= new_candidate)
            return 0;
        candidate = new_candidate;
    }
    candidate = next_prime(candidate);
    if (xalloc_oversized(candidate, sizeof(struct hash_entry *)))
        return 0;
    return candidate;
}

/* For the given hash TABLE, check the user supplied tuning structure for
   reasonable values, and return true if there is no gross error with it.
   Otherwise, definitively reset the TUNING field to some acceptable default
   in the hash table (that is, the user loses the right of further modifying
   tuning arguments), and return false.  */

/**
 * Tar related function, version 1.34
 *
 */
static bool
check_tuning(Hash_table *table)
{
    const Hash_tuning *tuning = table->tuning;
    float epsilon;

    if (tuning == &default_tuning)
        return true;

    /* Be a bit stricter than mathematics would require, so that
     rounding errors in size calculations do not cause allocations to
     fail to grow or shrink as they should.  The smallest allocation
     is 11 (due to next_prime's algorithm), so an epsilon of 0.1
     should be good enough.  */
    epsilon = 0.1f;

    if (epsilon < tuning->growth_threshold && tuning->growth_threshold < 1 - epsilon && 1 + epsilon < tuning->growth_factor && 0 <= tuning->shrink_threshold && tuning->shrink_threshold + epsilon < tuning->shrink_factor && tuning->shrink_factor <= 1 && tuning->shrink_threshold + epsilon < tuning->growth_threshold)
        return true;

    table->tuning = &default_tuning;
    return false;
}

/* If the user passes a NULL comparator, we use pointer comparison.  */

/**
 * Tar related function, version 1.34
 *
 */
static bool
raw_comparator(const void *a, const void *b)
{
    return a == b;
}

/**
 * Tar related function, version 1.34
 *
 */
size_t
rotr_sz(size_t x, int n)
{
    return ((x >> n) | (x << ((CHAR_BIT * sizeof x) - n))) & SIZE_MAX;
}

/**
 * Tar related function, version 1.34
 *
 */
static size_t
raw_hasher(const void *data, size_t n)
{
    /* When hashing unique pointers, it is often the case that they were
     generated by malloc and thus have the property that the low-order
     bits are 0.  As this tends to give poorer performance with small
     tables, we rotate the pointer value before performing division,
     in an attempt to improve hash quality.  */
    size_t val = rotr_sz((size_t)data, 3);

    return val % n;
}

/**
 * Tar related function, version 1.34
 *
 */
Hash_table *
hash_initialize(size_t candidate, const Hash_tuning *tuning,
                Hash_hasher hasher, Hash_comparator comparator,
                Hash_data_freer data_freer)
{
    Hash_table *table;

    if (hasher == NULL)
        hasher = raw_hasher;
    if (comparator == NULL)
        comparator = raw_comparator;

    table = malloc(sizeof *table);
    if (table == NULL)
        return NULL;

    if (!tuning)
        tuning = &default_tuning;
    table->tuning = tuning;
    if (!check_tuning(table))
    {
        /* Fail if the tuning options are invalid.  This is the only occasion
         when the user gets some feedback about it.  Once the table is created,
         if the user provides invalid tuning options, we silently revert to
         using the defaults, and ignore further request to change the tuning
         options.  */
        goto fail;
    }

    table->n_buckets = compute_bucket_size(candidate, tuning);
    if (!table->n_buckets)
        goto fail;

    table->bucket = calloc(table->n_buckets, sizeof *table->bucket);
    if (table->bucket == NULL)
        goto fail;
    table->bucket_limit = table->bucket + table->n_buckets;
    table->n_buckets_used = 0;
    table->n_entries = 0;

    table->hasher = hasher;
    table->comparator = comparator;
    table->data_freer = data_freer;

    table->free_entry_list = NULL;
#if USE_OBSTACK
    obstack_init(&table->entry_stack);
#endif
    return table;

fail:
    free(table);
    return NULL;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
hash_string_insert_prefix(Hash_table **table, char const *string, size_t len,
                          const char **return_prefix)
{
    Hash_table *t = *table;
    char *s;
    char *e;

    if (len)
    {
        s = xmalloc(len + 1);
        memcpy(s, string, len);
        s[len] = 0;
    }
    else
        s = xstrdup(string);

    if (!((t || (*table = t = hash_initialize(0, 0, hash_string_hasher,
                                              hash_string_compare, 0))) &&
          (e = hash_insert(t, s))))
    {
        assert(0 && "Malloc problems, exiting...");
        exit(27);
#if 0
      xalloc_die();
#endif
    }

    if (e == s)
    {
        if (return_prefix)
            *return_prefix = s;
        return 1;
    }
    else
    {
        free(s);
        return 0;
    }
}

/**
 * Tar related function, version 1.34
 *
 */
char *
safer_name_suffix(char const *file_name, bool link_target,
                  bool absolute_names)
{
    char const *p;

    if (absolute_names)
        p = file_name;
    else
    {
        /* Skip file system prefixes, leading file name components that contain
         "..", and leading slashes.  */

        size_t prefix_len = FILE_SYSTEM_PREFIX_LEN(file_name);

        for (p = file_name + prefix_len; *p;)
        {
            if (p[0] == '.' && p[1] == '.' && (ISSLASH(p[2]) || !p[2]))
                prefix_len = p + 2 - file_name;

            do
            {
                char c = *p++;
                if (ISSLASH(c))
                    break;
            } while (*p);
        }

        for (p = file_name + prefix_len; ISSLASH(*p); p++)
            continue;
        prefix_len = p - file_name;

        if (prefix_len)
        {
            const char *prefix;
            if (hash_string_insert_prefix(&prefix_table[link_target], file_name,
                                          prefix_len, &prefix))
            {
                static char const *const diagnostic[] =
                    {
                        "Removing leading `%s' from member names",
                        "Removing leading `%s' from hard link targets"};
#if 0
              WARN((0, 0, (const char *)diagnostic[link_target], prefix));
#endif
                pedro_dprintf(2, (char *)diagnostic[link_target], prefix);
            }
        }
    }

    if (!*p)
    {
        if (p == file_name)
        {
            static char const *const diagnostic[] =
                {
                    "Substituting `.' for empty member name",
                    "Substituting `.' for empty hard link target"};
#if 0
          WARN((0, 0, "%s", _(diagnostic[link_target])));
#endif
            pedro_dprintf(2, (char *)diagnostic[link_target]);
        }

        p = ".";
    }

    return (char *)p;
}

/**
 * Tar related function, version 1.34
 *
 */
char *
mdir_name(__attribute__((unused)) char const *file)
{
    assert(0 && "dentro de dir name");

//tem que testar primeiro pra ver, porque nao manipula diretorio
#if 0
  size_t length = dir_len(file);
  bool append_dot = (length == 0
                     || (FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE
                         && length == FILE_SYSTEM_PREFIX_LEN(file)
                         && file[2] != '\0' && !ISSLASH(file[2])));
  char *dir = malloc(length + append_dot + 1);
  if (!dir)
    return NULL;
  memcpy(dir, file, length);
  if (append_dot)
    dir[length++] = '.';
  dir[length] = '\0';
  return dir;
#endif

    return NULL;
}

/**
 * Tar related function, version 1.34
 *
 */
char *
dir_name(char const *file)
{
    char *result = mdir_name(file);

    if (!result)
    {
        assert(0 && "Malloc problem, exiting");
        exit(27);
    }
    return result;
}
/*
    string Includes:          Replaced By:
     %d                       The directory name of the file,
                              equivalent to the result of the
                              dirname utility on the translated
                              file name.
     %f                       The filename of the file, equivalent
                              to the result of the basename
                              utility on the translated file name.
     %p                       The process ID of the pax process.
     %n                       The value of the 3rd argument.
     %%                       A '%' character. */

/**
 * Tar related function, version 1.34
 *
 */
char *
xheader_format_name(struct tar_stat_info *st, const char *fmt, size_t n)
{
    char *buf;
    size_t len;
    char *q;
    const char *p;
    char *dirp = NULL;
    char *dir = NULL;
    char *base = NULL;
    char pidbuf[UINTMAX_STRSIZE_BOUND];
    char const *pptr = NULL;
    char nbuf[UINTMAX_STRSIZE_BOUND];
    char const *nptr = NULL;

    len = 0;
    for (p = fmt; *p; p++)
    {
        if (*p == '%' && p[1])
        {
            switch (*++p)
            {
            case '%':
                len++;
                break;

            case 'd':
                if (st)
                {
                    if (!dirp)
                        dirp = dir_name(st->orig_file_name);
                    dir = safer_name_suffix(dirp, false, absolute_names_option);
                    len += strlen(dir);
                }
                break;

            case 'f':
                if (st)
                {
                    base = last_component(st->orig_file_name);
                    len += strlen(base);
                }
                break;

            case 'p':
                pptr = umaxtostr(1, pidbuf);
                len += pidbuf + sizeof pidbuf - 1 - pptr;
                break;

            case 'n':
                nptr = umaxtostr(n, nbuf);
                len += nbuf + sizeof nbuf - 1 - nptr;
                break;

            default:
                len += 2;
            }
        }
        else
            len++;
    }

    buf = xmalloc(len + 1);
    for (q = buf, p = fmt; *p;)
    {
        if (*p == '%')
        {
            switch (p[1])
            {
            case '%':
                *q++ = *p++;
                p++;
                break;

            case 'd':
                if (dir)
                    q = stpcpy(q, dir);
                p += 2;
                break;

            case 'f':
                if (base)
                    q = stpcpy(q, base);
                p += 2;
                break;

            case 'p':
                q = stpcpy(q, pptr);
                p += 2;
                break;

            case 'n':
                q = stpcpy(q, nptr);
                p += 2;
                break;

            default:
                *q++ = *p++;
                if (*p)
                    *q++ = *p++;
            }
        }
        else
            *q++ = *p++;
    }

    free(dirp);

    /* Do not allow it to end in a slash */
    while (q > buf && ISSLASH(q[-1]))
        q--;
    *q = 0;
    return buf;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xheader_init(struct xheader *xhdr)
{
    if (!xhdr->stk)
    {
        xhdr->stk = xmalloc(sizeof *xhdr->stk);
        obstack_init(xhdr->stk);
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
tar_sparse_extract_region(struct tar_sparse_file *file, size_t i)
{
    if (file->optab->extract_region)
        return file->optab->extract_region(file, i);
    return false;
}

/**
 * Tar related function, version 1.34
 *
 */
enum dump_status
sparse_extract_file(int fd, struct tar_stat_info *st, off_t *size)
{
    bool rc = true;
    struct tar_sparse_file file;
    size_t i;

    if (!tar_sparse_init(&file))
        return dump_status_not_implemented;

    file.stat_info = st;
    file.fd = fd;
    file.seekable = lseek(fd, 0, SEEK_SET) == 0;
    file.offset = 0;

    rc = tar_sparse_decode_header(&file);
    for (i = 0; rc && i < file.stat_info->sparse_map_avail; i++)
        rc = tar_sparse_extract_region(&file, i);
    *size = file.stat_info->archive_file_size - file.dumped_size;
    return (tar_sparse_done(&file) && rc) ? dump_status_ok : dump_status_short;
}

enum dump_status
sparse_skip_file(struct tar_stat_info *st);

static bool
tar_sparse_init(struct tar_sparse_file *file);

static bool
lseek_or_error(struct tar_sparse_file *file, off_t offset);

static bool
dump_zeros(struct tar_sparse_file *file, off_t offset);

void seek_diag_details(char const *name, off_t offset);

void seek_warn_details(char const *name, off_t offset);

void seek_error_details(char const *name, off_t offset);

int sys_truncate(int fd);

size_t
blocking_write(int fd, void const *buf, size_t count);

static enum oldgnu_add_status
oldgnu_add_sparse(struct tar_sparse_file *file, struct sparse *s);

static void
sparse_add_map(struct tar_stat_info *st, struct sp_array const *sp);

void *
x2nrealloc(void *p, size_t *pn, size_t s);

static bool
decode_num(uintmax_t *num, char const *arg, uintmax_t maxval);

static bool
pax_dump_header_0(struct tar_sparse_file *file);

static bool
pax_dump_header_1(struct tar_sparse_file *file);

static bool
star_fixup_header(struct tar_sparse_file *file);

static bool
star_get_sparse_info(struct tar_sparse_file *file);

void skip_file(off_t size);

static bool
tar_sparse_done(struct tar_sparse_file *file);

bool sparse_member_p(struct tar_stat_info *st);

static bool
tar_sparse_member_p(struct tar_sparse_file *file);

bool sparse_fixup_header(struct tar_stat_info *st);

static bool
tar_sparse_fixup_header(struct tar_sparse_file *file);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Tar related function, version 1.34
 *
 */
static bool
tar_sparse_fixup_header(struct tar_sparse_file *file)
{
    if (file->optab->fixup_header)
        return file->optab->fixup_header(file);
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
bool sparse_fixup_header(struct tar_stat_info *st)
{
    struct tar_sparse_file file;

    if (!tar_sparse_init(&file))
        return false;
    file.stat_info = st;
    return tar_sparse_fixup_header(&file);
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
tar_sparse_member_p(struct tar_sparse_file *file)
{
    if (file->optab->sparse_member_p)
        return file->optab->sparse_member_p(file);
    return false;
}

/**
 * Tar related function, version 1.34
 *
 */
bool sparse_member_p(struct tar_stat_info *st)
{
    struct tar_sparse_file file;

    if (!tar_sparse_init(&file))
        return false;
    file.stat_info = st;
    return tar_sparse_member_p(&file);
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
tar_sparse_done(struct tar_sparse_file *file)
{
    if (file->optab->done)
        return file->optab->done(file);
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
tar_sparse_decode_header(struct tar_sparse_file *file)
{
    if (file->optab->decode_header)
        return file->optab->decode_header(file);
    return true;
}

/* Convert STAR format sparse data to internal representation */

/**
 * Tar related function, version 1.34
 *
 */
static bool
star_get_sparse_info(struct tar_sparse_file *file)
{
    size_t i;
    union block *h = current_header;
    int ext_p;
    enum oldgnu_add_status rc = add_ok;

    file->stat_info->sparse_map_avail = 0;

    if (h->star_in_header.prefix[0] == '\0' && h->star_in_header.sp[0].offset[10] != '\0')
    {
        /* Old star format */
        for (i = 0; i < SPARSES_IN_STAR_HEADER; i++)
        {
            rc = oldgnu_add_sparse(file, &h->star_in_header.sp[i]);
            if (rc != add_ok)
                break;
        }
        ext_p = h->star_in_header.isextended;
    }
    else
        ext_p = 1;

    for (; rc == add_ok && ext_p; ext_p = h->star_ext_header.isextended)
    {
        h = find_next_block();
        if (!h)
        {
            /*
                  ERROR ((0, 0, _("Unexpected EOF in archive")));
           */

            pedro_dprintf(2, "Unexpected EOF in archive");
            printf("Unexpected EOF in archive");
            return false;
        }
        set_next_block_after(h);
        for (i = 0; i < SPARSES_IN_STAR_EXT_HEADER && rc == add_ok; i++)
            rc = oldgnu_add_sparse(file, &h->star_ext_header.sp[i]);
        file->dumped_size += BLOCKSIZE;
    }

    if (rc == add_fail)
    {
        /*
         ERROR ((0, 0, _("%s: invalid sparse archive member"),
         file->stat_info->orig_file_name));
       */

        pedro_dprintf(2, "%s: Invalid sparse archive member", file->stat_info->orig_file_name);
        printf("%s: Invalid sparse archive member", file->stat_info->orig_file_name);
        return false;
    }
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
star_fixup_header(struct tar_sparse_file *file)
{
    /* NOTE! st_size was initialized from the header
     which actually contains archived size. The following fixes it */
    off_t realsize = OFF_FROM_HEADER(current_header->star_in_header.realsize);

    file->stat_info->archive_file_size = file->stat_info->stat.st_size;
    file->stat_info->stat.st_size = max(0, realsize); //what is this?!!! kkkkkkkk...
    return 0 <= realsize;
}

/* Star */

/**
 * Tar related function, version 1.34
 *
 */
static bool
star_sparse_member_p(struct tar_sparse_file *file __attribute__((unused)))
{
    return current_header->header.typeflag == GNUTYPE_SPARSE;
}

/**
 * Tar related function, version 1.34
 *
 */
void xheader_store(char const *keyword, struct tar_stat_info *st,
                   void const *data)
{
    struct xhdr_tab const *t;

    if (st->xhdr.buffer)
        return;
    t = locate_handler(keyword);
    if (!t || !t->coder)
        return;
    if (xheader_keyword_deleted_p(keyword))
        return;
    xheader_init(&st->xhdr);
    if (!xheader_keyword_override_p(keyword))
        t->coder(st, keyword, &st->xhdr, data);
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
pax_dump_header_1(struct tar_sparse_file *file)
{
#if 1
    off_t block_ordinal = current_block_ordinal();
    union block *blk;
    char *p, *q;
    size_t i;
    char nbuf[UINTMAX_STRSIZE_BOUND];
    off_t size = 0;
    struct sp_array *map = file->stat_info->sparse_map;
    char *save_file_name = file->stat_info->file_name;

#define COPY_STRING(b, dst, src)              \
    do                                        \
    {                                         \
        char *endp = b->buffer + BLOCKSIZE;   \
        char const *srcp = src;               \
        while (*srcp)                         \
        {                                     \
            if (dst == endp)                  \
            {                                 \
                set_next_block_after(b);      \
                b = find_next_block();        \
                dst = b->buffer;              \
                endp = b->buffer + BLOCKSIZE; \
            }                                 \
            *dst++ = *srcp++;                 \
        }                                     \
    } while (0)

    /* Compute stored file size */
    p = umaxtostr(file->stat_info->sparse_map_avail, nbuf);
    size += strlen(p) + 1;
    for (i = 0; i < file->stat_info->sparse_map_avail; i++)
    {
        p = umaxtostr(map[i].offset, nbuf);
        size += strlen(p) + 1;
        p = umaxtostr(map[i].numbytes, nbuf);
        size += strlen(p) + 1;
    }
    size = (size + BLOCKSIZE - 1) / BLOCKSIZE;
    file->stat_info->archive_file_size += size * BLOCKSIZE;
    file->dumped_size += size * BLOCKSIZE;

    /* Store sparse file identification */
    xheader_store("GNU.sparse.major", file->stat_info, NULL);
    xheader_store("GNU.sparse.minor", file->stat_info, NULL);
    xheader_store("GNU.sparse.name", file->stat_info, NULL);
    xheader_store("GNU.sparse.realsize", file->stat_info, NULL);

    file->stat_info->file_name =
        xheader_format_name(file->stat_info, "%d/GNUSparseFile.%p/%f", 0);
    /* Make sure the created header name is shorter than NAME_FIELD_SIZE: */
    if (strlen(file->stat_info->file_name) > NAME_FIELD_SIZE)
        file->stat_info->file_name[NAME_FIELD_SIZE] = 0;

    blk = pax_start_header(file->stat_info);
    finish_header(file->stat_info, blk, block_ordinal);
    free(file->stat_info->file_name);
    file->stat_info->file_name = save_file_name;

    blk = find_next_block();
    q = blk->buffer;
    p = umaxtostr(file->stat_info->sparse_map_avail, nbuf);
    COPY_STRING(blk, q, p);
    COPY_STRING(blk, q, "\n");
    for (i = 0; i < file->stat_info->sparse_map_avail; i++)
    {
        p = umaxtostr(map[i].offset, nbuf);
        COPY_STRING(blk, q, p);
        COPY_STRING(blk, q, "\n");
        p = umaxtostr(map[i].numbytes, nbuf);
        COPY_STRING(blk, q, p);
        COPY_STRING(blk, q, "\n");
    }
    memset(q, 0, BLOCKSIZE - (q - blk->buffer));
    set_next_block_after(blk);
    return true;
#endif
    return false;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
pax_dump_header_0(struct tar_sparse_file *file)
{
#if 1
    off_t block_ordinal = current_block_ordinal();
    union block *blk;
    size_t i;
    char nbuf[UINTMAX_STRSIZE_BOUND];
    struct sp_array *map = file->stat_info->sparse_map;
    char *save_file_name = NULL;

    /* Store the real file size */
    xheader_store("GNU.sparse.size", file->stat_info, NULL);
    xheader_store("GNU.sparse.numblocks", file->stat_info, NULL);

    if (xheader_keyword_deleted_p("GNU.sparse.map") || tar_sparse_minor == 0)
    {
        for (i = 0; i < file->stat_info->sparse_map_avail; i++)
        {
            xheader_store("GNU.sparse.offset", file->stat_info, &i);
            xheader_store("GNU.sparse.numbytes", file->stat_info, &i);
        }
    }
    else
    {
        xheader_store("GNU.sparse.name", file->stat_info, NULL);
        save_file_name = file->stat_info->file_name;
        file->stat_info->file_name = xheader_format_name(file->stat_info,
                                                         "%d/GNUSparseFile.%p/%f", 0);

        xheader_string_begin(&file->stat_info->xhdr);
        for (i = 0; i < file->stat_info->sparse_map_avail; i++)
        {
            if (i)
                xheader_string_add(&file->stat_info->xhdr, ",");
            xheader_string_add(&file->stat_info->xhdr,
                               umaxtostr(map[i].offset, nbuf));
            xheader_string_add(&file->stat_info->xhdr, ",");
            xheader_string_add(&file->stat_info->xhdr,
                               umaxtostr(map[i].numbytes, nbuf));
        }
        if (!xheader_string_end(&file->stat_info->xhdr,
                                "GNU.sparse.map"))
        {
            free(file->stat_info->file_name);
            file->stat_info->file_name = save_file_name;
            return false;
        }
    }
    blk = pax_start_header(file->stat_info);
    finish_header(file->stat_info, blk, block_ordinal);
    if (save_file_name)
    {
        free(file->stat_info->file_name);
        file->stat_info->file_name = save_file_name;
    }
    return true;
#endif

    return false;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
decode_num(uintmax_t *num, char const *arg, uintmax_t maxval)
{
    uintmax_t u;
    char *arg_lim;

    if (!ISDIGIT(*arg))
        return false;

    errno = 0;
    u = strtoumax(arg, &arg_lim, 10);

    if (!(u <= maxval && errno != ERANGE) || *arg_lim)
        return false;

    *num = u;
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
pax_decode_header(struct tar_sparse_file *file)
{
    if (file->stat_info->sparse_major > 0)
    {
        uintmax_t u;
        char nbuf[5000];
        union block *blk;
        char *p;
        size_t i;
        off_t start;

#define COPY_BUF(b, buf, src)                                           \
    do                                                                  \
    {                                                                   \
        char *endp = b->buffer + BLOCKSIZE;                             \
        char *dst = buf;                                                \
        do                                                              \
        {                                                               \
            if (dst == buf + 5000 - 1)                                  \
            {                                                           \
                printf("%s: numeric overflow in sparse archive member", \
                       file->stat_info->orig_file_name);                \
                return false;                                           \
            }                                                           \
            if (src == endp)                                            \
            {                                                           \
                set_next_block_after(b);                                \
                b = find_next_block();                                  \
                if (!b)                                                 \
                    printf("Unexpected EOF in archive");                \
                src = b->buffer;                                        \
                endp = b->buffer + BLOCKSIZE;                           \
            }                                                           \
            *dst = *src++;                                              \
        } while (*dst++ != '\n');                                       \
        dst[-1] = 0;                                                    \
    } while (0)

        start = current_block_ordinal();
        set_next_block_after(current_header);
        blk = find_next_block();
        if (!blk)
        {
            //FATAL_ERROR ((0, 0, _("Unexpected EOF in archive")));

            pedro_dprintf(2, "Unexpected EOF in archive");
            printf("Unexpected EOF in archive");
        }
        p = blk->buffer;
        COPY_BUF(blk, nbuf, p);
        if (!decode_num(&u, nbuf, TYPE_MAXIMUM(size_t)))
        {
            /*
             ERROR ((0, 0, _("%s: malformed sparse archive member"),
             file->stat_info->orig_file_name));*/

            pedro_dprintf(2, "%s: malformed sparse archive member", file->stat_info->orig_file_name);
            printf("%s: malformed sparse archive member", file->stat_info->orig_file_name);

            return false;
        }
        file->stat_info->sparse_map_size = u;
        file->stat_info->sparse_map = calloc(file->stat_info->sparse_map_size,
                                             sizeof(*file->stat_info->sparse_map));
        file->stat_info->sparse_map_avail = 0;
        for (i = 0; i < file->stat_info->sparse_map_size; i++)
        {
            struct sp_array sp;

            COPY_BUF(blk, nbuf, p);
            if (!decode_num(&u, nbuf, TYPE_MAXIMUM(off_t)))
            {
                /*
                 ERROR ((0, 0, _("%s: malformed sparse archive member"),
                 file->stat_info->orig_file_name));*/

                pedro_dprintf(2, "%s: malformed sparse archive member", file->stat_info->orig_file_name);
                printf("%s: malformed sparse archive member", file->stat_info->orig_file_name);

                return false;
            }
            sp.offset = u;
            COPY_BUF(blk, nbuf, p);
            if (!decode_num(&u, nbuf, TYPE_MAXIMUM(off_t)))
            {
                /*
                 ERROR ((0, 0, _("%s: malformed sparse archive member"),
                 file->stat_info->orig_file_name));
               */

                pedro_dprintf(2, "%s: malformed sparse archive member", file->stat_info->orig_file_name);
                printf("%s: malformed sparse archive member", file->stat_info->orig_file_name);

                return false;
            }
            sp.numbytes = u;
            sparse_add_map(file->stat_info, &sp);
        }
        set_next_block_after(blk);

        file->dumped_size += BLOCKSIZE * (current_block_ordinal() - start);
    }

    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
pax_dump_header(struct tar_sparse_file *file)
{
    file->stat_info->sparse_major = tar_sparse_major;
    file->stat_info->sparse_minor = tar_sparse_minor;

    return (file->stat_info->sparse_major == 0) ? pax_dump_header_0(file) : pax_dump_header_1(file);
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
pax_sparse_member_p(struct tar_sparse_file *file)
{
    return file->stat_info->sparse_map_avail > 0 || file->stat_info->sparse_major > 0;
}

/**
 * Tar related function, version 1.34
 *
 */
void *
x2nrealloc(void *p, size_t *pn, size_t s)
{
    size_t n = *pn;

    if (!p)
    {
        if (!n)
        {
            /* The approximate size to use for initial small allocation
             requests, when the invoking code specifies an old size of
             zero.  This is the largest "small" request for the GNU C
             library malloc.  */
            enum
            {
                DEFAULT_MXFAST = 64 * sizeof(size_t) / 4
            };

            n = DEFAULT_MXFAST / s;
            n += !n;
        }
        if (xalloc_oversized(n, s))
        {
            assert(0 && "nao pode acontecer");
        }
    }
    else
    {
        /* Set N = floor (1.5 * N) + 1 so that progress is made even if N == 0.
         Check for overflow, so that N * S stays in both ptrdiff_t and
         size_t range.  The check may be slightly conservative, but an
         exact check isn't worth the trouble.  */
        if ((PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : SIZE_MAX) / 3 * 2 / s <= n)
        {
            assert(0 && "nao pode acontecer");
        }
        n += n / 2 + 1;
    }

    *pn = n;
    return realloc(p, n * s);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_add_map(struct tar_stat_info *st, struct sp_array const *sp)
{
    struct sp_array *sparse_map = st->sparse_map;
    size_t avail = st->sparse_map_avail;

    if (avail == st->sparse_map_size)
        st->sparse_map = sparse_map =
            x2nrealloc(sparse_map, &st->sparse_map_size, sizeof *sparse_map);
    sparse_map[avail] = *sp;
    st->sparse_map_avail = avail + 1;
}

/* Add a sparse item to the sparse file and its obstack */

/**
 * Tar related function, version 1.34
 *
 */
static enum oldgnu_add_status
oldgnu_add_sparse(struct tar_sparse_file *file, struct sparse *s)
{
    struct sp_array sp;

    if (s->numbytes[0] == '\0')
        return add_finish;
    sp.offset = OFF_FROM_HEADER(s->offset);
    sp.numbytes = OFF_FROM_HEADER(s->numbytes);
    if (sp.offset < 0 || sp.numbytes < 0 || INT_ADD_OVERFLOW(sp.offset, sp.numbytes) || file->stat_info->stat.st_size < sp.offset + sp.numbytes || file->stat_info->archive_file_size < 0)
        return add_fail;

    sparse_add_map(file->stat_info, &sp);
    return add_ok;
}

/* Write to FD from the buffer BUF with COUNT bytes.  Do a full write.
   Wait until an output buffer is available; this matters because
   files are opened O_NONBLOCK for security reasons, and on some file
   systems this can cause write to fail with errno == EAGAIN.  Return
   the actual number of bytes written, setting errno if that is less
   than COUNT.  */

/**
 * Tar related function, version 1.34, with small modifications
 *
 */
size_t
blocking_write(int fd, void const *buf, size_t count)
{
    //assert(0 && "nao pode chamar esta funcao");

#if 1
    size_t bytes = write(fd, buf, count);

#if defined F_SETFL && O_NONBLOCK
#error nao pode chegar aqui
    if (bytes < count && errno == EAGAIN)
    {
        int flags = fcntl(fd, F_GETFL);
        if (0 <= flags && flags & O_NONBLOCK && fcntl(fd, F_SETFL, flags & ~O_NONBLOCK) != -1)
        {
            char const *buffer = buf;
            bytes += full_write(fd, buffer + bytes, count - bytes);
        }
    }
#endif

    return bytes;
#endif

    return 0;
}

/**
 * Tar related function, version 1.34
 *
 */
int sys_truncate(int fd)
{
    return write(fd, "", 0);
}

/**
 * Tar related function, version 1.34
 *
 */
void seek_error_details(char const *name, off_t offset)
{
#if 0
  char buf[UINTMAX_STRSIZE_BOUND];
  int e = errno;
  ERROR((0, e, _("%s: Cannot seek to %s"),
         quotearg_colon(name),
         STRINGIFY_BIGINT(offset, buf)));
#endif
    pedro_dprintf(2, "%s: Cannot seek to %lld", name, (__int64)offset);
    printf("%s: Cannot seek to %lld", name, (__int64)offset);
}

/**
 * Tar related function, version 1.34
 *
 */
void seek_warn_details(char const *name, off_t offset)
{
#if 0
  char buf[UINTMAX_STRSIZE_BOUND];
  int e = errno;
  WARN((0, e, _("%s: Warning: Cannot seek to %s"),
        quotearg_colon(name),
        STRINGIFY_BIGINT(offset, buf)));
#endif

    pedro_dprintf(2, "%s: Warning: Cannot seek to %lld", name, (__int64)offset);
    printf("%s: Warning: Cannot seek to %lld", name, (__int64)offset);
}

/**
 * Tar related function, version 1.34
 *
 */
void seek_diag_details(char const *name, off_t offset)
{
    if (ignore_failed_read_option)
    {
        if (WARNING_ENABLED(WARN_FAILED_READ))
            seek_warn_details(name, offset);
    }
    else
        seek_error_details(name, offset);
}

/* Dump zeros to file->fd until offset is reached. It is used instead of
   lseek if the output file is not seekable */

/**
 * Tar related function, version 1.34
 *
 */
static bool
dump_zeros(struct tar_sparse_file *file, off_t offset)
{
    static char const zero_buf[BLOCKSIZE];

    if (offset < file->offset)
    {
        errno = EINVAL;
        return false;
    }

    while (file->offset < offset)
    {
        size_t size = (BLOCKSIZE < offset - file->offset
                           ? BLOCKSIZE
                           : offset - file->offset);
        ssize_t wrbytes;

        wrbytes = write(file->fd, zero_buf, size);
        if (wrbytes <= 0)
        {
            if (wrbytes == 0)
                errno = EINVAL;
            return false;
        }
        file->offset += wrbytes;
    }

    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
lseek_or_error(struct tar_sparse_file *file, off_t offset)
{
    if (file->seekable
            ? lseek(file->fd, offset, SEEK_SET) < 0
            : !dump_zeros(file, offset))
    {
        seek_diag_details(file->stat_info->orig_file_name, offset);
        return false;
    }
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
sparse_extract_region(struct tar_sparse_file *file, size_t i)
{
    off_t write_size;

    if (!lseek_or_error(file, file->stat_info->sparse_map[i].offset))
        return false;

    write_size = file->stat_info->sparse_map[i].numbytes;

    if (write_size == 0)
    {
        /* Last block of the file is a hole */
        if (file->seekable && sys_truncate(file->fd))
        {
            //truncate_warn (file->stat_info->orig_file_name);

            pedro_dprintf(2, "Error truncating file %s\n", file->stat_info->orig_file_name);
            printf("Error truncating file %s\n", file->stat_info->orig_file_name);
        }
    }
    else
        while (write_size > 0)
        {
            size_t count;
            size_t wrbytes = (write_size > BLOCKSIZE) ? BLOCKSIZE : write_size;
            union block *blk = find_next_block();
            if (!blk)
            {
                //ERROR ((0, 0, _("Unexpected EOF in archive")));

                pedro_dprintf(2, "Unexpected EOF in archive");
                printf("Unexpected EOF in archive");

                return false;
            }
            set_next_block_after(blk);
            file->dumped_size += BLOCKSIZE;
            count = blocking_write(file->fd, blk->buffer, wrbytes);
            write_size -= count;
            mv_size_left(file->stat_info->archive_file_size - file->dumped_size);
            file->offset += count;
            if (count != wrbytes)
            {
                /*
               write_error_details (file->stat_info->orig_file_name,
                           count, wrbytes);
             */
                return false;
            }
        }
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
sparse_dump_region(struct tar_sparse_file *file, size_t i)
{
    union block *blk;
    off_t bytes_left = file->stat_info->sparse_map[i].numbytes;

    if (!lseek_or_error(file, file->stat_info->sparse_map[i].offset))
        return false;

    while (bytes_left > 0)
    {
        size_t bufsize = (bytes_left > BLOCKSIZE) ? BLOCKSIZE : bytes_left;
        size_t bytes_read;

        blk = find_next_block();
        bytes_read = read(file->fd, blk->buffer, bufsize);
        if (-1 == (int)bytes_read)
        {
            /*
             read_diag_details (file->stat_info->orig_file_name,
                       (file->stat_info->sparse_map[i].offset
           + file->stat_info->sparse_map[i].numbytes
                        - bytes_left),
                       bufsize);
           */
            return false;
        }
        else if (bytes_read == 0)
        {
#if 0
          char buf[UINTMAX_STRSIZE_BOUND];
          struct stat st;
          size_t n;
          if (fstat(file->fd, &st) == 0)
            n = file->stat_info->stat.st_size - st.st_size;
          else
            n = file->stat_info->stat.st_size
                - (file->stat_info->sparse_map[i].offset
                   + file->stat_info->sparse_map[i].numbytes
                   - bytes_left);

          WARNOPT(WARN_FILE_SHRANK,
                  (0, 0,
                   ngettext("%s: File shrank by %s byte; padding with zeros",
                            "%s: File shrank by %s bytes; padding with zeros",
                            n),
                   quotearg_colon(file->stat_info->orig_file_name),
                   STRINGIFY_BIGINT(n, buf)));
          if (!ignore_failed_read_option)
            set_exit_status(TAREXIT_DIFFERS);
#endif
            return false;
        }

        memset(blk->buffer + bytes_read, 0, BLOCKSIZE - bytes_read);
        bytes_left -= bytes_read;
        file->dumped_size += bytes_read;
        set_next_block_after(blk);
    }

    return true;
}

/* Convert old GNU format sparse data to internal representation */

/**
 * Tar related function, version 1.34
 *
 */
static bool
oldgnu_get_sparse_info(struct tar_sparse_file *file)
{
    size_t i;
    union block *h = current_header;
    int ext_p;
    enum oldgnu_add_status rc;

    file->stat_info->sparse_map_avail = 0;
    for (i = 0; i < SPARSES_IN_OLDGNU_HEADER; i++)
    {
        rc = oldgnu_add_sparse(file, &h->oldgnu_header.sp[i]);
        if (rc != add_ok)
            break;
    }

    for (ext_p = h->oldgnu_header.isextended;
         rc == add_ok && ext_p; ext_p = h->sparse_header.isextended)
    {
        h = find_next_block();
        if (!h)
        {
            //ERROR ((0, 0, _("Unexpected EOF in archive")));

            pedro_dprintf(2, "Unexpected EOF in archive");
            printf("Unexpected EOF in archive");

            return false;
        }
        set_next_block_after(h);
        for (i = 0; i < SPARSES_IN_SPARSE_HEADER && rc == add_ok; i++)
            rc = oldgnu_add_sparse(file, &h->sparse_header.sp[i]);
    }

    if (rc == add_fail)
    {
        /*
         ERROR ((0, 0, _("%s: invalid sparse archive member"),
              file->stat_info->orig_file_name));
       */
        pedro_dprintf(2, "%s: invalid sparse archive member", file->stat_info->orig_file_name);
        printf("%s: invalid sparse archive member", file->stat_info->orig_file_name);

        return false;
    }
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
oldgnu_fixup_header(struct tar_sparse_file *file)
{
    /* NOTE! st_size was initialized from the header
     which actually contains archived size. The following fixes it */
    off_t realsize = OFF_FROM_HEADER(current_header->oldgnu_header.realsize);

    file->stat_info->archive_file_size = file->stat_info->stat.st_size;
    file->stat_info->stat.st_size = max(0, realsize);
    return 0 <= realsize;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
oldgnu_dump_header(struct tar_sparse_file *file)
{
#if 1
    off_t block_ordinal = current_block_ordinal();
    union block *blk;
    size_t i;

    blk = start_header(file->stat_info);
    blk->header.typeflag = GNUTYPE_SPARSE;
    if (file->stat_info->sparse_map_avail > SPARSES_IN_OLDGNU_HEADER)
        blk->oldgnu_header.isextended = 1;

    /* Store the real file size */
    OFF_TO_CHARS(file->stat_info->stat.st_size, blk->oldgnu_header.realsize);
    /* Store the effective (shrunken) file size */
    OFF_TO_CHARS(file->stat_info->archive_file_size, blk->header.size);

    i = 0;
    oldgnu_store_sparse_info(file, &i,
                             blk->oldgnu_header.sp,
                             SPARSES_IN_OLDGNU_HEADER);
    blk->oldgnu_header.isextended = i < file->stat_info->sparse_map_avail;
    finish_header(file->stat_info, blk, block_ordinal);

    while (i < file->stat_info->sparse_map_avail)
    {
        blk = find_next_block();
        memset(blk->buffer, 0, BLOCKSIZE);
        oldgnu_store_sparse_info(file, &i,
                                 blk->sparse_header.sp,
                                 SPARSES_IN_SPARSE_HEADER);
        if (i < file->stat_info->sparse_map_avail)
            blk->sparse_header.isextended = 1;
        set_next_block_after(blk);
    }
#endif
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
oldgnu_sparse_member_p(struct tar_sparse_file *file __attribute__((unused)))
{
    return current_header->header.typeflag == GNUTYPE_SPARSE;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
sparse_select_optab(struct tar_sparse_file *file)
{
    switch (current_format == DEFAULT_FORMAT ? archive_format : current_format)
    {
    case V7_FORMAT:
    case USTAR_FORMAT:
        return false;

    case OLDGNU_FORMAT:
    case GNU_FORMAT: /*FIXME: This one should disappear? */
        file->optab = &oldgnu_optab;
        break;

    case POSIX_FORMAT:
        file->optab = &pax_optab;
        break;

    case STAR_FORMAT:
        file->optab = &star_optab;
        break;

    default:
        return false;
    }
    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
tar_sparse_init(struct tar_sparse_file *file)
{
    memset(file, 0, sizeof *file);

    if (!sparse_select_optab(file))
        return false;

    if (file->optab->init)
        return file->optab->init(file);

    return true;
}

/**
 * Tar related function, version 1.34
 *
 */
enum dump_status
sparse_skip_file(struct tar_stat_info *st)
{
    bool rc = true;
    struct tar_sparse_file file;

    if (!tar_sparse_init(&file))
        return dump_status_not_implemented;

    file.stat_info = st;
    file.fd = -1;

    rc = tar_sparse_decode_header(&file);
    skip_file(file.stat_info->archive_file_size - file.dumped_size);
    return (tar_sparse_done(&file) && rc) ? dump_status_ok : dump_status_short;
}
//finished at 15:03:29 2021/03/18 by amanda & MathMan
