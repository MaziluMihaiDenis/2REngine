#include "SpriteComponent.h"
#include "../Structs/Transformation2D.h"
#include <External/Glad/glad.h>

void SpriteComponent::Bind()
{
	DisplayVertexArray->Bind();
	DisplayShader->Bind();
	DisplayTexture->Bind();
}

void SpriteComponent::Unbind()
{
	DisplayVertexArray->Unbind();
	DisplayShader->Unbind();
	DisplayTexture->Unbind();
}

void SpriteComponent::Render()
{
	Bind();

	glDrawElements(
		GL_TRIANGLES, 
		6,
		GL_UNSIGNED_INT, 
		0
	);

	Unbind();
}

void SpriteComponent::SetColor(float r, float g, float b, float a)
{
	DisplayShader->Bind();
	DisplayShader->SetUniform4f("u_color", r, g, b, a);
}

void SpriteComponent::SetTexture(const char* filename)
{
	if(DisplayTexture)
		DisplayTexture->~Texture();
	DisplayTexture = new Texture(filename);
}

void SpriteComponent::SetShader(const char* filename)
{
	//..
}

void SpriteComponent::BufferData(Transformation2D& transform)
{
	float* matrix = transform.GetMatrix();
	glUseProgram(DisplayShader->ID);
	glUniformMatrix4fv(DisplayShader->GetLocation("matrix"), 1, GL_FALSE, matrix);
	delete matrix;
}

void SpriteComponent::SetProjection(float* projection)
{
	glUseProgram(DisplayShader->ID);
	glUniformMatrix4fv(DisplayShader->GetLocation("projection"), 1, GL_FALSE, projection);
}

SpriteComponent::SpriteComponent()
{
	float vertices[] = {
		-1.f, -1.f,		0.f, 0.f,
		 1.f, -1.f,		1.f, 0.f,
		 1.f, 1.f,		1.f, 1.f,
		-1.f, 1.f,		0.f, 1.f
	};
	unsigned int indices[]{ 0, 1, 2, 2, 3, 0 };

	DisplayVertexArray = new VertexArray(vertices, sizeof(vertices), indices, sizeof(indices));
	DisplayShader = new ShaderProgram("2REngine/Resources/Shaders/default_vertex.glsl", "2REngine/Resources/Shaders/default_fragment.glsl");
	DisplayTexture = new Texture("2REngine\\Resources\\Textures\\SwagGorilla.png");
}

void SpriteComponent::Loop(float deltaTime)
{
	if (Updated)
	{

	}
}
