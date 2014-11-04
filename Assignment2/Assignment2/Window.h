#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
#include <gl/glew.h>

using namespace std;

class Window
{
public:
	Window(void);
	virtual ~Window(void);

	int createWindow(int width, int height, string title);
	bool IsClosed();
	void Update();
	void Clear(float r, float g, float b, float a);

private:
	int width,height;
	char title [50];
	GLFWwindow *window;
	bool isClosed;
};

