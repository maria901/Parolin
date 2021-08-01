#compilando...


if [ "compile32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe amanda_32 -f makefile

exit

fi


if [ "compile64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe ricardo_64 -f makefile

exit

fi


if [ "updatec#" == "$1" ] 
then

cd '/tar/c#_x86/tar_sample_ar/tar_sample_ar/'

cp --preserve=timestamps *.cs *.resx '/tar/c#_x64/tar_sample_ar_x64/tar_sample_ar'

exit

fi


if [ "7zip32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe 7zip_32 -f makefile

exit

fi


if [ "7zip64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe 7zip_64 -f makefile

exit

fi


if [ "7zipclean" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe clean_7zip -f makefile

exit

fi


if [ "brotli32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe brotli_32 -f makefile

exit

fi


if [ "brotli64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe brotli_64 -f makefile

exit

fi


if [ "brotliclean" == "$1" ] 
then

	cd /bw_tmp/brotli/

	rm *.o

exit

fi


if [ "brotli232" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe brotli2_32 -f makefile

exit

fi


if [ "brotli264" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe brotli2_64 -f makefile

exit

fi


if [ "brotli2clean" == "$1" ] 
then

	cd /bw_tmp/brotli2/

	rm *.o

exit

fi


if [ "bzip232" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe bzip2_32 -f makefile

exit

fi


if [ "bzip264" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe bzip2_64 -f makefile

exit

fi


if [ "bzip2clean" == "$1" ] 
then

	cd /bw_tmp/bzip2/

	rm *.o

exit

fi


if [ "bzip332" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe bzip3_32 -f makefile

exit

fi


if [ "bzip364" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe bzip3_64 -f makefile

exit

fi


if [ "bzip3clean" == "$1" ] 
then

	cd /bw_tmp/bzip3/

	rm *.o

exit

fi


if [ "compress32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe compress_32 -f makefile

exit

fi


if [ "compress64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe compress_64 -f makefile

exit

fi


if [ "compressclean" == "$1" ] 
then

	cd /bw_tmp/compress/

	rm *.o

exit

fi


if [ "compress232" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe compress2_32 -f makefile

exit

fi


if [ "compress264" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe compress2_64 -f makefile

exit

fi


if [ "compress2clean" == "$1" ] 
then

	cd /bw_tmp/compress2/

	rm *.o

exit

fi


if [ "gzip32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe gzip_32 -f makefile

exit

fi


if [ "gzip64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe gzip_64 -f makefile

exit

fi


if [ "gzipclean" == "$1" ] 
then

	cd /bw_tmp/gzip/

	rm *.o *.a

exit

fi


if [ "gzip232" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe gzip2_32 -f makefile

exit

fi


if [ "gzip264" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe gzip2_64 -f makefile

exit

fi


if [ "gzip2clean" == "$1" ] 
then

	cd /bw_tmp/gzip2/

	rm *.o *.a

exit

fi


if [ "libarchive32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe libarchive_32 -f makefile

exit

fi


if [ "libarchive64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe libarchive_64 -f makefile

exit

fi


if [ "libarchiveupdatesources_at_x86" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe libarchiveupdatesources_at_x86 -f makefile

exit

fi


if [ "make_libarchive_x86" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe make_amanda_x86 -f makefile

exit

fi


if [ "make_libarchive_x86_clean" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe make_amanda_x86_clean -f makefile

exit

fi


if [ "make_libarchive_x64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe make_amanda_x64 -f makefile

exit

fi


if [ "make_libarchive_x64_clean" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe make_amanda_x64_clean -f makefile

exit

fi


if [ "libarchiveclean" == "$1" ] 
then

	cd /bw_tmp/libarchive/

	rm *.o *.a

exit

fi


if [ "lz432" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lz4_32 -f makefile

exit

fi


if [ "lz464" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lz4_64 -f makefile

exit

fi


if [ "lz4clean" == "$1" ] 
then

	cd /bw_tmp/lz4/

	rm *.o

exit

fi


if [ "lz532" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lz5_32 -f makefile

exit

fi


if [ "lz564" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lz5_64 -f makefile

exit

fi


if [ "lz5clean" == "$1" ] 
then

	cd /bw_tmp/lz5/

	rm *.o *.exe

exit

fi


if [ "lzip32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lzip_32 -f makefile

exit

fi


if [ "lzip64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lzip_64 -f makefile

exit

fi


if [ "lzipclean" == "$1" ] 
then

	cd /bw_tmp/lzip/

	rm *.o

exit

fi


if [ "lzma32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lzma_32 -f makefile

exit

fi


if [ "lzma64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lzma_64 -f makefile

exit

fi


if [ "lzmaclean" == "$1" ] 
then

	cd /bw_tmp/lzma/

	rm *.o

exit

fi


if [ "lzop32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lzop_lib__32 -f makefile

cd /tar/tar_dll

make_amanda_kp.exe lzop_dll__32 -f makefile

exit

fi


if [ "lzop64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lzop_lib__64 -f makefile

cd /tar/tar_dll

make_amanda_kp.exe lzop_dll__64 -f makefile

exit

fi


if [ "lzopclean" == "$1" ] 
then

	cd /bw_tmp/lzop/

	rm *.o
	
	cd /bw_tmp/lzop_b/

	rm *.o

exit

fi


if [ "lzop232" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lzop2_32 -f makefile

exit

fi


if [ "lzop264" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe lzop2_64 -f makefile

exit

fi


if [ "lzop2clean" == "$1" ] 
then

	cd /bw_tmp/lzop2/

	rm *.o
	
exit

fi


if [ "psftp32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe psftp_32 -f makefile

exit

fi


if [ "psftp64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe psftp_64 -f makefile

exit

fi


if [ "psftpclean" == "$1" ] 
then

	cd /bw_tmp/psftp/

	rm *.o
	
exit

fi



if [ "rsp_encrypt32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe rsp_encrypt_32 -f makefile

exit

fi


if [ "rsp_encrypt64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe rsp_encrypt_64 -f makefile

exit

fi


if [ "rsp_encrypt_clean" == "$1" ] 
then

	cd /bw_tmp/rsp_encrypt/

	rm *.o
	
exit

fi



if [ "xz32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe xz_32 -f makefile

exit

fi


if [ "xz64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe xz_64 -f makefile

exit

fi


if [ "xz_clean" == "$1" ] 
then

	cd /bw_tmp/xz/

	rm *.o *.a
	
	cd /bw_tmp/xz_b/

	rm *.o *.a
	
exit

fi


if [ "Zstandard32" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe Zstandard_32 -f makefile

exit

fi


if [ "Zstandard64" == "$1" ] 
then

cd /tar/tar_dll

make_amanda_kp.exe Zstandard_64 -f makefile

exit

fi


if [ "Zstandard_clean" == "$1" ] 
then

	cd /bw_tmp/Zstandard/

	rm *.o	
	
exit

fi


echo "Erro amor..."