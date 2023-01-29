#pragma once
#include "core.h"

#if defined(_WIN32)
#include <Windows.h>
typedef wchar_t widech;
#else
typedef char widech;
#endif 

#define MAKE_STR(T) _make_string(T)

typedef struct DString DString;

struct DString
{
	char* text;
	unsigned int size;
};

// converts a bool to a string
DString bool_to_string(DBool value);

// converts an int to a string
DString int_to_string(long long value);

// converts a float to a string
DString decimal_to_string(float value);

// makes a string from text
DString vector2D_to_string(struct DVector2D vector);

DString _make_string(const char* str);

// appends a string 
DString string_append(const char* to_append, const char* string);

int string_length(const char* string);

// frees the memory used by the string and its member variables
void string_free(DString* str);

// converts a char string to a wchar_t string
const widech* char_to_wide(DString string);

