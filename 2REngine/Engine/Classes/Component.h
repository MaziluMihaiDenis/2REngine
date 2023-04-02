#pragma once
#include "Object.h"

class Component : public Object
{
protected:
	bool Updated;
public:
	bool Enabled;

	virtual void Loop(float deltaTime);
};