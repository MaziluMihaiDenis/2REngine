#include "internal.h"
#include <External/Glad/glad.h>

void re_set_context_current(REWindow* window)
{
	if (!relib.platform->platform_set_context_current(window))
		return;
	relib.main_window = window;
}

void re_swap_buffers(REWindow* window)
{
	relib.platform->platform_swap_buffers(window);
}

void re_destroy_context(REWindow* window)
{
	relib.platform->platform_destroy_context(window);
	FREE(window->context, 1, REContext);
}
