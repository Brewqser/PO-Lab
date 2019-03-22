#pragma once

#include <vector>
#include <iostream>
#include "Item.h"
#include "Weapon.h"

namespace TG
{
	class Backpack
	{
	public:
		Backpack();
		Backpack(int maxcapacity);

		void info();

		void add(Item i);
		void add(Weapon w);

		void remove(int i, char co);

	public:
		int _maxcapacity;
		int _capacity;
		std::vector < Item > _items;
		std::vector < Weapon >  _weapons;
	};

}
