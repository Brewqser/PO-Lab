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

		void info(Player &pl,bool &gr);
		void manage(States &s, Backpack &bp);
		void travel();
		void search(Backpack &bp);

		void setLocation(Locations l);
		void setState(int s, int i);

		Locations getLocation();
		std::vector <int> &getState();

	private:
		Locations _location;
		std::vector <int> _state;

	};
}

