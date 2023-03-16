#include "Texture.h"
#include "../../External/stb_image/stb_image.h"
#include "../../External/Glad/glad.h"
#include "../../Core/Types/RECore.h"

Texture* generate_texture(const char* filename)
{
	Texture* texture;

	if (!MALLOC(texture, sizeof(Texture)))
		return 0;

	unsigned char* data;
	unsigned int texID;
	int width, height, channels;

	data = stbi_load(filename, &width, &height, &channels, 0);

	if (!data)
	{
		FREE(texture);
		FREE(data);
		return NULL;
	}

	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(&data);

	texture->filename = filename;
	texture->width = width;
	texture->height = height;
	texture->ID = texID;

	return texture;
}

void _bind_texture(Texture texture)
{
	glActiveTexture(texture.slot);
	glBindTexture(GL_TEXTURE_2D, texture.ID);
}

void _unbind_texture()
{
	glActiveTexture(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}
