#include <stdio.h>
#include "Core/RE Application/internal.h"

int main()
{
    REWindow* window;

    if (!re_init()) 
        return 1;

    window = re_create_window(MAKE_VEC(1024, 768), MAKE_STR("NIGGER"), FALSE, 0);

    while (window->running)
    {
        re_poll_events();
    }

    return 0;
}