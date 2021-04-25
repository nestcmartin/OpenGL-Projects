#ifndef __PLATFORM_H__
#define __PLATFORM_H__

struct GLFWwindow;

class Platform
{
public:
	static void Init();
	static void Release();

	inline static GLFWwindow* GetWindow() { return Window; }

	static void SetWindowShouldClose(bool close);
	static bool GetWindowShouldClose();
	static float GetTime();

private:
	static const int GL_VERSION_MAJOR = 3;
	static const int GL_VERSION_MINOR = 3;
	static const int WINDOW_WIDTH = 800;
	static const int WINDOW_HEIGHT = 600;

	static GLFWwindow* Window;
};

#endif // !__PLATFORM_H__

