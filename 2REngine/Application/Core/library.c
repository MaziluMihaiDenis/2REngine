#include "internal.h"

RELibrary relib;

DBool re_init()
{
	if (!MALLOC(relib.platform, sizeof(REPlatform)))
		return FALSE;
#if defined(_WIN32)
	_win32_connect();
#endif
	if (!relib.platform->platform_init())
		return FALSE;

	return TRUE;
}

REWindow* re_get_main_window()
{
	return relib.main_window;
}

REWindow* re_get_window(int index)
{
	if (index >= relib.windows_count)
		return NULL;
	return relib.windows[index];
}

void re_terminate()
{
	relib.platform->platform_terminate();
}
