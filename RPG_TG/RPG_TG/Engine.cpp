#include "Engine.h"

Engine::Engine()
{

}

Engine* Engine::_instance = 0;

Engine* Engine::getInstance()
{
	if (_instance == 0)
	{
		_instance = new Engine();
	}

	return _instance;
}

void Engine::afterUsageOfEngine()
{
	delete _instance;
}

