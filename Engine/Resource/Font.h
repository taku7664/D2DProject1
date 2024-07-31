#pragma once
#include "Resource.h"

namespace Resource
{
	class Font
		: public Resource
	{
	public:
		Font(std::wstring _key, const std::wstring& _path, ResourceType _type);
		~Font();

		IDWriteFontFile* GetFontFile() const { return m_fontFile; }
		IDWriteTextFormat* GetTextFormat() const { return m_textFormat; }
		std::wstring GetFontName() const { return m_fontName; }
	private:

		IDWriteFontFile* m_fontFile;
		IDWriteTextFormat* m_textFormat;
		std::wstring m_fontName;

	};
}