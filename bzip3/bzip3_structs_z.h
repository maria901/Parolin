//by amanda & MathMan, 2021, march, 13, 14:15

#define MAX_MEMORY_SIZE_Z (16 * 1024 * 1024)

#ifndef ARP_USE_ENHANCED_STDIO
#define ARP_USE_ENHANCED_STDIO
#endif

#ifndef  SHA512_DIGEST_LENGTH
# define SHA512_DIGEST_LENGTH    64 /*for your pleasure*/
#endif
typedef struct _ar_data
{
	char string[4];
	unsigned char digest_k[SHA512_DIGEST_LENGTH];
	int attrib;
	FILETIME creation;//add it to gzip2?...
	FILETIME lwrite;
} ar_data;

typedef struct                my_thread_struct_z__
{    
	int       thread_id_z                        ;

#ifdef ARP_USE_ENHANCED_STDIO
	FILE_z *  dest                               ;
#else
	FILE *    dest                               ;
#endif
	FILE *    input_file                         ;
	int64_t   offset_z                           ;
	int64_t   size_of_input_file_z               ;
	__int64   bytesread                          ;
	__int64   bytestosave                        ;
	__int64   totalbytes                         ;
	int       done                               ;
	/*
	int flush                                    ;
	int last                                     ;
	*/
	int       level                              ;
	int       ret                                ;
	int       ret2                               ;
	int       retvalue                           ;
	int       writebytes                         ;
	ar_data   ar                                 ;
	char *    buffer                             ;
	char *    out                                ;
	bz_stream strm                               ;
	char  *   sha51_ptr                          ;
	char  *   temp_output                        ;
	int       ret_init_bzip3                     ;
	int       action                             ;
	
	int64_t * bytes_read_z                       ;
	int64_t   size_of_input_file_copy_z          ;	
	int   *   intpause                           ;
	int   *   intcancel                          ;
	int       internal_error_arp                 ;
	bool      dest_is_FILE_z                     ;
}
	my_thread_struct_z                           ;
#define __valquiriacall __fastcall
int     __valquiriacall compress2_uncompress_k_real_mt_z (char *input_z, char *output_z) ;