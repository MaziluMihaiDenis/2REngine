#pragma once

typedef struct win32Library win32Library;
typedef struct win32Window win32Window;

#define WIN32_LIBRARY win32Library* win32;
#define WIN32_WINDOW win32Window* win32;

#include "../../core.h"

#include <Windows.h>

struct win32Library
{
	HINSTANCE instance;
};

struct win32Window
{
	HWND windowHandle;
};

DBool win32_init();
win32Window* win32_create_window(struct REWindow* window, struct REWindowSettings* windowSettings);
void win32_free_window(struct REWindow* window);