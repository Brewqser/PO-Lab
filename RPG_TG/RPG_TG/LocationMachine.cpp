#include "LocationMachine.h"

#include <iostream>

#include "Arena.h"
#include "txtManager.h"

namespace TG
{
	LocationMachine::LocationMachine()
	{
		_location = Locations::Bedroom;
		for (int i = 0; i < amountOfLocations; i++)
		{
			_state.push_back(0);
		}

		txtManager::getTxtManager().print("start", 1);
	}

	void LocationMachine::info(Player &pl,bool &gr)
	{
		switch (_location)
		{
		case Locations::Bedroom:
			txtManager::getTxtManager().print("bed", 1);
			
			break;

		case Locations::Kitchen:
			if (_state[Locations::Kitchen] == 0)
			{
				txtManager::getTxtManager().print("kit1", 1);
				txtManager::getTxtManager().print("kit2", 1);
				txtManager::getTxtManager().print("kit3", 1);
			}
			if (_state[Locations::Kitchen] == 1)
			{
				txtManager::getTxtManager().print("kit1", 1);
				txtManager::getTxtManager().print("kit3", 1);
			}
			if (_state[Locations::Kitchen] == 2)
			{
				txtManager::getTxtManager().print("kit1", 1);
				txtManager::getTxtManager().print("kit2", 1);
			}
			if (_state[Locations::Kitchen] == 3)
			{
				txtManager::getTxtManager().print("kit1", 1);
			}

			break;

		case Locations::Garage:

			txtManager::getTxtManager().print("gar", 1);
			break;

		case Locations::Attic:
			if (_state[Locations::Attic] == 0)
			{
				txtManager::getTxtManager().print("att1", 1);
				txtManager::getTxtManager().print("att3", 1);
				txtManager::getTxtManager().print("att2", 1);
			}
			if (_state[Locations::Attic] == 1)
			{

				txtManager::getTxtManager().print("att1", 1);
				txtManager::getTxtManager().print("att3", 1);
			}
			if (_state[Locations::Attic] == 2)
			{
				txtManager::getTxtManager().print("att1", 1);
				txtManager::getTxtManager().print("att2", 1);
			}
			if (_state[Locations::Attic] == 3)
			{
				txtManager::getTxtManager().print("att1", 1);
			}

			break;

		case Locations::Basemant:
			if (_state[Locations::Basemant] == 0)
			{
				txtManager::getTxtManager().print("attmess", 1);
				Arena(pl,3,gr);
				if (pl.getStatistics().getHp() <= 0)
				{
					gr = 0;
				}
				_state[Locations::Basemant] = 1;
			}
			if (_state[Locations::Basemant] == 1 && gr == 1)
			{
				txtManager::getTxtManager().print("bas", 1);
				_state[Locations::Basemant] = 2;
				gr = 0;
			}
		}
	}

	void LocationMachine::manage(States &s ,Backpack &bp)
	{
		txtManager::getTxtManager().print("loc opt", 1);

		int tmp;
		do
		{
			std::cin >> tmp;
		} while (tmp < 1 || tmp > 3);

		if (tmp == 1)
		{
			this->travel();
		}
		if (tmp == 2)
		{
			this->search(bp);
		}
		if (tmp == 3)
		{
			s = States::player;
		}
	}

	void LocationMachine::travel()
	{
		int tmp;
		switch (_location)
		{
		case Locations::Bedroom:

			txtManager::getTxtManager().print("bedt", 1);
			

			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 4);

			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			break;

		case Locations::Kitchen:
			txtManager::getTxtManager().print("kitt", 1);

			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 4);

			if (tmp == 1) _location = Locations::Bedroom;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			break;

		case Locations::Garage:
			txtManager::getTxtManager().print("gart", 1);

			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 4);

			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Bedroom;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
			break;

		case Locations::Attic:
			txtManager::getTxtManager().print("attt", 1);

			do
			{
				std::cin >> tmp;
			} while (tmp < 1 || tmp > 4);

			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Bedroom;
			if (tmp == 4) _location = Locations::Basemant;
			break;

		}
	}

	void LocationMachine::search(Backpack &bp)
	{
		int tmp;
		Weapon w1("Nó¿ kuchenny", 5, 2);
		Weapon w2("Pokrywka", 2, 2);
		Item i1("Stary Banda¿", 3, 2);
		Item i2("Banda¿", 5, 2);

		switch (_location)
		{
		case Locations::Bedroom:
			txtManager::getTxtManager().print("nf", 1);
			break;

		case Locations::Kitchen:
			switch (_state[Locations::Kitchen])
			{
			case 0:
				txtManager::getTxtManager().print("f", 1);
				txtManager::getTxtManager().print("w1", 1);
				txtManager::getTxtManager().print("w2", 1);
				txtManager::getTxtManager().print("take", 1);
				txtManager::getTxtManager().print(0, 1);
				txtManager::getTxtManager().print("nic", 1);
				txtManager::getTxtManager().print(1, 1);
				txtManager::getTxtManager().print(&w1);
				txtManager::getTxtManager().print(2, 1);
				txtManager::getTxtManager().print(&w2);
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 2);

				if (tmp == 1)
				{
					if (bp.add(w1)) _state[Locations::Kitchen] = 2;
				}
				if (tmp == 2)
				{
					if (bp.add(w2)) _state[Locations::Kitchen] = 1;
				}

				break;

			case 1:
				txtManager::getTxtManager().print("f", 1);
				txtManager::getTxtManager().print("w1", 1);
				txtManager::getTxtManager().print("take", 1);
				txtManager::getTxtManager().print(0, 1);
				txtManager::getTxtManager().print("nic", 1);
				txtManager::getTxtManager().print(1, 1);
				txtManager::getTxtManager().print(&w1);
				w1.info();
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 1);

				if (tmp == 1)
				{
					if (bp.add(w1)) _state[Locations::Kitchen] = 3;
				}
				break;

			case 2:
				txtManager::getTxtManager().print("f", 1);
				txtManager::getTxtManager().print("w2", 1);
				txtManager::getTxtManager().print("take", 1);
				txtManager::getTxtManager().print(0, 1);
				txtManager::getTxtManager().print("nic", 1);
				txtManager::getTxtManager().print(1, 1);
				txtManager::getTxtManager().print(&w2);
				w2.info();
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 1);

				if (tmp == 1)
				{
					if (bp.add(w2)) _state[Locations::Kitchen] = 3;
				}
				break;

			case 3:
				txtManager::getTxtManager().print("nf", 1);
				break;
			}

			break;

		case Locations::Garage:
			txtManager::getTxtManager().print("nf", 1);
			break;

		case Locations::Attic:
			switch (_state[Locations::Attic])
			{
			case 0:
				txtManager::getTxtManager().print("f", 1);
				txtManager::getTxtManager().print("i1", 1);
				txtManager::getTxtManager().print("i2", 1);
				txtManager::getTxtManager().print("take", 1);
				txtManager::getTxtManager().print(0, 1);
				txtManager::getTxtManager().print("nic", 1);
				txtManager::getTxtManager().print(1, 1);
				txtManager::getTxtManager().print(&i1);
				txtManager::getTxtManager().print(2, 1);
				txtManager::getTxtManager().print(&i2);
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 2);

				if (tmp == 1)
				{
					if (bp.add(i1)) _state[Locations::Attic] = 2;
				}
				if (tmp == 2)
				{
					if (bp.add(i2)) _state[Locations::Attic] = 1;
				}

				break;

			case 1:

				txtManager::getTxtManager().print("f", 1);
				txtManager::getTxtManager().print("i1", 1);
				txtManager::getTxtManager().print("take", 1);
				txtManager::getTxtManager().print(0, 1);
				txtManager::getTxtManager().print("nic", 1);
				txtManager::getTxtManager().print(1, 1);
				txtManager::getTxtManager().print(&i1);
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 1);

				if (tmp == 1)
				{
					if (bp.add(i1)) _state[Locations::Attic] = 3;
				}
				break;

			case 2:

				txtManager::getTxtManager().print("f", 1);
				txtManager::getTxtManager().print("i2", 1);
				txtManager::getTxtManager().print("take", 1);
				txtManager::getTxtManager().print(0, 1);
				txtManager::getTxtManager().print("nic", 1);
				txtManager::getTxtManager().print(1, 1);
				txtManager::getTxtManager().print(&i2);
				do
				{
					std::cin >> tmp;
				} while (tmp < 0 || tmp > 1);

				if (tmp == 1)
				{
					if (bp.add(i2)) _state[Locations::Attic] = 3;
				}
				break;

			case 3:
				txtManager::getTxtManager().print("nf", 1);
				break;
			}
		}
	}

	void LocationMachine::setLocation(Locations l)
	{
		_location = l;
	}

	void LocationMachine::setState(int s, int i)
	{
		_state[i] = s;
	}

	Locations LocationMachine::getLocation()
	{
		return _location;
	}

	std::vector <int>  &LocationMachine::getState()
	{
		return _state;
	}

}