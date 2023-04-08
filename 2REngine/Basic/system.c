#include <Application/Core/internal.h>

void re_get_monitor_size(int* width, int* height)
{
	relib.platform->platform_get_monitor_size(width, height);
}

int re_get_time_ms()
{
	return relib.platform->platform_get_time_ms();
}

int re_get_time_frequency()
{
	return relib.platform->platform_get_time_frequency();
}