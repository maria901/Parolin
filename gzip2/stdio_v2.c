
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
	assert(stream_z);

	if (stream_z->file_is_in_memory)
	{
		return stream_z->current_file_position_z;
	}
	else
	{
		assert(stream_z->internal_file_z && "File is not open");
		return _ftelli64(stream_z->internal_file_z);
	}
	return 0;
}

size_t fwrite_z(
	const void *buffer_z,
	size_t size_z,
	size_t count_z,
	FILE_z *stream_z)
{
	int ret_arp;
	//int64_t temp_z;
	assert(stream_z);
	assert(1 == size_z);
	if (stream_z->file_is_in_memory)
	{
		//return stream_z->current_file_position_z;

		assert(stream_z->memory_z);

		if ((int64_t)(count_z + stream_z->current_file_position_z) < (int64_t)stream_z->max_memory_size)
		{
			pedro_dprintf(-1, "file in memory\n");
			memcpy(stream_z->memory_z + stream_z->current_file_position_z, buffer_z, count_z);
			stream_z->current_file_position_z += count_z;
			stream_z->end_position_z = max(stream_z->current_file_position_z, stream_z->end_position_z);
			return count_z;
		}
		else
		{
			stream_z->file_is_in_memory = false;
			pedro_dprintf(-1, "dumping file to disk\n");
			if (NULL == stream_z->internal_file_z)
			{
				if (Z_MODE_IS_WB == stream_z->open_mode_int)
				{
					if (0 != stream_z->filename_a_z[0])
					{
						stream_z->internal_file_z = fopen(stream_z->filename_a_z, "wb");

						if (stream_z->internal_file_z)
						{
							ret_arp = fwrite(stream_z->memory_z, 1, stream_z->current_file_position_z, stream_z->internal_file_z);

							if (ret_arp != stream_z->current_file_position_z)
							{
								return -1;
							}

							ret_arp = fwrite(buffer_z, 1, count_z, stream_z->internal_file_z);

							if ((size_t)ret_arp != (size_t)count_z)
							{
								return -1;
							}

							return ret_arp;
						}
						else
						{
							return -1;
						}
					}
					else if (0 != stream_z->filename_w_z[0])
					{
						stream_z->internal_file_z = _wfopen(stream_z->filename_w_z, L"wb");

						if (stream_z->internal_file_z)
						{
							ret_arp = fwrite(stream_z->memory_z, 1, stream_z->current_file_position_z, stream_z->internal_file_z);

							if (ret_arp != stream_z->current_file_position_z)
							{
								return -1;
							}

							ret_arp = fwrite(buffer_z, 1, count_z, stream_z->internal_file_z);

							if ((size_t)ret_arp != (size_t)count_z)
							{
								return -1;
							}

							return ret_arp;
						}
						else
						{
							return -1;
						}
					}
					else
					{
						assert(0);
					}
				}
				else if (Z_MODE_IS_RB_PLUS == stream_z->open_mode_int)
				{
					if (0 != stream_z->filename_a_z[0])
					{
						stream_z->internal_file_z = fopen(stream_z->filename_a_z, "rb+");

						if (stream_z->internal_file_z)
						{
							ret_arp = fwrite(stream_z->memory_z, 1, stream_z->current_file_position_z, stream_z->internal_file_z);

							if (ret_arp != stream_z->current_file_position_z)
							{
								return -1;
							}

							ret_arp = fwrite(buffer_z, 1, count_z, stream_z->internal_file_z);

							if ((size_t)ret_arp != (size_t)count_z)
							{
								return -1;
							}

							return ret_arp;
						}
						else
						{
							return -1;
						}
					}
					else if (0 != stream_z->filename_w_z[0])
					{
						stream_z->internal_file_z = _wfopen(stream_z->filename_w_z, L"rb+");

						if (stream_z->internal_file_z)
						{
							ret_arp = fwrite(stream_z->memory_z, 1, stream_z->current_file_position_z, stream_z->internal_file_z);

							if (ret_arp != stream_z->current_file_position_z)
							{
								return -1;
							}

							ret_arp = fwrite(buffer_z, 1, count_z, stream_z->internal_file_z);

							if ((size_t)ret_arp != (size_t)count_z)
							{
								return -1;
							}

							return ret_arp;
						}
						else
						{
							return -1;
						}
					}
					else
					{
						assert(0 && "Error in fwrite_z function");
					}
				}
				else
				{
					assert(0 && "Invalid argument to fwrite_z function");
					exit(27);
				}
			}
			else
			{

				ret_arp = fwrite(buffer_z, 1, count_z, stream_z->internal_file_z);

				if ((size_t)ret_arp != (size_t)count_z)
				{
					return -1;
				}

				return ret_arp;
			}
		}
	}
	else
	{
		ret_arp = fwrite(buffer_z, 1, count_z, stream_z->internal_file_z);

		if ((size_t)ret_arp != (size_t)count_z)
		{
			return -1;
		}
		return ret_arp;
	}

	return 0;
}

int fclose_z(
	__attribute__((unused)) FILE_z *stream_z)
{
	return 0;
}

FILE_z *fopen_z(
	const char *filename_z,
	const char *mode_z,
	int64_t max_memory_size_z,
	char *file_z,
	int line_z,
	FILE_z *old_file_z)
{

	pedro_dprintf(-1, "fopen_z file %s line %d mode %s\n", file_z, line_z, mode_z);

	FILE_z *stream_z = NULL;
	if (NULL == old_file_z)
	{
		stream_z = calloc(1, sizeof(FILE_z));
		assert(stream_z);
		stream_z->memory_z = malloc(max_memory_size_z);
		assert(stream_z->memory_z);
		strcpy(stream_z->filename_a_z, filename_z);
		stream_z->file_is_in_memory = true;
		stream_z->max_memory_size = max_memory_size_z;
	}
	else
	{
		stream_z = old_file_z;
	}
	if (0 == strcmp(mode_z, "wb"))
	{
		assert(NULL == old_file_z);
		stream_z->open_mode_int = Z_MODE_IS_WB;
		return stream_z;
	}
	else if (0 == strcmp(mode_z, "rb+"))
	{
		assert(NULL != old_file_z);
		stream_z->open_mode_int = Z_MODE_IS_RB_PLUS;

		if (stream_z->file_is_in_memory)
		{
			stream_z->current_file_position_z = 0;
		}
		else
		{
			assert(stream_z->internal_file_z);
			fclose(stream_z->internal_file_z);
			stream_z->internal_file_z = fopen(filename_z, "rb+");
		}
		return stream_z;
	}
	else if (0 == strcmp(mode_z, "rb"))
	{
		assert(NULL != old_file_z);
		stream_z->open_mode_int = Z_MODE_IS_RB;

		if (stream_z->file_is_in_memory)
		{
			stream_z->current_file_position_z = 0;
		}
		else
		{
			assert(stream_z->internal_file_z);
			fclose(stream_z->internal_file_z);
			stream_z->internal_file_z = fopen(filename_z, "rb");
		}
		return stream_z;
	}
	else
	{
		assert(0 && "Invalid mode for fopen_z");
		exit(27);
	}
	assert(0);
	return NULL;
}

FILE_z *_wfopen_z(
	const wchar_t *filename_z,
	const char *mode_z,
	int64_t max_memory_size_z,
	char *file_z,
	int line_z,
	FILE_z *old_file_z)
{

	pedro_dprintf(-1, "_wfopen_z file %s line %d mode %s\n", file_z, line_z, mode_z);

	FILE_z *stream_z = NULL;
	if (NULL == old_file_z)
	{
		stream_z = calloc(1, sizeof(FILE_z));
		assert(stream_z);
		stream_z->memory_z = malloc(max_memory_size_z);
		assert(stream_z->memory_z);
		wcscpy(stream_z->filename_w_z, filename_z);
		stream_z->file_is_in_memory = true;
		stream_z->max_memory_size = max_memory_size_z;
	}
	else
	{
		stream_z = old_file_z;
	}
	if (0 == strcmp(mode_z, "wb"))
	{
		assert(NULL == old_file_z);
		stream_z->open_mode_int = Z_MODE_IS_WB;
		return stream_z;
	}
	else if (0 == strcmp(mode_z, "rb+"))
	{
		assert(NULL != old_file_z);
		stream_z->open_mode_int = Z_MODE_IS_RB_PLUS;

		if (stream_z->file_is_in_memory)
		{
			stream_z->current_file_position_z = 0;
		}
		else
		{
			assert(stream_z->internal_file_z);
			fclose(stream_z->internal_file_z);
			stream_z->internal_file_z = _wfopen(filename_z, L"rb+");
		}
		return stream_z;
	}
	else if (0 == strcmp(mode_z, "rb"))
	{
		assert(NULL != old_file_z);
		stream_z->open_mode_int = Z_MODE_IS_RB;

		if (stream_z->file_is_in_memory)
		{
			stream_z->current_file_position_z = 0;
		}
		else
		{
			assert(stream_z->internal_file_z);
			fclose(stream_z->internal_file_z);
			stream_z->internal_file_z = _wfopen(filename_z, L"rb");
		}
		return stream_z;
	}
	else
	{
		assert(0 && "Invalid mode for fopen_z");
		exit(27);
	}

	return NULL;
}

size_t fread_z(
	void *buffer_z,
	size_t size_z,
	size_t count_z,
	FILE_z *stream_z)
{
	int ret_arp;
	int64_t remaining_z;
	assert(1 == size_z);
	assert(Z_MODE_IS_RB == stream_z->open_mode_int);
	pedro_dprintf(-1, "dentro de fread_z\n");
	if (stream_z->file_is_in_memory)
	{
		pedro_dprintf(-1, "stream_z->end_position_z %lld\n", stream_z->end_position_z);
		remaining_z = stream_z->end_position_z - stream_z->current_file_position_z;
		assert(0 <= remaining_z);
		if (0 == remaining_z)
		{
			return 0;
		}
		ret_arp = min(remaining_z, count_z);
		memcpy(buffer_z, stream_z->memory_z + stream_z->current_file_position_z,
			   ret_arp);
		stream_z->current_file_position_z += ret_arp;
		return ret_arp;
	}
	else
	{
		assert(stream_z->internal_file_z);
		return fread(buffer_z, 1, count_z, stream_z->internal_file_z);
	}
	return 0;
}
void free_z(FILE_z *stream_z)
{
	assert(stream_z);
	if (stream_z->memory_z)
	{
		pedro_dprintf(-1, "free on %lld\n", (int64_t)(__INT32_OR_INT64)stream_z->memory_z);
		free(stream_z->memory_z);
		stream_z->memory_z = NULL;
	}
	if (stream_z->internal_file_z)
	{
		pedro_dprintf(-1, "fclose on %lld\n", (int64_t)(__INT32_OR_INT64)stream_z->internal_file_z);
		fclose(stream_z->internal_file_z);
		stream_z->internal_file_z = NULL;
	}
	free(stream_z);
}