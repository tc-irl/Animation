#include "Shader.h"

static void CheckShaderError(int shader, int flag, bool isProgram, const std::string& errorMessage);
static std::vector<UniformStruct> FindUniformStructs(const std::string& shaderText);
static std::string FindUniformStructName(const std::string& structStartToOpeningBrace);
static std::vector<TypedData> FindUniformStructComponents(const std::string& openingBraceToClosingBrace);
static std::string LoadShader(const std::string& fileName);


Shader::Shader(const std::string& fileName)
{
	this->fileName = fileName;

	std::map<std::string, ShaderData*>::const_iterator it = resourceMap.find(fileName);
	
	if(it != resourceMap.end())
	{
		shaderData = it->second;
		shaderData->AddReference();
	}
	else
	{
		shaderData = new ShaderData(fileName);
		resourceMap.insert(std::pair<std::string, ShaderData*>(fileName, shaderData));
	}
}


Shader::~Shader(void)
{
	if(shaderData && shaderData->RemoveReference())
	{
		if(fileName.length() > 0)
			resourceMap.erase(fileName);

		delete shaderData;
	}
}

void Shader::Bind()
{
	glUseProgram(shaderData->GetProgram());
}

void Shader::SetUniformDirectionalLight(const std::string& uniformName, const DirectionalLight& value)
{

}

void Shader::SetUniformPointLight(const std::string& uniformName, const PointLight& value)
{

}

void Shader::SetUniformSpotLight(const std::string& uniformName, const SpotLight& value)
{

}

void Shader::UpdateUniforms(const Transform& transform, RenderingEngine* renderingEngine)
{
	glm::mat4 worldMatrix = transform.GetTransformation();
	glm::mat4 projectedMatrix = renderingEngine->GetMainCamera().GetViewProjection() * worldMatrix;

	for(unsigned int i = 0; i < shaderData->GetUniformNames().size(); i++)
	{
		std::string uniformName = shaderData->GetUniformNames()[i];
		std::string uniformType = shaderData->GetUniformTypes()[i];

		if(uniformType == "sampler2D")
		{
			int samplerSlot = renderingEngine->GetSamplerSlot(uniformName);
			//material.GetTexture(uniformName)->Bind(samplerSlot);
			SetUniformi(uniformName, samplerSlot);
		}
		else if(uniformName.substr(0, 2) == "T_")
		{
			if(uniformName == "T_MVP")
			{
				SetUniformMatrix4f(uniformName, projectedMatrix);
			}

			else if(uniformName == "T_model")
				SetUniformMatrix4f(uniformName, worldMatrix);
			else
				throw "Invalid Transform Uniform: " + uniformName;
		}
		else if(uniformName.substr(0, 2) == "R_")
		{
			std::string unprefixedName = uniformName.substr(2, uniformName.length());

			if(uniformType == "vec3")
				SetUniformVector3f(uniformName, renderingEngine->GetVector3f(unprefixedName));
			else if(uniformType == "float")
				SetUniformf(uniformName, renderingEngine->GetFloat(unprefixedName));
			else if(uniformType == "DirectionalLight")
				SetUniformDirectionalLight(uniformName, *(DirectionalLight*)renderingEngine->GetActiveLight());
			else if(uniformType == "PointLight")
				SetUniformPointLight(uniformName, *(PointLight*)renderingEngine->GetActiveLight());
			else if(uniformType == "SpotLight")
				SetUniformSpotLight(uniformName, *(SpotLight*)renderingEngine->GetActiveLight());
			else
				renderingEngine->UpdateUniformStruct(transform, material, this, uniformName, uniformType);
		}
		else if(uniformName.substr(0, 2) == "C_")
		{
			if(uniformName == "C_eyePos")
				SetUniformVector3f(uniformName, renderingEngine->GetMainCamera().GetTransform().GetTransformedPos());
			else
				throw "Invalid Camera Uniform: " + uniformName;
		}
		else
		{
			if(uniformType == "vec3")
				SetUniformVector3f(uniformName, material.GetVector3f(uniformName));
			else if(uniformType == "float")
				SetUniformf(uniformName, material.GetFloat(uniformName));
			else
				throw uniformType + " is not supported by the Material class";
		}
	}
}

std::string LoadShader(const std::string& fileName)
{

}

void CheckShaderError(int shader, int flag, bool isProgram, const std::string& errorMessage)
{

}

std::vector<UniformStruct> FindUniformStructs(const std::string& shaderText)
{

}

std::string FindUniformStructName(const std::string& structStartToOpeningBrace)
{

}

std::vector<TypedData> FindUniformStructComponents(const std::string& openingBraceToClosingBrace)
{

}

ShaderData::ShaderData(const std::string& fileName)
{
	program = glCreateProgram();

	if (program == 0) 
	{
		fprintf(stderr, "Error creating shader program\n");
		exit(1);
	}

	std::string vertexShaderText = LoadShader(fileName + ".vs");
	std::string fragmentShaderText = LoadShader(fileName + ".fs");

	AddVertexShader(vertexShaderText);
	AddFragmentShader(fragmentShaderText);

	AddAllAttributes(vertexShaderText);

	CompileShader();

	AddShaderUniforms(vertexShaderText);
	AddShaderUniforms(fragmentShaderText);
}

ShaderData::~ShaderData()
{
	for(std::vector<int>::iterator it = shaders.begin(); it != shaders.end(); ++it) 
	{
		glDetachShader(program,*it);
		glDeleteShader(*it);
	}
	glDeleteProgram(program);
}

int ShaderData::GetProgram()
{

}

std::vector<int>& ShaderData::GetShaders()
{
	return shaders; 
}

std::vector<std::string>& ShaderData::GetUniformNames()
{
	return uniformNames; 
}

std::vector<std::string>& ShaderData::GetUniformTypes()
{
	return uniformTypes;
}

std::map<std::string, unsigned int>& ShaderData::GetUniformMap()
{
	return uniformMap;
}

void ShaderData::AddVertexShader(const std::string& text)
{

}

void ShaderData::AddGeometryShader(const std::string& text)
{

}

void ShaderData::AddFragmentShader(const std::string& text)
{

}

void ShaderData::AddProgram(const std::string& text, int type)
{

}

void ShaderData::AddAllAttributes(const std::string& vertexShaderText)
{

}

void ShaderData::AddShaderUniforms(const std::string& shaderText)
{

}

void ShaderData::AddUniform(const std::string& uniformName, const std::string& uniformType, const std::vector<UniformStruct>& structs)
{

}

void ShaderData::CompileShader()
{

}
