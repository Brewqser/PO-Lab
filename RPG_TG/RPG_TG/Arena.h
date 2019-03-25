#pragma once

#include <vector>

#include "Enemy.h"
#include "Player.h"

namespace TG
{
	class Arena
	{
	public:
		Arena(Player &pl, int n,bool &gr);

		void fight(Player &pl,bool &gr);

	private:
		std::vector <Enemy> _enemies;
	};
}
