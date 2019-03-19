#pragma once

#include "Backpack.h"
#include "Statistics.h"

using namespace std;

class Player
{
public:
	Player();
	
	void takeDamage(int d);
	void lvlup();
	void changeWeapon(int w);
	void dealDamage();

public:
	Statistics _stats;
	Backpack _bp;
	Weapon _wp;
};

