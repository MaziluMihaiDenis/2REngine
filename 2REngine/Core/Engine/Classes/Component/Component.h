#pragma once
#include "../Object.h"

class Component : public Object
{
public:
	bool Enabled;

	virtual void Loop(float deltaTime);
};