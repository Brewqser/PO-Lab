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

		void showItems();
		void showWeapons();

		void add(Item i);
		void add(Weapon w);

		void remove(int i, char co);

		std::vector < Item > &getItems();
		std::vector < Weapon > &getWeapons();

	private:
		int _maxcapacity;
		int _capacity;
		std::vector < Item > _items;
		std::vector < Weapon > _weapons;
	};

}
