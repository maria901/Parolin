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

#include "microsoft_header_fix_m.h"

#include /* amanda's smart ape */ "win64.h" /* to make the compiler happy */

//#define Z_DEBUG__TEMP 1

#define DEBUG_MICROSOFT_AMANDA_S_SMART_APE_______LIKE_PEDRO_VALUE__ ((0) /* if -1 not working, as usual... */)

//set it to one if you want to allow the extraction of VAL encrypted files with different passwords, but it is not recommended, you are warned
#define ARP_ALLOW_MULTIPLE_PASSWORDS_ 0

#define INT_BITS_STRLEN_BOUND(b) (((b)*146 + 484) / 485)

#define _GL_SIGNED_TYPE_OR_EXPR(t) TYPE_SIGNED(__typeof__(t))

#define INT_STRLEN_BOUND(t) \
	(INT_BITS_STRLEN_BOUND(TYPE_WIDTH(t) - _GL_SIGNED_TYPE_OR_EXPR(t)) + _GL_SIGNED_TYPE_OR_EXPR(t))

#define __amandacall __stdcall
#define __valquiriacall __fastcall

bool check_valid_path_i(char *data_i);

typedef void (*add_more_one_func)(char *);

bool mode_is_update_libarchive_v27 = false;

bool use_7zip_extraction_progress_i = false;

bool progress_is_libarchive_v27 = false;

int progress_lib_v27;

int __stdcall get_rand(int min, int max);

bool mode_is_libarchive_update_i = false;

bool dont_delete_7zip_file_i = false;

bool only_get_number_of_files_ar_v27 = false;

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

char encryption_method__i[300] = {0};
char compression_level_p[300];

char compression_level_char_i[300] = "6";
FILE *my___temp_file_i;
char temp_file_update_i[AMANDA__SIZE] = {
	0,
};

int64_t attributes_i;

int number_of_threads_p = 1;

__time64_t atime_i;
__time64_t ctime_i;
__time64_t mtime_i;

int show_debug_z = -1;

int cores_used_z = 1;

bool is_update_i = false;

bool mode_is_libarchive_list_p = false;
bool mode_is_libarchive_extract_p = false;

char key_fingerprint_i[1027] = {
	0,
};

extern int64_t real_VAL_filesize;

char my_error_as_a_programmer_z[AMANDA__SIZE] = {0};

typedef int(__stdcall *tar_list_function_ar)(int clear_flag_k);

int remove_temp_folder_i(void);

char error_message_k[AMANDA__SIZE] = {0};
char remote_path_i[AMANDA__SIZE] = {0};
;
int feline_read_xml(char *filename_utf8_feline,
					char *root__________feline,
					char *node__________feline,
					char *attribute_____feline,
					char *out_data______feline);

int feline_write_xml(char *filename_utf8_feline,
					 char *root__________feline,
					 char *node__________feline,
					 char *attribute_____feline,
					 char *in_data_______feline_);
int stripfilenameandpath(char *path, char *onlypath, char *onlyfilename);

__int64
getfilesize_ar(char *infile_ar);

double
get_bucaneiro_tick(void);

int __fastcall split_in_multiple_volumes_p(char *filename_utf_8_p);

int __stdcall split_compressed_file_p(int64_t slice_in_bytes_p_);

int __fastcall detect_multi_volume_p(char *filename_utf_8_p, char *adjusted_filename_in_temp_p);

/**
 * To convert an input wide string to a utf-8 encoded filename on return
 *
 * @param pUSC2_maria the wide string to be converted
 *
 * @return it will return the static allocated char * string with the utf-8 encoded filename
 *
 */
char *valquiria_wide_to_utf8(WCHAR *pUSC2_maria);

extern void
pedro_dprintf(
	int amanda_level,
	char *format, ...);
extern void
pedro_dprintfW(
	int amanda_level,
	wchar_t *format, ...);

wchar_t *
remove_permissive_name_m_(wchar_t *wname)
{

	/**
 * oi amor...
 */
	static wchar_t wname_copy[AMANDA__SIZE_w + 1];

	wchar_t *wname_copy_v27 = wname_copy;

	wcscpy(wname_copy, wname);

	if (3 < wcslen(wname_copy))
	{

		if ('\\' == wname_copy[0] &&
			'\\' == wname_copy[1] &&
			'?' == wname_copy[2])
		{
			wname_copy_v27++;
			wname_copy_v27++;
			wname_copy_v27++;
			wname_copy_v27++;
			return wname_copy_v27;
		}
		else
		{
			return wname;
		}
	}
	else
	{
		return wname;
	}
}

/**
 * To make the path wide mode aware, stolen from libarchive
 * 
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond...
 *
 */
wchar_t *
permissive_name_m_(const wchar_t *wname)
{

	static wchar_t *wnp = NULL;
	wchar_t *wn;
	wchar_t *ws, *wsp;
	DWORD len, slen;
	int unc;

	if (NULL == wnp)
	{
		wnp = calloc((AMANDA__SIZE_w * 2) + 2, 1);
	}

	//wnp = malloc(AMANDA__SIZE * 2);

	wcscpy(wnp, wname);

	len = wcslen(wname);

	wn = wnp;

	if (wnp[0] == L'\\' && wnp[1] == L'\\' && // access to the wrong position in memory, fixed now
		wnp[2] == L'?' && wnp[3] == L'\\')
		/* We have already a permissive name. */
		return (wn);

	if (wnp[0] == L'\\' && wnp[1] == L'\\' &&
		wnp[2] == L'.' && wnp[3] == L'\\')
	{
		/* This is a device name */
		if (((wnp[4] >= L'a' && wnp[4] <= L'z') ||
			 (wnp[4] >= L'A' && wnp[4] <= L'Z')) &&
			wnp[5] == L':' && wnp[6] == L'\\')
			wnp[2] = L'?'; /* Not device name. */
		return (wn);
	}

	unc = 0;
	if (wnp[0] == L'\\' && wnp[1] == L'\\' && wnp[2] != L'\\')
	{
		wchar_t *p = &wnp[2];

		/* Skip server-name letters. */
		while (*p != L'\\' && *p != L'\0')
			++p;
		if (*p == L'\\')
		{
			wchar_t *rp = ++p;
			/* Skip share-name letters. */
			while (*p != L'\\' && *p != L'\0')
				++p;
			if (*p == L'\\' && p != rp)
			{
				/* Now, match patterns such as
				 * "\\server-name\share-name\" */
				wnp += 2;
				len -= 2;
				unc = 1;
			}
		}
	}

	slen = 4 + (unc * 4) + len + 1;
	ws = wsp = malloc(slen * sizeof(wchar_t));
	if (ws == NULL)
	{
		//free(wn);
		return (NULL);
	}
	/* prepend "\\?\" */
	wcsncpy(wsp, L"\\\\?\\", 4);
	wsp += 4;
	slen -= 4;
	if (unc)
	{
		/* append "UNC\" ---> "\\?\UNC\" */
		wcsncpy(wsp, L"UNC\\", 4);
		wsp += 4;
		slen -= 4;
	}
	wcsncpy(wsp, wnp, slen);
	wsp[slen - 1] = L'\0'; /* Ensure null termination. */
	//free(wn);

	wcscpy(wnp, ws);

	free(ws);

	return (wnp);
}

wchar_t *
permissive_name_m_v27(const wchar_t *wname)
{

	static wchar_t *wnp = NULL;
	wchar_t *wn;
	wchar_t *ws, *wsp;
	DWORD len, slen;
	int unc;

	if (NULL == wnp)
	{
		wnp = calloc((AMANDA__SIZE_w * 2) + 2, 1);
	}

	//wnp = malloc(AMANDA__SIZE * 2);

	wcscpy(wnp, wname);

	len = wcslen(wname);

	wn = wnp;

	if (wnp[0] == L'\\' && wnp[1] == L'\\' && // access to the wrong position in memory, fixed now
		wnp[2] == L'?' && wnp[3] == L'\\')
		/* We have already a permissive name. */
		return (wn);

	if (wnp[0] == L'\\' && wnp[1] == L'\\' &&
		wnp[2] == L'.' && wnp[3] == L'\\')
	{
		/* This is a device name */
		if (((wnp[4] >= L'a' && wnp[4] <= L'z') ||
			 (wnp[4] >= L'A' && wnp[4] <= L'Z')) &&
			wnp[5] == L':' && wnp[6] == L'\\')
			wnp[2] = L'?'; /* Not device name. */
		return (wn);
	}

	unc = 0;
	if (wnp[0] == L'\\' && wnp[1] == L'\\' && wnp[2] != L'\\')
	{
		wchar_t *p = &wnp[2];

		/* Skip server-name letters. */
		while (*p != L'\\' && *p != L'\0')
			++p;
		if (*p == L'\\')
		{
			wchar_t *rp = ++p;
			/* Skip share-name letters. */
			while (*p != L'\\' && *p != L'\0')
				++p;
			if (*p == L'\\' && p != rp)
			{
				/* Now, match patterns such as
				 * "\\server-name\share-name\" */
				wnp += 2;
				len -= 2;
				unc = 1;
			}
		}
	}

	slen = 4 + (unc * 4) + len + 1;
	ws = wsp = malloc(slen * sizeof(wchar_t));
	if (ws == NULL)
	{
		//free(wn);
		return (NULL);
	}
	/* prepend "\\?\" */
	wcsncpy(wsp, L"\\\\?\\", 4);
	wsp += 4;
	slen -= 4;
	if (unc)
	{
		/* append "UNC\" ---> "\\?\UNC\" */
		wcsncpy(wsp, L"UNC\\", 4);
		wsp += 4;
		slen -= 4;
	}
	wcsncpy(wsp, wnp, slen);
	wsp[slen - 1] = L'\0'; /* Ensure null termination. */
	//free(wn);

	wcscpy(wnp, ws);

	free(ws);

	return (wnp);
}

/***************************************************************************************************************
 */

/**
 * To benchmark code execution, it will say in seconds and milliseconds the time passed
 *
 * @param value if 0 it will initialize the internal time position, if 1 it will return the time elapsed
 *
 *
 */
double
inittimer2(int value)
{
	static double freq = 0;
	static LARGE_INTEGER first;
	static LARGE_INTEGER second;

	if (0 == value)
	{
		if (freq == 0)
		{
			QueryPerformanceFrequency(&first);
			freq = (double)first.QuadPart;
		}

		QueryPerformanceCounter(&first);

		return 0;
	}

	if (1 == value)
	{
		QueryPerformanceCounter(&second);
		second.QuadPart = second.QuadPart -
						  first.QuadPart;
		return (double)second.QuadPart / freq;
	}

	return 0;
}

/**
 * My fixed strncpy
 *
 *
 */
void strncpy_z(char *dest_z, char *src_z, size_t len_)
{

	int len = (int)len_;

	assert(0 <= (int)len);

	len--;

	if (0 > len)
	{
		len = 0;
	}

	if (strlen(src_z) < (size_t)len)
	{
		strcpy(dest_z, src_z);
	}
	else
	{
		memcpy(dest_z, src_z, len);
		dest_z[len] = 0;
	}
	return;
}

int __amandacall set_temp_folder_z(char *folder_z);

/* Bound on buffer size needed to represent an integer type or expression T,
   including the terminating null.  */
#define INT_BUFSIZE_BOUND(t) (INT_STRLEN_BOUND(t) + 1)

#define UINTMAX_STRSIZE_BOUND INT_BUFSIZE_BOUND(uintmax_t)

#define xmalloc malloc

#define obstack_chunk_alloc xmalloc

#define MODE_IS_ARP_DEBUG 1

#define obstack_chunk_free free

#include "arp_2.h"
#include "arp.h"

FILE *decoder_file_z = NULL;

int init_decoder_z = 0;

bool keep_temp_file_flag_z = false;

int running_update = 0;

bool is_encrypted_by_extension = false;

char file_to_keep_z[AMANDA__SIZE] = {
	0,
};

char temp_file_for_encrypted[AMANDA__SIZE];
char temp_file_for_encrypted_v2[AMANDA__SIZE];

int already_arp;

int encryption_method_arp;

int encryption_method_to_create = ARP_AES;

int time_point_arp_2 = 0;

bool use_name_i = false;

int iso_mode_value = ARP_MODE_JOLIET_PLUS_ROCK_RIDGE;

int32_t decompression_progress_mode_arp = -1;

VAL_data my_VAL_data_arp;

bool is_mislaine_encrypted_;
bool is_mislaine_encrypted_v2_z;

int ret_arp_;

bool mode_is_VAL_arp;

int detected_format_arp;

char string_format_arp[1024] = "unkonwn";

char temp_folder_z[AMANDA__SIZE] = {
	0,
};

char *
ar_gettemppath_z(void);

bool file_is_VAL_arp;

int ispathfile(char *path);

char *
umaxtostr(uintmax_t i, char *buf);

char *
strsep(char **stringp, const char *delim);

int getpor_10000_int64_t_ar(int64_t max, int64_t fatia);

bool strmatch(char str[], char pattern[], int n, int m);

char global_patern_ar[20000] = {
	0,
};

__int64 file_size_total_int64 = 0;
__int64 file_total__read_int64 = 0;

bool extract_pause__flag;
bool extract_cancel_flag;

int last_list_error_int_arp;
char last_list_error_message_arp[AMANDA__SIZE];

bool mode_is_list_arp;
int has_itens_is_amanda_update_internal_b_arp;
bool mode_is_update_arp = false;

int step_for_create_arp;

FILE *our_update_file_fopen_arp = NULL;
int our_update_file_open__arp = -1;
int bytes_written_to_update_file_arp;
int64_t bytes_left_in_the_update_file_arp;
char update_filename_arp[AMANDA__SIZE];
char update_temp_dir_arp[AMANDA__SIZE];

bool recurse_on_subfolders_arp = true;

char creating_folder_maria[AMANDA__SIZE];

int getpor_10000(int max, int fatia);

void strtolower_ar(char *path);

int running_2_ar = 0;
int return_value_from_list = 0;

#define major(device) (device)
#define minor(device) (device)
#define makedev(major, minor) (((major) << 8) | (minor))

#define major_t int
#define minor_t int

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
WCHAR *amanda_utf8towide_1_(char *pUTF8)
{
	static WCHAR ricardo_k[AMANDA__SIZE_w + 1];

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, AMANDA__SIZE_w);
	return ricardo_k;
}

/**
 * <p align='justify'> To <b>convert</b> an utf-8 encoded filename to a wide string (WCHAR *) two functions
 * with the same code are required for multi-thread code even if we don&apos;t use
 * it here this mode</p>
 *
 * @param pUTF8 the input utf-8 encoded filename
 *
 * @return the static allocated WCHAR array with the filename as wide string
 *
 */
WCHAR *amanda_utf8towide_2_(char *pUTF8)
{
	static WCHAR ricardo_k[AMANDA__SIZE_w + 1];

	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, AMANDA__SIZE_w);
	return ricardo_k;
}
/**
 * To convert a wide string to an utf-8 encoded filename, today everything
 * is utf-8 encoded (fortunately...)
 *
 * @param pUSC2 the input wide string
 *
 * @param pUTF8 the output filename as utf-8
 *
 * @param nUTF8 the number of characters (bytes) in the pUTF8 array
 *
 */
int widetoutf8_ar(WCHAR *pUSC2, char *pUTF8, int nUTF8)
{
	return WideCharToMultiByte(CP_UTF8, 0, pUSC2, -1, (LPSTR)pUTF8, nUTF8, 0, 0);
}

/**
 * To convert an input wide string to a utf-8 encoded filename on return
 *
 * @param pUSC2_maria the wide string to be converted
 *
 * @return it will return the static allocated char * string with the utf-8 encoded filename
 *
 */
char *valquiria_wide_to_utf8(WCHAR *pUSC2_maria)
{
	static char saida_utf8[AMANDA__SIZE];

	WideCharToMultiByte(CP_UTF8, 0, pUSC2_maria, -1, (LPSTR)saida_utf8, AMANDA__SIZE, 0, 0);
	return saida_utf8;
}
/**
 * Function to generate a temporary filename, at this time we are using
 * createtempfilename_and_keep_z because it gives better reults
 *
 * @param path_arp the path where the file will be defined (but will
 * not be created, to create a temp file in the destination folder use the function createtempfilename_and_keep_z
 *
 *
 */
void rspgettemppath_arp(char *path_arp)
{
	static WCHAR out_arp[AMANDA__SIZE_w + 1];

	GetTempPathW(AMANDA__SIZE_w, out_arp);
	strncpy_z(path_arp, valquiria_wide_to_utf8(out_arp), AMANDA__SIZE_w);
	strcat(path_arp, "temp_file_");
	sprintf(path_arp + strlen(path_arp), "%d_arp.tmp", (int)GetTickCount());
	return;
}

bool enable_encryption_arp_ = false;
char the_pass_arp[1024 + 1 /*for safety*/] = {0};
char the_pass_arp_utf8_i[1024 + 1 /*for safety*/] = {0};

/**
 * To pass the password to the DLL, if it is not called the password will be "" or an empty string
 *
 * @param the_pass_arp_ the input password
 *
 */
void __stdcall pass_password(char *the_pass_arp_, char *the_pass_arp_as_utf_8_i_)
{
	memset(the_pass_arp, 0, sizeof(the_pass_arp));
	strncpy_z(the_pass_arp, the_pass_arp_, 1023); //porque o medo???
	memset(the_pass_arp_utf8_i, 0, sizeof(the_pass_arp_utf8_i));
	strncpy_z(the_pass_arp_utf8_i, the_pass_arp_as_utf_8_i_, 1023); //porque o medo???
}

/**
 * To enable or disable the encryption, if possible use the new encryption mode
 * because the old mode will try to compress an encrypted file what is impossible,
 * it was a programmer mistake
 *
 * @param enable_arp to enable or disable
 *
 */
void __stdcall enable_encryption(int enable_arp)
{
	enable_encryption_arp_ = false;
	if (enable_arp)
	{
		enable_encryption_arp_ = true;
	}
}
//WIN64 also work...
#ifdef _M_X64
#define MACHINE_ARP_ "64"
#else
#define MACHINE_ARP_ "32"
#endif
static void
mprintf___arp(char *format, ...);

HMODULE my_libarchive_dll = NULL;

typedef int(__stdcall *get_tar_info_p)(
	int *Isdir_k_ar,
	int *Second_k_ar,
	int *Minute_k_ar,
	int *Hour_k_ar,
	int *Year_k_ar,
	int *Month_k_ar,
	int *Day_k_ar,
	__int64 *Size_k_ar,
	char *filename_k_ar,
	int *Numdir_k_ar,
	int *Numfiles_k_ar,
	char *typeflag_ar_);

typedef int(__stdcall *libarchive_list_entries_p)(char *filename_utf_8_p, char *password_p, tar_list_function_ar our_function_p, char *error_message_p, char *archive_format_p);

typedef int(__stdcall *libarchive_extract_entries_p)(char *filename_utf_8_p, char *password_p, tar_list_function_ar our_function_p, char *error_message_p, char *archive_format_p, char *dir_to_extract_i, char *extracting_filename_ar, char *warning_info, char *creating_folder_maria, bool *extract_pause__flag, bool *extract_cancel_flag, int *folders_ar, int *files_ar);

typedef int(__stdcall *libarchive_create_archive_init_p)(int archive_kind_p, char *file_utf_8_p, char *passphrase_p,
														 char *compression_level_p, int number_of_threads_p_);
typedef int(__stdcall *libarchive_process_p)(char *new_entry_relative_p, char *new_entry_complete_p);
typedef int(__stdcall *libarchive_close_p)(void);
typedef int(__stdcall *set_progress_p)(int64_t *pointer_value_p);
typedef int(__stdcall *progress_extract_i)(void);

typedef int(__stdcall *init_playlist_z_june_24_i)(void);
typedef void(__stdcall *add_more_one_z_june_24_i)(
	time_t atime_i,
	time_t mtime_i,
	time_t birthtime_i,
	int64_t filesize_i,
	int64_t file_offset_i,
	char *item_entry_i,
	bool is_dir_i,
	bool in_use_i,
	int64_t attributes_i);

typedef int(__stdcall *check_item_z_june_24_i)(char *filename_utf8);

typedef int(__stdcall *extract_to_file_i)(char *temp_path_i, bool enable_i, char *temp_file_i, init_playlist_z_june_24_i init_playlist_z_june_24_ii, add_more_one_z_june_24_i add_more_one_z_june_24_ii, check_item_z_june_24_i check_item_z_june_24_ii);

get_tar_info_p get_tar_info_p_func = NULL;
libarchive_list_entries_p libarchive_list_entries_p_func = NULL;
libarchive_extract_entries_p libarchive_extract_entries_p_func = NULL;
libarchive_create_archive_init_p libarchive_create_archive_init_p_func = NULL;
libarchive_process_p libarchive_process_p_func = NULL;
libarchive_close_p libarchive_close_p_func = NULL;
set_progress_p set_progress_p_func = NULL;
progress_extract_i progress_extract_i_func = NULL;

extract_to_file_i extract_to_file_i_func = NULL;

HMODULE my_rsp_arp_encrypt_dll = NULL;

#define IS_TAR_DLL_I

////////////////////////////////////////////////////////////////////////////////

char remote_path_z_i[1027];
char user_name_z_i[1027];
char password_z_i[1027];
char host_z_i[1027];
char local_file_i[AMANDA__SIZE];

int returnvalue_i = 0;
__INT32_OR_INT64 my_thread_handle = 0;
bool sftp_already_running = false;
HANDLE hMapFile_arp_i = NULL;

#pragma pack(push, 1)
typedef struct _amanda_i_
{
	char the__path_i[1024]; //need to change soon... 17/september...
	char key_fingerprint_i[1024];
	int progress_arp;
	int pause____arp;
	int cancel___arp;
} our_map_arp_i;
#pragma pack(pop)

our_map_arp_i global_our_map_arp_i = {0};
our_map_arp_i *global_ptr_our_map_arp_v27_i = NULL;

unsigned __stdcall my_thread_function_v27(__attribute__((unused)) void *my_argument_z)
{
#define BUF_SIZE_ARP_I (sizeof(our_map_arp_i))

	char szName_arp_i[1027] = "que_dia____te_amo";
	int rnd_z;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	DWORD exit_code_arp_i = 0;
	char command_line_arp_i[1027];

#ifdef IS_TAR_DLL_I
	char copy_arp[1024];
#endif

	returnvalue_i = 0;

	rnd_z = 1000000000;
	rnd_z = get_rand(0, rnd_z);
	sprintf(szName_arp_i + strlen(szName_arp_i), "_%d", rnd_z);

	hMapFile_arp_i = CreateFileMapping(
		INVALID_HANDLE_VALUE, // use paging file
		NULL,				  // default security
		PAGE_READWRITE,		  // read/write access
		0,					  // maximum object size (high-order DWORD)
		BUF_SIZE_ARP_I,		  // maximum object size (low-order DWORD)
		szName_arp_i);		  // name of mapping object

	if (NULL == hMapFile_arp_i)
	{
#ifdef IS_TAR_DLL_I
		sprintf(copy_arp, "Could not create file mapping object (%d)",
				(int)GetLastError());

		strcpy(error_message_k, copy_arp);
#endif
		returnvalue_i = 28006;
		goto saida_i;
	}

	global_ptr_our_map_arp_v27_i = (our_map_arp_i *)MapViewOfFile(hMapFile_arp_i,	   // handle to map object
																  FILE_MAP_ALL_ACCESS, // read/write permission
																  0,
																  0,
																  BUF_SIZE_ARP_I);

	if (NULL == global_ptr_our_map_arp_v27_i)
	{
#ifdef IS_TAR_DLL_I
		sprintf(copy_arp, "Could not map view of file (%d)",
				(int)GetLastError());
		strcpy(error_message_k, copy_arp);
#endif

		CloseHandle(hMapFile_arp_i);
		returnvalue_i = 28007;
		goto saida_i;
	}

	memset(&global_our_map_arp_i, 0, sizeof(global_our_map_arp_i));
	CopyMemory((PVOID)global_ptr_our_map_arp_v27_i, &global_our_map_arp_i, BUF_SIZE_ARP_I);
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW;

#ifdef WIN64
	strcpy(command_line_arp_i, "be_psftp_64.exe ");
#else
	strcpy(command_line_arp_i, "be_psftp_32.exe "); // sem quebrar a compatbilidade se poss?vel...
#endif

	/*
	   arp_psftp_function_func(remote_path_z, user_name_z, password_z, host_z, local_file,
	                               "to remember february 2021..."
	                               );


	   char remote_path_z_i[1027];
	   char user_name_z_i  [1027];
	   char password_z_i[1027];
	   char host_z_i[1027];
	   char local_file_i[1027];

	 */

	strcat(command_line_arp_i, "\"");
	strcat(command_line_arp_i, szName_arp_i);
	strcat(command_line_arp_i, "\" \"");
	strcat(command_line_arp_i, remote_path_z_i);
	strcat(command_line_arp_i, "\" \"");
	strcat(command_line_arp_i, user_name_z_i);
	strcat(command_line_arp_i, "\" \"");
	strcat(command_line_arp_i, password_z_i);
	strcat(command_line_arp_i, "\" \"");
	strcat(command_line_arp_i, host_z_i);
	strcat(command_line_arp_i, "\" \"");
	strcat(command_line_arp_i, local_file_i);
	strcat(command_line_arp_i, "\"");

	if (!CreateProcess(NULL, command_line_arp_i, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
#ifdef IS_TAR_DLL_I
		sprintf(copy_arp, "Could not start executable 'be_psftp_xx.exe' (%d)",
				(int)GetLastError());

		strcpy(error_message_k, copy_arp);
#endif
		UnmapViewOfFile(global_ptr_our_map_arp_v27_i);
		CloseHandle(hMapFile_arp_i);
		global_ptr_our_map_arp_v27_i = NULL;
		returnvalue_i = 28008;
		goto saida_i;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	GetExitCodeProcess(pi.hProcess, &exit_code_arp_i);
	UnmapViewOfFile(global_ptr_our_map_arp_v27_i);
	CloseHandle(hMapFile_arp_i);
	global_ptr_our_map_arp_v27_i = NULL;
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	if (0 == returnvalue_i)
	{
		returnvalue_i = exit_code_arp_i;
	}

saida_i:;

	sftp_already_running = false;

	_endthreadex(0);

	return 27 + 51;
}

void init_psftp_arp(void)
{
	return;
}
/**
 * To make a call to the SFTP code, sending a local file to the remote path
 *
 * @param remote_path_z the remote path            example: /htdocs
 * @param user_name_z   the SFTP session user name example: amandaricardo
 * @param password_z    the SFTP session password  example: amandaavakocipereira
 * @param host_z        the SFTP host, example:    example: web.sf.net
 * @param local_file    the local file to upload   example: c:\\upload\\jpeg\\ale.jpg
 *
 * @return it will return 0 if ok, 1 otherwise, notice that you need to
 * call get_sftp_return_value_z() to know what is the return value for
 * the SFTP upload progress, see the sample project to an example
 *
 */
int __stdcall pass_sftp_data_z(
	char *remote_path_z,
	char *user_name_z,
	char *password_z,
	char *host_z,
	char *local_file)
{
	/*
	   return arp_psftp_function_func(remote_path_z, user_name_z, password_z, host_z, local_file,
	                               "to remember february 2021..."
	                               );
	 */

	if (sftp_already_running)
	{
		return 1;
	}

	remote_path_i[0] = 0;
	key_fingerprint_i[0] = 0;
	strcpy(remote_path_z_i, remote_path_z);
	strcpy(user_name_z_i, user_name_z);
	strcpy(password_z_i, password_z);
	strcpy(host_z_i, host_z);
	strcpy(local_file_i, local_file);

	sftp_already_running = true;
	my_thread_handle = (__INT32_OR_INT64)_beginthreadex(NULL, 0, my_thread_function_v27, NULL, 0, NULL);

	return 0; //pode dizer se ja esta sendo executado...ok amor...
}

/**
 * It will return the error code returned by the call to the main SFTP function call
 * pass_sftp_data_z
 *
 * @return the error value, 0 if ok
 *
 */
int __stdcall get_sftp_return_value_z(
	void)
{
	return returnvalue_i;
}

/**
 * It will return the current remote path, just to know whether the
 * correct path was set, as an example if the remote path donï¿½t exist
 * you may think that it was set correctly
 *
 * @param path_z the variable that will receive the remote path
 * information, suggested size 1024
 *
 */
int __stdcall get_remote_directory_z(char *path_z)
{

	if (0 != remote_path_i[0])
	{

		strcpy(path_z, remote_path_i);
	}
	else
	{
		if (sftp_already_running && global_ptr_our_map_arp_v27_i)
		{
			strcpy(path_z, global_ptr_our_map_arp_v27_i->the__path_i);

			strcpy(remote_path_i, path_z);
		}
	}

	return 0;
	//return get_remote_directory_pwd_func(path_z);
}

int __stdcall get_key_fingerprint_z(char *key_z)
{

	if (0 != key_fingerprint_i[0])
	{
		strcpy(key_z, key_fingerprint_i);
	}
	else
	{
		if (sftp_already_running && global_ptr_our_map_arp_v27_i)
		{
			strcpy(key_z, global_ptr_our_map_arp_v27_i->key_fingerprint_i);

			strcpy(key_fingerprint_i, key_z);
		}
	}

	return 0;
	//return get_remote_directory_pwd_func(path_z);
}

/**
 * After a call to pass_sftp_data_z it will return a value indicating
 * whether the SFTP code is sending the file or if it was finished
 *
 * @return 0 if not running, 1 otherwise
 *
 */
int __stdcall is_sftp_running_z(
	void)
{
	if (sftp_already_running)
	{
		return 1;
	}
	return 0;
}
/**
 * To pause the SFTP process, but then the server may close the connection after
 * the timeout passed
 *
 * @return 0
 *
 */
int __stdcall pause_sftp(void)
{
	if (sftp_already_running && global_ptr_our_map_arp_v27_i)
	{
		global_ptr_our_map_arp_v27_i->pause____arp = 1;
	}
	return 0; //pause_arp_func();
}
/**
 * To resume the SFTP process
 *
 * @return 0
 *
 */
int __stdcall resume_sftp(void)
{
	if (sftp_already_running && global_ptr_our_map_arp_v27_i)
	{
		global_ptr_our_map_arp_v27_i->pause____arp = 0;
	}
	return 0; //resume_arp_func();
}
/**
 * To cancel the SFTP process, if you regreted it
 *
 * @return 0
 *
 */
int __stdcall cancel_sftp(void)
{
	if (sftp_already_running && global_ptr_our_map_arp_v27_i)
	{
		global_ptr_our_map_arp_v27_i->cancel___arp = 1;
	}
	return 0; //cancel_arp_func();
}
/**
 * To retrieve the current position of the SFTP upload process
 *
 * @return 0 to 10000, 10000 = 100%, to know perfectly where is the
 * progress position, if you are demanding like me
 *
 */
int __stdcall progress_sftp(void)
{
	if (sftp_already_running && global_ptr_our_map_arp_v27_i)
	{
		return global_ptr_our_map_arp_v27_i->progress_arp;
	}
	return 0; //progress_arp_func();
}
typedef int (*decrypt_arp_)(char *inputfile, char *outputfile, char *key,
							int64_t *the_arp_file_size, char *encryption_method_i);
typedef int (*encrypt_arp_)(char *inputfile, char *outputfile, char *key, int is_rc4_arp);
typedef int(__stdcall *PauseExecution__arp_)(void);
typedef int(__stdcall *ResumeExecution_arp_)(void);
typedef int(__stdcall *CancelExecution_arp_)(void);
typedef int(__stdcall *GetProgress_____arp_)(void);
typedef int(__stdcall *internal_progress_z_arp_)(void);
typedef void (*update_progress_arp_)(int64_t *valor_a_atualizar_arp);
decrypt_arp_ decrypt_arp_func = NULL;
encrypt_arp_ encrypt_arp_func = NULL;
PauseExecution__arp_ PauseExecution__arp_func = NULL;
ResumeExecution_arp_ ResumeExecution_arp_func = NULL;
CancelExecution_arp_ CancelExecution_arp_func = NULL;
GetProgress_____arp_ GetProgress_____arp_func = NULL;
update_progress_arp_ update_progress_arp_func = NULL;
internal_progress_z_arp_ internal_progress_z_arp_func = NULL;

/**
 * To init the encrypt DLL, if you for some unknown reason need to hide 
 * information on your PC, like me
 *
 * @return void...
 * 
 */
void init_rsp_arp_encrypt_arp(void) //ola
{

	char copy_ar[1024];

	if (NULL == my_rsp_arp_encrypt_dll)
	{
		my_rsp_arp_encrypt_dll = LoadLibraryA(
			"RSP_encrypt_" MACHINE_ARP_ ".DLL");

		if (NULL == my_rsp_arp_encrypt_dll)
		{

			sprintf(copy_ar, "Cannot find DLL RSP_encrypt_" MACHINE_ARP_ ".DLL, it is required if"
							 "you want to encrypt and decrypt files");
			mprintf___arp("%s\n", copy_ar);
			exit(1);
			return;
		}
		else
		{
			decrypt_arp_func = (void *)GetProcAddress(
				my_rsp_arp_encrypt_dll,
				"decrypt_arp");

			encrypt_arp_func = (void *)GetProcAddress(
				my_rsp_arp_encrypt_dll,
				"encrypt_arp");

			PauseExecution__arp_func = (void *)GetProcAddress(
				my_rsp_arp_encrypt_dll,
				"PauseExecution");

			ResumeExecution_arp_func = (void *)GetProcAddress(
				my_rsp_arp_encrypt_dll,
				"ResumeExecution");

			CancelExecution_arp_func = (void *)GetProcAddress(
				my_rsp_arp_encrypt_dll,
				"CancelExecution");

			GetProgress_____arp_func = (void *)GetProcAddress(
				my_rsp_arp_encrypt_dll,
				"GetProgress");

			update_progress_arp_func = (void *)GetProcAddress(
				my_rsp_arp_encrypt_dll,
				"update_progress_arp");

			internal_progress_z_arp_func = (void *)GetProcAddress(
				my_rsp_arp_encrypt_dll,
				"internal_progress_z");

			assert(decrypt_arp_func);
			assert(encrypt_arp_func);
			assert(PauseExecution__arp_func);
			assert(ResumeExecution_arp_func);
			assert(CancelExecution_arp_func);
			assert(GetProgress_____arp_func);
			assert(update_progress_arp_func);
			assert(internal_progress_z_arp_func);
		}
	}
	return;
}

/**
 * To retrieve the progress information for the encrypt or decrypt
 * process, before loading a tar or VAL file if it is compressed it
 * needs to uncompress it and this is the progress of this decompression
 *
 * @return 0 to 10000, 10000 == 100%
 */
int internal_progress_z(void)
{
	init_rsp_arp_encrypt_arp();
	return internal_progress_z_arp_func();
}
/**
 * It will pass the address of the int64_t variable that will be
 * updated, (only for internal use)
 *
 *
 */
void update_progress_arp(int64_t *bytes_read_arp__)
{
	init_rsp_arp_encrypt_arp();
	update_progress_arp_func(bytes_read_arp__);
	return;
}

/**
 * To encrypt the file, full support to wide paths...Ricardo
 *
 * @param inputfile the utf-8 input file
 *
 * @param outputfile the utf-8 output file
 *
 * @param key the up to 32 bytes password, passwords larger than 32 bytes will be truncated
 *
 * @param encryption_method_z the encryption method to be used, see file arp.h the enum encryption_mode_arp for valid modes
 *
 * @return 0 if ok
 *
 */
int encrypt_arp(char *inputfile, char *outputfile, char *key, int encryption_method_z)
{
	init_rsp_arp_encrypt_arp();
	return encrypt_arp_func(inputfile, outputfile, key, encryption_method_z);
}

/**
 * To decrypt the file
 *
 * @param inputfile the utf8 encoded input file to decrypt
 *
 * @param outputfile the utf-8 encoded output file
 *
 * @param key up to 32 bytes password to be used
 *
 * @param the_arp_file_size it is a pointer to a int64_t variable that will
 * receive the size of the original file detected from the encrypted file, not
 * in use at this time, this value is just ignored
 *
 * @return 0 if no error occurred, if an erroneous password was used it will not return 0
 *
 */
int decrypt_arp(char *inputfile, char *outputfile, char *key, int64_t *the_arp_file_size, char *encryption_method_i)
{
	init_rsp_arp_encrypt_arp();
	return decrypt_arp_func(inputfile, outputfile, key, the_arp_file_size, encryption_method_i);
}

/**
 * To print a simple message
 *
 * @param format and ... the printf like parameters
 *
 */
static void
mprintf___arp(char *format, ...)
{
	char *buffer = calloc(1, 10000); //for multithread sake
	va_list amanda_do_ricardo;

	va_start(amanda_do_ricardo, format);
	vsprintf(buffer, format, amanda_do_ricardo);
	va_end(amanda_do_ricardo);
	MessageBox(0, buffer, "BW Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
	free(buffer);
}

/**
 * Internal function to read information from a XML file<br>
 * It is using our own 45kb source code to handle these files.
 *
 * @param key_name_z the subnode to retrieve the data
 *
 * @param data_z     where the data is passed...
 *
 * @return 0 if no error, or an error as you may expect
 *
 */
int write_xml_z(char *key_name_z, char *data_z)
{
	if (MODE_IS_ARP_DEBUG && ispathfile("c:\\Ava\\back\\my_c_file.c"))
	{
		return feline_write_xml("c:\\Ava\\back\\my_c_file.mis",
								"ok12_settings_22_march_2021__19_06",
								key_name_z,
								NULL,
								data_z);
	}
	else
	{
		return feline_write_xml("ar_tar_process.mis",
								"ok12_settings_22_march_2021__19_06",
								key_name_z,
								NULL,
								data_z);
	}
}

int __stdcall write_xml_z_amanda_s_smart_ape(char *filename_amanda_s_smart_ape, char *key_name_z, char *data_z)
{
	{
		return feline_write_xml(filename_amanda_s_smart_ape,
								"ok12_settings_16_february_1994",
								key_name_z,
								NULL,
								data_z);
	}
}

int __stdcall read_xml_z_amanda_s_smart_ape(char *filename_amanda_s_smart_ape, char *key_name_z, char *data_z, int output_len_z)
{
	int ret_arp;
	char *buf_z;
	int64_t size_z;

	{
		size_z = getfilesize_ar(filename_amanda_s_smart_ape);
		buf_z = malloc(size_z + 1);
		ret_arp = feline_read_xml(filename_amanda_s_smart_ape,
								  "ok12_settings_16_february_1994",
								  key_name_z,
								  NULL,
								  buf_z);
		strncpy_z(data_z, buf_z, output_len_z);
		free(buf_z);
	}
	return ret_arp;
}

/**
 * To get a randomic number between min and max inclusive, seed is automatic loaded during the first call
 *
 */
int __stdcall get_rand(int min, int max)
{

	int range = max - min;
	int ret;
	static bool already_amanda_s_smart_ape = false;
	/*
	   BOOLEAN RtlGenRandom(
	   PVOID RandomBuffer,
	   ULONG RandomBufferLength
	   );
	 */

	typedef BOOLEAN(__stdcall * RtlGenRandom)(PVOID RandomBuffer,
											  ULONG RandomBufferLength);

	static HMODULE my_i____dll = NULL;
	static RtlGenRandom RtlGenRandom_func = NULL;

	if (false == already_amanda_s_smart_ape)
		srand(time(0)),
			already_amanda_s_smart_ape = true;

	ret = (GetTickCount() * GetTickCount()) + GetTickCount(); //hack

	if (RtlGenRandom_func)
	{
		assert(TRUE == RtlGenRandom_func(&ret, 4));
		goto already_i;
	}

	if (NULL == my_i____dll)
	{

		my_i____dll = LoadLibraryA(
			"Advapi32.dll");

		if (NULL == my_i____dll)
		{
			;
		}
		else
		{

			RtlGenRandom_func = (void *)GetProcAddress(
				my_i____dll,
				"SystemFunction036");

			if (NULL == RtlGenRandom_func)
			{
				;
			}
			else
			{

				assert(TRUE == RtlGenRandom_func(&ret, 4));
			}
		}
	}

already_i:;

	if (/*1 || */ NULL == RtlGenRandom_func)
	{
		pedro_dprintf(1001, "Important!!! Cannot use the function SystemFunction036\n");
		//Beep(1000, 1000);
	}

	//ret = -2147483648;

	ret = abs(ret);
	ret = ret % (range + 1);
	ret += min;

	pedro_dprintf(-1, "valor de ret antes do fix %d\n", ret);

	if (ret < min)
	{
		ret = min; //fix for the abs problem

		pedro_dprintf(-1, "valor de ret depois do fix %d\n", ret);
	}
	return ret;
}

/**
 * To read a XML file, it is simple then it is amazingly fast<br>
 *
 * @param key_name_z the subnode from where the data will be read<br>
 * if inexistent an empty string will return.
 *
 * @param data_z where the data arrives, if it do exist in the XML file, as you<br>
 * may expect
 *
 * @param output_len_z the size available to write in the data_z buffer<br>
 * It will not write more than output_len_z bytes (chars)
 *
 * @return 0 if no error, or an error otherwise
 *
 */
int read_xml_z(char *key_name_z, char *data_z, int output_len_z)
{
	int ret_arp;
	char *buf_z;
	int64_t size_z;

	if (MODE_IS_ARP_DEBUG && ispathfile("c:\\Ava\\back\\my_c_file.c"))
	{

		size_z = getfilesize_ar("c:\\Ava\\back\\my_c_file.mis");
		buf_z = malloc(size_z + 1);
		ret_arp = feline_read_xml("c:\\Ava\\back\\my_c_file.mis",
								  "ok12_settings_22_march_2021__19_06",
								  key_name_z,
								  NULL,
								  buf_z);
		strncpy_z(data_z, buf_z, output_len_z);
		free(buf_z);
	}
	else
	{
		size_z = getfilesize_ar("ar_tar_process.mis");
		buf_z = malloc(size_z + 1);
		ret_arp = feline_read_xml("ar_tar_process.mis",
								  "ok12_settings_22_march_2021__19_06",
								  key_name_z,
								  NULL,
								  buf_z);
		strncpy_z(data_z, buf_z, output_len_z);
		free(buf_z);
	}
	return ret_arp;
}

/**
 * We will patent these two functions and charge roylaties...
 *
 */
void convert_char_to_wchar_idiot_z(char *input_z, WCHAR *output_z)
{
	while (*input_z)
	{
		*output_z++ = *input_z++;
	}
	*output_z = 0;
	return;
}

/**
 * We will patent it...
 *
 *
 */
void convert_wchar_to_char_jerk_z(WCHAR *input_z, char *output_z)
{
	while (*input_z)
	{
		*output_z++ = *input_z++;
	}
	*output_z = 0;
	return;
}

/**
 * Function to read from standard Windows ini files<br>
 * These daus we are usinf XML but in some cases when internal<br>
 * debug mode is used an ini file is used.
 *
 * @param key_arp the key of the ini file
 *
 * @param data_arp where the data arrives
 *
 * @param if_has_data_use_this_z if it has data the path of the ini file<br>
 * passed will be this and not the detected path of the ini file
 *
 * @param output_len_z the max size to write to the data_arp variable<br>
 * if more data is available it will be truncated, you are warned
 *
 * @return always 0
 *
 */
int old_ini_get(char *key_arp, char *data_arp, char *if_has_data_use_this_z, int output_len_z)
{
	WCHAR exe_path_z[1027] = {
		0,
	};
	char exe_aath_z[1027] = {
		0,
	};
	char exe_fath_z[1027] = {
		0,
	};
	char data_z[1027] = {
		0,
	};
	WCHAR data_w_z[1027] = {
		0,
	};
	WCHAR key_arpw_z[1027] = {
		0,
	};

	GetModuleFileNameW(
		NULL,
		exe_path_z,
		1027);
	strncpy_z(exe_aath_z, valquiria_wide_to_utf8(exe_path_z), sizeof(exe_aath_z) - 1);
	stripfilenameandpath(exe_aath_z, exe_fath_z, NULL);
	strcat(exe_fath_z, "\\");
	strcat(exe_fath_z, "ar_tar_process.ini");

	if (if_has_data_use_this_z)
	{
		pedro_dprintf(-1, "Ola ricardo, obrigado por usar nossa rotina de ini\n");
		strncpy_z(exe_fath_z, if_has_data_use_this_z, sizeof(exe_fath_z) - 1);
	}

	convert_char_to_wchar_idiot_z(key_arp, key_arpw_z);
	GetPrivateProfileStringW(L"parolin", key_arpw_z, L"", data_w_z, sizeof(data_w_z) / 2 /* please, correct me if I am wrong */,
							 permissive_name_m_(amanda_utf8towide_1_(exe_fath_z)));
	convert_wchar_to_char_jerk_z(data_w_z, data_z);
	strncpy_z(data_arp, data_z, output_len_z);
	return 0;
}

/**
 * This will write to a standard Windows ini file.<br>
 *
 * @param key_arp_z the key of the ini file
 *
 * @param data_arp_z the data to write
 *
 * @param if_has_data_use_this_z if it has data the path of the<br>
 * ini file will be this, and ini files path cannot be relative, it<br>
 * need to be absolute
 *
 * @return always 0 as you may expect
 *
 */
int old_ini_write(char *key_arp_z, char *data_arp_z, char *if_has_data_use_this_z)
{
	WCHAR exe_path_z[1027];
	char exe_aath_z[1027];
	char exe_fath_z[1027];
	WCHAR data_w_z[1027];
	WCHAR key_arpw_z[1027];

	GetModuleFileNameW(
		NULL,
		exe_path_z,
		1027);
	strncpy_z(exe_aath_z, valquiria_wide_to_utf8(exe_path_z), sizeof(exe_aath_z) - 1);
	stripfilenameandpath(exe_aath_z, exe_fath_z, NULL);
	strcat(exe_fath_z, "\\");
	strcat(exe_fath_z, "ar_tar_process.ini");

	if (if_has_data_use_this_z)
	{
		pedro_dprintf(-1, "Ola ricardo, obrigado por usar nossa rotina de ini\n");
		strncpy_z(exe_fath_z, if_has_data_use_this_z, MAX_PATH);
	}
	convert_char_to_wchar_idiot_z(key_arp_z, key_arpw_z);
	convert_char_to_wchar_idiot_z(data_arp_z, data_w_z);
	WritePrivateProfileStringW(L"parolin", key_arpw_z, data_w_z,
							   permissive_name_m_(amanda_utf8towide_1_(exe_fath_z)));
	return 0;
}

/**
 * It will retrieve the settings from the ar_tar_process.ini
 *
 * @param key_arp the ini key name
 *
 * @param data_arp the output variable, "" if the data is empty or inexistent
 *
 * @return 0 if ok ;-)
 *
 */
int __stdcall get__settings_arp(char *key_arp_z, char *data_arp_z, int output_len_z)
{

	if (0 > output_len_z)
	{
		output_len_z = 0;
	}

	read_xml_z(key_arp_z, data_arp_z, output_len_z);

	return 0;
}
/**
 * To save the settings on the ar_tar_process.ini file, it is located
 * in the same path of the DLL, notice that after 2021/03/22 we are
 * storing C# sample project settings using embedded XML code to the
 * file ar_tar_process.mis and the ini file is deleted
 *
 * @param key_arp the key name
 *
 * @param data_arp the data to save
 *
 * @return always 0 as you may expect
 */
int __stdcall save_settings_arp(char *key_arp_z, char *data_arp_z)
{

	write_xml_z(key_arp_z, data_arp_z);

	return 0;
}
struct my_struct_for_list_ar_is_amanda_update_ //for list only
{
	DWORD VAL_attributes;
	VAL_data VAL_data__arp;
	__int64 size_of_file_arp;
	__time64_t VAL_timestamp64;
	bool has_VAL_struct_arp;
	char *filename_k;
	int VAL_is_encrypted;
	int is_directory_arp;
	int has_next; //not in use
	int64_t position_on_file_arp;
	struct my_struct_for_list_ar_is_amanda_update_ *next_ar;
	time_t mtime_tv_sec_arp;
};

struct my_struct_for_list_ar_is_amanda_update_ *aak_is_amanda_update_;
struct my_struct_for_list_ar_is_amanda_update_ *aak_inicio_is_amanda_update_;

struct my_struct_for_list_ar_is_amanda_update_ *aak_pointer_is_amanda_update_;

int has_itens_is_amanda_update_ = 0;

int has_itens_copy_is_amanda_update_ = 0;

/**
 * To add a new item to the linked list, full support to wide paths...Ricardo
 *
 */
void add_more_one_is_amanda_update_(
	char *filename_k_ar,
	__int64 size_of_file_arp,
	time_t mtime_tv_sec_arp,
	int is_directory_arp,
	__int64 position_on_file_arp,
	DWORD VAL_attributes,
	int VAL_is_encrypted,
	__time64_t VAL_timestamp64,
	VAL_data *VAL_data__arp)
{
	struct my_struct_for_list_ar_is_amanda_update_ *aak_ptr;

	if (!has_itens_is_amanda_update_)
	{
		aak_is_amanda_update_ = calloc(1, sizeof(struct
												 my_struct_for_list_ar_is_amanda_update_));
		aak_inicio_is_amanda_update_ = aak_is_amanda_update_;
		aak_pointer_is_amanda_update_ = aak_is_amanda_update_;
		aak_is_amanda_update_->filename_k = malloc(strlen(filename_k_ar) + 1);

		strcpy(aak_is_amanda_update_->filename_k, filename_k_ar);

		aak_is_amanda_update_->size_of_file_arp = size_of_file_arp;
		aak_is_amanda_update_->mtime_tv_sec_arp = mtime_tv_sec_arp;
		aak_is_amanda_update_->next_ar = calloc(1, sizeof(struct
														  my_struct_for_list_ar_is_amanda_update_));
		aak_is_amanda_update_->is_directory_arp = is_directory_arp;
		aak_is_amanda_update_->position_on_file_arp = position_on_file_arp;
		aak_is_amanda_update_->VAL_attributes = VAL_attributes;
		aak_is_amanda_update_->VAL_is_encrypted = VAL_is_encrypted;
		aak_is_amanda_update_->VAL_timestamp64 = VAL_timestamp64;

		aak_is_amanda_update_->has_VAL_struct_arp = false;

		if (VAL_data__arp)
		{
			aak_is_amanda_update_->VAL_data__arp = *VAL_data__arp;
			aak_is_amanda_update_->has_VAL_struct_arp = true;
		}
		has_itens_is_amanda_update_ = 1;
		has_itens_copy_is_amanda_update_ = has_itens_is_amanda_update_;

		aak_is_amanda_update_ = aak_is_amanda_update_->next_ar;
	}
	else
	{
		aak_ptr = aak_is_amanda_update_;
		assert(aak_ptr);

		assert(8 < sizeof(struct my_struct_for_list_ar_is_amanda_update_));

		aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_amanda_update_));

		aak_ptr->filename_k = malloc(strlen(filename_k_ar) + 1);

		strcpy(aak_ptr->filename_k, filename_k_ar);
		aak_ptr->size_of_file_arp = size_of_file_arp;
		aak_ptr->mtime_tv_sec_arp = mtime_tv_sec_arp;
		aak_ptr->is_directory_arp = is_directory_arp;
		aak_ptr->position_on_file_arp = position_on_file_arp;
		aak_ptr->VAL_attributes = VAL_attributes;
		aak_ptr->VAL_is_encrypted = VAL_is_encrypted;
		aak_ptr->VAL_timestamp64 = VAL_timestamp64;

		aak_ptr->has_VAL_struct_arp = false;

		if (VAL_data__arp)
		{
			aak_ptr->VAL_data__arp = *VAL_data__arp;
			aak_ptr->has_VAL_struct_arp = true;
		}

		aak_is_amanda_update_ = aak_ptr->next_ar;
		has_itens_is_amanda_update_++;
		has_itens_copy_is_amanda_update_ = has_itens_is_amanda_update_;
	}
}

int clean_list__ar_is_amanda_update_(void);

/**
 * To cleanup the linked list when it is not in use anymore
 *
 */
int clean_list_itens_is_amanda_update_(void)
{
	if (!has_itens_copy_is_amanda_update_)
	{
		clean_list__ar_is_amanda_update_();
		return 0;
	}
	aak_pointer_is_amanda_update_ = aak_pointer_is_amanda_update_->next_ar;
	has_itens_copy_is_amanda_update_--;
	assert(has_itens_copy_is_amanda_update_ >= 0);
	return 1;
}

/**
 * To cleanup the linked list when it is not in use anymore
 *
 */
int clean_list__ar_is_amanda_update_(void)
{
	struct my_struct_for_list_ar_is_amanda_update_ *my_ptr_ar;

	struct my_struct_for_list_ar_is_amanda_update_ *my_ptr2_ar;

	my_ptr2_ar = aak_inicio_is_amanda_update_;
	my_ptr_ar = aak_inicio_is_amanda_update_;
inicio_ar:;
	if (!has_itens_is_amanda_update_)
	{
		has_itens_copy_is_amanda_update_ = 0;
		return 0;
	}
	my_ptr2_ar = my_ptr_ar;
	my_ptr_ar = my_ptr_ar->next_ar;
	if (1 == has_itens_is_amanda_update_)
	{
		free(my_ptr2_ar->next_ar);
	}
	free(my_ptr2_ar->filename_k);
	free(my_ptr2_ar);
	has_itens_is_amanda_update_--;
	goto inicio_ar;
	return 1;
}

enum amanda_commands
{
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

HMODULE my_gzip_dll = NULL;
HMODULE my_bz2__dll = NULL;
HMODULE my_lzip__dll = NULL;
HMODULE my_lzma__dll = NULL;
HMODULE my_xz____dll = NULL;
HMODULE my_co____dll = NULL;
HMODULE my_ju____dll = NULL;
HMODULE my_l4____dll = NULL;
HMODULE my_zs____dll = NULL;
HMODULE my_br____dll = NULL;
HMODULE my_g2____dll = NULL;
HMODULE my_b3____dll = NULL;
HMODULE my_l3____dll = NULL;
HMODULE my_l5____dll = NULL;
HMODULE my_bb____dll = NULL;
HMODULE my_c5____dll = NULL;

/*
//now 7zip amazing DLL ...
HMODULE my_7z____dll = NULL;
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *Compress_gzip_ar)(char *Inputfile, char *OutPutFile, int CompressionLevel);
Compress_gzip_ar Compress_gzip_ar_func = NULL;
typedef int(__stdcall *GetFinished_gzip_ar)(void);
GetFinished_gzip_ar GetFinished_gzip_ar_func = NULL;
typedef int(__stdcall *GetProgress_gzip_ar)(void);
GetProgress_gzip_ar GetProgress_gzip_ar_func = NULL;
typedef void(__stdcall *PauseExecution_gzip_ar)(void);
PauseExecution_gzip_ar PauseExecution_gzip_ar_func = NULL;
typedef void(__stdcall *ResumeExecution_gzip_ar)(void);
ResumeExecution_gzip_ar ResumeExecution_gzip_ar_func = NULL;
typedef void(__stdcall *CancelExecution_gzip_ar)(void);
CancelExecution_gzip_ar CancelExecution_gzip_ar_func = NULL;
typedef int(__stdcall *GetReturnValue_gzip_ar)(void);
GetReturnValue_gzip_ar GetReturnValue_gzip_ar_func = NULL;
typedef int(__stdcall *Uncompress_gzip_ar)(char *Inputfile, char *OutPutFile);
Uncompress_gzip_ar Uncompress_gzip_ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *Compress_bzip2_ar)(char *Inputfile, char *OutPutFile, int CompressionLevel);
Compress_bzip2_ar Compress_bzip2_ar_func = NULL;
typedef int(__stdcall *GetStatus_bzip2_ar)(void);
GetStatus_bzip2_ar GetStatus_bzip2_ar_func = NULL;
typedef int(__stdcall *GetProgress_bzip2_ar)(void);
GetProgress_bzip2_ar GetProgress_bzip2_ar_func = NULL;
typedef int(__stdcall *PauseCompress_bzip2_ar)(void);
PauseCompress_bzip2_ar PauseCompress_bzip2_ar_func = NULL;
typedef int(__stdcall *ResumeCompress_bzip2_ar)(void);
ResumeCompress_bzip2_ar ResumeCompress_bzip2_ar_func = NULL;
typedef int(__stdcall *CancelCompress_bzip2_ar)(void);
CancelCompress_bzip2_ar CancelCompress_bzip2_ar_func = NULL;
typedef int(__stdcall *Decompress_bzip2_ar)(char *Inputfile, char *OutPutFile);
Decompress_bzip2_ar Decompress_bzip2_ar_func = NULL;
typedef int(__stdcall *GetReturnValue_bzip2_ar)(void);
GetReturnValue_bzip2_ar GetReturnValue_bzip2_ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_lzip_rspk_ar)(char *Inputfile, char *OutPutFile, int CompressionLevel);
compress_lzip_rspk_ar compress_lzip_rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_lzip_rspk_ar)(char *Inputfile, char *OutPutFile);
uncompress_lzip_rspk_ar uncompress_lzip_rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_lzip_ar)(void);
get_progress_lzip_ar get_progress_lzip_ar_func = NULL;
typedef int(__stdcall *pause_lzip_aakp_lzip_ar)(void);
pause_lzip_aakp_lzip_ar pause_lzip_aakp_lzip_ar_func = NULL;
typedef int(__stdcall *resume_lzip_aakp_lzip_ar)(void);
resume_lzip_aakp_lzip_ar resume_lzip_aakp_lzip_ar_func = NULL;
typedef int(__stdcall *cancel_lzip_aakp_lzip_ar)(void);
cancel_lzip_aakp_lzip_ar cancel_lzip_aakp_lzip_ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_lzma_rspk_ar)(char *Inputfile, char *OutPutFile, int CompressionLevel);
compress_lzma_rspk_ar compress_lzma_rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_lzma_rspk_ar)(char *Inputfile, char *OutPutFile);
uncompress_lzma_rspk_ar uncompress_lzma_rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_lzma_ar)(void);
get_progress_lzma_ar get_progress_lzma_ar_func = NULL;
typedef int(__stdcall *pause_lzma_aakp_lzma_ar)(void);
pause_lzma_aakp_lzma_ar pause_lzma_aakp_lzma_ar_func = NULL;
typedef int(__stdcall *resume_lzma_aakp_lzma_ar)(void);
resume_lzma_aakp_lzma_ar resume_lzma_aakp_lzma_ar_func = NULL;
typedef int(__stdcall *cancel_lzma_aakp_lzma_ar)(void);
cancel_lzma_aakp_lzma_ar cancel_lzma_aakp_lzma_ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_xz___rspk_ar)(char *Inputfile, char *OutPutFile, int CompressionLevel,
											  int threads____z);
compress_xz___rspk_ar compress_xz___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_xz___rspk_ar)(char *Inputfile, char *OutPutFile);
uncompress_xz___rspk_ar uncompress_xz___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_xz___ar)(void);
get_progress_xz___ar get_progress_xz___ar_func = NULL;
typedef int(__stdcall *pause_xz___aakp_xz___ar)(void);
pause_xz___aakp_xz___ar pause_xz___aakp_xz___ar_func = NULL;
typedef int(__stdcall *resume_xz___aakp_xz___ar)(void);
resume_xz___aakp_xz___ar resume_xz___aakp_xz___ar_func = NULL;
typedef int(__stdcall *cancel_xz___aakp_xz___ar)(void);
cancel_xz___aakp_xz___ar cancel_xz___aakp_xz___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//pra voce nï¿½o esquecer nunca...
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_co___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level);
compress_co___rspk_ar compress_co___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_co___rspk_ar)(char *Inputfile, char *OutPutFile);
uncompress_co___rspk_ar uncompress_co___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_co___ar)(void);
get_progress_co___ar get_progress_co___ar_func = NULL;
typedef int(__stdcall *pause_co___aakp_co___ar)(void);
pause_co___aakp_co___ar pause_co___aakp_co___ar_func = NULL;
typedef int(__stdcall *resume_co___aakp_co___ar)(void);
resume_co___aakp_co___ar resume_co___aakp_co___ar_func = NULL;
typedef int(__stdcall *cancel_co___aakp_co___ar)(void);
cancel_co___aakp_co___ar cancel_co___aakp_co___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_ju___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level);
compress_ju___rspk_ar compress_ju___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_ju___rspk_ar)(char *Inputfile, char *OutPutFile);
uncompress_ju___rspk_ar uncompress_ju___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_ju___ar)(void);
get_progress_ju___ar get_progress_ju___ar_func = NULL;
typedef int(__stdcall *pause_ju___aakp_ju___ar)(void);
pause_ju___aakp_ju___ar pause_ju___aakp_ju___ar_func = NULL;
typedef int(__stdcall *resume_ju___aakp_ju___ar)(void);
resume_ju___aakp_ju___ar resume_ju___aakp_ju___ar_func = NULL;
typedef int(__stdcall *cancel_ju___aakp_ju___ar)(void);
cancel_ju___aakp_ju___ar cancel_ju___aakp_ju___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_l4___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level);
compress_l4___rspk_ar compress_l4___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_l4___rspk_ar)(char *Inputfile, char *OutPutFile);
uncompress_l4___rspk_ar uncompress_l4___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_l4___ar)(void);
get_progress_l4___ar get_progress_l4___ar_func = NULL;
typedef int(__stdcall *pause_l4___aakp_l4___ar)(void);
pause_l4___aakp_l4___ar pause_l4___aakp_l4___ar_func = NULL;
typedef int(__stdcall *resume_l4___aakp_l4___ar)(void);
resume_l4___aakp_l4___ar resume_l4___aakp_l4___ar_func = NULL;
typedef int(__stdcall *cancel_l4___aakp_l4___ar)(void);
cancel_l4___aakp_l4___ar cancel_l4___aakp_l4___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_zs___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level, int threads_z);
compress_zs___rspk_ar compress_zs___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_zs___rspk_ar)(char *Inputfile, char *OutPutFile);
uncompress_zs___rspk_ar uncompress_zs___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_zs___ar)(void);
get_progress_zs___ar get_progress_zs___ar_func = NULL;
typedef int(__stdcall *pause_zs___aakp_zs___ar)(void);
pause_zs___aakp_zs___ar pause_zs___aakp_zs___ar_func = NULL;
typedef int(__stdcall *resume_zs___aakp_zs___ar)(void);
resume_zs___aakp_zs___ar resume_zs___aakp_zs___ar_func = NULL;
typedef int(__stdcall *cancel_zs___aakp_zs___ar)(void);
cancel_zs___aakp_zs___ar cancel_zs___aakp_zs___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_br___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level);
compress_br___rspk_ar compress_br___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_br___rspk_ar)(char *Inputfile, char *OutPutFile);
uncompress_br___rspk_ar uncompress_br___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_br___ar)(void);
get_progress_br___ar get_progress_br___ar_func = NULL;
typedef int(__stdcall *pause_br___aakp_br___ar)(void);
pause_br___aakp_br___ar pause_br___aakp_br___ar_func = NULL;
typedef int(__stdcall *resume_br___aakp_br___ar)(void);
resume_br___aakp_br___ar resume_br___aakp_br___ar_func = NULL;
typedef int(__stdcall *cancel_br___aakp_br___ar)(void);
cancel_br___aakp_br___ar cancel_br___aakp_br___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_g2___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level, int n_threads_z /* number of threads to use */, char *temp_path_z);
compress_g2___rspk_ar compress_g2___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_g2___rspk_ar)(char *Inputfile, char *OutPutFile, int n_threads_z /* number of threads to use */, char *temp_path_z, int *cores_used_z);
uncompress_g2___rspk_ar uncompress_g2___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_g2___ar)(void);
get_progress_g2___ar get_progress_g2___ar_func = NULL;
typedef int(__stdcall *pause_g2___aakp_g2___ar)(void);
pause_g2___aakp_g2___ar pause_g2___aakp_g2___ar_func = NULL;
typedef int(__stdcall *resume_g2___aakp_g2___ar)(void);
resume_g2___aakp_g2___ar resume_g2___aakp_g2___ar_func = NULL;
typedef int(__stdcall *cancel_g2___aakp_g2___ar)(void);
cancel_g2___aakp_g2___ar cancel_g2___aakp_g2___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_b3___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level, int n_threads_z /* number of threads to use */, char *temp_path_z);
compress_b3___rspk_ar compress_b3___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_b3___rspk_ar)(char *Inputfile, char *OutPutFile, int n_threads_z /* number of threads to use */, char *temp_path_z, int *cores_used_z);
uncompress_b3___rspk_ar uncompress_b3___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_b3___ar)(void);
get_progress_b3___ar get_progress_b3___ar_func = NULL;
typedef int(__stdcall *pause_b3___aakp_b3___ar)(void);
pause_b3___aakp_b3___ar pause_b3___aakp_b3___ar_func = NULL;
typedef int(__stdcall *resume_b3___aakp_b3___ar)(void);
resume_b3___aakp_b3___ar resume_b3___aakp_b3___ar_func = NULL;
typedef int(__stdcall *cancel_b3___aakp_b3___ar)(void);
cancel_b3___aakp_b3___ar cancel_b3___aakp_b3___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//for your pleasure

typedef int(__stdcall *compress_l3___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level, int n_threads_z /* number of threads to use */, char *temp_path_z);
compress_l3___rspk_ar compress_l3___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_l3___rspk_ar)(char *Inputfile, char *OutPutFile, int n_threads_z /* number of threads to use */, char *temp_path_z, int *cores_used_z);
uncompress_l3___rspk_ar uncompress_l3___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_l3___ar)(void);
get_progress_l3___ar get_progress_l3___ar_func = NULL;
typedef int(__stdcall *pause_l3___aakp_l3___ar)(void);
pause_l3___aakp_l3___ar pause_l3___aakp_l3___ar_func = NULL;
typedef int(__stdcall *resume_l3___aakp_l3___ar)(void);
resume_l3___aakp_l3___ar resume_l3___aakp_l3___ar_func = NULL;
typedef int(__stdcall *cancel_l3___aakp_l3___ar)(void);
cancel_l3___aakp_l3___ar cancel_l3___aakp_l3___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_l5___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level, int n_threads_z /* number of threads to use */, char *temp_path_z);
compress_l5___rspk_ar compress_l5___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_l5___rspk_ar)(char *Inputfile, char *OutPutFile, int n_threads_z /* number of threads to use */, char *temp_path_z, int *cores_used_z);
uncompress_l5___rspk_ar uncompress_l5___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_l5___ar)(void);
get_progress_l5___ar get_progress_l5___ar_func = NULL;
typedef int(__stdcall *pause_l5___aakp_l5___ar)(void);
pause_l5___aakp_l5___ar pause_l5___aakp_l5___ar_func = NULL;
typedef int(__stdcall *resume_l5___aakp_l5___ar)(void);
resume_l5___aakp_l5___ar resume_l5___aakp_l5___ar_func = NULL;
typedef int(__stdcall *cancel_l5___aakp_l5___ar)(void);
cancel_l5___aakp_l5___ar cancel_l5___aakp_l5___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef int(__stdcall *compress_bb___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level, int n_threads_z /* number of threads to use */, char *temp_path_z);
compress_bb___rspk_ar compress_bb___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_bb___rspk_ar)(char *Inputfile, char *OutPutFile, int n_threads_z /* number of threads to use */, char *temp_path_z, int *cores_used_z);
uncompress_bb___rspk_ar uncompress_bb___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_bb___ar)(void);
get_progress_bb___ar get_progress_bb___ar_func = NULL;
typedef int(__stdcall *pause_bb___aakp_bb___ar)(void);
pause_bb___aakp_bb___ar pause_bb___aakp_bb___ar_func = NULL;
typedef int(__stdcall *resume_bb___aakp_bb___ar)(void);
resume_bb___aakp_bb___ar resume_bb___aakp_bb___ar_func = NULL;
typedef int(__stdcall *cancel_bb___aakp_bb___ar)(void);
cancel_bb___aakp_bb___ar cancel_bb___aakp_bb___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//for your pleasure...

typedef int(__stdcall *compress_c5___rspk_ar)(char *Input_amanda_file, char *OutPut_ricardo_File, int Compression_juliete_Level, int n_threads_z /* number of threads to use */, char *temp_path_z);
compress_c5___rspk_ar compress_c5___rspk_ar_func = NULL;
typedef int(__stdcall *uncompress_c5___rspk_ar)(char *Inputfile, char *OutPutFile, int n_threads_z /* number of threads to use */, char *temp_path_z, int *cores_used_z);
uncompress_c5___rspk_ar uncompress_c5___rspk_ar_func = NULL;
typedef int(__stdcall *get_progress_c5___ar)(void);
get_progress_c5___ar get_progress_c5___ar_func = NULL;
typedef int(__stdcall *pause_c5___aakp_c5___ar)(void);
pause_c5___aakp_c5___ar pause_c5___aakp_c5___ar_func = NULL;
typedef int(__stdcall *resume_c5___aakp_c5___ar)(void);
resume_c5___aakp_c5___ar resume_c5___aakp_c5___ar_func = NULL;
typedef int(__stdcall *cancel_c5___aakp_c5___ar)(void);
cancel_c5___aakp_c5___ar cancel_c5___aakp_c5___ar_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

get_tar_info_p get_tar_info_libarchive_func = NULL;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int got_a_warning_ar = 0;
int processed_itens_ar = 0;
int numero_de_itens = 0;
int folders_ar;
int files_ar;
char extracting_filename_ar[AMANDA__SIZE];
char warning_info[AMANDA__SIZE];

void __stdcall get_tar_info_ar(
	int *Isdir_k_ar,
	int *Second_k_ar,
	int *Minute_k_ar,
	int *Hour_k_ar,
	int *Year_k_ar,
	int *Month_k_ar,
	int *Day_k_ar,
	__int64 *Size_k_ar,
	char *filename_k_ar,
	int *Numdir_k_ar,
	int *Numfiles_k_ar,
	char *typeflag_ar_);

/**
 * To get the file size, filename is utf-8
 *
 * @param infile_ar the input file
 *
 * @return the size of the file or 0 in case of error or if the file is empty, if you need
 * to know whether the file do exist use ispathfile function
 *
 */
__int64
getfilesize_ar(char *infile_ar)
{
	__int64 ret;
	FILE *myfile;

	if ((myfile = _wfopen(permissive_name_m_(amanda_utf8towide_1_(infile_ar)), L"rb")) == NULL)
	{
		return 0;
	}
	ret = _fseeki64(myfile, 0, SEEK_END);
	ret = _ftelli64(myfile);
	fclose(myfile);
	return ret;
}

#pragma pack(push, 1)

struct my_struct_for_list_ar_is_list_ //for list only
{
	__int64 Size_k;
	char *filename_k;
	char *typeflag_ar_;
	int Day_k;
	int Hour_k;
	int Isdir_k;
	int Minute_k;
	int Month_k;
	int Numdir_k;
	int Numfiles_k;
	int Second_k;
	int Year_k;
	int has_next; //not in use
	struct my_struct_for_list_ar_is_list_ *next_ar;
};

#pragma pack(pop)

struct my_struct_for_list_ar_is_list_ *aak_is_list_;
struct my_struct_for_list_ar_is_list_ *aak_inicio_is_list_;
struct my_struct_for_list_ar_is_list_ *aak_pointer_is_list_;

int has_itens_is_list_ = 0;

int has_itens_copy_is_list_ = 0;

/**
 * To add one item to the linked list
 *
 * @param filename_k_ar the filename as utf-8
 *
 */
void add_more_one_is_list_(
	int Isdir_k_ar,
	int Second_k_ar,
	int Minute_k_ar,
	int Hour_k_ar,
	int Year_k_ar,
	int Month_k_ar,
	int Day_k_ar,
	__int64 Size_k_ar,
	char *filename_k_ar,
	int Numdir_k_ar,
	int Numfiles_k_ar,
	char *typeflag_ar_)
{
	struct my_struct_for_list_ar_is_list_ *aak_ptr;

	if (!has_itens_is_list_)
	{
		aak_is_list_ = calloc(1, sizeof(struct my_struct_for_list_ar_is_list_));
		aak_inicio_is_list_ = aak_is_list_;
		aak_pointer_is_list_ = aak_is_list_;
		aak_is_list_->filename_k = malloc(strlen(filename_k_ar) + 1);
		aak_is_list_->typeflag_ar_ = malloc(strlen(typeflag_ar_) + 1);

		strcpy(aak_is_list_->filename_k, filename_k_ar);
		strcpy(aak_is_list_->typeflag_ar_, typeflag_ar_);

		aak_is_list_->Isdir_k = Isdir_k_ar;
		aak_is_list_->Second_k = Second_k_ar;
		aak_is_list_->Minute_k = Minute_k_ar;
		aak_is_list_->Hour_k = Hour_k_ar;
		aak_is_list_->Year_k = Year_k_ar;
		aak_is_list_->Month_k = Month_k_ar;
		aak_is_list_->Day_k = Day_k_ar;
		aak_is_list_->Size_k = Size_k_ar;
		aak_is_list_->Numdir_k = Numdir_k_ar;
		aak_is_list_->Numfiles_k = Numfiles_k_ar;

		aak_is_list_->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_list_));
		has_itens_is_list_ = 1;
		has_itens_copy_is_list_ = has_itens_is_list_;

		aak_is_list_ = aak_is_list_->next_ar;
	}
	else
	{
		aak_ptr = aak_is_list_;
		assert(aak_ptr);

		assert(8 < sizeof(struct my_struct_for_list_ar_is_list_));

		aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_list_));

		aak_ptr->filename_k = malloc(strlen(filename_k_ar) + 1);
		aak_ptr->typeflag_ar_ = malloc(strlen(typeflag_ar_) + 1);

		strcpy(aak_ptr->filename_k, filename_k_ar);
		strcpy(aak_ptr->typeflag_ar_, typeflag_ar_);
		aak_ptr->Isdir_k = Isdir_k_ar;
		aak_ptr->Second_k = Second_k_ar;
		aak_ptr->Minute_k = Minute_k_ar;
		aak_ptr->Hour_k = Hour_k_ar;
		aak_ptr->Year_k = Year_k_ar;
		aak_ptr->Month_k = Month_k_ar;
		aak_ptr->Day_k = Day_k_ar;
		aak_ptr->Size_k = Size_k_ar;
		aak_ptr->Numdir_k = Numdir_k_ar;
		aak_ptr->Numfiles_k = Numfiles_k_ar;
		aak_is_list_ = aak_ptr->next_ar;
		has_itens_is_list_++;
		has_itens_copy_is_list_ = has_itens_is_list_;
	}
}

int clean_list__ar_is_list_(void);

/**
 * To cleanup the linked list when it is not required anymore
 *
 * @return 1 if it have more items, or 0 for no more items
 *
 */
int clean_list_itens_is_list_(void)
{
	if (!has_itens_copy_is_list_)
	{
		clean_list__ar_is_list_();
		return 0;
	}
	aak_pointer_is_list_ = aak_pointer_is_list_->next_ar;
	has_itens_copy_is_list_--;
	assert(has_itens_copy_is_list_ >= 0);
	return 1;
}

/**
 * To retrieve one item from the linked list
 *
 * @param filename_k_ar is the filename as utf-8
 *
 * @return 1 if it has more items or 0 otherwise
 *
 */
int __stdcall get_list__itens__is_list_(
	char *filename_k_ar,
	char *typeflag_ar_,
	int *Isdir_k_ar,
	int *Second_k_ar,
	int *Minute_k_ar,
	int *Hour_k_ar,
	int *Year_k_ar,
	int *Month_k_ar,
	int *Day_k_ar,
	int64_t *Size_k_ar,
	int *Numdir_k_ar,
	int *Numfiles_k_ar,
	int output_len_z)
{
	mode_is_list_arp = true;
	filename_k_ar[0] = 0;
	typeflag_ar_[0] = 0;
	if (!has_itens_copy_is_list_)
	{
		clean_list__ar_is_list_();
		return 0;
	}

	strncpy_z(filename_k_ar, aak_pointer_is_list_->filename_k, output_len_z);
	strncpy_z(typeflag_ar_, aak_pointer_is_list_->typeflag_ar_, output_len_z);

	*Isdir_k_ar = aak_pointer_is_list_->Isdir_k;
	*Second_k_ar = aak_pointer_is_list_->Second_k;
	*Minute_k_ar = aak_pointer_is_list_->Minute_k;
	*Hour_k_ar = aak_pointer_is_list_->Hour_k;
	*Year_k_ar = aak_pointer_is_list_->Year_k;
	*Month_k_ar = aak_pointer_is_list_->Month_k;
	*Day_k_ar = aak_pointer_is_list_->Day_k;
	*Size_k_ar = aak_pointer_is_list_->Size_k;
	*Numdir_k_ar = aak_pointer_is_list_->Numdir_k;
	*Numfiles_k_ar = aak_pointer_is_list_->Numfiles_k;

	aak_pointer_is_list_ = aak_pointer_is_list_->next_ar;
	has_itens_copy_is_list_--;
	assert(has_itens_copy_is_list_ >= 0);
	return 1;
}
/**
 * To cleanup the linked list when it is not in use anymore
 *
 *
 */
int clean_list__ar_is_list_(void)
{
	struct my_struct_for_list_ar_is_list_ *my_ptr_ar;
	struct my_struct_for_list_ar_is_list_ *my_ptr2_ar;

	my_ptr2_ar = aak_inicio_is_list_;
	my_ptr_ar = aak_inicio_is_list_;
inicio_ar:;
	if (!has_itens_is_list_)
	{
		has_itens_copy_is_list_ = 0;
		return 0;
	}
	my_ptr2_ar = my_ptr_ar;
	my_ptr_ar = my_ptr_ar->next_ar;

	if (1 == has_itens_is_list_)
	{
		;
		free(my_ptr2_ar->next_ar);
	}
	free(my_ptr2_ar->filename_k);
	free(my_ptr2_ar->typeflag_ar_);
	free(my_ptr2_ar);

	has_itens_is_list_--;

	goto inicio_ar;
	return 1;
}

#pragma pack(push, 1)

struct my_struct_for_list_ar_is_extract_ //for list only
{
	char *extracting_filename_ar_;
	char *creating_folder_maria_;
	char *warning_info_;
	int has_next;
	struct my_struct_for_list_ar_is_extract_ *next_ar;
};

#pragma pack(pop)

struct my_struct_for_list_ar_is_extract_ *aak_is_extract_;
struct my_struct_for_list_ar_is_extract_ *aak_inicio_is_extract_;
struct my_struct_for_list_ar_is_extract_ *aak_pointer_is_extract_;

int has_itens_is_extract_ = 0;

int has_itens_copy_is_extract_ = 0;
/**
 * To add one item to the linked list
 *
 * @param extracting_filename_ar__ the filename as utf-8 being extracted
 *
 */
void add_more_one_is_extract_(
	char *extracting_filename_ar__,
	char *warning_info_ar_,
	char *creating_folder_maria__)
{
	struct my_struct_for_list_ar_is_extract_ *aak_ptr;

	if (!has_itens_is_extract_)
	{
		aak_is_extract_ = calloc(1, sizeof(struct my_struct_for_list_ar_is_extract_));
		aak_inicio_is_extract_ = aak_is_extract_;
		aak_pointer_is_extract_ = aak_is_extract_;
		aak_is_extract_->extracting_filename_ar_ = malloc(strlen(extracting_filename_ar__) + 1);
		aak_is_extract_->warning_info_ = malloc(strlen(warning_info_ar_) + 1);
		aak_is_extract_->creating_folder_maria_ = malloc(strlen(creating_folder_maria__) + 1);
		strcpy(aak_is_extract_->extracting_filename_ar_, extracting_filename_ar__);
		strcpy(aak_is_extract_->warning_info_, warning_info_ar_);
		strcpy(aak_is_extract_->creating_folder_maria_, creating_folder_maria__);
		aak_is_extract_->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_extract_));
		has_itens_is_extract_ = 1;
		has_itens_copy_is_extract_ = has_itens_is_extract_;
		aak_is_extract_ = aak_is_extract_->next_ar;
	}
	else
	{
		aak_ptr = aak_is_extract_;
		assert(aak_ptr);
		assert(8 < sizeof(struct my_struct_for_list_ar_is_extract_));
		aak_ptr->next_ar = calloc(1, sizeof(struct my_struct_for_list_ar_is_extract_));
		aak_ptr->extracting_filename_ar_ = malloc(strlen(extracting_filename_ar__) + 1);
		aak_ptr->warning_info_ = malloc(strlen(warning_info_ar_) + 1);
		aak_ptr->creating_folder_maria_ = malloc(strlen(creating_folder_maria__) + 1);
		strcpy(aak_ptr->extracting_filename_ar_, extracting_filename_ar__);
		strcpy(aak_ptr->warning_info_, warning_info_ar_);
		strcpy(aak_ptr->creating_folder_maria_, creating_folder_maria__);
		aak_is_extract_ = aak_ptr->next_ar;
		has_itens_is_extract_++;
		has_itens_copy_is_extract_ = has_itens_is_extract_;
	}
}
/**
 * To get the progress value for the ListView being populated
 *
 * @return the progress value, 100% == 10000
 *
 */
int __stdcall get_listview_progress_arp(void)
{
	int ret_arp = 0;

	if (mode_is_list_arp)
	{
		ret_arp = (10000 - (getpor_10000_int64_t_ar(has_itens_is_list_, has_itens_copy_is_list_)));
	}
	else
	{
		ret_arp = (10000 - (getpor_10000_int64_t_ar(has_itens_is_extract_, has_itens_copy_is_extract_)));
	}

	if (0 > ret_arp)
		ret_arp = 0;

	if (10000 < ret_arp)
		ret_arp = 10000;

	return ret_arp;
}

int clean_list__ar_is_extract_(void);
/**
 * To remove one item from the linked list
 *
 * @return 1 if it has more items, 0 otherwise
 *
 */
int get_list_itens_is_extract_()
{
	if (!has_itens_copy_is_extract_)
	{
		clean_list__ar_is_extract_();
		return 0;
	}

	aak_pointer_is_extract_ = aak_pointer_is_extract_->next_ar;
	has_itens_copy_is_extract_--;
	assert(has_itens_copy_is_extract_ >= 0);
	return 1;
}
/**
 * To get one item from the linked list
 *
 * @param extracting_filename_ar__ the filename as utf-8
 *
 * @return 1 if it has more items, 0 otherwise
 *
 */
int __stdcall get_last_process_information_ar_is_extract_(char *extracting_filename_ar__, char *creating_folder_maria__, char *warning_info__, int *Folders_ar, int *Files_ar)
{
	*Folders_ar = folders_ar;
	*Files_ar = files_ar;
	mode_is_list_arp = false;
	extracting_filename_ar__[0] = 0;
	warning_info__[0] = 0;
	if (!has_itens_copy_is_extract_)
	{
		clean_list__ar_is_extract_();
		return 0;
	}
	strncpy_z(extracting_filename_ar__, aak_pointer_is_extract_->extracting_filename_ar_, 1026);
	strncpy_z(warning_info__, aak_pointer_is_extract_->warning_info_, 1026);
	strncpy_z(creating_folder_maria__, aak_pointer_is_extract_->creating_folder_maria_, 1026);
	aak_pointer_is_extract_ = aak_pointer_is_extract_->next_ar;
	has_itens_copy_is_extract_--;
	assert(has_itens_copy_is_extract_ >= 0);
	return 1;
}
/**
 * To cleanup the linked list
 *
 * @return 1 if it has more items, 0 otherwise
 *
 */
int clean_list__ar_is_extract_(void)
{
	struct my_struct_for_list_ar_is_extract_ *my_ptr_ar;
	struct my_struct_for_list_ar_is_extract_ *my_ptr2_ar;
	my_ptr2_ar = aak_inicio_is_extract_;
	my_ptr_ar = aak_inicio_is_extract_;
inicio_ar:;
	if (!has_itens_is_extract_)
	{
		has_itens_copy_is_extract_ = 0;
		return 0;
	}
	my_ptr2_ar = my_ptr_ar;
	my_ptr_ar = my_ptr_ar->next_ar;
	if (1 == has_itens_is_extract_)
	{
		free(my_ptr2_ar->next_ar);
	}
	free(my_ptr2_ar->extracting_filename_ar_);
	free(my_ptr2_ar->warning_info_);
	free(my_ptr2_ar->creating_folder_maria_);
	free(my_ptr2_ar);
	has_itens_is_extract_--;
	goto inicio_ar;
	return 1;
}
/**
 * Function to control the extraction flags and calls to the required functions
 *
 * @param clear_flag_k the flag to be used
 *
 * @return always 0
 *
 */
int __stdcall extract_function_ar_ok(int clear_flag_k)
{
	switch (clear_flag_k)
	{
	case AAKP_CLEAR:
		while (get_list_itens_is_extract_())
		{
			;
		}
		break;
	case AAKP_EXTRACT_PROCESS:
	{
		add_more_one_is_extract_(
			extracting_filename_ar,
			warning_info,
			creating_folder_maria);
		//exit(27);
	}
	break;
	}
	return 0;
}
/**
 * Function to control the list process
 *
 * @param clear_flag_k the flag to be used
 *
 * @return always 0
 *
 */
int __stdcall list_function_ar_ok(int clear_flag_k)
{
	switch (clear_flag_k)
	{
	case AAKP_CLEAR:
		while (clean_list_itens_is_list_())
		{
			;
		}
		break;
	case AAKP_LIST_PROCESS:
	{
		int Isdir_k_ar;
		int Second_k_ar;
		int Minute_k_ar;
		int Hour_k_ar;
		int Year_k_ar;
		int Month_k_ar;
		int Day_k_ar;
		__int64 Size_k_ar;
		static char filename_k_ar[AMANDA__SIZE];
		int Numdir_k_ar;
		int Numfiles_k_ar;
		static char typeflag_ar_[1024];
		get_tar_info_ar(
			&Isdir_k_ar,
			&Second_k_ar,
			&Minute_k_ar,
			&Hour_k_ar,
			&Year_k_ar,
			&Month_k_ar,
			&Day_k_ar,
			&Size_k_ar,
			filename_k_ar,
			&Numdir_k_ar,
			&Numfiles_k_ar,
			typeflag_ar_);
		numero_de_itens = Numdir_k_ar + Numfiles_k_ar;
		folders_ar = Numdir_k_ar;
		files_ar = Numfiles_k_ar;
		add_more_one_is_list_(
			Isdir_k_ar,
			Second_k_ar,
			Minute_k_ar,
			Hour_k_ar,
			Year_k_ar,
			Month_k_ar,
			Day_k_ar,
			Size_k_ar,
			filename_k_ar,
			Numdir_k_ar,
			Numfiles_k_ar,
			typeflag_ar_);
	}
	break;
	}
	return 0;
}

int __stdcall process_tar(int true_if_it_is_extract_ar, char *tar_file_ar, tar_list_function_ar my_func__);

tar_list_function_ar my_func_ar_ = NULL;

__int64 Size_k;
char filename_k[AMANDA__SIZE];
char typeflag_ar[300];
int Day_k;
int Hour_k;
int Isdir_k;
int Minute_k;
int Month_k;
int Numdir_k;
int Numfiles_k;
int Second_k;
int Year_k;

/**
 * Function to retrieve the Tar file informations
 *
 * @param filename_k_ar the name of the file inside the Tar file, utf-8 encoded
 *
 */
void __stdcall get_tar_info_ar(
	int *Isdir_k_ar,
	int *Second_k_ar,
	int *Minute_k_ar,
	int *Hour_k_ar,
	int *Year_k_ar,
	int *Month_k_ar,
	int *Day_k_ar,
	__int64 *Size_k_ar,
	char *filename_k_ar,
	int *Numdir_k_ar,
	int *Numfiles_k_ar,
	char *typeflag_ar_)
{
	*Isdir_k_ar = Isdir_k;
	*Second_k_ar = Second_k;
	*Minute_k_ar = Minute_k;
	*Hour_k_ar = Hour_k;
	*Year_k_ar = Year_k;
	*Month_k_ar = Month_k;
	*Day_k_ar = Day_k;
	*Size_k_ar = Size_k;
	strcpy(filename_k_ar, filename_k);
	*Numdir_k_ar = Numdir_k;
	*Numfiles_k_ar = Numfiles_k;
	strcpy(typeflag_ar_, typeflag_ar);
	return;
}

#ifndef AMANDA_MAIN___

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////2021 z
//defines

#define FALLTHROUGH __attribute__((__fallthrough__))

#define DEFAULT_BLOCKING 20

#include "tar.h"

char *volume_label = NULL;
char *continued_file_name = NULL;
uintmax_t continued_file_size;
uintmax_t continued_file_offset;

/**
 * Function to allocate memory
 *
 * @param p the address to duplicate the data
 *
 * @param s the size
 *
 * @return the memory address allocated and copied
 *
 */
void *
xmemdup(void const *p, size_t s)
{
	return memcpy(malloc(s), p, s);
}

/**
 * Function to duplicate a string
 *
 * @param string the input string
 *
 * @return the duplicated new address
 *
 */
char *
xstrdup(char const *string)
{
	return xmemdup(string, strlen(string) + 1);
}

#define XHDR_PROTECTED 0x01
#define XHDR_GLOBAL 0x02

/**
 * Tar related function, version 1.34
 *
 */
struct xhdr_tab
{
	char const *keyword;
	void (*coder)(struct tar_stat_info const *, char const *,
				  struct xheader *, void const *data);
	void (*decoder)(struct tar_stat_info *, char const *, char const *, size_t);
	int flags;
	bool prefix; /* select handler comparing prefix only */
};

enum read_header
{
	HEADER_STILL_UNREAD,	 /* for when read_header has not been called */
	HEADER_SUCCESS,			 /* header successfully read and checksummed */
	HEADER_SUCCESS_EXTENDED, /* likewise, but we got an extended header */
	HEADER_ZERO_BLOCK,		 /* zero block where header expected */
	HEADER_END_OF_FILE,		 /* true end of file while header expected */
	HEADER_FAILURE			 /* ill-formed header, or bad checksum */
};

enum read_header tar_checksum(union block *header, bool silent);

enum compressed_formats
{
	ct_compress_k = 1001,
	ct_gzip_k,
	ct_bzip2_k,
	ct_lzip_k,
	ct_lzma_k,
	ct_lzop_k,
	ct_xz_k,
	ct_lz4_k,
	ct_zstd_k,
	ct_brotli_k,
	ct_val_k,
	ct_gzip2a_k,
	ct_gzip2c_k,
	ct_bzip3_k,
	ct_lzop2_k,
	ct_lz5_k,
	ct_brotli2_k,
	ct_compress2_k
};

enum dump_status
{
	dump_status_ok,
	dump_status_short,
	dump_status_fail,
	dump_status_not_implemented
};

#define NAME_FIELD_SIZE 100

struct keyword_list
{
	struct keyword_list *next;
	char *pattern;
	char *value;
};

/* List of keyword/value pairs decoded from the last 'g' type header */
static struct keyword_list *global_header_override_list = {
	0,
};

/* Operation mode for read_header: */
enum read_header_mode
{
	read_header_auto,	 /* process extended headers automatically */
	read_header_x_raw,	 /* return raw extended headers (return
	                       HEADER_SUCCESS_EXTENDED) */
	read_header_x_global /* when POSIX global extended header is read,
	                        decode it and return
	                        HEADER_SUCCESS_EXTENDED */
};

enum compress_type
{
	ct_none, /* Unknown compression type */
	ct_tar,	 /* Plain tar file */
	ct_compress,
	ct_gzip,
	ct_bzip2,
	ct_lzip,
	ct_lzma,
	ct_lzop,
	ct_xz,
	ct_lz4,
	ct_zstd,
	ct_val,
	ct_gzip2a,
	ct_gzip2c,
	ct_bzip3,
	ct_lzop2,
	ct_lz5,
	ct_brotli2,
	ct_compress2,
};

struct bufmap
{
	struct bufmap *next; /* Pointer to the next map entry */
	size_t start;		 /* Offset of the first data block */
	char *file_name;	 /* Name of the stored file */
	off_t sizetotal;	 /* Size of the stored file */
	off_t sizeleft;		 /* Size left to read/write */
	size_t nblocks;		 /* Number of blocks written since reset */
};
static struct bufmap *bufmap_head, *bufmap_tail;
static void (*flush_write_ptr)(size_t);
enum archive_format current_format; /* recognized format */
enum archive_format archive_format;
struct zip_magic
{
	enum compress_type type;
	size_t length;
	char const *magic;
};

static intmax_t from_header(const char *, size_t, const char *,
							intmax_t, uintmax_t, bool, bool);

/* Base 64 digits; see Internet RFC 2045 Table 1.  */
static char const base_64_digits[64] =
	{
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//the destination folder
char extract_folder_final[AMANDA__SIZE] = {
	0,
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Table of base-64 digit values indexed by unsigned chars.
   The value is 64 for unsigned chars that are not base-64 digits.  */
static char base64_map[UCHAR_MAX + 1];

static void (*flush_read_ptr)(void);

union block *recent_long_link; /* likewise, for long link */

union block *recent_long_name; /* recent long name header and contents */

size_t recent_long_name_blocks; /* number of blocks in recent_long_name */

union block *current_header; /* points to current archive header */

size_t recent_long_link_blocks; /* likewise, for long link */

static union block *recent_global_header = NULL; /* Recent global header block */

static int read_error_count;

static off_t record_start_block; /* block ordinal at record_start */

static bool hit_eof;

static bool read_full_records = false;

char archive_name_array_filename[AMANDA__SIZE];

int fatal_exit_k = 0;

static int record_index;

static union block *record_buffer_aligned[2];

static void *record_buffer[2]; /* allocated memory */

bool time_to_start_writing = false;

off_t records_read;	   /* number of records read from this archive */
off_t records_written; /* likewise, for records written */

off_t off_from_header(const char *p, size_t s);

#define TYPE_SIGNED(t) (!((t)0 < (t)-1))
#define TYPE_WIDTH(t) (sizeof(t) * CHAR_BIT)

/* The maximum and minimum values for the integer type T.  */
#define TYPE_MINIMUM(t) ((t)~TYPE_MAXIMUM(t))
#define TYPE_MAXIMUM(t)  \
	((t)(!TYPE_SIGNED(t) \
			 ? (t)-1     \
			 : ((((t)1 << (TYPE_WIDTH(t) - 2)) - 1) * 2 + 1)))

#define OFF_FROM_HEADER(where) off_from_header(where, sizeof(where))

/* Module warning.c */
#define WARN_ALONE_ZERO_BLOCK 0x00000001
#define WARN_BAD_DUMPDIR 0x00000002
#define WARN_CACHEDIR 0x00000004
#define WARN_CONTIGUOUS_CAST 0x00000008
#define WARN_FILE_CHANGED 0x00000010
#define WARN_FILE_IGNORED 0x00000020
#define WARN_FILE_REMOVED 0x00000040
#define WARN_FILE_SHRANK 0x00000080
#define WARN_FILE_UNCHANGED 0x00000100
#define WARN_FILENAME_WITH_NULS 0x00000200
#define WARN_IGNORE_ARCHIVE 0x00000400
#define WARN_IGNORE_NEWER 0x00000800
#define WARN_NEW_DIRECTORY 0x00001000
#define WARN_RENAME_DIRECTORY 0x00002000
#define WARN_SYMLINK_CAST 0x00004000
#define WARN_TIMESTAMP 0x00008000
#define WARN_UNKNOWN_CAST 0x00010000
#define WARN_UNKNOWN_KEYWORD 0x00020000
#define WARN_XDEV 0x00040000
#define WARN_DECOMPRESS_PROGRAM 0x00080000
#define WARN_EXISTING_FILE 0x00100000
#define WARN_XATTR_WRITE 0x00200000
#define WARN_RECORD_SIZE 0x00400000
#define WARN_FAILED_READ 0x00800000

/* These warnings are enabled by default in verbose mode: */
#define WARN_VERBOSE_WARNINGS (WARN_RENAME_DIRECTORY | WARN_NEW_DIRECTORY |   \
							   WARN_DECOMPRESS_PROGRAM | WARN_EXISTING_FILE | \
							   WARN_RECORD_SIZE)
#define WARN_ALL (~WARN_VERBOSE_WARNINGS)

int warning_option = WARN_ALL;

#define WARNING_ENABLED(opt) (warning_option & (opt))

#define WARNOPT(opt, args)        \
	do                            \
	{                             \
		if (WARNING_ENABLED(opt)) \
			WARN(args);           \
	} while (0)

#define GLOBAL
GLOBAL bool read_full_records_option;
GLOBAL size_t record_size;
GLOBAL int blocking_factor;
GLOBAL int archive;
GLOBAL size_t archive_names;
GLOBAL bool seekable_archive;
GLOBAL bool ignore_failed_read_option;
GLOBAL struct tar_stat_info current_stat_info = {
	0,
};
GLOBAL bool incremental_option;
GLOBAL struct timespec start_time; /* when we started execution */
GLOBAL bool numeric_owner_option;
union block *record_start;	/* start of record of archive */
union block *record_end;	/* last+1 block of archive record */
union block *current_block; /* current block of archive */

typedef void (*do_something_k)(void);

do_something_k my_process_function = NULL;

enum access_mode
{
	ACCESS_READ,
	ACCESS_WRITE,
	ACCESS_UPDATE
};

enum access_mode access_mode; /* how do we handle the archive */

static void
_gnu_flush_read(void);

static void
simple_flush_read(void);

off_t seek_archive(off_t size);

static void
short_read(size_t status);

void archive_read_error(void);

off_t current_block_ordinal(void);

int getpagesize(void);

static void
init_buffer(void);

void flush_archive(void);

union block *
find_next_block(void);

static enum compress_type
check_compressed_archive(bool *pshort);

void open_archive(enum access_mode wanted_access);

static void
guess_seekable_archive(void);

static int
open_compressed_archive(void);

static void
_open_archive(enum access_mode wanted_access);

static void
gnu_flush_read(void);

void flush_read(void);

void flush_archive(void);

static void
base64_init(void);

void tar_stat_destroy(struct tar_stat_info *st);

bool tar_stat_close(struct tar_stat_info *st);

void close_diag(char const *name);

void close_diag(char const *name);

void open_diag(char const *name);

void open_warn(char const *name);

void open_error(char const *name);

void close_warn(char const *name);

void close_error(char const *name);

void xheader_xattr_free(struct xattr_array *xattr_map, size_t xattr_map_size);

enum read_header read_header(union block **return_block,
							 struct tar_stat_info *info,
							 enum read_header_mode m);

void set_next_block_after(union block *block);

size_t
available_space_after(union block *pointer);

void xheader_read(struct xheader *xhdr, union block *p, off_t size);

void xheader_decode_global(struct xheader *xhdr);

static void
xheader_list_destroy(struct keyword_list **root);

static void
gnu_flush_write(size_t buffer_level);

void xheader_destroy(struct xheader *xhdr);

void assign_string(char **string, const char *value);

char *
last_component(char const *name);

size_t
base_len_unix(char const *name);

char *
last_component_unix(char const *name);

size_t
base_len_unix(char const *name);

bool strip_trailing_slashes_unix(char *file);

void decode_header(union block *header, struct tar_stat_info *stat_info,
				   enum archive_format *format_pointer, int do_user_group);

static mode_t
mode_from_header(const char *p, size_t s, bool *hbits);

static time_t
time_from_header(const char *p, size_t s);

void assign_string_n(char **string, const char *value, size_t n);

void xheader_xattr_init(struct tar_stat_info *st);

static short
uid_from_header(const char *p, size_t s);

static short
gid_from_header(const char *p, size_t s);

int uname_to_uid(char const *uname, short *uidp);

int gname_to_gid(char const *gname, short *gidp);

void xheader_decode(struct tar_stat_info *st);

bool sparse_member_p(struct tar_stat_info *st);

bool sparse_fixup_header(struct tar_stat_info *st);

void skip_member(void);

void mv_begin_read(struct tar_stat_info *st);

void mv_begin_write(const char *file_name, off_t totsize, off_t sizeleft);

enum dump_status
sparse_skip_file(struct tar_stat_info *st);

void mv_size_left(off_t size);

void mv_end(void);

void list_archive(void);

void print_header(struct tar_stat_info *st, union block *blk,
				  off_t block_ordinal);

static ssize_t
_flush_write(void);

static void
simple_flush_write(size_t level __attribute__((unused)));

bool all_names_found(struct tar_stat_info *p);

static void
bufmap_free(struct bufmap *mark);

size_t
sys_write_archive_buffer(void);

static void
_gnu_flush_write(size_t buffer_level);

void xheader_xattr_init(struct tar_stat_info *st);

#include "compression_support_ar.c"

#include "sparse_2_k.c"

#include "xheader_k.c"

#include "extract_kkk.c" /* ask me why...*/

#include "create_zen_ar.c"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////AR 2021
//functions...

/**
 * Tar related function, version 1.34
 *
 */
void xheader_xattr_init(struct tar_stat_info *st)
{
	st->xattr_map = NULL;
	st->xattr_map_size = 0;
	st->acls_a_ptr = NULL;
	st->acls_a_len = 0;
	st->acls_d_ptr = NULL;
	st->acls_d_len = 0;
	st->cntx_name = NULL;
}

/**
 * Tar related function, version 1.34
 *
 */
static major_t
major_from_header(const char *p, size_t s)
{
	return from_header(p, s, "major_t",
					   TYPE_MINIMUM(major_t), TYPE_MAXIMUM(major_t),
					   false, false);
}

/**
 * Tar related function, version 1.34
 *
 */
static minor_t
minor_from_header(const char *p, size_t s)
{
	return from_header(p, s, "minor_t",
					   TYPE_MINIMUM(minor_t), TYPE_MAXIMUM(minor_t),
					   false, false);
}

/**
 * Tar related function, version 1.34
 *
 */
void xheader_destroy(struct xheader *xhdr)
{
	if (xhdr->stk)
	{
		obstack_free(xhdr->stk, NULL);
		free(xhdr->stk);
		xhdr->stk = NULL;
	}
	else
		free(xhdr->buffer);
	xhdr->buffer = 0;
	xhdr->size = 0;
}

/**
 * Tar related function, version 1.34
 *
 */
void xheader_xattr_free(struct xattr_array *xattr_map, size_t xattr_map_size)
{
	size_t scan = 0;

	while (scan < xattr_map_size)
	{
		free(xattr_map[scan].xkey);
		free(xattr_map[scan].xval_ptr);

		++scan;
	}
	free(xattr_map);
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xheader_list_destroy(struct keyword_list **root)
{
	if (root)
	{
		struct keyword_list *kw = *root;
		while (kw)
		{
			struct keyword_list *next = kw->next;
			free(kw->pattern);
			free(kw->value);
			free(kw);
			kw = next;
		}
		*root = NULL;
	}
}

static void
xheader_list_append(struct keyword_list **root, char const *kw,
					char const *value);

/**
 * Tar related function, version 1.34, this is the function that will dump the data to disk
 *
 */
static void
_gnu_flush_write(__attribute__((unused)) size_t buffer_level)
{
	ssize_t status;

	status = _flush_write();
	if ((int64_t)status != (int64_t)record_size)
	{
	}
	else
	{
		if (status)
			records_written++;
	}

	if ((int64_t)status == (int64_t)record_size)
	{
		return;
	}
}

/**
 * Tar related function, version 1.34
 *
 */
size_t
sys_write_archive_buffer(void)
{
	return write(archive, record_start->buffer, record_size);
}

/**
 * Tar related function, version 1.34, slightly modified...
 *
 */
static ssize_t
_flush_write(void)
{
	ssize_t status;
	status = sys_write_archive_buffer();
	return status;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
simple_flush_write(size_t level __attribute__((unused)))
{
	ssize_t status;
	status = _flush_write();
	if ((int64_t)status != (int64_t)record_size)
	{
	}
	else
	{
		records_written++;
	}
}

/**
 * Tar related function, version 1.34
 *
 */
static void
gnu_flush_write(size_t buffer_level)
{
	flush_write_ptr = simple_flush_write; /* Avoid recursion */ //too complex for me...
	_gnu_flush_write(buffer_level);
	flush_write_ptr = gnu_flush_write;
}

/**
 * It will convert a time_t unix time to FILETIME
 *
 */
void TimetToFileTime(time_t t, LPFILETIME pft)
{
	LONGLONG ll = Int32x32To64(t, 10000000) + 116444736000000000;
	pft->dwLowDateTime = (DWORD)ll;
	pft->dwHighDateTime = ll >> 32;
}

/**
 * Function to retrieve the file timestamp information, it is required because
 * _stat and _wstat are buggy
 *
 */
BOOL GetLastWriteTime_complete_arp(HANDLE hFile,
								   char *lpszString_amanda,
								   __attribute__((unused)) DWORD dwSize,
								   __time64_t *s_arp,
								   VAL_data *VAL_data_arp)
{
	struct tm tm;
	FILETIME ftCreate, ftAccess, ftWrite;
	SYSTEMTIME stUTC, stLocal;

	// Retrieve the file times for the file.
	if (!GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
	{
		*s_arp = time(NULL);

		atime_i = *s_arp;
		ctime_i = *s_arp;
		mtime_i = *s_arp;

		return FALSE;
	}

	VAL_data_arp->CreationTime___junior = ftCreate;
	VAL_data_arp->LastAccessTime_junior = ftAccess;
	VAL_data_arp->LastWriteTime__junior = ftWrite;

	{
		// Convert the last-write time to local time.
		FileTimeToSystemTime(&ftWrite, &stUTC);
		SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

		if (lpszString_amanda)
			// Build a string showing the date and time.
			sprintf(lpszString_amanda,
					TEXT("%02d/%02d/%d  %02d:%02d:%02d"),
					stLocal.wMonth, stLocal.wDay, stLocal.wYear,
					stLocal.wHour, stLocal.wMinute, stLocal.wSecond);

		memset(&tm, 0, sizeof(tm));

		tm.tm_year = stLocal.wYear - 1900; // EDIT 2 : 1900's Offset as per comment
		tm.tm_mon = stLocal.wMonth - 1;
		tm.tm_mday = stLocal.wDay;

		tm.tm_hour = stLocal.wHour;
		tm.tm_min = stLocal.wMinute;
		tm.tm_sec = stLocal.wSecond;
		tm.tm_isdst = -1; // Edit 2: Added as per comment

		*s_arp = _mktime64(&tm);
		mtime_i = *s_arp;
	}

	{
		// Convert the last-write time to local time.
		FileTimeToSystemTime(&ftCreate, &stUTC);
		SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

		if (lpszString_amanda)
			// Build a string showing the date and time.
			sprintf(lpszString_amanda,
					TEXT("%02d/%02d/%d  %02d:%02d:%02d"),
					stLocal.wMonth, stLocal.wDay, stLocal.wYear,
					stLocal.wHour, stLocal.wMinute, stLocal.wSecond);

		memset(&tm, 0, sizeof(tm));

		tm.tm_year = stLocal.wYear - 1900; // EDIT 2 : 1900's Offset as per comment
		tm.tm_mon = stLocal.wMonth - 1;
		tm.tm_mday = stLocal.wDay;

		tm.tm_hour = stLocal.wHour;
		tm.tm_min = stLocal.wMinute;
		tm.tm_sec = stLocal.wSecond;
		tm.tm_isdst = -1; // Edit 2: Added as per comment

		ctime_i = _mktime64(&tm);
	}

	{
		// Convert the last-write time to local time.
		FileTimeToSystemTime(&ftAccess, &stUTC);
		SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);

		if (lpszString_amanda)
			// Build a string showing the date and time.
			sprintf(lpszString_amanda,
					TEXT("%02d/%02d/%d  %02d:%02d:%02d"),
					stLocal.wMonth, stLocal.wDay, stLocal.wYear,
					stLocal.wHour, stLocal.wMinute, stLocal.wSecond);

		memset(&tm, 0, sizeof(tm));

		tm.tm_year = stLocal.wYear - 1900; // EDIT 2 : 1900's Offset as per comment
		tm.tm_mon = stLocal.wMonth - 1;
		tm.tm_mday = stLocal.wDay;

		tm.tm_hour = stLocal.wHour;
		tm.tm_min = stLocal.wMinute;
		tm.tm_sec = stLocal.wSecond;
		tm.tm_isdst = -1; // Edit 2: Added as per comment

		atime_i = _mktime64(&tm);
	}

	return 1;
}

/**
 * Function to retrieve the file timestamp, fixed version, _stat and _wstat cannot be used due to internal bug,
 *  full support to wide paths Ricardo...
 * 
 */
void get_timestamp_arp(char *file_arp, __time64_t *s_arp, VAL_data *VAL_data_arp)
{
	HANDLE hFile;
	char szBuf[MAX_PATH];

	hFile = CreateFileW(permissive_name_m_(amanda_utf8towide_1_(file_arp)),
						/*
	                       GENERIC_READ,
	                       FILE_SHARE_READ, NULL,
	                       OPEN_EXISTING,
	                       0,
	                       NULL);
	                     */
						GENERIC_READ,
						FILE_SHARE_READ, NULL,
						OPEN_EXISTING,
						FILE_FLAG_BACKUP_SEMANTICS,
						NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		*s_arp = time(NULL);
	}
	else
	{
		GetLastWriteTime_complete_arp(hFile, szBuf, MAX_PATH, s_arp, VAL_data_arp);

		CloseHandle(hFile);
	}
	return;
}

/**
 * To convert timestamp for file, as far I know not in use these days, it was only for debug purposes
 *
 */
void printf_time(time_t s_arp, __attribute__((unused)) char *file_arp)
{
	FILETIME ftime_in = {0};
	SYSTEMTIME systime_arp = {0};
	SYSTEMTIME systime_arp2 = {0};

	TimetToFileTime(s_arp, &ftime_in);
	FileTimeToSystemTime(
		&ftime_in,
		&systime_arp2);
	SystemTimeToTzSpecificLocalTime(NULL, &systime_arp2, &systime_arp);
	Second_k = systime_arp.wSecond;
	Minute_k = systime_arp.wMinute;
	Hour_k = systime_arp.wHour;
	Year_k = systime_arp.wYear;
	Month_k = systime_arp.wMonth;
	Day_k = systime_arp.wDay;
}

/**
 * Tar related function, version 1.34, it will convert variable t to the time representation
 *
 */
char const *
tartime(struct timespec t, __attribute__((unused)) bool full_time)
{
	enum
	{
		fraclen = sizeof ".FFFFFFFFF" - 1
	};
	static char buffer[5000];
	struct tm *tm;
	time_t s = t.tv_sec;

	tm = 0 ? gmtime(&s) : localtime(&s);
	tm = 0 ? gmtime(&s) : localtime(&s); //it is weird but you need two subsequent calls to make it work
	if (!tm)
	{
		s = time(NULL);
		tm = 0 ? gmtime(&s) : localtime(&s);
	}
	Second_k = tm->tm_sec;
	Minute_k = tm->tm_min;
	Hour_k = tm->tm_hour;
	Year_k = tm->tm_year + 1900;
	Month_k = tm->tm_mon + 1;
	Day_k = tm->tm_mday;
	return buffer;
}

/**
 * Tar related function, version 1.34
 *
 */
void bufmap_free(struct bufmap *mark)
{
	struct bufmap *map;

	for (map = bufmap_head; map && map != mark;)
	{
		struct bufmap *next = map->next;
		free(map->file_name);
		free(map);
		map = next;
	}
	bufmap_head = map;
	if (!bufmap_head)
		bufmap_tail = bufmap_head;
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void close_archive(void)
{
	if (!mode_is_VAL_arp)
	{
		if (access_mode == ACCESS_WRITE)
		{
			do
				flush_archive();
			while (current_block > record_start);
		}
		close(archive);
		archive = -1;
		tar_stat_destroy(&current_stat_info);
		bufmap_free(NULL);
	}
	else
	{
		if (-1 != archive)
		{
			close(archive);
		}
		archive = -1;
		tar_stat_destroy(&current_stat_info);
	}
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
bool all_names_found(struct tar_stat_info *p)
{
	if (!p->file_name)
	{
		;
		return false;
	}
	return true;
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void simple_print_header(struct tar_stat_info *st, union block *blk,
						 __attribute__((unused)) off_t block_ordinal)
{
	char *temp_name;

	if (0)
		temp_name = st->file_name ? st->file_name : st->orig_file_name;
	else
		temp_name = st->orig_file_name ? st->orig_file_name : st->file_name;

	;
	if (1)
	{
		/* Just the fax, mam.  */
		tartime(st->mtime, true);
		strcpy(typeflag_ar, "unknown");

		Isdir_k = 0;

		switch (blk->header.typeflag)
		{
		case GNUTYPE_VOLHDR:
			strcpy(typeflag_ar, "GNUTYPE_VOLHDR");
			break;

		case GNUTYPE_MULTIVOL:
			strcpy(typeflag_ar, "GNUTYPE_MULTIVOL");
			break;

		case GNUTYPE_LONGNAME:
			strcpy(typeflag_ar, "GNUTYPE_LONGNAME");
			break;

		case GNUTYPE_LONGLINK:
			strcpy(typeflag_ar, "GNUTYPE_LONGLINK");
			break;

		case GNUTYPE_SPARSE:
			strcpy(typeflag_ar, "GNUTYPE_SPARSE");

			Isdir_k = 0;
			if (st->had_trailing_slash)
			{
				Isdir_k = 1;
				Numdir_k++;
			}
			else
			{
				if (is_mislaine_encrypted_)
				{
					if (1 == already_arp)
					{
						already_arp++;
						if (ARP_AES == encryption_method_arp)
						{
							strcat(string_format_arp, " + AES");
						}
						else if (ARP_RC4 == encryption_method_arp)
						{
							strcat(string_format_arp, " + RC4");
						}
						else if (ARP_SERPENT == encryption_method_arp)
						{
							strcat(string_format_arp, " + SERPENT");
						}
						else if (ARP_MARS == encryption_method_arp)
						{
							strcat(string_format_arp, " + MARS");
						}
						else if (ARP_RC6 == encryption_method_arp)
						{
							strcat(string_format_arp, " + RC6");
						}
						else if (ARP_TWOFISH == encryption_method_arp)
						{
							strcat(string_format_arp, " + TWOFISH");
						}
					}

					if (ARP_AES == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted AES)");
					}
					else if (ARP_RC4 == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted RC4)");
					}
					else if (ARP_SERPENT == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted SERPENT)");
					}
					else if (ARP_MARS == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted MARS)");
					}
					else if (ARP_RC6 == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted RC6)");
					}
					else if (ARP_TWOFISH == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted TWOFISH)");
					}
				}
				Numfiles_k++;
			}

			break;

		case REGTYPE:
			strcpy(typeflag_ar, "REGTYPE");

			Isdir_k = 0;
			if (st->had_trailing_slash)
			{
				Isdir_k = 1;
				Numdir_k++;
			}
			else
			{
				if (is_mislaine_encrypted_)
				{
					if (1 == already_arp)
					{
						already_arp++;
						if (ARP_AES == encryption_method_arp)
						{
							strcat(string_format_arp, " + AES");
						}
						else if (ARP_RC4 == encryption_method_arp)
						{
							strcat(string_format_arp, " + RC4");
						}
						else if (ARP_SERPENT == encryption_method_arp)
						{
							strcat(string_format_arp, " + SERPENT");
						}
						else if (ARP_MARS == encryption_method_arp)
						{
							strcat(string_format_arp, " + MARS");
						}
						else if (ARP_RC6 == encryption_method_arp)
						{
							strcat(string_format_arp, " + RC6");
						}
						else if (ARP_TWOFISH == encryption_method_arp)
						{
							strcat(string_format_arp, " + TWOFISH");
						}
					}

					if (ARP_AES == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted AES)");
					}
					else if (ARP_RC4 == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted RC4)");
					}
					else if (ARP_SERPENT == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted SERPENT)");
					}
					else if (ARP_MARS == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted MARS)");
					}
					else if (ARP_RC6 == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted RC6)");
					}
					else if (ARP_TWOFISH == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted TWOFISH)");
					}
				}
				Numfiles_k++;
			}
			break;

		case AREGTYPE:
			strcpy(typeflag_ar, "AREGTYPE");

			Isdir_k = 0;
			if (st->had_trailing_slash)
			{
				Isdir_k = 1;
				Numdir_k++;
			}
			else
			{
				if (is_mislaine_encrypted_)
				{
					if (1 == already_arp)
					{
						already_arp++;
						if (ARP_AES == encryption_method_arp)
						{
							strcat(string_format_arp, " + AES");
						}
						else if (ARP_RC4 == encryption_method_arp)
						{
							strcat(string_format_arp, " + RC4");
						}
						else if (ARP_SERPENT == encryption_method_arp)
						{
							strcat(string_format_arp, " + SERPENT");
						}
						else if (ARP_MARS == encryption_method_arp)
						{
							strcat(string_format_arp, " + MARS");
						}
						else if (ARP_RC6 == encryption_method_arp)
						{
							strcat(string_format_arp, " + RC6");
						}
						else if (ARP_TWOFISH == encryption_method_arp)
						{
							strcat(string_format_arp, " + TWOFISH");
						}
					}

					if (ARP_AES == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted AES)");
					}
					else if (ARP_RC4 == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted RC4)");
					}
					else if (ARP_SERPENT == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted SERPENT)");
					}
					else if (ARP_MARS == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted MARS)");
					}
					else if (ARP_RC6 == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted RC6)");
					}
					else if (ARP_TWOFISH == encryption_method_arp)
					{
						strcat(typeflag_ar, " (Encrypted TWOFISH)");
					}
				}
				Numfiles_k++;
			}
			break;

		case LNKTYPE:
			strcpy(typeflag_ar, "LNKTYPE");
			break;

		case GNUTYPE_DUMPDIR:
			strcpy(typeflag_ar, "GNUTYPE_DUMPDIR");
			break;

		case DIRTYPE:
			Numdir_k++;
			Isdir_k = 1;
			strcpy(typeflag_ar, "DIRTYPE");
			break;

		case SYMTYPE:
			strcpy(typeflag_ar, "SYMTYPE");
			break;

		case BLKTYPE:
			strcpy(typeflag_ar, "BLKTYPE");
			break;

		case CHRTYPE:
			strcpy(typeflag_ar, "CHRTYPE");
			break;

		case FIFOTYPE:
			strcpy(typeflag_ar, "FIFOTYPE");
			break;

		case CONTTYPE:
			strcpy(typeflag_ar, "CONTTYPE");
			break;
		}

		Size_k = current_stat_info.stat.st_size;

		if (is_mislaine_encrypted_)
		{
			if (-1 == encryption_detected_z)
			{
				Size_k -= 76;
				if (0 > Size_k)
				{
					Size_k = 0;
				}
			}
		};

		strncpy_z(filename_k, temp_name, 1026);
		;
		my_func_ar_(AAKP_LIST_PROCESS);
	}
}
/**
 * Function to convert the value that come from the VAL struct to the time information
 *
 *
 */
void tartime_VAL(void)
{
	struct tm *tm;
	__time64_t s; //= my_VAL_data_arp.VAL_timestamp;

	s = my_VAL_data_arp.VAL_timestamp64;
	if (0 == my_VAL_data_arp.VAL_timestamp64)
	{
		s = my_VAL_data_arp.VAL_timestamp;
	}

	tm = 0 ? _gmtime64(&s) : _localtime64(&s);
	tm = 0 ? _gmtime64(&s) : _localtime64(&s);

	if (!tm)
	{
		s = time(NULL);
		tm = 0 ? _gmtime64(&s) : _localtime64(&s);
	}

	Second_k = tm->tm_sec;
	Minute_k = tm->tm_min;
	Hour_k = tm->tm_hour;
	Year_k = tm->tm_year + 1900;
	Month_k = tm->tm_mon + 1;
	Day_k = tm->tm_mday;
	return;
}
/**
 * Function to print the VAL information that is in the VAL struct and send it to list process
 *
 */
void simple_print_header_VAL(void)
{
	tartime_VAL();

	if (-1 != encryption_detected_z)
	{
		my_VAL_data_arp.VAL_is_encrypted = true;
		my_VAL_data_arp.VAL_encryption_method = encryption_detected_z;
	}

	if (my_VAL_data_arp.VAL_is_dir)
	{
		Isdir_k = 1;
		strcpy(typeflag_ar, "DIRECTORY");
		Numdir_k++;
	}
	else
	{
		if (my_VAL_data_arp.VAL_is_encrypted)
		{
			if (ARP_AES == my_VAL_data_arp.VAL_encryption_method)
			{
				if (0 == already_arp)
				{
					already_arp++;
					strcat(string_format_arp, " + AES");
				}
				strcpy(typeflag_ar, "FILE (Encrypted AES)");
			}
			else if (ARP_RC4 == my_VAL_data_arp.VAL_encryption_method)
			{
				if (0 == already_arp)
				{
					already_arp++;
					strcat(string_format_arp, " + RC4");
				}
				strcpy(typeflag_ar, "FILE (Encrypted RC4)");
			}
			else if (ARP_SERPENT == my_VAL_data_arp.VAL_encryption_method)
			{
				if (0 == already_arp)
				{
					already_arp++;
					strcat(string_format_arp, " + SERPENT");
				}
				strcpy(typeflag_ar, "FILE (Encrypted SERPENT)");
			}
			else if (ARP_MARS == my_VAL_data_arp.VAL_encryption_method)
			{
				if (0 == already_arp)
				{
					already_arp++;
					strcat(string_format_arp, " + MARS");
				}
				strcpy(typeflag_ar, "FILE (Encrypted MARS)");
			}
			else if (ARP_RC6 == my_VAL_data_arp.VAL_encryption_method)
			{
				if (0 == already_arp)
				{
					already_arp++;
					strcat(string_format_arp, " + RC6");
				}
				strcpy(typeflag_ar, "FILE (Encrypted RC6)");
			}
			else if (ARP_TWOFISH == my_VAL_data_arp.VAL_encryption_method)
			{
				if (0 == already_arp)
				{
					already_arp++;
					strcat(string_format_arp, " + TWOFISH");
				}
				strcpy(typeflag_ar, "FILE (Encrypted TWOFISH)");
			}
		}
		else
			strcpy(typeflag_ar, "FILE");
		Isdir_k = 0;
		Numfiles_k++;
	}

	Size_k = my_VAL_data_arp.VAL_file_size;

	if (my_VAL_data_arp.VAL_is_encrypted)
	{
		if (-1 == encryption_detected_z)
		{
			Size_k -= 76;
			if (0 > Size_k)
			{
				Size_k = 0;
			}
		}
	}
	if (0 != my_VAL_data_arp.VAL_filename_v27_v51[0])
	{
		strcpy(filename_k, my_VAL_data_arp.VAL_filename_v27_v51);
	}
	else
		strcpy(filename_k, my_VAL_data_arp.VAL_filename);

	my_func_ar_(AAKP_LIST_PROCESS);
}
/**
 * Function to get the list information for the .iso handling routines
 *
 */
void tartime_iso(void)
{
	struct tm *tm;
	__time64_t s;

	s = my_VAL_data_arp.VAL_timestamp64;
	tm = 0 ? _gmtime64(&s) : _localtime64(&s);
	tm = 0 ? _gmtime64(&s) : _localtime64(&s);
	if (!tm)
	{
		s = time(NULL);
		tm = 0 ? _gmtime64(&s) : _localtime64(&s);
	}
	Second_k = tm->tm_sec;
	Minute_k = tm->tm_min;
	Hour_k = tm->tm_hour;
	Year_k = tm->tm_year + 1900;
	Month_k = tm->tm_mon + 1;
	Day_k = tm->tm_mday;
	return;
}
/**
 * Function to print the VAL information to the list process
 *
 */
void simple_print_header_iso(void)
{
	tartime_iso();
	if (my_VAL_data_arp.VAL_is_dir)
	{
		Isdir_k = 1;
		strcpy(typeflag_ar, "DIRECTORY");
		Numdir_k++;
	}
	else
	{
		if (my_VAL_data_arp.VAL_is_encrypted)
		{
			strcpy(typeflag_ar, "FILE (Encrypted)");
		}
		else
			strcpy(typeflag_ar, "FILE");
		Isdir_k = 0;
		Numfiles_k++;
	}
	Size_k = my_VAL_data_arp.VAL_file_size;
	strncpy_z(filename_k, my_VAL_data_arp.VAL_filename, 1023);
	my_func_ar_(AAKP_LIST_PROCESS);
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void print_header(struct tar_stat_info *st, union block *blk,
				  off_t block_ordinal)
{
	simple_print_header(st, blk, block_ordinal);
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void list_archive(void)
{
	off_t block_ordinal = current_block_ordinal();

	print_header(&current_stat_info, current_header, block_ordinal);
	skip_member();
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void mv_end(void)
{
}

/**
 * Tar related function, version 1.34
 *
 */
void mv_size_left(off_t size)
{
	if (bufmap_head)
		bufmap_head->sizeleft = size;
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void skip_file(off_t size)
{
	union block *x;

	/* FIXME: Make sure mv_begin_read is always called before it */
	if (seekable_archive)
	{
		off_t nblk = seek_archive(size);
		if (nblk >= 0)
			size -= nblk * BLOCKSIZE;
		else
			seekable_archive = false;
	}
	mv_size_left(size);
	while (size > 0)
	{
		x = find_next_block();
		if (!x)
		{
			;
			strcpy(error_message_k, "Unexpected end of file found");
			fatal_exit_k = 2004;
			return;
		}
		set_next_block_after(x);
		size -= BLOCKSIZE;
		mv_size_left(size);
	}
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void mv_begin_write(__attribute__((unused)) const char *file_name, __attribute__((unused)) off_t totsize, __attribute__((unused)) off_t sizeleft)
{
}

/**
 * Tar related function, version 1.34
 *
 */
void mv_begin_read(struct tar_stat_info *st)
{
	mv_begin_write(st->orig_file_name, st->stat.st_size, st->stat.st_size);
}

/**
 * Tar related function, version 1.34
 * Skip the current member in the archive.
 * NOTE: Current header must be decoded before calling this function
 */
void skip_member(void)
{
	if (!current_stat_info.skipped)
	{
		char save_typeflag = current_header->header.typeflag;
		set_next_block_after(current_header);
		mv_begin_read(&current_stat_info);
		if (current_stat_info.is_sparse)
			sparse_skip_file(&current_stat_info);
		else if (save_typeflag != DIRTYPE)
		{
			skip_file(current_stat_info.stat.st_size);
		}
		mv_end();
	}
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
int gname_to_gid(__attribute__((unused)) char const *gname, __attribute__((unused)) short *gidp)
{
	return 0;
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
int uname_to_uid(__attribute__((unused)) char const *uname, __attribute__((unused)) short *uidp)
{
	return 0;
}

/**
 * Tar related function, version 1.34
 *
 */
short gid_from_header(const char *p, size_t s)
{
	return from_header(p, s, "int",
					   TYPE_MINIMUM(int), TYPE_MAXIMUM(int),
					   false, false);
}

/**
 * Tar related function, version 1.34
 *
 */
short uid_from_header(const char *p, size_t s)
{
	return from_header(p, s, "int",
					   TYPE_MINIMUM(int), TYPE_MAXIMUM(int),
					   false, false);
}

/**
 * Tar related function, version 1.34
 *
 */
void assign_string_n(char **string, const char *value, size_t n)
{
	free(*string);
	if (value)
	{
		size_t l = strnlen(value, n);
		char *p = malloc(l + 1);
		memcpy(p, value, l);
		p[l] = 0;
		*string = p;
	}
}

/**
 * Tar related function, version 1.34
 *
 */
time_t
time_from_header(const char *p, size_t s)
{
	return from_header(p, s, "time_t",
					   TYPE_MINIMUM(time_t), TYPE_MAXIMUM(time_t),
					   false, false);
}

/* high performance ("contiguous data") */
#ifndef S_ISCTG
#define S_ISCTG(p) 0
#endif

/* Cray DMF (data migration facility): off line, with data  */
#ifndef S_ISOFD
#define S_ISOFD(p) 0
#endif

/* Cray DMF (data migration facility): off line, with no data  */
#ifndef S_ISOFL
#define S_ISOFL(p) 0
#endif

/* 4.4BSD whiteout */
#ifndef S_ISWHT
#define S_ISWHT(m) 0
#endif

/* If any of the following are undefined,
   define them to their de facto standard values.  */
#if !S_ISUID
#define S_ISUID 04000
#endif
#if !S_ISGID
#define S_ISGID 02000
#endif

/* S_ISVTX is a common extension to POSIX.  */
#ifndef S_ISVTX
#define S_ISVTX 01000
#endif

#if !S_IRUSR && S_IREAD
#define S_IRUSR S_IREAD
#endif
#if !S_IRUSR
#define S_IRUSR 00400
#endif
#if !S_IRGRP
#define S_IRGRP (S_IRUSR >> 3)
#endif
#if !S_IROTH
#define S_IROTH (S_IRUSR >> 6)
#endif

#if !S_IWUSR && S_IWRITE
#define S_IWUSR S_IWRITE
#endif
#if !S_IWUSR
#define S_IWUSR 00200
#endif
#if !S_IWGRP
#define S_IWGRP (S_IWUSR >> 3)
#endif
#if !S_IWOTH
#define S_IWOTH (S_IWUSR >> 6)
#endif

#if !S_IXUSR && S_IEXEC
#define S_IXUSR S_IEXEC
#endif
#if !S_IXUSR
#define S_IXUSR 00100
#endif
#if !S_IXGRP
#define S_IXGRP (S_IXUSR >> 3)
#endif
#if !S_IXOTH
#define S_IXOTH (S_IXUSR >> 6)
#endif

/**
 * Tar related function, version 1.34
 * Convert P to the file mode, as understood by tar.
 * Set *HBITS if there are any unrecognized bits.
 */
mode_t
mode_from_header(const char *p, size_t s, bool *hbits)
{
	intmax_t u = from_header(p, s, "mode_t",
							 INTMAX_MIN, UINTMAX_MAX,
							 false, false);
	mode_t mode = ((u & TSUID ? S_ISUID : 0) | (u & TSGID ? S_ISGID : 0) | (u & TSVTX ? S_ISVTX : 0) | (u & TUREAD ? S_IRUSR : 0) | (u & TUWRITE ? S_IWUSR : 0) | (u & TUEXEC ? S_IXUSR : 0) | (u & TGREAD ? S_IRGRP : 0) | (u & TGWRITE ? S_IWGRP : 0) | (u & TGEXEC ? S_IXGRP : 0) | (u & TOREAD ? S_IROTH : 0) | (u & TOWRITE ? S_IWOTH : 0) | (u & TOEXEC ? S_IXOTH : 0));

	*hbits = (u & ~07777) != 0;
	return mode;
}

static major_t major_from_header(const char *buf, size_t size);
static minor_t minor_from_header(const char *buf, size_t size);

#define GID_FROM_HEADER(where) gid_from_header(where, sizeof(where))
#define MAJOR_FROM_HEADER(where) major_from_header(where, sizeof(where))
#define MINOR_FROM_HEADER(where) minor_from_header(where, sizeof(where))
#define MODE_FROM_HEADER(where, hbits) \
	mode_from_header(where, sizeof(where), hbits)
#define TIME_FROM_HEADER(where) time_from_header(where, sizeof(where))
#define UID_FROM_HEADER(where) uid_from_header(where, sizeof(where))

#define ISOCTAL(c) ((c) >= '0' && (c) <= '7')

/**
 *  Tar related function, version 1.34
 *
 *  Decode things from a file HEADER block into STAT_INFO, also setting
 *  FORMAT_POINTER depending on the header block format.  If
 *  DO_USER_GROUP, decode the user/group information (this is useful
 *  for extraction, but waste time when merely listing).
 *
 *  read_header() has already decoded the checksum and length, so we don't.
 *
 *  This routine should *not* be called twice for the same block, since
 *  the two calls might use different DO_USER_GROUP values and thus
 *  might end up with different uid/gid for the two calls.  If anybody
 *  wants the uid/gid they should decode it first, and other callers
 *  should decode it without uid/gid before calling a routine,
 *  e.g. print_header, that assumes decoded data.
 */
void decode_header(union block *header, struct tar_stat_info *stat_info,
				   enum archive_format *format_pointer, int do_user_group)
{
	enum archive_format format;
	bool hbits;
	mode_t mode = MODE_FROM_HEADER(header->header.mode, &hbits);

	if (strcmp(header->header.magic, TMAGIC) == 0)
	{
		if (header->star_header.prefix[130] == 0 && ISOCTAL(header->star_header.atime[0]) && header->star_header.atime[11] == ' ' && ISOCTAL(header->star_header.ctime[0]) && header->star_header.ctime[11] == ' ')
			format = STAR_FORMAT;
		else if (stat_info->xhdr.size)
			format = POSIX_FORMAT;
		else
			format = USTAR_FORMAT;
	}
	else if (strcmp(header->buffer + offsetof(struct posix_header, magic),
					OLDGNU_MAGIC) == 0)
		format = hbits ? OLDGNU_FORMAT : GNU_FORMAT;
	else
		format = V7_FORMAT;
	*format_pointer = format;

	detected_format_arp = format;

	stat_info->stat.st_mode = mode;
	stat_info->mtime.tv_sec = TIME_FROM_HEADER(header->header.mtime);
	stat_info->mtime.tv_nsec = 0;
	assign_string_n(&stat_info->uname,
					header->header.uname[0] ? header->header.uname : NULL,
					sizeof(header->header.uname));
	assign_string_n(&stat_info->gname,
					header->header.gname[0] ? header->header.gname : NULL,
					sizeof(header->header.gname));

	xheader_xattr_init(stat_info);

	if (format == OLDGNU_FORMAT && incremental_option)
	{
		stat_info->atime.tv_sec = TIME_FROM_HEADER(header->oldgnu_header.atime);
		stat_info->ctime.tv_sec = TIME_FROM_HEADER(header->oldgnu_header.ctime);
		stat_info->atime.tv_nsec = stat_info->ctime.tv_nsec = 0;
	}
	else if (format == STAR_FORMAT)
	{
		stat_info->atime.tv_sec = TIME_FROM_HEADER(header->star_header.atime);
		stat_info->ctime.tv_sec = TIME_FROM_HEADER(header->star_header.ctime);
		stat_info->atime.tv_nsec = stat_info->ctime.tv_nsec = 0;
	}
	else
		stat_info->atime = stat_info->ctime = start_time;

	if (format == V7_FORMAT)
	{
		stat_info->stat.st_uid = UID_FROM_HEADER(header->header.uid);
		stat_info->stat.st_gid = GID_FROM_HEADER(header->header.gid);
		stat_info->stat.st_rdev = 0;
	}
	else
	{
		if (do_user_group)
		{
			/* FIXME: Decide if this should somewhat depend on -p.  */

			if (numeric_owner_option || !*header->header.uname || !uname_to_uid(header->header.uname, &stat_info->stat.st_uid))
				stat_info->stat.st_uid = UID_FROM_HEADER(header->header.uid);

			if (numeric_owner_option || !*header->header.gname || !gname_to_gid(header->header.gname, &stat_info->stat.st_gid))
				stat_info->stat.st_gid = GID_FROM_HEADER(header->header.gid);
		}

		switch (header->header.typeflag)
		{
		case BLKTYPE:
		case CHRTYPE:

			stat_info->stat.st_rdev =
				makedev(MAJOR_FROM_HEADER(header->header.devmajor),
						MINOR_FROM_HEADER(header->header.devminor));

			//stat_info->stat.st_rdev = 0;

			break;

		default:
			stat_info->stat.st_rdev = 0;
		}
	}

	xheader_decode(stat_info);

	if (sparse_member_p(stat_info))
	{
		sparse_fixup_header(stat_info);
		stat_info->is_sparse = true;
	}
	else
	{
		stat_info->is_sparse = false;
		if (((current_format == GNU_FORMAT || current_format == OLDGNU_FORMAT) && current_header->header.typeflag == GNUTYPE_DUMPDIR) || stat_info->dumpdir)
			stat_info->is_dumpdir = true;
	}
}

#define FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE_UNIX 0

#define DOUBLE_SLASH_IS_DISTINCT_ROOT_UNIX 0

#define ISSLASH_UNIX(C) ((C) == '/')
#define IS_ABSOLUTE_PATH_UNIX(P) ISSLASH_UNIX((P)[0])
#define IS_PATH_WITH_DIR_UNIX(P) (strchr(P, '/') != NULL)
#define FILE_SYSTEM_PREFIX_LEN_UNIX(P) 0

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
char *
last_component_unix(char const *name)
{
	char const *base = name + FILE_SYSTEM_PREFIX_LEN_UNIX(name);
	char const *p;
	bool saw_slash = false;

	while (ISSLASH_UNIX(*base))
		base++;

	for (p = base; *p; p++)
	{
		if (ISSLASH_UNIX(*p))
			saw_slash = true;
		else if (saw_slash)
		{
			base = p;
			saw_slash = false;
		}
	}

	return (char *)base;
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
size_t
base_len_unix(char const *name)
{
	size_t len;
	size_t prefix_len = FILE_SYSTEM_PREFIX_LEN_UNIX(name);

	for (len = strlen(name); 1 < len && ISSLASH_UNIX(name[len - 1]); len--)
		continue;

	if (DOUBLE_SLASH_IS_DISTINCT_ROOT_UNIX && len == 1 && ISSLASH_UNIX(name[0]) && ISSLASH_UNIX(name[1]) && !name[2])
		return 2;

	if (FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE_UNIX && prefix_len && len == prefix_len && ISSLASH_UNIX(name[prefix_len]))
		return prefix_len + 1;

	return len;
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
bool strip_trailing_slashes_unix(char *file)
{
	char *base = last_component_unix(file);
	char *base_lim;
	bool had_slash;

	/* last_component returns "" for file system roots, but we need to turn
	   "///" into "/".  */
	if (!*base)
		base = file;
	base_lim = base + base_len_unix(base);
	had_slash = (*base_lim != '\0');
	*base_lim = '\0';
	return had_slash;
}

/**
 *  Tar related function, version 1.34
 *  Assign STRING to a copy of VALUE if not zero, or to zero.  If
 *  STRING was nonzero, it is freed first.
 */
void assign_string(char **string, const char *value)
{
	free(*string);
	*string = value ? strdup(value) : 0;
}

/**
 * Tar related function, version 1.34
 * Return the number of bytes comprising the space between POINTER
 * through the end of the current buffer of blocks.  This space is
 * available for filling with data, or taking data from.  POINTER is
 * usually (but not always) the result of previous find_next_block call.
 */
size_t
available_space_after(union block *pointer)
{
	return record_end->buffer - pointer->buffer;
}

/**
 * Tar related function, version 1.34
 * Indicate that we have used all blocks up thru BLOCK.
 */
void set_next_block_after(union block *block)
{
	while (block >= current_block)
		current_block++;

	/* Do *not* flush the archive here.  If we do, the same argument to
	   set_next_block_after could mean the next block (if the input record
	   is exactly one block long), which is not what is intended.  */

	if (current_block > record_end)
		abort();
}

/**
 * Tar related function, version 1.34
 *
 */
off_t off_from_header(const char *p, size_t s)
{
	/* Negative offsets are not allowed in tar files, so invoke
	   from_header with minimum value 0, not TYPE_MINIMUM (off_t).  */
	return from_header(p, s, "off_t",
					   0, TYPE_MAXIMUM(off_t),
					   false, false);
}

/**
 * Tar related function, version 1.34
 * Decode a single extended header record, advancing *PTR to the next record.
 * Return true on success, false otherwise.
 */
static bool
decode_record(struct xheader *xhdr,
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

	if (!ISDIGIT(*p))
	{
		if (*p)
		{
			pedro_dprintf(2, "Malformed extended header: missing length");
		}
		return false;
	}

	len = strtoumax(p, &len_lim, 10);

	if (len_max < len)
	{
		int len_len = len_lim - p;
		pedro_dprintf(2, "Extended header length %*s is out of range",
					  len_len, p);
		return false;
	}

	nextp = start + len;

	for (p = len_lim; *p == ' ' || *p == '\t'; p++)
		continue;
	if (p == len_lim)
	{
		pedro_dprintf(2, "Malformed extended header: missing blank after length");
		return false;
	}

	keyword = p;
	p = strchr(p, '=');
	if (!(p && p < nextp))
	{
		pedro_dprintf(2, "Malformed extended header: missing equal sign");
		return false;
	}

	if (nextp[-1] != '\n')
	{
		pedro_dprintf(2, "Malformed extended header: missing newline");
		return false;
	}

	*p = nextp[-1] = '\0';
	handler(data, keyword, p + 1, nextp - p - 2); /* '=' + trailing '\n' */
	*p = '=';
	nextp[-1] = '\n';
	*ptr = nextp;
	return true;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
xheader_list_append(struct keyword_list **root, char const *kw,
					char const *value)
{
	struct keyword_list *kp = malloc(sizeof *kp);

	kp->pattern = xstrdup(kw);
	kp->value = value ? xstrdup(value) : NULL;
	kp->next = *root;
	*root = kp;
}

/**
 * Tar related function, version 1.34
 *
 */
static void
decg(void *data, char const *keyword, char const *value,
	 size_t size __attribute__((unused)))
{
	struct keyword_list **kwl = data;
	struct xhdr_tab const *tab = locate_handler(keyword);

	if (tab && (tab->flags & XHDR_GLOBAL))
		tab->decoder(data, keyword, value, size);
	else
		xheader_list_append(kwl, keyword, value);
}

/**
 * Tar related function, version 1.34
 *
 */
void xheader_decode_global(struct xheader *xhdr)
{
	if (xhdr->size)
	{
		char *p = xhdr->buffer + BLOCKSIZE;
		xheader_list_destroy(&global_header_override_list);
		while (decode_record(xhdr, &p, decg, &global_header_override_list))
			continue;
	}
}

/**
 * Tar related function, version 1.34
 *
 */
enum read_header
read_header_old_1_32(union block **return_block, struct tar_stat_info *info,
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
		;
		enum read_header status;

		header = find_next_block();
		*return_block = header;
		if (!header)
			return HEADER_END_OF_FILE;

		if ((status = tar_checksum(header, false)) != HEADER_SUCCESS)
			return status;

		/* Good block.  Decode file size and return.  */

		if (header->header.typeflag == LNKTYPE)
			info->stat.st_size = 0; /* links 0 size on tape */
		else
		{
			info->stat.st_size = OFF_FROM_HEADER(header->header.size);
			if (info->stat.st_size < 0)
				return HEADER_FAILURE;
		}

		if (header->header.typeflag == GNUTYPE_LONGNAME || header->header.typeflag == GNUTYPE_LONGLINK || header->header.typeflag == XHDTYPE || header->header.typeflag == XGLTYPE || header->header.typeflag == SOLARIS_XHDTYPE)
		{
			if (mode == read_header_x_raw)
				return HEADER_SUCCESS_EXTENDED;
			else if (header->header.typeflag == GNUTYPE_LONGNAME || header->header.typeflag == GNUTYPE_LONGLINK)
			{
				size_t name_size = info->stat.st_size;
				size_t n = name_size % BLOCKSIZE;
				size = name_size + BLOCKSIZE;
				if (n)
					size += BLOCKSIZE - n;

				if ((size_t)name_size != (size_t)(info->stat.st_size) || size < name_size)
				{
					assert(0 && "nunca pode acontecer");
				}

				header_copy = malloc(size + 1);

				if (header->header.typeflag == GNUTYPE_LONGNAME)
				{
					free(next_long_name);
					next_long_name = header_copy;
					next_long_name_blocks = size / BLOCKSIZE;
				}
				else
				{
					free(next_long_link);
					next_long_link = header_copy;
					next_long_link_blocks = size / BLOCKSIZE;
				}

				set_next_block_after(header);
				*header_copy = *header;
				bp = header_copy->buffer + BLOCKSIZE;

				for (size -= BLOCKSIZE; size > 0; size -= written)
				{
					data_block = find_next_block();
					if (!data_block)
					{
						pedro_dprintf(2, "Unexpected EOF in archive");

						break;
					}
					written = available_space_after(data_block);
					if (written > size)
						written = size;

					memcpy(bp, data_block->buffer, written);
					bp += written;
					set_next_block_after((union block *)(data_block->buffer + written - 1));
				}

				*bp = '\0';
			}
			else if (header->header.typeflag == XHDTYPE || header->header.typeflag == SOLARIS_XHDTYPE)
			{
				;
				xheader_read(&info->xhdr, header,
							 OFF_FROM_HEADER(header->header.size));
			}
			else if (header->header.typeflag == XGLTYPE)
			{
				struct xheader xhdr;

				if (!recent_global_header)
					recent_global_header = malloc(sizeof *recent_global_header);
				memcpy(recent_global_header, header,
					   sizeof *recent_global_header);
				;
				memset(&xhdr, 0, sizeof xhdr);
				xheader_read(&xhdr, header,
							 OFF_FROM_HEADER(header->header.size));
				xheader_decode_global(&xhdr);
				xheader_destroy(&xhdr);

				if (mode == read_header_x_global)
					return HEADER_SUCCESS_EXTENDED;
			}
		}
		else
		{
			char const *name;
			struct posix_header const *h = &header->header;
			char namebuf[sizeof h->prefix + 1 + NAME_FIELD_SIZE + 1];

			if (recent_long_name)
			{
				free(recent_long_name);
				recent_long_name = NULL;
			}

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

				if (h->prefix[0] && strcmp(h->magic, TMAGIC) == 0)
				{
					memcpy(np, h->prefix, sizeof h->prefix);
					np[sizeof h->prefix] = '\0';
					np += strlen(np);
					*np++ = '/';
				}
				memcpy(np, h->name, sizeof h->name);
				np[sizeof h->name] = '\0';
				name = namebuf;
				recent_long_name = 0;
				recent_long_name_blocks = 0;
			}

			assign_string(&info->orig_file_name, name);
			assign_string(&info->file_name, name);
			info->had_trailing_slash = strip_trailing_slashes_unix(info->file_name);
			if (recent_long_link)
			{
				free(recent_long_link);
				recent_long_link = NULL;
			}
			if (next_long_link)
			{
				name = next_long_link->buffer + BLOCKSIZE;
				recent_long_link = next_long_link;
				recent_long_link_blocks = next_long_link_blocks;
			}
			else
			{
				memcpy(namebuf, h->linkname, sizeof h->linkname);
				namebuf[sizeof h->linkname] = '\0';
				name = namebuf;
				recent_long_link = 0;
				recent_long_link_blocks = 0;
			}
			assign_string(&info->link_name, name);
			return HEADER_SUCCESS;
		}
	}
}

/**
 * Tar related function, version 1.34
 *
 */
enum read_header
read_header(union block **return_block, struct tar_stat_info *info,
			enum read_header_mode mode)
{
	union block *header;
	char *bp;
	union block *data_block;
	size_t size, written;
	union block *next_long_name = NULL;
	union block *next_long_link = NULL;
	size_t next_long_name_blocks = 0;
	size_t next_long_link_blocks = 0;
	enum read_header status = HEADER_SUCCESS;

	while (1)
	{
		header = find_next_block();
		*return_block = header;
		if (!header)
		{
			status = HEADER_END_OF_FILE;
			break;
		}

		if ((status = tar_checksum(header, false)) != HEADER_SUCCESS)
			break;

		/* Good block.  Decode file size and return.  */

		if (header->header.typeflag == LNKTYPE)
			info->stat.st_size = 0; /* links 0 size on tape */
		else
		{
			info->stat.st_size = OFF_FROM_HEADER(header->header.size);
			if (info->stat.st_size < 0)
			{
				status = HEADER_FAILURE;
				break;
			}
		}

		if (header->header.typeflag == GNUTYPE_LONGNAME || header->header.typeflag == GNUTYPE_LONGLINK || header->header.typeflag == XHDTYPE || header->header.typeflag == XGLTYPE || header->header.typeflag == SOLARIS_XHDTYPE)
		{
			if (mode == read_header_x_raw)
			{
				status = HEADER_SUCCESS_EXTENDED;
				break;
			}
			else if (header->header.typeflag == GNUTYPE_LONGNAME || header->header.typeflag == GNUTYPE_LONGLINK)
			{
				union block *header_copy;
				size_t name_size = info->stat.st_size;
				size_t n = name_size % BLOCKSIZE;
				size = name_size + BLOCKSIZE;
				if (n)
					size += BLOCKSIZE - n;

				if ((size_t)name_size != (size_t)(info->stat.st_size) || size < name_size)
				{
					//xalloc_die ();
					assert(0 && "nunca pode acontecer");
				}

				header_copy = xmalloc(size + 1);

				if (header->header.typeflag == GNUTYPE_LONGNAME)
				{
					free(next_long_name);
					next_long_name = header_copy;
					next_long_name_blocks = size / BLOCKSIZE;
				}
				else
				{
					free(next_long_link);
					next_long_link = header_copy;
					next_long_link_blocks = size / BLOCKSIZE;
				}

				set_next_block_after(header);
				*header_copy = *header;
				bp = header_copy->buffer + BLOCKSIZE;

				for (size -= BLOCKSIZE; size > 0; size -= written)
				{
					data_block = find_next_block();
					if (!data_block)
					{
						pedro_dprintf(2, "Unexpected EOF in archive");
						break;
					}
					written = available_space_after(data_block);
					if (written > size)
						written = size;

					memcpy(bp, data_block->buffer, written);
					bp += written;
					set_next_block_after((union block *)(data_block->buffer + written - 1));
				}

				*bp = '\0';
			}
			else if (header->header.typeflag == XHDTYPE || header->header.typeflag == SOLARIS_XHDTYPE)
				xheader_read(&info->xhdr, header,
							 OFF_FROM_HEADER(header->header.size));
			else if (header->header.typeflag == XGLTYPE)
			{
				struct xheader xhdr;

				if (!recent_global_header)
					recent_global_header = xmalloc(sizeof *recent_global_header);
				memcpy(recent_global_header, header,
					   sizeof *recent_global_header);
				memset(&xhdr, 0, sizeof xhdr);
				xheader_read(&xhdr, header,
							 OFF_FROM_HEADER(header->header.size));
				xheader_decode_global(&xhdr);
				xheader_destroy(&xhdr);
				if (mode == read_header_x_global)
				{
					status = HEADER_SUCCESS_EXTENDED;
					break;
				}
			}

			/* Loop!  */
		}
		else
		{
			char const *name;
			struct posix_header const *h = &header->header;
			char namebuf[sizeof h->prefix + 1 + NAME_FIELD_SIZE + 1];

			free(recent_long_name);

			if (next_long_name)
			{
				name = next_long_name->buffer + BLOCKSIZE;
				recent_long_name = next_long_name;
				recent_long_name_blocks = next_long_name_blocks;
				next_long_name = NULL;
			}
			else
			{
				/* Accept file names as specified by POSIX.1-1996
				   section 10.1.1.  */
				char *np = namebuf;

				if (h->prefix[0] && strcmp(h->magic, TMAGIC) == 0)
				{
					memcpy(np, h->prefix, sizeof h->prefix);
					np[sizeof h->prefix] = '\0';
					np += strlen(np);
					*np++ = '/';
				}
				memcpy(np, h->name, sizeof h->name);
				np[sizeof h->name] = '\0';
				name = namebuf;
				recent_long_name = 0;
				recent_long_name_blocks = 0;
			}
			assign_string(&info->orig_file_name, name);
			assign_string(&info->file_name, name);
			info->had_trailing_slash = strip_trailing_slashes_unix(info->file_name);

			free(recent_long_link);

			if (next_long_link)
			{
				name = next_long_link->buffer + BLOCKSIZE;
				recent_long_link = next_long_link;
				recent_long_link_blocks = next_long_link_blocks;
				next_long_link = NULL;
			}
			else
			{
				memcpy(namebuf, h->linkname, sizeof h->linkname);
				namebuf[sizeof h->linkname] = '\0';
				name = namebuf;
				recent_long_link = 0;
				recent_long_link_blocks = 0;
			}
			assign_string(&info->link_name, name);

			break;
		}
	}
	free(next_long_name);
	free(next_long_link);
	return status;
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void close_error(__attribute__((unused)) char const *name)
{
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void close_warn(__attribute__((unused)) char const *name)
{
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void open_error(__attribute__((unused)) char const *name)
{
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void open_warn(__attribute__((unused)) char const *name)
{
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void open_diag(char const *name)
{
	if (ignore_failed_read_option)
	{
		if (WARNING_ENABLED(WARN_FAILED_READ))
			open_warn(name);
	}
	else
		open_error(name);
}

/**
 * Tar related function, version 1.34
 *
 */
void close_diag(char const *name)
{
	if (ignore_failed_read_option)
	{
		if (WARNING_ENABLED(WARN_FAILED_READ))
			close_warn(name);
	}
	else
		close_error(name);
}

/**
 * Tar related function, version 1.34
 * Close the stream or file descriptor associated with ST, and remove
 * all traces of it from ST.  Return true if successful, false (with a
 * diagnostic) otherwise.
 */
bool tar_stat_close(struct tar_stat_info *st)
{
	int status = (st->dirstream ? closedir(st->dirstream)
				  : 0 < st->fd	? close(st->fd)
								: 0);

	st->dirstream = 0;
	st->fd = 0;

	if (status == 0)
		return true;
	else
	{
		close_diag(st->orig_file_name);
		return false;
	}
}

/**
 * Tar related function, version 1.34
 *
 */
void tar_stat_destroy(struct tar_stat_info *st)
{
	tar_stat_close(st);
	xheader_xattr_free(st->xattr_map, st->xattr_map_size);
	free(st->orig_file_name);
	free(st->file_name);
	free(st->link_name);
	free(st->uname);
	free(st->gname);
	free(st->cntx_name);
	free(st->acls_a_ptr);
	free(st->acls_d_ptr);
	free(st->sparse_map);
	free(st->dumpdir);
	xheader_destroy(&st->xhdr);
	memset(st, 0, sizeof(*st));
}

#if !(UINTMAX_MAX / 2 <= INTMAX_MAX)
#error "represent_uintmax returns intmax_t to represent uintmax_t"
#endif

#define LG_8 3
#define LG_64 6
#define LG_256 8

#define ISODIGIT(c) ((unsigned)(c) - '0' <= 7)

/* Convert buffer at WHERE0 of size DIGS from external format to
   intmax_t.  DIGS must be positive.  If TYPE is nonnull, the data are
   of type TYPE.  The buffer must represent a value in the range
   MINVAL through MAXVAL; if the mathematically correct result V would
   be greater than INTMAX_MAX, return a negative integer V such that
   (uintmax_t) V yields the correct result.  If OCTAL_ONLY, allow only octal
   numbers instead of the other GNU extensions.  Return -1 on error,
   diagnosing the error if TYPE is nonnull and if !SILENT.  */
#if !(INTMAX_MAX <= UINTMAX_MAX && -(INTMAX_MIN + 1) <= UINTMAX_MAX)
#error "from_header internally represents intmax_t as uintmax_t + sign"
#endif
#if !(UINTMAX_MAX / 2 <= INTMAX_MAX)
#error "from_header returns intmax_t to represent uintmax_t"
#endif

/**
 * Tar related function, version 1.34
 *
 */
intmax_t
from_header(char const *where0, size_t digs, char const *type,
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
			{
				/*
				   ERROR ((0, 0,
				   TRANSLATORS: %s is type of the value (gid_t, uid_t,
				   etc.)
				   _("Blanks in header where numeric %s value expected"),
				   type));
				 */

				printf("Blanks in header where numeric %s value expected", type);
				pedro_dprintf(2, "Blanks in header where numeric %s value expected", type);
			}
			return -1;
		}
		if (!isspace((unsigned char)*where))
			break;
		where++;
	}

	value = 0;
	if (ISODIGIT(*where))
	{
		char const *where1 = where;
		bool overflow = false;

		for (;;)
		{
			value += *where++ - '0';
			if (where == lim || !ISODIGIT(*where))
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
				if (where == lim || !ISODIGIT(*where))
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
				{
					printf("Archive octal value is out of range; assuming two's complement");
					pedro_dprintf(2, "Archive octal value is out of range; assuming two's complement");
				}

				negative = true;
			}
		}

		if (overflow)
		{
			if (type && !silent)
			{
				printf("Archive octal value is out of range");
				pedro_dprintf(2, "Archive octal value is out of range");
			}
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
				printf("Archive contains obsolescent base-64 headers");
				pedro_dprintf(2, "Archive contains obsolescent base-64 headers");
			}
		}
		negative = *where++ == '-';
		while (where != lim && (dig = base64_map[(unsigned char)*where]) < 64)
		{
			if (value << LG_64 >> LG_64 != value)
			{
				char *string = alloca(digs + 1);
				memcpy(string, where0, digs);
				string[digs] = '\0';
				if (type && !silent)
				{
					printf("Archive signed base-64 string is out of range");
					pedro_dprintf(2, "Archive signed base-64 string is out of range");
				}

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
		uintmax_t topbits = (((uintmax_t)-signbit)
							 << (CHAR_BIT * sizeof(uintmax_t) - LG_256 - (LG_256 - 2)));
		value = (*where++ & ((1 << (LG_256 - 2)) - 1)) - signbit;
		for (;;)
		{
			value = (value << LG_256) + (unsigned char)*where++;
			if (where == lim)
				break;
			if (((value << LG_256 >> LG_256) | topbits) != value)
			{
				if (type && !silent)
				{
					printf("Archive base-256 value is out of range");
					pedro_dprintf(2, "Archive base-256 value is out of range");
				}
				return -1;
			}
		}
		negative = signbit != 0;
		if (negative)
			value = -value;
	}

	if (where != lim && *where && !isspace((unsigned char)*where))
	{
		if (type)
		{
			if (!silent)
			{
				printf("Archive contains where numeric value expected");
				pedro_dprintf(2, "Archive contains where numeric value expected");
			}
		}

		return -1;
	}

	if (value <= (negative ? minus_minval : maxval))
		return represent_uintmax(negative ? -value : value);

	if (type && !silent)
	{
		printf("Archive value is out of range -> %s\n", type);
		pedro_dprintf(2, "Archive value is out of range -> %s\n", type);
	}

	return -1;
}

/**
 * Tar related function, version 1.34
 *
 */
void base64_init(void)
{
	int i;
	memset(base64_map, 64, sizeof base64_map);
	for (i = 0; i < 64; i++)
		base64_map[(int)base_64_digits[i]] = i;
}

/**
 * Tar related function, version 1.34
 *
 */
enum read_header
tar_checksum(union block *header, bool silent)
{
	size_t i;
	int unsigned_sum = 0; /* the POSIX one :-) */
	int signed_sum = 0;	  /* the Sun one :-( */
	int recorded_sum;
	int parsed_sum;
	char *p;
	p = header->buffer;
	for (i = sizeof *header; i-- != 0;)
	{
		unsigned_sum += (unsigned char)*p;
		signed_sum += (signed char)(*p++);
	}

	if (unsigned_sum == 0)
		return HEADER_ZERO_BLOCK;

	/* Adjust checksum to count the "chksum" field as blanks.  */

	for (i = sizeof header->header.chksum; i-- != 0;)
	{
		unsigned_sum -= (unsigned char)header->header.chksum[i];
		signed_sum -= (signed char)(header->header.chksum[i]);
	}
	unsigned_sum += ' ' * sizeof header->header.chksum;
	signed_sum += ' ' * sizeof header->header.chksum;

	parsed_sum = from_header(header->header.chksum,
							 sizeof header->header.chksum, 0,
							 0, INT_MAX, true, silent);
	if (parsed_sum < 0)
		return HEADER_FAILURE;

	recorded_sum = parsed_sum;

	if (unsigned_sum != recorded_sum && signed_sum != recorded_sum)
		return HEADER_FAILURE;

	return HEADER_SUCCESS;
}

/**
 * Tar related function, version 1.34
 *
 */
void gnu_flush_read(void)
{
	flush_read_ptr = simple_flush_read; /* Avoid recursion */
	_gnu_flush_read();
	flush_read_ptr = gnu_flush_read;
}

/**
 * Tar related function, version 1.34, modified
 * Open an archive file.  The argument specifies whether we are
 * reading or writing, or both.
 */
void _open_archive(enum access_mode wanted_access)
{
	if (record_size == 0)
	{
		strcpy(error_message_k, "Invalid value for record_size");
		fatal_exit_k = 1;
		return;
	}
	tar_stat_destroy(&current_stat_info);
	record_index = 0;
	init_buffer();

	/* When updating the archive, we start with reading.  */
	access_mode = wanted_access == ACCESS_UPDATE ? ACCESS_READ : wanted_access;

	read_full_records = read_full_records_option;

	records_read = 0;

	if (0 /*use_compress_program_option*/)
	{
	}
	else if (0 /*strcmp (archive_name_array_filename, "-") == 0*/)
	{
	}
	else
		switch (wanted_access)
		{
		case ACCESS_UPDATE: //to make the ricardo compiler happy

			break;

		case ACCESS_READ:
			archive = open_compressed_archive();

			if (fatal_exit_k) //out own error handling method
			{
				return;
			}

			if (archive >= 0)
				guess_seekable_archive();
			break;

		case ACCESS_WRITE:
			archive = _wcreat(permissive_name_m_(amanda_utf8towide_1_(archive_name_array_filename)), _S_IWRITE);
			if (0 > archive)
			{
				fatal_exit_k = 1;
				strcpy(error_message_k, "Cannot access the file to write");
				return;
			}

			break;
		}

	if (archive < 0)
	{
		fatal_exit_k = 1;
		strcpy(error_message_k, "Cannot access the file to read");
		return;
	}
	setmode(archive, O_BINARY);
	switch (wanted_access)
	{
	case ACCESS_UPDATE: //to make the ricardo compiler happy
		break;
	case ACCESS_READ:
		find_next_block(); /* read it in, check for EOF */
		break;
	case ACCESS_WRITE:
		records_written = 0;
		break;
	}
}
/**
 * This function will check whether the extension of the tar file is .br
 *
 */
int check_brotli_file_aakp(char *data_rspk)
{
	static char temp_aakp[AMANDA__SIZE];
	char *ptr = NULL;
	strcpy(temp_aakp, data_rspk);
	ptr = strrstr(temp_aakp, ".");
	if (NULL == ptr)
	{
		return 0;
	}
	ptr++;
	strtolower_ar(ptr);
	if (0 == strcmp("br", ptr))
	{
		return 1;
	}
	return 0;
}
/**
 * This function will check whether the file is an .iso file
 *
 */
int check_iso_file_aakp(char *data_rspk)
{
	static char temp_aakp[AMANDA__SIZE];
	char *ptr = NULL;
	strcpy(temp_aakp, data_rspk);
	ptr = strrstr(temp_aakp, ".");
	if (NULL == ptr)
	{
		return 0;
	}
	ptr++;
	strtolower_ar(ptr);
	if (0 == strcmp("iso", ptr))
	{
		return 1;
	}
	return 0;
}
/**
 * This function will check whether the file is a .lzma file
 *
 */
int check_lzma_file_aakp(char *data_rspk)
{
	static char temp_aakp[AMANDA__SIZE];
	char *ptr = NULL;
	strcpy(temp_aakp, data_rspk);
	ptr = strrstr(temp_aakp, ".");
	if (NULL == ptr)
	{
		return 0;
	}
	ptr++;
	strtolower_ar(ptr);
	if (0 == strcmp("lzma", ptr))
	{
		return 1;
	}
	if (0 == strcmp("tlz", ptr))
	{
		return 1;
	}
	return 0;
}

/**
 * Tar related function, version 1.34, slightly modified
 * Open an archive named archive_name_array_filename. Detect if it is
 * a compressed archive of known type and use corresponding decompression
 * program if so (in Unix, now Windows)
 */
int open_compressed_archive(void)
{
	archive = _wopen(permissive_name_m_(amanda_utf8towide_1_(archive_name_array_filename)), O_RDONLY | O_BINARY,
					 _S_IREAD);
	if (archive == -1)
		return archive;
	if (1)
	{
		if (1)
		{
			bool shortfile;
			enum compress_type type = check_compressed_archive(&shortfile);

			switch (type)
			{
			case ct_gzip2a:

				sprintf(error_message_k, " %d - File looks like a ct_gzip2a based file, extract it first", ct_gzip2a_k);

				fatal_exit_k = ct_gzip2a_k;
				return archive;
				break;

			case ct_gzip2c:

				sprintf(error_message_k, " %d - File looks like a ct_gzip2c based file, extract it first", ct_gzip2c_k);

				fatal_exit_k = ct_gzip2c_k;
				return archive;
				break;

			case ct_bzip3:

				sprintf(error_message_k, " %d - File looks like a ct_bzip3 based file, extract it first", ct_bzip3_k);

				fatal_exit_k = ct_bzip3_k;
				return archive;
				break;

			case ct_lzop2:

				sprintf(error_message_k, " %d - File looks like a ct_lzop2 based file, extract it first", ct_lzop2_k);

				fatal_exit_k = ct_lzop2_k;
				return archive;
				break;

			case ct_lz5:

				sprintf(error_message_k, " %d - File looks like a ct_lz5 based file, extract it first", ct_lz5_k);

				fatal_exit_k = ct_lz5_k;
				return archive;
				break;

			case ct_brotli2:

				sprintf(error_message_k, " %d - File looks like a ct_brotli2 based file, extract it first", ct_brotli2_k);

				fatal_exit_k = ct_brotli2_k;
				return archive;
				break;

			case ct_compress2:

				sprintf(error_message_k, " %d - File looks like a ct_compress2 based file, extract it first", ct_compress2_k);

				fatal_exit_k = ct_compress2_k;
				return archive;
				break;

			case ct_val:

				file_is_VAL_arp = true;

				return archive;

			case ct_tar:
				if (shortfile)
				{
					strcpy(error_message_k, "This does not look like a tar archive, file ct_tar");
					fatal_exit_k = 1;
				}

				return archive;

			case ct_none:
				if (shortfile)
				{

					strcpy(error_message_k, "This does not look like a tar archive, file ct_none 1");
					fatal_exit_k = 1;

					return archive;
				}

				if (check_lzma_file_aakp(archive_name_array_filename))
				{
					sprintf(error_message_k, " %d - File looks like a lzma based file, extract it first", ct_lzma_k);
					fatal_exit_k = ct_lzma_k;
					return archive;
				}

				if (check_brotli_file_aakp(archive_name_array_filename))
				{
					sprintf(error_message_k, " %d - File looks like a brotli based file, extract it first", ct_brotli_k);
					fatal_exit_k = ct_brotli_k;
					return archive;
				}

				fatal_exit_k = 0;
				return archive;
				break;

			case ct_compress:

				sprintf(error_message_k, " %d - File looks like a compress based file, extract it first", ct_compress_k);

				fatal_exit_k = ct_compress_k;
				return archive;

				break;

			case ct_gzip:

				sprintf(error_message_k, " %d - File looks like a gzip based file, extract it first", ct_gzip_k);

				fatal_exit_k = ct_gzip_k;
				return archive;

				break;

			case ct_bzip2:
				sprintf(error_message_k, " %d - File looks like a bzip2 based file, extract it first", ct_bzip2_k);
				fatal_exit_k = ct_bzip2_k;
				return archive;

				break;

			case ct_lzip:
				sprintf(error_message_k, " %d - File looks like a lzip based file, extract it first", ct_lzip_k);
				fatal_exit_k = ct_lzip_k;
				return archive;

				break;

			case ct_lzma:
				sprintf(error_message_k, " %d - File looks like a lzma based file, extract it first", ct_lzma_k);
				fatal_exit_k = ct_lzma_k;
				return archive;

				break;

			case ct_lzop:
				sprintf(error_message_k, " %d - File looks like a lzop based file, extract it first", ct_lzop_k);
				fatal_exit_k = ct_lzop_k;
				return archive;

				break;

			case ct_xz:
				sprintf(error_message_k, " %d - File looks like a xz based file, extract it first", ct_xz_k);
				fatal_exit_k = ct_xz_k;
				return archive;

				break;

			case ct_lz4:
				sprintf(error_message_k, "%d - File looks like a lz4 based file, extract it first", ct_lz4_k);
				fatal_exit_k = ct_lz4_k;
				return archive;

				break;

			case ct_zstd:
				sprintf(error_message_k, "%d - File looks like a Zstandard based file, extract it first", ct_zstd_k);
				fatal_exit_k = ct_zstd_k;
				return archive;

				break;

			default:

				strcpy(error_message_k, "This does not look like a tar archive, file unknown ");
				fatal_exit_k = 1;

				return archive;

				break;
			}
		}

		assert(0 && "nao pode chegar aqui nunca");

		hit_eof = false;
	}

	records_read = 0;
	record_end = record_start; /* set up for 1st record = # 0 */

	return archive;
}

/**
 * Tar related function, version 1.34, slightly modified
 * Guess if the archive is seekable.
 */
void guess_seekable_archive(void)
{
	seekable_archive = true; //in our case (windows) the file is always seekable
	return;
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void _gnu_flush_read(void)
{
	size_t status; /* result from system call */
	size_t status_b = -1;
	read_error_count = 0; /* clear error count */
	for (;;)
	{
		status = read(archive, record_start->buffer, record_size);
		if (status == record_size)
		{
			file_total__read_int64 += status;
			records_read++;
			return;
		}
		if (status_b == status)
		{
			fatal_exit_k = 1;
			strcpy(error_message_k, "Cannot read from tar file");
			return;
		}
		break;
	}
	short_read(status);
}

/**
 * Tar related function, version 1.34
 * Simple flush read (no multi-volume or label extensions)
 */
void simple_flush_read(void)
{
	size_t status; /* result from system call */
	int status_i;
	read_error_count = 0; /* clear error count */
	for (;;)
	{
		status = read(archive, record_start->buffer, record_size);
		if (status == record_size)
		{
			file_total__read_int64 += status;
			//#error aqui 2
			records_read++;
			return;
		}

		status_i = (int)status;

		if (0 > status_i)
		{
			fatal_exit_k = 1;
			strcpy(error_message_k, "Cannot read from tar file");
			return;
		}
		break;
	}
	short_read(status);
}

/**
 * Tar related function, version 1.34
 *
 */
off_t seek_archive(off_t size)
{
	off_t start = current_block_ordinal();
	off_t offset;
	off_t nrec, nblk;
	off_t skipped = (blocking_factor - (current_block - record_start)) * BLOCKSIZE;
	if (size <= skipped)
		return 0;
	/* Compute number of records to skip */
	nrec = (size - skipped) / record_size;
	if (nrec == 0)
		return 0;
	offset = lseek(archive, nrec * record_size, SEEK_CUR);
	if (offset < 0)
		return offset;
	if (offset % record_size)
	{
		strcpy(error_message_k, "lseek not stopped at a record boundary");
		fatal_exit_k = 1;
		return 0;
	}
	/* Convert to number of records */
	offset /= BLOCKSIZE;
	/* Compute number of skipped blocks */
	nblk = offset - start;
	/* Update buffering info */
	records_read += nblk / blocking_factor;
	record_start_block = offset - blocking_factor;
	current_block = record_end;
	return nblk;
}

/**
 * Tar related function, version 1.34
 *
 */
void short_read(size_t status)
{
	size_t left; /* bytes left */
	char *more;	 /* pointer to next byte to read */
	more = record_start->buffer + status;
	left = record_size - status;
	if (left && left % BLOCKSIZE == 0 && record_start_block == 0 && status != 0)
	{
		unsigned long rsize = status / BLOCKSIZE;
		printf("Record size = %lu block", rsize);
		pedro_dprintf(2, "Record size = %lu block", rsize);
	}

	while (left % BLOCKSIZE != 0 || (left && status && read_full_records))
	{
		if (status)
		{
			status = read(archive, more, left); // == SAFE_READ_ERROR)
			if (status == left)
				file_total__read_int64 += status;
		}
		if (status == 0)
			break;
		if (!read_full_records)
		{
			unsigned long rest = record_size - left;
			printf("Unaligned block (%lu byte) in archive", rest);
			pedro_dprintf(2, "Unaligned block (%lu byte) in archive", rest);
		}
		left -= status;
		more += status;
	}
	record_end = record_start + (record_size - left) / BLOCKSIZE;
	records_read++;
}

/**
 * It will retrieve in windows the pagesize
 *
 */
int getpagesize(void)
{
	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);
	return system_info.dwPageSize;
}

/**
 * Tar related function, version 1.34
 * Return PTR, aligned upward to the next multiple of ALIGNMENT.
 * ALIGNMENT must be nonzero.  The caller must arrange for ((char *)
 * PTR) through ((char *) PTR + ALIGNMENT - 1) to be addressable
 * locations.
 */
void *
ptr_align(void *ptr, size_t alignment)
{
	char *p0 = ptr;
	char *p1 = p0 + alignment - 1;
	return p1 - (size_t)p1 % alignment;
}

/**
 * Tar related function, version 1.34
 * Return the address of a page-aligned buffer of at least SIZE bytes.
 * The caller should free *PTR when done with the buffer.
 */
void *
page_aligned_alloc(void **ptr, size_t size)
{
	size_t alignment = getpagesize();
	size_t size1 = size + alignment;
	if (size1 < size)
	{
		pedro_dprintf(2, "Memory exausted");
		assert(0 && "Memory exausted");
		exit(26);
	}
	*ptr = malloc(size1);
	return ptr_align(*ptr, alignment);
}

/**
 * Tar related function, version 1.34
 *
 */
void init_buffer(void)
{
	if (!record_buffer_aligned[record_index])
		record_buffer_aligned[record_index] =
			page_aligned_alloc(&record_buffer[record_index], record_size);
	record_start = record_buffer_aligned[record_index];
	current_block = record_start;
	record_end = record_start + blocking_factor;
}

/**
 * Tar related function, version 1.34
 * Flush the current buffer to/from the archive.
 */
void flush_archive(void)
{
	size_t buffer_level;
	if (access_mode == ACCESS_READ && time_to_start_writing)
	{
		;
	}

	buffer_level = current_block->buffer - record_start->buffer;
	record_start_block += record_end - record_start;
	current_block = record_start;
	record_end = record_start + blocking_factor;

	switch (access_mode)
	{
	case ACCESS_UPDATE: //to make the ricardo compiler happy

		break;

	case ACCESS_READ:
		flush_read();
		break;

	case ACCESS_WRITE:

		flush_write_ptr(buffer_level);
		break;
	}
}

/**
 * Tar related function, version 1.34
 * Return the location of the next available input or output block.
 * Return zero for EOF.  Once we have returned zero, we just keep returning
 * it, to avoid accidentally going on to the next file on the tape.
 */
//what??? a tape???!!!
union block *
find_next_block(void)
{
	if (current_block == record_end)
	{
		if (hit_eof)
			return 0;
		flush_archive();
		if (current_block == record_end)
		{
			hit_eof = true;
			return 0;
		}
	}
	return current_block;
}

static struct zip_magic const magic[] = {
	{ct_none, 0, 0},
	{ct_tar, 0, 0},
	{ct_compress, 2, "\037\235"},
	{ct_gzip, 2, "\037\213"},
	{ct_bzip2, 3, "BZh"},
	{ct_lzip, 4, "LZIP"},
	{ct_lzma, 6, "\xFFLZMA"}, /* 
                                this don't work as you will see, but I will keep it here...
                                brotli also don't have a pre-defined header and both are
                                detected by extension at least in my code, notice that
                                brotli2 have a header 
                              */
	{ct_lzop, 4, "\211LZO"},
	{ct_xz, 6, "\xFD"
			   "7zXZ"},
	{ct_lz4, 4, "\x04\x22\x4d\x18"},
	{ct_zstd, 4, "\x28\xB5\x2F\xFD"},
	{ct_val, 4, "\x56\x41\x4c\x50"},
	{ct_gzip2a, 4, "\x52\x53\x50\x47"},
	{ct_gzip2c, 4, "\x41\x52\x5f\x5f"},
	{ct_gzip2c, 4, "\x41\x52\x5f\x5E"},
	{ct_bzip3, 4, "\x41\x52\x5f\x32"},
	{ct_bzip3, 4, "\x41\x52\x5f\x5d"},
	{ct_lzop2, 4, "\x41\x52\x5f\x53"},
	{ct_lz5, 4, "\x41\x52\x5f\x56"},
	{ct_brotli2, 4, "\x41\x52\x5f\x55"},
	{ct_compress2, 4, "\x41\x52\x5f\x54"},
};

#define NMAGIC (sizeof(magic) / sizeof(magic[0]))

/**
 * Tar related function, version 1.34
 *
 */
enum compress_type
check_compressed_archive(bool *pshort)
{
	struct zip_magic const *p;
	bool sfr;
	bool temp;
	strcpy(record_start->buffer, "<no data$$$>"); //hack by BW

	if (!pshort)
		pshort = &temp;

	/* Prepare global data needed for find_next_block: */
	record_end = record_start; /* set up for 1st record = # 0 */
	sfr = read_full_records;
	read_full_records = true; /* Suppress fatal error on reading a partial
	                             record */
	*pshort = find_next_block() == 0;

	if (0 == strcmp("<no data$$$>", record_start->buffer)) //hack by BW
	{
		FILE *my_file_z = _wfopen(permissive_name_m_(amanda_utf8towide_1_(archive_name_array_filename)), L"rb");

		if (my_file_z)
		{
			memset(record_start->buffer, 0, 7);
			fread(record_start->buffer, 1, 7, my_file_z);
			fclose(my_file_z);
			goto next_step_z;
		}
	}

	/* Restore global values */
	read_full_records = sfr;

	if (record_start != record_end /* no files smaller than BLOCKSIZE */
		&& (strcmp(record_start->header.magic, TMAGIC) == 0 || strcmp(record_start->buffer + offsetof(struct posix_header,
																									  magic),
																	  OLDGNU_MAGIC) == 0) &&
		tar_checksum(record_start, true) == HEADER_SUCCESS)
		/* Probably a valid header */
		return ct_tar;
next_step_z:;
	for (p = magic + 2; p < magic + NMAGIC; p++)
		if (memcmp(record_start->buffer, p->magic, p->length) == 0)
		{
			return p->type;
		}
	return ct_none;
}

/**
 * Tar related function, version 1.34
 *
 */
void flush_read(void)
{
	flush_read_ptr();
}

/**
 * Tar related function, version 1.34, slightly modified
 *
 */
void open_archive(enum access_mode wanted_access)
{
	flush_read_ptr = gnu_flush_read;
	flush_write_ptr = gnu_flush_write;
	_open_archive(wanted_access);
	if (fatal_exit_k)
	{
		return;
	}
	switch (wanted_access)
	{
	case ACCESS_READ:
	case ACCESS_UPDATE:
		break;
	case ACCESS_WRITE:
		records_written = 0;
		break;
	}
}

/**
 * Required function for a standard windows DLL
 *
 */
int __stdcall DllMain(__attribute__((unused)) HANDLE hModule, DWORD ul_reason_for_call, __attribute__((unused)) LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString("BW Tar DLL ;-) "
						  " - DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__
						  ") "
						  " _amanda_debug_ \n");
		break;

	case DLL_THREAD_ATTACH:
		break;

	case DLL_THREAD_DETACH:
		break;

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
/**
 * To know whether the list process is running
 *
 */
int __stdcall IsListRunning(void)
{
	return running_2_ar;
}
/**
 * To get the return value for the list process
 *
 */
int __stdcall GetReturnValueFromList(void)
{
	return return_value_from_list;
}

char tar_file_ar_real[AMANDA__SIZE];
/**
 * To retrieve the last error message, all errors have a description that can help debug the problem
 *
 */
void __stdcall get_error_message(char *data_ar)
{
	strcpy(data_ar, error_message_k);
}

int __stdcall list_tar_file_ar(char *tar_file_ar);
bool modo_e_duplo_ar = false;
char copy_for_extract_ar[AMANDA__SIZE];

/**
 * This function is called by the thread initializer, for list process
 *
 */
int __stdcall startapi_ar_2(__attribute__((unused)) int parameter) //for list process thread...
{
	int is_multi_volume_p;
	static char temp_tar_file_in_temp_path[AMANDA__SIZE];
	cores_used_z = 1;
	memset(copy_for_extract_ar, 0, sizeof(copy_for_extract_ar));
	modo_e_duplo_ar = false;
	return_value_from_list = 0;

	init_rsp_arp_encrypt_arp();

	is_multi_volume_p = detect_multi_volume_p(tar_file_ar_real, temp_tar_file_in_temp_path);

	if (0 == is_multi_volume_p)
	{
		if (!mode_is_libarchive_list_p)
			return_value_from_list = process_tar(0, tar_file_ar_real, list_function_ar_ok);
		else
		{
			pedro_dprintf(-1, "7");
			dllinit_arp();

			{

				get_tar_info_p_func(
					&Isdir_k,
					&Second_k,
					&Minute_k,
					&Hour_k,
					&Year_k,
					&Month_k,
					&Day_k,
					&Size_k,
					filename_k,
					&Numdir_k,
					&Numfiles_k,
					typeflag_ar);

				return_value_from_list = libarchive_list_entries_p_func(tar_file_ar_real, the_pass_arp, list_function_ar_ok, error_message_k, string_format_arp);
			}
		}
	}
	else if (1 == is_multi_volume_p)
	{
		if (!mode_is_libarchive_list_p)
			return_value_from_list = process_tar(0, temp_tar_file_in_temp_path, list_function_ar_ok);
		else
		{
			dllinit_arp();
	
			{
				get_tar_info_p_func(
					&Isdir_k,
					&Second_k,
					&Minute_k,
					&Hour_k,
					&Year_k,
					&Month_k,
					&Day_k,
					&Size_k,
					filename_k,
					&Numdir_k,
					&Numfiles_k,
					typeflag_ar);

				return_value_from_list = libarchive_list_entries_p_func(temp_tar_file_in_temp_path, the_pass_arp, list_function_ar_ok, error_message_k, string_format_arp);
			}
		}
		_wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_tar_file_in_temp_path)));
	}
	else
	{
		return_value_from_list = is_multi_volume_p;
	}
	pedro_dprintf(-1, "is multi volume2 %d\n", (int)is_multi_volume_p);
pedro_dprintf(-1, "13");
	running_2_ar = 0;
	mode_is_libarchive_list_p = false;
	return 0;
}
/**
 * This function is called when a thread is initialized, for an extraction process
 *
 */
int __stdcall startapi_ar_3(__attribute__((unused)) int parameter) //extract call function...
{
	int is_multi_volume_p;
	static char temp_tar_file_in_temp_path[AMANDA__SIZE];
	cores_used_z = 1;
	modo_e_duplo_ar = true;
	memset(copy_for_extract_ar, 0, sizeof(copy_for_extract_ar));
	return_value_from_list = 0;

	init_rsp_arp_encrypt_arp();

	is_multi_volume_p = detect_multi_volume_p(tar_file_ar_real, temp_tar_file_in_temp_path);

	if (0 == is_multi_volume_p)
	{
		if (!mode_is_libarchive_extract_p)
			return_value_from_list = process_tar(1, tar_file_ar_real, extract_function_ar_ok);
		else
		{
			dllinit_arp();

			{
				return_value_from_list = libarchive_extract_entries_p_func(tar_file_ar_real, the_pass_arp, extract_function_ar_ok, error_message_k, string_format_arp, extract_folder_final, extracting_filename_ar, warning_info, creating_folder_maria, &extract_pause__flag, &extract_cancel_flag, &folders_ar, &files_ar);
			}
		}
	}
	else if (1 == is_multi_volume_p)
	{
		if (!mode_is_libarchive_extract_p)
			return_value_from_list = process_tar(1, temp_tar_file_in_temp_path, extract_function_ar_ok);
		else
		{
			dllinit_arp();

			{
				return_value_from_list = libarchive_extract_entries_p_func(temp_tar_file_in_temp_path, the_pass_arp, extract_function_ar_ok, error_message_k, string_format_arp, extract_folder_final, extracting_filename_ar, warning_info, creating_folder_maria, &extract_pause__flag, &extract_cancel_flag, &folders_ar, &files_ar);
			}
		}

		_wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_tar_file_in_temp_path)));
	}
	else
	{
		return_value_from_list = is_multi_volume_p;
	}

	running_2_ar = 0;
	modo_e_duplo_ar = false;
	mode_is_libarchive_extract_p = false;
	return 0;
}

/**
 * New support function to libarchive, to be used with version 5.3.8 and above<br>
 * For the moment the formats that are disable due to bugs are rar and rar5<br>
 * Soon these formats will be enabled, we only need to track down these problems<br>
 * If the format is not supported an error will occur<br>
 * Notice that the formats that are handled correctly for the moment are the<br>
 * formats that libarchive can create<br>
 * But you can check whether the not tested formats are working correctly<br>
 * Soon all formats supported by libarchive will be fully tested, the<br>
 * major problem is the handling of Unicode windows characters<br>
 *
 * @param tar_file_ar the tar or other format file, cannot be relative, it need<br>
 * to be a complete path<br>
 *
 * @return 0 if no error, or an error otherwise<br>
 *
 */
int __stdcall libarchive_list_tar_file_ar(
	char *tar_file_ar)
{
	mode_is_libarchive_list_p = true;
	pedro_dprintf(-1, "1");
	return list_tar_file_ar(tar_file_ar);
}

/**
 * This function will list the information for a given Tar file
 *
 */
int __stdcall list_tar_file_ar(char *tar_file_ar)
{
	if (AMANDA__SIZE < strlen(tar_file_ar))
	{
		mode_is_libarchive_list_p = false;
		return 2;
	}
	if (running_2_ar)
	{
		mode_is_libarchive_list_p = false;
		return 1;
	}
	if (false == check_valid_path_i(tar_file_ar))
	{
		return 3;
	}

	extract_pause__flag = false;
	extract_cancel_flag = false;

	running_2_ar = 1;
pedro_dprintf(-1, "2");
	strncpy_z(tar_file_ar_real, tar_file_ar, AMANDA__SIZE);

	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;
pedro_dprintf(-1, "3");
	myhandle = CreateThread((LPSECURITY_ATTRIBUTES)0,
							(SIZE_T)0,
							(void *)startapi_ar_2,
							(LPVOID)parameter,
							(DWORD)0,
							(LPDWORD)&ThreadId);
	CloseHandle(myhandle);
	return 0;
}
/**
 * It will pause the extraction process
 *
 */
int __stdcall ExtractPause_ar(void)
{
	if (pause_lzip_aakp_lzip_ar_func)
	{
		pause_lzip_aakp_lzip_ar_func();
		PauseExecution_gzip_ar_func();
		PauseCompress_bzip2_ar_func();
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
	extract_pause__flag = true;
	if (global_ptr_our_map_arp_v27)
	{
		global_ptr_our_map_arp_v27->pause____arp = 1;
	}
	init_rsp_arp_encrypt_arp();
	PauseExecution__arp_func();
	return 0;
}
/**
 * It will resume the extraction process
 *
 */
int __stdcall ExtractResume_ar(void)
{
	if (resume_lzip_aakp_lzip_ar_func)
	{
		resume_lzip_aakp_lzip_ar_func();
		ResumeExecution_gzip_ar_func();
		ResumeCompress_bzip2_ar_func();
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
	if (global_ptr_our_map_arp_v27)
	{
		global_ptr_our_map_arp_v27->pause____arp = 0;
	}
	init_rsp_arp_encrypt_arp();
	ResumeExecution_arp_func();
	extract_pause__flag = false;
	return 0;
}
/**
 * This function is required to explode a string by delimiters, a Linux fnmatch like function requires it
 *
 */
char *
strsep(char **stringp, const char *delim)
{
	char *begin, *end;
	begin = *stringp;
	if (begin == NULL)
		return NULL;
	/* Find the end of the token.  */
	end = begin + strcspn(begin, delim);
	if (*end)
	{
		/* Terminate the token and set *STRINGP past NUL character.  */
		*end++ = '\0';
		*stringp = end;
	}
	else
		/* No more delimiters; this is the last token.  */
		*stringp = NULL;
	return begin;
}

/**
 * It will cancel the extraction process
 *
 */
int __stdcall ExtractCancel_ar(void)
{
	if (cancel_lzip_aakp_lzip_ar_func)
	{
		cancel_lzip_aakp_lzip_ar_func();
		CancelExecution_gzip_ar_func();
		CancelCompress_bzip2_ar_func();
		cancel_lzip_aakp_lzip_ar_func();
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
	if (global_ptr_our_map_arp_v27)
	{
		global_ptr_our_map_arp_v27->cancel___arp = 1;
	}
	init_rsp_arp_encrypt_arp();
	CancelExecution_arp_func();
	extract_cancel_flag = true;
	return 0;
}
/**
 * It will extract the tar file 'tar_file_ar' an utf-8 encoded file
 *
 * @param tar_file_ar the tar file
 *
 * @param destination_folder_ar the destination path, if it doesnot exist it will be created
 *
 * @return 1 or 2 on error, 0 otherwise
 */
int __stdcall extract_tar_file_ar(char *tar_file_ar, char *destination_folder_ar)
{
	if (AMANDA__SIZE < strlen(tar_file_ar))
	{
		mode_is_libarchive_extract_p = false;
		return 2;
	}
	if (AMANDA__SIZE < strlen(destination_folder_ar))
	{
		mode_is_libarchive_extract_p = false;
		return 2;
	}
	if (running_2_ar)
	{
		mode_is_libarchive_extract_p = false;
		return 1;
	}
	if (false == check_valid_path_i(tar_file_ar) || false == check_valid_path_i(destination_folder_ar))
	{
		return 3;
	}

	running_2_ar = 1;
	last_list_error_int_arp = 0;
	memset(last_list_error_message_arp, 0, sizeof(last_list_error_message_arp));
	extract_pause__flag = false;
	extract_cancel_flag = false;
	strncpy_z(tar_file_ar_real, tar_file_ar, AMANDA__SIZE);
	strncpy_z(extract_folder_final, destination_folder_ar, AMANDA__SIZE);
	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;
	myhandle = CreateThread((LPSECURITY_ATTRIBUTES)0,
							(SIZE_T)0,
							(void *)startapi_ar_3,
							(LPVOID)parameter,
							(DWORD)0,
							(LPDWORD)&ThreadId);

	CloseHandle(myhandle);
	return 0;
}
/**
 * Version 5.3.8 and above have the embedded libarchive (https://libarchive.org) on it<br>
 * then it supports many other formats that Parolin cannot handle like zip, 7zip, cab<br>
 * Notice that rar and rar5 are disabled for the moment due to buggy handling of Unicode<br>
 * characters, it will be reenabled in the future<br>
 * The formats that libarchive can create are very well tested and are the suggested<br>
 * formats to be used at this moment<br>
 *
 * @param tar_file_ar the compressed file to extract, if not supported an error will be<br>
 * raised<br>
 * Need to be a complete path (not relative)<br>
 * Anyway an error will be returned in case of problems<br>
 *
 * @param destination_folder_ar the destination folder, if it doesnot exist it will be created<br>
 * Cannot be relative<br>
 *
 * @return 0 if no error, an error otherwise, see the C# sample project<br>
 *
 */
int __stdcall libarchive_extract_tar_file_ar(char *tar_file_ar, char *destination_folder_ar)
{
	mode_is_libarchive_extract_p = true;
	return extract_tar_file_ar(tar_file_ar, destination_folder_ar);
}

/**
 * It will return a slice of 10000 for the percentage between max and
 * fatia, 100% == 10000, it is required to  the progress information to be smooth
 *
 * @param max : the maximum value
 *
 * @param fatia : the slice of the max value
 */
int getpor_10000_int64_t_ar(int64_t max, int64_t fatia)
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
 * It will return the progress of the list process, 0 for the moment
 *
 * @return 0 for the moment
 *
 */
int __stdcall GetListProgress_ar(void)
{
	return 0; //for the moment...
}

/**
 * It will retrieve the extraction progress
 *
 * @return the value that can be a slice of 0 to 10000, 10000 == 100%
 *
 */
int __stdcall GetExtrationProgress_ar(void)
{
	int ret_ar;

	if (mode_is_libarchive_extract_p)
	{

		if (progress_extract_i_func)
		{

			ret_ar = progress_extract_i_func();

			return ret_ar;
		}
		return 10000;
	}

	if (global_ptr_our_map_arp_v27)
	{
		assert(0 && "Don't handle iso files anymore in Parolin");
		/*
		   static int old_value_arp = 0;
		   if (time_point_arp_2 < GetTickCount())
		   {
		        old_value_arp = global_ptr_our_map_arp_v27->progress_arp;
		        time_point_arp_2 = GetTickCount() + 50;
		        return old_value_arp;
		   }
		   return old_value_arp;
		 */
	}
	ret_ar = getpor_10000(numero_de_itens, processed_itens_ar);
	if (0 > ret_ar)
	{
		ret_ar = 0;
	}
	if (10000 < ret_ar)
	{
		ret_ar = 10000;
	}
	return ret_ar;
}

char temp_tar_file_ar[AMANDA__SIZE];
bool flag_to_delete_temp_ar = false;

/**
 * It will return the Tar format of the loaded file
 *
 * @param format_arp the variable that will return the string
 * with the format description, it is very informative
 *
 */
int __stdcall get_tar_format_arp(char *format_arp)
{
	strcpy(format_arp, string_format_arp);
	return 0;
}

/**
 * It will check whether the file if encrypted, only work
 * for Tar files since VAL files already have the information
 * about encryption embedded on it, only Tar files don&apos;t have
 * a standard way to know whether it is encrypted
 *
 * @return the return values goes in the global variables is_mislaine_encrypted_ and
 * encryption_method_arp
 *
 */
void check_mislaine_encrypted(void)
{
	char buf_amanda[1];
	char header_end_arp[300] = {0};
	int64_t file_size_arp;
	FILE *amanda_file;
	file_size_arp = getfilesize_ar(archive_name_array_filename);
	if (8 < file_size_arp)
	{
		amanda_file = _wfopen(permissive_name_m_(amanda_utf8towide_1_(archive_name_array_filename)), L"rb");
		if (amanda_file)
		{
			encryption_method_arp = ARP_AES;
			fseek(amanda_file, file_size_arp - 5, SEEK_SET);
			fread(buf_amanda, 1, 1, amanda_file);
			if (ARP_RC4 == buf_amanda[0])
			{
				encryption_method_arp = ARP_RC4;
			}
			if (ARP_SERPENT == buf_amanda[0])
			{
				encryption_method_arp = ARP_SERPENT;
			}
			if (ARP_MARS == buf_amanda[0])
			{
				encryption_method_arp = ARP_MARS;
			}
			if (ARP_RC6 == buf_amanda[0])
			{
				encryption_method_arp = ARP_RC6;
			}
			if (ARP_TWOFISH == buf_amanda[0])
			{
				encryption_method_arp = ARP_TWOFISH;
			}
			fseek(amanda_file, file_size_arp - 4, SEEK_SET);
			fread(header_end_arp, 1, 4, amanda_file);
			if (0 == strcmp("misl", header_end_arp)) //misl comes from Mislaine, my first daughther...
			{
				is_mislaine_encrypted_ = true;
			}
			else
			{
				;
			}
			fclose(amanda_file);
		}
	}
}
/**
 * If the file is compressed by one of the 16 compressors supported
 * this function will return the progress of the initial uncompression
 * call
 *
 * @return the 0 to 10000 value referred to the progress, 10000 == 100%, as you may guess
 *
 */
int __stdcall Initial_Progress_z(void)
{
	if (-1 == decompression_progress_mode_arp)
	{
		if (keep_temp_file_flag_z)
		{
			if (is_encrypted_by_extension) //almost irrelevant...
				return internal_progress_z() / 2;
			return internal_progress_z();
		}
		return 10000;
	}
	switch (decompression_progress_mode_arp)
	{
	case AAKP_MODE_GZIP:
		if (GetProgress_gzip_ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)GetProgress_gzip_ar_func() * 100.0) / 2.0);
			}
			return GetProgress_gzip_ar_func() * 100;
		}

		return 10000;
		break;

	case AAKP_MODE_BZ2:
		if (GetProgress_bzip2_ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)GetProgress_bzip2_ar_func() * 100.0) / 2.0);
			}
			return GetProgress_bzip2_ar_func() * 100;
		}
		return 10000;
		break;

	case AAKP_MODE_BZIP3:
		if (get_progress_b3___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_b3___ar_func()) / 2.0);
			}
			return get_progress_b3___ar_func();
		}
		return 10000;
		break;

	case AAKP_MODE_LZOP2:
		if (get_progress_l3___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_l3___ar_func()) / 2.0);
			}
			return get_progress_l3___ar_func();
		}
		return 10000;
	case AAKP_MODE_LZ5:
		if (get_progress_l5___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_l5___ar_func()) / 2.0);
			}
			return get_progress_l5___ar_func();
		}
		return 10000;
	case AAKP_MODE_BROTLI2:
		if (get_progress_bb___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_bb___ar_func()) / 2.0);
			}
			return get_progress_bb___ar_func();
		}
		return 10000;
		break;
	case AAKP_MODE_COMPRESS2:
		if (get_progress_c5___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_c5___ar_func()) / 2.0);
			}
			return get_progress_c5___ar_func();
		}
		return 10000;
		break;
	case AAKP_MODE_LZIP:
		if (get_progress_lzip_ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_lzip_ar_func()) / 2.0);
			}
			return get_progress_lzip_ar_func();
		}
		break;
	case AAKP_MODE_LZMA:
		if (get_progress_lzma_ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_lzma_ar_func()) / 2.0);
			}
			return get_progress_lzma_ar_func();
		}
		break;
	case AAKP_MODE_XZ:
		if (get_progress_xz___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_xz___ar_func()) / 2.0);
			}
			return get_progress_xz___ar_func();
		}
		break;
	case AAKP_MODE_COMPRESS:
		if (get_progress_co___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_co___ar_func()) / 2.0);
			}
			return get_progress_co___ar_func();
		}
		break;
	case AAKP_MODE_LZOP:
		if (get_progress_ju___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_ju___ar_func()) / 2.0);
			}
			return get_progress_ju___ar_func();
		}
		break;
	case AAKP_MODE_LZ4:
		if (get_progress_l4___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_l4___ar_func()) / 2.0);
			}
			return get_progress_l4___ar_func();
		}
		break;
	case AAKP_MODE_ZSTANDARD:
		if (get_progress_zs___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_zs___ar_func()) / 2.0);
			}
			return get_progress_zs___ar_func();
		}
		break;
	case AAKP_MODE_BROTLI:
		if (get_progress_br___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_br___ar_func()) / 2.0);
			}
			return get_progress_br___ar_func();
		}
		break;
	case AAKP_MODE_GZIP2:
		if (get_progress_g2___ar_func)
		{
			if (keep_temp_file_flag_z)
			{
				return 5000 + ((int)(double)((double)get_progress_g2___ar_func()) / 2.0);
			}
			return get_progress_g2___ar_func();
		}
		break;
	}
	return 10000;
}

/**
 * (not in use anymore because now libarchive handles iso) 
 *  It will set the iso mode, valid values for iso_mode_arp are:<br>
 *  ARP_MODE_ISO9660,<br>
 *  ARP_MODE_JOLIET,<br>
 *  ARP_MODE_ROCK_RIDGE,
 *  ARP_MODE_JOLIET_PLUS_ROCK_RIDGE<br>and <br>
 *  ARP_MODE_UDF,<br>recommended ARP_MODE_JOLIET_PLUS_ROCK_RIDGE see wikipedia
 *  to learn more about possible iso modes
 *
 * @return always 0
 *
 */
int __stdcall set_iso_settings(int iso_mode)
{
	iso_mode_value = iso_mode;
	return 0;
}

/**
 * (Not in use anymore) 
 * This function will list or extract an iso file
 *
 * @param true_if_it_is_extract_ar 1 if it is extract, 0 if it is list process
 *
 * @param tar_file_ar the iso file utf-8 encoded
 *
 * @return 0 if ok, non 0 if an error occur, see the function that
 * get the error message for the function
 *
 */
int __stdcall process_iso(int true_if_it_is_extract_ar, char *tar_file_ar)
{
	files_ar = 0;
	folders_ar = 0;
	Numdir_k = 0;
	Numfiles_k = 0;
	my_func_ar_(AAKP_CLEAR);
	DWORD exit_code_arp;
	char command_line_arp[1024];
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	assert(4 == sizeof(DWORD));
	char copy_arp[1024];
	char list_file__S2_arp[1024] = {0};
	char extract_file__S2_arp[1024] = {0};
	char get_data_arp[1024];
	char my_command_call_arp[1024];
	int pos_arp;
	char *token, *str, *tofree;
	int copy_itens_arp;
	int found_arp = 0;
	int internal_is_dir_arp = 0;
	int rnd_z;
	struct my_struct_for_list_ar_is_amanda_update_ *aak_ptr;
	strcpy(string_format_arp, "iso");
	time_point_arp_2 = 0;

	while (clean_list_itens_is_list_())
	{
		;
	}

	while (clean_list_itens_is_amanda_update_())
	{
		;
	}
	//modified April/10/2021

	strcpy(error_message_k, "iso9660 was disable so the mkisofs executables and cygwin DLL is not required anymore, use libarchive instead");
	return 27999;

	assert(0 == has_itens_is_amanda_update_);
	assert(0 == has_itens_copy_is_amanda_update_);
#define BUF_SIZE_ARP sizeof(our_map_arp)
	char szName_arp[1024] = "amanda_e_ricardo_map_v27";

	fatal_exit_k = 0;
	rnd_z = 1000000000;
	rnd_z = get_rand(0, rnd_z);
	sprintf(szName_arp + strlen(szName_arp), "_%d", rnd_z);

	if (true_if_it_is_extract_ar)
	{
		trocadordebackslashtras(extract_folder_final);
		if (strlen(extract_folder_final) && '\\' != extract_folder_final[strlen(extract_folder_final) - 1])
		{
			strcat(extract_folder_final, "\\");
		}
		rspmakedir(extract_folder_final);
	}

	hMapFile_arp = CreateFileMapping(
		INVALID_HANDLE_VALUE, // use paging file
		NULL,				  // default security
		PAGE_READWRITE,		  // read/write access
		0,					  // maximum object size (high-order DWORD)
		BUF_SIZE_ARP,		  // maximum object size (low-order DWORD)
		szName_arp);		  // name of mapping object

	if (NULL == hMapFile_arp)
	{
		sprintf(copy_arp, "Could not create file mapping object (%d)",
				(int)GetLastError());

		strcpy(error_message_k, copy_arp);
		return 28006;
	}

	global_ptr_our_map_arp_v27 = (our_map_arp *)MapViewOfFile(hMapFile_arp,		   // handle to map object
															  FILE_MAP_ALL_ACCESS, // read/write permission
															  0,
															  0,
															  BUF_SIZE_ARP);

	if (NULL == global_ptr_our_map_arp_v27)
	{
		sprintf(copy_arp, "Could not map view of file (%d)",
				(int)GetLastError());
		strcpy(error_message_k, copy_arp);
		CloseHandle(hMapFile_arp);
		return 28007;
	}

	memset(&global_our_map_arp, 0, sizeof(global_our_map_arp));
	CopyMemory((PVOID)global_ptr_our_map_arp_v27, &global_our_map_arp, BUF_SIZE_ARP);
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	switch (iso_mode_value)
	{
	case ARP_MODE_ISO9660:
		strcpy(my_command_call_arp, "be_isoinfo_cygwin64.exe -X -i \"");
		break;

	case ARP_MODE_JOLIET:
		strcpy(my_command_call_arp, "be_isoinfo_cygwin64.exe -J -X -i \"");
		break;

	case ARP_MODE_ROCK_RIDGE:
		strcpy(my_command_call_arp, "be_isoinfo_cygwin64.exe -R -X -i \"");
		break;

	case ARP_MODE_JOLIET_PLUS_ROCK_RIDGE:
		strcpy(my_command_call_arp, "be_isoinfo_cygwin64.exe -R -X -i \"");
		break;

	case ARP_MODE_UDF:
		strcpy(my_command_call_arp, "be_isoinfo_cygwin64.exe -X -i \"");
		break;

	default:
		strcpy(my_command_call_arp, "be_isoinfo_cygwin64.exe -J -X -i \"");
		break;
	}

	if (true_if_it_is_extract_ar)
	{
		rspgettemppath_arp(extract_file__S2_arp);
		strcpy(global_ptr_our_map_arp_v27->extract_file_arp, extract_file__S2_arp);
		strcpy(command_line_arp, my_command_call_arp);
		strcat(command_line_arp, tar_file_ar);
		strcat(command_line_arp, "\" -e \"");
		strcat(command_line_arp, extract_folder_final);
		strcat(command_line_arp, "\" ");
	}
	else
	{
		rspgettemppath_arp(list_file__S2_arp);
		strcpy(command_line_arp, my_command_call_arp);
		strcat(command_line_arp, tar_file_ar);
		strcat(command_line_arp, "\" -l \"");
		strcat(command_line_arp, list_file__S2_arp); //to modify
		strcat(command_line_arp, "\" ");
	}

	sprintf(command_line_arp + strlen(command_line_arp), "%s", szName_arp);

	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW;

	if (!CreateProcess(NULL, command_line_arp, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		sprintf(copy_arp, "Could not start executable 'be_isoinfo_cygwin64.exe' (%d)",
				(int)GetLastError());

		strcpy(error_message_k, copy_arp);
		UnmapViewOfFile(global_ptr_our_map_arp_v27);
		CloseHandle(hMapFile_arp);
		global_ptr_our_map_arp_v27 = NULL;
		return 28008;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	GetExitCodeProcess(pi.hProcess, &exit_code_arp);
	UnmapViewOfFile(global_ptr_our_map_arp_v27);
	CloseHandle(hMapFile_arp);
	global_ptr_our_map_arp_v27 = NULL;
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	if (strlen(list_file__S2_arp))
	{
		FILE *my_arp_file;
		my_arp_file = _wfopen(amanda_utf8towide_1_(list_file__S2_arp), L"rb");

		if (my_arp_file)
		{
			while (fgets(get_data_arp, 1024, my_arp_file))
			{
				if (2 < strlen(get_data_arp))
				{
					pos_arp = 0;
					tofree = str = strdup(get_data_arp); // We own str's memory now.
					while ((token = strsep(&str, "<")))
					{
						my_VAL_data_arp.VAL_is_encrypted = 0;
						if (0 == pos_arp)
						{
							strcpy(my_VAL_data_arp.VAL_filename, token);
							found_arp = 0;
							aak_ptr = aak_inicio_is_amanda_update_;
							copy_itens_arp = has_itens_is_amanda_update_;
							while (copy_itens_arp--)
							{
								if (0 == strcmp(my_VAL_data_arp.VAL_filename, aak_ptr->filename_k))
								{
									found_arp++;
									break;
								}
								aak_ptr = aak_ptr->next_ar;
							}
							if (0 == found_arp)
							{
								add_more_one_is_amanda_update_(
									my_VAL_data_arp.VAL_filename,
									0,
									0,
									0,
									0,
									0,
									0,
									0,
									NULL);
							}
						}
						if (1 == pos_arp)
						{
							my_VAL_data_arp.VAL_is_dir = 1;
							if (0 == strcmp("file", token))
							{
								my_VAL_data_arp.VAL_is_dir = 0;
							}
							else
							{
								strcat(my_VAL_data_arp.VAL_filename, "/");
							}
						}
						if (2 == pos_arp)
						{
							;
						}
						if (3 == pos_arp)
						{
							my_VAL_data_arp.VAL_timestamp64 = strtoll(token, NULL, 10);
						}
						if (4 == pos_arp)
						{
							my_VAL_data_arp.VAL_file_size = strtoll(token, NULL, 10);
						}
						pos_arp++;
					}
					free(tofree);
					if (!found_arp)
					{
						simple_print_header_iso();
					}
				}
			}
			fclose(my_arp_file);
		}
		_wunlink(amanda_utf8towide_1_(list_file__S2_arp));
		assert(0 == ispathfile(list_file__S2_arp));
	}
	if (strlen(extract_file__S2_arp))
	{
		FILE *my_arp_file;
		my_arp_file = _wfopen(amanda_utf8towide_1_(extract_file__S2_arp), L"rb");

		if (my_arp_file)
		{
			while (fgets(get_data_arp, 1024, my_arp_file))
			{
				if (2 < strlen(get_data_arp))
				{
					int achou_arp = 0;
					pos_arp = 0;
					tofree = str = strdup(get_data_arp); // We own str's memory now.
					found_arp = 1;

					while ((token = strsep(&str, "<")))
					{
						if (0 == pos_arp)
						{
							found_arp = 0;
							aak_ptr = aak_inicio_is_amanda_update_;
							copy_itens_arp = has_itens_is_amanda_update_;
							while (copy_itens_arp--)
							{
								if (0 == strcmp(token, aak_ptr->filename_k))
								{
									found_arp++;
									achou_arp = 1;
									break;
								}
								aak_ptr = aak_ptr->next_ar;
							}
							if (0 == found_arp)
							{
								add_more_one_is_amanda_update_(
									token,
									0,
									0,
									0,
									0,
									0,
									0,
									0,
									NULL);
							}
						}
						if (1 == pos_arp)
						{
							if (0 == strcmp(" ", token))
							{
								warning_info[0] = 0;
							}
							else
							{
								fatal_exit_k = 120;
								strcpy(error_message_k, "At least one warning occurred, see the ListBox to see what is it");
								strcpy(warning_info, token);
							}
						}
						if (2 == pos_arp)
						{
							if (0 == strcmp(" ", token))
							{
								extracting_filename_ar[0] = 0;
							}
							else
							{
								strcpy(extracting_filename_ar, token);
							}
						}
						if (3 == pos_arp)
						{
							if (0 == strcmp(" ", token))
							{
								internal_is_dir_arp = 0;
								creating_folder_maria[0] = 0;
							}
							else
							{
								internal_is_dir_arp = 1;
								strcpy(creating_folder_maria, token);
							}
						}
						if (4 == pos_arp)
						{
							;
						}
						pos_arp++;
					}
					free(tofree);
					if (!achou_arp)
					{
						if (internal_is_dir_arp)
						{
							folders_ar++;
						}
						else
						{
							files_ar++;
						}

						my_func_ar_(AAKP_EXTRACT_PROCESS);
					}
				}
			}
			fclose(my_arp_file);
		}
		_wunlink(amanda_utf8towide_1_(extract_file__S2_arp));
		assert(0 == ispathfile(extract_file__S2_arp));
	}
	while (clean_list_itens_is_amanda_update_())
	{
		;
	}
	assert(0 == has_itens_is_amanda_update_);
	assert(0 == has_itens_copy_is_amanda_update_);
	if (exit_code_arp)
	{
		if (29 == exit_code_arp)
		{
			fatal_exit_k = 119;
			strcpy(error_message_k, "User abort");
			fatal_exit_k = 0;
			goto final_arp;
		}
		sprintf(copy_arp, "Error %d running 'be_isoinfo_cygwin64.exe'", (int)exit_code_arp);
		strcpy(error_message_k, copy_arp);
		return 28009;
	}
final_arp:;
	return fatal_exit_k;
}

/**
 * It will retrieve the CPU speed as a string
 *
 */
char *__amandacall cpu_speed_z(void)
{
	DWORD type_z = REG_SZ;
	static char speed_z[300] = {
		0,
	};
	char Buffer[_MAX_PATH];
	char Buffer_z[_MAX_PATH] = {
		0,
	};
	DWORD BufSize = 35;
	DWORD dwMHz = _MAX_PATH;
	HKEY hKey;
	if (0 != strlen(speed_z))
	{
		return speed_z;
	}
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
							   "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
							   0,
							   KEY_READ,
							   &hKey);

	if (lError != ERROR_SUCCESS)
	{
		FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,
					  NULL,
					  lError,
					  0,
					  Buffer,
					  _MAX_PATH,
					  0);
		return "<not found>";
	}
	RegQueryValueEx(hKey, "~MHz", NULL, NULL, (LPBYTE)&dwMHz, &BufSize);
	BufSize = MAX_PATH;
	RegQueryValueEx(hKey, "Identifier", NULL, &type_z, (LPBYTE)Buffer_z, &BufSize);
	sprintf(speed_z, "%ld MHz, %s", dwMHz, Buffer_z);
	RegCloseKey(hKey);
	return speed_z;
}
/**
 * It will process the tar file for list or extraction
 *
 * @param true_if_it_is_extract_ar if 0 it is list, if 1 it is extraction
 *
 * @param tar_file_ar the Tar file to process, can be Tar, VAL
 * or iso format in all 16 compression formats that are most used
 *
 * @param my_func__ the internal function for the process, not user selected
 *
 */
int __stdcall process_tar(int true_if_it_is_extract_ar, char *tar_file_ar, tar_list_function_ar my_func__)
{
	int64_t size_got_p = 0;
	static int64_t temp_long_long;
	int64_t temp_unused_var_long_long_int = 0;
	already_arp = 0;
	enum read_header status = HEADER_STILL_UNREAD;
	enum read_header prev_status;
	int ret_k;
	encryption_detected_z = -1;
	flag_to_delete_temp_ar = false;
	file_is_VAL_arp = false;
	is_mislaine_encrypted_ = false;
	decoder_file_z = NULL;
	strcpy(string_format_arp, "unknown");
	is_encrypted_by_extension = is_compressed_z(tar_file_ar);

	real_VAL_filesize = -1;

	/*
	if (
		check_iso_file_aakp(tar_file_ar))
	{
		my_func_ar_ = my_func__;
		return process_iso(true_if_it_is_extract_ar, tar_file_ar);
	}
*/

	if (0 == true_if_it_is_extract_ar)
	{
		file_size_total_int64 = getfilesize_ar(tar_file_ar);
		file_total__read_int64 = 0;
	}

	keep_temp_file_flag_z = is_encrypted_gnu_tar_arp(tar_file_ar);

	if (true_if_it_is_extract_ar)
	{
		while (clean_list_itens_is_list_())
		{
			;
		}
		numero_de_itens = 0;
		processed_itens_ar = 0;
		keep_temp_file_flag_z = is_encrypted_gnu_tar_arp(tar_file_ar);

		if (keep_temp_file_flag_z)
		{
			if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_file_for_encrypted, L"AM_"))
			{
				archive = -1;
				strcpy(error_message_k, "Cannot create temporary file");
				fatal_exit_k = 40001;
				goto saida_o_k;
			}
			strcpy(temp_file_for_encrypted_v2, temp_file_for_encrypted);
			adjust_extension_z(tar_file_ar, temp_file_for_encrypted_v2);
			if (0 != strcmp(temp_file_for_encrypted, temp_file_for_encrypted_v2))
			{
				_wrename(permissive_name_m_(amanda_utf8towide_2_(temp_file_for_encrypted)), amanda_utf8towide_1_(temp_file_for_encrypted_v2));
			}
			update_progress_arp(&temp_long_long);
			ret_arp_ = decrypt_arp(tar_file_ar, temp_file_for_encrypted_v2, the_pass_arp, &temp_unused_var_long_long_int, encryption_method__i);

			strcpy(file_to_keep_z, temp_file_for_encrypted_v2);
			strcpy(tar_file_ar, temp_file_for_encrypted_v2);
			if (0 == ret_arp_)
			{
			}
			else if (4 == ret_arp_)
			{
				archive = -1;
				strcpy(error_message_k, "Wrong password used");
				fatal_exit_k = 40003;
				goto saida_o_k;
			}
			else
			{
				archive = -1;
				strcpy(error_message_k, "Unexpected decryption error");
				fatal_exit_k = 40005;
				goto saida_o_k;
			}
		}
		ret_k = process_tar(0, tar_file_ar, list_function_ar_ok);
		if (2004 == ret_k)
		{
			archive = -1; //redundant? maybe not !!
			goto saida_o_k;
		}
	}
	if (false == modo_e_duplo_ar)
	{
		keep_temp_file_flag_z = is_encrypted_gnu_tar_arp(tar_file_ar);
		if (keep_temp_file_flag_z)
		{
			if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_file_for_encrypted, L"AM_"))
			{
				archive = -1;
				strcpy(error_message_k, "Cannot create temporary file");
				fatal_exit_k = 40001;
				goto saida_o_k;
			}
			strcpy(temp_file_for_encrypted_v2, temp_file_for_encrypted);
			adjust_extension_z(tar_file_ar, temp_file_for_encrypted_v2);
			if (0 != strcmp(temp_file_for_encrypted, temp_file_for_encrypted_v2))
			{
				_wrename(permissive_name_m_(amanda_utf8towide_2_(temp_file_for_encrypted)), amanda_utf8towide_1_(temp_file_for_encrypted_v2));
			}
			update_progress_arp(&temp_long_long);
			ret_arp_ = decrypt_arp(tar_file_ar, temp_file_for_encrypted_v2, the_pass_arp, &temp_unused_var_long_long_int, encryption_method__i);
			strcpy(file_to_keep_z, temp_file_for_encrypted_v2);
			strcpy(tar_file_ar, temp_file_for_encrypted_v2);
			if (0 == ret_arp_)
			{
			}
			else if (4 == ret_arp_)
			{
				archive = -1;
				strcpy(error_message_k, "Wrong password used");
				fatal_exit_k = 40003;
				goto saida_o_k;
			}
			else
			{
				archive = -1;
				strcpy(error_message_k, "Unexpected decryption error");
				fatal_exit_k = 40005;
				goto saida_o_k;
			}
		}
	}
	my_func_ar_ = my_func__;
	got_a_warning_ar = 0;
	if (true_if_it_is_extract_ar)
	{
		trocadordebackslashtras(extract_folder_final);
		if (strlen(extract_folder_final) && '\\' != extract_folder_final[strlen(extract_folder_final) - 1])
		{
			strcat(extract_folder_final, "\\");
		}
	}
	if (true_if_it_is_extract_ar)
	{
		if (last_list_error_int_arp)
		{
			goto final_jump_arp;
		}
	}
	Numdir_k = 0;
	Numfiles_k = 0;
	my_func_ar_(AAKP_CLEAR);
	if (1)
	{
		blocking_factor = DEFAULT_BLOCKING;
		record_size = DEFAULT_BLOCKING * BLOCKSIZE;
		record_index = 0;
		read_full_records = read_full_records_option;
		hit_eof = false;
		record_start_block = 0;
		error_message_k[0] = 0;
		fatal_exit_k = 0;
		archive = -1;
		if (true_if_it_is_extract_ar)
		{
			if (!mode_is_update_arp)
			{
				if (rspmakedir(extract_folder_final))
				{
					strcpy(error_message_k, "Invalid destination path");
					fatal_exit_k = 12;
					goto saida_o_k;
				}
			}
		}
		tar_sparse_major = 1;
		tar_sparse_minor = 0;
		strcpy(archive_name_array_filename, tar_file_ar);
		{
			static int already_k = 0;
			if (!already_k)
				base64_init();
			already_k = 2;
		}
		if (recent_global_header)
		{
			free(recent_global_header);
			recent_global_header = NULL;
		}
		if (true_if_it_is_extract_ar)
		{
			my_process_function = extract_archive;
		}
		else
			my_process_function = list_archive;
		if (true_if_it_is_extract_ar)
		{
			if (!strlen(extract_folder_final))
			{
				fatal_exit_k = 2001;
				strcpy(error_message_k, " 2001, You need to provide a destination folder");
				goto saida_o_k;
			}
		}
		if (strlen(copy_for_extract_ar) && true_if_it_is_extract_ar)
		{
			strcpy(archive_name_array_filename, copy_for_extract_ar);
		}
		open_archive(ACCESS_READ);
		if (fatal_exit_k)
		{
			if (-1 != archive)
			{
				close(archive);
				archive = -1;
			}
			if (0 == true_if_it_is_extract_ar && (ct_bzip3_k == fatal_exit_k))
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"BZ_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_BZIP3;
				ret_k = uncompress_b3___rspk_ar_func(original_file_tar,
													 archive_name_array_filename,
													 threads_z,
													 ar_gettemppath_z(),
													 &cores_used_z);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "bzip3 decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
				{
				case 0:;
					break;

				case 6:
					fatal_exit_k = 1513;
					strcpy(error_message_k, " 6 Cannot write to output file");
					break;

				case 7:
					fatal_exit_k = 1514;
					strcpy(error_message_k, "Decompression error");
					break;

				case 14:
					fatal_exit_k = 1515;
					strcpy(error_message_k, " 14 Cannot write to output file");
					break;

				case 107:
					fatal_exit_k = 1516;
					strcpy(error_message_k, "Cannot open input file");
					break;

				case 108:
					fatal_exit_k = 1517;
					strcpy(error_message_k, "Cannot open output file");
					break;

				case 119:
					fatal_exit_k = 119;
					strcpy(error_message_k, "User cancel");
					break;

				case 121:
					fatal_exit_k = 1518;
					strcpy(error_message_k, "Cannot init decompression");
					break;

				case 122:
					fatal_exit_k = 1519;
					strcpy(error_message_k, "Cannot read from input file");
					break;

				case 123:
					fatal_exit_k = 1520;
					strcpy(error_message_k, "md5 checksum error");
					break;

				case 124:
					fatal_exit_k = 1521;
					strcpy(error_message_k, "Unexpected error ;-) ");
					break;

				case 125:
					fatal_exit_k = 1522;
					strcpy(error_message_k, "Memory error");
					break;

				case 126:
					fatal_exit_k = 1523;
					strcpy(error_message_k, "Invalid bzip3 stream");
					break;

				case 198:
					fatal_exit_k = 1524;
					strcpy(error_message_k, "Header magic error");
					break;

				case 199:
					fatal_exit_k = 1525;
					strcpy(error_message_k, "Invalid bzip3 file");
					break;

				case 300:
					fatal_exit_k = 1526;
					strcpy(error_message_k, "sha512 checksum error");
					break;

				case 500:
					fatal_exit_k = 1527;
					strcpy(error_message_k, "Invalid multi-thread bzip3 file");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor and"
														" not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}
			if (0 == true_if_it_is_extract_ar && (ct_lzop2_k == fatal_exit_k))
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"L2_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_LZOP2;
				ret_k = uncompress_l3___rspk_ar_func(original_file_tar,
													 archive_name_array_filename,
													 threads_z,
													 ar_gettemppath_z(),
													 &cores_used_z);
				decompression_progress_mode_arp = -1;
				switch (ret_k)
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

				case 407:
					fatal_exit_k = 1116;
					strcpy(error_message_k, "Cannot create temp file");
					break;

				case 405:
					fatal_exit_k = 1117;
					strcpy(error_message_k, "Cannot open output tempfile");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor "
														"and not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);
					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}
					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && (ct_lz5_k == fatal_exit_k))
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"L5_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_LZ5;
				ret_k = uncompress_l5___rspk_ar_func(original_file_tar,
													 archive_name_array_filename,
													 threads_z,
													 ar_gettemppath_z(),
													 &cores_used_z);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lz5 decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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

				case 403:
					fatal_exit_k = 1116;
					strcpy(error_message_k, "File access error");
					break;

				case 500:
					fatal_exit_k = 1116;
					strcpy(error_message_k, "Internal Error 500");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor "
														"and not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}
			if (0 == true_if_it_is_extract_ar && (ct_brotli2_k == fatal_exit_k))
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"BB_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_BROTLI2;
				ret_k = uncompress_bb___rspk_ar_func(original_file_tar,
													 archive_name_array_filename,
													 threads_z,
													 ar_gettemppath_z(),
													 &cores_used_z);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "brotli2 decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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

				case 199:
					fatal_exit_k = 1116;
					strcpy(error_message_k, "Invalid file signature for a brotli2 file");
					break;

				case 403:
					fatal_exit_k = 1117;
					strcpy(error_message_k, "File access error");
					break;

				case 500:
					fatal_exit_k = 1118;
					strcpy(error_message_k, "Invalid compressed file");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor "
														"and not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && (ct_compress2_k == fatal_exit_k))
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;

				strcpy(original_file_tar, archive_name_array_filename);

				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"C2_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);

				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_COMPRESS2;
				ret_k = uncompress_c5___rspk_ar_func(original_file_tar,
													 archive_name_array_filename,
													 threads_z,
													 ar_gettemppath_z(),
													 &cores_used_z);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "compress2 decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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

				case 407:
					fatal_exit_k = 1116;
					strcpy(error_message_k, "Cannot create temp file");
					break;

				case 405:
					fatal_exit_k = 1117;
					strcpy(error_message_k, "Cannot open output tempfile");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor "
														"and not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && (ct_gzip2a_k == fatal_exit_k || ct_gzip2c_k == fatal_exit_k))
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;

				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"G2_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_GZIP2;
				ret_k = uncompress_g2___rspk_ar_func(original_file_tar,
													 archive_name_array_filename,
													 threads_z,
													 ar_gettemppath_z(),
													 &cores_used_z);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "gzip2 decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
				{
				case 0:;
					break;

				case 9:
					fatal_exit_k = 1411;
					strcpy(error_message_k, "Cannot read from input file");
					break;

				case 10:
					fatal_exit_k = 1412;
					strcpy(error_message_k, "Cannot open input file");
					break;

				case 11:
					fatal_exit_k = 1413;
					strcpy(error_message_k, "Cannot open output file");
					break;

				case 14:
					fatal_exit_k = 1414;
					strcpy(error_message_k, "Cannot write to output file");
					break;

				case 15:
					fatal_exit_k = 1415;
					strcpy(error_message_k, "md5 checksum error");
					break;

				case 18:
					fatal_exit_k = 1416;
					strcpy(error_message_k, "Unexpected error");
					break;

				case 19:
					fatal_exit_k = 119;
					strcpy(error_message_k, "User cancel");
					break;

				case 20:
					fatal_exit_k = 1418;
					strcpy(error_message_k, "sha512 checksum error");
					break;

				case 21:
					fatal_exit_k = 1419;
					strcpy(error_message_k, "zlib stream error");
					break;

				case 90:
					fatal_exit_k = 1420;
					strcpy(error_message_k, "Not a valid gzip2 file");
					break;

				case 500:
					fatal_exit_k = 1421;
					strcpy(error_message_k, "Invalid gzip2 multi-thread file");
					break;

				case 501:
					fatal_exit_k = 1422;
					strcpy(error_message_k, "File access error reading input file");
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
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor "
														"and not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_gzip_k == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"GZ_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_GZIP;
				ret_k = Uncompress_gzip_ar_func(original_file_tar, archive_name_array_filename);
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "gzip decompression required %.3f seconds\n", inittimer2(1));
				while (0 == GetFinished_gzip_ar_func())
				{
					file_size_total_int64 = 0, file_total__read_int64 = 0;
					Sleep(50);
				}
				decompression_progress_mode_arp = -1;
				ret_k = GetReturnValue_gzip_ar_func();
				switch (ret_k)
				{
				case 0:;
					break;

				case 10:
					fatal_exit_k = 91;
					strcpy(error_message_k, "Cannot open file to read");
					break;

				case 11:
					fatal_exit_k = 91;
					strcpy(error_message_k, "Cannot open file to write");
					break;

				case 19:
					fatal_exit_k = 92;
					strcpy(error_message_k, "User abort");
					break;

				case 15:
					fatal_exit_k = 93;
					strcpy(error_message_k, "Internal gzip error");
					break;
				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor "
														"and not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_bzip2_k == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"B2_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);

				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_BZ2;
				ret_k = Decompress_bzip2_ar_func(original_file_tar, archive_name_array_filename);
				while (GetStatus_bzip2_ar_func())
				{
					file_size_total_int64 = 0, file_total__read_int64 = 0;
					Sleep(5);
				}
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "bzip2 decompression required %.3f seconds\n", inittimer2(1));
				decompression_progress_mode_arp = -1;
				ret_k = GetReturnValue_bzip2_ar_func();
				switch (ret_k)
				{
				case 0:;
					break;

				case 8:
					fatal_exit_k = 110;
					strcpy(error_message_k, "Cannot open file to read");
					break;

				case 14:
					fatal_exit_k = 111;
					strcpy(error_message_k, "Cannot read from file");
					break;

				case 9:
					fatal_exit_k = 112;
					strcpy(error_message_k, "Cannot open file to write");
					break;

				case 12:
					fatal_exit_k = 113;
					strcpy(error_message_k, "Internal bzip2 error");
					break;

				case 15:
					fatal_exit_k = 114;
					strcpy(error_message_k, "Internal error reading from bzip2 file");
					break;

				case 13:
					fatal_exit_k = 115;
					strcpy(error_message_k, "Internal error in bzip2");
					break;

				case 119:
					fatal_exit_k = 116;
					strcpy(error_message_k, "User abort");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor "
														"and not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_lzip_k == fatal_exit_k)
			{
				static char original_file_tar[1024];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"LZ_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_LZIP;
				ret_k = uncompress_lzip_rspk_ar_func(original_file_tar, archive_name_array_filename);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lzip decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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
					fatal_exit_k = 305;
					strcpy(error_message_k, "User abort");
					break;
				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor and "
														"not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_lzma_k /*it is LZMA ok ....*/ == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"LM_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0); //o otimizador de Curitiba
				decompression_progress_mode_arp = AAKP_MODE_LZMA;
				ret_k = uncompress_lzma_rspk_ar_func(original_file_tar, archive_name_array_filename);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lzma decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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
					fatal_exit_k = 604;
					strcpy(error_message_k, "User abort");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor "
														"and not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_xz_k == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"XZ_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0); //o otimizador de Curitiba
				decompression_progress_mode_arp = AAKP_MODE_XZ;
				ret_k = uncompress_xz___rspk_ar_func(original_file_tar, archive_name_array_filename);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "xz decompression required %.3f seconds\n", inittimer2(1));

				switch (ret_k)
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
					fatal_exit_k = 711;
					strcpy(error_message_k, "User abort");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor and "
														"not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_compress_k == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;

				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"CO_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_COMPRESS;
				ret_k = uncompress_co___rspk_ar_func(original_file_tar, archive_name_array_filename);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "compress decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor and "
														"not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_lzop_k == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;

				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"LP_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0); //o otimizador de Curitiba
				decompression_progress_mode_arp = AAKP_MODE_LZOP;
				ret_k = uncompress_ju___rspk_ar_func(original_file_tar, archive_name_array_filename);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lzop decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor and "
														"not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_lz4_k == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;

				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"L4_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);
				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0); //o otimizador de Curitiba
				decompression_progress_mode_arp = AAKP_MODE_LZ4;
				ret_k = uncompress_l4___rspk_ar_func(original_file_tar, archive_name_array_filename);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "lz4 decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor and "
														"not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_zstd_k == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"ZS_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);

				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();
				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_ZSTANDARD;
				ret_k = uncompress_zs___rspk_ar_func(original_file_tar, archive_name_array_filename);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "Zstandard decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor and "
														""
														"not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			if (0 == true_if_it_is_extract_ar && ct_brotli_k == fatal_exit_k)
			{
				static char original_file_tar[AMANDA__SIZE];
				file_size_total_int64 = 0, file_total__read_int64 = 0;
				fatal_exit_k = 0;
				strcpy(original_file_tar, archive_name_array_filename);
				if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_tar_file_ar, L"BR_"))
				{
					strcpy(error_message_k, "Cannot create temporary file");
					fatal_exit_k = 30100;

					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}

				strcpy(copy_for_extract_ar, temp_tar_file_ar);

				strcpy(archive_name_array_filename, temp_tar_file_ar);
				flag_to_delete_temp_ar = true;
				dllinit_arp();

				if (fatal_exit_k)
				{
					if (-1 != archive)
					{
						close(archive);
						archive = -1;
					}
					goto saida_o_k;
				}
				inittimer2(0);
				decompression_progress_mode_arp = AAKP_MODE_BROTLI;
				ret_k = uncompress_br___rspk_ar_func(original_file_tar, archive_name_array_filename);
				decompression_progress_mode_arp = -1;
				pedro_dprintf(SHOW_DEBUG_SPEED_Z, "brotli decompression required %.3f seconds\n", inittimer2(1));
				switch (ret_k)
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

				case 119:
					fatal_exit_k = 119;
					strcpy(error_message_k, "User abort");
					break;

				default:
					sprintf(my_error_as_a_programmer_z, "Error %d reported by the decompressor and "
														"not handled correctly by the programmer",
							ret_k);
					strcpy(error_message_k, my_error_as_a_programmer_z);
					fatal_exit_k = ret_k;
				}

				if (0 == fatal_exit_k)
				{
					open_archive(ACCESS_READ);

					if (fatal_exit_k)
					{
						if (-1 != archive)
						{
							close(archive);
							archive = -1;
						}
						goto saida_o_k;
					}

					goto vai_em_frente_ar;
				}
			}

			goto saida_o_k;
		}

	vai_em_frente_ar:;
		keep_temp_file_flag_z = false;

		if (-1 != encryption_detected_z)
		{
			is_mislaine_encrypted_ = true;
			encryption_method_arp = encryption_detected_z;
		}

		if (!file_is_VAL_arp)
		{
			if (my_process_function == list_archive)
			{
				if (-1 == encryption_detected_z)
					check_mislaine_encrypted();
			}
			do
			{
				prev_status = status;
				tar_stat_destroy(&current_stat_info);
				status = read_header(&current_header, &current_stat_info,
									 read_header_auto);
#if 0
				switch (status)
				{
				case HEADER_STILL_UNREAD:
					pedro_dprintf(2, "HEADER_STILL_UNREAD %d\n", status);
					break;

				case HEADER_SUCCESS_EXTENDED:
					pedro_dprintf(2, "HEADER_SUCCESS_EXTENDED %d\n", status);
					break;

				case HEADER_SUCCESS:
					pedro_dprintf(2, "HEADER_SUCCESS %d\n", status);
					break;

				case HEADER_ZERO_BLOCK:
					pedro_dprintf(2, "HEADER_ZERO_BLOCK %d\n", status);
					break;

				case HEADER_FAILURE:
					pedro_dprintf(2, "HEADER_FAILURE %d\n", status);
					break;

				case HEADER_END_OF_FILE:
					pedro_dprintf(2, "HEADER_END_OF_FILE %d\n", status);
					break;

				default:
					pedro_dprintf(2, "default\n");
					break;
				}
#endif

				switch (status)
				{
				case HEADER_STILL_UNREAD:
				case HEADER_SUCCESS_EXTENDED:
					goto exit_now_k;

				case HEADER_SUCCESS:

					/* Valid header.  We should decode next field (mode) first.
					   Ensure incoming names are null terminated.  */
					decode_header(current_header, &current_stat_info,
								  &current_format, 1);
					if (0)
					{
						switch (current_header->header.typeflag)
						{
						case GNUTYPE_VOLHDR:
						case GNUTYPE_MULTIVOL:
							break;

						case DIRTYPE:
							FALLTHROUGH;

						default:
							skip_member();
							continue;
						}
					}

					if (!already_arp)
					{
						//encryption_method__i[0] = 0;
						strcpy(string_format_arp, archive_format_string(detected_format_arp));

						already_arp++;
					}

					if (true_if_it_is_extract_ar)
					{
						processed_itens_ar++;
					}

					my_process_function();

					if (2004 == fatal_exit_k)
					{
						goto exit_now_k;
					}

					if (10002 == fatal_exit_k)
					{
						goto exit_now_k;
					}

					if (28000 == fatal_exit_k) //wrong password
					{
						goto exit_now_k;
					}
					if (28001 == fatal_exit_k) //Unexpected
					{
						goto exit_now_k;
					}

					if (extract_cancel_flag)
					{
						strcpy(error_message_k, "User abort");
						fatal_exit_k = 3001; //can change to 119? , I don't know...
						goto exit_now_k;
					}

					continue;

				case HEADER_ZERO_BLOCK:
					set_next_block_after(current_header);

					if (1)
					{

						status = read_header(&current_header, &current_stat_info,
											 read_header_auto);
						if (status == HEADER_ZERO_BLOCK)
							break;
						break;
					}
					status = prev_status;
					continue;

				case HEADER_END_OF_FILE:
					break;

				case HEADER_FAILURE:
					/* If the previous header was good, tell them that we are
					   skipping bad ones.  */
					set_next_block_after(current_header);
					switch (prev_status)
					{
					case HEADER_STILL_UNREAD:

						pedro_dprintf(2, "This does not look like a tar archive");

						FALLTHROUGH;

					case HEADER_ZERO_BLOCK:
					case HEADER_SUCCESS:

						pedro_dprintf(2, "Skipping to next header");

						break;

					case HEADER_END_OF_FILE:
					case HEADER_FAILURE:
						/* We are in the middle of a cascade of errors.  */
						break;

					case HEADER_SUCCESS_EXTENDED:
						assert(0 && "can never occur");
					}
					continue;
				}
				break;
			} while (1);

		exit_now_k:;
		}
		else
		{

			size_got_p = getfilesize_ar(archive_name_array_filename);

			decoder_file_z = _wfopen(permissive_name_m_(amanda_utf8towide_1_(archive_name_array_filename)), L"rb");
			if (NULL == decoder_file_z)
			{
				strcpy(error_message_k, "Cannot open VAL file for read");
				fatal_exit_k = 40005;
				goto exit_now_k_VAL;
			}

			init_decoder_z = 1;
			//encryption_method__i[0] = 0;
			strcpy(string_format_arp, "VAL");
			while (1)
			{
				int ret_arp;
				memset(my_VAL_data_arp.VAL_filename, 0, sizeof(my_VAL_data_arp.VAL_filename));
				memset(my_VAL_data_arp.VAL_filename_v27_v51, 0, sizeof(my_VAL_data_arp.VAL_filename_v27_v51));
				ret_arp = decode_VAL_arp(&my_VAL_data_arp);
				if (ARP_NOMORE == ret_arp)
				{
					break;
				}
				else
				{
					if (true_if_it_is_extract_ar)
					{
						processed_itens_ar++;
						if (my_VAL_data_arp.VAL_is_dir)
						{
							if (0 != my_VAL_data_arp.VAL_filename_v27_v51[0])
							{
								extract_dir_VAL(my_VAL_data_arp.VAL_filename_v27_v51);
							}
							else
							{
								extract_dir_VAL(my_VAL_data_arp.VAL_filename);
							}
						}
						else
						{
							if (0 != my_VAL_data_arp.VAL_filename_v27_v51[0])
							{
								extract_file_VAL(my_VAL_data_arp.VAL_filename_v27_v51);
							}
							else
							{
								extract_file_VAL(my_VAL_data_arp.VAL_filename);
							}
						}
					}
					else
					{
						simple_print_header_VAL();
						if (my_VAL_data_arp.VAL_file_size)
						{
							_fseeki64(
								decoder_file_z,
								my_VAL_data_arp.VAL_file_size,
								SEEK_CUR);
						}
					}

#if 1 != ARP_ALLOW_MULTIPLE_PASSWORDS_
					if (28000 == fatal_exit_k) //wrong password
					{
						goto exit_now_k_VAL;
					}
					if (28001 == fatal_exit_k) //Unexpected
					{
						goto exit_now_k_VAL;
					}
#endif
					if (extract_cancel_flag)
					{
						strcpy(error_message_k, "User abort");
						fatal_exit_k = 3001; //can change to 119? , I don't know...
						goto exit_now_k_VAL;
					}
				}
			}
		}

	exit_now_k_VAL:;

		if (decoder_file_z)
		{
			fclose(decoder_file_z);
			decoder_file_z = NULL;
		}

		if (-1 != real_VAL_filesize)
		{
			if (size_got_p < real_VAL_filesize)
			{
				strcpy(error_message_k, "Unexpected end of file found");
				fatal_exit_k = 5131;
			}
			if (size_got_p > real_VAL_filesize)
			{
				strcpy(error_message_k, "Size of the VAL file donï¿½t match the header");
				fatal_exit_k = 5132;
			}
		}
		else
		{
			pedro_dprintf(-1, "arquivo VAL antigo ou tar file\n");
		}
	}

saida_o_k:;

	if (-1 != archive)
	{
		close_archive();
		archive = -1;
	}

	if (fatal_exit_k)
	{
		Numdir_k = 0;
		Numfiles_k = 0;
	}

	if (0 == fatal_exit_k)
	{
		if (got_a_warning_ar)
		{
			strcpy(error_message_k, "At least one warning occurred, see the listbox to see why");
			fatal_exit_k = 105;
		}
	}

	if (fatal_exit_k)
	{
		Numdir_k = 0;
		Numfiles_k = 0;
	}

final_jump_arp:;

	if (flag_to_delete_temp_ar)
	{
		if (false == modo_e_duplo_ar)
		{
			_wunlink(permissive_name_m_(amanda_utf8towide_1_(archive_name_array_filename)));
		}
	}

	if (false == modo_e_duplo_ar)
	{
		if (strlen(file_to_keep_z))
		{
			_wunlink(permissive_name_m_(amanda_utf8towide_1_(file_to_keep_z)));
			file_to_keep_z[0] = 0;
		}
	}

	if (true_if_it_is_extract_ar)
	{

		//so aqui...

		strcat(string_format_arp, encryption_method__i);
		encryption_method__i[0] = 0;
		if (last_list_error_int_arp)
		{
			fatal_exit_k = last_list_error_int_arp;
			strcpy(error_message_k, last_list_error_message_arp);
		}
		if (strlen(copy_for_extract_ar))
		{
			_wunlink(permissive_name_m_(amanda_utf8towide_1_(copy_for_extract_ar)));
			memset(copy_for_extract_ar, 0, sizeof(copy_for_extract_ar));
		}
		if (strlen(file_to_keep_z))
		{
			_wunlink(permissive_name_m_(amanda_utf8towide_1_(file_to_keep_z)));
			file_to_keep_z[0] = 0;
		}
	}
	if (fatal_exit_k)
		last_list_error_int_arp = fatal_exit_k,
		strcpy(last_list_error_message_arp, error_message_k); //que que ï¿½ isto cara?...

	//encryption_method__i[0] = 0;

	return fatal_exit_k;
}

#endif

int __stdcall update_archive_ar_v2_internal(char *tar_filename_ar,
											char *path_with_the_files_ar,
											char *patern_ar,
											int compression_mode_external_ar,
											int recurse_in_subfolders_arp,
											enum mode_is_include_or_exclude the__patern_ar__mode);

int __stdcall startapi_ar_6(int parameter);

static char tar_filename_ar___[AMANDA__SIZE] = {
	0,
};
static char path_with_the_files_ar___[AMANDA__SIZE] = {
	0,
};
char patern_ar___[20000] = {
	0,
};
int compression_mode_external_ar___;
int recurse_in_subfolders_arp___;
enum mode_is_include_or_exclude the__patern_ar__mode___;

/**
 * This is the function to update a Tar file (or VAL) with new entries or deletion of entries
 *
 * @param tar_filename_ar the Tar (or VAL) file to update
 *
 * @return 0 if no error, if not the error and a string with the
 * description of the error can be accessed, after a call to this function
 * you need to call GetStatus_ar() to wait for the end of the execution and
 * and GetReturnValue_ar() to know whether the update occurred without
 * problems and if problems occurred you can call get_error_message to get
 * the error information
 *
 */
int __stdcall update_archive_ar_v2(char *tar_filename_ar,
								   char *path_with_the_files_ar,
								   char *patern_ar,
								   int compression_mode_external_ar,
								   int recurse_in_subfolders_arp,
								   enum mode_is_include_or_exclude the__patern_ar__mode)
{
	if (MAX_PATH < strlen(tar_filename_ar))
	{
		mode_is_libarchive_update_i = false;
		return 2;
	}
	if (MAX_PATH < strlen(path_with_the_files_ar))
	{
		mode_is_libarchive_update_i = false;
		return 2;
	}
	if (19999 < strlen(patern_ar))
	{
		mode_is_libarchive_update_i = false;
		return 2;
	}

	if (running_update || running_2_ar || running_ar)
	{
		mode_is_libarchive_update_i = false;
		return 4;
	}

	HANDLE myhandle;
	MYCAST ThreadId;
	MYCAST parameter = 1;

	running_update = 1;

	strncpy_z(tar_filename_ar___, tar_filename_ar, AMANDA__SIZE);
	strncpy_z(path_with_the_files_ar___, path_with_the_files_ar, AMANDA__SIZE);
	strncpy_z(patern_ar___, patern_ar, 19999);
	compression_mode_external_ar___ = compression_mode_external_ar;
	recurse_in_subfolders_arp___ = recurse_in_subfolders_arp;
	the__patern_ar__mode___ = the__patern_ar__mode;

	myhandle = CreateThread((LPSECURITY_ATTRIBUTES)0,
							(SIZE_T)0,
							(void *)startapi_ar_6,
							(LPVOID)parameter,
							(DWORD)0,
							(LPDWORD)&ThreadId);

	CloseHandle(myhandle);

	return 0;
}

/**
 * This is the function to update a libarchive based file with new entries
 *
 * @param tar_filename_ar the compressed file to update
 *
 * @param path_with_the_files_ar the folder from where the files will be read
 *
 * @param patern_ar the files or wildcards to use for file selection<br>
 * to include all .ini and .txt files use "*.ini *.txt", I am sure that you<br>
 * understood
 *
 * @param compression_mode_external_ar the compression method to be used<br>
 * For the moment the allowed values are:<br>
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
 *
 * @param recurse_in_subfolders_arp whether it will recurse on subfolders
 *
 * @param the__patern_ar__mode whether it will include the files or exclude it<br>
 * based on the argument "patern_ar"
 *
 * @param compression_level_char_i_ the compression level to be used<br>
 * for standard compression level use "6"
 *
 * @return 0 if no error, if not the error and a string with the
 * description of the error can be accessed, after a call to this function
 * you need to call GetStatus_ar() to wait for the end of the execution and
 * and GetReturnValue_ar() to know whether the update occurred without
 * problems and if problems occurred you can call get_error_message to get
 * the error information
 *
 */
int __stdcall libarchive_update_archive_ar_v2(char *tar_filename_ar,
											  char *path_with_the_files_ar,
											  char *patern_ar,
											  int compression_mode_external_ar,
											  int recurse_in_subfolders_arp,
											  enum mode_is_include_or_exclude the__patern_ar__mode,
											  char *compression_level_char_i_)
{

	mode_is_libarchive_update_i = true;
	strcpy(compression_level_char_i, compression_level_char_i_);
	return update_archive_ar_v2(tar_filename_ar,
								path_with_the_files_ar,
								patern_ar,
								compression_mode_external_ar,
								recurse_in_subfolders_arp,
								the__patern_ar__mode);
}

int set_folder_time(char *in_folder_i, char *out_folder_i)
{
	HANDLE hFile;
	FILETIME lpCreationTime___jumior;
	FILETIME lpLastAccessTime_junior;
	FILETIME lpLastWriteTime__junior;

	hFile =
		CreateFileW(permissive_name_m_(amanda_utf8towide_1_(in_folder_i)),
					/*
		               GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
		               NULL,
		               OPEN_EXISTING,
		               FILE_FLAG_BACKUP_SEMANTICS,
		               NULL);
		             */
					/*
		               GENERIC_READ,
		                  FILE_SHARE_READ, NULL,
		                  OPEN_EXISTING,
		                  0,
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
			{

				{

					HANDLE hFile2;

					{

						hFile2 =
							CreateFileW(permissive_name_m_(amanda_utf8towide_1_(out_folder_i)),
										GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
										NULL,
										OPEN_EXISTING,
										FILE_FLAG_BACKUP_SEMANTICS,
										NULL);

						if (INVALID_HANDLE_VALUE != hFile2)
						{
							SetFileTime(hFile2,
										&lpCreationTime___jumior,
										&lpLastAccessTime_junior,
										&lpLastWriteTime__junior);
							CloseHandle(hFile2);
						}
						else
						{
							pedro_dprintf(2, "Cannot set filetime on folder\n");
						}
					}
				}
			}
		}
		else
		{
			pedro_dprintf(2, "Cannot access timestamp\n");
		}

		CloseHandle(hFile);
	}
	else
	{
		//pedro_dprintf(2, "Cannot get filetime on folder\n");

		pedro_dprintf(2, "Cannot get filetime on file or folder %s\n", in_folder_i);

	} //

	return 0;
}

int file_copy_i(char *input_i, char *out_put_i)
{

#define AMANDA_SIZE___ (1 << 17)
	int len_i;
	int len_2_i;
	int returnvalue_i = 2;
	char *buf_i = malloc(AMANDA_SIZE___);
	FILE *out_i;
	FILE *in_i = _wfopen(permissive_name_m_(amanda_utf8towide_1_(input_i)), L"rb");

	if (in_i)
	{

		out_i = _wfopen(permissive_name_m_(amanda_utf8towide_1_(out_put_i)), L"wb");

		if (out_i)
		{
			while ((len_i = fread(buf_i, 1, AMANDA_SIZE___, in_i)))
			{
				len_2_i = fwrite(buf_i, 1, len_i, out_i);
				if (len_2_i != len_i)
				{
					returnvalue_i = 1;
				}
			}
			if (2 == returnvalue_i)
			{
				returnvalue_i = 0;
			}
			fclose(out_i);
		}
		fclose(in_i);
	}
	free(buf_i);

	if (0 == returnvalue_i)
	{
		set_folder_time(input_i, out_put_i);
		//don`t need two calls anymore...set_folder_time(input_i, out_put_i);
	}
	return returnvalue_i;
}

bool check_temp_folder_passed_i(char *temp_folder_i, char *new_entry_i)
{

	static char copy_amanda_pereira[AMANDA__SIZE] = {0};
	static char copy_amanda_pereira_2[AMANDA__SIZE] = {0};

	if (strlen(temp_folder_i) == strlen(new_entry_i))
	{
		if (0 == strcmp(temp_folder_i, new_entry_i))
		{

			return false;
		}
	}

	if (strlen(new_entry_i) >= strlen(temp_folder_i) + 1)
	{

		strcpy(copy_amanda_pereira, temp_folder_i);
		strcat(copy_amanda_pereira, "\\");
		//ready...
		memcpy(copy_amanda_pereira_2, new_entry_i, strlen(copy_amanda_pereira));

		assert(strlen(copy_amanda_pereira_2) == strlen(copy_amanda_pereira));

		if (0 == strcmp(copy_amanda_pereira, copy_amanda_pereira_2))
		{
			return false;
		}
	}

	return true;
}

bool true_if_include_i = false;

bool delete_if_true_i = false;

char global_temp_folder_i[1027];

#include "enum_files_and_folders_1.c"

bool ScanFolder(char *lpcszFolder_ar, __attribute__((unused)) int first_call, bool recurse_i) //return value is irrelevant...
{

#ifdef DEBUG_MICROSOFT_AMANDA_S_SMART_APE_______LIKE_PEDRO_VALUE__

#if DEBUG_MICROSOFT_AMANDA_S_SMART_APE_______LIKE_PEDRO_VALUE__ > -1
	//assert(0 && " my love ape entering...");
	//test_amanda_and_ricardo();

	amanda_s_smart_ape(lpcszFolder_ar, recurse_i, I_MODE_IS_SCANFOLDER);

	return true;
#endif

#endif

	return true;
}

/**
 * Internal libarchive based function, see libarchive_update_archive_ar_v2
 *
 */
int __stdcall libarchive_update_archive_ar_v2_internal(char *tar_filename_ar,
													   char *path_with_the_files_ar,
													   char *patern_ar,
													   int compression_mode_external_ar,
													   int recurse_in_subfolders_arp,
													   enum mode_is_include_or_exclude the__patern_ar__mode)
{

	static char temp_folder_i[AMANDA__SIZE];
	int i_z;
	int ret_value_arp = 0;
	int returnvalue_i = 0;
	int folders_ar = 0;
	int files_ar = 0;

	init_rsp_arp_encrypt_arp();
	dllinit_arp();

	my___temp_file_i = NULL;

	files_that_cannot_be_read_update = 0;

	//exit(1);

	mode_is_libarchive_update_i = false;

	if (AMANDA__SIZE < strlen(tar_filename_ar))
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

	if (!ispathfile(tar_filename_ar))
	{

		//running_ar = 1;
		return libarchive_create_archive_ar_v2(tar_filename_ar,
											   path_with_the_files_ar,
											   patern_ar,
											   compression_mode_external_ar,
											   recurse_in_subfolders_arp,
											   the__patern_ar__mode,
											   compression_level_char_i);
	}

	if (-1 == ret_value_arp) //compiler happy during development...
	{

		return 27;
	}
	//aqui?..., sim

	/*

   primeiro cria um diretorio no temp...

   temp_$$$ ta bom

 */
	progress_is_libarchive_v27 = true;
	progress_lib_v27 = 0;
	//multiple chunks are not supported
	split_compressed_file_p(0); //to zero it

	strcpy(error_message_k, "My Error 11");

	strcpy(temp_folder_i, ar_gettemppath_z());

	strcat(temp_folder_i, "temp_$$$");

	//tem que criar o diretorio e copiar

	//criar o cï¿½digo

	strcpy(global_patern_ar, "*");
	true_if_include_i = true;
	delete_if_true_i = true;

	strcpy(global_temp_folder_i, temp_folder_i);

	//ScanFolder(temp_folder_i, 1);

	delete_if_true_i = false;

	extract_pause__flag = false;
	extract_cancel_flag = false;

	dllinit_arp();

	/*
	   aqui tem que iniciar a adicao de cï¿½digo
	 */

	if (createtempfilename_and_keep_z(ar_gettemppath_z(), temp_file_update_i, L"am_"))
	{
	}
	else
	{
		strcpy(error_message_k, "Error creating temporary file, aborting...");
		returnvalue_i = 105;
		goto sai_agora_i;
	}

	//exit(27);

	extract_to_file_i_func(ar_gettemppath_z(), true, temp_file_update_i, init_playlist_z_june_24, add_more_one_z_june_24, check_item_z_june_24);

	returnvalue_i = libarchive_extract_entries_p_func(tar_filename_ar, the_pass_arp, NULL, error_message_k, string_format_arp, temp_folder_i, extracting_filename_ar, warning_info, creating_folder_maria, &extract_pause__flag, &extract_cancel_flag, &folders_ar, &files_ar);

	extract_to_file_i_func(ar_gettemppath_z(), false, temp_file_update_i, init_playlist_z_june_24, add_more_one_z_june_24, check_item_z_june_24);

	if (!returnvalue_i)
	{
		//copy the files
		strcpy(global_patern_ar, patern_ar);

		true_if_include_i = false;
		if (ARP_INCLUDE_FILES == the__patern_ar__mode)
		{
			true_if_include_i = true;
		}

		delete_if_true_i = false; //for safety

		is_update_i = true;

		my___temp_file_i = _wfopen(permissive_name_m_(amanda_utf8towide_1_(temp_file_update_i)), L"rb+");

		if (NULL == my___temp_file_i)
		{
			strcpy(error_message_k, "Error openning temporary file, aborting...");
			returnvalue_i = 106;
			goto sai_agora_i;
		}

		_fseeki64(my___temp_file_i, 0, SEEK_END);
		fatal_exit_k = 0;

		if (recurse_in_subfolders_arp)
		{
			ScanFolder(path_with_the_files_ar, 1, true);
		}
		else
		{
			ScanFolder(path_with_the_files_ar, 1, false);
		}

		if (12345100 == fatal_exit_k)
		{
			strcpy(error_message_k, "Cannot write to temporary file, aborting...");
			returnvalue_i = 107;
			goto sai_agora_i;
		}

		is_update_i = false;

		if (i_z) //to make the compiler happy...
		{
			goto now_i;
		}
	now_i:;

		if (my___temp_file_i)
		{
			fclose(my___temp_file_i);
			my___temp_file_i = NULL;
		}
		//exit(27);
		//aqui basta chamar o compressor
		use_name_i = true;

		mode_is_update_libarchive_v27 = true;

		libarchive_create_archive_ar_v2(tar_filename_ar,
										temp_folder_i, //aqui...sim, vamos la
										patern_ar,
										compression_mode_external_ar,
										recurse_in_subfolders_arp,
										the__patern_ar__mode,
										compression_level_char_i);

		return 0;
	}

sai_agora_i:;

	return_value_ar = returnvalue_i;

	running_update = 0;

	if (my___temp_file_i)
	{
		fclose(my___temp_file_i);
		my___temp_file_i = NULL;
	}

	_wunlink(permissive_name_m_(amanda_utf8towide_1_(temp_file_update_i)));
	progress_is_libarchive_v27 = false;
	return 10;
}

/**
 * This function is called when the new thread for the update process is started
 *
 * @return it is 0 if no error or the return value with a string with the error information,
 * can be got with the function 'get_error_message'
 */
int __stdcall startapi_ar_6(__attribute__((unused)) int parameter)
{
	return update_archive_ar_v2_internal(tar_filename_ar___,
										 path_with_the_files_ar___,
										 patern_ar___,
										 compression_mode_external_ar___,
										 recurse_in_subfolders_arp___,
										 the__patern_ar__mode___);
}

/**
 * This is the internal function to update a Tar file (or VAL) with new entries or deletion of entries
 *
 * @param tar_filename_ar the Tar (or VAL) file to update
 *
 * @return 0 if no error, if not the error and a string with the
 * description of the error can be accessed, after a call to this function
 * you need to call GetStatus_ar() to wait for the end of the execution and
 * and GetReturnValue_ar() to know whether the update occurred without
 * problems and if problems occurred you can call get_error_message to get
 * the error information
 *
 */
int __stdcall update_archive_ar_v2_internal(char *tar_filename_ar,
											char *path_with_the_files_ar,
											char *patern_ar,
											int compression_mode_external_ar,
											int recurse_in_subfolders_arp,
											enum mode_is_include_or_exclude the__patern_ar__mode)
{
	int ret_value_arp;

	if (mode_is_libarchive_update_i)
	{
		return libarchive_update_archive_ar_v2_internal(tar_filename_ar,
														path_with_the_files_ar,
														patern_ar,
														compression_mode_external_ar,
														recurse_in_subfolders_arp,
														the__patern_ar__mode);
	}

	if (AMANDA__SIZE < strlen(tar_filename_ar))
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

	if (!ispathfile(tar_filename_ar))
	{

		//running_ar = 1;
		return create_archive_ar_v2(tar_filename_ar,
									path_with_the_files_ar,
									patern_ar,
									compression_mode_external_ar,
									recurse_in_subfolders_arp,
									the__patern_ar__mode);
	}
	else
	{
		if (
			check_iso_file_aakp(tar_filename_ar))
		{
			strcpy(error_message_k, "This version cannot update an iso file, only in the future");
			fatal_exit_k = 3;
			return_value_ar = fatal_exit_k;
			running_update = 0;
			return fatal_exit_k;
		}

		mode_is_update_arp = true;

		while (clean_list_itens_is_amanda_update_())
		{
			;
		}
		assert(0 == has_itens_is_amanda_update_);
		assert(0 == has_itens_copy_is_amanda_update_);
		if (running_2_ar || running_ar)
		{
			strcpy(error_message_k, "Already running, call cancel first");
			fatal_exit_k = 1001;
			clean_up_update_ARP();
			return_value_ar = fatal_exit_k;
			running_update = 0;
			return fatal_exit_k;
		}

		if (!createtempfilename_and_keep_z(ar_gettemppath_z(), update_filename_arp, L"UP_"))
		{
			strcpy(update_filename_arp, tar_filename_ar);
			strcat(update_filename_arp, ".$$$$$_bw_update_$$$$$.tmp");
		}
		strcpy(update_temp_dir_arp, update_filename_arp);
		strcat(update_temp_dir_arp, "_d");
		{
			our_update_file_open__arp = _wopen(permissive_name_m_(amanda_utf8towide_1_(update_filename_arp)),
											   O_BINARY | O_CREAT | O_WRONLY | O_TRUNC,
											   S_IRUSR | S_IWUSR);
			if (-1 == our_update_file_open__arp)
			{
				strcpy(error_message_k, "Cannot open temporary file to write");
				fatal_exit_k = 1002;
				clean_up_update_ARP();
				return_value_ar = fatal_exit_k;
				running_update = 0;
				return fatal_exit_k;
			}
		}

		running_2_ar = 1;
		last_list_error_int_arp = 0;
		memset(last_list_error_message_arp, 0, sizeof(last_list_error_message_arp));
		extract_pause__flag = false;
		extract_cancel_flag = false;
		strcpy(tar_file_ar_real, tar_filename_ar);
		strcpy(extract_folder_final, update_temp_dir_arp);
		startapi_ar_3(1);

		if (return_value_from_list)
		{
			clean_up_update_ARP();
			running_update = 0;
			return return_value_from_list;
		}
		has_itens_is_amanda_update_internal_b_arp = has_itens_is_amanda_update_;

		//basta zerar a flag...
		split_compressed_file_p(0);

		ret_value_arp = create_archive_ar_v2(tar_filename_ar,
											 path_with_the_files_ar,
											 patern_ar,
											 compression_mode_external_ar,
											 recurse_in_subfolders_arp,
											 the__patern_ar__mode);
		return ret_value_arp;
	}
	return 0;
}

/**
 * This function will return the temp folder being used, if not set with 
 * set_temp_folder_z it will be the user temp folder 
 *
 * @return a string with the current temp folder 
 */
char *
ar_gettemppath_z(void)
{
#ifdef Z_DEBUG__TEMP
	pedro_dprintf(2, "Usando Z_DEBUG__TEMP -> C:\\Ava\\back\\temp\n");

	if (0 == strlen(temp_folder_z))
	{
		set_temp_folder_z("C:\\Ava\\back\\temp");
	}
#endif

	if (ispathfile("c:\\Ava\\back\\my_c_file.c"))
	{
		static int counter = 0;
		show_debug_z = 0;
		counter++;
		if (25 == counter)
		{
			pedro_dprintf(2, "using internal temp folder for debug \n");
			counter = 0;
		}
		if (0 == strlen(temp_folder_z))
		{
			set_temp_folder_z("C:\\Ava\\back\\temp");
		}
	}

	if (0 == strlen(temp_folder_z))
	{
		static WCHAR out_z[AMANDA__SIZE_w + 1];
		GetTempPathW(AMANDA__SIZE_w, out_z);
		strcpy(temp_folder_z, valquiria_wide_to_utf8(out_z));
	}

	return temp_folder_z;
}
/**
 * To set the temp folder, if the path is invalid it will return an error
 *
 * @param folder_z the new temp folder
 *
 * @return 0 if no error, or the error value (in this case 1)
 *
 */
int __amandacall set_temp_folder_z(char *folder_z)
{
	static char copy_path[AMANDA__SIZE] = {
		0,
	};
	static char copy_path2[AMANDA__SIZE] = {
		0,
	};
	strncpy_z(copy_path, folder_z, AMANDA__SIZE);

	if ('\\' == copy_path[0] && '\\' == copy_path[1])
	{
		goto ok_z;
	}
	if ('a' <= tolower(copy_path[0]) && 'z' >= tolower(copy_path[0]))
	{
		if (':' == copy_path[1] && ('\\' == copy_path[2] || '/' == copy_path[2]))
			goto ok_z;
	}

	return 1;

ok_z:;

	trocadordebackslashtras(copy_path);

	ret_arp_ = strlen(copy_path);

	if ('\\' != copy_path[ret_arp_ - 1])
	{
		strcat(copy_path, "\\");
	}

	if (createtempfilename_and_keep_z(copy_path, copy_path2, L"oi_"))
	{
		_wunlink(permissive_name_m_(amanda_utf8towide_1_(copy_path2)));
		strncpy_z(temp_folder_z, copy_path, sizeof(temp_folder_z) - 1);
		return 0;
	}
	return 1;
}
/**
 * It will return the current threads or cores decompressing a file, only
 * usefull at runtime during a extraction, notice that if the file was
 * compressed with 3 cores then it will decompress with 3 cores even if you
 * have 8 or more
 *
 * @return the cores or threads
 *
 */
int __amandacall decompression_cores_used__z(void)
{
	return cores_used_z;
}

int fixed_abs(int value_to_fix)
{

	value_to_fix = abs(value_to_fix);

	if (-2147483648 == value_to_fix)
	{
		value_to_fix = 2147483647;
	}
	return value_to_fix;
}

/**
 * It will return the amount of memory that is being used by the whole
 * application using the Tar DLL
 *
 * @param data_z the string that will receive the information
 *
 */
int __amandacall memory_usage__z(char *data_z)
{
	//#pragma message "amanda & MathMan compiling Tar DLL at " __TIME__ "..."

	/*
	 *                                                                                                       ï¿½\_(^^)_/ï¿½
	 */

	double val_z;
	PROCESS_MEMORY_COUNTERS_EX memory;
	/* Mr Do. */ GetProcessMemoryInfo(GetCurrentProcess(), (void *)&memory, sizeof(memory));
	val_z = memory.WorkingSetSize;
	val_z = val_z / 1024.0;
	val_z = val_z / 1024.0;
	sprintf(data_z, "%.3f MB", val_z);

	return 0;
}

#include "cpu_fixed_z.c"

/**
 * Randomic number generator, ar_min the min value inclusive,
 * ar_max the max value inclusive
 *
 * @param ar_min the minimum value, can be negative
 *
 * @param ar_max any value above ar_min, up to INT_MAX
 *
 * @return  the randomic number
 *
 */

#include "multi_volume_p.c"
