#pragma once
#include "../../Interface/IUICore.h"

namespace PVPUI
{
	class List;
	class SelectMap;
	class ArrowButton;
	class PVPButton;

	class PVPList
		: public IUICore
	{
	public:
		List* playerList[8] = { nullptr };
		SelectMap* selMap = nullptr;
		ArrowButton* rightArrow = nullptr;
		ArrowButton* leftArrow = nullptr;
		PVPButton* startButton = nullptr;
		PVPButton* replayButton = nullptr;
		PVPButton* exitButton = nullptr;

		virtual void Start();
		virtual void Update();
	};
}
