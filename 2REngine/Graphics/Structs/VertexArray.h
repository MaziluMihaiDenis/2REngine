#pragma once

struct VertexArray
{
	friend class DisplayComponent;
private:
	unsigned int VA_ID, VB_ID, IB_ID;
	unsigned int IndicesSize;
	unsigned int* Indices;
public:
	VertexArray(float* vertices, unsigned int vsize, unsigned int* indices, unsigned int isize);
	~VertexArray();
	void Bind();
	void Unbind();
};