#pragma once

// 디버그 관련 구조체
class Debug
{
	static HANDLE m_hConsole;
	static FILE* m_fCout;

public:
	static bool IsActive() { return m_hConsole != nullptr; }

	// 콘솔창을 출력합니다.
	static bool Get_Console()
	{
		if (!AllocConsole())
		{
			return false;
		}
		else
		{
			SetConsoleTitle(TEXT("Debug Console"));
			m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			_wfreopen_s(&m_fCout, L"CONOUT$", L"w", stdout);
			Log("Get_Console : Ok");
			return true;
		}
	}

	// 콘솔창을 닫습니다.
	static bool Close_Console()
	{
		if (m_fCout)
		{
			fclose(m_fCout);
			m_fCout = nullptr;
		}
		if (m_hConsole)
		{
			if (FreeConsole())
			{
				m_hConsole = nullptr;
				return true;
			}
			else
			{
				return false;
			}
		}
		return true; // 콘솔이 이미 닫혀 있거나 할당되지 않은 경우에도 true를 반환
	}
	// 콘솔을 지웁니다.
	static void Clear()
	{
		system("cls");
	}
	// 콘솔 창에 문자를 출력합니다.
	static bool Log(const char* _log)
	{
		if (!m_hConsole) return false;
		if (printf_s(_log) <= 0) return false;
		else
		{
			printf_s("\n");
			return true;
		}
	}
	static bool Log(std::string _log)
	{
		if (!m_hConsole) return false;
		if (printf_s(_log.c_str()) <= 0) return false;
		else
		{
			printf_s("\n");
			return true;
		}
	}
	static bool Log(std::wstring _log)
	{
		if (!m_hConsole) return false;
		if (wprintf_s(_log.c_str()) <= 0) return false;
		else
		{
			printf_s("\n");
			return true;
		}
	}
};