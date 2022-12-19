#include "win32_core.h"
#include "../internal.h"

DBool _win32_init()
{
	relib.win32.instance = GetModuleHandle(0);

	if (!_win32_init_gl())
		LOG_ERROR("COULDN'T CREATE A FALSE CONTEXT");

	return TRUE;
}

void _win32_terminate()
{
}

void _win32_connect()
{
	relib.platform = (REPlatform){
		_win32_init,
		_win32_terminate,
		win32_create_window,
		_win32_poll_events,
		_win32_free_window,
		win32_make_context_current,
		_win32_swap_buffers
	};
}
