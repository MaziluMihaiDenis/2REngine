#pragma once

#define NOTHING int __unused;

#if defined(_WIN32)
#include "win32/win32_core.h"
#else
#define WIN32_LIBRARY 
#define WIN32_WINDOW
#define WIN32_CONTEXT
#endif

#define PLATFORM_LIBRARY \
			WIN32_LIBRARY \
			NOTHING

#define PLATFORM_WINDOW \
			WIN32_WINDOW \
			NOTHING

#define PLATFORM_CONTEXT \
			WIN32_CONTEXT \
			NOTHING		   
