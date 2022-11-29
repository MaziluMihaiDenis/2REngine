#include "internal.h"

DBool re_init()
{
	if (relib.platform.platform_init())
	{
	}
	return TRUE;
}