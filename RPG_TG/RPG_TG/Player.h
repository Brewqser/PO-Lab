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
		void opcions();
		void manage(char a);
		void equipWeapon();

		Statistics &getStatistics();
		Backpack &getBackpack();
		Weapon &getWeapon();

	private:
		Statistics _statistics;
		Backpack _backpack;
		Weapon _weapon;

	};
}