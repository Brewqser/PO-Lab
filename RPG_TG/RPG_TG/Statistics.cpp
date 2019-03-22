#include "Statistics.h"

#include <iostream>

namespace TG
{
	Statistics::Statistics()
	{
		_hp = 1;
		_baseDamage = 0;
	}

	Statistics::Statistics(int hp, int baseDamage)
	{
		_hp = hp;
		_baseDamage = baseDamage;
	}

	int Statistics::gethp()
	{
		return _hp;
	}
	
	void Statistics::reducehp(int r)
	{
		_hp -= r;
	}

	void Statistics::info()
	{
		std::cout << "HP: " << _hp << " Base Damage: " << _baseDamage << std::endl << std::endl;
	}
}