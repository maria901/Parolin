#2021 amanda & MathMan

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -Wno-stringop-truncation -DALE__
JULIET_FLAGS  =
AMANDA_SIZE__ =                                    62


amanda_32: adlercheck_32.o aes_32.o pedro_32.o    \
	cpu_32.o crc32_32.o dll_32.o              \
	folder_i_32.o hexa_32.o longfile_32.o     \
	rc4_32.o sha512_k_32.o serpent_32.o       \
	mars_32.o rc6_32.o twofish_32.o

	@i686-w64-mingw32-gcc.exe --version       \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i            \
	feline_gcc_version_x86.ric                \
	adlercheck_32.o aes_32.o pedro_32.o       \
	cpu_32.o crc32_32.o dll_32.o              \
	folder_i_32.o hexa_32.o longfile_32.o     \
	rc4_32.o sha512_k_32.o serpent_32.o       \
	mars_32.o rc6_32.o twofish_32.o

	@./amandaricardo_mvbuild26_32.exe         \
	./amanda_file_counter_32.ini              \
	versio_n.ama.rc                           \
	version_ricardo_mislaine_final_2_.rc      \
	aline_definitive_header_2_.h "32 bits"    \
	RSP_encrypt_32.DLL increase

	@i686-w64-mingw32-windres.exe -o          \
	ver32.o -O coff                           \
	version_ricardo_mislaine_final_2_.rc

	i686-w64-mingw32-gcc.exe -mdll            \
	-O3                                       \
	-o RSP_encrypt_32.DLL                     \
	adlercheck_32.o aes_32.o pedro_32.o       \
	cpu_32.o crc32_32.o dll_32.o              \
	folder_i_32.o hexa_32.o longfile_32.o     \
	rc4_32.o sha512_k_32.o serpent_32.o       \
	mars_32.o rc6_32.o twofish_32.o           \
	ver32.o controlname_k.c                   \
	-Wl,-enable-stdcall-fixup dll_k.def

	@cp RSP_encrypt_32.DLL ../

	@cp RSP_encrypt_32.DLL 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe      83
sha512_k_32.o        : makefile                         sha512_file_k.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o sha512_k_32.o                                    sha512_file_k.c
	@./espaco_arp.exe     83

sha512_k_32.o: sha512_file_k.c
	i686-w64-mingw32-gcc.exe -c -o             \
	sha512_k_32.o sha512_file_k.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	sha512_k_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

mars_32.o: mars.c
	i686-w64-mingw32-gcc.exe -c -o             \
	mars_32.o mars.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	mars_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

rc6_32.o: rc6.c
	i686-w64-mingw32-gcc.exe -c -o             \
	rc6_32.o rc6.c                             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	rc6_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

twofish_32.o: twofish.c
	i686-w64-mingw32-gcc.exe -c -o             \
	twofish_32.o twofish.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	twofish_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

serpent_32.o: serpent.c
	i686-w64-mingw32-gcc.exe -c -o             \
	serpent_32.o serpent.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	serpent_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

adlercheck_32.o: adlercheck.c
	i686-w64-mingw32-gcc.exe -c -o             \
	adlercheck_32.o adlercheck.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	adlercheck_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

aes_32.o             : makefile                             aes.c aes.h
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o aes_32.o                                                   aes.c
	@./espaco_arp.exe     83

aes_32.o: aes.c aes.h
	i686-w64-mingw32-gcc.exe -c -o             \
	aes_32.o aes.c                             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	aes_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

amandaricardo_koci_dprintf_32.o: makefile  amandaricardo_koci_dprintf.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o amandaricardo_koci_dprintf_32.o                                \
	                                       amandaricardo_koci_dprintf.c
	@./espaco_arp.exe     83
cpu_32.o             : makefile                                   cpu.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o cpu_32.o                                                   cpu.c
	@./espaco_arp.exe     83
crc32_32.o           : makefile                                 crc32.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o crc32_32.o                                               crc32.c
	@./espaco_arp.exe     83
dll_32.o             : makefile                                   dll.c
#gcc -o a_test.exe -DAMANDA__ cpu_fixed_k.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o dll_32.o                                                   dll.c
	@./espaco_arp.exe     83
dprintf_32.o         : makefile                               dprintf.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o dprintf_32.o                                           dprintf.c
	@./espaco_arp.exe     83
folder_32.o          : makefile                                folder.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o folder_32.o                                             folder.c
	@./espaco_arp.exe     83
hexa_32.o            : makefile                                  hexa.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o hexa_32.o                                                 hexa.c
	@./espaco_arp.exe     83
longfile_32.o        : makefile                              longfile.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o longfile_32.o                                         longfile.c
	@./espaco_arp.exe     83
rc4_32.o             : makefile                                   rc4.c
	i686-w64-mingw32-gcc.exe -c                                       \
	$(AR_______________________________________________________FLAGS) \
	-o rc4_32.o                                                   rc4.c
	@./espaco_arp.exe     83
	
#####################################################64 bits, for your pleasure...###############################################################################
ricardo_64:	adlercheck_64.o aes_64.o amandaricardo_koci_dprintf_64.o cpu_64.o crc32_64.o \
	dll_64.o dprintf_64.o folder_64.o hexa_64.o longfile_64.o rc4_64.o sha512_k_64.o     \
	serpent_64.o mars_64.o rc6_64.o twofish_64.o

	@./amandaricardo_mvbuild26_32.exe ./amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" RSP_encrypt_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o ver64_k.o -O                            \
	coff version_ricardo_mislaine_final_2_.rc

	x86_64-w64-mingw32-gcc -mdll $(AR_______________________________________________________FLAGS) -o                                \
	RSP_encrypt_64.DLL adlercheck_64.o aes_64.o                                \
	amandaricardo_koci_dprintf_64.o cpu_64.o crc32_64.o                        \
	dll_64.o dprintf_64.o sha512_k_64.o                                        \
	folder_64.o hexa_64.o longfile_64.o rc4_64.o serpent_64.o mars_64.o        \
	rc6_64.o twofish_64.o ver64_k.o controlname_k.c                            \
	-Wl,-enable-stdcall-fixup dll_k.def
	
	@cp RSP_encrypt_64.DLL ../
	@cp RSP_encrypt_64.DLL 'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_sample_ar_x64\tar_sample_ar\bin\Release'
	@./espaco_arp.exe      83
	
sha512_k_64.o        : makefile                         sha512_file_k.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o sha512_k_64.o                                    sha512_file_k.c
	@./espaco_arp.exe     83
adlercheck_64.o      : makefile                            adlercheck.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o adlercheck_64.o                                     adlercheck.c
	@./espaco_arp.exe     83
twofish_64.o      : makefile                                      twofish.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o twofish_64.o                                           twofish.c
	@./espaco_arp.exe     83
serpent_64.o      : makefile                                  serpent.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o serpent_64.o                                           serpent.c
	@./espaco_arp.exe     83
mars_64.o      : makefile                                        mars.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o mars_64.o                                                 mars.c
	@./espaco_arp.exe     83
rc6_64.o       : makefile                                          rc6.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o rc6_64.o                                                   rc6.c
	@./espaco_arp.exe     83
aes_64.o             : makefile                             aes.c aes.h
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o aes_64.o                                                   aes.c
	@./espaco_arp.exe     83
amandaricardo_koci_dprintf_64.o: makefile  amandaricardo_koci_dprintf.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o amandaricardo_koci_dprintf_64.o                                \
	                                       amandaricardo_koci_dprintf.c
	@./espaco_arp.exe     83
cpu_64.o             : makefile                                   cpu.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o cpu_64.o                                                   cpu.c
	@./espaco_arp.exe     83
crc32_64.o           : makefile                                 crc32.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o crc32_64.o                                               crc32.c
	@./espaco_arp.exe     83
dll_64.o             : makefile                                   dll.c
#x86_64-w64-mingw32-gcc -o a_test.exe -DAMANDA__ cpu_fixed_k.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o dll_64.o                                                   dll.c
	@./espaco_arp.exe     83
dprintf_64.o         : makefile                               dprintf.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o dprintf_64.o                                           dprintf.c
	@./espaco_arp.exe     83
folder_64.o          : makefile                                folder.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o folder_64.o                                             folder.c
	@./espaco_arp.exe     83
hexa_64.o            : makefile                                  hexa.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o hexa_64.o                                                 hexa.c
	@./espaco_arp.exe     83
longfile_64.o        : makefile                              longfile.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o longfile_64.o                                         longfile.c
	@./espaco_arp.exe     83
rc4_64.o             : makefile                                   rc4.c
	x86_64-w64-mingw32-gcc -c                                         \
	$(AR_______________________________________________________FLAGS) \
	-o rc4_64.o                                                   rc4.c
	@./espaco_arp.exe     83
