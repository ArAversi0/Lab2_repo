#include "Defs.h"

PlayWindow::PlayWindow() {};
PlayWindow::~PlayWindow() {};

void PlayWindow::PlayDiffWidgets(HWND hWnd)
{
	RECT _PlayDiffRect;
	GetClientRect(hWnd, &_PlayDiffRect);
	int _LEFT = (_PlayDiffRect.right - 150) / 15;
	int _TOP = (_PlayDiffRect.bottom - 200) / 15;
	
	_textDiff = CreateWindowA("button", "Choose the difficulty", 
		WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
		_LEFT, _TOP,
		150, 200,
		hWnd,
		(HMENU)1001,
		GetModuleHandle(0),
		NULL
	);

	_radioBtnEasy = CreateWindowA("button",
		"Easy",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		_LEFT + 10, _TOP + 50,
		80, 20,
		hWnd,
		(HMENU)COMMANDS::EasyChosen,
		GetModuleHandle(0),
		NULL
	);

	_radioBtnMedium = CreateWindowA("button",
		"Medium",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		_LEFT + 10, _TOP + 90,
		80, 20,
		hWnd,
		(HMENU)COMMANDS::AvgChosen,
		GetModuleHandle(0),
		NULL
	);

	_radioBtnHard = CreateWindowA("button",
		"Hard",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		_LEFT + 10, _TOP + 130,
		80, 20,
		hWnd,
		(HMENU)COMMANDS::HardChosen,
		GetModuleHandle(0),
		NULL
	);
}

void PlayWindow::PlaySizeWidgets(HWND hWnd)
{
	RECT _PlaySizeRect;
	GetClientRect(hWnd, &_PlaySizeRect);
	int _LEFT = (_PlaySizeRect.right - 200) / 3;
	int _TOP = (_PlaySizeRect.bottom - 200) / 15;

	_textSize = CreateWindowA("button",
		"Choose the size of the maze",
		WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
		_LEFT, _TOP,
		200, 200,
		hWnd,
		(HMENU)2001, GetModuleHandle(0),
		NULL
	);

	_radioBtnSmall = CreateWindowA(
		"button",
		"15x15",
		WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,
		_LEFT + 10, _TOP + 50,
		80, 20,
		hWnd,
		(HMENU)COMMANDS::_15x15Chosen,
		GetModuleHandle(0),
		NULL
	);

	_radioBtnAverage = CreateWindowA(
		"button",
		"25x25",
		WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
		_LEFT + 10, _TOP + 90,
		80, 20,
		hWnd,
		(HMENU)COMMANDS::_25x25Chosen,
		GetModuleHandle(0),
		NULL
	);
	
	_radioBtnLarge = CreateWindowA(
		"button",
		"40x40",
		WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
		_LEFT + 10, _TOP + 130,
		80, 20,
		hWnd,
		(HMENU)COMMANDS::_40x40Chosen,
		GetModuleHandle(0),
		NULL
	);
}

void PlayWindow::PlayBtnWidgets(HWND hWnd)
{
	RECT _PlayBtnRect;
	GetClientRect(hWnd, &_PlayBtnRect);
	int _LEFT = (_PlayBtnRect.right - 150) / 2;
	int _TOP = (_PlayBtnRect.bottom - 40) / 2;

	_BtnOk = CreateWindowA(
		"button",
		"OK",
		WS_VISIBLE | WS_CHILD,
		_LEFT - 15, _TOP,
		150, 40,
		hWnd,
		(HMENU)COMMANDS::OnPlayOkClicked,
		GetModuleHandle(0),
		NULL
	);

	_BtnApply = CreateWindowA(
		"button",
		"Apply",
		WS_VISIBLE | WS_CHILD,
		_LEFT - 220, _TOP,
		150, 40,
		hWnd,
		(HMENU)COMMANDS::OnPlayApplyClicked,
		GetModuleHandle(0),
		NULL
	);
}

void PlayWindow::PlayGameModeWidgets(HWND hWnd)
{
	RECT _PlayGameModeRect;
	GetClientRect(hWnd, &_PlayGameModeRect);
	int _LEFT = (_PlayGameModeRect.right - 150) / 1.6;
	int _TOP = (_PlayGameModeRect.bottom - 200) / 15;

	_textGameMode = CreateWindowA("button", "Choose the game mode",
		WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
		_LEFT, _TOP,
		170, 200,
		hWnd,
		(HMENU)3001,
		GetModuleHandle(0),
		NULL
	);

	_radioBtnPlayer = CreateWindowA("button",
		"Player",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		_LEFT + 10, _TOP + 50,
		80, 20,
		hWnd,
		(HMENU)COMMANDS::_PlayerChoosen,
		GetModuleHandle(0),
		NULL
	);

	_radioBtnBot = CreateWindowA("button",
		"Bot",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		_LEFT + 10, _TOP + 90,
		80, 20,
		hWnd,
		(HMENU)COMMANDS::_BotChoosen,
		GetModuleHandle(0),
		NULL
	);

}

HWND PlayWindow::GetTheMazeWnd()
{
	return _TheMazeWnd;
}

void PlayWindow::SetTheMazeWnd(HWND _hChild)
{
	_TheMazeWnd = _hChild;
}




