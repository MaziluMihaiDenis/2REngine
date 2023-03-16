#pragma once

#include "../../../Rendering/Data Types/BufferObject.h"
#include "../../../Rendering/Data Types/Shader.h"
#include "../../../Rendering/Data Types/Texture.h"
#include "Object.h"

typedef struct DisplayObject DisplayObject;

class DisplayObject : public Object
{
	Texture* DisplayTexture;
	ShaderProgram* DisplayShader;
	BufferObject* DisplayBuffer;
};



