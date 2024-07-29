#pragma once
#include "DemoApp.h"

class AI;

class AI_SwordManController
	: public Script
{
private:

	AI* owner;
	float targetTimer = 0.f;
	Vector2 targetDistance;

public:

	void Start();
	void Update();
	void FixedUpdate();

};

