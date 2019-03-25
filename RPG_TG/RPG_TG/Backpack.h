#pragma once

#include <vector>
#include "Item.h"
#include "Weapon.h"

namespace TG
{
	class Backpack
	{
	public:
		Backpack();
		Backpack(int freeWeigth);

		void info();

		bool add(Item i);
		bool add(Weapon w);
		void remove();
		void manage();

		void setFreeWeigth(int f);

		int getFreeWeigth();
		std::vector < Item > &getItems();
		std::vector < Weapon > &getWeapons();

	private:
		int _freeWeigth;
		std::vector < Item > _items;
		std::vector < Weapon > _weapons;
	};

}
