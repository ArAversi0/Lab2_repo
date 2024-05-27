#include <Windows.h>
#include "Defs.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASS MainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(NULL, IDI_QUESTION),
		L"MainWndClass", MainProcedure);

	if (!RegisterClassW(&MainClass)) { return -1; }

	MSG MainMessage = { 0 };

	CreateWindow(L"MainWndClass", L"The Maze", WS_OVERLAPPED | WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 100, 100, 900, 600,
		NULL, NULL, NULL, NULL);
	while (GetMessage(&MainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&MainMessage);
		DispatchMessage(&MainMessage);
	}
	
	return 0;
}
