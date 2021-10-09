#include "rc4.h"
#include "aes.h"

#include "serpent.h"
#include "serpentsboxes.h"

#include "./std_defs.h"

typedef struct _ar_data
{
    char string[4];
    //unsigned char sha512_k[SHA512_DIGEST_LENGTH];
    int attrib;
} ar_data;

typedef struct my_thread_struct_z__
{

    int thread_id_z;

    FILE *dest;

    FILE *input_file;
    int64_t offset_z;
    int64_t size_of_input_file_z;
    __int64 bytesread;
    __int64 bytestosave;
    __int64 totalbytes;
    int done;
    int flush;
    int last;
    int level;
    int ret;
    int ret2;
    int retvalue;
    int writebytes;
    ar_data ar;
    char *buffer;
    char *out;
    char *temp_output;
    char key_k__p[300];
    unsigned char sha512_digest_k[65];
    int64_t *bytes_read_z;
    int64_t size_of_input_file_copy_z;
    bool dest_is_FILE_z;
    int *intpause;
    int *intcancel;
    int internal_error_arp;
    int encryption_method_internal_arp;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // aes encryotion variables
    int init_aes;
    int done2;
    char countbuffer[17];

    int *ptr1;
    int *ptr2;
    int *ptr3;
    int *ptr4;
    aes_context ctxxx2;
    aes_context ctxxx;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // rc4 encryotion variable
    struct rc4_state rc4s;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // serpent
    keyInstance keyI_arp;
    cipherInstance cipherI_arp;
    int init_serpent_arp;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // mars
    int init_mars_arp__;
    u4byte l_key[40];
    u4byte vk[47];
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
} my_thread_struct_z;
