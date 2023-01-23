#pragma once

typedef unsigned short DBool;

#define TRUE 1
#define FALSE 0

#define IS_TYPE_OF(x, type) _Generic((x), type : 1, default : 0)

#define DEBUG_MODE_ENABLED 1

#define MALLOC(ptr, size) ((ptr = mem_alloc(size, #ptr)) != NULL)	
#define FREE(ptr) mem_free(ptr, #ptr)

void* mem_alloc(size_t size, const char* name);
void mem_free(void* ptr, const char* name);