#include "win32_core.h"
#include "../internal.h"

// TODO: track all the memory allocations

DBool _win32_init()
{
	relib.win32.instance = GetModuleHandle(0);

	if (!_win32_init_gl())
		return FALSE;
	return TRUE;
}

void _win32_terminate()
{
}

void _win32_connect()
{
	*relib.platform = (REPlatform){
		_win32_init,
		_win32_terminate,
		win32_create_window,
		_win32_poll_events,
		_win32_free_window,
		win32_set_context_current,
		_win32_swap_buffers,
		_win_get_monitor_size
	};
}
