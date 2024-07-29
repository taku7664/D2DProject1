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
		owner->targetRay->startPos = gameObject->transform->WorldPosition();
		owner->targetRay->endPos = owner->target->gameObject->transform->WorldPosition();
		targetDistance.x = abs(owner->targetRay->startPos.x - owner->targetRay->endPos.x);
		targetDistance.y = abs(owner->targetRay->startPos.y - owner->targetRay->endPos.y);

		if (targetDistance.x > 300 && targetDistance.y > 200)
		{

		}
		else
		{
			owner->GetKey(KeyType::LEFT);
		}
	}
}
