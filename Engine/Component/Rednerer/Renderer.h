#pragma once
#include "../Component.h"

class Actor;
class Object;

class Renderer abstract
	: public Component 
{

public:
	Renderer() = default;
	virtual ~Renderer() = default;

	virtual bool Draw(Camera2D* _camera) { return false; }

	Vector2		 size = { 0,0 };
	Vector2		 renderOffset = { 0,0 }; // ��µ� �� �� �ɼ� (destRect)
	Vector2      centerOffset = { 0,0 }; // �߽����� �ű� �� �ɼ� (�����Ҷ� ���� x)
	Vector2      center;
	float	     alpha = 1.f;

	float Left();
	float Right();
	float Top();
	float Down();

protected:
	D2D1_MATRIX_3X2_F CalCulateMatrix(Camera2D* _camera);
};

