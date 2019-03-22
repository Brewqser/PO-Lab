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
		std::cout << "Sterowanie:" << std::endl;
		std::cout << "s - zmiana mi�dzy postaci� a map�" << std::endl;
		std::cout << "1 / 9  - przemieszcanie si� po menu/ lokacjach / itp." << std::endl << std::endl;

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
			if (tmp == 's')
			{
				_state = States::travel;
				system("cls");
			}

			break;

		case States::travel:
			if (_locationMachine.getMoveDone() == 1) _locationMachine.print();

			if (_gameOver != 1)
			{
				if (_locationMachine.getMoveDone() == 1) _locationMachine.locationNet();
				if (_locationMachine.getMoveDone() == 1) _locationMachine.resetMoveDone();
				std::cin >> tmp;
				if (tmp == 's')
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
		}



	}
}

