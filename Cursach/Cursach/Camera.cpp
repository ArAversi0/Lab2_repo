#include "Defs.h"

Camera::Camera()
{
	x = 0;
	y = 0;
}

Camera::~Camera() {}

void Camera::moveUp(HWND hWnd)
{
	setCam(hWnd);
	if (y > 0) y -= 5;
}

void Camera::moveDown(HWND hWnd)
{
	setCam(hWnd);
	if (y < 600) y += 5;
}

void Camera::moveLeft(HWND hWnd)
{
	setCam(hWnd);
	if (x > 0) x -= 5;
}

void Camera::moveRight(HWND hWnd)
{
	setCam(hWnd);
	if (x < 960) x += 5;
}

void Camera::setCam(HWND hWnd) {
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	_COORD NewPos;
	NewPos.X = x;
	NewPos.Y = y;
	SetCursorPos(x, y);
}

