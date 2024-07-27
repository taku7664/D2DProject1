#include "SkillCoolHUD.h"
#include "System/GameMode.h"
#include "UpperHUD.h"
#include "Data/Resource/LoadSpriteData.h"

void HUD::SkillCoolHUD::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::SwordManSkillIcon().Load());

	coolBar = gameObject->AddComponent<RectRenderer>();
	coolBar->size = uiSprite->size;
	coolBar->SetLine(false);
	coolBar->SetFillColor(D2D1::ColorF(D2D1::ColorF::Black));
	coolBar->alpha = 0.5;
	
}

void HUD::SkillCoolHUD::Update()
{
}
