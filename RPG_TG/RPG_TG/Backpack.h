#pragma once

#include <vector>
#include <iostream>
#include "Item.h"
#include "Weapon.h"

using namespace std;

class Backpack
{
public:
	Backpack();
	Backpack(int maxcapacity);

	void Info();
	void AddItem(Item i);
	void RemoveItem(int i);
	void AddWeapon(Weapon w);
	void RemoveWeapon(int w);
	void Upgrade();

private:
	int _maxcapacity;
	int _capacity;
	vector < Item > _items;
	vector < Weapon >  _weapons;
};

