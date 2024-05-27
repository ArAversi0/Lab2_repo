#include "Defs.h"

SettingsWindow::SettingsWindow() {}
SettingsWindow::~SettingsWindow() {}

void SettingsWindow::SetGoUpKey(char _GoUpKey)
{
	this->_GoUpKey = _GoUpKey;
}

void SettingsWindow::SetGoDownKey(char _GoDownKey)
{
	this->_GoDownKey = _GoDownKey;
}

void SettingsWindow::SetGoLeftKey(char _GoLeftKey)
{
	this->_GoLeftKey = _GoLeftKey;
}

void SettingsWindow::SetGoRightKey(char _GoRigntKey)
{
	this->_GoRightKey = _GoRigntKey;
}

void SettingsWindow::SetPickMoney(char _PickMoney)
{
	this->_PickMoney = _PickMoney;
}

char SettingsWindow::GetGoUpKey()
{
	return _GoUpKey;
}

char SettingsWindow::GetGoDownKey()
{
	return _GoDownKey;
}

char SettingsWindow::GetGoLeftKey()
{
	return _GoLeftKey;
}

char SettingsWindow::GetGoRightKey()
{
	return _GoRightKey;
}

char SettingsWindow::GetMoney()
{
	return _PickMoney;
}

