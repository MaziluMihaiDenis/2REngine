#include "win32_core.h"
#include "../internal.h"

DBool win32_init()
{
	relib.win32.instance = GetModuleHandle(0);
	return TRUE;
}

void win32_terminate()
{
}

void win32_connect()
{
	relib.platform = (REPlatform){
		win32_init,
		win32_terminate,
		win32_create_window,
		win32_poll_events,
		win32_free_window,
		win32_make_context_current
	};
}