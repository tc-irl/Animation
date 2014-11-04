#pragma once
#include "Game.h"
#include "Window.h"
#include "RenderingEngine.h"
#include <iostream>

using namespace std;
class CoreEngine
{
public:
	CoreEngine(void);
	CoreEngine(int width,int height,double framerate,Game *game);
	~CoreEngine(void);

	void Start();
	void Stop();
	void CreateWindow(string title);

private:
	Game *game;
	bool isRunning; 
	int width, height;
	double framerate;
	Window *window;
	RenderingEngine* renderingEngine;

	void Run();
};

