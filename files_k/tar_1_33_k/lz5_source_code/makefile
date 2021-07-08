AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function -I ./
JULIET_FLAGS  =

AMANDA_SIZE__ =                                    62

amanda_32: pedro_32.o cpu_fixed_k_32.o             \
	folder_i_32.o longfile_32.o lz4_32arp.o    \
	lz4_frame_arp_32arp.o lz4frame_32arp.o     \
	lz4hc_32arp.o lz5dll_32.o lz5_32.o         \
	lz5_multi_32.o stdio_v2_32.o               \
	xxhash_32arp.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	pedro_32.o cpu_fixed_k_32.o                \
	folder_i_32.o longfile_32.o lz4_32arp.o    \
	lz4_frame_arp_32arp.o lz4frame_32arp.o     \
	lz4hc_32arp.o lz5dll_32.o lz5_32.o         \
	lz5_multi_32.o stdio_v2_32.o               \
	xxhash_32arp.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini               \
	versio_n.ama.rc                            \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h               \
	"31.5 bits ;-)"	rsp_lz5_32.DLL increase

	@i686-w64-mingw32-windres.exe -o ver32.o   \
	-O coff                                    \
	version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -O3 -mdll        \
	-o rsp_lz5_32.DLL dll_k.def                \
	pedro_32.o                                 \
	cpu_fixed_k_32.o folder_32.o longfile_32.o \
	lz4_32arp.o lz4_frame_arp_32arp.o          \
	lz4frame_32arp.o lz4hc_32arp.o lz5dll_32.o \
	lz5_32.o lz5_multi_32.o stdio_v2_32.o      \
	xxhash_32arp.o                             \
	ver32.o -Wl,-enable-stdcall-fixup

	@cp rsp_lz5_32.DLL ../

	@cp rsp_lz5_32.DLL                         'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar/tar_sample_ar/bin/Release/'

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz5_multi_32.o: stdio_v2.c stdio_v2.h              \
	lz5_thread.c stdio_v2.h                    \
	lz5_multi.c
	i686-w64-mingw32-gcc.exe -c -o             \
	lz5_multi_32.o lz5_multi.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz5_multi_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4_frame_arp_32arp.o: lz4_frame_arp.c             \
	stdio_v3.h stdio_v2.h
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

lz4frame_32arp.o: lz4frame.c
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

lz4_32arp.o: lz4.c
	i686-w64-mingw32-gcc.exe -c -o             \
	lz4_32arp.o lz4.c                          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz4_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4hc_32arp.o: lz4hc.c
	i686-w64-mingw32-gcc.exe -c -o             \
	lz4hc_32arp.o lz4hc.c                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz4hc_32arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

xxhash_32arp.o: xxhash.c
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

testmini_32.o: z.c lz5.h
	i686-w64-mingw32-gcc.exe -c -o             \
	testmini_32.o z.c                          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__) -DMAIN_Z

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	testmini_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

minilzo_32.o: minilzo.c
	i686-w64-mingw32-gcc.exe -c -o             \
	minilzo_32.o minilzo.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	minilzo_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

stdio_v2_32.o: stdio_v2.c stdio_v2.h
	i686-w64-mingw32-gcc.exe -c -o             \
	stdio_v2_32.o                              \
	stdio_v2.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	stdio_v2_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz5dll_32.o: lz5dll.c
	i686-w64-mingw32-gcc.exe -c -o lz5dll_32.o \
	lz5dll.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz5dll_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

folder_i_32.o: folder.c
	i686-w64-mingw32-gcc.exe -c -o             \
	folder_i_32.o                              \
	folder.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	folder_i_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

longfile_32.o: longfile.c
	i686-w64-mingw32-gcc.exe -c -o             \
	longfile_32.o                              \
	longfile.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	longfile_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz5_32.o: lz5.c stdio_v2.h stdio_v3.h              \
	lz5_decoder_mt_z.c
	i686-w64-mingw32-gcc.exe -c -o lz5_32.o    \
	lz5.c                                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	lz5_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

cpu_fixed_k_32.o: cpu_fixed_k.c
	i686-w64-mingw32-gcc.exe -c -o             \
	cpu_fixed_k_32.o cpu_fixed_k.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	cpu_fixed_k_32.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_32.o: pedro.c
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

ricardo_64: pedro_64.o cpu_fixed_k_64.o            \
	folder_i_64.o longfile_64.o                \
	lz4_64arp.o lz4_frame_arp_64arp.o          \
	lz4frame_64arp.o lz4hc_64arp.o lz5dll_64.o \
	lz5_64.o lz5_multi_64.o stdio_v2_64.o      \
	xxhash_64arp.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	pedro_64.o cpu_fixed_k_64.o                \
	folder_i_64.o longfile_64.o                \
	lz4_64arp.o lz4_frame_arp_64arp.o          \
	lz4frame_64arp.o lz4hc_64arp.o lz5dll_64.o \
	lz5_64.o lz5_multi_64.o stdio_v2_64.o      \
	xxhash_64arp.o

	@./amandaricardo_mvbuild26_32.exe          \
	./amanda_file_counter_32.ini               \
	versio_n.ama.rc                            \
	version_ricardo_mislaine_final_2_.rc       \
	aline_definitive_header_2_.h               \
	"63.5 bits ;-)"                            \
	rsp_lz5_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o ver64.o \
	-O coff                                    \
	version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc -mdll -o           \
	rsp_lz5_64.DLL -O3 dll_k.def ver64.o       \
	pedro_64.o                                 \
	cpu_fixed_k_64.o folder_i_64.o             \
	longfile_64.o                              \
	lz4_64arp.o	lz4_frame_arp_64arp.o      \
	lz4frame_64arp.o lz4hc_64arp.o lz5dll_64.o \
	lz5_64.o lz5_multi_64.o stdio_v2_64.o      \
	xxhash_64arp.o                             \
	-Wl,-enable-stdcall-fixup

	@cp rsp_lz5_64.DLL ../

	@cp rsp_lz5_64.DLL                         'C:/Amanda Ava Pereira/nosso_trabalho/amanda_projects/Lurdes_tar_gzip_parolin_k/files_k/tar_sample_ar_x64/tar_sample_ar/bin/Release'

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz5_multi_64.o: stdio_v2.c stdio_v2.h              \
	lz5_thread.c stdio_v2.h                    \
	lz5_multi.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	lz5_multi_64.o lz5_multi.c                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lz5_multi_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4_frame_arp_64arp.o: lz4_frame_arp.c             \
	stdio_v3.h stdio_v2.h
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

lz4frame_64arp.o: lz4frame.c
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

lz4_64arp.o: lz4.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	lz4_64arp.o lz4.c                          \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lz4_64arp.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz4hc_64arp.o: lz4hc.c
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

xxhash_64arp.o: xxhash.c
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

stdio_v2_64.o: stdio_v2.c stdio_v2.h
	x86_64-w64-mingw32-gcc -c -o stdio_v2_64.o \
	stdio_v2.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	stdio_v2_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz5dll_64.o: lz5dll.c
	x86_64-w64-mingw32-gcc -c -o lz5dll_64.o   \
	lz5dll.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lz5dll_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

folder_i_64.o: folder.c
	x86_64-w64-mingw32-gcc -c -o folder_i_64.o \
	folder.c                                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	folder_i_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

longfile_64.o: longfile.c
	x86_64-w64-mingw32-gcc -c -o longfile_64.o \
	longfile.c                                 \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	longfile_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

lz5_64.o: lz5.c stdio_v2.h
	x86_64-w64-mingw32-gcc -c -o lz5_64.o      \
	lz5.c                                      \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	lz5_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

cpu_fixed_k_64.o: cpu_fixed_k.c
	x86_64-w64-mingw32-gcc -c -o               \
	cpu_fixed_k_64.o cpu_fixed_k.c             \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	cpu_fixed_k_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

pedro_64.o: pedro.c
	x86_64-w64-mingw32-gcc -c -o               \
	pedro_64.o                                 \
	pedro.c                                    \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	pedro_64.o

	@./espaco_arp.exe $(AMANDA_SIZE__)

cpu_detect_k:
	x86_64-w64-mingw32-gcc.exe -O3 -o          \
	cpu64_k.exe cpu_k.c
	i686-w64-mingw32-gcc.exe.exe               \
	-msse -O3 -o cpu32_k.exe cpu_k.c
	@./espaco_arp.exe $(AMANDA_SIZE__)
