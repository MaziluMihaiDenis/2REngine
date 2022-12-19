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

    while (window->running)
    {
        re_poll_events();

        re_swap_buffers(window);
    }

    re_free_window(window);

    return 0;
}