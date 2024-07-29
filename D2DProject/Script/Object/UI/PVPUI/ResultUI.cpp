#include "ResultUI.h"
#include "Contents.h"

void PVPUI::ResultUI::Start()
{
	__super::Start();
	rect = CreateObject<Actor>("ResRect", LayerTag::UI, ObjectTag::UI)->AddComponent<RectRenderer>();
	rect->size = GameApp::GetScreenSize();
	rect->gameObject->transform->SetParent(gameObject->transform);
	rect->SetLine(false);
	rect->alpha = 0.7f;
	rect->SetFillColor(D2D1::ColorF(D2D1::ColorF::Black));
	gameObject->transform->position = rect->size * 0.5f;
	uiSprite->SetSprite(LoadSprite::ResultUI1().Load(), 1);
	uiSprite->renderOffset = Vector2(10, -170);
	gameObject->depthsLevel = 100;
	rect->gameObject->depthsLevel = gameObject->depthsLevel - 10;
}

void PVPUI::ResultUI::Update()
{

}
