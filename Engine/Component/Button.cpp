#include "pch.h"
#include "Button.h"
#include "../World/Object/Actor/Actor.h"
#include "../Collision/Manager/ButtonManager.h"
#include "Render/D2DRender.h"

Button::Button()
{
	m_type = ComponentType::Button;
	isEnter = false;
}

Button::~Button()
{
}

void Button::EarlyUpdate()
{
	Vector2 mousePos = Mouse::mousePosition;
	Vector2 ownerPos = gameObject->transform->WorldPosition();

	// ��ư�� �� ���� �ִ� ��ư�� �����ؾ���. Enter, Stay, Exit�� ����.
	if (ownerPos.x - m_buttonSize.x / 2 < mousePos.x &&
		ownerPos.y - m_buttonSize.y / 2 < mousePos.y &&
		ownerPos.x + m_buttonSize.x / 2 > mousePos.x &&
		ownerPos.y + m_buttonSize.y / 2 > mousePos.y)
	{
		ButtonManager::SetTarget(gameObject);
	}
}

void Button::Update()
{
	if (isEnter && ButtonManager::GetTarget() != gameObject)
	{
		for (Component* scr : gameObject->GetComponentList(ComponentType::Script))
		{
			dynamic_cast<Script*>(scr)->OnMouseExit();
		}
		isEnter = false;
	}
}