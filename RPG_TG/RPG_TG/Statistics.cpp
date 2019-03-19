#include "Statistics.h"

Statistics::Statistics()
{
	_hp = 1;
	_lvl = 1;
	_strength = 1;
	_agility = 1;
	_exp = 0;
	_baseDamage = 1 ;
}

Statistics::Statistics(int hp = 1, int lvl = 1,int strength = 1,int agility = 1,int exp = 0,int baseDamage = 1)
{
	_hp = hp;
	_lvl = lvl;
	_strength = strength;
	_agility = agility;
	_exp = exp;
	_baseDamage = baseDamage;
}

void Statistics::Info()
{
	cout << _hp << " " << _lvl << " " << _strength << " " << _agility << " " << _exp << " " << _baseDamage << endl;
}

void Statistics::hpminus(int m)
{
	_hp -= m;
}
void Statistics::lvlup()
{
	_strength += 1;
	_agility += 1;
}
