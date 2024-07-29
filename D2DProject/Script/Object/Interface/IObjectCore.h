#pragma once
#include "Data/Skill/SkillData.h"
#include "Data/Object/ObjectData.h"
#include "../BodyActor.h"

class ObjectData;

struct PVPInfo
{
	float dmgDealt = 0.f;
	float dmgTaken = 0.f;
	int   highCombo = 0;
	float highDmg = 0.f;
	float highAir = 0.f;
	int	  tempCombo = 0;
	float tempDmg = 0.f;
	float tempAir = 0.f;
	void Clear()
	{
		dmgDealt = 0.f;
		dmgTaken = 0.f;
		highCombo = 0;
		highDmg = 0.f;
		highAir = 0.f;
		tempCombo = 0;
		tempDmg = 0.f;
		tempAir = 0.f;
	}
	void Update()
	{
		if (tempCombo >= highCombo) highCombo = tempCombo;
		if (tempDmg >= highDmg) highDmg = tempDmg;
		if (tempAir >= highAir) highAir = tempAir;
	}
};


class IObjectCore
	: public Script
	, public ObjectData
{
public:
	void Start();
	void Update();
	void LateUpdate();
	void OnDestroy();
	BodyActor*			bodyActor;
	BoxCollider2D*		body;
	// 방향 벡터
	Vector2				dirVector; 
	// 컴포넌트
	BoxCollider2D*		foot;
	FiniteStateMachine* fsm;

	FMODPlayer*			soundPlayer;
	std::vector<Resource::FMODSound*> hitVoice;

	// PVP정보
	PVPInfo				pvpInfo;

};