#pragma once
#include "../Object/Charactor/CharactorCore.h"
#include "AI_SwordManController.h"


class AI
	: public CharactorCore
{
public:

	AI_SwordManController* controller;

	KeyState aiKeys[256];
	std::vector<short> KeyDown_Reset;
	std::vector<short> KeyUp_Reset;

	IObjectCore* target;
	LineRenderer* targetRay;

	void Start();
	void Update();
	void LateUpdate();
	void GetKey(int _key, bool _down = true);
	void ResetKey();

	// 기타 업데이트
	virtual bool TriggerKeyDown(int _trigger);
	virtual bool TriggerKeyHold(int _trigger);
	virtual bool TriggerKeyUp(int _trigger);
};