#pragma once
#pragma comment (lib, "gdiplus.lib")
#include <Windows.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <vector>
#include <cmath>
#include <conio.h>
#include <gdiplus.h>

using namespace std;
using namespace Gdiplus;

LRESULT CALLBACK MainProcedure(HWND _hWnd, UINT _message, WPARAM _wp, LPARAM _lp);
WNDCLASS NewWindowClass(HBRUSH _BGColor, HCURSOR _Cursor, HINSTANCE _hInst, HICON _Icon, LPCWSTR _Name, WNDPROC _Procedure);

enum COMMANDS
{
	OnPlayClicked = 1,
	OnStatisticsClicked = 2,
	OnSettingsClicked = 3,
	OnExitClicked = 4,

	EasyChosen = 5,
	AvgChosen = 6,
	HardChosen = 7,

	_15x15Chosen = 15,
	_25x25Chosen = 25,
	_40x40Chosen = 40,

	_PlayerChoosen = 32,
	_BotChoosen = 33,

	_15x15Size = 10,
	_25x25Size = 20,
	_40x40Size = 30,

	OnPlayOkClicked = 12,
	OnPlayApplyClicked = 13,

	Up_W_Pressed = 14,
	Down_S_Pressed = 16,
	Left_A_Pressed = 17,
	Right_D_Pressed = 18,
	Take_E_Pressed = 19,

	OnFinishClicked = 100

};

static int _selectedMazeSize = NULL;
static int _transmittedMazeSize = NULL;
static int _SelectedMazeGameMode = NULL;
static int _gameID = 0;


class MainMenu
{
public:
	
	MainMenu();
	~MainMenu();

	void AddMainMenu(HWND hWnd);
	
	void ExitApp();
	std::pair<bool, HWND> AddWindow(const std::wstring&& WndClass, const std::wstring&& title, 
		HWND hWnd, const WNDPROC _callback);

	HWND GetSettings();
	void SetSettings(HWND _hChild);

	HWND GetStatistics();
	void SetStatistics(HWND _hChild);

	HWND GetPlay();
	void SetPlay(HWND _hChild);

private:
	HWND _PlayBtn = NULL;
	HWND _StatBtn = NULL;
	HWND _SettBtn = NULL;
	HWND _ExitBtn = NULL;

	HWND _SettingsWnd = NULL;
	HWND _StatisticsWnd = NULL;
	HWND _PlayWnd = NULL;
};

class SettingsWindow : public MainMenu
{
public:
	SettingsWindow();
	~SettingsWindow();

	void SetGoUpKey(char _GoUpKey);
	void SetGoDownKey(char _GoDownKey);
	void SetGoLeftKey(char _GoLeftKey);
	void SetGoRightKey(char _GoRigntKey);
	void SetPickMoney(char _PickMoney);

	char GetGoUpKey();
	char GetGoDownKey();
	char GetGoLeftKey();
	char GetGoRightKey();
	char GetMoney();

private:
	char _GoUpKey = 'W';
	char _GoDownKey = 'S';
	char _GoLeftKey = 'A';
	char _GoRightKey = 'D';
	char _PickMoney = 'E';

};

class PlayWindow : public MainMenu
{
public:
	PlayWindow();
	~PlayWindow();

	void PlayDiffWidgets(HWND hWnd);
	void PlaySizeWidgets(HWND hWnd);
	void PlayBtnWidgets(HWND hWnd);
	void PlayGameModeWidgets(HWND hWnd);

	HWND GetTheMazeWnd();
	void SetTheMazeWnd(HWND _hChild);

private:
	HWND _textDiff = NULL;
	HWND _textSize = NULL;
	HWND _textGameMode = NULL;
	
	HWND _radioBtnEasy = NULL;
	HWND _radioBtnMedium = NULL;
	HWND _radioBtnHard = NULL;
	
	HWND _radioBtnSmall = NULL;
	HWND _radioBtnAverage = NULL;
	HWND _radioBtnLarge = NULL;

	HWND _radioBtnPlayer = NULL;
	HWND _radioBtnBot = NULL;

	HWND _BtnOk = NULL;
	HWND _BtnApply = NULL;

	HWND _TheMazeWnd = NULL;
};

class StatisticsWindow : public MainMenu
{
public:
	StatisticsWindow();
	~StatisticsWindow();

private:
	int _roomsCounter = 0;
	int _coinsCounter = 0;
	
	class GameOver
	{

	};
};

class Character : public PlayWindow
{
public:
	Character();
	~Character();

	int GetX();
	int GetY();

	void reset();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void clear(HDC _hdc, int _X, int _Y, HWND hWnd);
	void DrawCircleToXY(HDC hdc, int X, int Y, HWND hWnd);

private:
	const int _Radius = 20;
	int _X, _Y;

};

class Room : public PlayWindow
{
public:
	Room();
	~Room();



private:
	const int cell_size = 26;

	int _roomCoins = NULL;

	class Spikes
	{

	};
};

class Camera {

public:
	Camera();
	~Camera();

	void moveUp(HWND hWnd);
	void moveDown(HWND hWnd);
	void moveLeft(HWND hWnd);
	void moveRight(HWND hWnd);

	void setCam(HWND hWnd);

private:
	int x, y;
};

class TheMazeWindow : public PlayWindow
{
public:
	TheMazeWindow();
	TheMazeWindow(int y, int x);
	~TheMazeWindow();

	int getMaze(int y, int x);
	void prepare();
	bool testXY(int y, int x);
	void generateTree();
	void testforDEADEND(int num);
	void near_finish(int num);
	void draw(HDC hdc, HWND hWnd, RECT rect);

	void ActionMoveUp(HWND hWnd);
	void ActionMoveDown(HWND hWnd);
	void ActionMoveLeft(HWND hWnd);
	void ActionMoveRight(HWND hWnd);

	float Get_Cell_size();
	
	Camera Get_Camera_status();
	void DoMoveUp(HWND hWnd);
	void DoMoveDown(HWND hWnd);
	void DoMoveLeft(HWND hWnd);
	void DoMoveRight(HWND hWnd);

	void StatisticsWidgets_15x15(HWND hWnd);
	void StatisticsWidgets_25x25(HWND hWnd);
	void StatisticsWidgets_40x40(HWND hWnd);

	void BotAlgorithm();
	void drawBotWay(HDC hdc, HWND hWnd, RECT rect);

private:
	//сам лабиринт на плоскости, если элемент= 0-стена, если =1-проход(двумерный массив, сделал динамическим чтобы при запуске можно было задавать размеры)
	int** maz;
	int cons_x, cons_y;//переменные для размера лабиринта, чем больше тем дольше генерируется

	vector<int> points_x;//глупое решение, но первое что пришло в голову, хранить в 2х массивах координаты тех точек лабиринта, которые уже вырублены, т.е вершины   
	vector<int> points_y;//чтобы из них потом продолжать строить ответвления, рандомно выбирая точки из этих массивов и рандомное направление прокладки пути 
	int number;//собственно, переменная, чтобы знать насколько заполнены предыдущие массивы, и выбирать из них случайный

	Character player;//символ игрока
	Camera camera;//для управления камерой
	Room room; // комната
	int end_x, end_y;//координаты выхода
	
	HDC _hdc = NULL;
	RECT _clientRect;

	const float cell_size = 26.0;

	HWND _textStat_1 = NULL;
	HWND _textStat_2 = NULL;
	HWND _textStat_3 = NULL;
	HWND _btnStatFinish = NULL;
	
	vector<pair<int, int>> _wave;
	vector<pair<int, int>> _oldWave;
	int _nstep = 0;
};


