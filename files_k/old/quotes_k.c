/* MSGID approximates a quotation mark.  Return its translation if it
   has one; otherwise, return either it or "\"", depending on S.

   S is either clocale_quoting_style or locale_quoting_style.  */
static char const *
gettext_quote (char const *msgid, enum quoting_style s)
{
  char const *translation = _(msgid);
  char const *locale_code;

  if (translation != msgid)
    return translation;

  /* For UTF-8 and GB-18030, use single quotes U+2018 and U+2019.
     Here is a list of other locales that include U+2018 and U+2019:

        ISO-8859-7   0xA1                 KOI8-T       0x91
        CP869        0x8B                 CP874        0x91
        CP932        0x81 0x65            CP936        0xA1 0xAE
        CP949        0xA1 0xAE            CP950        0xA1 0xA5
        CP1250       0x91                 CP1251       0x91
        CP1252       0x91                 CP1253       0x91
        CP1254       0x91                 CP1255       0x91
        CP1256       0x91                 CP1257       0x91
        EUC-JP       0xA1 0xC6            EUC-KR       0xA1 0xAE
        EUC-TW       0xA1 0xE4            BIG5         0xA1 0xA5
        BIG5-HKSCS   0xA1 0xA5            EUC-CN       0xA1 0xAE
        GBK          0xA1 0xAE            Georgian-PS  0x91
        PT154        0x91

     None of these is still in wide use; using iconv is overkill.  */
	 
	 /*
	 
	 
  locale_code = locale_charset ();
  if (STRCASEEQ (locale_code, "UTF-8", 'U','T','F','-','8',0,0,0,0))
    return msgid[0] == '`' ? "\xe2\x80\x98": "\xe2\x80\x99";
  if (STRCASEEQ (locale_code, "GB18030", 'G','B','1','8','0','3','0',0,0))
    return msgid[0] == '`' ? "\xa1\ae": "\xa1\xaf";
*/

  return (s == clocale_quoting_style ? "\"" : "'");
}

/* Place into buffer BUFFER (of size BUFFERSIZE) a quoted version of
   argument ARG (of size ARGSIZE), using QUOTING_STYLE, FLAGS, and
   QUOTE_THESE_TOO to control quoting.
   Terminate the output with a null character, and return the written
   size of the output, not counting the terminating null.
   If BUFFERSIZE is too small to store the output string, return the
   value that would have been returned had BUFFERSIZE been large enough.
   If ARGSIZE is SIZE_MAX, use the string length of the argument for ARGSIZE.

   This function acts like quotearg_buffer (BUFFER, BUFFERSIZE, ARG,
   ARGSIZE, O), except it breaks O into its component pieces and is
   not careful about errno.  */

static size_t
quotearg_buffer_restyled (char *buffer, size_t buffersize,
                          char const *arg, size_t argsize,
                          enum quoting_style quoting_style, int flags,
                          unsigned int const *quote_these_too,
                          char const *left_quote,
                          char const *right_quote)
{
  size_t i;
  size_t len = 0;
  size_t orig_buffersize = 0;
  char const *quote_string = 0;
  size_t quote_string_len = 0;
  bool backslash_escapes = false;
  bool unibyte_locale = MB_CUR_MAX == 1;
  bool elide_outer_quotes = (flags & QA_ELIDE_OUTER_QUOTES) != 0;
  bool pending_shell_escape_end = false;
  bool encountered_single_quote = false;
  bool all_c_and_shell_quote_compat = true;

#define STORE(c) \
    do \
      { \
        if (len < buffersize) \
          buffer[len] = (c); \
        len++; \
      } \
    while (0)

#define START_ESC() \
    do \
      { \
        if (elide_outer_quotes) \
          goto force_outer_quoting_style; \
        escaping = true; \
        if (quoting_style == shell_always_quoting_style \
            && ! pending_shell_escape_end) \
          { \
            STORE ('\''); \
            STORE ('$'); \
            STORE ('\''); \
            pending_shell_escape_end = true; \
          } \
        STORE ('\\'); \
      } \
    while (0)

#define END_ESC() \
    do \
      { \
        if (pending_shell_escape_end && ! escaping) \
          { \
            STORE ('\''); \
            STORE ('\''); \
            pending_shell_escape_end = false; \
          } \
      } \
    while (0)

 process_input:

  switch (quoting_style)
    {
    case c_maybe_quoting_style:
      quoting_style = c_quoting_style;
      elide_outer_quotes = true;
      FALLTHROUGH;
    case c_quoting_style:
      if (!elide_outer_quotes)
        STORE ('"');
      backslash_escapes = true;
      quote_string = "\"";
      quote_string_len = 1;
      break;

    case escape_quoting_style:
      backslash_escapes = true;
      elide_outer_quotes = false;
      break;

    case locale_quoting_style:
    case clocale_quoting_style:
    case custom_quoting_style:
      {
        if (quoting_style != custom_quoting_style)
          {
            /* TRANSLATORS:
               Get translations for open and closing quotation marks.
               The message catalog should translate "`" to a left
               quotation mark suitable for the locale, and similarly for
               "'".  For example, a French Unicode local should translate
               these to U+00AB (LEFT-POINTING DOUBLE ANGLE
               QUOTATION MARK), and U+00BB (RIGHT-POINTING DOUBLE ANGLE
               QUOTATION MARK), respectively.

               If the catalog has no translation, we will try to
               use Unicode U+2018 (LEFT SINGLE QUOTATION MARK) and
               Unicode U+2019 (RIGHT SINGLE QUOTATION MARK).  If the
               current locale is not Unicode, locale_quoting_style
               will quote 'like this', and clocale_quoting_style will
               quote "like this".  You should always include translations
               for "`" and "'" even if U+2018 and U+2019 are appropriate
               for your locale.

               If you don't know what to put here, please see
               <https://en.wikipedia.org/wiki/Quotation_marks_in_other_languages>
               and use glyphs suitable for your language.  */
            left_quote = gettext_quote (N_("`"), quoting_style);
            right_quote = gettext_quote (N_("'"), quoting_style);
          }
        if (!elide_outer_quotes)
          for (quote_string = left_quote; *quote_string; quote_string++)
            STORE (*quote_string);
        backslash_escapes = true;
        quote_string = right_quote;
        quote_string_len = strlen (quote_string);
      }
      break;

    case shell_escape_quoting_style:
      backslash_escapes = true;
      FALLTHROUGH;
    case shell_quoting_style:
      elide_outer_quotes = true;
      FALLTHROUGH;
    case shell_escape_always_quoting_style:
      if (!elide_outer_quotes)
        backslash_escapes = true;
      FALLTHROUGH;
    case shell_always_quoting_style:
      quoting_style = shell_always_quoting_style;
      if (!elide_outer_quotes)
        STORE ('\'');
      quote_string = "'";
      quote_string_len = 1;
      break;

    case literal_quoting_style:
      elide_outer_quotes = false;
      break;

    default:
      abort ();
    }

  for (i = 0;  ! (argsize == SIZE_MAX ? arg[i] == '\0' : i == argsize);  i++)
    {
      unsigned char c;
      unsigned char esc;
      bool is_right_quote = false;
      bool escaping = false;
      bool c_and_shell_quote_compat = false;

      if (backslash_escapes
          && quoting_style != shell_always_quoting_style
          && quote_string_len
          && (i + quote_string_len
              <= (argsize == SIZE_MAX && 1 < quote_string_len
                  /* Use strlen only if we must: when argsize is SIZE_MAX,
                     and when the quote string is more than 1 byte long.
                     If we do call strlen, save the result.  */
                  ? (argsize = strlen (arg)) : argsize))
          && memcmp (arg + i, quote_string, quote_string_len) == 0)
        {
          if (elide_outer_quotes)
            goto force_outer_quoting_style;
          is_right_quote = true;
        }

      c = arg[i];
      switch (c)
        {
        case '\0':
          if (backslash_escapes)
            {
              START_ESC ();
              /* If quote_string were to begin with digits, we'd need to
                 test for the end of the arg as well.  However, it's
                 hard to imagine any locale that would use digits in
                 quotes, and set_custom_quoting is documented not to
                 accept them.  Use only a single \0 with shell-escape
                 as currently digits are not printed within $'...'  */
              if (quoting_style != shell_always_quoting_style
                  && i + 1 < argsize && '0' <= arg[i + 1] && arg[i + 1] <= '9')
                {
                  STORE ('0');
                  STORE ('0');
                }
              c = '0';
              /* We don't have to worry that this last '0' will be
                 backslash-escaped because, again, quote_string should
                 not start with it and because quote_these_too is
                 documented as not accepting it.  */
            }
          else if (flags & QA_ELIDE_NULL_BYTES)
            continue;
          break;

        case '?':
          switch (quoting_style)
            {
            case shell_always_quoting_style:
              if (elide_outer_quotes)
                goto force_outer_quoting_style;
              break;

            case c_quoting_style:
              if ((flags & QA_SPLIT_TRIGRAPHS)
                  && i + 2 < argsize && arg[i + 1] == '?')
                switch (arg[i + 2])
                  {
                  case '!': case '\'':
                  case '(': case ')': case '-': case '/':
                  case '<': case '=': case '>':
                    /* Escape the second '?' in what would otherwise be
                       a trigraph.  */
                    if (elide_outer_quotes)
                      goto force_outer_quoting_style;
                    c = arg[i + 2];
                    i += 2;
                    STORE ('?');
                    STORE ('"');
                    STORE ('"');
                    STORE ('?');
                    break;

                  default:
                    break;
                  }
              break;

            default:
              break;
            }
          break;

        case '\a': esc = 'a'; goto c_escape;
        case '\b': esc = 'b'; goto c_escape;
        case '\f': esc = 'f'; goto c_escape;
        case '\n': esc = 'n'; goto c_and_shell_escape;
        case '\r': esc = 'r'; goto c_and_shell_escape;
        case '\t': esc = 't'; goto c_and_shell_escape;
        case '\v': esc = 'v'; goto c_escape;
        case '\\': esc = c;
          /* Never need to escape '\' in shell case.  */
          if (quoting_style == shell_always_quoting_style)
            {
              if (elide_outer_quotes)
                goto force_outer_quoting_style;
              goto store_c;
            }

          /* No need to escape the escape if we are trying to elide
             outer quotes and nothing else is problematic.  */
          if (backslash_escapes && elide_outer_quotes && quote_string_len)
            goto store_c;

        c_and_shell_escape:
          if (quoting_style == shell_always_quoting_style
              && elide_outer_quotes)
            goto force_outer_quoting_style;
          /* fall through */
        c_escape:
          if (backslash_escapes)
            {
              c = esc;
              goto store_escape;
            }
          break;

        case '{': case '}': /* sometimes special if isolated */
          if (! (argsize == SIZE_MAX ? arg[1] == '\0' : argsize == 1))
            break;
          FALLTHROUGH;
        case '#': case '~':
          if (i != 0)
            break;
          FALLTHROUGH;
        case ' ':
          c_and_shell_quote_compat = true;
          FALLTHROUGH;
        case '!': /* special in bash */
        case '"': case '$': case '&':
        case '(': case ')': case '*': case ';':
        case '<':
        case '=': /* sometimes special in 0th or (with "set -k") later args */
        case '>': case '[':
        case '^': /* special in old /bin/sh, e.g. SunOS 4.1.4 */
        case '`': case '|':
          /* A shell special character.  In theory, '$' and '`' could
             be the first bytes of multibyte characters, which means
             we should check them with mbrtowc, but in practice this
             doesn't happen so it's not worth worrying about.  */
          if (quoting_style == shell_always_quoting_style
              && elide_outer_quotes)
            goto force_outer_quoting_style;
          break;

        case '\'':
          encountered_single_quote = true;
          c_and_shell_quote_compat = true;
          if (quoting_style == shell_always_quoting_style)
            {
              if (elide_outer_quotes)
                goto force_outer_quoting_style;

              if (buffersize && ! orig_buffersize)
                {
                  /* Just scan string to see if supports a more concise
                     representation, rather than writing a longer string
                     but returning the length of the more concise form.  */
                  orig_buffersize = buffersize;
                  buffersize = 0;
                }

              STORE ('\'');
              STORE ('\\');
              STORE ('\'');
              pending_shell_escape_end = false;
            }
          break;

        case '%': case '+': case ',': case '-': case '.': case '/':
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9': case ':':
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
        case 'G': case 'H': case 'I': case 'J': case 'K': case 'L':
        case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
        case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
        case 'Y': case 'Z': case ']': case '_': case 'a': case 'b':
        case 'c': case 'd': case 'e': case 'f': case 'g': case 'h':
        case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
        case 'o': case 'p': case 'q': case 'r': case 's': case 't':
        case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
          /* These characters don't cause problems, no matter what the
             quoting style is.  They cannot start multibyte sequences.
             A digit or a special letter would cause trouble if it
             appeared at the beginning of quote_string because we'd then
             escape by prepending a backslash.  However, it's hard to
             imagine any locale that would use digits or letters as
             quotes, and set_custom_quoting is documented not to accept
             them.  Also, a digit or a special letter would cause
             trouble if it appeared in quote_these_too, but that's also
             documented as not accepting them.  */
          c_and_shell_quote_compat = true;
          break;

        default:
          /* If we have a multibyte sequence, copy it until we reach
             its end, find an error, or come back to the initial shift
             state.  For C-like styles, if the sequence has
             unprintable characters, escape the whole sequence, since
             we can't easily escape single characters within it.  */
          {
            /* Length of multibyte sequence found so far.  */
            size_t m;

            bool printable;

            if (unibyte_locale)
              {
                m = 1;
                printable = isprint (c) != 0;
              }
            else
              {
                mbstate_t mbstate;
                memset (&mbstate, 0, sizeof mbstate);

                m = 0;
                printable = true;
                if (argsize == SIZE_MAX)
                  argsize = strlen (arg);

                do
                  {
                    wchar_t w;
                    size_t bytes = mbrtowc (&w, &arg[i + m],
                                            argsize - (i + m), &mbstate);
                    if (bytes == 0)
                      break;
                    else if (bytes == (size_t) -1)
                      {
                        printable = false;
                        break;
                      }
                    else if (bytes == (size_t) -2)
                      {
                        printable = false;
                        while (i + m < argsize && arg[i + m])
                          m++;
                        break;
                      }
                    else
                      {
                        /* Work around a bug with older shells that "see" a '\'
                           that is really the 2nd byte of a multibyte character.
                           In practice the problem is limited to ASCII
                           chars >= '@' that are shell special chars.  */
                        if ('[' == 0x5b && elide_outer_quotes
                            && quoting_style == shell_always_quoting_style)
                          {
                            size_t j;
                            for (j = 1; j < bytes; j++)
                              switch (arg[i + m + j])
                                {
                                case '[': case '\\': case '^':
                                case '`': case '|':
                                  goto force_outer_quoting_style;

                                default:
                                  break;
                                }
                          }

                        if (! iswprint (w))
                          printable = false;
                        m += bytes;
                      }
                  }
                while (! mbsinit (&mbstate));
              }

            c_and_shell_quote_compat = printable;

            if (1 < m || (backslash_escapes && ! printable))
              {
                /* Output a multibyte sequence, or an escaped
                   unprintable unibyte character.  */
                size_t ilim = i + m;

                for (;;)
                  {
                    if (backslash_escapes && ! printable)
                      {
                        START_ESC ();
                        STORE ('0' + (c >> 6));
                        STORE ('0' + ((c >> 3) & 7));
                        c = '0' + (c & 7);
                      }
                    else if (is_right_quote)
                      {
                        STORE ('\\');
                        is_right_quote = false;
                      }
                    if (ilim <= i + 1)
                      break;
                    END_ESC ();
                    STORE (c);
                    c = arg[++i];
                  }

                goto store_c;
              }
          }
        }

      if (! (((backslash_escapes && quoting_style != shell_always_quoting_style)
              || elide_outer_quotes)
             && quote_these_too
             && quote_these_too[c / INT_BITS] >> (c % INT_BITS) & 1)
          && !is_right_quote)
        goto store_c;

    store_escape:
      START_ESC ();

    store_c:
      END_ESC ();
      STORE (c);

      if (! c_and_shell_quote_compat)
        all_c_and_shell_quote_compat = false;
    }

  if (len == 0 && quoting_style == shell_always_quoting_style
      && elide_outer_quotes)
    goto force_outer_quoting_style;

  /* Single shell quotes (') are commonly enough used as an apostrophe,
     that we attempt to minimize the quoting in this case.  Note itʼs
     better to use the apostrophe modifier "\u02BC" if possible, as that
     renders better and works with the word match regex \W+ etc.  */
  if (quoting_style == shell_always_quoting_style && ! elide_outer_quotes
      && encountered_single_quote)
    {
      if (all_c_and_shell_quote_compat)
        return quotearg_buffer_restyled (buffer, orig_buffersize, arg, argsize,
                                         c_quoting_style,
                                         flags, quote_these_too,
                                         left_quote, right_quote);
      else if (! buffersize && orig_buffersize)
        {
          /* Disable read-only scan, and reprocess to write quoted string.  */
          buffersize = orig_buffersize;
          len = 0;
          goto process_input;
        }
    }

  if (quote_string && !elide_outer_quotes)
    for (; *quote_string; quote_string++)
      STORE (*quote_string);

  if (len < buffersize)
    buffer[len] = '\0';
  return len;

 force_outer_quoting_style:
  /* Don't reuse quote_these_too, since the addition of outer quotes
     sufficiently quotes the specified characters.  */
  if (quoting_style == shell_always_quoting_style && backslash_escapes)
    quoting_style = shell_escape_always_quoting_style;
  return quotearg_buffer_restyled (buffer, buffersize, arg, argsize,
                                   quoting_style,
                                   flags & ~QA_ELIDE_OUTER_QUOTES, NULL,
                                   left_quote, right_quote);
}
