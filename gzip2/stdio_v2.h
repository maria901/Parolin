//2021 started at: Sun 28/February/2021 07:13:17 juliette

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

enum open_modes_z
{
     Z_MODE_IS_RB,
     Z_MODE_IS_RB_PLUS,
     Z_MODE_IS_WB
};

enum k_states_for_stdio_v27
{
     P_MODE_OK = 1001,
     P_MODE_IS_IN_ERROR,
     P_MODE_CANNOT_OPEN_INTERNAL_FILE,
};

typedef struct FILE_z__
{
     char filename_a_z[5000];
     WCHAR filename_w_z[5000];
     enum open_modes_z open_mode_int;
     FILE *internal_file_z;
     //char open_mode[20]           ;
     bool file_is_in_memory;
     enum k_states_for_stdio_v27 internal_error_m;
     char *memory_z;
     int64_t max_memory_size;
     int64_t current_file_position_z;
     int64_t end_position_z;
} FILE_z;

__int64 _ftelli64_z(
    FILE_z *stream);

int fwrite_z(
    const void *buffer,
    size_t size,
    size_t count,
    FILE_z *stream_z);

int fclose_z(
    FILE_z *stream_z);

FILE_z *fopen_z(
    const char *filename_z,
    const char *mode_z,
    int64_t max_memory_size_z,
    char *file_z,
    int line_z,
    FILE_z *old_file_z);

FILE_z *_wfopen_z(
    const wchar_t *filename_z,
    const char *mode_z,
    int64_t max_memory_size_z,
    char *file_z,
    int line_z,
    FILE_z *old_file_z);

size_t fread_z(
    void *buffer_z,
    size_t size_z,
    size_t count_z,
    FILE_z *stream_z);

void free_z(FILE_z *stream_z);