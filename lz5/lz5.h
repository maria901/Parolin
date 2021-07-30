//2021 amanda & ricardo
/*
    Copyright (C) <2022>  <BinaryWork Corp.>

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
   
        direct programmers e-mails:
        Ricardo: arsoftware25@gmail.com  ricardo@arsoftware.net.br
         Amanda: arsoftware10@gmail.com  amanda@arsoftware.net. br

        immediate contact(for a very fast answer) WhatsApp
        (+55)41 9627 1708 - it is always on
 */
 
#define INTERNAL_SIZE____Z (32768 * 2 * 2)

#define lzo_uint unsigned int

enum commands_z
{
	LZOP_RUN,
	LZOP_FLUSH,
	LZOP_FINISH,
};

enum error_value_z
{
	LZOP_OK,
	LZOP_ERROR,
};

enum return_value_of_lzop2
{
	LZOP_RUN_OK,
	LZOP_FINISH_OK,
	LZOP_FLUSH_OK,
	LZOP_SEQUENCE_ERROR,
	LZOP_STREAM_END,
	LZOP_DATA_ERROR,
	LZOP_MEM_ERROR,
	LZOP_DATA_ERROR_MAGIC
};

typedef struct LZOP2_struct__
{
	int64_t   compressed_size_z;
}LZOP2_data;

typedef struct LZOP_stream__z
{
	bool   processed_input_z         ;
	int    size_of_the_input_buffer_z;
	int    max_in_bytes              ;
	int    max_out_bytes             ;
	char * in_ptr                    ;
	char * out_ptr                   ;
	int    in_bytes_z                ;
	int    out_bytes_z               ;	
	char * internal_buffer           ;
	char * internal_out_buffer       ;
	char * memory_z                  ;	
	char * next_in                   ;
	char * next_out                  ;
	char * out_ptr_saved             ;
	int    avail_in                  ;
	int    avail_out                 ;
	int64_t   compressed_size_z      ;
	lzo_uint out_len_z               ;
	int has_more_data_to_save        ;
	int bytes_remaining_z            ;
	int bytes_input_remaining_z      ;
	/*for your pleasure */
	bool first_pass_decoder_z        ;	
	char * header_ptr_z              ;
	int header_ptr_loaded_z          ;
	
}LZOP_stream                         ;

int LZOP2_bzCompressInit(LZOP_stream * strm, int level_z, int unused_a_z, int unused_b_z);
int LZOP2_bzCompress (LZOP_stream * strm, int action_z)                                  ;

int LZOP2_bzCompressEnd   (LZOP_stream * strm);

int LZOP2_bzDecompressInit(LZOP_stream * strm, int unused_1_z, int unused_2_z);

int LZOP2_bzDecompress    (LZOP_stream * strm);

int LZOP2_bzDecompressEnd (LZOP_stream * strm);