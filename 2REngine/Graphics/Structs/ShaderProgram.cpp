#include "ShaderProgram.h"
#include <2relibrary.h>

ShaderProgram::ShaderProgram(const char* vertexFn, const char* fragmentFn)
{
    int success = 0;
    
    const char* vertexSrc = get_file_contents(vertexFn);
    const char* fragmentSrc = get_file_contents(fragmentFn);

    ID = glCreateProgram();
    VertexID = glCreateShader(GL_VERTEX_SHADER);
    FragmentID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(VertexID, 1, &vertexSrc, 0);
    glCompileShader(VertexID);
    glGetShaderiv(VertexID, GL_COMPILE_STATUS, &success);
    if (success == 0)
    {
        PRINT(SV_ERROR, "Vertex Shader Could Not Be Compiled: %s", vertexFn);
        PRINT(SV_WARNING, "%s", vertexSrc);
    }

    glShaderSource(FragmentID, 1, &fragmentSrc, 0);
    glCompileShader(FragmentID);
    glGetShaderiv(FragmentID, GL_COMPILE_STATUS, &success);
    if (success == 0)
    {
        PRINT(SV_ERROR, "Fragment Shader Could Not Be Compiled: %s", fragmentFn);
        PRINT(SV_WARNING, "%s", fragmentSrc);
    }

    glAttachShader(ID, VertexID);
    glAttachShader(ID, FragmentID);

    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (success == 0)
    {
        PRINT(SV_ERROR, "%s", "Program Could Not Link");
    }

    ZeroMemory((void*)vertexSrc, 3000);
    ZeroMemory((void*)fragmentSrc, 3000);

    glDeleteShader(VertexID);
    glDeleteShader(FragmentID);
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(ID);
    delete this;
}

void ShaderProgram::Bind()
{
    glUseProgram(ID);
}

void ShaderProgram::Unbind()
{
    glUseProgram(0);
}

int ShaderProgram::GetLocation(const char* uniformName)
{
    return glGetUniformLocation(ID, uniformName);
}

void ShaderProgram::SetUniform4f(const char* uniformName, float a, float b, float c, float d)
{
    glUniform4f(GetLocation(uniformName), a, b, c, d);
}

void ShaderProgram::SetUniform3f(const char* uniformName, float a, float b, float c)
{
    glUniform3f(GetLocation(uniformName), a, b, c);
}

void ShaderProgram::SetUniform2f(const char* uniformName, float a, float b)
{
    glUniform2f(GetLocation(uniformName), a, b);
}

void ShaderProgram::SetUniform1f(const char* uniformName, float a)
{
    glUniform1f(GetLocation(uniformName), a);
}

void ShaderProgram::SetUniform4i(const char* uniformName, int a, int b, int c, int d)
{
    glUniform4i(GetLocation(uniformName), a, b, c, d);
}

void ShaderProgram::SetUniform3i(const char* uniformName, int a, int b, int c)
{
    glUniform3i(GetLocation(uniformName), a, b, c);
}

void ShaderProgram::SetUniform2i(const char* uniformName, int a, int b)
{
    glUniform2i(GetLocation(uniformName), a, b);
}

void ShaderProgram::SetUniform1i(const char* uniformName, int a)
{
    glUniform1i(GetLocation(uniformName), a);
}
