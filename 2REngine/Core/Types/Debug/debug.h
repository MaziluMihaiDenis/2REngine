#pragma once
#include <stdio.h>

#define PRINT(SEVERITY, TYPES, ...) \
		if(SEVERITY == -1) \
			printf(""); \
		else if(SEVERITY == 1) \
			printf(""); \
		printf(TYPES "\n", __VA_ARGS__)