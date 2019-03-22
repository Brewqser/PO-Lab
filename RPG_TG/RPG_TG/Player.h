#pragma once

#include "Statistics.h"
#include "Backpack.h"

namespace TG
{
	class Player
	{
	public:
		Player();

		void info();
		
		Backpack &getBackpack();

	private:
		Statistics _statistics;
		Backpack _backpack;

	};
}