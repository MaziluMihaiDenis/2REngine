#include "internal.h"

REWindow* re_create_window(REWindowSettings* settings, DBool fullscreen, REWindow* share)
{
	REWindow* window;

	if (!MALLOC(window, sizeof(REWindow)))
		return NULL;

	if (!MALLOC(window->settings, sizeof(REWindowSettings)))
	{
		FREE(window);
		return NULL;
	}

	window->settings = settings;
	window->share = share;
	window->fullscreen = fullscreen;
	window->running = TRUE;
	window->share = share;

	if (!relib.platform->platform_create_window(window, window->settings))
		return NULL;

	relib.windows = realloc(relib.windows, (relib.windows_count + 1) *sizeof(REWindow*));
	relib.windows[relib.windows_count++] = window;

	return window;
}

void re_poll_events()
{
	relib.platform->platform_poll_events();
}

void re_free_window(REWindow* window)
{
	relib.platform->platform_free_window(window);
}

