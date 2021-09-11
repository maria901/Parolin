AMANDA_FLAGS__=-O3 -Wextra -Wall -Wfatal-errors -Werror -Wno-unused-function

amanda_32: /bw_tmp/bzip3/pedro_32.o /bw_tmp/bzip3/blocksort_32.o /bw_tmp/bzip3/bzip2_32.o /bw_tmp/bzip3/bzip2dll_32.o /bw_tmp/bzip3/bzip3_32.o /bw_tmp/bzip3/bzip3_multi_32.o /bw_tmp/bzip3/bzlib_32.o /bw_tmp/bzip3/compress_32.o /bw_tmp/bzip3/cpu_fixed_k_32.o /bw_tmp/bzip3/crctable_32.o /bw_tmp/bzip3/decompress_32.o /bw_tmp/bzip3/folder_i_32.o /bw_tmp/bzip3/huffman_32.o /bw_tmp/bzip3/longfile_32.o /bw_tmp/bzip3/md5_32.o /bw_tmp/bzip3/randtable_32.o /bw_tmp/bzip3/sha512_k_32.o /bw_tmp/bzip3/stdio_v2_32.o 

	-rm *.o *.DLL *.dll *.exe
	
	@/bw_tmp/amandaricardo_mvbuild26_33.exe ./amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "31.5 bits ;-)" rsp_bzip3_32.DLL increase

	@i686-w64-mingw32-windres.exe -o ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -O3 -mdll -o /bin/tar/x86/rsp_bzip3_32.DLL dll_k.def /bw_tmp/bzip3/pedro_32.o /bw_tmp/bzip3/blocksort_32.o /bw_tmp/bzip3/bzip2_32.o /bw_tmp/bzip3/bzip2dll_32.o /bw_tmp/bzip3/bzip3_32.o /bw_tmp/bzip3/bzip3_multi_32.o /bw_tmp/bzip3/bzlib_32.o /bw_tmp/bzip3/compress_32.o /bw_tmp/bzip3/cpu_fixed_k_32.o /bw_tmp/bzip3/crctable_32.o /bw_tmp/bzip3/decompress_32.o /bw_tmp/bzip3/folder_i_32.o /bw_tmp/bzip3/huffman_32.o /bw_tmp/bzip3/longfile_32.o /bw_tmp/bzip3/md5_32.o /bw_tmp/bzip3/randtable_32.o /bw_tmp/bzip3/sha512_k_32.o /bw_tmp/bzip3/stdio_v2_32.o ver32.o -Wl,-enable-stdcall-fixup

/bw_tmp/bzip3/bzip3_multi_32.o: stdio_v2.c stdio_v2.h bzip3_thread.c bzip3_structs_z.h bzip3_multi.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/bzip3_multi_32.o bzip3_multi.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/stdio_v2_32.o: stdio_v2.c stdio_v2.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/stdio_v2_32.o stdio_v2.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/bzip2dll_32.o: bzip2dll.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/bzip2dll_32.o bzip2dll.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/blocksort_32.o: blocksort.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/blocksort_32.o blocksort.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/bzip2_32.o: bzip2.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/bzip2_32.o bzip2.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/bzlib_32.o: bzlib.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/bzlib_32.o bzlib.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/compress_32.o: compress.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/compress_32.o compress.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/crctable_32.o: crctable.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/crctable_32.o crctable.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/decompress_32.o: decompress.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/decompress_32.o decompress.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/huffman_32.o: huffman.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/huffman_32.o huffman.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/randtable_32.o: randtable.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/randtable_32.o randtable.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/folder_i_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/folder_i_32.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/md5_32.o: md5.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/md5_32.o md5.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/longfile_32.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/bzip3_32.o: bzip3.c stdio_v2.h bzip3_decoder_mt_z.c bzip3_structs_z.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/bzip3_32.o bzip3.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/sha512_k_32.o: sha512_k.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/sha512_k_32.o sha512_k.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/cpu_fixed_k_32.o: cpu_fixed_k.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/cpu_fixed_k_32.o cpu_fixed_k.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/pedro_32.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip3/pedro_32.o pedro.c $(AMANDA_FLAGS__)

ricardo_64: /bw_tmp/bzip3/pedro_64.o /bw_tmp/bzip3/blocksort_64.o /bw_tmp/bzip3/bzip2_64.o /bw_tmp/bzip3/bzip2dll_64.o /bw_tmp/bzip3/bzip3_64.o /bw_tmp/bzip3/bzip3_multi_64.o /bw_tmp/bzip3/bzlib_64.o /bw_tmp/bzip3/compress_64.o /bw_tmp/bzip3/cpu_fixed_k_64.o /bw_tmp/bzip3/crctable_64.o /bw_tmp/bzip3/decompress_64.o /bw_tmp/bzip3/folder_64.o /bw_tmp/bzip3/huffman_64.o /bw_tmp/bzip3/longfile_64.o /bw_tmp/bzip3/md5_64.o /bw_tmp/bzip3/randtable_64.o /bw_tmp/bzip3/sha512_k_64.o /bw_tmp/bzip3/stdio_v2_64.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe ./amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "63.5 bits ;-)" rsp_bzip3_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/bzip3/ver64.o -O coff version_ricardo_mislaine_final_2_.rc

	x86_64-w64-mingw32-gcc -mdll -O3 -o /bin/tar/x64/rsp_bzip3_64.DLL dll_k.def /bw_tmp/bzip3/ver64.o /bw_tmp/bzip3/pedro_64.o /bw_tmp/bzip3/blocksort_64.o /bw_tmp/bzip3/bzip2_64.o /bw_tmp/bzip3/bzip2dll_64.o /bw_tmp/bzip3/bzip3_64.o /bw_tmp/bzip3/bzip3_multi_64.o /bw_tmp/bzip3/bzlib_64.o /bw_tmp/bzip3/compress_64.o /bw_tmp/bzip3/cpu_fixed_k_64.o /bw_tmp/bzip3/crctable_64.o /bw_tmp/bzip3/decompress_64.o /bw_tmp/bzip3/folder_64.o /bw_tmp/bzip3/huffman_64.o /bw_tmp/bzip3/longfile_64.o /bw_tmp/bzip3/md5_64.o /bw_tmp/bzip3/randtable_64.o /bw_tmp/bzip3/sha512_k_64.o /bw_tmp/bzip3/stdio_v2_64.o -Wl,-enable-stdcall-fixup

/bw_tmp/bzip3/bzip3_multi_64.o: stdio_v2.c stdio_v2.h bzip3_thread.c bzip3_structs_z.h bzip3_multi.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/bzip3_multi_64.o bzip3_multi.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/stdio_v2_64.o: stdio_v2.c stdio_v2.h
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/stdio_v2_64.o stdio_v2.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/bzip2dll_64.o: bzip2dll.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/bzip2dll_64.o bzip2dll.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/blocksort_64.o: blocksort.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/blocksort_64.o blocksort.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/bzip2_64.o: bzip2.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/bzip2_64.o bzip2.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/bzlib_64.o: bzlib.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/bzlib_64.o bzlib.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/compress_64.o: compress.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/compress_64.o compress.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/crctable_64.o: crctable.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/crctable_64.o crctable.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/decompress_64.o: decompress.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/decompress_64.o decompress.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/huffman_64.o: huffman.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/huffman_64.o huffman.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/randtable_64.o: randtable.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/randtable_64.o randtable.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/folder_64.o: folder.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/folder_64.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/md5_64.o: md5.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/md5_64.o md5.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/longfile_64.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/bzip3_64.o: bzip3.c stdio_v2.h bzip3_decoder_mt_z.c bzip3_structs_z.h
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/bzip3_64.o bzip3.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/sha512_k_64.o: sha512_k.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/sha512_k_64.o sha512_k.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/cpu_fixed_k_64.o: cpu_fixed_k.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/cpu_fixed_k_64.o cpu_fixed_k.c $(AMANDA_FLAGS__)

/bw_tmp/bzip3/pedro_64.o: pedro.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/bzip3/pedro_64.o pedro.c $(AMANDA_FLAGS__)

cpu_detect_k:
	x86_64-w64-mingw32-gcc.exe -O3 -o cpu64_k.exe cpu_k.c i686-w64-mingw32-gcc.exe.exe -msse -O3 -o cpu32_k.exe cpu_k.c