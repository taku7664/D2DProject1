#pragma once
#include "DemoApp.h"

class IMap;

class PVPMap
	: public World
{
public:
	Actor* map;
	IMap*  mapCore;
	virtual void WorldLoad();
	virtual void WorldDestroy();
	virtual void WorldEnter();
	virtual void WorldExit();
};

