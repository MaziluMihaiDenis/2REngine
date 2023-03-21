#include "DisplayComponent.h"
#include "../../../../External/Glad/glad.h"

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

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	Unbind();
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
	DisplayShader = new ShaderProgram("2Rengine/Shaders/default_vertex.glsl", "2Rengine/Shaders/default_fragment.glsl");
	DisplayTexture = new Texture("2Rengine/SwagGorilla.png");
}

void DisplayComponent::Loop(float deltaTime)
{
	if (Updated)
	{
		// to do
	}
}
