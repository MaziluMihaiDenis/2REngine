#include "Texture.h"
#include <stb_image/stb_image.h>
#include <Glad/glad.h>
extern "C"
{
#include <RECore.h>
#include <Debug/debug.h>
}

Texture::Texture(const char* filename)
{
	unsigned char* data;
	int channels;

	data = stbi_load(filename, &Width, &Height, &channels, 0);
	FileName = filename;
	Slot = g_Slot;
	g_Slot++;

	if (!data)
	{
		PRINT(SV_ERROR, "NO TEXTURE DATA IN FILE: %s", filename);
		FREE(data);
	}

	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
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
