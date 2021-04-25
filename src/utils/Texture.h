#ifndef __TEXTURE_H__
#define __TEXTURE_H__

class Texture
{
public:
	Texture(const char* filename);
	~Texture();

	void bind();

	void setDefaultWrapping();
	void setMirroredWrapping();
	void setClampToEdge();

	void setDefaultFiltering();
	void setNearestFiltering();

private:
	unsigned int id_;

	int width_;
	int height_;
	int numChannels_;
};

#endif // !__TEXTURE_H__

