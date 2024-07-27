#include "SelectType.h"
#include "Data/Resource/LoadSpriteData.h"

void PVPUI::SelectType::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::PlayerType().Load());
	uiSprite->alpha = 0.5f;
	button = gameObject->AddComponent<Button>();
	button->SetSize(uiSprite->size);
}

void PVPUI::SelectType::Update()
{
}

void PVPUI::SelectType::OnMouseStay()
{
	uiSprite->alpha = 1.f;
}

void PVPUI::SelectType::OnMouseExit()
{
	uiSprite->alpha = 0.5f;
}
