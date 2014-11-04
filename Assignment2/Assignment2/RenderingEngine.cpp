#include "RenderingEngine.h"


RenderingEngine::RenderingEngine(void)
{
	samplerMap.insert(std::pair<std::string, unsigned int>("diffuse", 0));

	AddVector3f("ambient", glm::vec3(0.1f, 0.1f, 0.1f));
	defaultShader = new Shader("diffuse");

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_CLAMP);
}

RenderingEngine::RenderingEngine(const RenderingEngine& other)
{

}


RenderingEngine::~RenderingEngine(void)
{
}

Camera& RenderingEngine::GetMainCamera()
{
	return *camera; 
}

void RenderingEngine::AddCamera(Camera* camera)
{
	this->camera = camera;
}

BaseLight* RenderingEngine::GetActiveLight()
{
	return activeLight;
}

void RenderingEngine::AddLight(BaseLight* light)
{
	lights.push_back(light);
}

void RenderingEngine::Render(GameObject* object)
{

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEPTH_CLAMP);
	
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

}

void RenderingEngine::operator=(const RenderingEngine& other)
{

}

void RenderingEngine::UpdateUniformStruct(const Transform& transform, const Material& material, Shader* shader, const std::string& uniformName, const std::string& uniformType)
{
	//throw uniformType + " is not supported by the rendering engine";
}
