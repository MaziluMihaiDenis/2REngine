#include "TextureImporter.h"
#include "TextureImporter.h"
extern "C"
{
#include <Basic/filesystem.h>
}

void TextureImporter::Init()
{
	import_texture("2REngine/SwagGorilla.png", NULL);
}