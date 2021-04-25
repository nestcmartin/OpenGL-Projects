#ifndef __VERTEX_BUFFER_H__
#define __VERTEX_BUFFER_H__

class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	void load(const float* vertices);
	void bind() const;

private:
	unsigned int VBO;
};

#endif // !__VERTEX_BUFFER_H__