#pragma once

typedef struct win32Library win32Library;
typedef struct win32Window win32Window;

#define WIN32_LIBRARY win32Library* platform;
#define WIN32_WINDOW win32Window* platform;

#include <Windows.h>
#include "../re_core.h"

struct win32Library
{
	HINSTANCE instance;
};

struct win32Window
{
	HWND windowHandle;
};

DBool win32_init();
win32Window* win32_create_window(REWindowSettings* windowSettings);