#include "Defs.h"

Character::Character() 
{
	_X = 1;
	_Y = 1;
}

Character::~Character() {}

void Character::DrawCircleToXY(HDC _hdc, int _X, int _Y, HWND hWnd) {
	this->_X = _X;
	this->_Y = _Y;
	
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0)); // Красный цвет кисти
	SelectObject(_hdc, hBrush);

	Ellipse(_hdc, 100 - _Radius, 100 - _Radius, 100 + _Radius, 100 + _Radius);

	DeleteObject(hBrush);
}

int Character::GetX()
{
	return _X;
}

int Character::GetY()
{
	return _Y;
}

void Character::reset()
{
	_X = 1;
	_Y = 1;
}

void Character::moveUp()
{
	_Y -= 1;
}

void Character::moveDown()
{
	_Y += 1;
}

void Character::moveLeft()
{
	_X -= 1;
}

void Character::moveRight()
{
	_X += 1;
}

void Character::clear(HDC _hdc, int _X, int _Y, HWND hWnd)
{
	this->_X = _X;
	this->_Y = _Y;
	
	HBRUSH hBrush = CreateSolidBrush(GetSysColor(COLOR_WINDOW)); // Цвет заднего фона
	SelectObject(_hdc, hBrush);

	Ellipse(_hdc, 50 - _Radius, 50 - _Radius, 50 + _Radius, 50 + _Radius);

	DeleteObject(hBrush);
}
