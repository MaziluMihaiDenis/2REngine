#version 330 core

layout(location = 0) in vec2 VertexPos;
layout(location = 1) in vec2 TexCoord;

out vec2 texCoord;

void main()
{
	gl_Position = vec4(VertexPos, 0.0, 1.0);
	texCoord = TexCoord;
}