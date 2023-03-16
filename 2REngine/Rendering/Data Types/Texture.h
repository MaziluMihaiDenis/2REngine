#pragma once

typedef struct Texture Texture;

struct Texture
{
	int ID;
	unsigned int width, height, slot;
	const char* filename;
};

Texture* generate_texture(const char* filename);
void _bind_texture(Texture texture);
void _unbind_texture();


