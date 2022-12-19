#pragma once
#include <glad/glad.h>

struct BufferObject
{
	int VertexArray, VertexBuffer, IndexBuffer;
	int IndicesSize;
};

BufferObject _make_buffer_object(float* vertices);