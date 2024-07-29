#pragma once
#include "Data/Skill/SkillData.h"
#include "Data/Object/ObjectData.h"
#include "../BodyActor.h"

class ObjectData;

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
	// ¹æÇâ º¤ÅÍ
	Vector2				dirVector; 
	// ÄÄÆ÷³ÍÆ®
	BoxCollider2D*		foot;
	FiniteStateMachine* fsm;

	FMODPlayer*			soundPlayer;

	std::vector<Resource::FMODSound*> hitVoice;

};