#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Shader.h"
#include "ObjectBuffer.h"
#include "Init.h"
#include "Camera.h"
#include "Bone.h"
#include "Skeleton.h"
#include "cylinder.h"
#include "maths_funcs.h"
#define MAX 16

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
	glm::mat4 currentTransform;
};

