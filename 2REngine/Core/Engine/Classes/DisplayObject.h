#pragma once

#include "BufferObject.h"
#include "Shader.h"
#include "Texture.h"

typedef struct DisplayObject DisplayObject;

struct DisplayObject
{
	Texture* DisplayTexture;
	ShaderProgram* DisplayShader;
	BufferObject* DisplayBuffer;
};



