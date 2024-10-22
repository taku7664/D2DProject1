#pragma once
#include "DemoApp.h"

namespace PVPUI
{
	class ListButton;
	class SelectType;

	class List
		: public Script
	{
	public:
		ListButton* bt;
		SelectType* pt;

		TextRenderer* txt;

		int id = -1;
		virtual void Start();
		virtual void Update();
	};
}
