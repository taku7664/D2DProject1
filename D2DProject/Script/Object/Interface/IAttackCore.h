#pragma once
#include "DemoApp.h"
#include "Data/Skill/SkillData.h"

class IObjectCore;

class IAttackCore
	: public Script
	, public AttackInfo
{
private:
	
public:

	IObjectCore*				owner;
	Vector2						dirVector;
	BoxCollider2D*				HitBox;
	std::vector<IObjectCore*>	collisionArr;

	FMODPlayer*					soundPlayer;
	std::vector<Resource::FMODSound*> effectSounds;
	std::vector<Resource::FMODSound*> hitSounds;

	virtual void Set(IObjectCore* _owner, AttackInfo& _info);
	void SetInfo(const AttackInfo& _info);

	virtual void OnCollisionEnter(Actor* _collision);

	void Clear() { collisionArr.clear(); }
	
	bool IsHit() { return !collisionArr.empty(); }

	float CalculateDamage(IObjectCore* _dest);
	void CreateDamageEffect(IObjectCore* _dest, int _type, int _dmg);
	void CalculateVelocity(IObjectCore* _dest);
	void PlayHitSound();

};