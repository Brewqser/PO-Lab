#pragma once

#include "Definitions.h"
#include "Player.h"
#include "LocationMachine.h"
#include <map>
#include <string>
#include <memory>
#include "txt_file_Handle.h"

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
		std::map < std::string, int > _settings;

		std::unique_ptr <txt_file_Handle> _txt_loader;
	};
}