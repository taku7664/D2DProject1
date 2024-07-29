#pragma once
#include "../../Interface/IUICore.h"

namespace PVPUI
{
	class ResultUI
		: public IUICore
	{
	public:
		RectRenderer* rect;

		virtual void Start();
		virtual void Update();

	};
}
