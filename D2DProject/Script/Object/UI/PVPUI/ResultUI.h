#pragma once
#include "../../Interface/IUICore.h"

namespace PVPUI
{
	class ResultUI
		: public IUICore
	{
	public:

		RectRenderer* rect;
		SpriteRenderer2D* exitFont;

		virtual void Start();
		virtual void Update();
		virtual void OnDestroy();

	};
}
