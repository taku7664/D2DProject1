#pragma once
#include "DemoApp.h"

class FadeRect
	: public Script
{
public:

	RectRenderer* fadeRect = nullptr;
	float alpha = 0.f;
	float duration = 1.f;
	int fadeType = 0; // 0 = 대기, -1 = 감소, 1 = 증가

	void Start();
	void Update();

	bool FadeInEnd() { return alpha == 0.f; }
	bool FadeOutEnd() { return alpha == 1.f; }

};

