#pragma once

#define SWAP(X, Y) AUX = X; X = Y; Y = AUX;
#define PI 3.14159265359

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

inline float* ortho(float left, float bottom, float right, float top)
{
	float *proj;
	proj = new float[16];
	for (int i = 0; i < 16; i++)
		proj[i] = 0.f;

	proj[4 * 0 + 0] = 2 / (right - left);
	proj[4 * 1 + 1] = 2 / (top - bottom);
	proj[4 * 2 + 2] = -1.f;
	proj[4 * 3 + 3] = 1.f;

	/*lrd = right - left;
	lrs = right + left;
	btd = top - bottom;
	bts = top + bottom;

	proj[4 * 3 + 0] = lrs / lrd;
	proj[4 * 3 + 1] = bts / btd;

	proj[4 * 0 + 0] = 2 / lrd;
	proj[4 * 1 + 1] = 2 / btd;*/

	return proj;
}

inline double degrees_to_radian(double degrees)
{
	return degrees * PI / 180.0;
}

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

