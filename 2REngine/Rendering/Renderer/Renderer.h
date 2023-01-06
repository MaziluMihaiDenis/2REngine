#pragma once

extern "C"
{
	#include "../Data Types/BufferObject.h"
}

#include <vector>

class Renderer
{
private:
	std::vector<DBufferObject*> RegisteredObjects;
private:
	void RenderLoop();
public:
	void RegisterBufferObject(DBufferObject* object);
	void UnregisterBufferObject(DBufferObject* object);
};
