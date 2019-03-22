#include "Item.h"

namespace TG
{
	Item::Item(std::string name, int weight, int hpadd)
	{
		_name = name;
		_weight = weight;
		_hpadd = hpadd;
	}

	void Item::info()
	{
		std::cout << _name << " " << _weight << " " << _hpadd << std::endl;
	}

	int Item::gethpadd()
	{
		return _hpadd;
	}

	int Item::getweight()
	{
		return _weight;
	}

	std::string Item::getName()
	{
		return _name;
	}
}