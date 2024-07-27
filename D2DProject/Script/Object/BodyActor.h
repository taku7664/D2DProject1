#pragma once
#include "DemoApp.h"

class BodyActor
	: public Actor
{
public:
	BodyActor(std::string _name, ObjectTag _tag)
		: Actor(_name, _tag) {}
};

