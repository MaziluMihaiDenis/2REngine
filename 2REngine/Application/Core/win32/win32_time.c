#include <Windows.h>
#include "win32_core.h"
#define TIME_FREQUNECY frequency

static int frequency = 1;

int _win32_init_time()
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	frequency = freq.QuadPart;

	if (freq.QuadPart == 0)
		return 0;
	return 1;
}

int _win32_get_current_time_ms()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return count.QuadPart;
}

int _win32_get_time_frequency()
{
	return frequency;
}
