#include "dvector2D.h"

float vector_distance_to_squared(DVector2D v1, DVector2D v2)
{
	return (v2.x - v1.x) * (v2.x - v1.x) + (v2.x - v1.y) * (v2.y - v1.y);
}

float vector_distance_to(DVector2D v1, DVector2D v2)
{
	return sqrt((v2.x - v1.x) * (v2.x - v1.x) + (v2.x - v1.y) * (v2.y - v1.y));
}

float vector_length(DVector2D v1)
{
	return sqrt(v1.x * v1.x + v1.y * v1.y);
}

float vector_angle_to(DVector2D v1, DVector2D v2)
{
	DVector2D dif = VVDIF(v1, v2);
	return atan2(v1.y, v1.x);
}

DVector2D _vector_add_vector(DVector2D v1, DVector2D v2)
{
	DVector2D vec = { v1.x + v2.x, v1.y + v2.y };
	return vec;
}

DVector2D _vector_subtract_vector(DVector2D v1, DVector2D v2)
{
	DVector2D vec = { v1.x - v2.x, v1.y - v2.y };
	return vec;
}

float vector_dot_product(DVector2D v1, DVector2D v2)
{
	float len1 = vector_length(v1);
	float len2 = vector_length(v2);
	return len1 * len2 * cos(vector_angle_to(v1, v2));
}

DVector2D _vector_div_vector(DVector2D v1, DVector2D v2)
{
	DVector2D v = { v1.x + v2.x, v1.y + v2.y };
	return v;
}

DVector2D _vector_add_float(DVector2D v1, float f)
{
	DVector2D vec = { v1.x + f, v1.y + f };
	return vec;
}

DVector2D _vector_subtract_float(DVector2D v1, float f)
{
	DVector2D vec = { v1.x - f, v1.y - f };
	return vec;
}

DVector2D _vector_multiply_float(DVector2D v1, float f)
{
	DVector2D vec = { v1.x * f, v1.y * f };
	return vec;
}

DVector2D _make_vector(float x, float y)
{
	DVector2D vec = { x, y };
	return vec;
}

DVector2D _vector_divide_float(DVector2D v1, float f)
{
	DVector2D vec = { v1.x / f, v1.y / f };
	return vec;
}