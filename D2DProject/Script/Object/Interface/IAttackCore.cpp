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
		// =================�浹 ��� ���� Ȯ��=================
		if (!_collision->transform->GetParent()) return;
		if (_collision->GetTag() == ObjectTag::BodyBox)
		{
			// Core�� �ٲٱ� ���� Actor�� ��ȯ (�θ�� ����)
			destAct = dynamic_cast<Actor*>(_collision->transform->GetParent()->gameObject);
			if (!destAct) return;
			if (destAct == owner->gameObject) return; // �ڱ� �ڽ��� ����

			// Core�� ����
			destCore = destAct->GetComponent<IObjectCore>();
			if (!destCore || destCore->hp._cur <= 0.f) return;
			if (owner->gameObject->transform->position.y > destCore->gameObject->transform->position.y + yHitRange * 0.5f ||
				owner->gameObject->transform->position.y < destCore->gameObject->transform->position.y - yHitRange * 0.5f)
				return;
			// �̹� �浹�� ��ü�� Pass
			auto it = std::find(collisionArr.begin(), collisionArr.end(), destCore);
			if (it != collisionArr.end()) return;
			// =================���� ���� �� ���� �˻�=================
			FSM::CharactorHit* fsm = destCore->fsm->ChangeStateAndReturn<FSM::CharactorHit>("Hit");
			if (fsm->isAirbon == true && destCore->zPos == 0.f && !isLow) return;
			// =================������ ���� ����=================
			float resDamage = CalculateDamage(destCore);
			// =================������ ����Ʈ ���=================
			CreateDamageEffect(destCore, 1, resDamage);
			// =================���� ó�� ����=================
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

	// ���߿� ���� ��ų�� ��� �߷� ����
	if (airPower != 0.f)
	{
		// �������� ���̰ų� �ٴڿ� �巯���������� �߷������� ����
		if (_dest->gravity > 150 || (fsm->isAirbon == true && _dest->zPos >= -20.f))
		{
			_dest->gravity = -airPower * 0.5f;
			fsm->owner->animator->GotoAndPlay(1);
		}
		// �ƴϸ� ���� ���� �״�� ����
		else
		{
			_dest->gravity = -airPower;
		}
		fsm->isAirbon = true;
		_dest->velocity *= 0.5;
		if (!fsm->isAirbon) fsm->preHp = _dest->hp._cur;
	}
	// ���߿� ���� ��ų�� �ƴϾ ��밡 ���߿� ���ִ� ���̶�� ���� ����� �Ѵ�.
	else if (airPower == 0.f)
	{
		// ���߿� �� ����
		if (fsm->isAirbon == true)
		{
			_dest->gravity = (_dest->zPos * 1.4f);
			_dest->velocity *= 0.5;
			fsm->isAirbon = true;
			fsm->owner->animator->GotoAndPlay(1);
		}
		// ���߿� ���� �ʾ����� ���� �����ϰ� �⺻ Hit����
		else
		{
			fsm->isAirbon = false;
			fsm->wakeTime = staggerTime;
		}
	}
	fsm->startJump = _dest->gravity;
}
