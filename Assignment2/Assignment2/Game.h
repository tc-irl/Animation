#pragma once
#include "GameObject.h"
#include "RenderingEngine.h"
#include "CoreEngine.h"

class Game
{
public:
	Game(void);
	virtual ~Game(void);

	virtual void Init();
	void Input(float delta);
	void Update(float delta);
	void Render(RenderingEngine* renderingEngine);

	GameObject& GetRoot();

	void SetEngine(CoreEngine* engine);
protected:
	void AddToScene(GameObject* child);
private:
	Game(Game &game) {}

	GameObject root;
};

