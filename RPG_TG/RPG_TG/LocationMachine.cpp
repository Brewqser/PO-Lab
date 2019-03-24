#include "LocationMachine.h"

#include <iostream>

#include "Arena.h"

namespace TG
{
	LocationMachine::LocationMachine()
	{
		_location = Locations::Bedroom;
		for (int i = 0; i < amountOfLocations; i++)
		{
			_search.push_back(0);
		}

		std::cout << "Budzisz siÍ w swoim ≥Ûøku." << std::endl;
		std::cout << "Nagle s≥yszysz dziwne düwiÍki dobiekajπce z piwnicy." << std::endl;
		std::cout << "ZdezoriÍtowany wstajesz i przypominasz sobie," << std::endl;
		std::cout << "øe masz schowanie gdzieú w domu coú w razie takiej sytu≥acji." << std::endl << std::endl;
		std::cout << "Sterowanie ( obowiπzuje 'globalnie'):" << std::endl;
		std::cout << "t - menu porusznia" << std::endl;
		std::cout << "p - menu postaci" << std::endl;
		std::cout << "s - przeszukanie danej lokacji" << std::endl;
		std::cout << "inne cyfry i znaki - przemieszcanie siÍ po menu/ lokacjach / itp." << std::endl << std::endl;
	}

	void LocationMachine::info(Player &pl)
	{
		if (_location == Locations::Bedroom)
		{
			std::cout << "Stajesz ko≥o ≥Ûøka i rozglπdasz siÍ." << std::endl;
			std::cout << "Za tobπ znajduje sie szafka nocna." << std::endl;
			std::cout << "Na przeciwko wejúcia wisi ogromne lustro" << std::endl;
			std::cout << "Twojπ uwagÍ przykuwa takøe gazeta wystajπca spod ≥Ûøka." << std::endl;
			std::cout << std::endl;
			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;
		}

		if (_location == Locations::Kitchen)
		{
			if (_search[Locations::Kitchen] == 0)
			{
				std::cout << "Kuchnia wyglπda inaczej niø zwykle." << std::endl;
				std::cout << "Jednakowoø nic nie wydaje siÍ wychodziÊ poza schemat" << std::endl;
				std::cout << "Na kuchence po≥oøony jest garczek" << std::endl;
				std::cout << "Na ladzie ko≥o kuchenki widzisz krÛtki, ale ostry nÛø" << std::endl << std::endl;
			}
			if (_search[Locations::Kitchen] == 1)
			{
				std::cout << "Kuchnia wyglπda inaczej niø zwykle." << std::endl;
				std::cout << "Jednakowoø nic nie wydaje siÍ wychodziÊ poza schemat" << std::endl;
				std::cout << "Na ladzie ko≥o kuchenki widzisz krÛtki, ale ostry nÛø" << std::endl << std::endl;
			}
			if (_search[Locations::Kitchen] == 2)
			{
				std::cout << "Kuchnia wyglπda inaczej niø zwykle." << std::endl;
				std::cout << "Jednakowoø nic nie wydaje siÍ wychodziÊ poza schemat" << std::endl;
				std::cout << "Na kuchence po≥oøony jest garczek" << std::endl << std::endl;
			}
			if (_search[Locations::Kitchen] == 3)
			{
				std::cout << "Kuchnia wyglπda inaczej niø zwykle." << std::endl;
				std::cout << "Jednakowoø nic nie wydaje siÍ wychodziÊ poza schemat" << std::endl << std::endl;

			}
			std::cout << "1 -> Idü do sypialni" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;

		}

		if (_location == Locations::Garage)
		{
			std::cout << "Garaø jak garaø nic tu nie ma oprÛcz wypasionego samochodu" << std::endl;
			std::cout << "A przynajmniej narazie xd." << std::endl << std::endl;

			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do sypialni" << std::endl;
			std::cout << "3 -> Idü na strych" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;
		}

		if (_location == Locations::Attic)
		{
			
			if (_search[Locations::Attic] == 0)
			{
				std::cout << "Wychodzisz po stromych, skrzypiπcych schodach, ktÛre ledwo" << std::endl;
				std::cout << "ale jednak wytrzymujπ twÛj ciÍøar." << std::endl;
				std::cout << "Podnoszπc wie coraz wyøej spoglπdasz na stary fortepian." << std::endl;
				std::cout << "Jednak przez przypadek kierujesz wzrok na inne úmieci ktÛre tam leøπ." << std::endl << std::endl;
			}
			if (_search[Locations::Attic] == 1)
			{
				std::cout << "Wychodzisz po stromych, skrzypiπcych schodach, ktÛre ledwo" << std::endl;
				std::cout << "ale jednak wytrzymujπ twÛj ciÍøar." << std::endl;
				std::cout << "Jednak przez przypadek kierujesz wzrok na inne úmieci ktÛre tam leøπ." << std::endl << std::endl;
			}
			if (_search[Locations::Attic] == 2)
			{
				std::cout << "Wychodzisz po stromych, skrzypiπcych schodach, ktÛre ledwo" << std::endl;
				std::cout << "ale jednak wytrzymujπ twÛj ciÍøar." << std::endl;
				std::cout << "Podnoszπc sie coraz wyøej spoglπdasz na stary fortepian." << std::endl << std::endl;
			}
			if (_search[Locations::Attic] == 3)
			{
				std::cout << "Wychodzisz po stromych, skrzypiπcych schodach, ktÛre ledwo" << std::endl;
				std::cout << "ale jednak wytrzymujπ twÛj ciÍøar." << std::endl << std::endl;
			}

			std::cout << "1 -> Idü do kuchnii" << std::endl;
			std::cout << "2 -> Idü do garaøu" << std::endl;
			std::cout << "3 -> Idü na sypialni" << std::endl;
			std::cout << "4 -> Idü do piwnicy" << std::endl << std::endl;
		}

		if (_location == Locations::Basemant)
		{
			if (_search[Locations::Basemant] == 0)
			{
				// Arena;
				std::cout << "Nartafiasz na 3 szczury." << std::endl << std::endl;
				Arena(pl,3);

				_search[Locations::Basemant] = 1;
			}
			if (_search[Locations::Basemant] == 1)
			{
				std::cout << "Pokona≥eú szczury" << std::endl;
				std::cout << "Dziwne düwiÍki nasilajπ siÍ!?" << std::endl;
				std::cout << "Z zaciekawieniem zaglπdasz do piwnicy." << std::endl;
				std::cout << "Zapalasz úwiat≥o...... " << std::endl;
				std::cout << "Wchodzisz coraz g≥Íbiej." << std::endl;
				std::cout << "Nagle wejúcie zostaje zaczaúniÍte." << std::endl;
				std::cout << "Widzisz ma≥e, s≥odki kotki i umierasz ze szczÍúcia." << std::endl;
				//std::cout << "åwiat≥o zaczyna mrÛgaÊ, widzisz tylko jakieú dziwne cienie." << std::endl;
				//std::cout << "Czujesz potÍøny, k≥ujπcy bul w klatce piersiowej." << std::endl;
				//std::cout << "Umierasz ...... " << std::endl;
				std::cout << "Happy End" << std::endl << std::endl;
			}
		}
	}

	void LocationMachine::travel(int tmp)
	{
		//std::cout << tmp << std::endl;
		if (_location == Locations::Bedroom)
		{
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;

		}
		else if (_location == Locations::Kitchen)
		{
			if (tmp == 1) _location = Locations::Bedroom;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Garage)
		{
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Bedroom;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Basemant;
		}
		else if (_location == Locations::Attic)
		{
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Bedroom;
			if (tmp == 4) _location = Locations::Basemant;
		}
		/*
		if( _location == Locations::Basemant)
		{
			if (tmp == 1) _location = Locations::Kitchen;
			if (tmp == 2) _location = Locations::Garage;
			if (tmp == 3) _location = Locations::Attic;
			if (tmp == 4) _location = Locations::Bedroom;
		}
		*/

		///std::cout << _location << std::endl;
	}

	void LocationMachine::search(Backpack &bp)
	{
		if (_location == Locations::Bedroom)
		{
			std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
		}

		if (_location == Locations::Kitchen)
		{
			if (_search[Locations::Kitchen] == 0)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> NÛø kuchenny" <<  std::endl;
				std::cout << "2 -> Pokrywka" << std::endl  << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Weapon("NÛø kuchenny", 5, 2));
					_search[Locations::Kitchen] = 2;
				}
				if (a == 2)
				{
					bp.add(Weapon("Pokrywka", 2, 2));
					_search[Locations::Kitchen] = 1;
				}
			}
			else if (_search[Locations::Kitchen] == 1)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> NÛø kuchenny" << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ): ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Weapon("NÛø kuchenny", 5, 2));
					_search[Locations::Kitchen] = 3;
				}
			}
			else if (_search[Locations::Kitchen] == 2)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> Pokrywka"  << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Weapon("Pokrywka", 2, 2));
					_search[Locations::Kitchen] = 3;
				}
			}
			else if (_search[Locations::Kitchen] == 3)
			{
				std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
			}

		}

		if (_location == Locations::Garage)
		{
			std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
		}

		if (_location == Locations::Attic)
		{
			if (_search[Locations::Attic] == 0)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> Stary Bandaø" << std::endl;
				std::cout << "2 -> Bandaø" << std::endl  << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Item("Stary Bandaø",3,2));
					_search[Locations::Kitchen] = 2;
				}
				if (a == 2)
				{
					bp.add(Weapon("Bandaø", 5, 2));
					_search[Locations::Kitchen] = 1;
				}
			}
			else if (_search[Locations::Attic] == 1)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> Stary Bandaø"  << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Item("Stary Bandaø", 3, 2));
					_search[Locations::Kitchen] = 3;
				}
			}
			else if (_search[Locations::Attic] == 2)
			{
				std::cout << "Znajdujesz:" << std::endl;
				std::cout << "1 -> Bandaø" << std::endl << std::endl;
				std::cout << "Co bierzesz ( 0 -> nic ) : ";
				int a;
				std::cin >> a;
				if (a == 1)
				{
					bp.add(Weapon("Bandaø", 5, 2));
					_search[Locations::Kitchen] = 3;
				}
			}
			else if (_search[Locations::Attic] == 3)
			{
				std::cout << "Nic nie znajdujesz." << std::endl << std::endl;
			}
		}
		/*
		if (_location == Locations::Basemant)
		{

		}
		*/
	}

	void LocationMachine::setLocation(Locations l)
	{
		_location = l;
	}

	void LocationMachine::setSearch(int s, int i)
	{
		_search[i] = s;
	}

	Locations LocationMachine::getLocation()
	{
		return _location;
	}

	std::vector <int>  &LocationMachine::getSearch()
	{
		return _search;
	}
}