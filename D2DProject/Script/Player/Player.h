#pragma once
#include "../Object/Charactor/CharactorCore.h"

class CameraController;
class CharactorCore;

struct AIKeys
{

};

class Player
	: public CharactorCore
{
public:

	int inputID = -1;

	CameraController*    camera;  // 메인카메라 뷰
	
	void Start();
	void Update();
	void LateUpdate();

	// 기타 업데이트
	virtual bool TriggerKeyDown(int _trigger);
	virtual bool TriggerKeyHold(int _trigger);
	virtual bool TriggerKeyUp(int _trigger);

};

