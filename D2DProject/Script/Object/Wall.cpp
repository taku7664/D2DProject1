#include "Wall.h"
#include "Interface/IObjectCore.h"

void Wall::Start()
{
	wall = gameObject->AddComponent<BoxCollider2D>();
}

void Wall::OnCollisionStay(Actor* _collision)
{
	IObjectCore* core = _collision->GetComponent<IObjectCore>();
	if (core)
	{
		std::pair<Vector2, float> distance[4];
		std::pair<Vector2, float> minDistance = std::make_pair(Vector2::Zero, 99999.f);
		Vector2 wallPos = gameObject->transform->WorldPosition();
		Vector2 corePos = core->gameObject->transform->WorldPosition();

		// foot : right, wall : left
		distance[0] = std::make_pair(Vector2::Left,
			abs((wallPos.x - (wall->size.x* 0.5)) -
			(corePos.x + core->foot->size.x* 0.5)));
		// foot : bottom, wall : top
		distance[1] = std::make_pair(Vector2::Up,
			abs((wallPos.y - (wall->size.y* 0.5)) -
			(corePos.y + core->foot->size.y* 0.5)));
		// foot : left, wall : right
		distance[2] = std::make_pair(Vector2::Right,
			abs((wallPos.x + (wall->size.x* 0.5)) -
			(corePos.x - core->foot->size.x* 0.5)));
		// foot : top, wall : bottom
		distance[3] = std::make_pair(Vector2::Down,
			abs((wallPos.y + (wall->size.y* 0.5)) -
			(corePos.y - core->foot->size.y* 0.5)));

		for (const std::pair<Vector2, float>& dt : distance)
		{
			if (minDistance.second > dt.second)
				minDistance = dt;
		}

			 if (minDistance.first == Vector2::Left  && core->dirVector.x > 0.0f)	SetLeft(core);
		else if (minDistance.first == Vector2::Up    && core->dirVector.y > 0.0f)	SetTop(core);
		else if (minDistance.first == Vector2::Right && core->dirVector.x < 0.0f)	SetRight(core);
		else if (minDistance.first == Vector2::Down  && core->dirVector.y < 0.0f)	SetBottom(core);

	}
}

void Wall::SetLeft(IObjectCore* _dest)
{
	_dest->gameObject->transform->position.x =
		gameObject->transform->WorldPosition().x
		- (wall->size.x* 0.5)
		- (_dest->foot->size.x* 0.5) ;
}

void Wall::SetTop(IObjectCore* _dest)
{
	_dest->gameObject->transform->position.y =
		gameObject->transform->WorldPosition().y
		- (wall->size.y* 0.5)
		- (_dest->foot->size.y* 0.5) ;
}

void Wall::SetRight(IObjectCore* _dest)
{
	_dest->gameObject->transform->position.x =
		gameObject->transform->WorldPosition().x
		+ (wall->size.x* 0.5)
		+ (_dest->foot->size.x* 0.5) ;
}

void Wall::SetBottom(IObjectCore* _dest)
{
	_dest->gameObject->transform->position.y =
		gameObject->transform->WorldPosition().y
		+ (wall->size.y* 0.5)
		+ (_dest->foot->size.y* 0.5) ;
}
