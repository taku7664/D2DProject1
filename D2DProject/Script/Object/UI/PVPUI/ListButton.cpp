#include "ListButton.h"
#include "Data/Resource/LoadSpriteData.h"

void PVPUI::ListButton::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::PMButton().Load());
	uiSprite->renderOffset.y = 1;
	uiSprite->alpha = 0.5f;
	button = gameObject->AddComponent<Button>();
	button->SetSize(uiSprite->size);
}

void PVPUI::ListButton::Update()
{

}

void PVPUI::ListButton::OnMouseStay()
{
	uiSprite->alpha = 1.f;
}

void PVPUI::ListButton::OnMouseExit()
{
	uiSprite->alpha = 0.5f;
}
