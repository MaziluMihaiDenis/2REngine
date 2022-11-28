#pragma once

#define NOTHING int platform;

#if defined(_WIN32)
#include "win32/win32_re_core.h"
#else
#define WIN32_LIBRARY 
#define WIN32_WINDOW
#endif

#define PLATFORM_LIBRARY \
			WIN32_LIBRARY \
			NOTHING
#define PLATFORM_WINDOW \
			WIN32_WINDOW \
			NOTHING
