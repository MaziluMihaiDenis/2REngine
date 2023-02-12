#include "internal.h"

void re_get_monitor_size(int* width, int* height)
{
	relib.platform->platform_get_monitor_size(&*width, &*height);
}