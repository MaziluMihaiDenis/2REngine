#version 330 core

layout (location = 0) in vec2 v_pos;
layout (location = 1) in vec2 v_tex_coord;

out vec2 tex_coord;

void main()
{
    gl_Position = vec4(v_pos, 1.0, 1.0);
    tex_coord = v_tex_coord;
}