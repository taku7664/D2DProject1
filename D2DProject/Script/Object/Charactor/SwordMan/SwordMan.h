#pragma once
#include "../Charactor.h"

// Script를 상속중
class SwordMan
	: public Charactor
{
public:
	SwordMan(CharactorCore* _core) : Charactor(_core) {}
	virtual void Initialize();
	virtual void Release();
};