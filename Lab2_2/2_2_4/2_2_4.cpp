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

// Задание 4.
int main()
{
	setlocale(LC_ALL, "ru");

	ifstream _a("C:/Users/User/Desktop/a.txt");

	int _number;
	int _position = 1;
	int _numberOfZeroes = 0;

	while (_a >> _number) {
		if (_position % 2 == 0 && _number == 0) {
			_numberOfZeroes++;
		}
		_position++;
	}
	cout << _numberOfZeroes << endl;

	_a.close();

	return 0;
}
