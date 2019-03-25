#include "Statistics.h"

#include <iostream>

namespace TG
{
	Statistics::Statistics()
	{
		_name = "";
		_hp = 1;
		_damage = 1;
	}

	Statistics::Statistics(int  hp, int damage, std::string name)
	{
		_name = name;
		_hp = hp;
		_damage = damage;
	}

	void Statistics::info()
	{
		std::cout << "Statystyki:" << std::endl;
		std::cout << "- HP: " << _hp << std::endl; 
		std::cout << "- Damage: " << _damage << std::endl << std::endl;
	}

	void Statistics::updateHP(int u)
	{
		_hp = _hp + u;
	}

	void Statistics::setName(std::string n)
	{
		_name = n;
	}

	void Statistics::setHp(int h)
	{
		_hp = h;
	}

	void Statistics::setDamage(int d)
	{
		_damage = d;
	}

	std::string Statistics::getName()
	{
		return _name;
	}

	int Statistics::getHp()
	{
		return _hp;
	}

	int Statistics::getDamage()
	{
		return _damage;
	}
}