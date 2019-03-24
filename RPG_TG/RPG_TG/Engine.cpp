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

		while (_gameOver == 0)
		{
			std::cout << "XXXXXX" << std::endl;
			if (_state == States::travel)
			{
				_locationMachine.info(_player);
				std::cin >> a;
				if ( a == 'p' )
				{
					_state = States::player;
				}
				else if (a == 's')
				{
					_locationMachine.search(_player.getBackpack());
				}
				else _locationMachine.travel((int)a - 48 );
			}
			else if (_state == States::player)
			{
				_player.info();
				_player.opcions();
				std::cin >> a;
				if (a == 't')
				{
					_state = States::travel;
				}
				else _player.manage(a);
			}
		}
	}

	Engine::Engine() : _locationMachine(), _player()
	{
		_gameOver = 0;
		_state = States::travel;
	}

	Engine::Engine(const Engine &)
	{

	}

	Engine::~Engine()
	{

	}
}