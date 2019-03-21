#include "Engine.h"
#include "Definitions.h"

namespace TG
{
	Engine::Engine()
	{

	}

	Engine::Engine(const Engine &)
	{

	}

	Engine::~Engine()
	{

	}

	Engine &Engine::getEngine()
	{
		static Engine engine;
		return engine;
	}

}

