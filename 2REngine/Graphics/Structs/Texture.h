#pragma once

#include "TextureConfig.h"
#include <string>

static unsigned short g_Slot;

struct Texture
{
protected:
	unsigned int ID;
	unsigned short Slot;
	TextureConfig Config;
public:
	Texture(const char* filename);
	~Texture();
	void Bind();
	void Unbind();
};

