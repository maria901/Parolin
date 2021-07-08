#define MBCHAR_BUF_SIZE 24

struct mbchar
{
  const char *ptr;      /* pointer to current character */
  size_t bytes;         /* number of bytes of current character, > 0 */
  bool wc_valid;        /* true if wc is a valid wide character */
  wchar_t wc;           /* if wc_valid: the current character */
  char buf[MBCHAR_BUF_SIZE]; /* room for the bytes, used for file input only */
};

/* EOF (not a real character) is represented with bytes = 0 and
   wc_valid = false.  */

typedef struct mbchar mbchar_t;

/* Access the current character.  */
#define mb_ptr(mbc) ((mbc).ptr)
#define mb_len(mbc) ((mbc).bytes)

/* Comparison of characters.  */
#define mb_iseq(mbc, sc) ((mbc).wc_valid && (mbc).wc == (sc))
#define mb_isnul(mbc) ((mbc).wc_valid && (mbc).wc == 0)
#define mb_cmp(mbc1, mbc2) \
  ((mbc1).wc_valid                                                      \
   ? ((mbc2).wc_valid                                                   \
      ? (int) (mbc1).wc - (int) (mbc2).wc                               \
      : -1)                                                             \
   : ((mbc2).wc_valid                                                   \
      ? 1                                                               \
      : (mbc1).bytes == (mbc2).bytes                                    \
        ? memcmp ((mbc1).ptr, (mbc2).ptr, (mbc1).bytes)                 \
        : (mbc1).bytes < (mbc2).bytes                                   \
          ? (memcmp ((mbc1).ptr, (mbc2).ptr, (mbc1).bytes) > 0 ? 1 : -1) \
          : (memcmp ((mbc1).ptr, (mbc2).ptr, (mbc2).bytes) >= 0 ? 1 : -1)))
#define mb_casecmp(mbc1, mbc2) \
  ((mbc1).wc_valid                                                      \
   ? ((mbc2).wc_valid                                                   \
      ? (int) towlower ((mbc1).wc) - (int) towlower ((mbc2).wc)         \
      : -1)                                                             \
   : ((mbc2).wc_valid                                                   \
      ? 1                                                               \
      : (mbc1).bytes == (mbc2).bytes                                    \
        ? memcmp ((mbc1).ptr, (mbc2).ptr, (mbc1).bytes)                 \
        : (mbc1).bytes < (mbc2).bytes                                   \
          ? (memcmp ((mbc1).ptr, (mbc2).ptr, (mbc1).bytes) > 0 ? 1 : -1) \
          : (memcmp ((mbc1).ptr, (mbc2).ptr, (mbc2).bytes) >= 0 ? 1 : -1)))
#define mb_equal(mbc1, mbc2) \
  ((mbc1).wc_valid && (mbc2).wc_valid                                   \
   ? (mbc1).wc == (mbc2).wc                                             \
   : (mbc1).bytes == (mbc2).bytes                                       \
     && memcmp ((mbc1).ptr, (mbc2).ptr, (mbc1).bytes) == 0)
#define mb_caseequal(mbc1, mbc2) \
  ((mbc1).wc_valid && (mbc2).wc_valid                                   \
   ? towlower ((mbc1).wc) == towlower ((mbc2).wc)                       \
   : (mbc1).bytes == (mbc2).bytes                                       \
     && memcmp ((mbc1).ptr, (mbc2).ptr, (mbc1).bytes) == 0)

/* <ctype.h>, <wctype.h> classification.  */
#define mb_isascii(mbc) \
  ((mbc).wc_valid && (mbc).wc >= 0 && (mbc).wc <= 127)
#define mb_isalnum(mbc) ((mbc).wc_valid && iswalnum ((mbc).wc))
#define mb_isalpha(mbc) ((mbc).wc_valid && iswalpha ((mbc).wc))
#define mb_isblank(mbc) ((mbc).wc_valid && iswblank ((mbc).wc))
#define mb_iscntrl(mbc) ((mbc).wc_valid && iswcntrl ((mbc).wc))
#define mb_isdigit(mbc) ((mbc).wc_valid && iswdigit ((mbc).wc))
#define mb_isgraph(mbc) ((mbc).wc_valid && iswgraph ((mbc).wc))
#define mb_islower(mbc) ((mbc).wc_valid && iswlower ((mbc).wc))
#define mb_isprint(mbc) ((mbc).wc_valid && iswprint ((mbc).wc))
#define mb_ispunct(mbc) ((mbc).wc_valid && iswpunct ((mbc).wc))
#define mb_isspace(mbc) ((mbc).wc_valid && iswspace ((mbc).wc))
#define mb_isupper(mbc) ((mbc).wc_valid && iswupper ((mbc).wc))
#define mb_isxdigit(mbc) ((mbc).wc_valid && iswxdigit ((mbc).wc))

/* Extra <wchar.h> function.  */

/* Unprintable characters appear as a small box of width 1.  */
#define MB_UNPRINTABLE_WIDTH 1







/* Determine a canonical name for the current locale's character encoding.

   Copyright (C) 2000-2006, 2008-2019 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, see <https://www.gnu.org/licenses/>.  */

/* Written by Bruno Haible <bruno@clisp.org>.  */

//#include <config.h>

/* Specification.  */
//#include "localcharset.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if defined __APPLE__ && defined __MACH__ && HAVE_LANGINFO_CODESET
# define DARWIN7 /* Darwin 7 or newer, i.e. Mac OS X 10.3 or newer */
#endif

#if defined _WIN32 && !defined __CYGWIN__
# define WINDOWS_NATIVE
# include <locale.h>
#endif

#if defined __EMX__
/* Assume EMX program runs on OS/2, even if compiled under DOS.  */
# ifndef OS2
#  define OS2
# endif
#endif

#if !defined WINDOWS_NATIVE
# if HAVE_LANGINFO_CODESET
#  include <langinfo.h>
# else
#  if 0 /* see comment regarding use of setlocale(), below */
#   include <locale.h>
#  endif
# endif
# ifdef __CYGWIN__
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
# endif
#elif defined WINDOWS_NATIVE
# define WIN32_LEAN_AND_MEAN
# include <windows.h>
#endif
#if defined OS2
# define INCL_DOS
# include <os2.h>
#endif

/* For MB_CUR_MAX_L */
#if defined DARWIN7
# include <xlocale.h>
#endif


#if HAVE_LANGINFO_CODESET || defined WINDOWS_NATIVE || defined OS2

/* On these platforms, we use a mapping from non-canonical encoding name
   to GNU canonical encoding name.  */

/* With glibc-2.1 or newer, we don't need any canonicalization,
   because glibc has iconv and both glibc and libiconv support all
   GNU canonical names directly.  */
# if !((defined __GNU_LIBRARY__ && __GLIBC__ >= 2) || defined __UCLIBC__)

struct table_entry
{
  const char alias[11+1];
  const char canonical[11+1];
};

/* Table of platform-dependent mappings, sorted in ascending order.  */
static const struct table_entry alias_table[] =
  {
#  if defined __FreeBSD__                                   /* FreeBSD */
  /*{ "ARMSCII-8",  "ARMSCII-8" },*/
    { "Big5",       "BIG5" },
    { "C",          "ASCII" },
  /*{ "CP1131",     "CP1131" },*/
  /*{ "CP1251",     "CP1251" },*/
  /*{ "CP866",      "CP866" },*/
  /*{ "GB18030",    "GB18030" },*/
  /*{ "GB2312",     "GB2312" },*/
  /*{ "GBK",        "GBK" },*/
  /*{ "ISCII-DEV",  "?" },*/
    { "ISO8859-1",  "ISO-8859-1" },
    { "ISO8859-13", "ISO-8859-13" },
    { "ISO8859-15", "ISO-8859-15" },
    { "ISO8859-2",  "ISO-8859-2" },
    { "ISO8859-5",  "ISO-8859-5" },
    { "ISO8859-7",  "ISO-8859-7" },
    { "ISO8859-9",  "ISO-8859-9" },
  /*{ "KOI8-R",     "KOI8-R" },*/
  /*{ "KOI8-U",     "KOI8-U" },*/
    { "SJIS",       "SHIFT_JIS" },
    { "US-ASCII",   "ASCII" },
    { "eucCN",      "GB2312" },
    { "eucJP",      "EUC-JP" },
    { "eucKR",      "EUC-KR" }
#   define alias_table_defined
#  endif
#  if defined __NetBSD__                                    /* NetBSD */
    { "646",        "ASCII" },
  /*{ "ARMSCII-8",  "ARMSCII-8" },*/
  /*{ "BIG5",       "BIG5" },*/
    { "Big5-HKSCS", "BIG5-HKSCS" },
  /*{ "CP1251",     "CP1251" },*/
  /*{ "CP866",      "CP866" },*/
  /*{ "GB18030",    "GB18030" },*/
  /*{ "GB2312",     "GB2312" },*/
    { "ISO8859-1",  "ISO-8859-1" },
    { "ISO8859-13", "ISO-8859-13" },
    { "ISO8859-15", "ISO-8859-15" },
    { "ISO8859-2",  "ISO-8859-2" },
    { "ISO8859-4",  "ISO-8859-4" },
    { "ISO8859-5",  "ISO-8859-5" },
    { "ISO8859-7",  "ISO-8859-7" },
  /*{ "KOI8-R",     "KOI8-R" },*/
  /*{ "KOI8-U",     "KOI8-U" },*/
  /*{ "PT154",      "PT154" },*/
    { "SJIS",       "SHIFT_JIS" },
    { "eucCN",      "GB2312" },
    { "eucJP",      "EUC-JP" },
    { "eucKR",      "EUC-KR" },
    { "eucTW",      "EUC-TW" }
#   define alias_table_defined
#  endif
#  if defined __OpenBSD__                                   /* OpenBSD */
    { "646",        "ASCII" },
    { "ISO8859-1",  "ISO-8859-1" },
    { "ISO8859-13", "ISO-8859-13" },
    { "ISO8859-15", "ISO-8859-15" },
    { "ISO8859-2",  "ISO-8859-2" },
    { "ISO8859-4",  "ISO-8859-4" },
    { "ISO8859-5",  "ISO-8859-5" },
    { "ISO8859-7",  "ISO-8859-7" }
#   define alias_table_defined
#  endif
#  if defined __APPLE__ && defined __MACH__                 /* Mac OS X */
    /* Darwin 7.5 has nl_langinfo(CODESET), but sometimes its value is
       useless:
       - It returns the empty string when LANG is set to a locale of the
         form ll_CC, although ll_CC/LC_CTYPE is a symlink to an UTF-8
         LC_CTYPE file.
       - The environment variables LANG, LC_CTYPE, LC_ALL are not set by
         the system; nl_langinfo(CODESET) returns "US-ASCII" in this case.
       - The documentation says:
           "... all code that calls BSD system routines should ensure
            that the const *char parameters of these routines are in UTF-8
            encoding. All BSD system functions expect their string
            parameters to be in UTF-8 encoding and nothing else."
         It also says
           "An additional caveat is that string parameters for files,
            paths, and other file-system entities must be in canonical
            UTF-8. In a canonical UTF-8 Unicode string, all decomposable
            characters are decomposed ..."
         but this is not true: You can pass non-decomposed UTF-8 strings
         to file system functions, and it is the OS which will convert
         them to decomposed UTF-8 before accessing the file system.
       - The Apple Terminal application displays UTF-8 by default.
       - However, other applications are free to use different encodings:
         - xterm uses ISO-8859-1 by default.
         - TextEdit uses MacRoman by default.
       We prefer UTF-8 over decomposed UTF-8-MAC because one should
       minimize the use of decomposed Unicode. Unfortunately, through the
       Darwin file system, decomposed UTF-8 strings are leaked into user
       space nevertheless.
       Then there are also the locales with encodings other than US-ASCII
       and UTF-8. These locales can be occasionally useful to users (e.g.
       when grepping through ISO-8859-1 encoded text files), when all their
       file names are in US-ASCII.
     */
    { "ARMSCII-8",  "ARMSCII-8" },
    { "Big5",       "BIG5" },
    { "Big5HKSCS",  "BIG5-HKSCS" },
    { "CP1131",     "CP1131" },
    { "CP1251",     "CP1251" },
    { "CP866",      "CP866" },
    { "CP949",      "CP949" },
    { "GB18030",    "GB18030" },
    { "GB2312",     "GB2312" },
    { "GBK",        "GBK" },
  /*{ "ISCII-DEV",  "?" },*/
    { "ISO8859-1",  "ISO-8859-1" },
    { "ISO8859-13", "ISO-8859-13" },
    { "ISO8859-15", "ISO-8859-15" },
    { "ISO8859-2",  "ISO-8859-2" },
    { "ISO8859-4",  "ISO-8859-4" },
    { "ISO8859-5",  "ISO-8859-5" },
    { "ISO8859-7",  "ISO-8859-7" },
    { "ISO8859-9",  "ISO-8859-9" },
    { "KOI8-R",     "KOI8-R" },
    { "KOI8-U",     "KOI8-U" },
    { "PT154",      "PT154" },
    { "SJIS",       "SHIFT_JIS" },
    { "eucCN",      "GB2312" },
    { "eucJP",      "EUC-JP" },
    { "eucKR",      "EUC-KR" }
#   define alias_table_defined
#  endif
#  if defined _AIX                                          /* AIX */
  /*{ "GBK",        "GBK" },*/
    { "IBM-1046",   "CP1046" },
    { "IBM-1124",   "CP1124" },
    { "IBM-1129",   "CP1129" },
    { "IBM-1252",   "CP1252" },
    { "IBM-850",    "CP850" },
    { "IBM-856",    "CP856" },
    { "IBM-921",    "ISO-8859-13" },
    { "IBM-922",    "CP922" },
    { "IBM-932",    "CP932" },
    { "IBM-943",    "CP943" },
    { "IBM-eucCN",  "GB2312" },
    { "IBM-eucJP",  "EUC-JP" },
    { "IBM-eucKR",  "EUC-KR" },
    { "IBM-eucTW",  "EUC-TW" },
    { "ISO8859-1",  "ISO-8859-1" },
    { "ISO8859-15", "ISO-8859-15" },
    { "ISO8859-2",  "ISO-8859-2" },
    { "ISO8859-5",  "ISO-8859-5" },
    { "ISO8859-6",  "ISO-8859-6" },
    { "ISO8859-7",  "ISO-8859-7" },
    { "ISO8859-8",  "ISO-8859-8" },
    { "ISO8859-9",  "ISO-8859-9" },
    { "TIS-620",    "TIS-620" },
  /*{ "UTF-8",      "UTF-8" },*/
    { "big5",       "BIG5" }
#   define alias_table_defined
#  endif
#  if defined __hpux                                        /* HP-UX */
    { "SJIS",      "SHIFT_JIS" },
    { "arabic8",   "HP-ARABIC8" },
    { "big5",      "BIG5" },
    { "cp1251",    "CP1251" },
    { "eucJP",     "EUC-JP" },
    { "eucKR",     "EUC-KR" },
    { "eucTW",     "EUC-TW" },
    { "gb18030",   "GB18030" },
    { "greek8",    "HP-GREEK8" },
    { "hebrew8",   "HP-HEBREW8" },
    { "hkbig5",    "BIG5-HKSCS" },
    { "hp15CN",    "GB2312" },
    { "iso88591",  "ISO-8859-1" },
    { "iso885913", "ISO-8859-13" },
    { "iso885915", "ISO-8859-15" },
    { "iso88592",  "ISO-8859-2" },
    { "iso88594",  "ISO-8859-4" },
    { "iso88595",  "ISO-8859-5" },
    { "iso88596",  "ISO-8859-6" },
    { "iso88597",  "ISO-8859-7" },
    { "iso88598",  "ISO-8859-8" },
    { "iso88599",  "ISO-8859-9" },
    { "kana8",     "HP-KANA8" },
    { "koi8r",     "KOI8-R" },
    { "roman8",    "HP-ROMAN8" },
    { "tis620",    "TIS-620" },
    { "turkish8",  "HP-TURKISH8" },
    { "utf8",      "UTF-8" }
#   define alias_table_defined
#  endif
#  if defined __sgi                                         /* IRIX */
    { "ISO8859-1",  "ISO-8859-1" },
    { "ISO8859-15", "ISO-8859-15" },
    { "ISO8859-2",  "ISO-8859-2" },
    { "ISO8859-5",  "ISO-8859-5" },
    { "ISO8859-7",  "ISO-8859-7" },
    { "ISO8859-9",  "ISO-8859-9" },
    { "eucCN",      "GB2312" },
    { "eucJP",      "EUC-JP" },
    { "eucKR",      "EUC-KR" },
    { "eucTW",      "EUC-TW" }
#   define alias_table_defined
#  endif
#  if defined __osf__                                       /* OSF/1 */
  /*{ "GBK",        "GBK" },*/
    { "ISO8859-1",  "ISO-8859-1" },
    { "ISO8859-15", "ISO-8859-15" },
    { "ISO8859-2",  "ISO-8859-2" },
    { "ISO8859-4",  "ISO-8859-4" },
    { "ISO8859-5",  "ISO-8859-5" },
    { "ISO8859-7",  "ISO-8859-7" },
    { "ISO8859-8",  "ISO-8859-8" },
    { "ISO8859-9",  "ISO-8859-9" },
    { "KSC5601",    "CP949" },
    { "SJIS",       "SHIFT_JIS" },
    { "TACTIS",     "TIS-620" },
  /*{ "UTF-8",      "UTF-8" },*/
    { "big5",       "BIG5" },
    { "cp850",      "CP850" },
    { "dechanyu",   "DEC-HANYU" },
    { "dechanzi",   "GB2312" },
    { "deckanji",   "DEC-KANJI" },
    { "deckorean",  "EUC-KR" },
    { "eucJP",      "EUC-JP" },
    { "eucKR",      "EUC-KR" },
    { "eucTW",      "EUC-TW" },
    { "sdeckanji",  "EUC-JP" }
#   define alias_table_defined
#  endif
#  if defined __sun                                         /* Solaris */
    { "5601",        "EUC-KR" },
    { "646",         "ASCII" },
  /*{ "BIG5",        "BIG5" },*/
    { "Big5-HKSCS",  "BIG5-HKSCS" },
    { "GB18030",     "GB18030" },
  /*{ "GBK",         "GBK" },*/
    { "ISO8859-1",   "ISO-8859-1" },
    { "ISO8859-11",  "TIS-620" },
    { "ISO8859-13",  "ISO-8859-13" },
    { "ISO8859-15",  "ISO-8859-15" },
    { "ISO8859-2",   "ISO-8859-2" },
    { "ISO8859-3",   "ISO-8859-3" },
    { "ISO8859-4",   "ISO-8859-4" },
    { "ISO8859-5",   "ISO-8859-5" },
    { "ISO8859-6",   "ISO-8859-6" },
    { "ISO8859-7",   "ISO-8859-7" },
    { "ISO8859-8",   "ISO-8859-8" },
    { "ISO8859-9",   "ISO-8859-9" },
    { "PCK",         "SHIFT_JIS" },
    { "TIS620.2533", "TIS-620" },
  /*{ "UTF-8",       "UTF-8" },*/
    { "ansi-1251",   "CP1251" },
    { "cns11643",    "EUC-TW" },
    { "eucJP",       "EUC-JP" },
    { "gb2312",      "GB2312" },
    { "koi8-r",      "KOI8-R" }
#   define alias_table_defined
#  endif
#  if defined __minix                                       /* Minix */
    { "646", "ASCII" }
#   define alias_table_defined
#  endif
#  if defined WINDOWS_NATIVE || defined __CYGWIN__          /* Windows */
    { "CP1361",  "JOHAB" },
    { "CP20127", "ASCII" },
    { "CP20866", "KOI8-R" },
    { "CP20936", "GB2312" },
    { "CP21866", "KOI8-RU" },
    { "CP28591", "ISO-8859-1" },
    { "CP28592", "ISO-8859-2" },
    { "CP28593", "ISO-8859-3" },
    { "CP28594", "ISO-8859-4" },
    { "CP28595", "ISO-8859-5" },
    { "CP28596", "ISO-8859-6" },
    { "CP28597", "ISO-8859-7" },
    { "CP28598", "ISO-8859-8" },
    { "CP28599", "ISO-8859-9" },
    { "CP28605", "ISO-8859-15" },
    { "CP38598", "ISO-8859-8" },
    { "CP51932", "EUC-JP" },
    { "CP51936", "GB2312" },
    { "CP51949", "EUC-KR" },
    { "CP51950", "EUC-TW" },
    { "CP54936", "GB18030" },
    { "CP65001", "UTF-8" },
    { "CP936",   "GBK" }
#   define alias_table_defined
#  endif
#  if defined OS2                                           /* OS/2 */
    /* The list of encodings is taken from "List of OS/2 Codepages"
       by Alex Taylor:
       <http://altsan.org/os2/toolkits/uls/index.html#codepages>.
       See also "IBM Globalization - Code page identifiers":
       <https://www-01.ibm.com/software/globalization/cp/cp_cpgid.html>.  */
    { "CP1089", "ISO-8859-6" },
    { "CP1208", "UTF-8" },
    { "CP1381", "GB2312" },
    { "CP1386", "GBK" },
    { "CP3372", "EUC-JP" },
    { "CP813",  "ISO-8859-7" },
    { "CP819",  "ISO-8859-1" },
    { "CP878",  "KOI8-R" },
    { "CP912",  "ISO-8859-2" },
    { "CP913",  "ISO-8859-3" },
    { "CP914",  "ISO-8859-4" },
    { "CP915",  "ISO-8859-5" },
    { "CP916",  "ISO-8859-8" },
    { "CP920",  "ISO-8859-9" },
    { "CP921",  "ISO-8859-13" },
    { "CP923",  "ISO-8859-15" },
    { "CP954",  "EUC-JP" },
    { "CP964",  "EUC-TW" },
    { "CP970",  "EUC-KR" }
#   define alias_table_defined
#  endif
#  if defined VMS                                           /* OpenVMS */
    /* The list of encodings is taken from the OpenVMS 7.3-1 documentation
       "Compaq C Run-Time Library Reference Manual for OpenVMS systems"
       section 10.7 "Handling Different Character Sets".  */
    { "DECHANYU",  "DEC-HANYU" },
    { "DECHANZI",  "GB2312" },
    { "DECKANJI",  "DEC-KANJI" },
    { "DECKOREAN", "EUC-KR" },
    { "ISO8859-1", "ISO-8859-1" },
    { "ISO8859-2", "ISO-8859-2" },
    { "ISO8859-5", "ISO-8859-5" },
    { "ISO8859-7", "ISO-8859-7" },
    { "ISO8859-8", "ISO-8859-8" },
    { "ISO8859-9", "ISO-8859-9" },
    { "SDECKANJI", "EUC-JP" },
    { "SJIS",      "SHIFT_JIS" },
    { "eucJP",     "EUC-JP" },
    { "eucTW",     "EUC-TW" }
#   define alias_table_defined
#  endif
#  ifndef alias_table_defined
    /* Just a dummy entry, to avoid a C syntax error.  */
    { "", "" }
#  endif
  };

# endif

#else

/* On these platforms, we use a mapping from locale name to GNU canonical
   encoding name.  */

struct table_entry
{
  const char locale[17+1];
  const char canonical[11+1];
};

/* Table of platform-dependent mappings, sorted in ascending order.  */
static const struct table_entry locale_table[] =
  {
# if defined __FreeBSD__                                    /* FreeBSD 4.2 */
    { "cs_CZ.ISO_8859-2",  "ISO-8859-2" },
    { "da_DK.DIS_8859-15", "ISO-8859-15" },
    { "da_DK.ISO_8859-1",  "ISO-8859-1" },
    { "de_AT.DIS_8859-15", "ISO-8859-15" },
    { "de_AT.ISO_8859-1",  "ISO-8859-1" },
    { "de_CH.DIS_8859-15", "ISO-8859-15" },
    { "de_CH.ISO_8859-1",  "ISO-8859-1" },
    { "de_DE.DIS_8859-15", "ISO-8859-15" },
    { "de_DE.ISO_8859-1",  "ISO-8859-1" },
    { "en_AU.DIS_8859-15", "ISO-8859-15" },
    { "en_AU.ISO_8859-1",  "ISO-8859-1" },
    { "en_CA.DIS_8859-15", "ISO-8859-15" },
    { "en_CA.ISO_8859-1",  "ISO-8859-1" },
    { "en_GB.DIS_8859-15", "ISO-8859-15" },
    { "en_GB.ISO_8859-1",  "ISO-8859-1" },
    { "en_US.DIS_8859-15", "ISO-8859-15" },
    { "en_US.ISO_8859-1",  "ISO-8859-1" },
    { "es_ES.DIS_8859-15", "ISO-8859-15" },
    { "es_ES.ISO_8859-1",  "ISO-8859-1" },
    { "fi_FI.DIS_8859-15", "ISO-8859-15" },
    { "fi_FI.ISO_8859-1",  "ISO-8859-1" },
    { "fr_BE.DIS_8859-15", "ISO-8859-15" },
    { "fr_BE.ISO_8859-1",  "ISO-8859-1" },
    { "fr_CA.DIS_8859-15", "ISO-8859-15" },
    { "fr_CA.ISO_8859-1",  "ISO-8859-1" },
    { "fr_CH.DIS_8859-15", "ISO-8859-15" },
    { "fr_CH.ISO_8859-1",  "ISO-8859-1" },
    { "fr_FR.DIS_8859-15", "ISO-8859-15" },
    { "fr_FR.ISO_8859-1",  "ISO-8859-1" },
    { "hr_HR.ISO_8859-2",  "ISO-8859-2" },
    { "hu_HU.ISO_8859-2",  "ISO-8859-2" },
    { "is_IS.DIS_8859-15", "ISO-8859-15" },
    { "is_IS.ISO_8859-1",  "ISO-8859-1" },
    { "it_CH.DIS_8859-15", "ISO-8859-15" },
    { "it_CH.ISO_8859-1",  "ISO-8859-1" },
    { "it_IT.DIS_8859-15", "ISO-8859-15" },
    { "it_IT.ISO_8859-1",  "ISO-8859-1" },
    { "ja_JP.EUC",         "EUC-JP" },
    { "ja_JP.SJIS",        "SHIFT_JIS" },
    { "ja_JP.Shift_JIS",   "SHIFT_JIS" },
    { "ko_KR.EUC",         "EUC-KR" },
    { "la_LN.ASCII",       "ASCII" },
    { "la_LN.DIS_8859-15", "ISO-8859-15" },
    { "la_LN.ISO_8859-1",  "ISO-8859-1" },
    { "la_LN.ISO_8859-2",  "ISO-8859-2" },
    { "la_LN.ISO_8859-4",  "ISO-8859-4" },
    { "lt_LN.ASCII",       "ASCII" },
    { "lt_LN.DIS_8859-15", "ISO-8859-15" },
    { "lt_LN.ISO_8859-1",  "ISO-8859-1" },
    { "lt_LN.ISO_8859-2",  "ISO-8859-2" },
    { "lt_LT.ISO_8859-4",  "ISO-8859-4" },
    { "nl_BE.DIS_8859-15", "ISO-8859-15" },
    { "nl_BE.ISO_8859-1",  "ISO-8859-1" },
    { "nl_NL.DIS_8859-15", "ISO-8859-15" },
    { "nl_NL.ISO_8859-1",  "ISO-8859-1" },
    { "no_NO.DIS_8859-15", "ISO-8859-15" },
    { "no_NO.ISO_8859-1",  "ISO-8859-1" },
    { "pl_PL.ISO_8859-2",  "ISO-8859-2" },
    { "pt_PT.DIS_8859-15", "ISO-8859-15" },
    { "pt_PT.ISO_8859-1",  "ISO-8859-1" },
    { "ru_RU.CP866",       "CP866" },
    { "ru_RU.ISO_8859-5",  "ISO-8859-5" },
    { "ru_RU.KOI8-R",      "KOI8-R" },
    { "ru_SU.CP866",       "CP866" },
    { "ru_SU.ISO_8859-5",  "ISO-8859-5" },
    { "ru_SU.KOI8-R",      "KOI8-R" },
    { "sl_SI.ISO_8859-2",  "ISO-8859-2" },
    { "sv_SE.DIS_8859-15", "ISO-8859-15" },
    { "sv_SE.ISO_8859-1",  "ISO-8859-1" },
    { "uk_UA.KOI8-U",      "KOI8-U" },
    { "zh_CN.EUC",         "GB2312" },
    { "zh_TW.BIG5",        "BIG5" },
    { "zh_TW.Big5",        "BIG5" }
#  define locale_table_defined
# endif
# if defined __DJGPP__                                      /* DOS / DJGPP 2.03 */
    /* The encodings given here may not all be correct.
       If you find that the encoding given for your language and
       country is not the one your DOS machine actually uses, just
       correct it in this file, and send a mail to
       Juan Manuel Guerrero <juan.guerrero@gmx.de>
       and <bug-gnulib@gnu.org>.  */
    { "C",     "ASCII" },
    { "ar",    "CP864" },
    { "ar_AE", "CP864" },
    { "ar_DZ", "CP864" },
    { "ar_EG", "CP864" },
    { "ar_IQ", "CP864" },
    { "ar_IR", "CP864" },
    { "ar_JO", "CP864" },
    { "ar_KW", "CP864" },
    { "ar_MA", "CP864" },
    { "ar_OM", "CP864" },
    { "ar_QA", "CP864" },
    { "ar_SA", "CP864" },
    { "ar_SY", "CP864" },
    { "be",    "CP866" },
    { "be_BE", "CP866" },
    { "bg",    "CP866" }, /* not CP855 ?? */
    { "bg_BG", "CP866" }, /* not CP855 ?? */
    { "ca",    "CP850" },
    { "ca_ES", "CP850" },
    { "cs",    "CP852" },
    { "cs_CZ", "CP852" },
    { "da",    "CP865" }, /* not CP850 ?? */
    { "da_DK", "CP865" }, /* not CP850 ?? */
    { "de",    "CP850" },
    { "de_AT", "CP850" },
    { "de_CH", "CP850" },
    { "de_DE", "CP850" },
    { "el",    "CP869" },
    { "el_GR", "CP869" },
    { "en",    "CP850" },
    { "en_AU", "CP850" }, /* not CP437 ?? */
    { "en_CA", "CP850" },
    { "en_GB", "CP850" },
    { "en_NZ", "CP437" },
    { "en_US", "CP437" },
    { "en_ZA", "CP850" }, /* not CP437 ?? */
    { "eo",    "CP850" },
    { "eo_EO", "CP850" },
    { "es",    "CP850" },
    { "es_AR", "CP850" },
    { "es_BO", "CP850" },
    { "es_CL", "CP850" },
    { "es_CO", "CP850" },
    { "es_CR", "CP850" },
    { "es_CU", "CP850" },
    { "es_DO", "CP850" },
    { "es_EC", "CP850" },
    { "es_ES", "CP850" },
    { "es_GT", "CP850" },
    { "es_HN", "CP850" },
    { "es_MX", "CP850" },
    { "es_NI", "CP850" },
    { "es_PA", "CP850" },
    { "es_PE", "CP850" },
    { "es_PY", "CP850" },
    { "es_SV", "CP850" },
    { "es_UY", "CP850" },
    { "es_VE", "CP850" },
    { "et",    "CP850" },
    { "et_EE", "CP850" },
    { "eu",    "CP850" },
    { "eu_ES", "CP850" },
    { "fi",    "CP850" },
    { "fi_FI", "CP850" },
    { "fr",    "CP850" },
    { "fr_BE", "CP850" },
    { "fr_CA", "CP850" },
    { "fr_CH", "CP850" },
    { "fr_FR", "CP850" },
    { "ga",    "CP850" },
    { "ga_IE", "CP850" },
    { "gd",    "CP850" },
    { "gd_GB", "CP850" },
    { "gl",    "CP850" },
    { "gl_ES", "CP850" },
    { "he",    "CP862" },
    { "he_IL", "CP862" },
    { "hr",    "CP852" },
    { "hr_HR", "CP852" },
    { "hu",    "CP852" },
    { "hu_HU", "CP852" },
    { "id",    "CP850" }, /* not CP437 ?? */
    { "id_ID", "CP850" }, /* not CP437 ?? */
    { "is",    "CP861" }, /* not CP850 ?? */
    { "is_IS", "CP861" }, /* not CP850 ?? */
    { "it",    "CP850" },
    { "it_CH", "CP850" },
    { "it_IT", "CP850" },
    { "ja",    "CP932" },
    { "ja_JP", "CP932" },
    { "kr",    "CP949" }, /* not CP934 ?? */
    { "kr_KR", "CP949" }, /* not CP934 ?? */
    { "lt",    "CP775" },
    { "lt_LT", "CP775" },
    { "lv",    "CP775" },
    { "lv_LV", "CP775" },
    { "mk",    "CP866" }, /* not CP855 ?? */
    { "mk_MK", "CP866" }, /* not CP855 ?? */
    { "mt",    "CP850" },
    { "mt_MT", "CP850" },
    { "nb",    "CP865" }, /* not CP850 ?? */
    { "nb_NO", "CP865" }, /* not CP850 ?? */
    { "nl",    "CP850" },
    { "nl_BE", "CP850" },
    { "nl_NL", "CP850" },
    { "nn",    "CP865" }, /* not CP850 ?? */
    { "nn_NO", "CP865" }, /* not CP850 ?? */
    { "no",    "CP865" }, /* not CP850 ?? */
    { "no_NO", "CP865" }, /* not CP850 ?? */
    { "pl",    "CP852" },
    { "pl_PL", "CP852" },
    { "pt",    "CP850" },
    { "pt_BR", "CP850" },
    { "pt_PT", "CP850" },
    { "ro",    "CP852" },
    { "ro_RO", "CP852" },
    { "ru",    "CP866" },
    { "ru_RU", "CP866" },
    { "sk",    "CP852" },
    { "sk_SK", "CP852" },
    { "sl",    "CP852" },
    { "sl_SI", "CP852" },
    { "sq",    "CP852" },
    { "sq_AL", "CP852" },
    { "sr",    "CP852" }, /* CP852 or CP866 or CP855 ?? */
    { "sr_CS", "CP852" }, /* CP852 or CP866 or CP855 ?? */
    { "sr_YU", "CP852" }, /* CP852 or CP866 or CP855 ?? */
    { "sv",    "CP850" },
    { "sv_SE", "CP850" },
    { "th",    "CP874" },
    { "th_TH", "CP874" },
    { "tr",    "CP857" },
    { "tr_TR", "CP857" },
    { "uk",    "CP1125" },
    { "uk_UA", "CP1125" },
    { "zh_CN", "GBK" },
    { "zh_TW", "CP950" } /* not CP938 ?? */
#  define locale_table_defined
# endif
# ifndef locale_table_defined
    /* Just a dummy entry, to avoid a C syntax error.  */
    { "", "" }
# endif
  };

#endif


/* Determine the current locale's character encoding, and canonicalize it
   into one of the canonical names listed in localcharset.h.
   The result must not be freed; it is statically allocated.
   If the canonical name cannot be determined, the result is a non-canonical
   name.  */

#ifdef STATIC
STATIC
#endif
const char *
locale_charset (void)
{
  const char *codeset;

#if HAVE_LANGINFO_CODESET || defined WINDOWS_NATIVE || defined OS2

# if HAVE_LANGINFO_CODESET

  /* Most systems support nl_langinfo (CODESET) nowadays.  */
  codeset = nl_langinfo (CODESET);

#  ifdef __CYGWIN__
  /* Cygwin < 1.7 does not have locales.  nl_langinfo (CODESET) always
     returns "US-ASCII".  Return the suffix of the locale name from the
     environment variables (if present) or the codepage as a number.  */
  if (codeset != NULL && strcmp (codeset, "US-ASCII") == 0)
    {
      const char *locale;
      static char buf[2 + 10 + 1];

      locale = getenv ("LC_ALL");
      if (locale == NULL || locale[0] == '\0')
        {
          locale = getenv ("LC_CTYPE");
          if (locale == NULL || locale[0] == '\0')
            locale = getenv ("LANG");
        }
      if (locale != NULL && locale[0] != '\0')
        {
          /* If the locale name contains an encoding after the dot, return
             it.  */
          const char *dot = strchr (locale, '.');

          if (dot != NULL)
            {
              const char *modifier;

              dot++;
              /* Look for the possible @... trailer and remove it, if any.  */
              modifier = strchr (dot, '@');
              if (modifier == NULL)
                return dot;
              if (modifier - dot < sizeof (buf))
                {
                  memcpy (buf, dot, modifier - dot);
                  buf [modifier - dot] = '\0';
                  return buf;
                }
            }
        }

      /* The Windows API has a function returning the locale's codepage as a
         number: GetACP().  This encoding is used by Cygwin, unless the user
         has set the environment variable CYGWIN=codepage:oem (which very few
         people do).
         Output directed to console windows needs to be converted (to
         GetOEMCP() if the console is using a raster font, or to
         GetConsoleOutputCP() if it is using a TrueType font).  Cygwin does
         this conversion transparently (see winsup/cygwin/fhandler_console.cc),
         converting to GetConsoleOutputCP().  This leads to correct results,
         except when SetConsoleOutputCP has been called and a raster font is
         in use.  */
      sprintf (buf, "CP%u", GetACP ());
      codeset = buf;
    }
#  endif

  if (codeset == NULL)
    /* The canonical name cannot be determined.  */
    codeset = "";

# elif defined WINDOWS_NATIVE

  static char buf[2 + 10 + 1];

  /* The Windows API has a function returning the locale's codepage as
     a number, but the value doesn't change according to what the
     'setlocale' call specified.  So we use it as a last resort, in
     case the string returned by 'setlocale' doesn't specify the
     codepage.  */
  char *current_locale = setlocale (LC_ALL, NULL);
  char *pdot;

  /* If they set different locales for different categories,
     'setlocale' will return a semi-colon separated list of locale
     values.  To make sure we use the correct one, we choose LC_CTYPE.  */
  if (strchr (current_locale, ';'))
    current_locale = setlocale (LC_CTYPE, NULL);

  pdot = strrchr (current_locale, '.');
  if (pdot && 2 + strlen (pdot + 1) + 1 <= sizeof (buf))
    sprintf (buf, "CP%s", pdot + 1);
  else
    {
      /* The Windows API has a function returning the locale's codepage as a
        number: GetACP().
        When the output goes to a console window, it needs to be provided in
        GetOEMCP() encoding if the console is using a raster font, or in
        GetConsoleOutputCP() encoding if it is using a TrueType font.
        But in GUI programs and for output sent to files and pipes, GetACP()
        encoding is the best bet.  */
      sprintf (buf, "CP%u", GetACP ());
    }
  codeset = buf;

# elif defined OS2

  const char *locale;
  static char buf[2 + 10 + 1];
  ULONG cp[3];
  ULONG cplen;

  codeset = NULL;

  /* Allow user to override the codeset, as set in the operating system,
     with standard language environment variables.  */
  locale = getenv ("LC_ALL");
  if (locale == NULL || locale[0] == '\0')
    {
      locale = getenv ("LC_CTYPE");
      if (locale == NULL || locale[0] == '\0')
        locale = getenv ("LANG");
    }
  if (locale != NULL && locale[0] != '\0')
    {
      /* If the locale name contains an encoding after the dot, return it.  */
      const char *dot = strchr (locale, '.');

      if (dot != NULL)
        {
          const char *modifier;

          dot++;
          /* Look for the possible @... trailer and remove it, if any.  */
          modifier = strchr (dot, '@');
          if (modifier == NULL)
            return dot;
          if (modifier - dot < sizeof (buf))
            {
              memcpy (buf, dot, modifier - dot);
              buf [modifier - dot] = '\0';
              return buf;
            }
        }

      /* For the POSIX locale, don't use the system's codepage.  */
      if (strcmp (locale, "C") == 0 || strcmp (locale, "POSIX") == 0)
        codeset = "";
    }

  if (codeset == NULL)
    {
      /* OS/2 has a function returning the locale's codepage as a number.  */
      if (DosQueryCp (sizeof (cp), cp, &cplen))
        codeset = "";
      else
        {
          sprintf (buf, "CP%u", cp[0]);
          codeset = buf;
        }
    }

# else

#  error "Add code for other platforms here."

# endif

  /* Resolve alias.  */
  {
# ifdef alias_table_defined
    /* On some platforms, UTF-8 locales are the most frequently used ones.
       Speed up the common case and slow down the less common cases by
       testing for this case first.  */
#  if defined __OpenBSD__ || (defined __APPLE__ && defined __MACH__) || defined __sun || defined __CYGWIN__
    if (strcmp (codeset, "UTF-8") == 0)
      goto done_table_lookup;
    else
#  endif
      {
        const struct table_entry * const table = alias_table;
        size_t const table_size =
          sizeof (alias_table) / sizeof (struct table_entry);
        /* The table is sorted.  Perform a binary search.  */
        size_t hi = table_size;
        size_t lo = 0;
        while (lo < hi)
          {
            /* Invariant:
               for i < lo, strcmp (table[i].alias, codeset) < 0,
               for i >= hi, strcmp (table[i].alias, codeset) > 0.  */
            size_t mid = (hi + lo) >> 1; /* >= lo, < hi */
            int cmp = strcmp (table[mid].alias, codeset);
            if (cmp < 0)
              lo = mid + 1;
            else if (cmp > 0)
              hi = mid;
            else
              {
                /* Found an i with
                     strcmp (table[i].alias, codeset) == 0.  */
                codeset = table[mid].canonical;
                goto done_table_lookup;
              }
          }
      }
    if (0)
      done_table_lookup: ;
    else
# endif
      {
        /* Did not find it in the table.  */
        /* On Mac OS X, all modern locales use the UTF-8 encoding.
           BeOS and Haiku have a single locale, and it has UTF-8 encoding.  */
# if (defined __APPLE__ && defined __MACH__) || defined __BEOS__ || defined __HAIKU__
        codeset = "UTF-8";
# else
        /* Don't return an empty string.  GNU libc and GNU libiconv interpret
           the empty string as denoting "the locale's character encoding",
           thus GNU libiconv would call this function a second time.  */
        if (codeset[0] == '\0')
          codeset = "ASCII";
# endif
      }
  }

#else

  /* On old systems which lack it, use setlocale or getenv.  */
  const char *locale = NULL;

  /* But most old systems don't have a complete set of locales.  Some
     (like DJGPP) have only the C locale.  Therefore we don't use setlocale
     here; it would return "C" when it doesn't support the locale name the
     user has set.  */
# if 0
  locale = setlocale (LC_CTYPE, NULL);
# endif
  if (locale == NULL || locale[0] == '\0')
    {
      locale = getenv ("LC_ALL");
      if (locale == NULL || locale[0] == '\0')
        {
          locale = getenv ("LC_CTYPE");
          if (locale == NULL || locale[0] == '\0')
            locale = getenv ("LANG");
            if (locale == NULL)
              locale = "";
        }
    }

  /* Map locale name to canonical encoding name.  */
  {
# ifdef locale_table_defined
    const struct table_entry * const table = locale_table;
    size_t const table_size =
      sizeof (locale_table) / sizeof (struct table_entry);
    /* The table is sorted.  Perform a binary search.  */
    size_t hi = table_size;
    size_t lo = 0;
    while (lo < hi)
      {
        /* Invariant:
           for i < lo, strcmp (table[i].locale, locale) < 0,
           for i >= hi, strcmp (table[i].locale, locale) > 0.  */
        size_t mid = (hi + lo) >> 1; /* >= lo, < hi */
        int cmp = strcmp (table[mid].locale, locale);
        if (cmp < 0)
          lo = mid + 1;
        else if (cmp > 0)
          hi = mid;
        else
          {
            /* Found an i with
                 strcmp (table[i].locale, locale) == 0.  */
            codeset = table[mid].canonical;
            goto done_table_lookup;
          }
      }
    if (0)
      done_table_lookup: ;
    else
# endif
      {
        /* Did not find it in the table.  */
        /* On Mac OS X, all modern locales use the UTF-8 encoding.
           BeOS and Haiku have a single locale, and it has UTF-8 encoding.  */
# if (defined __APPLE__ && defined __MACH__) || defined __BEOS__ || defined __HAIKU__
        codeset = "UTF-8";
# else
        /* The canonical name cannot be determined.  */
        /* Don't return an empty string.  GNU libc and GNU libiconv interpret
           the empty string as denoting "the locale's character encoding",
           thus GNU libiconv would call this function a second time.  */
        codeset = "ASCII";
# endif
      }
  }

#endif

#ifdef DARWIN7
  /* Mac OS X sets MB_CUR_MAX to 1 when LC_ALL=C, and "UTF-8"
     (the default codeset) does not work when MB_CUR_MAX is 1.  */
  if (strcmp (codeset, "UTF-8") == 0 && MB_CUR_MAX_L (uselocale (NULL)) <= 1)
    codeset = "ASCII";
#endif

  return codeset;
}

#if defined (__GNUC__) && defined (__OPTIMIZE__)

static inline int
streq9 (const char *s1, const char *s2)
{
  return strcmp (s1 + 9, s2 + 9) == 0;
}

static inline int
streq8 (const char *s1, const char *s2, char s28)
{
  if (s1[8] == s28)
    {
      if (s28 == 0)
        return 1;
      else
        return streq9 (s1, s2);
    }
  else
    return 0;
}

static inline int
streq7 (const char *s1, const char *s2, char s27, char s28)
{
  if (s1[7] == s27)
    {
      if (s27 == 0)
        return 1;
      else
        return streq8 (s1, s2, s28);
    }
  else
    return 0;
}

static inline int
streq6 (const char *s1, const char *s2, char s26, char s27, char s28)
{
  if (s1[6] == s26)
    {
      if (s26 == 0)
        return 1;
      else
        return streq7 (s1, s2, s27, s28);
    }
  else
    return 0;
}

static inline int
streq5 (const char *s1, const char *s2, char s25, char s26, char s27, char s28)
{
  if (s1[5] == s25)
    {
      if (s25 == 0)
        return 1;
      else
        return streq6 (s1, s2, s26, s27, s28);
    }
  else
    return 0;
}

static inline int
streq4 (const char *s1, const char *s2, char s24, char s25, char s26, char s27, char s28)
{
  if (s1[4] == s24)
    {
      if (s24 == 0)
        return 1;
      else
        return streq5 (s1, s2, s25, s26, s27, s28);
    }
  else
    return 0;
}

static inline int
streq3 (const char *s1, const char *s2, char s23, char s24, char s25, char s26, char s27, char s28)
{
  if (s1[3] == s23)
    {
      if (s23 == 0)
        return 1;
      else
        return streq4 (s1, s2, s24, s25, s26, s27, s28);
    }
  else
    return 0;
}

static inline int
streq2 (const char *s1, const char *s2, char s22, char s23, char s24, char s25, char s26, char s27, char s28)
{
  if (s1[2] == s22)
    {
      if (s22 == 0)
        return 1;
      else
        return streq3 (s1, s2, s23, s24, s25, s26, s27, s28);
    }
  else
    return 0;
}

static inline int
streq1 (const char *s1, const char *s2, char s21, char s22, char s23, char s24, char s25, char s26, char s27, char s28)
{
  if (s1[1] == s21)
    {
      if (s21 == 0)
        return 1;
      else
        return streq2 (s1, s2, s22, s23, s24, s25, s26, s27, s28);
    }
  else
    return 0;
}

static inline int
streq0 (const char *s1, const char *s2, char s20, char s21, char s22, char s23, char s24, char s25, char s26, char s27, char s28)
{
  if (s1[0] == s20)
    {
      if (s20 == 0)
        return 1;
      else
        return streq1 (s1, s2, s21, s22, s23, s24, s25, s26, s27, s28);
    }
  else
    return 0;
}

#define STREQ_OPT(s1,s2,s20,s21,s22,s23,s24,s25,s26,s27,s28) \
  streq0 (s1, s2, s20, s21, s22, s23, s24, s25, s26, s27, s28)

#else

#define STREQ_OPT(s1,s2,s20,s21,s22,s23,s24,s25,s26,s27,s28) \
  (strcmp (s1, s2) == 0)

#endif

static int
is_cjk_encoding (const char *encoding)
{
  if (0
      /* Legacy Japanese encodings */
      || STREQ_OPT (encoding, "EUC-JP", 'E', 'U', 'C', '-', 'J', 'P', 0, 0, 0)
      /* Legacy Chinese encodings */
      || STREQ_OPT (encoding, "GB2312", 'G', 'B', '2', '3', '1', '2', 0, 0, 0)
      || STREQ_OPT (encoding, "GBK", 'G', 'B', 'K', 0, 0, 0, 0, 0, 0)
      || STREQ_OPT (encoding, "EUC-TW", 'E', 'U', 'C', '-', 'T', 'W', 0, 0, 0)
      || STREQ_OPT (encoding, "BIG5", 'B', 'I', 'G', '5', 0, 0, 0, 0, 0)
      /* Legacy Korean encodings */
      || STREQ_OPT (encoding, "EUC-KR", 'E', 'U', 'C', '-', 'K', 'R', 0, 0, 0)
      || STREQ_OPT (encoding, "CP949", 'C', 'P', '9', '4', '9', 0, 0, 0, 0)
      || STREQ_OPT (encoding, "JOHAB", 'J', 'O', 'H', 'A', 'B', 0, 0, 0, 0))
    return 1;
  return 0;
}


/* Returns 1 if the current locale is an UTF-8 locale, 0 otherwise.  */
static inline int
is_locale_utf8 (void)
{
  const char *encoding = locale_charset ();
  return STREQ_OPT (encoding, "UTF-8", 'U', 'T', 'F', '-', '8', 0, 0, 0, 0);
}

#if GNULIB_WCHAR_SINGLE
/* When we know that the locale does not change, provide a speedup by
   caching the value of is_locale_utf8.  */
static int cached_is_locale_utf8 = -1;
static inline int
is_locale_utf8_cached (void)
{
  if (cached_is_locale_utf8 < 0)
    cached_is_locale_utf8 = is_locale_utf8 ();
  return cached_is_locale_utf8;
}
#else
/* By default, don't make assumptions, hence no caching.  */
# define is_locale_utf8_cached is_locale_utf8
#endif




/* Determine display width of Unicode character.
   Copyright (C) 2001-2002, 2006-2019 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2002.

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

//#include <config.h>

/* Specification.  */
//#include "uniwidth.h"

//#include "cjk.h"

/*
 * Non-spacing attribute table.
 * Consists of:
 * - Non-spacing characters; generated from PropList.txt or
 *   "grep '^[^;]*;[^;]*;[^;]*;[^;]*;NSM;' UnicodeData.txt"
 * - Format control characters; generated from
 *   "grep '^[^;]*;[^;]*;Cf;' UnicodeData.txt"
 * - Zero width characters; generated from
 *   "grep '^[^;]*;ZERO WIDTH ' UnicodeData.txt"
 */
static const unsigned char nonspacing_table_data[38*64] = {
  /* 0x0000-0x01ff */
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, /* 0x0000-0x003f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, /* 0x0040-0x007f */
  0xff, 0xff, 0xff, 0xff, 0x00, 0x20, 0x00, 0x00, /* 0x0080-0x00bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x00c0-0x00ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0100-0x013f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0140-0x017f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0180-0x01bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x01c0-0x01ff */
  /* 0x0200-0x03ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0200-0x023f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0240-0x027f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0280-0x02bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x02c0-0x02ff */
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 0x0300-0x033f */
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, /* 0x0340-0x037f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0380-0x03bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x03c0-0x03ff */
  /* 0x0400-0x05ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0400-0x043f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0440-0x047f */
  0xf8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0480-0x04bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x04c0-0x04ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0500-0x053f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0540-0x057f */
  0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xbf, /* 0x0580-0x05bf */
  0xb6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x05c0-0x05ff */
  /* 0x0600-0x07ff */
  0x3f, 0x00, 0xff, 0x17, 0x00, 0x00, 0x00, 0x00, /* 0x0600-0x063f */
  0x00, 0xf8, 0xff, 0xff, 0x00, 0x00, 0x01, 0x00, /* 0x0640-0x067f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0680-0x06bf */
  0x00, 0x00, 0xc0, 0xbf, 0x9f, 0x3d, 0x00, 0x00, /* 0x06c0-0x06ff */
  0x00, 0x80, 0x02, 0x00, 0x00, 0x00, 0xff, 0xff, /* 0x0700-0x073f */
  0xff, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0740-0x077f */
  0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x01, 0x00, /* 0x0780-0x07bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00, /* 0x07c0-0x07ff */
  /* 0x0800-0x09ff */
  0x00, 0x00, 0xc0, 0xfb, 0xef, 0x3e, 0x00, 0x00, /* 0x0800-0x083f */
  0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, /* 0x0840-0x087f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0880-0x08bf */
  0x00, 0x00, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, /* 0x08c0-0x08ff */
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, /* 0x0900-0x093f */
  0xfe, 0x21, 0xfe, 0x00, 0x0c, 0x00, 0x00, 0x00, /* 0x0940-0x097f */
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, /* 0x0980-0x09bf */
  0x1e, 0x20, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, /* 0x09c0-0x09ff */
  /* 0x0a00-0x0bff */
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, /* 0x0a00-0x0a3f */
  0x86, 0x39, 0x02, 0x00, 0x00, 0x00, 0x23, 0x00, /* 0x0a40-0x0a7f */
  0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, /* 0x0a80-0x0abf */
  0xbe, 0x21, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, /* 0x0ac0-0x0aff */
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, /* 0x0b00-0x0b3f */
  0x1e, 0x20, 0x40, 0x00, 0x0c, 0x00, 0x00, 0x00, /* 0x0b40-0x0b7f */
  0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0b80-0x0bbf */
  0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0bc0-0x0bff */
  /* 0x0c00-0x0dff */
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, /* 0x0c00-0x0c3f */
  0xc1, 0x3d, 0x60, 0x00, 0x0c, 0x00, 0x00, 0x00, /* 0x0c40-0x0c7f */
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, /* 0x0c80-0x0cbf */
  0x00, 0x30, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, /* 0x0cc0-0x0cff */
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0d00-0x0d3f */
  0x1e, 0x20, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, /* 0x0d40-0x0d7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0d80-0x0dbf */
  0x00, 0x04, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0dc0-0x0dff */
  /* 0x0e00-0x0fff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf2, 0x07, /* 0x0e00-0x0e3f */
  0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0e40-0x0e7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf2, 0x1b, /* 0x0e80-0x0ebf */
  0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0ec0-0x0eff */
  0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0xa0, 0x02, /* 0x0f00-0x0f3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x7f, /* 0x0f40-0x0f7f */
  0xdf, 0xe0, 0xff, 0xfe, 0xff, 0xff, 0xff, 0x1f, /* 0x0f80-0x0fbf */
  0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x0fc0-0x0fff */
  /* 0x1000-0x11ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xfd, 0x66, /* 0x1000-0x103f */
  0x00, 0x00, 0x00, 0xc3, 0x01, 0x00, 0x1e, 0x00, /* 0x1040-0x107f */
  0x64, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, /* 0x1080-0x10bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10c0-0x10ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1100-0x113f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1140-0x117f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1180-0x11bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11c0-0x11ff */
  /* 0x1200-0x13ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1200-0x123f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1240-0x127f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1280-0x12bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x12c0-0x12ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1300-0x133f */
  0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, /* 0x1340-0x137f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1380-0x13bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x13c0-0x13ff */
  /* 0x1600-0x17ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1600-0x163f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1640-0x167f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1680-0x16bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16c0-0x16ff */
  0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x1c, 0x00, /* 0x1700-0x173f */
  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x00, /* 0x1740-0x177f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x3f, /* 0x1780-0x17bf */
  0x40, 0xfe, 0x0f, 0x20, 0x00, 0x00, 0x00, 0x00, /* 0x17c0-0x17ff */
  /* 0x1800-0x19ff */
  0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1800-0x183f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1840-0x187f */
  0x60, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, /* 0x1880-0x18bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x18c0-0x18ff */
  0x00, 0x00, 0x00, 0x00, 0x87, 0x01, 0x04, 0x0e, /* 0x1900-0x193f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1940-0x197f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1980-0x19bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x19c0-0x19ff */
  /* 0x1a00-0x1bff */
  0x00, 0x00, 0x80, 0x09, 0x00, 0x00, 0x00, 0x00, /* 0x1a00-0x1a3f */
  0x00, 0x00, 0x40, 0x7f, 0xe5, 0x1f, 0xf8, 0x9f, /* 0x1a40-0x1a7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x7f, /* 0x1a80-0x1abf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1ac0-0x1aff */
  0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x17, /* 0x1b00-0x1b3f */
  0x04, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x0f, 0x00, /* 0x1b40-0x1b7f */
  0x03, 0x00, 0x00, 0x00, 0x3c, 0x3b, 0x00, 0x00, /* 0x1b80-0x1bbf */
  0x00, 0x00, 0x00, 0x00, 0x40, 0xa3, 0x03, 0x00, /* 0x1bc0-0x1bff */
  /* 0x1c00-0x1dff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xcf, 0x00, /* 0x1c00-0x1c3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1c40-0x1c7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1c80-0x1cbf */
  0x00, 0x00, 0xf7, 0xff, 0xfd, 0x21, 0x10, 0x03, /* 0x1cc0-0x1cff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d00-0x1d3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d40-0x1d7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d80-0x1dbf */
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xf8, /* 0x1dc0-0x1dff */
  /* 0x2000-0x21ff */
  0x00, 0xf8, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, /* 0x2000-0x203f */
  0x00, 0x00, 0x00, 0x00, 0xdf, 0xff, 0x00, 0x00, /* 0x2040-0x207f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2080-0x20bf */
  0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x01, 0x00, /* 0x20c0-0x20ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2100-0x213f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2140-0x217f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2180-0x21bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x21c0-0x21ff */
  /* 0x2c00-0x2dff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2c00-0x2c3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2c40-0x2c7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2c80-0x2cbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, /* 0x2cc0-0x2cff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2d00-0x2d3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, /* 0x2d40-0x2d7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x2d80-0x2dbf */
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, /* 0x2dc0-0x2dff */
  /* 0x3000-0x31ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, /* 0x3000-0x303f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x3040-0x307f */
  0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, /* 0x3080-0x30bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x30c0-0x30ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x3100-0x313f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x3140-0x317f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x3180-0x31bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x31c0-0x31ff */
  /* 0xa600-0xa7ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa600-0xa63f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf7, 0x3f, /* 0xa640-0xa67f */
  0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, /* 0xa680-0xa6bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, /* 0xa6c0-0xa6ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa700-0xa73f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa740-0xa77f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa780-0xa7bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa7c0-0xa7ff */
  /* 0xa800-0xa9ff */
  0x44, 0x08, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, /* 0xa800-0xa83f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa840-0xa87f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa880-0xa8bf */
  0x30, 0x00, 0x00, 0x00, 0xff, 0xff, 0x03, 0x00, /* 0xa8c0-0xa8ff */
  0x00, 0x00, 0x00, 0x00, 0xc0, 0x3f, 0x00, 0x00, /* 0xa900-0xa93f */
  0x80, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xa940-0xa97f */
  0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc8, 0x13, /* 0xa980-0xa9bf */
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, /* 0xa9c0-0xa9ff */
  /* 0xaa00-0xabff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x66, 0x00, /* 0xaa00-0xaa3f */
  0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, /* 0xaa40-0xaa7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9d, 0xc1, /* 0xaa80-0xaabf */
  0x02, 0x00, 0x00, 0x00, 0x00, 0x30, 0x40, 0x00, /* 0xaac0-0xaaff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xab00-0xab3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xab40-0xab7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xab80-0xabbf */
  0x00, 0x00, 0x00, 0x00, 0x20, 0x21, 0x00, 0x00, /* 0xabc0-0xabff */
  /* 0xfa00-0xfbff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfa00-0xfa3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfa40-0xfa7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfa80-0xfabf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfac0-0xfaff */
  0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, /* 0xfb00-0xfb3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfb40-0xfb7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfb80-0xfbbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfbc0-0xfbff */
  /* 0xfe00-0xffff */
  0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, /* 0xfe00-0xfe3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfe40-0xfe7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xfe80-0xfebf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, /* 0xfec0-0xfeff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xff00-0xff3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xff40-0xff7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0xff80-0xffbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, /* 0xffc0-0xffff */
  /* 0x10000-0x101ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10000-0x1003f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10040-0x1007f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10080-0x100bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x100c0-0x100ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10100-0x1013f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10140-0x1017f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10180-0x101bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, /* 0x101c0-0x101ff */
  /* 0x10200-0x103ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10200-0x1023f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10240-0x1027f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10280-0x102bf */
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, /* 0x102c0-0x102ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10300-0x1033f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x07, /* 0x10340-0x1037f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10380-0x103bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x103c0-0x103ff */
  /* 0x10a00-0x10bff */
  0x6e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, /* 0x10a00-0x10a3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10a40-0x10a7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10a80-0x10abf */
  0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, /* 0x10ac0-0x10aff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10b00-0x10b3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10b40-0x10b7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10b80-0x10bbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x10bc0-0x10bff */
  /* 0x11000-0x111ff */
  0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, /* 0x11000-0x1103f */
  0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, /* 0x11040-0x1107f */
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x26, /* 0x11080-0x110bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x110c0-0x110ff */
  0x07, 0x00, 0x00, 0x00, 0x80, 0xef, 0x1f, 0x00, /* 0x11100-0x1113f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, /* 0x11140-0x1117f */
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x7f, /* 0x11180-0x111bf */
  0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x111c0-0x111ff */
  /* 0x11200-0x113ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xd3, 0x40, /* 0x11200-0x1123f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11240-0x1127f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11280-0x112bf */
  0x00, 0x00, 0x00, 0x80, 0xf8, 0x07, 0x00, 0x00, /* 0x112c0-0x112ff */
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, /* 0x11300-0x1133f */
  0x01, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x1f, 0x00, /* 0x11340-0x1137f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11380-0x113bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x113c0-0x113ff */
  /* 0x11400-0x115ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, /* 0x11400-0x1143f */
  0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11440-0x1147f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x85, /* 0x11480-0x114bf */
  0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x114c0-0x114ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11500-0x1153f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11540-0x1157f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xb0, /* 0x11580-0x115bf */
  0x01, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, /* 0x115c0-0x115ff */
  /* 0x11600-0x117ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xa7, /* 0x11600-0x1163f */
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11640-0x1167f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0xbf, 0x00, /* 0x11680-0x116bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x116c0-0x116ff */
  0x00, 0x00, 0x00, 0xe0, 0xbc, 0x0f, 0x00, 0x00, /* 0x11700-0x1173f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11740-0x1177f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11780-0x117bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x117c0-0x117ff */
  /* 0x11c00-0x11dff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x3f, /* 0x11c00-0x11c3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11c40-0x11c7f */
  0x00, 0x00, 0xfc, 0xff, 0xff, 0xfc, 0x6d, 0x00, /* 0x11c80-0x11cbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11cc0-0x11cff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11d00-0x11d3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11d40-0x11d7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11d80-0x11dbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x11dc0-0x11dff */
  /* 0x16a00-0x16bff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16a00-0x16a3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16a40-0x16a7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16a80-0x16abf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, /* 0x16ac0-0x16aff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, /* 0x16b00-0x16b3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16b40-0x16b7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16b80-0x16bbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16bc0-0x16bff */
  /* 0x16e00-0x16fff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16e00-0x16e3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16e40-0x16e7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16e80-0x16ebf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16ec0-0x16eff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16f00-0x16f3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16f40-0x16f7f */
  0x00, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16f80-0x16fbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x16fc0-0x16fff */
  /* 0x1bc00-0x1bdff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1bc00-0x1bc3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1bc40-0x1bc7f */
  0x00, 0x00, 0x00, 0x60, 0x0f, 0x00, 0x00, 0x00, /* 0x1bc80-0x1bcbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1bcc0-0x1bcff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1bd00-0x1bd3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1bd40-0x1bd7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1bd80-0x1bdbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1bdc0-0x1bdff */
  /* 0x1d000-0x1d1ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d000-0x1d03f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d040-0x1d07f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d080-0x1d0bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d0c0-0x1d0ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d100-0x1d13f */
  0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0xf8, 0xff, /* 0x1d140-0x1d17f */
  0xe7, 0x0f, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, /* 0x1d180-0x1d1bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d1c0-0x1d1ff */
  /* 0x1d200-0x1d3ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d200-0x1d23f */
  0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d240-0x1d27f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d280-0x1d2bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d2c0-0x1d2ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d300-0x1d33f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d340-0x1d37f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d380-0x1d3bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1d3c0-0x1d3ff */
  /* 0x1da00-0x1dbff */
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf8, /* 0x1da00-0x1da3f */
  0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 0x20, 0x00, /* 0x1da40-0x1da7f */
  0x10, 0x00, 0x00, 0xf8, 0xfe, 0xff, 0x00, 0x00, /* 0x1da80-0x1dabf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1dac0-0x1daff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1db00-0x1db3f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1db40-0x1db7f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1db80-0x1dbbf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1dbc0-0x1dbff */
  /* 0x1e000-0x1e1ff */
  0x7f, 0xff, 0xff, 0xf9, 0xdb, 0x07, 0x00, 0x00, /* 0x1e000-0x1e03f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e040-0x1e07f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e080-0x1e0bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e0c0-0x1e0ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e100-0x1e13f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e140-0x1e17f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e180-0x1e1bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e1c0-0x1e1ff */
  /* 0x1e800-0x1e9ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e800-0x1e83f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e840-0x1e87f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e880-0x1e8bf */
  0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e8c0-0x1e8ff */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e900-0x1e93f */
  0xf0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e940-0x1e97f */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* 0x1e980-0x1e9bf */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  /* 0x1e9c0-0x1e9ff */
};
static const signed char nonspacing_table_ind[248] = {
   0,  1,  2,  3,  4,  5,  6,  7, /* 0x0000-0x0fff */
   8,  9, -1, 10, 11, 12, 13, -1, /* 0x1000-0x1fff */
  14, -1, -1, -1, -1, -1, 15, -1, /* 0x2000-0x2fff */
  16, -1, -1, -1, -1, -1, -1, -1, /* 0x3000-0x3fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x4000-0x4fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x5000-0x5fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x6000-0x6fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x7000-0x7fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x8000-0x8fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x9000-0x9fff */
  -1, -1, -1, 17, 18, 19, -1, -1, /* 0xa000-0xafff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0xb000-0xbfff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0xc000-0xcfff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0xd000-0xdfff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0xe000-0xefff */
  -1, -1, -1, -1, -1, 20, -1, 21, /* 0xf000-0xffff */
  22, 23, -1, -1, -1, 24, -1, -1, /* 0x10000-0x10fff */
  25, 26, 27, 28, -1, -1, 29, -1, /* 0x11000-0x11fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x12000-0x12fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x13000-0x13fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x14000-0x14fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x15000-0x15fff */
  -1, -1, -1, -1, -1, 30, -1, 31, /* 0x16000-0x16fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x17000-0x17fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x18000-0x18fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x19000-0x19fff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x1a000-0x1afff */
  -1, -1, -1, -1, -1, -1, 32, -1, /* 0x1b000-0x1bfff */
  -1, -1, -1, -1, -1, -1, -1, -1, /* 0x1c000-0x1cfff */
  33, 34, -1, -1, -1, 35, -1, -1, /* 0x1d000-0x1dfff */
  36, -1, -1, -1, 37, -1, -1, -1  /* 0x1e000-0x1efff */
};

typedef uint32_t ucs4_t;

/* Determine number of column positions required for UC.  */
int
uc_width (ucs4_t uc, const char *encoding)
{
  /* Test for non-spacing or control character.  */
  if ((uc >> 9) < 248)
    {
      int ind = nonspacing_table_ind[uc >> 9];
      if (ind >= 0)
        if ((nonspacing_table_data[64*ind + ((uc >> 3) & 63)] >> (uc & 7)) & 1)
          {
            if (uc > 0 && uc < 0xa0)
              return -1;
            else
              return 0;
          }
    }
  else if ((uc >> 9) == (0xe0000 >> 9))
    {
      if (uc >= 0xe0100)
        {
          if (uc <= 0xe01ef)
            return 0;
        }
      else
        {
          if (uc >= 0xe0020 ? uc <= 0xe007f : uc == 0xe0001)
            return 0;
        }
    }
  /* Test for double-width character.
   * Generated from "grep '^[^;]\{4,5\};[WF]' EastAsianWidth.txt"
   * and            "grep '^[^;]\{4,5\};[^WF]' EastAsianWidth.txt"
   */
  if (uc >= 0x1100
      && ((uc < 0x1160) /* Hangul Jamo */
          || (uc >= 0x2329 && uc < 0x232b) /* Angle Brackets */
          || (uc >= 0x2e80 && uc < 0xa4d0  /* CJK ... Yi */
              && !(uc == 0x303f) && !(uc >= 0x4dc0 && uc < 0x4e00))
          || (uc >= 0xac00 && uc < 0xd7a4) /* Hangul Syllables */
          || (uc >= 0xf900 && uc < 0xfb00) /* CJK Compatibility Ideographs */
          || (uc >= 0xfe10 && uc < 0xfe20) /* Presentation Forms for Vertical */
          || (uc >= 0xfe30 && uc < 0xfe70) /* CJK Compatibility Forms */
          || (uc >= 0xff00 && uc < 0xff61) /* Fullwidth Forms */
          || (uc >= 0xffe0 && uc < 0xffe7) /* Fullwidth Signs */
          || (uc >= 0x20000 && uc <= 0x2ffff) /* Supplementary Ideographic Plane */
          || (uc >= 0x30000 && uc <= 0x3ffff) /* Tertiary Ideographic Plane */
     )   )
    return 2;
  /* In ancient CJK encodings, Cyrillic and most other characters are
     double-width as well.  */
  if (uc >= 0x00A1 && uc < 0xFF61 && uc != 0x20A9
      && is_cjk_encoding (encoding))
    return 2;
  return 1;
}





int
wcwidth (wchar_t wc)
#undef wcwidth
{
  /* In UTF-8 locales, use a Unicode aware width function.  */
  if (is_locale_utf8_cached ())
    {
      /* We assume that in a UTF-8 locale, a wide character is the same as a
         Unicode character.  */
      return uc_width (wc, "UTF-8");
    }
  else
    {
      /* Otherwise, fall back to the system's wcwidth function.  */
#if HAVE_WCWIDTH
      return wcwidth (wc);
#else
      return wc == 0 ? 0 : iswprint (wc) ? 1 : -1;
#endif
    }
}

  int
mb_width_aux (wint_t wc)
{
  int w = wcwidth (wc);
  /* For unprintable characters, arbitrarily return 0 for control characters
     and MB_UNPRINTABLE_WIDTH otherwise.  */
  return (w >= 0 ? w : iswcntrl (wc) ? 0 : MB_UNPRINTABLE_WIDTH);
}

#define mb_width(mbc) \
  ((mbc).wc_valid ? mb_width_aux ((mbc).wc) : MB_UNPRINTABLE_WIDTH)

/* Output.  */
#define mb_putc(mbc, stream)  fwrite ((mbc).ptr, 1, (mbc).bytes, (stream))

/* Assignment.  */
#define mb_setascii(mbc, sc) \
  ((mbc)->ptr = (mbc)->buf, (mbc)->bytes = 1, (mbc)->wc_valid = 1, \
   (mbc)->wc = (mbc)->buf[0] = (sc))

/* Copying a character.  */
  void
mb_copy (mbchar_t *new_mbc, const mbchar_t *old_mbc)
{
  if (old_mbc->ptr == &old_mbc->buf[0])
    {
      memcpy (&new_mbc->buf[0], &old_mbc->buf[0], old_mbc->bytes);
      new_mbc->ptr = &new_mbc->buf[0];
    }
  else
    new_mbc->ptr = old_mbc->ptr;
  new_mbc->bytes = old_mbc->bytes;
  if ((new_mbc->wc_valid = old_mbc->wc_valid))
    new_mbc->wc = old_mbc->wc;
}


/* is_basic(c) tests whether the single-byte character c is in the
   ISO C "basic character set".
   This is a convenience function, and is in this file only to share code
   between mbiter_multi.h and mbfile_multi.h.  */
#if (' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
    && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
    && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
    && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
    && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
    && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
    && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
    && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
    && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
    && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
    && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
    && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
    && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
    && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
    && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
    && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
    && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
    && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
    && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
    && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
    && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
    && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
    && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126)
/* The character set is ISO-646, not EBCDIC. */
# define IS_BASIC_ASCII 1

extern const unsigned int is_basic_table[];

  bool
is_basic (char c)
{
  return (is_basic_table [(unsigned char) c >> 5] >> ((unsigned char) c & 31))
         & 1;
}

#else

  bool
is_basic (char c)
{
  switch (c)
    {
    case '\t': case '\v': case '\f':
    case ' ': case '!': case '"': case '#': case '%':
    case '&': case '\'': case '(': case ')': case '*':
    case '+': case ',': case '-': case '.': case '/':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case ':': case ';': case '<': case '=': case '>':
    case '?':
    case 'A': case 'B': case 'C': case 'D': case 'E':
    case 'F': case 'G': case 'H': case 'I': case 'J':
    case 'K': case 'L': case 'M': case 'N': case 'O':
    case 'P': case 'Q': case 'R': case 'S': case 'T':
    case 'U': case 'V': case 'W': case 'X': case 'Y':
    case 'Z':
    case '[': case '\\': case ']': case '^': case '_':
    case 'a': case 'b': case 'c': case 'd': case 'e':
    case 'f': case 'g': case 'h': case 'i': case 'j':
    case 'k': case 'l': case 'm': case 'n': case 'o':
    case 'p': case 'q': case 'r': case 's': case 't':
    case 'u': case 'v': case 'w': case 'x': case 'y':
    case 'z': case '{': case '|': case '}': case '~':
      return 1;
    default:
      return 0;
    }
}

#endif

struct mbuiter_multi
{
  bool in_shift;        /* true if next byte may not be interpreted as ASCII */
  mbstate_t state;      /* if in_shift: current shift state */
  bool next_done;       /* true if mbui_avail has already filled the following */
  struct mbchar cur;    /* the current character:
        const char *cur.ptr             pointer to current character
        The following are only valid after mbui_avail.
        size_t cur.bytes                number of bytes of current character
        bool cur.wc_valid               true if wc is a valid wide character
        wchar_t cur.wc                  if wc_valid: the current character
        */
};

/* Find the length of STRING + 1, but scan at most MAXLEN bytes.
   If no '\0' terminator is found in that many characters, return MAXLEN.  */
/* This is the same as strnlen (string, maxlen - 1) + 1.  */
size_t
strnlen1 (const char *string, size_t maxlen)
{
  const char *end = (const char *) memchr (string, '\0', maxlen);
  if (end != NULL)
    return end - string + 1;
  else
    return maxlen;
}

  void
mbuiter_multi_next (struct mbuiter_multi *iter)
{
  if (iter->next_done)
    return;
  if (iter->in_shift)
    goto with_shift;
  /* Handle most ASCII characters quickly, without calling mbrtowc().  */
  if (is_basic (*iter->cur.ptr))
    {
      /* These characters are part of the basic character set.  ISO C 99
         guarantees that their wide character code is identical to their
         char code.  */
      iter->cur.bytes = 1;
      iter->cur.wc = *iter->cur.ptr;
      iter->cur.wc_valid = true;
    }
  else
    {
      assert (mbsinit (&iter->state));
      iter->in_shift = true;
    with_shift:
      iter->cur.bytes = mbrtowc (&iter->cur.wc, iter->cur.ptr,
                                 strnlen1 (iter->cur.ptr, MB_CUR_MAX),
                                 &iter->state);
      if (iter->cur.bytes == (size_t) -1)
        {
          /* An invalid multibyte sequence was encountered.  */
          iter->cur.bytes = 1;
          iter->cur.wc_valid = false;
          /* Whether to set iter->in_shift = false and reset iter->state
             or not is not very important; the string is bogus anyway.  */
        }
      else if (iter->cur.bytes == (size_t) -2)
        {
          /* An incomplete multibyte character at the end.  */
          iter->cur.bytes = strlen (iter->cur.ptr);
          iter->cur.wc_valid = false;
          /* Whether to set iter->in_shift = false and reset iter->state
             or not is not important; the string end is reached anyway.  */
        }
      else
        {
          if (iter->cur.bytes == 0)
            {
              /* A null wide character was encountered.  */
              iter->cur.bytes = 1;
              assert (*iter->cur.ptr == '\0');
              assert (iter->cur.wc == 0);
            }
          iter->cur.wc_valid = true;

          /* When in the initial state, we can go back treating ASCII
             characters more quickly.  */
          if (mbsinit (&iter->state))
            iter->in_shift = false;
        }
    }
  iter->next_done = true;
}

  void
mbuiter_multi_reloc (struct mbuiter_multi *iter, ptrdiff_t ptrdiff)
{
  iter->cur.ptr += ptrdiff;
}

  void
mbuiter_multi_copy (struct mbuiter_multi *new_iter, const struct mbuiter_multi *old_iter)
{
  if ((new_iter->in_shift = old_iter->in_shift))
    memcpy (&new_iter->state, &old_iter->state, sizeof (mbstate_t));
  else
    memset (&new_iter->state, 0, sizeof (mbstate_t));
  new_iter->next_done = old_iter->next_done;
  mb_copy (&new_iter->cur, &old_iter->cur);
}

/* Iteration macros.  */
typedef struct mbuiter_multi mbui_iterator_t;
#define mbui_init(iter, startptr) \
  ((iter).cur.ptr = (startptr), \
   (iter).in_shift = false, memset (&(iter).state, '\0', sizeof (mbstate_t)), \
   (iter).next_done = false)
#define mbui_avail(iter) \
  (mbuiter_multi_next (&(iter)), !mb_isnul ((iter).cur))
#define mbui_advance(iter) \
  ((iter).cur.ptr += (iter).cur.bytes, (iter).next_done = false)

/* Access to the current character.  */
#define mbui_cur(iter) (iter).cur
#define mbui_cur_ptr(iter) (iter).cur.ptr

/* Relocation.  */
#define mbui_reloc(iter, ptrdiff) mbuiter_multi_reloc (&iter, ptrdiff)

/* Copying an iterator.  */
#define mbui_copy mbuiter_multi_copy


#undef  FNM_PATHNAME
#undef  FNM_NOESCAPE
#undef  FNM_PERIOD

/* Bits set in the FLAGS argument to 'fnmatch'.  */
#define FNM_PATHNAME    (1 << 0) /* No wildcard can ever match '/'.  */
#define FNM_NOESCAPE    (1 << 1) /* Backslashes don't quote special chars.  */
#define FNM_PERIOD      (1 << 2) /* Leading '.' is matched only explicitly.  */

#if !defined _POSIX_C_SOURCE || _POSIX_C_SOURCE < 2 || defined _GNU_SOURCE
# define FNM_FILE_NAME   FNM_PATHNAME   /* Preferred GNU name.  */
# define FNM_LEADING_DIR (1 << 3)       /* Ignore '/...' after a match.  */
# define FNM_CASEFOLD    (1 << 4)       /* Compare without regard to case.  */
# define FNM_EXTMATCH    (1 << 5)       /* Use ksh-like extended matching. */
#endif

# define FNM_FILE_NAME   FNM_PATHNAME   /* Preferred GNU name.  */
# define FNM_LEADING_DIR (1 << 3)       /* Ignore '/...' after a match.  */
# define FNM_CASEFOLD    (1 << 4)       /* Compare without regard to case.  */
# define FNM_EXTMATCH    (1 << 5)       /* Use ksh-like extended matching. */

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

struct exclude;

bool fnmatch_pattern_has_wildcards (const char *, int) _GL_ATTRIBUTE_PURE;

struct exclude *new_exclude (void) ;
void free_exclude (struct exclude *);
void add_exclude (struct exclude *, char const *, int);
int add_exclude_file (void (*) (struct exclude *, char const *, int),
                      struct exclude *, char const *, int, char);
int add_exclude_fp (void (*) (struct exclude *, char const *, int, void *),
                    struct exclude *, FILE *, int, char, void *);
bool excluded_file_name (struct exclude const *, char const *);
void exclude_add_pattern_buffer (struct exclude *ex, char *buf);
bool exclude_fnmatch (char const *, char const *, int);

/* Register BUF in the pattern buffer list of EX.  ADD_FUNC (see
   add_exclude_file and add_exclude_fp below) can use this function
   if it modifies the pattern, to ensure the allocated memory will be
   properly reclaimed upon calling free_exclude. */
void
exclude_add_pattern_buffer (struct exclude *ex, char *buf)
{
  struct pattern_buffer *pbuf = xmalloc (sizeof *pbuf);
  pbuf->base = buf;
  pbuf->next = ex->patbuf;
  ex->patbuf = pbuf;
}

/* Return true if STR has or may have wildcards, when matched with OPTIONS.
   Return false if STR definitely does not have wildcards.  */
bool
fnmatch_pattern_has_wildcards (const char *str, int options)
{
  while (1)
    {
      switch (*str++)
        {
        case '.':
        case '{':
        case '}':
        case '(':
        case ')':
          if (options & EXCLUDE_REGEX)
            return true;
          break;

        case '\\':
          if (options & EXCLUDE_REGEX)
            continue;
          else
            str += ! (options & FNM_NOESCAPE) && *str;
          break;

        case '+': case '@': case '!':
          if (options & FNM_EXTMATCH && *str == '(')
            return true;
          break;

        case '?': case '*': case '[':
          return true;

        case '\0':
          return false;
        }
    }
}

static void
unescape_pattern (char *str)
{
  char const *q = str;
  do
    q += *q == '\\' && q[1];
  while ((*str++ = *q++));
}

/* Return a newly allocated and empty exclude list.  */

struct exclude *
new_exclude (void)
{
  return xzalloc (sizeof *new_exclude ());
}

/* Calculate the hash of string.  */
static size_t
string_hasher (void const *data, size_t n_buckets)
{
  char const *p = data;
  return hash_string (p, n_buckets);
}

/* Ditto, for case-insensitive hashes */
static size_t
string_hasher_ci (void const *data, size_t n_buckets)
{
  char const *p = data;
  mbui_iterator_t iter;
  size_t value = 0;

  for (mbui_init (iter, p); mbui_avail (iter); mbui_advance (iter))
    {
      mbchar_t m = mbui_cur (iter);
      wchar_t wc;

      if (m.wc_valid)
        wc = towlower (m.wc);
      else
        wc = *m.ptr;

      value = (value * 31 + wc) % n_buckets;
    }

  return value;
}

/* compare two strings for equality */
static bool
string_compare (void const *data1, void const *data2)
{
  char const *p1 = data1;
  char const *p2 = data2;
  return strcmp (p1, p2) == 0;
}


/* Case-insensitive string comparison function.
   Copyright (C) 1998-1999, 2005-2019 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2005,
   based on earlier glibc code.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

//#include <config.h>

/* Specification.  */
#include <string.h>

#include <ctype.h>
#include <limits.h>

//#include "mbuiter.h"

#define TOLOWER(Ch) (isupper (Ch) ? tolower (Ch) : (Ch))

/* Compare the character strings S1 and S2, ignoring case, returning less than,
   equal to or greater than zero if S1 is lexicographically less than, equal to
   or greater than S2.
   Note: This function may, in multibyte locales, return 0 for strings of
   different lengths!  */
int
mbscasecmp (const char *s1, const char *s2)
{
  if (s1 == s2)
    return 0;

  /* Be careful not to look at the entire extent of s1 or s2 until needed.
     This is useful because when two strings differ, the difference is
     most often already in the very few first characters.  */
  if (MB_CUR_MAX > 1)
    {
      mbui_iterator_t iter1;
      mbui_iterator_t iter2;

      mbui_init (iter1, s1);
      mbui_init (iter2, s2);

      while (mbui_avail (iter1) && mbui_avail (iter2))
        {
          int cmp = mb_casecmp (mbui_cur (iter1), mbui_cur (iter2));

          if (cmp != 0)
            return cmp;

          mbui_advance (iter1);
          mbui_advance (iter2);
        }
      if (mbui_avail (iter1))
        /* s2 terminated before s1.  */
        return 1;
      if (mbui_avail (iter2))
        /* s1 terminated before s2.  */
        return -1;
      return 0;
    }
  else
    {
      const unsigned char *p1 = (const unsigned char *) s1;
      const unsigned char *p2 = (const unsigned char *) s2;
      unsigned char c1, c2;

      do
        {
          c1 = TOLOWER (*p1);
          c2 = TOLOWER (*p2);

          if (c1 == '\0')
            break;

          ++p1;
          ++p2;
        }
      while (c1 == c2);

      if (UCHAR_MAX <= INT_MAX)
        return c1 - c2;
      else
        /* On machines where 'char' and 'int' are types of the same size, the
           difference of two 'unsigned char' values - including the sign bit -
           doesn't fit in an 'int'.  */
        return (c1 > c2 ? 1 : c1 < c2 ? -1 : 0);
    }
}

/* compare two strings for equality, case-insensitive */
static bool
string_compare_ci (void const *data1, void const *data2)
{
  char const *p1 = data1;
  char const *p2 = data2;
  return mbscasecmp (p1, p2) == 0;
}

static void
string_free (void *data)
{
  free (data);
}

/* Create new exclude segment of given TYPE and OPTIONS, and attach it
   to the head of EX.  */
static void
new_exclude_segment (struct exclude *ex, enum exclude_type type, int options)
{
  struct exclude_segment *sp = xzalloc (sizeof (struct exclude_segment));
  sp->type = type;
  sp->options = options;
  switch (type)
    {
    case exclude_pattern:
      break;

    case exclude_hash:
      sp->v.table = hash_initialize (0, NULL,
                                     (options & FNM_CASEFOLD) ?
                                       string_hasher_ci
                                       : string_hasher,
                                     (options & FNM_CASEFOLD) ?
                                       string_compare_ci
                                       : string_compare,
                                     string_free);
      break;
    }
  sp->next = ex->head;
  ex->head = sp;
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

/* Free the storage associated with an exclude list.  */
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

/* Return zero if PATTERN matches F, obeying OPTIONS, except that
   (unlike fnmatch) wildcards are disabled in PATTERN.  */

static int
fnmatch_no_wildcards (char const *pattern, char const *f, int options)
{
  if (! (options & FNM_LEADING_DIR))
    return ((options & FNM_CASEFOLD)
            ? mbscasecmp (pattern, f)
            : strcmp (pattern, f));
  else if (! (options & FNM_CASEFOLD))
    {
      size_t patlen = strlen (pattern);
      int r = strncmp (pattern, f, patlen);
      if (! r)
        {
          r = f[patlen];
          if (r == '/')
            r = 0;
        }
      return r;
    }
  else
    {
      /* Walk through a copy of F, seeing whether P matches any prefix
         of F.

         FIXME: This is an O(N**2) algorithm; it should be O(N).
         Also, the copy should not be necessary.  However, fixing this
         will probably involve a change to the mbs* API.  */

      char *fcopy = xstrdup (f);
      char *p;
      int r;
      for (p = fcopy; ; *p++ = '/')
        {
          p = strchr (p, '/');
          if (p)
            *p = '\0';
          r = mbscasecmp (pattern, fcopy);
          if (!p || r <= 0)
            break;
        }
      free (fcopy);
      return r;
    }
}

int
fnmatch (const char *pattern, const char *string, int flags)
{
	pedro_dprintf(0, "call to fnmatch");
	assert(0);
	return 0;
}
/*
int
fnmatch_no_wildcards (const char *pattern, const char *string, int flags)
{
	pedro_dprintf(0, "call to fnmatch_no_wildcards");
	assert(0);
	return 0;
}
*/
bool
exclude_fnmatch (char const *pattern, char const *f, int options)
{
  int (*matcher) (char const *, char const *, int) =
    (options & EXCLUDE_WILDCARDS
     ? fnmatch
     : fnmatch_no_wildcards);
  bool matched = ((*matcher) (pattern, f, options) == 0);
  char const *p;

  if (! (options & EXCLUDE_ANCHORED))
    for (p = f; *p && ! matched; p++)
      if (*p == '/' && p[1] != '/')
        matched = ((*matcher) (pattern, p + 1, options) == 0);

  return matched;
}

static bool
exclude_patopts (struct patopts const *opts, char const *f)
{
  int options = opts->options;

  return (options & EXCLUDE_REGEX)
          ? regexec (&opts->v.re, f, 0, NULL, 0) == 0
          : exclude_fnmatch (opts->v.pattern, f, options);
}

/* Return true if the exclude_pattern segment SEG matches F.  */

static bool
file_pattern_matches (struct exclude_segment const *seg, char const *f)
{
  size_t exclude_count = seg->v.pat.exclude_count;
  struct patopts const *exclude = seg->v.pat.exclude;
  size_t i;

  for (i = 0; i < exclude_count; i++)
    {
      if (exclude_patopts (exclude + i, f))
        return true;
    }
  return false;
}

/* Return true if the exclude_hash segment SEG matches F.
   BUFFER is an auxiliary storage of the same length as F (with nul
   terminator included) */
static bool
file_name_matches (struct exclude_segment const *seg, char const *f,
                   char *buffer)
{
  int options = seg->options;
  Hash_table *table = seg->v.table;

  do
    {
      /* initialize the pattern */
      strcpy (buffer, f);

      while (1)
        {
          if (hash_lookup (table, buffer))
            return true;
          if (options & FNM_LEADING_DIR)
            {
              char *p = strrchr (buffer, '/');
              if (p)
                {
                  *p = 0;
                  continue;
                }
            }
          break;
        }

      if (!(options & EXCLUDE_ANCHORED))
        {
          f = strchr (f, '/');
          if (f)
            f++;
        }
      else
        break;
    }
  while (f);

  return false;
}

/* Return true if EX excludes F.  */

bool
excluded_file_name (struct exclude const *ex, char const *f)
{
  struct exclude_segment *seg;
  bool invert = false;
  char *filename = NULL;

  /* If no patterns are given, the default is to include.  */
  if (!ex->head)
    return false;

  /* Scan through the segments, reporting the status of the first match.
     The segments are in reverse order, so this reports the status of
     the last match in the original option list.  */
  for (seg = ex->head; ; seg = seg->next)
    {
      if (seg->type == exclude_hash)
        {
          if (!filename)
            filename = xmalloc (strlen (f) + 1);
          if (file_name_matches (seg, f, filename))
            break;
        }
      else
        {
          if (file_pattern_matches (seg, f))
            break;
        }

      if (! seg->next)
        {
          /* If patterns are given but none match, the default is the
             opposite of the last segment (i.e., the first in the
             original option list).  For example, in the command
             'grep -r --exclude="a*" --include="*b" pat dir', the
             first option is --exclude so any file name matching
             neither a* nor *b is included.  */
          invert = true;
          break;
        }
    }

  free (filename);
  return invert ^ ! (seg->options & EXCLUDE_INCLUDE);
}

/* Append to EX the exclusion PATTERN with OPTIONS.  */

void
add_exclude (struct exclude *ex, char const *pattern, int options)
{
  struct exclude_segment *seg;
  struct exclude_pattern *pat;
  struct patopts *patopts;

  if ((options & (EXCLUDE_REGEX|EXCLUDE_WILDCARDS))
      && fnmatch_pattern_has_wildcards (pattern, options))
    {
      if (! (ex->head && ex->head->type == exclude_pattern
             && ((ex->head->options & EXCLUDE_INCLUDE)
                 == (options & EXCLUDE_INCLUDE))))
        new_exclude_segment (ex, exclude_pattern, options);

      seg = ex->head;

      pat = &seg->v.pat;
      if (pat->exclude_count == pat->exclude_alloc)
        pat->exclude = x2nrealloc (pat->exclude, &pat->exclude_alloc,
                                   sizeof *pat->exclude);
      patopts = &pat->exclude[pat->exclude_count++];

      patopts->options = options;
      if (options & EXCLUDE_REGEX)
        {
          int rc;
          int cflags = REG_NOSUB|REG_EXTENDED|
                       ((options & FNM_CASEFOLD) ? REG_ICASE : 0);

          if (options & FNM_LEADING_DIR)
            {
              char *tmp;
              size_t len = strlen (pattern);

              while (len > 0 && ISSLASH (pattern[len-1]))
                --len;

              if (len == 0)
                rc = 1;
              else
                {
                  tmp = xmalloc (len + 7);
                  memcpy (tmp, pattern, len);
                  strcpy (tmp + len, "(/.*)?");
                  rc = regcomp (&patopts->v.re, tmp, cflags);
                  free (tmp);
                }
            }
          else
            rc = regcomp (&patopts->v.re, pattern, cflags);

          if (rc)
            {
              pat->exclude_count--;
              return;
            }
        }
      else
        {
          if (options & EXCLUDE_ALLOC)
            {
              pattern = xstrdup (pattern);
              exclude_add_pattern_buffer (ex, (char*) pattern);
            }
          patopts->v.pattern = pattern;
        }
    }
  else
    {
      char *str, *p;
      int exclude_hash_flags = (EXCLUDE_INCLUDE | EXCLUDE_ANCHORED
                                | FNM_LEADING_DIR | FNM_CASEFOLD);
      if (! (ex->head && ex->head->type == exclude_hash
             && ((ex->head->options & exclude_hash_flags)
                 == (options & exclude_hash_flags))))
        new_exclude_segment (ex, exclude_hash, options);
      seg = ex->head;

      str = xstrdup (pattern);
      if ((options & (EXCLUDE_WILDCARDS | FNM_NOESCAPE)) == EXCLUDE_WILDCARDS)
        unescape_pattern (str);
      p = hash_insert (seg->v.table, str);
      if (p != str)
        free (str);
    }
}

/* Use ADD_FUNC to append to EX the patterns in FILE_NAME, each with
   OPTIONS.  LINE_END terminates each pattern in the file.  If
   LINE_END is a space character, ignore trailing spaces and empty
   lines in FP.  Return -1 on failure, 0 on success.  */

int
add_exclude_fp (void (*add_func) (struct exclude *, char const *, int, void *),
                struct exclude *ex, FILE *fp, int options,
                char line_end,
                void *data)
{
  char *buf = NULL;
  char *p;
  char *pattern;
  char const *lim;
  size_t buf_alloc = 0;
  size_t buf_count = 0;
  int c;
  int e = 0;

  while ((c = getc (fp)) != EOF)
    {
      if (buf_count == buf_alloc)
        buf = x2realloc (buf, &buf_alloc);
      buf[buf_count++] = c;
    }

  if (ferror (fp))
    e = errno;

  buf = xrealloc (buf, buf_count + 1);
  buf[buf_count] = line_end;
  lim = buf + buf_count + ! (buf_count == 0 || buf[buf_count - 1] == line_end);

  exclude_add_pattern_buffer (ex, buf);

  pattern = buf;

  for (p = buf; p < lim; p++)
    if (*p == line_end)
      {
        char *pattern_end = p;

        if (isspace ((unsigned char) line_end))
          {
            for (; ; pattern_end--)
              if (pattern_end == pattern)
                goto next_pattern;
              else if (! isspace ((unsigned char) pattern_end[-1]))
                break;
          }

        *pattern_end = '\0';
        (*add_func) (ex, pattern, options, data);

      next_pattern:
        pattern = p + 1;
      }

  errno = e;
  return e ? -1 : 0;
}

static void
call_addfn (struct exclude *ex, char const *pattern, int options, void *data)
{
  void (**addfnptr) (struct exclude *, char const *, int) = data;
  (*addfnptr) (ex, pattern, options);
}

int
add_exclude_file (void (*add_func) (struct exclude *, char const *, int),
                  struct exclude *ex, char const *file_name, int options,
                  char line_end)
{
  bool use_stdin = file_name[0] == '-' && !file_name[1];
  FILE *in;
  int rc = 0;

  if (use_stdin)
    in = stdin;
  else if (! (in = fopen (file_name, "r")))
    return -1;

  rc = add_exclude_fp (call_addfn, ex, in, options, line_end, &add_func);

  if (!use_stdin && fclose (in) != 0)
    rc = -1;

  return rc;
}
