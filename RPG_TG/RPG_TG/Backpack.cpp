#include "Backpack.h"

#include <iostream>
#include <string>

namespace TG
{
	Backpack::Backpack()
	{
		_maxcapacity = 10;
		_capacity = 0;
		_overweigth = false;
	}

	Backpack::Backpack(int maxcapacity)
	{
		_maxcapacity = maxcapacity;
		_capacity = 0;
		_overweigth = false;
	}

	void Backpack::info()
	{
		std::cout << "Plecak posiada " << _maxcapacity << " pojemnosci" << std::endl;
		std::cout << "Obecnie jest zajête " << _capacity  << std::endl;

		if (_items.size() != 0)
		{
			std::cout << std::endl << "Przedmioty:" << std::endl;
			for (unsigned int i = 0; i < _items.size(); i++)
			{
				_items[i].info();
			}
		}

		if (_weapons.size() != 0)
		{
			std::cout << std::endl << "Bronie:" << std::endl;
			for (unsigned int i = 0; i < _weapons.size(); i++)
			{
				_weapons[i].info();
			}
		}
		std::cout << std::endl;
	}

	void Backpack::add(Weapon w)
	{
		_capacity += w.getWeight();
		_weapons.push_back(w);
		this->checkOverWeigth();
	}

	void Backpack::add(Item i)
	{
		_capacity += i.getWeight();
		_items.push_back(i);
		this->checkOverWeigth();
	}

	void Backpack::itemRemove()
	{
		std::cout << "0 -> powrót" << std::endl;
		for (unsigned int i = 0; i < _items.size(); i++)
		{
			std::cout << i + 1 << " -> ";
			_items[i].info();
		}
		int a;

		do
		{
			std::cin >> a;
		} while (a < 0 || a > (int)_items.size());

		if (a != 0)
		{
			_capacity -= _items[a - 1].getWeight();
			_items.erase(_items.begin() + a - 1);
		}
	}

	void Backpack::weaponRemove()
	{
		std::cout << "0 -> powrót" << std::endl;
		for (unsigned int i = 0; i < _weapons.size(); i++)
		{
			std::cout << i + 1 << " -> ";
			_weapons[i].info();
		}
		int a;
		do
		{
			std::cin >> a;
		} while (a < 0 || a > (int)_weapons.size());

		if (a != 0)
		{
			_capacity -= _weapons[a - 1].getWeight();
			_weapons.erase(_weapons.begin() + a - 1);
		}
	}

	void Backpack::manage()
	{
		std::cout << "Opcje: " << std::endl;
		std::cout << "0 -> powrót" << std::endl;
		std::cout << "1 -> wyrzuæ przedmiot" << std::endl;
		std::cout << "2 -> wyrzuæ broñ" << std::endl;
		int a;
		std::cin >> a;
		if (a == 1) this->itemRemove();
		if (a == 2) this->weaponRemove();
	}

	void Backpack::handleOverWeigth()
	{
		while (_overweigth == true)
		{
			std::cout << "Jestes przeci¹¿ony musisz zwolniæ miejsce." << std::endl;
			std::cout << "Obecnie jest zajête " << _capacity <<  " / " << _maxcapacity << std::endl;
			std::cout << "Wybierz co chcesz usun¹æ." << std::endl << std::endl;
			std::cout << "1 -> item" << std::endl;
			std::cout << "2 -> broñ" << std::endl;

			int a;
			std::cin >> a;

			if (a == 1) this->itemRemove();
			if (a == 2) this->weaponRemove();

			this->checkOverWeigth();
		}
	}

	void Backpack::checkOverWeigth()
	{
		if (_capacity > _maxcapacity) _overweigth = true;
		else _overweigth = false;
	}

	void Backpack::clearItems()
	{
		_items.clear();
	}

	void Backpack::clearWeapons()
	{
		_weapons.clear();
	}

	void Backpack::setMaxCapacity(int m)
	{
		_maxcapacity = m;
	}

	void Backpack::setOverWeigth(bool o)
	{
		_overweigth = o;
	}

	int Backpack::getMaxCapacity()
	{
		return _maxcapacity;
	}

	bool Backpack::getOverWeigth()
	{
		return _overweigth;
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