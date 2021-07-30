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

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <lzma.h>

#define uint unsigned int


WCHAR* __stdcall utf8towide (const char *pUTF8);

void
dprintf (char *format, ...);

extern int porcentagem;

extern int intpause;
extern int intcancel;

static __int64 tamanho=0;
static __int64 processado=0;
static int progress=0;
static __int64 getfilesize (char *infile)
{

	uint ret;

	FILE  *myfile;

	if ((myfile = _wfopen (utf8towide(infile), L"rb")) == NULL)
	{
		//dprintf ("The file 'data' was not opened\n");
		return 0;
	}
	else
	{
		//dprintf ("The file 'data' was opened\n");
	}

	ret = fseek (myfile, 0, SEEK_END);

	ret = ftell (myfile);

	// dprintf ("tamanho do arquivo %d\n ", ret);

	fclose (myfile);

	// printf ("Tamanho do arquivo %s  %d \n", infile, ret);

	return ret;


}

int xz_uncompression_progress()
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

static uint getpor (__int64 max, __int64 fatia)
{


	double maxa;
	double fatiaa;

	maxa = (double) max;
	fatiaa = (double) fatia;

	if (max == 0)
	{
		return 0;
	}

	maxa = ((double) 10000 / maxa * fatiaa);

	return (uint) maxa;
}

static bool
init_decoder(lzma_stream *strm)
{
	// Initialize a .xz decoder. The decoder supports a memory usage limit
	// and a set of flags.
	//
	// The memory usage of the decompressor depends on the settings used
	// to compress a .xz file. It can vary from less than a megabyte to
	// a few gigabytes, but in practice (at least for now) it rarely
	// exceeds 65 MiB because that's how much memory is required to
	// decompress files created with "xz -9". Settings requiring more
	// memory take extra effort to use and don't (at least for now)
	// provide significantly better compression in most cases.
	//
	// Memory usage limit is useful if it is important that the
	// decompressor won't consume gigabytes of memory. The need
	// for limiting depends on the application. In this example,
	// no memory usage limiting is used. This is done by setting
	// the limit to UINT64_MAX.
	//
	// The .xz format allows concatenating compressed files as is:
	//
	//     echo foo | xz > foobar.xz
	//     echo bar | xz >> foobar.xz
	//
	// When decompressing normal standalone .xz files, LZMA_CONCATENATED
	// should always be used to support decompression of concatenated
	// .xz files. If LZMA_CONCATENATED isn't used, the decoder will stop
	// after the first .xz stream. This can be useful when .xz data has
	// been embedded inside another file format.
	//
	// Flags other than LZMA_CONCATENATED are supported too, and can
	// be combined with bitwise-or. See lzma/container.h
	// (src/liblzma/api/lzma/container.h in the source package or e.g.
	// /usr/include/lzma/container.h depending on the install prefix)
	// for details.
	lzma_ret ret = lzma_stream_decoder(
		strm, UINT64_MAX, LZMA_CONCATENATED);

	// Return successfully if the initialization went fine.
	if (ret == LZMA_OK)
		return true;

	// Something went wrong. The possible errors are documented in
	// lzma/container.h (src/liblzma/api/lzma/container.h in the source
	// package or e.g. /usr/include/lzma/container.h depending on the
	// install prefix).
	//
	// Note that LZMA_MEMLIMIT_ERROR is never possible here. If you
	// specify a very tiny limit, the error will be delayed until
	// the first headers have been parsed by a call to lzma_code().
	const char *msg;
	switch (ret) {
	case LZMA_MEM_ERROR:
		msg = "Memory allocation failed";
		break;

	case LZMA_OPTIONS_ERROR:
		msg = "Unsupported decompressor flags";
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

	fprintf(stderr, "Error initializing the decoder: %s (error code %u)\n",
	        msg, ret);
	return false;
}


static bool
decompress(lzma_stream *strm, FILE *infile, FILE *outfile)
{
	// When LZMA_CONCATENATED flag was used when initializing the decoder,
	// we need to tell lzma_code() when there will be no more input.
	// This is done by setting action to LZMA_FINISH instead of LZMA_RUN
	// in the same way as it is done when encoding.
	//
	// When LZMA_CONCATENATED isn't used, there is no need to use
	// LZMA_FINISH to tell when all the input has been read, but it
	// is still OK to use it if you want. When LZMA_CONCATENATED isn't
	// used, the decoder will stop after the first .xz stream. In that
	// case some unused data may be left in strm->next_in.
	lzma_action action = LZMA_RUN;

	uint8_t inbuf[BUFSIZ];
	uint8_t outbuf[BUFSIZ];

	strm->next_in = NULL;
	strm->avail_in = 0;
	strm->next_out = outbuf;
	strm->avail_out = sizeof(outbuf);

	while (true) {
		if (strm->avail_in == 0 && !feof(infile)) {
			strm->next_in = inbuf;
			strm->avail_in = fread(inbuf, 1, sizeof(inbuf),
			                       infile);




			while (intpause)
			{


				Sleep (50);

				if (intcancel)
				{
					goto saida;
				}


			}

			if (intcancel)
			{
				goto saida;
			}

			processado+=strm->avail_in;

			progress=getpor(tamanho,processado);


			if(progress<0)
			{
				progress=0;
			}

			if(progress>10000)
			{
				progress=10000;
			}

			//rintf("progress %03d\r",progress);



			porcentagem=progress;







			if (ferror(infile)) {
				fprintf(stderr, "%s: Read error: \n",
				        strerror(errno));
				return false;
			}

			// Once the end of the input file has been reached,
			// we need to tell lzma_code() that no more input
			// will be coming. As said before, this isn't required
			// if the LZMA_CONCATENATED flag isn't used when
			// initializing the decoder.
			if (feof(infile))
				action = LZMA_FINISH;
		}

		lzma_ret ret = lzma_code(strm, action);

		if (strm->avail_out == 0 || ret == LZMA_STREAM_END) {
			size_t write_size = sizeof(outbuf) - strm->avail_out;

			if (fwrite(outbuf, 1, write_size, outfile)
			    != write_size) {
				fprintf(stderr, "Write error: %s\n",
				        strerror(errno));
				return false;
			}

			strm->next_out = outbuf;
			strm->avail_out = sizeof(outbuf);
		}

		if (ret != LZMA_OK) {
			// Once everything has been decoded successfully, the
			// return value of lzma_code() will be LZMA_STREAM_END.
			//
			// It is important to check for LZMA_STREAM_END. Do not
			// assume that getting ret != LZMA_OK would mean that
			// everything has gone well or that when you aren't
			// getting more output it must have successfully
			// decoded everything.
			if (ret == LZMA_STREAM_END)
				return true;

			// It's not LZMA_OK nor LZMA_STREAM_END,
			// so it must be an error code. See lzma/base.h
			// (src/liblzma/api/lzma/base.h in the source package
			// or e.g. /usr/include/lzma/base.h depending on the
			// install prefix) for the list and documentation of
			// possible values. Many values listen in lzma_ret
			// enumeration aren't possible in this example, but
			// can be made possible by enabling memory usage limit
			// or adding flags to the decoder initialization.
			const char *msg;
			switch (ret) {
			case LZMA_MEM_ERROR:
				msg = "Memory allocation failed";
				break;

			case LZMA_FORMAT_ERROR:
				// .xz magic bytes weren't found.
				msg = "The input is not in the .xz format";
				break;

			case LZMA_OPTIONS_ERROR:
				// For example, the headers specify a filter
				// that isn't supported by this liblzma
				// version (or it hasn't been enabled when
				// building liblzma, but no-one sane does
				// that unless building liblzma for an
				// embedded system). Upgrading to a newer
				// liblzma might help.
				//
				// Note that it is unlikely that the file has
				// accidentally became corrupt if you get this
				// error. The integrity of the .xz headers is
				// always verified with a CRC32, so
				// unintentionally corrupt files can be
				// distinguished from unsupported files.
				msg = "Unsupported compression options";
				break;

			case LZMA_DATA_ERROR:
				msg = "Compressed file is corrupt";
				break;

			case LZMA_BUF_ERROR:
				// Typically this error means that a valid
				// file has got truncated, but it might also
				// be a damaged part in the file that makes
				// the decoder think the file is truncated.
				// If you prefer, you can use the same error
				// message for this as for LZMA_DATA_ERROR.
				msg = "Compressed file is truncated or "
				      "otherwise corrupt";
				break;

			default:
				// This is most likely LZMA_PROG_ERROR.
				msg = "Unknown error, possibly a bug";
				break;
			}

			fprintf(stderr, "%s: Decoder error: "
			        " (error code %u)\n",
			        msg, ret);
			return false;
		}
	}
saida:
	;
	return false;
}


int
xz_uncompress(char*inputfile,char*outputfile)
{
	int returnvalue=0;
	lzma_stream strm = LZMA_STREAM_INIT;

	bool success = true;


	FILE *input=NULL;
	FILE *output=NULL;

	progress=porcentagem=0;
	tamanho=getfilesize(inputfile);
	processado=0;
	input=_wfopen (utf8towide(inputfile), L"rb");
	if(NULL==input)
	{
		returnvalue=1;//cannot open input file
		goto saida;
	}
	output=_wfopen (utf8towide(outputfile), L"wb");
	if(NULL==output)
	{
		returnvalue=2;//cannot open output file
		goto saida;
	}



	// Try to decompress all files.

	if (!init_decoder(&strm))
	{
		// Decoder initialization failed. There's no point
		// to retry it so we need to exit.
		success = false;
		returnvalue=3;
		goto final;
	}

	success = decompress(&strm,  input, output);
	if(!success)
	{
		returnvalue=4;
	}



	// Free the memory allocated for the decoder.

final:
	;

	lzma_end(&strm);



saida:
	;
	if(input)
	{
		fclose(input);
	}
	if(output)
	{
		fclose(output);
	}
	progress=porcentagem=10000;
	return returnvalue;
}



int
xz_uncompress(char*inputfile,char*outputfile);


#ifdef DEBUGME
int main(int argc,  char**argv)
{
	int level;
	int ret=0;
	printf("argc %d\n",argc);
	assert(3==argc);

	printf("level final %d\n",level);

	ret=
		xz_uncompress(argv[1],argv[2]);
	if(ret)
		printf("retornou %d\n",ret);
	return ret;
}

#endif
