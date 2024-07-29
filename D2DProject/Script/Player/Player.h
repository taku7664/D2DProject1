#pragma once
#include "../Object/Charactor/CharactorCore.h"

class CameraController;
class CharactorCore;

class Player
	: public CharactorCore
{
public:

	int inputID = -1;
	
	void Start();
	void Update();
	void LateUpdate();

	// 기타 업데이트
	virtual bool TriggerKeyDown(int _trigger);
	virtual bool TriggerKeyHold(int _trigger);
	virtual bool TriggerKeyUp(int _trigger);

};

