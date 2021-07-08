#2021 amanda & MathMan, updated May/15

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  = 

AMANDA_SIZE__ =                                    62

amanda_32: pedro_32.o                              \
	carg_parser_aakp_rspk_32.o                 \
	lzlib_aakp_rspk_32.o main_aakp_32.o        \

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	pedro_32.o                                 \
	carg_parser_aakp_rspk_32.o                 \
	lzlib_aakp_rspk_32.o main_aakp_32.o 

	@i686-w64-mingw32-gcc.exe -O3              \
	-mdll dll_aakp.def -o                      \
	bw_lzip_aakp_32.DLL                        \
	pedro_32.o                                 \
	carg_parser_aakp_rspk_32.o                 \
	lzlib_aakp_rspk_32.o main_aakp_32.o        \
	-Wl,-enable-stdcall-fixup

	@cp bw_lzip_aakp_32.DLL ../../

	@cp bw_lzip_aakp_32.DLL                      'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe $(AMANDA_SIZE__)

main_aakp_32.o : main_aakp_1.12.c encoder_base.h
	i686-w64-mingw32-gcc.exe -c -o             \
	main_aakp_32.o main_aakp_1.12.c            \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	main_aakp_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

carg_parser_aakp_rspk_32.o : carg_parser.c         \
	encoder_base.h
	i686-w64-mingw32-gcc.exe -c -o             \
	carg_parser_aakp_rspk_32.o carg_parser.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	carg_parser_aakp_rspk_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_32.o : pedro.c                               \
	encoder_base.h
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32.o                                 \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pedro_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lzlib_aakp_rspk_32.o : encoder_base.h lzlib.c      \
	encoder_base.h
	i686-w64-mingw32-gcc.exe -c -o             \
	lzlib_aakp_rspk_32.o lzlib.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lzlib_aakp_rspk_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

###############################64 bits

ricardo_64: pedro_64.o                             \
	carg_parser_aakp_rspk_64.o                 \
	lzlib_aakp_rspk_64.o main_aakp_64.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	pedro_64.o                                 \
	carg_parser_aakp_rspk_64.o                 \
	lzlib_aakp_rspk_64.o main_aakp_64.o

	@x86_64-w64-mingw32-gcc -O3 -mdll          \
	dll_aakp.def -o bw_lzip_aakp_64.DLL        \
	pedro_64.o                                 \
	carg_parser_aakp_rspk_64.o                 \
	lzlib_aakp_rspk_64.o main_aakp_64.o        \
	-Wl,-enable-stdcall-fixup

	@cp bw_lzip_aakp_64.DLL ../../

	@cp bw_lzip_aakp_64.DLL  'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@./espaco_arp.exe $(AMANDA_SIZE__)

main_aakp_64.o : main_aakp_1.12.c encoder_base.h
	x86_64-w64-mingw32-gcc.exe -c -o           \
	main_aakp_64.o main_aakp_1.12.c            \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	main_aakp_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

carg_parser_aakp_rspk_64.o : carg_parser.c         \
	encoder_base.h
	x86_64-w64-mingw32-gcc.exe -c -o           \
	carg_parser_aakp_rspk_64.o carg_parser.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	carg_parser_aakp_rspk_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_64.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	pedro_64.o pedro.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lzlib_aakp_rspk_64.o : encoder_base.h lzlib.c      \
	encoder_base.h
	x86_64-w64-mingw32-gcc.exe -c -o           \
	lzlib_aakp_rspk_64.o lzlib.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lzlib_aakp_rspk_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)
