#pragma once

#include <string>

static unsigned short g_Slot;

struct Texture
{
protected:
	unsigned short Slot;
	unsigned int ID;
	int Width, Height;
	const char* FileName;
public:
	Texture(const char* filename);
	void Bind();
	void Unbind();
};

