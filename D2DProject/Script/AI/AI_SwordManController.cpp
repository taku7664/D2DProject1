#include "AI_SwordManController.h"
#include "AI.h"
#include "Contents.h"

void AI_SwordManController::Start()
{
	owner = gameObject->GetComponent<AI>();
	if (!owner) assert(false);
}

void AI_SwordManController::Update()
{
	
	targetTimer -= Time::deltaTime;
	moveTimer += Time::deltaTime;
	seedTimer += Time::deltaTime;
	// Å¸°ÙÆÃ
	if (GameMode::curState == GameProcess::Start)
	{
		TargettingLogic();
		if (owner->target)
		{
			Debug::Log(std::to_string(owner->target->zPos));

			Vector2 myPos = owner->targetRay->startPos = gameObject->transform->WorldPosition();
			Vector2 targetPos = owner->targetRay->endPos = owner->target->gameObject->transform->WorldPosition();
			targetDistance.x = abs(owner->targetRay->startPos.x - owner->targetRay->endPos.x);
			targetDistance.y = abs(owner->targetRay->startPos.y - owner->targetRay->endPos.y);

			if (!MoveLogic(myPos, targetPos))
			{
				std::string state = owner->fsm->GetCurrentState()->GetName();
				if (state == "Jump")			  State_Jump(seed);
				else if (state == "BasicAttack1") State_BassicAttack1(seed);
				else if (state == "BasicAttack2") State_BassicAttack2(seed);
				else if (state == "BasicAttack3") State_BassicAttack3(seed);
				else if (state == "Upper")		  State_UpperSlash(seed);
				else if (state == "HardAttack")   State_HardAttack(seed);
				else if (state == "VaneSlash")    State_VaneSlash(seed);
			}
		}
	}
}

void AI_SwordManController::Cmd_Dash(KeyType _key)
{
	owner->commandQueue[1] = _key;
	owner->GetKey(_key);
}

bool AI_SwordManController::MoveLogic(Vector2 _myPos, Vector2 _targetPos)
{
	if (targetDistance.x > 80 + (seed % 40) || targetDistance.y > 20 + (seed % 25))
	{
		if (moveTimer > 1.f)
		{
			Vector2 move;
			move.x = Random::Range(0, 1);
			move.y = Random::Range(0, 1);
			if (move.y == 1)
			{
				if (_myPos.y > _targetPos.y)
				{
					owner->GetKey(KeyType::DOWN, false);
					owner->GetKey(KeyType::UP);
				}
				else
				{
					owner->GetKey(KeyType::UP, false);
					owner->GetKey(KeyType::DOWN);
				}
			}
			else
			{
				owner->GetKey(KeyType::UP, false);
				owner->GetKey(KeyType::DOWN, false);
			}
			if (move.x == 1)
			{
				if (_myPos.x > _targetPos.x)
				{
					owner->GetKey(KeyType::RIGHT, false);
					if (Random::Range(0, 5) != 0)
						Cmd_Dash(KeyType::LEFT);
					else owner->GetKey(KeyType::LEFT);
				}
				else
				{
					owner->GetKey(KeyType::LEFT, false);
					if (Random::Range(0, 5) != 0)
						Cmd_Dash(KeyType::RIGHT);
					else owner->GetKey(KeyType::RIGHT);
				}
			}
			else
			{
				owner->GetKey(KeyType::LEFT, false);
				owner->GetKey(KeyType::RIGHT, false);
			}
			owner->GetKey(owner->input.x, false);
			owner->GetKey(owner->input.z, false);
			owner->GetKey(owner->input.QuickKey[1], false);

			if (Random::Range(0, 5) == 0)
			{
				owner->GetKey(owner->input.c);
			}
			else if (move == Vector2::Zero) curLogic = Idle;
			moveTimer = Random::Range(0.0f, 1.0f);
			return true;
		}
	}
	else
	{
		if (owner->animator->End() && (owner->state == CharactorState::Move || owner->state == CharactorState::Idle))
		{
			if (_myPos.x > _targetPos.x)
				owner->bodyActor->transform->scale.x = -1.f;
			else owner->bodyActor->transform->scale.x = 1.f;
		}
		
		int seed = Random::Range(0, 10);
		if (seed < 4)
		{
			owner->GetKey(owner->input.x);
		}
		else if (seed < 7)
		{
			if (owner->target->zPos > -40)
				owner->GetKey(owner->input.QuickKey[1]);
		}
		else if (seed < 10)
		{
			owner->GetKey(owner->input.z);
		}
	}
	return false;
}

void AI_SwordManController::TargettingLogic()
{
	if ((targetTimer <= 0.f && GameMode::playerList.size() >= 2) || !owner->target)
	{
		while (true)
		{
			IObjectCore* temp = GameMode::playerList[Random::Range(0, GameMode::playerList.size() - 1)];
			if (temp->gameObject != gameObject)
			{
				owner->target = temp;
				targetTimer = Random::Range(10.0f, 20.0f);
				seed = Random::Range(0, 100);
				if(owner->target->hp._cur > 0.f) break;
			}
		}
	}
}

void AI_SwordManController::State_Jump(int _seed)
{
	owner->GetKey(owner->input.c, false);
	if (owner->target)
	{
		if (owner->target->zPos < -40)
		{
			owner->GetKey(owner->input.x);
		}
	}
}

void AI_SwordManController::State_BassicAttack1(int _seed)
{
	owner->GetKey(owner->input.x);
}

void AI_SwordManController::State_BassicAttack2(int _seed)
{
	if (owner->animator->currentFrame > 6)
	{
		if (_seed % 10 > 5)
		{
			owner->GetKey(owner->input.z);
		}
		else
		{
			owner->GetKey(owner->input.x); return;
		}
		owner->GetKey(owner->input.x, false);
	}
}

void AI_SwordManController::State_BassicAttack3(int _seed)
{
	owner->GetKey(owner->input.x, false);
	if(owner->animator->currentFrame > 6)
		owner->GetKey(owner->input.QuickKey[2]);
}

void AI_SwordManController::State_UpperSlash(int _seed)
{
	owner->GetKey(owner->input.z, false);
	owner->GetKey(owner->input.QuickKey[1], false);
	owner->GetKey(owner->input.x, false);
	if (owner->target)
	{
		if (owner->target->zPos < -30)
		{
			owner->GetKey(owner->input.c);
		}
	}
}

void AI_SwordManController::State_HardAttack(int _seed)
{
	owner->GetKey(owner->input.QuickKey[1], false);
	owner->GetKey(owner->input.z);
}

void AI_SwordManController::State_VaneSlash(int _seed)
{
	owner->GetKey(owner->input.QuickKey[2], false);
	owner->GetKey(owner->input.z);
}
