#include "ShaderProgram.h"
#include <Glad/glad.h>
#include <string>
extern "C"
{
#include <Debug/debug.h>
#include <Filesystem.h>
}

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
        PRINT(SV_WARNING, "Vertex Shader Could Not Be Compiled: %s", vertexFn);
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

    glDeleteShader(VertexID);
    glDeleteShader(FragmentID);

}

void ShaderProgram::Bind()
{
    glUseProgram(ID);
}

void ShaderProgram::Unbind()
{
    glUseProgram(0);
}
