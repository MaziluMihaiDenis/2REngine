#include "internal.h"

void re_set_context_current(REWindow* window)
{
	if (!relib.platform->platform_set_context_current(window))
		LOG_ERROR("COULDN'T MAKE THE CONTEXT CURRENT");
}

void re_swap_buffers(REWindow* window)
{
	relib.platform->platform_swap_buffers(window);
}

