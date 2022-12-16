#pragma once
#include <corecrt_malloc.h>

typedef unsigned short DBool;

#define TRUE 1
#define FALSE 0

#define MALLOC(ptr, size) ((ptr = malloc(size)) != NULL)
#define FREE(ptr) free(ptr); ptr = NULL

#define IS_TYPE_OF(x, type) _Generic((x), type : 1, default : 0)


