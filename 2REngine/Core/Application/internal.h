#pragma once
#include "../Structs/dstring.h"
#include "../Structs/dvector2D.h"
#include "../Debug/logging.h"
#include "platform.h"

typedef struct REWindowSettings REWindowSettings;
typedef struct RELibrary RELibrary;
typedef struct REPlatform REPlatform;
typedef struct REWindow REWindow;
typedef struct REContextSettings REContextSettings;
typedef struct REContext REContext;
typedef struct RESystem RESystem;

struct REWindowSettings
{
	DString name;
	DVector2D pos;
	DVector2D size;
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
};

struct RELibrary
{
	REPlatform* platform;
	RESystem system;
	REWindow** windows;

	int windows_count;

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