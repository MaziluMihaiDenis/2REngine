#include "win32_core.h"

void _win32_get_monitor_size(int * width, int * height)
{
	*width = GetSystemMetrics(SM_CXSCREEN);
	*height = GetSystemMetrics(SM_CYSCREEN);
}