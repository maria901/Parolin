#hi, are you having a great day like us? , notice that in order to compile it you need cygwin 3.1.7 or above with mingw64 toolchain and mingw...

#version of the compilers, for win64 11.1.0 and for win32 also 11.1.0

AMANDA_FLAGS__=-O3 -Wall -Wfatal-errors -Werror
FELINE_FLAGS__=-Wno-unused-function
JULIET_FLAGS  =
AMANDA_SIZE   =                                    62

amanda_win32: adler32_32.o compress_32.o           \
	crc32_32.o deflate_32.o gzclose_32.o       \
	gzlib_32.o gzread_32.o gzwrite_32.o        \
	infback_32.o inffast_32.o inflate_32.o     \
	inftrees_32.o trees_32.o uncompr_32.o      \
	zutil_32.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x86.ric                 \
	adler32_32.o compress_32.o                 \
	crc32_32.o deflate_32.o gzclose_32.o       \
	gzlib_32.o gzread_32.o gzwrite_32.o        \
	infback_32.o inffast_32.o inflate_32.o     \
	inftrees_32.o trees_32.o uncompr_32.o      \
	zutil_32.o

	@i686-w64-mingw32-ar rcs ricardo_zlib32.a  \
	adler32_32.o                               \
	compress_32.o crc32_32.o deflate_32.o      \
	gzclose_32.o gzlib_32.o gzread_32.o        \
	gzwrite_32.o infback_32.o inffast_32.o     \
	inflate_32.o inftrees_32.o trees_32.o      \
	uncompr_32.o zutil_32.o

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	ricardo_zlib32.a

	cp ricardo_zlib32.a ../ricardo_zlib32.a

adler32_32.o: adler32.c
	i686-w64-mingw32-gcc.exe -c -o             \
	adler32_32.o adler32.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	adler32_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress_32.o: compress.c
	i686-w64-mingw32-gcc.exe -c -o             \
	compress_32.o compress.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	compress_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

crc32_32.o: crc32.c
	i686-w64-mingw32-gcc.exe -c -o             \
	crc32_32.o crc32.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	crc32_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

deflate_32.o: deflate.c
	i686-w64-mingw32-gcc.exe -c -o             \
	deflate_32.o deflate.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	deflate_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

gzclose_32.o: gzclose.c
	i686-w64-mingw32-gcc.exe -c -o             \
	gzclose_32.o gzclose.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	gzclose_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

gzlib_32.o: gzlib.c
	i686-w64-mingw32-gcc.exe -c -o             \
	gzlib_32.o gzlib.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	gzlib_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

gzread_32.o: gzread.c
	i686-w64-mingw32-gcc.exe -c -o             \
	gzread_32.o gzread.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	gzread_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

gzwrite_32.o: gzwrite.c
	i686-w64-mingw32-gcc.exe -c -o             \
	gzwrite_32.o gzwrite.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	gzwrite_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

infback_32.o: infback.c
	i686-w64-mingw32-gcc.exe -c -o             \
	infback_32.o infback.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	infback_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

inffast_32.o: inffast.c
	i686-w64-mingw32-gcc.exe -c -o             \
	inffast_32.o inffast.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	inffast_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

inflate_32.o: inflate.c
	i686-w64-mingw32-gcc.exe -c -o             \
	inflate_32.o inflate.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	inflate_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

inftrees_32.o: inftrees.c
	i686-w64-mingw32-gcc.exe -c -o             \
	inftrees_32.o inftrees.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	inftrees_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

trees_32.o: trees.c
	i686-w64-mingw32-gcc.exe -c -o             \
	trees_32.o trees.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	trees_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

uncompr_32.o: uncompr.c
	i686-w64-mingw32-gcc.exe -c -o             \
	uncompr_32.o uncompr.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	uncompr_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

zutil_32.o: zutil.c
	i686-w64-mingw32-gcc.exe -c -o             \
	zutil_32.o zutil.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@i686-w64-mingw32-gcc.exe --version        \
	>feline_gcc_version_x86.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x86.ric                 \
	zutil_32.o

	@./espaco_arp.exe $(AMANDA_SIZE)

ricardo_win64: adler32_64.o compress_64.o          \
	crc32_64.o deflate_64.o gzclose_64.o       \
	gzlib_64.o gzread_64.o gzwrite_64.o        \
	infback_64.o inffast_64.o inflate_64.o     \
	inftrees_64.o trees_64.o uncompr_64.o      \
	zutil_64.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe read_i             \
	feline_gcc_version_x64.ric                 \
	adler32_64.o compress_64.o                 \
	crc32_64.o deflate_64.o gzclose_64.o       \
	gzlib_64.o gzread_64.o gzwrite_64.o        \
	infback_64.o inffast_64.o inflate_64.o     \
	inftrees_64.o trees_64.o uncompr_64.o      \
	zutil_64.o

	@x86_64-w64-mingw32-ar rcs amanda_zlib64.a \
	adler32_64.o compress_64.o crc32_64.o      \
	deflate_64.o gzclose_64.o gzlib_64.o       \
	gzread_64.o gzwrite_64.o infback_64.o      \
	inffast_64.o inflate_64.o inftrees_64.o    \
	trees_64.o uncompr_64.o zutil_64.o

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	amanda_zlib64.a

	cp amanda_zlib64.a ../amanda_zlib64.a

adler32_64.o: adler32.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	adler32_64.o adler32.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	adler32_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

compress_64.o: compress.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	compress_64.o compress.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	compress_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

crc32_64.o: crc32.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	crc32_64.o crc32.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	crc32_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

deflate_64.o: deflate.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	deflate_64.o deflate.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	deflate_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

gzclose_64.o: gzclose.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	gzclose_64.o gzclose.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	gzclose_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

gzlib_64.o: gzlib.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	gzlib_64.o gzlib.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	gzlib_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

gzread_64.o: gzread.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	gzread_64.o gzread.c                       \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	gzread_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

gzwrite_64.o: gzwrite.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	gzwrite_64.o gzwrite.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	gzwrite_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

infback_64.o: infback.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	infback_64.o infback.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	infback_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

inffast_64.o: inffast.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	inffast_64.o inffast.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	inffast_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

inflate_64.o: inflate.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	inflate_64.o inflate.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	inflate_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

inftrees_64.o: inftrees.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	inftrees_64.o inftrees.c                   \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	inftrees_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

trees_64.o: trees.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	trees_64.o trees.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	trees_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

uncompr_64.o: uncompr.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	uncompr_64.o uncompr.c                     \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	uncompr_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)

zutil_64.o: zutil.c
	x86_64-w64-mingw32-gcc.exe -c -o           \
	zutil_64.o zutil.c                         \
	$(AMANDA_FLAGS__) $(JULIET_FLAGS)          \
	$(FELINE_FLAGS__)

	@x86_64-w64-mingw32-gcc.exe --version      \
	>feline_gcc_version_x64.ric

	@./file_gcc_version.exe write_i            \
	feline_gcc_version_x64.ric                 \
	zutil_64.o

	@./espaco_arp.exe $(AMANDA_SIZE)
