#include "IUICore.h"

void IUICore::Start()
{
	uiSprite = gameObject->AddComponent<SpriteRenderer2D>();
}
