#pragma once
#include "../Charactor.h"

// Script�� �����
class Gunner
	: public Charactor
{
public:
	Gunner(CharactorCore* _core) : Charactor(_core) {}
	virtual void Initialize();
};

