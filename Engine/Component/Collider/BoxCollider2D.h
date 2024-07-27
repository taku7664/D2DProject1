#pragma once
#include "Collider.h"

class BoxCollider2D
	: public Collider
{
public:

	BoxCollider2D();
	virtual ~BoxCollider2D();

	virtual bool Draw(Camera2D* _camera) final;

	D2D1_RECT_F ColliderRect();

	Vector2 size;

private:

};

