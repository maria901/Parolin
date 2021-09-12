#2021 amanda & MathMan
AMANDA_FLAGS__=-O3 -Wextra -Wall -Wfatal-errors -Werror -Wno-unused-function -I ./

amanda_32: /bw_tmp/lz4/pedro_32arp.o /bw_tmp/lz4/lz4_32arp.o /bw_tmp/lz4/lz4_frame_arp_32arp.o /bw_tmp/lz4/lz4frame_32arp.o /bw_tmp/lz4/lz4hc_32arp.o /bw_tmp/lz4/xxhash_32arp.o

	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" rsp_lz4_arp_32.DLL increase

	@i686-w64-mingw32-windres.exe -o /bw_tmp/lz4/amanda_ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -shared arp.def -o /bin/tar/x86/rsp_lz4_arp_32.DLL /bw_tmp/lz4/amanda_ver32.o /bw_tmp/lz4/pedro_32arp.o /bw_tmp/lz4/lz4_32arp.o /bw_tmp/lz4/lz4_frame_arp_32arp.o /bw_tmp/lz4/lz4frame_32arp.o /bw_tmp/lz4/lz4hc_32arp.o /bw_tmp/lz4/xxhash_32arp.o -Wl,-enable-stdcall-fixup -static-libgcc -O3

/bw_tmp/lz4/lz4_frame_arp_32arp.o : helper_utilities_by_amanda_and_ricardo.c lz4_frame_arp.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/lz4_frame_arp_32arp.o lz4_frame_arp.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/lz4_32arp.o : lz4.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/lz4_32arp.o lz4.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/lz4frame_32arp.o : lz4frame.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/lz4frame_32arp.o lz4frame.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/lz4hc_32arp.o : lz4hc.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/lz4hc_32arp.o lz4hc.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/xxhash_32arp.o : xxhash.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/xxhash_32arp.o xxhash.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/pedro_32arp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/pedro_32arp.o pedro.c $(AMANDA_FLAGS__)

#################################64 bits

ricardo_64: /bw_tmp/lz4/pedro_64arp.o /bw_tmp/lz4/lz4_64arp.o /bw_tmp/lz4/lz4_frame_arp_64arp.o /bw_tmp/lz4/lz4frame_64arp.o /bw_tmp/lz4/lz4hc_64arp.o /bw_tmp/lz4/xxhash_64arp.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" rsp_lz4_arp_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/lz4/amanda_ver64.o -O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc -shared arp.def -o /bin/tar/x64/rsp_lz4_arp_64.DLL -O3 /bw_tmp/lz4/amanda_ver64.o /bw_tmp/lz4/pedro_64arp.o /bw_tmp/lz4/lz4_64arp.o /bw_tmp/lz4/lz4_frame_arp_64arp.o /bw_tmp/lz4/lz4frame_64arp.o /bw_tmp/lz4/lz4hc_64arp.o /bw_tmp/lz4/xxhash_64arp.o -Wl,-enable-stdcall-fixup -static-libgcc

/bw_tmp/lz4/lz4_frame_arp_64arp.o : helper_utilities_by_amanda_and_ricardo.c lz4_frame_arp.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/lz4_frame_arp_64arp.o lz4_frame_arp.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/lz4_64arp.o : lz4.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/lz4_64arp.o lz4.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/lz4frame_64arp.o : lz4frame.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/lz4frame_64arp.o lz4frame.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/lz4hc_64arp.o : lz4hc.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/lz4hc_64arp.o lz4hc.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/xxhash_64arp.o : xxhash.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/xxhash_64arp.o xxhash.c $(AMANDA_FLAGS__)

/bw_tmp/lz4/pedro_64arp.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz4/pedro_64arp.o pedro.c $(AMANDA_FLAGS__)
