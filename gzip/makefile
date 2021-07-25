#2021 amanda & MathMan
AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror -Wno-unused-function
FELINE_FLAGS__=
JULIET_FLAGS  =
AMANDA_SIZE   =                                    62


amanda_32: ricardo_zlib32.a dll_32.o               \
	zlib_32.o longfile_32.o md5_32.o           \
	folder_i_32.o pedro_32.o                   \
	sha512_k_32.o ricardo_64

	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	ricardo_zlib32.a dll_32.o                  \
	zlib_32.o longfile_32.o md5_32.o           \
	folder_i_32.o pedro_32.o                   \
	sha512_k_32.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini               \
	versio_n.ama.rc                            \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h "32 bits"     \
	rspgzip200_32.dll increase

	@i686-w64-mingw32-windres.exe -o ver32.o   \
	-O coff                                    \
	version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -O3 -mdll        \
	-DNPRINTF_NO  dprintf.c def_k.def          \
	dll_32.o pedro_32.o                        \
	sha512_k_32.o                              \
	                                           \
	zlib_32.o                                  \
	longfile_32.o                              \
	md5_32.o                                   \
	                                           \
	ver32.o                                    \
	folder_i_32.o -o rspgzip200_32.dll         \
	-Wl,-enable-stdcall-fixup ricardo_zlib32.a

	@cp rspgzip200_32.dll ../rspgzip200_32.dll

	@cp rspgzip200_32.dll  'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

pedro_32.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32.o pedro.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pedro_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

dll_32.o: dll.c
	i686-w64-mingw32-gcc.exe -c -o             \
	dll_32.o dll.c                             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	dll_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

zlib_32.o: zlib.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zlib_32.o zlib.c                           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zlib_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o             \
	longfile_32.o longfile.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	longfile_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

md5_32.o: md5.c
	i686-w64-mingw32-gcc.exe -c -o             \
	md5_32.o md5.c                             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	md5_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

folder_i_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o             \
	folder_i_32.o folder.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	folder_i_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

sha512_k_32.o: sha512_k.c
	i686-w64-mingw32-gcc.exe -c -o             \
	sha512_k_32.o sha512_k.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	sha512_k_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

id:

ricardo_zlib32.a:
	@make amanda_win32 -C ./zlib_src/

ricardo_64: amanda_zlib64.a dll_64.o zlib_64.o     \
	longfile_64.o md5_64.o folder_i_64.o       \
	pedro_64.o                                 \
	sha512_k_64.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	amanda_zlib64.a dll_64.o zlib_64.o         \
	longfile_64.o md5_64.o folder_i_64.o       \
	pedro_64.o                                 \
	sha512_k_64.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini               \
	versio_n.ama.rc                            \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h "64 bits"     \
	rspgzip200_64.dll increase

	@x86_64-w64-mingw32-windres.exe -o ver64.o \
	-O coff                                    \
	version_ricardo_mislaine_final_2_.rc

	x86_64-w64-mingw32-gcc.exe -DNPRINTF_NO    \
	-O3 -mdll def_k.def dprintf.c \
	\
	dll_64.o zlib_64.o longfile_64.o md5_64.o  \
	folder_i_64.o pedro_64.o                   \
	sha512_k_64.o                              \
	                                           \
	ver64.o                                    \
	                                           \
	-o rspgzip200_64.dll                       \
	-Wl,-enable-stdcall-fixup amanda_zlib64.a

	@cp rspgzip200_64.dll ../rspgzip200_64.dll

	@cp rspgzip200_64.dll 'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

amanda_zlib64.a:
	@make ricardo_win64 -C ./zlib_src/

pedro_64.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	pedro_64.o pedro.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

dll_64.o: dll.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	dll_64.o dll.c                             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	dll_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

zlib_64.o: zlib.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	zlib_64.o zlib.c                           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zlib_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	longfile_64.o longfile.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	longfile_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

md5_64.o: md5.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	md5_64.o md5.c                             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	md5_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

folder_i_64.o: folder.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	folder_i_64.o folder.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	folder_i_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

sha512_k_64.o: sha512_k.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	sha512_k_64.o sha512_k.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	sha512_k_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)
