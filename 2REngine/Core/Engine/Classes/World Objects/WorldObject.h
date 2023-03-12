#pragma once

#include "EmptyWorldObject.h"
#include "../../../Types/Transformation2D.h"

class WorldObject : public EmptyWorldObject
{
public:
	Transformation2D transformation;
};

