#include "pch.h"
#include "DynamicInput.h"

std::unordered_map<HANDLE, Keys> DynamicInput::m_Keyboards = {};
std::vector<HANDLE> DynamicInput::m_hTable = {};

void DynamicInput::Initialize(HINSTANCE _hinstance)
{
    RAWINPUTDEVICE Rid[1];

    Rid[0].usUsagePage = 0x01;          // HID_USAGE_PAGE_GENERIC
    Rid[0].usUsage = 0x06;              // HID_USAGE_GENERIC_MOUSE
    Rid[0].dwFlags = RIDEV_NOLEGACY;    // adds mouse and also ignores legacy mouse messages
    Rid[0].hwndTarget = 0;

    if (RegisterRawInputDevices(Rid, 1, sizeof(Rid[0])) == FALSE)
    {
        //registration failed. Call GetLastError for the cause of the error
    }
}

void DynamicInput::ResetKey()
{
    for (auto it = m_Keyboards.begin(); it != m_Keyboards.end(); ++it)
    {
        std::vector<int>& down = (*it).second.KeyDown_Reset;
        std::vector<int>& up = (*it).second.KeyUp_Reset;
        while (!down.empty())
        {
            (*it).second.Key_Code[down.back()].IsDown = false;
            down.pop_back();
        }
        while (!up.empty())
        {
            (*it).second.Key_Code[up.back()].IsUp = false;
            up.pop_back();
        }
    }
}

void DynamicInput::GetKey(HRAWINPUT _hri)
{
    UINT dwSize;
    GetRawInputData(_hri, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));

    LPBYTE lpb = new BYTE[dwSize];
    if (lpb == NULL) {
        return;
    }

    if (GetRawInputData(_hri, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER)) != dwSize) {
        delete[] lpb;
        return;
    }

    RAWINPUT* raw = (RAWINPUT*)lpb;
    if (raw->header.dwType == RIM_TYPEKEYBOARD) {
        UINT keyCode = raw->data.keyboard.VKey; // Ű �ڵ�
        HANDLE hDevice = raw->header.hDevice;   // Ű���� �ڵ鰪

        // Ű���� �ڵ��� m_Keyboards�� �ִ��� Ȯ���ϰ� ������ �߰�
        if (m_Keyboards.find(hDevice) == m_Keyboards.end()) {
            // ���ο� Ű���� �ڵ��� �߰��ϰ� �ʱ�ȭ
            m_Keyboards[hDevice] = Keys();
            m_hTable.push_back(hDevice);
        }

        Keys& key = m_Keyboards[hDevice];

        // Ű �̺�Ʈ ó��
        if (raw->data.keyboard.Flags & RI_KEY_BREAK) {
            // Ű�� �������� ��
            key.Key_Code[keyCode].IsHold = false;
            key.Key_Code[keyCode].IsUp = true;
            key.KeyUp_Reset.push_back(keyCode);
        }
        else {
            // Ű�� ������ ��
            key.Key_Code[keyCode].IsDown = true;
            key.Key_Code[keyCode].IsHold = true;
            key.KeyDown_Reset.push_back(keyCode);
        }

        // �޸� ����
        delete[] lpb;
    }
}


bool DynamicInput::KeyDown(int handle, int _code)
{
    if (m_hTable.size() <= handle - 1) return false;
    else return m_Keyboards[m_hTable[handle - 1]].Key_Code[_code].IsDown;
}

bool DynamicInput::KeyDown(int handle, char _code)
{
    if (m_hTable.size() <= handle - 1) return false;
    else return m_Keyboards[m_hTable[handle - 1]].Key_Code[(int)_code].IsDown;
}

bool DynamicInput::KeyHold(int handle, int _code)
{
    if (m_hTable.size() <= handle - 1) return false;
    else return m_Keyboards[m_hTable[handle - 1]].Key_Code[_code].IsHold;
}

bool DynamicInput::KeyHold(int handle, char _code)
{
    if (m_hTable.size() <= handle - 1) return false;
    else return m_Keyboards[m_hTable[handle - 1]].Key_Code[(int)_code].IsHold;
}

bool DynamicInput::KeyUp(int handle, int _code)
{
    if (m_hTable.size() <= handle - 1) return false;
    else  return m_Keyboards[m_hTable[handle - 1]].Key_Code[_code].IsUp;
}

bool DynamicInput::KeyUp(int handle, char _code)
{
    if (m_hTable.size() <= handle - 1) return false;
    else return m_Keyboards[m_hTable[handle - 1]].Key_Code[(int)_code].IsUp;
}