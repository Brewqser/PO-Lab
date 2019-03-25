#include "Item.h"

#include <iostream>

namespace TG
{
	Item::Item()
	{
		_name = "";
		_hpadd = 0;
		_weight = 0;
	}
	Item::Item(std::string name, int hpadd, int weight)
	{
		_name = name;
		_hpadd = hpadd;
		_weight = weight;
	}

	void Item::info()
	{
		if (_name != "")
		{
			std::cout << _name << " (leczenie: " << _hpadd << ", ciê¿ar: " << _weight << ")" << std::endl;
		}
		else
		{
			std::cout << "Brak przedmiotu." << std::endl;
		}
	}

	void Item::setName(std::string n)
	{
		_name = n;
	}

	void Item::setHpadd(int h)
	{
		_hpadd = h;
	}

	void Item::setWeight(int w)
	{
		_weight = w;
	}

	std::string Item::getName()
	{
		return _name;
	}

	int Item::getHpadd()
	{
		return _hpadd;
	}

	int Item::getWeight()
	{
		return _weight;
	}
}