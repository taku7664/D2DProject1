#pragma once
#include "../../Interface/IUICore.h"
#include "Script/Object/Charactor/CharactorCore.h"

namespace HUD
{
	class UpperHUD;

	class SkillCoolHUD
		: public IUICore
	{
	public:

		int id = -1;

		UpperHUD* owner;
		RectRenderer* coolBar;

		void Start();
		void Update();

	};
}