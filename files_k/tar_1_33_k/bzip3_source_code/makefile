AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =

AMANDA_SIZE__ =                                   62

amanda_32: pedro_32.o                              \
	blocksort_32.o bzip2_32.o bzip2dll_32.o    \
	bzip3_32.o bzip3_multi_32.o                \
	bzlib_32.o compress_32.o                   \
	cpu_fixed_k_32.o crctable_32.o             \
	decompress_32.o	             folder_i_32.o \
	huffman_32.o longfile_32.o md5_32.o        \
	randtable_32.o sha512_k_32.o stdio_v2_32.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	pedro_32.o	                           \
	blocksort_32.o bzip2_32.o bzip2dll_32.o    \
	bzip3_32.o bzip3_multi_32.o                \
	bzlib_32.o compress_32.o                   \
	cpu_fixed_k_32.o crctable_32.o             \
	decompress_32.o	             folder_i_32.o \
	huffman_32.o longfile_32.o md5_32.o        \
	randtable_32.o sha512_k_32.o stdio_v2_32.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini versio_n.ama.rc \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h "31.5 bits ;-)" \
	rsp_bzip3_32.DLL increase

	@i686-w64-mingw32-windres.exe -o ver32.o -O  \
	coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -O3 -mdll        \
	-o rsp_bzip3_32.DLL dll_k.def              \
	pedro_32.o	                           \
	blocksort_32.o bzip2_32.o bzip2dll_32.o    \
	bzip3_32.o bzip3_multi_32.o                \
	bzlib_32.o compress_32.o                   \
	cpu_fixed_k_32.o crctable_32.o             \
	decompress_32.o	             folder_i_32.o \
	huffman_32.o longfile_32.o md5_32.o        \
	randtable_32.o sha512_k_32.o stdio_v2_32.o \
	ver32.o -Wl,-enable-stdcall-fixup

	@cp rsp_bzip3_32.DLL ../
	@cp rsp_bzip3_32.DLL                         'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'
	@./espaco_arp.exe $(AMANDA_SIZE__)

bzip3_multi_32.o: stdio_v2.c stdio_v2.h            \
	bzip3_thread.c bzip3_structs_z.h           \
	bzip3_multi.c
	i686-w64-mingw32-gcc.exe -c -o             \
	bzip3_multi_32.o bzip3_multi.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	bzip3_multi_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

stdio_v2_32.o: stdio_v2.c stdio_v2.h
	i686-w64-mingw32-gcc.exe -c -o             \
	stdio_v2_32.o                              \
	stdio_v2.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	stdio_v2_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

bzip2dll_32.o: bzip2dll.c
	i686-w64-mingw32-gcc.exe -c -o             \
	bzip2dll_32.o                              \
	bzip2dll.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	bzip2dll_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

blocksort_32.o: blocksort.c
	i686-w64-mingw32-gcc.exe -c -o             \
	blocksort_32.o blocksort.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	blocksort_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

bzip2_32.o: bzip2.c
	i686-w64-mingw32-gcc.exe -c -o             \
	bzip2_32.o                                 \
	bzip2.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	bzip2_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

bzlib_32.o: bzlib.c
	i686-w64-mingw32-gcc.exe -c -o             \
	bzlib_32.o                                 \
	bzlib.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	bzlib_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

compress_32.o: compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress_32.o                              \
	compress.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

crctable_32.o: crctable.c
	i686-w64-mingw32-gcc.exe -c -o             \
	crctable_32.o                              \
	crctable.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	crctable_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

decompress_32.o: decompress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	decompress_32.o decompress.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	decompress_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

huffman_32.o: huffman.c
	i686-w64-mingw32-gcc.exe -c -o             \
	huffman_32.o                               \
	huffman.c                                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	huffman_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

randtable_32.o: randtable.c
	i686-w64-mingw32-gcc.exe -c -o             \
	randtable_32.o randtable.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	randtable_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

folder_i_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o             \
	folder_i_32.o                              \
	folder.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	folder_i_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

md5_32.o: md5.c
	i686-w64-mingw32-gcc.exe -c -o             \
	md5_32.o                                   \
	md5.c                                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	md5_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o             \
	longfile_32.o                              \
	longfile.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	longfile_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

bzip3_32.o: bzip3.c stdio_v2.h                     \
	bzip3_decoder_mt_z.c bzip3_structs_z.h
	i686-w64-mingw32-gcc.exe -c -o             \
	bzip3_32.o                                 \
	bzip3.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	bzip3_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

sha512_k_32.o: sha512_k.c
	i686-w64-mingw32-gcc.exe -c -o             \
	sha512_k_32.o                              \
	sha512_k.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	sha512_k_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

cpu_fixed_k_32.o: cpu_fixed_k.c
	i686-w64-mingw32-gcc.exe -c -o             \
	cpu_fixed_k_32.o cpu_fixed_k.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	cpu_fixed_k_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_32.o:                                        \
	pedro.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32.o                                 \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pedro_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

ricardo_64: pedro_64.o                             \
	blocksort_64.o bzip2_64.o bzip2dll_64.o    \
	bzip3_64.o bzip3_multi_64.o                \
	bzlib_64.o compress_64.o                   \
	cpu_fixed_k_64.o crctable_64.o             \
	decompress_64.o folder_64.o huffman_64.o   \
	longfile_64.o md5_64.o randtable_64.o      \
	sha512_k_64.o stdio_v2_64.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	pedro_64.o                                 \
	blocksort_64.o bzip2_64.o bzip2dll_64.o    \
	bzip3_64.o bzip3_multi_64.o                \
	bzlib_64.o compress_64.o                   \
	cpu_fixed_k_64.o crctable_64.o             \
	decompress_64.o folder_64.o huffman_64.o   \
	longfile_64.o md5_64.o randtable_64.o      \
	sha512_k_64.o stdio_v2_64.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini versio_n.ama.rc \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h "63.5 bits ;-)" \
	rsp_bzip3_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o ver64.o \
	-O coff version_ricardo_mislaine_final_2_.rc

	x86_64-w64-mingw32-gcc -mdll -O3 -o        \
	rsp_bzip3_64.DLL dll_k.def ver64.o         \
	pedro_64.o                                 \
	blocksort_64.o bzip2_64.o bzip2dll_64.o    \
	bzip3_64.o bzip3_multi_64.o                \
	bzlib_64.o compress_64.o                   \
	cpu_fixed_k_64.o crctable_64.o             \
	decompress_64.o folder_64.o huffman_64.o   \
	longfile_64.o md5_64.o randtable_64.o      \
	sha512_k_64.o stdio_v2_64.o                \
	-Wl,-enable-stdcall-fixup

	@cp rsp_bzip3_64.DLL ../
	@cp rsp_bzip3_64.DLL                         'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'
	@./espaco_arp.exe $(AMANDA_SIZE__)

bzip3_multi_64.o: stdio_v2.c stdio_v2.h            \
	bzip3_thread.c bzip3_structs_z.h           \
	bzip3_multi.c
	x86_64-w64-mingw32-gcc -c -o               \
	bzip3_multi_64.o bzip3_multi.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	bzip3_multi_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

stdio_v2_64.o: stdio_v2.c stdio_v2.h
	x86_64-w64-mingw32-gcc -c -o               \
	stdio_v2_64.o                              \
	stdio_v2.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	stdio_v2_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

bzip2dll_64.o: bzip2dll.c
	x86_64-w64-mingw32-gcc -c -o               \
	bzip2dll_64.o                              \
	bzip2dll.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	bzip2dll_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

blocksort_64.o: blocksort.c
	x86_64-w64-mingw32-gcc -c -o               \
	blocksort_64.o                             \
	blocksort.c                                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	blocksort_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

bzip2_64.o: bzip2.c
	x86_64-w64-mingw32-gcc -c -o               \
	bzip2_64.o                                 \
	bzip2.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	bzip2_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

bzlib_64.o: bzlib.c
	x86_64-w64-mingw32-gcc -c -o               \
	bzlib_64.o                                 \
	bzlib.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	bzlib_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

compress_64.o: compress.c
	x86_64-w64-mingw32-gcc -c -o               \
	compress_64.o                              \
	compress.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

crctable_64.o: crctable.c
	x86_64-w64-mingw32-gcc -c -o               \
	crctable_64.o                              \
	crctable.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	crctable_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

decompress_64.o: decompress.c
	x86_64-w64-mingw32-gcc -c -o               \
	decompress_64.o                            \
	decompress.c                               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	decompress_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

huffman_64.o: huffman.c
	x86_64-w64-mingw32-gcc -c -o               \
	huffman_64.o                               \
	huffman.c                                  \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	huffman_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

randtable_64.o: randtable.c
	x86_64-w64-mingw32-gcc -c -o               \
	randtable_64.o                             \
	randtable.c                                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	randtable_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

folder_64.o: folder.c
	x86_64-w64-mingw32-gcc -c -o               \
	folder_64.o                                \
	folder.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	folder_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

md5_64.o: md5.c
	x86_64-w64-mingw32-gcc -c -o               \
	md5_64.o md5.c                             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	md5_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc -c -o               \
	longfile_64.o                              \
	longfile.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	longfile_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

bzip3_64.o: bzip3.c stdio_v2.h                     \
	bzip3_decoder_mt_z.c bzip3_structs_z.h
	x86_64-w64-mingw32-gcc -c -o               \
	bzip3_64.o                                 \
	bzip3.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	bzip3_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

sha512_k_64.o: sha512_k.c
	x86_64-w64-mingw32-gcc -c -o               \
	sha512_k_64.o                              \
	sha512_k.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	sha512_k_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

cpu_fixed_k_64.o: cpu_fixed_k.c
	x86_64-w64-mingw32-gcc -c -o               \
	cpu_fixed_k_64.o cpu_fixed_k.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	cpu_fixed_k_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_64.o: pedro.c
	x86_64-w64-mingw32-gcc -c -o               \
	pedro_64.o                                 \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

cpu_detect_k:
	x86_64-w64-mingw32-gcc.exe -O3 -o          \
	cpu64_k.exe cpu_k.c
	i686-w64-mingw32-gcc.exe.exe               \
	-msse -O3 -o cpu32_k.exe cpu_k.c
	@./espaco_arp.exe $(AMANDA_SIZE__)

