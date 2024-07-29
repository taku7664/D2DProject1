#pragma once
#include "Component.h"

// 부모 자식을 Transform에서 관리함.

class Transform2D
	: public Component
{
public:

	Transform2D();
	virtual ~Transform2D();

	// ==============좌표계==============
	Vector2					 position = { 1,1 };
	float					 rotation = 0.f;
	Vector2					 scale = { 1,1 };

	virtual void			 Update() final;
	virtual void			 LateUpdate() final;
	void                     Release();
	// ==============월드 좌표 및 행렬 반환함수==============
	Vector2					 WorldPosition();
	float					 WorldRotation();
	Vector2					 WorldScale();
	D2D1_MATRIX_3X2_F		 GetLocalMatrix() { return m_localMatrix; }
	D2D1_MATRIX_3X2_F		 GetWorldMatrix() { return m_worldMatrix; }
	// ==============기타==============
	void					 SetParent(Transform2D* _parent);
	Transform2D*			 GetParent() { return m_parent; }
	std::vector<Transform2D*>GetChild() { return m_childList; }
	void					 LookAt(Transform2D* _target);
	// ==============행렬 변환 함수==============
	static D2D1_MATRIX_3X2_F TranslateMatrix(float _x, float _y);
	static D2D1_MATRIX_3X2_F TranslateMatrix(Vector2 _xy);
	static D2D1_MATRIX_3X2_F RotationMatrix(float _rotation);
	static D2D1_MATRIX_3X2_F ScaleMatrix(float _xScale, float _yScale);

	// 컴포넌트를 가진 객체 (owner)
	Object* gameObject;

private:

	Transform2D*				    m_parent;         // 부모
	std::vector<Transform2D*>       m_childList;      // 자식리스트
	D2D_MATRIX_3X2_F				m_localMatrix;    // 상대 복합 변환
	D2D_MATRIX_3X2_F				m_worldMatrix;    // 부모까지 반영된 최종 변환

	D2D_MATRIX_3X2_F CalculationWorldTransform();
};

