#pragma once;
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string> 
#include <fstream>
#include <iostream>
#include <sstream>

// Macro for indexing vertex buffer
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

using namespace std;

class ObjectBuffer
{
public:
	ObjectBuffer();
	ObjectBuffer(GLuint numVertices);
	~ObjectBuffer();

	GLuint GenerateVBO(GLfloat vertices[], GLfloat colors[]);
	void LinkBufferToShader(GLuint shaderProgramID);
	GLuint GetVBO();
	GLuint GetVAO();
	void DeleteVBO();
	void DeleteVAO();


private:
	GLuint VBO,VAO;
	glm::mat3 vertices;
	glm::mat4 colors;
	GLuint numVertices;
};

