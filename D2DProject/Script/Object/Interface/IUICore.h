#pragma once
#include "DemoApp.h"

class IUICore
	: public Script
{
public:
	SpriteRenderer2D* uiSprite;

	virtual void Start();
};

