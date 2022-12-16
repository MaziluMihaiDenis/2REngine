#include "internal.h"

REWindow* re_create_window(DVector2D size, DString name, DBool fullscreen, REWindow* share)
{
	REWindow* window;

	if (!MALLOC(window, 4))
		return NULL;

	if (!MALLOC(window->settings, 4))
	{
		free(window);
		return NULL;
	}

	window->settings->name = name;
	window->settings->pos = VECTOR2D(100, 100);
	window->settings->size = size;
	window->settings->style = 0;
	window->share = share;
	window->fullscreen = fullscreen;
	window->running = TRUE;
	window->share = share;

	if (!relib.platform.platform_create_window(window, window->settings))
		return NULL;

	relib.mainWindow = window;

	return window;
}

void re_poll_events()
{
	relib.platform.platform_poll_events();
}

void re_free_window(REWindow* window)
{
	relib.platform.platform_free_window(window);
}

