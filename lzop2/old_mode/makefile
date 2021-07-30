AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =
amanda_32: amandaricardo_koci_dprintf_32.o       \
	bzip2dll_32.o cpu_fixed_k_32.o folder_32.o   \
	longfile_32.o lzop2_32.o minilzo_32.o        \
	stdio_v2_32.o testmini_32.o
		
	@./amandaricardo_mvbuild26_32.exe            \
	./amanda_file_counter_32.ini versio_n.ama.rc \
	version_ricardo_mislaine_final_2_.rc         \
	aline_definitive_header_2_.h "31.5 bits ;-)" \
	rsp_lzop2_32.DLL increase

	@i686-w64-mingw32-windres.exe -o ver32.o -O  \
	coff version_ricardo_mislaine_final_2_.rc
		
	i686-w64-mingw32-gcc.exe -O3 -mdll           \
	-o rsp_lzop2_32.DLL dll_k.def                \
	amandaricardo_koci_dprintf_32.o              \
	bzip2dll_32.o cpu_fixed_k_32.o folder_32.o   \
	longfile_32.o lzop2_32.o minilzo_32.o        \
	stdio_v2_32.o testmini_32.o                  \
	ver32.o -Wl,-enable-stdcall-fixup
	
	@cp rsp_lzop2_32.DLL ../
	@cp rsp_lzop2_32.DLL                         'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_sample_ar\tar_sample_ar\bin\Release\'
	@./espaco_arp.exe 83

testmini_32.o: z.c lzop2.h
	i686-w64-mingw32-gcc.exe -O3 -c -o           \
	testmini_32.o z.c                            \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
#	unc78.bat z.c
	
minilzo_32.o: minilzo.c
	i686-w64-mingw32-gcc.exe -O3 -c -o           \
	minilzo_32.o minilzo.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83

stdio_v2_32.o: stdio_v2.c stdio_v2.h
	i686-w64-mingw32-gcc.exe -c -o stdio_v2_32.o \
	stdio_v2.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
#	unc77.bat stdio_v2.c

bzip2dll_32.o: bzip2dll.c
	i686-w64-mingw32-gcc.exe -c -o bzip2dll_32.o \
	bzip2dll.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
folder_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o folder_32.o   \
	folder.c                                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
			
longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o longfile_32.o \
	longfile.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
lzop2_32.o: lzop2.c stdio_v2.h
	i686-w64-mingw32-gcc.exe -c -o lzop2_32.o    \
	lzop2.c                                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
cpu_fixed_k_32.o: cpu_fixed_k.c
	i686-w64-mingw32-gcc.exe -c -o               \
	cpu_fixed_k_32.o cpu_fixed_k.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
amandaricardo_koci_dprintf_32.o:                 \
	amandaricardo_koci_dprintf.c
	i686-w64-mingw32-gcc.exe -c -o               \
	amandaricardo_koci_dprintf_32.o              \
	amandaricardo_koci_dprintf.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
ricardo_64: amandaricardo_koci_dprintf_64.o      \
	bzip2dll_64.o cpu_fixed_k_64.o folder_64.o   \
	longfile_64.o lzop2_64.o minilzo_64.o        \
	stdio_v2_64.o testmini_64.o
		
	@./amandaricardo_mvbuild26_32.exe            \
	./amanda_file_counter_32.ini versio_n.ama.rc \
	version_ricardo_mislaine_final_2_.rc         \
	aline_definitive_header_2_.h "63.5 bits ;-)" \
	rsp_lzop2_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o ver64.o   \
	-O coff version_ricardo_mislaine_final_2_.rc
		
	x86_64-w64-mingw32-gcc -mdll -o              \
	rsp_lzop2_64.DLL -O3 dll_k.def ver64.o       \
	amandaricardo_koci_dprintf_64.o              \
	bzip2dll_64.o cpu_fixed_k_64.o folder_64.o   \
	longfile_64.o lzop2_64.o minilzo_64.o        \
	stdio_v2_64.o testmini_64.o                  \
	-Wl,-enable-stdcall-fixup
	
	@cp rsp_lzop2_64.DLL ../
	@cp rsp_lzop2_64.DLL                         'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_sample_ar_x64\tar_sample_ar\bin\Release'
	@./espaco_arp.exe 83


testmini_64.o: z.c lzop2.h
	x86_64-w64-mingw32-gcc -O3 -c -o             \
	testmini_64.o z.c                            \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
#	unc78.bat z.c
	
minilzo_64.o: minilzo.c
	x86_64-w64-mingw32-gcc -O3 -c -o             \
	minilzo_64.o minilzo.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83

stdio_v2_64.o: stdio_v2.c stdio_v2.h
	x86_64-w64-mingw32-gcc -c -o stdio_v2_64.o   \
	stdio_v2.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
#	unc77.bat stdio_v2.c

bzip2dll_64.o: bzip2dll.c
	x86_64-w64-mingw32-gcc -c -o bzip2dll_64.o   \
	bzip2dll.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
		
folder_64.o: folder.c
	x86_64-w64-mingw32-gcc -c -o folder_64.o     \
	folder.c                                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
			
longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc -c -o longfile_64.o   \
	longfile.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
lzop2_64.o: lzop2.c stdio_v2.h
	x86_64-w64-mingw32-gcc -c -o lzop2_64.o      \
	lzop2.c                                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
cpu_fixed_k_64.o: cpu_fixed_k.c
	x86_64-w64-mingw32-gcc -c -o                 \
	cpu_fixed_k_64.o cpu_fixed_k.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
amandaricardo_koci_dprintf_64.o:                 \
	amandaricardo_koci_dprintf.c
	x86_64-w64-mingw32-gcc -c -o                 \
	amandaricardo_koci_dprintf_64.o              \
	amandaricardo_koci_dprintf.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
cpu_detect_k:
	x86_64-w64-mingw32-gcc.exe -O3 -o            \
	cpu64_k.exe cpu_k.c
	i686-w64-mingw32-gcc.exe.exe                 \
	-msse -O3 -o cpu32_k.exe cpu_k.c
	@./espaco_arp.exe 83
	
clear_z:
	-rm *.o