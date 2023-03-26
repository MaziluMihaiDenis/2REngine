#version 330 core

out vec4 frag_Color;
in vec4 color;

uniform sampler2D u_tex;
in vec2 tex_coord;

void main()
{
    frag_Color = texture(u_tex, tex_coord);
}