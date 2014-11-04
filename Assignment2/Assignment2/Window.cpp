#include "Window.h"


Window::Window(void)
{
	isClosed = false;
}


Window::~Window(void)
{
	glfwDestroyWindow(window);
}

int Window::createWindow(int width, int height, string title)
{
	this->width = width;
	this->height = height;

	strcpy(this->title,title.c_str());

	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(width, height, this->title, NULL, NULL);

	if( window == NULL ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_CURSOR,GLFW_CURSOR_DISABLED);
	glfwSetCursorPos(window, 1024/2, 768/2);

}

void Window::Update()
{
	glfwSwapBuffers(window);

	if (glfwGetKey( window, GLFW_KEY_F1 ) == GLFW_PRESS)
	{
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	}
	else if((glfwGetKey( window, GLFW_KEY_F2 ) == GLFW_PRESS))
	{
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL);
	}
	
	if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS && glfwWindowShouldClose(window) == 0)
	{
		isClosed = true;
	}
}

bool Window::IsClosed()
{
	return isClosed;
}

