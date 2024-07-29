#pragma once
#include "DemoApp.h"

class AI;

class AI_SwordManController
	: public Script
{
private:

	AI* owner;
	float targetTimer = 0.f;
	float moveTimer = 10.f;
	Vector2 targetDistance;

	void Cmd_Dash(KeyType _key);

public:

	void Start();
	void Update();
	void FixedUpdate();

};

