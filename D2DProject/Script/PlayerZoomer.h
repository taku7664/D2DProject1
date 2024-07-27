#pragma once
#include "DemoApp.h"

class CameraController;

class PlayerZoomer
	: public Script
{
public:

	CameraController* cameraController;

	float timer = 0.f;
	float duration = 0.f;
	int index = 0;
	void Start();
	void Update();
};

