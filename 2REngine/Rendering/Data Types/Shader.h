#pragma once

typedef struct ShaderProgram ShaderProgram;

struct ShaderProgram
{
	int ID;
};

ShaderProgram* _generate_shader(const char* vertexFn, const char* fragmentFn);
void _use_shader(ShaderProgram shader);
void _unuse_shader();

