#pragma once

enum Locations
{
	Kitchen,
	Garage,
	Bedroom,
	Attic,
	Basemant
};

const int amountOfLocations = 5;

enum States
{
	select,
	travel,
	player
};