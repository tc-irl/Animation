#include "CoreEngine.h"


CoreEngine::CoreEngine(void)
{
}

CoreEngine::CoreEngine(int width,int height,double framerate,Game *game)
{
	isRunning = false;

	this->height = height;
	this->width = width;
	this->framerate = framerate;
	this->game = game;

	window = new Window();
}


CoreEngine::~CoreEngine(void)
{
}

void CoreEngine::CreateWindow(string title)
{
	window->createWindow(800,600,title);
}

void CoreEngine::Start()
{
	if(isRunning)
	{
		return;
	}
	else
	{
		Run();
	}
}
void CoreEngine::Stop()
{
	if(!isRunning)
	{
		return;
	}
	else
	{
		isRunning = false;
	}
}

void CoreEngine::Run()
{
	isRunning = true;
	game->Init();
}