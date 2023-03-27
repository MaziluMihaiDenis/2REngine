#pragma once

#define SWAP(X, Y) AUX = X; X = Y; Y = AUX;

/*
template<typename T>
float dot_product(T* vec1, T* vec2, int length)
{
	float res = 0.0f;
	for (int i = 0; i < length; i++)
		res += vec1[i] * vec2[i];
	return res;
}
*/
inline int get_number_size(long long value)
{
	int size;
	size = 0;

	if (value < 0)
		size++;

	while (value)
		value /= 10, size++;
	return size;
}

