#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Definitions.h"
#include "Engine.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));

	TG::Engine::getEngine().run();

	/*

	int a;
	while (1)
	{
		l.info();
		cin >> a;
		l.travel(a);
	}
	TG::Player p;

	p.info();
	p.manage();
	TG::Backpack bp;

	bp.info();

	bp.add(TG::Weapon("Gun", 123, 4));

	bp.add(TG::Item("FUK", 5, 1));

	bp.add(TG::Item("FUK", 5, 2));

	bp.add(TG::Item("FUK", 5, 3));

	bp.add(TG::Item("FUK", 5, 4));

	bp.info();

	cout << endl;
	bp.itemRemove();

	bp.info();
	bp.handleOverWeigth();
	TG::Weapon wep("bron" ,124, 5);

	wep.info();
	cout << endl;
	TG::Statistics stat(12, 12, "Szczur");
	//stat.updateHP(-8);

	stat.setBaseDamage(10);

	stat.info();

	stat.setBaseDamage(5);

	stat.info();
	
	while ( !TG::Engine::getEngine().getGameOver() )
	{
		TG::Engine::getEngine().update();
	}
	*/
	system("pause");
}