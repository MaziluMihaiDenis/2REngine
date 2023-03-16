#pragma once

typedef struct BufferObject BufferObject;

struct BufferObject
{
	unsigned int vertexArray, vertexBuffer, indexBuffer;
	unsigned int indicesSize;
	unsigned int* indices;
};

BufferObject* _make_buffer_object(float* vertices, unsigned int vsize, unsigned int* indices, unsigned int isize);

// Set to 0 for unbind
void _bind_buffer_object(BufferObject* obj);
void _free_buffer_object(BufferObject* obj);