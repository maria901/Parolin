
 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                              *
 *        Licensa de Cópia (C) <2021>  <Corporação do Trabalho Binário>         *
 *                                                                              *
 *     Este  programa  é software livre: você pode redistribuir isto e/ou       *
 *     modificar  isto sobre os termos do  GNU Licensa Geral Pública como       8
 *     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da       *
 *     Licensa, ou (dependendo da sua opção) qualquer versão posterior.         *
 *                                                                              *
 *     Este  programa é distribuído na  esperança que isto vai  ser útil,       *
 *     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de       *
 *     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a             *
 *     Licensa Geral Pública para mais detalhes.                                *
 *                                                                              *
 *     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU       *
 *     Licensa Pública Menor junto com este programa                            *
 *     Se não, veja <http://www.gnu.org/licenses/>.                             *
 *                                                                              *
 *     Suporte: https://nomade.sourceforge.io/                                  *
 *                                                                              *
 *     E-mails direto dos felizes programadores:                                *
 *     O Ricardinho :    arsoftware25@gmail.com    ricardo@arsoftware.net.br    *
 *     Little_Amanda:    arsoftware10@gmail.com    amanda.@arsoftware.net.br    *
 *                                                                              *
 *     contato imediato(para uma resposta muita rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/
   
C code and DLL (with sample project) with library libarchive and GNU tar 1.34
to list, update, delete, extract and create latest GNU tar files uncompressed or
compressed with gzip, gzip2, gzip2 multi-thread, bzip2, bzip3, bzip3 multi-thread, lzip, lzop,
lzop2, lzop2 multi-thread, lz4, lz5 multi-thread, lzma, brotli, brotli2
multi-thread, Zstandard, xz , the old Unix compression utility 'compress' (.Z)
, compress2 multi-thread (.Z2), zip, 7zip and many more formats with full Unicode support
when creating and extracting files in windows, compiled with mingw, notice that we have
developed a replacement for tar when running in windows with
support to file attributes, it is extensible without breaking
compatibility with older files, this means that if in the future
we add new features to the format it still will be able to extract
older VAL files, this is the recommended mode to be used, the extension
is .val, support to AES 256, RC4, Serpent, MARS, RC6 and TWOFISH encryption
and also support to upload of files to SFTP server, also .iso files
support was included.

What we implement is largely based on user feedback. If there is a particular
API that is critical to your use of Parolin, then please let us know. We can
then adjust our priorities accordingly.

SourceForge: https://sourceforge.net/projects/parolin/ updated monthly
GitHub     : https://github.com/maria901/Parolin     / updated daily..., no binaries

About the encryption support:

The encryption used is AES 256 CTR mode, RC4, Serpent, MARS,
RC6 and TWOFISH, the majority was borrowed from the rspencdll
project (sources included), it was modified to detect an erroneous
password being used, when using encryption if possible use the VAL
format mode, because standard tar files encrypted will result in
encrypted files being extracted with other tar based software, and
this software when handling tar encrypted files will try to extract
it to see if it is encrypted or not while the VAL format already
know whether it is encrypted or not, you are warned, notice also
that if you update an encrypted file with different passwords it
will fail to extract, updated encrypted files need to have always
the same password, if you want to allow it you need to set the define
ARP_ALLOW_MULTIPLE_PASSWORDS_ to 1 in the file tar_1_33.c and this
hack only work fine for VAL files and it will extract only the entries
where the password is the correct one for the entry, then you need
to extract the same file with the different passwords to have all the
files correctly extracted as you may already expect, notice that from
my point of view an encrypted file with multiple passwords is a damaged
file.

/////////////////////////////////////////////////////////////////////////

Latest documentation is available in these links:

Mirror 1 - https://arsoftware.net.br/binarywork/html/files.html
Mirror 2 -  http://nomade.sourceforge.net/parolin_doc/html/files.html

/////////////////////////////////////////////////////////////////////////

Formats detected by extension when using Parolin:
.lzma (lzma format)
.br   (brotli format)

This occurs because the original developer have not added an easy way
to detect the format by header

All other formats are detected by header, this means that the only
files that need to have the correct extension to extract by the Parolin
or rsptargzip projects is .lzma and .br, make your tests and you will see

When using libarchive all the supported formats are handled correctly,
soon we will make the Parolin project work this way too

//////////////////////////////////////////////////////////////////////////

About encrypted tar files:

Obviously if you try to extract the .tar files with other tar based software
that don`t have our code it will just report that the file is an invalid
.tar file

//////////////////////////////////////////////////////////////////////////

Single-thread only compressors:
gzip
bzip2
lzip
lzma
compress (.Z)
lzop     (.lzo)
lz4
brotli

Multi-thread capable compressors:
gzip2             (compression and decompression)
bzip3             (compression and decompression)
XZ
lzop2    (.lzo2)  (compression and decompression)
Zstandard
lz5               (compression and decompression)
brotli2           (compression and decompression)
compress2         (compression and decompression)

Notice that the number of threads used in the decompression (when
supported) is based in the number of threads used to compress the
file and not in the selected number of threads

If you select 1 thread then a single-thread code will be used
to extract a multi-thread file, if you select 8 it will use
as many threads as the number of threads used to compress the
file, I hope that it is well explained

Anyway the decompress sample code will show how many threads
are being used to uncompress the file, just take a look in the
sample project on how to get this information, the sample is
very simple

////////////////////////////////////////////////////////////////////

About the advantages and disadvantages of using multi-thread

            important: using multiple threads for compression and 
            decompression will only be useful if the time to compress
            and decompress is higher than the time to handle the
            required temp files, make some tests with large files
            and you will see, it may slow down the execution in some
            cases

            example: if the compression of a file requires 1 second
            and the handling of the temp files requires 10 seconds it
            is better to stay with the single-thread mode, I hope you
            understand it

////////////////////////////////////////////////////////////////////

Compressors that don´t have a checksum for integrity check:

compress
compress2
lz4
lz5
lzop2

Then if a damaged file is loaded it may extract without an error, this is
the price to be fast...

////////////////////////////////////////////////////////////////////

Header information for Parolin:

the following information can be used to detect a compressed file

Notice that some formats like bzip3 and gzip2 have more than one
header for it, and you need to handle it

 { compress,              2, "\037\235" },
 { gzip,                  2, "\037\213" },
 { bzip2,                      3, "BZh" },
 { lzip,                      4, "LZIP" },
 { lzma,                  6, "\xFFLZMA" }, (this is not correct, lzma don`t
                                            have a pre-defined header that
					    can be used to detect it, brotli too)
 { lzop,                   4, "\211LZO" },
 { xz,                 6, "\xFD" "7zXZ" },
 { lz4,           4, "\x04\x22\x4d\x18" },
 { zstd,          4, "\x28\xB5\x2F\xFD" },
 { val,           4, "\x56\x41\x4c\x50" },
 { gzip2a,        4, "\x52\x53\x50\x47" }, ( after release 5.1.7 this
                                              don`t extract anymore)
 { gzip2c,        4, "\x41\x52\x5f\x5f" },
 { gzip2c,        4, "\x41\x52\x5f\x5E" },
 { bzip3,         4, "\x41\x52\x5f\x32" },
 { bzip3,         4, "\x41\x52\x5f\x5d" },
 { lzop2,         4, "\x41\x52\x5f\x53" },
 { lz5,           4, "\x41\x52\x5f\x56" },
 { brotli2,       4, "\x41\x52\x5f\x55" },
 { compress2,     4, "\x41\x52\x5f\x54" },

////////////////////////////////////////////////////////////////////

Information about unknown formats handled by Parolin:

lz5       = lz4 with multithread support
lzop2     = based on lzo library with multi-thread support
brotli2   = brotli with multi-thread support
compress2 = Unix compress with multi-thread support

////////////////////////////////////////////////////////////////////

About 7zip compression methods available

For the moment the libarchive modified to support encrypted files
can handle and extract the methods:

LZMA
LZMA2

Other valid 7zip compression methods available in the original GUI
that cannot be extracted for the moment are:

PPMD
Bzip2

But you can list the files and folders if you want

Sorry for this limitation

////////////////////////////////////////////////////////////////////

Changelog:

What is new in version 7.9.1  build 005866 Fri 17/September/2021 23:59:61 codename Dirson

.......... For the moment the  7zip  support  is  only to not
.......... encrypted files, in compression and uncompression,
.......... the 7zip  code  developed and release by Igor were
.......... just  removed,  sorry, if  you think  that you are
.......... brave  enough  to  fix  the   original  Igor  code 
.......... download  the  latest  version  tag  that have the
.......... buggy code from GitHub at:
https://github.com/maria901/Parolin/tree/v6.8.2.12
.......... It  is  in the folder 7zip... good luck it is pure
.......... COM based calls in C++
..........
.......... A  good  replacement  for  encrypted 7zip files is
.......... VAL with lzma  compression in encrypted mode, give
.......... it a try, and if using encryption use the new mode
.......... AES CTR is  the  recommended  encryption  mode for
.......... maximum security
.......... Also  this  release  is  capable  of  creating and
.......... extracting VAL files with  wide paths (larger than
.......... MAX_PATH), but notice that the compressors and deco-
.......... mpressors  are  not  for the moment, only pure VAL
.......... files,  and this VAL files if extracted with older
.......... VAL  based  software  the  long paths will be just
.......... truncated as you may expect

What is new in version 6.7.8  build 005753 Segunda 02 Agosto 2021  11:24 codename Lööf
Fixed the files and folders search function, now it is not recursive anymore,
so, no matter how many files and folders you search it will not consume the
stack anymore, minor modifications.

What is new in version 6.4.9  build 005724 Domingo 01 Agosto 2021  23:22 codename Normann
Fixed a bug in the libarchive mode where a read-only file would not
be updated generating an error, now it first removes the read-only
attribute before writing to it, minor modifications.

What is new in version 6.4.7  build 005722 Domingo 01 Agosto 2021  19:12 codename McCaughan
Fixed finally the update for libarchive mode, in the past the update code
was not working as expected in systems with some anti-virus because a
copy of exe and dlls could make the antivirus interfere with the
code, this new version stores all data in a single file as expected, notice
that in the case of Parolin it was already working as expected, also
the replace of the recursive files and folders search yet don't is using
the non recursive code but the code is already embedded on the sources, next
release will use it, minor modifications.

What is new in version 6.0.8  build 005683 Sabado  31 Julho  2021  17:45 codename Ikonen
First release compiled with -Wextra for safety, minor modifications,
notice that the update archive portions of the code is not complete
yet.

What is new in version 5.8.6  build 005661 Sexta  30 Julho 2021  18:45 codename Gabard
Finished the replacement of the folders for folders based on Cygwin for ease
of use, and no more predefined folders that may not exist in your system,
notice that you need to create the paths referred in tar.sh or it will
not compile, or maybe you can customize the folders to fit your needs,
minor modifications, notice that yet the update archives code is in debug
mode then if possible don't use it.

What is new in version 5.4.21 build 005626 Sabado 24 Julho 2021  08:35 codename Floc'hlay and Ébalard
Rearranged the sources for ease of access and compilation, minor modifications,
soon we will have a major release (6.0).

What is new in version 5.4.20 build 005625 Sat 12/June/2021   02:27:57 codename Payrard
Fixed a sftp bug that was causing the connection to never finish, minor modifications.

What is new in version 5.4.19 build 005622 Fri 28/May/2021 21:35:29  codename Liddicott
Added progress information to the method LZMA of 7zip extraction, it was missing in the
last release, minor modifications.

What is new in version 5.4.18 build 005621 Fri 28/May/2021 17:05:03 codename Audoly
Added more errors reports for unhandled compression methods in the extraction, notice
that the DLL can list files and folders even from unsupported compression methods,
like PPMD and Bzip2 methods, minor modifications.

What is new in version 5.4.17 build 005619 Fri 28/May/2021 09:04:33 codename Nemec
First release with support to encrypted 7zip files in the standard mode, with
or without encrypted headers (see the sample project), documentation will
be updated today also, minor modifications.

What is new in version 5.4.13 build 005610 Fri 21/May/2021 16:08:41 codename Belabas
Fixed inconsistencies in time retrieval between libarchive and Parolin, fixed
a folder timestamp error that was setting the modification time as creation time
in folders in Parolin, minor modifications.

What is new in version 5.4.8  build 005609 Fri 21/May/2021 00:36:43 codename Takayama
Fixed a possible stack consume in the function EnumerateFolder when too many
files or folders are handled due to the required recursive call, now the required
memory for the function is malloced, minor modifications.

What is new in version 5.4.7 build 005608 Thu 20/May/2021 21:41:29 codename Rouillier
First release with support to update libarchive based files, this is new to
libarchive that don`t allow update out of the box, notice that it requires files
copied to a temporary folder for the moment, future versions may use only a single
temp file to store all the required data, minor modifications.

What is new in version 5.4.6 build 005607 Tue 18/May/2021 14:09:44 codename Grayson
Updated Zstandard from version 1.4.9 to version 1.5.0, minor modifications.

What is new in version 5.4.5 build 005606 Mon 17/May/2021 20:25:23 codename Seidl
Added code in the scripts section to force a recompilation if the version
of mingw and mingw64 have changed, recompiled the code with the version
11.1.0 of mingw and mingw64 (GCC), minor modifications.

What is new in version 5.4.1 build 005601 Mon 10/May/2021 13:09:27 codename Michel
Added code to check the validity of files and folders on entrance and not
during compression or decompression, also it will detect and inform error
if the files or paths are relative and not complete, minor modifications.

What is new in version 5.4.0 build 005947 Mon 10/May/2021 07:34:34 codename Martens
First release with support to the library libarchive, notice that some
formats supported by libarchive are disabled in this release because some
modifications need to be added to handle Unicode correctly, rar and rar5 are
two of then, but zip and 7zip was added without problems (after a few
modifications on the original libarchive code), take a look in the sample
project to see how to use libarchive, it is self-descriptive, minor
modifications

What is new in version 5.3.7 build 005947 Wed 21/April/2021 16:25:54 codename McGrath
First release with support to multiple volumes, the sample project
shows how to split the tar or VAL file in slices of selected bytes
size, the first file has an extension .001 and so on, to extract
or list the file just pass any of the slices that range from
.001 to .099 or more to the decompression function and it will handle
the multi-files compressed perfectly, make a few tests and you
will see, then if your file is file.val.gz the first slice will
be file.val.gz.001, the multi-volume tar files can be decompressed
with 7zip or Winrar, replaced the ini file with a XML file, sorry
for the delay, minor modifications

What is new in version 5.3.5 build 005944 Sat 20/March/2021 09:01:37 codename Delgado
Fixed a bug that was causing to some files not added to the Tar or (VAL)
file, the attribute files code was borrowed from the rspzip project
but it have bugs, now fixed, minor modifications.

What is new in version 5.3.3 build 005942 Mon 15/March/2021 10:49:41 codename Corsepius
Fixed a bug on the progress information of the extract progress,
fixed the iso code that in older versions cannot have multiple
instances of the creation or extraction running at the same time, now
you can create two isos at the same time in two copies of the sample
project at the same time, minor modifications.

What is new in version 5.3.0 build 005939 <internal only>            codename Crain
First release with support to decompression using multi-thread for
lz5 and brotli2, sample project now show threads used and memory
usage, minor modifications.

What is new in version 5.2.9 build 005938 Sat 13/March/2021 17:51:28 codename Dariol
First release with support to decompression of bzip3 files in
multi-thread mode, more than 50% speed improvement for each
additional core, fixed the bzip2 handling rotines to support
the creation and extraction of files above 2GB, minor modifications.

What is new in version 5.2.7 build 005936 Fri 12/March/2021 22:41:26 codename DeJong
Fixed the gzip2 decoding bug called now 'Z_BUF_ERROR' bug, the
explanation about it is available in our homepage, it was our
mistake from 20 years ago fixed now, sorry for the problems, this
is exactly the kind of bug that I studied to never create, hope to
never see such a bug again in the rest of my life

Next release to be available tomorrow will fix too the 2GB bzip2
limit, notice that bzip3 don`t have this problem also the next release
will extract bzip3 files using multi-thread for speed improvements, for
the moment it can only create bzip3 files using multi-thread, if correctly
implemented the multi-thread code can be up to 100% faster for each
additional core as you may expect, major modifications.

Future releases will also allow the use of two or more instances of the
sample project at the same time to handle .iso files without problems.
For the moment if you do it it may only crash the DLL, this occurs
because the global data in memory to exchange information with the
.iso handling executable is fixed, the next release will generate an
unique name for each instance running, the .iso handling rountines
requires the exchange of data between an executable and the main
tar DLL, and this only occurs because you cannot have a mingw DLL
and a cygwin DLL in the same address space without a crash.

What is new in version 5.2.6 build 005935 <internal only>            codename Desitter

Problem found on the gzip2 compress and decompressor,
notice that it only occurs with very specific files, we supose that
it was the reason we have not detected it in the past, then chances
are that you will be unable to extract your gzip2 files in some cases,
we want to apologize for the problem and notice that the code that we
was using was borrowed from the original zlib pages, I just don`t
understand why this problem have occurred.

First release with gzip2 code that can uncompress using multi-thread,
notice that after this new release the code cannot extract anymore
very old gzip2 files where the header was "AR__", if you really need to
handle an old file or the file cannot be extracted in this version or
above just download and try again with one version below or equal 5.1.7, and
now we will use miniz as the zlib handler, but if you want to keep
using zlib you can of course modify the sources.

We just figured out that the old code for bzip2 cannot handle files
above 2GB, it will be fixed in the next release, sorry for the problem

What is new in version 5.2.5 build 005934 Wed 10/March/2021 19:39:57 codename Drepper
First release with compress2 with uncompression as multi-thread when
selected

            important: using multiple threads for compression and 
            decompression will only be useful if the time to compress
            and decompress is higher than the time to handle the
            required temp files, make some tests with large files
            and you will see, it may slow down the execution in some
            cases

            example: if the compression of a file requires 1 second
            and the handling of the temp files requires 10 seconds it
            is better to stay with the single-thread mode, I hope you
            understand it

What is new in version 5.1.9 build 005929 Wed 10/March/2021 15:03:55 codename Dumont
First release with multi-thread capabilities on the decompression, for
the moment it is the lzop2 compressor, soon (if possible) all the
multi-thread capable compressors will also decompress using multi-thread,
my tests show that for each core decompressing it will speed up 2% to
10% the execution, minor modifications.

What is new in version 5.1.7 build 005927 Tue 09/March/2021 15:40:19 codename Richard
Replaced the lzop2 code with the enhanced interface that is being
used in compress2 and brotli2, it is faster and less prone to internal
bugs, notice that the header changed too, then if you created a few
lzop2 files since the last week you need to create it again, minor
modifications.

What is new in version 5.1.5 build 005915 Tue 09/March/2021 08:17:59 codename Haifa
Bug fix version, the problem was with the VAL format, in this case
if the VAL file was less than 512 bytes an error was occurring, now
it can handle VAL files of any size, minor modifications.

What is new in version 5.1.4 build 005914 Mon 08/March/2021 20:15:58 codename Ediger
First release with support to compress2 (.Z2) it is the old Unix
compress utility as multi-thread, the multi-thread version runs twice
faster than the original compress code, make your tests and you will
see, minor modifications.

What is new in version 5.1.0 build 005910 Mon 08/March/2021 11:46:27 codename Eggert
Updated the lzip library to the version 1.12, minor modifications.

What is new in version 5.0.7 build 005907 Mon 08/March/2021 02:20:20
Updated the Zstandard code from 1.4.8 to 1.4.9 released a few days ago,
no speed improvements, at least in our tests, but as the changelog says
it have a few bugs fixed, minor modifications.

What is new in version 5.0.6 build 005906 Sun 07/March/2021 08:08:08 codename Ehrhardt
Fixed a bug that appeared by magic in the new encryption code, kkkkkkkkk,
now it is working again, and remember, only use the old encryption method
if you really cannot use the new mode, minor modifications.

What is new in version 5.0.5 build 005905 Sun 07/March/2021 05:36:06 codename Eres
First release with brotli2, brotli2 is brotli with multi-thread support,
this is the best compressor for text files now, use brotli only if you
need compatibility with it, and soon you will see multi-thread decompressors
for these new muti-thread modes, minor modifications.

What is new in version 5.0.3 build 005903 Fri 05/March/2021 15:56:53 codename Faylor
First version with lz5 compressor, it is lz4 with multi-thread support,
fixed small bugs, minor modifications, the lz5 is the preferred method
for fast compression, notice that for speed it don`t have checksums,
if checksum is important use lzop2, it is also fast, using rsp32 as
checksum.

What is new in version 5.0.0 build 005900 Thu 04/March/2021 07:28:09 codename Fish
First release with support to the new lzop2 compressor, when running
as multi-thread it is faster than lz4, fixed a bug that was causing
a decoder error in the lzop2 decompressor, minor modifications.

What is new in version 4.9.8 build 005896 Tue 02/March/2021 01:53:02 codename Gerwinski
Fixed a small bug on the bzip3 compression, it will show an assert window
in the second execution of the multi-thread code.

What is new in version 4.9.7 build 005895 Tue 02/March/2021 00:24:26 codename Gilmore
First release with bzip compression also in multi-thread mode, notice
that the multi-thread mode is a lot faster than single-thread, even
if you don´t have a lot of cores, make some tests and you will see,
we saw that the extract in multi-thread mode may speed up the
execution and will be implemented in future releases of the embedded
compressors, minor modifications

What is new in version 4.9.3 build 00585 Sun 28/February/2021 18:52:32 codename Granlund
Added code to keep the temp data in memory resulting in a faster execution
when running in multi-thread mode the gzip2 compressor, next to run in
multi-htread mode is bzip3, that is an enhancement over bzip2, minor
modifications

What is new in version 4.9.1 build 00583 Sun 28/February/2021 00:16:18 codename Gschwind
First release with a version of gzip2 with support to multi-htread, in
the compression for the moment but soon if possible also in decompression,
minor modifications, notice that single-thread gzip2 files and multi-thread
gzip2 files can be extracted without problems, the code is smart enough
to detect and handle it correctly at runtime, the next to have multi-thread
support added is bzip3, also you will see that even when many threads
are running in the gzip2 format the progress is very accurated, this don't
occur with XZ and Zstandard, these compressors report 97 percent when it
is running, make your tests and you will see, maybe we can fix this problem
in a near future without breaking compatibility



important: gzip2 below 4.9.1 cannot extract a
           multi-thread gzip2 file, only single-thread based,
           I supose that it is obvious



What is new in version 4.8.3 build 00577 Wed 24/February/2021 05:47:09 codename Biener
Accelerated the execution of the VAL handling rountines several times,
now it finishes in less than a second what in the past was requiring
5 seconds, it is now just slightly slower than TAR rountines, added the
possibility to define how many threads will be used for XZ compression,
notice that the progress information will not work as expected because
you cannot know when one of the threads will end, it will return 97%
while it is working, added a new now correct mode to encrypt the files,
the old mode was encrypting the files before the compression, generating
a now very well compressible data (my mistake), the new method is the
recommended method, but the old mode is still available for compatability
purposes, this version yet is not loading in the memory files below 16
mb, but a future version will, for fast file access, this version fixes
a problem when listing or extracting files that are in read-only disk,
in the past it will just return an error since it will be unable to
create a temporary file in these read-only disks, and now you can set
the temp folder to be used, if not then the default user temp will
be used, many modifications were added.

What is new in version 4.7.1 build 00555 Thu 18/February/2021 20:34:07 codename Gundapaneni
Updated the sources of the GNU tar code to the release 1.34, fixed a bug
in the SFTP code that was generating an error when sending files above
8 mb, minor modifications.

What is new in version 4.6.7 build 00541 Mon 15/February/2021 14:51:42 codename Hazeghi
First release with support to RC6 and TWOFISH encryption, minor
modifications.

What is new in version 4.6.3 build 00537 Mon 15/February/2021 08:22:25 codename Hikichi
First version with support to MARS encryption, minor modifications.

What is new in version 4.6.0 build 00534 Sun 14/February/2021 01:49:20 codename Holmgren
First version with support to RC4 encryption, this encryption method
was created a lot of years ago by RSA and it was de defacto before
AES encryption, minor modifications.

What is new in version 4.5.5 build 00529 Sat 13/February/2021 09:42:25 codename Hostetter
First release with support to the formats gzip2 and bzip3, these are
gzip and bzip2 with large file support and advanced checksums, the
sources and makefile was modified to compile the win32 version with
i686-w64-mingw32-gcc.exe, minor modifications.

What is new in version 4.5.1 build 00525 Thu 11/February/2021 08:24:43 codename Innocenti
Fixed a few small bugs in the iso handling code, future releases will
have support to gzip2 and bzip3 file compression formats.

What is new in version 4.4.7 build 00512 Wed 10/February/2021 16:43:33 codename Johnston
Fixed a few bugs in the iso support, added inclusion and exclusion files
for the iso code, minor modifications.

What is new in version 4.4.5 build 00499 Tue 09/February/2021 17:22:39 codename Josuttis
First version capable of creating and extracting iso files, the formats
are limited to the formats supported by mkisofs.exe application from the
Linux project cdrtools, notice that inclusion and exclusion files are
not supported yet in iso mode, and it is a cygwin project then it only
works on 64 bits version, minor modifications.

What is new in version 4.3.0 build 00492 Thu 04/February/2021 14:39:44 codename Kabatek
First version with SFTP upload support, see the sample project to
see how to use it, it is important because many backup systems need
to upload the backup file using FTP or SFTP and SFTP capable code
is difficult to find, future releases will also list the contents
of SFTP and also get files from it.

What is new in version 4.2.7 build 00486 Tue 02/February/2021 13:47:16 codename Kellogg
Upadet the VAL format to store all the file timestamps, not only the
last access time, minor modifications.

What is new in version 4.2.5 build 00478 Mon 01/February/2021 18:29:24 codename Kenner
Extended the limit of the year 2038 in the VAL format, then file dates
can be larger than this, and after now if an invalid timestamp is in the
entry it will be replaced with the current time and date, this is for tar
and VAL format.

What is new in version 4.1.2 build 00456 Mon 01/February/2021 15:04:49 codename Khan
First version with support to encryption in both atr format and VAL
format,  the settings of the sample project is stored in the file
´ar_tar_process.ini´, fixed a bug in the VAL format that was reading 4
bytes where only one was permited, it could lead to a memory corruption,
minor modifications, since all versions of VAL format are compatible
with you already created some files it can extract and list without
problems.

What is new in version 4.0.0 build 00444 Sun 31/January/2021 05:42:46 codename Günter
First version with support to our own archive format, it was developed
to replace zip and tar, and to avoid problems with future modifications
to the format because no matter what change older files can be
extracted without problems, the description about how it work are
expressed in the files val_create.c and val_extract.c, it is not
complicated to understand and the important is that it don´t have any limit
, sizes of filenames or data are limited to 2^64 and from my point of
view it is enough, it have support to file attributes what was missing
on standard tar files, use the tar format only if you need compatibility
with it, the idea was borrowed from the tag support of OGG Vorbis files,
minor modifications.

What is new in version 3.0.6 build 00339 Tue 26/January/2021 08:08:08 codename Kosnik
Replaced the progress of the create process with a method based
on the total size of the files and the bytes read, now it is more
accurate and seasonable, in the past it was based on the number
of files and folders, it was causing a block in the progress when
a large file was processed, and we are thinking about the method
that we will add to the standard tar files to handle the Windows
file attributes, because it is a problem that need to be solved,
for the moment all files have only the archive attribute set on
extraction, at this moment the solution is the creation of a new
variant of the standard GNU tar method with an additional int value
for it, but a little reasearch need to be done to see what is the
best solution, minor modifications as usual.

What is new in version 3.0.5 build 00338 Mon 25/January/2021 04:31:11 codename Kuvyrkov
Fixed a bug in the sample project that was causing a not close of
the cancel form if the tar file is very small, fixed a bug that
was causing the wrong information of tar files that are not
GNU_FORMAT, now all formats are handled correctly no matter what
format was used, all the five formats are supported, the next
release will allow the definition of the tar format, and not only the
GNU_FORMAT, many modifications, the upgrade is recommended.

Fixed a bug that was causing the report and extraction of files

What is new in version 3.0.0 build 00333 Sat 23/January/2021 15:02:18 codename Leikehman
Fixed a bug that was causing the report and extraction of files
with an erroneous timestamp, it was caused by some problems of
the posix function _wstat, in this case it was reporting a
timestamp with a difference of one hour for the real last  modified
information, in 24 years of C programming I never detected this
limitation of the timestamp functions that came from Unix, minor
modifications.

What is new in version 2.9.7 build 00330 Fri 22/January/2021 14:17:42 codename Lemon
First release with support to update a tar file with new entries, and
it also allow to delete entries on a tar file, to do this just select
the wildcard exclusion list of files to remove, minor modifications.

What is new in version 2.8.3 build 00302 Thu 21/January/2021 07:55:09 codename Lerdsuwanakij
Added the option to select whether recurse or not in subfolders,
added the option to not only include but exclude files or wildcards,
minor modifications.

Added more code to the sample project and DLL to allow the cancel
in any stage of the list or extraction, older versions just cannot
do it in a reasonable way.

What is new in version 2.7.1 build 00296 Wed 20/January/2021 21:26:31 codename Love
Added more code to the sample project and DLL to allow the cancel
in any stage of the list or extraction, older versions just cannot
do it in a reasonable way.

First release providing not only Win32 but Win64 DLLs and both
projects ready to be compiled, minor modifications.

What is new in version 2.6.3 build 00275 Wed 20/January/2021 13:53:39 codename Lú
First release providing not only Win32 but Win64 DLLs and both
projects ready to be compiled, minor modifications.

What is new in version 2.5.8 build 00261 Wed 20/January/2021 08:48:08 codename MacLeod
First release with support to Brotli compression, it is the best
compressor for text files, minor modifications.

What is new in version 2.5.2 build 00253 Tue 19/January/2021 08:30:08 codename Manson
First release with support to Zstandard, it is the future of file
compression and is already replacing .xz in the Linux distributions,
notice that for the moment all the compression formats run as a
default compression level (usualy level 6, 3 for Zstandard) but it
will change soon to allow the definition by the user of the compression
level, and soon too the Win64 versions of the DLLs will be available,
minor modifications.

What is new in version 2.4.0 build 00241 Mon 18/January/2021 07:34:15 codename Marino
Fixed a bug that was causing the handling of long filenames (above
100 characters) to generate invalid entries when using posix(pax) mode
decompression, this version can extract any latest GNU tar files
in all known formats, older versions just cannot do it, minor
modifications, future releases will also create GNU tar files in
all formats, something about lzop: it is slower than gzip compression
for the moment, the decompression is fast, we need to research a
little more to see what is wrong in the lzop code, for the moment
if you need fast compression and decompression use the lz4 compression.

What is new in version 2.3.5 build 00236 Sat 16/January/2021 21:15:17 codename Meissner
Fixed a few memory leaks that was causing problems, notice that the
next release will be based on the GNU tar version 1.33 released at
07 January 2021.

What is new in version 2.3.1 build 00232 Wed 13/January/2021 14:25:33 codename Michlmayr
First version with support to lz4 compression, minor modifications.

What is new in version 2.2.0 build 00221 Tue 12/January/2021 11:48:59 codename Minarik
Fixed a problem that was creating invalid entries with paths larger
than 100 characters, now it can be up to MAX_PATH as expected, minor
modifications.

What is new in version 2.1.5 build 00216 Thu 31/December/2020 09:46:04 codename Moore
Fixed a bug that was causing the compress function to be unable to
open an output file to write in some cases when mode compress was
selected, first release capable of handling lzop files, minor modifications.

What is new in version 2.0.1 build 00201 Wed 30/December/2020 12:16:34 codename Mosberger-Tang
First release with support to .Z files (Unix compress utility), minor
modifications, now only lzop is missing...

What is new in version 1.9.2 build 00185 Wed 30/December/2020 07:14:10 codename De Muyter
First release with support to xz compression, minor modifications.

What is new in version 1.8.1 build 00153 Tue 29/December/2020 23:30:21 codename Nerode
First version with support to LZMA compressed tar files, notice that
due to a limitation of the LZMA format the compressed file cannot be
easily detected without the decompression of part of the file, then for the
moment the lzma compressed file is detected by extension, if it is .lzma
or .tlz it is a lzma file, this recommendation come from Igor Pavlov
the creator of LZMA, fixed an Unicode problem with lzip files (they are
missing), minor modifications.

What is new in version 1.7.8 build 00148 Tue 29/December/2020 11:52:27 codename Nilsson
First release with support to lzip compression, xz and lzma will be
added soon, minor modifications.

What is new in version 1.6.5 build 00135 Sun 27/December/2020 12:37:47 codename Novillo
Enhanced the way the timestamp of files are handled, notice that
folder timestamp in windows is irrelevant because when a file is
updated in a folder the timestamp changes, notice that it can have
up to one hour of difference of the timestamp of files in some cases,
I am yet reaserching on it, minor modifications.

What is new in version 1.5.1 build 00125 Sun 27/December/2020 00:38:21 codename Orth
Added full Unicode support when creating and extrating files at least
in windows, the files created are 100% compatible with Winrar, also
Winrar based tar files can be extracted without problems or warnings,
minor modifications.

What is new in version 1.3.5 build 00112 Sat 26/December/2020 15:49:36 codename Pemberton
First version that can handle compressed tar files in the gzip and bzip2
format (future versions will handle also more compression formats), minor
modifications.

What is new in version 1.1.2 build 0095 Fri 25/December/2020 00:34:30 codename Petersen
First version capable of creating Tar files, debug information removed,
next version will also update an already existent Tar file, now back
to the code.

What is new in version 1.0.1 build 0078 Tue 22/December/2020 13:56:58 codename Petit-Bianco
First version as a DLL with all the required code to create an
application to list and extract tar files, notice that for the moment
you need to ungzip prior to the process, it is only capable of handling
uncompressed tar files, the next step now is to add the possibility to
also create tar files, now back to the code.

What is new in version 0.8.0 build 34 Fri 18/December/2020 09:56:42 codename Pfaller
First release with support to latest gnu tar files, older versions
was only capable of extracting old tar files.


Thanks for using our software
