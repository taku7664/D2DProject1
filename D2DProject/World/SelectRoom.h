#pragma once
#include "DemoApp.h"

class SelectRoom
	: public World
{
public:
	virtual void WorldLoad() final;
	virtual void WorldDestroy() final;
	virtual void WorldEnter() final;
	virtual void WorldExit() final;
};

