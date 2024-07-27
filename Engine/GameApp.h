#pragma once
#include "pch.h"
#include "Render/D2DRender.h"
#include "World/Manager/WorldManager.h"
#include "Resource/Manager/ResourceManager.h"
#include "Collision/Manager/CollisionManager.h"
#include "Collision/Manager/ButtonManager.h"
#include "GameManager/GameManager.h"

// �ֻ�� �������̽�
// Ŭ���̾�Ʈ ������ GameApp�� include �� ����ؼ� ���� ��� ����� ����� �� �մ�.

class GameApp
{
public:

	void Initialize(HINSTANCE _hinstance, int _width, int _height, const wchar_t* _title);

	void Run();

	void Release();

	static void		GameExit() { isEnd = true; }
	static Vector2  GetScreenSize() { return scrennSize; }

protected:

	Engine::GameManager* gameManager;

	void FixedUpdate();
	void EarlyUpdate();
	void Update();
	void LateUpdate();
	void Render();
	void StateUpdate();

private:

	static bool		isEnd;
	static Vector2  scrennSize;

	HINSTANCE m_hinstance;

	HWND InitializeWindow(int _width, int _height, const wchar_t* _title);

	static void CenterOfScreen(HWND _hwnd);
	static LRESULT CALLBACK WndProc(HWND _hwnd, UINT message, WPARAM wParam, LPARAM lParam);

};

