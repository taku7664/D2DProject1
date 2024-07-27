#pragma once
#include "../Charactor.h"

// Script를 상속중
class Gunner
	: public Charactor
{
public:
	Gunner(CharactorCore* _core) : Charactor(_core) {}
	virtual void Initialize();
};

