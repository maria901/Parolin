/* LZ4frame API example : compress a file
 * Modified from an example code by Zbigniew Jędrzejewski-Szmek
 *
 * This example streams an input file into an output file
 * using a bounded memory budget.
 * Input is read in chunks of IN_CHUNK_SIZE */

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

#include "helper_utilities_by_amanda_and_ricardo.c"

#include <lz4frame.h>

#define IN_CHUNK_SIZE  (16*1024)

static const LZ4F_preferences_t kPrefs = {
    { LZ4F_max256KB, LZ4F_blockLinked, LZ4F_noContentChecksum, LZ4F_frame,
      0 /* unknown content size */, 0 /* no dictID */ , LZ4F_noBlockChecksum },
    0,   /* compression level; 0 == default */
    0,   /* autoflush */
    0,   /* favor decompression speed */
    { 0, 0, 0 },  /* reserved, must be set to 0 */
};


/* safe_fwrite() :
 * performs fwrite(), ensure operation success, or immediately exit() */
static void safe_fwrite(void* buf, size_t eltSize, size_t nbElt, FILE* f)
{
    size_t const writtenSize = fwrite(buf, eltSize, nbElt, f);
    size_t const expectedSize = eltSize * nbElt;
    //if (nbElt>0) assert(expectedSize / nbElt == eltSize);  /* check overflow */
    if (writtenSize < expectedSize) {
        if (ferror(f))  /* note : ferror() must follow fwrite */
            fprintf(stderr, "Write failed \n");
        else
            fprintf(stderr, "Write too short \n");
       // exit(1);
	   
	   internal_error_arp = 6;
	   
    }
}


/* ================================================= */
/*     Streaming Compression example               */
/* ================================================= */

typedef struct {
    int error;
    unsigned long long size_in;
    unsigned long long size_out;
} compressResult_t;

static compressResult_t
compress_file_internal(FILE* f_in, FILE* f_out,
                       LZ4F_compressionContext_t ctx,
                       void* inBuff,  size_t inChunkSize,
                       void* outBuff, size_t outCapacity)
{
    compressResult_t result = { 1, 0, 0 };  /* result for an error */
    unsigned long long count_in = 0, count_out;

    assert(f_in != NULL); assert(f_out != NULL);
    assert(ctx != NULL);
    assert(outCapacity >= LZ4F_HEADER_SIZE_MAX);
    assert(outCapacity >= LZ4F_compressBound(inChunkSize, &kPrefs));

    /* write frame header */
    {   size_t const headerSize = LZ4F_compressBegin(ctx, outBuff, outCapacity, &kPrefs);
        if (LZ4F_isError(headerSize)) {
            printf("Failed to start compression: error %u \n", (unsigned)headerSize);
            return result;
        }
        count_out = headerSize;
        printf("Buffer size is %u bytes, header size %u bytes \n",
                (unsigned)outCapacity, (unsigned)headerSize);
        safe_fwrite(outBuff, 1, headerSize, f_out);
		
		if(internal_error_arp)
		{
			return result;
		}
    }

    /* stream file */
    for (;;) {
        size_t const readSize = fread(inBuff, 1, IN_CHUNK_SIZE, f_in);
        if (readSize == 0) break; /* nothing left to read from input file */
        count_in += readSize;

        size_t const compressedSize = LZ4F_compressUpdate(ctx,
                                                outBuff, outCapacity,
                                                inBuff, readSize,
                                                NULL);
        if (LZ4F_isError(compressedSize)) {
            printf("Compression failed: error %u \n", (unsigned)compressedSize);
            return result;
        }

        printf("Writing %u bytes\n", (unsigned)compressedSize);
        safe_fwrite(outBuff, 1, compressedSize, f_out);
		
		if(internal_error_arp)
		{
			return result;
		}
		
		processado_rspk += readSize;

		while(intpause___aakp)
		{
			Sleep(50);

			if(intcancel__rspk)
			{
				internal_error_arp = 119;
				return result;
			}
		}

		if(intcancel__rspk)
		{
			internal_error_arp = 119;
			return result;
		}
		
		
        count_out += compressedSize;
    }

    /* flush whatever remains within internal buffers */
    {   size_t const compressedSize = LZ4F_compressEnd(ctx,
                                                outBuff, outCapacity,
                                                NULL);
        if (LZ4F_isError(compressedSize)) {
            printf("Failed to end compression: error %u \n", (unsigned)compressedSize);
            return result;
        }

        printf("Writing %u bytes \n", (unsigned)compressedSize);
        safe_fwrite(outBuff, 1, compressedSize, f_out);
		if(internal_error_arp)
		{
			return result;
		}
        count_out += compressedSize;
    }

    result.size_in = count_in;
    result.size_out = count_out;
    result.error = 0;
    return result;
}

static compressResult_t
compress_file(FILE* f_in, FILE* f_out)
{
    assert(f_in != NULL);
    assert(f_out != NULL);

    /* ressource allocation */
    LZ4F_compressionContext_t ctx;
    size_t const ctxCreation = LZ4F_createCompressionContext(&ctx, LZ4F_VERSION);
    void* const src = malloc(IN_CHUNK_SIZE);
    size_t const outbufCapacity = LZ4F_compressBound(IN_CHUNK_SIZE, &kPrefs);   /* large enough for any input <= IN_CHUNK_SIZE */
    void* const outbuff = malloc(outbufCapacity);

    compressResult_t result = { 1, 0, 0 };  /* == error (default) */
    if (!LZ4F_isError(ctxCreation) && src && outbuff) {
        result = compress_file_internal(f_in, f_out,
                                        ctx,
                                        src, IN_CHUNK_SIZE,
                                        outbuff, outbufCapacity);
    } else {
        printf("error : ressource allocation failed \n");
    }

    LZ4F_freeCompressionContext(ctx);   /* supports free on NULL */
    free(src);
    free(outbuff);
    return result;
}


/* ================================================= */
/*     Streaming decompression example               */
/* ================================================= */

static size_t get_block_size(const LZ4F_frameInfo_t* info) {
    switch (info->blockSizeID) {
        case LZ4F_default:
        case LZ4F_max64KB:  return 1 << 16;
        case LZ4F_max256KB: return 1 << 18;
        case LZ4F_max1MB:   return 1 << 20;
        case LZ4F_max4MB:   return 1 << 22;
        default:
            printf("Impossible with expected frame specification (<=v1.6.1)\n");
            exit(1);
    }
}

/* @return : 1==error, 0==success */
static int
decompress_file_internal(FILE* f_in, FILE* f_out,
                         LZ4F_dctx* dctx,
                         void* src, size_t srcCapacity, size_t filled, size_t alreadyConsumed,
                         void* dst, size_t dstCapacity)
{
    int firstChunk = 1;
    size_t ret = 1;

    assert(f_in != NULL); assert(f_out != NULL);
    assert(dctx != NULL);
    assert(src != NULL); assert(srcCapacity > 0); assert(filled <= srcCapacity); assert(alreadyConsumed <= filled);
    assert(dst != NULL); assert(dstCapacity > 0);

    /* Decompression */
    while (ret != 0) {
        /* Load more input */
        size_t readSize = firstChunk ? filled : fread(src, 1, srcCapacity, f_in); firstChunk=0;
        const void* srcPtr = (const char*)src + alreadyConsumed; alreadyConsumed=0;
        const void* const srcEnd = (const char*)srcPtr + readSize;
        if (readSize == 0 || ferror(f_in)) {
            printf("Decompress: not enough input or error reading file\n");
            return 1;
        }

		processado_rspk += readSize;

		while(intpause___aakp)
		{
			Sleep(50);

			if(intcancel__rspk)
			{
				internal_error_arp = 119;
				return 1;
			}
		}

		if(intcancel__rspk)
		{
			internal_error_arp = 119;
			return 1;
		}

        /* Decompress:
         * Continue while there is more input to read (srcPtr != srcEnd)
         * and the frame isn't over (ret != 0)
         */
        while (srcPtr < srcEnd && ret != 0) {
            /* Any data within dst has been flushed at this stage */
            size_t dstSize = dstCapacity;
            size_t srcSize = (const char*)srcEnd - (const char*)srcPtr;
            ret = LZ4F_decompress(dctx, dst, &dstSize, srcPtr, &srcSize, /* LZ4F_decompressOptions_t */ NULL);
            if (LZ4F_isError(ret)) {
                printf("Decompression error: %s\n", LZ4F_getErrorName(ret));
                return 1;
            }
            /* Flush output */
            if (dstSize != 0) safe_fwrite(dst, 1, dstSize, f_out);

			if(internal_error_arp)
			{
				return 1;
			}
		
            /* Update input */
            srcPtr = (const char*)srcPtr + srcSize;
        }

        assert(srcPtr <= srcEnd);

        /* Ensure all input data has been consumed.
         * It is valid to have multiple frames in the same file,
         * but this example only supports one frame.
         */
        if (srcPtr < srcEnd) {
            printf("Decompress: Trailing data left in file after frame\n");
            return 1;
        }
    }

    /* Check that there isn't trailing data in the file after the frame.
     * It is valid to have multiple frames in the same file,
     * but this example only supports one frame.
     */
    {   size_t const readSize = fread(src, 1, 1, f_in);
        if (readSize != 0 || !feof(f_in)) {
            printf("Decompress: Trailing data left in file after frame\n");
            return 1;
    }   }

    return 0;
}


/* @return : 1==error, 0==completed */
static int
decompress_file_allocDst(FILE* f_in, FILE* f_out,
                        LZ4F_dctx* dctx,
                        void* src, size_t srcCapacity)
{
    assert(f_in != NULL); assert(f_out != NULL);
    assert(dctx != NULL);
    assert(src != NULL);
    assert(srcCapacity >= LZ4F_HEADER_SIZE_MAX);  /* ensure LZ4F_getFrameInfo() can read enough data */

    /* Read Frame header */
    size_t const readSize = fread(src, 1, srcCapacity, f_in);
    if (readSize == 0 || ferror(f_in)) {
        printf("Decompress: not enough input or error reading file\n");
        return 1;
    }

    LZ4F_frameInfo_t info;
    size_t consumedSize = readSize;
    {   size_t const fires = LZ4F_getFrameInfo(dctx, &info, src, &consumedSize);
        if (LZ4F_isError(fires)) {
            printf("LZ4F_getFrameInfo error: %s\n", LZ4F_getErrorName(fires));
            return 1;
    }   }

    /* Allocating enough space for an entire block isn't necessary for
     * correctness, but it allows some memcpy's to be elided.
     */
    size_t const dstCapacity = get_block_size(&info);
    void* const dst = malloc(dstCapacity);
    if (!dst) { perror("decompress_file(dst)"); return 1; }

    int const decompressionResult = decompress_file_internal(
                        f_in, f_out,
                        dctx,
                        src, srcCapacity, readSize-consumedSize, consumedSize,
                        dst, dstCapacity);

    free(dst);
    return decompressionResult;
}


/* @result : 1==error, 0==success */
static int decompress_file(FILE* f_in, FILE* f_out)
{
    assert(f_in != NULL); assert(f_out != NULL);

    /* Ressource allocation */
    void* const src = malloc(IN_CHUNK_SIZE);
    if (!src) { perror("decompress_file(src)"); return 1; }

    LZ4F_dctx* dctx;
    {   size_t const dctxStatus = LZ4F_createDecompressionContext(&dctx, LZ4F_VERSION);
        if (LZ4F_isError(dctxStatus)) {
            printf("LZ4F_dctx creation error: %s\n", LZ4F_getErrorName(dctxStatus));
    }   }

    int const result = !dctx ? 1 /* error */ :
                       decompress_file_allocDst(f_in, f_out, dctx, src, IN_CHUNK_SIZE);

    free(src);
    LZ4F_freeDecompressionContext(dctx);   /* note : free works on NULL */
    return result;
}


int compareFiles(FILE* fp0, FILE* fp1)
{
    int result = 0;

    while (result==0) {
        char b0[1024];
        char b1[1024];
        size_t const r0 = fread(b0, 1, sizeof(b0), fp0);
        size_t const r1 = fread(b1, 1, sizeof(b1), fp1);

        result = (r0 != r1);
        if (!r0 || !r1) break;
        if (!result) result = memcmp(b0, b1, r0);
    }

    return result;
}


int main(int argc, const char **argv) {
    char inpFilename[256] = { 0 };
    char lz4Filename[256] = { 0 };
    char decFilename[256] = { 0 };

    if (argc < 2) {
        printf("Please specify input filename\n");
        return 0;
    }

    snprintf(inpFilename, 256, "%s", argv[1]);
    snprintf(lz4Filename, 256, "%s.lz4", argv[1]);
    snprintf(decFilename, 256, "%s.lz4.dec", argv[1]);

    printf("inp = [%s]\n", inpFilename);
    printf("lz4 = [%s]\n", lz4Filename);
    printf("dec = [%s]\n", decFilename);

    /* compress */
    {   FILE* const inpFp = fopen(inpFilename, "rb");
        FILE* const outFp = fopen(lz4Filename, "wb");

        printf("compress : %s -> %s\n", inpFilename, lz4Filename);
        compressResult_t const ret = compress_file(inpFp, outFp);

        fclose(outFp);
        fclose(inpFp);

        if (ret.error) {
            printf("compress : failed with code %i\n", ret.error);
            return ret.error;
        }
        printf("%s: %zu → %zu bytes, %.1f%%\n",
            inpFilename,
            (size_t)ret.size_in, (size_t)ret.size_out,  /* might overflow is size_t is 32 bits and size_{in,out} > 4 GB */
            (double)ret.size_out / ret.size_in * 100);
        printf("compress : done\n");
    }

    /* decompress */
    {   FILE* const inpFp = fopen(lz4Filename, "rb");
        FILE* const outFp = fopen(decFilename, "wb");

        printf("decompress : %s -> %s\n", lz4Filename, decFilename);
        int const ret = decompress_file(inpFp, outFp);

        fclose(outFp);
        fclose(inpFp);

        if (ret) {
            printf("decompress : failed with code %i\n", ret);
            return ret;
        }
        printf("decompress : done\n");
    }

    /* verify */
    {   FILE* const inpFp = fopen(inpFilename, "rb");
        FILE* const decFp = fopen(decFilename, "rb");

        printf("verify : %s <-> %s\n", inpFilename, decFilename);
        int const cmp = compareFiles(inpFp, decFp);

        fclose(decFp);
        fclose(inpFp);

        if (cmp) {
            printf("corruption detected : decompressed file differs from original\n");
            return cmp;
        }
        printf("verify : OK\n");
    }

    return 0;
}


int __stdcall compress_l4___rspk_ar(char * Input_amanda_file_utf_8, char * OutPut_ricardo_File_utf_8, int Compression_juliete_Level_unused___)
{
	//

	FILE * fd_aakp           = NULL;
	FILE * fd_valquiria_aakp = NULL;
	int return_value_valquiria   = 0;
	internal_error_arp           = 0;
	intpause___aakp              = 0;
	intcancel__rspk              = 0;
	tamanho____aakp =       getfilesize_aakp_plus_rspk(Input_amanda_file_utf_8);
	processado_rspk =                                                         0;
	porcentagem_junior_ale_mislaine_thalia_aline_juliete_valquiria_maria_feline_pedro = 0;
	fd_aakp = _wfopen(utf8towide(Input_amanda_file_utf_8), L"rb");

	if(NULL != fd_aakp)
	{
		fd_valquiria_aakp = _wfopen(utf8towide(OutPut_ricardo_File_utf_8), L"wb");

		pedro_dprintf(-1, "retorno de open de output %d file %s\n", fd_valquiria_aakp, OutPut_ricardo_File_utf_8);

		if(NULL != fd_valquiria_aakp)
		{

			{
			
				compressResult_t const ret = compress_file(fd_aakp, fd_valquiria_aakp);

				if(119 == internal_error_arp)
				{
					return_value_valquiria = internal_error_arp;
				}
				else if(6 == internal_error_arp)
				{
					return_value_valquiria = internal_error_arp;
				}
				else
				{
					
					if(ret.error)
					{
						return_value_valquiria = 8;//Compression error
					}
					
				}
		
			}

//5 cannot read from input file....
//6 cannot write to output file

		}
		else
		{
			return_value_valquiria = 2;        //cannot open output file
			goto saida_amanda_agora;
		}
	}
	else
	{
		return_value_valquiria = 1;        //cannot open input file
		goto saida_amanda_agora;
	}

saida_amanda_agora:
	;

	if(fd_aakp)
	{
		fclose(fd_aakp);
	}

	if(fd_valquiria_aakp)
	{
		fclose(fd_valquiria_aakp);
	}
	
	pedro_dprintf(-1, "return value %d\n", return_value_valquiria);
	return return_value_valquiria;//119 user cancel
}
int __stdcall uncompress_l4___rspk_ar(char * Input_amanda_file_utf_8, char * OutPut_ricardo_File_utf_8)
{
	//
	int ret                      = 0;
	FILE * fd_aakp           = NULL;
	FILE * fd_valquiria_aakp = NULL;
	int return_value_valquiria   = 0;
	internal_error_arp           = 0;
	intpause___aakp              = 0;
	intcancel__rspk              = 0;
	tamanho____aakp =       getfilesize_aakp_plus_rspk(Input_amanda_file_utf_8);
	processado_rspk =                                                         0;
	porcentagem_junior_ale_mislaine_thalia_aline_juliete_valquiria_maria_feline_pedro = 0;
	fd_aakp = _wfopen(utf8towide(Input_amanda_file_utf_8), L"rb");

	if(NULL != fd_aakp)
	{
		fd_valquiria_aakp = _wfopen(utf8towide(OutPut_ricardo_File_utf_8), L"wb");

		if(NULL != fd_valquiria_aakp)
		{

			{   
				
				ret = decompress_file(fd_aakp, fd_valquiria_aakp);

				if(119 == internal_error_arp)
				{
					return_value_valquiria = internal_error_arp;
				}
				else if(6 == internal_error_arp)
				{
					return_value_valquiria = internal_error_arp;
				}
				else
				{
					if(ret)
					{
						return_value_valquiria = 7; //Decompression error
					}
				}
			}
//uncompress
//5 cannot read from input file....
//6 cannot write to output file
//7 not a valid compressed file
		}
		else
		{
			return_value_valquiria = 2;        //cannot open output file
			goto saida_amanda_agora;
		}
	}
	else
	{
		return_value_valquiria = 1;        //cannot open input file
		goto saida_amanda_agora;
	}

saida_amanda_agora:
	;

	if(fd_aakp)
	{
		fclose(fd_aakp);
	}

	if(fd_valquiria_aakp)
	{
		fclose(fd_valquiria_aakp);
	}

	pedro_dprintf(-1, "return value %d\n", return_value_valquiria);
	return return_value_valquiria;//119 user cancel
}
int __stdcall get_progress_l4___ar (void)
{
	int ret_val_aakp_rspk_;

	ret_val_aakp_rspk_ = lgetpor
		             (
		tamanho____aakp,
		processado_rspk
	                     );

	if(10000 < ret_val_aakp_rspk_)
	{
		return 10000;
	}
	if(0 >     ret_val_aakp_rspk_)
	{
		return 0;
	}
	return ret_val_aakp_rspk_;
}

 int __stdcall  pause_l4___aakp_l4___ar(void)
 {
	 intpause___aakp = 1;
 }
 int __stdcall  resume_l4___aakp_l4___ar(void)
 {
	 intpause___aakp = 0;
 }
 int __stdcall  cancel_l4___aakp_l4___ar(void)
 {
	 intcancel__rspk = 1;
 }

BOOL WINAPI DllMain (HINSTANCE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString ("LZ4 Compress DLL DLL_PROCESS_ATTACH (" __TIME__ " " __DATE__ ") _amanda_debug_\n");

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

