#include "pch.h"
#include "LineRenderer.h"
#include "../../Render/D2DRender.h"
#include "../Camera2D.h"
#include "../Transform2D.h"

LineRenderer::LineRenderer()
{
	m_type = ComponentType::LineRenderer;
	lineWidth = 1.f;
	m_linecolor = D2D1::ColorF(D2D1::ColorF::Black);
	startPos = { 0,0 };
	endPos = { 0,0 };
}

LineRenderer::~LineRenderer()
{

}

void LineRenderer::SetLineColor(D2D1_COLOR_F _color)
{
	m_linecolor = _color;
}

bool LineRenderer::Draw(Camera2D* _camera)
{
	ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();
	ID2D1SolidColorBrush* brush = D2DRender::GetBrush();
	D2D1_COLOR_F oldColor = brush->GetColor(); // 기존 색상 저장
	float oldAlpha = brush->GetOpacity(); // 기존 색상 저장

	//Vector2 startPos = startPos;
	//Vector2 endPos = endPos;
	//startPos.x = std::round(startPos.x);
	//startPos.y = std::round(startPos.y);
	//endPos.x = std::round(endPos.x);
	//endPos.y = std::round(endPos.y);

	renderTarget->SetTransform(_camera->CameraMatrix());

	brush->SetColor(m_linecolor);
	brush->SetOpacity(alpha);
	renderTarget->DrawLine(D2D1::Point2F(startPos.x, startPos.y), D2D1::Point2F(endPos.x, endPos.y), brush, lineWidth);

	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	brush->SetColor(oldColor); // 기존 색상 돌려놓기
	brush->SetOpacity(oldAlpha); // 기존 색상 돌려놓기

	return true;
}
