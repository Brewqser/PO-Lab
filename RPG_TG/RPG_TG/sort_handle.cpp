#include "sort_handle.h"
#include <iostream>


namespace TG
{
	sort_handle::sort_handle()
	{
		en = EHandlesort::name;
	}

	void sort_handle::set(int i)
	{
		en = i;
	}

	bool sort_handle::operator()( Weapon i, Weapon j) 
	{
		if (en == EHandlesort::name)
		{
			return i.getName() < j.getName();
		}
		if (en == EHandlesort::weight)
		{
			return i.getWeight() < j.getWeight();
		}
		if (en == EHandlesort::damage)
		{
			return i.getDamage() < j.getDamage();
		}

	}
}