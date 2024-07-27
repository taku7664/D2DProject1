#pragma once
#include "../../Interface/IUICore.h"

namespace HUD
{
	class Timer
		: public IUICore
	{
	public:

		float timer;
		bool isStart = false;

		SpriteRenderer2D* timeSprite[8];

		void Start();
		void Update();

		void SetTimer(float _time);
		void Play();
		void Stop();
		bool IsEnd();

	};
}
