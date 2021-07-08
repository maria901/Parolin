#2021 amanda & MathMan, updated 08/march/2021 14:08 PM
AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -Wno-unused-but-set-variable
JULIET_FLAGS  =

AMANDA_SIZE__ =                                    62

amanda_32: pedro_32arp.o                           \
	arp_dll_32arp.o compress2_z_32.o           \
	compress2_2_z_32.o compress2dll_32.o       \
	longfile_32arp.o                           \
	stdio_v2_32arp.o z_32.o minilzo_32.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	pedro_32arp.o                              \
	arp_dll_32arp.o compress2_z_32.o           \
	compress2_2_z_32.o compress2dll_32.o       \
	longfile_32arp.o                           \
	stdio_v2_32arp.o z_32.o minilzo_32.o

	@i686-w64-mingw32-gcc.exe -O3 -o           \
	rsp_lzop2_32.DLL  -shared                  \
	arp.def                                    \
	pedro_32arp.o                              \
	arp_dll_32arp.o compress2_z_32.o           \
	compress2_2_z_32.o compress2dll_32.o       \
	longfile_32arp.o                           \
	stdio_v2_32arp.o z_32.o minilzo_32.o       \
	-Wl,-enable-stdcall-fixup -static-libgcc

	@cp rsp_lzop2_32.DLL ../../

	@cp rsp_lzop2_32.DLL  'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe $(AMANDA_SIZE__)

z_32.o :                                           \
	c/tools/z.c c/tools/stdio_v2.h             \
	c/tools/stdio_v3.h
	i686-w64-mingw32-gcc.exe -c -o             \
	z_32.o                                     \
	c/tools/z.c                                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__) -DMY_MAIN_Z__no

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	z_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

minilzo_32.o :                                     \
	c/tools/minilzo.c
	i686-w64-mingw32-gcc.exe -c -o             \
	minilzo_32.o                               \
	c/tools/minilzo.c                          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	minilzo_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

longfile_32arp.o:                                  \
	c/tools/longfile.c
	i686-w64-mingw32-gcc.exe -c -o             \
	longfile_32arp.o                           \
	c/tools/longfile.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	longfile_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

stdio_v2_32arp.o:                                  \
	c/tools/stdio_v2.c                         \
	c/tools/stdio_v2.h c/tools/stdio_v3.h
	i686-w64-mingw32-gcc.exe -c -o             \
	stdio_v2_32arp.o                           \
	c/tools/stdio_v2.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	stdio_v2_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_32arp.o: pedro.c
	i686-w64-mingw32-gcc.exe -c -o             \
	pedro_32arp.o                              \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	pedro_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

arp_dll_32arp.o:                                  \
	c/tools/helper_utilities_by_amanda_and_ricardo.c \
	c/tools/arp_dll.c c/tools/stdio_v2.h       \
	c/tools/stdio_v3.h
	i686-w64-mingw32-gcc.exe -c -o             \
	arp_dll_32arp.o c/tools/arp_dll.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	arp_dll_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

compress2_z_32.o:   c/tools/compress2_z.c          \
	c/tools/stdio_v2.h  c/tools/stdio_v3.h
	i686-w64-mingw32-gcc.exe -c -o             \
	compress2_z_32.o c/tools/compress2_z.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress2_z_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

compress2_2_z_32.o:   c/tools/compress2_2_z.c     \
	c/tools/lzop2_multi.c c/tools/lzop2_thread.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress2_2_z_32.o c/tools/compress2_2_z.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress2_2_z_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

compress2dll_32.o:   c/tools/compress2dll.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress2dll_32.o c/tools/compress2dll.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress2dll_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

################################64 bits

ricardo_64: pedro_64arp.o                          \
	arp_dll_64arp.o compress2_z_64.o           \
	compress2_2_z_64.o compress2dll_64.o       \
	longfile_64arp.o                           \
	stdio_v2_64arp.o z_64.o minilzo_64.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	pedro_64arp.o                              \
	arp_dll_64arp.o compress2_z_64.o           \
	compress2_2_z_64.o compress2dll_64.o       \
	longfile_64arp.o                           \
	stdio_v2_64arp.o z_64.o minilzo_64.o

	@x86_64-w64-mingw32-gcc.exe -O3 -o         \
	rsp_lzop2_64.DLL  -shared                  \
	arp.def                                    \
	pedro_64arp.o                              \
	arp_dll_64arp.o compress2_z_64.o           \
	compress2_2_z_64.o compress2dll_64.o       \
	longfile_64arp.o                           \
	stdio_v2_64arp.o z_64.o minilzo_64.o       \
	-Wl,-enable-stdcall-fixup -static-libgcc

	@cp rsp_lzop2_64.DLL ../../

	@cp rsp_lzop2_64.DLL  'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@./espaco_arp.exe $(AMANDA_SIZE__)

z_64.o :                                           \
	c/tools/z.c c/tools/stdio_v2.h             \
	c/tools/stdio_v3.h
	x86_64-w64-mingw32-gcc.exe -c -o           \
	z_64.o                                     \
	c/tools/z.c                                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__) -DMY_MAIN_Z__no

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	z_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

minilzo_64.o:                                      \
	c/tools/minilzo.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	minilzo_64.o                               \
	c/tools/minilzo.c                          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	minilzo_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

longfile_64arp.o:                                  \
	c/tools/longfile.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	longfile_64arp.o                           \
	c/tools/longfile.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	longfile_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

stdio_v2_64arp.o:                                  \
	c/tools/stdio_v2.c                         \
	c/tools/stdio_v2.h c/tools/stdio_v3.h
	x86_64-w64-mingw32-gcc.exe -c -o           \
	stdio_v2_64arp.o                           \
	c/tools/stdio_v2.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	stdio_v2_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_64arp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	pedro_64arp.o                              \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

arp_dll_64arp.o:                                   \
	c/tools/helper_utilities_by_amanda_and_ricardo.c \
	c/tools/arp_dll.c c/tools/stdio_v2.h       \
	c/tools/stdio_v3.h
	x86_64-w64-mingw32-gcc.exe -c -o           \
	arp_dll_64arp.o c/tools/arp_dll.c          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	arp_dll_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

compress2_z_64.o:   c/tools/compress2_z.c          \
	c/tools/stdio_v2.h  c/tools/stdio_v3.h
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress2_z_64.o c/tools/compress2_z.c     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress2_z_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

compress2_2_z_64.o:   c/tools/compress2_2_z.c      \
	c/tools/lzop2_multi.c c/tools/lzop2_thread.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress2_2_z_64.o c/tools/compress2_2_z.c \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress2_2_z_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

compress2dll_64.o: c/tools/compress2dll.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress2dll_64.o c/tools/compress2dll.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress2dll_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)
