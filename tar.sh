#compilando...


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


echo "Erro amor..."