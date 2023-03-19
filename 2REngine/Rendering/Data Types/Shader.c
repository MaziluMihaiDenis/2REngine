#include "Shader.h"
#include "../../External/Glad/glad.h"
#include "../../Core/Types/Filesystem.h"
#include "../../Core/Types/Debug/debug.h"
#include "../../Core/Types/RECore.h"

ShaderProgram* _generate_shader(const char* vertexFn, const char* fragmentFn)
{
    ShaderProgram* shader;
    unsigned int vertID, fragID;
    int ok = 0;

    const char* vertexSrc = get_file_contents(vertexFn);
    const char* fragmentSrc = get_file_contents(fragmentFn);

    printf(vertexSrc);

    if (!MALLOC(shader, sizeof(ShaderProgram)))
        return NULL;

    shader->ID = glCreateProgram();
    vertID = glCreateShader(GL_VERTEX_SHADER);
    fragID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertID, 1, vertexSrc, 0);
    glCompileShader(vertID);
    glGetShaderiv(vertID, GL_COMPILE_STATUS, &ok);
    if (!ok)
        PRINT(0, "%s", "Vertex Shader Could Not Be Compiled");

    glShaderSource(fragID, 1, fragmentSrc, 0);
    glCompileShader(fragID);
    glGetShaderiv(fragID, GL_COMPILE_STATUS, &ok);
    if (!ok)
        PRINT(0, "%s", "Fragment Shader Could Not Be Compiled");

    glAttachShader(shader->ID, vertID);
    glAttachShader(shader->ID, fragID);

    glLinkProgram(shader->ID);
    glGetProgramiv(shader->ID, GL_LINK_STATUS, &ok);

    glDeleteShader(vertID);
    glDeleteShader(fragID);

    if (!ok)
        PRINT(0, "%s", "Program Could Not Link");

    return shader;
}

void _use_shader(ShaderProgram shader)
{
    glUseProgram(shader.ID);
}

void _unuse_shader()
{
    glUseProgram(0);
}
