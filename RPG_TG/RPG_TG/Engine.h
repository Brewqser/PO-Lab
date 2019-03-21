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

	public:
		static Engine &getEngine();

	};
}