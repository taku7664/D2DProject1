#include "SelectMap.h"
#include "Data/Resource/LoadSpriteData.h"

void PVPUI::SelectMap::Start()
{
	__super::Start();
	uiSprite->SetSprite(LoadSprite::Select_Map().Load());
}

void PVPUI::SelectMap::Update()
{
}