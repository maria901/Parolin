
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

#include <windows.h>
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

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <lzma.h>

#define uint unsigned int

extern int porcentagem;

int threads_z = 1; //default

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we 
 *  . provide two functions that are exactly the same because someone may 
 * use it in multi-thread code 
 *
 * @param pUTF8 the input utf-8 encoded filename 
 *
 * @return the static allocated WCHAR array with the filename as wide string 
 *
 */
WCHAR *amanda_utf8towide_1_v27(char *pUTF8);

void dprintf(char *format, ...);

void pedro_dprintf(
    int amanda_level,
    char *format, ...);

extern int intpause;
extern int intcancel;

static __int64 tamanho = 0;
static __int64 processado = 0;
static int progress = 0;
/**
 * wide aware...
 * 
 * 
 */
static __int64 getfilesize(char *infile)
{

      __int64 ret;

      FILE *myfile;

      if ((myfile = _wfopen(amanda_utf8towide_1_v27(infile), L"rb")) == NULL)
      {
            //dprintf ("The file 'data' was not opened\n");
            return 0;
      }
      else
      {
            //dprintf ("The file 'data' was opened\n");
      }

      ret = _fseeki64(myfile, 0, SEEK_END);

      ret = _ftelli64(myfile);

      // dprintf ("tamanho do arquivo %d\n ", ret);

      fclose(myfile);

      // printf ("Tamanho do arquivo %s  %d \n", infile, ret);

      return ret;
}
/*
int xz_compression_progress()
{
	int val=progress;

	if(val<0)
	{
		val=0;
	}

	if(val>10000)
	{
		val=10000;
	}
	return val;
}
*/
static uint getpor(__int64 max, __int64 fatia)
{

      double maxa;
      double fatiaa;

      maxa = (double)max;
      fatiaa = (double)fatia;

      if (max == 0)
      {
            return 0;
      }

      maxa = ((double)10000 / maxa * fatiaa);

      return (uint)maxa;
}

static void
show_usage_and_exit(const char *argv0)
{
      fprintf(stderr, "Usage: %s PRESET < INFILE > OUTFILE\n"
                      "PRESET is a number 0-9 and can optionally be "
                      "followed by `e' to indicate extreme preset\n",
              argv0);
      exit(EXIT_FAILURE);
}

static uint32_t
get_preset(int argc, char **argv)
{
      // One argument whose first char must be 0-9.
      if (argc != 2 || argv[1][0] < '0' || argv[1][0] > '9')
            show_usage_and_exit(argv[0]);

      // Calculate the preste level 0-9.
      uint32_t preset = argv[1][0] - '0';

      // If there is a second char, it must be 'e'. It will set
      // the LZMA_PRESET_EXTREME flag.
      if (argv[1][1] != '\0')
      {
            if (argv[1][1] != 'e' || argv[1][2] != '\0')
                  show_usage_and_exit(argv[0]);

            preset |= LZMA_PRESET_EXTREME;
      }

      return preset;
}

static bool
init_encoder_multi_thread_z(lzma_stream *strm)
{

      pedro_dprintf(-1, "Modo multi thread\n");

      // The threaded encoder takes the options as pointer to
      // a lzma_mt structure.
      lzma_mt mt = {
          // No flags are needed.
          .flags = 0,

          // Let liblzma determine a sane block size.
          .block_size = 0,

          // Use no timeout for lzma_code() calls by setting timeout
          // to zero. That is, sometimes lzma_code() might block for
          // a long time (from several seconds to even minutes).
          // If this is not OK, for example due to progress indicator
          // needing updates, specify a timeout in milliseconds here.
          // See the documentation of lzma_mt in lzma/container.h for
          // information how to choose a reasonable timeout.
          .timeout = 0,

          // Use the default preset (6) for LZMA2.
          // To use a preset, filters must be set to NULL.
          .preset = LZMA_PRESET_DEFAULT,
          .filters = NULL,

          // Use CRC64 for integrity checking. See also
          // 01_compress_easy.c about choosing the integrity check.
          .check = LZMA_CHECK_CRC64,
      };

      // Detect how many threads the CPU supports.
      mt.threads = lzma_cputhreads();

      pedro_dprintf(-1, "threads got %d\n", (int)mt.threads);

      // If the number of CPU cores/threads cannot be detected,
      // use one thread. Note that this isn't the same as the normal
      // single-threaded mode as this will still split the data into
      // blocks and use more RAM than the normal single-threaded mode.
      // You may want to consider using lzma_easy_encoder() or
      // lzma_stream_encoder() instead of lzma_stream_encoder_mt() if
      // lzma_cputhreads() returns 0 or 1.
      if (mt.threads == 0)
            mt.threads = 1;

      if (0 != threads_z)
      {
            mt.threads = threads_z;
      }

      pedro_dprintf(-1, "threads set %d\n", mt.threads);

      // If the number of CPU cores/threads exceeds threads_max,
      // limit the number of threads to keep memory usage lower.
      // The number 8 is arbitrarily chosen and may be too low or
      // high depending on the compression preset and the computer
      // being used.
      //
      // FIXME: A better way could be to check the amount of RAM
      // (or available RAM) and use lzma_stream_encoder_mt_memusage()
      // to determine if the number of threads should be reduced.
      const uint32_t threads_max = 8;
      if (mt.threads > threads_max)
            mt.threads = threads_max;

      // Initialize the threaded encoder.
      lzma_ret ret = lzma_stream_encoder_mt(strm, &mt);

      if (ret == LZMA_OK)
            return true;

      const char *msg;
      switch (ret)
      {
      case LZMA_MEM_ERROR:
            msg = "Memory allocation failed";
            break;

      case LZMA_OPTIONS_ERROR:
            // We are no longer using a plain preset so this error
            // message has been edited accordingly compared to
            // 01_compress_easy.c.
            msg = "Specified filter chain is not supported";
            break;

      case LZMA_UNSUPPORTED_CHECK:
            msg = "Specified integrity check is not supported";
            break;

      default:
            msg = "Unknown error, possibly a bug";
            break;
      }

      pedro_dprintf(-1, "Error initializing the encoder: %s (error code %u)\n",
                    msg, ret);
      return false;
}

static bool
init_encoder(lzma_stream *strm, uint32_t preset)
{

      pedro_dprintf(-1, "Modo single thread\n");

      // Initialize the encoder using a preset. Set the integrity to check
      // to CRC64, which is the default in the xz command line tool. If
      // the .xz file needs to be decompressed with XZ Embedded, use
      // LZMA_CHECK_CRC32 instead.
      lzma_ret ret = lzma_easy_encoder(strm, preset, LZMA_CHECK_CRC64);

      // Return successfully if the initialization went fine.
      if (ret == LZMA_OK)
            return true;

      // Something went wrong. The possible errors are documented in
      // lzma/container.h (src/liblzma/api/lzma/container.h in the source
      // package or e.g. /usr/include/lzma/container.h depending on the
      // install prefix).
      const char *msg;
      switch (ret)
      {
      case LZMA_MEM_ERROR:
            msg = "Memory allocation failed";
            break;

      case LZMA_OPTIONS_ERROR:
            msg = "Specified preset is not supported";
            break;

      case LZMA_UNSUPPORTED_CHECK:
            msg = "Specified integrity check is not supported";
            break;

      default:
            // This is most likely LZMA_PROG_ERROR indicating a bug in
            // this program or in liblzma. It is inconvenient to have a
            // separate error message for errors that should be impossible
            // to occur, but knowing the error code is important for
            // debugging. That's why it is good to print the error code
            // at least when there is no good error message to show.
            msg = "Unknown error, possibly a bug";
            break;
      }

      fprintf(stderr, "Error initializing the encoder: %s (error code %u)\n",
              msg, ret);
      return false;
}

static bool
compress(lzma_stream *strm, FILE *infile, FILE *outfile)
{
      // This will be LZMA_RUN until the end of the input file is reached.
      // This tells lzma_code() when there will be no more input.
      lzma_action action = LZMA_RUN;

      pedro_dprintf(-1, "Entrou\n");

      // Buffers to temporarily hold uncompressed input
      // and compressed output.
      uint8_t inbuf[BUFSIZ];
      uint8_t outbuf[BUFSIZ];

      // Initialize the input and output pointers. Initializing next_in
      // and avail_in isn't really necessary when we are going to encode
      // just one file since LZMA_STREAM_INIT takes care of initializing
      // those already. But it doesn't hurt much and it will be needed
      // if encoding more than one file like we will in 02_decompress.c.
      //
      // While we don't care about strm->total_in or strm->total_out in this
      // example, it is worth noting that initializing the encoder will
      // always reset total_in and total_out to zero. But the encoder
      // initialization doesn't touch next_in, avail_in, next_out, or
      // avail_out.
      strm->next_in = NULL;
      strm->avail_in = 0;
      strm->next_out = outbuf;
      strm->avail_out = sizeof(outbuf);

      // Loop until the file has been successfully compressed or until
      // an error occurs.
      while (true)
      {
            // Fill the input buffer if it is empty.
            if (strm->avail_in == 0 && !feof(infile))
            {
                  strm->next_in = inbuf;
                  strm->avail_in = fread(inbuf, 1, sizeof(inbuf),
                                         infile);
                  processado += strm->avail_in;

                  while (intpause)
                  {

                        Sleep(50);

                        if (intcancel)
                        {
                              goto saida;
                        }
                  }

                  if (intcancel)
                  {
                        goto saida;
                  }

                  progress = getpor(tamanho, processado);

                  if (progress < 0)
                  {
                        progress = 0;
                  }

                  if (progress > 10000)
                  {
                        progress = 10000;
                  }

                  porcentagem = progress;

                  //printf("progress %03d\r",progress);

                  if (ferror(infile))
                  {
                        fprintf(stderr, "Read error: %s\n",
                                strerror(errno));

                        pedro_dprintf(-1, "erro aqui 2\n");

                        return false;
                  }

                  // Once the end of the input file has been reached,
                  // we need to tell lzma_code() that no more input
                  // will be coming and that it should finish the
                  // encoding.
                  if (feof(infile))
                        action = LZMA_FINISH;
            }

            // Tell liblzma do the actual encoding.
            //
            // This reads up to strm->avail_in bytes of input starting
            // from strm->next_in. avail_in will be decremented and
            // next_in incremented by an equal amount to match the
            // number of input bytes consumed.
            //
            // Up to strm->avail_out bytes of compressed output will be
            // written starting from strm->next_out. avail_out and next_out
            // will be incremented by an equal amount to match the number
            // of output bytes written.
            //
            // The encoder has to do internal buffering, which means that
            // it may take quite a bit of input before the same data is
            // available in compressed form in the output buffer.
            lzma_ret ret = lzma_code(strm, action);

            // If the output buffer is full or if the compression finished
            // successfully, write the data from the output buffer to
            // the output file.
            if (strm->avail_out == 0 || ret == LZMA_STREAM_END)
            {
                  // When lzma_code() has returned LZMA_STREAM_END,
                  // the output buffer is likely to be only partially
                  // full. Calculate how much new data there is to
                  // be written to the output file.
                  size_t write_size = sizeof(outbuf) - strm->avail_out;

                  if (fwrite(outbuf, 1, write_size, outfile) != write_size)
                  {
                        pedro_dprintf(-1, "Write error: %s\n",
                                      strerror(errno));
                        return false;
                  }

                  // Reset next_out and avail_out.
                  strm->next_out = outbuf;
                  strm->avail_out = sizeof(outbuf);
            }

            // Normally the return value of lzma_code() will be LZMA_OK
            // until everything has been encoded.
            if (ret != LZMA_OK)
            {
                  // Once everything has been encoded successfully, the
                  // return value of lzma_code() will be LZMA_STREAM_END.
                  //
                  // It is important to check for LZMA_STREAM_END. Do not
                  // assume that getting ret != LZMA_OK would mean that
                  // everything has gone well.
                  if (ret == LZMA_STREAM_END)
                        return true;

                  // It's not LZMA_OK nor LZMA_STREAM_END,
                  // so it must be an error code. See lzma/base.h
                  // (src/liblzma/api/lzma/base.h in the source package
                  // or e.g. /usr/include/lzma/base.h depending on the
                  // install prefix) for the list and documentation of
                  // possible values. Most values listen in lzma_ret
                  // enumeration aren't possible in this example.
                  const char *msg;
                  switch (ret)
                  {
                  case LZMA_MEM_ERROR:
                        msg = "Memory allocation failed";
                        break;

                  case LZMA_DATA_ERROR:
                        // This error is returned if the compressed
                        // or uncompressed size get near 8 EiB
                        // (2^63 bytes) because that's where the .xz
                        // file format size limits currently are.
                        // That is, the possibility of this error
                        // is mostly theoretical unless you are doing
                        // something very unusual.
                        //
                        // Note that strm->total_in and strm->total_out
                        // have nothing to do with this error. Changing
                        // those variables won't increase or decrease
                        // the chance of getting this error.
                        msg = "File size limits exceeded";
                        break;

                  default:
                        // This is most likely LZMA_PROG_ERROR, but
                        // if this program is buggy (or liblzma has
                        // a bug), it may be e.g. LZMA_BUF_ERROR or
                        // LZMA_OPTIONS_ERROR too.
                        //
                        // It is inconvenient to have a separate
                        // error message for errors that should be
                        // impossible to occur, but knowing the error
                        // code is important for debugging. That's why
                        // it is good to print the error code at least
                        // when there is no good error message to show.
                        msg = "Unknown error, possibly a bug";
                        break;
                  }

                  pedro_dprintf(-1, "Encoder error: %s (error code %u)\n",
                                msg, ret);
                  return false;
            }
      }

saida:;
      pedro_dprintf(-1, "erro aqui 1\n");
      return false;
}

int xz_compress(char *inputfile, char *outputfile, int level);

/**

function to compress files in the standard .xz format
the level range from 0 to 9, 9 to best compression

xz files can be decompressed with Winrar

*/
int xz_compress(char *inputfile, char *outputfile, int level)
{
      // Get the preset number from the command line.

      uint32_t preset = level; //get_preset(argc, argv);
                               /*
	if(preset<0)
	{
		dprintf("preset fix to down\n");
		preset=0;
	}
*/
      if (preset > 9)
      {
            dprintf("preset fix to up\n");
            preset = 9;
      }

      int returnvalue = 0;
      FILE *input = NULL;
      FILE *output = NULL;

      progress = 0;
      porcentagem = 0;
      tamanho = getfilesize(inputfile);

      if (1 != threads_z)
      {
            int64_t temp_arp;

            temp_arp = tamanho / 20;

            tamanho += temp_arp;
      }

      processado = 0;
      input = _wfopen(amanda_utf8towide_1_v27(inputfile), L"rb");
      if (NULL == input)
      {
            returnvalue = 1; //cannot open input file
            goto saida;
      }
      output = _wfopen(amanda_utf8towide_1_v27(outputfile), L"wb");
      if (NULL == output)
      {
            returnvalue = 2; //cannot open output file
            goto saida;
      }

      dprintf("preset %d\n", preset);
      // Initialize a lzma_stream structure. When it is allocated on stack,
      // it is simplest to use LZMA_STREAM_INIT macro like below. When it
      // is allocated on heap, using memset(strmptr, 0, sizeof(*strmptr))
      // works (as long as NULL pointers are represented with zero bits
      // as they are on practically all computers today).
      lzma_stream strm = LZMA_STREAM_INIT;

      // Initialize the encoder. If it succeeds, compress
      //bool success = init_encoder(&strm, preset);

      bool success;

      //success = init_encoder_multi_thread_z(&strm);
      if (1 == threads_z)
      {
            success = init_encoder(&strm, preset);
      }
      else
      {
            success = init_encoder_multi_thread_z(&strm);
      }

      if (success)
      {
            success = compress(&strm, input, output);
      }
      else
      {
            returnvalue = 3;
      }

      // Free the memory allocated for the encoder. If we were encoding
      // multiple files, this would only need to be done after the last
      // file. See 02_decompress.c for handling of multiple files.
      //
      // It is OK to call lzma_end() multiple times or when it hasn't been
      // actually used except initialized with LZMA_STREAM_INIT.
      lzma_end(&strm);

saida:;
      if (input)
      {
            fclose(input);
      }
      if (output)
      {
            fclose(output);
      }
      progress = 10000;
      porcentagem = 10000;
      return returnvalue;
}
#ifdef DEBUGME
int main(int argc, char **argv)
{
      int level;
      int ret = 0;
      printf("argc %d\n", argc);
      assert(4 == argc);

      level = strtol(argv[1], NULL, 10);

      printf("level got %d\n", level);

      /*
	   if(9==level)
	   {
	        level|=LZMA_PRESET_EXTREME;
	   }

	 */

      printf("level final %d\n", level);

      ret =
          xz_compress(argv[2], argv[3], level);

      return 0;
}

#endif
