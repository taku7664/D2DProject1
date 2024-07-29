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

		FMODPlayer* soundPlayer;
		Resource::FMODSound* sounds[4];

		virtual void Start();
		virtual void Update();
		virtual void OnDestroy();
	};
};