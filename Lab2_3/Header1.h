#pragma once

// Задание 2

class Vector
{
private:
	int _size = 2;
	int _temp = 0;

	int* _point_1 = new int[_size];
	int* _point_2 = new int[_size];

	int _line_1;
	int _line_2;
	float _area;

public:
	Vector();
	Vector(int x1, int y1, int x2, int y2);
	~Vector();

	void doubling();
	void triangleArea();
	void printInfo();

};