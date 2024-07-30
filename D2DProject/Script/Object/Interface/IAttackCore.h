#pragma once
#include "DemoApp.h"
#include "Data/Skill/SkillData.h"

class CharactorCore;

class IAttackCore
	: public Script
	, public AttackInfo
{
private:
	
public:

	CharactorCore*				owner;
	Vector2						dirVector;
	BoxCollider2D*				HitBox;
	std::vector<CharactorCore*>	collisionArr;

	FMODPlayer*					soundPlayer;
	std::vector<Resource::FMODSound*> effectSounds;
	std::vector<Resource::FMODSound*> hitSounds;

	virtual void Set(CharactorCore* _owner, AttackInfo& _info);
	void SetInfo(const AttackInfo& _info);

	virtual void OnCollisionEnter(Actor* _collision);

	void Clear() { collisionArr.clear(); }
	
	bool IsHit() { return !collisionArr.empty(); }

	float CalculateDamage(CharactorCore* _dest);
	void CreateDamageEffect(CharactorCore* _dest, int _type, int _dmg);
	void CalculateVelocity(CharactorCore* _dest);
	void PlayHitSound();

};