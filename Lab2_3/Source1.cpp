#include "Header1.h"
#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Задание 2

Vector::Vector()
{
	_point_1[0] = 0;
	_point_1[1] = 0;
	_point_2[0] = 1;
	_point_2[1] = 1;
}

Vector::Vector(int x1, int y1, int x2, int y2)
{
	_point_1[0] = x1;
	_point_1[1] = y1;
	_point_2[0] = x2;
	_point_2[1] = y2;
}

Vector::~Vector()
{
	delete[] _point_1;
	delete[] _point_2;

	cout << "Выполнено удаление объекта " << endl;
}

void Vector::doubling()
{
	for (int i = 0; i < _size; i++)
	{
		*(_point_1 + i) *= 2;
		*(_point_2 + i) *= 2;
	}
}

void Vector::triangleArea() // int& _line_1, int& _line_2, int* _point_1, int* _point_2
{
	_line_1 = abs(_point_1[0] - _point_2[0]);
	_line_2 = abs(_point_1[1] - _point_2[1]);

	_area = 0.5 * _line_1 * _line_2;

	cout << "Площадь прямоугольного треугольника, заданного вектором: " << _area << endl;
}

void Vector::printInfo()
{
	cout << "Информация об объекте:" << endl;
	cout << "Вектор составлен из точек с координатами (" << _point_1[0] << ", " << _point_1[1] <<
		"), (" << _point_2[0] << ", " << _point_2[1] << ")." << endl;

	if (_area)
	{
		cout << "Площадь треугольника, образуемого вектором и двумя прямыми: " << _area << endl << endl;
	}
	else
	{
		cout << "Площадь треугольника ещё не найдена." << endl << endl;
	}

}