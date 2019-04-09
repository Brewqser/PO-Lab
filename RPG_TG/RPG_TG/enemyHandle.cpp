#include "enemyHandle.h"


namespace TG
{
	enemyHandle::enemyHandle(EHandledEnemyTypes type)
	{
		switch (type)
		{
		case EHandledEnemyTypes::szczur:
			fBodyObj = std::make_unique <enemyBody_szczur>();

			break;

		case EHandledEnemyTypes::mutant:
			fBodyObj = std::make_unique <enemyBody_mutant>();
			break;

		default:
			break;
		}
	}

	void enemyHandle::info()
	{
		fBodyObj->info();
	}
}