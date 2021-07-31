
#include <shlwapi.h>

#define xcalloc calloc
#define xmalloc malloc

/* This declaration must be extern, because ISO C99 section 6.9.2
   prohibits a tentative definition that has both internal linkage and
   incomplete type.  If we made it static, we'd have to declare its
   size which would be a maintenance pain; if we put its initializer
   here, we'd need a boatload of forward declarations, which would be
   even more of a pain.  */
extern struct xhdr_tab const xhdr_tab[];

/**
 * Tar related function, version 1.34
 *
 */
void *
x2realloc(void *p, size_t *pn)
{
  return x2nrealloc(p, pn, 1);
}

/* Bound on length of the string representing an unsigned integer
   value representable in B bits.  log10 (2.0) < 146/485.  The
   smallest value of B where this bound is not tight is 2621.  */

enum { SYSINT_BUFSIZE =
         max(UINTMAX_STRSIZE_BOUND, INT_BUFSIZE_BOUND(intmax_t)) };
enum { BILLION = 1000000000, LOG10_BILLION = 9 };
enum { TIMESPEC_STRSIZE_BOUND =
         UINTMAX_STRSIZE_BOUND + LOG10_BILLION + sizeof "-." - 1 };

#ifndef HAVE_ICONV

# undef iconv_open
# define iconv_open(tocode, fromcode) ((iconv_t)-1)

# undef iconv
# define iconv(cd, inbuf, inbytesleft, outbuf, outbytesleft) (errno = ENOSYS, (size_t)-1)

# undef iconv_close
# define iconv_close(cd) 0

# undef iconv_t
# define iconv_t int

#endif

static iconv_t conv_desc[2] = { (iconv_t)-1, (iconv_t)-1 };

bool
strip_trailing_slashes_unix(char *file);

static bool
xheader_keyword_override_p(const char *keyword);

int
fnmatch(const char *pattern, const char * string, int flags);

bool
xheader_keyword_deleted_p(const char *kw);

static void
decx(void *data, char const *keyword, char const *value, size_t size);

static struct xhdr_tab const *
locate_handler(char const *keyword);

static void
run_override_list(struct keyword_list *kp, struct tar_stat_info *st);

void
xheader_decode(struct tar_stat_info *st);

void
_obstack_free(struct obstack *h, void *obj);

static void
call_freefun(struct obstack *h, void *old_chunk);

static void *
call_chunkfun(struct obstack *h, size_t size);

void
_obstack_newchunk(struct obstack *h, _OBSTACK_SIZE_T length);

void *
xrealloc(void *p, size_t n);

static void
xheader_xattr__add(struct xattr_array **xattr_map,
                   size_t *xattr_map_size,
                   const char *key, const char *val, size_t len);

char *
stpcpy(char *dest, const char *src);

void
xheader_xattr_add(struct tar_stat_info *st,
                  const char *key, const char *val, size_t len);

static void
xattr_decode_keyword(char *keyword);

static void
xattr_decoder(struct tar_stat_info *st,
              char const *keyword, char const *arg, size_t size);

static void
xattr_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data);

static void
xattr_acls_d_decoder(struct tar_stat_info *st,
                     char const *keyword, char const *arg, size_t size);

static void
xattr_acls_d_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, void const *data);

static void
xattr_acls_a_decoder(struct tar_stat_info *st,
                     char const *keyword, char const *arg, size_t size);

static void
xattr_acls_a_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, void const *data);

static void
xattr_selinux_decoder(struct tar_stat_info *st,
                      char const *keyword, char const *arg, size_t size);

static void
xattr_selinux_coder(struct tar_stat_info const *st, char const *keyword,
                    struct xheader *xhdr, void const *data);

static void
volume_offset_decoder(struct tar_stat_info *st,
                      char const *keyword,
                      char const *arg, size_t size);

static void
volume_offset_coder(struct tar_stat_info const *st, char const *keyword,
                    struct xheader *xhdr, void const *data);

static void
volume_size_decoder(struct tar_stat_info *st,
                    char const *keyword,
                    char const *arg, size_t size);

static void
volume_size_coder(struct tar_stat_info const *st, char const *keyword,
                  struct xheader *xhdr, void const *data);

static void
volume_filename_decoder(struct tar_stat_info *st,
                        char const *keyword __attribute__((unused)),
                        char const *arg,
                        size_t size __attribute__((unused)));

static void
volume_label_decoder(struct tar_stat_info *st,
                     char const *keyword __attribute__((unused)),
                     char const *arg,
                     size_t size __attribute__((unused)));

static void
volume_label_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, void const *data);

static void
dumpdir_decoder(struct tar_stat_info *st,
                char const *keyword __attribute__((unused)),
                char const *arg,
                size_t size);

size_t
dumpdir_size(const char *p);

static void
dumpdir_coder(struct tar_stat_info const *st, char const *keyword,
              struct xheader *xhdr, void const *data);

static void
sparse_map_decoder(struct tar_stat_info *st,
                   char const *keyword,
                   char const *arg,
                   size_t size __attribute__((unused)));

static void
sparse_numbytes_decoder(struct tar_stat_info *st,
                        char const *keyword,
                        char const *arg,
                        size_t size __attribute__((unused)));

static void
sparse_numbytes_coder(struct tar_stat_info const *st, char const *keyword,
                      struct xheader *xhdr, void const *data);

static void
sparse_offset_decoder(struct tar_stat_info *st,
                      char const *keyword,
                      char const *arg,
                      size_t size __attribute__((unused)));

static void
sparse_offset_coder(struct tar_stat_info const *st, char const *keyword,
                    struct xheader *xhdr, void const *data);

static void
sparse_numblocks_decoder(struct tar_stat_info *st,
                         char const *keyword,
                         char const *arg,
                         size_t size __attribute__((unused)));

static void
sparse_numblocks_coder(struct tar_stat_info const *st, char const *keyword,
                       struct xheader *xhdr,
                       void const *data __attribute__ ((unused)));

static void
sparse_size_decoder(struct tar_stat_info *st,
                    char const *keyword,
                    char const *arg,
                    size_t size __attribute__((unused)));

static void
sparse_size_coder(struct tar_stat_info const *st, char const *keyword,
                  struct xheader *xhdr, void const *data);

static void
sparse_minor_decoder(struct tar_stat_info *st,
                     char const *keyword,
                     char const *arg,
                     size_t size);

static void
sparse_minor_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, void const *data);

static void
sparse_major_decoder(struct tar_stat_info *st,
                     char const *keyword,
                     char const *arg,
                     size_t size);

static void
sparse_major_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, void const *data);

static void
sparse_path_decoder(struct tar_stat_info *st,
                    char const *keyword __attribute__((unused)),
                    char const *arg,
                    size_t size __attribute__((unused)));

static void
uname_decoder(struct tar_stat_info *st,
              char const *keyword __attribute__((unused)),
              char const *arg,
              size_t size __attribute__((unused)));

static void
uname_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data __attribute__ ((unused)));

static void
uid_decoder(struct tar_stat_info *st,
            char const *keyword,
            char const *arg,
            size_t size __attribute__((unused)));

static void
uid_coder(struct tar_stat_info const *st, char const *keyword,
          struct xheader *xhdr, void const *data __attribute__ ((unused)));

static bool
decode_num_v2_arp(uintmax_t *num, char const *arg, uintmax_t maxval,
                  char const *keyword);

static void
size_decoder(struct tar_stat_info *st,
             char const *keyword,
             char const *arg,
             size_t size __attribute__((unused)));

static void
code_num(uintmax_t value, char const *keyword, struct xheader *xhdr);

static void
size_coder(struct tar_stat_info const *st, char const *keyword,
           struct xheader *xhdr, void const *data __attribute__ ((unused)));

static void
raw_path_decoder(struct tar_stat_info *st, char const *arg);

static void
path_decoder(struct tar_stat_info *st,
             char const *keyword __attribute__((unused)),
             char const *arg,
             size_t size __attribute__((unused)));

static void
path_coder(struct tar_stat_info const *st, char const *keyword,
           struct xheader *xhdr, void const *data __attribute__ ((unused)));

static void
mtime_decoder(struct tar_stat_info *st,
              char const *keyword,
              char const *arg,
              size_t size __attribute__((unused)));

static void
mtime_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data);

static void
linkpath_decoder(struct tar_stat_info *st,
                 char const *keyword __attribute__((unused)),
                 char const *arg,
                 size_t size __attribute__((unused)));

static void
linkpath_coder(struct tar_stat_info const *st, char const *keyword,
               struct xheader *xhdr, void const *data __attribute__ ((unused)));

static void
decode_string(char **string, char const *arg);

static void
gname_decoder(struct tar_stat_info *st,
              char const *keyword __attribute__((unused)),
              char const *arg,
              size_t size __attribute__((unused)));

bool
utf8_convert(bool to_utf, char const *input, char **output);

static iconv_t
utf8_init(bool to_utf);

static void
code_string(char const *string, char const *keyword, struct xheader *xhdr);

static void
gname_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data __attribute__ ((unused)));
intmax_t
represent_uintmax(uintmax_t n);

intmax_t
strtosysint(char const *arg, char **arglim, intmax_t minval, uintmax_t maxval);

static bool
decode_signed_num(intmax_t *num, char const *arg,
                  intmax_t minval, uintmax_t maxval,
                  char const *keyword);

static void
gid_decoder(struct tar_stat_info *st,
            char const *keyword,
            char const *arg,
            size_t size __attribute__((unused)));

char *
sysinttostr(uintmax_t value, intmax_t minval, uintmax_t maxval,
            char buf[SYSINT_BUFSIZE]);

static void
code_signed_num(uintmax_t value, char const *keyword,
                intmax_t minval, uintmax_t maxval, struct xheader *xhdr);

static void
gid_coder(struct tar_stat_info const *st, char const *keyword,
          struct xheader *xhdr, void const *data __attribute__ ((unused)));

static void
ctime_decoder(struct tar_stat_info *st,
              char const *keyword,
              char const *arg,
              size_t size __attribute__((unused)));

static void
ctime_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data __attribute__ ((unused)));

static void
dummy_coder(struct tar_stat_info const *st __attribute__ ((unused)),
            char const *keyword __attribute__ ((unused)),
            struct xheader *xhdr __attribute__ ((unused)),
            void const *data __attribute__ ((unused)));

static void
dummy_decoder(struct tar_stat_info *st __attribute__ ((unused)),
              char const *keyword __attribute__ ((unused)),
              char const *arg __attribute__ ((unused)),
              size_t size __attribute__((unused)));

char *
imaxtostr(intmax_t i, char *buf);

static void
out_of_range_header(char const *keyword, char const *value,
                    intmax_t minval, uintmax_t maxval);

bool
valid_timespec(struct timespec t);

static bool
decode_time(struct timespec *ts, char const *arg, char const *keyword);

static void
atime_decoder(struct tar_stat_info *st,
              char const *keyword,
              char const *arg,
              size_t size __attribute__((unused)));

static intmax_t
strtoimax(char const *ptr, char **endptr, int base);

void
code_ns_fraction(int ns, char *p);

struct timespec
decode_timespec(char const *arg, char **arg_lim, bool parse_fraction);

static void
x_obstack_1grow(struct xheader *xhdr, char c);

static void
x_obstack_grow(struct xheader *xhdr, const char *ptr, size_t length);

char *
umaxtostr(uintmax_t i, char *buf);

static char *
xattr_encode_keyword(const char *keyword);

static void
xheader_print_n(struct xheader *xhdr, char const *keyword,
                char const *value, size_t vsize);

static void
xheader_print(struct xheader *xhdr, char const *keyword, char const *value);

static void
atime_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data __attribute__ ((unused)));
static void

code_time(struct timespec t, char const *keyword, struct xheader *xhdr);

static bool
decode_record(struct xheader *xhdr,
              char **ptr,
              void (*handler)(void *, char const *, char const *, size_t),
              void *data);

////////////////////////////////////////////////////////////////////////////////////////////////////////////arp////
//functions

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Tar related function, version 1.34
 *
 */
static bool
xheader_keyword_override_p(const char *keyword)
{
  struct keyword_list *kp;

  for (kp = keyword_override_list; kp; kp = kp->next)
    if (strcmp(kp->pattern, keyword) == 0)
      return true;
  return false;
}

#include "fnmatch_arp.c"

/**
 * Tar related function, version 1.34
 *
 */
bool
xheader_keyword_deleted_p(const char *kw)
{
  struct keyword_list *kp;

  for (kp = keyword_pattern_list; kp; kp = kp->next)
    if (fnmatch(kp->pattern, kw, 0) == 0)
      return true;
  return false;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
decx(void *data, char const *keyword, char const *value, size_t size)
{
  struct xhdr_tab const *t;
  struct tar_stat_info *st = data;

  if (xheader_keyword_deleted_p(keyword)
      || xheader_keyword_override_p(keyword))
    return;

  t = locate_handler(keyword);
  if (t)
    t->decoder(st, keyword, value, size);
  else
    {
#if 0
      WARNOPT(WARN_UNKNOWN_KEYWORD,
              (0, 0, _("Ignoring unknown extended header keyword '%s'"),
               keyword));
#endif
      pedro_dprintf(2, "Ignoring unknown extended header keyword '%s'", keyword);
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static struct xhdr_tab const *
locate_handler(char const *keyword)
{
  struct xhdr_tab const *p;

  for (p = xhdr_tab; p->keyword; p++)
    if (p->prefix)
      {
        if (strncmp(p->keyword, keyword, strlen(p->keyword)) == 0)
          return p;
      }
    else
      {
        if (strcmp(p->keyword, keyword) == 0)
          return p;
      }

  return NULL;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
run_override_list(struct keyword_list *kp, struct tar_stat_info *st)
{
  for (; kp; kp = kp->next)
    {
      struct xhdr_tab const *t = locate_handler(kp->pattern);
      if (t)
        t->decoder(st, t->keyword, kp->value, strlen(kp->value));
    }
}

/**
 * Tar related function, version 1.34
 *
 */
void
xheader_decode(struct tar_stat_info *st)
{
  run_override_list(keyword_global_override_list, st);
  run_override_list(global_header_override_list, st);

  if (st->xhdr.size)
    {
      char *p = st->xhdr.buffer + BLOCKSIZE;
      while (decode_record(&st->xhdr, &p, decx, st))
        continue;
    }
  run_override_list(keyword_override_list, st);

  /* The archived (effective) file size is always set directly in tar header
     field, possibly overridden by "size" extended header - in both cases,
     result is now decoded in st->stat.st_size */
  st->archive_file_size = st->stat.st_size;

  /* The real file size (given by stat()) may be redefined for sparse
     files in "GNU.sparse.realsize" extended header */
  if (st->real_size_set)
    st->stat.st_size = st->real_size;
}

/* Free objects in obstack H, including OBJ and everything allocate
   more recently than OBJ.  If OBJ is zero, free everything in H.  */

/**
 * Tar related function, version 1.34
 *
 */
void
_obstack_free(struct obstack *h, void *obj)
{
  struct _obstack_chunk *lp;    /* below addr of any objects in this chunk */
  struct _obstack_chunk *plp;   /* point to previous chunk if any */

  lp = h->chunk;
  /* We use >= because there cannot be an object at the beginning of a chunk.
     But there can be an empty object at that address
     at the end of another chunk.  */
  while (lp != 0 && ((void *)lp >= obj || (void *)(lp)->limit < obj))
    {
      plp = lp->prev;
      call_freefun(h, lp);
      lp = plp;
      /* If we switch chunks, we can't tell whether the new current
         chunk contains an empty object, so assume that it may.  */
      h->maybe_empty_object = 1;
    }
  if (lp)
    {
      h->object_base = h->next_free = (char *)(obj);
      h->chunk_limit = lp->limit;
      h->chunk = lp;
    }
  else if (obj != 0)
    /* obj is not in any of the chunks! */
    abort();
}

/**
 * Tar related function, version 1.34
 *
 */
static void
call_freefun(struct obstack *h, void *old_chunk)
{
  if (h->use_extra_arg)
    h->freefun.extra(h->extra_arg, old_chunk);
  else
    h->freefun.plain(old_chunk);
}

/* Call functions with either the traditional malloc/free calling
   interface, or the mmalloc/mfree interface (that adds an extra first
   argument), based on the value of use_extra_arg.  */

/**
 * Tar related function, version 1.34
 *
 */
void
_obstack_newchunk(struct obstack *h, _OBSTACK_SIZE_T length)
{
  struct _obstack_chunk *old_chunk = h->chunk;
  struct _obstack_chunk *new_chunk = 0;
  size_t obj_size = h->next_free - h->object_base;
  char *object_base;

  /* Compute size for new chunk.  */
  size_t sum1 = obj_size + length;
  size_t sum2 = sum1 + h->alignment_mask;
  size_t new_size = sum2 + (obj_size >> 3) + 100;

  if (new_size < sum2)
    new_size = sum2;
  if (new_size < h->chunk_size)
    new_size = h->chunk_size;

  /* Allocate and initialize the new chunk.  */
  if (obj_size <= sum1 && sum1 <= sum2)
    new_chunk = call_chunkfun(h, new_size);
  if (!new_chunk)
    {
      assert(0 && "Memory exausted");
      pedro_dprintf(2, "Memory exausted");
    }
  h->chunk = new_chunk;
  new_chunk->prev = old_chunk;
  new_chunk->limit = h->chunk_limit = (char *)new_chunk + new_size;

  /* Compute an aligned object_base in the new chunk */
  object_base =
    __PTR_ALIGN((char *)new_chunk, new_chunk->contents, h->alignment_mask);

  /* Move the existing object to the new chunk.  */
  memcpy(object_base, h->object_base, obj_size);

  /* If the object just copied was the only data in OLD_CHUNK,
     free that chunk and remove it from the chain.
     But not if that chunk might contain an empty object.  */
  if (!h->maybe_empty_object
      && (h->object_base
          == __PTR_ALIGN((char *)old_chunk, old_chunk->contents,
                         h->alignment_mask)))
    {
      new_chunk->prev = old_chunk->prev;
      call_freefun(h, old_chunk);
    }

  h->object_base = object_base;
  h->next_free = h->object_base + obj_size;
  /* The new chunk certainly contains no empty object yet.  */
  h->maybe_empty_object = 0;
}

/**
 * Tar related function, version 1.34
 *
 */
void *
xrealloc(void *p, size_t n)
{
  if (!n && p)
    {
      /* The GNU and C99 realloc behaviors disagree here.  Act like
         GNU, even if the underlying realloc is C99.  */
      free(p);
      return NULL;
    }

  p = realloc(p, n);
  if (!p && n)
    {
      assert(0 && "will never occur...");
    }
  return p;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xheader_xattr__add(struct xattr_array **xattr_map,
                   size_t *xattr_map_size,
                   const char *key, const char *val, size_t len)
{
  size_t pos = (*xattr_map_size)++;

  *xattr_map = xrealloc(*xattr_map,
                        *xattr_map_size * sizeof(struct xattr_array));
  (*xattr_map)[pos].xkey = xstrdup(key);
  (*xattr_map)[pos].xval_ptr = xmemdup(val, len + 1);
  (*xattr_map)[pos].xval_len = len;
}

/**
 * Tar related function, version 1.34
 *
 */
char *
stpcpy(char *dest, const char *src)
{
  register char *d = dest;
  register const char *s = src;

  do
    *d++ = *s;
  while (*s++ != '\0');

  return d - 1;
}

/**
 * Tar related function, version 1.34
 *
 */
void
xheader_xattr_add(struct tar_stat_info *st,
                  const char *key, const char *val, size_t len)
{
  size_t klen = strlen(key);
  char *xkey = xmalloc(strlen("SCHILY.xattr.") + klen + 1);
  char *tmp = xkey;

  tmp = stpcpy(tmp, "SCHILY.xattr.");
  stpcpy(tmp, key);

  xheader_xattr__add(&st->xattr_map, &st->xattr_map_size, xkey, val, len);

  free(xkey);
}

/* This is reversal function for xattr_encode_keyword.  See comment for
   xattr_encode_keyword() for more info. */

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_decode_keyword(char *keyword)
{
  char *kpr, *kpl; /* keyword pointer left/right */

  kpr = kpl = keyword;

  for (;;)
    {
      if (*kpr == '%')
        {
          if (kpr[1] == '3' && kpr[2] == 'D')
            {
              *kpl = '=';
              kpr += 3;
              kpl++;
              continue;
            }
          else if (kpr[1] == '2' && kpr[2] == '5')
            {
              *kpl = '%';
              kpr += 3;
              kpl++;
              continue;
            }
        }

      *kpl = *kpr;

      if (*kpr == 0)
        break;

      kpr++;
      kpl++;
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_decoder(struct tar_stat_info *st,
              char const *keyword, char const *arg, size_t size)
{
  char *xstr, *xkey;

  /* copy keyword */
  size_t klen_raw = strlen(keyword);

  xkey = alloca(klen_raw + 1);
  memcpy(xkey, keyword, klen_raw + 1) /* including null-terminating */;

  /* copy value */
  xstr = alloca(size + 1);
  memcpy(xstr, arg, size + 1); /* separator included, for GNU tar '\n' */;

  xattr_decode_keyword(xkey);

  xheader_xattr_add(st, xkey + strlen("SCHILY.xattr."), xstr, size);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data)
{
  struct xattr_array *xattr_map = st->xattr_map;
  const size_t *off = data;

  xheader_print_n(xhdr, keyword,
                  xattr_map[*off].xval_ptr, xattr_map[*off].xval_len);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_acls_d_decoder(struct tar_stat_info *st,
                     __attribute__((unused)) char const *keyword, char const *arg, size_t size)
{
  st->acls_d_ptr = xmemdup(arg, size + 1);
  st->acls_d_len = size;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_acls_d_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, __attribute__((unused)) void const *data)
{
  xheader_print_n(xhdr, keyword, st->acls_d_ptr, st->acls_d_len);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_acls_a_decoder(struct tar_stat_info *st,
                     __attribute__((unused)) char const *keyword, char const *arg, size_t size)
{
  st->acls_a_ptr = xmemdup(arg, size + 1);
  st->acls_a_len = size;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_acls_a_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, __attribute__((unused)) void const *data)
{
  xheader_print_n(xhdr, keyword, st->acls_a_ptr, st->acls_a_len);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_selinux_decoder(struct tar_stat_info *st,
                      __attribute__((unused)) char const *keyword, char const *arg, __attribute__((unused)) size_t size)
{
  decode_string(&st->cntx_name, arg);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xattr_selinux_coder(struct tar_stat_info const *st, char const *keyword,
                    struct xheader *xhdr, __attribute__((unused)) void const *data)
{
  code_string(st->cntx_name, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
volume_offset_decoder(__attribute__((unused)) struct tar_stat_info *st,
                      char const *keyword,
                      char const *arg, __attribute__((unused)) size_t size)
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, TYPE_MAXIMUM(uintmax_t), keyword))
    continued_file_offset = u;
}

/* FIXME: Merge with volume_size_coder */

/**
 * Tar related function, version 1.34
 *
 */
static void
volume_offset_coder(__attribute__((unused)) struct tar_stat_info const *st, char const *keyword,
                    struct xheader *xhdr, void const *data)
{
  off_t const *v = data;

  code_num(*v, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
volume_size_decoder(__attribute__((unused)) struct tar_stat_info *st,
                    char const *keyword,
                    char const *arg, __attribute__((unused)) size_t size)
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, TYPE_MAXIMUM(uintmax_t), keyword))
    continued_file_size = u;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
volume_size_coder(__attribute__((unused)) struct tar_stat_info const *st, char const *keyword,
                  struct xheader *xhdr, void const *data)
{
  off_t const *v = data;

  code_num(*v, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
volume_filename_decoder(__attribute__((unused)) struct tar_stat_info *st,
                        char const *keyword __attribute__((unused)),
                        char const *arg,
                        size_t size __attribute__((unused)))
{
  decode_string(&continued_file_name, arg);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
volume_label_decoder(__attribute__((unused)) struct tar_stat_info *st,
                     char const *keyword __attribute__((unused)),
                     char const *arg,
                     size_t size __attribute__((unused)))
{
  decode_string(&volume_label, arg);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
volume_label_coder(__attribute__((unused)) struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, void const *data)
{
  code_string(data, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
dumpdir_decoder(struct tar_stat_info *st,
                char const *keyword __attribute__((unused)),
                char const *arg,
                size_t size)
{
  st->dumpdir = xmalloc(size);
  memcpy(st->dumpdir, arg, size);
}

/* Return size in bytes of the dumpdir array P */

/**
 * Tar related function, version 1.34
 *
 */
size_t
dumpdir_size(const char *p)
{
  size_t totsize = 0;

  while (*p)
    {
      size_t size = strlen(p) + 1;
      totsize += size;
      p += size;
    }
  return totsize + 1;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
dumpdir_coder(__attribute__((unused)) struct tar_stat_info const *st, char const *keyword,
              struct xheader *xhdr, void const *data)
{
  xheader_print_n(xhdr, keyword, data, dumpdir_size(data));
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_map_decoder(struct tar_stat_info *st,
                   char const *keyword,
                   char const *arg,
                   size_t size __attribute__((unused)))
{
  int offset = 1;
  struct sp_array e;

  st->sparse_map_avail = 0;
  while (1)
    {
      intmax_t u;
      char *delim;

      if (!ISDIGIT(*arg))
        {
#if 0
          ERROR((0, 0, _("Malformed extended header: invalid %s=%s"),
                 keyword, arg));
#endif
          pedro_dprintf(2, "Malformed extended header: invalid %s=%s",
                        keyword, arg);
          return;
        }

      errno = 0;
      u = strtoimax(arg, &delim, 10);
      if (TYPE_MAXIMUM(off_t) < u)
        {
          u = TYPE_MAXIMUM(off_t);
          errno = ERANGE;
        }
      if (offset)
        {
          e.offset = u;
          if (errno == ERANGE)
            {
              out_of_range_header(keyword, arg, 0, TYPE_MAXIMUM(off_t));
              return;
            }
        }
      else
        {
          e.numbytes = u;
          if (errno == ERANGE)
            {
              out_of_range_header(keyword, arg, 0, TYPE_MAXIMUM(off_t));
              return;
            }
          if (st->sparse_map_avail < st->sparse_map_size)
            st->sparse_map[st->sparse_map_avail++] = e;
          else
            {
#if 0
              ERROR((0, 0, _("Malformed extended header: excess %s=%s"),
                     keyword, arg));
#endif
              pedro_dprintf(2, "Malformed extended header: excess %s=%s",
                            keyword, arg);
              return;
            }
        }

      offset = !offset;

      if (*delim == 0)
        break;
      else if (*delim != ',')
        {
#if 0
          ERROR((0, 0,
                 _("Malformed extended header: invalid %s: unexpected delimiter %c"),
                 keyword, *delim));
#endif
          pedro_dprintf(2, "Malformed extended header: invalid %s: unexpected delimiter %c",
                        keyword, *delim);
          return;
        }

      arg = delim + 1;
    }

  if (!offset)
    {
#if 0
      ERROR((0, 0,
             _("Malformed extended header: invalid %s: odd number of values"),
             keyword));
#endif
      pedro_dprintf(2, "Malformed extended header: invalid %s: odd number of values",
                    keyword);
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_numbytes_decoder(struct tar_stat_info *st,
                        char const *keyword,
                        char const *arg,
                        size_t size __attribute__((unused)))
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, TYPE_MAXIMUM(off_t), keyword))
    {
      if (st->sparse_map_avail < st->sparse_map_size)
        st->sparse_map[st->sparse_map_avail++].numbytes = u;
      else
        {
#if 0
          ERROR((0, 0, _("Malformed extended header: excess %s=%s"),
                 keyword, arg));
#endif
          pedro_dprintf(2, "Malformed extended header: excess %s=%s",
                        keyword, arg);
        }
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_numbytes_coder(struct tar_stat_info const *st, char const *keyword,
                      struct xheader *xhdr, void const *data)
{
  size_t const *pi = data;

  code_num(st->sparse_map[*pi].numbytes, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_offset_decoder(struct tar_stat_info *st,
                      char const *keyword,
                      char const *arg,
                      size_t size __attribute__((unused)))
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, TYPE_MAXIMUM(off_t), keyword))
    {
      if (st->sparse_map_avail < st->sparse_map_size)
        st->sparse_map[st->sparse_map_avail].offset = u;
      else
        {
#if 0
          ERROR((0, 0, _("Malformed extended header: excess %s=%s"),
                 "GNU.sparse.offset", arg));
#endif

          pedro_dprintf(2, "Malformed extended header: excess %s=%s",
                        "GNU.sparse.offset", arg);
        }
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_offset_coder(struct tar_stat_info const *st, char const *keyword,
                    struct xheader *xhdr, void const *data)
{
  size_t const *pi = data;

  code_num(st->sparse_map[*pi].offset, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_numblocks_decoder(struct tar_stat_info *st,
                         char const *keyword,
                         char const *arg,
                         size_t size __attribute__((unused)))
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, SIZE_MAX, keyword))
    {
      st->sparse_map_size = u;
      st->sparse_map = xcalloc(u, sizeof st->sparse_map[0]);
      st->sparse_map_avail = 0;
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_numblocks_coder(struct tar_stat_info const *st, char const *keyword,
                       struct xheader *xhdr,
                       void const *data __attribute__ ((unused)))
{
  code_num(st->sparse_map_avail, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_size_decoder(struct tar_stat_info *st,
                    char const *keyword,
                    char const *arg,
                    size_t size __attribute__((unused)))
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, TYPE_MAXIMUM(off_t), keyword))
    {
      st->real_size_set = true;
      st->real_size = u;
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_size_coder(struct tar_stat_info const *st, char const *keyword,
                  struct xheader *xhdr, void const *data)
{
  size_coder(st, keyword, xhdr, data);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_minor_decoder(struct tar_stat_info *st,
                     char const *keyword,
                     char const *arg,
                     __attribute__((unused)) size_t size)
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, TYPE_MAXIMUM(unsigned), keyword))
    st->sparse_minor = u;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_minor_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, __attribute__((unused)) void const *data)
{
  code_num(st->sparse_minor, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_major_decoder(struct tar_stat_info *st,
                     char const *keyword,
                     char const *arg,
                     __attribute__((unused)) size_t size)
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, TYPE_MAXIMUM(unsigned), keyword))
    st->sparse_major = u;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_major_coder(struct tar_stat_info const *st, char const *keyword,
                   struct xheader *xhdr, __attribute__((unused)) void const *data)
{
  code_num(st->sparse_major, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
sparse_path_decoder(struct tar_stat_info *st,
                    char const *keyword __attribute__((unused)),
                    char const *arg,
                    size_t size __attribute__((unused)))
{
  st->sparse_name_done = true;
  raw_path_decoder(st, arg);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
uname_decoder(struct tar_stat_info *st,
              char const *keyword __attribute__((unused)),
              char const *arg,
              size_t size __attribute__((unused)))
{
  decode_string(&st->uname, arg);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
uname_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_string(st->uname, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
uid_decoder(struct tar_stat_info *st,
            char const *keyword,
            char const *arg,
            size_t size __attribute__((unused)))
{
  intmax_t u;

  if (decode_signed_num(&u, arg, TYPE_MINIMUM(uid_t),
                        TYPE_MAXIMUM(uid_t), keyword))
    st->stat.st_uid = u;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
uid_coder(struct tar_stat_info const *st, char const *keyword,
          struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_signed_num(st->stat.st_uid, keyword,
                  TYPE_MINIMUM(uid_t), TYPE_MAXIMUM(uid_t), xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
decode_num_v2_arp(uintmax_t *num, char const *arg, uintmax_t maxval,
                  char const *keyword)
{
  intmax_t i;

  if (!decode_signed_num(&i, arg, 0, maxval, keyword))
    return false;
  *num = i;
  return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
size_decoder(struct tar_stat_info *st,
             char const *keyword,
             char const *arg,
             size_t size __attribute__((unused)))
{
  uintmax_t u;

  if (decode_num_v2_arp(&u, arg, TYPE_MAXIMUM(off_t), keyword))
    st->stat.st_size = u;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
code_num(uintmax_t value, char const *keyword, struct xheader *xhdr)
{
  code_signed_num(value, keyword, 0, UINTMAX_MAX, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
size_coder(struct tar_stat_info const *st, char const *keyword,
           struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_num(st->stat.st_size, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
raw_path_decoder(struct tar_stat_info *st, char const *arg)
{
  decode_string(&st->orig_file_name, arg);
  decode_string(&st->file_name, arg);
  st->had_trailing_slash = strip_trailing_slashes_unix(st->file_name);
  //pedro_dprintf(-1, "aqui  st->had_trailing_slash %s %d\n", st->file_name, st->had_trailing_slash);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
path_decoder(struct tar_stat_info *st,
             char const *keyword __attribute__((unused)),
             char const *arg,
             size_t size __attribute__((unused)))
{
  if (!st->sparse_name_done)
    raw_path_decoder(st, arg);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
path_coder(struct tar_stat_info const *st, char const *keyword,
           struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_string(st->file_name, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
mtime_decoder(struct tar_stat_info *st,
              char const *keyword,
              char const *arg,
              size_t size __attribute__((unused)))
{
  struct timespec ts;

  if (decode_time(&ts, arg, keyword))
    st->mtime = ts;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
mtime_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data)
{
  struct timespec const *mtime = data;

  code_time(mtime ? *mtime : st->mtime, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
linkpath_decoder(struct tar_stat_info *st,
                 char const *keyword __attribute__((unused)),
                 char const *arg,
                 size_t size __attribute__((unused)))
{
  decode_string(&st->link_name, arg);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
linkpath_coder(struct tar_stat_info const *st, char const *keyword,
               struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_string(st->link_name, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
decode_string(char **string, char const *arg)
{
  if (*string)
    {
      free(*string);
      *string = NULL;
    }
  if (!utf8_convert(false, arg, string))
    {
      /* FIXME: report error and act accordingly to --pax invalid=UTF-8 */
      assign_string(string, arg);
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
gname_decoder(struct tar_stat_info *st,
              char const *keyword __attribute__((unused)),
              char const *arg,
              size_t size __attribute__((unused)))
{
  decode_string(&st->gname, arg);
}

/**
 * Tar related function, version 1.34
 *
 */
bool
utf8_convert(bool to_utf, char const *input, char **output)
{
  char *ob, *ret;
  size_t inlen;
  size_t outlen;
  iconv_t cd = utf8_init(to_utf);

  if (cd == 0)
    {
      *output = xstrdup(input);
      return true;
    }
  else if (cd == (iconv_t)-1)
    return false;

  inlen = strlen(input) + 1;
  outlen = inlen * MB_LEN_MAX + 1;
  ob = ret = malloc(outlen);
  //ib = (char *) input;
  /* According to POSIX, "if iconv() encounters a character in the input
     buffer that is valid, but for which an identical character does not
     exist in the target codeset, iconv() shall perform an
     implementation-defined conversion on this character." It will "update
     the variables pointed to by the arguments to reflect the extent of the
     conversion and return the number of non-identical conversions performed".
     On error, it returns -1.
     In other words, non-zero return always indicates failure, either because
     the input was not fully converted, or because it was converted in a
     non-reversible way.
   */
  if (iconv(cd, &ib, &inlen, &ob, &outlen) != 0)
    {
      free(ret);
      return false;
    }
  *ob = 0;
  *output = ret;
  return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static iconv_t
utf8_init(bool to_utf)
{
  if (conv_desc[(int)to_utf] == (iconv_t)-1)
    {
      if (to_utf)
        conv_desc[(int)to_utf] = iconv_open("UTF-8", locale_charset());
      else
        conv_desc[(int)to_utf] = iconv_open(locale_charset(), "UTF-8");
    }
  return conv_desc[(int)to_utf];
}

/**
 * Tar related function, version 1.34
 *
 */
static void
code_string(char const *string, char const *keyword, struct xheader *xhdr)
{
  char *outstr;

  if (!utf8_convert(true, string, &outstr))
    {
      /* FIXME: report error */
      outstr = xstrdup(string);
    }
  xheader_print(xhdr, keyword, outstr);
  free(outstr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
gname_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_string(st->gname, keyword, xhdr);
}

/* Represent N using a signed integer I such that (uintmax_t) I == N.
   With a good optimizing compiler, this is equivalent to (intmax_t) i
   and requires zero machine instructions.  */

#if !(UINTMAX_MAX / 2 <= INTMAX_MAX)
# error "represent_uintmax returns intmax_t to represent uintmax_t"
#endif

/**
 * Tar related function, version 1.34
 *
 */
intmax_t
represent_uintmax(uintmax_t n)
{
  if (n <= INTMAX_MAX)
    return n;
  else
    {
      /* Avoid signed integer overflow on picky platforms.  */
      intmax_t nd = n - INTMAX_MIN;
      return nd + INTMAX_MIN;
    }
}

/* Convert a prefix of the string ARG to a system integer type whose
   minimum value is MINVAL and maximum MAXVAL.  If MINVAL is negative,
   negative integers MINVAL .. -1 are assumed to be represented using
   leading '-' in the usual way.  If the represented value exceeds
   INTMAX_MAX, return a negative integer V such that (uintmax_t) V
   yields the represented value.  If ARGLIM is nonnull, store into
 * ARGLIM a pointer to the first character after the prefix.

   This is the inverse of sysinttostr.

   On a normal return, set errno = 0.
   On conversion error, return 0 and set errno = EINVAL.
   On overflow, return an extreme value and set errno = ERANGE.  */
#if !(INTMAX_MAX <= UINTMAX_MAX)
# error "strtosysint: nonnegative intmax_t does not fit in uintmax_t"
#endif

/**
 * Tar related function, version 1.34
 *
 */
intmax_t
strtosysint(char const *arg, char **arglim, intmax_t minval, uintmax_t maxval)
{
  errno = 0;
  if (maxval <= INTMAX_MAX)
    {
      if (ISDIGIT(arg[*arg == '-']))
        {
          intmax_t i = strtoimax(arg, arglim, 10);
          intmax_t imaxval = maxval;
          if (minval <= i && i <= imaxval)
            return i;
          errno = ERANGE;
          return i < minval ? (intmax_t) minval : (intmax_t) maxval;
        }
    }
  else
    {
      if (ISDIGIT(*arg))
        {
          uintmax_t i = strtoumax(arg, arglim, 10);
          if (i <= maxval)
            return represent_uintmax(i);
          errno = ERANGE;
          return maxval;
        }
    }

  errno = EINVAL;
  return 0;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
decode_signed_num(intmax_t *num, char const *arg,
                  intmax_t minval, uintmax_t maxval,
                  char const *keyword)
{
  char *arg_lim;
  intmax_t u = strtosysint(arg, &arg_lim, minval, maxval);

  if (errno == EINVAL || *arg_lim)
    {
#if 0
      ERROR((0, 0, _("Malformed extended header: invalid %s=%s"),
             keyword, arg));
#endif
      pedro_dprintf(2, "Malformed extended header: invalid %s=%s",
                    keyword, arg);
      return false;
    }

  if (errno == ERANGE)
    {
      out_of_range_header(keyword, arg, minval, maxval);
      return false;
    }

  *num = u;
  return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
gid_decoder(struct tar_stat_info *st,
            char const *keyword,
            char const *arg,
            size_t size __attribute__((unused)))
{
  intmax_t u;

  if (decode_signed_num(&u, arg, TYPE_MINIMUM(gid_t),
                        TYPE_MAXIMUM(gid_t), keyword))
    st->stat.st_gid = u;
}

/* Convert VALUE, which is converted from a system integer type whose
   minimum value is MINVAL and maximum MINVAL, to an decimal
   integer string.  Use the storage in BUF and return a pointer to the
   converted string.  If VALUE is converted from a negative integer in
   the range MINVAL .. -1, represent it with a string representation
   of the negative integer, using leading '-'.  */
#if !(INTMAX_MAX <= UINTMAX_MAX / 2)
# error "sysinttostr: uintmax_t cannot represent all intmax_t values"
#endif

/**
 * Tar related function, version 1.34
 *
 */
char *
sysinttostr(uintmax_t value, intmax_t minval, uintmax_t maxval,
            char buf[SYSINT_BUFSIZE])
{
  if (value <= maxval)
    return umaxtostr(value, buf);
  else
    {
      intmax_t i = value - minval;
      return imaxtostr(i + minval, buf);
    }
}

/**
 * Tar related function, version 1.34
 *
 */
static void
code_signed_num(uintmax_t value, char const *keyword,
                intmax_t minval, uintmax_t maxval, struct xheader *xhdr)
{
  char sbuf[SYSINT_BUFSIZE];

  xheader_print(xhdr, keyword, sysinttostr(value, minval, maxval, sbuf));
}

/**
 * Tar related function, version 1.34
 *
 */
static void
gid_coder(struct tar_stat_info const *st, char const *keyword,
          struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_signed_num(st->stat.st_gid, keyword,
                  TYPE_MINIMUM(gid_t), TYPE_MAXIMUM(gid_t), xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
ctime_decoder(struct tar_stat_info *st,
              char const *keyword,
              char const *arg,
              size_t size __attribute__((unused)))
{
  struct timespec ts;

  if (decode_time(&ts, arg, keyword))
    st->ctime = ts;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
ctime_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_time(st->ctime, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
dummy_coder(struct tar_stat_info const *st __attribute__ ((unused)),
            char const *keyword __attribute__ ((unused)),
            struct xheader *xhdr __attribute__ ((unused)),
            void const *data __attribute__ ((unused)))
{
}

/**
 * Tar related function, version 1.34
 *
 */
static void
dummy_decoder(struct tar_stat_info *st __attribute__ ((unused)),
              char const *keyword __attribute__ ((unused)),
              char const *arg __attribute__ ((unused)),
              size_t size __attribute__((unused)))
{
}

/**
 * Tar related function, version 1.34
 *
 */
char *
imaxtostr(intmax_t i, char *buf)
{
  char *p = buf + INT_STRLEN_BOUND(intmax_t);

  *p = 0;

  if (i < 0)
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
}
/* Implementations */

/**
 * Tar related function, version 1.34
 *
 */
static void
out_of_range_header(char const *keyword, char const *value,
                    intmax_t minval, uintmax_t maxval)
{
  char minval_buf[INT_BUFSIZE_BOUND(intmax_t)];
  char maxval_buf[UINTMAX_STRSIZE_BOUND];
  char *minval_string = imaxtostr(minval, minval_buf);
  char *maxval_string = umaxtostr(maxval, maxval_buf);

  /* TRANSLATORS: The first %s is the pax extended header keyword
     (atime, gid, etc.).  */

#if 0
  ERROR((0, 0, _("Extended header %s=%s is out of range %s..%s"),
         keyword, value, minval_string, maxval_string));
#endif

  pedro_dprintf(2, "Extended header %s=%s is out of range %s..%s",
                keyword, value, minval_string, maxval_string);
}

/**
 * Tar related function, version 1.34
 *
 */
bool
valid_timespec(struct timespec t)
{
  return 0 <= t.tv_nsec;
}

/**
 * Tar related function, version 1.34
 *
 */
static bool
decode_time(struct timespec *ts, char const *arg, char const *keyword)
{
  char *arg_lim;
  struct timespec t = decode_timespec(arg, &arg_lim, true);

  if (!valid_timespec(t))
    {
      if (arg < arg_lim && !*arg_lim)
        out_of_range_header(keyword, arg, TYPE_MINIMUM(time_t),
                            TYPE_MAXIMUM(time_t));
      else
        {
#if 0
          ERROR((0, 0, _("Malformed extended header: invalid %s=%s"),
                 keyword, arg));
#endif
          pedro_dprintf(2, "Malformed extended header: invalid %s=%s", keyword, arg);
        }
      return false;
    }

  *ts = t;
  return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
atime_decoder(struct tar_stat_info *st,
              char const *keyword,
              char const *arg,
              size_t size __attribute__((unused)))
{
  struct timespec ts;

  if (decode_time(&ts, arg, keyword))
    st->atime = ts;
}

/* Output fraction and trailing digits appropriate for a nanoseconds
   count equal to NS, but don't output unnecessary '.' or trailing
   zeros.  */

/**
 * Tar related function, version 1.34
 *
 */
void
code_ns_fraction(int ns, char *p)
{
  if (ns == 0)
    *p = '\0';
  else
    {
      int i = 9;
      *p++ = '.';

      while (ns % 10 == 0)
        {
          ns /= 10;
          i--;
        }

      p[i] = '\0';

      for (;;)
        {
          p[--i] = '0' + ns % 10;
          if (i == 0)
            break;
          ns /= 10;
        }
    }
}

/**
 * Tar related function, version 1.34
 *
 */
char const *
code_timespec(struct timespec t, char sbuf[TIMESPEC_STRSIZE_BOUND])
{
  time_t s = t.tv_sec;
  int ns = t.tv_nsec;
  char *np;
  bool negative = s < 0;

  /* ignore invalid values of ns */
  if (BILLION <= ns || ns < 0)
    ns = 0;

  if (negative && ns != 0)
    {
      s++;
      ns = BILLION - ns;
    }

  np = umaxtostr(negative ? -(uintmax_t)s : (uintmax_t)s, sbuf + 1);
  if (negative)
    *--np = '-';
  code_ns_fraction(ns, sbuf + UINTMAX_STRSIZE_BOUND);
  return np;
}

/**
 * Tar related function, version 1.34
 *
 */
struct timespec
decode_timespec(char const *arg, char **arg_lim, bool parse_fraction)
{
  time_t s = TYPE_MINIMUM(time_t);
  int ns = -1;
  char const *p = arg;
  bool negative = *arg == '-';
  struct timespec r;

  if (!ISDIGIT(arg[negative]))
    errno = EINVAL;
  else
    {
      errno = 0;

      if (negative)
        {
          intmax_t i = strtoimax(arg, arg_lim, 10);
          if (TYPE_SIGNED(time_t) ? TYPE_MINIMUM(time_t) <= i : 0 <= i)
            s = i;
          else
            errno = ERANGE;
        }
      else
        {
          uintmax_t i = strtoumax(arg, arg_lim, 10);
          if (i <= TYPE_MAXIMUM(time_t))
            s = i;
          else
            errno = ERANGE;
        }

      p = *arg_lim;
      ns = 0;

      if (parse_fraction && *p == '.')
        {
          int digits = 0;
          bool trailing_nonzero = false;

          while (ISDIGIT(*++p))
            if (digits < LOG10_BILLION)
              digits++, ns = 10 * ns + (*p - '0');
            else
              trailing_nonzero |= *p != '0';

          while (digits < LOG10_BILLION)
            digits++, ns *= 10;

          if (negative)
            {
              /* Convert "-1.10000000000001" to s == -2, ns == 89999999.
                 I.e., truncate time stamps towards minus infinity while
                 converting them to internal form.  */
              ns += trailing_nonzero;
              if (ns != 0)
                {
                  if (s == TYPE_MINIMUM(time_t))
                    ns = -1;
                  else
                    {
                      s--;
                      ns = BILLION - ns;
                    }
                }
            }
        }

      if (errno == ERANGE)
        ns = -1;
    }

  *arg_lim = (char *)p;
  r.tv_sec = s;
  r.tv_nsec = ns;
  return r;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
x_obstack_1grow(struct xheader *xhdr, char c)
{
  obstack_1grow(xhdr->stk, c);
  xhdr->size++;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
x_obstack_grow(struct xheader *xhdr, const char *ptr, size_t length)
{
  obstack_grow(xhdr->stk, ptr, length);
  xhdr->size += length;
}

/**
 * Tar related function, version 1.34
 *
 */
static char *
xattr_encode_keyword(const char *keyword)
{
  static char *encode_buffer = NULL;
  static size_t encode_buffer_size = 0;
  size_t bp; /* keyword/buffer pointers */

  if (!encode_buffer)
    {
      encode_buffer_size = 256;
      encode_buffer = malloc(encode_buffer_size);
    }
  else
    *encode_buffer = 0;

  for (bp = 0; *keyword != 0; ++bp, ++keyword)
    {
      char c = *keyword;

      if (bp + 2 /* enough for URL encoding also.. */ >= encode_buffer_size)
        {
          encode_buffer = x2realloc(encode_buffer, &encode_buffer_size);
        }

      if (c == '%')
        {
          strcpy(encode_buffer + bp, "%25");
          bp += 2;
        }
      else if (c == '=')
        {
          strcpy(encode_buffer + bp, "%3D");
          bp += 2;
        }
      else
        encode_buffer[bp] = c;
    }

  encode_buffer[bp] = 0;

  return encode_buffer;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xheader_print_n(struct xheader *xhdr, char const *keyword,
                char const *value, size_t vsize)
{
  size_t p;
  size_t n = 0;
  char nbuf[UINTMAX_STRSIZE_BOUND];
  char const *np;
  size_t len, klen;

  keyword = xattr_encode_keyword(keyword);
  klen = strlen(keyword);
  len = klen + vsize + 3; /* ' ' + '=' + '\n' */

  do
    {
      p = n;
      np = umaxtostr(len + p, nbuf);
      n = nbuf + sizeof nbuf - 1 - np;
    }while (n != p);

  x_obstack_grow(xhdr, np, n);
  x_obstack_1grow(xhdr, ' ');
  x_obstack_grow(xhdr, keyword, klen);
  x_obstack_1grow(xhdr, '=');
  x_obstack_grow(xhdr, value, vsize);
  x_obstack_1grow(xhdr, '\n');
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xheader_print(struct xheader *xhdr, char const *keyword, char const *value)
{
  xheader_print_n(xhdr, keyword, value, strlen(value));
}

/**
 * Tar related function, version 1.34
 *
 */
static void
atime_coder(struct tar_stat_info const *st, char const *keyword,
            struct xheader *xhdr, void const *data __attribute__ ((unused)))
{
  code_time(st->atime, keyword, xhdr);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
code_time(struct timespec t, char const *keyword, struct xheader *xhdr)
{
  char buf[TIMESPEC_STRSIZE_BOUND];

  xheader_print(xhdr, keyword, code_timespec(t, buf));
}

struct xhdr_tab const xhdr_tab[] = {
  { "atime", atime_coder, atime_decoder, 0, false },
  { "comment", dummy_coder, dummy_decoder, 0, false },
  { "charset", dummy_coder, dummy_decoder, 0, false },
  { "ctime", ctime_coder, ctime_decoder, 0, false },
  { "gid", gid_coder, gid_decoder, 0, false },
  { "gname", gname_coder, gname_decoder, 0, false },
  { "linkpath", linkpath_coder, linkpath_decoder, 0, false },
  { "mtime", mtime_coder, mtime_decoder, 0, false },
  { "path", path_coder, path_decoder, 0, false },
  { "size", size_coder, size_decoder, 0, false },
  { "uid", uid_coder, uid_decoder, 0, false },
  { "uname", uname_coder, uname_decoder, 0, false },

  /* Sparse file handling */
  { "GNU.sparse.name", path_coder, sparse_path_decoder,
    XHDR_PROTECTED, false },
  { "GNU.sparse.major", sparse_major_coder, sparse_major_decoder,
    XHDR_PROTECTED, false },
  { "GNU.sparse.minor", sparse_minor_coder, sparse_minor_decoder,
    XHDR_PROTECTED, false },
  { "GNU.sparse.realsize", sparse_size_coder, sparse_size_decoder,
    XHDR_PROTECTED, false },
  { "GNU.sparse.numblocks", sparse_numblocks_coder, sparse_numblocks_decoder,
    XHDR_PROTECTED, false },

  /* tar 1.14 - 1.15.90 keywords. */
  { "GNU.sparse.size", sparse_size_coder, sparse_size_decoder,
    XHDR_PROTECTED, false },
  /* tar 1.14 - 1.15.1 keywords. Multiple instances of these appeared in 'x'
     headers, and each of them was meaningful. It confilcted with POSIX specs,
     which requires that "when extended header records conflict, the last one
     given in the header shall take precedence." */
  { "GNU.sparse.offset", sparse_offset_coder, sparse_offset_decoder,
    XHDR_PROTECTED, false },
  { "GNU.sparse.numbytes", sparse_numbytes_coder, sparse_numbytes_decoder,
    XHDR_PROTECTED, false },
  /* tar 1.15.90 keyword, introduced to remove the above-mentioned conflict. */
  { "GNU.sparse.map", NULL /* Unused, see pax_dump_header() */,
    sparse_map_decoder, 0, false },

  { "GNU.dumpdir", dumpdir_coder, dumpdir_decoder,
    XHDR_PROTECTED, false },

  /* Keeps the tape/volume label. May be present only in the global headers.
     Equivalent to GNUTYPE_VOLHDR.  */
  { "GNU.volume.label", volume_label_coder, volume_label_decoder,
    XHDR_PROTECTED | XHDR_GLOBAL, false },

  /* These may be present in a first global header of the archive.
     They provide the same functionality as GNUTYPE_MULTIVOL header.
     The GNU.volume.size keeps the real_s_sizeleft value, which is
     otherwise kept in the size field of a multivolume header.  The
     GNU.volume.offset keeps the offset of the start of this volume,
     otherwise kept in oldgnu_header.offset.  */
  { "GNU.volume.filename", volume_label_coder, volume_filename_decoder,
    XHDR_PROTECTED | XHDR_GLOBAL, false },
  { "GNU.volume.size", volume_size_coder, volume_size_decoder,
    XHDR_PROTECTED | XHDR_GLOBAL, false },
  { "GNU.volume.offset", volume_offset_coder, volume_offset_decoder,
    XHDR_PROTECTED | XHDR_GLOBAL, false },

  /* We get the SELinux value from filecon, so add a namespace for SELinux
     instead of storing it in SCHILY.xattr.* (which would be RAW). */
  { "RHT.security.selinux",
    xattr_selinux_coder, xattr_selinux_decoder, 0, false },

  /* ACLs, use the star format... */
  { "SCHILY.acl.access",
    xattr_acls_a_coder, xattr_acls_a_decoder, 0, false },

  { "SCHILY.acl.default",
    xattr_acls_d_coder, xattr_acls_d_decoder, 0, false },

  /* We are storing all extended attributes using this rule even if some of them
     were stored by some previous rule (duplicates) -- we just have to make sure
     they are restored *only once* during extraction later on. */
  { "SCHILY.xattr", xattr_coder, xattr_decoder, 0, true },

  { NULL, NULL, NULL, 0, false }
};

/**
 * Tar related function, version 1.34
 *
 */
void
xheader_read(struct xheader *xhdr, union block *p, off_t size)
{
  size_t j = 0;

  if (size < 0)
    size = 0; /* Already diagnosed.  */

  if ((off_t)(SIZE_MAX - BLOCKSIZE) <= size)
    {
      //xalloc_die ();

      assert(0 && "never will occur");
    }
  size += BLOCKSIZE;

  xhdr->size = size;
  xhdr->buffer = xmalloc(size + 1);
  xhdr->buffer[size] = '\0';

  do
    {
      size_t len = size;

      if (len > BLOCKSIZE)
        len = BLOCKSIZE;

      if (!p)
        {
          //FATAL_ERROR ((0, 0, _("Unexpected EOF in archive")));

          pedro_dprintf(2, "Unexpected EOF in archive");
        }
      memcpy(&xhdr->buffer[j], p->buffer, len);
      set_next_block_after(p);

      p = find_next_block();

      j += len;
      size -= len;
    }while (size > 0);
}

//by amanda & ricardo 2021
