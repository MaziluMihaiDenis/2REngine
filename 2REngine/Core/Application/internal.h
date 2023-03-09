#pragma once
#include "platform.h"

typedef struct REWindowSettings REWindowSettings;
typedef struct RELibrary RELibrary;
typedef struct REPlatform REPlatform;
typedef struct REWindow REWindow;
typedef struct REContextSettings REContextSettings;
typedef struct REContext REContext;
typedef struct RESystem RESystem;

// TODO: Implement RESystem

typedef void(*REKeyCallback)(int, int);

struct REWindowSettings
{
	char *name;
	int offsetX, offsetY;
	int width, height;
	int style;
};

struct REContextSettings
{
	int minor, major, profile;
};

struct RESystem
{
	int screenWidth, screenHeight;
};

struct REPlatform
{
	DBool(*platform_init)();
	void(*platform_terminate)();
	DBool(*platform_create_window)(REWindow*, REWindowSettings*);
	void(*platform_poll_events)();
	void(*platform_free_window)(REWindow*);
	DBool(*platform_set_context_current)(REWindow*);
	void(*platform_swap_buffers)(REWindow*);
	void(*platform_get_monitor_size)(int*, int*);
	int(*platform_get_time_ms)();
	int(*platform_get_time_frequency)();
};

struct RELibrary
{
	REPlatform* platform;
	RESystem system;
	REWindow** windows;

	int windows_count;

	struct
	{
		REKeyCallback key;
	} callbacks;

	PLATFORM_LIBRARY
};

struct REContext
{
	REContextSettings* settings;

	PLATFORM_CONTEXT
};

struct REWindow
{
	REContext* context;
	REWindow* share;
	REWindowSettings* settings;
	DBool fullscreen;
	DBool running;

	PLATFORM_WINDOW
};

extern RELibrary relib;

REWindow* re_get_window(int index);
DBool re_init();
void re_terminate();

REWindow* re_create_window(REWindowSettings* settings, DBool fullscreen, REWindow* share);
void re_poll_events();
void re_free_window(REWindow* window);

void re_set_context_current(REWindow* window);
void re_swap_buffers(REWindow* window);

void re_get_monitor_size(int *width, int *height);
void re_set_key_callback(REKeyCallback callback);

int re_get_time_ms();
int re_get_time_frequency();