#pragma once

#include "Definitions.h"
#include "Player.h"
#include "LocationMachine.h"

namespace TG
{
	class Engine
	{
	public:
		static Engine &getEngine();

		void run();

	private:
		Engine();
		Engine(const Engine &);
		~Engine();

		LocationMachine _locationMachine;
		Player _player;
		States _state;
		bool _gameRun;

	};
}