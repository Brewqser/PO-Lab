#include "Item.h"

Item::Item(string name, int weight, int hpadd)
{
	_name = name;
	_weight = weight;
	_hpadd = hpadd;
}

void Item::info()
{
	cout << _name << " " << _weight << " " << _hpadd << endl;
}

int Item::gethpadd()
{
	return _hpadd;
}

int Item::getweight()
{
	return _weight;
}