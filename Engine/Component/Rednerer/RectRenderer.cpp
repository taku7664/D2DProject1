#include "pch.h"
#include "RectRenderer.h"
#include "../../World/Object/Actor/Actor.h"
#include "../../Render/D2DRender.h"
#include "../Camera2D.h"
#include "../Transform2D.h"

RectRenderer::RectRenderer()
	: isFill(true),
	isLine(true),
	lineWidth(1.f),
	m_fillcolor(D2D1::ColorF(D2D1::ColorF::White)),
	m_linecolor(D2D1::ColorF(D2D1::ColorF::Black))
{
	m_type = ComponentType::RectRenderer;
}

RectRenderer::~RectRenderer()
{
}

bool RectRenderer::Draw(Camera2D* _camera)
{
	ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();
	ID2D1SolidColorBrush* brush = D2DRender::GetBrush();
	D2D1_COLOR_F oldColor = brush->GetColor(); // 기존 색상 저장
	float oldAlpha = brush->GetOpacity(); // 기존 색상 저장
	brush->SetOpacity(alpha);

	renderTarget->SetTransform(CalCulateMatrix(_camera));

	D2D1_RECT_F rect = D2D1::RectF(renderOffset.x, renderOffset.y,
		renderOffset.x + size.x, renderOffset.y + size.y);

	if (isFill)
	{
		brush->SetColor(m_fillcolor);
		
		renderTarget->FillRectangle(rect, brush);
	}

	if (isLine)
	{
		brush->SetColor(m_linecolor);
		renderTarget->DrawRectangle(rect, brush);
	}

	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());

	brush->SetColor(oldColor); // 기존 색상 돌려놓기
	brush->SetOpacity(oldAlpha); // 기존 색상 돌려놓기

	return true;
}

void RectRenderer::SetLineColor(D2D1_COLOR_F _color)
{
	m_linecolor = _color;
}

void RectRenderer::SetFillColor(D2D1_COLOR_F _color)
{
	m_fillcolor = _color;
}

void RectRenderer::SetLine(bool _val)
{
	isLine = _val;
}

void RectRenderer::SetFill(bool _val)
{
	isFill = _val;
}