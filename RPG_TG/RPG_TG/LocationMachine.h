#pragma once

#include "Definitions.h"

namespace TG
{
	class LocationMachine
	{
	private:
		LocationMachine(const LocationMachine &);

		int _location;

	public:
		LocationMachine();
		~LocationMachine();

		auto getLocation();
		void setLocation(Locations l);

		void print();
		void LocationNet();

	};
}

