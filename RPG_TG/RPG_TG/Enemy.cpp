#include "Enemy.h"

#include <cstdlib>

namespace TG
{
	Enemy::Enemy()
	{
		_statistics = Statistics();
	}

	Enemy::Enemy(std::string name, int hp, int damage)
	{
		_statistics = Statistics(name, hp, damage);
	}

	Statistics &Enemy::getStatistics()
	{
		return _statistics;
	}

	void Enemy::attac()
	{
		int tmp = rand();

		if (tmp % 2 == 0)
		{
			std::cout << "Attakuje za " << _statistics.getdamage()  << std::endl;
			Engine::getEngine().getPlayer().getStatistics().reducehp(_statistics.getdamage());
		}
		else
		{
			std::cout << "Czeka" << std::endl;
		}
	}
}
