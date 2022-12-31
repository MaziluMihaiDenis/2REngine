extern "C"
{
#include "Core/2relibrary.h"
#include "Rendering/Data Types/BufferObject.h"
}
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

    float verts[6] = {
        -1.f, -1.f,
        1.f, -1.f,
        1.f, 1.f
    };
    unsigned int indices[] = { 0, 1, 2 };

    DBufferObject* bo = _make_buffer_object(verts, 6, indices, 3);

    while (window->running)
    {
        re_poll_events();

        _bind_buffer_object(bo);
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);

        re_swap_buffers(window);
    }

    _free_buffer_object(bo);
    re_free_window(window);

    return 0;
}