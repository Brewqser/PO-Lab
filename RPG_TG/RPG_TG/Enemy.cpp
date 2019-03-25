#include "Enemy.h"

#include <cstdlib>
#include <iostream>

namespace TG
{
	Enemy::Enemy()
	{
		_statistics = Statistics();
	}

	Enemy::Enemy(std::string name, int hp, int damage,int miss)
	{
		_statistics = Statistics(hp, damage, name);
		_miss = miss;
	}

	void Enemy::info()
	{
		std::cout << _statistics.getName() << std::endl;
		_statistics.info();
	}

	void Enemy::attack(Player &pl)
	{
		int tmp = rand();

		if (tmp % _miss == 0)
		{
			std::cout << "Czeka" << std::endl;
		}
		else
		{
			std::cout << "Attakuje za " << _statistics.getDamage() << std::endl;
			pl.getStatistics().updateHP(-1 * _statistics.getDamage());
		}
	}

	void Enemy::setMiss(int m)
	{
		_miss = m;
	}

	Statistics &Enemy::getStatistics()
	{
		return _statistics;
	}

	int Enemy::getMiss()
	{
		return _miss;
	}
}
