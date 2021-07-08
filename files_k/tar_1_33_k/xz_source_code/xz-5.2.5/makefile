AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -DDEBUGME_NO -I .
JULIET_FLAGS  =

AMANDA_SIZE_  =                                    62

amanda_32: liblzma_32aakp_2020.a compress_32aakp.o \
	decompress_32aakp.o dprintf_32aakp.o       \
	unicode_large_32aakp.o dllxz_32aakp.o      \
	pedro_32aakp.o        \
	ricardo_64

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	liblzma_32aakp_2020.a compress_32aakp.o    \
	decompress_32aakp.o dprintf_32aakp.o       \
	unicode_large_32aakp.o dllxz_32aakp.o      \
	pedro_32aakp.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini               \
	versio_n.ama.rc                            \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h "32 bits"     \
	rsp_xz_aakp_32.dll increase

	@i686-w64-mingw32-windres -o ver_32_ar.o   \
	-O coff                                    \
	version_ricardo_mislaine_final_2_.rc

	i686-w64-mingw32-gcc.exe -mdll -O3 -o      \
	rsp_xz_aakp_32.DLL controlname_ar.c        \
	dllxz_32aakp.o def_ar.def                  \
	compress_32aakp.o                          \
	decompress_32aakp.o dprintf_32aakp.o       \
	unicode_large_32aakp.o ver_32_ar.o         \
	liblzma_32aakp_2020.a                      \
	pedro_32aakp.o        \
	-Wl,-enable-stdcall-fixup

	@cp rsp_xz_aakp_32.DLL ../../
	@cp rsp_xz_aakp_32.DLL  'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'
liblzma_32aakp_2020.a                     :
	make amanda_32 -C ./xz-5.2.5/windows/vs2019

compress_32aakp.o: compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress_32aakp.o compress.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

decompress_32aakp.o: decompress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	decompress_32aakp.o  decompress.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	decompress_32aakp.o 

	@./espaco_arp.exe $(AMANDA_SIZE_)

dprintf_32aakp.o: dprintf.c
	i686-w64-mingw32-gcc.exe -c -o             \
	dprintf_32aakp.o dprintf.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	dprintf_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

unicode_large_32aakp.o: unicode_large.c
	i686-w64-mingw32-gcc.exe -c -o             \
	unicode_large_32aakp.o unicode_large.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	unicode_large_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

dllxz_32aakp.o: dllxz.c
	i686-w64-mingw32-gcc.exe -c -o             \
	dllxz_32aakp.o dllxz.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	dllxz_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

pedro_32aakp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32aakp.o pedro.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pedro_32aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

ricardo_64: liblzma_64aakp_2020.a                  \
	compress_64aakp.o decompress_64aakp.o      \
	dprintf_64aakp.o unicode_large_64aakp.o    \
	dllxz_64aakp.o pedro_64aakp.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	liblzma_64aakp_2020.a                      \
	compress_64aakp.o decompress_64aakp.o      \
	dprintf_64aakp.o unicode_large_64aakp.o    \
	dllxz_64aakp.o pedro_64aakp.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini               \
	versio_n.ama.rc                            \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h "64 bits"     \
	rsp_xz_aakp_64.dll increase

	@x86_64-w64-mingw32-windres -o ver_64_ar.o \
	-O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc -mdll -O3 -o       \
	rsp_xz_aakp_64.DLL controlname_ar.c        \
	dllxz_64aakp.o def_ar.def                  \
	compress_64aakp.o decompress_64aakp.o      \
	dprintf_64aakp.o unicode_large_64aakp.o    \
	ver_64_ar.o liblzma_64aakp_2020.a          \
	pedro_64aakp.o -Wl,-enable-stdcall-fixup

	@cp rsp_xz_aakp_64.DLL ../../
	@cp rsp_xz_aakp_64.DLL  'C:\Amanda Ava Pereira\nosso_trabalho\amanda_projects\Lurdes_tar_gzip_parolin_k\files_k\tar_sample_ar_x64\tar_sample_ar\bin\Release'
liblzma_64aakp_2020.a                     :
	make ricardo_64 -C ./xz-5.2.5/windows/vs2019

compress_64aakp.o: compress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress_64aakp.o compress.c               \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

decompress_64aakp.o: decompress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	decompress_64aakp.o decompress.c           \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	decompress_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

dprintf_64aakp.o: dprintf.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	dprintf_64aakp.o dprintf.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	dprintf_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

unicode_large_64aakp.o: unicode_large.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	unicode_large_64aakp.o unicode_large.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	unicode_large_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

dllxz_64aakp.o: dllxz.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	dllxz_64aakp.o dllxz.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	dllxz_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)

pedro_64aakp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	pedro_64aakp.o pedro.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64aakp.o

	@./espaco_arp.exe $(AMANDA_SIZE_)
