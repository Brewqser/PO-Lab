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

	private:
		Statistics _statistics;
		Backpack _backpack;
		Weapon _weapon;

	};
}