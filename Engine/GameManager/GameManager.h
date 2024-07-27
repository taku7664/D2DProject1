#pragma once
#include "../Component/Script.h"

namespace Engine
{
	class GameManager
		: public Script
	{
	public:
		virtual void FixedUpdate() {}
		virtual void EarlyUpdate() {}
		virtual void Update() {}
		virtual void LateUpdate() {}
	};
}
