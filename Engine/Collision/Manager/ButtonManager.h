#pragma once
#include "../../World/Manager/WorldManager.h"

class ButtonManager
{
public:

	static void EarlyUpdate();
	static void LateUpdate();

	static void SetTarget(Actor* _target) { m_targetObject = _target; }
	static Actor* GetTarget() { return m_targetObject; }

private:

	static Actor* m_targetObject;

};

