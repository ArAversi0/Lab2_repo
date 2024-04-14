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


// Задание 1.
int main()
{
	ifstream _in("C:/Users/User/Desktop/a.txt");
	fstream _out("C:/Users/User/Desktop/b.txt");
	float _flNum;

	while (_in >> _flNum)
	{
		if (_flNum > 0)
		{
			_out << _flNum << " ";
		}
	}

	_in.close();
	_out.close();

	return 0;
}


