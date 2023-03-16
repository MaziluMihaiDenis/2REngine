#version 330 core

out vec4 FragColor;

in vec2 texCoord;

uniform sampler2D texture;
uniform vec3 color;

void main()
{
	FragColor = texture(texture, TexCoord) * vec4(color, 1.0);
}