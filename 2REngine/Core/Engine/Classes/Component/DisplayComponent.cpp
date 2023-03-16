#include "DisplayComponent.h"
#include "../../../../External/Glad/glad.h"

void DisplayComponent::Bind()
{
	_bind_buffer_object(*DisplayBuffer);
	_use_shader(*DisplayShader);
	_bind_texture(*DisplayTexture);
}

void DisplayComponent::Unbind()
{
	_unbind_buffer_object();
	_unuse_shader();
	_unbind_texture();
}

void DisplayComponent::Render()
{
	Bind();

	glDrawElements(GL_TRIANGLES, DisplayBuffer->indicesSize, GL_UNSIGNED_INT, (void*)(*DisplayBuffer->indices));

	Unbind();
}

DisplayComponent::DisplayComponent()
{
	float vertices[] = {
		-1.f, -1.f,
		1.f, -1.f,
		1.f, 1.f,
		-1.f, 1.f
	};
	unsigned int indices[]{ 0, 1, 2, 2, 3, 0 };

	DisplayBuffer = _make_buffer_object(vertices, sizeof(vertices), indices, sizeof(indices));
	DisplayShader = _generate_shader("2Rengine/Shaders/default_vertex.glsl", "2Rengine/Shaders/default_fragment.glsl");
	DisplayTexture = _generate_texture("2Rengine/SwagGorilla.png");
}

void DisplayComponent::Loop(float deltaTime)
{
	if (Updated)
	{
		// to do
	}
}
