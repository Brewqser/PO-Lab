#pragma once

#include <vector>

#include "Enemy.h"
#include "Player.h"

namespace TG
{
	class Arena
	{
	public:
		Arena(Player &pl, int n);

		void fight(Player &pl);

	private:
		std::vector <Enemy> _enemies;
	};
}
