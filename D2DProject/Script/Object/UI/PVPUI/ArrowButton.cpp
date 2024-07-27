#include "ArrowButton.h"
#include "Data/Resource/LoadSpriteData.h"

void PVPUI::ArrowButton::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::ArrowSheet().Load());
	button = gameObject->AddComponent<Button>();
	button->SetSize(uiSprite->size);
}

void PVPUI::ArrowButton::Update()
{
	uiSprite->index = index + index_ex;
}

void PVPUI::ArrowButton::OnMouseStay()
{
	index_ex = 1;
}

void PVPUI::ArrowButton::OnMouseExit()
{
	index_ex = 0;
}
