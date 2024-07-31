#include "pch.h"
#include "TextRenderer.h"
#include "Render/D2DRender.h"
#include "../Camera2D.h"
#include "../Transform2D.h"
#include "../../World/Object/Actor/Actor.h"

TextRenderer::TextRenderer()
	:m_font(nullptr),
	m_textSize(20.f),
	m_textColor(D2D1::ColorF(D2D1::ColorF::White)),
	m_textBoldSize(DWRITE_FONT_WEIGHT_NORMAL),
	m_textBox(),
	m_textLayout(nullptr),
	m_text(L"")
{
    m_type = ComponentType::TextRenderer;
}

TextRenderer::~TextRenderer()
{
	if (m_textLayout) m_textLayout->Release();
}

void TextRenderer::Initialize()
{
	UpdateTextLayout();
}

bool TextRenderer::Draw(Camera2D* _camera)
{
	ID2D1BitmapRenderTarget* renderTarget = _camera->GetBitmapRenderTarget();
	ID2D1SolidColorBrush* brush = D2DRender::GetBrush();
	D2D1_COLOR_F oldColor = brush->GetColor(); // 기존 색상 저장
	float oldAlpha = brush->GetOpacity(); // 기존 색상 저장
	brush->SetColor(m_textColor);
	brush->SetOpacity(alpha);

	// 텍스트의 생성 위치와 범위를 설정
	Vector2 ownerPos = gameObject->transform->WorldPosition();
	D2D1_POINT_2F origin = D2D1::Point2F(ownerPos.x, ownerPos.y);

	renderTarget->SetTransform(CalCulateMatrix(_camera));

	renderTarget->DrawTextLayout(origin, m_textLayout, brush);

	renderTarget->SetTransform(D2D1::Matrix3x2F::Identity());
	// 원래 색상 복원
	brush->SetColor(oldColor);
	brush->SetOpacity(oldAlpha); // 기존 색상 돌려놓기

	return true;
}

void TextRenderer::TextSize(float _val)
{
	if (m_textLayout)
	{
		m_textSize = _val;
		m_textLayout->SetFontSize(m_textSize, { 0, (UINT32)m_text.length() });
	}
	else
	{
		assert(false);
	}
}

void TextRenderer::TextSizeToRange(float _val, UINT32 _start, UINT32 _range)
{
	if (_range == -1) _range = m_text.length() - _start;
	if (m_textLayout)
	{
		m_textLayout->SetFontSize(_val, { _start, _range });
	}
	else
	{
		assert(false);
	}
}

void TextRenderer::TextColor(D2D1_COLOR_F _color)
{
	if (m_textLayout)
	{
		m_textColor = _color;
		ID2D1SolidColorBrush* brush = nullptr;
		D2DRender::GetRenderTarget()->CreateSolidColorBrush(m_textColor, &brush);
		m_textLayout->SetDrawingEffect(brush, { 0, (UINT32)m_text.length() });
		brush->Release();
	}
	else
	{
		assert(false);
	}
}

void TextRenderer::TextBold(BoldType _boldtype)
{
	if (m_textLayout)
	{
		m_textBoldSize = (DWRITE_FONT_WEIGHT)_boldtype;
		m_textLayout->SetFontWeight(m_textBoldSize, { 0, (UINT32)m_text.length() });
	}
	else
	{
		assert(false);
	}
}

void TextRenderer::TextColorToRange(D2D1_COLOR_F _color, UINT32 _start, UINT32 _range)
{
	if (_range == -1) _range = m_text.length() - _start;
	if (m_textLayout)
	{
		ID2D1SolidColorBrush* brush = nullptr;
		D2DRender::GetRenderTarget()->CreateSolidColorBrush(_color, &brush);
		m_textLayout->SetDrawingEffect(brush, { _start, _range });
		brush->Release();
	}
	else
	{
		assert(false);
	}
}

void TextRenderer::TextBoldToRange(BoldType _boldtype, UINT32 _start, UINT32 _range)
{
	if (m_textLayout)
	{
		m_textBoldSize = (DWRITE_FONT_WEIGHT)_boldtype;
		m_textLayout->SetFontWeight(m_textBoldSize, { _start, _range });
	}
	else
	{
		assert(false);
	}
}

void TextRenderer::SetText(const wchar_t* _text)
{
	if (m_text != _text)
	{
		m_text = _text;
		UpdateTextLayout();
	}
}

void TextRenderer::SetText(std::wstring _text)
{
	if (m_text != _text)
	{
		m_text = _text;
		UpdateTextLayout();
	}
}

void TextRenderer::SetFont(Resource::Font* _font)
{
	if (m_font != _font)
	{
		m_font = _font;
		m_textLayout->SetFontFamilyName(m_font->GetFontName().c_str(), { 0, (UINT32)m_text.length() });
	}
}

void TextRenderer::UpdateTextLayout()
{

	UINT32 len = m_text.length();

	if (m_textLayout)
	{
		m_textLayout->Release();
		m_textLayout = nullptr;
	}

	HRESULT check;
	if (m_font)
	{
		check = D2DRender::GetWriteFactory()->CreateTextLayout(
			m_text.c_str(),
			len,
			m_font->GetTextFormat(),
			size.x,
			size.y,
			&m_textLayout
		);
	}
	else
	{
		check = D2DRender::GetWriteFactory()->CreateTextLayout(
			m_text.c_str(),
			len,
			D2DRender::GetTextFormat(),
			size.x,
			size.y,
			&m_textLayout
		);
	}
	if (SUCCEEDED(check))
	{
		DWRITE_TEXT_RANGE textRange = { 0, len };

		m_textLayout->SetFontSize(m_textSize, textRange);
		m_textLayout->SetFontWeight(m_textBoldSize, textRange);
		if (m_font) m_textLayout->SetFontFamilyName(m_font->GetFontName().c_str(), textRange);

		ID2D1SolidColorBrush* brush = nullptr;
		D2DRender::GetRenderTarget()->CreateSolidColorBrush(m_textColor, &brush);
		m_textLayout->SetDrawingEffect(brush, textRange);
		if(brush) brush->Release();
	}
}
