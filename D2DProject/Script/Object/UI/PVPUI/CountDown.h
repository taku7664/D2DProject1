#pragma once
#include "../../Interface/IUICore.h"

namespace PVPUI
{
	class CountDown
		: public IUICore
	{
	public:
		int count = 0;
		float timer = 0;
		virtual void Start();
		virtual void Update();
		virtual void OnDestroy();
	};
};