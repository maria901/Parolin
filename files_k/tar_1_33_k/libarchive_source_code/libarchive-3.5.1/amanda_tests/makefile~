#2021 amanda & MathMan April 23

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -I ../libarchive
JULIET_FLAGS  =
AMANDA_SIZE   =                              62

pedro_32arp.o : pedro.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32arp.o pedro.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version          \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i              \
	feline_gcc_version_x86.ric                   \
	pedro_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE)

pedro_64arp.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	pedro_64arp.o pedro.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE)

amanda_32: minitar_p.c pedro_32arp.o

	@cd 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_1_33_k/libarchive_source_code/libarchive-3.5.1_x86/.libs' && cp --preserve=timestamps libarchive.a 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_1_33_k/libarchive_source_code/libarchive-3.5.1/amanda_tests'

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	./libarchive.a pedro_32arp.o

	i686-w64-mingw32-gcc.exe -o                \
	BE_libarchive_32.DLL minitar_p.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__) $(ARARARARARARARARA)     \
	./libarchive.a -lz -llzma                  \
	-lbcrypt -lbz2 -static -shared             \
	interface_27.def pedro_32arp.o             \
	-Wl,-enable-stdcall-fixup
	@cp --preserve=timestamps BE_libarchive_32.DLL 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release'

	@cp --preserve=timestamps BE_libarchive_32.DLL 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_1_33_k'

	@./espaco_arp.exe $(AMANDA_SIZE)

ricardo_64: minitar_p.c pedro_64arp.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	../.libs/libarchive.a pedro_64arp.o

	x86_64-w64-mingw32-gcc.exe -o              \
	BE_libarchive_64.DLL minitar_p.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__) $(ARARARARARARARARA)     \
	../.libs/libarchive.a -lz -llzma           \
	-lbcrypt -lbz2 -static -shared             \
	interface_27.def pedro_64arp.o

	@cp --preserve=timestamps BE_libarchive_64.DLL 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@cp --preserve=timestamps BE_libarchive_64.DLL 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_1_33_k'

	@./espaco_arp.exe $(AMANDA_SIZE)

#C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\libarchive_source_code\libarchive-3.5.1_x86\.libs

#libarchive.a

update_c_i_x86:
	cd 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\libarchive_source_code\libarchive-3.5.1\libarchive' && cp --preserve=timestamps *.c 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\libarchive_source_code\libarchive-3.5.1_x86\libarchive' && cp --preserve=timestamps *.h 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_1_33_k\libarchive_source_code\libarchive-3.5.1_x86\libarchive'

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
