#include "basic_num_func.h"

int get_number_size(long long value)
{
	int size;
	size = 0;

	if (value < 0)
		size++;

	while (value)
		value /= 10, size++;
	return size;
}