#pragma once

#include "Definitions.h"

namespace TG
{
	class LocationMachine
	{
	private:
		LocationMachine(const LocationMachine &);

		Locations _location;

	public:
		LocationMachine();
		~LocationMachine();

		Locations getLocation();
		void setLocation(Locations l);

			
	};
}

