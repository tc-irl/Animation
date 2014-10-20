#include "Window.h"

Shader* tShader;
ObjectBuffer* buffer;
Init* initW;
Camera* fpsCam;


void Window::init()
{
	initW = new Init();

	fpsCam = new Camera(initW);

	string vs, ps;

	// Create 3 vertices that make up a triangle that fits on the viewport 
	GLfloat vertices[] = 
	{
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};
	// Create a color array that identifies the colors of each vertex (format R, G, B, A)
	GLfloat colors[] = 
	{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f
	};

	tShader = new Shader();

	tShader->CreateProgram();

	tShader->LoadFile("../diffuse.vs",vs);
	tShader->AddShader(tShader->GetProgramID(), vs.c_str(), GL_VERTEX_SHADER);
	tShader->LoadFile("../diffuse.ps",ps);
	tShader->AddShader(tShader->GetProgramID(), ps.c_str(), GL_FRAGMENT_SHADER);

	tShader->LinkProgram();
	tShader->ValidateProgram();
	tShader->UseProgram();


	buffer = new ObjectBuffer(36);
	buffer->GenerateVBO(vertices,colors);
	buffer->LinkBufferToShader(tShader->GetProgramID());
}

Window::Window()
{
	setUpWindow();
}


Window::~Window()
{
}

int Window::setUpWindow()
{
	
	init();

	do
	{

		glClearColor(0.0f,0.2f,0.2f,0.0f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (glfwGetKey( initW->GetWindow(), GLFW_KEY_F1 ) == GLFW_PRESS)
		{
			glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		}
		else if((glfwGetKey( initW->GetWindow(), GLFW_KEY_F2 ) == GLFW_PRESS))
		{
			glPolygonMode( GL_FRONT_AND_BACK, GL_FILL);
		}

		// Use our shader
		glUseProgram(tShader->GetProgramID());

		fpsCam->computeMatricesFromInputs();

		GLuint modelLoc = glGetUniformLocation(tShader->GetProgramID(), "model");
		GLuint viewLoc = glGetUniformLocation(tShader->GetProgramID(), "view");
		GLuint projLoc = glGetUniformLocation(tShader->GetProgramID(), "projection");

		fpsCam->handleMVP(modelLoc,viewLoc,projLoc);

	
		glBindVertexArray(buffer->GetVAO());
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

		glBindVertexArray(0);
		// Swap buffers
		initW->swapBuffers();
		glfwPollEvents();
		
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(initW->GetWindow(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		glfwWindowShouldClose(initW->GetWindow()) == 0 );
	
	buffer->DeleteVBO();
	tShader->DeleteProgram();
	buffer->DeleteVAO();
	tShader->DeleteShader();

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
