#include <stdio.h>
#include "Core/RE Application/internal.h"

int main()
{
    REWindow* window;

    if (!re_init()) 
        return 1;

    window = re_create_window(VECTOR2D(1024, 768), STRING("NIGGER"), FALSE, 0);
    re_make_current(window);

    while (window->running)
    {
        re_poll_events();
    }

    re_free_window(window);

    return 0;
}