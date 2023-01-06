#include "Core/2relibrary.h"
#include <stb_image.h>
extern "C"
{
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
    unsigned int indices[3] = { 0, 1, 2 };

    DBufferObject* bo = _make_buffer_object(verts, sizeof(verts), indices, sizeof(indices));

    while (window->running)
    {
        re_poll_events();


        re_swap_buffers(window);
    }

    _free_buffer_object(bo);
    re_free_window(window);

    return 0;
}