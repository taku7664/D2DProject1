#include "pch.h"
#include "GameApp.h"

bool GameApp::isEnd = false;
Vector2 GameApp::scrennSize = { 0,0 };

void GameApp::Initialize(HINSTANCE _hinstance, int _width, int _height, const wchar_t* _title)
{
	scrennSize = { _width , _height };
	m_hinstance = _hinstance;
	HWND hwnd = InitializeWindow(_width, _height, _title);
	if (!hwnd)
		assert(false && "Fail - InitializeWindow");
	FMODSystem::Initialize();
	D2DRender::Initialize(hwnd);
	Time::Initialize();
	DynamicInput::Initialize(m_hinstance);
}	

void GameApp::Run()
{
	MSG msg;
	while (!isEnd)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			Time::Update();
			Key::Update();
			Mouse::Update();
			FixedUpdate();
			EarlyUpdate();
			Update();
			LateUpdate();
			StateUpdate();
			Render();
			Key::ResetKey();
			DynamicInput::ResetKey();
		}
	}
}

void GameApp::Release()
{
	D2DRender::Release();
	WorldManager::Release();
	if (gameManager) delete gameManager;
}

void GameApp::FixedUpdate()
{
	static float deltaCount;
	deltaCount += Time::deltaTime;
	while (deltaCount >= 0.02f)
	{
		if (CollisionManager::ProcessCycle == 0)
			CollisionManager::CollsionProcess();
		if(gameManager) gameManager->FixedUpdate();
		WorldManager::FixedUpdate();
		deltaCount -= 0.02f;
	}
}

void GameApp::EarlyUpdate()
{
	if(CollisionManager::ProcessCycle == 1)
		CollisionManager::CollsionProcess();
	if (gameManager) gameManager->EarlyUpdate();
	WorldManager::EarlyUpdate();
	ButtonManager::EarlyUpdate();
}

void GameApp::Update()
{
	if (gameManager) gameManager->Update();
	WorldManager::Update();
	FMODSystem::Update();
}

void GameApp::LateUpdate()
{
	if (CollisionManager::ProcessCycle == 2)
		CollisionManager::CollsionProcess();
	if (gameManager) gameManager->LateUpdate();
	WorldManager::LateUpdate();
	ButtonManager::LateUpdate();
}

void GameApp::StateUpdate()
{
	WorldManager::StateUpdate();
}

void GameApp::Render()
{
	D2DRender::BeginDraw();
	WorldManager::Render();
	D2DRender::EndDraw();
}

HWND GameApp::InitializeWindow(int _width, int _height, const wchar_t* _title)
{

	WNDCLASS WndC = {};
	WndC.style = CS_HREDRAW | CS_VREDRAW;
	WndC.lpfnWndProc = WndProc;
	WndC.cbClsExtra = 0;
	WndC.cbWndExtra = 0;
	WndC.hInstance = m_hinstance;
	WndC.hIcon = LoadIcon(m_hinstance, IDI_APPLICATION);
	WndC.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndC.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	WndC.lpszMenuName = NULL;
	WndC.lpszClassName = _title;

	RegisterClass(&WndC);

	// 원하는 클라이언트 영역 크기
	RECT clientRect = { 0, 0, _width, _height };

	// 윈도우 스타일 지정 (메뉴 바 제외)
	DWORD style = WS_OVERLAPPEDWINDOW;
	AdjustWindowRect(&clientRect, style, FALSE);

	int windowWidth = clientRect.right - clientRect.left;
	int windowHeight = clientRect.bottom - clientRect.top;

	HWND hwnd = CreateWindow(
		_title, _title, style,
		CW_USEDEFAULT, CW_USEDEFAULT, windowWidth, windowHeight,
		NULL, NULL, m_hinstance, NULL);

	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	return hwnd;
}

void GameApp::CenterOfScreen(HWND _hwnd)
{
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);

	RECT windowRect;
	GetWindowRect(_hwnd, &windowRect);

	int windowWidth = windowRect.right - windowRect.left;
	int windowHeight = windowRect.bottom - windowRect.top;

	SetWindowPos(_hwnd, NULL,
		(screenWidth - windowWidth) / 2,
		(screenHeight - windowHeight) / 2,
		0, 0, SWP_NOZORDER | SWP_NOSIZE
	);
}

LRESULT GameApp::WndProc(HWND _hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INPUT:
		Key::GetKey(message, wParam);
		DynamicInput::GetKey((HRAWINPUT)lParam);
		break;
		// Alt 키 비활성화용
	case WM_SYSKEYDOWN:
	case WM_SYSKEYUP:
		if (wParam == VK_MENU)
			return 0;
		break;
	case WM_CREATE:
	{
		// 윈도우를 화면 중앙으로 이동
		CenterOfScreen(_hwnd);
	}
	break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	break;
	default:
		return DefWindowProc(_hwnd, message, wParam, lParam);
	}
	return 0;
}