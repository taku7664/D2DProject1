#pragma once
#include "DemoApp.h"

// GameManager���� ���ҽ��� �̸� �ε���
class NumberFontSprite
	: public Script
{
public:

	std::vector<SpriteRenderer2D*> spriteArr;
	float count = 0.f;
	int number;

	void Start();
	void Update();
	void Set(int _type, int _number);
};

