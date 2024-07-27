#include "pch.h"
#include "Renderer.h"
#include "../Transform2D.h"
#include "../Camera2D.h"
#include "../../World/Object/Actor/Actor.h"

float Renderer::Left()
{
	return  gameObject->transform->position.x - (size.x / 2);
}
float Renderer::Right()
{
	return  gameObject->transform->position.x + (size.x / 2);
}
float Renderer::Top()
{
	return gameObject->transform->position.y - (size.y / 2);
}
float Renderer::Down()
{
	return gameObject->transform->position.y + (size.y / 2);
}
D2D1_MATRIX_3X2_F Renderer::CalCulateMatrix(Camera2D* _camera)
{
	Transform2D* tr = gameObject->transform;
	center = { (size.x / 2) + centerOffset.x, (size.y / 2) + centerOffset.y };
	// 중앙을 축으로 회전 및 뒤집기 변환 행렬 설정
	D2D1_MATRIX_3X2_F transform =
		Transform2D::TranslateMatrix(-center.x, -center.y) *     // 이미지의 중심축에 오프셋을 계산해서 이동
		tr->GetWorldMatrix();							    	 // 월드 변환 적용
	if(_camera && gameObject->GetTag() != ObjectTag::UI)
		transform = transform * _camera->CameraMatrix();

	return transform;
}
