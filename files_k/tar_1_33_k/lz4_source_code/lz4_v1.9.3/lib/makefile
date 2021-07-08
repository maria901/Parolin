#2021 amanda & MathMan
AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -I ./
JULIET_FLAGS  =

AMANDA_SIZE__ =                                    62

amanda_32: pedro_32arp.o                           \
	lz4_32arp.o lz4_frame_arp_32arp.o          \
	lz4frame_32arp.o lz4hc_32arp.o             \
	xxhash_32arp.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	pedro_32arp.o                              \
	lz4_32arp.o lz4_frame_arp_32arp.o          \
	lz4frame_32arp.o lz4hc_32arp.o             \
	xxhash_32arp.o

	@i686-w64-mingw32-gcc.exe -shared arp.def  \
	-o rsp_lz4_arp_32.DLL                      \
	pedro_32arp.o                              \
	lz4_32arp.o lz4_frame_arp_32arp.o          \
	lz4frame_32arp.o lz4hc_32arp.o             \
	xxhash_32arp.o                             \
	-Wl,-enable-stdcall-fixup -static-libgcc   \
	-O3

	@cp rsp_lz4_arp_32.DLL ../../../

	@cp rsp_lz4_arp_32.DLL  'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4_frame_arp_32arp.o :                            \
	helper_utilities_by_amanda_and_ricardo.c   \
	lz4_frame_arp.c
	i686-w64-mingw32-gcc.exe -c -o             \
	lz4_frame_arp_32arp.o lz4_frame_arp.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz4_frame_arp_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4_32arp.o : lz4.c
	i686-w64-mingw32-gcc.exe -c -o             \
	lz4_32arp.o                                \
	lz4.c                                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz4_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4frame_32arp.o : lz4frame.c
	i686-w64-mingw32-gcc.exe -c -o             \
	lz4frame_32arp.o lz4frame.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz4frame_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4hc_32arp.o : lz4hc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	lz4hc_32arp.o                              \
	lz4hc.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz4hc_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

xxhash_32arp.o : xxhash.c
	i686-w64-mingw32-gcc.exe -c -o             \
	xxhash_32arp.o xxhash.c                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	xxhash_32arp.o

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

#################################64 bits

ricardo_64: pedro_64arp.o                          \
	lz4_64arp.o lz4_frame_arp_64arp.o          \
	lz4frame_64arp.o lz4hc_64arp.o             \
	xxhash_64arp.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	pedro_64arp.o                              \
	lz4_64arp.o lz4_frame_arp_64arp.o          \
	lz4frame_64arp.o lz4hc_64arp.o             \
	xxhash_64arp.o

	@x86_64-w64-mingw32-gcc -shared arp.def -o \
	rsp_lz4_arp_64.DLL -O3                     \
	pedro_64arp.o                              \
	lz4_64arp.o lz4_frame_arp_64arp.o          \
	lz4frame_64arp.o lz4hc_64arp.o             \
	xxhash_64arp.o                             \
	-Wl,-enable-stdcall-fixup -static-libgcc

	@cp rsp_lz4_arp_64.DLL ../../../

	@cp rsp_lz4_arp_64.DLL                     'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4_frame_arp_64arp.o :                            \
	helper_utilities_by_amanda_and_ricardo.c   \
	lz4_frame_arp.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	lz4_frame_arp_64arp.o lz4_frame_arp.c      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lz4_frame_arp_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4_64arp.o : lz4.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	lz4_64arp.o                                \
	lz4.c                                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lz4_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4frame_64arp.o : lz4frame.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	lz4frame_64arp.o lz4frame.c                \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lz4frame_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4hc_64arp.o : lz4hc.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	lz4hc_64arp.o lz4hc.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lz4hc_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

xxhash_64arp.o : xxhash.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	xxhash_64arp.o xxhash.c                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	xxhash_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_64arp.o : pedro.c
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
