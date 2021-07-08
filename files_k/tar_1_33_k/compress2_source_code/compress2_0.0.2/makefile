#2021 amanda & MathMan, updated 08/march/2021 14:08 PM
AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -Wno-unused-but-set-variable
JULIET_FLAGS  =

AMANDA_SIZE   =                              62

amanda_32: pedro_32arp.o                           \
	arp_dll_32arp.o compress2_z_32.o           \
	compress2_2_z_32.o compress2dll_32.o       \
	longfile_32arp.o                           \
	compress42_thread_1_32.o                   \
	compress42_thread_2_32.o                   \
	compress42_thread_3_32.o                   \
	compress42_thread_4_32.o                   \
	compress42_thread_5_32.o                   \
	compress42_thread_6_32.o                   \
	compress42_thread_7_32.o                   \
	stdio_v2_32arp.o compress42_32.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	pedro_32arp.o                              \
	arp_dll_32arp.o compress2_z_32.o           \
	compress2_2_z_32.o compress2dll_32.o       \
	longfile_32arp.o                           \
	compress42_thread_1_32.o                   \
	compress42_thread_2_32.o                   \
	compress42_thread_3_32.o                   \
	compress42_thread_4_32.o                   \
	compress42_thread_5_32.o                   \
	compress42_thread_6_32.o                   \
	compress42_thread_7_32.o                   \
	stdio_v2_32arp.o compress42_32.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \

	@i686-w64-mingw32-gcc -O3 -o               \
	BE_compress2_aakp_32.DLL  -shared          \
	arp.def                                    \
	pedro_32arp.o                              \
	arp_dll_32arp.o compress2_z_32.o           \
	compress2_2_z_32.o compress2dll_32.o       \
	longfile_32arp.o                           \
	compress42_thread_1_32.o                   \
	compress42_thread_2_32.o                   \
	compress42_thread_3_32.o                   \
	compress42_thread_4_32.o                   \
	compress42_thread_5_32.o                   \
	compress42_thread_6_32.o                   \
	compress42_thread_7_32.o                   \
	stdio_v2_32arp.o compress42_32.o           \
	-Wl,-enable-stdcall-fixup -static-libgcc

	@cp BE_compress2_aakp_32.DLL ../../
	@cp BE_compress2_aakp_32.DLL  'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_32.o :                                  \
	c/tools/compress42.c c/tools/decompress_for_all_z.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress42_32.o                            \
	c/tools/compress42.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress42_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_1_32.o :                         \
	c/tools/compress42_thread_1.c c/tools/decompress_for_all_z.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress42_thread_1_32.o                   \
	c/tools/compress42_thread_1.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)
	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress42_thread_1_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_2_32.o :                         \
	c/tools/compress42_thread_2.c c/tools/decompress_for_all_z.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress42_thread_2_32.o                   \
	c/tools/compress42_thread_2.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress42_thread_2_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_3_32.o :                         \
	c/tools/compress42_thread_3.c c/tools/decompress_for_all_z.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress42_thread_3_32.o                   \
	c/tools/compress42_thread_3.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress42_thread_3_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_4_32.o :                         \
	c/tools/compress42_thread_4.c c/tools/decompress_for_all_z.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress42_thread_4_32.o                   \
	c/tools/compress42_thread_4.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress42_thread_4_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_5_32.o :                         \
	c/tools/compress42_thread_5.c c/tools/decompress_for_all_z.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress42_thread_5_32.o                   \
	c/tools/compress42_thread_5.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress42_thread_5_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_6_32.o :                         \
	c/tools/compress42_thread_6.c c/tools/decompress_for_all_z.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress42_thread_6_32.o                   \
	c/tools/compress42_thread_6.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress42_thread_6_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_7_32.o :                         \
	c/tools/compress42_thread_7.c c/tools/decompress_for_all_z.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress42_thread_7_32.o                   \
	c/tools/compress42_thread_7.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress42_thread_7_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

longfile_32arp.o :                                 \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

stdio_v2_32arp.o :                                 \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

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

	@./espaco_arp.exe $(AMANDA_SIZE)

arp_dll_32arp.o :                                  \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

compress2_z_32.o :   c/tools/compress2_z.c         \
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

	@./espaco_arp.exe $(AMANDA_SIZE)
#	unc77.bat c/tools/brotli.c

compress2_2_z_32.o :   c/tools/compress2_2_z.c     \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

compress2dll_32.o :   c/tools/compress2dll.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress2dll_32.o c/tools/compress2dll.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress2dll_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

################################64 bits

ricardo_64: pedro_64arp.o                          \
	arp_dll_64arp.o compress2_z_64.o           \
	compress2_2_z_64.o compress2dll_64.o       \
	longfile_64arp.o                           \
	compress42_thread_1_64.o                   \
	compress42_thread_2_64.o                   \
	compress42_thread_3_64.o                   \
	compress42_thread_4_64.o                   \
	compress42_thread_5_64.o                   \
	compress42_thread_6_64.o                   \
	compress42_thread_7_64.o                   \
	stdio_v2_64arp.o compress42_64.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	pedro_64arp.o                              \
	arp_dll_64arp.o compress2_z_64.o           \
	compress2_2_z_64.o compress2dll_64.o       \
	longfile_64arp.o                           \
	compress42_thread_1_64.o                   \
	compress42_thread_2_64.o                   \
	compress42_thread_3_64.o                   \
	compress42_thread_4_64.o                   \
	compress42_thread_5_64.o                   \
	compress42_thread_6_64.o                   \
	compress42_thread_7_64.o                   \
	stdio_v2_64arp.o compress42_64.o

	@x86_64-w64-mingw32-gcc.exe -O3 -o         \
	BE_compress2_aakp_64.DLL  -shared          \
	arp.def                                    \
	pedro_64arp.o                              \
	arp_dll_64arp.o compress2_z_64.o           \
	compress2_2_z_64.o compress2dll_64.o       \
	longfile_64arp.o                           \
	compress42_thread_1_64.o                   \
	compress42_thread_2_64.o                   \
	compress42_thread_3_64.o                   \
	compress42_thread_4_64.o                   \
	compress42_thread_5_64.o                   \
	compress42_thread_6_64.o                   \
	compress42_thread_7_64.o                   \
	stdio_v2_64arp.o compress42_64.o           \
	-Wl,-enable-stdcall-fixup -static-libgcc

	@cp BE_compress2_aakp_64.DLL ../../
	@cp BE_compress2_aakp_64.DLL  'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_64.o :                                  \
	c/tools/compress42.c c/tools/decompress_for_all_z.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress42_64.o                            \
	c/tools/compress42.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress42_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_1_64.o :                         \
	c/tools/compress42_thread_1.c c/tools/decompress_for_all_z.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress42_thread_1_64.o                   \
	c/tools/compress42_thread_1.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress42_thread_1_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_2_64.o :                         \
	c/tools/compress42_thread_2.c c/tools/decompress_for_all_z.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress42_thread_2_64.o                   \
	c/tools/compress42_thread_2.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress42_thread_2_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_3_64.o :                         \
	c/tools/compress42_thread_3.c c/tools/decompress_for_all_z.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress42_thread_3_64.o                   \
	c/tools/compress42_thread_3.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress42_thread_3_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_4_64.o :                         \
	c/tools/compress42_thread_4.c c/tools/decompress_for_all_z.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress42_thread_4_64.o                   \
	c/tools/compress42_thread_4.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress42_thread_4_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_5_64.o :                         \
	c/tools/compress42_thread_5.c c/tools/decompress_for_all_z.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress42_thread_5_64.o                   \
	c/tools/compress42_thread_5.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress42_thread_5_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_6_64.o :                         \
	c/tools/compress42_thread_6.c c/tools/decompress_for_all_z.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress42_thread_6_64.o                   \
	c/tools/compress42_thread_6.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress42_thread_6_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress42_thread_7_64.o :                         \
	c/tools/compress42_thread_7.c c/tools/decompress_for_all_z.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress42_thread_7_64.o                   \
	c/tools/compress42_thread_7.c              \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress42_thread_7_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

longfile_64arp.o :                                 \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

stdio_v2_64arp.o :                                 \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

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

	@./espaco_arp.exe $(AMANDA_SIZE)

arp_dll_64arp.o :                                  \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

compress2_z_64.o :   c/tools/compress2_z.c         \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

compress2_2_z_64.o :   c/tools/compress2_2_z.c     \
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

	@./espaco_arp.exe $(AMANDA_SIZE)

compress2dll_64.o :   c/tools/compress2dll.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress2dll_64.o c/tools/compress2dll.c   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress2dll_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)
