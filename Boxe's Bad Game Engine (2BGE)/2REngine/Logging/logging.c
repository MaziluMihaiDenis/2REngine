#include "logging.h"
#include <stdio.h>

void _debug_log_float(float f)
{
	_debug_log_string(decimal_to_string(f));
}

void _debug_log_int(int i)
{
	_debug_log_string(int_to_string(i));
}

void _debug_log_vec2d(DVector2D vec)
{
	_debug_log_string(vector2D_to_string(vec));
}

void _debug_log_bool(DBool boolean)
{
	_debug_log_string(bool_to_string(boolean));
}

void _debug_log_string(DString str)
{
	_debug_log_text(str.text);
}

void _debug_log_text(const char* text)
{
	printf("%s", text);
}
