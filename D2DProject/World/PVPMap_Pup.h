#pragma once
#include "PVPMap.h"

class CameraController;

class PVPMap_Pup
	: public PVPMap
{
	
public:
	virtual void WorldLoad() final;
	virtual void WorldDestroy() final;
	virtual void WorldEnter() final;
	virtual void WorldExit() final;
};

