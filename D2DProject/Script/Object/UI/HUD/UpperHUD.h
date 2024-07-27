#pragma once
#include "../../Interface/IUICore.h"

#include "SkillCoolHUD.h"

class CharactorCore;
class SkillCoolHUD;

namespace HUD
{
	class UpperHUD
		: public IUICore
	{
	public:

		int id = -1;

		SpriteRenderer2D* hpBar;
		SpriteRenderer2D* mpBar;
		CharactorCore* targetObject;
		SkillCoolHUD* coolBar[20];

		void Start();
		void Update();

		void OnEnable();
		void OnDisable();
	};
}

