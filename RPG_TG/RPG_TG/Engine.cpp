#include <iostream>

#include "Engine.h"
#include "Definitions.h"

namespace TG
{
	Engine::Engine() : _locationMachine()
	{
		std::cout << "Budzisz si� w swoim ��ku." << std::endl;
		std::cout << "Nagle s�yszysz dziwne d�wi�ki dobiekaj�ce z piwnicy." << std::endl;
		std::cout << "Zdezori�towany wstajesz i przypominasz sobie," << std::endl;
		std::cout << "�e masz schowanie gdzie� w domu co� w razie takiej sytu�acji." << std::endl << std::endl;

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
		//std::cout << "G�WMO" << std::endl;
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

