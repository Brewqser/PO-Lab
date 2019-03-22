#pragma once

#include "Definitions.h"

namespace TG
{
	class LocationMachine
	{
	private:
		LocationMachine(const LocationMachine &);

		Locations _location;
		bool _movedone;
		bool _visited[amountOfLocations];

	public:
		LocationMachine();
		~LocationMachine();

		Locations getLocation();
		void setLocation(Locations l);

		void print();
		void locationNet();
		void move(int tmp);

		bool getMoveDone();
		void resetMoveDone();
		void setMoveDone();

	};
}

