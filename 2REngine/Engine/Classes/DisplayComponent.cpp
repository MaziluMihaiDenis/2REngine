#include "DisplayComponent.h"
#include "../Structs/Transformation2D.h"
#include <External/Glad/glad.h>

void DisplayComponent::Bind()
{
	DisplayVertexArray->Bind();
	DisplayShader->Bind();
	DisplayTexture->Bind();
}

void DisplayComponent::Unbind()
{
	DisplayVertexArray->Unbind();
	DisplayShader->Unbind();
	DisplayTexture->Unbind();
}

void DisplayComponent::Render()
{
	Bind();

	glDrawElements(
		GL_TRIANGLES, 
		DisplayVertexArray->IndicesSize, 
		GL_UNSIGNED_INT, 
		DisplayVertexArray->Indices
	);

	Unbind();
}

void DisplayComponent::SetColor(float r, float g, float b, float a)
{
	DisplayShader->SetUniform4f("u_color", r, g, b, a);
}

void DisplayComponent::SetTexture(const char* filename)
{
	if(DisplayTexture)
		DisplayTexture->~Texture();
	DisplayTexture = new Texture(filename);
}

void DisplayComponent::SetShader(const char* filename)
{
	//..
}

void DisplayComponent::BufferData(Transformation2D& transform)
{
	float* matrix = transform.GetMatrix();
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//		printf("%f ", matrix[4 * i + j]);
	//	printf("\n");
	//}
	glUseProgram(DisplayShader->ID);
	glUniformMatrix4fv(DisplayShader->GetLocation("matrix"), 1, GL_FALSE, matrix);
}

void DisplayComponent::SetProjection(float* projection)
{
	glUseProgram(DisplayShader->ID);
	float* matrix = projection;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			printf("%f ", matrix[4 * i + j]);
		printf("\n");
	}
	glUniformMatrix4fv(DisplayShader->GetLocation("projection"), 1, GL_FALSE, matrix);
}

DisplayComponent::DisplayComponent()
{
	float vertices[] = {
		-1.f, -1.f,		0.f, 0.f,
		 1.f, -1.f,		1.f, 0.f,
		 1.f, 1.f,		1.f, 1.f,
		-1.f, 1.f,		0.f, 1.f
	};
	unsigned int indices[]{ 0, 1, 2, 2, 3, 0 };

	DisplayVertexArray = new VertexArray(vertices, sizeof(vertices), indices, sizeof(indices));
	DisplayShader = new ShaderProgram("2Rengine/Rendering/Shaders/default_vertex.glsl", "2Rengine/Rendering/Shaders/default_fragment.glsl");
	DisplayTexture = new Texture("2Rengine/SwagGorilla.png");
}

void DisplayComponent::Loop(float deltaTime)
{
	if (Updated)
	{

	}
}
