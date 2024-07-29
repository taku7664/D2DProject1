#pragma once

// ����� ���� ����ü
class Debug
{
	static HANDLE m_hConsole;
	static FILE* m_fCout;

public:
	static bool IsActive() { return m_hConsole != nullptr; }

	// �ܼ�â�� ����մϴ�.
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

	// �ܼ�â�� �ݽ��ϴ�.
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
		return true; // �ܼ��� �̹� ���� �ְų� �Ҵ���� ���� ��쿡�� true�� ��ȯ
	}
	// �ܼ��� ����ϴ�.
	static void Clear()
	{
		system("cls");
	}
	// �ܼ� â�� ���ڸ� ����մϴ�.
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