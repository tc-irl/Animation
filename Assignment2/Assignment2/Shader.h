#ifndef SHADER_H
#define SHADER_H

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <gl/glew.h>
#include <glm/glm.hpp>
#include "Transform.h"
#include "ReferenceCounter.h"
#include "RenderingEngine.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "SpotLight.h"

struct TypedData
{
	std::string name;
	std::string type;
};

struct UniformStruct
{
	std::string name;
	std::vector<TypedData> memberNames;
};

class Shader
{
public:
	Shader(const std::string& fileName);
	virtual ~Shader();

	void Bind();
	//virtual void UpdateUniforms(const Transform& transform, const Material& material, RenderingEngine* renderingEngine);

	void SetUniformi(const std::string& uniformName, int value);
	void SetUniformf(const std::string& uniformName, float value);
	void SetUniformMatrix4f(const std::string& uniformName, const glm::mat4& value);
	void SetUniformVector3f(const std::string& uniformName, const glm::vec3& value);
	virtual void UpdateUniforms(const Transform& transform, RenderingEngine* renderingEngine);
	virtual void UpdateUniforms(const Transform& transform, const Material& material,RenderingEngine* renderingEngine);

protected:

private:
	static std::map<std::string, ShaderData*> resourceMap;

	ShaderData* shaderData;
	std::string fileName;

	void SetUniformDirectionalLight(const std::string& uniformName, const DirectionalLight& value);
	void SetUniformPointLight(const std::string& uniformName, const PointLight& value);
	void SetUniformSpotLight(const std::string& uniformName, const SpotLight& value);
};

class ShaderData : public ReferenceCounter
{
public:
	ShaderData(const std::string& fileName);
	virtual ~ShaderData();

	int GetProgram();
	std::vector<int>& GetShaders();
	std::vector<std::string>& GetUniformNames();
	std::vector<std::string>& GetUniformTypes();
	std::map<std::string, unsigned int>& GetUniformMap();

private:
	void AddVertexShader(const std::string& text);
	void AddGeometryShader(const std::string& text);
	void AddFragmentShader(const std::string& text);
	void AddProgram(const std::string& text, int type);

	void AddAllAttributes(const std::string& vertexShaderText);
	void AddShaderUniforms(const std::string& shaderText);
	void AddUniform(const std::string& uniformName, const std::string& uniformType, const std::vector<UniformStruct>& structs);
	void CompileShader();

	int program;
	std::vector<int> shaders;
	std::vector<std::string> uniformNames;
	std::vector<std::string> uniformTypes;
	std::map<std::string, unsigned int> uniformMap;
};

#endif