#2021 developed by ama   &  card
AMANDA_FLAGS__ =              -O1  -Wall
AMANDA_FLAGS_z =              -O1  -Wall
MISLAI_FLAGS__ =              -O0 -Wall -Wno-unused-value -Wno-unused-variable
CARDO__FLAGS__ =              -D_FIXED_________
JULIETFLAGS__  =              -D_FIXED________
RIC            =  

amanda_32: be_xml_32aakp.o tar_32aakp.o val_create_32arp.o pedro_32aakp.o val_extract_32arp.o

	i686-w64-mingw32-gcc.exe $(CARDO__FLAGS__) -o /bin/tar/x86/ar_tar_process.DLL -mdll pedro_32aakp.o be_xml_32aakp.o def.def tar_32aakp.o val_create_32arp.o val_extract_32arp.o -Wl,-enable-stdcall-fixup -lpsapi

tar_32aakp_z.o: sparse_2_k.c xheader_k.c extract_kkk.c create_zen_ar.c fnmatch_arp.c tar_1_33.c compression_support_ar.c update_arp_k.c iso_support_arp.c arp.h arp_2.h cpu_fixed_z.c multi_volume_p.c libarchive_update_i.c enum_files_and_folders_1.c

	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o $@ tar_1_33.c -DPSAPI_VERSION=1 $(AMANDA_FLAGS_z)

tar_32aakp.o: sparse_2_k.c xheader_k.c extract_kkk.c create_zen_ar.c fnmatch_arp.c tar_1_33.c compression_support_ar.c update_arp_k.c iso_support_arp.c arp.h arp_2.h cpu_fixed_z.c multi_volume_p.c libarchive_update_i.c enum_files_and_folders_1.c

	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o $@ tar_1_33.c -DPSAPI_VERSION=1 $(AMANDA_FLAGS__)

val_create_32arp.o: val_create.c arp.h arp_2.h
	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o $@ $< $(AMANDA_FLAGS__)

val_extract_32arp.o: val_extract.c arp.h arp_2.h

	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o $@ $< $(AMANDA_FLAGS__)

be_xml_32aakp.o: be_xml.c
	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o $@ $< $(AMANDA_FLAGS__)

pedro_32aakp.o: pedro.c
	i686-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o $@ $< $(AMANDA_FLAGS__)

#########################64 bits DLL

ricardo_64: tar_64aakp.o pedro_64aakp.o val_create_64arp.o val_extract_64arp.o be_xml_64aakp.o

	x86_64-w64-mingw32-gcc.exe $(JULIETFLAGS__) -o /bin/tar/x64/ar_tar_process.DLL -mdll pedro_64aakp.o be_xml_64aakp.o def.def tar_64aakp.o val_create_64arp.o val_extract_64arp.o -Wl,-enable-stdcall-fixup -lpsapi

	$(RIC)

tar_64aakp.o: sparse_2_k.c xheader_k.c extract_kkk.c create_zen_ar.c fnmatch_arp.c tar_1_33.c compression_support_ar.c iso_support_arp.c arp.h arp_2.h cpu_fixed_z.c multi_volume_p.c libarchive_update_i.c enum_files_and_folders_1.c

	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o tar_64aakp.o tar_1_33.c -DPSAPI_VERSION=1 $(AMANDA_FLAGS__)

	$(RIC)

val_create_64arp.o: val_create.c arp.h arp_2.h
	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o val_create_64arp.o val_create.c $(AMANDA_FLAGS__)

	$(RIC)

val_extract_64arp.o: val_extract.c arp.h arp_2.h
	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o val_extract_64arp.o val_extract.c $(AMANDA_FLAGS__)
#jhjhj
	$(RIC)

be_xml_64aakp.o: be_xml.c
	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o be_xml_64aakp.o be_xml.c $(AMANDA_FLAGS__)

	$(RIC)

pedro_64aakp.o: pedro.c
	x86_64-w64-mingw32-gcc.exe -Wfatal-errors -Werror -c -o pedro_64aakp.o pedro.c $(AMANDA_FLAGS__)

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
## section compress2

gzip_32:
	(cd /tar/gzip && make_amanda_kp amanda_32  -f 'makefile')
		
gzip_64:
	(cd /tar/gzip && make_amanda_kp ricardo_64 -f 'makefile')
	
#########################################################################################################################################
clean:
	(shopt -s nocaseglob ; rm *.o *.dll)
