#include "Backpack.h"

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

void Backpack::Info()
{
	cout << "Plecak posiada " << _maxcapacity << " pojemnosci" << endl;
	cout << "Obecnie jest zapelnione " << (double)_capacity * 100.f / (double)_maxcapacity << "% (tj " << _capacity << " / " << _maxcapacity << " )" << endl;

	if (_items.size() != 0)
	{
		cout << endl << "Przedmioty:" << endl;
		for (unsigned int i = 0; i < _items.size(); i++)
		{
			_items[i].info();
		}
	}
	if (_weapons.size() != 0)
	{
		cout << endl << "Bronie:" << endl;
		for (unsigned int i = 0; i < _weapons.size(); i++)
		{
			_weapons[i].info();
		}
	}
	cout << endl;
}

void Backpack::AddItem(Item i)
{
	if (_capacity + i.getweight() <= _maxcapacity)
	{
		_capacity += i.getweight();
		_items.push_back(i);
	}
	// sort _items ?? 

}
void Backpack::RemoveItem(int i)
{
	if( _items.size() != 0)
	{
		_capacity -= _items[i].getweight();
		_items.erase(_items.begin() + i);
	}

	// sort ?? 

}

void Backpack::AddWeapon(Weapon w)
{
	if (_capacity + w.getWeight() <= _maxcapacity)
	{
		_capacity += w.getWeight();
		_weapons.push_back(w);
	}
	// sort ?? 
}

void Backpack::RemoveWeapon(int w)
{
	if (_weapons.size() != 0)
	{
		_capacity -= _weapons[w].getWeight();
		this->_weapons.erase(_weapons.begin() + w);
	}
	// sort ? 
}

void Backpack::Upgrade()
{
	_maxcapacity += 10;
}
