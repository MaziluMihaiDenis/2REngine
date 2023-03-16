#pragma once

typedef struct ShaderProgram ShaderProgram;

struct ShaderProgram
{
	int ID;
};

ShaderProgram generate_shader(const char* vertexFn, const char* fragmentFn);
void use_shader(ShaderProgram shader);

