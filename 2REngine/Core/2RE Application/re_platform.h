#pragma once

#if defined(_WIN32)
#include "win32/win32_2re_platform.h"
#else
#define WIN32_LIBRARY 
#define WIN32_WINDOW
#endif

#define PLATFORM_LIBRARY WIN32_LIBRARY 
#define PLATFORM_WINDOW WIN32_WINDOW 
