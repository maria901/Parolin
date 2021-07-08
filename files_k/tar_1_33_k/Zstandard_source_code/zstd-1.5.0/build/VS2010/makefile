#amanda & MathMan 2021 May

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -DZSTD_MULTITHREAD
JULIET_FLAGS  = 

AMANDA_SIZE   =                                    62

amanda_32: pedro_32KP.o                            \
	../../programs/arp_dll_32KP.o              \
	../../lib/common/debug_32KP.o              \
	../../lib/common/entropy_common_32KP.o     \
	../../lib/common/error_private_32KP.o      \
	../../lib/common/fse_decompress_32KP.o     \
	../../lib/common/pool_32KP.o               \
	../../lib/common/threading_32KP.o          \
	../../lib/common/xxhash_32KP.o             \
	../../lib/common/zstd_common_32KP.o        \
	../../lib/compress/fse_compress_32KP.o     \
	../../lib/compress/hist_32KP.o             \
	../../lib/compress/huf_compress_32KP.o     \
	../../lib/compress/zstd_compress_32KP.o    \
	../../lib/compress/zstd_compress_literals_32KP.o   \
	../../lib/compress/zstd_compress_sequences_32KP.o  \
	../../lib/compress/zstd_compress_superblock_32KP.o  \
	../../lib/compress/zstd_double_fast_32KP.o          \
	../../lib/compress/zstd_fast_32KP.o                 \
	../../lib/compress/zstd_lazy_32KP.o                 \
	../../lib/compress/zstd_ldm_32KP.o                  \
	../../lib/compress/zstd_opt_32KP.o                  \
	../../lib/compress/zstdmt_compress_32KP.o           \
	../../lib/decompress/huf_decompress_32KP.o          \
	../../lib/decompress/zstd_ddict_32KP.o     \
	../../lib/decompress/zstd_decompress_32KP.o  \
	../../lib/decompress/zstd_decompress_block_32KP.o   \
	../../lib/dictBuilder/cover_32KP.o         \
	../../lib/dictBuilder/divsufsort_32KP.o    \
	../../lib/dictBuilder/fastcover_32KP.o     \
	../../lib/dictBuilder/zdict_32KP.o         \
	../../lib/legacy/zstd_v01_32KP.o           \
	../../lib/legacy/zstd_v02_32KP.o           \
	../../lib/legacy/zstd_v03_32KP.o           \
	../../lib/legacy/zstd_v04_32KP.o           \
	../../lib/legacy/zstd_v05_32KP.o           \
	../../lib/legacy/zstd_v06_32KP.o           \
	../../lib/legacy/zstd_v07_32KP.o           \
	../../programs/benchfn_32KP.o              \
	../../programs/benchzstd_32KP.o            \
	../../programs/datagen_32KP.o              \
	../../programs/dibio_32KP.o                \
	../../programs/fileio_32KP.o               \
	../../programs/timefn_32KP.o               \
	../../programs/util_32KP.o                 \
	../../programs/zstdcli_32KP.o              \
	../../programs/zstdcli_trace_32KP.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	pedro_32KP.o                               \
	../../programs/arp_dll_32KP.o              \
	../../lib/common/debug_32KP.o              \
	../../lib/common/entropy_common_32KP.o     \
	../../lib/common/error_private_32KP.o      \
	../../lib/common/fse_decompress_32KP.o     \
	../../lib/common/pool_32KP.o               \
	../../lib/common/threading_32KP.o          \
	../../lib/common/xxhash_32KP.o             \
	../../lib/common/zstd_common_32KP.o        \
	../../lib/compress/fse_compress_32KP.o     \
	../../lib/compress/hist_32KP.o             \
	../../lib/compress/huf_compress_32KP.o     \
	../../lib/compress/zstd_compress_32KP.o    \
	../../lib/compress/zstd_compress_literals_32KP.o   \
	../../lib/compress/zstd_compress_sequences_32KP.o  \
	../../lib/compress/zstd_compress_superblock_32KP.o  \
	../../lib/compress/zstd_double_fast_32KP.o          \
	../../lib/compress/zstd_fast_32KP.o                 \
	../../lib/compress/zstd_lazy_32KP.o                 \
	../../lib/compress/zstd_ldm_32KP.o                  \
	../../lib/compress/zstd_opt_32KP.o                  \
	../../lib/compress/zstdmt_compress_32KP.o           \
	../../lib/decompress/huf_decompress_32KP.o          \
	../../lib/decompress/zstd_ddict_32KP.o     \
	../../lib/decompress/zstd_decompress_32KP.o  \
	../../lib/decompress/zstd_decompress_block_32KP.o   \
	../../lib/dictBuilder/cover_32KP.o         \
	../../lib/dictBuilder/divsufsort_32KP.o    \
	../../lib/dictBuilder/fastcover_32KP.o     \
	../../lib/dictBuilder/zdict_32KP.o         \
	../../lib/legacy/zstd_v01_32KP.o           \
	../../lib/legacy/zstd_v02_32KP.o           \
	../../lib/legacy/zstd_v03_32KP.o           \
	../../lib/legacy/zstd_v04_32KP.o           \
	../../lib/legacy/zstd_v05_32KP.o           \
	../../lib/legacy/zstd_v06_32KP.o           \
	../../lib/legacy/zstd_v07_32KP.o           \
	../../programs/benchfn_32KP.o              \
	../../programs/benchzstd_32KP.o            \
	../../programs/datagen_32KP.o              \
	../../programs/dibio_32KP.o                \
	../../programs/fileio_32KP.o               \
	../../programs/timefn_32KP.o               \
	../../programs/util_32KP.o                 \
	../../programs/zstdcli_32KP.o              \
	../../programs/zstdcli_trace_32KP.o

	@i686-w64-mingw32-gcc.exe -O3 -o           \
	RSP_Zstandard_arp_32.DLL arp.def -mdll     \
	pedro_32KP.o                               \
	../../programs/arp_dll_32KP.o              \
	../../lib/common/debug_32KP.o              \
	../../lib/common/entropy_common_32KP.o     \
	../../lib/common/error_private_32KP.o      \
	../../lib/common/fse_decompress_32KP.o     \
	../../lib/common/pool_32KP.o               \
	../../lib/common/threading_32KP.o          \
	../../lib/common/xxhash_32KP.o             \
	../../lib/common/zstd_common_32KP.o        \
	../../lib/compress/fse_compress_32KP.o     \
	../../lib/compress/hist_32KP.o             \
	../../lib/compress/huf_compress_32KP.o     \
	../../lib/compress/zstd_compress_32KP.o    \
	../../lib/compress/zstd_compress_literals_32KP.o   \
	../../lib/compress/zstd_compress_sequences_32KP.o  \
	../../lib/compress/zstd_compress_superblock_32KP.o  \
	../../lib/compress/zstd_double_fast_32KP.o          \
	../../lib/compress/zstd_fast_32KP.o                 \
	../../lib/compress/zstd_lazy_32KP.o                 \
	../../lib/compress/zstd_ldm_32KP.o                  \
	../../lib/compress/zstd_opt_32KP.o                  \
	../../lib/compress/zstdmt_compress_32KP.o           \
	../../lib/decompress/huf_decompress_32KP.o          \
	../../lib/decompress/zstd_ddict_32KP.o     \
	../../lib/decompress/zstd_decompress_32KP.o  \
	../../lib/decompress/zstd_decompress_block_32KP.o   \
	../../lib/dictBuilder/cover_32KP.o         \
	../../lib/dictBuilder/divsufsort_32KP.o    \
	../../lib/dictBuilder/fastcover_32KP.o     \
	../../lib/dictBuilder/zdict_32KP.o         \
	../../lib/legacy/zstd_v01_32KP.o           \
	../../lib/legacy/zstd_v02_32KP.o           \
	../../lib/legacy/zstd_v03_32KP.o           \
	../../lib/legacy/zstd_v04_32KP.o           \
	../../lib/legacy/zstd_v05_32KP.o           \
	../../lib/legacy/zstd_v06_32KP.o           \
	../../lib/legacy/zstd_v07_32KP.o           \
	../../programs/benchfn_32KP.o              \
	../../programs/benchzstd_32KP.o            \
	../../programs/datagen_32KP.o              \
	../../programs/dibio_32KP.o                \
	../../programs/fileio_32KP.o               \
	../../programs/timefn_32KP.o               \
	../../programs/util_32KP.o                 \
	../../programs/zstdcli_32KP.o              \
	../../programs/zstdcli_trace_32KP.o        \
	-Wl,-enable-stdcall-fixup

	@cp RSP_Zstandard_arp_32.DLL ../../../../

	@cp RSP_Zstandard_arp_32.DLL               'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe $(AMANDA_SIZE)

	@./espaco_arp.exe $(AMANDA_SIZE) 27


pedro_32KP.o : pedro.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32KP.o                               \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pedro_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/arp_dll_32KP.o : ../../programs/arp_dll.c \
	../../programs/helper_utilities_by_amanda_and_ricardo.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/arp_dll_32KP.o              \
	../../programs/arp_dll.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/arp_dll_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/debug_32KP.o : ../../lib/common/debug.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/common/debug_32KP.o              \
	../../lib/common/debug.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/common/debug_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/entropy_common_32KP.o : ../../lib/common/entropy_common.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/common/entropy_common_32KP.o     \
	../../lib/common/entropy_common.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/common/entropy_common_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/error_private_32KP.o : ../../lib/common/error_private.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/common/error_private_32KP.o      \
	../../lib/common/error_private.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/common/error_private_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/fse_decompress_32KP.o : ../../lib/common/fse_decompress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/common/fse_decompress_32KP.o     \
	../../lib/common/fse_decompress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/common/fse_decompress_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/pool_32KP.o : ../../lib/common/pool.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/common/pool_32KP.o               \
	../../lib/common/pool.c                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/common/pool_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/threading_32KP.o : ../../lib/common/threading.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/common/threading_32KP.o          \
	../../lib/common/threading.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/common/threading_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/xxhash_32KP.o : ../../lib/common/xxhash.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/common/xxhash_32KP.o             \
	../../lib/common/xxhash.c                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/common/xxhash_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/zstd_common_32KP.o : ../../lib/common/zstd_common.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/common/zstd_common_32KP.o        \
	../../lib/common/zstd_common.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/common/zstd_common_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/fse_compress_32KP.o : ../../lib/compress/fse_compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/fse_compress_32KP.o     \
	../../lib/compress/fse_compress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/fse_compress_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/hist_32KP.o : ../../lib/compress/hist.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/hist_32KP.o             \
	../../lib/compress/hist.c                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/hist_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/huf_compress_32KP.o : ../../lib/compress/huf_compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/huf_compress_32KP.o     \
	../../lib/compress/huf_compress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/huf_compress_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_compress_32KP.o : ../../lib/compress/zstd_compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_compress_32KP.o    \
	../../lib/compress/zstd_compress.c         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_compress_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_compress_literals_32KP.o : ../../lib/compress/zstd_compress_literals.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_compress_literals_32KP.o \
	../../lib/compress/zstd_compress_literals.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_compress_literals_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_compress_sequences_32KP.o : ../../lib/compress/zstd_compress_sequences.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_compress_sequences_32KP.o \
	../../lib/compress/zstd_compress_sequences.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_compress_sequences_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_compress_superblock_32KP.o : ../../lib/compress/zstd_compress_superblock.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_compress_superblock_32KP.o \
	../../lib/compress/zstd_compress_superblock.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_compress_superblock_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_double_fast_32KP.o : ../../lib/compress/zstd_double_fast.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_double_fast_32KP.o \
	../../lib/compress/zstd_double_fast.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_double_fast_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_fast_32KP.o : ../../lib/compress/zstd_fast.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_fast_32KP.o        \
	../../lib/compress/zstd_fast.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_fast_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_lazy_32KP.o : ../../lib/compress/zstd_lazy.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_lazy_32KP.o        \
	../../lib/compress/zstd_lazy.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_lazy_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_ldm_32KP.o : ../../lib/compress/zstd_ldm.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_ldm_32KP.o         \
	../../lib/compress/zstd_ldm.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_ldm_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_opt_32KP.o : ../../lib/compress/zstd_opt.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstd_opt_32KP.o         \
	../../lib/compress/zstd_opt.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstd_opt_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstdmt_compress_32KP.o : ../../lib/compress/zstdmt_compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/compress/zstdmt_compress_32KP.o  \
	../../lib/compress/zstdmt_compress.c       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/compress/zstdmt_compress_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/decompress/huf_decompress_32KP.o : ../../lib/decompress/huf_decompress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/decompress/huf_decompress_32KP.o \
	../../lib/decompress/huf_decompress.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/decompress/huf_decompress_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/decompress/zstd_ddict_32KP.o : ../../lib/decompress/zstd_ddict.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/decompress/zstd_ddict_32KP.o     \
	../../lib/decompress/zstd_ddict.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/decompress/zstd_ddict_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/decompress/zstd_decompress_32KP.o : ../../lib/decompress/zstd_decompress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/decompress/zstd_decompress_32KP.o \
	../../lib/decompress/zstd_decompress.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/decompress/zstd_decompress_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/decompress/zstd_decompress_block_32KP.o : ../../lib/decompress/zstd_decompress_block.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/decompress/zstd_decompress_block_32KP.o \
	../../lib/decompress/zstd_decompress_block.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/decompress/zstd_decompress_block_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/dictBuilder/cover_32KP.o : ../../lib/dictBuilder/cover.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/dictBuilder/cover_32KP.o         \
	../../lib/dictBuilder/cover.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/dictBuilder/cover_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/dictBuilder/divsufsort_32KP.o : ../../lib/dictBuilder/divsufsort.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/dictBuilder/divsufsort_32KP.o    \
	../../lib/dictBuilder/divsufsort.c         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/dictBuilder/divsufsort_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/dictBuilder/fastcover_32KP.o : ../../lib/dictBuilder/fastcover.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/dictBuilder/fastcover_32KP.o     \
	../../lib/dictBuilder/fastcover.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/dictBuilder/fastcover_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/dictBuilder/zdict_32KP.o : ../../lib/dictBuilder/zdict.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/dictBuilder/zdict_32KP.o         \
	../../lib/dictBuilder/zdict.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/dictBuilder/zdict_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v01_32KP.o : ../../lib/legacy/zstd_v01.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/legacy/zstd_v01_32KP.o           \
	../../lib/legacy/zstd_v01.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/legacy/zstd_v01_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v02_32KP.o : ../../lib/legacy/zstd_v02.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/legacy/zstd_v02_32KP.o           \
	../../lib/legacy/zstd_v02.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/legacy/zstd_v02_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v03_32KP.o : ../../lib/legacy/zstd_v03.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/legacy/zstd_v03_32KP.o           \
	../../lib/legacy/zstd_v03.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/legacy/zstd_v03_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v04_32KP.o : ../../lib/legacy/zstd_v04.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/legacy/zstd_v04_32KP.o           \
	../../lib/legacy/zstd_v04.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/legacy/zstd_v04_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v05_32KP.o : ../../lib/legacy/zstd_v05.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/legacy/zstd_v05_32KP.o           \
	../../lib/legacy/zstd_v05.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/legacy/zstd_v05_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v06_32KP.o : ../../lib/legacy/zstd_v06.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/legacy/zstd_v06_32KP.o           \
	../../lib/legacy/zstd_v06.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/legacy/zstd_v06_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v07_32KP.o : ../../lib/legacy/zstd_v07.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../lib/legacy/zstd_v07_32KP.o           \
	../../lib/legacy/zstd_v07.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../lib/legacy/zstd_v07_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/benchfn_32KP.o : ../../programs/benchfn.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/benchfn_32KP.o              \
	../../programs/benchfn.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/benchfn_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/benchzstd_32KP.o : ../../programs/benchzstd.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/benchzstd_32KP.o            \
	../../programs/benchzstd.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/benchzstd_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/datagen_32KP.o : ../../programs/datagen.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/datagen_32KP.o              \
	../../programs/datagen.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/datagen_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/dibio_32KP.o : ../../programs/dibio.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/dibio_32KP.o                \
	../../programs/dibio.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/dibio_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/fileio_32KP.o : ../../programs/fileio.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/fileio_32KP.o               \
	../../programs/fileio.c                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/fileio_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/timefn_32KP.o : ../../programs/timefn.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/timefn_32KP.o               \
	../../programs/timefn.c                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/timefn_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/util_32KP.o : ../../programs/util.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/util_32KP.o                 \
	../../programs/util.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/util_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/zstdcli_32KP.o : ../../programs/zstdcli.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/zstdcli_32KP.o              \
	../../programs/zstdcli.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/zstdcli_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/zstdcli_trace_32KP.o : ../../programs/zstdcli_trace.c
	i686-w64-mingw32-gcc.exe -c -o             \
	../../programs/zstdcli_trace_32KP.o        \
	../../programs/zstdcli_trace.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	../../programs/zstdcli_trace_32KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)



ricardo_64: pedro_64KP.o                           \
	../../programs/arp_dll_64KP.o              \
	../../lib/common/debug_64KP.o              \
	../../lib/common/entropy_common_64KP.o     \
	../../lib/common/error_private_64KP.o      \
	../../lib/common/fse_decompress_64KP.o     \
	../../lib/common/pool_64KP.o               \
	../../lib/common/threading_64KP.o          \
	../../lib/common/xxhash_64KP.o             \
	../../lib/common/zstd_common_64KP.o        \
	../../lib/compress/fse_compress_64KP.o     \
	../../lib/compress/hist_64KP.o             \
	../../lib/compress/huf_compress_64KP.o     \
	../../lib/compress/zstd_compress_64KP.o    \
	../../lib/compress/zstd_compress_literals_64KP.o   \
	../../lib/compress/zstd_compress_sequences_64KP.o  \
	../../lib/compress/zstd_compress_superblock_64KP.o  \
	../../lib/compress/zstd_double_fast_64KP.o          \
	../../lib/compress/zstd_fast_64KP.o                 \
	../../lib/compress/zstd_lazy_64KP.o                 \
	../../lib/compress/zstd_ldm_64KP.o                  \
	../../lib/compress/zstd_opt_64KP.o                  \
	../../lib/compress/zstdmt_compress_64KP.o           \
	../../lib/decompress/huf_decompress_64KP.o          \
	../../lib/decompress/zstd_ddict_64KP.o     \
	../../lib/decompress/zstd_decompress_64KP.o  \
	../../lib/decompress/zstd_decompress_block_64KP.o   \
	../../lib/dictBuilder/cover_64KP.o         \
	../../lib/dictBuilder/divsufsort_64KP.o    \
	../../lib/dictBuilder/fastcover_64KP.o     \
	../../lib/dictBuilder/zdict_64KP.o         \
	../../lib/legacy/zstd_v01_64KP.o           \
	../../lib/legacy/zstd_v02_64KP.o           \
	../../lib/legacy/zstd_v03_64KP.o           \
	../../lib/legacy/zstd_v04_64KP.o           \
	../../lib/legacy/zstd_v05_64KP.o           \
	../../lib/legacy/zstd_v06_64KP.o           \
	../../lib/legacy/zstd_v07_64KP.o           \
	../../programs/benchfn_64KP.o              \
	../../programs/benchzstd_64KP.o            \
	../../programs/datagen_64KP.o              \
	../../programs/dibio_64KP.o                \
	../../programs/fileio_64KP.o               \
	../../programs/timefn_64KP.o               \
	../../programs/util_64KP.o                 \
	../../programs/zstdcli_64KP.o              \
	../../programs/zstdcli_trace_64KP.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	pedro_64KP.o                               \
	../../programs/arp_dll_64KP.o              \
	../../lib/common/debug_64KP.o              \
	../../lib/common/entropy_common_64KP.o     \
	../../lib/common/error_private_64KP.o      \
	../../lib/common/fse_decompress_64KP.o     \
	../../lib/common/pool_64KP.o               \
	../../lib/common/threading_64KP.o          \
	../../lib/common/xxhash_64KP.o             \
	../../lib/common/zstd_common_64KP.o        \
	../../lib/compress/fse_compress_64KP.o     \
	../../lib/compress/hist_64KP.o             \
	../../lib/compress/huf_compress_64KP.o     \
	../../lib/compress/zstd_compress_64KP.o    \
	../../lib/compress/zstd_compress_literals_64KP.o   \
	../../lib/compress/zstd_compress_sequences_64KP.o  \
	../../lib/compress/zstd_compress_superblock_64KP.o  \
	../../lib/compress/zstd_double_fast_64KP.o          \
	../../lib/compress/zstd_fast_64KP.o                 \
	../../lib/compress/zstd_lazy_64KP.o                 \
	../../lib/compress/zstd_ldm_64KP.o                  \
	../../lib/compress/zstd_opt_64KP.o                  \
	../../lib/compress/zstdmt_compress_64KP.o           \
	../../lib/decompress/huf_decompress_64KP.o          \
	../../lib/decompress/zstd_ddict_64KP.o     \
	../../lib/decompress/zstd_decompress_64KP.o  \
	../../lib/decompress/zstd_decompress_block_64KP.o   \
	../../lib/dictBuilder/cover_64KP.o         \
	../../lib/dictBuilder/divsufsort_64KP.o    \
	../../lib/dictBuilder/fastcover_64KP.o     \
	../../lib/dictBuilder/zdict_64KP.o         \
	../../lib/legacy/zstd_v01_64KP.o           \
	../../lib/legacy/zstd_v02_64KP.o           \
	../../lib/legacy/zstd_v03_64KP.o           \
	../../lib/legacy/zstd_v04_64KP.o           \
	../../lib/legacy/zstd_v05_64KP.o           \
	../../lib/legacy/zstd_v06_64KP.o           \
	../../lib/legacy/zstd_v07_64KP.o           \
	../../programs/benchfn_64KP.o              \
	../../programs/benchzstd_64KP.o            \
	../../programs/datagen_64KP.o              \
	../../programs/dibio_64KP.o                \
	../../programs/fileio_64KP.o               \
	../../programs/timefn_64KP.o               \
	../../programs/util_64KP.o                 \
	../../programs/zstdcli_64KP.o              \
	../../programs/zstdcli_trace_64KP.o

	@x86_64-w64-mingw32-gcc -O3 -o             \
	RSP_Zstandard_arp_64.DLL arp.def -mdll     \
	pedro_64KP.o                               \
	../../programs/arp_dll_64KP.o              \
	../../lib/common/debug_64KP.o              \
	../../lib/common/entropy_common_64KP.o     \
	../../lib/common/error_private_64KP.o      \
	../../lib/common/fse_decompress_64KP.o     \
	../../lib/common/pool_64KP.o               \
	../../lib/common/threading_64KP.o          \
	../../lib/common/xxhash_64KP.o             \
	../../lib/common/zstd_common_64KP.o        \
	../../lib/compress/fse_compress_64KP.o     \
	../../lib/compress/hist_64KP.o             \
	../../lib/compress/huf_compress_64KP.o     \
	../../lib/compress/zstd_compress_64KP.o    \
	../../lib/compress/zstd_compress_literals_64KP.o   \
	../../lib/compress/zstd_compress_sequences_64KP.o  \
	../../lib/compress/zstd_compress_superblock_64KP.o  \
	../../lib/compress/zstd_double_fast_64KP.o          \
	../../lib/compress/zstd_fast_64KP.o                 \
	../../lib/compress/zstd_lazy_64KP.o                 \
	../../lib/compress/zstd_ldm_64KP.o                  \
	../../lib/compress/zstd_opt_64KP.o                  \
	../../lib/compress/zstdmt_compress_64KP.o           \
	../../lib/decompress/huf_decompress_64KP.o          \
	../../lib/decompress/zstd_ddict_64KP.o     \
	../../lib/decompress/zstd_decompress_64KP.o  \
	../../lib/decompress/zstd_decompress_block_64KP.o   \
	../../lib/dictBuilder/cover_64KP.o         \
	../../lib/dictBuilder/divsufsort_64KP.o    \
	../../lib/dictBuilder/fastcover_64KP.o     \
	../../lib/dictBuilder/zdict_64KP.o         \
	../../lib/legacy/zstd_v01_64KP.o           \
	../../lib/legacy/zstd_v02_64KP.o           \
	../../lib/legacy/zstd_v03_64KP.o           \
	../../lib/legacy/zstd_v04_64KP.o           \
	../../lib/legacy/zstd_v05_64KP.o           \
	../../lib/legacy/zstd_v06_64KP.o           \
	../../lib/legacy/zstd_v07_64KP.o           \
	../../programs/benchfn_64KP.o              \
	../../programs/benchzstd_64KP.o            \
	../../programs/datagen_64KP.o              \
	../../programs/dibio_64KP.o                \
	../../programs/fileio_64KP.o               \
	../../programs/timefn_64KP.o               \
	../../programs/util_64KP.o                 \
	../../programs/zstdcli_64KP.o              \
	../../programs/zstdcli_trace_64KP.o        \
	-Wl,-enable-stdcall-fixup

	@cp RSP_Zstandard_arp_64.DLL ../../../../

	@cp RSP_Zstandard_arp_64.DLL               'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@./espaco_arp.exe $(AMANDA_SIZE)

	@./espaco_arp.exe $(AMANDA_SIZE) 27


pedro_64KP.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	pedro_64KP.o                               \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/arp_dll_64KP.o : ../../programs/arp_dll.c \
	../../programs/helper_utilities_by_amanda_and_ricardo.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/arp_dll_64KP.o              \
	../../programs/arp_dll.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/arp_dll_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/debug_64KP.o : ../../lib/common/debug.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/common/debug_64KP.o              \
	../../lib/common/debug.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/common/debug_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/entropy_common_64KP.o : ../../lib/common/entropy_common.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/common/entropy_common_64KP.o     \
	../../lib/common/entropy_common.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/common/entropy_common_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/error_private_64KP.o : ../../lib/common/error_private.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/common/error_private_64KP.o      \
	../../lib/common/error_private.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/common/error_private_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/fse_decompress_64KP.o : ../../lib/common/fse_decompress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/common/fse_decompress_64KP.o     \
	../../lib/common/fse_decompress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/common/fse_decompress_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/pool_64KP.o : ../../lib/common/pool.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/common/pool_64KP.o               \
	../../lib/common/pool.c                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/common/pool_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/threading_64KP.o : ../../lib/common/threading.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/common/threading_64KP.o          \
	../../lib/common/threading.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/common/threading_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/xxhash_64KP.o : ../../lib/common/xxhash.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/common/xxhash_64KP.o             \
	../../lib/common/xxhash.c                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/common/xxhash_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/common/zstd_common_64KP.o : ../../lib/common/zstd_common.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/common/zstd_common_64KP.o        \
	../../lib/common/zstd_common.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/common/zstd_common_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/fse_compress_64KP.o : ../../lib/compress/fse_compress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/fse_compress_64KP.o     \
	../../lib/compress/fse_compress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/fse_compress_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/hist_64KP.o : ../../lib/compress/hist.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/hist_64KP.o             \
	../../lib/compress/hist.c                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/hist_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/huf_compress_64KP.o : ../../lib/compress/huf_compress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/huf_compress_64KP.o     \
	../../lib/compress/huf_compress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/huf_compress_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_compress_64KP.o : ../../lib/compress/zstd_compress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_compress_64KP.o    \
	../../lib/compress/zstd_compress.c         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_compress_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_compress_literals_64KP.o : ../../lib/compress/zstd_compress_literals.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_compress_literals_64KP.o \
	../../lib/compress/zstd_compress_literals.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_compress_literals_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_compress_sequences_64KP.o : ../../lib/compress/zstd_compress_sequences.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_compress_sequences_64KP.o \
	../../lib/compress/zstd_compress_sequences.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_compress_sequences_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_compress_superblock_64KP.o : ../../lib/compress/zstd_compress_superblock.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_compress_superblock_64KP.o \
	../../lib/compress/zstd_compress_superblock.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_compress_superblock_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_double_fast_64KP.o : ../../lib/compress/zstd_double_fast.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_double_fast_64KP.o \
	../../lib/compress/zstd_double_fast.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_double_fast_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_fast_64KP.o : ../../lib/compress/zstd_fast.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_fast_64KP.o        \
	../../lib/compress/zstd_fast.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_fast_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_lazy_64KP.o : ../../lib/compress/zstd_lazy.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_lazy_64KP.o        \
	../../lib/compress/zstd_lazy.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_lazy_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_ldm_64KP.o : ../../lib/compress/zstd_ldm.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_ldm_64KP.o         \
	../../lib/compress/zstd_ldm.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_ldm_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstd_opt_64KP.o : ../../lib/compress/zstd_opt.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstd_opt_64KP.o         \
	../../lib/compress/zstd_opt.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstd_opt_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/compress/zstdmt_compress_64KP.o : ../../lib/compress/zstdmt_compress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/compress/zstdmt_compress_64KP.o  \
	../../lib/compress/zstdmt_compress.c       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/compress/zstdmt_compress_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/decompress/huf_decompress_64KP.o : ../../lib/decompress/huf_decompress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/decompress/huf_decompress_64KP.o \
	../../lib/decompress/huf_decompress.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/decompress/huf_decompress_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/decompress/zstd_ddict_64KP.o : ../../lib/decompress/zstd_ddict.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/decompress/zstd_ddict_64KP.o     \
	../../lib/decompress/zstd_ddict.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/decompress/zstd_ddict_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/decompress/zstd_decompress_64KP.o : ../../lib/decompress/zstd_decompress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/decompress/zstd_decompress_64KP.o \
	../../lib/decompress/zstd_decompress.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/decompress/zstd_decompress_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/decompress/zstd_decompress_block_64KP.o : ../../lib/decompress/zstd_decompress_block.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/decompress/zstd_decompress_block_64KP.o \
	../../lib/decompress/zstd_decompress_block.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/decompress/zstd_decompress_block_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/dictBuilder/cover_64KP.o : ../../lib/dictBuilder/cover.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/dictBuilder/cover_64KP.o         \
	../../lib/dictBuilder/cover.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/dictBuilder/cover_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/dictBuilder/divsufsort_64KP.o : ../../lib/dictBuilder/divsufsort.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/dictBuilder/divsufsort_64KP.o    \
	../../lib/dictBuilder/divsufsort.c         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/dictBuilder/divsufsort_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/dictBuilder/fastcover_64KP.o : ../../lib/dictBuilder/fastcover.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/dictBuilder/fastcover_64KP.o     \
	../../lib/dictBuilder/fastcover.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/dictBuilder/fastcover_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/dictBuilder/zdict_64KP.o : ../../lib/dictBuilder/zdict.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/dictBuilder/zdict_64KP.o         \
	../../lib/dictBuilder/zdict.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/dictBuilder/zdict_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v01_64KP.o : ../../lib/legacy/zstd_v01.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/legacy/zstd_v01_64KP.o           \
	../../lib/legacy/zstd_v01.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/legacy/zstd_v01_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v02_64KP.o : ../../lib/legacy/zstd_v02.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/legacy/zstd_v02_64KP.o           \
	../../lib/legacy/zstd_v02.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/legacy/zstd_v02_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v03_64KP.o : ../../lib/legacy/zstd_v03.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/legacy/zstd_v03_64KP.o           \
	../../lib/legacy/zstd_v03.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/legacy/zstd_v03_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v04_64KP.o : ../../lib/legacy/zstd_v04.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/legacy/zstd_v04_64KP.o           \
	../../lib/legacy/zstd_v04.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/legacy/zstd_v04_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v05_64KP.o : ../../lib/legacy/zstd_v05.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/legacy/zstd_v05_64KP.o           \
	../../lib/legacy/zstd_v05.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/legacy/zstd_v05_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v06_64KP.o : ../../lib/legacy/zstd_v06.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/legacy/zstd_v06_64KP.o           \
	../../lib/legacy/zstd_v06.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/legacy/zstd_v06_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../lib/legacy/zstd_v07_64KP.o : ../../lib/legacy/zstd_v07.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../lib/legacy/zstd_v07_64KP.o           \
	../../lib/legacy/zstd_v07.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../lib/legacy/zstd_v07_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/benchfn_64KP.o : ../../programs/benchfn.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/benchfn_64KP.o              \
	../../programs/benchfn.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/benchfn_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/benchzstd_64KP.o : ../../programs/benchzstd.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/benchzstd_64KP.o            \
	../../programs/benchzstd.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/benchzstd_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/datagen_64KP.o : ../../programs/datagen.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/datagen_64KP.o              \
	../../programs/datagen.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/datagen_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/dibio_64KP.o : ../../programs/dibio.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/dibio_64KP.o                \
	../../programs/dibio.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/dibio_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/fileio_64KP.o : ../../programs/fileio.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/fileio_64KP.o               \
	../../programs/fileio.c                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/fileio_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/timefn_64KP.o : ../../programs/timefn.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/timefn_64KP.o               \
	../../programs/timefn.c                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/timefn_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/util_64KP.o : ../../programs/util.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/util_64KP.o                 \
	../../programs/util.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/util_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/zstdcli_64KP.o : ../../programs/zstdcli.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/zstdcli_64KP.o              \
	../../programs/zstdcli.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/zstdcli_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

../../programs/zstdcli_trace_64KP.o : ../../programs/zstdcli_trace.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	../../programs/zstdcli_trace_64KP.o        \
	../../programs/zstdcli_trace.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	../../programs/zstdcli_trace_64KP.o

	@./espaco_arp.exe $(AMANDA_SIZE)

