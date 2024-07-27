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

	CameraController*    camera;  // ����ī�޶� ��
	
	void Start();
	void Update();
	void LateUpdate();

	// ��Ÿ ������Ʈ
	virtual bool TriggerKeyDown(int _trigger);
	virtual bool TriggerKeyHold(int _trigger);
	virtual bool TriggerKeyUp(int _trigger);

};

