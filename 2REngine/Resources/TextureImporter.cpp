#include "TextureImporter.h"
#include <Graphics/Structs/TextureConfig.h>
extern "C"
{
#include <Basic/filesystem.h>
}

void TextureImporter::Init()
{
	import_texture("2REngine\\Resources\\Textures\\SwagGorilla.png", NULL);
}