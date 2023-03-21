#pragma once
#include <stdio.h>

#define SV_ERROR -1
#define SV_WARNING 1
#define SV_DEFAULT 0

#define PRINT(SEVERITY, TYPES, ...) \
		if(SEVERITY == -1) \
			printf("\x1b[31m"); \
		else if(SEVERITY == 1) \
			printf("\x1b[33m"); \
		printf(TYPES "\n\x1b[0m", __VA_ARGS__)