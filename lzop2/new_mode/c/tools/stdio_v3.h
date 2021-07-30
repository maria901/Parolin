//2021 by amanda & ricardo

#define ARP_USE_ENHANCED_STDIO

enum process_mode
{
	Z_MODE_IS_COMPRESSION   = 1001,
	Z_MODE_IN_DECOMPRESSION = 1002,
};

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

typedef struct my_thread_struct_z__
{   
	int64_t size_of_destination_file_z ;
	int * intpause                     ;
	int * intcancel                    ;
	int thread_id_z                    ;
	int ret                            ;
#ifdef ARP_USE_ENHANCED_STDIO
	FILE_z * dest                      ;
#else
	FILE * dest                        ;
#endif
	FILE * dest_original               ;
	FILE * input_file                  ;
	int64_t offset_z                   ;
	int64_t size_of_input_file_z       ;
	
	ar_data ar                         ;
	int level                          ;
	
	int retvalue                       ;
	int internal_error_arp             ;
	int64_t *bytes_read_z              ;
	int64_t size_of_input_file_copy_z  ;
	
	enum process_mode our_mode_z       ;
	char * memory_z                    ;
	
	bool dest_is_FILE_z                ;
}
	my_thread_struct_z                 ;

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