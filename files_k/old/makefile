#december 2020

amanda_32: untgz_32k.o infblock_32k.o infcodes_32k.o inffast_32k.o       inflate_32k.o \
	inftrees_32k.o infutil_32k.o trees_32k.o uncompr_32k.o zutil_2_32k.o adler32_32k.o \
	compress_32k.o crc32_32k.o deflate_32k.o    gvmat32c_32k.o gzio_32k.o folder_32k.o \
	dll_k_32k.o dprintf_32k.o link_32k.o              amandaricardo_koci_dprintf_32k.o \
	new_untgz_k_32.o
	
	@./amandaricardo_mvbuild26_32.exe ./amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" rsptargzipdll.dll increase

	@windres.exe -o ver_32.o -O coff version_ricardo_mislaine_final_2_.rc
	
	gcc -O3 -mdll -o rsptargzipdll.dll                                                 \
	untgz_32k.o infblock_32k.o infcodes_32k.o inffast_32k.o inflate_32k.o              \
	inftrees_32k.o infutil_32k.o trees_32k.o uncompr_32k.o zutil_2_32k.o adler32_32k.o \
	compress_32k.o crc32_32k.o deflate_32k.o gvmat32c_32k.o gzio_32k.o folder_32k.o    \
	dll_k_32k.o dprintf_32k.o link_32k.o ver_32.o amandaricardo_koci_dprintf_32k.o     \
	new_untgz_k_32.o -Wl,-enable-stdcall-fixup def_k.def
	
	gcc -O3 -o example_32_k.exe -DAMANDA_MAIN___                                       \
	untgz_32k.o infblock_32k.o infcodes_32k.o inffast_32k.o inflate_32k.o              \
	inftrees_32k.o infutil_32k.o trees_32k.o uncompr_32k.o zutil_2_32k.o adler32_32k.o \
	compress_32k.o crc32_32k.o deflate_32k.o gvmat32c_32k.o gzio_32k.o folder_32k.o    \
	dll_k.c     dprintf_32k.o link_32k.o ver_32.o amandaricardo_koci_dprintf_32k.o     \
	new_untgz_k_32.o -Wl,-enable-stdcall-fixup

	./example_32_k.exe
	
new_untgz_k_32.o     :  quotes_k.c                                 new_untgz_k.c
	gcc -Wfatal-errors -Werror -c -O3 -o new_untgz_k_32.o          new_untgz_k.c
amandaricardo_koci_dprintf_32k.o :                  amandaricardo_koci_dprintf.c
	gcc -c -O3 -o amandaricardo_koci_dprintf_32k.o  amandaricardo_koci_dprintf.c
untgz_32k.o          :                                                   untgz.c
	gcc -c -O3 -o untgz_32k.o                                            untgz.c
infblock_32k.o       :                                                infblock.c
	gcc -c -O3 -o infblock_32k.o                                      infblock.c
infcodes_32k.o       :                                                infcodes.c
	gcc -c -O3 -o infcodes_32k.o                                      infcodes.c
inffast_32k.o        :                                                 inffast.c
	gcc -c -O3 -o inffast_32k.o                                        inffast.c
inflate_32k.o        :                                                 inflate.c
	gcc -c -O3 -o inflate_32k.o                                        inflate.c
inftrees_32k.o       :                                                inftrees.c
	gcc -c -O3 -o inftrees_32k.o                                      inftrees.c
infutil_32k.o        :                                                 infutil.c
	gcc -c -O3 -o infutil_32k.o                                        infutil.c
trees_32k.o          :                                                   trees.c
	gcc -c -O3 -o trees_32k.o                                            trees.c
uncompr_32k.o        :                                                 uncompr.c
	gcc -c -O3 -o uncompr_32k.o                                        uncompr.c
zutil_2_32k.o        :                                                   zutil.c
	gcc -c -O3 -o zutil_2_32k.o                                           zutil.c
adler32_32k.o        :                                                 adler32.c
	gcc -c -O3 -o adler32_32k.o                                        adler32.c
compress_32k.o       :                                                compress.c
	gcc -c -O3 -o compress_32k.o                                      compress.c
crc32_32k.o          :                                                   crc32.c
	gcc -c -O3 -o crc32_32k.o                                            crc32.c
deflate_32k.o        :                                                 deflate.c
	gcc -c -O3 -o deflate_32k.o                                        deflate.c
gvmat32c_32k.o       :                                                gvmat32c.c
	gcc -c -O3 -o gvmat32c_32k.o                                      gvmat32c.c
gzio_32k.o           :                                                    gzio.c
	gcc -c -O3 -o gzio_32k.o                                              gzio.c
folder_32k.o         :                                                  folder.c
	gcc -c -O3 -o folder_32k.o                                          folder.c
dll_k_32k.o          :                                                   dll_k.c
	gcc -c -O3 -o dll_k_32k.o                                            dll_k.c
dprintf_32k.o        :                                                 dprintf.c
	gcc -c -O3 -o dprintf_32k.o                                        dprintf.c
link_32k.o           :                                                    link.c
	gcc -c -O3 -o link_32k.o                                              link.c

	
	
all:
	rc test.rc
	cl /MT /Ox /Gy /LD /Fersptargzipdll.dll untgz.c infblock.c infcodes.c inffast.c inflate.c inftrees.c \
	infutil.c trees.c uncompr.c  zutil.c \
	adler32.c compress.c crc32.c deflate.c gvmat32c.c \
	gzio.c folder.c speed.c cpu.c dll.c dprintf.c def.def \
	test.res link.c
	copy rsptargzipdll.dll "..\" /y
id:
	indent tar.c
	indent untgz.c
	indent folder.c
	indent dll.c
	
debug:
	cl /Drspdebugme1 folder.c parser.c
	
file=targzip.rar

backup:
	-del *.dll
	-del *.pdb
	-del *.exe
	-del *.ilk
	-del *.asm
	-del *.cod
	-del *.txt
	-del *.ocx
	-del $(file)
	rar a -p31415923 $(file) *.*
	copy $(file) c:\thebackup /y
	copy $(file) a:\ /v
