/*
    Copyright (C) <2021>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
        and GNU LESSER GENERAL PUBLIC LICENSE along with this program.
        If not, see <http://www.gnu.org/licenses/>.

    support: https://arsoftware.net.br/binarywork _____________
    mirror :  http://nomade.sourceforge.net/?AR=true&ar_debug=1

        direct programmers e-mails:
        Ricardo: arsoftware25@gmail.com  ricardo@arsoftware.net.br
         Amanda: arsoftware10@gmail.com  amanda@arsoftware.net. br

        immediate contact(for a very fast answer) WhatsApp
        (+55)41 9627 1708 - it is always on
 */

#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

#include <sys/time.h>

//#include <stat.h>kkkkkkk..eu te amo

#include <sys/stat.h>

#include "common_k.h"

#include "tar.h"

#define xmalloc malloc

# include <process.h>
# define SET_BINARY_MODE(arc) setmode(arc, O_BINARY)

#define OFF_FROM_HEADER(where) off_from_header (where, sizeof (where))

#define xrealloc realloc

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

char archive_name_array_string[1024] ={0};
#define _GL_ATTRIBUTE_WUR
#define _GL_ATTRIBUTE_PURE
#define GLOBAL
GLOBAL int seek_option;
GLOBAL bool seekable_archive;
GLOBAL const char *use_compress_program_option = NULL;
static int record_index;
GLOBAL bool read_full_records_option = true;
GLOBAL struct tar_stat_info current_stat_info;
typedef double tarlong;
GLOBAL tarlong tape_length_option;
static tarlong bytes_written;   /* bytes written on this volume */
static bool read_full_records = false;
GLOBAL size_t record_size;
bool write_archive_to_stdout;
static int read_error_count;
static void (*flush_write_ptr) (size_t);
static void (*flush_read_ptr) (void);
GLOBAL size_t archive_names = 1;//hack as usual...
GLOBAL bool multi_volume_option = false;
static off_t record_start_block; /* block ordinal at record_start */
GLOBAL bool backup_option = false;
GLOBAL int blocking_factor;
GLOBAL int archive = 0;
GLOBAL bool verify_option;
GLOBAL bool dev_null_output;
GLOBAL dev_t ar_dev;
GLOBAL ino_t ar_ino;
GLOBAL const char *volume_label_option = NULL;
GLOBAL struct timespec start_time;        /* when we started execution */
GLOBAL struct timespec volume_start_time; /* when the current volume was
                                             opened*/
GLOBAL struct timespec last_stat_time;    /* when the statistics was last computed */
GLOBAL bool same_order_option;
GLOBAL bool unquote_option;
GLOBAL struct exclude *excluded; //precisa ser inicializado
static size_t name_buffer_length; /* allocated length of name_buffer */
static char *name_buffer;       /* buffer to hold the current file name */
/* Either NL or NUL, as decided by the --null option.  */
static char filename_terminator = '\n';
static bool verbatim_files_from_option;
size_t recent_long_link_blocks; /* likewise, for long link */
union block *recent_long_link;  /* likewise, for long link */
union block *recent_long_name;
size_t recent_long_name_blocks; /* number of blocks in recent_long_name */
static struct keyword_list *global_header_override_list;
static union block *recent_global_header; /* Recent global header block */
static struct stat archive_stat; /* stat block for archive file */
static bool hit_eof;

char *output_start;

int force_exit_k = 0;

#ifndef FALLTHROUGH
# if __GNUC__ < 7

#  define FALLTHROUGH ((void) 0)
# else

#  define FALLTHROUGH __attribute__ ((__fallthrough__))
# endif
#endif

#define TYPE_SIGNED(t) (!((t) 0 < (t) -1))
#define TYPE_WIDTH(t) (sizeof (t) * CHAR_BIT)

#define TYPE_MAXIMUM(t)                                                 \
	((t) (!TYPE_SIGNED (t)                                               \
	? (t) -1                                                        \
	: ((((t) 1 << (TYPE_WIDTH (t) - 2)) - 1) * 2 + 1)))

# define gettext(Msgid) ((const char *) (Msgid))

#define _(msgid) gettext (msgid)
#define N_(msgid) msgid
/*
 #define _S_IWRITE       0x0080
 #define _S_IREAD        0x0100
 */
char *
anytostr (intmax_t i, char *buf)
{
	char *p = buf + 60;
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

#define STRINGIFY_BIGINT(i, b) anytostr (i, b)

#define NAME_FIELD_SIZE   100
#define PREFIX_FIELD_SIZE 155
#define UNAME_FIELD_SIZE   32
#define GNAME_FIELD_SIZE   32

/* A name_list element contains entries of three types: */

enum read_file_list_state  /* Result of reading file name from the list file */
{
	file_list_success, /* OK, name read successfully */
	file_list_end,     /* End of list file */
	file_list_zero,    /* Zero separator encountered where it should not */
	file_list_skip     /* Empty (zero-length) entry encountered, skip it */
};

enum nelt_type
{
	NELT_NAME, /* File name */
	NELT_CHDIR, /* Change directory request */
	NELT_FILE, /* Read file names from that file */
	NELT_NOOP, /* No operation */
	NELT_OPTION /* Filename-selection option */
};

struct passwd {
               char   *pw_name;       /* username */
               char   *pw_passwd;     /* user password */
               int   pw_uid;        /* user ID */
               int   pw_gid;        /* group ID */
               char   *pw_gecos;      /* user information */
               char   *pw_dir;        /* home directory */
               char   *pw_shell;      /* shell program */
           };

struct name_elt        /* A name_array element. */
{
	struct name_elt *next, *prev;
	enum nelt_type type; /* Element type, see NELT_* constants above */
	union
	{
		const char *name; /* File or directory name */
		struct /* File, if type == NELT_FILE */
		{
			const char *name;/* File name */
			size_t line; /* Input line number */
			int term; /* File name terminator in the list */
			bool verbatim; /* Verbatim handling of file names: no white-space
			                  trimming, no option processing */
			FILE *fp;
		} file;
		struct
		{
			int option;
			char const *arg;
		} opt; /* NELT_OPTION */
	} v;
};

static struct name_elt *name_head;/* store a list of names */

/* General Interface */

#define XHDR_PROTECTED 0x01
#define XHDR_GLOBAL    0x02

struct xhdr_tab
{
	char const *keyword;
	void (*coder) (struct tar_stat_info const *, char const *,
	               struct xheader *, void const *data);
	void (*decoder) (struct tar_stat_info *, char const *, char const *, size_t);
	int flags;
	bool prefix; /* select handler comparing prefix only */
};

/* Keyword options */

struct keyword_list
{
	struct keyword_list *next;
	char *pattern;
	char *value;
};

/* Prevent recursive inclusion of the same file */
struct file_id_list
{
	struct file_id_list *next;
	ino_t ino;
	dev_t dev;
	const char *from_file;
};

/* Where an option comes from: */
enum option_source
  {
    OPTS_ENVIRON,        /* Environment variable TAR_OPTIONS */
    OPTS_COMMAND_LINE,   /* Command line */
    OPTS_FILE            /* File supplied by --files-from */
  };

/* Option location */
struct option_locus
{
  enum option_source source;  /* Option origin */
  char const *name;           /* File or variable name */
  size_t line;                /* Number of input line if source is OPTS_FILE */
  struct option_locus *prev;  /* Previous occurrence of the option of same
				 class */
};

static struct file_id_list *file_id_list;

typedef struct wordsplit wordsplit_t;

/* Structure used to direct the splitting.  Members marked with [Input]
   can be defined before calling wordsplit(), those marked with [Output]
   provide return values when the function returns.  If neither mark is
   used, the member is internal and must not be used by the caller.

   In the comments below, the identifiers in parentheses indicate bits that
   must be set (or unset, if starting with !) in ws_flags (if starting with
   WRDSF_) or ws_options (if starting with WRDSO_) to initialize or use the
   given member.
   
   If not redefined explicitly, most of them are set to some reasonable
   default value upon entry to wordsplit(). */
struct wordsplit            
{
  size_t ws_wordc;          /* [Output] Number of words in ws_wordv. */
  char **ws_wordv;          /* [Output] Array of parsed out words. */
  size_t ws_offs;           /* [Input] (WRDSF_DOOFFS) Number of initial
			       elements in ws_wordv to fill with NULLs. */
  size_t ws_wordn;          /* Number of elements ws_wordv can accomodate. */ 
  unsigned ws_flags;        /* [Input] Flags passed to wordsplit. */
  unsigned ws_options;      /* [Input] (WRDSF_OPTIONS)
			       Additional options. */
  size_t ws_maxwords;       /* [Input] (WRDSO_MAXWORDS) Return at most that
			       many words */
  size_t ws_wordi;          /* [Output] (WRDSF_INCREMENTAL) Total number of
			       words returned so far */

  const char *ws_delim;     /* [Input] (WRDSF_DELIM) Word delimiters. */
  const char *ws_comment;   /* [Input] (WRDSF_COMMENT) Comment characters. */
  const char *ws_escape[2]; /* [Input] (WRDSF_ESCAPE) Characters to be escaped
			       with backslash. */
  void (*ws_alloc_die) (wordsplit_t *wsp);
                            /* [Input] (WRDSF_ALLOC_DIE) Function called when
			       out of memory.  Must not return. */
  void (*ws_error) (const char *, ...)
                   __attribute__ ((__format__ (__printf__, 1, 2)));
                            /* [Input] (WRDSF_ERROR) Function used for error
			       reporting */
  void (*ws_debug) (const char *, ...)
                   __attribute__ ((__format__ (__printf__, 1, 2)));
                            /* [Input] (WRDSF_DEBUG) Function used for debug
			       output. */
  const char **ws_env;      /* [Input] (WRDSF_ENV, !WRDSF_NOVAR) Array of
			       environment variables. */

  char **ws_envbuf;
  size_t ws_envidx;
  size_t ws_envsiz;
  
  int (*ws_getvar) (char **ret, const char *var, size_t len, void *clos);
                            /* [Input] (WRDSF_GETVAR, !WRDSF_NOVAR) Looks up
			       the name VAR (LEN bytes long) in the table of
			       variables and if found returns in memory
			       location pointed to by RET the value of that
			       variable.  Returns WRDSE_OK (0) on success,
			       and an error code (see WRDSE_* defines below)
			       on error.  User-specific errors can be returned
			       by storing the error diagnostic string in RET
			       and returning WRDSE_USERERR.
                               Whatever is stored in RET, it must be allocated
			       using malloc(3). */
  void *ws_closure;         /* [Input] (WRDSF_CLOSURE) Passed as the CLOS
			       argument to ws_getvar and ws_command. */
  int (*ws_command) (char **ret, const char *cmd, size_t len, char **argv,
                     void *clos);
	                    /* [Input] (!WRDSF_NOCMD) Returns in the memory
			       location pointed to by RET the expansion of
			       the command CMD (LEN bytes long).  If WRDSO_ARGV
			       option is set, ARGV contains CMD split out to
			       words.  Otherwise ARGV is NULL.

			       See ws_getvar for a discussion of possible
			       return values. */
	
  const char *ws_input;     /* Input string (the S argument to wordsplit. */  
  size_t ws_len;            /* Length of ws_input. */
  size_t ws_endp;           /* Points past the last processed byte in
			       ws_input. */
  int ws_errno;             /* [Output] Error code, if an error occurred. */
  char *ws_usererr;         /* Points to textual description of
			       the error, if ws_errno is WRDSE_USERERR.  Must
			       be allocated with malloc(3). */
  struct wordsplit_node *ws_head, *ws_tail;
                            /* Doubly-linked list of parsed out nodes. */
  int ws_lvl;               /* Invocation nesting level. */
};

/*

 #define INT_STRLEN_BOUND(t)                                     \
   (INT_BITS_STRLEN_BOUND (TYPE_WIDTH (t) - _GL_SIGNED_TYPE_OR_EXPR (t)) \
 + _GL_SIGNED_TYPE_OR_EXPR (t))

 #define INT_BUFSIZE_BOUND(t) (INT_STRLEN_BOUND (t) + 1)

 #define UINTMAX_STRSIZE_BOUND INT_BUFSIZE_BOUND (uintmax_t)

 */

enum read_header_mode
{
	read_header_auto,       /* process extended headers automatically */
	read_header_x_raw,      /* return raw extended headers (return
	                           HEADER_SUCCESS_EXTENDED) */
	read_header_x_global    /* when POSIX global extended header is read,
	                           decode it and return
	                           HEADER_SUCCESS_EXTENDED */
};

enum subcommand
{
	UNKNOWN_SUBCOMMAND,     /* none of the following */
	APPEND_SUBCOMMAND,      /* -r */
	CAT_SUBCOMMAND,         /* -A */
	CREATE_SUBCOMMAND,      /* -c */
	DELETE_SUBCOMMAND,      /* -D */
	DIFF_SUBCOMMAND,        /* -d */
	EXTRACT_SUBCOMMAND,     /* -x */
	LIST_SUBCOMMAND,        /* -t */
	UPDATE_SUBCOMMAND,      /* -u */
	TEST_LABEL_SUBCOMMAND,  /* --test-label */
};

GLOBAL enum subcommand subcommand_option;

enum compress_type {
	ct_none,       /* Unknown compression type */
	ct_tar,        /* Plain tar file */
	ct_compress,
	ct_gzip,
	ct_bzip2,
	ct_lzip,
	ct_lzma,
	ct_lzop,
	ct_xz,
	ct_zstd
};

struct zip_magic
{
	enum compress_type type;
	size_t length;
	char const *magic;
};

struct zip_program
{
	enum compress_type type;
	char const *program;
	char const *option;
};

static struct zip_magic const magic[] = {
	{ ct_none,     0, 0 },
	{ ct_tar,      0, 0 },
	{ ct_compress, 2, "\037\235" },
	{ ct_gzip,     2, "\037\213" },
	{ ct_bzip2,    3, "BZh" },
	{ ct_lzip,     4, "LZIP" },
	{ ct_lzma,     6, "\xFFLZMA" },
	{ ct_lzop,     4, "\211LZO" },
	{ ct_xz,       6, "\xFD" "7zXZ" },
	{ ct_zstd,     4, "\x28\xB5\x2F\xFD" },
};

#define NMAGIC (sizeof(magic)/sizeof(magic[0]))

/* Flags for use in set_quoting_flags.  */
enum quoting_flags
{
	/* Always elide null bytes from styles that do not quote them,
	   even when the length of the result is available to the
	   caller.  */
	QA_ELIDE_NULL_BYTES = 0x01,

	/* Omit the surrounding quote characters if no escaped characters
	   are encountered.  Note that if no other character needs
	   escaping, then neither does the escape character.  */
	QA_ELIDE_OUTER_QUOTES = 0x02,

	/* In the c_quoting_style and c_maybe_quoting_style, split ANSI
	   trigraph sequences into concatenated strings (for example,
	   "?""?/" rather than "??/", which could be confused with
	   "\\").  */
	QA_SPLIT_TRIGRAPHS = 0x04
};

enum quoting_style
{
	/* Output names as-is (ls --quoting-style=literal).  Can result in
	   embedded null bytes if QA_ELIDE_NULL_BYTES is not in
	   effect.

	   quotearg_buffer:
	   "simple", "\0 \t\n'\"\033??/\\", "a:b"
	   quotearg:
	   "simple", " \t\n'\"\033??/\\", "a:b"
	   quotearg_colon:
	   "simple", " \t\n'\"\033??/\\", "a:b"
	 */
	literal_quoting_style,

	/* Quote names for the shell if they contain shell metacharacters
	   or would cause ambiguous output (ls --quoting-style=shell).
	   Can result in embedded null bytes if QA_ELIDE_NULL_BYTES is not
	   in effect.

	   quotearg_buffer:
	   "simple", "'\0 \t\n'\\''\"\033??/\\'", "a:b"
	   quotearg:
	   "simple", "' \t\n'\\''\"\033??/\\'", "a:b"
	   quotearg_colon:
	   "simple", "' \t\n'\\''\"\033??/\\'", "'a:b'"
	 */
	shell_quoting_style,

	/* Quote names for the shell, even if they would normally not
	   require quoting (ls --quoting-style=shell-always).  Can result
	   in embedded null bytes if QA_ELIDE_NULL_BYTES is not in effect.
	   Behaves like shell_quoting_style if QA_ELIDE_OUTER_QUOTES is in
	   effect.

	   quotearg_buffer:
	   "'simple'", "'\0 \t\n'\\''\"\033??/\\'", "'a:b'"
	   quotearg:
	   "'simple'", "' \t\n'\\''\"\033??/\\'", "'a:b'"
	   quotearg_colon:
	   "'simple'", "' \t\n'\\''\"\033??/\\'", "'a:b'"
	 */
	shell_always_quoting_style,

	/* Quote names for the shell if they contain shell metacharacters
	   or other problematic characters (ls --quoting-style=shell-escape).
	   Non printable characters are quoted using the $'...' syntax,
	   which originated in ksh93 and is widely supported by most shells,
	   and proposed for inclusion in POSIX.

	   quotearg_buffer:
	   "simple", "''$'\\0'' '$'\\t\\n'\\''\"'$'\\033''??/\\'", "a:b"
	   quotearg:
	   "simple", "''$'\\0'' '$'\\t\\n'\\''\"'$'\\033''??/\\'", "a:b"
	   quotearg_colon:
	   "simple", "''$'\\0'' '$'\\t\\n'\\''\"'$'\\033''??/\\'", "'a:b'"
	 */
	shell_escape_quoting_style,

	/* Quote names for the shell even if they would normally not
	   require quoting (ls --quoting-style=shell-escape).
	   Non printable characters are quoted using the $'...' syntax,
	   which originated in ksh93 and is widely supported by most shells,
	   and proposed for inclusion in POSIX.  Behaves like
	   shell_escape_quoting_style if QA_ELIDE_OUTER_QUOTES is in effect.

	   quotearg_buffer:
	   "simple", "''$'\\0'' '$'\\t\\n'\\''\"'$'\\033''??/\'", "a:b"
	   quotearg:
	   "simple", "''$'\\0'' '$'\\t\\n'\\''\"'$'\\033''??/\'", "a:b"
	   quotearg_colon:
	   "simple", "''$'\\0'' '$'\\t\\n'\\''\"'$'\\033''??/\'", "'a:b'"
	 */
	shell_escape_always_quoting_style,

	/* Quote names as for a C language string (ls --quoting-style=c).
	   Behaves like c_maybe_quoting_style if QA_ELIDE_OUTER_QUOTES is
	   in effect.  Split into consecutive strings if
	   QA_SPLIT_TRIGRAPHS.

	   quotearg_buffer:
	   "\"simple\"", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "\"a:b\""
	   quotearg:
	   "\"simple\"", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "\"a:b\""
	   quotearg_colon:
	   "\"simple\"", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "\"a\\:b\""
	 */
	c_quoting_style,

	/* Like c_quoting_style except omit the surrounding double-quote
	   characters if no quoted characters are encountered.

	   quotearg_buffer:
	   "simple", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "a:b"
	   quotearg:
	   "simple", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "a:b"
	   quotearg_colon:
	   "simple", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "\"a:b\""
	 */
	c_maybe_quoting_style,

	/* Like c_quoting_style except always omit the surrounding
	   double-quote characters and ignore QA_SPLIT_TRIGRAPHS
	   (ls --quoting-style=escape).

	   quotearg_buffer:
	   "simple", "\\0 \\t\\n'\"\\033??/\\\\", "a:b"
	   quotearg:
	   "simple", "\\0 \\t\\n'\"\\033??/\\\\", "a:b"
	   quotearg_colon:
	   "simple", "\\0 \\t\\n'\"\\033??/\\\\", "a\\:b"
	 */
	escape_quoting_style,

	/* Like clocale_quoting_style, but use single quotes in the
	   default C locale or if the program does not use gettext
	   (ls --quoting-style=locale).  For UTF-8 locales, quote
	   characters will use Unicode.

	   LC_MESSAGES=C
	   quotearg_buffer:
	   "`simple'", "`\\0 \\t\\n\\'\"\\033??/\\\\'", "`a:b'"
	   quotearg:
	   "`simple'", "`\\0 \\t\\n\\'\"\\033??/\\\\'", "`a:b'"
	   quotearg_colon:
	   "`simple'", "`\\0 \\t\\n\\'\"\\033??/\\\\'", "`a\\:b'"

	   LC_MESSAGES=pt_PT.utf8
	   quotearg_buffer:
	   "\302\253simple\302\273",
	   "\302\253\\0 \\t\\n'\"\\033??/\\\\\302\253", "\302\253a:b\302\273"
	   quotearg:
	   "\302\253simple\302\273",
	   "\302\253\\0 \\t\\n'\"\\033??/\\\\\302\253", "\302\253a:b\302\273"
	   quotearg_colon:
	   "\302\253simple\302\273",
	   "\302\253\\0 \\t\\n'\"\\033??/\\\\\302\253", "\302\253a\\:b\302\273"
	 */
	locale_quoting_style,

	/* Like c_quoting_style except use quotation marks appropriate for
	   the locale and ignore QA_SPLIT_TRIGRAPHS
	   (ls --quoting-style=clocale).

	   LC_MESSAGES=C
	   quotearg_buffer:
	   "\"simple\"", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "\"a:b\""
	   quotearg:
	   "\"simple\"", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "\"a:b\""
	   quotearg_colon:
	   "\"simple\"", "\"\\0 \\t\\n'\\\"\\033??/\\\\\"", "\"a\\:b\""

	   LC_MESSAGES=pt_PT.utf8
	   quotearg_buffer:
	   "\302\253simple\302\273",
	   "\302\253\\0 \\t\\n'\"\\033??/\\\\\302\253", "\302\253a:b\302\273"
	   quotearg:
	   "\302\253simple\302\273",
	   "\302\253\\0 \\t\\n'\"\\033??/\\\\\302\253", "\302\253a:b\302\273"
	   quotearg_colon:
	   "\302\253simple\302\273",
	   "\302\253\\0 \\t\\n'\"\\033??/\\\\\302\253", "\302\253a\\:b\302\273"
	 */
	clocale_quoting_style,

	/* Like clocale_quoting_style except use the custom quotation marks
	   set by set_custom_quoting.  If custom quotation marks are not
	   set, the behavior is undefined.

	   left_quote = right_quote = "'"
	   quotearg_buffer:
	   "'simple'", "'\\0 \\t\\n\\'\"\\033??/\\\\'", "'a:b'"
	   quotearg:
	   "'simple'", "'\\0 \\t\\n\\'\"\\033??/\\\\'", "'a:b'"
	   quotearg_colon:
	   "'simple'", "'\\0 \\t\\n\\'\"\\033??/\\\\'", "'a\\:b'"

	   left_quote = "(" and right_quote = ")"
	   quotearg_buffer:
	   "(simple)", "(\\0 \\t\\n'\"\\033??/\\\\)", "(a:b)"
	   quotearg:
	   "(simple)", "(\\0 \\t\\n'\"\\033??/\\\\)", "(a:b)"
	   quotearg_colon:
	   "(simple)", "(\\0 \\t\\n'\"\\033??/\\\\)", "(a\\:b)"

	   left_quote = ":" and right_quote = " "
	   quotearg_buffer:
	   ":simple ", ":\\0\\ \\t\\n'\"\\033??/\\\\ ", ":a:b "
	   quotearg:
	   ":simple ", ":\\0\\ \\t\\n'\"\\033??/\\\\ ", ":a:b "
	   quotearg_colon:
	   ":simple ", ":\\0\\ \\t\\n'\"\\033??/\\\\ ", ":a\\:b "

	   left_quote = "\"'" and right_quote = "'\""
	   Notice that this is treated as a single level of quotes or two
	   levels where the outer quote need not be escaped within the inner
	   quotes.  For two levels where the outer quote must be escaped
	   within the inner quotes, you must use separate quotearg
	   invocations.
	   quotearg_buffer:
	   "\"'simple'\"", "\"'\\0 \\t\\n\\'\"\\033??/\\\\'\"", "\"'a:b'\""
	   quotearg:
	   "\"'simple'\"", "\"'\\0 \\t\\n\\'\"\\033??/\\\\'\"", "\"'a:b'\""
	   quotearg_colon:
	   "\"'simple'\"", "\"'\\0 \\t\\n\\'\"\\033??/\\\\'\"", "\"'a\\:b'\""
	 */
	custom_quoting_style
};

#define INT_BITS (sizeof (int) * CHAR_BIT)

struct quoting_options
{
	/* Basic quoting style.  */
	enum quoting_style style;

	/* Additional flags.  Bitwise combination of enum quoting_flags.  */
	int flags;

	/* Quote the characters indicated by this bit vector even if the
	   quoting style would not normally require them to be quoted.  */
	unsigned int quote_these_too[(UCHAR_MAX / INT_BITS) + 1];

	/* The left quote for custom_quoting_style.  */
	char const *left_quote;

	/* The right quote for custom_quoting_style.  */
	char const *right_quote;
};

static struct quoting_options default_quoting_options;


#if STDC_HEADERS
# define IN_CTYPE_DOMAIN(c) 1
#else
# define IN_CTYPE_DOMAIN(c) ((unsigned) (c) <= 0177)
#endif

#define ISDIGIT(c) ((unsigned) (c) - '0' <= 9)
#define ISODIGIT(c) ((unsigned) (c) - '0' <= 7)
#define ISPRINT(c) (IN_CTYPE_DOMAIN (c) && isprint (c))
#define ISSPACE(c) (IN_CTYPE_DOMAIN (c) && isspace (c))

#define LG_8 3
#define LG_64 6
#define LG_256 8

union block *record_start;      /* start of record of archive */
union block *record_end;        /* last+1 block of archive record */
union block *current_block;     /* current block of archive */
enum access_mode access_mode;   /* how do we handle the archive */
off_t records_read;             /* number of records read from this archive */
off_t records_written;          /* likewise, for records written */
extern off_t records_skipped;   /* number of records skipped at the start
                                   of the archive, defined in delete.c */
static void *record_buffer[2];  /* allocated memory */
static union block *record_buffer_aligned[2];
static int record_index;

enum access_mode
{
	ACCESS_READ,
	ACCESS_WRITE,
	ACCESS_UPDATE
};

extern bool time_to_start_writing;

const char *_wordsplit_errstr[] = {
  N_("no error"),
  N_("missing closing quote"),
  N_("memory exhausted"),
  N_("invalid wordsplit usage"),
  N_("unbalanced curly brace"),
  N_("undefined variable"),
  N_("input exhausted"),
  N_("unbalanced parenthesis"),
  N_("globbing error")
};

int _wordsplit_nerrs =
  sizeof (_wordsplit_errstr) / sizeof (_wordsplit_errstr[0]);

/* Node state flags */
#define _WSNF_NULL     0x01	/* null node (a noop) */
#define _WSNF_WORD     0x02	/* node contains word in v.word */
#define _WSNF_QUOTE    0x04	/* text is quoted */
#define _WSNF_NOEXPAND 0x08	/* text is not subject to expansion */
#define _WSNF_JOIN     0x10	/* node must be joined with the next node */
#define _WSNF_SEXP     0x20	/* is a sed expression */
#define _WSNF_DELIM    0x40     /* node is a delimiter */

#define _WSNF_EMPTYOK  0x0100	/* special flag indicating that
				   wordsplit_add_segm must add the
				   segment even if it is empty */

#define ISDELIM(ws,c) \
  (strchr ((ws)->ws_delim, (c)) != NULL)

struct wordsplit_node
{
  struct wordsplit_node *prev;	/* Previous element */
  struct wordsplit_node *next;	/* Next element */
  unsigned flags;		/* Node flags */
  union
  {
    struct
    {
      size_t beg;		/* Start of word in ws_input */
      size_t end;		/* End of word in ws_input */
    } segm;
    char *word;
  } v;
};


/* This structure describes a single expansion phase */
struct exptab
{
  char const *descr; /* Textual description (for debugging) */
  int flag;          /* WRDSF_ bit that controls this phase */
  int opt;           /* Entry-specific options (see EXPOPT_ flags below */
  int (*expansion) (struct wordsplit *wsp); /* expansion function */
};

#define EXPOPT_NEG      0x01
/* All bits in flag must be set in order for entry to match */
#define EXPORT_ALLOF    0x02
/* Coalesce the input list before running the expansion. */
#define EXPOPT_COALESCE 0x04

#define ISPUNCT(c) (strchr("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~",(c))!=NULL)

#define ISUPPER(c) ('A' <= ((unsigned) (c)) && ((unsigned) (c)) <= 'Z')
#define ISLOWER(c) ('a' <= ((unsigned) (c)) && ((unsigned) (c)) <= 'z')
#define ISALPHA(c) (ISUPPER(c) || ISLOWER(c))
//#define ISDIGIT(c) ('0' <= ((unsigned) (c)) && ((unsigned) (c)) <= '9')
#define ISXDIGIT(c) (strchr("abcdefABCDEF", c)!=NULL)
#define ISALNUM(c) (ISALPHA(c) || ISDIGIT(c))
//#define ISPRINT(c) (' ' <= ((unsigned) (c)) && ((unsigned) (c)) <= 127)

#define WRDSF_RETURN_DELIMS     0x00001000
#define WRDSO_MAXWORDS          0x00000080
#define WSP_RETURN_DELIMS(wsp) \
 ((wsp)->ws_flags & WRDSF_RETURN_DELIMS || ((wsp)->ws_options & WRDSO_MAXWORDS))

#define _WRDS_EOF   0
#define _WRDS_OK    1
#define _WRDS_ERR   2

char wordsplit_c_escape_tab[] = "\\\\\"\"a\ab\bf\fn\nr\rt\tv\v";

/* Initial size for ws_env, if allocated automatically */
#define WORDSPLIT_ENV_INIT 16

/* Wordsplit flags. */
/* Append the words found to the array resulting from a previous
   call. */
#define WRDSF_APPEND            0x00000001
/* Insert ws_offs initial NULLs in the array ws_wordv.
   (These are not counted in the returned ws_wordc.) */
#define WRDSF_DOOFFS            0x00000002
/* Don't do command substitution. */
#define WRDSF_NOCMD             0x00000004
/* The parameter p resulted from a previous call to
   wordsplit(), and wordsplit_free() was not called. Reuse the
   allocated storage. */
#define WRDSF_REUSE             0x00000008
/* Print errors */
#define WRDSF_SHOWERR           0x00000010
/* Consider it an error if an undefined variable is expanded. */
#define WRDSF_UNDEF             0x00000020
/* Don't do variable expansion. */
#define WRDSF_NOVAR             0x00000040
/* Abort on ENOMEM error */
#define WRDSF_ENOMEMABRT        0x00000080
/* Trim off any leading and trailind whitespace */
#define WRDSF_WS                0x00000100
/* Handle single quotes */
#define WRDSF_SQUOTE            0x00000200
/* Handle double quotes */
#define WRDSF_DQUOTE            0x00000400
/* Handle single and double quotes */
#define WRDSF_QUOTE             (WRDSF_SQUOTE|WRDSF_DQUOTE)
/* Replace each input sequence of repeated delimiters with a single
   delimiter */
#define WRDSF_SQUEEZE_DELIMS    0x00000800
/* Return delimiters */
/* Treat sed expressions as words */
#define WRDSF_SED_EXPR          0x00002000
/* ws_delim field is initialized */
#define WRDSF_DELIM             0x00004000
/* ws_comment field is initialized */
#define WRDSF_COMMENT           0x00008000
/* ws_alloc_die field is initialized */
#define WRDSF_ALLOC_DIE         0x00010000
/* ws_error field is initialized */
#define WRDSF_ERROR             0x00020000
/* ws_debug field is initialized */
#define WRDSF_DEBUG             0x00040000
/* ws_env field is initialized */
#define WRDSF_ENV               0x00080000
/* ws_getvar field is initialized */
#define WRDSF_GETVAR            0x00100000
/* enable debugging */
#define WRDSF_SHOWDBG           0x00200000
/* Don't split input into words.  Useful for side effects. */
#define WRDSF_NOSPLIT           0x00400000
/* Keep undefined variables in place, instead of expanding them to
   empty strings. */
#define WRDSF_KEEPUNDEF         0x00800000
/* Warn about undefined variables */
#define WRDSF_WARNUNDEF         0x01000000
/* Handle C escapes */
#define WRDSF_CESCAPES          0x02000000
/* ws_closure is set */
#define WRDSF_CLOSURE           0x04000000
/* ws_env is a Key/Value environment, i.e. the value of a variable is
   stored in the element that follows its name. */
#define WRDSF_ENV_KV            0x08000000
/* ws_escape is set */
#define WRDSF_ESCAPE            0x10000000
/* Incremental mode */
#define WRDSF_INCREMENTAL       0x20000000
/* Perform pathname and tilde expansion */
#define WRDSF_PATHEXPAND        0x40000000
/* ws_options is initialized */
#define WRDSF_OPTIONS           0x80000000

#define WRDSF_DEFFLAGS	       \
  (WRDSF_NOVAR | WRDSF_NOCMD | \
   WRDSF_QUOTE | WRDSF_SQUEEZE_DELIMS | WRDSF_CESCAPES)

/* Remove the word that produces empty string after path expansion */
#define WRDSO_NULLGLOB        0x00000001
/* Print error message if path expansion produces empty string */
#define WRDSO_FAILGLOB        0x00000002
/* Allow a leading period to be matched by metacharacters. */
#define WRDSO_DOTGLOB         0x00000004
/* ws_command needs argv parameter */
#define WRDSO_ARGV            0x00000008
/* Keep backslash in unrecognized escape sequences in words */
#define WRDSO_BSKEEP_WORD     0x00000010
/* Handle octal escapes in words */
#define WRDSO_OESC_WORD       0x00000020
/* Handle hex escapes in words */
#define WRDSO_XESC_WORD       0x00000040

/* ws_maxwords field is initialized */


/* Keep backslash in unrecognized escape sequences in quoted strings */
#define WRDSO_BSKEEP_QUOTE    0x00000100
/* Handle octal escapes in quoted strings */
#define WRDSO_OESC_QUOTE      0x00000200
/* Handle hex escapes in quoted strings */
#define WRDSO_XESC_QUOTE      0x00000400

#define WRDSO_BSKEEP          WRDSO_BSKEEP_WORD     
#define WRDSO_OESC            WRDSO_OESC_WORD       
#define WRDSO_XESC            WRDSO_XESC_WORD       

/* Indices into ws_escape */
#define WRDSX_WORD  0
#define WRDSX_QUOTE 1

/* Set escape option F in WS for words (Q==0) or quoted strings (Q==1) */
#define WRDSO_ESC_SET(ws,q,f) ((ws)->ws_options |= ((f) << 4*(q)))
/* Test WS for escape option F for words (Q==0) or quoted strings (Q==1) */
#define WRDSO_ESC_TEST(ws,q,f) ((ws)->ws_options & ((f) << 4*(q)))

#define WRDSE_OK         0
#define WRDSE_EOF        WRDSE_OK
#define WRDSE_QUOTE      1
#define WRDSE_NOSPACE    2
#define WRDSE_USAGE      3
#define WRDSE_CBRACE     4
#define WRDSE_UNDEF      5
#define WRDSE_NOINPUT    6
#define WRDSE_PAREN      7
#define WRDSE_GLOBERR    8
#define WRDSE_USERERR    9

static int
wordsplit_trimws (struct wordsplit *wsp);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//definicao de funcoes

static void
gnu_flush_write (size_t buffer_level);

static void
gnu_flush_read (void);

static void
simple_flush_read (void);

static void
_gnu_flush_read (void);

static void
short_read (size_t status);

static void
simple_flush_write (size_t level __attribute__((unused)));

static ssize_t
_flush_write (void);

size_t
sys_write_archive_buffer (void);

static void
_gnu_flush_write (size_t buffer_level);

static void
_open_archive (enum access_mode wanted_access);

bool
tar_stat_close (struct tar_stat_info *st);

void
tar_stat_destroy (struct tar_stat_info *st);

struct dirent *
readdir (DIR *dirp);

int
closedir (DIR *dirp);

void
xheader_xattr_free (struct xattr_array *xattr_map, size_t xattr_map_size);

void
xheader_destroy (struct xheader *xhdr);

void
info_free_exclist (struct tar_stat_info *dir);

static void
init_buffer (void);

void *
page_aligned_alloc (void **ptr, size_t size);

int
getpagesize (void);

static inline void *
ptr_align (void *ptr, size_t alignment);

static void
check_tty (enum access_mode mode);

static int
open_compressed_archive (void);

static enum compress_type
check_compressed_archive (bool *pshort);

union block *
find_next_block (void);

void
flush_archive (void);

static void
backspace_output (void);

void
flush_read (void);

enum read_header
tar_checksum (union block *header, bool silent);

static intmax_t
from_header (char const *where0, size_t digs, char const *type,
             intmax_t minval, uintmax_t maxval,
             bool octal_only, bool silent);

static void
base64_init (void);

struct quoting_options *
clone_quoting_options (struct quoting_options *o);

void *
xmemdup (void const *p, size_t s);

void
set_quoting_style (struct quoting_options *o, enum quoting_style s);

size_t
quotearg_buffer (char *buffer, size_t buffersize,
                 char const *arg, size_t argsize,
                 struct quoting_options const *o);

static size_t
quotearg_buffer_restyled (char *buffer, size_t buffersize,
                          char const *arg, size_t argsize,
                          enum quoting_style quoting_style, int flags,
                          unsigned int const *quote_these_too,
                          char const *left_quote,
                          char const *right_quote);

static char const *
gettext_quote (char const *msgid, enum quoting_style s);

intmax_t
represent_uintmax (uintmax_t n);

static void
guess_seekable_archive (void);

void
sys_detect_dev_null_output (void);

static void
set_volume_start_time (void);

off_t
off_from_header (const char *p, size_t s);

void
set_next_block_after (union block *block);

size_t
available_space_after (union block *pointer);

void
xheader_read (struct xheader *xhdr, union block *p, off_t size);

void
xheader_decode_global (struct xheader *xhdr);

static void
xheader_list_destroy (struct keyword_list **root);

static bool
decode_record (struct xheader *xhdr,
               char **ptr,
               void (*handler)(void *, char const *, char const *, size_t),
               void *data);

static void
decg (void *data, char const *keyword, char const *value,
      size_t size __attribute__((unused)));

static struct xhdr_tab const *
locate_handler (char const *keyword);

static void
xheader_list_append (struct keyword_list **root, char const *kw,
                     char const *value);

char *
xstrdup (char const *string);

void
assign_string (char **string, const char *value);

#  define FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE 1

# define DOUBLE_SLASH_IS_DISTINCT_ROOT 0

# define ISSLASH(C) ((C) == '/' || (C) == '\\')

# define _IS_DRIVE_LETTER(C) (((unsigned int) (C) | ('a' - 'A')) - 'a'  \
	                      <= 'z' - 'a')
# define FILE_SYSTEM_PREFIX_LEN(Filename) \
	(_IS_DRIVE_LETTER ((Filename)[0]) && (Filename)[1] == ':' ? 2 : 0)

bool
strip_trailing_slashes (char *file);

char *
last_component (char const *name);

size_t
base_len (char const *name);

void
name_gather (void);

static struct name_elt *
name_next_elt (int change_dirs);

static void
name_list_advance (void);

static void
unconsumed_option_push (struct name_elt *elt);

struct name_elt *unconsumed_option_tail;

static void
unconsumed_option_free (void);

static int
read_next_name (struct name_elt *ent, struct name_elt *ret);

static int
add_file_id (const char *filename);

static const char *
file_list_name (void);

static enum read_file_list_state
read_name_from_file (struct name_elt *ent);

void *
x2realloc (void *p, size_t *pn);

void *
x2nrealloc (void *p, size_t *pn, size_t s);

static void
chopslash (char *str);

int
unquote_string (char *string);

static int
handle_option (const char *str, struct name_elt const *ent);

int
wordsplit (const char *command, struct wordsplit *ws, unsigned flags);

int
wordsplit_len (const char *command, size_t length, struct wordsplit *wsp, 
               unsigned flags);

static int
wordsplit_run (const char *command, size_t length, struct wordsplit *wsp,
               unsigned flags, int lvl);

static int
_wsplt_seterr (struct wordsplit *wsp, int ec);

void
wordsplit_perror (struct wordsplit *wsp);

const char *
wordsplit_strerror (struct wordsplit *ws);

static int
wordsplit_finish (struct wordsplit *wsp);

static const char *
wsnode_ptr (struct wordsplit *wsp, struct wordsplit_node *p);

static void
wsnode_remove (struct wordsplit *wsp, struct wordsplit_node *node);

static int
wsnode_tail_coalesce (struct wordsplit *wsp, struct wordsplit_node *p);

static int
coalesce_segment (struct wordsplit *wsp, struct wordsplit_node *node);

static size_t
wsnode_len (struct wordsplit_node *p);

static int
_wsplt_nomem (struct wordsplit *wsp);

void
wordsplit_free (struct wordsplit *ws);

static void
wordsplit_free_nodes (struct wordsplit *wsp);

static void
wsnode_free (struct wordsplit_node *p);

void
wordsplit_free_words (struct wordsplit *ws);

void
wordsplit_free_envbuf (struct wordsplit *ws);

static int
wordsplit_process_list (struct wordsplit *wsp, size_t start);

static int
scan_word (struct wordsplit *wsp, size_t start, int consume_all);

static int
skip_sed_expr (const char *command, size_t i, size_t len);

static int
wordsplit_add_segm (struct wordsplit *wsp, size_t beg, size_t end, int flg);

static int
wsnode_new (struct wordsplit *wsp, struct wordsplit_node **pnode);

static void
wsnode_append (struct wordsplit *wsp, struct wordsplit_node *node);

static int
scan_qstring (struct wordsplit *wsp, size_t start, size_t *end);

static int
find_closing_paren (const char *str, size_t i, size_t len, size_t *poff,
		    char const *paren);

static inline size_t
skip_delim_internal (struct wordsplit *wsp, int return_delims);

static inline size_t
skip_delim (struct wordsplit *wsp);

static void
wordsplit_dump_nodes (struct wordsplit *wsp);

static const char *
wsnode_flagstr (unsigned flags);

static int
wordsplit_cmdexp (struct wordsplit *wsp);

static int
node_expand (struct wordsplit *wsp, struct wordsplit_node *node,
	     int (*beg_p) (int),
	     int (*ws_exp_fn) (struct wordsplit *wsp,
			       const char *str, size_t len,
			       struct wordsplit_node **ptail,
			       const char **pend,
			       unsigned flg));

static int
node_split_prefix (struct wordsplit *wsp,
		   struct wordsplit_node **ptail,
		   struct wordsplit_node *node,
		   size_t beg, size_t len, int flg);

static void
wsnode_insert (struct wordsplit *wsp, struct wordsplit_node *node,
	       struct wordsplit_node *anchor, int before);

static struct wordsplit_node *
wsnode_tail (struct wordsplit_node *p);

static int
begin_cmd_p (int c);

static int
expcmd (struct wordsplit *wsp, const char *str, size_t len,
	struct wordsplit_node **ptail, const char **pend, unsigned flg);
	
	static int
_wsplt_subsplit (struct wordsplit *wsp, struct wordsplit *wss,
		 char const *str, int len,
		 unsigned flags, int finalize);
		 
		 static int

wordsplit_init (struct wordsplit *wsp, const char *input, size_t len,
		unsigned flags);
		
		static void
_wsplt_alloc_die (struct wordsplit *wsp);

static void /*__WORDSPLIT_ATTRIBUTE_FORMAT ((__printf__, 1, 2))*/
_wsplt_error (const char *fmt, ...);

static void
wordsplit_init0 (struct wordsplit *wsp);

void
wordsplit_clearerr (struct wordsplit *ws);

static void
_wsplt_seterr_sub (struct wordsplit *wsp, struct wordsplit *wss);

static void
wsnode_nullelim (struct wordsplit *wsp);

static int
wordsplit_tildexpand (struct wordsplit *wsp);

void *
xzalloc (size_t s);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void *
xzalloc (size_t s)
{
  return memset (xmalloc (s), 0, s);
}

typedef size_t (*Hash_hasher) (const void *, size_t);
typedef bool (*Hash_comparator) (const void *, const void *);
typedef void (*Hash_data_freer) (void *);
typedef bool (*Hash_processor) (void *, void *);

struct hash_tuning
  {
    /* This structure is mainly used for 'hash_initialize', see the block
       documentation of 'hash_reset_tuning' for more complete comments.  */

    float shrink_threshold;     /* ratio of used buckets to trigger a shrink */
    float shrink_factor;        /* ratio of new smaller size to original size */
    float growth_threshold;     /* ratio of used buckets to trigger a growth */
    float growth_factor;        /* ratio of new bigger size to original size */
    bool is_n_buckets;          /* if CANDIDATE really means table size */
  };

typedef struct hash_tuning Hash_tuning;

struct hash_table;

typedef struct hash_table Hash_table;

/* Information and lookup.  */
size_t hash_get_n_buckets (const Hash_table *) _GL_ATTRIBUTE_PURE;
size_t hash_get_n_buckets_used (const Hash_table *) _GL_ATTRIBUTE_PURE;
size_t hash_get_n_entries (const Hash_table *) _GL_ATTRIBUTE_PURE;
size_t hash_get_max_bucket_length (const Hash_table *) _GL_ATTRIBUTE_PURE;
bool hash_table_ok (const Hash_table *) _GL_ATTRIBUTE_PURE;
void hash_print_statistics (const Hash_table *, FILE *);
void *hash_lookup (const Hash_table *, const void *);

/* Walking.  */
void *hash_get_first (const Hash_table *) _GL_ATTRIBUTE_PURE;
void *hash_get_next (const Hash_table *, const void *);
size_t hash_get_entries (const Hash_table *, void **, size_t);
size_t hash_do_for_each (const Hash_table *, Hash_processor, void *);

/* Allocation and clean-up.  */
size_t hash_string (const char *, size_t) _GL_ATTRIBUTE_PURE;
void hash_reset_tuning (Hash_tuning *);
Hash_table *hash_initialize (size_t, const Hash_tuning *,
                             Hash_hasher, Hash_comparator,
                             Hash_data_freer) _GL_ATTRIBUTE_WUR;
void hash_clear (Hash_table *);
void hash_free (Hash_table *);

/* Insertion and deletion.  */
bool hash_rehash (Hash_table *, size_t) _GL_ATTRIBUTE_WUR;
void *hash_insert (Hash_table *, const void *) _GL_ATTRIBUTE_WUR;

int hash_insert_if_absent (Hash_table *table, const void *entry,
                           const void **matched_ent);
void *hash_delete (Hash_table *, const void *);


#include "regex.h"
struct patopts
{
	int options;
	union
	{
		char const *pattern;
		regex_t re;
	} v;
};


struct exclude_pattern
{
	struct patopts *exclude;
	size_t exclude_alloc;
	size_t exclude_count;
};

enum exclude_type
{
	exclude_hash,                /* a hash table of excluded names */
	exclude_pattern              /* an array of exclude patterns */
};

struct exclude_segment
{
	struct exclude_segment *next; /* next segment in list */
	enum exclude_type type;      /* type of this segment */
	int options;                 /* common options for this segment */
	union
	{
		Hash_table *table;   /* for type == exclude_hash */
		struct exclude_pattern pat; /* for type == exclude_pattern */
	} v;
};

struct pattern_buffer
{
	struct pattern_buffer *next;
	char *base;
};

/* The exclude structure keeps a singly-linked list of exclude segments,
   maintained in reverse order.  */
struct exclude
{
	struct exclude_segment *head;
	struct pattern_buffer *patbuf;
};

#include "wordsplit_k.c"
#include "exclude_k.c"
#include "names_k.c"

/* Takes a quoted C string (like those produced by quote_copy_string)
   and turns it back into the un-quoted original.  This is done in
   place.  Returns 0 only if the string was not properly quoted, but
   completes the unquoting anyway.

   This is used for reading the saved directory file in incremental
   dumps.  It is used for decoding old 'N' records (demangling names).
   But also, it is used for decoding file arguments, would they come
   from the shell or a -T file, and for decoding the --exclude
   argument.  */
int
unquote_string (char *string)
{
	int result = 1;
	char *source = string;
	char *destination = string;

	/* Escape sequences other than \\ and \n are no longer generated by
	   quote_copy_string, but accept them for backwards compatibility,
	   and also because unquote_string is used for purposes other than
	   parsing the output of quote_copy_string.  */

	while (*source)
		if (*source == '\\')
			switch (*++source)
			{
			case '\\':
				*destination++ = '\\';
				source++;
				break;

			case 'a':
				*destination++ = '\a';
				source++;
				break;

			case 'b':
				*destination++ = '\b';
				source++;
				break;

			case 'f':
				*destination++ = '\f';
				source++;
				break;

			case 'n':
				*destination++ = '\n';
				source++;
				break;

			case 'r':
				*destination++ = '\r';
				source++;
				break;

			case 't':
				*destination++ = '\t';
				source++;
				break;

			case 'v':
				*destination++ = '\v';
				source++;
				break;

			case '?':
				*destination++ = 0177;
				source++;
				break;

			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			{
				int value = *source++ - '0';

				if (*source < '0' || *source > '7')
				{
					*destination++ = value;
					break;
				}
				value = value * 8 + *source++ - '0';
				if (*source < '0' || *source > '7')
				{
					*destination++ = value;
					break;
				}
				value = value * 8 + *source++ - '0';
				*destination++ = value;
				break;
			}

			default:
				result = 0;
				*destination++ = '\\';
				if (*source)
					*destination++ = *source++;
				break;
			}
		else if (source != destination)
			*destination++ = *source++;
		else
			source++, destination++;

	if (source != destination)
		*destination = '\0';
	return result;
}

/* Chop trailing slashes.  */
static void
chopslash (char *str)
{
	char *p = str + strlen (str) - 1;
	while (p > str && ISSLASH (*p))
		*p-- = '\0';
}

void *
x2nrealloc (void *p, size_t *pn, size_t s)
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
			enum { DEFAULT_MXFAST = 64 * sizeof (size_t) / 4 };

			n = DEFAULT_MXFAST / s;
			n += !n;
		}
#if 0
		if (xalloc_oversized (n, s))
			xalloc_die ();
#endif
	}
	else
	{
		/* Set N = floor (1.5 * N) + 1 so that progress is made even if N == 0.
		   Check for overflow, so that N * S stays in both ptrdiff_t and
		   size_t range.  The check may be slightly conservative, but an
		   exact check isn't worth the trouble.  */
#if 0
		if ((PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : SIZE_MAX) / 3 * 2 / s
		    <= n)
			xalloc_die ();
#endif

		n += n / 2 + 1;
	}

	*pn = n;
	return realloc (p, n * s);
}

void *
x2realloc (void *p, size_t *pn)
{
	return x2nrealloc (p, pn, 1);
}

/* Read from FP a sequence of characters up to TERM and put them
   into STK.
 */
static enum read_file_list_state
read_name_from_file (struct name_elt *ent)
{
	int c;
	size_t counter = 0;
	FILE *fp = ent->v.file.fp;
	int term = ent->v.file.term;

	++ent->v.file.line;
	for (c = getc (fp); c != EOF && c != term; c = getc (fp))
	{
		if (counter == name_buffer_length)
			name_buffer = x2realloc (name_buffer, &name_buffer_length);
		name_buffer[counter++] = c;
		if (c == 0)
		{
			/* We have read a zero separator. The file possibly is
			   zero-separated */
			return file_list_zero;
		}
	}

	if (counter == 0 && c != EOF)
		return file_list_skip;

	if (counter == name_buffer_length)
		name_buffer = x2realloc (name_buffer, &name_buffer_length);
	name_buffer[counter] = 0;
	chopslash (name_buffer);
	return (counter == 0 && c == EOF) ? file_list_end : file_list_success;
}

/* Return the name of the file from which the file names and options
   are being read.
 */
static const char *
file_list_name (void)
{
	struct name_elt *elt;

	for (elt = name_head; elt; elt = elt->next)
		if (elt->type == NELT_FILE && elt->v.file.fp)
			return elt->v.file.name;
	return ("command line");
}

static int
add_file_id (const char *filename)
{
	struct file_id_list *p;
	struct stat st;
	const char *reading_from;

	if (stat (filename, &st))
	{
		force_exit_k = 1;
		return 1;
		//stat_fatal (filename);
	}
	reading_from = file_list_name (); //__AMANDA__
	for (p = file_id_list; p; p = p->next)
		if (p->ino == st.st_ino && p->dev == st.st_dev)
		{
#if 0
			int oldc = set_char_quoting (NULL, ':', 1);
			ERROR ((0, 0,
			        _("%s: file list requested from %s already read from %s"),
			        quotearg_n (0, filename),
			        reading_from, p->from_file));
			set_char_quoting (NULL, ':', oldc);
#endif

			pedro_dprintf(0, "File list requested from %s\n", filename);

			force_exit_k = 1;
			return 1;
		}
	p = xmalloc (sizeof *p);
	p->next = file_id_list;
	p->ino = st.st_ino;
	p->dev = st.st_dev;
	p->from_file = reading_from;
	file_id_list = p;
	return 0;
}

static int
read_next_name (struct name_elt *ent, struct name_elt *ret)
{
	pedro_dprintf(0, "dentro de read_next_name, %d", __LINE__);
	if (!ent->v.file.fp)
	{
		if (!strcmp (ent->v.file.name, "-"))
		{
			assert(0);
#if 0
			request_stdin ("-T");
			ent->v.file.fp = stdin;
#endif

		}
		else
		{
			if (add_file_id (ent->v.file.name))
			{
				name_list_advance ();
				return 1;
			}
			pedro_dprintf(0, "nao pode chegar aqui, %d, arquivo '%s'", __LINE__, ent->v.file.name);
			if ((ent->v.file.fp = fopen (ent->v.file.name, "r")) == NULL)
			{
#if 0
				open_fatal (ent->v.file.name);
#endif

				force_exit_k = 1;

				return 1;

			}
		}
		ent->v.file.term = filename_terminator;
		ent->v.file.verbatim = verbatim_files_from_option;
	}

	while (1)
	{
		switch (read_name_from_file (ent))
		{
		case file_list_skip:
			continue;

		case file_list_zero:

			pedro_dprintf(0, "file name %s read contains nul character", ent->v.file.name);

			ent->v.file.term = 0;
			FALLTHROUGH;
		case file_list_success:
			if (!ent->v.file.verbatim)
			{
				if (unquote_option)
					unquote_string (name_buffer);
				if (handle_option (name_buffer, ent) == 0)
				{
					name_list_adjust ();
					return 1;
				}
			}
			ret->type = NELT_NAME;
			ret->v.name = name_buffer;
			return 0;

		case file_list_end:
			if (strcmp (ent->v.file.name, "-"))
				fclose (ent->v.file.fp);
			ent->v.file.fp = NULL;
			name_list_advance ();
			return 1;
		}
	}
}

/* Clear the unconsumed option list */
static void
unconsumed_option_free (void)
{
	while (unconsumed_option_tail)
	{
		struct name_elt *elt = unconsumed_option_tail;
		unconsumed_option_tail = unconsumed_option_tail->prev;
		free (elt);
	}
}

/* Push an option to the list */
static void
unconsumed_option_push (struct name_elt *elt)
{
	elt->next = NULL;
	elt->prev = unconsumed_option_tail;
	if (unconsumed_option_tail)
		unconsumed_option_tail->next = elt;
	unconsumed_option_tail = elt;
}

static void
name_list_advance (void)
{
	struct name_elt *elt = name_head;
	name_head = elt->next;
	if (name_head)
		name_head->prev = NULL;
	if (elt->type == NELT_OPTION || elt->type == NELT_CHDIR)
	{
		if (subcommand_option == CREATE_SUBCOMMAND
		    || subcommand_option == UPDATE_SUBCOMMAND)
			unconsumed_option_push (elt);
	}
	else
	{
		if (elt->type != NELT_NOOP)
			unconsumed_option_free ();
		free (elt);
	}
}

static struct name_elt *
name_next_elt (int change_dirs)
{
	static struct name_elt entry;
	struct name_elt *ep;

	while ((ep = name_head) != NULL)
	{
		switch (ep->type)
		{
		case NELT_NOOP:
			name_list_advance ();
			break;

		case NELT_FILE:
			if (read_next_name (ep, &entry) == 0)
				return &entry;

			if(force_exit_k)
			{
				return NULL;
			}

			continue;

		case NELT_CHDIR:
			if (change_dirs)
			{
				chdir_do (chdir_arg (xstrdup (ep->v.name)));
				name_list_advance ();
				break;
			}
			FALLTHROUGH;
		case NELT_NAME:
			copy_name (ep);
			if (unquote_option)
				unquote_string (name_buffer);
			entry.type = ep->type;
			entry.v.name = name_buffer;
			name_list_advance ();
			return &entry;

		case NELT_OPTION:
			handle_file_selection_option (ep->v.opt.option, ep->v.opt.arg);
			name_list_advance ();
			continue;
		}
	}

	unconsumed_option_report ();

	return NULL;
}

/* Gather names in a list for scanning.  Could hash them later if we
   really care.

   If the names are already sorted to match the archive, we just read
   them one by one.  name_gather reads the first one, and it is called
   by name_match as appropriate to read the next ones.  At EOF, the
   last name read is just left in the buffer.  This option lets users
   of small machines extract an arbitrary number of files by doing
   "tar t" and editing down the list of files.  */

void
name_gather (void)
{
	/* Buffer able to hold a single name.  */
	static struct name *buffer = NULL;

	struct name_elt *ep;

	if (same_order_option)
	{
		static int change_dir;

		while ((ep = name_next_elt (0)) && ep->type == NELT_CHDIR)
			change_dir = chdir_arg (xstrdup (ep->v.name));

		if(force_exit_k)
		{
			return;
		}


		if (ep)
		{
			free_name (buffer);
			buffer = make_name (ep->v.name);
			buffer->change_dir = change_dir;
			buffer->next = 0;
			buffer->found_count = 0;
			buffer->matching_flags = INCLUDE_OPTIONS;
			buffer->directory = NULL;
			buffer->parent = NULL;
			buffer->cmdline = true;

			namelist = nametail = buffer;
		}
		else if (change_dir)
			addname (0, change_dir, false, NULL);
	}
	else
	{
		/* Non sorted names -- read them all in.  */
		int change_dir = 0;

		for (;;)
		{
			int change_dir0 = change_dir;
			while ((ep = name_next_elt (0)) && ep->type == NELT_CHDIR)
				change_dir = chdir_arg (xstrdup (ep->v.name));
			if(force_exit_k)
			{
				return;
			}
			if (ep)
				addname (ep->v.name, change_dir, true, NULL);
			else
			{
				if (change_dir != change_dir0)
					addname (NULL, change_dir, false, NULL);
				break;
			}
		}
	}
}

size_t
base_len (char const *name)
{
	size_t len;
	size_t prefix_len = FILE_SYSTEM_PREFIX_LEN (name);

	for (len = strlen (name); 1 < len && ISSLASH (name[len - 1]); len--)
		continue;

	if (DOUBLE_SLASH_IS_DISTINCT_ROOT && len == 1
	    && ISSLASH (name[0]) && ISSLASH (name[1]) && !name[2])
		return 2;

	if (FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE && prefix_len
	    && len == prefix_len && ISSLASH (name[prefix_len]))
		return prefix_len + 1;

	return len;
}

/* Return the address of the last file name component of NAME.  If
   NAME has no relative file name components because it is a file
   system root, return the empty string.  */

char *
last_component (char const *name)
{

	//tem que ser testado

	char const *base = name + FILE_SYSTEM_PREFIX_LEN (name);
	char const *p;
	bool saw_slash = false;

	while (ISSLASH (*base))
		base++;

	for (p = base; *p; p++)
	{
		if (ISSLASH (*p))
			saw_slash = true;
		else if (saw_slash)
		{
			base = p;
			saw_slash = false;
		}
	}

	return (char *) base;
}

bool
strip_trailing_slashes (char *file)
{
	char *base = last_component (file);
	char *base_lim;
	bool had_slash;

	/* last_component returns "" for file system roots, but we need to turn
	   "///" into "/".  */
	if (!*base)
		base = file;
	base_lim = base + base_len (base);
	had_slash = (*base_lim != '\0');
	*base_lim = '\0';
	return had_slash;
}

/* Assign STRING to a copy of VALUE if not zero, or to zero.  If
   STRING was nonzero, it is freed first.  */
void
assign_string (char **string, const char *value)
{
	free (*string);
	*string = value ? xstrdup (value) : 0;
}

char *
xstrdup (char const *string)
{
	return xmemdup (string, strlen (string) + 1);
}

static void
xheader_list_append (struct keyword_list **root, char const *kw,
                     char const *value)
{
	struct keyword_list *kp = xmalloc (sizeof *kp);
	kp->pattern = xstrdup (kw);
	kp->value = value ? xstrdup (value) : NULL;
	kp->next = *root;
	*root = kp;
}

/* This declaration must be extern, because ISO C99 section 6.9.2
   prohibits a tentative definition that has both internal linkage and
   incomplete type.  If we made it static, we'd have to declare its
   size which would be a maintenance pain; if we put its initializer
   here, we'd need a boatload of forward declarations, which would be
   even more of a pain.  */
extern struct xhdr_tab const xhdr_tab[];

static struct xhdr_tab const *
locate_handler (char const *keyword)
{
	struct xhdr_tab const *p;

	for (p = xhdr_tab; p->keyword; p++)
		if (p->prefix)
		{
			if (strncmp (p->keyword, keyword, strlen(p->keyword)) == 0)
				return p;
		}
		else
		{
			if (strcmp (p->keyword, keyword) == 0)
				return p;
		}

	return NULL;
}

static void
decg (void *data, char const *keyword, char const *value,
      size_t size __attribute__((unused)))
{
	struct keyword_list **kwl = data;
	struct xhdr_tab const *tab = locate_handler (keyword);
	if (tab && (tab->flags & XHDR_GLOBAL))
		tab->decoder (data, keyword, value, size);
	else
		xheader_list_append (kwl, keyword, value);
}

/* Decode a single extended header record, advancing *PTR to the next record.
   Return true on success, false otherwise.  */
static bool
decode_record (struct xheader *xhdr,
               char **ptr,
               void (*handler)(void *, char const *, char const *, size_t),
               void *data)
{
	char *start = *ptr;
	char *p = start;
	size_t len;
	char *len_lim;
	char const *keyword;
	char *nextp;
	size_t len_max = xhdr->buffer + xhdr->size - start;

	while (*p == ' ' || *p == '\t')
		p++;

	if (!ISDIGIT (*p))
	{
		if (*p)
			pedro_dprintf(0, "Malformed extended header: missing length");
		return false;
	}

	len = strtol (p, &len_lim, 10);

	if (len_max < len)
	{
		int len_len = len_lim - p;
		pedro_dprintf(0, "Extended header length is out of range");
		return false;
	}

	nextp = start + len;

	for (p = len_lim; *p == ' ' || *p == '\t'; p++)
		continue;
	if (p == len_lim)
	{
		pedro_dprintf(0, "Malformed extended header: missing blank after length");
		return false;
	}

	keyword = p;
	p = strchr (p, '=');
	if (!(p && p < nextp))
	{
		pedro_dprintf(0, "Malformed extended header: missing equal sign");
		return false;
	}

	if (nextp[-1] != '\n')
	{
		pedro_dprintf(0, "Malformed extended header: missing newline");
		return false;
	}

	*p = nextp[-1] = '\0';
	handler (data, keyword, p + 1, nextp - p - 2); /* '=' + trailing '\n' */
	*p = '=';
	nextp[-1] = '\n';
	*ptr = nextp;
	return true;
}

static void
xheader_list_destroy (struct keyword_list **root)
{
	if (root)
	{
		struct keyword_list *kw = *root;
		while (kw)
		{
			struct keyword_list *next = kw->next;
			free (kw->pattern);
			free (kw->value);
			free (kw);
			kw = next;
		}
		*root = NULL;
	}
}

void
xheader_decode_global (struct xheader *xhdr)
{
	if (xhdr->size)
	{
		char *p = xhdr->buffer + BLOCKSIZE;

		xheader_list_destroy (&global_header_override_list);
		while (decode_record (xhdr, &p, decg, &global_header_override_list))
			continue;
	}
}

void
xheader_read (struct xheader *xhdr, union block *p, off_t size)
{
	size_t j = 0;

	if (size < 0)
		size = 0; /* Already diagnosed.  */

	if (SIZE_MAX - BLOCKSIZE <= size)
	{

		force_exit_k = 1;

		return;

		//xalloc_die ();
	}

	size += BLOCKSIZE;
	xhdr->size = size;
	xhdr->buffer = xmalloc (size + 1);
	xhdr->buffer[size] = '\0';

	do
	{
		size_t len = size;

		if (len > BLOCKSIZE)
			len = BLOCKSIZE;

		if (!p)
		{
			pedro_dprintf(0, "Unexpected EOF in archive");

			force_exit_k = 1;
			return;

		}

		memcpy (&xhdr->buffer[j], p->buffer, len);
		set_next_block_after (p);

		p = find_next_block ();

		j += len;
		size -= len;
	}
	while (size > 0);
}

/* Return the number of bytes comprising the space between POINTER
   through the end of the current buffer of blocks.  This space is
   available for filling with data, or taking data from.  POINTER is
   usually (but not always) the result of previous find_next_block call.  */
size_t
available_space_after (union block *pointer)
{
	return record_end->buffer - pointer->buffer;
}

/* Indicate that we have used all blocks up thru BLOCK. */
void
set_next_block_after (union block *block)
{
	while (block >= current_block)
		current_block++;

	/* Do *not* flush the archive here.  If we do, the same argument to
	   set_next_block_after could mean the next block (if the input record
	   is exactly one block long), which is not what is intended.  */

	if (current_block > record_end)
	{
		//abort ();
		force_exit_k = 1;
	}
}

off_t
off_from_header (const char *p, size_t s)
{
	/* Negative offsets are not allowed in tar files, so invoke
	   from_header with minimum value 0, not TYPE_MINIMUM (off_t).  */
	return from_header (p, s, "off_t",
	                    0, TYPE_MAXIMUM (off_t),
	                    false, false);
}

/* Get the system time into *TS.  */

void
gettime (struct timespec *ts)
{
#if defined CLOCK_REALTIME && HAVE_CLOCK_GETTIME
	clock_gettime (CLOCK_REALTIME, ts);
#else
	struct timeval tv;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
	gettimeofday (&tv, NULL);
#pragma GCC diagnostic pop
	ts->tv_sec = tv.tv_sec;
	ts->tv_nsec = tv.tv_usec * 1000;
#endif
}

static void
set_volume_start_time (void)
{
	gettime (&volume_start_time);
	last_stat_time = volume_start_time;
}

/* Save archive file inode and device numbers */
void
sys_save_archive_dev_ino (void)
{
	if (
#if 0
		!_isrmt (archive) &&
#endif
		S_ISREG (archive_stat.st_mode))
	{
		ar_dev = archive_stat.st_dev;
		ar_ino = archive_stat.st_ino;
	}
	else
		ar_dev = 0;
}

void
sys_detect_dev_null_output (void)
{
	static char const dev_null[] = "nul";

	dev_null_output = (strcmp (archive_name_array_string, dev_null) == 0

#if 0
	                   || (!_isrmt (archive))
#endif

	                   );
}


bool
sys_get_archive_stat (void)
{
	return fstat (archive, &archive_stat) == 0;
}

/* Guess if the archive is seekable. */
static void
guess_seekable_archive (void)
{
	struct stat st;

	if (subcommand_option == DELETE_SUBCOMMAND)
	{
		/* The current code in delete.c is based on the assumption that
		   skip_member() reads all data from the archive. So, we should
		   make sure it won't use seeks. On the other hand, the same code
		   depends on the ability to backspace a record in the archive,
		   so setting seekable_archive to false is technically incorrect.
		   However, it is tested only in skip_member(), so it's not a
		   problem. */
		seekable_archive = false;
	}

	if (seek_option != -1)
	{
		seekable_archive = !!seek_option;
		return;
	}

	if (!multi_volume_option && !use_compress_program_option
	    && fstat (archive, &st) == 0)
		seekable_archive = S_ISREG (st.st_mode);
	else
		seekable_archive = false;
}

/* Base 64 digits; see Internet RFC 2045 Table 1.  */
static char const base_64_digits[64] =
{
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
	'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

/* Table of base-64 digit values indexed by unsigned chars.
   The value is 64 for unsigned chars that are not base-64 digits.  */
static char base64_map[UCHAR_MAX + 1];

static void
base64_init (void)
{
	int i;
	memset (base64_map, 64, sizeof base64_map);
	for (i = 0; i < 64; i++)
		base64_map[(int) base_64_digits[i]] = i;
}

static inline void *
ptr_align (void *ptr, size_t alignment)
{
	char *p0 = ptr;
	char *p1 = p0 + alignment - 1;
	return p1 - (size_t) p1 % alignment;
}

int
getpagesize (void)
{
	SYSTEM_INFO system_info;
	GetSystemInfo (&system_info);
	return system_info.dwPageSize;
}

/* Return the address of a page-aligned buffer of at least SIZE bytes.
   The caller should free *PTR when done with the buffer.  */

void *
page_aligned_alloc (void **ptr, size_t size)
{
	size_t alignment = getpagesize ();
	size_t size1 = size + alignment;
	if (size1 < size)
	{
		pedro_dprintf(0, "memory exausted");
		abort();
	}
	*ptr = xmalloc (size1);
	return ptr_align (*ptr, alignment);
}

#include "hash.h"

#define EXCLUDE_ANCHORED (1 << 30)

/* Include instead of exclude.  */
#define EXCLUDE_INCLUDE (1 << 29)

/* '?', '*', '[', and '\\' are special in patterns.  Without this
   option, these characters are ordinary and fnmatch is not used.  */
#define EXCLUDE_WILDCARDS (1 << 28)

/* Patterns are POSIX extended regular expressions */
#define EXCLUDE_REGEX     (1 << 27)

/* Allocate storage for the pattern */
#define EXCLUDE_ALLOC     (1 << 26)

/* An array of pattern-options pairs.  */

/* Free the storage associated with an exclude list.  */

static void
free_exclude_segment (struct exclude_segment *seg);

void
free_exclude (struct exclude *ex);

void
free_exclude (struct exclude *ex)
{
	struct exclude_segment *seg;
	struct pattern_buffer *pbuf;

	for (seg = ex->head; seg; )
	{
		struct exclude_segment *next = seg->next;
		free_exclude_segment (seg);
		seg = next;
	}

	for (pbuf = ex->patbuf; pbuf; )
	{
		struct pattern_buffer *next = pbuf->next;
		free (pbuf->base);
		free (pbuf);
		pbuf = next;
	}

	free (ex);
}

struct exclist
{
	struct exclist *next, *prev;
	int flags;
	struct exclude *excluded;
};

void
info_free_exclist (struct tar_stat_info *dir)
{
	struct exclist *ep = dir->exclude_list;

	while (ep)
	{
		struct exclist *next = ep->next;
		free_exclude (ep->excluded);
		free (ep);
		ep = next;
	}

	dir->exclude_list = NULL;
}

/* Free a single exclude segment */
static void
free_exclude_segment (struct exclude_segment *seg)
{
	size_t i;

	switch (seg->type)
	{
	case exclude_pattern:
		for (i = 0; i < seg->v.pat.exclude_count; i++)
		{
			if (seg->v.pat.exclude[i].options & EXCLUDE_REGEX)
				regfree (&seg->v.pat.exclude[i].v.re);
		}
		free (seg->v.pat.exclude);
		break;

	case exclude_hash:
		hash_free (seg->v.table);
		break;
	}
	free (seg);
}

#include "obstack.h"

void
xheader_destroy (struct xheader *xhdr)
{
	if (xhdr->stk)
	{
		obstack_free (xhdr->stk, NULL);
		free (xhdr->stk);
		xhdr->stk = NULL;
	}
	else
		free (xhdr->buffer);
	xhdr->buffer = 0;
	xhdr->size = 0;
}

void
xheader_xattr_free (struct xattr_array *xattr_map, size_t xattr_map_size)
{
	size_t scan = 0;

	while (scan < xattr_map_size)
	{
		free (xattr_map[scan].xkey);
		free (xattr_map[scan].xval_ptr);

		++scan;
	}
	free (xattr_map);
}

struct dirent *
readdir (DIR *dirp)
{
	char type;
	struct dirent *result;

	/* There is no need to add code to produce entries for "." and "..".
	   According to the POSIX:2008 section "4.12 Pathname Resolution"
	   <http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap04.html>
	   "." and ".." are syntactic entities.
	   POSIX also says:
	     "If entries for dot or dot-dot exist, one entry shall be returned
	      for dot and one entry shall be returned for dot-dot; otherwise,
	      they shall not be returned."  */

	switch (dirp->status)
	{
	case -2:
		/* End of directory already reached.  */
		return NULL;
	case -1:
		break;
	case 0:
		if (!FindNextFile (dirp->current, &dirp->entry))
		{
			switch (GetLastError ())
			{
			case ERROR_NO_MORE_FILES:
				dirp->status = -2;
				return NULL;
			default:
				errno = EIO;
				return NULL;
			}
		}
		break;
	default:
		errno = dirp->status;
		return NULL;
	}

	dirp->status = 0;

	if (dirp->entry.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		type = DT_DIR;
	else if (dirp->entry.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT)
		type = DT_LNK;
	else if ((dirp->entry.dwFileAttributes
	          & ~(FILE_ATTRIBUTE_READONLY
	              | FILE_ATTRIBUTE_HIDDEN
	              | FILE_ATTRIBUTE_SYSTEM
	              | FILE_ATTRIBUTE_ARCHIVE
	              | FILE_ATTRIBUTE_NORMAL
	              | FILE_ATTRIBUTE_TEMPORARY
	              | FILE_ATTRIBUTE_SPARSE_FILE
	              | FILE_ATTRIBUTE_COMPRESSED
	              | FILE_ATTRIBUTE_NOT_CONTENT_INDEXED
	              | FILE_ATTRIBUTE_ENCRYPTED)) == 0)
		/* Devices like COM1, LPT1, NUL would also have the attributes 0x20 but
		   they cannot occur here.  */
		type = DT_REG;
	else
		type = DT_UNKNOWN;

	/* Reuse the memory of dirp->entry for the result.  */
	result =
		(struct dirent *)
		((char *) dirp->entry.cFileName - offsetof (struct dirent, d_name[0]));
	result->d_type = type;

	return result;
}

int
closedir (DIR *dirp)
{
	int retval_k;
	if (dirp->current != INVALID_HANDLE_VALUE)
		FindClose (dirp->current);
	free (dirp);
	retval_k = 0;
	return retval_k;
}

bool
tar_stat_close (struct tar_stat_info *st)
{
	int status = (st->dirstream ? closedir (st->dirstream)
	        : 0 < st->fd ? close (st->fd)
	        : 0);
	st->dirstream = 0;
	st->fd = 0;

	if (status == 0)
		return true;
	else
	{
#if 0
		close_diag (st->orig_file_name);
#endif

		pedro_dprintf(0, "Error closing files and dir");
		force_exit_k = 1;
		return false;
	}
}

void
tar_stat_destroy (struct tar_stat_info *st)
{
	tar_stat_close (st);
	xheader_xattr_free (st->xattr_map, st->xattr_map_size);
	free (st->orig_file_name);
	free (st->file_name);
	free (st->link_name);
	free (st->uname);
	free (st->gname);
	free (st->cntx_name);
	free (st->acls_a_ptr);
	free (st->acls_d_ptr);
	free (st->sparse_map);
	free (st->dumpdir);
	xheader_destroy (&st->xhdr);
	info_free_exclist (st);
	memset (st, 0, sizeof (*st));
}

static void
init_buffer (void)
{
	if (!record_buffer_aligned[record_index])
		record_buffer_aligned[record_index] =
			page_aligned_alloc (&record_buffer[record_index], record_size);

	record_start = record_buffer_aligned[record_index];
	current_block = record_start;
	record_end = record_start + blocking_factor;
}

static void
check_tty (enum access_mode mode)
{
	/* Refuse to read archive from and write it to a tty. */
	if (strcmp (archive_name_array_string, "-") == 0
	    && isatty (mode == ACCESS_READ ? STDIN_FILENO : STDOUT_FILENO))
	{
		pedro_dprintf(0, "Refusing to read archive contents from terminal "
		              "(missing -f option?)");
		force_exit_k = 1;
	}
}

/*  Flush the current buffer to/from the archive.  */
void
flush_archive (void)
{
	size_t buffer_level;

	if (access_mode == ACCESS_READ && time_to_start_writing)
	{
		access_mode = ACCESS_WRITE;
		time_to_start_writing = false;
		backspace_output ();
		if (record_end - record_start < blocking_factor)
		{
			memset (record_end, 0,
			        (blocking_factor - (record_end - record_start))
			        * BLOCKSIZE);
			record_end = record_start + blocking_factor;
			return;
		}
	}

	buffer_level = current_block->buffer - record_start->buffer;
	record_start_block += record_end - record_start;
	current_block = record_start;
	record_end = record_start + blocking_factor;

	switch (access_mode)
	{
	case ACCESS_READ:
		flush_read ();
		break;

	case ACCESS_WRITE:
		flush_write_ptr (buffer_level);
		break;

	case ACCESS_UPDATE:
		abort ();
	}
}

/* Return the location of the next available input or output block.
   Return zero for EOF.  Once we have returned zero, we just keep returning
   it, to avoid accidentally going on to the next file on the tape.  */
union block *
find_next_block (void)
{
	if (current_block == record_end)
	{
		if (hit_eof)
			return 0;
		flush_archive ();
		if (current_block == record_end)
		{
			hit_eof = true;
			return 0;
		}
	}
	return current_block;
}

void *
xmemdup (void const *p, size_t s)
{
	return memcpy (malloc (s), p, s);
}


#include "quotes_k.c"


/* Allocate a new set of quoting options, with contents initially identical
   to O if O is not null, or to the default if O is null.
   It is the caller's responsibility to free the result.  */
struct quoting_options *
clone_quoting_options (struct quoting_options *o)
{
	int e = errno;
	struct quoting_options *p = xmemdup (o ? o : &default_quoting_options,
	                                     sizeof *o);
	errno = e;
	return p;
}
size_t
quotearg_buffer (char *buffer, size_t buffersize,
                 char const *arg, size_t argsize,
                 struct quoting_options const *o)
{
	struct quoting_options const *p = o ? o : &default_quoting_options;
	int e = errno;
	size_t r = quotearg_buffer_restyled (buffer, buffersize, arg, argsize,
	                                     p->style, p->flags, p->quote_these_too,
	                                     p->left_quote, p->right_quote);
	errno = e;
	return r;
}
/* In O (or in the default if O is null),
   set the value of the quoting style to S.  */
void
set_quoting_style (struct quoting_options *o, enum quoting_style s)
{
	(o ? o : &default_quoting_options)->style = s;
}

intmax_t
represent_uintmax (uintmax_t n)
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

static intmax_t
from_header (char const *where0, size_t digs, char const *type,
             intmax_t minval, uintmax_t maxval,
             bool octal_only, bool silent)
{
	uintmax_t value;
	uintmax_t uminval = minval;
	uintmax_t minus_minval = -uminval;
	char const *where = where0;
	char const *lim = where + digs;
	bool negative = false;

	/* Accommodate buggy tar of unknown vintage, which outputs leading
	   NUL if the previous field overflows.  */
	where += !*where;

	/* Accommodate older tars, which output leading spaces.  */
	for (;;)
	{
		if (where == lim)
		{
			if (type && !silent)
				pedro_dprintf(0, "Blanks in header where numeric %s value expected", type);

			force_exit_k = 1;
			return -1;
		}
		if (!isspace ((unsigned char) *where))
			break;
		where++;
	}

	value = 0;
	if (ISODIGIT (*where))
	{
		char const *where1 = where;
		bool overflow = false;

		for (;;)
		{
			value += *where++ - '0';
			if (where == lim || !ISODIGIT (*where))
				break;
			overflow |= value != (value << LG_8 >> LG_8);
			value <<= LG_8;
		}

		/* Parse the output of older, unportable tars, which generate
		   negative values in two's complement octal.  If the leading
		   nonzero digit is 1, we can't recover the original value
		   reliably; so do this only if the digit is 2 or more.  This
		   catches the common case of 32-bit negative time stamps.  */
		if ((overflow || maxval < value) && '2' <= *where1 && type)
		{
			/* Compute the negative of the input value, assuming two's
			   complement.  */
			int digit = (*where1 - '0') | 4;
			overflow = 0;
			value = 0;
			where = where1;
			for (;;)
			{
				value += 7 - digit;
				where++;
				if (where == lim || !ISODIGIT (*where))
					break;
				digit = *where - '0';
				overflow |= value != (value << LG_8 >> LG_8);
				value <<= LG_8;
			}
			value++;
			overflow |= !value;

			if (!overflow && value <= minus_minval)
			{
				if (!silent)
					pedro_dprintf(0, "Archive octal value %s is out of %s range; assuming two's complement", where1, type);
				negative = true;
			}
		}

		if (overflow)
		{
			if (type && !silent)
				pedro_dprintf(0, "Archive octal value %s is out of %s range", where1, type);

			force_exit_k = 1;

			return -1;
		}
	}
	else if (octal_only)
	{
		/* Suppress the following extensions.  */
	}
	else if (*where == '-' || *where == '+')
	{
		/* Parse base-64 output produced only by tar test versions
		   1.13.6 (1999-08-11) through 1.13.11 (1999-08-23).
		   Support for this will be withdrawn in future releases.  */
		int dig;
		if (!silent)
		{
			static bool warned_once;
			if (!warned_once)
			{
				warned_once = true;
				pedro_dprintf(0, "Archive contains obsolescent base-64 headers");//:-) kkkkkk...
			}
		}
		negative = *where++ == '-';
		while (where != lim
		       && (dig = base64_map[(unsigned char) *where]) < 64)
		{
			if (value << LG_64 >> LG_64 != value)
			{
				char *string = alloca (digs + 1);
				memcpy (string, where0, digs);
				string[digs] = '\0';
				if (type && !silent)
					pedro_dprintf(0, "Archive signed base-64 string %s is out of %s range", string, type);

				force_exit_k = 1;

				return -1;
			}
			value = (value << LG_64) | dig;
			where++;
		}
	}
	else if (*where == '\200' /* positive base-256 */
	         || *where == '\377' /* negative base-256 */)
	{
		/* Parse base-256 output.  A nonnegative number N is
		   represented as (256**DIGS)/2 + N; a negative number -N is
		   represented as (256**DIGS) - N, i.e. as two's complement.
		   The representation guarantees that the leading bit is
		   always on, so that we don't confuse this format with the
		   others (assuming ASCII bytes of 8 bits or more).  */
		int signbit = *where & (1 << (LG_256 - 2));
		uintmax_t topbits = (((uintmax_t) -signbit)
		                     << (CHAR_BIT * sizeof (uintmax_t)
		                         - LG_256 - (LG_256 - 2)));
		value = (*where++ & ((1 << (LG_256 - 2)) - 1)) - signbit;
		for (;;)
		{
			value = (value << LG_256) + (unsigned char) *where++;
			if (where == lim)
				break;
			if (((value << LG_256 >> LG_256) | topbits) != value)
			{
				if (type && !silent)
					pedro_dprintf(0, "Archive base-256 value is out of %s range", type);

				force_exit_k = 1;

				return -1;
			}
		}
		negative = signbit != 0;
		if (negative)
			value = -value;
	}

	if (where != lim && *where && !isspace ((unsigned char) *where))
	{
		if (type)
		{
			char buf[1000]; /* Big enough to represent any header.  */
			static struct quoting_options *o;

			if (!o)
			{
				o = clone_quoting_options (0);
				set_quoting_style (o, locale_quoting_style);
			}

			while (where0 != lim && !lim[-1])
				lim--;
			quotearg_buffer (buf, sizeof buf, where0, lim - where0, o);
			if (!silent)
				pedro_dprintf(0, "Archive contains %s where numeric %s value expected", buf, type);
		}

		return -1;
	}

	if (value <= (negative ? minus_minval : maxval))
		return represent_uintmax (negative ? -value : value);

	if (type && !silent)
	{
		char minval_buf[5000 /*UINTMAX_STRSIZE_BOUND + 1*/];
		char maxval_buf[5000 /*UINTMAX_STRSIZE_BOUND + 1*/];
		char value_buf[5000 /*UINTMAX_STRSIZE_BOUND + 1*/];
		char *minval_string = STRINGIFY_BIGINT (minus_minval, minval_buf + 1);
		char *value_string = STRINGIFY_BIGINT (value, value_buf + 1);
		if (negative)
			*--value_string = '-';
		if (minus_minval)
			*--minval_string = '-';
		/* TRANSLATORS: Second %s is type name (gid_t,uid_t,etc.) */
		pedro_dprintf(0, "Archive value %s is out of %s range %s..%s", value_string, type, minval_string, STRINGIFY_BIGINT (maxval, maxval_buf));
	}

	return -1;
}

enum read_header
tar_checksum (union block *header, bool silent)
{
	size_t i;
	int unsigned_sum = 0;   /* the POSIX one :-) */
	int signed_sum = 0;     /* the Sun one :-( */
	int recorded_sum;
	int parsed_sum;
	char *p;

	p = header->buffer;
	for (i = sizeof *header; i-- != 0;)
	{
		unsigned_sum += (unsigned char) *p;
		signed_sum += (signed char) (*p++);
	}

	if (unsigned_sum == 0)
		return HEADER_ZERO_BLOCK;

	/* Adjust checksum to count the "chksum" field as blanks.  */

	for (i = sizeof header->header.chksum; i-- != 0;)
	{
		unsigned_sum -= (unsigned char) header->header.chksum[i];
		signed_sum -= (signed char) (header->header.chksum[i]);
	}
	unsigned_sum += ' ' * sizeof header->header.chksum;
	signed_sum += ' ' * sizeof header->header.chksum;

	parsed_sum = from_header (header->header.chksum,
	                          sizeof header->header.chksum, 0,
	                          0, INT_MAX, true, silent);


	if(force_exit_k)
	{
		return HEADER_FAILURE;
	}
	if (parsed_sum < 0)
		return HEADER_FAILURE;

	recorded_sum = parsed_sum;

	if (unsigned_sum != recorded_sum && signed_sum != recorded_sum)
		return HEADER_FAILURE;

	return HEADER_SUCCESS;
}

/* Check if the file ARCHIVE is a compressed archive. */
static enum compress_type
check_compressed_archive (bool *pshort)
{
	struct zip_magic const *p;
	bool sfr;
	bool temp;

	if (!pshort)
		pshort = &temp;

	/* Prepare global data needed for find_next_block: */
	record_end = record_start; /* set up for 1st record = # 0 */
	sfr = read_full_records;
	read_full_records = true; /* Suppress fatal error on reading a partial
	                             record */
	*pshort = find_next_block () == 0;

	/* Restore global values */
	read_full_records = sfr;

	if (record_start != record_end /* no files smaller than BLOCKSIZE */
	    && (strcmp (record_start->header.magic, TMAGIC) == 0
	        || strcmp (record_start->buffer + offsetof (struct posix_header,
	                                                    magic),
	                   OLDGNU_MAGIC) == 0)
	    && tar_checksum (record_start, true) == HEADER_SUCCESS)
		/* Probably a valid header */
		return ct_tar;

	for (p = magic + 2; p < magic + NMAGIC; p++)
		if (memcmp (record_start->buffer, p->magic, p->length) == 0)
			return p->type;

	return ct_none;
}

/* Open an archive named archive_name_array[0]. Detect if it is
   a compressed archive of known type and use corresponding decompression
   program if so */
static int
open_compressed_archive (void)
{
	archive = open (archive_name_array_string, O_RDONLY | O_BINARY,
	                _S_IREAD);
	if (archive == -1)
		return archive;

	if (!multi_volume_option)
	{
		if (!use_compress_program_option)
		{
			bool shortfile;
			enum compress_type type = check_compressed_archive (&shortfile);

			switch (type)
			{
			case ct_tar:
				if (shortfile)
				{
					pedro_dprintf(0, "This does not look like a tar archive");
					force_exit_k = 1;
				}
				return archive;//aqui vai ser trigger
				break;
			case ct_none:
				if (shortfile)
				{
					pedro_dprintf(0, "This does not look like a tar archive");
					force_exit_k = 1;
				}
				return archive;
				break;

			default:

			{
				pedro_dprintf(0, "This does not look like a tar archive");
				force_exit_k = 1;
				return archive;
			}
#if 0
				archive_compression_type = type;
#endif
				break;
			}
		}

		assert(0);//nunca vai chegar aqui
		/* FD is not needed any more */
		close (archive);

		hit_eof = false; /* It might have been set by find_next_block in
		                    check_compressed_archive */
/*
      // Open compressed archive
      child_pid = sys_child_open_for_uncompress ();
      read_full_records = true;
 */
	}

	records_read = 0;
	record_end = record_start; /* set up for 1st record = # 0 */

	return archive;
}

/* Open an archive file.  The argument specifies whether we are
   reading or writing, or both.  */
static void
_open_archive (enum access_mode wanted_access)
{
	int backed_up_flag = 0;

	if (record_size == 0)
	{
		pedro_dprintf(0, "Invalid value for record_size");
		force_exit_k = 1;
		return;
	}

	if (archive_names == 0)
	{
		pedro_dprintf(0, "No archive name given");
		force_exit_k = 1;
		return;
	}

	tar_stat_destroy (&current_stat_info);

	record_index = 0;
	init_buffer ();

	/* When updating the archive, we start with reading.  */
	access_mode = wanted_access == ACCESS_UPDATE ? ACCESS_READ : wanted_access;
	check_tty (access_mode);

	if(force_exit_k)
	{
		return;
	}
	read_full_records = read_full_records_option;

	records_read = 0;

	if (use_compress_program_option)
	{
#if 0
		switch (wanted_access)
		{
		case ACCESS_READ:
			child_pid = sys_child_open_for_uncompress ();
			read_full_records = true;
			record_end = record_start; /* set up for 1st record = # 0 */
			break;

		case ACCESS_WRITE:
			child_pid = sys_child_open_for_compress ();
			break;

		case ACCESS_UPDATE:
			abort (); /* Should not happen */
			break;
		}

		if (!index_file_name
		    && wanted_access == ACCESS_WRITE
		    && strcmp (archive_name_array_string, "-") == 0)
			stdlis = stderr;

#endif

	}
	else if (strcmp (archive_name_array_string, "-") == 0)
	{

#if 0
		read_full_records = true; /* could be a pipe, be safe */
		if (verify_option)
			FATAL_ERROR ((0, 0, _("Cannot verify stdin/stdout archive")));

		switch (wanted_access)
		{
		case ACCESS_READ:
		{
			bool shortfile;
			enum compress_type type;

			archive = STDIN_FILENO;
			type = check_compressed_archive (&shortfile);
			if (type != ct_tar && type != ct_none)
				FATAL_ERROR ((0, 0,
				              _("Archive is compressed. Use %s option"),
				              compress_option (type)));
			if (shortfile)
				ERROR ((0, 0, _("This does not look like a tar archive")));
		}
		break;

		case ACCESS_WRITE:
			archive = STDOUT_FILENO;
			if (!index_file_name)
				stdlis = stderr;
			break;

		case ACCESS_UPDATE:
			archive = STDIN_FILENO;
			write_archive_to_stdout = true;
			record_end = record_start; /* set up for 1st record = # 0 */
			if (!index_file_name)
				stdlis = stderr;
			break;
		}
#endif
	}
	else
		switch (wanted_access)
		{
		case ACCESS_READ:
			archive = open_compressed_archive ();

			if(force_exit_k)
			{
				return;
			}

			if (archive >= 0)
				guess_seekable_archive ();
			break;

		case ACCESS_WRITE:
#if 0
			if (backup_option)
			{
				maybe_backup_file (archive_name_array_string, 1);
				backed_up_flag = 1;
			}
#endif
			if (verify_option)
				archive = open (archive_name_array_string, O_RDWR | O_CREAT | O_BINARY, _S_IREAD | _S_IWRITE);
			else
				archive = creat (archive_name_array_string, _S_IREAD | _S_IWRITE);
			break;

		case ACCESS_UPDATE:
			archive = open (archive_name_array_string,
			                O_RDWR | O_CREAT | O_BINARY,
			                _S_IREAD | _S_IWRITE);

			switch (check_compressed_archive (NULL))
			{
			case ct_none:
			case ct_tar:
				break;

			default:
				pedro_dprintf(0, "Cannot update compressed archives");

				force_exit_k = 1;
				return;

			}
			break;
		}

	if (archive < 0
	    || (

#if 0
		    !_isrmt (archive) &&
#endif

		    !sys_get_archive_stat ()))
	{
		int saved_errno = errno;

		pedro_dprintf(0, "deu erro de stat, linha %d", __LINE__);
#if 0
		if (backed_up_flag)
			undo_last_backup ();
#endif
		errno = saved_errno;
#if 0
		open_fatal (archive_name_array_string);
#endif

		force_exit_k = 1;

		return;

	}

	sys_detect_dev_null_output ();
	sys_save_archive_dev_ino ();
	SET_BINARY_MODE (archive);

	switch (wanted_access)
	{
	case ACCESS_READ:
		find_next_block (); /* read it in, check for EOF */
		break;

	case ACCESS_UPDATE:
	case ACCESS_WRITE:
		records_written = 0;
		break;
	}
}

static void
_gnu_flush_write (size_t buffer_level)
{
	ssize_t status;
	union block *header;
	char *copy_ptr;
	size_t copy_size;
	size_t bufsize;
	struct bufmap *map;

	status = _flush_write ();
	if (status != record_size)
	{
		pedro_dprintf(0, "Error writing to file");
		force_exit_k = 1;
	}
	else
	{
		if (status)
			records_written++;
		bytes_written += status;
	}

	if (status == record_size)
	{
		return;
	}


#if 0
	map = bufmap_locate (status);
#endif
	if (status % BLOCKSIZE)
	{
		pedro_dprintf(0, "write did not end on a block boundary");
		//archive_write_error (status);
		force_exit_k = 1;
		return;
	}

#if 0
	/* In multi-volume mode. */
	/* ENXIO is for the UNIX PC.  */
	if (status < 0 && errno != ENOSPC && errno != EIO && errno != ENXIO)
		archive_write_error (status);

	if (!new_volume (ACCESS_WRITE))
		return;

	tar_stat_destroy (&dummy);

	increase_volume_number ();
	prev_written += bytes_written;
	bytes_written = 0;

	copy_ptr = record_start->buffer + status;
	copy_size = buffer_level - status;

	/* Switch to the next buffer */
	record_index = !record_index;
	init_buffer ();

	inhibit_map = 1;

	if (volume_label_option)
		add_volume_label ();

	if (map)
		add_multi_volume_header (map);

	write_extended (true, &dummy, find_next_block ());
	tar_stat_destroy (&dummy);

	if (map)
		add_chunk_header (map);
	header = find_next_block ();
	bufmap_reset (map, header - record_start);
	bufsize = available_space_after (header);
	inhibit_map = 0;
	while (bufsize < copy_size)
	{
		memcpy (header->buffer, copy_ptr, bufsize);
		copy_ptr += bufsize;
		copy_size -= bufsize;
		set_next_block_after (header + (bufsize - 1) / BLOCKSIZE);

		if(force_exit_k)
		{
			return;
		}

		header = find_next_block ();
		bufsize = available_space_after (header);
	}
	memcpy (header->buffer, copy_ptr, copy_size);
	memset (header->buffer + copy_size, 0, bufsize - copy_size);
	set_next_block_after (header + (copy_size - 1) / BLOCKSIZE);

	if(force_exit_k)
	{
		return;
	}

	find_next_block ();
#endif
}

size_t
sys_write_archive_buffer (void)
{
	return write (archive, record_start->buffer, record_size);
}

/* Perform a write to flush the buffer.  */
static ssize_t
_flush_write (void)
{
	ssize_t status;

	// checkpoint_run (true);
	if (tape_length_option && tape_length_option <= bytes_written)
	{
		errno = ENOSPC;
		status = 0;
	}
#if 0
	else if (dev_null_output)
		status = record_size;
#endif
	else
		status = sys_write_archive_buffer ();
#if 0
	if (status && multi_volume_option && !inhibit_map)
	{
		struct bufmap *map = bufmap_locate (status);
		if (map)
		{
			size_t delta = status - map->start * BLOCKSIZE;
			ssize_t diff;
			map->nblocks += delta / BLOCKSIZE;
			if (delta > map->sizeleft)
				delta = map->sizeleft;
			map->sizeleft -= delta;
			if (map->sizeleft == 0)
			{
				diff = map->start + map->nblocks;
				map = map->next;
			}
			else
				diff = map->start;
			bufmap_reset (map, -diff);
		}
	}

#endif

	return status;
}

static void
simple_flush_write (size_t level __attribute__((unused)))
{
	ssize_t status;

	status = _flush_write ();
	if (status != record_size)
	{
		force_exit_k = 1;
		return;
	}
	else
	{
		records_written++;
		bytes_written += status;
	}
}

static void
short_read (size_t status)
{
	size_t left;            /* bytes left */
	char *more;             /* pointer to next byte to read */

	more = record_start->buffer + status;
	left = record_size - status;

	if (left && left % BLOCKSIZE == 0
	    /*&& (warning_option & WARN_RECORD_SIZE)*/
	    && record_start_block == 0 && status != 0

#if 0
	    && archive_is_dev ()
#endif

	    )
	{
		unsigned long rsize = status / BLOCKSIZE;
		pedro_dprintf(0, "Record size = %lu block", rsize);
	}

	while (left % BLOCKSIZE != 0
	       || (left && status && read_full_records))
	{
		if (status)
		{
			status = read (archive, more, left);

			if(-1 == status)
			{
				force_exit_k = 1;//error
				return;
			}
		}

		if (status == 0)
			break;

		if (!read_full_records)
		{
			unsigned long rest = record_size - left;
			pedro_dprintf(0, "Unaligned block (%lu bytes) in archive", rest);
			force_exit_k = 1;
			return;
		}

		left -= status;
		more += status;
	}

	record_end = record_start + (record_size - left) / BLOCKSIZE;
	records_read++;
}

static void
_gnu_flush_read (void)
{
	size_t status;          /* result from system call */

	//checkpoint_run (false);

	/* Clear the count of errors.  This only applies to a single call to
	   flush_read.  */

	read_error_count = 0;   /* clear error count */

	if (write_archive_to_stdout && record_start_block != 0)
	{
		assert(0);
		/*
		   archive = STDOUT_FILENO;
		   status = sys_write_archive_buffer ();
		   archive = STDIN_FILENO;
		   if (status != record_size)
		   archive_write_error (status);
		 */
	}

	for (;;)
	{
		status = read (archive, record_start->buffer, record_size);
		if (status == record_size)
		{
			records_read++;
			return;
		}

		if (status == -1)
		{
			force_exit_k = 1;
			return;
		}
		break;
	}
	short_read (status);
}

static void
gnu_flush_read (void)
{
	flush_read_ptr = simple_flush_read; /* Avoid recursion */
	_gnu_flush_read ();
	flush_read_ptr = gnu_flush_read;
}


/* Simple flush read (no multi-volume or label extensions) */
static void
simple_flush_read (void)
{
	size_t status;          /* result from system call */

	//checkpoint_run (false);

	/* Clear the count of errors.  This only applies to a single call to
	   flush_read.  */

	read_error_count = 0;   /* clear error count */

	if (write_archive_to_stdout && record_start_block != 0)
	{
		assert(0);
		/*
		   archive = STDOUT_FILENO;
		   status = sys_write_archive_buffer ();
		   archive = STDIN_FILENO;
		   if (status != record_size)
		   archive_write_error (status);
		 */
	}

	for (;;)
	{
		status = read (archive, record_start->buffer, record_size);
		if (status == record_size)
		{
			records_read++;
			return;
		}
		if (status == -1)
		{

			pedro_dprintf(0, "error reading from file, it need to stop working");

			force_exit_k = 1;
			return;
		}
		break;
	}
	short_read (status);
}

static void
gnu_flush_write (size_t buffer_level)
{
	flush_write_ptr = simple_flush_write; /* Avoid recursion */
	_gnu_flush_write (buffer_level);
	flush_write_ptr = gnu_flush_write;
}

void
open_archive (enum access_mode wanted_access)
{
	flush_read_ptr = gnu_flush_read;
	flush_write_ptr = gnu_flush_write;

	_open_archive (wanted_access);

	if(force_exit_k)
	{
		return;
	}

	switch (wanted_access)
	{
	case ACCESS_READ:
	case ACCESS_UPDATE:

#if 0
		if (volume_label_option)
			match_volume_label ();
#endif

		break;

	case ACCESS_WRITE:
		records_written = 0;
#if 0
		if (volume_label_option)
			write_volume_label ();
#endif
		break;
	}
	set_volume_start_time ();
}

void
flush_read (void)
{
	flush_read_ptr ();
}

static void
backspace_output (void)
{
	/*
	 #ifdef MTIOCTOP
	   {
	   struct mtop operation;

	   operation.mt_op = MTBSR;
	   operation.mt_count = 1;
	   if (rmtioctl (archive, MTIOCTOP, (char *) &operation) >= 0)
	   return;
	   if (errno == EIO && rmtioctl (archive, MTIOCTOP, (char *) &operation) >= 0)
	   return;
	   }
	 #endif
	 */

	{
		off_t position = lseek (archive, (off_t) 0, SEEK_CUR);

		/* Seek back to the beginning of this record and start writing there.  */

		position -= record_end->buffer - record_start->buffer;
		if (position < 0)
			position = 0;
		if (lseek (archive, position, SEEK_SET) != position)
		{
			/* Lseek failed.  Try a different method.  */

			pedro_dprintf(0, "Cannot backspace archive file; it may be unreadable without -i");

			/* Replace the first part of the record with NULs.  */

			if (record_start->buffer != output_start)
				memset (record_start->buffer, 0,
				        output_start - record_start->buffer);
		}
	}
}


/*  Flush the current buffer to/from the archive.  */
/*
   void
   flush_archive (void)
   {
        size_t buffer_level;

        if (access_mode == ACCESS_READ && time_to_start_writing)
        {
                access_mode = ACCESS_WRITE;
                time_to_start_writing = false;
                backspace_output ();
                if (record_end - record_start < blocking_factor)
                {
                        memset (record_end, 0,
                                (blocking_factor - (record_end - record_start))
 * BLOCKSIZE);
                        record_end = record_start + blocking_factor;
                        return;
                }
        }

        buffer_level = current_block->buffer - record_start->buffer;
        record_start_block += record_end - record_start;
        current_block = record_start;
        record_end = record_start + blocking_factor;

        switch (access_mode)
        {
        case ACCESS_READ:
                flush_read ();
                break;

        case ACCESS_WRITE:
                flush_write_ptr (buffer_level);
                break;

        case ACCESS_UPDATE:
                abort ();
        }
   }
 */
/*
   union block *
   find_next_block (void)
   {
        if (current_block == record_end)
        {
                if (hit_eof)
                        return 0;
                flush_archive ();
                if (current_block == record_end)
                {
                        hit_eof = true;
                        return 0;
                }
        }
        return current_block;
   }
 */
enum read_header
read_header (union block **return_block, struct tar_stat_info *info,
             enum read_header_mode mode)
{
	union block *header;
	union block *header_copy;
	char *bp;
	union block *data_block;
	size_t size, written;
	union block *next_long_name = 0;
	union block *next_long_link = 0;
	size_t next_long_name_blocks = 0;
	size_t next_long_link_blocks = 0;

	while (1)
	{
		enum read_header status;

		header = find_next_block ();
		*return_block = header;
		if (!header)
			return HEADER_END_OF_FILE;

		if ((status = tar_checksum (header, false)) != HEADER_SUCCESS)
			return status;

		/* Good block.  Decode file size and return.  */

		if (header->header.typeflag == LNKTYPE)
			info->stat.st_size = 0; /* links 0 size on tape */
		else
		{
			info->stat.st_size = OFF_FROM_HEADER (header->header.size);
			if (info->stat.st_size < 0)
				return HEADER_FAILURE;
		}

		if (header->header.typeflag == GNUTYPE_LONGNAME
		    || header->header.typeflag == GNUTYPE_LONGLINK
		    || header->header.typeflag == XHDTYPE
		    || header->header.typeflag == XGLTYPE
		    || header->header.typeflag == SOLARIS_XHDTYPE)
		{
			if (mode == read_header_x_raw)
				return HEADER_SUCCESS_EXTENDED;
			else if (header->header.typeflag == GNUTYPE_LONGNAME
			         || header->header.typeflag == GNUTYPE_LONGLINK)
			{
				size_t name_size = info->stat.st_size;
				size_t n = name_size % BLOCKSIZE;
				size = name_size + BLOCKSIZE;
				if (n)
					size += BLOCKSIZE - n;

				if (name_size != info->stat.st_size || size < name_size)
				{
					force_exit_k = 1;
					return HEADER_FAILURE;
				}

				header_copy = xmalloc (size + 1);

				if (header->header.typeflag == GNUTYPE_LONGNAME)
				{
					free (next_long_name);
					next_long_name = header_copy;
					next_long_name_blocks = size / BLOCKSIZE;
				}
				else
				{
					free (next_long_link);
					next_long_link = header_copy;
					next_long_link_blocks = size / BLOCKSIZE;
				}

				set_next_block_after (header);

				if(force_exit_k)
				{
					return HEADER_FAILURE;
				}

				*header_copy = *header;
				bp = header_copy->buffer + BLOCKSIZE;

				for (size -= BLOCKSIZE; size > 0; size -= written)
				{
					data_block = find_next_block ();
					if (!data_block)
					{
						pedro_dprintf(0, "Unexpected EOF in archive");

						force_exit_k = 1;

						return HEADER_FAILURE;

						break;
					}
					written = available_space_after (data_block);
					if (written > size)
						written = size;

					memcpy (bp, data_block->buffer, written);
					bp += written;
					set_next_block_after ((union block *)
					                      (data_block->buffer + written - 1));

					if(force_exit_k)
					{
						return HEADER_FAILURE;
					}

				}

				*bp = '\0';
			}
			else if (header->header.typeflag == XHDTYPE
			         || header->header.typeflag == SOLARIS_XHDTYPE)
			{
				xheader_read (&info->xhdr, header,
				              OFF_FROM_HEADER (header->header.size));

				if(force_exit_k)
				{
					return HEADER_FAILURE;
				}

			}
			else if (header->header.typeflag == XGLTYPE)
			{
				struct xheader xhdr;

				if (!recent_global_header)
					recent_global_header = xmalloc (sizeof *recent_global_header);
				memcpy (recent_global_header, header,
				        sizeof *recent_global_header);
				memset (&xhdr, 0, sizeof xhdr);
				xheader_read (&xhdr, header,
				              OFF_FROM_HEADER (header->header.size));

				if(force_exit_k)
				{
					return HEADER_FAILURE;
				}

				xheader_decode_global (&xhdr);
				xheader_destroy (&xhdr);
				if (mode == read_header_x_global)
					return HEADER_SUCCESS_EXTENDED;
			}

			/* Loop!  */

		}
		else
		{
			char const *name;
			struct posix_header const *h = &header->header;
			char namebuf[sizeof h->prefix + 1 + NAME_FIELD_SIZE + 1];

			free (recent_long_name);

			if (next_long_name)
			{
				name = next_long_name->buffer + BLOCKSIZE;
				recent_long_name = next_long_name;
				recent_long_name_blocks = next_long_name_blocks;
			}
			else
			{
				/* Accept file names as specified by POSIX.1-1996
				   section 10.1.1.  */
				char *np = namebuf;

				if (h->prefix[0] && strcmp (h->magic, TMAGIC) == 0)
				{
					memcpy (np, h->prefix, sizeof h->prefix);
					np[sizeof h->prefix] = '\0';
					np += strlen (np);
					*np++ = '/';
				}
				memcpy (np, h->name, sizeof h->name);
				np[sizeof h->name] = '\0';
				name = namebuf;
				recent_long_name = 0;
				recent_long_name_blocks = 0;
			}
			assign_string (&info->orig_file_name, name);
			assign_string (&info->file_name, name);
			info->had_trailing_slash = strip_trailing_slashes (info->file_name);

			free (recent_long_link);

			if (next_long_link)
			{
				name = next_long_link->buffer + BLOCKSIZE;
				recent_long_link = next_long_link;
				recent_long_link_blocks = next_long_link_blocks;
			}
			else
			{
				memcpy (namebuf, h->linkname, sizeof h->linkname);
				namebuf[sizeof h->linkname] = '\0';
				name = namebuf;
				recent_long_link = 0;
				recent_long_link_blocks = 0;
			}
			assign_string (&info->link_name, name);

			return HEADER_SUCCESS;
		}
	}
}

void
read_and (void (*do_something)(void))
{
	enum read_header status = HEADER_STILL_UNREAD;
	enum read_header prev_status;
	struct timespec mtime;

	force_exit_k = 0;

	base64_init ();
	name_gather ();

	if(force_exit_k)
	{
		return;
	}

	open_archive (ACCESS_READ);

	if(force_exit_k)
	{
		return;
	}

	do
	{
		prev_status = status;
		tar_stat_destroy (&current_stat_info);

		status = read_header (&current_header, &current_stat_info,
		                      read_header_auto);

		if(force_exit_k)
		{
			return;
		}

		switch (status)
		{
		case HEADER_STILL_UNREAD:
		case HEADER_SUCCESS_EXTENDED:
			abort ();

		case HEADER_SUCCESS:

			/* Valid header.  We should decode next field (mode) first.
			   Ensure incoming names are null terminated.  */
			decode_header (current_header, &current_stat_info,
			               &current_format, 1);
			if (!name_match (current_stat_info.file_name)
			    || (TIME_OPTION_INITIALIZED (newer_mtime_option)
			        /* FIXME: We get mtime now, and again later; this causes
			           duplicate diagnostics if header.mtime is bogus.  */
			        && ((mtime.tv_sec
			                     = TIME_FROM_HEADER (current_header->header.mtime)),
			            /* FIXME: Grab fractional time stamps from
			               extended header.  */
			            mtime.tv_nsec = 0,
			            current_stat_info.mtime = mtime,
			            OLDER_TAR_STAT_TIME (current_stat_info, m)))
			    || excluded_name (current_stat_info.file_name,
			                      current_stat_info.parent))
			{
				switch (current_header->header.typeflag)
				{
				case GNUTYPE_VOLHDR:
				case GNUTYPE_MULTIVOL:
					break;

				case DIRTYPE:
					if (show_omitted_dirs_option)
						WARN ((0, 0, _("%s: Omitting"),
						       quotearg_colon (current_stat_info.file_name)));
					FALLTHROUGH;
				default:
					skip_member ();
					continue;
				}
			}

			transform_stat_info (current_header->header.typeflag,
			                     &current_stat_info);
			(*do_something)();
			continue;

		case HEADER_ZERO_BLOCK:
			if (block_number_option)
			{
				char buf[5000];
				fprintf (stdlis, _("block %s: ** Block of NULs **\n"),
				         STRINGIFY_BIGINT (current_block_ordinal (), buf));
			}

			set_next_block_after (current_header);
			if(force_exit_k)
			{
				return;
			}

			if (!ignore_zeros_option)
			{
				char buf[5000];

				status = read_header (&current_header, &current_stat_info,
				                      read_header_auto);

				if(force_exit_k)
				{
					return;
				}

				if (status == HEADER_ZERO_BLOCK)
					break;
				WARNOPT (WARN_ALONE_ZERO_BLOCK,
				         (0, 0, _("A lone zero block at %s"),
				          STRINGIFY_BIGINT (current_block_ordinal (), buf)));
				break;
			}
			status = prev_status;
			continue;

		case HEADER_END_OF_FILE:
			if (block_number_option)
			{
				char buf[5000];
				fprintf (stdlis, _("block %s: ** End of File **\n"),
				         STRINGIFY_BIGINT (current_block_ordinal (), buf));
			}
			break;

		case HEADER_FAILURE:
			/* If the previous header was good, tell them that we are
			   skipping bad ones.  */
			set_next_block_after (current_header);
			if(force_exit_k)
			{
				return;
			}
			switch (prev_status)
			{
			case HEADER_STILL_UNREAD:
				ERROR ((0, 0, _("This does not look like a tar archive")));
				FALLTHROUGH;
			case HEADER_ZERO_BLOCK:
			case HEADER_SUCCESS:
				if (block_number_option)
				{
					char buf[5000];
					off_t block_ordinal = current_block_ordinal ();
					block_ordinal -= recent_long_name_blocks;
					block_ordinal -= recent_long_link_blocks;
					fprintf (stdlis, _("block %s: "),
					         STRINGIFY_BIGINT (block_ordinal, buf));
				}
				ERROR ((0, 0, _("Skipping to next header")));
				break;

			case HEADER_END_OF_FILE:
			case HEADER_FAILURE:
				/* We are in the middle of a cascade of errors.  */
				break;

			case HEADER_SUCCESS_EXTENDED:
				abort ();
			}
			continue;
		}
		break;
	}
	while (!all_names_found (&current_stat_info));

	close_archive ();
	names_notfound ();      /* print names not found */
}

#ifdef AMANDA_MAIN__

int main()
{

//lembrar de setar para 0 o archive depois de fecha-lo, e de reiniciar todas as variaveis...pode ter memory leaks

	subcommand_option = LIST_SUBCOMMAND;// or EXTRACT_SUBCOMMAND

//lembre-se de checar so o arquivo é "-", ok amor...

//verifuqe oque acontece nesta funcao

//veja excluded em tar.c e veja oque precisa ser inicializado

//reading_from = file_list_name (); //__AMANDA__ procure por mais itens destes para verificar possiveis erros

//precisa testar strip_trailing_slashes
/*
   case EXTRACT_SUBCOMMAND:
      extr_init ();
      read_and (extract_archive);

      // FIXME: should extract_finish () even if an ordinary signal is
         //received.
      extract_finish ();

      break;

    case LIST_SUBCOMMAND:
      read_and (list_archive);
      break;
 */

}

#endif
