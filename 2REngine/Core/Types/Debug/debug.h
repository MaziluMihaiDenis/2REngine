#pragma once
#include <stdio.h>

enum ESEVERITY
{
	DEFAULT,
	WARN,
	ERR
};

#define PRINT(SEVERITY, TYPES, ...) \
		if(SEVERITY == ESEVERITY::ERR) \
			printf(""); \
		else if(SEVERITY == ESEVERITY::WARN) \
			printf(""); \
		printf(TYPES "", __VA_ARGS__)