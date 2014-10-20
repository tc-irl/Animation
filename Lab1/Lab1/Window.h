#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include "ObjectBuffer.h"
#include "Init.h"
#include "Camera.h"

// Macro for indexing vertex buffer
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using namespace std;
class Window
{
public:
	Window();
	~Window(void);
	void init();
	int setUpWindow();

};

