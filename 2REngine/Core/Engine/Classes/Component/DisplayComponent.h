#pragma once

extern "C"
{
#include "../../../../Rendering/Data Types/BufferObject.h"
#include "../../../../Rendering/Data Types/Shader.h"
#include "../../../../Rendering/Data Types/Texture.h"
}
#include "Component.h"

class DisplayComponent : public Component
{
	friend class Renderer;

private:
	Texture* DisplayTexture;
	ShaderProgram* DisplayShader;
	BufferObject* DisplayBuffer;

private:
	void Bind();
	void Unbind();
	void Render();

public:
	DisplayComponent();
	virtual void Loop(float deltaTime) override;
};