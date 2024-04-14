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

// Задание 9

const int _ROWS = 5;
const int _COLS = 5;

// Ф-ия вывода массива
void printArray(float _arr[_ROWS][_COLS]) {
	for (int i = 0; i < _ROWS; i++) {
		for (int j = 0; j < _COLS; j++) {
			cout << _arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	float _arr[_ROWS][_COLS];

	// Заполнение массива
	cout << "Введите " << _ROWS * _COLS << " значения(-й) массива" << endl;
	for (int i = 0; i < _ROWS; i++) {
		for (int j = 0; j < _COLS; j++) {
			cin >> _arr[i][j];
		}
	}

	// Запись массива в бинарный файл
	ofstream _outFile1("C:/Users/User/Desktop/2.txt", ios::out | ios::binary);
	if (_outFile1.is_open()) {
		_outFile1.write((char*)_arr, sizeof(_arr));
		_outFile1.close();
		cout << "Массив успешно записан в файл!" << endl;
	}
	else {
		cerr << "Невозможно открыть файл..." << endl;
		return 1;
	}

	// Вывод элементов массива до изменения
	cout << "\nДо:" << endl;
	printArray(_arr);

	// Считывание данных из бинарного файла
	ifstream _inFile1("C:/Users/User/Desktop/2.txt", ios::in | ios::binary);
	if (_inFile1.is_open()) {
		_inFile1.read((char*)_arr, sizeof(_arr));

		// Изменение значений элементов в каждом столбце
		for (int i = 0; i < _COLS; i++) {
			for (int j = 0; j < _ROWS; j++) {
				_arr[j][i] *= 2.5;
			}
		}

		_inFile1.close();
	}
	else {
		cerr << "Невозможно открыть файл..." << endl;
		return 1;
	}

	ofstream _outFile2("C:/Users/User/Desktop/2.txt", ios::out | ios::binary);
	if (_outFile2.is_open())
	{
		// На данном этапе уже записан изменённый массив
		_outFile2.write((char*)_arr, sizeof(_arr));
		cout << "Массив успешно перезаписан в файл!" << endl;

		_outFile2.close();
	}
	else {
		cerr << "Невозможно открыть файл..." << endl;
		return 1;
	}

	// Повторное считывание уже изменённого массива
	ifstream _inFile2("C:/Users/User/Desktop/2.txt", ios::in | ios::binary);
	if (_inFile2.is_open())
	{
		_inFile2.read((char*)_arr, sizeof(_arr));
		cout << "Успешно считан изменённый массив!" << endl;

		_inFile2.close();
	}
	else {
		cerr << "Невозможно открыть файл..." << endl;
		return 1;
	}

	// Печать массива после изменения данных
	cout << "\nПосле:" << endl;
	printArray(_arr);

	return 0;
}
