#include "Texture.h"
#include <stb_image/stb_image.h>
#include <Glad/glad.h>
extern "C"
{
#include <Core/Types/Filesystem.h>
#include <RECore.h>
#include <Debug/debug.h>
}

Texture::Texture(const char* filename)
{
	unsigned char* data;
	int channels;

	read_reimptex(filename, &Config);
	data = stbi_load(filename, &Config.Width, &Config.Height, &channels, 0);
	Config.FileName = filename;
	Slot = g_Slot;
	g_Slot++;

	if (!data)
	{
		PRINT(SV_ERROR, "NO TEXTURE DATA IN FILE: %s", filename);
		FREE(data);
	}

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, Config.Wrapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, Config.Wrapping);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, Config.Filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, Config.Filter);

	glTexImage2D(GL_TEXTURE_2D, 0, Config.ColorFormat, Config.Width, Config.Height, 0, Config.ColorFormat, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

void Texture::Bind()
{
	glActiveTexture(Slot);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind()
{
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}
