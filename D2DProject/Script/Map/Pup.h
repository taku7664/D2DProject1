#pragma once
#include "Interface/IMap.h"

namespace MAP
{
	class Pup
		: public IMap
	{
	public:
		virtual void Start();
		virtual void OnDestroy();

		virtual void SetSpawnPoint() final;
	};
}


