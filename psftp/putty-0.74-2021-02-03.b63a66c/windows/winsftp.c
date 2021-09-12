/*
 * winsftp.c: the Windows-specific parts of PSFTP and PSCP.
 */

#include <winsock2.h> /* need to put this first, for winelib builds */

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

#include <stdbool.h>

#include <process.h>

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

#ifdef WIN64
#define MYCAST __int64
#else
#define MYCAST int
#endif

int returnvalue_i = 0;
HANDLE hMapFile_arp_i = NULL;

extern int emission_error_amanda_s_smart_ape;

#pragma pack(push, 1)

typedef struct _amanda_i_
{
	char the__path_i[1024];
	char key_fingerprint_i[1024];
	int progress_arp;
	int pause____arp;
	int cancel___arp;
} our_map_arp_i;

#pragma pack(pop)

our_map_arp_i global_our_map_arp_i = {0};
our_map_arp_i *global_ptr_our_map_arp_v27_i = NULL;

extern char key_fingerprint_i[];

#include <assert.h>

#define NEED_DECLARATION_OF_SELECT

#include "putty.h"
#include "psftp.h"
#include "ssh.h"
#include "winsecur.h"

#include "helper_utilities_by_amanda_and_ricardo.c"

int position_i = 0;

int filexfer_get_userpass_input(__attribute__((unused)) Seat *seat,
								__attribute__((unused)) prompts_t *p,
								__attribute__((unused)) bufchain *input)
{
	int ret;
	ret = cmdline_get_passwd_input(p);
	if (ret == -1)
		ret = console_get_userpass_input(p);
	return ret;
}

void platform_get_x11_auth(__attribute__((unused)) struct X11Display *display,
						   __attribute__((unused)) Conf *conf)
{
	/* Do nothing, therefore no auth. */
}
const bool platform_uses_x11_unix_by_default = true;

/* ----------------------------------------------------------------------
 * File access abstraction.
 */

/*
 * Set local current directory. Returns NULL on success, or else an
 * error message which must be freed after printing.
 */
char *psftp_lcd(char *dir)
{
	char *ret = NULL;

	if (!SetCurrentDirectory(dir))
	{
		LPVOID message;
		int i;
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
						  FORMAT_MESSAGE_FROM_SYSTEM |
						  FORMAT_MESSAGE_IGNORE_INSERTS,
					  NULL, GetLastError(),
					  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
					  (LPTSTR)&message, 0, NULL);
		i = strcspn((char *)message, "\n");
		ret = dupprintf("%.*s", i, (LPCTSTR)message);
		LocalFree(message);
	}

	return ret;
}

/*
 * Get local current directory. Returns a string which must be
 * freed.
 */
char *psftp_getcwd(void)
{
	char *ret = snewn(256, char);
	size_t len = GetCurrentDirectory(256, ret);
	if (len > 256)
		ret = sresize(ret, len, char);
	GetCurrentDirectory(len, ret);
	return ret;
}

static inline uint64_t uint64_from_words(uint32_t hi, uint32_t lo)
{
	return (((uint64_t)hi) << 32) | lo;
}

#define TIME_POSIX_TO_WIN(t, ft)                                        \
	do                                                                  \
	{                                                                   \
		ULARGE_INTEGER uli;                                             \
		uli.QuadPart = ((ULONGLONG)(t) + 11644473600ull) * 10000000ull; \
		(ft).dwLowDateTime = uli.LowPart;                               \
		(ft).dwHighDateTime = uli.HighPart;                             \
	} while (0)
#define TIME_WIN_TO_POSIX(ft, t)                                    \
	do                                                              \
	{                                                               \
		ULARGE_INTEGER uli;                                         \
		uli.LowPart = (ft).dwLowDateTime;                           \
		uli.HighPart = (ft).dwHighDateTime;                         \
		uli.QuadPart = uli.QuadPart / 10000000ull - 11644473600ull; \
		(t) = (unsigned long)uli.QuadPart;                          \
	} while (0)

struct RFile
{
	HANDLE h;
};

RFile *open_existing_file(const char *name, uint64_t *size,
						  unsigned long *mtime, unsigned long *atime,
						  long *perms)
{
	HANDLE h;
	RFile *ret;

	h = CreateFileW(utf8towide(name), GENERIC_READ, FILE_SHARE_READ, NULL,
					OPEN_EXISTING, 0, 0);
	if (h == INVALID_HANDLE_VALUE)
	{
		error_value_arp = 9;
		return NULL;
	}

	ret = snew(RFile);
	ret->h = h;

	if (size)
	{
		DWORD lo, hi;
		lo = GetFileSize(h, &hi);
		*size = uint64_from_words(hi, lo);
	}

	if (mtime || atime)
	{
		FILETIME actime, wrtime;
		GetFileTime(h, NULL, &actime, &wrtime);
		if (atime)
			TIME_WIN_TO_POSIX(actime, *atime);
		if (mtime)
			TIME_WIN_TO_POSIX(wrtime, *mtime);
	}

	if (perms)
		*perms = -1;

	return ret;
}

int read_from_file(RFile *f, void *buffer, int length)
{
	DWORD read;

	if (global_ptr_our_map_arp_v27_i)
	{
		while (global_ptr_our_map_arp_v27_i->pause____arp)
		{

			Sleep(50);

			if (global_ptr_our_map_arp_v27_i->cancel___arp)
			{
				return 0;
			}
		}
		if (global_ptr_our_map_arp_v27_i->cancel___arp)
		{
			return 0;
		}
		if (0 == global_ptr_our_map_arp_v27_i->the__path_i[0])
		{

			strcpy(global_ptr_our_map_arp_v27_i->the__path_i, the__path_arp);
		}
		if (0 == global_ptr_our_map_arp_v27_i->key_fingerprint_i[0])
		{

			strcpy(global_ptr_our_map_arp_v27_i->key_fingerprint_i, key_fingerprint_i);
		}
	}

	while (intpause___aakp)
	{

		Sleep(50);

		if (intcancel__rspk)
		{
			return 0;
		}
	}

	if (intcancel__rspk)
	{
		return 0;
	}

	if (!ReadFile(f->h, buffer, length, &read, NULL))
		return -1; /* error */
	else
	{

		processado_rspk += read;

		{
			int ret_arp_;
			if ((int64_t)position_i < (int64_t)GetTickCount())
			{
				ret_arp_ = lgetpor(tamanho____aakp, processado_rspk);

				if (10000 < ret_arp_)
				{
					ret_arp_ = 10000;
				}

				if (0 > ret_arp_)
				{
					ret_arp_ = 0;
				}
				position_i = GetTickCount() + 50;

				if (global_ptr_our_map_arp_v27_i)
				{
					global_ptr_our_map_arp_v27_i->/*for your pleasure */ progress_arp = ret_arp_;
				}
			}

			if ((int64_t)GetTickCount() < (int64_t)position_i - 600) //to avoid the 49 days problem... or add 64 to it my love...
			{

				position_i = GetTickCount();
			}
		}

		return read;
	}
}

void close_rfile(RFile *f)
{
	CloseHandle(f->h);
	sfree(f);
}

struct WFile
{
	HANDLE h;
};

WFile *open_new_file(const char *name,
					 __attribute__((unused)) long perms)
{
	HANDLE h;
	WFile *ret;

	h = CreateFile(name, GENERIC_WRITE, 0, NULL,
				   CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (h == INVALID_HANDLE_VALUE)
		return NULL;

	ret = snew(WFile);
	ret->h = h;

	return ret;
}

WFile *open_existing_wfile(const char *name, uint64_t *size)
{
	HANDLE h;
	WFile *ret;

	h = CreateFile(name, GENERIC_WRITE, FILE_SHARE_READ, NULL,
				   OPEN_EXISTING, 0, 0);
	if (h == INVALID_HANDLE_VALUE)
		return NULL;

	ret = snew(WFile);
	ret->h = h;

	if (size)
	{
		DWORD lo, hi;
		lo = GetFileSize(h, &hi);
		*size = uint64_from_words(hi, lo);
	}

	return ret;
}

int write_to_file(WFile *f, void *buffer, int length)
{
	DWORD written;
	if (!WriteFile(f->h, buffer, length, &written, NULL))
		return -1; /* error */
	else
		return written;
}

void set_file_times(WFile *f, unsigned long mtime, unsigned long atime)
{
	FILETIME actime, wrtime;
	TIME_POSIX_TO_WIN(atime, actime);
	TIME_POSIX_TO_WIN(mtime, wrtime);
	SetFileTime(f->h, NULL, &actime, &wrtime);
}

void close_wfile(WFile *f)
{
	CloseHandle(f->h);
	sfree(f);
}

/* Seek offset bytes through file, from whence, where whence is
   FROM_START, FROM_CURRENT, or FROM_END */
int seek_file(WFile *f, uint64_t offset, int whence)
{
	DWORD movemethod;

	switch (whence)
	{
	case FROM_START:
		movemethod = FILE_BEGIN;
		break;
	case FROM_CURRENT:
		movemethod = FILE_CURRENT;
		break;
	case FROM_END:
		movemethod = FILE_END;
		break;
	default:
		return -1;
	}

	{
		LONG lo = offset & 0xFFFFFFFFU, hi = offset >> 32;
		SetFilePointer(f->h, lo, &hi, movemethod);
	}

	if (GetLastError() != NO_ERROR)
		return -1;
	else
		return 0;
}

uint64_t get_file_posn(WFile *f)
{
	LONG lo, hi = 0;

	lo = SetFilePointer(f->h, 0L, &hi, FILE_CURRENT);
	return uint64_from_words(hi, lo);
}

int file_type(const char *name)
{
	DWORD attr;
	attr = GetFileAttributes(name);
	/* We know of no `weird' files under Windows. */
	if (attr == (DWORD)-1)
		return FILE_TYPE_NONEXISTENT;
	else if (attr & FILE_ATTRIBUTE_DIRECTORY)
		return FILE_TYPE_DIRECTORY;
	else
		return FILE_TYPE_FILE;
}

struct DirHandle
{
	HANDLE h;
	char *name;
};

DirHandle *open_directory(const char *name, const char **errmsg)
{
	HANDLE h;
	WIN32_FIND_DATA fdat;
	char *findfile;
	DirHandle *ret;

	/* Enumerate files in dir `foo'. */
	findfile = dupcat(name, "/*");
	h = FindFirstFile(findfile, &fdat);
	if (h == INVALID_HANDLE_VALUE)
	{
		*errmsg = win_strerror(GetLastError());
		return NULL;
	}
	sfree(findfile);

	ret = snew(DirHandle);
	ret->h = h;
	ret->name = dupstr(fdat.cFileName);
	return ret;
}

char *read_filename(DirHandle *dir)
{
	do
	{

		if (!dir->name)
		{
			WIN32_FIND_DATA fdat;
			if (!FindNextFile(dir->h, &fdat))
				return NULL;
			else
				dir->name = dupstr(fdat.cFileName);
		}

		assert(dir->name);
		if (dir->name[0] == '.' &&
			(dir->name[1] == '\0' ||
			 (dir->name[1] == '.' && dir->name[2] == '\0')))
		{
			sfree(dir->name);
			dir->name = NULL;
		}

	} while (!dir->name);

	if (dir->name)
	{
		char *ret = dir->name;
		dir->name = NULL;
		return ret;
	}
	else
		return NULL;
}

void close_directory(DirHandle *dir)
{
	FindClose(dir->h);
	if (dir->name)
		sfree(dir->name);
	sfree(dir);
}

int test_wildcard(const char *name,
				  __attribute__((unused)) bool cmdline)
{
	HANDLE fh;
	WIN32_FIND_DATA fdat;

	/* First see if the exact name exists. */
	if (GetFileAttributes(name) != (DWORD)-1)
		return WCTYPE_FILENAME;

	/* Otherwise see if a wildcard match finds anything. */
	fh = FindFirstFile(name, &fdat);
	if (fh == INVALID_HANDLE_VALUE)
		return WCTYPE_NONEXISTENT;

	FindClose(fh);
	return WCTYPE_WILDCARD;
}

struct WildcardMatcher
{
	HANDLE h;
	char *name;
	char *srcpath;
};

char *stripslashes(const char *str, bool local)
{
	char *p;

	/*
	 * On Windows, \ / : are all path component separators.
	 */

	if (local)
	{
		p = strchr(str, ':');
		if (p)
			str = p + 1;
	}

	p = strrchr(str, '/');
	if (p)
		str = p + 1;

	if (local)
	{
		p = strrchr(str, '\\');
		if (p)
			str = p + 1;
	}

	return (char *)str;
}

WildcardMatcher *begin_wildcard_matching(const char *name)
{
	HANDLE h;
	WIN32_FIND_DATA fdat;
	WildcardMatcher *ret;
	char *last;

	h = FindFirstFile(name, &fdat);
	if (h == INVALID_HANDLE_VALUE)
		return NULL;

	ret = snew(WildcardMatcher);
	ret->h = h;
	ret->srcpath = dupstr(name);
	last = stripslashes(ret->srcpath, true);
	*last = '\0';
	if (fdat.cFileName[0] == '.' &&
		(fdat.cFileName[1] == '\0' ||
		 (fdat.cFileName[1] == '.' && fdat.cFileName[2] == '\0')))
		ret->name = NULL;
	else
		ret->name = dupcat(ret->srcpath, fdat.cFileName);

	return ret;
}

char *wildcard_get_filename(WildcardMatcher *dir)
{
	while (!dir->name)
	{
		WIN32_FIND_DATA fdat;

		if (!FindNextFile(dir->h, &fdat))
			return NULL;

		if (fdat.cFileName[0] == '.' &&
			(fdat.cFileName[1] == '\0' ||
			 (fdat.cFileName[1] == '.' && fdat.cFileName[2] == '\0')))
			dir->name = NULL;
		else
			dir->name = dupcat(dir->srcpath, fdat.cFileName);
	}

	if (dir->name)
	{
		char *ret = dir->name;
		dir->name = NULL;
		return ret;
	}
	else
		return NULL;
}

void finish_wildcard_matching(WildcardMatcher *dir)
{
	FindClose(dir->h);
	if (dir->name)
		sfree(dir->name);
	sfree(dir->srcpath);
	sfree(dir);
}

bool vet_filename(const char *name)
{
	if (strchr(name, '/') || strchr(name, '\\') || strchr(name, ':'))
		return false;

	if (!name[strspn(name, ".")]) /* entirely composed of dots */
		return false;

	return true;
}

bool create_directory(const char *name)
{
	return CreateDirectory(name, NULL) != 0;
}

char *dir_file_cat(const char *dir, const char *file)
{
	ptrlen dir_pl = ptrlen_from_asciz(dir);
	return dupcat(
		dir, (ptrlen_endswith(dir_pl, PTRLEN_LITERAL("\\"), NULL) || ptrlen_endswith(dir_pl, PTRLEN_LITERAL("/"), NULL)) ? "" : "\\",
		file);
}

/* ----------------------------------------------------------------------
 * Platform-specific network handling.
 */
struct winsftp_cliloop_ctx
{
	HANDLE other_event;
	int toret;
};
static bool winsftp_cliloop_pre(void *vctx, const HANDLE **extra_handles,
								size_t *n_extra_handles)
{
	struct winsftp_cliloop_ctx *ctx = (struct winsftp_cliloop_ctx *)vctx;

	if (ctx->other_event != INVALID_HANDLE_VALUE)
	{
		*extra_handles = &ctx->other_event;
		*n_extra_handles = 1;
	}

	return true;
}
static bool winsftp_cliloop_post(void *vctx, size_t extra_handle_index)
{
	struct winsftp_cliloop_ctx *ctx = (struct winsftp_cliloop_ctx *)vctx;

	if (ctx->other_event != INVALID_HANDLE_VALUE &&
		extra_handle_index == 0)
		ctx->toret = 1; /* other_event was set */

	return false; /* always run only one loop iteration */
}
int do_eventsel_loop(HANDLE other_event)
{
	struct winsftp_cliloop_ctx ctx[1];
	ctx->other_event = other_event;
	ctx->toret = 0;
	cli_main_loop(winsftp_cliloop_pre, winsftp_cliloop_post, ctx);
	return ctx->toret;
}

/*
 * Wait for some network data and process it.
 *
 * We have two variants of this function. One uses select() so that
 * it's compatible with WinSock 1. The other uses WSAEventSelect
 * and MsgWaitForMultipleObjects, so that we can consistently use
 * WSAEventSelect throughout; this enables us to also implement
 * ssh_sftp_get_cmdline() using a parallel mechanism.
 */
int ssh_sftp_loop_iteration(void)
{
	if (p_WSAEventSelect == NULL)
	{
		fd_set readfds;
		int ret;
		unsigned long now = GETTICKCOUNT(), then;
		SOCKET skt = winselcli_unique_socket();

		if (skt == INVALID_SOCKET)
			return -1; /* doom */

		if (socket_writable(skt))
			select_result((WPARAM)skt, (LPARAM)FD_WRITE);

		do
		{
			unsigned long next;
			long ticks;
			struct timeval tv, *ptv;

			if (run_timers(now, &next))
			{
				then = now;
				now = GETTICKCOUNT();
				if (now - then > next - then)
					ticks = 0;
				else
					ticks = next - now;
				tv.tv_sec = ticks / 1000;
				tv.tv_usec = ticks % 1000 * 1000;
				ptv = &tv;
			}
			else
			{
				ptv = NULL;
			}

			FD_ZERO(&readfds);
			FD_SET(skt, &readfds);
			ret = p_select(1, &readfds, NULL, NULL, ptv);

			if (ret < 0)
				return -1; /* doom */
			else if (ret == 0)
				now = next;
			else
				now = GETTICKCOUNT();

		} while (ret == 0);

		select_result((WPARAM)skt, (LPARAM)FD_READ);

		return 0;
	}
	else
	{
		return do_eventsel_loop(INVALID_HANDLE_VALUE);
	}
}

/*
 * Read a command line from standard input.
 *
 * In the presence of WinSock 2, we can use WSAEventSelect to
 * mediate between the socket and stdin, meaning we can send
 * keepalives and respond to server events even while waiting at
 * the PSFTP command prompt. Without WS2, we fall back to a simple
 * fgets.
 */
struct command_read_ctx
{
	HANDLE event;
	char *line;
};

static DWORD WINAPI command_read_thread(void *param)
{
	struct command_read_ctx *ctx = (struct command_read_ctx *)param;

	ctx->line = fgetline(stdin);

	SetEvent(ctx->event);

	return 0;
}

char *ssh_sftp_get_cmdline(const char *prompt, bool no_fds_ok)
{
	int ret;
	struct command_read_ctx ctx[1];
	DWORD threadid;
	HANDLE hThread;

	fputs(prompt, stdout);
	fflush(stdout);

	if ((winselcli_unique_socket() == INVALID_SOCKET && no_fds_ok) ||
		p_WSAEventSelect == NULL)
	{
		return fgetline(stdin); /* very simple */
	}

	/*
	 * Create a second thread to read from stdin. Process network
	 * and timing events until it terminates.
	 */
	ctx->event = CreateEvent(NULL, false, false, NULL);
	ctx->line = NULL;

	hThread = CreateThread(NULL, 0, command_read_thread, ctx, 0, &threadid);
	if (!hThread)
	{
		CloseHandle(ctx->event);
		fprintf(stderr, "Unable to create command input thread\n");
		cleanup_exit(21);
	}

	do
	{
		ret = do_eventsel_loop(ctx->event);

		/* do_eventsel_loop can't return an error (unlike
		 * ssh_sftp_loop_iteration, which can return -1 if select goes
		 * wrong or if the socket doesn't exist). */
		assert(ret >= 0);
	} while (ret == 0);

	CloseHandle(hThread);
	CloseHandle(ctx->event);

	return ctx->line;
}

void platform_psftp_pre_conn_setup(LogPolicy *lp)
{
	if (restricted_acl())
	{
		lp_eventlog(lp, "Running with restricted process ACL");
	}
}

/* ----------------------------------------------------------------------
 * Main program. Parse arguments etc.
 */
int main_int_i(int argc, char *argv[])
{
	int ret;
	//printf("oi amor\n");
	dll_hijacking_protection();
	pedro_dprintf(-1, "dentrinho %d %s\n", argc, argv[1]);
	ret = psftp_main(argc, argv);

	pedro_dprintf(-1, "ret interno\n", ret);

	return ret;
}

int argc_arp;
char **argv_arp;
int is_running_arp = 0;
int return_value_from_list_arp;
int __stdcall arp_psftp_function_internal(
	void)
{

	return main_int_i(argc_arp, argv_arp);
}

int __stdcall startapi_ar_2(__attribute__((unused)) int parameter)
{
	return_value_from_list_arp = 0;
	return_value_from_list_arp = arp_psftp_function_internal();

	if (error_value_arp)
	{
		return_value_from_list_arp = error_value_arp;
	}

	is_running_arp = 0;
	return 0;
}
int __stdcall arp_psftp_function_enter(
	int argc_arp_____,
	char *argv_arp_[])
{

	if (is_running_arp)
	{
		return 1; //already running, wait or cancel
	}
	error_value_arp = 0;
	argc_arp = argc_arp_____;
	argv_arp = argv_arp_;

	is_running_arp = 1;

	/*
	myhandle = CreateThread ((LPSECURITY_ATTRIBUTES) 0, (SIZE_T)0, (LPTHREAD_START_ROUTINE) startapi_ar_2, (LPVOID) parameter, (DWORD) 0, (LPDWORD) &ThreadId);

	CloseHandle (myhandle);
*/
	startapi_ar_2(0);

	return 0;
}

int __stdcall get_return_value_arp(void)
{
	//start from 28...

	if (emission_error_amanda_s_smart_ape)
	{
		return emission_error_amanda_s_smart_ape;
	}
	return return_value_from_list_arp;
}
int __stdcall is__running_arp(void)
{
	return is_running_arp;
}
int __stdcall pause_arp(void)
{
	intpause___aakp = 1;
	return 0;
}
int __stdcall resume_arp(void)
{
	intpause___aakp = 0;
	return 0;
}
int __stdcall cancel_arp(void)
{
	intcancel__rspk = 1;
	return 0;
}
int __stdcall get_remote_directory_pwd(char *the_path_arp)
{
	strcpy(the_path_arp, the__path_arp);
	return 0;
}
int __stdcall progress_arp(void)
{
	ret_arp_ = lgetpor(tamanho____aakp, processado_rspk);

	if (10000 < ret_arp_)
	{
		ret_arp_ = 10000;
	}

	if (0 > ret_arp_)
	{
		ret_arp_ = 0;
	}

	return ret_arp_;
}

/*
BOOL WINAPI DllMain (HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("BE PSFTP DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") \n");

#ifdef NPRINTF
		MessageBox (0, "Alladin debugging code", "BinaryWork Corp.", MB_OK | MB_TOPMOST);
#endif
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
*/

int __stdcall arp_psftp_function(
	char *remote_path_arp,
	char *user_arp,
	char *password_arp,
	char *host_arp,
	char *filename,
	__attribute__((unused)) char *filename_path)
{
	static char user_final_arp[600];
	static char password_arp2[600];

	if (is_running_arp)
	{
		return 1;
	}
	the__path_arp[0] = 0;
	item_counter_arp = 0;
	strcpy(local_file__arp, filename);
	strcpy(remote__path_arp, remote_path_arp);
	pedro_dprintf(-1, "entrou \n");

	strncpy(user_final_arp, user_arp, 100);
	strcat(user_final_arp, "@");
	strncat(user_final_arp, host_arp, 100);

	pedro_dprintf(-1, "aqui %s\n", user_final_arp);

	int ret_ar = 6;
	static char *my_main_args[6];

	if (getfilesize_aakp_plus_rspk(filename))
	{
		ret_ar = 6; //to make compiler happy
	}

	my_main_args[0] = "psftp.exe";
	my_main_args[1] = "-pw";

	strncpy(password_arp2, password_arp, 598);
	my_main_args[2] = password_arp2;
	my_main_args[3] = user_final_arp;
	my_main_args[4] = "-b";
	my_main_args[5] = "batch_arp.ava";

	pedro_dprintf(-1, "saiu 2 pass %s\n", password_arp2);

	tamanho____aakp = getfilesize_aakp_plus_rspk(filename);
	processado_rspk = 0;
	intpause___aakp = 0;
	intcancel__rspk = 0;
	return arp_psftp_function_enter(ret_ar, my_main_args);
}

int main(__attribute__((unused)) int argc_i,
		 char **argv_i)
{

	int cancel_i = 0;

	emission_error_amanda_s_smart_ape = 0;

	global_ptr_our_map_arp_v27_i = NULL;
	hMapFile_arp_i = OpenFileMapping(
		FILE_MAP_ALL_ACCESS, // read/write access
		FALSE,				 // do not inherit the name
		argv_i[1]);			 // name of mapping object

	if (NULL == hMapFile_arp_i)
	{
		pedro_dprintf(2, "Could not open file mapping object (%d)",
					  (int)GetLastError());
		return 7;
	}

	global_ptr_our_map_arp_v27_i = (our_map_arp_i *)MapViewOfFile(hMapFile_arp_i,	   // handle to map object
																  FILE_MAP_ALL_ACCESS, // read/write permission
																  0,
																  0,
																  sizeof(our_map_arp_i));

	if (NULL == global_ptr_our_map_arp_v27_i)
	{
		pedro_dprintf(2, "Could not map view of file (%d).\n",
					  GetLastError());

		CloseHandle(hMapFile_arp_i);

		return 7;
	}

	position_i = 0;

	memset(the__path_arp, 0, sizeof(the__path_arp));
	global_ptr_our_map_arp_v27_i->the__path_i[0] = 0;
	global_ptr_our_map_arp_v27_i->cancel___arp = 0;
	global_ptr_our_map_arp_v27_i->pause____arp = 0;
	global_ptr_our_map_arp_v27_i->progress_arp = 0;
	arp_psftp_function(
		argv_i[2],
		argv_i[3],
		argv_i[4],
		argv_i[5],
		argv_i[6],
		"oi amor?...");

	cancel_i = global_ptr_our_map_arp_v27_i->cancel___arp;

	UnmapViewOfFile(global_ptr_our_map_arp_v27_i);
	global_ptr_our_map_arp_v27_i = NULL;
	CloseHandle(hMapFile_arp_i);

	if (cancel_i)
	{
		return 27;
	}

	return get_return_value_arp();
}
