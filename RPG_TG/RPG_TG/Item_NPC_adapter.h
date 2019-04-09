#pragma once

#include "Item.h"
#include "NPC.h"

namespace TG
{
	class Item_NPC_adapter : public NPC, public Item
	{
	public:

		Item_NPC_adapter(std::string name, int hp, int lives);

		virtual void info();

	};
}