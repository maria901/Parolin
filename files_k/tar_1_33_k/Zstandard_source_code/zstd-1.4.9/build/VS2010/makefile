#2021 amanda & MathMan, updated May

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -DZSTD_MULTITHREAD
JULIET_FLAGS  = 

AMANDA_SIZE__ =                                    62

amanda_32: pedro_32arp.o                           \
	arp_dll_32arp.o benchfn_32arp.o            \
	benchzstd_32arp.o cover_32arp.o            \
	datagen_32arp.o debug_32arp.o              \
	dibio_32arp.o                              \
	divsufsort_32arp.o entropy_common_32arp.o  \
	error_private_32arp.o fastcover_32arp.o    \
	fileio_32arp.o fse_compress_32arp.o        \
	fse_decompress_32arp.o hist_32arp.o        \
	huf_compress_32arp.o                       \
	huf_decompress_32arp.o                     \
	pool_32arp.o threading_32arp.o             \
	timefn_32arp.o util_32arp.o xxhash_32arp.o \
	zdict_32arp.o zstd_common_32arp.o          \
	zstd_compress_32arp.o                      \
	zstd_compress_literals_32arp.o             \
	zstd_compress_sequences_32arp.o            \
	zstd_compress_superblock_32arp.o           \
	zstd_ddict_32arp.o zstd_decompress_32arp.o \
	zstd_decompress_block_32arp.o              \
	zstd_double_fast_32arp.o                   \
	zstd_fast_32arp.o zstd_lazy_32arp.o        \
	zstd_ldm_32arp.o zstd_opt_32arp.o          \
	zstd_v01_32arp.o zstd_v02_32arp.o          \
	zstd_v03_32arp.o zstd_v04_32arp.o          \
	zstd_v05_32arp.o zstd_v06_32arp.o          \
	zstd_v07_32arp.o zstdcli_32arp.o           \
	zstdmt_compress_32arp.o                    \
	zstdcli_trace_32arp.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	pedro_32arp.o                              \
	arp_dll_32arp.o benchfn_32arp.o            \
	benchzstd_32arp.o cover_32arp.o            \
	datagen_32arp.o debug_32arp.o              \
	dibio_32arp.o                              \
	divsufsort_32arp.o entropy_common_32arp.o  \
	error_private_32arp.o fastcover_32arp.o    \
	fileio_32arp.o fse_compress_32arp.o        \
	fse_decompress_32arp.o hist_32arp.o        \
	huf_compress_32arp.o                       \
	huf_decompress_32arp.o                     \
	pool_32arp.o threading_32arp.o             \
	timefn_32arp.o util_32arp.o xxhash_32arp.o \
	zdict_32arp.o zstd_common_32arp.o          \
	zstd_compress_32arp.o                      \
	zstd_compress_literals_32arp.o             \
	zstd_compress_sequences_32arp.o            \
	zstd_compress_superblock_32arp.o           \
	zstd_ddict_32arp.o zstd_decompress_32arp.o \
	zstd_decompress_block_32arp.o              \
	zstd_double_fast_32arp.o                   \
	zstd_fast_32arp.o zstd_lazy_32arp.o        \
	zstd_ldm_32arp.o zstd_opt_32arp.o          \
	zstd_v01_32arp.o zstd_v02_32arp.o          \
	zstd_v03_32arp.o zstd_v04_32arp.o          \
	zstd_v05_32arp.o zstd_v06_32arp.o          \
	zstd_v07_32arp.o zstdcli_32arp.o           \
	zstdmt_compress_32arp.o                    \
	zstdcli_trace_32arp.o

	@i686-w64-mingw32-gcc.exe -O3 -o           \
	RSP_Zstandard_arp_32.DLL arp.def -mdll     \
	pedro_32arp.o                              \
	arp_dll_32arp.o benchfn_32arp.o            \
	benchzstd_32arp.o cover_32arp.o            \
	datagen_32arp.o debug_32arp.o              \
	dibio_32arp.o                              \
	divsufsort_32arp.o entropy_common_32arp.o  \
	error_private_32arp.o fastcover_32arp.o    \
	fileio_32arp.o fse_compress_32arp.o        \
	fse_decompress_32arp.o hist_32arp.o        \
	huf_compress_32arp.o                       \
	huf_decompress_32arp.o                     \
	pool_32arp.o threading_32arp.o             \
	timefn_32arp.o util_32arp.o xxhash_32arp.o \
	zdict_32arp.o zstd_common_32arp.o          \
	zstd_compress_32arp.o                      \
	zstd_compress_literals_32arp.o             \
	zstd_compress_sequences_32arp.o            \
	zstd_compress_superblock_32arp.o           \
	zstd_ddict_32arp.o zstd_decompress_32arp.o \
	zstd_decompress_block_32arp.o              \
	zstd_double_fast_32arp.o                   \
	zstd_fast_32arp.o zstd_lazy_32arp.o        \
	zstd_ldm_32arp.o zstd_opt_32arp.o          \
	zstd_v01_32arp.o zstd_v02_32arp.o          \
	zstd_v03_32arp.o zstd_v04_32arp.o          \
	zstd_v05_32arp.o zstd_v06_32arp.o          \
	zstd_v07_32arp.o zstdcli_32arp.o           \
	zstdmt_compress_32arp.o                    \
	zstdcli_trace_32arp.o                      \
	-Wl,-enable-stdcall-fixup

	@cp RSP_Zstandard_arp_32.DLL ../../../../

	@cp RSP_Zstandard_arp_32.DLL               'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe $(AMANDA_SIZE__)

	@./espaco_arp.exe $(AMANDA_SIZE__) 27

#		dumppe RSP_Zstandard_arp_32.DLL
run_arp:
		./test_arp.exe -f ./test_arp.exe -o ./test_arp.zst
		./test_arp.exe -f -d ./test_arp.zst -o ./test_arp.out

debug_32arp.o : ../../lib/common/debug.c
	i686-w64-mingw32-gcc.exe -c -o             \
	debug_32arp.o                              \
	../../lib/common/debug.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	debug_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstdcli_trace_32arp.o :                            \
	../../programs/zstdcli_trace.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstdcli_trace_32arp.o                      \
	../../programs/zstdcli_trace.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstdcli_trace_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

entropy_common_32arp.o :                           \
	../../lib/common/entropy_common.c
	i686-w64-mingw32-gcc.exe -c -o             \
	entropy_common_32arp.o                     \
	../../lib/common/entropy_common.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	entropy_common_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

error_private_32arp.o :                            \
	../../lib/common/error_private.c
	i686-w64-mingw32-gcc.exe -c -o             \
	error_private_32arp.o                      \
	../../lib/common/error_private.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	error_private_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

fse_decompress_32arp.o :                           \
	../../lib/common/fse_decompress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	fse_decompress_32arp.o                     \
	../../lib/common/fse_decompress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	fse_decompress_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pool_32arp.o : ../../lib/common/pool.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pool_32arp.o ../../lib/common/pool.c       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pool_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

threading_32arp.o : ../../lib/common/threading.c
	i686-w64-mingw32-gcc.exe -c -o             \
	threading_32arp.o                          \
	../../lib/common/threading.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	threading_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

xxhash_32arp.o : ../../lib/common/xxhash.c
	i686-w64-mingw32-gcc.exe -c -o             \
	xxhash_32arp.o ../../lib/common/xxhash.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	xxhash_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_common_32arp.o :                              \
	../../lib/common/zstd_common.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_common_32arp.o                        \
	../../lib/common/zstd_common.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_common_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

fse_compress_32arp.o :                             \
	../../lib/compress/fse_compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	fse_compress_32arp.o                       \
	../../lib/compress/fse_compress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	fse_compress_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

hist_32arp.o : ../../lib/compress/hist.c
	i686-w64-mingw32-gcc.exe -c -o             \
	hist_32arp.o                               \
	../../lib/compress/hist.c                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	hist_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

huf_compress_32arp.o :                             \
	../../lib/compress/huf_compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	huf_compress_32arp.o                       \
	../../lib/compress/huf_compress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	huf_compress_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_compress_32arp.o :                            \
	../../lib/compress/zstd_compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_compress_32arp.o                      \
	../../lib/compress/zstd_compress.c         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_compress_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_compress_literals_32arp.o :                   \
	../../lib/compress/zstd_compress_literals.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_compress_literals_32arp.o             \
	../../lib/compress/zstd_compress_literals.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_compress_literals_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_compress_sequences_32arp.o:                   \
	../../lib/compress/zstd_compress_sequences.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_compress_sequences_32arp.o            \
	../../lib/compress/zstd_compress_sequences.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_compress_sequences_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_compress_superblock_32arp.o :                 \
	../../lib/compress/zstd_compress_superblock.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_compress_superblock_32arp.o           \
	../../lib/compress/zstd_compress_superblock.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_compress_superblock_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_double_fast_32arp.o :                         \
	../../lib/compress/zstd_double_fast.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_double_fast_32arp.o                   \
	../../lib/compress/zstd_double_fast.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_double_fast_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_fast_32arp.o :                                \
	../../lib/compress/zstd_fast.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_fast_32arp.o                          \
	../../lib/compress/zstd_fast.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_fast_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_lazy_32arp.o :                                \
	../../lib/compress/zstd_lazy.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_lazy_32arp.o                          \
	../../lib/compress/zstd_lazy.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_lazy_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_ldm_32arp.o : ../../lib/compress/zstd_ldm.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_ldm_32arp.o                           \
	../../lib/compress/zstd_ldm.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_ldm_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_opt_32arp.o : ../../lib/compress/zstd_opt.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_opt_32arp.o                           \
	../../lib/compress/zstd_opt.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_opt_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstdmt_compress_32arp.o :                          \
	../../lib/compress/zstdmt_compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstdmt_compress_32arp.o                    \
	../../lib/compress/zstdmt_compress.c       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstdmt_compress_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

huf_decompress_32arp.o :                           \
	../../lib/decompress/huf_decompress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	huf_decompress_32arp.o                     \
	../../lib/decompress/huf_decompress.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	huf_decompress_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_ddict_32arp.o :                               \
	../../lib/decompress/zstd_ddict.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_ddict_32arp.o                         \
	../../lib/decompress/zstd_ddict.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_ddict_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_decompress_32arp.o :                          \
	../../lib/decompress/zstd_decompress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_decompress_32arp.o                    \
	../../lib/decompress/zstd_decompress.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_decompress_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_decompress_block_32arp.o :                    \
	../../lib/decompress/zstd_decompress_block.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_decompress_block_32arp.o              \
	../../lib/decompress/zstd_decompress_block.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_decompress_block_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

cover_32arp.o : ../../lib/dictBuilder/cover.c
	i686-w64-mingw32-gcc.exe -c -o             \
	cover_32arp.o ../../lib/dictBuilder/cover.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	cover_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

divsufsort_32arp.o :                               \
	../../lib/dictBuilder/divsufsort.c
	i686-w64-mingw32-gcc.exe -c -o             \
	divsufsort_32arp.o                         \
	../../lib/dictBuilder/divsufsort.c         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	divsufsort_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

fastcover_32arp.o :                                \
	../../lib/dictBuilder/fastcover.c
	i686-w64-mingw32-gcc.exe -c -o             \
	fastcover_32arp.o                          \
	../../lib/dictBuilder/fastcover.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	fastcover_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zdict_32arp.o : ../../lib/dictBuilder/zdict.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zdict_32arp.o                              \
	../../lib/dictBuilder/zdict.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zdict_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v01_32arp.o : ../../lib/legacy/zstd_v01.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_v01_32arp.o ../../lib/legacy/zstd_v01.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_v01_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v02_32arp.o : ../../lib/legacy/zstd_v02.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_v02_32arp.o ../../lib/legacy/zstd_v02.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_v02_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v03_32arp.o : ../../lib/legacy/zstd_v03.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_v03_32arp.o                           \
	../../lib/legacy/zstd_v03.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_v03_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v04_32arp.o : ../../lib/legacy/zstd_v04.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_v04_32arp.o                           \
	../../lib/legacy/zstd_v04.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_v04_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v05_32arp.o : ../../lib/legacy/zstd_v05.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_v05_32arp.o                           \
	../../lib/legacy/zstd_v05.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_v05_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v06_32arp.o : ../../lib/legacy/zstd_v06.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_v06_32arp.o                           \
	../../lib/legacy/zstd_v06.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_v06_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v07_32arp.o : ../../lib/legacy/zstd_v07.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstd_v07_32arp.o                           \
	../../lib/legacy/zstd_v07.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstd_v07_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

benchfn_32arp.o : ../../programs/benchfn.c
	i686-w64-mingw32-gcc.exe -c -o             \
	benchfn_32arp.o                            \
	../../programs/benchfn.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	benchfn_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

benchzstd_32arp.o : ../../programs/benchzstd.c
	i686-w64-mingw32-gcc.exe -c -o             \
	benchzstd_32arp.o                          \
	../../programs/benchzstd.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	benchzstd_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

datagen_32arp.o : ../../programs/datagen.c
	i686-w64-mingw32-gcc.exe -c -o             \
	datagen_32arp.o ../../programs/datagen.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	datagen_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

dibio_32arp.o : ../../programs/dibio.c
	i686-w64-mingw32-gcc.exe -c -o             \
	dibio_32arp.o ../../programs/dibio.c       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	dibio_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

fileio_32arp.o : ../../programs/fileio.c
	i686-w64-mingw32-gcc.exe -c -o             \
	fileio_32arp.o ../../programs/fileio.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	fileio_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

timefn_32arp.o : ../../programs/timefn.c
	i686-w64-mingw32-gcc.exe -c -o             \
	timefn_32arp.o ../../programs/timefn.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	timefn_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

util_32arp.o : ../../programs/util.c
	i686-w64-mingw32-gcc.exe -c -o             \
	util_32arp.o -DARP_MISSING_WDM_HEADER__    \
	../../programs/util.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	util_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstdcli_32arp.o : ../../programs/zstdcli.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zstdcli_32arp.o ../../programs/zstdcli.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zstdcli_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

arp_dll_32arp.o : \
	../../programs/helper_utilities_by_amanda_and_ricardo.c \
	../../programs/arp_dll.c
	i686-w64-mingw32-gcc.exe -c -o             \
	arp_dll_32arp.o ../../programs/arp_dll.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	arp_dll_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_32arp.o : pedro.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32arp.o                              \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pedro_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

#################################64 bits ***************************************************************************************

ricardo_64: pedro_64arp.o                          \
	arp_dll_64arp.o benchfn_64arp.o            \
	benchzstd_64arp.o cover_64arp.o            \
	datagen_64arp.o debug_64arp.o              \
	dibio_64arp.o                              \
	divsufsort_64arp.o entropy_common_64arp.o  \
	error_private_64arp.o fastcover_64arp.o    \
	fileio_64arp.o fse_compress_64arp.o        \
	fse_decompress_64arp.o hist_64arp.o        \
	huf_compress_64arp.o                       \
	huf_decompress_64arp.o                     \
	pool_64arp.o threading_64arp.o             \
	timefn_64arp.o util_64arp.o xxhash_64arp.o \
	zdict_64arp.o zstd_common_64arp.o          \
	zstd_compress_64arp.o                      \
	zstd_compress_literals_64arp.o             \
	zstd_compress_sequences_64arp.o            \
	zstd_compress_superblock_64arp.o           \
	zstd_ddict_64arp.o zstd_decompress_64arp.o \
	zstd_decompress_block_64arp.o              \
	zstd_double_fast_64arp.o                   \
	zstd_fast_64arp.o zstd_lazy_64arp.o        \
	zstd_ldm_64arp.o zstd_opt_64arp.o          \
	zstd_v01_64arp.o zstd_v02_64arp.o          \
	zstd_v03_64arp.o zstd_v04_64arp.o          \
	zstd_v05_64arp.o zstd_v06_64arp.o          \
	zstd_v07_64arp.o zstdcli_64arp.o           \
	zstdmt_compress_64arp.o                    \
	zstdcli_trace_64arp.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	pedro_64arp.o                              \
	arp_dll_64arp.o benchfn_64arp.o            \
	benchzstd_64arp.o cover_64arp.o            \
	datagen_64arp.o debug_64arp.o              \
	dibio_64arp.o                              \
	divsufsort_64arp.o entropy_common_64arp.o  \
	error_private_64arp.o fastcover_64arp.o    \
	fileio_64arp.o fse_compress_64arp.o        \
	fse_decompress_64arp.o hist_64arp.o        \
	huf_compress_64arp.o                       \
	huf_decompress_64arp.o                     \
	pool_64arp.o threading_64arp.o             \
	timefn_64arp.o util_64arp.o xxhash_64arp.o \
	zdict_64arp.o zstd_common_64arp.o          \
	zstd_compress_64arp.o                      \
	zstd_compress_literals_64arp.o             \
	zstd_compress_sequences_64arp.o            \
	zstd_compress_superblock_64arp.o           \
	zstd_ddict_64arp.o zstd_decompress_64arp.o \
	zstd_decompress_block_64arp.o              \
	zstd_double_fast_64arp.o                   \
	zstd_fast_64arp.o zstd_lazy_64arp.o        \
	zstd_ldm_64arp.o zstd_opt_64arp.o          \
	zstd_v01_64arp.o zstd_v02_64arp.o          \
	zstd_v03_64arp.o zstd_v04_64arp.o          \
	zstd_v05_64arp.o zstd_v06_64arp.o          \
	zstd_v07_64arp.o zstdcli_64arp.o           \
	zstdmt_compress_64arp.o                    \
	zstdcli_trace_64arp.o

	@x86_64-w64-mingw32-gcc -O3 -o             \
	RSP_Zstandard_arp_64.DLL arp.def -mdll     \
	pedro_64arp.o                              \
	arp_dll_64arp.o benchfn_64arp.o            \
	benchzstd_64arp.o cover_64arp.o            \
	datagen_64arp.o debug_64arp.o              \
	dibio_64arp.o                              \
	divsufsort_64arp.o entropy_common_64arp.o  \
	error_private_64arp.o fastcover_64arp.o    \
	fileio_64arp.o fse_compress_64arp.o        \
	fse_decompress_64arp.o hist_64arp.o        \
	huf_compress_64arp.o                       \
	huf_decompress_64arp.o                     \
	pool_64arp.o threading_64arp.o             \
	timefn_64arp.o util_64arp.o                \
	xxhash_64arp.o                             \
	zdict_64arp.o zstd_common_64arp.o          \
	zstd_compress_64arp.o                      \
	zstd_compress_literals_64arp.o             \
	zstd_compress_sequences_64arp.o            \
	zstd_compress_superblock_64arp.o           \
	zstd_ddict_64arp.o                         \
	zstd_decompress_64arp.o                    \
	zstd_decompress_block_64arp.o              \
	zstd_double_fast_64arp.o                   \
	zstd_fast_64arp.o zstd_lazy_64arp.o        \
	zstd_ldm_64arp.o zstd_opt_64arp.o          \
	zstd_v01_64arp.o zstd_v02_64arp.o          \
	zstd_v03_64arp.o zstd_v04_64arp.o          \
	zstd_v05_64arp.o zstd_v06_64arp.o          \
	zstd_v07_64arp.o zstdcli_64arp.o           \
	zstdmt_compress_64arp.o                    \
	zstdcli_trace_64arp.o                      \
	-Wl,-enable-stdcall-fixup
	@cp RSP_Zstandard_arp_64.DLL ../../../../
	@cp RSP_Zstandard_arp_64.DLL               'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@./espaco_arp.exe $(AMANDA_SIZE__)

	@./espaco_arp.exe $(AMANDA_SIZE__) 27

zstdcli_trace_64arp.o :                            \
	../../programs/zstdcli_trace.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstdcli_trace_64arp.o                      \
	../../programs/zstdcli_trace.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstdcli_trace_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

debug_64arp.o : ../../lib/common/debug.c
	x86_64-w64-mingw32-gcc -c -o               \
	debug_64arp.o                              \
	../../lib/common/debug.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	debug_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

entropy_common_64arp.o :                           \
	../../lib/common/entropy_common.c
	x86_64-w64-mingw32-gcc -c -o               \
	entropy_common_64arp.o                     \
	../../lib/common/entropy_common.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	entropy_common_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

error_private_64arp.o :                            \
	../../lib/common/error_private.c
	x86_64-w64-mingw32-gcc -c -o               \
	error_private_64arp.o                      \
	../../lib/common/error_private.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	error_private_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

fse_decompress_64arp.o :                           \
	../../lib/common/fse_decompress.c
	x86_64-w64-mingw32-gcc -c -o               \
	fse_decompress_64arp.o                     \
	../../lib/common/fse_decompress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	fse_decompress_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pool_64arp.o : ../../lib/common/pool.c
	x86_64-w64-mingw32-gcc -c -o               \
	pool_64arp.o ../../lib/common/pool.c       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pool_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

threading_64arp.o : ../../lib/common/threading.c
	x86_64-w64-mingw32-gcc -c -o               \
	threading_64arp.o                          \
	../../lib/common/threading.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	threading_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

xxhash_64arp.o : ../../lib/common/xxhash.c
	x86_64-w64-mingw32-gcc -c -o               \
	xxhash_64arp.o ../../lib/common/xxhash.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	xxhash_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_common_64arp.o :                              \
	../../lib/common/zstd_common.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_common_64arp.o                        \
	../../lib/common/zstd_common.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_common_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

fse_compress_64arp.o:                              \
	../../lib/compress/fse_compress.c
	x86_64-w64-mingw32-gcc -c -o               \
	fse_compress_64arp.o                       \
	../../lib/compress/fse_compress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	fse_compress_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

hist_64arp.o : ../../lib/compress/hist.c
	x86_64-w64-mingw32-gcc -c -o               \
	hist_64arp.o                               \
	../../lib/compress/hist.c                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	hist_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

huf_compress_64arp.o :                             \
	../../lib/compress/huf_compress.c
	x86_64-w64-mingw32-gcc -c -o               \
	huf_compress_64arp.o                       \
	../../lib/compress/huf_compress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	huf_compress_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_compress_64arp.o :                            \
	../../lib/compress/zstd_compress.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_compress_64arp.o                      \
	../../lib/compress/zstd_compress.c         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_compress_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_compress_literals_64arp.o :                   \
	../../lib/compress/zstd_compress_literals.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_compress_literals_64arp.o             \
	../../lib/compress/zstd_compress_literals.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_compress_literals_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_compress_sequences_64arp.o :                  \
	../../lib/compress/zstd_compress_sequences.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_compress_sequences_64arp.o            \
	../../lib/compress/zstd_compress_sequences.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_compress_sequences_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_compress_superblock_64arp.o :                 \
	../../lib/compress/zstd_compress_superblock.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_compress_superblock_64arp.o           \
	../../lib/compress/zstd_compress_superblock.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_compress_superblock_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_double_fast_64arp.o :                         \
	../../lib/compress/zstd_double_fast.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_double_fast_64arp.o                   \
	../../lib/compress/zstd_double_fast.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_double_fast_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_fast_64arp.o :                                \
	../../lib/compress/zstd_fast.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_fast_64arp.o                          \
	../../lib/compress/zstd_fast.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_fast_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_lazy_64arp.o :                                \
	../../lib/compress/zstd_lazy.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_lazy_64arp.o                          \
	../../lib/compress/zstd_lazy.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_lazy_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_ldm_64arp.o : ../../lib/compress/zstd_ldm.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_ldm_64arp.o                           \
	../../lib/compress/zstd_ldm.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_ldm_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_opt_64arp.o : ../../lib/compress/zstd_opt.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_opt_64arp.o                           \
	../../lib/compress/zstd_opt.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_opt_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstdmt_compress_64arp.o :                          \
	../../lib/compress/zstdmt_compress.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstdmt_compress_64arp.o                    \
	../../lib/compress/zstdmt_compress.c       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstdmt_compress_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

huf_decompress_64arp.o :                           \
	../../lib/decompress/huf_decompress.c
	x86_64-w64-mingw32-gcc -c -o               \
	huf_decompress_64arp.o                     \
	../../lib/decompress/huf_decompress.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	huf_decompress_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_ddict_64arp.o :                               \
	../../lib/decompress/zstd_ddict.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_ddict_64arp.o                         \
	../../lib/decompress/zstd_ddict.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_ddict_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_decompress_64arp.o :                          \
	../../lib/decompress/zstd_decompress.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_decompress_64arp.o                    \
	../../lib/decompress/zstd_decompress.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_decompress_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_decompress_block_64arp.o :                    \
	../../lib/decompress/zstd_decompress_block.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_decompress_block_64arp.o              \
	../../lib/decompress/zstd_decompress_block.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_decompress_block_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

cover_64arp.o : ../../lib/dictBuilder/cover.c
	x86_64-w64-mingw32-gcc -c -o               \
	cover_64arp.o ../../lib/dictBuilder/cover.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	cover_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

divsufsort_64arp.o :                               \
	../../lib/dictBuilder/divsufsort.c
	x86_64-w64-mingw32-gcc -c -o               \
	divsufsort_64arp.o                         \
	../../lib/dictBuilder/divsufsort.c         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	divsufsort_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

fastcover_64arp.o :                                \
	../../lib/dictBuilder/fastcover.c
	x86_64-w64-mingw32-gcc -c -o               \
	fastcover_64arp.o                          \
	../../lib/dictBuilder/fastcover.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	fastcover_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zdict_64arp.o : ../../lib/dictBuilder/zdict.c
	x86_64-w64-mingw32-gcc -c -o               \
	zdict_64arp.o                              \
	../../lib/dictBuilder/zdict.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zdict_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v01_64arp.o : ../../lib/legacy/zstd_v01.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_v01_64arp.o ../../lib/legacy/zstd_v01.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_v01_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v02_64arp.o : ../../lib/legacy/zstd_v02.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_v02_64arp.o ../../lib/legacy/zstd_v02.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_v02_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v03_64arp.o : ../../lib/legacy/zstd_v03.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_v03_64arp.o                           \
	../../lib/legacy/zstd_v03.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_v03_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v04_64arp.o : ../../lib/legacy/zstd_v04.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_v04_64arp.o                           \
	../../lib/legacy/zstd_v04.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_v04_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v05_64arp.o : ../../lib/legacy/zstd_v05.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_v05_64arp.o                           \
	../../lib/legacy/zstd_v05.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_v05_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v06_64arp.o : ../../lib/legacy/zstd_v06.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_v06_64arp.o                           \
	../../lib/legacy/zstd_v06.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_v06_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstd_v07_64arp.o : ../../lib/legacy/zstd_v07.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstd_v07_64arp.o                           \
	../../lib/legacy/zstd_v07.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstd_v07_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

benchfn_64arp.o : ../../programs/benchfn.c
	x86_64-w64-mingw32-gcc -c -o               \
	benchfn_64arp.o                            \
	../../programs/benchfn.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	benchfn_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

benchzstd_64arp.o : ../../programs/benchzstd.c
	x86_64-w64-mingw32-gcc -c -o               \
	benchzstd_64arp.o                          \
	../../programs/benchzstd.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	benchzstd_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

datagen_64arp.o : ../../programs/datagen.c
	x86_64-w64-mingw32-gcc -c -o               \
	datagen_64arp.o ../../programs/datagen.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	datagen_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

dibio_64arp.o : ../../programs/dibio.c
	x86_64-w64-mingw32-gcc -c -o               \
	dibio_64arp.o ../../programs/dibio.c       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	dibio_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

fileio_64arp.o : ../../programs/fileio.c
	x86_64-w64-mingw32-gcc -c -o               \
	fileio_64arp.o ../../programs/fileio.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	fileio_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

timefn_64arp.o : ../../programs/timefn.c
	x86_64-w64-mingw32-gcc -c -o               \
	timefn_64arp.o ../../programs/timefn.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	timefn_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

util_64arp.o : ../../programs/util.c
	x86_64-w64-mingw32-gcc -c -o               \
	util_64arp.o -DARP_MISSING_WDM_HEADER__    \
	../../programs/util.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	util_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

zstdcli_64arp.o : ../../programs/zstdcli.c
	x86_64-w64-mingw32-gcc -c -o               \
	zstdcli_64arp.o ../../programs/zstdcli.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zstdcli_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

arp_dll_64arp.o : \
	../../programs/helper_utilities_by_amanda_and_ricardo.c \
	../../programs/arp_dll.c
	x86_64-w64-mingw32-gcc -c -o               \
	arp_dll_64arp.o ../../programs/arp_dll.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	arp_dll_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_64arp.o : pedro.c
	x86_64-w64-mingw32-gcc -c -o               \
	pedro_64arp.o                              \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)
