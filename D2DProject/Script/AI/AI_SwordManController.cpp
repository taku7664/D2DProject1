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
	if (targetTimer <= 0.f)
	{
		while (true)
		{
			Actor* temp = GameMode::playerList[Random::Range(0, GameMode::playerList.size() - 1)];
			if (temp != gameObject)
			{
				owner->target = temp->GetComponent<IObjectCore>();
				targetTimer = Random::Range(20.0f, 30.0f);
				break;
			}
		}
	}

	
}

void AI_SwordManController::FixedUpdate()
{
	if (owner->target)
	{
		
		Vector2 myPos = owner->targetRay->startPos = gameObject->transform->WorldPosition();
		Vector2 targetPos = owner->targetRay->endPos = owner->target->gameObject->transform->WorldPosition();
		targetDistance.x = abs(owner->targetRay->startPos.x - owner->targetRay->endPos.x);
		targetDistance.y = abs(owner->targetRay->startPos.y - owner->targetRay->endPos.y);

		if (moveTimer > 1.f)
		{
			if (targetDistance.x > 300 && targetDistance.y > 200)
			{

			}
			else
			{
				if (Random::Range(0, 1) == 1)
				{
					if (myPos.x > targetPos.x)
					{
						owner->GetKey(KeyType::RIGHT, false);
						if (Random::Range(0, 5) > 1)
							Cmd_Dash(KeyType::LEFT);
						else owner->GetKey(KeyType::LEFT);
					}
					else
					{
						owner->GetKey(KeyType::LEFT, false);
						if (Random::Range(0, 5) > 1)
							Cmd_Dash(KeyType::RIGHT);
						else owner->GetKey(KeyType::RIGHT);
					}
				}
				else
				{
					owner->GetKey(KeyType::LEFT, false);
					owner->GetKey(KeyType::RIGHT, false);
				}
				if (Random::Range(0, 1) == 1)
				{
					if (myPos.y > targetPos.y)
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
			}
			moveTimer = Random::Range(0.0f, 1.0f);
		}
	}
}

void AI_SwordManController::Cmd_Dash(KeyType _key)
{
	owner->commandQueue.push(_key);
	owner->GetKey(_key);
}
