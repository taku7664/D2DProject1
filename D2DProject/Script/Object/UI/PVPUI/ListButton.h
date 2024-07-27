#pragma once
#include "../../Interface/IUICore.h"

namespace PVPUI
{
	class ListButton
		: public IUICore
	{
	public:

		Button* button;

		virtual void Start();
		virtual void Update();

		virtual void OnMouseStay();
		virtual void OnMouseExit();
	};
};