#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#pragma once

#include <vector>
#include "Transform.h"
#include "GameComponent.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	GameObject* AddChild(GameObject* child);
	GameObject* AddComponent(GameComponent* component);

	void InputAll(float delta);
	void UpdateAll(float delta);
	void RenderAll(Shader* shader, RenderingEngine* renderingEngine);

	std::vector<GameObject*> GetAllAttached();

	Transform& GetTransform();
	void SetEngine(CoreEngine* engine);
protected:
private:
	void Input(float delta);
	void Update(float delta);
	void Render(Shader* shader, RenderingEngine* renderingEngine);

	std::vector<GameObject*> children;
	std::vector<GameComponent*> components;
	Transform transform;
	CoreEngine* coreEngine;
};

#endif // GAMEOBJECT_H