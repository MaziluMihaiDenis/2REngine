#include "Core/RE Application/internal.h"
#include <glad/glad.h>
#include <stdio.h>

int main()
{
    REWindow* window;

    if (!re_init()) 
        return 1;

    window = re_create_window(VECTOR2D(1024, 768), STRING("NIGGER"), FALSE, 0);
    re_make_current(window);
    gladLoadGL();
    glViewport(0, 0, 1024, 768);

    while (window->running)
    {
        re_poll_events();

        re_swap_buffers(window);
    }

    re_free_window(window);

    return 0;
}