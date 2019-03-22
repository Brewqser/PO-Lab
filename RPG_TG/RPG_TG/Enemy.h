#pragma once

#include <string>

#include "Engine.h"
#include "Statistics.h"

namespace TG
{
	class Enemy
	{
	private:
		Statistics _statistics;

	public:
		Enemy();
		Enemy(std::string name, int hp, int damage);

		Statistics &getStatistics();
		void attac();
	};
}

