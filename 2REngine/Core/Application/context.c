#include "internal.h"
#include <Glad/glad.h>

void re_set_context_current(REWindow* window)
{
	if (!relib.platform->platform_set_context_current(window))
		return;
}

void re_swap_buffers(REWindow* window)
{
	relib.platform->platform_swap_buffers(window);
}

void re_destroy_context(REWindow* window)
{
	relib.platform->platform_destroy_context(window);
}

void re_set_window_color(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);
}

