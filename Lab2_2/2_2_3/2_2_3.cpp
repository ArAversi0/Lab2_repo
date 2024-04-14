#include <iostream>
#include <fstream>
#include <math.h>


using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;
using std::string;
using std::cerr;

// Задание 3.
int main()
{
	setlocale(LC_ALL, "ru");

	ifstream _a("C:/Users/User/Desktop/a.txt");
	ofstream _b("C:/Users/User/Desktop/b.txt");
	float _n;

	if (_a.is_open() && _b.is_open())
	{
		while (_a >> _n)
		{
			if (_n >= 0)
			{
				_b << sqrt(_n) << " ";
			}
			else
			{
				_b << pow(_n, 2) << " ";
			}
		}
	}

	_a.close();
	_b.close();

	return 0;
}
