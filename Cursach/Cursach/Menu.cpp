#include "Defs.h"

MainMenu::MainMenu() {}
MainMenu::~MainMenu() {}

void MainMenu::AddMainMenu(HWND hWnd)
{
	RECT _mainRect;
	GetClientRect(hWnd, &_mainRect);
	int _LEFT = (_mainRect.right - 250) / 2;
	int _TOP = (_mainRect.bottom - 60) / 6;

	_PlayBtn = CreateWindowA(
		"button",
		"Play",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		_LEFT, _TOP, 250, 60,
		hWnd,
		(HMENU)COMMANDS::OnPlayClicked,
		GetModuleHandle(0), NULL
	);

	_DownloadBtn = CreateWindowA(
		"button",
		"Download",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		_LEFT, _TOP * 2, 250, 60,
		hWnd,
		(HMENU)COMMANDS::OnDownLoadClicked,
		GetModuleHandle(0), NULL
	);

	_StatBtn = CreateWindowA(
		"button",
		"Statistics",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		_LEFT, _TOP * 3, 250, 60,
		hWnd,
		(HMENU)COMMANDS::OnStatisticsClicked,
		GetModuleHandle(0), NULL
	);

	_SettBtn = CreateWindowA(
		"button",
		"Settings",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		_LEFT, _TOP * 4, 250, 60,
		hWnd,
		(HMENU)COMMANDS::OnSettingsClicked,
		GetModuleHandle(0), NULL
	);

	_ExitBtn = CreateWindowA(
		"button",
		"Exit",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		_LEFT, _TOP * 5, 250, 60,
		hWnd,
		(HMENU)COMMANDS::OnExitClicked,
		GetModuleHandle(0), NULL
	);

}

void MainMenu::ExitApp()
{
	PostQuitMessage(0);
}

std::pair<bool, HWND> MainMenu::AddWindow(const std::wstring&& _WndClass, const std::wstring&& _Title, HWND _hWnd, const WNDPROC _callback)
{
	UnregisterClass(_WndClass.c_str(), GetModuleHandle(0));
	WNDCLASSEX WC{ sizeof(WNDCLASSEX) };
	HWND _hWindow;
	WC.cbClsExtra = 0;
	WC.cbWndExtra = 0;
	WC.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	WC.hCursor = LoadCursor(NULL, IDC_ARROW);
	WC.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WC.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	WC.lpfnWndProc = _callback;
	WC.lpszClassName = _WndClass.c_str();
	WC.style = CS_VREDRAW | CS_HREDRAW;

	const auto Create_Window = [&_hWindow, &_WndClass, &_Title, &_hWnd]() -> std::pair<bool, HWND> {
		if (_hWindow = CreateWindow(_WndClass.c_str(), _Title.c_str(), WS_OVERLAPPED
			| WS_VISIBLE | WS_CAPTION | WS_SYSMENU, 0, 0, 900, 600, NULL, NULL, NULL, NULL), !_hWindow)
		{
			return { false, nullptr };
		}
		
		ShowWindow(_hWindow, SW_SHOWDEFAULT);
		UpdateWindow(_hWindow);
		return { true, _hWindow };
	};

	if (!RegisterClassEx(&WC))
	{
		return Create_Window();
	}

	return Create_Window();
}

HWND MainMenu::GetSettings()
{
	return _SettingsWnd;
}

void MainMenu::SetSettings(HWND _hChild)
{
	_SettingsWnd = _hChild;
}

HWND MainMenu::GetStatistics()
{
	return _StatisticsWnd;
}

void MainMenu::SetStatistics(HWND _hChild)
{
	_StatisticsWnd = _hChild;
}

HWND MainMenu::GetPlay()
{
	return _PlayWnd;
}

void MainMenu::SetPlay(HWND _hChild)
{
	_PlayWnd = _hChild;
}

HWND MainMenu::GetDownload()
{
	return _Download;
}

void MainMenu::SetDownload(HWND _hChild)
{
	_Download = _hChild;
}






