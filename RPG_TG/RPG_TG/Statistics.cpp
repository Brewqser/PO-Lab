#include "Statistics.h"

#include <iostream>

namespace TG
{
	Statistics::Statistics()
	{
		_hp = 1;
		_baseDamage = 1;
		_damage = _baseDamage;
	}

	Statistics::Statistics(int hp, int baseDamage)
	{
		_hp = hp;
		_baseDamage = baseDamage;
		_damage = _baseDamage;
	}

	Statistics::Statistics(std::string name, int  hp, int baseDamage)
	{
		_name = name;
		_hp = hp;
		_baseDamage = baseDamage;
		_damage = _baseDamage;
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
		std::cout << "HP: " << _hp << " Base_Damage: " << _baseDamage << " Damage: " << _damage << std::endl << std::endl;
	}

	void Statistics::addhp( int a )
	{
		_hp += a;
	}

	void Statistics::updatedamage(int u)
	{
		_damage = _baseDamage + u;
	}

	int Statistics::getdamage()
	{
		return _damage;
	}

	std::string Statistics::getname()
	{
		return _name;
	}
}