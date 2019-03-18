#include <iostream>
#include "Backpack.h"

using namespace std;

int main()
{
	Backpack bp;
	//bp.Info();
	bp.AddItem(Item("Large_FA",3,10));
	bp.AddItem(Item("Small_FA", 1, 2));
	bp.AddItem(Item("Medium_FA", 2, 5));
	bp.Info();
	bp.RemoveItem(1);
	bp.Info();
	bp.AddWeapon(Weapon("Glock", 1, 12, 2));
	bp.AddWeapon(Weapon("Bereta", 1, 10, 4));
	bp.AddWeapon(Weapon("AK-47", 1, 30, 5));
	bp.Info();
	bp.RemoveWeapon(2);
	bp.Info();
	system("pause");
}