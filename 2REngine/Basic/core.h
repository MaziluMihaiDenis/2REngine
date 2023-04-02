#pragma once

#include <stdlib.h>

#define IS_TYPE_OF(x, type) _Generic((x), type : 1, default : 0)

#define MALLOC(ptr, size) ((ptr = mem_alloc(size, #ptr)) != NULL)	
#define FREE(ptr) mem_free(ptr, #ptr)

#define DEBUG_MODE_ENABLED 0

#define TRUE 1
#define FALSE 0

typedef unsigned short DBool;

void* mem_alloc(size_t size, const char* name);
void mem_free(void* ptr, const char* name);