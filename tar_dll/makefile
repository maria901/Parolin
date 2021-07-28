#2021 developed by ama   &  card
AMANDA_FLAGS__ =              -O3  -Wall
AMANDA_FLAGS_z =              -O3  -Wall
MISLAI_FLAGS__ =              -O0 -Wall -Wno-unused-value -Wno-unused-variable
CARDO__FLAGS__ =              -D_FIXED_________ -O3
JULIETFLAGS__  =              -D_FIXED________  -O3
RIC            =  

amanda_32: /bw_tmp/parolin/be_xml_32aakp.o /bw_tmp/parolin/tar_32aakp.o /bw_tmp/parolin/val_create_32arp.o /bw_tmp/parolin/pedro_32aakp.o /bw_tmp/parolin/val_extract_32arp.o

	-rm *.DLL *.dll *.ric *~ *.exe *.EXE *.o *.a

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "32 bits" ar_tar_process.DLL increase

	@i686-w64-mingw32-windres.exe -o /bw_tmp/parolin/amanda_ver32.o -O coff version_ricardo_mislaine_final_2_.rc

	i686-w64-mingw32-gcc.exe $(CARDO__FLAGS__) -o /bin/tar/x86/ar_tar_process.DLL -mdll version_amanda.c /bw_tmp/parolin/amanda_ver32.o /bw_tmp/parolin/pedro_32aakp.o /bw_tmp/parolin/be_xml_32aakp.o def.def /bw_tmp/parolin/tar_32aakp.o /bw_tmp/parolin/val_create_32arp.o /bw_tmp/parolin/val_extract_32arp.o -Wl,-enable-stdcall-fixup -lpsapi

/bw_tmp/parolin/tar_32aakp_z.o: sparse_2_k.c xheader_k.c extract_kkk.c create_zen_ar.c fnmatch_arp.c tar_1_33.c compression_support_ar.c update_arp_k.c iso_support_arp.c arp.h arp_2.h cpu_fixed_z.c multi_volume_p.c libarchive_update_i.c enum_files_and_folders_1.c

	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/tar_32aakp_z.o tar_1_33.c -DPSAPI_VERSION=1 $(AMANDA_FLAGS_z)

/bw_tmp/parolin/tar_32aakp.o: sparse_2_k.c xheader_k.c extract_kkk.c create_zen_ar.c fnmatch_arp.c tar_1_33.c compression_support_ar.c update_arp_k.c iso_support_arp.c arp.h arp_2.h cpu_fixed_z.c multi_volume_p.c libarchive_update_i.c enum_files_and_folders_1.c

	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/tar_32aakp.o tar_1_33.c -DPSAPI_VERSION=1 $(AMANDA_FLAGS__)

/bw_tmp/parolin/val_create_32arp.o: val_create.c arp.h arp_2.h
	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/val_create_32arp.o val_create.c $(AMANDA_FLAGS__)

/bw_tmp/parolin/val_extract_32arp.o: val_extract.c arp.h arp_2.h

	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/val_extract_32arp.o val_extract.c $(AMANDA_FLAGS__)

/bw_tmp/parolin/be_xml_32aakp.o: be_xml.c
	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/be_xml_32aakp.o $< $(AMANDA_FLAGS__)

/bw_tmp/parolin/pedro_32aakp.o: pedro.c
	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/pedro_32aakp.o $< $(AMANDA_FLAGS__)

#########################64 bits DLL

ricardo_64: /bw_tmp/parolin/tar_64aakp.o /bw_tmp/parolin/pedro_64aakp.o /bw_tmp/parolin/val_create_64arp.o /bw_tmp/parolin/val_extract_64arp.o /bw_tmp/parolin/be_xml_64aakp.o

	@/bw_tmp/amandaricardo_mvbuild26_33.exe amanda_file_counter_32.ini versio_n.ama.rc version_ricardo_mislaine_final_2_.rc aline_definitive_header_2_.h "64 bits" ar_tar_process.DLL increase

	@x86_64-w64-mingw32-windres.exe -o /bw_tmp/parolin/amanda_ver64.o -O coff version_ricardo_mislaine_final_2_.rc

	x86_64-w64-mingw32-gcc.exe $(JULIETFLAGS__) -o /bin/tar/x64/ar_tar_process.DLL -mdll version_amanda.c /bw_tmp/parolin/amanda_ver64.o /bw_tmp/parolin/pedro_64aakp.o /bw_tmp/parolin/be_xml_64aakp.o def.def /bw_tmp/parolin/tar_64aakp.o /bw_tmp/parolin/val_create_64arp.o /bw_tmp/parolin/val_extract_64arp.o -Wl,-enable-stdcall-fixup -lpsapi

	$(RIC)

/bw_tmp/parolin/tar_64aakp.o: sparse_2_k.c xheader_k.c extract_kkk.c create_zen_ar.c fnmatch_arp.c tar_1_33.c compression_support_ar.c iso_support_arp.c arp.h arp_2.h cpu_fixed_z.c multi_volume_p.c libarchive_update_i.c enum_files_and_folders_1.c

	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/tar_64aakp.o tar_1_33.c -DPSAPI_VERSION=1 $(AMANDA_FLAGS__)

	$(RIC)

/bw_tmp/parolin/val_create_64arp.o: val_create.c arp.h arp_2.h
	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/val_create_64arp.o val_create.c $(AMANDA_FLAGS__)

	$(RIC)

/bw_tmp/parolin/val_extract_64arp.o: val_extract.c arp.h arp_2.h
	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/val_extract_64arp.o val_extract.c $(AMANDA_FLAGS__)
#jhjhj
	$(RIC)

/bw_tmp/parolin/be_xml_64aakp.o: be_xml.c
	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/be_xml_64aakp.o be_xml.c $(AMANDA_FLAGS__)

	$(RIC)

/bw_tmp/parolin/pedro_64aakp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o /bw_tmp/parolin/pedro_64aakp.o pedro.c $(AMANDA_FLAGS__)

	$(RIC_amandinha)

################################################################################################################################
## section 7zip

7zip_32      :
	(cd '/tar/7zip/CPP/7zip/Bundles/Alone7z' && rm /bin/tar/x86/BE_7zip_r_32.DLL ; make_amanda_kp -f 'makefile.gcc.x86')

7zip_64      :
	(cd '/tar/7zip/CPP/7zip/Bundles/Alone7z' && rm /bin/tar/x64/BE_7zip_r_64.DLL ; make_amanda_kp -f 'makefile.gcc.x64')
	
clean_7zip   :
	(cd /bw_tmp/7zip_x86 && rm *.o)
	(cd /bw_tmp/7zip_x64 && rm *.o)
	
#########################################################################################################################################
## section Brotli

brotli_32:
	(cd /tar/brotli/brotli-1.0.9/ && make_amanda_kp amanda_32  -f 'makefile')
		
brotli_64:
	(cd /tar/brotli/brotli-1.0.9/ && make_amanda_kp ricardo_64 -f 'makefile')
	
#########################################################################################################################################
## section Brotli2

brotli2_32:
	(cd /tar/brotli2/brotli-1.0.9/ && make_amanda_kp amanda_32  -f 'makefile')
		
brotli2_64:
	(cd /tar/brotli2/brotli-1.0.9/ && make_amanda_kp ricardo_64 -f 'makefile')

#########################################################################################################################################
## section Bzip2

bzip2_32:
	(cd /tar/bzip2 && make_amanda_kp amanda_32  -f 'makefile')
		
bzip2_64:
	(cd /tar/bzip2 && make_amanda_kp ricardo_64 -f 'makefile')

#########################################################################################################################################
## section Bzip3

bzip3_32:
	(cd /tar/bzip3 && make_amanda_kp amanda_32  -f 'makefile')
		
bzip3_64:
	(cd /tar/bzip3 && make_amanda_kp ricardo_64 -f 'makefile')

#########################################################################################################################################
## section compress

compress_32:
	(cd /tar/compress/ncompress-4.2.4.6 && make_amanda_kp amanda_32  -f 'makefile')
		
compress_64:
	(cd /tar/compress/ncompress-4.2.4.6 && make_amanda_kp ricardo_64 -f 'makefile')

#########################################################################################################################################
## section compress2

compress2_32:
	(cd /tar/compress2/compress2_0.0.2 && make_amanda_kp amanda_32  -f 'makefile')
		
compress2_64:
	(cd /tar/compress2/compress2_0.0.2 && make_amanda_kp ricardo_64 -f 'makefile')

#########################################################################################################################################
## section gzip

gzip_32:
	(cd /tar/gzip && make_amanda_kp amanda_32  -f 'makefile')
		
gzip_64:
	(cd /tar/gzip && make_amanda_kp ricardo_64 -f 'makefile')

#########################################################################################################################################
## section gzip2

gzip2_32:
	(cd /tar/gzip2 && make_amanda_kp amanda_32  -f 'makefile')
		
gzip2_64:
	(cd /tar/gzip2 && make_amanda_kp ricardo_64 -f 'makefile')

#########################################################################################################################################
## section libarchive

libarchive_32:
	(cd /tar/libarchive/libarchive-3.5.1/amanda_tests && make_amanda_kp amanda_32                 -f 'makefile')
		
libarchive_64:
	(cd /tar/libarchive/libarchive-3.5.1/amanda_tests && make_amanda_kp ricardo_64                -f 'makefile')

libarchiveupdatesources_at_x86:
	(cd /tar/libarchive/libarchive-3.5.1/amanda_tests && make_amanda_kp update_c_i_x86            -f 'makefile')
	
make_amanda_x86:
	(cd /tar/libarchive/libarchive-3.5.1/amanda_tests && make_amanda_kp make_amanda_x86           -f 'makefile')
	
make_amanda_x86_clean:
	(cd /tar/libarchive/libarchive-3.5.1/amanda_tests && make_amanda_kp make_amanda_x86_clean     -f 'makefile')
	
make_amanda_x64:
	(cd /tar/libarchive/libarchive-3.5.1/amanda_tests && make_amanda_kp make_amanda_x64           -f 'makefile')
	
make_amanda_x64_clean:
	(cd /tar/libarchive/libarchive-3.5.1/amanda_tests && make_amanda_kp make_amanda_x64_clean     -f 'makefile')

#########################################################################################################################################
## section lz4

lz4_32:
	(cd /tar/lz4/lz4_v1.9.3/lib && make_amanda_kp amanda_32  -f 'makefile')
		
lz4_64:
	(cd /tar/lz4/lz4_v1.9.3/lib && make_amanda_kp ricardo_64 -f 'makefile')

#########################################################################################################################################
## section lz5

lz5_32:
	(cd /tar/lz5 && make_amanda_kp amanda_32  -f 'makefile')
		
lz5_64:
	(cd /tar/lz5 && make_amanda_kp ricardo_64 -f 'makefile')
	
#########################################################################################################################################
## section lzip

lzip_32:
	(cd /tar/lzip/lzlib-1.12 && make_amanda_kp amanda_32  -f 'makefile')

lzip_64:
	(cd /tar/lzip/lzlib-1.12 && make_amanda_kp ricardo_64 -f 'makefile')
	
	
#########################################################################################################################################
## section lzma

lzma_32:
	(cd /tar/lzma/LZMA_sdk_c_19.00_2019_02_21 && make_amanda_kp amanda_32  -f 'makefile')

lzma_64:
	(cd /tar/lzma/LZMA_sdk_c_19.00_2019_02_21 && make_amanda_kp ricardo_64 -f 'makefile')
	
#########################################################################################################################################
## section lzop

lzop_lib__32:
	(cd /tar/lzop/lzo-2.10 && make_amanda_kp amanda_32     -f 'makefile')

lzop_dll__32:
	(cd /tar/lzop/lzop-1.04 && make_amanda_kp amanda_32    -f 'makefile')

lzop_lib__64:
	(cd /tar/lzop/lzo-2.10 && make_amanda_kp ricardo_64    -f 'makefile')

lzop_dll__64:
	(cd /tar/lzop/lzop-1.04 && make_amanda_kp ricardo_64   -f 'makefile')


#########################################################################################################################################
## section lzop2

lzop2_32:
	(cd /tar/lzop2/new_mode && make_amanda_kp amanda_32      -f 'makefile')

lzop2_64:
	(cd /tar/lzop2/new_mode && make_amanda_kp ricardo_64     -f 'makefile')
	

#########################################################################################################################################
## section psftp

psftp_32:
	(cd /tar/psftp/putty-0.74-2021-02-03.b63a66c/windows/VS2012/psftp/ && make_amanda_kp amanda_32      -f 'makefile')

psftp_64:
	(cd /tar/psftp/putty-0.74-2021-02-03.b63a66c/windows/VS2012/psftp/ && make_amanda_kp ricardo_64     -f 'makefile')
	
#########################################################################################################################################
clean:
	(shopt -s nocaseglob ; rm *.o *.dll)
