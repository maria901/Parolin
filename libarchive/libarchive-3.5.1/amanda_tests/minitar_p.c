//2021 amanda & MathMan  April 24

 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *                                                                                *
  *      Licensa de Cópia (C) <202*>  <Corporação do Trabalho Binário>             *
  *                                                                                *
  *   Este programa é software livre: você pode redistribuir isto e/ou modificar   *
  *   isto sobre os termos do GNU Licensa Geral Pública como publicado pela        *
  *   Fundação de Software Livre, tanto a versão 3 da Licensa, ou                  *
  *   (dependendo da sua opção) qualquer versão posterior.                         *
  *                                                                                *
  *   Este programa é distribuído na esperança que isto vai ser útil,              *
  *   mas SEM QUALQUER GARANTIA; sem até mesmo a implicada garantia de             *
  *   COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a                 *
  *   Licensa Geral Pública para mais detalhes.                                    *
  *                                                                                *
  *   Você deve ter recebido uma cópia da LICENSA GERAL PUBLICA                    *
  *       e a GNU Licensa Pública Menor junto com este programa                    *
  *       Se não, veja <http://www.gnu.org/licenses/>.                             *
  *                                                                                *
  *   Suporte: https://arsoftware.net.br/binarywork ____________________           *
  *   Mirrors: https://locacaodiaria.com.br/corporacaodotrabalhobinario/           *
  *             http://nomade.sourceforge.net/binarywork/ ______________            *
  *                                                                                *
  *       e-mails direto dos felizes programadores:                                *
  *       MathMan: arsoftware25@gmail.com  ricardo@arsoftware.net.br               *
  *        Amanda: arsoftware10@gmail.com  amanda@arsoftware.net.br                *
  *                                                                                *
  *       contato imediato(para uma resposta muita rápida) WhatsApp                *
  *       (+55)41 9627 1708 - isto está sempre ligado                              *
  *                                                                                *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
  
/*-
 * This file is in the public domain.
 * Do with it as you will., ok, as you wish
 */

/*-
 * This is a compact "tar" program whose primary goal is small size.
 * Statically linked, it can be very small indeed.  This serves a number
 * of goals:
 *   o a testbed for libarchive (to check for link pollution),
 *   o a useful tool for space-constrained systems (boot floppies, etc),
 *   o a place to experiment with new implementation ideas for bsdtar,
 *   o a small program to demonstrate libarchive usage.
 *
 * Use the following macros to suppress features:
 *   NO_BZIP2 - Implies NO_BZIP2_CREATE and NO_BZIP2_EXTRACT
 *   NO_BZIP2_CREATE - Suppress bzip2 compression support.
 *   NO_BZIP2_EXTRACT - Suppress bzip2 auto-detection and decompression.
 *   NO_COMPRESS - Implies NO_COMPRESS_CREATE and NO_COMPRESS_EXTRACT
 *   NO_COMPRESS_CREATE - Suppress compress(1) compression support
 *   NO_COMPRESS_EXTRACT - Suppress compress(1) auto-detect and decompression.
 *   NO_CREATE - Suppress all archive creation support.
 *   NO_CPIO_EXTRACT - Suppress auto-detect and dearchiving of cpio archives.
 *   NO_GZIP - Implies NO_GZIP_CREATE and NO_GZIP_EXTRACT
 *   NO_GZIP_CREATE - Suppress gzip compression support.
 *   NO_GZIP_EXTRACT - Suppress gzip auto-detection and decompression.
 *   NO_LOOKUP - Try to avoid getpw/getgr routines, which can be very large
 *   NO_TAR_EXTRACT - Suppress tar extraction
 *
 * With all of the above macros defined (except NO_TAR_EXTRACT), you
 * get a very small program that can recognize and extract essentially
 * any uncompressed tar archive.  On FreeBSD 5.1, this minimal program
 * is under 64k, statically linked, which compares rather favorably to
 *         main(){printf("hello, world");}
 * which is over 60k statically linked on the same operating system.
 * Without any of the above macros, you get a static executable of
 * about 180k with a lot of very sophisticated modern features.
 * Obviously, it's trivial to add support for ISO, Zip, mtree,
 * lzma/xz, etc.  Just fill in the appropriate setup calls.
 */

#include  <windows.h>
#include   <stdint.h>
#include    <stdio.h>
#include   <stdlib.h>
#include   <string.h>
#include     <time.h>
#include    <errno.h>
#include    <fcntl.h>
#include    <ctype.h>
#include     <math.h>
#include   <wctype.h>
#include    <wchar.h>
#include   <stdarg.h>
#include   <stddef.h>
#include   <setjmp.h>
#include   <locale.h>
#include   <signal.h>
#include   <limits.h>
#include    <float.h>
#include   <iso646.h>

#undef NDEBUG
#include   <assert.h>

#include  <stdbool.h>

#include  <process.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

#include <sys/types.h>
#include <sys/stat.h>

FILE * my_temp_file_i_i;

extern int64_t attributes_i;

typedef int  (__stdcall * init_playlist_z_june_24_i)(void);
typedef void (__stdcall * add_more_one_z_june_24_i)
(
     time_t  atime_i           ,
     time_t  mtime_i           ,
     time_t  birthtime_i       ,
     int64_t filesize_i        ,
     int64_t file_offset_i     ,
     char *  item_entry_i      ,
     bool    is_dir_i          ,
     bool    in_use_i          ,
     int64_t attributes_i
     );

time_t  atime_ii;
time_t  mtime_ii;
time_t  birthtime_ii;
int64_t filesize_ii;
int64_t file_offset_ii;
bool    is_dir_ii;

extern time_t  atime_iii;
extern time_t  mtime_iii;
extern time_t  birthtime_iii;

typedef int (__stdcall * check_item_z_june_24_i)(char * filename_utf8);

init_playlist_z_june_24_i init_playlist_z_june_24_iii;
add_more_one_z_june_24_i   add_more_one_z_june_24_iii;
check_item_z_june_24_i       check_item_z_june_24_iii;

static int64_t *bytes_read_p = 0;

WCHAR * amanda_utf8towide_1_(char *pUTF8);

bool do_it_i;

char filename_copy_i[1027];

extern int use_hack_i;
int    use_hack_internal_i = 0;

extern char temp_path_23_june_i[];

extern int number_of_threads_p;

int64_t bytes_saved_i;

extern int disable_utf_8_p;

extern int debug_mode_i;

char temp__file_i[1027];

//0 = show debug
#define USE_PEDRO_DPRINTF 0

#include <archive.h>
#include <archive_entry.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <zlib.h>
#include <bzlib.h>
#include <lzma.h>

static void
mprintf___arp(char *format, ...)
{
	char *     buffer = calloc(1, 10000);    //for multithread sake
	va_list amanda_do_ricardo;

	va_start(amanda_do_ricardo, format);
	vsprintf(buffer, format, amanda_do_ricardo);
	va_end(amanda_do_ricardo);
	MessageBox(0, buffer, "BW Error", MB_OK |
	           MB_ICONERROR | MB_SYSTEMMODAL);
	free(buffer);
}

/*
 * NO_CREATE implies NO_BZIP2_CREATE and NO_GZIP_CREATE and NO_COMPRESS_CREATE.
 */
#ifdef NO_CREATE
#undef NO_BZIP2_CREATE
#define NO_BZIP2_CREATE
#undef NO_COMPRESS_CREATE
#define NO_COMPRESS_CREATE
#undef NO_GZIP_CREATE
#define NO_GZIP_CREATE
#endif

/*
 * The combination of NO_BZIP2_CREATE and NO_BZIP2_EXTRACT is
 * equivalent to NO_BZIP2.
 */
#ifdef NO_BZIP2_CREATE
#ifdef NO_BZIP2_EXTRACT
#undef NO_BZIP2
#define NO_BZIP2
#endif
#endif

#ifdef NO_BZIP2
#undef NO_BZIP2_EXTRACT
#define NO_BZIP2_EXTRACT
#undef NO_BZIP2_CREATE
#define NO_BZIP2_CREATE
#endif

extern char real_input_utf_8_i[];
extern char real_input_utf_8_i_2[];
extern char real_input_utf_8_i_3[];
extern char destination_path_utf_8_i[];
extern char real_input_utf_8_i_extract_2[];
extern int64_t fix_it_i;
/*
 * The combination of NO_COMPRESS_CREATE and NO_COMPRESS_EXTRACT is
 * equivalent to NO_COMPRESS.
 */
#ifdef NO_COMPRESS_CREATE
#ifdef NO_COMPRESS_EXTRACT
#undef NO_COMPRESS
#define NO_COMPRESS
#endif
#endif

#ifdef NO_COMPRESS
#undef NO_COMPRESS_EXTRACT
#define NO_COMPRESS_EXTRACT
#undef NO_COMPRESS_CREATE
#define NO_COMPRESS_CREATE
#endif

/*
 * The combination of NO_GZIP_CREATE and NO_GZIP_EXTRACT is
 * equivalent to NO_GZIP.
 */
#ifdef NO_GZIP_CREATE
#ifdef NO_GZIP_EXTRACT
#undef NO_GZIP
#define NO_GZIP
#endif
#endif

#ifdef NO_GZIP
#undef NO_GZIP_EXTRACT
#define NO_GZIP_EXTRACT
#undef NO_GZIP_CREATE
#define NO_GZIP_CREATE
#endif

#ifndef NO_CREATE
static void     create(const char *filename, int compress, const char **argv);
#endif
static void     errmsg(const char *);
static void     extract(const char *filename, int do_extract, int flags);
static int      copy_data(struct archive *, struct archive *);
static void     msg(const char *);
static void     usage(void);

static int verbose = 0;

extern int wide_fix_p;

static bool fatal_error_p = false;

int
main(int argc, const char **argv)
{
	const char *filename = NULL;
	int compress, flags, mode, opt;

	(void)argc;
	mode = 'x';
	verbose = 0;
	compress = '\0';
	flags = ARCHIVE_EXTRACT_TIME;
	fprintf(stderr, "dentro\n");
	fflush(stderr);
	/* Among other sins, getopt(3) pulls in printf(3). */
	while (*++argv != NULL && **argv == '-')
	{
		const char *p = *argv + 1;

		while ((opt = *p++) != '\0')
		{
			switch (opt)
			{
#ifndef NO_CREATE
			case 'c':
				mode = opt;
				break;
#endif
			case 'f':
				if (*p != '\0')
					filename = p;
				else
					filename = *++argv;
				p += strlen(p);
				break;
#ifndef NO_BZIP2_CREATE
			case 'j':
				compress = opt;
				break;
#endif
			case 'p':
				flags |= ARCHIVE_EXTRACT_PERM;
				flags |= ARCHIVE_EXTRACT_ACL;
				flags |= ARCHIVE_EXTRACT_FFLAGS;
				break;
			case 't':
				mode = opt;
				break;
			case 'v':
				verbose++;
				break;
			case 'x':
				mode = opt;
				break;
#ifndef NO_BZIP2_CREATE
			case 'y':
				compress = opt;
				break;
#endif
#ifndef NO_COMPRESS_CREATE
			case 'Z':
				compress = opt;
				break;
#endif
#ifndef NO_GZIP_CREATE
			case 'z':
				compress = opt;
				break;
#endif
			default:

				fprintf(stderr, "Usage\n");
				fflush(stderr);

				usage();
			}
		}
	}

	fprintf(stderr, "dentro 2 %p\n", filename);
	fflush(stderr);

	switch (mode)
	{
#ifndef NO_CREATE
	case 'c':
		fprintf(stderr, "dentro 4 %p\n", filename);
		fflush(stderr);
		create(filename, compress, argv);
		break;
#endif
	case 't':
		fprintf(stderr, "dentro 5 %p\n", filename);
		fflush(stderr);
		extract(filename, 0, flags);
		break;
	case 'x':
		fprintf(stderr, "dentro 6 %p\n", filename);
		fflush(stderr);
		extract(filename, 1, flags);
		break;
	}
	fprintf(stderr, "dentro 3 %p\n", filename);
	fflush(stderr);
	return (0);
}


#ifndef NO_CREATE
static char buff[(1 << 17)];

static void
create(const char *filename, int compress, const char **argv)
{
	struct archive *a;
	struct archive_entry *entry;
	ssize_t len;
	int fd;

	a = archive_write_new();
	switch (compress)
	{
#ifndef NO_BZIP2_CREATE
	case 'j':
	case 'y':
		//archive_write_add_filter_bzip2(a);
		break;
#endif
#ifndef NO_COMPRESS_CREATE
	case 'Z':
		//archive_write_add_filter_compress(a);
		break;
#endif
#ifndef NO_GZIP_CREATE
	case 'z':
		//archive_write_add_filter_gzip(a);
		break;
#endif
	default:
		archive_write_add_filter_none(a);
		break;
	}
//	archive_write_set_format_ustar(a);
	archive_write_set_format_7zip(a);
	//archive_write_add_filter_none(a);
	//archive_write_set_format_zip(a);
	archive_write_add_filter_none(a);

	/*
	   if (ARCHIVE_OK != archive_write_set_options(a,
	                                        "zip:encryption=zipcrypt"))
	   {
	     printf("This system does not have cryptographic library");

	   }
	 */
	/*
	   if (ARCHIVE_OK != archive_write_set_options(a,
	                                        "zip:encryption=aes128"))
	   {
	     printf("This system does not have cryptographic library");

	   }
	 */
	/*
	   if (ARCHIVE_OK != archive_write_set_options(a,
	                                        "zip:encryption=aes256"))
	   {
	     printf("This system does not have cryptographic library");

	   }
	 */

	archive_write_set_passphrase(a, "password1234");

	if (filename != NULL && strcmp(filename, "-") == 0)
		filename = NULL;
	archive_write_open_filename(a, filename);

	while (*argv != NULL)
	{
		struct archive *disk = archive_read_disk_new();
#ifndef NO_LOOKUP

		archive_read_disk_set_standard_lookup(disk);
#endif
		int r;

		r = archive_read_disk_open(disk, *argv);
		if (r != ARCHIVE_OK)
		{
			errmsg(archive_error_string(disk));
			errmsg("\n");
			exit(1);
		}

		for (;;)
		{
			int needcr = 0;

			entry = archive_entry_new();
			r = archive_read_next_header2(disk, entry);
			if (r == ARCHIVE_EOF)
				break;
			if (r != ARCHIVE_OK)
			{
				errmsg(archive_error_string(disk));
				errmsg("\n");
				exit(1);
			}
			archive_read_disk_descend(disk);
			if (verbose)
			{
				msg("a ");
				msg(archive_entry_pathname(entry));
				needcr = 1;
			}
			r = archive_write_header(a, entry);
			if (r < ARCHIVE_OK)
			{
				errmsg(": ");
				errmsg(archive_error_string(a));
				needcr = 1;
			}
			if (r == ARCHIVE_FATAL)
				exit(1);
			if (r > ARCHIVE_FAILED)
			{
#if 0
				/* Ideally, we would be able to use
				 * the same code to copy a body from
				 * an archive_read_disk to an
				 * archive_write that we use for
				 * copying data from an archive_read
				 * to an archive_write_disk.
				 * Unfortunately, this doesn't quite
				 * work yet. */
				copy_data(disk, a);
#else
				/* For now, we use a simpler loop to copy data
				 * into the target archive. */
				fd = open(archive_entry_sourcepath(entry), O_RDONLY | O_BINARY);//sacanagem...
				len = read(fd, buff, sizeof(buff));
				while (len > 0)
				{
					archive_write_data(a, buff, len);
					len = read(fd, buff, sizeof(buff));
				}
				close(fd);
#endif
			}
			archive_entry_free(entry);
			if (needcr)
				msg("\n");
		}
		archive_read_close(disk);
		archive_read_free(disk);
		argv++;
	}
	archive_write_close(a);
	archive_write_free(a);
	printf("Deu certo\n");
}
#endif

static void
extract(const char *filename, int do_extract, int flags)
{
	struct archive *a;
	struct archive *ext;
	struct archive_entry *entry;
	int r;

	a = archive_read_new();
	ext = archive_write_disk_new();
	archive_write_disk_set_options(ext, flags);
#ifndef NO_BZIP2_EXTRACT
	archive_read_support_filter_bzip2(a);
#endif
#ifndef NO_GZIP_EXTRACT
	archive_read_support_filter_gzip(a);
#endif
#ifndef NO_COMPRESS_EXTRACT
	archive_read_support_filter_compress(a);
#endif
#ifndef NO_TAR_EXTRACT
	//;archive_read_support_format_tar(a);
	archive_read_support_format_all(a);
	archive_read_add_passphrase(a, "password1234");
#endif
#ifndef NO_CPIO_EXTRACT
	archive_read_support_format_cpio(a);
#endif
#ifndef NO_LOOKUP
	archive_write_disk_set_standard_lookup(ext);
#endif
	if (filename != NULL && strcmp(filename, "-") == 0)
		filename = NULL;
	if ((r = archive_read_open_filename(a, filename, 10240)))
	{
		errmsg(archive_error_string(a));
		errmsg("\n");
		exit(r);
	}
	for (;;)
	{
		int needcr = 0;
		r = archive_read_next_header(a, &entry);
		if (r == ARCHIVE_EOF)
			break;
		if (r != ARCHIVE_OK)
		{
			errmsg(archive_error_string(a));
			errmsg("\n");
			exit(1);
		}
		if (verbose && do_extract)
			msg("x ");
		if (verbose || !do_extract)
		{
			msg(archive_entry_pathname(entry));
			msg(" ");
			needcr = 1;
		}
		if (do_extract)
		{
			r = archive_write_header(ext, entry);
			if (r != ARCHIVE_OK)
			{
				errmsg(archive_error_string(a));
				needcr = 1;
			}
			else
			{
				r = copy_data(a, ext);
				if (r != ARCHIVE_OK)
					needcr = 1;
			}
		}
		if (needcr)
			msg("\n");
	}
	archive_read_close(a);
	archive_read_free(a);

	archive_write_close(ext);
	archive_write_free(ext);
	exit(0);
}

static int
copy_data(struct archive *ar, struct archive *aw)
{
	int r;
	const void *buff;
	size_t size;
	int64_t offset;

	if(do_it_i)
	{
	     if(use_hack_internal_i)
	     {
		file_offset_ii = _ftelli64(my_temp_file_i_i);
	     }
	}
	 	
	for (;;)
	{
		r = archive_read_data_block(ar, &buff, &size, &offset);
		if (r == ARCHIVE_EOF)
			return (ARCHIVE_OK);
		if (r != ARCHIVE_OK)
		{
			errmsg(archive_error_string(ar));
			return (r);
		}
		bytes_saved_i += size;
		r = archive_write_data_block(aw, buff, size, offset);

		if(do_it_i)
		{
		     if(use_hack_internal_i)
		     {
			  fwrite(buff, 1, size, my_temp_file_i_i);
		     }
		}
		
		if (r != ARCHIVE_OK)
		{
			errmsg(archive_error_string(ar));
			return (r);
		}
	}
}

static void
msg(const char *m)
{
	write(1, m, strlen(m));
}

static void
errmsg(const char *m)
{
	if (m == NULL)
	{
		m = "Error: No error description provided.\n";
	}
	write(2, m, strlen(m));
}

static void
usage(void)
{
	/* Many program options depend on compile options. */
	const char *m = "Usage: minitar [-"
#ifndef NO_CREATE
	                "c"
#endif
#ifndef NO_BZIP2
	                "j"
#endif
	                "tvx"
#ifndef NO_BZIP2
	                "y"
#endif
#ifndef NO_COMPRESS
	                "Z"
#endif
#ifndef NO_GZIP
	                "z"
#endif
	                "] [-f file] [file]\n";

	errmsg(m);
	exit(1);
}

WCHAR * amanda_utf8towide_1_(char *pUTF8)
{
	static WCHAR ricardo_k[1024];

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, 1024);
	return ricardo_k;
}

enum libarchive_compression_modes_AR
{
	P_MODE_IS_ZIP__NO_PASSWORD,
	P_MODE_IS_ZIP__ZIPCRYPTO,
	P_MODE_IS_ZIP__AES_128,
	P_MODE_IS_ZIP__AES_256,
	P_MODE_IS_7ZIP,
	P_MODE_IS_ISO9660,
	P_MODE_IS_TAR,
	P_MODE_IS_GNUTAR,
	P_MODE_IS_V7TAR,
	P_MODE_IS_TAR_GZIP,
	P_MODE_IS_TAR_BZIP2,
	P_MODE_IS_TAR_XZ,
	P_MODE_IS_GNUTAR_GZIP,
	P_MODE_IS_GNUTAR_BZIP2,
	P_MODE_IS_GNUTAR_XZ,
	P_MODE_IS_V7TAR_GZIP,
	P_MODE_IS_V7TAR_BZIP2,
	P_MODE_IS_V7TAR_XZ
};

struct archive *a;
struct archive_entry *entry;
ssize_t len;
int fd;

bool is_open_p = false;

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...);

void pedro_dprintfW( //para imprimir wide string use %ls ok?
	int amanda_level,
	const wchar_t *format, ...);

int __stdcall libarchive_create_archive_init_p(int archive_kind_p, char *file_utf_8_p, char * passphrase_p, char * compression_level_p, int number_of_threads_p_)
{

	char our_compression_data_p[300];
	int ret_arp_;

	debug_mode_i = 0;	
#if USE_PEDRO_DPRINTF
	debug_mode_i = 1;
#endif

	pedro_dprintf(0, "@@ init\n");

	assert(!is_open_p);

	a = archive_write_new();

	number_of_threads_p = number_of_threads_p_;

	/*
	   case 'Z':
	   //archive_write_add_filter_compress(a);*/

	switch(archive_kind_p)
	{

	case P_MODE_IS_ZIP__NO_PASSWORD:

		archive_write_set_format_zip(a);
		archive_write_add_filter_none(a);

		strcpy(our_compression_data_p, "zip:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		pedro_dprintf(-1, "ret_arp_ %d\n", ret_arp_);

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;

	case P_MODE_IS_ZIP__ZIPCRYPTO:

		archive_write_set_format_zip(a);
		archive_write_add_filter_none(a);

		strcpy(our_compression_data_p, "zip:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		if (ARCHIVE_OK != archive_write_set_options(a,
		                                            "zip:encryption=zipcrypt"))
		{
			pedro_dprintf(2, "This system does not have cryptographic library zipcrypt");
			assert(0 && "This system does not have cryptographic library zipcrypt");
		}

		if(strlen(passphrase_p))
		{
			archive_write_set_passphrase(a, passphrase_p);
		}
		else
		{
			archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));
			archive_write_close(a);
			archive_write_free(a);
			return 2;
		}

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;

	case P_MODE_IS_ZIP__AES_128:

		archive_write_set_format_zip(a);
		archive_write_add_filter_none(a);

		strcpy(our_compression_data_p, "zip:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);
		/*
		   if (ARCHIVE_OK != archive_write_set_options(a,
		                                                  "zip:encryption=zipcrypt"))
		      {
		           pedro_dprintf(2, "This system does not have cryptographic library zipcrypt");
		           assert(0 && "This system does not have cryptographic library zipcrypt");
		           }*/

		if (ARCHIVE_OK != archive_write_set_options(a,
		                                            "zip:encryption=aes128"))
		{
			pedro_dprintf(2, "This system does not have cryptographic library aes128");
			assert(0 && "This system does not have cryptographic library aes128");
		}

		if(strlen(passphrase_p))
		{
			archive_write_set_passphrase(a, passphrase_p);
		}
		else
		{
			archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));
			archive_write_close(a);
			archive_write_free(a);
			return 2;
		}

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		break;

	case P_MODE_IS_ZIP__AES_256:

		archive_write_set_format_zip(a);
		archive_write_add_filter_none(a);
		/*
		   if (ARCHIVE_OK != archive_write_set_options(a,
		                                                  "zip:encryption=zipcrypt"))
		      {
		           pedro_dprintf(2, "This system does not have cryptographic library zipcrypt");
		           assert(0 && "This system does not have cryptographic library zipcrypt");
		           }*/

		strcpy(our_compression_data_p, "zip:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		if (ARCHIVE_OK != archive_write_set_options(a,
		                                            "zip:encryption=aes256"))
		{

			pedro_dprintf(2, "This system does not have cryptographic library aes256");
			assert(0 && "This system does not have cryptographic library aes256");

		}
		/*
		   if (ARCHIVE_OK != archive_write_set_options(a,
		                                  "zip:encryption=aes128"))
		   {
		     pedro_dprintf(2, "This system does not have cryptographic library aes128");
		     assert(0 && "This system does not have cryptographic library aes128");
		     }*/

		if(strlen(passphrase_p))
		{
			archive_write_set_passphrase(a, passphrase_p);
		}
		else
		{
			archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));
			archive_write_close(a);
			archive_write_free(a);
			return 2;
		}

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;

	case P_MODE_IS_7ZIP:

		archive_write_set_format_7zip(a);
		archive_write_add_filter_none(a);

		strcpy(our_compression_data_p, "7zip:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;

	case P_MODE_IS_ISO9660:

		assert(ARCHIVE_OK == archive_write_set_format_filter_by_ext(a, ".iso"));
		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		break;

	case P_MODE_IS_TAR:

		assert(ARCHIVE_OK == archive_write_set_format_filter_by_ext(a, ".tar"));
		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		break;

	case P_MODE_IS_GNUTAR:

		assert(ARCHIVE_OK == archive_write_set_format_gnutar(a));
		archive_write_add_filter_none(a);
		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		break;

	case P_MODE_IS_V7TAR:

		assert(ARCHIVE_OK == archive_write_set_format_v7tar(a));
		archive_write_add_filter_none(a);
		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		break;

	case P_MODE_IS_TAR_GZIP:

		assert(ARCHIVE_OK == archive_write_set_format_pax_restricted(a));
		assert(ARCHIVE_OK == archive_write_add_filter_gzip(a));

		strcpy(our_compression_data_p, "gzip:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;

	case P_MODE_IS_TAR_BZIP2:

		assert(ARCHIVE_OK == archive_write_set_format_pax_restricted(a));
		assert(ARCHIVE_OK == archive_write_add_filter_bzip2(a));

		strcpy(our_compression_data_p, "bzip2:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;
	case P_MODE_IS_TAR_XZ:

		assert(ARCHIVE_OK == archive_write_set_format_pax_restricted(a));
		assert(ARCHIVE_OK == archive_write_add_filter_xz(a));

		strcpy(our_compression_data_p, "xz:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}
		/*
		      pedro_dprintf(0, "oque foi?\n");

		      exit(27);*/
		break;
////////////////////////////////////////////////////////////////////////////////////////
	case P_MODE_IS_GNUTAR_GZIP:

		assert(ARCHIVE_OK ==archive_write_set_format_gnutar (a));
		assert(ARCHIVE_OK == archive_write_add_filter_gzip(a));

		strcpy(our_compression_data_p, "gzip:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;
/////////////////////////////////////////////////////////////////////////////////////////
	case P_MODE_IS_GNUTAR_BZIP2:

		assert(ARCHIVE_OK == archive_write_set_format_gnutar(a));
		assert(ARCHIVE_OK == archive_write_add_filter_bzip2(a));

		strcpy(our_compression_data_p, "bzip2:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;
/////////////////////////////////////////////////////////////////////////////////////////

	case P_MODE_IS_GNUTAR_XZ:

		assert(ARCHIVE_OK == archive_write_set_format_gnutar(a));
		assert(ARCHIVE_OK == archive_write_add_filter_xz(a));

		strcpy(our_compression_data_p, "xz:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}
		/*
		      pedro_dprintf(0, "oque foi?\n");

		      exit(27);*/
		break;
////////////////////////////////////////////////////////////////////////////////////////

	case P_MODE_IS_V7TAR_GZIP:

		assert(ARCHIVE_OK == archive_write_set_format_v7tar(a));
		assert(ARCHIVE_OK == archive_write_add_filter_gzip(a));

		strcpy(our_compression_data_p, "gzip:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;

	case P_MODE_IS_V7TAR_BZIP2:

		assert(ARCHIVE_OK == archive_write_set_format_v7tar(a));
		assert(ARCHIVE_OK == archive_write_add_filter_bzip2(a));

		strcpy(our_compression_data_p, "bzip2:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}

		break;
	case P_MODE_IS_V7TAR_XZ:

		assert(ARCHIVE_OK == archive_write_set_format_v7tar(a));
		assert(ARCHIVE_OK == archive_write_add_filter_xz(a));

		strcpy(our_compression_data_p, "xz:compression-level=");

		strcat(our_compression_data_p, compression_level_p);

		ret_arp_ = archive_write_set_options(a, our_compression_data_p);

		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));

		if(ARCHIVE_OK != ret_arp_)
		{
			archive_write_close(a);
			archive_write_free(a);
			return 3;
		}
		/*
		      pedro_dprintf(0, "oque foi?\n");

		      exit(27);*/
		break;
////////////////////////////////////////////////////////////////////////////////////////

	default:
		archive_write_open_filename_w(a, amanda_utf8towide_1_(file_utf_8_p));
		archive_write_close(a);
		archive_write_free(a);
		return 1;

		break;
	}

	is_open_p = true;
	wide_fix_p = 1;

	*bytes_read_p = 0;
	fatal_error_p = false;
	return 0;
}

int __stdcall libarchive_process_p(char * new_entry_relative_p, char * new_entry_complete_p)
{

	debug_mode_i = 0;	
#if USE_PEDRO_DPRINTF
	debug_mode_i = 1;
#endif
	pedro_dprintf(0, "@@ process\n");
     pedro_dprintf(0, "passou amanda 6\n");
	assert(is_open_p);
	{
		struct archive *disk = archive_read_disk_new();
#ifndef NO_LOOKUP

		archive_read_disk_set_standard_lookup(disk);
#endif
		int r;

		pedro_dprintf(0, "file %s\n", new_entry_relative_p);
		pedro_dprintf(0, "complete file %s\n", new_entry_complete_p);

		strcpy(real_input_utf_8_i_2, new_entry_complete_p);
		//strcpy(real_input_utf_8_i,   new_entry_complete_p);
		char temp_p[300] = {0};

		{


			WCHAR temp_p_w[300];
			int p;
			int i_p;

			p = wcslen(amanda_utf8towide_1_(new_entry_relative_p));

			wcscpy(temp_p_w, amanda_utf8towide_1_(new_entry_relative_p));

			for(i_p =0; i_p < p; i_p++)
			{
				temp_p[i_p] = (char) temp_p_w[i_p];
			}

		}

		r = archive_read_disk_open_w(disk, amanda_utf8towide_1_(new_entry_relative_p));
		pedro_dprintf(0, "2 file %s\n", temp_p);

		if (r != ARCHIVE_OK)
		{

			pedro_dprintf(2, "failed with file %s\n", new_entry_relative_p);
			pedro_dprintf(2, "%s %s %d\n", archive_error_string(disk), __FILE__, __LINE__);

			exit(1);
		}

		for (;;)
		{
			int needcr = 0;

			entry = archive_entry_new();

			pedro_dprintf(0, "alocacao de entry %p\n", entry);

			strcpy(real_input_utf_8_i_3, new_entry_complete_p);
			
			r = archive_read_next_header2(disk, entry);

			real_input_utf_8_i_3[0] = 0;
			
			if (r == ARCHIVE_EOF)
			{
				pedro_dprintf(0, "3 file %s\n", new_entry_relative_p);
				break;
			}
			pedro_dprintf(0, "2 alocacao de entry %p\n", entry);
			pedro_dprintf(0, "4 file %s\n", new_entry_relative_p);
			if (r != ARCHIVE_OK)
			{

				pedro_dprintf(0, "%s %s %d\n", archive_error_string(disk), __FILE__, __LINE__);

				archive_entry_free(entry);

				goto final_ok_p;
				exit(1);
			}
			pedro_dprintf(0, "5 file %s\n", new_entry_relative_p);
			archive_read_disk_descend(disk);
			if (verbose)
			{
				msg("a ");
				msg(archive_entry_pathname(entry));
				needcr = 1;
			}
			pedro_dprintf(0, "7 file %s\n", new_entry_relative_p);
			pedro_dprintf(0, "4 alocacao de entry %p\n", entry);
			pedro_dprintf(0,  "     %s %d\n", archive_entry_pathname(entry), __LINE__);
			pedro_dprintf(0, "utf8 %s %d\n", archive_entry_pathname_utf8(entry), __LINE__);
			pedro_dprintfW(0, L" %ls %d\n", archive_entry_pathname_w(entry), __LINE__);
			pedro_dprintf(0, "8 file %s\n", new_entry_relative_p);
			r = archive_write_header(a, entry);
			if (r < ARCHIVE_OK)
			{

				pedro_dprintf(2, "%s %s %d\n", archive_error_string(disk), __FILE__, __LINE__);

				needcr = 1;
			}

			pedro_dprintfW(0, L"9 file %s\n", new_entry_relative_p);

			if (r == ARCHIVE_FATAL)
			{

				fatal_error_p = true;

				mprintf___arp("Fatal error, can be a wrong combination of compression level and number of threads, contact the developer and explain how to reproduce the problem\n");

				exit(27);

				goto finish_ok_1_p;
			}

			pedro_dprintf(0, "10 file %s\n", new_entry_relative_p);

			if (r > ARCHIVE_FAILED)
			{
#if 0
				/* Ideally, we would be able to use
				 * the same code to copy a body from
				 * an archive_read_disk to an
				 * archive_write that we use for
				 * copying data from an archive_read
				 * to an archive_write_disk.
				 * Unfortunately, this doesn't quite
				 * work yet. */
				copy_data(disk, a);
#else
				/* For now, we use a simpler loop to copy data
				 * into the target archive. */

				pedro_dprintf(0,   " A dando open em %s\n", archive_entry_sourcepath(entry));

				pedro_dprintfW(0, L" W dando open em %ls\n", archive_entry_sourcepath_w(entry));

				if(NULL == archive_entry_sourcepath(entry))
				{
				     pedro_dprintf(0, "modo _wopen\n");
					fd = _wopen(archive_entry_sourcepath_w(entry), O_RDONLY | O_BINARY);//sacanagem...
				}
				else
				{
				     pedro_dprintf(0, "modo open\n");
				     pedro_dprintf(0, "11 file %s\n", new_entry_relative_p);
				     pedro_dprintf(0, "file para open %s\n", archive_entry_sourcepath(entry));
				     fd = open(archive_entry_sourcepath(entry), O_RDONLY | O_BINARY);//sacanagem...
				}

				pedro_dprintf(0, "fd %d\n", fd);

				len = read(fd, buff, sizeof(buff));
				while (len > 0)
				{
					*bytes_read_p += len;

					archive_write_data(a, buff, len);
					len = read(fd, buff, sizeof(buff));
				}
				close(fd);
#endif
			}

finish_ok_1_p:
			;

			archive_entry_free(entry);
			if (needcr)
				msg("\n");

			break;
		}

final_ok_p:
		;

		archive_read_close(disk);
		archive_read_free(disk);

	}
	return 0;
}

int __stdcall libarchive_close_p(void)
{
     
	debug_mode_i = 0;	
#if USE_PEDRO_DPRINTF
	debug_mode_i = 1;
#endif
	pedro_dprintf(0, "@@ de init\n");
	assert(is_open_p);
	archive_write_close(a);
	archive_write_free(a);

	is_open_p = false;
	wide_fix_p = 0;

	//assert(0 && "fechou libarchive");
	
	if(false == fatal_error_p)
	{

		return 0;

	}
	return 1;
}

int __stdcall set_progress_p(int64_t * pointer_value_p)
{
     
	debug_mode_i = 0;	
#if USE_PEDRO_DPRINTF
	debug_mode_i = 1;
#endif	
	assert(pointer_value_p);
	bytes_read_p = pointer_value_p;
	return 0;
}

enum amanda_commands {
	AAKP_CLEAR,
	AAKP_LIST_PROCESS,
	AAKP_LIST_FINISH,
	AAKP_EXTRACT_PROCESS,
	AAKP_EXTRACT_FINISH,
	AAKP_ERROR,
	AAKP_CREATE_ERROR,
	AAKP_CREATE_WARNING,
	AAKP_CREATE_FINISH,
	AAKP_CREATE_PROCESS
};

typedef int (__stdcall * tar_list_function_ar)(int clear_flag_k);

int       * Isdir_k_ar_p       = NULL;
int       * Second_k_ar_p      = NULL;
int       * Minute_k_ar_p      = NULL;
int       * Hour_k_ar_p        = NULL;
int       * Year_k_ar_p        = NULL;
int       * Month_k_ar_p       = NULL;
int       * Day_k_ar_p         = NULL;
__int64   * Size_k_ar_p        = NULL;
char      * filename_k_ar_p    = NULL;
int       * Numdir_k_ar_p      = NULL;
int       * Numfiles_k_ar_p    = NULL;
char      * typeflag_ar__p     = NULL;

int __stdcall get_tar_info_p
(
	int       * Isdir_k_ar,
	int       * Second_k_ar,
	int       * Minute_k_ar,
	int       * Hour_k_ar,
	int       * Year_k_ar,
	int       * Month_k_ar,
	int       * Day_k_ar,
	__int64   * Size_k_ar,
	char      * filename_k_ar,
	int       * Numdir_k_ar,
	int       * Numfiles_k_ar,
	char      * typeflag_ar_
)
{

     Isdir_k_ar_p      = Isdir_k_ar    ;
     Second_k_ar_p     = Second_k_ar   ;
     Minute_k_ar_p     = Minute_k_ar   ;
     Hour_k_ar_p       = Hour_k_ar     ;
     Year_k_ar_p       = Year_k_ar     ;
     Month_k_ar_p      = Month_k_ar    ;
     Day_k_ar_p        = Day_k_ar      ;
     Size_k_ar_p       = Size_k_ar     ;
     filename_k_ar_p   = filename_k_ar ;
     Numdir_k_ar_p     = Numdir_k_ar   ;
     Numfiles_k_ar_p   = Numfiles_k_ar ;
     typeflag_ar__p    = typeflag_ar_  ;

     return 0;
}

static char * valquiria_wide_to_utf8(WCHAR * pUSC2_maria)
{
	static char saida_utf8[1024];

	WideCharToMultiByte(CP_UTF8, 0, pUSC2_maria, -1, (LPSTR)saida_utf8, 1024, 0, 0);
	return saida_utf8;
}
enum ricardo_mode
{

     AMANDA_NONE,
     AMANDA_MAX,
     AMANDA_PROGRESS,
     
};

int my_mode_i = AMANDA_NONE;

int64_t  max_items    = 0;
int64_t  items_got    = 0;

bool extrair_arquivos_i = false;

bool enable_list_process_i = true;

bool raise_events_i = true;

char destination_path_final_i[1027] = { 0 };

char * extracting_filename_ar = NULL;
char * warning_info           = NULL;
char * creating_folder_maria  = NULL;

bool * extract_pause__flag    = NULL;
bool * extract_cancel_flag    = NULL;

int * folders_ar = NULL;
int * files_ar   = NULL;

bool is_7z_i = false;

int __stdcall libarchive_list_entries_p(char *filename_utf_8_p, char * password_p, tar_list_function_ar our_function_list_p, char * error_message_p, char * archive_format_p)
{
     /*
     int counter_p = 0;
     char temp_p[1024] ={ 0, };
     WCHAR * ptr_w_p;
     */

     bool use_attributes  = false;
     int returnvalue_i    =     0;
     int flags;
     char * ptr_i         =  NULL;
     char   temp_i        [ 1027];
     char   temp_v2_i     [ 1027];
     char   temp_v3_i     [ 1027];
     struct archive       *a     ;
     struct archive       *ext   ;
     struct archive_entry *entry ;
     int r;

	debug_mode_i = 0;	
#if USE_PEDRO_DPRINTF
	debug_mode_i = 1;
#endif
	
     flags = ARCHIVE_EXTRACT_TIME;
     a = archive_read_new();
     ext = archive_write_disk_new();
     archive_write_disk_set_options(ext, flags);
     
     if(!enable_list_process_i)
     {
	  filename_k_ar_p = temp_v2_i;
     }
     
     //strcpy(destination_path_final_i, "C:\\Ava\\back\\a_test__i\\");

     if(strlen(destination_path_final_i))
     {
     
denovo_i:;
     
     if(3 == strlen(destination_path_final_i))
     {

	  goto safety_i;
	  
     }
     if(strlen(destination_path_final_i) > 3)
     {

	  if('\\' == destination_path_final_i[strlen(destination_path_final_i) - 1])
	  {
	       destination_path_final_i[strlen(destination_path_final_i) - 1] = 0;
	       goto denovo_i;
	  }
	  if('/' == destination_path_final_i[strlen(destination_path_final_i) - 1])
	  {
	       destination_path_final_i[strlen(destination_path_final_i) - 1] = 0;
	       goto denovo_i;
	  }
	  
     }

safety_i:;

     pedro_dprintf(0, "path consertado %s\n", destination_path_final_i);
     
     strcpy(destination_path_utf_8_i,     destination_path_final_i);
     strcpy(real_input_utf_8_i_extract_2, destination_path_final_i);

     }
     else
     {

	  strcpy(destination_path_utf_8_i,     "C:\\back_nao");
	  strcpy(real_input_utf_8_i_extract_2, "C:\\back_nao");
	  
     }
     disable_utf_8_p = 1;

     archive_format_p[0] = 0;
     
     strcpy(error_message_p, "Amanda eu te amo...\n");

     if(enable_list_process_i)
     *Numfiles_k_ar_p = 0;

     if(enable_list_process_i)
     *Numdir_k_ar_p = 0;

     if(enable_list_process_i && raise_events_i)
     {
     our_function_list_p(AAKP_CLEAR);//process is AAKP_LIST_PROCESS
     }

     archive_read_support_filter_all(a);

     //;archive_read_support_format_tar(a);
     archive_read_support_format_all(a);

     if(strlen(password_p))
     {
	  archive_read_add_passphrase(a, password_p);
     }
     else
     {
	  archive_read_add_passphrase(a, "rico");
     }

#ifndef NO_LOOKUP
     archive_write_disk_set_standard_lookup(ext);
#endif

     if ((r = archive_read_open_filename_w(a, amanda_utf8towide_1_(filename_utf_8_p), 10240)))
     {
	  errmsg(archive_error_string(a));

	  pedro_dprintf(0, "Error: %s\n", archive_error_string(a));

	  returnvalue_i = 11; //Open error
	  strcpy(error_message_p, archive_error_string(a));
	  goto exit_now_aqui_i;
		    
	  //exit(r);
     }
     for (;;)
     {
	  
	  if(extract_pause__flag)
	  {
	       while(*extract_pause__flag)
	       {
		    if(*extract_cancel_flag)
		    {
			 returnvalue_i = 17;
			 strcpy(error_message_p, "User cancel");
			 goto exit_now_aqui_i;		    
		    }
		    Sleep(50);
	       }
	       if(*extract_cancel_flag)
	       {
		    returnvalue_i = 17;
		    strcpy(error_message_p, "User cancel");
		    goto exit_now_aqui_i;		    
	       }
	  }
	       
	  r = archive_read_next_header(a, &entry);
	  if (r == ARCHIVE_EOF)
	       break;
	  if (r != ARCHIVE_OK)
	  {
	       errmsg(archive_error_string(a));
	       returnvalue_i = 12; //Read compressed file error
	       strcpy(error_message_p, archive_error_string(a));
	       goto exit_now_aqui_i;
	  }

	  if (true)//hack.. as usual
	  {
	       //msg(archive_entry_pathname(entry));
	       //msg(" ");
	       //needcr = 1;

	       use_attributes = false; //important: use of attributes is only enabled when fully handled in the update mode of files in libarchive modified by us...
	       
	       pedro_dprintf(0, "----------------------->%s\n", archive_entry_pathname(entry));

	       pedro_dprintf(0, "kkkkkk formato %s\n", archive_format_name(a));
	      
	       fix_it_i = 1;
	       strcpy(filename_k_ar_p, archive_entry_pathname(entry));

	       if(0 == strcmp("POSIX pax interchange format", archive_format_name(a)))
	       {
		    disable_utf_8_p = 0;
		    strcpy(filename_k_ar_p, archive_entry_pathname(entry));
	       }

	       is_7z_i = false;
	       if(0 == strcmp("7-Zip", archive_format_name(a)))//not in use anymore...using real 7zip code from Igor...
	       {
		    is_7z_i = true;
		    fix_it_i = 0;
		    strcpy(filename_k_ar_p, valquiria_wide_to_utf8((void *) archive_entry_pathname_w(entry)));
	       }

	       pedro_dprintf(0, "format -%s-\n", archive_format_name(a));

	       if(0 == archive_format_p[0])
	       {
		    ptr_i = strstr(archive_format_name(a), "ZIP ");

		    if(ptr_i)
		    {
			 use_attributes = true; //fully supported, but only if the Zip is new mode of zip that have the attribute, anyway if not the default attribute for a file will be used, stay calm...
		    }
		    
		    ptr_i = strstr(archive_format_name(a), "ZIP 2.0");
   	       
		    if(ptr_i)
		    {
			 strcpy(archive_format_p, "ZIP 2.0");
		    }
		    else
		    strcpy(archive_format_p, archive_format_name(a));
	       }
	       
	       ptr_i = strstr(archive_format_name(a), "POSIX ustar format");

	       if(ptr_i)
	       {
		    pedro_dprintf(0, "disabled fix 1 !!!!\n");
		    fix_it_i = 0;
	       }
	       
	       ptr_i = strstr(archive_format_name(a), "POSIX pax interchange format");

	       if(ptr_i)
	       {
		    pedro_dprintf(0, "disabled fix 2 !!!!\n");
		    fix_it_i = 0;
	       }

	       if(0 == strcmp("RAR", archive_format_name(a)))
	       {
		    fix_it_i = 0;
		    strcpy(filename_k_ar_p, valquiria_wide_to_utf8((void *) archive_entry_pathname_w(entry)));
		    returnvalue_i = 9; //RAR format disabled due to buggy code
		    strcpy(error_message_p, "RAR format disabled due to buggy code");
		    goto exit_now_aqui_i;
	       }
	       if(0 == strcmp("RAR5", archive_format_name(a)))
	       {
		    fix_it_i = 0;
		    strcpy(filename_k_ar_p, valquiria_wide_to_utf8((void *) archive_entry_pathname_w(entry)));
		    returnvalue_i = 10; //RAR5 format disabled due to buggy code
		    strcpy(error_message_p, "RAR5 format disabled due to buggy code");
		    goto exit_now_aqui_i;
	       }

	       do_it_i = false;
	       filesize_ii = 0;
	       if(0 == strcmp(".", filename_k_ar_p) || 0 == strcmp("..", filename_k_ar_p))
	       {
		    ;//skip...
	       }
	       else
	       {
		    if(enable_list_process_i)
		    (* Size_k_ar_p)      = 0;

		    
		    if(strlen(filename_k_ar_p) && enable_list_process_i)
		    {
			 strcpy(filename_copy_i, filename_k_ar_p);
			 strcpy(typeflag_ar__p, "Unknown");
			 if(S_ISDIR(archive_entry_mode(entry)))
			 {
			      is_dir_ii = true;
			      do_it_i = true;
			      if('/' != filename_k_ar_p[strlen(filename_k_ar_p) -1])
			      {

				   strcat(filename_k_ar_p, "/");
					
			      }
			      strcpy(temp_v3_i, filename_k_ar_p);

			      if(strlen(temp_v3_i))
			      temp_v3_i[strlen(temp_v3_i) - 1] = 0;			      
			      
			      strcpy(typeflag_ar__p, "DIRTYPE");
			      (*Numdir_k_ar_p) ++;
			      (* Isdir_k_ar_p) = 1;
			      (* Size_k_ar_p)      = 0;
			      filesize_ii          = 0;
			      if(AMANDA_MAX == my_mode_i)
			      {
				   max_items++;
			      }
			      if(AMANDA_PROGRESS == my_mode_i)
			      {
				   items_got++;
			      }
			      if(extracting_filename_ar)
			      {
				   extracting_filename_ar[0] = 0;
				   warning_info[0]           = 0;
				   strcpy(creating_folder_maria, temp_v3_i);

				   (*folders_ar) ++;
				   
				   our_function_list_p(AAKP_EXTRACT_PROCESS);
			      }

			      
			 }

			 if(S_ISREG(archive_entry_mode(entry)))
			 {
			      is_dir_ii = false;
			      do_it_i = true;
			      
			      (*Numfiles_k_ar_p)++;
			      strcpy(typeflag_ar__p, "REGTYPE");
			      (* Isdir_k_ar_p) = 0;
			      (* Size_k_ar_p)      = archive_entry_size(entry);

			      filesize_ii = (* Size_k_ar_p);
			      if(AMANDA_MAX == my_mode_i)
			      {
				   max_items++;
			      }
			      if(AMANDA_PROGRESS == my_mode_i)
			      {
				   items_got++;
			      }
			      if(extracting_filename_ar)
			      {
				   strcpy(extracting_filename_ar, filename_k_ar_p);
				   warning_info[0]           = 0;
				   creating_folder_maria[0]  = 0;

				   (*files_ar) ++;
				   
				   our_function_list_p(AAKP_EXTRACT_PROCESS);
			      }
			 }
		
			 struct tm tm_k;

			 __time64_t s;

			 s = archive_entry_mtime(entry);

			 if (!_gmtime64(&s))
			 {
			      s = time(NULL);
			 }

			 tm_k = 0 ? *_gmtime64(&s) : *_localtime64(&s);

			 (* Second_k_ar_p)    = (WORD)tm_k.tm_sec;
			 (* Minute_k_ar_p)    = (WORD)tm_k.tm_min;
			 (* Hour_k_ar_p)      = (WORD)tm_k.tm_hour;
			 (* Year_k_ar_p)      = (WORD)tm_k.tm_year + 1900;
			 (* Month_k_ar_p)     = (WORD)tm_k.tm_mon + 1;
			 (* Day_k_ar_p)       = (WORD)tm_k.tm_mday;

			 if(enable_list_process_i && raise_events_i)
			 {
			      our_function_list_p(AAKP_LIST_PROCESS);
			 }
		    }
	       }     
	  }
	  if (extrair_arquivos_i)
	  {
	       pedro_dprintf(0, "---antes\n");

	       if(use_hack_internal_i)
	       {
		    use_hack_i = 1;
	       }

	       attributes_i = -1;
	       
	       r = archive_write_header(ext, entry);
	       
	       if(-1 != attributes_i)
	       {

		    if(use_attributes)//to make the compiler happy...
		    {
			 goto jump_3_i;
		    }
		    
	       jump_3_i:;
		    
	       }

	       if(-1 == attributes_i)
	       {

		    attributes_i = 0x20;
		    
	       }

	       pedro_dprintf(0, "veja o attribute %llx\n", attributes_i);
	       
	       //assert(0x20 == attributes_i);
	       
	       if(do_it_i)
	       {
		    if(use_hack_internal_i)
		    {
			 
			 atime_ii     = atime_iii       ;
			 mtime_ii     = mtime_iii       ;
			 birthtime_ii = birthtime_iii   ;		  
			 			 
		    }
	       }
	       
	       use_hack_i = 0;
	       
	       pedro_dprintf(0, "---depois\n");
	       
	       if (r != ARCHIVE_OK)
	       {
		    if(archive_error_string(a))
		    pedro_dprintf(0, "arquivo erro-> %s\n", archive_error_string(a));
		    errmsg(archive_error_string(a));

		    strcpy(error_message_p, "Write archive error on file or folder '");

		    strcat(error_message_p, destination_path_final_i);
		    strcat(error_message_p, "\\");
		    
		    strcat(error_message_p, filename_k_ar_p);
		    strcat(error_message_p, "\'");

		    ptr_i = error_message_p;
		    while(*ptr_i)
		    {
			 if('/' == *ptr_i)
			 {
			      *ptr_i = '\\';
			 }
			 ptr_i++;
		    }
		    
		    returnvalue_i = 14;
		    
		    goto exit_now_aqui_i;
	       }
	       else
	       {
		    r = copy_data(a, ext);
		    if (r != ARCHIVE_OK)
		    {
			 returnvalue_i = 8;//read error...or wrong password

			 strcpy(error_message_p, "Read error or wrong password");

			 if(is_7z_i)
			 {
			      strcpy(error_message_p, "Read error or trying to uncompress a 7zip file with a password, this release don\'t support it for the moment (libarchive)");
			 }
			 
			 pedro_dprintf(0, "@@@@@@@@@@@@@@read error\n");
			 pedro_dprintf(0, "file to delete %s\n", filename_k_ar_p);
			 goto exit_now_aqui_i;
		    }
		    //aqui...
		    if(do_it_i)
		    {
			 if(use_hack_internal_i)
			 {
			      add_more_one_z_june_24_iii
				   (
				
					atime_ii          ,
					mtime_ii          ,
					birthtime_ii      ,
					filesize_ii       ,
					file_offset_ii    ,
					filename_copy_i   ,
					is_dir_ii         ,
					true              ,
					attributes_i);

			 }
		    }
	       }
	  }
	  pedro_dprintf(0, "final de for\n");
     }

exit_now_aqui_i:;

     pedro_dprintf(0, "real final de for\n");
     
     archive_read_close(a);
     archive_read_free(a);

     archive_write_close(ext);
     archive_write_free(ext);

     disable_utf_8_p = 0;

     destination_path_utf_8_i    [0] = 0;
     real_input_utf_8_i_extract_2[0] = 0;
     fix_it_i = 0;

     if(8 == returnvalue_i)
     {
	  strcpy(temp_i, destination_path_final_i);
	  strcat(temp_i, "\\");
	  strcat(temp_i, filename_k_ar_p);
	  pedro_dprintf(0, "to delete path %s\n", temp_i);
	  unlink(temp_i);//damn...
     }
     if(returnvalue_i) returnvalue_i += 6001;

     pedro_dprintf(0, "exit function \n");
     
     return returnvalue_i;
}

static int __stdcall extract_function_ar_ok(int clear_flag_k)
{

     return 0;
     
}

int __stdcall libarchive_extract_entries_p(char *filename_utf_8_p, char * password_p, tar_list_function_ar our_function_extract_p, char * error_message_p, char * archive_format_p, char * dir_to_extract_i, char * extracting_filename_ar_, char * warning_info_, char * creating_folder_maria_, bool * extract_pause__flag_, bool * extract_cancel_flag_, int * folders_ar_, int * files_ar_)
{
     
     int returnvalue_i     = 0;
     int        Isdir_k_ar    ;
     int        Second_k_ar   ;
     int        Minute_k_ar   ;
     int        Hour_k_ar     ;
     int        Year_k_ar     ;
     int        Month_k_ar    ;
     int        Day_k_ar      ;
     __int64    Size_k_ar     ;
     char       filename_k_ar[1027];
     int        Numdir_k_ar = 0;
     int        Numfiles_k_ar = 0;
     char       typeflag_ar_[1027];
     
	debug_mode_i = 0;	
#if USE_PEDRO_DPRINTF
	debug_mode_i = 1;
#endif	
     
     Isdir_k_ar_p      = & Isdir_k_ar    ;
     Second_k_ar_p     = & Second_k_ar   ;
     Minute_k_ar_p     = & Minute_k_ar   ;
     Hour_k_ar_p       = & Hour_k_ar     ;
     Year_k_ar_p       = & Year_k_ar     ;
     Month_k_ar_p      = & Month_k_ar    ;
     Day_k_ar_p        = & Day_k_ar      ;
     Size_k_ar_p       = & Size_k_ar     ;
     filename_k_ar_p   = filename_k_ar ;
     Numdir_k_ar_p     = & Numdir_k_ar   ;
     Numfiles_k_ar_p   = & Numfiles_k_ar ;
     typeflag_ar__p    = typeflag_ar_  ;

     pedro_dprintf(0, "dest path %s\n", dir_to_extract_i);

     extrair_arquivos_i = false;

     enable_list_process_i = true;
 
     raise_events_i = false;

     max_items = 0;
     items_got = 0;
     
     if(use_hack_internal_i)
     {
	  init_playlist_z_june_24_iii();
	  my_temp_file_i_i = NULL;
	  my_temp_file_i_i = _wfopen(amanda_utf8towide_1_(temp__file_i), L"wb");

	  if(NULL == my_temp_file_i_i)
	  {
	       returnvalue_i = 115;
	       strcpy(error_message_p,"Cannot open temp file to write");
	  }
     }
     
     if(NULL == our_function_extract_p)
     {
	  our_function_extract_p = extract_function_ar_ok;
     }
     //aqui amor?...

     my_mode_i = AMANDA_MAX;
     
     strcpy(destination_path_final_i, dir_to_extract_i);

     extract_pause__flag = extract_pause__flag_;
     extract_cancel_flag = extract_cancel_flag_;
     
     returnvalue_i = libarchive_list_entries_p(filename_utf_8_p, password_p, our_function_extract_p, error_message_p,  archive_format_p);

     my_mode_i = AMANDA_PROGRESS;

     strcpy(destination_path_final_i, dir_to_extract_i);//to the next call

     pedro_dprintf(0, "antes max == %d got == %d\n", max_items, items_got);

     if(0 == returnvalue_i)
     {
	  
	  extrair_arquivos_i = true;
	  my_mode_i = AMANDA_PROGRESS;

	  extracting_filename_ar = extracting_filename_ar_;
	  warning_info = warning_info_;
	  creating_folder_maria = creating_folder_maria_;

	  folders_ar = folders_ar_;
	  files_ar   = files_ar_;

	  * folders_ar = 0;
	  * files_ar   = 0;
	  our_function_extract_p(AAKP_CLEAR);

	  assert(0 && "antes de extrair");
	  
	  bytes_saved_i = 0;
	  
	  returnvalue_i = libarchive_list_entries_p(filename_utf_8_p, password_p, our_function_extract_p, error_message_p,  archive_format_p);

	  pedro_dprintf(0, "bytes saved %lld\n", bytes_saved_i);
	  
	  assert(0 && "depois de extrair");
	  
	  extracting_filename_ar  =  NULL;
	  warning_info            =  NULL;
	  creating_folder_maria   =  NULL;
	  
     pedro_dprintf(0, "depois max == %d got == %d\n", max_items, items_got);

     }
     
     extrair_arquivos_i = false;

     enable_list_process_i = true;

     raise_events_i = true;
     
     destination_path_final_i[0] = 0;

     my_mode_i    = AMANDA_NONE;
     
     extract_pause__flag = NULL;
     extract_cancel_flag = NULL;

     if(use_hack_internal_i)
     {
	  if(my_temp_file_i_i)
	  {
	       fclose(my_temp_file_i_i);
	  }
     }
     return returnvalue_i;
}

/**
 * It will return a slice of 10000 for the percentage between max and
 * fatia, 100% == 10000, it is required to  the progress information to be smooth
 *
 * @param max : the maximum value
 *
 * @param fatia : the slice of the max value
 */
static int
getpor_10000_int64_t_ar(int64_t avamax, int64_t fatia)
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

int __stdcall progress_extract_i(void)
{
     int returnvalue_i = 0;

     returnvalue_i = getpor_10000_int64_t_ar(max_items, items_got);

     if(0 > returnvalue_i)
     {
	  return 0;
     }
     if(10000 < returnvalue_i)
     {
	  return 10000;
     }
    
     return returnvalue_i;
     
}

int __stdcall extract_to_file_i(char * temp_path_i, bool enable_i, char * temp_file_i_, init_playlist_z_june_24_i init_playlist_z_june_24_ii, add_more_one_z_june_24_i add_more_one_z_june_24_ii, check_item_z_june_24_i check_item_z_june_24_ii)
{

     init_playlist_z_june_24_iii = init_playlist_z_june_24_ii;
     add_more_one_z_june_24_iii  = add_more_one_z_june_24_ii ;
     check_item_z_june_24_iii    =    check_item_z_june_24_ii;
     
     strcpy(temp_path_23_june_i, temp_path_i);
     strcpy(temp__file_i, temp_file_i_);
     use_hack_internal_i = 0;
     if(enable_i)
     {
	  use_hack_internal_i = 1;
     }
     
     return 0;
}
