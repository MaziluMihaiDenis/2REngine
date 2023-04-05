#pragma once
#include "platform.h"
#include <Basic/core.h>

typedef struct REWindowSettings REWindowSettings;
typedef struct RELibrary RELibrary;
typedef struct REPlatform REPlatform;
typedef struct REWindow REWindow;
typedef struct REContext REContext;
typedef struct RESystem RESystem;
typedef struct REContextSettings REContextSettings;

typedef void(*REKeyCallback)(int, int);

struct REWindowSettings
{
	int offsetX, offsetY;
	int width, height;
	int style;
    DBool resizable;
    DBool focused;
    DBool maximized;
    DBool visible;
};

struct REContextSettings
{
	int minor, major, profile;
    DBool forward;
};

struct REPlatform
{
	DBool(*platform_init)();
	void(*platform_terminate)();
	DBool(*platform_create_window)(REWindow*, REWindowSettings*, REContextSettings*);
	void(*platform_poll_events)();
	void(*platform_free_window)(REWindow*);
	DBool(*platform_set_context_current)(REWindow*);
	void(*platform_swap_buffers)(REWindow*);
	void(*platform_destroy_context)(REWindow*);
	void(*platform_get_monitor_size)(int*, int*);
	int(*platform_get_time_ms)();
	int(*platform_get_time_frequency)();
};

struct RELibrary
{
	REPlatform* platform;
	REWindow** windows;
	REWindow* main_window;

	int windows_count;

	struct
	{
		REKeyCallback key;
	} callbacks;

	struct {
        struct {
            int redBits, greenBits, blueBits, alphaBits;
            int depthBits, stencilBits;
            int accumRedBits, accumGreenBits, accumBlueBits, accumAlphaBits;
            int auxBuffers;
            DBool stereo;
            DBool doubleBuffer;
            DBool transparent;
            int samples;
            DBool sRGB;
        } framebuffer;
	} hints;

	int attribList[30];

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
    char* name;

	int index;

	PLATFORM_WINDOW
};

extern RELibrary relib;

REWindow* re_get_main_window();
REWindow* re_get_window(int index);
DBool re_init();
void re_terminate();

REWindow* re_create_window(REWindowSettings* settings, const char* title, DBool fullscreen, REWindow* share);
void re_poll_events();
void re_free_window(REWindow* window);
int re_add_window_hints(int attrib, int value);
int re_get_hint(int attrib);

void re_set_context_current(REWindow* window);
void re_swap_buffers(REWindow* window);
void re_destroy_context(REWindow* window);

void re_get_monitor_size(int *width, int *height);
void re_set_key_callback(REKeyCallback callback);

int re_get_time_ms();
int re_get_time_frequency();