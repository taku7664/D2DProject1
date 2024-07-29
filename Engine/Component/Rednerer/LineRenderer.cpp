#include "pch.h"
#include "LineRenderer.h"
#include "../../Render/D2DRender.h"
#include "../Camera2D.h"

LineRenderer::LineRenderer()
{
	m_type = ComponentType::LineRenderer;
	lineWidth = 1.f;
	m_linecolor = D2D1::ColorF(D2D1::ColorF::Black);
	m_startPos = { 0,0 };
	m_endPos = { 0,0 };
}

LineRenderer::~LineRenderer()
{

}

void LineRenderer::SetLineColor(D2D1_COLOR_F _color)
{
	m_linecolor = _color;
}

void LineRenderer::SetLinePosition(Vector2 _startPos, Vector2 _endPos)
{
	m_startPos = _startPos;
	m_endPos = _endPos;
}

void LineRenderer::SetStartPosition(Vector2 _startpos)
{
	m_startPos = _startpos;
}

void LineRenderer::SetEndPosition(Vector2 _endPos)
{
	m_endPos = _endPos;
}

bool LineRenderer::Draw(Camera2D* _camera)
{
	ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();
	ID2D1SolidColorBrush* brush = D2DRender::GetBrush();
	D2D1_COLOR_F oldColor = brush->GetColor(); // 기존 색상 저장
	float oldAlpha = brush->GetOpacity(); // 기존 색상 저장

	Vector2 startPos = m_startPos;
	Vector2 endPos = m_endPos;
	startPos.x = std::round(startPos.x);
	startPos.y = std::round(startPos.y);
	endPos.x = std::round(endPos.x);
	endPos.y = std::round(endPos.y);


	brush->SetColor(m_linecolor);
	renderTarget->DrawLine(D2D1::Point2F(startPos.x, startPos.y), D2D1::Point2F(endPos.x, endPos.y), brush, lineWidth);

	brush->SetColor(oldColor); // 기존 색상 돌려놓기
	brush->SetOpacity(oldAlpha); // 기존 색상 돌려놓기
}
