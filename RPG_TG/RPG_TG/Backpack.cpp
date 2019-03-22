#include "Backpack.h"

namespace TG
{
	Backpack::Backpack()
	{
		_maxcapacity = 10;
		_capacity = 0;
	}

	Backpack::Backpack(int maxcapacity)
	{
		_maxcapacity = maxcapacity;
		_capacity = 0;
	}

	void Backpack::info()
	{
		std::cout << "Plecak posiada " << _maxcapacity << " pojemnosci" << std::endl;
		std::cout << "Obecnie jest zapelnione " << (double)_capacity * 100.f / (double)_maxcapacity << "% (tj " << _capacity << " / " << _maxcapacity << " )" << std::endl;

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
		if (_capacity + w.getWeight() <= _maxcapacity)
		{
			_capacity += w.getWeight();
			_weapons.push_back(w);
		}
	}

	void Backpack::add(Item i)
	{
		if (_capacity + i.getweight() <= _maxcapacity)
		{
			_capacity += i.getweight();
			_items.push_back(i);
		}
	}
	void Backpack::remove(int i, char co)
	{
		if (co == 'i')
		{
			if (_items.size() != 0)
			{
				_capacity -= _items[i].getweight();
				_items.erase(_items.begin() + i);
			}
		}

		if (co == 'w')
		{
			if (_weapons.size() != 0)
			{
				_capacity -= _weapons[i].getWeight();
				this->_weapons.erase(_weapons.begin() + i);
			}
		}
	}

	void Backpack::showItems()
	{
		for (unsigned int i = 1; i <= _items.size(); i++)
		{
			std::cout << i << " -> " << _items[i - 1].getName() << std::endl;
		}
	}

	void Backpack::showWeapons()
	{
		for (unsigned int i = 1; i <= _weapons.size(); i++)
		{
			std::cout << i << " -> " << _weapons[i - 1].getName() << std::endl;
		}
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