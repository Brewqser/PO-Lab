#pragma once

#include "Definitions.h"
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
		bool _gameOver;

	public:
		static Engine &getEngine();

		LocationMachine &getLocationMachine();

		void printLocation();
		void changeLocation();

		void setGameOver();
		bool getGameOver();

	};
}