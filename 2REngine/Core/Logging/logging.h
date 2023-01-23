#pragma once
#include "../Data Types/dstring.h"
#include "../Data Types/dvector2D.h"
#include "../core.h"
#include <stdio.h>

///
/// REWORK NEEDED
/// 

#define DEBUG_LOG(x) _Generic((x), \
	float: _debug_log_float, double: _debug_log_float, \
	int: _debug_log_int, \
	DVector2D: _debug_log_vec2d, \
	DBool: _debug_log_bool, \
	DString: _debug_log_string, \
	default: _debug_log_text \
)(x)

#define RESET_PRINT_COLOR() printf("\033[0m")

#if !defined(__cplusplus)
#define LOG_ERROR(x) \
printf("\033[0;31m"), \
DEBUG_LOG(x),		   \
RESET_PRINT_COLOR()
#endif

#if !defined(__cplusplus)
#define LOG_WARNING(x) \
printf("\033[0;33m"), 	\
DEBUG_LOG(x),			 \
RESET_PRINT_COLOR()
#endif

void _debug_log_float(float f);

void _debug_log_int(int i);

void _debug_log_vec2d(DVector2D vec);

void _debug_log_bool(DBool boolean);

void _debug_log_string(DString str);

void _debug_log_text(const char* text);