#include "DisplayObject.h"

void DisplayObject::Bind()
{
	_bind_buffer_object(*DisplayBuffer);
	_use_shader(*DisplayShader);
	_bind_texture(*DisplayTexture);
}

void DisplayObject::Unbind()
{
	_unbind_buffer_object();
	_unuse_shader();
	_unbind_texture();
}

void DisplayObject::Loop(float deltaTime)
{
	if (Updated)
	{
		// to do
	}
}
