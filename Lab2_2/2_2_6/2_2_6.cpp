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

// Задание 6.
int main()
{
	setlocale(LC_ALL, "ru");

	fstream _a("C:/Users/User/Desktop/a.txt");

	int _position = 1;
	float _number;
	float _max = 0;
	float _temp;

	if (_a.is_open())
	{
		while (_a >> _number)
		{
			_temp = _number;
			if ((_position % 2 != 0) && (fabs(_temp) > _max))
			{
				_max = fabs(_number);
			}
			_position++;
		}
	}
	cout << "Максимальное значение модуля числа на нечётной позиции: " << _max << endl;

	_a.close();
}
