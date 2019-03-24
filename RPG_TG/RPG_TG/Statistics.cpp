#include "Statistics.h"

#include <iostream>

namespace TG
{
	Statistics::Statistics()
	{
		_name = "";
		_hp = 1;
		_baseDamage = 1;
		_damage = _baseDamage;
	}

	Statistics::Statistics(int  hp, int baseDamage, std::string name)
	{
		_name = name;
		_hp = hp;
		_baseDamage = baseDamage;
		_damage = _baseDamage;
	}

	void Statistics::info()
	{
		std::cout << "Statystyki";
		if (_name != "") std::cout << " " << _name;
		std::cout << ":" << std::endl;
		std::cout << "- HP: " << _hp << std::endl; 
		std::cout << "- Base_Damage: " << _baseDamage << std::endl;
		std::cout << "- Damage: " << _damage << std::endl << std::endl;
	}

	void Statistics::updateHP(int u)
	{
		_hp = _hp + u;
	}
	
	void Statistics::updateDamage(int d)
	{
		_damage = _baseDamage + d;
	}

	void Statistics::setName(std::string n)
	{
		_name = n;
	}

	void Statistics::setHp(int h)
	{
		_hp = h;
	}

	void Statistics::setBaseDamage(int d)
	{
		int tmp = _damage - _baseDamage;
		_baseDamage = d;
		this->updateDamage(tmp);
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