#include "internal.h"

void re_make_current(REWindow* window)
{
	if (!relib.platform.platform_make_current(window))
		LOG_ERROR("COULDN'T MAKE THE CONTEXT CURRENT");
}

void re_swap_buffers(REWindow* window)
{
	relib.platform.platform_swap_buffers(window);
}

