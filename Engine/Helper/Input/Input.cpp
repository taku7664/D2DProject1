#include "pch.h"
#include "Input.h"
#include "../../Render/D2DRender.h"

std::vector<short> Key::KeyDown_Reset{};
std::vector<short> Key::KeyUp_Reset{};
float			 Key::Horizontal_Axis = 0.f;
float	 		 Key::Vertical_Axis = 0.f;
int		 		 Key::Horizontal_AxisRaw = 0;
int				 Key::Vertical_AxisRaw = 0;
KeyState		 Key::Key_Code[256]{};
MouseState		 Mouse::Cur_Mouse{};
MouseState		 Mouse::Pre_Mouse{};
Vector2			 Mouse::mousePosition = { 0,0 };

// 누른 키보드 값을 저장합니다.
void Key::GetKey(UINT _msg, WPARAM _wParam)
{
	// 딜레이 없게 하려고 
	Key_Code[_wParam].IsDown = false;
	if (_msg == WM_KEYDOWN) {
		if (Key_Code[_wParam].IsHold == false) {
			Key_Code[_wParam].IsDown = true;
			Key_Code[_wParam].IsHold = true;
			KeyDown_Reset.push_back(_wParam);
		}
	}
	if (_msg == WM_KEYUP) {
		Key_Code[_wParam].IsHold = false;
		Key_Code[_wParam].IsUp = true;
		KeyUp_Reset.push_back(_wParam);
	}
}

// 매 업데이트 마지막에 Down이나 Up의 정보들을 초기화시킵니다.
void Key::ResetKey()
{
	while (!KeyDown_Reset.empty())
	{
		Key_Code[KeyDown_Reset.back()].IsDown = false;
		KeyDown_Reset.pop_back();
	}
	while (!KeyUp_Reset.empty()) 
	{
		Key_Code[KeyUp_Reset.back()].IsUp = false;
		KeyUp_Reset.pop_back();
	}
}


// Axis 정보를 갱신합니다.
void Key::Update()
{
	// 키보드 업데이트
	Axis();
	AxisRaw();
}

bool Key::KeyDown(int _code)
{
	return Key_Code[_code].IsDown;
}
bool Key::KeyDown(char _code)
{
	return Key_Code[(int)_code].IsDown;
}
bool Key::KeyDown(KeyType _code)
{
	return Key_Code[(int)_code].IsDown;
}
bool Key::KeyHold(int _code)
{
	return Key_Code[_code].IsHold;
}
bool Key::KeyHold(char _code)
{
	return Key_Code[(int)_code].IsHold;
}
bool Key::KeyHold(KeyType _code)
{
	return Key_Code[(int)_code].IsHold;
}
bool Key::KeyUp(int _code)
{
	return Key_Code[_code].IsUp;
}

bool Key::KeyUp(char _code)
{
	return Key_Code[(int)_code].IsUp;
}

bool Key::KeyUp(KeyType _code)
{
	return Key_Code[(int)_code].IsUp;
}

void Key::Axis()
{
	
	float deltaTime = Time::deltaTime * 3;

	if (Horizontal_Axis >= deltaTime * -1  && Horizontal_Axis <= deltaTime * 1) Horizontal_Axis = 0.f;
	if (Vertical_Axis >= deltaTime * -1  && Vertical_Axis <= deltaTime * 1) Vertical_Axis = 0.f;

	if (Horizontal_Axis >= -1.f && Horizontal_Axis <= 1.f) {
		if (KeyHold(RIGHT)) Horizontal_Axis += deltaTime;
		else if (KeyHold(LEFT)) Horizontal_Axis -= deltaTime;
		else if (Horizontal_Axis != 0.f) Horizontal_Axis += deltaTime * (Horizontal_Axis <= 0 ? 1 : -1);
	}
	if (Horizontal_Axis <= -1.f) Horizontal_Axis = -1.f;
	if (Horizontal_Axis >= 1.f) Horizontal_Axis = 1.f;

	if (Vertical_Axis >= -1.f && Vertical_Axis <= 1.f) {
		if (KeyHold(DOWN)) Vertical_Axis += deltaTime;
		else if (KeyHold(UP)) Vertical_Axis -= deltaTime;
		else if (Vertical_Axis != 0.f) Vertical_Axis += deltaTime * (Vertical_Axis < 0.f ? 1 : -1);
	}
	if (Vertical_Axis <= -1.f) Vertical_Axis = -1.f;
	if (Vertical_Axis >= 1.f) Vertical_Axis = 1.f;
	
}

void Key::AxisRaw()
{
	if (KeyHold(RIGHT)) Horizontal_AxisRaw = 1;
	else if (KeyHold(LEFT)) Horizontal_AxisRaw =- 1;
	else Horizontal_AxisRaw = 0;
	if (KeyHold(DOWN)) Vertical_AxisRaw = 1;
	else if (KeyHold(UP)) Vertical_AxisRaw = -1;
	else Vertical_AxisRaw = 0;
}

float Key::GetAxis(string dir)
{
	if (dir == "Horizontal") return Horizontal_Axis;
	else if (dir == "Vertical") return Vertical_Axis;
	else return 0;
}

int Key::GetAxisRaw(string dir)
{
	if (dir == "Horizontal") return Horizontal_AxisRaw;
	else if (dir == "Vertical") return Vertical_AxisRaw;
	else return 0;
}

void Key::SetAxis(string dir, float value)
{
	if (dir == "Horizontal") Horizontal_Axis = value;
	if (dir == "Vertical") Vertical_Axis = value;
}

void Key::SetAxisRaw(string dir, int value)
{
	if (dir == "Horizontal") Horizontal_AxisRaw = value;
	if (dir == "Vertical") Vertical_AxisRaw = value;
}

void Mouse::Update()
{
	// 마우스 업데이트
	Pre_Mouse = Cur_Mouse;

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(D2DRender::GetHWND(), &pt);

	mousePosition = { (float)pt.x , (float)pt.y };
	Cur_Mouse.Mid = 0;

	Cur_Mouse.Left = (GetKeyState(VK_LBUTTON) & 0x8000) != 0;
	Cur_Mouse.Right = (GetKeyState(VK_RBUTTON) & 0x8000) != 0;
	Cur_Mouse.Mid = (GetKeyState(VK_MBUTTON) & 0x8000) != 0;
}

bool Mouse::MouseDown(MouseType _code)
{
	if (_code == MouseType::RIGHT && !Pre_Mouse.Right) return Cur_Mouse.Right;
	if (_code == MouseType::ROLL && !Pre_Mouse.Mid) return Cur_Mouse.Mid;
	if (_code == MouseType::LEFT && !Pre_Mouse.Left) return Cur_Mouse.Left;
	return false;
}

bool Mouse::MouseHold(MouseType _code)
{
	if (_code == MouseType::RIGHT) return Cur_Mouse.Right;
	if (_code == MouseType::ROLL) return Cur_Mouse.Mid;
	if (_code == MouseType::LEFT) return Cur_Mouse.Left;
	return false;
}

bool Mouse::MouseUp(MouseType _code)
{
	if (_code == MouseType::RIGHT && !Cur_Mouse.Right && Pre_Mouse.Right) return true;
	if (_code == MouseType::ROLL && !Cur_Mouse.Mid && Pre_Mouse.Mid) return true;
	if (_code == MouseType::LEFT && !Cur_Mouse.Left && Pre_Mouse.Left) return true;
	return false;
}
