#pragma once

#include "Definitions.h"
#include "Player.h"
#include "LocationMachine.h"

namespace TG
{
	class Engine
	{
	private:
		Engine();
		Engine(const Engine &);
		~Engine();

		LocationMachine _locationMachine;
		Player _player;
		bool _gameOver;
		States _state;

	public:
		static Engine &getEngine();

		LocationMachine &getLocationMachine();

		void printLocation();
		void changeLocation();

		void setGameOver();
		bool getGameOver();

		void setState(States sta);

		Player &getPlayer();

		void update();
	};
}