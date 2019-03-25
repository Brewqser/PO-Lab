#pragma once

#include "Definitions.h"
#include "Statistics.h"
#include "Backpack.h"

namespace TG
{
	class Player
	{
	public:
		Player();
		Player(int hp, int bpsize );

		void info();
		void manage(States &s, bool &gr);
		void useItem();
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