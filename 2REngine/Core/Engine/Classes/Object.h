#pragma once

#include <vector>

#define NAME_OF_CLASS(T) typeid(T).name()

class Object
{
public:
	virtual void Start();
	virtual void Loop(float deltaTime);
	virtual void Destroy(float time = 0.f);
};

