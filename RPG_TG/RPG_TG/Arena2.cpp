#include "Arena2.h"

namespace TG
{
	Arena2::Arena2(std::string enemy)
	{
		if (enemy == "szczur") _enemy = std::make_unique<enemyHandle>(enemyHandle::EHandledEnemyTypes::szczur);
		if (enemy == "mutant") _enemy = std::make_unique<enemyHandle>(enemyHandle::EHandledEnemyTypes::mutant);


		
		this->fight();
	}

	void Arena2::fight()
	{
		_enemy->info();
	}
}