//2021 MathMan and amanda
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

#include <process.h>

#include "win64.h"

#include "include_multi_k__p.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#ifndef ushort
#define ushort unsigned short
#endif

extern int64_t *bytes_read_arp;

extern int64_t bytes_read_z;

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

/**
 * The maximum size of an utf-8 encoded filename with the max limit of a file in Windows
 */
#define AMANDA__SIZE ((32767 * 6) + 2)
/**
 * The maximum size of Unicode characters in a path in Windows, Linux is 1024 characters as far I know 
 * 
 */
#define AMANDA__SIZE_w (32767)

#define AMANDA__SIZE_ww ((32767 * 2) + 2)

static int *cores___S2_ = NULL;

static int64_t ret_arp_ = 0;
int SHA512_filelong_m_opened_file_v27(FILE *the_input_file_arthur, int64_t offset_m, int64_t file_size_erika, unsigned char *sha512_digest_k);
int __fastcall get_size_of_struct_twofish_m(void);
int __stdcall encryptstring_twofish_arp_maria_v27(uchar *buf, uchar *bufout, char *key_arp, uint size, char *variaveis_m);
int __stdcall init_twofish_arp_maria_v27(char *key_arp_, char *variaveis_m);
int __stdcall init_rc6__arp_v27(char *key_arp_, char *minha_struct_maria__);
int __stdcall encryptstring_rc6_arp_v27(uchar *buf, uchar *bufout, char *key_arp, uint size, char *minha_struct_maria_in);
int get_size_minha_struct_m(void);
int get_sha512(char *data_arp, char *out_arp);
uint crc32(uint crc, const uchar *buf, uint len);
int __stdcall encryptstring2(int *done, uchar *buf, uchar *key, uchar *bufout, uint size, uint keysize);
int createtempfilename_and_keep_z(char *path1, char *out_z, WCHAR *signature_z);
int aesencrypt(unsigned char *buf, unsigned char *bufout, unsigned char *key, int keysize, int *done);

/**
 * sha512_digest_k need to be at least 65 bytes long
 *
 */
int SHA512_filelong_k(unsigned char *inputfile_utf_8, unsigned char *sha512_digest_k);
int SHA512_filelong_m_opened_file(FILE *the_input_file_arthur, int64_t file_size_erika, unsigned char *sha512_digest_k);

/**
 * It will replace character '/' with '\\' on the given path, very useful
 * to programmers converting code from Unix to Windows... not using cygwin
 *
 * @param path the path to replace the character
 *
 * @return void
 *
 */
static void trocadordebackslashtras(char *path)
{
     int ret;
     char aqui;
     int i;

     ret = strlen(path);

     if (ret)
     {
          for (i = 0; i < ret; i++)
          {
               aqui = path[i];
               if (aqui == '/')
               {
                    path[i] = '\\';
               }
          }
     }
}

/**
 * My fixed strncpy
 *
 *
 */
void strncpy_z(char *dest_z, char *src_z, size_t len_)
{

     int len = (int)len_;

     assert(0 <= (int)len);

     len--;

     if (0 > len)
     {
          len = 0;
     }

     if (strlen(src_z) < (size_t)len)
     {
          strcpy(dest_z, src_z);
     }
     else
     {
          memcpy(dest_z, src_z, len);
          dest_z[len] = 0;
     }
     return;
}

extern int unicodemode;

static char temp_folder_z[AMANDA__SIZE] = {
    0,
};

/**
 * To convert an input wide string to a utf-8 encoded filename on return
 *
 * @param pUSC2_maria the wide string to be converted
 *
 * @return it will return the static allocated char * string with the utf-8 encoded filename
 *
 */
static char *valquiria_wide_to_utf8(WCHAR *pUSC2_maria, char *ar_temp_char)
{
     char *saida_utf8 = ar_temp_char;

     WideCharToMultiByte(CP_UTF8, 0, pUSC2_maria, -1, (LPSTR)saida_utf8, AMANDA__SIZE, 0, 0);
     return saida_utf8;
}

uint32_t
tuklib_cpucores_z(void);

__int64 lffilesize(const char *szFileName);
int __fastcall set_temp_folder_z(char *folder_z);
void pedro_dprintf(int amanda_level,
                   char *format, ...);

#define CHUNK_k__p (1 << 17) /* to never change... */

unsigned int pauseflag;
unsigned int cancelflag;

int64_t totalbytes_z;
int64_t bytes__read_thread_z[129];
int64_t offset_z__[129];
int64_t size_of_input_file_z__[129];
__INT32_OR_INT64 my_thread_handle[129];
char temp_files_z[129][2048];
int thread_return_value_z;
int n_threads_z = 1;

/**
 * To make the path wide mode aware, stolen from libarchive
 * 
 * 15/september/2021 10:14, last visit 16/09/2021 22:36 by bhond...
 *
 */
static wchar_t *
permissive_name_m_(const wchar_t *wname, wchar_t *mem_amanda)
{

     wchar_t *wnp = NULL;
     wchar_t *wn;
     wchar_t *ws, *wsp;
     DWORD len, slen;
     int unc;

     wnp = (void *)mem_amanda;

     //wnp = malloc(AMANDA__SIZE * 2);

     wcscpy(wnp, wname);

     len = wcslen(wname);

     wn = wnp;

     if (wnp[0] == L'\\' && wnp[1] == L'\\' && // access to the wrong position in memory, fixed now
         wnp[2] == L'?' && wnp[3] == L'\\')
          /* We have already a permissive name. */
          return (wn);

     if (wnp[0] == L'\\' && wnp[1] == L'\\' &&
         wnp[2] == L'.' && wnp[3] == L'\\')
     {
          /* This is a device name */
          if (((wnp[4] >= L'a' && wnp[4] <= L'z') ||
               (wnp[4] >= L'A' && wnp[4] <= L'Z')) &&
              wnp[5] == L':' && wnp[6] == L'\\')
               wnp[2] = L'?'; /* Not device name. */
          return (wn);
     }

     unc = 0;
     if (wnp[0] == L'\\' && wnp[1] == L'\\' && wnp[2] != L'\\')
     {
          wchar_t *p = &wnp[2];

          /* Skip server-name letters. */
          while (*p != L'\\' && *p != L'\0')
               ++p;
          if (*p == L'\\')
          {
               wchar_t *rp = ++p;
               /* Skip share-name letters. */
               while (*p != L'\\' && *p != L'\0')
                    ++p;
               if (*p == L'\\' && p != rp)
               {
                    /* Now, match patterns such as
				 * "\\server-name\share-name\" */
                    wnp += 2;
                    len -= 2;
                    unc = 1;
               }
          }
     }

     slen = 4 + (unc * 4) + len + 1;
     ws = wsp = malloc(slen * sizeof(wchar_t));
     if (ws == NULL)
     {
          //free(wn);
          return (NULL);
     }
     /* prepend "\\?\" */
     wcsncpy(wsp, L"\\\\?\\", 4);
     wsp += 4;
     slen -= 4;
     if (unc)
     {
          /* append "UNC\" ---> "\\?\UNC\" */
          wcsncpy(wsp, L"UNC\\", 4);
          wsp += 4;
          slen -= 4;
     }
     wcsncpy(wsp, wnp, slen);
     wsp[slen - 1] = L'\0'; /* Ensure null termination. */
     //free(wn);

     wcscpy(wnp, ws);

     free(ws);

     return (wnp);
}

wchar_t *
remove_permissive_name_m_(wchar_t *wname, WCHAR *ar_mem);

wchar_t *
remove_permissive_name_m_(wchar_t *wname, WCHAR *ar_mem)
{

     /**
 * oi amor...
 */
     wchar_t *wname_copy = ar_mem;

     wchar_t *wname_copy_v27 = ar_mem;

     wcscpy(wname_copy, wname);

     if (3 < wcslen(wname_copy))
     {

          if ('\\' == wname_copy[0] &&
              '\\' == wname_copy[1] &&
              '?' == wname_copy[2])
          {
               wname_copy_v27++;
               wname_copy_v27++;
               wname_copy_v27++;
               wname_copy_v27++;
               return wname_copy_v27;
          }
          else
          {
               return wname;
          }
     }
     else
     {
          return wname;
     }
}

/**
 * To convert an utf-8 encoded filename to a wide string (WCHAR *), we 
 *  . provide two functions that are exactly the same because someone may 
 * use it in multi-thread code 
 *
 * @param pUTF8 the input utf-8 encoded filename 
 *
 * @return the static allocated WCHAR array with the filename as wide string 
 *
 */
static WCHAR *amanda_utf8towide_1_(char *pUTF8, WCHAR *ar_mem)
{
     WCHAR *ricardo_k = ar_mem;

     MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)pUTF8, -1, ricardo_k, AMANDA__SIZE_w);
     return ricardo_k;
}

/**
 * It will test the utf-8 encoded path to see if it do exist and is a file
 *
 * @param path utf-8 encoded path to test
 *
 * @return 0 if the path is not a file or valid, 1 if it is a readable
 * file
 *
 */
static int ispathfile(char *path)
{
     static char x[AMANDA__SIZE];
     int ret;

     strcpy(x, path);
     ret = strlen(x);

     if (!ret)
     {
          return 0;
     }

     {
          WCHAR *temp_ar = (void *)malloc(AMANDA__SIZE_ww);
          WCHAR *temp_ar2 = (void *)malloc(AMANDA__SIZE_ww);
          ret = GetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(x, temp_ar2), temp_ar));
          free(temp_ar);
          free(temp_ar2);
     }

     if ((int)0xffffffff != (int)ret)
     {
          if (ret & (0x00000010))
          {
               return 0;
          }
          else
          {
               return 1;
          }
     }
     else
     {
          return 0;
     }
}

static char *
ar_gettemppath_z(void)
{
#ifdef Z_DEBUG__TEMP
     pedro_dprintf(2, "Usando Z_DEBUG__TEMP -> C:\\Ava\\back\\temp\n");

     if (0 == strlen(temp_folder_z))
     {
          set_temp_folder_z("C:\\Ava\\back\\temp");
     }
#endif

     if (ispathfile("c:\\Ava\\back\\my_c_file.c"))
     {
          static int counter = 0;
          counter++;
          if (25 == counter)
          {
               pedro_dprintf(2, "using internal temp folder for debug \n");
               counter = 0;
          }
          if (0 == strlen(temp_folder_z))
          {
               set_temp_folder_z("C:\\Ava\\back\\temp");
          }
     }

     if (0 == strlen(temp_folder_z))
     {
          char *ar_temp_char = (void *)malloc(AMANDA__SIZE);
          WCHAR *out_z = malloc(AMANDA__SIZE_w + 1);
          GetTempPathW(AMANDA__SIZE_w, out_z);
          strcpy(temp_folder_z, valquiria_wide_to_utf8(out_z, ar_temp_char));
          free(ar_temp_char);
          free(out_z);
     }

     return temp_folder_z;
}

/**
 * To set the temp folder, if the path is invalid it will return an error
 *
 * @param folder_z the new temp folder
 *
 * @return 0 if no error, or the error value (in this case 1)
 *
 */
int __fastcall set_temp_folder_z(char *folder_z)
{
     char *copy_path = malloc(AMANDA__SIZE);
     char *copy_path2 = malloc(AMANDA__SIZE);
     strncpy_z(copy_path, folder_z, AMANDA__SIZE);

     if ('\\' == copy_path[0] && '\\' == copy_path[1])
     {
          goto ok_z;
     }
     if ('a' <= tolower(copy_path[0]) && 'z' >= tolower(copy_path[0]))
     {
          if (':' == copy_path[1] && ('\\' == copy_path[2] || '/' == copy_path[2]))
               goto ok_z;
     }
     free(copy_path);
     free(copy_path2);
     return 1;

ok_z:;

     trocadordebackslashtras(copy_path);

     ret_arp_ = strlen(copy_path);

     if ('\\' != copy_path[ret_arp_ - 1])
     {
          strcat(copy_path, "\\");
     }

     if (createtempfilename_and_keep_z(copy_path, copy_path2, L"oi_"))
     {
          {
               WCHAR *temp_ar = (void *)malloc(AMANDA__SIZE_ww);
               WCHAR *temp_ar2 = (void *)malloc(AMANDA__SIZE_ww);
               _wunlink(permissive_name_m_(amanda_utf8towide_1_(copy_path2, temp_ar), temp_ar2));
               free(temp_ar);
               free(temp_ar2);
          }
          strncpy_z(temp_folder_z, copy_path, sizeof(temp_folder_z) - 1);

          free(copy_path);
          free(copy_path2);
          return 0;
     }

     free(copy_path);
     free(copy_path2);
     return 1;
}

#include "the_thread_function_p.c"

int rspencrypt_encrypt_multi_thread_k__p(char *input,
                                         char *output,
                                         char *key_k__p,
                                         int encryption_method_internal_arp,
                                         int threads_to_use_k__p)
{
     int i_z;
     FILE *dest = NULL;
     FILE *temp_z = NULL;
     __int64 totalbytes = 0;
     unsigned int fatia_m = 0;
     int ret_z = 0;
     int ret2 = 0;
     static char buffer[CHUNK_k__p /* + 1 why?...*/];
     int n_threads_copy;
     int n_thread_counter;
     int first_step_z = 0;
     int64_t slice_z;
     int64_t remaining_z;
     int64_t offset_z;
     (void)key_k__p;
     thread_return_value_z = 0;
     my_thread_struct_z *ptr_my_struct_z;
     pauseflag = 0;
     cancelflag = 0;
     unicodemode = 1;
     n_threads_z = threads_to_use_k__p;

     bytes_read_z = 0;

     {

          pedro_dprintf(0, "new encryption threads used %d\n", n_threads_z);

          totalbytes = lffilesize(input);

          totalbytes_z = totalbytes;

          if (1000 > totalbytes)
          {
               n_threads_z = 1;
          }

          if (true)
          {
               //aqui...
               if (0 == n_threads_z)
               {
                    n_threads_z = tuklib_cpucores_z();

                    if (0 == n_threads_z)
                    {
                         n_threads_z = 1;
                    }
               }

               if (128 < n_threads_z)
               {
                    n_threads_z = 128; //correcting it for maximum threads...
               }

               for (i_z = 0; i_z < n_threads_z; i_z++)
               {
                    bytes__read_thread_z[i_z] = 0;
               }

               n_threads_copy = n_threads_z;
               n_thread_counter = 0;
               while (n_threads_copy--)
               {
                    ptr_my_struct_z = calloc(1, sizeof(my_thread_struct_z));
                    assert(ptr_my_struct_z);
                    pedro_dprintf(-1, "alocou\n");

                    ptr_my_struct_z->thread_id_z = n_thread_counter;

                    if (unicodemode)
                    {
                         WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                         WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);

                         ptr_my_struct_z->input_file = _wfopen(permissive_name_m_(amanda_utf8towide_1_(input, ar_temp), ar_temp2), L"rb");

                         free(ar_temp);
                         free(ar_temp2);
                    }
                    else
                         ptr_my_struct_z->input_file = fopen(input, "rb");

                    if (NULL == ptr_my_struct_z->input_file)
                    {
                         if (0 == thread_return_value_z)
                         {
                              thread_return_value_z = 7; //cannot open input file
                         }
                    }

                    ptr_my_struct_z->dest = NULL;
                    if (!createtempfilename_and_keep_z(ar_gettemppath_z(), temp_files_z[n_thread_counter], L"GZ2"))
                    {
                         if (0 == thread_return_value_z)
                         {
                              thread_return_value_z = 401; //cannot create temp file
                         }
                    }
                    else
                    {
                         if (unicodemode)
                         {

                              WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                              WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
                              ptr_my_struct_z->dest = _wfopen(permissive_name_m_(amanda_utf8towide_1_(temp_files_z[n_thread_counter], ar_temp), ar_temp2), L"wb");
                              free(ar_temp);
                              free(ar_temp2);
                         }

                         if (NULL == ptr_my_struct_z->dest)
                         {
                              if (0 == thread_return_value_z)
                              {
                                   thread_return_value_z = 8; //cannot open output file
                              }
                         }
                    }

                    if (0 == first_step_z)
                    {
                         pedro_dprintf(-1, "tamanho %lld\n", totalbytes);
                         slice_z = totalbytes / n_threads_z;
                         remaining_z = totalbytes;
                         offset_z = 0;

                         pedro_dprintf(-1, "!!!!! n_threads_z %d", n_threads_z);

                         for (i_z = 0; i_z < n_threads_z; i_z++)
                         {
                              if (i_z == (n_threads_z - 1))
                              {
                                   offset_z__[i_z] = offset_z;
                                   size_of_input_file_z__[i_z] = remaining_z;
                              }
                              else
                              {
                                   offset_z__[i_z] = offset_z;
                                   size_of_input_file_z__[i_z] = slice_z;
                                   offset_z += slice_z;
                                   remaining_z -= slice_z;
                              }
                         }
                         first_step_z = 1;
                    }

                    ptr_my_struct_z->offset_z = offset_z__[n_thread_counter];
                    ptr_my_struct_z->size_of_input_file_z = size_of_input_file_z__[n_thread_counter];

                    //init...

                    ptr_my_struct_z->buffer = calloc(1, CHUNK_k__p + 1);
                    assert(ptr_my_struct_z->buffer);
                    ptr_my_struct_z->out = calloc(1, CHUNK_k__p);
                    assert(ptr_my_struct_z->out);

                    memset(&ptr_my_struct_z->ar, 0, sizeof(ar_data));
                    strncpy_z(ptr_my_struct_z->key_k__p, key_k__p, 299);

                    ptr_my_struct_z->init_aes = 1;
                    ptr_my_struct_z->done2 = 0;

                    {

                         switch (encryption_method_internal_arp)
                         {

                         case ARP_AES_MT:
                              fatia_m = 0x706c6176 - 6; //proximo da lista
                              memcpy(ptr_my_struct_z->ar.string, &fatia_m, 4);
                              break;
                         case ARP_RC4_MT:
                              fatia_m = 0x706c6176 - 7; //proximo da lista
                              memcpy(ptr_my_struct_z->ar.string, &fatia_m, 4);
                              break;
                         case ARP_SERPENT_MT:
                              fatia_m = 0x706c6176 - 8; //proximo da lista
                              memcpy(ptr_my_struct_z->ar.string, &fatia_m, 4);
                              break;
                         case ARP_MARS_MT:
                              fatia_m = 0x706c6176 - 9; //proximo da lista
                              memcpy(ptr_my_struct_z->ar.string, &fatia_m, 4);
                              break;
                         case ARP_RC6_MT:
                              fatia_m = 0x706c6176 - 10; //proximo da lista
                              memcpy(ptr_my_struct_z->ar.string, &fatia_m, 4);
                              break;
                         case ARP_TWOFISH_MT:
                              fatia_m = 0x706c6176 - 11; //proximo da lista
                              memcpy(ptr_my_struct_z->ar.string, &fatia_m, 4);
                              break;
                         default:
                              pedro_dprintf(1001, "Wrong encryption method");
                              assert(0 && "Wrong encryption method");
                              exit(27);
                              break;
                         }

                         ptr_my_struct_z->encryption_method_internal_arp = encryption_method_internal_arp;

                         /*

                         memcpy(ptr_my_struct_z->ar.string, "AR__", 4); //aqui 2

                         ptr_my_struct_z->ar.string[3] = '_' - 1; //signature for gzip2 multi-thread

                         */
                    }

                    if (unicodemode)
                    {
                         WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                         WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
                         ptr_my_struct_z->ar.attrib = GetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(input, ar_temp), ar_temp2));
                         free(ar_temp);
                         free(ar_temp2);
                    }
                    else
                         ptr_my_struct_z->ar.attrib = GetFileAttributes(input);

                    if ((int)0xFFFFFFFF == (int)ptr_my_struct_z->ar.attrib)
                    {
                         ptr_my_struct_z->ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
                    }

                    bytes__read_thread_z[n_thread_counter] = 0;

                    my_thread_handle[n_thread_counter] = (__INT32_OR_INT64)_beginthreadex(NULL, 0, my_thread_function, ptr_my_struct_z, 0, NULL);

                    n_thread_counter++;
               }

               for (i_z = 0; i_z < n_threads_z; i_z++)
               {
                    WaitForSingleObject((void *)my_thread_handle[i_z], INFINITE);
                    CloseHandle((void *)my_thread_handle[i_z]);
               }
               /*
			   //to finished the code
			   if(unicodemode)
			   {
			        WCHAR wpmode[300] ={0,};
			        utf8towide (input, wpmode, 300);
			        ar.attrib = GetFileAttributesW (wpmode);
			   }
			   else
			        ar.attrib = GetFileAttributes (input);

			   if (0xFFFFFFFF == ar.attrib)
			   {
			        ar.attrib = FILE_ATTRIBUTE_ARCHIVE;
			   }
			 */
               {

                    WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                    WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
                    ret_z = SetFileAttributesW(permissive_name_m_(amanda_utf8towide_1_(output, ar_temp), ar_temp2), FILE_ATTRIBUTE_ARCHIVE);
                    free(ar_temp);
                    free(ar_temp2);
               }
               //abrir arquivo

               if (unicodemode)
               {

                    WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                    WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
                    dest = _wfopen(permissive_name_m_(amanda_utf8towide_1_(output, ar_temp), ar_temp2), L"wb");
                    free(ar_temp),
                        free(ar_temp2);
               }
               else
                    dest = fopen(output, "wb");

               if (NULL == dest)
               {
                    if (0 == thread_return_value_z)
                    {
                         thread_return_value_z = 80; //Cannot open output file
                    }
               }

               //depois de finalizar
               for (i_z = 0; i_z < n_threads_z; i_z++)
               {
                    pedro_dprintf(-1, "arquivo temp a del %s\n", temp_files_z[i_z]);
                    if (dest)
                    {

                         if (unicodemode)
                         {

                              WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                              WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
                              temp_z = _wfopen(permissive_name_m_(amanda_utf8towide_1_(temp_files_z[i_z], ar_temp), ar_temp2), L"rb");
                              free(ar_temp);
                              free(ar_temp2);
                         }
                         if (temp_z)
                         {
                              //Mr. Do

                         volta_amanda:;
                              if (97001 == thread_return_value_z)
                              {
                                   ret_z = 0;
                              }
                              else
                                   ret_z = fread(buffer, 1, CHUNK_k__p, temp_z);

                              if (0 > ret_z) //Never will occur...but I will keep it here for historical reasons...
                              {
                                   if (0 == thread_return_value_z)
                                   {
                                        thread_return_value_z = 402; //Cannot read from input file
                                   }
                              }
                              else if (0 == ret_z)
                              {
                                   ; //just go by...
                              }
                              else
                              {

                                   ret2 = fwrite(buffer, 1, ret_z, dest);

                                   if (ret2 != ret_z)
                                   {
                                        if (0 == thread_return_value_z)
                                        {
                                             thread_return_value_z = 14; //Cannot write to output file
                                        }
                                        goto exit_loop_z;
                                   }

                                   goto volta_amanda;
                              }

                         exit_loop_z:;

                              fclose(temp_z);
                         }
                         else
                         {
                              if (0 == thread_return_value_z)
                              {
                                   thread_return_value_z = 404; //Cannot open temp file
                              }
                         }
                    }
                    {
                         WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                         _wunlink(amanda_utf8towide_1_(temp_files_z[i_z], ar_temp));
                         free(ar_temp);
                    }
               }

               if (dest)
               {
                    fclose(dest), dest = NULL;
               }

               pedro_dprintf(0, "vejamos %d\n", thread_return_value_z);

               return thread_return_value_z;
          }
     }
}

uint32_t
tuklib_cpucores_z(void)
{
     uint32_t ret = 0;
     SYSTEM_INFO sysinfo;
     GetSystemInfo(&sysinfo);
     ret = sysinfo.dwNumberOfProcessors;
     return ret;
}

/**
 * It will just create a windows based temp file using the 
 *  signature_z information
 *
 * @param path1 the path where it will create
 *
 * @param out_z the utf-8 encoded temp file
 *
 * @param signature_z the 3 characters to be used as the initial data
 *  on the destination temp file
 *
 * @return 0 on error, 1 otherwise
 *
 */
int createtempfilename_and_keep_z(char *path1, char *out_z, WCHAR *signature_z)
{
     int ret;
     char *path = malloc(AMANDA__SIZE);
     strcpy(path, path1);
     ret = strlen(path);

     if (path[ret - 1] != '\\')
     {
          path[ret] = '\\';
          path[ret + 1] = 0;
     }
     {
          WCHAR *fixo_w_ar = (void *)malloc((AMANDA__SIZE_w * 2) + 2);
          WCHAR *path_w_ar = (void *)malloc((AMANDA__SIZE_w * 2) + 2);
          {
               WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
               wcscpy(path_w_ar, amanda_utf8towide_1_(path, ar_temp));
               free(ar_temp);
          }
          {
               WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
               ret = GetTempFileNameW(permissive_name_m_(path_w_ar, ar_temp), signature_z, 0, fixo_w_ar);
               free(ar_temp);
          }
          if (ret == 0)
          {
               free(fixo_w_ar);
               free(path_w_ar);
               free(path);
               return 0;
          }
          else
          {
               {

                    WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
                    char *ar_temp_char = (void *)malloc(AMANDA__SIZE);
                    strcpy(out_z,
                           valquiria_wide_to_utf8(remove_permissive_name_m_(fixo_w_ar, ar_temp), ar_temp_char));
                    free(ar_temp);
                    free(ar_temp_char);
               }
               free(fixo_w_ar);
               free(path_w_ar);
               free(path);
               return 1;
          }
     }
}

bool is_encrypted_multi_thread_m(char *filename_v)
{
     int len_arp;
     int ret_arp_ = 0;
     FILE *amanda_file;

     {

          WCHAR *ar_temp = (void *)malloc(AMANDA__SIZE_ww);
          WCHAR *ar_temp2 = (void *)malloc(AMANDA__SIZE_ww);
          amanda_file = _wfopen(permissive_name_m_(amanda_utf8towide_1_(filename_v, ar_temp), ar_temp2), L"rb");
          free(ar_temp);
          free(ar_temp2);
     }

     if (amanda_file)
     {
          len_arp = fread(&ret_arp_, 1, 4, amanda_file);

          fclose(amanda_file);

          if (4 == len_arp)
          {
               switch (ret_arp_)
               {

               case 0x706c6176 - 6:
                    return true;
                    break;

               case 0x706c6176 - 7:
                    return true;
                    break;

               case 0x706c6176 - 8:
                    return true;
                    break;

               case 0x706c6176 - 9:
                    return true;
                    break;

               case 0x706c6176 - 10:
                    return true;
                    break;

               case 0x706c6176 - 11:
                    return true;
                    break;
               }
          }
     }

     return false;
}
#include "decode_encryption_multi_pedro.c"