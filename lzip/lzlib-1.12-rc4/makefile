#2021 amanda & MathMan, updated 07/march/2021 21:50 PM

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  = 

amanda_32: amandaricardo_koci_dprintf_aakp_rspk_32.o \
	carg_parser_aakp_rspk_32.o                   \
	lzlib_aakp_rspk_32.o main_aakp_32.o          \
	ricardo_64
	
	i686-w64-mingw32-gcc.exe -O3 -mdll dll_aakp.def -o  \
	bw_lzip_aakp_32.DLL                          \
	amandaricardo_koci_dprintf_aakp_rspk_32.o    \
	carg_parser_aakp_rspk_32.o                   \
	lzlib_aakp_rspk_32.o main_aakp_32.o          \
	-Wl,-enable-stdcall-fixup
#			rm *.DLL
	@cp bw_lzip_aakp_32.DLL ../../
	@cp bw_lzip_aakp_32.DLL                      'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_sample_ar\tar_sample_ar\bin\Release\'
	@./espaco_arp.exe   83
	@./espaco_arp.exe   83 27
	
main_aakp_32.o : main_aakp.c
	i686-w64-mingw32-gcc.exe -c -o               \
	main_aakp_32.o main_aakp.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
carg_parser_aakp_rspk_32.o : carg_parser.c
	i686-w64-mingw32-gcc.exe -c -o               \
	carg_parser_aakp_rspk_32.o carg_parser.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
amandaricardo_koci_dprintf_aakp_rspk_32.o :      \
	amandaricardo_koci_dprintf.c
	i686-w64-mingw32-gcc.exe -c -o               \
	amandaricardo_koci_dprintf_aakp_rspk_32.o    \
	amandaricardo_koci_dprintf.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83

lzlib_aakp_rspk_32.o : encoder_base.h lzlib.c
	i686-w64-mingw32-gcc.exe -c -o               \
	lzlib_aakp_rspk_32.o lzlib.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
		
###############################64 bits

ricardo_64: amandaricardo_koci_dprintf_aakp_rspk_64.o \
	carg_parser_aakp_rspk_64.o                   \
	lzlib_aakp_rspk_64.o main_aakp_64.o
	x86_64-w64-mingw32-gcc -O3 -mdll             \
	dll_aakp.def -o bw_lzip_aakp_64.DLL          \
	amandaricardo_koci_dprintf_aakp_rspk_64.o    \
	carg_parser_aakp_rspk_64.o                   \
	lzlib_aakp_rspk_64.o main_aakp_64.o          \
	-Wl,-enable-stdcall-fixup

	@cp bw_lzip_aakp_64.DLL ../../
	@cp bw_lzip_aakp_64.DLL  'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_sample_ar_x64\tar_sample_ar\bin\Release'
	@./espaco_arp.exe   83
	@./espaco_arp.exe   83 27
	
main_aakp_64.o : main_aakp.c
	x86_64-w64-mingw32-gcc.exe -c -o             \
	main_aakp_64.o main_aakp.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
carg_parser_aakp_rspk_64.o : carg_parser.c
	x86_64-w64-mingw32-gcc.exe -c -o             \
	carg_parser_aakp_rspk_64.o carg_parser.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83
	
amandaricardo_koci_dprintf_aakp_rspk_64.o :      \
	amandaricardo_koci_dprintf.c
	x86_64-w64-mingw32-gcc.exe -c -o             \
	amandaricardo_koci_dprintf_aakp_rspk_64.o    \
	amandaricardo_koci_dprintf.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83

lzlib_aakp_rspk_64.o : encoder_base.h lzlib.c
	x86_64-w64-mingw32-gcc.exe -c -o             \
	lzlib_aakp_rspk_64.o lzlib.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)            \
	$(FELINE_FLAGS__)
	@./espaco_arp.exe 83

clean_ar:
	-rm amandaricardo_koci_dprintf_aakp_rspk_32.o \
	carg_parser_aakp_rspk_32.o                   \
	lzlib_aakp_rspk_32.o main_aakp_32.o
	@./espaco_arp.exe   83