#pragma once
#include "../Component/Script.h"

// 클라이언트에서 상속받아서 사용할 것
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
