#pragma once

#include "Player.h"

class Engine
{
public:
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
	static Engine* getInstance();
	static void afterUsageOfEngine();

	Player _p;

private:
	Engine();
	
	static Engine* _instance;

};