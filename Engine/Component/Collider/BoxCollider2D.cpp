#include "pch.h"
#include "BoxCollider2D.h"
#include "../../Render/D2DRender.h"	
#include "../../World/Object/Actor/Actor.h"

BoxCollider2D::BoxCollider2D()
	: size({ 0.f,0.f })
{
	m_type = ComponentType::BoxCollider2D;
}

BoxCollider2D::~BoxCollider2D()
{

}

bool BoxCollider2D::Draw(Camera2D* _camera)
{
	if (Debug::IsActive())
	{
		ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();
		ID2D1SolidColorBrush* brush = D2DRender::GetBrush();
		D2D1_COLOR_F oldColor = brush->GetColor(); // ���� ���� ����

		Transform2D* tr = gameObject->transform;
		if (!tr) assert("transform is Nullptr");

		Vector2 center = { (size.x / 2) + offset.x, (size.y / 2) + offset.y };

		// �߾��� ������ ȸ�� �� ������ ��ȯ ��� ����
		D2D1_MATRIX_3X2_F transform =
			Transform2D::TranslateMatrix(-center.x, -center.y) *
			Transform2D::TranslateMatrix(tr->WorldPosition()) * // ���� ��ȯ ����
			//tr->GetWorldMatrix() * // ���� ��ȯ ����
			//Transform2D::TranslateMatrix(offset.x, offset.y) *
			_camera->CameraMatrix(); // ���������� ī�޶� ��ȯ ����

		renderTarget->SetTransform(transform);

		D2D1_RECT_F dstRect = D2D1::RectF(0, 0, size.x, size.y);

		// �ܰ��� ���
		brush->SetColor(m_rendercolor);
		renderTarget->DrawRectangle(dstRect, brush, m_renderWidth);
		// �߽��� ���
		D2D1_ELLIPSE ellipse = D2D1::Ellipse(D2D1::Point2F(center.x, center.y), 2.f, 2.f);
		renderTarget->DrawEllipse(ellipse, brush, 3.f);

		renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

		brush->SetColor(oldColor); // ���� ���� ��������
		return true;
	}
	return false;
}

D2D1_RECT_F BoxCollider2D::ColliderRect()
{
	Vector2 ownerPos = gameObject->transform->WorldPosition() + offset;
	return D2D1::RectF(
		ownerPos.x - size.x,
		ownerPos.y - size.y,
		ownerPos.x + size.x,
		ownerPos.y + size.y
	);
}
