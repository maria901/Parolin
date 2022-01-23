/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*        Licensa de Cópia (C) <2022>  <Corporação do Trabalho Binário>        *
*                                                                             *
*     Este  programa  é software livre: você pode redistribuir isto e/ou      *
*     modificar  isto sobre os termos do  GNU Licensa Geral Pública como     10
*     publicado  pela Fundação  de Software  Livre, tanto a versão 3  da      *
*     Licensa, ou (dependendo da sua opção) qualquer versão posterior.        *
*                                                                             *
*     Este  programa é distribuído na  esperança que isto vai  ser útil,      *
*     mas SEM  QUALQUER GARANTIA; sem  até mesmo a implicada garantia de      *
*     COMERCIALIZAÇÃO ou CABIMENTO PARA UM FIM PARTICULAR.  Veja a            *
*     Licensa Geral Pública para mais detalhes.                               *
*                                                                             *
*     Você deve ter recebido uma  cópia da LICENSA GERAL PUBLICA e a GNU      *
*     Licensa Pública Menor junto com este programa                           *
*     Se não, veja <http://www.gnu.org/licenses/>.                            *
*                                                                             *
*     Suporte: https://nomade.sourceforge.io/                                 *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

	 E-mails:
	 maria@arsoftware.net.br
	 pedro@locacaodiaria.com.br

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                             *
*     contato imediato(para uma resposta muito rápida) WhatsApp               *
*     (+55)41 9627 1708 - isto está sempre ligado (eu acho...)                *
*                                                                             *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

// Última modificação/compilação: Tue Fev 17 00:00 1994

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

void pedro_dprintf(int amanda_level,
				   char *format, ...)
{
	if (-1 < amanda_level)
	{
		va_list amanda;
		char *buffer_kp = malloc(20000);
		char *ptr_z;
		va_start(amanda, format);
		vsprintf(buffer_kp, format, amanda);
		if (strlen(buffer_kp))
		{
			ptr_z = buffer_kp;

			while (*ptr_z)
			{
				if ('\n' == *ptr_z || '\r' == *ptr_z)
				{

					*ptr_z = ' ';
				}
				ptr_z++;
			}
		}
		strcat(buffer_kp, " _amanda_debug_");
		OutputDebugString(buffer_kp);
		free(buffer_kp);
		va_end(amanda);
		// fixed...my love
	}
	return;
}

/**
 * Function to send a formatted string to OutputDebugString as a wide string that
 * can be captured by DebugView or the installed debugger
 *
 * @param amanda_level if above -1 it will show the string
 *
 * @param format the formatted string to show
 *
 */
void pedro_dprintfW( // para imprimir wide string use %ls ok?, te amo...
	int amanda_level,
	const wchar_t *format, ...)
{
	if (-1 < amanda_level)
	{

// since we don´t use the standard mingw for the moment we can use only this
// part of the code
#if 1

		// int vswprintf (wchar_t * ws, size_t len, const wchar_t * format, va_list arg );

		wchar_t *buffer_kp = malloc(40000);
		wchar_t *ptr_z;
		va_list args;
		va_start(args, format);
		vswprintf(buffer_kp, 20000, format, args);
		if (wcslen(buffer_kp))
		{
			ptr_z = buffer_kp;

			while (*ptr_z)
			{
				if ('\n' == *ptr_z || '\r' == *ptr_z)
				{

					*ptr_z = ' ';
				}
				ptr_z++;
			}
		}
		wcscat(buffer_kp, L" _amanda_debug_");
		OutputDebugStringW(buffer_kp);
		free(buffer_kp);
		va_end(args);

#else
		wchar_t buffer[20000];
		va_list args;
		va_start(args, format);
		vswprintf(buffer, format, args);
		if ('\n' == buffer[wcslen(buffer) - 1])
		{
			buffer[wcslen(buffer) - 1] = ' ';
		}
		wcscat(buffer, L" _amanda_debug_");
		OutputDebugStringW(buffer);
		va_end(args);
#endif
	}
	return;
}

int ra____file_size(unsigned char *ra____file)
{
	int ra____tamanho;
	FILE *ra____file_ptr = fopen((void *)ra____file, "rb");
	if (NULL == ra____file_ptr)
	{
		printf("Erro em %s\n", __FUNCTION__);
		exit(7);
		return 7;
	}

	fseek(ra____file_ptr, 0, SEEK_END);

	ra____tamanho = ftell(ra____file_ptr);

	fclose(ra____file_ptr);

	return ra____tamanho;
}
int ra____mensaginha_sim_nao(unsigned short *ra____text)
{
	return MessageBoxW(0, ra____text, L"Ric listen to this\n", MB_YESNO);
}
int ra____mensaginha_ok(unsigned short *ra____text)
{
	return MessageBoxW(0, ra____text, L"Ric listen to this\n", MB_OK);
}

void ra____dump_arrays_to_disk(unsigned char *ra____bytes_array_file,
							   unsigned char *ra____bits_array_file,
							   unsigned char *ra____pointers_array_file,
							   unsigned char *ra____file_out)
{
	uint8_t ra____character_one;
	uint8_t ra____character_two;
	uint64_t ra____last_byte_saved_postion = 0;
	uint64_t ra____last_bit_saved_postion = 0;
	uint64_t ra____counter_1 = 0;
	uint64_t ra____counter_2 = 0;
	uint64_t ra____counter_3 = 0;
	int ra____character_read_bytes;
	int ra____character_temp;
	int ra____len;

	uint64_t ra____size_r = ra____file_size(ra____bits_array_file) +
							ra____file_size(ra____bytes_array_file) +
							ra____file_size(ra____pointers_array_file);

	printf("Total size %lld\n", ra____size_r);

	FILE *ra____dest_file = fopen((void *)ra____file_out, "wb");
	FILE *ra____S2_bytes_array_file = fopen((void *)ra____bytes_array_file, "rb");
	FILE *ra____S2_bits_array_file = fopen((void *)ra____bits_array_file, "rb");
	FILE *ra____S2_pointers_array_file = fopen((void *)ra____pointers_array_file, "rb");
	// assert(0 && "inicio");
	if (NULL == ra____dest_file || NULL == ra____S2_bytes_array_file || NULL == ra____S2_bits_array_file || NULL == ra____S2_pointers_array_file)
	{
		printf("Cannot open temporary files, exiting\n");
		exit(7);
	}
	/*
	fwrite(&ra____last_byte_saved_postion, 1, sizeof(ra____last_byte_saved_postion), ra____dest_file);
	fwrite(&ra____last_byte_saved_postion, 1, sizeof(ra____last_byte_saved_postion), ra____dest_file);
	putc(0, ra____dest_file);
	putc(0, ra____dest_file);
	*/
	while ((/* for your pleasure */ fread(&ra____character_one, 1, 1, ra____S2_bytes_array_file)))
	{
		if (0 == ra____counter_2 % 8)
		{
			ra____len = fread(&ra____character_two, 1, 1, ra____S2_bits_array_file);

			assert(0 != ra____len);

			fwrite(&ra____character_two, 1, 1, ra____dest_file);

			ra____counter_2++;
		}

		fwrite(&ra____character_one, 1, 1, ra____dest_file);

		ra____counter_1++;
	}
	while (fread(&ra____character_one, 1, 1, ra____S2_pointers_array_file))
	{
		if (0 == ra____counter_2 % 8)
		{
			ra____len = fread(&ra____character_two, 1, 1, ra____S2_bits_array_file);

			assert(0 != ra____len);

			fwrite(&ra____character_two, 1, 1, ra____dest_file);

			ra____counter_2++;
		}

		ra____counter_3++;
		fwrite(&ra____character_one, 1, 1, ra____dest_file);
	}

	while (fread(&ra____character_two, 1, 1, ra____S2_bits_array_file))
	{

		fwrite(&ra____character_two, 1, 1, ra____dest_file);

		ra____counter_2++;
	}
	// assert(0 && "final");
	printf("Total %lld\n", ra____counter_1 + ra____counter_2 + ra____counter_3);
	printf("Bytes saved %lld\n", ra____counter_1);
	printf("Bits saved %lld\n", ra____counter_2);
	printf("\n\nbytes file ric %s\n", ra____bytes_array_file);
	printf("ra____bits_array_file file ric %s\n", ra____bits_array_file);
	printf("ra____pointers_array_file file ric %s\n", ra____pointers_array_file);
	printf("ra____file_out file ric %s\n\n", ra____file_out);

	fclose(ra____dest_file);
	fclose(ra____S2_bytes_array_file);
	fclose(ra____S2_bits_array_file);
	fclose(ra____S2_pointers_array_file);

	return;
}