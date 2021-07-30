#2021 amanda & MathMan April 23

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -I ../libarchive
JULIET_FLAGS  =
AMANDA_SIZE   =                              62

pedro_64arp.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	pedro_64arp.o pedro.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

ricardo_64: minitar_p.c pedro_64arp.o
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
