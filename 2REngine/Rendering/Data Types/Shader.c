#include "Shader.h"
#include "../../External/Glad/glad.h"
#include "../../Core/Types/Filesystem.h"
#include "../../Core/Types/Debug/debug.h"

ShaderProgram generate_shader(const char* vertexFn, const char* fragmentFn)
{
    ShaderProgram shader = {0};
    unsigned int vertID, fragID;
    int ok = 0;

    vertID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader.ID, 1, get_file_contents(vertexFn), 0);
    glCompileShader(shader.ID);
    glGetShaderiv(vertID, GL_COMPILE_STATUS, &ok);

    if (!ok)
        PRINT(0, "%s", "Vertex Shader Could Not Be Compiled");


    glAttachShader(shader.ID, vertID);

    fragID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader.ID, 1, get_file_contents(fragmentFn), 0);
    glCompileShader(shader.ID);
    glGetShaderiv(fragID, GL_COMPILE_STATUS, &ok);

    if (!ok)
        PRINT(0, "%s", "Fragment Shader Could Not Be Compiled");

    glAttachShader(shader.ID, fragID);

    glLinkProgram(shader.ID);
    glGetProgramiv(shader.ID, GL_LINK_STATUS, &ok);

    if (!ok)
        PRINT(0, "%s", "Program Could Not Link");

    return shader;
}

void use_shader(ShaderProgram shader)
{
    glUseProgram(shader.ID);
}
