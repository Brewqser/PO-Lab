#include <string>
#include <cstdlib>
#include <ctime>

#include "Engine.h"
#include "txtManager.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	TG::Engine::getEngine().run();


	/*
	TG::Statistics s;
	s.info();
	s.updateHP(-123);
	s.info();
	
	TG::txtManager::getTxtManager().print("endl",0);
	TG::Item i1;
	TG::Item i("Asd", 12, 51);
	i.info();
	i1.info();

	TG::txtManager::getTxtManager().print("endl",0);
	TG::Weapon w1;
	TG::Weapon w("ASD", 1314141, 123);
	w.info();
	w1.info();

	
	//
	
	TG::Player p(13, 123);
	p.getBackpack().add(TG::Weapon("aaa", 12, 3));
	p.getBackpack().add(TG::Weapon("bbb", 123, 13));
	p.getBackpack().add(TG::Weapon("ccc", 51, 8));
	p.getBackpack().add(TG::Weapon("ddd", 69, 9));

	p.getBackpack().add(TG::Item("a", 12, 3));
	p.getBackpack().add(TG::Item("b", 1, 1));
	p.getBackpack().add(TG::Item("c", 14, 0));
	p.getBackpack().add(TG::Item("d", 69, 13));

	p.info();
	

	TG::Player p(1, 131);
	bool gr = 1;

	TG::LocationMachine l;
	States s = States::travel;

	while (gr)
	{
		l.info(p,gr);
		if (gr) l.manage(s,p.getBackpack());
	}

	TG::Player p(1, 131);
	p.getBackpack().add(TG::Weapon("aaa", 12, 3));
	p.getBackpack().add(TG::Weapon("bbb", 123, 13));
	p.getBackpack().add(TG::Weapon("ccc", 51, 8));
	p.getBackpack().add(TG::Weapon("ddd", 69, 9));

	p.getBackpack().add(TG::Item("a", 12, 3));
	p.getBackpack().add(TG::Item("b", 1, 1));
	p.getBackpack().add(TG::Item("c", 14, 0));
	p.getBackpack().add(TG::Item("d", 69, 13));
	bool go = 1;

	TG::Arena(p, 3,go );
	*/

	/*
	TG::Enemy e("asd", 12, 41, 3);

	e.info();
	e.info();
	e.info();
	*/
	/*
	TG::Player p(13,123);
	p.getBackpack().add(TG::Weapon("aaa", 12, 3));
	p.getBackpack().add(TG::Weapon("bbb", 123, 13));
	p.getBackpack().add(TG::Weapon("ccc", 51, 8));
	p.getBackpack().add(TG::Weapon("ddd", 69, 9));

	p.getBackpack().add(TG::Item("a", 12, 3));
	p.getBackpack().add(TG::Item("b", 1, 1));
	p.getBackpack().add(TG::Item("c", 14, 0));
	p.getBackpack().add(TG::Item("d", 69, 13));

	bool go = 1;
	while (go)
	{
		p.info();
		p.manage(go);
		if (go)
		{
			system("pause");
			std::cout << "////////////////////////////////////////////////////////////////////////////" << std::endl;
		}
	}
	*/


	/*

	TG::Backpack b;
	b.info();

	b.add(TG::Weapon("bbb", 1234, 5));

	b.info();

	b.add(TG::Item("aaa", 1234, 5));


	b.info();

	b.add(TG::Weapon("aqef", 0, 5));

	b.info();

	b.remove();

	b.info();

	b.add(TG::Weapon("aaasdad", 1214, 41));

	b.info();

	b.add(TG::Item("aadadaf", 0, 5));

	b.info();

	b.manage();

	TG::Weapon w("ASD", 1314141, 123);

	w.info();
	w.info();
	TG::Item i("Asd",12,51);

	i.info();
	i.info();

	
	*/
	system("pause");
}