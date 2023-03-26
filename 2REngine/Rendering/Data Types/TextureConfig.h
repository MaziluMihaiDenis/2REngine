#pragma once

struct TextureConfig
{
	int Wrapping, ColorFormat, Filter;
	int Width, Height;
	const char* FileName;
};