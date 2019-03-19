#pragma once

#include <iostream>

using namespace std;

class Statistics
{
public:
	Statistics();
	Statistics(int hp, int lvl, int strength , int agility, int exp , int baseDamage);

	void Info();
	void hpminus(int m);
	void lvlup();

private:
	int _hp;
	int _lvl;
	int _strength;
	int	_agility;
	int _exp;
	int _baseDamage;
};

