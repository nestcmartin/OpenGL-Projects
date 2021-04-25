#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void bind() const;

	inline unsigned int getVAO() const { return VAO; }

private:
	unsigned int VAO;
};

#endif // !__VERTEX_ARRAY_H__