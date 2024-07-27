#include "pch.h"
#include "ButtonManager.h"

Actor* ButtonManager::m_targetObject = nullptr;

void ButtonManager::EarlyUpdate()
{
	if (m_targetObject != nullptr)
	{
		Button* button = m_targetObject->GetComponent<Button>();
		bool& isEnter = button->IsEnter();
		if (!isEnter)
		{
			isEnter = true;
			for (Component* scr : m_targetObject->GetComponentList(ComponentType::Script))
			{
				dynamic_cast<Script*>(scr)->OnMouseEnter();
			}
		}
		else if (isEnter)
		{
			for (Component* scr : m_targetObject->GetComponentList(ComponentType::Script))
			{
				dynamic_cast<Script*>(scr)->OnMouseStay();
			}
		}
	}
}

void ButtonManager::LateUpdate()
{
	m_targetObject = nullptr;
}
