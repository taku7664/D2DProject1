#pragma once
#include "DemoApp.h"
#include "UpperHUD.h"

class FadeRect;

namespace HUD
{
	class HUDOwner
		: public Script
	{
	public:

		UpperHUD* upperHUDs[8];

		virtual void Start();
		virtual void Update();

	};
}

