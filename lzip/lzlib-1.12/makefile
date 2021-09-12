#2021 amanda & SmartApe, updated May/15, also July/27

AMANDA_FLAGS__=-O3 -Wextra -Wall -Wfatal-errors -Werror -Wno-unused-function

amanda_32: /bw_tmp/lzip/pedro_32.o /bw_tmp/lzip/carg_parser_aakp_rspk_32.o /bw_tmp/lzip/lzlib_aakp_rspk_32.o /bw_tmp/lzip/main_aakp_32.o 

	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" bw_lzip_aakp_32.DLL increase

	@i686-w64-mingw32-windres.exe -o /bw_tmp/gzip2/amanda_ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	@i686-w64-mingw32-gcc.exe -O3 -mdll dll_aakp.def -o /bin/tar/x86/bw_lzip_aakp_32.DLL /bw_tmp/gzip2/amanda_ver32.o /bw_tmp/lzip/pedro_32.o /bw_tmp/lzip/carg_parser_aakp_rspk_32.o /bw_tmp/lzip/lzlib_aakp_rspk_32.o /bw_tmp/lzip/main_aakp_32.o -Wl,-enable-stdcall-fixup

/bw_tmp/lzip/main_aakp_32.o : main_aakp_1.12.c encoder_base.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzip/main_aakp_32.o main_aakp_1.12.c $(AMANDA_FLAGS__)

/bw_tmp/lzip/carg_parser_aakp_rspk_32.o : carg_parser.c encoder_base.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzip/carg_parser_aakp_rspk_32.o carg_parser.c $(AMANDA_FLAGS__)

/bw_tmp/lzip/pedro_32.o : pedro.c encoder_base.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzip/pedro_32.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/lzip/lzlib_aakp_rspk_32.o : encoder_base.h lzlib.c      \
	encoder_base.h
	i686-w64-mingw32-gcc.exe -c -o /bw_tmp/lzip/lzlib_aakp_rspk_32.o lzlib.c $(AMANDA_FLAGS__)

###############################64 bits

ricardo_64: /bw_tmp/lzip/pedro_64.o /bw_tmp/lzip/carg_parser_aakp_rspk_64.o /bw_tmp/lzip/lzlib_aakp_rspk_64.o /bw_tmp/lzip/main_aakp_64.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" bw_lzip_aakp_64.DLL increase

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/lzip/amanda_ver64.o -O coff version_ricardo_mislaine_final_2_.rc

	@x86_64-w64-mingw32-gcc -O3 -mdll dll_aakp.def -o /bin/tar/x64/bw_lzip_aakp_64.DLL /bw_tmp/lzip/amanda_ver64.o /bw_tmp/lzip/pedro_64.o /bw_tmp/lzip/carg_parser_aakp_rspk_64.o /bw_tmp/lzip/lzlib_aakp_rspk_64.o /bw_tmp/lzip/main_aakp_64.o -Wl,-enable-stdcall-fixup

/bw_tmp/lzip/main_aakp_64.o : main_aakp_1.12.c encoder_base.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzip/main_aakp_64.o main_aakp_1.12.c $(AMANDA_FLAGS__)

/bw_tmp/lzip/carg_parser_aakp_rspk_64.o : carg_parser.c encoder_base.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzip/carg_parser_aakp_rspk_64.o carg_parser.c $(AMANDA_FLAGS__)

/bw_tmp/lzip/pedro_64.o : pedro.c
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzip/pedro_64.o pedro.c $(AMANDA_FLAGS__)

/bw_tmp/lzip/lzlib_aakp_rspk_64.o : encoder_base.h lzlib.c encoder_base.h
	x86_64-w64-mingw32-gcc.exe -c -o /bw_tmp/lzip/lzlib_aakp_rspk_64.o lzlib.c $(AMANDA_FLAGS__)
