#pragma once
#include "../../Interface/IUICore.h"

namespace PVPUI
{
	class SelectMap
		: public IUICore
	{
	public:

		int index;

		virtual void Start();
		virtual void Update();
	};
}