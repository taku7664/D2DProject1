#include "pch.h"
#include "Collider.h"
#include "../../Collision/Manager/CollisionManager.h"
#include "../../World/Object/Actor/Actor.h"

UINT Collider::CollisionID = 1;

Collider::Collider()
	: isTrigger(false),
	m_id(CollisionID++)
{
}

Collider::~Collider()
{

}

void Collider::OnCollisionEnter(Actor* other)
{
	for (Component*& comp : gameObject->GetComponentList(ComponentType::Script))
	{
		if (comp->GetState() == GameState::Active)
		{
			dynamic_cast<Script*>(comp)->OnCollisionEnter(other);
		}
	}
}

void Collider::OnCollisionStay(Actor* other)
{
	for (Component*& comp : gameObject->GetComponentList(ComponentType::Script))
	{
		if (comp->GetState() == GameState::Active)
		{
			dynamic_cast<Script*>(comp)->OnCollisionStay(other);
		}
	}
}

void Collider::OnCollisionExit(Actor* other)
{
	for (Component*& comp : gameObject->GetComponentList(ComponentType::Script))
	{
		if (comp->GetState() == GameState::Active)
		{
			dynamic_cast<Script*>(comp)->OnCollisionExit(other);
		}
	}
}

bool Collider::CheckInteract(Collider* _dest)
{
	return CollisionManager::GetCollisionID(this, _dest);
}
