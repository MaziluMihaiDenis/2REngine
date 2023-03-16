#pragma once

#include "../../Core/Engine/Classes/Component/DisplayObject.h"
#include <vector>

class Renderer
{
private:
	std::vector<DisplayObject*> RegisteredObjects;
private:
	void RenderLoop();
public:
	void RegisterDisplayObject(DisplayObject* object);
	void UnregisterDisplayObject(DisplayObject* object);
};
