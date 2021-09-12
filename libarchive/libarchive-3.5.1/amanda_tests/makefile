#2021 amanda & MathMan April 23

AMANDA_FLAGS__=-O3 -Wextra -Wall -Wfatal-errors -Werror -Wno-unused-function -I ../libarchive

/bw_tmp/libarchive/pedro_32arp.o : pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/libarchive/pedro_32arp.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/libarchive/pedro_64arp.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/libarchive/pedro_64arp.o pedro.c $(AMANDA_FLAGS__)

amanda_32: /bw_tmp/libarchive/pedro_32arp.o

	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a
	
	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" BE_libarchive_32.DLL increase

	@i686-w64-mingw32-windres.exe -o /bw_tmp/libarchive/amanda_ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@cd '/tar/libarchive/libarchive-3.5.1_x86/.libs' && cp --preserve=timestamps libarchive.a '/tar/libarchive/libarchive-3.5.1/amanda_tests'

	i686-w64-mingw32-gcc.exe -o /bin/tar/x86/BE_libarchive_32.DLL minitar_p.c $(AMANDA_FLAGS__)	/bw_tmp/libarchive/amanda_ver32.o ./libarchive.a -lz -llzma -lbcrypt -lbz2 -static -shared interface_27.def /bw_tmp/libarchive/pedro_32arp.o -Wl,-enable-stdcall-fixup

ricardo_64: /bw_tmp/libarchive/pedro_64arp.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" BE_libarchive_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/libarchive/amanda_ver64.o	-O coff version_ricardo_mislaine_final_2_.rc

	x86_64-w64-mingw32-gcc.exe -o /bin/tar/x64/BE_libarchive_64.DLL minitar_p.c $(AMANDA_FLAGS__) /bw_tmp/libarchive/amanda_ver64.o ../.libs/libarchive.a -lz -llzma -lbcrypt -lbz2 -static -shared interface_27.def /bw_tmp/libarchive/pedro_64arp.o

update_c_i_x86:
	cd '/tar/libarchive/libarchive-3.5.1/libarchive' && cp --preserve=timestamps *.c '/tar/libarchive/libarchive-3.5.1_x86/libarchive' && cp --preserve=timestamps *.h '/tar/libarchive/libarchive-3.5.1_x86/libarchive'

make_amanda_x86:
	cd '/tar/libarchive/libarchive-3.5.1_x86' && make
	
make_amanda_x86_clean:
	cd '/tar/libarchive/libarchive-3.5.1_x86' && make clean

make_amanda_x64:
	cd '/tar/libarchive/libarchive-3.5.1' && make
	
make_amanda_x64_clean:
	cd '/tar/libarchive/libarchive-3.5.1' && make clean