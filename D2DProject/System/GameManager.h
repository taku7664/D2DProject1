#pragma once
#include "DemoApp.h"
#include "Script/Object/UI/HUD/HUDOwner.h"
#include "Script/Object/FadeRect.h"
#include "Script/Object/UI/HUD/Timer.h"

class FadeRect;

class GameManager
	: public Engine::GameManager
{
public:
	GameManager();
	virtual ~GameManager();

	static FMODPlayer*			BgmPlayer;
	static std::vector<Resource::FMODSound*> bgms;
	static Resource::FMODSound* roomBgm;
	Actor*				HUDs;
	static FadeRect*	fader;
	static HUD::Timer*  timer;

	virtual void Update() final;
};

enum SoundGroup
{
	BackGround,
	Effect,
	Voice,
	GroupSize
};