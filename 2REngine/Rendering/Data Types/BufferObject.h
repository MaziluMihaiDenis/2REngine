#pragma once

typedef struct DBufferObject DBufferObject;

struct DBufferObject
{
	unsigned int vertexArray, vertexBuffer, indexBuffer;
	unsigned int indicesSize;
	unsigned int* indices;
};

DBufferObject* _make_buffer_object(float* vertices, unsigned int vsize, unsigned int* indices, unsigned int isize);

// Set to 0 for unbind
void _bind_buffer_object(DBufferObject* obj);

void _free_buffer_object(DBufferObject* obj);