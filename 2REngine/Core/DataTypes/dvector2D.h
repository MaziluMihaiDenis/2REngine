#pragma once

#include <math.h>

#define MAKE_VEC(X, Y) (DVector2D){(X), (Y)}

#define VFSUM(V1, F1) _vector_add_float(V1, F1)
#define VFDIF(V1, F1) _vector_subtract_float(V1, F1)
#define VFPROD(V1, F1) _vector_multiply_float(V1, F1)
#define VFDIV(V1, F1) _vector_divide_float(V1, F1)

#define VVSUM(V1, V2) _vector_add_vector(V1, V2)
#define VVDIF(V1, V2) _vector_subtract_vector(V1, V2)
#define VVPROD(V1, V2) vector_dot_product(V1, V2)

#define PI 3.14159265359
#define DEG2RAD PI / 180
#define RAD2DEG 180 / PI

typedef struct DVector2D DVector2D;

struct DVector2D
{
	float x, y;
};

/*
	distance from v1 to v2 squared
	faster than vector_distance_to
*/
float vector_distance_to_squared(DVector2D v1, DVector2D v2);
/*
	distance from v1 to v2
	slower than vector_distance_to_squared
	more accurate than vector_distance_to_squared
*/
float vector_distance_to(DVector2D v1, DVector2D v2);
/*
	returns the magnitude of v1
*/
float vector_length(DVector2D v1);
/*
	returns angle from v1 to v2 (radians)
*/
float vector_angle_to(DVector2D v1, DVector2D v2);
/*
	returns sum of the 2 vectors
	v1 + v2
*/
DVector2D _vector_add_vector(DVector2D v1, DVector2D v2);
/*
	returns difference between the 2 vectors
	v1 - v2
*/
DVector2D _vector_subtract_vector(DVector2D v1, DVector2D v2);
/*
	returns sum of the 2 vectors
*/
float vector_dot_product(DVector2D v1, DVector2D v2);
/*
	returns sum of the 2 vectors
*/
DVector2D _vector_div_vector(DVector2D v1, DVector2D v2);
/*
	returns sum of the vector and scalar
	v1 + (f, f)
*/
DVector2D _vector_add_float(DVector2D v1, float f);
/*
	returns difference between the vector and scalar
	v1 - (f, f)
*/
DVector2D _vector_subtract_float(DVector2D v1, float f);
/*
	returns product of the vector and scalar
	v1 * f
*/
DVector2D _vector_multiply_float(DVector2D v1, float f);
/*
	returns quotient of the vector and scalar
	v1 * f
*/
DVector2D _vector_divide_float(DVector2D v1, float f);