#pragma once

typedef struct win32Library win32Library;
typedef struct win32Window win32Window;
typedef struct win32Context win32Context;

#define WIN32_LIBRARY win32Library win32;
#define WIN32_WINDOW win32Window* win32;
#define WIN32_CONTEXT win32Context* win32;

#include "../../core.h"

#include <Windows.h>

struct win32Library
{
	HINSTANCE instance;
	HDC deviceContext;
};

struct win32Window
{
	HWND windowHandle;
};

struct win32Context
{
	HGLRC hglrc;
};

void _win32_connect();
void _win32_terminate();
DBool _win32_init();

void _win32_poll_events();
DBool win32_create_window(struct REWindow* window, struct REWindowSettings* windowSettings);
DBool _win32_create_window_instance(struct REWindow* window, struct REWindowSettings* windowSettings);
void _win32_free_window(struct REWindow* window);

DBool _win32_create_context(struct REWindow* window, struct REContextSettings* settings);
DBool win32_make_context_current(struct REWindow* window);
DBool _win32_init_gl();

DBool _choose_pixel_format(struct REWindow* window, struct REContextSettings* settings);
DBool _wgl_choose_pixel_format(struct REWindow* window, struct REContextSettings* settings);
DBool _win32_choose_pixel_format(struct REWindow* window, struct REContextSettings* settings);
void _win32_swap_buffers(struct REWindow* window);