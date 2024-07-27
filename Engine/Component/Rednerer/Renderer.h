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
	Vector2		 renderOffset = { 0,0 }; // 출력될 떄 줄 옵셋 (destRect)
	Vector2      centerOffset = { 0,0 }; // 중심점을 옮길 때 옵셋 (렌더할땐 영향 x)
	Vector2      center;
	float	     alpha = 1.f;

	float Left();
	float Right();
	float Top();
	float Down();

protected:
	D2D1_MATRIX_3X2_F CalCulateMatrix(Camera2D* _camera);
};

