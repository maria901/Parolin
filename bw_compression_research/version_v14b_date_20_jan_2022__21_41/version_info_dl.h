#define THE_CURRENT_DL_COMPRESSOR_VERSION_FOR_THIS_RELEASE___ (((53 + 3 + 3 + 2))) /* each version can encode/decode a single version, if don't match the decoder will point you to the correct version to download the decoder binary ready to be used */

#define STRING_VERSION_DL_COMPRESSOR " v14b build 00235   \n(char value == 53 + 3 + 3 + 2) \ncodename: Mauro \n(" __TIME__ " " __DATE__ ") \n\n"

/*

*/

// versions below this are invalid

#define THE_FIRST_RELEASE_WITH_A_DDECDER___ (((53 + 0 + 0 + 0)))

minha_struct.version_of_the_code = THE_CURRENT_DL_COMPRESSOR_VERSION_FOR_THIS_RELEASE___; // v12 started 17 jan 2022 18:57

/*
........... (20 jan 2022 16:02)
........... 101643 - ric (v14a)
........... 101575 - Haruhiko Okumura
........... 101638 - Michael Dipperstein
...........
........... (18 jan 2022 19:58)
........... Again... now while zlib compresses to 85kb v12b compresses
........... to 68kb, he he he, soon I get the bug
........... For fun I am releasing version v12b, but know that 
........... this is a buggy version, only to test, the lzss + ari 
........... standard working version compresses to 90 kb
...........

*/

/*
...........
........... (18 jan 2022 13:25)
........... Great... now while zlib compresses make.exe to 85kb 
........... our v12 is compressing to 23kb 
........... More work to find the bug now...
...........

........... in v12 we will try to compress better adding
........... more 8kb at the dictionary size using past 
........... buffers like v10
........... it will add the overhead of more one bit
........... to the compressed stream
........... Coding...
...........
........... v12 will use two bits to select each of the
........... 4 buffer of 4096 bytes making 16 kb of buffer
...........

*/

/*


........... v10 was finished and tested at:
........... 17 jan 2022 16:48 PM
........... Ok, bug fixed, now the tests and soon the release
........... available
........... The bug was in the decompressor
...........
........... Version v10 compresses make.exe to 106kb, while
........... version v9c compresses to 111kb
...........


*/

// 9.c version initiated at 13 jan 2022 09:48

/*

...........
........... First version that will not only encode but also decode
...........
........... We will store the data information on the compressed
........... file in such a way that a fseek and fwrite is not
........... required to store file header information, for a
........... compressed file the pre last 8 bytes stores the
........... original uncompressed size and the last 8 the
........... compressed size, to help the usage in a near
........... future, while the compressed information for
........... each 4096 compressed chunck is already encoded
........... in the compressed stream, it will make it easy
........... to retrieve the information about the compressed
........... data for decoders, also the first four bytes
........... will never change only the version value will
........... increase

........... (14/jan/2022 23:55) Due to the bug in the encoder the compression ratio changed,
........... now it is more close to the expected ratio, and it is not
........... outperforming lzss + ari when text compression is used
...........
........... What occurred: Due to the bug in the conder that data was there
........... but large sets of character 0 instead of real data
........... and arithmetic compression compresses very well this kind
........... of data
........... when the bug got fixed it start passing real data for the
........... arithmetic compressor and it obviously was dimishing the
........... compression ratio, now what was compressing to 96 kb is
........... compressing to 111 kb, giving the same compression ratio
........... as compress from Unix (.Z) files
........... To avoid future problems like this after now we will
........... always provide a decoder to test and avoid large mistakes
........... like these
........... The v9.c release that don't compresses well will be
........... uploaded to GitHub in a few minutes
........... sorry for the problem, my mistake
...........

*/

// 9th version... initiated at 12 jan 2022 18:10:05
/*

........... v9 development starts now (18:10 12 jan)...
........... We will expand the 8192 buffer size
........... to (1 << 14) at the beginning and also
........... if possible will expand the 18 characters
........... string limit
...........
........... v9.a is available at GitHub, v9.b will follow
........... soon, but first we need a decoder
...........
........... version v9.b is available, it can compress make.exe to
........... 91kb and tar_1_33.c to 64kb
...........
........... our v9.b is compressing text files better than lzss + ari
........... we will create the decoder now
...........
........... Without the additional bit for more 4096 bytes to search
........... it diminishes the size of the compressed file in 1 kb only
........... And using the additional bit 5kb was won
...........
........... (09:21 13 jan)
........... before 12:00 hs we will have a decoder alive and
........... kicking
...........
........... Version information is stored in the compressed file
........... and the correct version is required to decompress
........... If you try to decompress a newer file with an older
........... version or vice versa it will point you to the
........... correct version
........... each version will decode only the pre-defined version
...........
........... Debug version need to show the size of the strings
........... matched and the count also to show how it can be
........... improved
........... v9.c will follow at 12:00 hs
...........
*/
// minha_struct.version_of_the_code = 7; // 8th version... initiated at 12 jan 2022 10:49:08
/*

........... (10:49) I should be sleeping but just figured out that the rle
........... problem need to be solved yet today, because files
........... highly compressible don't compress well as pure rle
........... More on it in two hours

........... v8 development started (11:27), first we will make the code
........... compress highly compressible files very well
........... I don't remember about the instrinsics of zlib
........... but the sources talk about rle enconding and
........... standard lzss and our modified lz77 compress
........... up to 18 characters strings to two bytes plus a bit
........... Working on it, for it we will add a very large high
........... compressible file and add to the tests

........... (11:50) Even without rle on it the compressor can dimish a 30 kb file
........... to 300 bytes, maybe it will not be a problem

........... Interesting tar_1_33.c:
...........                         zip          : 59kb
...........                         lzss + ari   : 74kb
...........                         dl_compressor: 83kb
........... A lot need to be enhanced yet
...........
........... (12:12) For the moment we are using only 4096 bytes for
........... the limited search method, we will expand it to
........... (1 << 13) without losing the two bytes pointer
........... size that is a good value to make the compression
........... What we will do is use the past buffer of 4098
........... as an additional search item if not found in the
........... current buffer being searched, and if possible
........... increasing only the additional bit to define whether
........... the current buffer was used or the previous, did
........... you got the idea? two buffers to search using only
........... 12 bits as the address and 4 for the string size
........... This will be version v8 of today noon
........... What is a waste of two bits if we are compressing
........... up to 18 characters on it?
........... Lets code...
...........
........... Understand, we have only 12 bits for the addressing,
........... but we can have lots of buffers to search these 12 bits
........... and yet we will store it in two bytes the pointer
...........
........... Understand, an additional bit will only be wasted
........... if a string was found
........... We will show a proof... the version v8 will do this
...........
........... (16:30)We did it!..., v8 compresses at least text better than lzss
........... And yet it can be improved a lot, more tests will follow...
...........
........... for file tar_1_33.c:
...........                         zip               : 59kb
...........                         lzss + ari        : 74kb
...........                         dl_compressor (v8): 73kb
...........
........... v8 is amazing, we did it again, it compress make.exe better

........... for file make.exe
...........                         zip               : 85kb
...........                         lzss + ari        : 90kb
...........                         dl_compressor (v8): 87kb
...........
........... v8 outperform lzss standard, v9 development will
........... start soon
...........
........... What we did: Added searching code for the previous
........... buffer that now are 4096 plus the current buffer
........... making 8192 and add plus one bit for each pointer
........... to the uncompressed buffer previous and current
........... v9 will extend it to (1 << 14) or more
...........

            */
// minha_struct.version_of_the_code = 6; // 7th version... initiated at 12 jan 2022 05:35:02
/*

we have an idea of trying to compress 3 bytes in two using the standard lzss method of handling 4096
bytes in the sliding window but in a lz77 method

depending on the file it will achieve more compression than our v6 method that was not perfect but
already can compress better than many compressors available in research papers

as you may examinate the v6 method can compress up to 4 bytes in 3,
this is the maximum for the minimum size
and up to 255 characters in a string for maximum size but we saw that this is irrelevant to the majority
of files, and standard lzss method encode at the maximum 18 characters string to 2 bytes and it is better than our v6 compressor

well here now with version v7 we will try to compress using 12 bits for adressing (4096 bytes) and four bits (16 possible values startinr from the minimum size that is 3 gives 18 as the maximum size)

this allow for a whole buffer like lz77 as 4096, lets see how it compresses...

coding time... (05:42:09)

to don't waste time we will keep for the moment the v6 variables in the code, even if not in use, blame us for this

happilly developed with VSCode: (but we may be forced to use Emacs for windows for some unknown reason)

begin ---

VSCode Version: 1.63.2
Commit: 899d46d82c4c95423fb7e10e68eba52050e30ba3
Date: 2021-12-15T09:40:02.816Z
Electron: 13.5.2
Chromium: 91.0.4472.164
Node.js: 14.16.0
V8: 9.1.269.39-electron.0
OS: Windows_NT x64 10.0.19042

end ---

...........
........... From my point of view v7 need to compress as good as lzss,
........... since the idea was based on it, the size and method are
........... almost the same but without a sliding window only the
........... real input buffer from where the string to match are
........... searched
...........

  begin of modification, will adjust the buffers (07:03)

........... We did it (08:59), v6 compresses make.bin to 111 kb and version
........... v7 compresses to 92 kb, the original lzss compresses to
........... 90 kb and zip compresses to 85 kb, the difference is that
........... our code that is compressing to 92 kb now have a lot
........... of room to improve
...........
........... By tomorrow we will have a compressor better than lzss
...........
........... Now that the code is ready compare the v7 code with 'LZSS.c'
........... available in the subfolder './lzss to learn' and see what
........... version is more easy to be understood
...........
........... Notice that our code is not exactly lzss, it don't search on
........... a sliding window but on the input data to compress, from 0 to
........... the last byte (4096), and it is already compressing as good
........... as original lzss...
...........
........... Just will add the arithmetic compression to the code to
........... avoid the requirement of the call to ari.exe after the call
........... It will help, and will be a simple call without ari.exe
...........
........... Just removed the overhead of the additional struct and
........... the size of the compressed file now is 91 kb
...........
........... And now the arithmetic compressor is already inside, no need
........... to call ari.exe after the compression
...........
........... In one hour we will start the development of the v8
........... Need to rest for a while (10:28)
........... end of v7 updates...

*/

// minha_struct.version_of_the_code = 5; // 6º version... initiated at 11 jan 2022 03:53:01

/*

     After reading a few papers we saw that we are trying to compress to much large strings that are not common
     As an example our version 5 from yeasterday will try to compress strings up to 512 characters on it
     while lzss will compress up to 18 characters on a string, and compressed better than our implementation
     Also we are wasting too much space at this moment, while lzss will expand only one bit for each not compressible character and more 1 bit for position and lenght stored in two bytes for a maximum of
     4096 bytes sliding window addressable using 12 bits, plus for to the lenght

     we will try to use these ideas in our compressor, for the moment the size of the data to compress is slices of (1 << 15) 32 kb then we need more than 12 bits to make a position on the passed data

     Michael Dipperstein from https://michaeldipperstein.github.io/lzss.html have very interesting papers and code and advanced documentation about lzss and we will borrow some ideas

     also we will try to compress strings up to 3 bytes of size or four, and not 10 as the v5 code and below, also, we will not waste time searching for strings larger than 20 characters on it, indeed it will be the limit for the moment

     after the strings replaces arithmetic compression will be applied to gather some bytes on the final size

     so lets code (04:04:01 day 11 jan)

     first we will start modifying the function convert_8_bits_to_nine_bits to encode using the smallest possible size for a maximum window of (1 << 15)

     also we will borrow the idea from Michael to use bit encode as whole bytes and just pass it later to the stream in a predefined struct as header, this idea we used in 2009 in our advanced rle compressor modified

     to increase compression we will use the smallest possible size to store data as we learned with lzss

     now allocating memory to the arrays of bits as bytes it will be up to 1 bit more for each byte to encode the size = size + (size * .2) will be enough, let we implement it

     also the arithmetic compression can work on the whole file and not in the 32 kb slice for better
     compression, but we will take care of this later, first we need to create an advanced strings search and replace mode

     lets code...

     during debug for the moment we will use the external arithmetic compressor, no need to use it internally now, only later

     well, bit handling rountine was added, now what we will do is adapt a ls77 and lz77 together
     to see if it work, we will not use a sliding window but the current buffer so far to store
     the data encoded in the compressed stream with a sequence of encoded bytes that require plus one bit in the bit stream or a sequence of pointer to the passed data with position and size limited to a window of 32 kb perfectly

     lets code, first we need to generate the adjusts for the size of data to store in case of a pointer in the passed data

     lets go...



*/

// minha_struct.version_of_the_code = 4; // 5º version... initiated at 10 jan 2022 15:54:01

/*

Version 4 was now fast but yet dont compress very well on not very compressible files, version 5 will enable
arithmetic compression to see whether is more easy to make comparisons

the zlib do huffman compression not only string search, interesting would be to see how it adjusts
strings and how to compare it without additional compression, maybe disabling huffman in the compression in
zlib

more code...

*/
// minha_struct.version_of_the_code = 3; // 4º version... initiated at 10 jan 2022 10:05:00

/* 4º version information, we will change the double linkd
list compression method that failed with a method that will
try to locate the maximum size of the current string in
the previous buffer, if found it will mark the size and position
in the passed string, now it 10:07 hs, hope to have it working
before 14:00 hs

for this we will not use a linked list but preallocated memory for the required size that is slightly larger than the input uncompressed string, and will just be adding data to it in the processed form

more code... (10:12), description of changes will follow

added the resulting memory with the compressed data, in the function convert_8_bits_to_nine_bits the
hard work will be done..., variable buf_dl_compressed holds the compressed stream, first we will focus on the compression, it need to compress, fast and well, then later we write the uncompressor

for the moment we will just not use the arithmetic compression, because what we need is to achieve
compression with the strings replacement, later we use it
when working dl_compressor will be part of the Parolin project, the extension will be .dl

more code...

we will just go modifying code from version 3 to match version 4 requirements

*/

// minha_struct.version_of_the_code = 2; // 3º version... initiated at 10 jan 2022 02:00:00
