#pragma once
#include "../Helper/ReferenceCounter.h"

namespace Resource
{
	class Resource abstract
		: public Ref::ReferenceCounter
	{
	public:

		Resource(const std::wstring& _key, ResourceType _type)
			: m_key(_key), m_type(_type) {}
		virtual ~Resource();

		std::wstring const GetKey() { return m_key; }

	protected:
		std::wstring m_key;   // 키값
		std::wstring m_path;   // 키값
		ResourceType m_type;    // 리소스 타입
	};
}