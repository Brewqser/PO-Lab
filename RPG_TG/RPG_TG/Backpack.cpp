#include "Backpack.h"

#include <iostream>
#include <string>
#include "txtManager.h"

namespace TG
{
	Backpack::Backpack() 
	{
		_freeWeigth = 10;
		_comp.set(0);
	}

	Backpack::Backpack(int freeWeigth)
	{
		_freeWeigth = freeWeigth;
		_comp.set(0);
	}

	void Backpack::info()
	{
		txtManager::getTxtManager().print(this);

		if (_items.size() != 0)
		{
			txtManager::getTxtManager().print("it",1);
			for (unsigned int i = 0; i < _items.size(); i++)
			{
				_items[i].info();
			}
			txtManager::getTxtManager().print("endl", 0);
		}

		if (_weapons.size() != 0)
		{
			txtManager::getTxtManager().print("wp", 1);
			for (unsigned int i = 0; i < _weapons.size(); i++)
			{
				_weapons[i].info();
			}

			txtManager::getTxtManager().print("endl", 0);
		}
	}

	bool Backpack::add(Weapon w)
	{
		if (w.getWeight() <= _freeWeigth)
		{
			txtManager::getTxtManager().print("addw", 0);
			Weapon *w1 = &w;
			txtManager::getTxtManager().print(w1);

			_weapons.push_back(w);
			_freeWeigth -= w.getWeight();
			return 1;
		}
		else
		{
			txtManager::getTxtManager().print("tmc", 1);
			return 0;
		}

		return 0;
	}

	bool Backpack::add(Item i)
	{
		if (i.getWeight() <= _freeWeigth)
		{
			txtManager::getTxtManager().print("addw", 0);
			Item *i1 = &i;
			txtManager::getTxtManager().print(i1);

			_items.push_back(i);
			_freeWeigth -= i.getWeight();
			return 1;
		}
		else
		{
			txtManager::getTxtManager().print("tmc", 1);
			return 0;
		}

		return 0;
	}

	void Backpack::remove()
	{
		txtManager::getTxtManager().print("bpr", 1);
		
		for (unsigned int i = 0; i < _items.size(); i++)
		{
			txtManager::getTxtManager().print(i + 1, 0);
			_items[i].info();
		}
		for (unsigned int i = 0; i < _weapons.size(); i++)
		{
			txtManager::getTxtManager().print(i +(int) _items.size() + 1, 0);
			_weapons[i].info();
		}
		txtManager::getTxtManager().print(" ", 0);

		int tmp;
		do
		{
			std::cin >> tmp;
		} while (tmp < 0 || tmp > _items.size() + _weapons.size());


		if (tmp != 0)
		{
			tmp--;
			if (tmp < _items.size())
			{
				_freeWeigth += _items[tmp].getWeight();
				_items.erase(_items.begin() + tmp);
			}
			else
			{
				tmp -= (int) _items.size();
				_freeWeigth += _weapons[tmp].getWeight();
				_weapons.erase(_weapons.begin() + tmp);
			}
		}
	}

	void Backpack::manage()
	{
		txtManager::getTxtManager().print("bpm", 1);

		int tmp;
		do
		{
			std::cin >> tmp;
		} while (tmp < 0 || tmp > 2);

		if (tmp == 1)
		{
			this->info();
		}
		if (tmp == 2)
		{
			this->remove();
		}
	}

	void Backpack::setsort(int i)
	{
		_comp.set(i);
		std::cout << i << std::endl;
	}

	void Backpack::sort()
	{
		std::sort(_weapons.begin(), _weapons.end(), _comp);
	}

	void Backpack::setFreeWeigth(int f)
	{
		_freeWeigth = f;
	}

	int Backpack::getFreeWeigth()
	{
		return _freeWeigth;
	}
	
	std::vector < Item > &Backpack::getItems()
	{
		return _items;
	}

	std::vector < Weapon > &Backpack::getWeapons()
	{
		return _weapons;
	}
}