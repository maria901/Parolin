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

#include "stdio_v2.h"

#include "win64.h"

void pedro_dprintf(
	int amanda_level,
	char *format, ...);

int print(void)
{
	pedro_dprintf(-1, "developed by the parents of Juliette\n");
	return -1;
}

__int64 _ftelli64_z(FILE_z *stream_z)
{
	return _ftelli64(stream_z);
}

size_t fwrite_z(
	const void *buffer_z,
	size_t size_z,
	size_t count_z,
	FILE_z *stream_z,
	enum error_modes_J *have_error_M)
{
	(void)buffer_z;
	(void)size_z;
	(void)count_z;
	(void)stream_z;
	(void)have_error_M;
	pedro_dprintf(-1, "tamanho salvo %d", (int)count_z);
	return fwrite(buffer_z, 1, count_z, stream_z);

	return 0;
}

int fclose_z(
	__attribute__((unused)) FILE_z *stream_z)
{

	fclose(stream_z);

	return 0;
}

FILE_z *_wfopen_z(
	const wchar_t *filename_z,
	const char *mode_z,
	int64_t max_memory_size_z,
	char *file_z,
	int line_z,
	FILE_z *old_file_z)
{
	(void)filename_z;
	(void)mode_z;
	(void)max_memory_size_z;
	(void)file_z;
	(void)line_z;
	(void)old_file_z;

	if (0 == strcmp("rb+", mode_z))
	{
		return _wfopen(filename_z, L"rb+");
	}
	if (0 == strcmp("rb", mode_z))
	{
		return _wfopen(filename_z, L"rb");
	}
	if (0 == strcmp("wb", mode_z))
	{
		return _wfopen(filename_z, L"wb");
	}
	return NULL;
}

size_t fread_z(
	void *buffer_z,
	size_t size_z,
	size_t count_z,
	FILE_z *stream_z,
	enum error_modes_J *have_error_M)
{
	(void)size_z;
	(void)have_error_M;

	return fread(buffer_z, 1, count_z, stream_z);

	return 0;
}
void free_z(FILE_z *stream_z)
{
	(void)stream_z;
}

FILE *fopen_utf8_z(char *filename_z, char *mode)
{
	FILE *eu_ela_;
	WCHAR *ricardo_k = (void *)malloc(32767 * 2);
	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)filename_z, -1, ricardo_k, (32767 * 2));
	WCHAR *ricardo2_k = (void *)malloc(32767 * 2);
	MultiByteToWideChar(CP_UTF8, 0, (LPCSTR)mode, -1, ricardo2_k, (32767 * 2));

	eu_ela_ = _wfopen(ricardo_k, ricardo2_k);
	free(ricardo_k);
	free(ricardo2_k);

	return eu_ela_;
}
