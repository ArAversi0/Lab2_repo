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

// Задание 2.
int main()
{
	setlocale(LC_ALL, "ru");

	ifstream _a1("C:/Users/User/Desktop/a1.txt");
	ifstream _a2("C:/Users/User/Desktop/a2.txt");
	float _result = 1.0;
	float _n1, _n2;

	if (_a1.is_open())
	{
		while (_a1 >> _n1)
		{
			if (_n1 < 0)
			{
				_result *= _n1;
			}
		}
	}
	if (_a2.is_open())
	{
		while (_a2 >> _n2)
		{
			if (_n2 < 0)
			{
				_result *= _n2;
			}
		}
	}
	cout << "Произведение: " << _result << endl;

	_a1.close();
	_a2.close();

	return 0;
}
