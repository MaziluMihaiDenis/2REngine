#pragma once

#include "Vector2D.h"

struct Transformation2D
{
	Vector2D Position, Size, RelativePosition, RelativeSize;
	float Rotation, RelativeRotation;
};

