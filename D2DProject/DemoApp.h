#pragma once
#include "../Engine/GameApp.h"

class DemoApp
	: public GameApp
{
public:

	DemoApp() {}
	~DemoApp() {}

	virtual void Initialize(HINSTANCE _hinstance, int _width, int _height, const wchar_t* _title) final;
	virtual void Release();
	void LoadWorld();
	void LoadResource();

};