#include "Window.h"

Shader* tShader;
//ObjectBuffer* buffer;
Init* initW;
Camera* fpsCam;

Skeleton* skeleton;

void Window::init()
{
	initW = new Init();

	fpsCam = new Camera(initW);
	
	string vs, ps;

	tShader = new Shader();

	tShader->CreateProgram();

	tShader->LoadFile("../diffuse.vs",vs);
	tShader->AddShader(tShader->GetProgramID(), vs.c_str(), GL_VERTEX_SHADER);
	tShader->LoadFile("../diffuse.ps",ps);
	tShader->AddShader(tShader->GetProgramID(), ps.c_str(), GL_FRAGMENT_SHADER);

	tShader->LinkProgram();
	tShader->ValidateProgram();
	tShader->UseProgram();

	skeleton = new Skeleton(MAX);
	skeleton->setUpBones();


	//buffer = new ObjectBuffer(36);
	//buffer->GenerateVBO(vertices,colors);
	//buffer->LinkBufferToShader(tShader->GetProgramID());
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

		fpsCam->getProjectionMatrix();
		fpsCam->getViewMatrix();

		skeleton->animateHand(modelLoc);

		initW->swapBuffers();
		glfwPollEvents();
		
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(initW->GetWindow(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		glfwWindowShouldClose(initW->GetWindow()) == 0 );
	
	//buffer->DeleteVBO();
	tShader->DeleteProgram();
	//buffer->DeleteVAO();
	tShader->DeleteShader();

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}