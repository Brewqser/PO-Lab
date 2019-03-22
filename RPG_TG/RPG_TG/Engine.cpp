#include <iostream>

#include "Engine.h"
#include "Definitions.h"
#include "Arena.h"

namespace TG
{
	Engine::Engine() : _locationMachine()
	{
		std::cout << "Budzisz siê w swoim ³ó¿ku." << std::endl;
		std::cout << "Nagle s³yszysz dziwne dŸwiêki dobiekaj¹ce z piwnicy." << std::endl;
		std::cout << "Zdezoriêtowany wstajesz i przypominasz sobie," << std::endl;
		std::cout << "¿e masz schowanie gdzieœ w domu coœ w razie takiej sytu³acji." << std::endl << std::endl;
		std::cout << "Sterowanie ( obowi¹zuje 'globalnie'):" << std::endl;
		std::cout << "t - menu porusznia" << std::endl;
		std::cout << "p - menu postaci" << std::endl;
		std::cout << "inne cyfry i znaki - przemieszcanie siê po menu/ lokacjach / itp." << std::endl << std::endl;

		_gameOver = 0;
		_state = States::travel;
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
		_locationMachine.print();
	}

	void Engine::changeLocation()
	{
		_locationMachine.locationNet();
	}

	void Engine::setGameOver()
	{
		_gameOver = 1;
	}

	bool Engine::getGameOver()
	{
		return _gameOver;
	}

	void Engine::setState(States sta)
	{
		_state = sta;
	}

	Player &Engine::getPlayer()
	{
		return _player;
	}

	void Engine::update()
	{
		char tmp;

		switch( _state )
		{
		case States::player:
			_player.info();

			std::cin >> tmp;
			if (tmp == 't')
			{
				_state = States::travel;
				system("cls");
			}
			else if (tmp == 'i')
			{
				_player.useItem();
			}
			else if (tmp == 'w')
			{
				_player.updateWeapon();
			}
			else if (tmp == 'r')
			{
				_player.removeItem();
			}

			break;

		case States::travel:
			if (_locationMachine.getMoveDone() == 1) _locationMachine.print();

			if (_gameOver != 1 && _state != States::fight)
			{
				if (_locationMachine.getMoveDone() == 1) _locationMachine.locationNet();
				if (_locationMachine.getMoveDone() == 1) _locationMachine.resetMoveDone();
				std::cin >> tmp;
				if (tmp == 'p')
				{
					_state = States::player;
					_locationMachine.setMoveDone();
					system("cls");
				}
				else
				{
					_locationMachine.move((int)tmp - 48);
				}
			}
			break;

		case States::fight:

			Arena(3);
			if (_player.getStatistics().gethp() <= 0)
			{
				std::cout << "GAME OVER" << std::endl;
				_gameOver = 1;
			}
			_state = States::travel;

			break;

		}

		




	}
}