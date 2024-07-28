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
		std::wstring m_key;   // Ű��
		std::wstring m_path;   // Ű��
		ResourceType m_type;    // ���ҽ� Ÿ��
	};
}