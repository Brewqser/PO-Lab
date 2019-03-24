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
		Backpack(int maxcapacity);

		void info();

		void add(Item i);
		void add(Weapon w);

		void itemRemove();
		void weaponRemove();
		void manage();
		void handleOverWeigth();
		void checkOverWeigth(); // sprawdzian grubasa

		void clearItems();
		void clearWeapons();

		void setMaxCapacity(int m);
		void setOverWeigth(bool o);

		int getMaxCapacity();
		bool getOverWeigth();
		std::vector < Item > &getItems();
		std::vector < Weapon > &getWeapons();

	private:
		int _maxcapacity;
		int _capacity;
		bool _overweigth;
		std::vector < Item > _items;
		std::vector < Weapon > _weapons;
	};

}
