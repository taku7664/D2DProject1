#include "IAttackCore.h"
#include "Contents.h"
#include "IObjectCore.h"
#include "../Charactor/CommonFSM/CharactorHit.h"
#include "../../Effect/NumberFontSprite.h"

void IAttackCore::Set(IObjectCore* _owner, AttackInfo& _info)
{
	collisionArr.clear();
	owner = _owner;
	HitBox = gameObject->AddComponent<BoxCollider2D>();
	gameObject->transform->position = owner->gameObject->transform->position;
	gameObject->transform->scale.x = owner->bodyActor->transform->scale.x;
	gameObject->transform->scale *= GameMode::skillRangePer;

	SetInfo(_info);
}

void IAttackCore::SetInfo(const AttackInfo& _info)
{
	damagePer = _info.damagePer;
	yHitRange = _info.yHitRange;
	airPower = _info.airPower;
	staggerTime = _info.staggerTime;
	vPower = _info.vPower;
	isLow = _info.isLow;
	singleTarget = _info.singleTarget;
}

void IAttackCore::OnCollisionEnter(Actor* _collision)
{
	if (!singleTarget || (singleTarget && collisionArr.empty()))
	{
		IObjectCore* destCore = nullptr;
		Object* destobj = nullptr;
		Actor* destAct = nullptr;
		// =================충돌 대상 조건 확인=================
		if (!_collision->transform->GetParent()) return;
		if (_collision->GetTag() == ObjectTag::BodyBox)
		{
			// Core로 바꾸기 위해 Actor로 변환 (부모로 접근)
			destAct = dynamic_cast<Actor*>(_collision->transform->GetParent()->gameObject);
			if (!destAct) return;
			if (destAct == owner->gameObject) return; // 자기 자신은 제외

			// Core로 변경
			destCore = destAct->GetComponent<IObjectCore>();
			if (!destCore || destCore->hp._cur <= 0.f) return;
			if (owner->gameObject->transform->position.y > destCore->gameObject->transform->position.y + yHitRange * 0.5f ||
				owner->gameObject->transform->position.y < destCore->gameObject->transform->position.y - yHitRange * 0.5f)
				return;
			// 이미 충돌한 객체면 Pass
			auto it = std::find(collisionArr.begin(), collisionArr.end(), destCore);
			if (it != collisionArr.end()) return;
			// =================상태 변경 및 조건 검사=================
			FSM::CharactorHit* fsm = destCore->fsm->ChangeStateAndReturn<FSM::CharactorHit>("Hit");
			if (fsm->isAirbon == true && destCore->zPos == 0.f && !isLow) return;
			// =================데미지 연산 과정=================
			float resDamage = CalculateDamage(destCore);
			// =================데미지 이펙트 출력=================
			CreateDamageEffect(destCore, 1, resDamage);
			// =================물리 처리 과정=================
			CalculateVelocity(destCore);

			collisionArr.push_back(destCore);
		}
	}
}

float IAttackCore::CalculateDamage(IObjectCore* _dest)
{
	float resDamage = (owner->atk * damagePer);
	resDamage *= Random::Range(80.0f, 100.0f) * 0.01f;
	_dest->hp._cur -= resDamage;
	return resDamage;
}

void IAttackCore::CreateDamageEffect(IObjectCore* _dest, int _type, int _dmg)
{
	Actor* font = CreateObject<Actor>("DamageFontEffect", LayerTag::Particle, ObjectTag::Particle);
	font->AddComponent<NumberFontSprite>()->Set(_type, _dmg);
	font->transform->position = _dest->bodyActor->transform->WorldPosition() + Vector2(0, -80);
}

void IAttackCore::CalculateVelocity(IObjectCore* _dest)
{
	FSM::CharactorHit* fsm = _dest->fsm->ChangeStateAndReturn<FSM::CharactorHit>("Hit");

	_dest->dirVector = Vector2(0, 0);
	_dest->velocity = { vPower.x, vPower.y };
	_dest->bodyActor->transform->scale.x = -gameObject->transform->scale.x;
	_dest->dirVector.x = gameObject->transform->scale.x;

	// 공중에 띄우는 스킬일 경우 중력 적용
	if (airPower != 0.f)
	{
		// 내려오는 중이거나 바닥에 드러누워있으면 중력적용이 절감
		if (_dest->gravity > 150 || (fsm->isAirbon == true && _dest->zPos >= -20.f))
		{
			_dest->gravity = -airPower * 0.5f;
			fsm->owner->animator->GotoAndPlay(1);
		}
		// 아니면 띄우는 힘을 그대로 적용
		else
		{
			_dest->gravity = -airPower;
		}
		fsm->isAirbon = true;
		_dest->velocity *= 0.5;
		if (!fsm->isAirbon) fsm->preHp = _dest->hp._cur;
	}
	// 공중에 띄우는 스킬이 아니어도 상대가 공중에 떠있는 중이라면 조금 띄워야 한다.
	else if (airPower == 0.f)
	{
		// 공중에 뜬 상태
		if (fsm->isAirbon == true)
		{
			_dest->gravity = (_dest->zPos * 1.4f);
			_dest->velocity *= 0.5;
			fsm->isAirbon = true;
			fsm->owner->animator->GotoAndPlay(1);
		}
		// 공중에 뜨지 않았으면 경직 적용하고 기본 Hit적용
		else
		{
			fsm->isAirbon = false;
			fsm->wakeTime = staggerTime;
		}
	}
	fsm->startJump = _dest->gravity;
}
