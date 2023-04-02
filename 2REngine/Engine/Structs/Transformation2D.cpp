#include "Transformation2D.h"
#include <cmath>
#include <stdio.h>

float* Transformation2D::GetMatrix()
{
	float* matrix, radians;
	radians = DEG2RAD * Rotation;
	matrix = new float[16];
	for (int i = 0; i < 16; i++)
		matrix[i] = 0.f;
	matrix[4 * 3 + 3] = 1.f;

	// x rotation
	matrix[0] = Size.x * cos(radians);
	matrix[1] = Size.x * sin(radians);

	// y rotation
	matrix[4 * 1 + 0] = Size.y * -sin(radians);
	matrix[4 * 1 + 1] = Size.y * cos(radians);

	// translation
	matrix[4 * 3 + 0] = Position.x * (cos(radians) - sin(radians));
	matrix[4 * 3 + 1] = Position.y * (sin(radians) + cos(radians));

	return matrix;
}
