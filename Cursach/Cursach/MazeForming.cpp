#include "Defs.h"

TheMazeWindow::~TheMazeWindow() {}

TheMazeWindow::TheMazeWindow()
{
	//� ������������ ������������� ������������� ������� ��������� � ��� ��������
	cons_x = 10, cons_y = 10;
	maz = new int* [cons_y];
	for (int i = 0; i < cons_y; i++) {
		maz[i] = new int[cons_x];
	}
	end_x = cons_x - 2, end_y = cons_y - 2;
}

TheMazeWindow::TheMazeWindow(int y = 10, int x = 10)
{
	//� ������������ ������������� ������������� ������� ��������� � ��� ��������
	cons_x = x, cons_y = y;
	maz = new int* [cons_y];
	for (int i = 0; i < cons_y; i++) {
		maz[i] = new int[cons_x];
	}
	end_x = cons_x - 2, end_y = cons_y - 2;
}

//������� �������� ����� ������ ��������� �� �����������
int TheMazeWindow::getMaze(int y, int x)
{
	return maz[y][x];
}

//���������� ���������, ��� ������� � ���������� ����� �������
void TheMazeWindow::prepare()
{
	for (int i = 0; i < cons_y; i++) {
		for (int i1 = 0; i1 < cons_x; i1++) 
		{ 
			maz[i][i1] = 0; 
		}
	}
	number = 1;//1 ��������� �������
	maz[1][1] = 1;
	points_x.push_back(1);//���������� � ������� �������� 1,1-��������� �����, �� ������� ������ ��������
	points_y.push_back(1);
}

//������� ����� ������ ����� �� �������� ������ x,y � ���������
//�������� ���� ��� ��� ������ ��������� ������ ���������, ��� �� ��������� � ��� ������ ��� ��� � ����� ����������� ��� 3�
//��� ��������� ������ ���������(����� �� ������ ���� �� ���� �����, ���� 2*2 ������ �����)
bool TheMazeWindow::testXY(int y, int x)
{
	if (x == end_x && y == end_y) { return true; }//����� � ����� ������ ���� ��������� �������, ����� ��� ��������� �������� ��� ��������� �����
	else if (x<1 || y<1 || x>end_x || y>end_y || maz[y][x] == 1) { return false; }
	else if (maz[y - 1][x - 1] + maz[y - 1][x] + maz[y][x - 1] >= 3) { return false; }//����������� ����� ����� 3 ������
	else if (maz[y - 1][x] + maz[y - 1][x + 1] + maz[y][x + 1] >= 3) { return false; }//������ ����� 3 ��
	else if (maz[y + 1][x - 1] + maz[y + 1][x] + maz[y][x - 1] >= 3) { return false; }//����� ���� 3 ��
	else if (maz[y + 1][x] + maz[y + 1][x + 1] + maz[y][x + 1] >= 3) { return false; }//������ ���� 3 ��
	else { return true; }
}

//���������� ���� � ���������-������� maz(������� �� ���� ��������� � x � y)
void TheMazeWindow::generateTree()
{
	//������� ������
	prepare();

	int rep = 0;//���������� ����������
	int point = rand() % number;//����� ��������� ����� �� �������� points_x � points_x, ����� �� ��� ���������� ��������
	while (maz[end_y][end_x] != 1) {//���� �� ������ �� �����
		point = rand() % number;//������ ��� ������� ��������� ����� ������, �� ������� ����� ������� ����

		switch (rand() % 4)//��������� ����������� ��������� �������
		{
			//0-�����: ���� � ������� ������ ����� ������� ������ � ������������ � ������� testXY(), � ���� ��� � ��� �� ������, �� ������ ������
		case 0: if (testXY(points_y[point] - 1, points_x[point]) && maz[points_y[point] - 2][points_x[point]] != 1) {
			maz[points_y[point] - 1][points_x[point]] = 1;//������
			//� ����� �� �������� ��������� ��� ���� ������,������ ��� ���� ������ �� ����� �������� ����� �� ��������,
			//� ������� ���� �� ����� ������ �� ������ � ��������� ������������, ���� �� ���� �������, ����� �� �������� � ������� ����������
			if (testXY(points_y[point] - 2, points_x[point])) {
				maz[points_y[point] - 2][points_x[point]] = 1;//������
				//���������� ���������� x � y ���� ������ � ������� points, ����� �������� �� � ������ ������, �� ������� �������� �������� ����
				points_x.push_back(points_x[point]);
				points_y.push_back(points_y[point] - 2);
				number++;//������ �� 1 ����� ������ ������
			}
		}	break;
			//���������� ��� ���� ��������� 3� ������
		case 1: if (testXY(points_y[point], points_x[point] + 1) && maz[points_y[point]][points_x[point] + 2] != 1) {
			maz[points_y[point]][points_x[point] + 1] = 1;
			if (testXY(points_y[point], points_x[point] + 2)) {
				maz[points_y[point]][points_x[point] + 2] = 1;
				points_x.push_back(points_x[point] + 2);
				points_y.push_back(points_y[point]);
				number++;
			}
		}	break;
		case 2: if (testXY(points_y[point] + 1, points_x[point]) && maz[points_y[point] + 2][points_x[point]] != 1) {
			maz[points_y[point] + 1][points_x[point]] = 1;
			if (testXY(points_y[point] + 2, points_x[point])) {
				maz[points_y[point] + 2][points_x[point]] = 1;
				points_x.push_back(points_x[point]);
				points_y.push_back(points_y[point] + 2);
				number++;
			}
		}	break;
		case 3: if (testXY(points_y[point], points_x[point] - 1) && maz[points_y[point]][points_x[point] - 2] != 1) {
			maz[points_y[point]][points_x[point] - 1] = 1;
			if (testXY(points_y[point], points_x[point] - 2)) {
				maz[points_y[point]][points_x[point] - 2] = 1;
				points_x.push_back(points_x[point] - 2);
				points_y.push_back(points_y[point]);
				number++;
			}
		}	break;
		default:
			break;
		}
		rep++;

		//����� �������� ��� �����������
		testforDEADEND(point);
	}
}

//������� ��� �������� ������, ���� �� ������� ������� ���������� �� � ���� ������� ��������� ������, �� ��� ������� ��������� �� ������ points, ����� ������ ������ �� �� �������
//�� ������ �������� ��������� ��������� ��� ������� �������� � 10 � ����� ���
void TheMazeWindow::testforDEADEND(int num)
{
	if (!testXY(points_y[num] - 2, points_x[num])) {
		if (!testXY(points_y[num] + 2, points_x[num])) {
			if (!testXY(points_y[num], points_x[num] - 2)) {
				if (!testXY(points_y[num], points_x[num] + 2)) {
					near_finish(num);//�������� �� �� ��� �� ����� ������, ����� �� ���� ������� � ���������� ������
					if (number > 1) {
						auto iter = points_x.cbegin();//������� ��������, ��� ��������-��������� �� ������ vector�, ����� �� ����� ����������� ������� �� ������ �������� 
						points_x.erase(iter + num);//����� �������� � vector
						auto iter2 = points_y.cbegin();
						points_y.erase(iter2 + num);
						number--;
					}
				}
			}
		}
	}
}

//���� �������� � ��������� ��������� ������, �� �� ������ �������� ����� ��� �� ����,
//������� ���� ����� ������� ��� �������
void TheMazeWindow::near_finish(int num)
{
	if (abs(points_y[num] - end_y) <= 2 && abs(points_x[num] - end_x) <= 2) {
		for (int i = end_y - 1; i <= end_y; i++) {
			for (int i1 = end_x - 1; i1 <= end_x; i1++) {
				maz[i][i1] = 1;
			}
		}
	}
}



void TheMazeWindow::draw(HDC hdc, HWND hWnd, RECT rect)
{
	int _current_cell_size = Get_Cell_size();
	HBRUSH _WhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH _BlackBrush = CreateSolidBrush(RGB(0, 0, 0));

	FillRect(hdc, &rect, _WhiteBrush);

	// ��������� ���� � �����
	for (int y = 0; y < cons_y; ++y)
	{
		for (int x = 0; x < cons_x; ++x)
		{
			RECT _rectangle = { x * _current_cell_size, y * _current_cell_size,
								(x + 1) * _current_cell_size, (y + 1) * _current_cell_size };

			if (maz[y][x] == 0)
			{
				FillRect(hdc, &_rectangle, _BlackBrush);
			}
			else if (maz[y][x] == 1)
			{
				FillRect(hdc, &_rectangle, _WhiteBrush);
				Rectangle(hdc, _rectangle.left, _rectangle.top, _rectangle.right, _rectangle.bottom);		
			}
		}
	}

	DeleteObject(_WhiteBrush);
	DeleteObject(_BlackBrush);
}

void TheMazeWindow::drawBotWay(HDC hdc, HWND hWnd, RECT rect)
{
	int _current_cell_size = Get_Cell_size();
	HBRUSH _RedBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH _WhiteBrush = CreateSolidBrush(RGB(255, 255, 255));
	HBRUSH _BlackBrush = CreateSolidBrush(RGB(0, 0, 0));

	FillRect(hdc, &rect, _WhiteBrush);

	// ��������� ���� � �����
	for (int y = 0; y < cons_y; ++y)
	{
		for (int x = 0; x < cons_x; ++x)
		{
			RECT _rectangle = { x * _current_cell_size, y * _current_cell_size,
								(x + 1) * _current_cell_size, (y + 1) * _current_cell_size };

			if (maz[y][x] == 0)
			{
				FillRect(hdc, &_rectangle, _BlackBrush);
			}
			else if (maz[y][x] == 1)
			{
				FillRect(hdc, &_rectangle, _WhiteBrush);
				Rectangle(hdc, _rectangle.left, _rectangle.top, _rectangle.right, _rectangle.bottom);
			}
		}
	}

	for (vector<pair<int, int>>::iterator i = _wave.begin(); i != _wave.end(); ++i)
	{
		
		RECT _rectangle = { (i->first) * _current_cell_size, (i->second) * _current_cell_size,
								((i->first) + 1) * _current_cell_size, ((i->second) + 1) * _current_cell_size };

		FillRect(hdc, &_rectangle, _RedBrush);

	}

	DeleteObject(_RedBrush);
	DeleteObject(_WhiteBrush);
	DeleteObject(_BlackBrush);
}

float TheMazeWindow::Get_Cell_size()
{
	return cell_size;
}

Camera TheMazeWindow::Get_Camera_status()
{
	return camera;
}

void TheMazeWindow::DoMoveUp(HWND hWnd)
{
	camera.moveUp(hWnd);
}

void TheMazeWindow::DoMoveDown(HWND hWnd)
{
	camera.moveDown(hWnd);
}

void TheMazeWindow::DoMoveLeft(HWND hWnd)
{
	camera.moveLeft(hWnd);
}

void TheMazeWindow::DoMoveRight(HWND hWnd)
{
	camera.moveRight(hWnd);
}

void TheMazeWindow::StatisticsWidgets_15x15(HWND hWnd)
{
	RECT _StatisticsWidgetsSizeRect_15x15;
	GetClientRect(hWnd, &_StatisticsWidgetsSizeRect_15x15);
	int _LEFT = (_StatisticsWidgetsSizeRect_15x15.right - 200) / 1.6;
	int _TOP = (_StatisticsWidgetsSizeRect_15x15.bottom - 20) / 15;

	_textStat_1 = CreateWindowA("static", "Game id:",
		WS_VISIBLE | WS_CHILD,
		_LEFT, _TOP,
		150, 20,
		hWnd,
		(HMENU)4001,
		GetModuleHandle(0),
		NULL
	);

	_textStat_2 = CreateWindowA("static", "Total number of rooms passed:",
		WS_VISIBLE | WS_CHILD,
		_LEFT, _TOP + 60,
		150, 40,
		hWnd,
		(HMENU)4002,
		GetModuleHandle(0),
		NULL
	);

	_textStat_3 = CreateWindowA("static", "Total number of coins collected:",
		WS_VISIBLE | WS_CHILD,
		_LEFT, _TOP + 140,
		150, 40,
		hWnd,
		(HMENU)4003,
		GetModuleHandle(0),
		NULL
	);

	_btnStatFinish = CreateWindowA("button", "Finish",
		WS_VISIBLE | WS_CHILD,
		_LEFT, _TOP + 220,
		150, 40,
		hWnd,
		(HMENU)OnFinishClicked,
		GetModuleHandle(0),
		NULL
	);
}

void TheMazeWindow::StatisticsWidgets_25x25(HWND hWnd)
{
	RECT _StatisticsWidgetsSizeRect_25x25;
	GetClientRect(hWnd, &_StatisticsWidgetsSizeRect_25x25);
	int _LEFT = (_StatisticsWidgetsSizeRect_25x25.right - 200) / 1.6;
	int _TOP = (_StatisticsWidgetsSizeRect_25x25.bottom - 20) / 15;

	_textStat_1 = CreateWindowA("static", "Game id:",
		WS_VISIBLE | WS_CHILD,
		_LEFT + 260, _TOP,
		150, 20,
		hWnd,
		(HMENU)5001,
		GetModuleHandle(0),
		NULL
	);

	_textStat_2 = CreateWindowA("static", "Total number of rooms passed:",
		WS_VISIBLE | WS_CHILD,
		_LEFT + 260, _TOP + 60,
		150, 40,
		hWnd,
		(HMENU)5002,
		GetModuleHandle(0),
		NULL
	);

	_textStat_3 = CreateWindowA("static", "Total number of coins collected:",
		WS_VISIBLE | WS_CHILD,
		_LEFT + 260, _TOP + 140,
		150, 40,
		hWnd,
		(HMENU)5003,
		GetModuleHandle(0),
		NULL
	);

	_btnStatFinish = CreateWindowA("button", "Finish",
		WS_VISIBLE | WS_CHILD,
		_LEFT + 260, _TOP + 220,
		150, 40,
		hWnd,
		(HMENU)OnFinishClicked,
		GetModuleHandle(0),
		NULL
	);
}

void TheMazeWindow::StatisticsWidgets_40x40(HWND hWnd)
{
	RECT _StatisticsWidgetsSizeRect_40x40;
	GetClientRect(hWnd, &_StatisticsWidgetsSizeRect_40x40);
	int _LEFT = (_StatisticsWidgetsSizeRect_40x40.right - 200) / 1.6;
	int _TOP = (_StatisticsWidgetsSizeRect_40x40.bottom - 20) / 15;

	_textStat_1 = CreateWindowA("static", "Game id:",
		WS_VISIBLE | WS_CHILD,
		_LEFT + 650, _TOP,
		150, 20,
		hWnd,
		(HMENU)6001,
		GetModuleHandle(0),
		NULL
	);

	_textStat_2 = CreateWindowA("static", "Total number of rooms passed:",
		WS_VISIBLE | WS_CHILD,
		_LEFT + 650, _TOP + 60,
		150, 40,
		hWnd,
		(HMENU)6002,
		GetModuleHandle(0),
		NULL
	);

	_textStat_3 = CreateWindowA("static", "Total number of coins collected:",
		WS_VISIBLE | WS_CHILD,
		_LEFT + 650, _TOP + 140,
		150, 40,
		hWnd,
		(HMENU)6003,
		GetModuleHandle(0),
		NULL
	);

	_btnStatFinish = CreateWindowA("button", "Finish",
		WS_VISIBLE | WS_CHILD,
		_LEFT + 650, _TOP + 220,
		150, 40,
		hWnd,
		(HMENU)OnFinishClicked,
		GetModuleHandle(0),
		NULL
	);
}

void TheMazeWindow::BotAlgorithm()
{
	_oldWave.push_back(pair<int, int>(2, 2));
	maz[2][2] = _nstep;
	const int dx[] = { 0, 1, 0, -1 };
	const int dy[] = { -1, 0, 1, 0 };
	
	while (_oldWave.size() > 0)
	{
		++_nstep;

		_wave.clear();
		for (vector<pair<int, int>>::iterator i = _oldWave.begin(); i != _oldWave.end(); ++i)
		{		
			for (int d = 0; d < 4; ++d)
			{
				int nx = i->first + dx[d];
				int ny = i->second + dy[d];
				
				
				if (maz[nx][ny] == -1)
				{
					_wave.push_back(pair<int, int>(nx, ny));
					maz[nx][ny] = _nstep;
					if (nx == end_x && ny == end_y)
						goto done;
				}
			}
			
		}
		_oldWave = _wave;
	}
done:
	int _x = end_x;
	int _y = end_y;
	_wave.clear();
	_wave.push_back(pair<int, int>(_x, _y));
	while (maz[_x][_y] != 0)
	{
		for (int d = 0; d < 4; ++d)
		{
			int nx = _x + dx[d];
			int ny = _y + dx[d];
			if (maz[_x][_y] - 1 == maz[nx][ny])
			{
				_x = nx;
				_y = ny;
				_wave.push_back(pair<int, int>(_x, _y));
				break;
			}
		}
	}
}

void TheMazeWindow::ActionMoveUp(HWND _hWnd)
{
	GetClientRect(_hWnd, &_clientRect);
	PAINTSTRUCT _psUp;
	HDC _hdcUp = BeginPaint(_hWnd, &_psUp);

	if (maz[player.GetY() - 1][player.GetX()] == 1) 
	{ 
		player.clear(_hdcUp, player.GetX(), player.GetY(), _hWnd); 
		player.moveUp(); 
		player.DrawCircleToXY(_hdcUp, player.GetX(), player.GetY(), _hWnd);
	}

	EndPaint(_hWnd, &_psUp);
}

void TheMazeWindow::ActionMoveDown(HWND _hWnd)
{
	GetClientRect(_hWnd, &_clientRect);
	PAINTSTRUCT _psDown;
	HDC _hdcDown = BeginPaint(_hWnd, &_psDown);

	if (maz[player.GetY() + 1][player.GetX()] == 1)
	{
		player.clear(_hdcDown, player.GetX(), player.GetY(), _hWnd);
		player.moveDown();
		player.DrawCircleToXY(_hdcDown, player.GetX(), player.GetY(), _hWnd);
	}

	EndPaint(_hWnd, &_psDown);
}

void TheMazeWindow::ActionMoveLeft(HWND _hWnd)
{
	GetClientRect(_hWnd, &_clientRect);
	PAINTSTRUCT _psLeft;
	HDC _hdcLeft = BeginPaint(_hWnd, &_psLeft);

	if (maz[player.GetY()][player.GetX() - 1] == 1)
	{
		player.clear(_hdcLeft, player.GetX(), player.GetY(), _hWnd);
		player.moveLeft();
		player.DrawCircleToXY(_hdcLeft, player.GetX(), player.GetY(), _hWnd);
	}

	EndPaint(_hWnd, &_psLeft);
}

void TheMazeWindow::ActionMoveRight(HWND _hWnd)
{
	GetClientRect(_hWnd, &_clientRect);
	PAINTSTRUCT _psRight;
	HDC _hdcRight = BeginPaint(_hWnd, &_psRight);

	if (maz[player.GetY()][player.GetX() + 1] == 1)
	{
		player.clear(_hdcRight, player.GetX(), player.GetY(), _hWnd);
		player.moveRight();
		player.DrawCircleToXY(_hdcRight, player.GetX(), player.GetY(), _hWnd);
	}

	EndPaint(_hWnd, &_psRight);
}
