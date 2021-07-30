AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wextra -Wno-unused-function -DDEBUGME_NO -I .

amanda_32: /bw_tmp/xz/liblzma_32aakp_2020.a /bw_tmp/xz/compress_32aakp.o /bw_tmp/xz/decompress_32aakp.o /bw_tmp/xz/dprintf_32aakp.o /bw_tmp/xz/unicode_large_32aakp.o /bw_tmp/xz/dllxz_32aakp.o /bw_tmp/xz/pedro_32aakp.o

	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" rsp_xz_aakp_32.dll increase

	@i686-w64-mingw32-windres -o /bw_tmp/xz/ver_32_ar.o -O coff version_ricardo_mislaine_final_2_.rc

	i686-w64-mingw32-gcc.exe -mdll -O3 -o /bin/tar/x86/rsp_xz_aakp_32.DLL controlname_ar.c def_ar.def /bw_tmp/xz/ver_32_ar.o /bw_tmp/xz/liblzma_32aakp_2020.a /bw_tmp/xz/compress_32aakp.o /bw_tmp/xz/decompress_32aakp.o /bw_tmp/xz/dprintf_32aakp.o /bw_tmp/xz/unicode_large_32aakp.o /bw_tmp/xz/dllxz_32aakp.o /bw_tmp/xz/pedro_32aakp.o /bw_tmp/xz/liblzma_32aakp_2020.a -Wl,-enable-stdcall-fixup

/bw_tmp/xz/liblzma_32aakp_2020.a:
	make amanda_32 -C ./xz-5.2.5/windows/vs2019

/bw_tmp/xz/compress_32aakp.o: compress.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/compress_32aakp.o compress.c     $(AMANDA_FLAGS__)

/bw_tmp/xz/decompress_32aakp.o: decompress.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/decompress_32aakp.o decompress.c        $(AMANDA_FLAGS__)

/bw_tmp/xz/dprintf_32aakp.o: dprintf.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/dprintf_32aakp.o dprintf.c              $(AMANDA_FLAGS__)

/bw_tmp/xz/unicode_large_32aakp.o: unicode_large.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/unicode_large_32aakp.o unicode_large.c  $(AMANDA_FLAGS__)

/bw_tmp/xz/dllxz_32aakp.o: dllxz.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/dllxz_32aakp.o dllxz.c                  $(AMANDA_FLAGS__)

/bw_tmp/xz/pedro_32aakp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/pedro_32aakp.o pedro.c                  $(AMANDA_FLAGS__)

ricardo_64: /bw_tmp/xz/liblzma_64aakp_2020.a /bw_tmp/xz/compress_64aakp.o /bw_tmp/xz/decompress_64aakp.o /bw_tmp/xz/dprintf_64aakp.o /bw_tmp/xz/unicode_large_64aakp.o /bw_tmp/xz/dllxz_64aakp.o /bw_tmp/xz/pedro_64aakp.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" rsp_xz_aakp_64.dll increase

	@x86_64-w64-mingw32-windres -o /bw_tmp/xz/ver_64_ar.o -O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc -mdll -O3 -o /bin/tar/x64/rsp_xz_aakp_64.DLL controlname_ar.c def_ar.def /bw_tmp/xz/ver_64_ar.o /bw_tmp/xz/liblzma_64aakp_2020.a /bw_tmp/xz/compress_64aakp.o /bw_tmp/xz/decompress_64aakp.o /bw_tmp/xz/dprintf_64aakp.o /bw_tmp/xz/unicode_large_64aakp.o /bw_tmp/xz/dllxz_64aakp.o /bw_tmp/xz/pedro_64aakp.o /bw_tmp/xz/liblzma_64aakp_2020.a -Wl,-enable-stdcall-fixup

/bw_tmp/xz/liblzma_64aakp_2020.a:
	make ricardo_64 -C ./xz-5.2.5/windows/vs2019

/bw_tmp/xz/compress_64aakp.o: compress.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/compress_64aakp.o compress.c     $(AMANDA_FLAGS__)

/bw_tmp/xz/decompress_64aakp.o: decompress.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/decompress_64aakp.o decompress.c $(AMANDA_FLAGS__)

/bw_tmp/xz/dprintf_64aakp.o: dprintf.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/dprintf_64aakp.o dprintf.c       $(AMANDA_FLAGS__)

/bw_tmp/xz/unicode_large_64aakp.o: unicode_large.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/unicode_large_64aakp.o unicode_large.c $(AMANDA_FLAGS__)

/bw_tmp/xz/dllxz_64aakp.o: dllxz.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/dllxz_64aakp.o dllxz.c $(AMANDA_FLAGS__)

/bw_tmp/xz/pedro_64aakp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/xz/pedro_64aakp.o pedro.c $(AMANDA_FLAGS__)