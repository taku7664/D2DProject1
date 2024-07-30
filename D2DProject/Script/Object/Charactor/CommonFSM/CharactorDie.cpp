#include "CharactorDie.h"
#include "Contents.h"
#include "../CharactorCore.h"

void FSM::CharactorDie::Start()
{
	__super::Start();
}

void FSM::CharactorDie::StateEnter()
{
	owner->animator->ChangeAnimation("Hit", false);
	owner->animator->GotoAndPlay(0);
	owner->gravity = -300;
	owner->velocity.x = 200;
	owner->isAirial = true;
	owner->state = CharactorState::Die;
	if (GameMode::CheckWinner())
	{
		Time::timeScale = 0.2f;
	}
}

void FSM::CharactorDie::StateUpdate()
{
	if (owner->isAirial)
	{
		owner->zPos += owner->gravity * Time::deltaTime;
		owner->gravity += owner->weight * owner->gravityScale * Time::deltaTime;
		owner->invCount = 0.f;
		if (owner->gravity > 0)
		{
			if (owner->foot->CheckInteract(owner->body))
			{
				if (startJump < -1.5f)
				{
					startJump *= 0.4f;
					owner->gravity = startJump;
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
					owner->soundPlayer->Play("Die");
					GameMode::deadList.push_back(owner);
					CharactorCore* temp = GameMode::CheckWinner();
					if (temp)
					{
						Time::timeScale = 1.f;
						GameMode::curState = GameProcess::End;
						//owner->body->SetState(GameState::Passive);
					}
				}
			}
		}
	}
}

void FSM::CharactorDie::StateExit()
{
	owner->body->SetState(GameState::Active);
}
