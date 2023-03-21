#pragma once

struct VertexArray
{
private:
	unsigned int VA_ID, VB_ID, IB_ID;
	unsigned int IndicesSize;
	unsigned int* Indices;
public:
	VertexArray(float* vertices, unsigned int vsize, unsigned int* indices, unsigned int isize);
	void Bind();
	void Unbind();
};