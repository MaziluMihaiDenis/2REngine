#pragma once

#include "../../../../Rendering/Data Types/BufferObject.h"
#include "../../../../Rendering/Data Types/Shader.h"
#include "../../../../Rendering/Data Types/Texture.h"
#include "Component.h"

class DisplayObject : public Component
{
	friend class Renderer;
private:
	Texture* DisplayTexture;
	ShaderProgram* DisplayShader;
	BufferObject* DisplayBuffer;

private:
	void Bind();
	void Unbind();

public:
	virtual void Loop(float deltaTime) override;
};