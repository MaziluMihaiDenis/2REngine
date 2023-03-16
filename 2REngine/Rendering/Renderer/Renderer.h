#pragma once

extern "C"
{
	#include "../Data Types/BufferObject.h"
}

#include <vector>

class Renderer
{
private:
	std::vector<BufferObject*> RegisteredObjects;
private:
	void RenderLoop();
public:
	void RegisterBufferObject(BufferObject* object);
	void UnregisterBufferObject(BufferObject* object);
};
