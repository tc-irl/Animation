#pragma once

#ifndef Shader_h
#define Shader_h

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string> 
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Shader
{
public:
	
	Shader();

	bool LoadFile(const string& fileName, string& outShader);
	void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType);

	void DeleteShader();

	void CreateProgram();
	bool LinkProgram();
	void UseProgram();
	void DeleteProgram();
	void ValidateProgram();


	GLuint GetProgramID();
	GLuint GetShaderID();

private:
		GLint success;
		GLuint numVertices;
		GLchar errorLog[1024], infoLog[1024];

		GLuint shaderProgramID, shaderObj;

};

#endif