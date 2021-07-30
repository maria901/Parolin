#by amanda & MathMan, march 2021...
AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-unused-function -D_NET_

amanda_32: /bw_tmp/bzip2/pedro_32.o /bw_tmp/bzip2/blocksort_32.o /bw_tmp/bzip2/bzip2_32.o /bw_tmp/bzip2/bzip2dll_32.o /bw_tmp/bzip2/bzlib_32.o /bw_tmp/bzip2/compress_32.o /bw_tmp/bzip2/cpu_fixed_k_32.o /bw_tmp/bzip2/crctable_32.o /bw_tmp/bzip2/decompress_32.o /bw_tmp/bzip2/folder_i_32.o /bw_tmp/bzip2/huffman_32.o /bw_tmp/bzip2/longfile_32.o /bw_tmp/bzip2/randtable_32.o /bw_tmp/bzip2/sha512_k_32.o

#	-(rm *.o *.dll *.DLL)
	
	@/bw_tmp/amandaricardo_mvbuild26_33.exe ./amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" rspbzip2_32.dll increase

	@i686-w64-mingw32-windres.exe -o ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -mdll -O3  -o /bin/tar/x86/rspbzip2_32.dll dll_k.def /bw_tmp/bzip2/pedro_32.o /bw_tmp/bzip2/blocksort_32.o /bw_tmp/bzip2/bzip2_32.o /bw_tmp/bzip2/bzip2dll_32.o /bw_tmp/bzip2/bzlib_32.o /bw_tmp/bzip2/compress_32.o /bw_tmp/bzip2/cpu_fixed_k_32.o /bw_tmp/bzip2/crctable_32.o /bw_tmp/bzip2/decompress_32.o /bw_tmp/bzip2/folder_i_32.o /bw_tmp/bzip2/huffman_32.o /bw_tmp/bzip2/longfile_32.o /bw_tmp/bzip2/randtable_32.o /bw_tmp/bzip2/sha512_k_32.o ver32.o -Wl,-enable-stdcall-fixup

/bw_tmp/bzip2/bzip2dll_32.o: bzip2dll.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/bzip2dll_32.o bzip2dll.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/blocksort_32.o: blocksort.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/blocksort_32.o blocksort.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/bzip2_32.o: bzip2.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/bzip2_32.o bzip2.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/bzlib_32.o: bzlib.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/bzlib_32.o bzlib.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/compress_32.o: compress.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/compress_32.o compress.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/crctable_32.o: crctable.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/crctable_32.o crctable.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/decompress_32.o: decompress.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/decompress_32.o decompress.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/huffman_32.o: huffman.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/huffman_32.o huffman.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/randtable_32.o: randtable.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/randtable_32.o randtable.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/folder_i_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/folder_i_32.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/longfile_32.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/sha512_k_32.o: sha512_k.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/sha512_k_32.o sha512_k.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/cpu_fixed_k_32.o: cpu_fixed_k.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/cpu_fixed_k_32.o cpu_fixed_k.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/pedro_32.o : pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/pedro_32.o pedro.c $(AMANDA_FLAGS__)

ricardo_64 : /bw_tmp/bzip2/pedro_i_64.o /bw_tmp/bzip2/blocksort_64.o /bw_tmp/bzip2/bzip2_64.o /bw_tmp/bzip2/bzip2dll_64.o /bw_tmp/bzip2/bzlib_64.o /bw_tmp/bzip2/compress_64.o /bw_tmp/bzip2/cpu_fixed_k_64.o /bw_tmp/bzip2/crctable_64.o /bw_tmp/bzip2/decompress_64.o /bw_tmp/bzip2/folder_i_64.o /bw_tmp/bzip2/huffman_64.o /bw_tmp/bzip2/longfile_64.o /bw_tmp/bzip2/randtable_64.o /bw_tmp/bzip2/sha512_k_64.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe ./amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" rspbzip2_64.dll increase

	@x86_64-w64-mingw32-windres.exe -o ver64.o -O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc.exe -mdll -o /bin/tar/x64/rspbzip2_64.dll dll_k.def /bw_tmp/bzip2/pedro_i_64.o /bw_tmp/bzip2/blocksort_64.o /bw_tmp/bzip2/bzip2_64.o /bw_tmp/bzip2/bzip2dll_64.o /bw_tmp/bzip2/bzlib_64.o /bw_tmp/bzip2/compress_64.o /bw_tmp/bzip2/cpu_fixed_k_64.o /bw_tmp/bzip2/crctable_64.o /bw_tmp/bzip2/decompress_64.o /bw_tmp/bzip2/folder_i_64.o /bw_tmp/bzip2/huffman_64.o /bw_tmp/bzip2/longfile_64.o /bw_tmp/bzip2/randtable_64.o /bw_tmp/bzip2/sha512_k_64.o ver64.o -Wl,-enable-stdcall-fixup

/bw_tmp/bzip2/bzip2dll_64.o: bzip2dll.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/bzip2dll_64.o bzip2dll.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/blocksort_64.o: blocksort.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/blocksort_64.o blocksort.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/bzip2_64.o: bzip2.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/bzip2_64.o bzip2.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/bzlib_64.o: bzlib.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/bzlib_64.o bzlib.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/compress_64.o: compress.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/compress_64.o compress.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/crctable_64.o: crctable.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/crctable_64.o crctable.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/decompress_64.o: decompress.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/decompress_64.o decompress.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/huffman_64.o: huffman.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/huffman_64.o huffman.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/randtable_64.o: randtable.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/randtable_64.o randtable.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/folder_i_64.o: folder.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/folder_i_64.o folder.c $(AMANDA_FLAGS__)
	
/bw_tmp/bzip2/longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/longfile_64.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/sha512_k_64.o: sha512_k.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/sha512_k_64.o sha512_k.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/cpu_fixed_k_64.o: cpu_fixed_k.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/cpu_fixed_k_64.o cpu_fixed_k.c $(AMANDA_FLAGS__)

/bw_tmp/bzip2/pedro_i_64.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/bzip2/pedro_i_64.o pedro.c $(AMANDA_FLAGS__)
