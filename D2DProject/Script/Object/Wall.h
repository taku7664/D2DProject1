#pragma once
#include "DemoApp.h"

class IObjectCore;

class Wall
	: public Script
{
public:

	BoxCollider2D*  wall;

	void Start();
	void OnCollisionStay(Actor* _collision);

	void SetLeft(IObjectCore* _dest);
	void SetTop(IObjectCore* _dest);
	void SetRight(IObjectCore* _dest);
	void SetBottom(IObjectCore* _dest);
};

