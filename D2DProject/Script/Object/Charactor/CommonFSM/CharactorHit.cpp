#include "CharactorHit.h"
#include "../CharactorCore.h"

void FSM::CharactorHit::StateEnter()
{
	owner->animator->ChangeAnimation("Hit", false);
	owner->state = CharactorState::Hit;
	standTime = 0.f;
	preHp = owner->hp._cur;
}

void FSM::CharactorHit::StateUpdate()
{ 
	//=================중력보정 연산=================
	float hpPer = (float)(preHp - owner->hp._cur) / (float)owner->hp._max;
	if (hpPer > 0.3f)
	{
		owner->gravityScale = 2.0f + (hpPer - 0.3) * 3;
	}
	//=================공중에 뜬 상태의 중력연산=================
	if (isAirbon)
	{
		owner->pvpInfo.tempAir += Time::deltaTime;
		owner->animator->Play();
		owner->zPos += owner->gravity * Time::deltaTime;
		owner->gravity += owner->weight * owner->gravityScale * Time::deltaTime;
		if (owner->gravity >= 0)
		{
			if (owner->foot->CheckInteract(owner->body))
			{
				if (startJump < -1.5f)
				{
					startJump *= 0.4f;
					owner->gravity = startJump;
					owner->velocity.x *= 0.5;
					standTime = 0.f;
					owner->zPos = 0.f;
					return;
				}
				else
				{
					owner->isAirial = false;
					owner->zPos = 0.f;
					owner->gravity = 0.f;
					owner->velocity = { 0.f, 0.f };
					standTime += Time::deltaTime;
					if (standTime >= 0.5f)
					{
						FSM->ChangeState("Idle");
						owner->pvpInfo.tempCombo = 0;
						owner->pvpInfo.tempDmg = 0.f;
						owner->pvpInfo.tempAir = 0.f;
						return;
					}
				}
			}
		}
		else standTime = 0.f;
	}
	//=================스탠딩 상태의 중력연산=================
	else
	{
		owner->animator->GotoAndStop(1);
		wakeTime -= Time::deltaTime;
		if (wakeTime <= 0.f)
		{
			FSM->ChangeState("Idle");
			return;
		}
		float delta = Time::GetDeltaTime(200); // 인재원컴 기준 0.9 ~ 1.1언저리 나오는듯?
		if (abs(owner->velocity.x) > 20.0f)
			owner->velocity.x -= (owner->velocity.x * 0.05f) * delta;
		else 
			owner->velocity.x = 0.f;

		if (abs(owner->velocity.y) > 0.1f)
			owner->velocity.y -= (owner->velocity.y * 0.05f) * delta;
		else 
			owner->velocity.y = 0.f;
	}
}

void FSM::CharactorHit::StateExit()
{
	isAirbon = false;
	owner->gravityScale = 1.f;
	owner->isAirial = false;
	owner->zPos = 0.f;
	owner->gravity = 0.f;
	standTime = 0.f;
	owner->invCount = owner->invTime;
}

void FSM::CharactorHit::HitEnter()
{
	if (!owner->hitVoice.empty())
	{
		int hitvoice = Random::Range(0, (int)owner->hitVoice.size() - 1);
		owner->soundPlayer->Play(owner->hitVoice[hitvoice]);
	}
}
