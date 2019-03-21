#include <iostream>

#include "Engine.h"
#include "Definitions.h"

namespace TG
{
	Engine::Engine() : _locationMachine()
	{
		std::cout << "Budzisz siê w swoim ³ó¿ku." << std::endl;
		std::cout << "Nagle s³yszysz dziwne dŸwiêki dobiekaj¹ce z piwnicy." << std::endl;
		std::cout << "Zdezoriêtowany wstajesz i przypominasz sobie," << std::endl;
		std::cout << "¿e masz schowanie gdzieœ w domu coœ w razie takiej sytu³acji." << std::endl << std::endl;

		_gameOver = 0;
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

	LocationMachine &Engine::getLocationMachine()
	{
		return _locationMachine;
	}

	void Engine::printLocation()
	{
		//std::cout << "GÓWMO" << std::endl;
		_locationMachine.print();
	}

	void Engine::changeLocation()
	{
		_locationMachine.LocationNet();
	}

	void Engine::setGameOver()
	{
		_gameOver = 1;
	}

	bool Engine::getGameOver()
	{
		return _gameOver;
	}

}

