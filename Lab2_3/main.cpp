#include "Header.h"
#include "Header1.h"
#include <iostream>

// 1 Задание
int main()
{
	setlocale(LC_ALL, "ru");

	GeomAverage n1;
	GeomAverage n2(5, 4);

	n1.SetX(7);
	n1.SetY(5);
	n1.Print();

	n2.Print();

	n1.Sqrt();
	n2.Sqrt();

	return 0;
}


/*
// 2 задание
int main()
{
	setlocale(LC_ALL, "ru");

	Vector a;

	a.doubling();
	a.triangleArea();
	a.printInfo();

	Vector b(1, 1, 5, 5);

	b.doubling();
	b.triangleArea();
	b.printInfo();
}
*/