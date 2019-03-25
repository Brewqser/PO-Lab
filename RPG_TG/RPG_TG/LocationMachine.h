#pragma once

#include <vector>

#include "Definitions.h"
#include "Backpack.h"
#include "Player.h"

namespace TG
{
	class LocationMachine
	{
	public:
		LocationMachine();

		void info(Player &pl,bool &gs);
		void travel(int tmp);
		void search(Backpack &bp);

		void setLocation(Locations l);
		void setSearch(int s, int i);

		Locations getLocation();
		std::vector <int> &getSearch();

	private:
		Locations _location;
		std::vector <int> _search;

	};
}

