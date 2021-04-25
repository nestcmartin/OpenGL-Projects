#ifndef __INPUT_H__
#define __INPUT_H__

struct GLFWwindow;

class Input
{
public:
	static void Init();
	static void Release();
	
	static void Update(float deltaTime);

	static bool IsKeyDown(int key);
	static bool IsKeyUp(int key);

	static void GetMousePosition(double& x, double& y);
	static void GetMouseOffset(double& x, double& y);
	static double GetMouseWheel();

private:
	static GLFWwindow* window;
};

#endif // !__INPUT_H__