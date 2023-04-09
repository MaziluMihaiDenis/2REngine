#pragma once

#include <stdlib.h>
#include <stdio.h>

#define IS_TYPE_OF(x, type) _Generic((x), type : 1, default : 0)

#define MALLOC(ptr, size, TYPE) \
{ \
	if(DEBUG_MODE_ENABLED) \
		printf("ALLOCATING %d BYTES TO %s\n", size * sizeof(TYPE), #ptr); \
	ptr = (TYPE*)malloc(size * sizeof(TYPE)); \
}
#define FREE(ptr, size, TYPE) \
{ \
	if(ptr == NULL) \
		return; \
	if (DEBUG_MODE_ENABLED) \
		printf("DEALLOCATING %d BYTES FROM %s\n", size * sizeof(TYPE), #ptr); \
	free(ptr); \
	ptr = NULL; \
}
#define NAME(y) #y

#define DEBUG_MODE_ENABLED 0

#define TRUE 1
#define FALSE 0

typedef unsigned short DBool;