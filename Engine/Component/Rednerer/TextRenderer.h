#pragma once
#include "Renderer.h"
#include "Resource/Font.h"

class TextRenderer
	: public Renderer
{
public:
	TextRenderer();
	virtual ~TextRenderer();

	virtual void Initialize() final;
	virtual bool Draw(Camera2D* _camera) final;

	void TextSize(float _val);
	void TextColor(D2D1_COLOR_F _color);
	void TextBold(BoldType _boldtype);
	void TextSizeToRange(float _val, UINT32 _start, UINT32 _range = -1);
	void TextColorToRange(D2D1_COLOR_F _color, UINT32 _start, UINT32 _range = -1);
	void TextBoldToRange(BoldType _boldtype, UINT32 _start, UINT32 _range = -1);

	void SetText(const wchar_t* _text);
	void SetText(std::wstring _text);
	void SetFont(Resource::Font* _font);
	std::wstring GetText() { return m_text; }
	Resource::Font* GetFont() { return m_font; }

private:

	Rect_F m_textBox;
	std::wstring m_text;                 // ������ �ؽ�Ʈ
	Resource::Font* m_font;              // ��Ʈ
	float m_textSize;                    // �۾� ũ��
	D2D1_COLOR_F m_textColor;            // �۾� ��
	DWRITE_FONT_WEIGHT m_textBoldSize;   // �۾� ����
	IDWriteTextLayout* m_textLayout;

	void UpdateTextLayout();

};

