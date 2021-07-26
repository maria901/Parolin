AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-unused-function

amanda_32: /bw_tmp/gzip2/pedro_32.o /bw_tmp/gzip2/dll_32.o /bw_tmp/gzip2/folder_i_32.o /bw_tmp/gzip2/longfile_32.o /bw_tmp/gzip2/gzip2__multi_32.o /bw_tmp/gzip2/sha512_k_32.o /bw_tmp/gzip2/stdio_v2_32.o /bw_tmp/gzip2/zlib_32.o /bw_tmp/gzip2/miniz_32.o

#	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" rsp_gzip2_32.DLL increase

	@i686-w64-mingw32-windres.exe -o /bw_tmp/gzip2/amanda_ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -mdll def_k.def -o /bin/tar/x86/rsp_gzip2_32.DLL /bw_tmp/gzip2/amanda_ver32.o /bw_tmp/gzip2/pedro_32.o /bw_tmp/gzip2/dll_32.o /bw_tmp/gzip2/folder_i_32.o /bw_tmp/gzip2/longfile_32.o /bw_tmp/gzip2/gzip2__multi_32.o /bw_tmp/gzip2/sha512_k_32.o /bw_tmp/gzip2/stdio_v2_32.o /bw_tmp/gzip2/zlib_32.o /bw_tmp/gzip2/miniz_32.o -Wl,-enable-stdcall-fixup

/bw_tmp/gzip2/miniz_32.o: miniz.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/miniz_32.o miniz.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/gzip2__multi_32.o: stdio_v2.c stdio_v2.h gzip2__thread.c gzip2_include.h gzip2__multi.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/gzip2__multi_32.o gzip2__multi.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/stdio_v2_32.o: stdio_v2.c stdio_v2.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/stdio_v2_32.o stdio_v2.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/pedro_32.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/pedro_32.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/dll_32.o: dll.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/dll_32.o dll.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/zlib_32.o: zlib.c stdio_v2.h gzip2_decoder_mt_z.c gzip2_include.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/zlib_32.o zlib.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/longfile_32.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/folder_i_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/folder_i_32.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/sha512_k_32.o: sha512_k.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/sha512_k_32.o sha512_k.c $(AMANDA_FLAGS__)

ricardo_64: /bw_tmp/gzip2/pedro_64.o /bw_tmp/gzip2/dll_64.o /bw_tmp/gzip2/folder_i_64.o /bw_tmp/gzip2/longfile_64.o /bw_tmp/gzip2/gzip2__multi_64.o /bw_tmp/gzip2/sha512_k_64.o /bw_tmp/gzip2/stdio_v2_64.o /bw_tmp/gzip2/zlib_64.o /bw_tmp/gzip2/miniz_64.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" rsp_gzip2_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/gzip2/amanda_ver64.o	-O coff version_ricardo_mislaine_final_2_.rc

	x86_64-w64-mingw32-gcc.exe -DNPRINTF_NO -mdll def_k.def -o /bin/tar/x64/rsp_gzip2_64.DLL /bw_tmp/gzip2/amanda_ver64.o /bw_tmp/gzip2/pedro_64.o /bw_tmp/gzip2/dll_64.o /bw_tmp/gzip2/folder_i_64.o /bw_tmp/gzip2/longfile_64.o /bw_tmp/gzip2/gzip2__multi_64.o /bw_tmp/gzip2/sha512_k_64.o /bw_tmp/gzip2/stdio_v2_64.o /bw_tmp/gzip2/zlib_64.o /bw_tmp/gzip2/miniz_64.o -Wl,-enable-stdcall-fixup

/bw_tmp/gzip2/miniz_64.o: miniz.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/miniz_64.o miniz.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/gzip2__multi_64.o: stdio_v2.c stdio_v2.h gzip2__thread.c gzip2_include.h gzip2__multi.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/gzip2__multi_64.o gzip2__multi.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/stdio_v2_64.o: stdio_v2.c stdio_v2.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/stdio_v2_64.o stdio_v2.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/pedro_64.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/pedro_64.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/dll_64.o: dll.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/dll_64.o dll.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/zlib_64.o: zlib.c stdio_v2.h gzip2_decoder_mt_z.c gzip2_include.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/zlib_64.o zlib.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/longfile_64.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/folder_i_64.o: folder.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/folder_i_64.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/gzip2/sha512_k_64.o: sha512_k.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip2/sha512_k_64.o sha512_k.c $(AMANDA_FLAGS__)
