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
	// �߾��� ������ ȸ�� �� ������ ��ȯ ��� ����
	D2D1_MATRIX_3X2_F transform =
		Transform2D::TranslateMatrix(-center.x, -center.y) *     // �̹����� �߽��࿡ �������� ����ؼ� �̵�
		tr->GetWorldMatrix();							    	 // ���� ��ȯ ����
	if(_camera && gameObject->GetTag() != ObjectTag::UI)
		transform = transform * _camera->CameraMatrix();

	return transform;
}
