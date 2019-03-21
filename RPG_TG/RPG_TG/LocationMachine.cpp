#include "LocationMachine.h"

namespace TG
{
	LocationMachine::LocationMachine()
	{
		_location = Locations::Ground_Floor;
	}

	LocationMachine::LocationMachine(const LocationMachine &)
	{

	}

	LocationMachine::~LocationMachine()
	{

	}

	Locations LocationMachine::getLocation()
	{
		return _location;
	}

	void LocationMachine::setLocation(Locations l)
	{
		_location = l;
	}
}