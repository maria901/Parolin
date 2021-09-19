//2021 by amanda & ricardo

#define ARP_USE_ENHANCED_STDIO

//#define MAX_MEMORY_SIZE_Z (16 * 1024 * 1024)

typedef struct _ar_data
{
	char string[4];
	/*
	uint rsp32; //since we want speed we have no checksum on it
	*/
	int attrib;
	/*
	FILETIME creation;//add it to gzip2?...
	FILETIME lwrite;
	*/
} ar_data;

typedef struct               my_thread_struct_z__
{
	ar_data   ar                                ;
	bool      dest_is_FILE_z                    ;
	FILE    * input_file                        ;
	int       internal_error_arp                ;
	int       level                             ;
	int       ret                               ;
	int       retvalue                          ;
	int       thread_id_z                       ;
	int     * intcancel                         ;
	int     * intpause                          ;
	int64_t   offset_z                          ;
	int64_t   size_of_destination_file_z        ;
	int64_t   size_of_input_file_copy_z         ;
	int64_t   size_of_input_file_z              ;
	int64_t * bytes_read_z                      ;

#ifdef ARP_USE_ENHANCED_STDIO
	FILE_z *  dest                              ;
#else
	FILE *    dest                              ;
#endif
}
	my_thread_struct_z                          ;

typedef struct {
    int error;
    unsigned long long size_in;
    unsigned long long size_out;
} compressResult_t;


#ifdef ARP_USE_ENHANCED_STDIO
compressResult_t
compress_file(FILE* f_in, FILE_z* f_out, my_thread_struct_z * amanda);
#else
compressResult_t
compress_file(FILE* f_in, FILE* f_out, my_thread_struct_z * amanda);
#endif

int decompress_file(FILE* f_in, FILE* f_out, my_thread_struct_z * amanda);

void
pedro_dprintf
(
	int amanda_level,
	char *format, ...
);

#define __valquiriacall __fastcall
int     __valquiriacall compress2_uncompress_k_real_mt_z (char *input_z, char *output_z)/*for your pleasure */;