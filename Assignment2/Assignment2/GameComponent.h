#pragma once
#include "transform.h"
#include "gameObject.h"
#include "CoreEngine.h"

class RenderingEngine;
class Shader;

class GameComponent
{
public:
	virtual ~GameComponent() {}

	virtual void Input(float delta) {}
	virtual void Update(float delta) {}
	virtual void Render(Shader* shader, RenderingEngine* renderingEngine) {}

	virtual void AddToEngine(CoreEngine* engine) { }

	inline void SetParent(GameObject* parent) { parent = parent; }
	inline Transform& GetTransform() 
	{ return parent->GetTransform(); }
	inline const Transform& GetTransform() const { return parent->GetTransform(); }

private:
	GameObject* parent;
};
