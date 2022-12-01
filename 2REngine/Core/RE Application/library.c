#include "internal.h"

DBool re_init()
{
#if defined(_WIN32)

#endif

	if (!relib.platform.platform_init())
		return FALSE;

	return TRUE;
}