#include "Engine.h"

#include <iostream>
#include "txtManager.h"

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
					txtManager::getTxtManager().print("///", 1);
				}

				break;
				
			case States::player:
				_player.info();
				_player.manage(_state, _gameRun);
				if (_gameRun)txtManager::getTxtManager().print("///", 1);
			}
		}

		if (_locationMachine.getState()[Locations::Basemant] != 2)
		{
			txtManager::getTxtManager().print("go", 1);
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