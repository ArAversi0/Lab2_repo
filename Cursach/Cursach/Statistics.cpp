#include "Defs.h"

StatisticsWindow::StatisticsWindow() {};
StatisticsWindow::~StatisticsWindow() {}

void StatisticsWindow::StatisticsWidget(HWND hWnd)
{

	RECT _InfoTextRect;
	GetClientRect(hWnd, &_InfoTextRect);
	int _LEFT = (_InfoTextRect.right - 500) / 20;
	int _TOP = (_InfoTextRect.bottom - 30) / 20;

	_Info = CreateWindowA(
		"static",
		"  Game_ID               Number of passed rooms               Number of collected coins",
		WS_VISIBLE | WS_CHILD | ES_CENTER,
		_LEFT, _TOP,
		850, 30,
		hWnd,
		(HMENU)COMMANDS::OnStatisticsClicked,
		GetModuleHandle(0),
		NULL
	);
}



