#pragma once

#include <VertexArray.h>
#include <ShaderProgram.h>
#include <Texture.h>
#include "Component.h"

class DisplayComponent : public Component
{
	friend class Renderer;

private:
	Texture* DisplayTexture;
	ShaderProgram* DisplayShader;
	VertexArray* DisplayVertexArray;

private:
	void Bind();
	void Unbind();
	void Render();

public:
	void SetColor(float r, float g, float b, float a = 1.f);
	void SetTexture(const char* filename);
	void SetShader(const char* filename);

public:
	DisplayComponent();
	virtual void Loop(float deltaTime) override;
};