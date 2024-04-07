#include "Header.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::endl;

// Задание 1

GeomAverage::GeomAverage(float x, float y)
{
	this->x = x;
	this->y = y;
}

GeomAverage::GeomAverage()
{
	x = NULL;
	y = NULL;
}

void GeomAverage::SetX(float x)
{
	this->x = x;
}

void GeomAverage::SetY(float y)
{
	this->y = y;
}

float GeomAverage::GetX()
{
	return x;
}

float GeomAverage::GetY()
{
	return y;
}

void GeomAverage::Print()
{
	cout << "Вещественное число 1: " << x
		<< "\nВещественное число 2: " << y << endl << endl;
}

void GeomAverage::Sqrt()
{
	cout << "Квадратный корень из произведения чисел: "
		<< pow(x * y, 1. / 2.) << endl << endl;
}