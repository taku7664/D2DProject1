#include "Player.h"
#include "../CameraController.h"
#include "System/GameMode.h"

void Player::Start()
{
	inputID = ++GameMode::playerCount;
	__super::Start();
}

void Player::Update()
{
	__super::Update();
}

void Player::LateUpdate()
{ 
	__super::LateUpdate();
}

bool Player::TriggerKeyDown(int _trigger)
{
	return DynamicInput::KeyDown(inputID, _trigger);
}

bool Player::TriggerKeyHold(int _trigger)
{
	return DynamicInput::KeyHold(inputID, _trigger);
}

bool Player::TriggerKeyUp(int _trigger)
{
	return DynamicInput::KeyUp(inputID, _trigger);
}


