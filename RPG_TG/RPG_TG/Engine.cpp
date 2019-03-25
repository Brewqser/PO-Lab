#include "Engine.h"

#include <iostream>

namespace TG
{
	Engine &Engine::getEngine()
	{
		static Engine engine;
		return engine;
	}

	void Engine::run()
	{
		char a;

		while (_gameRun)
		{
			switch (_state)
			{
			case States::travel:
				_locationMachine.info(_player,_gameRun);
				if (_gameRun)
				{
					_locationMachine.manage(_state, _player.getBackpack());
					std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
				}

				break;
				
			case States::player:
				_player.info();
				_player.manage(_state, _gameRun);
				if (_gameRun) std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
			}
		}

		if (_locationMachine.getState()[Locations::Basemant] != 2)
		{
			std::cout << "GAME OVER" << std::endl;
		}
	}

	Engine::Engine() : _locationMachine(), _player()
	{
		_gameRun = 1;
		_state = States::travel;
	}

	Engine::Engine(const Engine &)
	{

	}

	Engine::~Engine()
	{

	}
}