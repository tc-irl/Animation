#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
class Init
{
public:
	Init();
	~Init(void);
	int setUpGL();
	GLFWwindow* GetWindow();
	GLFWwindow *window;
	void swapBuffers();
};

