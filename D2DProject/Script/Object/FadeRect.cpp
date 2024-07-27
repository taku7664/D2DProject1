#include "FadeRect.h"

void FadeRect::Start()
{
	fadeRect = gameObject->AddComponent<RectRenderer>();
	fadeRect->size = GameApp::GetScreenSize() + 1;
	fadeRect->SetFillColor(D2D1::ColorF(D2D1::ColorF::Black));
	fadeRect->SetLine(false);
	gameObject->depthsLevel = 5000;
	gameObject->transform->position = Vector2(400,300);
	gameObject->SetPersistent(true);
}

void FadeRect::Update()
{
	fadeRect->alpha = alpha;

	alpha += ((float)fadeType * Time::deltaTime) / duration;

	if (alpha >= 1.f)
	{
		alpha = 1.f;
		fadeType = 0;
	}
	else if (alpha <= 0.f)
	{
		alpha = 0.f;
		fadeType = 0;
	}

}
