#include "internal.h"

REWindow* re_create_window(REWindowSettings* settings, const char* title, DBool fullscreen, REWindow* share)
{
	REWindow* window;
	REContextSettings* ctxsettings;

	MALLOC(window, 1, REWindow);
	MALLOC(ctxsettings, 1, REContextSettings);

	if (!window)
		return NULL;
	if (!ctxsettings)
	{
		FREE(window);
		return NULL;
	}

	ctxsettings->major = 3;
	ctxsettings->minor = 3;
	ctxsettings->profile = 1;
	ctxsettings->forward = 0;

	window->settings = settings;
	window->share = share;
	window->fullscreen = fullscreen;
	window->running = TRUE;
	window->share = share;
	window->name = title;	
	window->index = relib.windows_count;

	if (!relib.platform->platform_create_window(window, window->settings, ctxsettings))
		return NULL;

	relib.windows = realloc(relib.windows, (relib.windows_count + 1) * sizeof(REWindow*));
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
	relib.windows[window->index] = relib.windows[relib.windows_count - 1];
	relib.windows_count--;
	FREE(window->settings);
	FREE(window);
}

int re_add_window_hints(int attrib, int value)
{
	relib.attribList[attrib] = value;
	return 1;
}

int re_get_hint(int attrib)
{
	return relib.attribList[attrib];
}

void re_set_key_callback(REKeyCallback callback)
{
	relib.callbacks.key = callback;
}

