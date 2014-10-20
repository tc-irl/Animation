#include "ObjectBuffer.h"

ObjectBuffer::ObjectBuffer()
{
	
}

ObjectBuffer::ObjectBuffer(GLuint numVertices)
{
	this->numVertices = numVertices;
}


GLuint ObjectBuffer::GenerateVBO(GLfloat vertices[], GLfloat colors[])
{
	glGenVertexArrays(1,&VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	// In OpenGL, we bind (make active) the handle to a target name and then execute commands on that target
	// Buffer will contain an array of vertices 
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// After binding, we now fill our object with data, everything in "Vertices" goes to the GPU
	glBufferData(GL_ARRAY_BUFFER, numVertices*6*sizeof(GLfloat), NULL, GL_STATIC_DRAW);

	// if you have more data besides vertices (e.g., vertex colors or normals), use glBufferSubData to tell the buffer when the vertices array ends and when the colors start
	glBufferSubData (GL_ARRAY_BUFFER, 0, numVertices*3*sizeof(GLfloat), vertices);
	glBufferSubData (GL_ARRAY_BUFFER, numVertices*3*sizeof(GLfloat), numVertices*3*sizeof(GLfloat), colors);

	return VBO;
}

void ObjectBuffer::LinkBufferToShader(GLuint shaderProgramID)
{
	// find the location of the variables that we will be using in the shader program
	GLuint positionID = glGetAttribLocation(shaderProgramID, "vPosition");
	GLuint colorID = glGetAttribLocation(shaderProgramID, "vColor");

	// Have to enable this
	glEnableVertexAttribArray(positionID);
	// Tell it where to find the position data in the currently active buffer (at index positionID)
	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	// Similarly, for the color data.
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(numVertices*3*sizeof(GLfloat)));

	glBindVertexArray(0); // unbind vao

}

GLuint ObjectBuffer::GetVBO()
{
	return VBO;
}

GLuint ObjectBuffer::GetVAO()
{
	return VAO;
}

void ObjectBuffer::DeleteVAO()
{
	glDeleteVertexArrays(1,&VAO);
}

void ObjectBuffer::DeleteVBO()
{
	glDeleteBuffers(1,&VBO);
}


