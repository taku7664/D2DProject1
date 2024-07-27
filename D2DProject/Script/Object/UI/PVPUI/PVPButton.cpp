#include "PVPButton.h"
#include "Data/Resource/LoadSpriteData.h"

void PVPUI::PVPButton::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::ButtonSheet().Load());
	uiSprite->alpha = 0.5f;
	button = gameObject->AddComponent<Button>();
	button->SetSize(uiSprite->size);
}

void PVPUI::PVPButton::Update()
{
	uiSprite->index = index + index_ex;
}

void PVPUI::PVPButton::OnMouseStay()
{
	uiSprite->alpha = 1.f;
}

void PVPUI::PVPButton::OnMouseExit()
{
	uiSprite->alpha = 0.5f;
}
