#include "AI.h"

void AI::Start()
{
	__super::Start();
}

void AI::Update()
{
	__super::Update();
}

void AI::LateUpdate()
{
	__super::LateUpdate();
	ResetKey();
}

void AI::GetKey(bool _down, int _key)
{
	// 딜레이 없게 하려고 
	aiKeys[_key].IsDown = false;
	if (_down == true) {
		if (aiKeys[_key].IsHold == false) {
			aiKeys[_key].IsDown = true;
			aiKeys[_key].IsHold = true;
			KeyDown_Reset.push_back(_key);
		}
	}
	if (_down == false) {
		aiKeys[_key].IsHold = false;
		aiKeys[_key].IsUp = true;
		KeyUp_Reset.push_back(_key);
	}
}

void AI::ResetKey()
{
	while (!KeyDown_Reset.empty())
	{
		aiKeys[KeyDown_Reset.back()].IsDown = false;
		KeyDown_Reset.pop_back();
	}
	while (!KeyUp_Reset.empty())
	{
		aiKeys[KeyUp_Reset.back()].IsUp = false;
		KeyUp_Reset.pop_back();
	}
}

bool AI::TriggerKeyDown(int _trigger)
{
	return false;
}

bool AI::TriggerKeyHold(int _trigger)
{
	return false;
}

bool AI::TriggerKeyUp(int _trigger)
{
	return false;
}
