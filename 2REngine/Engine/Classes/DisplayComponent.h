#pragma once

#include "Component.h"
#include <Graphics/Structs/VertexArray.h>
#include <Graphics/Structs/ShaderProgram.h>
#include <Graphics/Structs/Texture.h>

class DisplayComponent : public Component
{
	friend class Graphics;

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
	void BufferData(struct Transformation2D& transform);
	void SetProjection(float* projection);

public:
	DisplayComponent();
	virtual void Loop(float deltaTime) override;
};