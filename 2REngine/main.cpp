#include "Core/2relibrary.h"
#include <glad/glad.h>
#include <stdio.h>

int main()
{
    REWindow* window;

    if (!re_init()) 
        return 1;

    window = re_create_window(MAKE_VEC(1024, 768), MAKE_STR("NIGGER"), FALSE, 0);
    re_make_current(window);
    gladLoadGL();
    glViewport(0, 0, 1024, 768);

   /* unsigned int VAO, VBO, EBO;

    float verts[] =
    {
        -1.f, -1.f,
        1.f, -1.f,
        1.f, 1.f
    };

    unsigned int indices[] = {
        0, 1, 2
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), &verts, GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);*/

    while (window->running)
    {
        re_poll_events();

        /*glBindVertexArray(VAO); 
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);*/

        re_swap_buffers(window);
    }

    re_free_window(window);

    return 0;
}