#pragma once
#include "../DataTypes/dstring.h"
#include "../DataTypes/dvector2D.h"
#include "../Core/core.h"

#define DEBUG_LOG(x) _Generic((x), \
	float: _debug_log_float, double: _debug_log_float, \
	int: _debug_log_int, \
	DVector2D: _debug_log_vec2d, \
	DBool: _debug_log_bool, \
	DString: _debug_log_string, \
	default: _debug_log_text \
)(x)

void _debug_log_float(float f);

void _debug_log_int(int i);

void _debug_log_vec2d(DVector2D vec);

void _debug_log_bool(DBool boolean);

void _debug_log_string(DString str);

void _debug_log_text(const char* text);