#include "internal.h"

void re_make_current(REWindow* window)
{
	if (!relib.platform.platform_make_current(window))
		LOG_ERROR("COULDN'T MAKE THE CONTEXT CURRENT");
}