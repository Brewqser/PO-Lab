#pragma once

#include <string>

#include "Player.h"
#include "Statistics.h"

namespace TG
{
	class Enemy
	{
	public:
		Enemy();
		Enemy(std::string name, int hp, int damage, int miss);

		void attack(Player &pl);

		Statistics &getStatistics();

	private:
		Statistics _statistics;
		int _miss;
	};
}

