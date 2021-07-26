#2021 amanda & MathMan April 23

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-unused-function -I ../libarchive

/bw_tmp/libarchive/pedro_32arp.o : pedro.c
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/libarchive/pedro_32arp.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/libarchive/pedro_64arp.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/libarchive/pedro_64arp.o pedro.c $(AMANDA_FLAGS__)

amanda_32: /bw_tmp/libarchive/pedro_32arp.o

	@cd '/tar/libarchive/libarchive-3.5.1_x86/.libs' && cp --preserve=timestamps libarchive.a '/tar/libarchive/libarchive-3.5.1/amanda_tests'

	i686-w64-mingw32-gcc.exe -o /bin/tar/x86/BE_libarchive_32.DLL minitar_p.c $(AMANDA_FLAGS__)	./libarchive.a -lz -llzma -lbcrypt -lbz2 -static -shared interface_27.def /tar/libarchive/pedro_32arp.o -Wl,-enable-stdcall-fixup

ricardo_64: /bw_tmp/libarchive/pedro_64arp.o

	x86_64-w64-mingw32-gcc.exe -o /bin/tar/x64/BE_libarchive_64.DLL minitar_p.c $(AMANDA_FLAGS__) ../.libs/libarchive.a -lz -llzma -lbcrypt -lbz2 -static -shared interface_27.def /bw_tmp/libarchive/pedro_64arp.o

update_c_i_x86:
	cd '/tar/libarchive/libarchive-3.5.1/libarchive' && cp --preserve=timestamps *.c '/tar/libarchive/libarchive-3.5.1_x86/libarchive' && cp --preserve=timestamps *.h '/tar/libarchive/libarchive-3.5.1_x86/libarchive'

make_amanda_x86:
	cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\libarchive_source_code\libarchive-3.5.1_x86' && make && cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\libarchive_source_code\libarchive-3.5.1_x86\.libs' && i686-w64-mingw32-gcc.exe --version          \
	>feline_gcc_version_x86.ric && 	./file_gcc_version.exe write_i              \
	feline_gcc_version_x86.ric                   \
	libarchive.a

make_amanda_x64:
	cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\libarchive_source_code\libarchive-3.5.1' && make && cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\libarchive_source_code\libarchive-3.5.1\.libs' && x86_64-w64-mingw32-gcc.exe --version          \
	>feline_gcc_version_x64.ric && 	./file_gcc_version.exe write_i              \
	feline_gcc_version_x64.ric                   \
	libarchive.a
