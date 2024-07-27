#pragma once
#include "Component.h"

class D2DRender;

class Button
	: public Component
{
public:
	Button();
	virtual ~Button();

	virtual void EarlyUpdate() final;
	virtual void Update() final;

	bool& IsEnter() { return isEnter; }
	void  SetSize(Vector2 _size) { m_buttonSize = _size; }

	bool OnPress() { return isEnter&& Mouse::MouseDown(MouseType::LEFT); }
	bool OnHold() { return isEnter&& Mouse::MouseHold(MouseType::LEFT); }
	bool OnRelease() { return isEnter&& Mouse::MouseUp(MouseType::LEFT); }

private:

	static Actor* m_targetObject;
	Vector2 	  m_buttonSize;
	bool		  isEnter;

};