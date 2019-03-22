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

		void useItem();
		void updateWeapon();
		void removeItem();
		int gethp();
		Statistics &getStatistics();
		Weapon &getWeapon();

	private:
		Statistics _statistics;
		Backpack _backpack;
		Weapon _weapon;

	};
}