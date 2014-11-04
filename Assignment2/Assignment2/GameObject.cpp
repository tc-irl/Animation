#include "GameObject.h"

GameObject::GameObject()
{
	coreEngine = 0;
}


GameObject::~GameObject(void)
{
	for(unsigned int i = 0; i < components.size(); i++)
	{
		if(components[i])
		{
			delete components[i];
		}
	}

	for(unsigned int i = 0; i < children.size(); i++)
	{
		if(children[i])
		{
			delete children[i];
		}
	}
}

GameObject* GameObject::AddChild(GameObject* child)
{
	children.push_back(child); 
	child->GetTransform().SetParent(&transform);
	child->SetEngine(coreEngine);
	return this;
}

GameObject* GameObject::AddComponent(GameComponent* component)
{
	components.push_back(component);
	component->SetParent(this);
	return this;
}

void GameObject::InputAll(float delta)
{
	Input(delta);

	for(unsigned int i = 0; i < children.size(); i++)
		children[i]->InputAll(delta);
}

void GameObject::UpdateAll(float delta)
{
	Update(delta);

	for(unsigned int i = 0; i < children.size(); i++)
		children[i]->UpdateAll(delta);
}

void GameObject::RenderAll(Shader* shader, RenderingEngine* renderingEngine)
{
	Render(shader, renderingEngine);

	for(unsigned int i = 0; i < children.size(); i++)
		children[i]->RenderAll(shader, renderingEngine);
}

std::vector<GameObject*> GameObject::GetAllAttached()
{

}

Transform& GameObject::GetTransform()
{
	return transform;
}

void GameObject::SetEngine(CoreEngine* engine)
{
	if(coreEngine != engine)
	{
		coreEngine = engine;

		for(unsigned int i = 0; i < components.size(); i++)
			components[i]->AddToEngine(engine);

		for(unsigned int i = 0; i < children.size(); i++)
			children[i]->SetEngine(engine);
	}
}

void GameObject::Input(float delta)
{
	transform.Update();

	for(unsigned int i = 0; i < components.size(); i++)
		components[i]->Input(delta);
}

void GameObject::Update(float delta)
{
	for(unsigned int i = 0; i < components.size(); i++)
		components[i]->Update(delta);
}

void GameObject::Render(Shader* shader, RenderingEngine* renderingEngine)
{
	for(unsigned int i = 0; i < components.size(); i++)
		components[i]->Render(shader, renderingEngine);
}
