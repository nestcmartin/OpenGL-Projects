#ifndef __INDEX_BUFFER_H__
#define __INDEX_BUFFER_H__

class IndexBuffer
{
public:
	IndexBuffer();
	~IndexBuffer();

	void load(const unsigned int* indices, unsigned int count);
	void bind() const;

	inline unsigned int count() const { return count_; }

private:
	unsigned int EBO;
	unsigned int count_;
};

#endif // !__INDEX_BUFFER_H__