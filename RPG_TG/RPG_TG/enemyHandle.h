#pragma once

#include <memory>
#include <map>

#include "enemyBody.h"
#include "enemyBody_szczur.h"
#include "enemyBody_mutant.h"

namespace TG
{
	class enemyHandle
	{

	private:
		using BodyPtr = std::unique_ptr <enemyBody>;

		BodyPtr fBodyObj;

	public:

		enum class EHandledEnemyTypes { szczur, mutant };
		
		enemyHandle(EHandledEnemyTypes type);
		void info();

		virtual ~enemyHandle() = default;

	};
}