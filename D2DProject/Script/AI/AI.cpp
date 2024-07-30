#include "AI.h"

void AI::Start()
{
	__super::Start();

	controller = gameObject->AddComponent<AI_SwordManController>();

	targetRay = gameObject->AddComponent<LineRenderer>();
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

void AI::GetKey(int _key, bool _down)
{
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
	return aiKeys[_trigger].IsDown;
}

bool AI::TriggerKeyHold(int _trigger)
{
	return aiKeys[_trigger].IsHold;
}

bool AI::TriggerKeyUp(int _trigger)
{
	return aiKeys[_trigger].IsUp;
}
