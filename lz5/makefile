AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-unused-function -I ./

amanda_32: /bw_tmp/lz5/pedro_32.o /bw_tmp/lz5/cpu_fixed_k_32.o /bw_tmp/lz5/folder_i_32.o /bw_tmp/lz5/longfile_32.o /bw_tmp/lz5/lz4_32arp.o /bw_tmp/lz5/lz4_frame_arp_32arp.o /bw_tmp/lz5/lz4frame_32arp.o /bw_tmp/lz5/lz4hc_32arp.o /bw_tmp/lz5/lz5dll_32.o /bw_tmp/lz5/lz5_32.o /bw_tmp/lz5/lz5_multi_32.o /bw_tmp/lz5/stdio_v2_32.o /bw_tmp/lz5/xxhash_32arp.o

	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "31.5 bits ;-)" rsp_lz5_32.DLL increase
	
	@i686-w64-mingw32-windres.exe -o /bw_tmp/lz5/amanda_ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -O3 -mdll -o /bin/tar/x86/rsp_lz5_32.DLL dll_k.def /bw_tmp/lz5/amanda_ver32.o /bw_tmp/lz5/pedro_32.o /bw_tmp/lz5/cpu_fixed_k_32.o /bw_tmp/lz5/folder_i_32.o /bw_tmp/lz5/longfile_32.o /bw_tmp/lz5/lz4_32arp.o /bw_tmp/lz5/lz4_frame_arp_32arp.o /bw_tmp/lz5/lz4frame_32arp.o /bw_tmp/lz5/lz4hc_32arp.o /bw_tmp/lz5/lz5dll_32.o /bw_tmp/lz5/lz5_32.o /bw_tmp/lz5/lz5_multi_32.o /bw_tmp/lz5/stdio_v2_32.o /bw_tmp/lz5/xxhash_32arp.o -Wl,-enable-stdcall-fixup

/bw_tmp/lz5/lz5_multi_32.o: stdio_v2.c stdio_v2.h lz5_thread.c stdio_v2.h lz5_multi.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz5_multi_32.o lz5_multi.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz4_frame_arp_32arp.o: lz4_frame_arp.c stdio_v3.h stdio_v2.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz4_frame_arp_32arp.o lz4_frame_arp.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz4frame_32arp.o: lz4frame.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz4frame_32arp.o lz4frame.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz4_32arp.o: lz4.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz4_32arp.o lz4.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz4hc_32arp.o: lz4hc.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz4hc_32arp.o lz4hc.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/xxhash_32arp.o: xxhash.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/xxhash_32arp.o xxhash.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/testmini_32.o: z.c lz5.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/testmini_32.o z.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/minilzo_32.o: minilzo.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/minilzo_32.o minilzo.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/stdio_v2_32.o: stdio_v2.c stdio_v2.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/stdio_v2_32.o stdio_v2.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz5dll_32.o: lz5dll.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz5dll_32.o lz5dll.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/folder_i_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/folder_i_32.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/longfile_32.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz5_32.o: lz5.c stdio_v2.h stdio_v3.h lz5_decoder_mt_z.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz5_32.o lz5.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/cpu_fixed_k_32.o: cpu_fixed_k.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/cpu_fixed_k_32.o cpu_fixed_k.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/pedro_32.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/pedro_32.o pedro.c $(AMANDA_FLAGS__)

ricardo_64: /bw_tmp/lz5/pedro_64.o /bw_tmp/lz5/cpu_fixed_k_64.o /bw_tmp/lz5/folder_i_64.o /bw_tmp/lz5/longfile_64.o /bw_tmp/lz5/lz4_64arp.o /bw_tmp/lz5/lz4_frame_arp_64arp.o /bw_tmp/lz5/lz4frame_64arp.o /bw_tmp/lz5/lz4hc_64arp.o /bw_tmp/lz5/lz5dll_64.o /bw_tmp/lz5/lz5_64.o /bw_tmp/lz5/lz5_multi_64.o /bw_tmp/lz5/stdio_v2_64.o /bw_tmp/lz5/xxhash_64arp.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "63.5 bits ;-)" rsp_lz5_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/amanda_ver64.o -O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc -mdll -o /bin/tar/x64/rsp_lz5_64.DLL -O3 dll_k.def /bw_tmp/amanda_ver64.o /bw_tmp/lz5/pedro_64.o /bw_tmp/lz5/cpu_fixed_k_64.o /bw_tmp/lz5/folder_i_64.o /bw_tmp/lz5/longfile_64.o /bw_tmp/lz5/lz4_64arp.o /bw_tmp/lz5/lz4_frame_arp_64arp.o /bw_tmp/lz5/lz4frame_64arp.o /bw_tmp/lz5/lz4hc_64arp.o /bw_tmp/lz5/lz5dll_64.o /bw_tmp/lz5/lz5_64.o /bw_tmp/lz5/lz5_multi_64.o /bw_tmp/lz5/stdio_v2_64.o /bw_tmp/lz5/xxhash_64arp.o -Wl,-enable-stdcall-fixup

/bw_tmp/lz5/lz5_multi_64.o: stdio_v2.c stdio_v2.h lz5_thread.c stdio_v2.h lz5_multi.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz5_multi_64.o lz5_multi.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz4_frame_arp_64arp.o: lz4_frame_arp.c stdio_v3.h stdio_v2.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz4_frame_arp_64arp.o lz4_frame_arp.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz4frame_64arp.o: lz4frame.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz4frame_64arp.o lz4frame.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz4_64arp.o: lz4.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz4_64arp.o lz4.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz4hc_64arp.o: lz4hc.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/lz4hc_64arp.o lz4hc.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/xxhash_64arp.o: xxhash.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lz5/xxhash_64arp.o xxhash.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/stdio_v2_64.o: stdio_v2.c stdio_v2.h
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/lz5/stdio_v2_64.o stdio_v2.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz5dll_64.o: lz5dll.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/lz5/lz5dll_64.o lz5dll.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/folder_i_64.o: folder.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/lz5/folder_i_64.o folder.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/lz5/longfile_64.o longfile.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/lz5_64.o: lz5.c stdio_v2.h
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/lz5/lz5_64.o lz5.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/cpu_fixed_k_64.o: cpu_fixed_k.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/lz5/cpu_fixed_k_64.o cpu_fixed_k.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/pedro_64.o: pedro.c
	x86_64-w64-mingw32-gcc -c -o /bw_tmp/lz5/pedro_64.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/lz5/cpu_detect_k:
	x86_64-w64-mingw32-gcc.exe -O3 -o /bw_tmp/lz5/cpu64_k.exe cpu_k.c
	i686-w64-mingw32-gcc.exe.exe -msse -O3 -o /bw_tmp/lz5/cpu32_k.exe cpu_k.c
