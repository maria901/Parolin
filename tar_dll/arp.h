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
 *     E-mails:                                                                 *
 *     maria@arsoftware.net.br                                                  *
 *     pedro@locacaodiaria.com.br                                               *
 *                                                                              *
 *     contato imediato(para uma resposta muito rápida) WhatsApp                *
 *     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                 *      
 *                                                                              *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  **/


#include <windows.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <math.h>
#include <wctype.h>
#include <wchar.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <locale.h>
#include <signal.h>
#include <limits.h>
#include <float.h>
#include <iso646.h>

#undef NDEBUG
#include <assert.h>

#include <stdbool.h>
/**
 * All the possible compressors modes
 *
 *
 */
enum progress_decompression_modes_KP
{
	AAKP_MODE_GZIP,		 /**< standard gzip  method, limited to 2GB */
	AAKP_MODE_BZ2,		 /**< standard bzip2 method */
	AAKP_MODE_LZIP,		 /**< lzip method */
	AAKP_MODE_LZMA,		 /**< standard lzma  method */
	AAKP_MODE_XZ,		 /**< XZ method */
	AAKP_MODE_COMPRESS,	 /**< old standard Unix compress method */
	AAKP_MODE_LZOP,		 /**< lzop method */
	AAKP_MODE_LZ4,		 /**< lz4 method */
	AAKP_MODE_ZSTANDARD, /**< Zstandard method */
	AAKP_MODE_BROTLI,	 /**< brotli method */
	AAKP_MODE_GZIP2,	 /**< gzip2       method, gzip with steroids     */
	AAKP_MODE_BZIP3,	 /**< bzip3       method, bzip2 with steroids    */
	AAKP_MODE_LZOP2,	 /**< lzop2       method, lzop with steroids     */
	AAKP_MODE_LZ5,		 /**< lz5         method, lz4  with steroids     */
	AAKP_MODE_BROTLI2,	 /**< brotli2     method, brotli with steroids   */
	AAKP_MODE_COMPRESS2, /**< compress2   method, compress with steroids */
};

enum libarchive_compression_modes_AR
{
	P_MODE_IS_ZIP__NO_PASSWORD,
	P_MODE_IS_ZIP__ZIPCRYPTO,
	P_MODE_IS_ZIP__AES_128,
	P_MODE_IS_ZIP__AES_256,
	P_MODE_IS_7ZIP,
	P_MODE_IS_ISO9660,
	P_MODE_IS_TAR,
	P_MODE_IS_GNUTAR,
	P_MODE_IS_V7TAR,
	P_MODE_IS_TAR_GZIP,
	P_MODE_IS_TAR_BZIP2,
	P_MODE_IS_TAR_XZ,
	P_MODE_IS_GNUTAR_GZIP,
	P_MODE_IS_GNUTAR_BZIP2,
	P_MODE_IS_GNUTAR_XZ,
	P_MODE_IS_V7TAR_GZIP,
	P_MODE_IS_V7TAR_BZIP2,
	P_MODE_IS_V7TAR_XZ,
	P_MODE_IS_7ZIP_ENCRYPTED,
	P_MODE_IS_7ZIP_ENCRYPTED_ALSO_HEADERS,
	P_MODE_IS_RAR,
	P_MODE_IS_RAR5
};

enum compression_modes_AR
{
	AAKP_MODE_TAR,
	AAKP_MODE_TAR_GZIP,
	AAKP_MODE_TAR_BZ2,
	AAKP_MODE_TAR_LZIP,
	AAKP_MODE_TAR_LZMA,
	AAKP_MODE_TAR_XZ,
	AAKP_MODE_TAR_COMPRESS,
	AAKP_MODE_TAR_LZOP,
	AAKP_MODE_TAR_LZ4,
	AAKP_MODE_TAR_ZSTANDARD,
	AAKP_MODE_TAR_BROTLI,
	AAKP_MODE_VAL, /**< Our own homemade Tar replacement with support to file timestamp and file attributes in windows, it is called the VAL format */
	AAKP_MODE_VAL_GZIP,
	AAKP_MODE_VAL_BZ2,
	AAKP_MODE_VAL_LZIP,
	AAKP_MODE_VAL_LZMA,
	AAKP_MODE_VAL_XZ,
	AAKP_MODE_VAL_COMPRESS,
	AAKP_MODE_VAL_LZOP,
	AAKP_MODE_VAL_LZ4,
	AAKP_MODE_VAL_ZSTANDARD,
	AAKP_MODE_VAL_BROTLI,
	AAKP_MODE_ISO,
	AAKP_MODE_TAR_GZIP2,
	AAKP_MODE_VAL_GZIP2,
	AAKP_MODE_TAR_BZIP3,
	AAKP_MODE_VAL_BZIP3,
	AAKP_MODE_TAR_LZOP2,
	AAKP_MODE_VAL_LZOP2,
	AAKP_MODE_TAR_LZ5,
	AAKP_MODE_VAL_LZ5,
	AAKP_MODE_TAR_BROTLI2,
	AAKP_MODE_VAL_BROTLI2,
	AAKP_MODE_TAR_COMPRESS2,
	AAKP_MODE_VAL_COMPRESS2
};

#ifndef AMANDA__SIZE
#define AMANDA__SIZE ((32767 * 6) + 2)
#endif

typedef struct arp_
{
	__time64_t VAL_timestamp64;
	bool Val_is_using_filetime;
	char VAL_filename[AMANDA__SIZE];
	char VAL_filename_v27_v51[AMANDA__SIZE];
	DWORD VAL_attributes;
	FILETIME CreationTime___junior;
	FILETIME LastAccessTime_junior;
	FILETIME LastWriteTime__junior;
	int VAL_encryption_method;
	int VAL_is_dir;
	int VAL_is_encrypted;
	int64_t VAL_file_position;
	int64_t VAL_file_size;
	time_t VAL_timestamp;
} VAL_data;

int decode_VAL_arp(VAL_data *my_VAL_data);

enum VAL_decode_status
{
	ARP_DECODED,
	ARP_NOMORE,
};

enum iso_mode_arp
{
	ARP_MODE_ISO9660,
	ARP_MODE_JOLIET,
	ARP_MODE_ROCK_RIDGE,
	ARP_MODE_JOLIET_PLUS_ROCK_RIDGE,
	ARP_MODE_UDF
};

enum encryption_mode_arp
{
	ARP_AES, /**< The Advanced Encryption Standard (AES), also known by its original name Rijndael is a specification for the encryption of electronic data established by the U.S. National Institute of Standards and Technology (NIST) in 2001.*/

	ARP_RC4, /**< In cryptography, RC4 (Rivest Cipher 4 also known as ARC4 or ARCFOUR meaning Alleged RC4) is a stream cipher. While it is remarkable for its simplicity and speed in software, multiple vulnerabilities have been discovered in RC4, rendering it insecure. */

	ARP_SERPENT, /**< Serpent is a symmetric key block cipher that was a finalist in the Advanced Encryption Standard (AES) contest, where it was ranked second to Rijndael. Serpent was designed by Ross Anderson, Eli Biham, and Lars Knudsen. */

	ARP_MARS, /**< MARS is a block cipher that was IBM's submission to the Advanced Encryption Standard process. MARS was selected as an AES finalist in August 1999, after the AES2 conference in March 1999, where it was voted as the fifth and last finalist algorithm. */

	ARP_RC6, /**< In cryptography, RC6 (Rivest cipher 6) is a symmetric key block cipher derived from RC5. It was designed by Ron Rivest, Matt Robshaw, Ray Sidney, and Yiqun Lisa Yin to meet the requirements of the Advanced Encryption Standard (AES) competition. The algorithm was one of the five finalists, and also was submitted to the NESSIE and CRYPTREC projects. It was a proprietary algorithm, patented by RSA Security. */

	ARP_TWOFISH, /**< In cryptography, Twofish is a symmetric key block cipher with a block size of 128 bits and key sizes up to 256 bits. It was one of the five finalists of the Advanced Encryption Standard contest, but it was not selected for standardization. Twofish is related to the earlier block cipher Blowfish. */
	
	ARP_AES_MT, /**< The Advanced Encryption Standard (AES), also known by its original name Rijndael is a specification for the encryption of electronic data established by the U.S. National Institute of Standards and Technology (NIST) in 2001.*/

	ARP_RC4_MT, /**< In cryptography, RC4 (Rivest Cipher 4 also known as ARC4 or ARCFOUR meaning Alleged RC4) is a stream cipher. While it is remarkable for its simplicity and speed in software, multiple vulnerabilities have been discovered in RC4, rendering it insecure. */

	ARP_SERPENT_MT, /**< Serpent is a symmetric key block cipher that was a finalist in the Advanced Encryption Standard (AES) contest, where it was ranked second to Rijndael. Serpent was designed by Ross Anderson, Eli Biham, and Lars Knudsen. */

	ARP_MARS_MT, /**< MARS is a block cipher that was IBM's submission to the Advanced Encryption Standard process. MARS was selected as an AES finalist in August 1999, after the AES2 conference in March 1999, where it was voted as the fifth and last finalist algorithm. */

	ARP_RC6_MT, /**< In cryptography, RC6 (Rivest cipher 6) is a symmetric key block cipher derived from RC5. It was designed by Ron Rivest, Matt Robshaw, Ray Sidney, and Yiqun Lisa Yin to meet the requirements of the Advanced Encryption Standard (AES) competition. The algorithm was one of the five finalists, and also was submitted to the NESSIE and CRYPTREC projects. It was a proprietary algorithm, patented by RSA Security. */

	ARP_TWOFISH_MT, /**< In cryptography, Twofish is a symmetric key block cipher with a block size of 128 bits and key sizes up to 256 bits. It was one of the five finalists of the Advanced Encryption Standard contest, but it was not selected for standardization. Twofish is related to the earlier block cipher Blowfish. */
};

enum z_encryption_method
{
	Z_OLD_MODE, /**< If this method is selected the compressor will encrypt the data before the compression what will result in a uncompressible file, not recommended, only here for people that have already encrypted files this way */
	Z_NEW_MODE, /**< If this method is selected the compressor will only encrypt the data after the compression, this means that the output size will be just slightly higher than the original compressed data, this is the recommended mode */
};

/*
#ifdef _M_X64
#define Print_Long_ARP "ll"
#else
#define Print_Long_ARP "I64"
#endif
*/

enum amanda__mode
{
	I_MODE_IS_SCANFOLDER = 1001,
	I_MODE_IS_ENUMFOLDER_1,
};
