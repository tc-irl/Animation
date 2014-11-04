#pragma once
#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include "Camera.h"
#include "GameObject.h"
#include "Lighting.h"
#include "Shader.h"
#include "MeshRenderer.h"
#include "MappedValues.h"
#include "Mesh.h"
#include "Material.h"

#include <gl/glew.h>

#include <iostream>
#include <vector>
#include <map>


class RenderingEngine : public MappedValues
{
public:
	RenderingEngine(void);
	virtual ~RenderingEngine(void);

	void AddCamera(Camera* camera);
	void AddLight(BaseLight* light);
	void Render(GameObject* object);

	BaseLight* GetActiveLight();

	Camera& GetMainCamera(); 

	virtual void UpdateUniformStruct(const Transform& transform, const Material& material, Shader* shader, 
		const std::string& uniformName, const std::string& uniformType);

private:
	RenderingEngine(const RenderingEngine& other);
	void operator=(const RenderingEngine& other);

	Camera *camera;
	BaseLight* activeLight;
	Shader* defaultShader;
	std::vector<BaseLight*> lights;
	std::map<std::string, unsigned int> samplerMap;
};

#endif