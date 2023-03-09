#pragma once

#include <vector>

#include "Component.h"

typedef const char* ClassName;

class Object
{
public:
	virtual void Start();
	virtual void Loop(float deltaTime);
	virtual void Destroy(float time = 0.f);

public:
	ClassName GetClassName();
};

