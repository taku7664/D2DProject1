#pragma once
#include "../Charactor.h"

// Script�� �����
class SwordMan
	: public Charactor
{
public:
	SwordMan(CharactorCore* _core) : Charactor(_core) {}
	virtual void Initialize();
	virtual void Release();
};