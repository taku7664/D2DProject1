#include "pch.h"
#include "Font.h"
#include "Render/D2DRender.h"

Resource::Font::Font(std::wstring _key, const std::wstring& _path, ResourceType _type)
    : Resource(_key, _type)
{
    m_path = _path;

    m_fontName = _key;

    HRESULT check;
    // 폰트 파일 참조 생성
    check = D2DRender::GetWriteFactory()->CreateFontFileReference(_path.c_str(), nullptr, &m_fontFile);
    if (FAILED(check)) assert(false);
    // 텍스트 포맷 생성
    check = D2DRender::GetWriteFactory()->CreateTextFormat(
        _path.c_str(),
        nullptr,
        DWRITE_FONT_WEIGHT_NORMAL,
        DWRITE_FONT_STYLE_NORMAL,
        DWRITE_FONT_STRETCH_NORMAL,
        20.0f,
        L"",
        &m_textFormat
    );
    if (FAILED(check)) assert(false);
}

Resource::Font::~Font()
{

}