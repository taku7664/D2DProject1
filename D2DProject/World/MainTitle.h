#pragma once
#include "DemoApp.h"

class MainTitle
	: public World
{
public:
	virtual void WorldLoad() final;
	virtual void WorldDestroy() final;
	virtual void WorldEnter() final;
	virtual void WorldExit() final;
};

