#include "Backpack.h"

#include <iostream>
#include <string>

namespace TG
{
	Backpack::Backpack()
	{
		_freeWeigth = 10;
	}

	Backpack::Backpack(int freeWeigth)
	{
		_freeWeigth = freeWeigth;
	}

	void Backpack::info()
	{
		std::cout << "W plecaku zmieœci sie jeszcze  " << _freeWeigth << " wagi." << std::endl << std::endl;

		if (_items.size() != 0)
		{
			std::cout <<  "Przedmioty:" << std::endl;
			for (unsigned int i = 0; i < _items.size(); i++)
			{
				_items[i].info();
			}
			std::cout << std::endl;
		}

		if (_weapons.size() != 0)
		{
			std::cout <<  "Bronie:" << std::endl;
			for (unsigned int i = 0; i < _weapons.size(); i++)
			{
				_weapons[i].info();
			}

			std::cout << std::endl;
		}
	}

	bool Backpack::add(Weapon w)
	{
		if (w.getWeight() <= _freeWeigth)
		{
			std::cout << "Do plecaka dodano " << w.getName() << std::endl << std::endl;
			_weapons.push_back(w);
			_freeWeigth -= w.getWeight();
			return 1;
		}
		else
		{
			std::cout << "Za ma³o miejsca w plecaku. Musisz zwolniæ co najmniej " << w.getWeight() - _freeWeigth << " wagi."<< std::endl << std::endl;
			return 0;
		}

		return 0;
	}

	bool Backpack::add(Item i)
	{
		if (i.getWeight() <= _freeWeigth)
		{
			std::cout << "Do plecaka dodano " << i.getName() << std::endl << std::endl;
			_items.push_back(i);
			_freeWeigth -= i.getWeight();
			return 1;
		}
		else
		{
			std::cout << "Za ma³o miejsca w plecaku. Musisz zwolniæ co najmniej " << i.getWeight() - _freeWeigth << " wagi." << std::endl << std::endl;
			return 0;
		}

		return 0;
	}

	void Backpack::remove()
	{
		std::cout << "Co chcesz usun¹æ: "  << std::endl;
		std::cout << "0 -> nic " << std::endl;
		for (unsigned int i = 0; i < _items.size(); i++)
		{
			std::cout << i + 1 << " -> ";
			_items[i].info();
		}
		for (unsigned int i = 0; i < _weapons.size(); i++)
		{
			std::cout << i + _items.size() + 1 << " -> ";
			_weapons[i].info();
		}
		std::cout << std::endl;


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
		std::cout << "Otwierasz plecak co robisz: " << std::endl;
		std::cout << "0 -> nic " << std::endl;
		std::cout << "1 -> przegl¹dam plecak " << std::endl;
		std::cout << "2 -> zwalniam miejsce " << std::endl;

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