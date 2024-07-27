#pragma once
#include "../../Interface/IUICore.h"


namespace PVPUI
{
	class ArrowButton
		: public IUICore
	{
	public:

		Button* button;
		int index = 0;
		int index_ex = 0;

		virtual void Start();
		virtual void Update();

		virtual void OnMouseStay();
		virtual void OnMouseExit();
	};
};