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

enum error_modes_J
{
     ERROR_AMANDA_NO_ERROR__,
};

#define FILE_z FILE

size_t fwrite_z(const void *buffer_z,
                size_t size_z,
                size_t count_z,
                FILE_z *stream_z,
                enum error_modes_J *have_error_M);

int fclose_z(FILE_z *stream_z);

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
    FILE_z *stream_z,
    enum error_modes_J *have_error_M);

void free_z(FILE_z *stream_z);

enum error_modes_J check_internal_status_to_open_junior(FILE_z *my_file_mislaine);