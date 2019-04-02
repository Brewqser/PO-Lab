#pragma once

#include <vector>
#include <memory>
#include "Item.h"
#include "Weapon.h"
#include "sort_handle.h"
#include <algorithm>

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
		void setsort(int s);
		void sort();

		void setFreeWeigth(int f);

		int getFreeWeigth();
		std::vector < Item > &getItems();
		std::vector < Weapon > &getWeapons();

	private:
		int _freeWeigth;
		std::vector < Item > _items;
		std::vector < Weapon > _weapons;
		 sort_handle _comp;

	};

}
