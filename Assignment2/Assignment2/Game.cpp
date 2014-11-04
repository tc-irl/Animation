#include "Game.h"


Game::Game(void)
{
}


Game::~Game(void)
{
}

GameObject& Game::GetRoot()
{
	return root; 
}

void Game::SetEngine(CoreEngine* engine)
{
	root.SetEngine(engine);
}

void Game::Input(float delta)
{
	root.InputAll(delta);
}

void Game::Update(float delta)
{
	root.UpdateAll(delta);
}

void Game::Render(RenderingEngine* renderingEngine)
{
	renderingEngine->Render(&root);
}

void Game::Init()
{
	//
}

void Game::AddToScene(GameObject* child)
{
	root.AddChild(child);
}
