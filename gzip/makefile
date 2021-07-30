#2021 amanda & MathMan
AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-unused-function

amanda_32: /bw_tmp/gzip/ricardo_zlib32.a /bw_tmp/gzip/dll_32.o /bw_tmp/gzip/zlib_32.o /bw_tmp/gzip/longfile_32.o /bw_tmp/gzip/md5_32.o /bw_tmp/gzip/folder_i_32.o /bw_tmp/gzip/pedro_32.o /bw_tmp/gzip/sha512_k_32.o

#	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" rspgzip200_32.dll increase

	@i686-w64-mingw32-windres.exe -o /bw_tmp/gzip/ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -O3 -mdll -DNPRINTF_NO dprintf.c def_k.def -o /bin/tar/x86/rspgzip200_32.dll /bw_tmp/gzip/ver32.o /bw_tmp/gzip/dll_32.o /bw_tmp/gzip/zlib_32.o /bw_tmp/gzip/longfile_32.o /bw_tmp/gzip/md5_32.o /bw_tmp/gzip/folder_i_32.o /bw_tmp/gzip/pedro_32.o /bw_tmp/gzip/sha512_k_32.o /bw_tmp/gzip/ricardo_zlib32.a -Wl,-enable-stdcall-fixup

/bw_tmp/gzip/pedro_32.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/pedro_32.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/dll_32.o: dll.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/dll_32.o dll.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/zlib_32.o: zlib.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/zlib_32.o zlib.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/longfile_32.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/md5_32.o: md5.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/md5_32.o md5.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/folder_i_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/folder_i_32.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/sha512_k_32.o: sha512_k.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/sha512_k_32.o sha512_k.c $(AMANDA_FLAGS__)

id:

/bw_tmp/gzip/ricardo_zlib32.a:
	@make amanda_win32 -C ./zlib_src/

ricardo_64: /bw_tmp/gzip/amanda_zlib64.a /bw_tmp/gzip/dll_64.o /bw_tmp/gzip/zlib_64.o /bw_tmp/gzip/longfile_64.o /bw_tmp/gzip/md5_64.o /bw_tmp/gzip/folder_i_64.o /bw_tmp/gzip/pedro_64.o /bw_tmp/gzip/sha512_k_64.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" rspgzip200_64.dll increase
	
	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/gzip/ver64.o -O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc.exe -DNPRINTF_NO -O3 -mdll def_k.def -o /bin/tar/x64/rspgzip200_64.dll dprintf.c /bw_tmp/gzip/amanda_zlib64.a /bw_tmp/gzip/ver64.o /bw_tmp/gzip/dll_64.o /bw_tmp/gzip/zlib_64.o /bw_tmp/gzip/longfile_64.o /bw_tmp/gzip/md5_64.o /bw_tmp/gzip/folder_i_64.o /bw_tmp/gzip/pedro_64.o /bw_tmp/gzip/sha512_k_64.o /bw_tmp/gzip/amanda_zlib64.a -Wl,-enable-stdcall-fixup

#	x86_64-w64-mingw32-strip.exe /bin/tar/x64/rspgzip200_64.dll
	
/bw_tmp/gzip/amanda_zlib64.a:
	@make ricardo_win64 -C ./zlib_src/

/bw_tmp/gzip/pedro_64.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/pedro_64.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/dll_64.o: dll.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/dll_64.o dll.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/zlib_64.o: zlib.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/zlib_64.o zlib.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/longfile_64.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/md5_64.o: md5.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/md5_64.o md5.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/folder_i_64.o: folder.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/folder_i_64.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/gzip/sha512_k_64.o: sha512_k.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/gzip/sha512_k_64.o sha512_k.c $(AMANDA_FLAGS__)
