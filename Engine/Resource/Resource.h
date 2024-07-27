#pragma once
#include "../Helper/ReferenceCounter.h"

namespace Resource
{
	class Resource abstract
		: public Ref::ReferenceCounter
	{
	public:

		Resource();
		virtual ~Resource();

		std::wstring const GetKey() { return m_key; }

	protected:
		std::wstring m_key;   // Ű��
		ResourceType type;    // ���ҽ� Ÿ��
	};
}