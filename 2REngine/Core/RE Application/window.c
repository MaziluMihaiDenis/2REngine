#include "internal.h"

REWindow* re_create_window(DVector2D size, DString name, DBool fullscreen, REWindow* share)
{
	REWindow* window;

	if (!MALLOC(window, 4))
		return NULL;

	window->settings->name = name;
	window->settings->pos = (DVector2D){ .x = 100, .y = 100 };
	window->settings->size = size;
	window->settings->style = 0;
	window->share = share;
	window->fullscreen = fullscreen;
	window->running = TRUE;

	relib.platform.platform_create_window(window, window->settings);

	relib.mainWindow = window;

	return window;
}

void re_poll_events()
{

}

void re_free_window(REWindow* window)
{

}

