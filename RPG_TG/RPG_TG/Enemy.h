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

		void info();
		void attack(Player &pl);

		void setMiss(int m);

		Statistics &getStatistics();
		int getMiss();

	private:
		Statistics _statistics;
		int _miss;
	};
}

