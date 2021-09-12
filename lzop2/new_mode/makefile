#2021 amanda & MathMan, updated 08/march/2021 14:08 PM
AMANDA_FLAGS__=-O3 -Wextra -Wall -Wfatal-errors -Werror -Wextra -Wno-unused-function -Wno-unused-but-set-variable

amanda_32: /bw_tmp/lzop2/pedro_32arp.o /bw_tmp/lzop2/arp_dll_32arp.o /bw_tmp/lzop2/compress2_z_32.o /bw_tmp/lzop2/compress2_2_z_32.o /bw_tmp/lzop2/compress2dll_32.o /bw_tmp/lzop2/longfile_32arp.o /bw_tmp/lzop2/stdio_v2_32arp.o /bw_tmp/lzop2/z_32.o /bw_tmp/lzop2/minilzo_32.o

#	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" rsp_lzop2_32.DLL increase

	@i686-w64-mingw32-windres.exe -o /bw_tmp/lzop2/amanda_ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -O3 -o /bin/tar/x86/rsp_lzop2_32.DLL -shared arp.def /bw_tmp/lzop2/amanda_ver32.o /bw_tmp/lzop2/pedro_32arp.o /bw_tmp/lzop2/arp_dll_32arp.o /bw_tmp/lzop2/compress2_z_32.o /bw_tmp/lzop2/compress2_2_z_32.o /bw_tmp/lzop2/compress2dll_32.o /bw_tmp/lzop2/longfile_32arp.o /bw_tmp/lzop2/stdio_v2_32arp.o /bw_tmp/lzop2/z_32.o /bw_tmp/lzop2/minilzo_32.o -Wl,-enable-stdcall-fixup -static-libgcc

/bw_tmp/lzop2/z_32.o : c/tools/z.c c/tools/stdio_v2.h c/tools/stdio_v3.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/z_32.o c/tools/z.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/minilzo_32.o : c/tools/minilzo.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/minilzo_32.o c/tools/minilzo.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/longfile_32arp.o: c/tools/longfile.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/longfile_32arp.o c/tools/longfile.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/stdio_v2_32arp.o: c/tools/stdio_v2.c c/tools/stdio_v2.h c/tools/stdio_v3.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/stdio_v2_32arp.o c/tools/stdio_v2.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/pedro_32arp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/pedro_32arp.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/arp_dll_32arp.o: c/tools/helper_utilities_by_amanda_and_ricardo.c c/tools/arp_dll.c c/tools/stdio_v2.h c/tools/stdio_v3.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/arp_dll_32arp.o c/tools/arp_dll.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/compress2_z_32.o: c/tools/compress2_z.c c/tools/stdio_v2.h c/tools/stdio_v3.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/compress2_z_32.o c/tools/compress2_z.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/compress2_2_z_32.o: c/tools/compress2_2_z.c c/tools/lzop2_multi.c c/tools/lzop2_thread.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/compress2_2_z_32.o c/tools/compress2_2_z.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/compress2dll_32.o: c/tools/compress2dll.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/compress2dll_32.o c/tools/compress2dll.c $(AMANDA_FLAGS__)

################################64 bits

ricardo_64: /bw_tmp/lzop2/pedro_64arp.o /bw_tmp/lzop2/arp_dll_64arp.o /bw_tmp/lzop2/compress2_z_64.o /bw_tmp/lzop2/compress2_2_z_64.o /bw_tmp/lzop2/compress2dll_64.o /bw_tmp/lzop2/longfile_64arp.o /bw_tmp/lzop2/stdio_v2_64arp.o /bw_tmp/lzop2/z_64.o /bw_tmp/lzop2/minilzo_64.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" rsp_lzop2_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/lzop2/amanda_ver64.o -O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc.exe -O3 -o /bin/tar/x64/rsp_lzop2_64.DLL -shared arp.def /bw_tmp/lzop2/amanda_ver64.o /bw_tmp/lzop2/pedro_64arp.o /bw_tmp/lzop2/arp_dll_64arp.o /bw_tmp/lzop2/compress2_z_64.o /bw_tmp/lzop2/compress2_2_z_64.o /bw_tmp/lzop2/compress2dll_64.o /bw_tmp/lzop2/longfile_64arp.o /bw_tmp/lzop2/stdio_v2_64arp.o /bw_tmp/lzop2/z_64.o /bw_tmp/lzop2/minilzo_64.o -Wl,-enable-stdcall-fixup -static-libgcc

/bw_tmp/lzop2/z_64.o: c/tools/z.c c/tools/stdio_v2.h c/tools/stdio_v3.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/z_64.o c/tools/z.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/minilzo_64.o: c/tools/minilzo.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/minilzo_64.o c/tools/minilzo.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/longfile_64arp.o: c/tools/longfile.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/longfile_64arp.o c/tools/longfile.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/stdio_v2_64arp.o: c/tools/stdio_v2.c c/tools/stdio_v2.h c/tools/stdio_v3.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/stdio_v2_64arp.o c/tools/stdio_v2.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/pedro_64arp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/pedro_64arp.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/arp_dll_64arp.o: c/tools/helper_utilities_by_amanda_and_ricardo.c c/tools/arp_dll.c c/tools/stdio_v2.h c/tools/stdio_v3.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/arp_dll_64arp.o c/tools/arp_dll.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/compress2_z_64.o: c/tools/compress2_z.c c/tools/stdio_v2.h c/tools/stdio_v3.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/compress2_z_64.o c/tools/compress2_z.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/compress2_2_z_64.o: c/tools/compress2_2_z.c c/tools/lzop2_multi.c c/tools/lzop2_thread.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/compress2_2_z_64.o c/tools/compress2_2_z.c $(AMANDA_FLAGS__)

/bw_tmp/lzop2/compress2dll_64.o: c/tools/compress2dll.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzop2/compress2dll_64.o c/tools/compress2dll.c $(AMANDA_FLAGS__)
