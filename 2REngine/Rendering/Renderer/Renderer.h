#pragma once

#include "../../Core/Engine/Classes/Component/DisplayComponent.h"
#include <vector>

class Renderer
{
	friend class Engine;
private:
	static inline Renderer* Instance;
	std::vector<DisplayComponent*> RegisteredObjects;
private:
	void RenderLoop();
public:
	void RegisterDisplayObject(DisplayComponent* object);
	void UnregisterDisplayObject(DisplayComponent* object);
	static Renderer* GetInstance();
};
