#pragma once
#include "../Object/Charactor/CharactorCore.h"



class AI
	: public CharactorCore
{
public:

	KeyState aiKeys[256];
	std::vector<short> KeyDown_Reset;
	std::vector<short> KeyUp_Reset;

	void Start();
	void Update();
	void LateUpdate();
	void GetKey(bool _down, int _key);
	void ResetKey();

	// 기타 업데이트
	virtual bool TriggerKeyDown(int _trigger);
	virtual bool TriggerKeyHold(int _trigger);
	virtual bool TriggerKeyUp(int _trigger);
};