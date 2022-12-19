#pragma once

typedef struct DBufferObject DBufferObject;

struct DBufferObject
{
	unsigned int VertexArray, VertexBuffer, IndexBuffer;
	unsigned int IndicesSize;
};

DBufferObject _make_buffer_object(float* vertices, unsigned int vsize, unsigned int* indices, int isize);
void _bind_buffer_object(DBufferObject obj);