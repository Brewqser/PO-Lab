#include "Enemy.h"

#include <cstdlib>
#include "txtManager.h"

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
		txtManager::getTxtManager().print(this);
	}

	void Enemy::attack(Player &pl)
	{
		int tmp = rand();

		if (tmp % _miss == 0)
		{
			txtManager::getTxtManager().print("w8", 1);
		}
		else
		{
			txtManager::getTxtManager().attack("att", _statistics.getDamage());
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
