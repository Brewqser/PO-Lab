#include "Item_NPC_adapter.h"
#include <iostream>

namespace TG
{
	Item_NPC_adapter::Item_NPC_adapter(std::string name, int hp, int lives) : Item (name,hp,lives)
	{
		std::cout << "created NPC base on Item" << std::endl;
	}

	void Item_NPC_adapter::info()
	{
		std::cout << "Name: " << this->getName() << " HP: " << this->getHpadd() << " Lives: " << this->getWeight() << std::endl;
	}
}