#ifndef __RENDERER_H__
#define __RENDERER_H__

struct GLFWwindow;
class Shader;

struct RenderData
{
	unsigned int vao = 0;
	unsigned int count = 0;
	Shader* shader = nullptr;
};

class Renderer
{
public:
	static void Init();
	static void Release();

	// Draw Functions
	static void Clear();
	static void Draw(unsigned int vao, unsigned int count, unsigned int shader);
	static void Present();

	// Render Options
	static void EnableWireframeMode();
	static void DisableWireframeMode();
	static RenderData* GetRenderData(const float* vertices, unsigned int verts, const unsigned int* layout, 
		unsigned int attrs, const unsigned int* indices, unsigned int elems, const char* shader);

	// Viewport Functions
	static void UpdateViewport(int x, int y, int w, int h);
	inline static const int GetViewportWidth() { return ViewportWidth; }
	inline static const int GetViewportHeight() { return ViewportHeight; }
	inline static const int GetViewportX() { return ViewportX; }
	inline static const int GetViewportY() { return ViewportY; }
	
private:
	static int ViewportX;
	static int ViewportY;
	static int ViewportWidth;
	static int ViewportHeight;

	static GLFWwindow* window;
};

#endif // !__RENDERER_H__