#pragma once

typedef struct win32Library win32Library;
typedef struct win32Window win32Window;
typedef struct win32Context win32Context;

#define WIN32_LIBRARY win32Library win32;
#define WIN32_WINDOW win32Window* win32;
#define WIN32_CONTEXT win32Context* win32;

#include <Basic/core.h>
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
void _win32_process_input(UINT Msg);

DBool _win32_create_window(struct REWindow* window, struct REWindowSettings* winSet, struct REContextSettings* ctxSet);
DBool _win32_create_window_instance(struct REWindow* window, struct REWindowSettings* windowSettings);
void _win32_free_window(struct REWindow* window);

DBool _win32_create_context(struct REWindow* window, struct REContextSettings* settings);
DBool _win32_set_context_current(struct REWindow* window);
DBool _win32_init_gl();
void _win32_destroy_context(struct REWindow* window);

DBool _wgl_choose_pixel_format(struct REWindow* window);
DBool _choose_pixel_format(struct REWindow* window);
void _win32_swap_buffers(struct REWindow* window);

void _win32_get_monitor_size(int* width, int* height);

int _win32_init_time();
int _win32_get_current_time_ms();
int _win32_get_time_frequency();