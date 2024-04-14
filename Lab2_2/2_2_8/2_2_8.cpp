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

// Задание 8.

// Структура Car для хранения информации о машинах
struct Car {
	char _brand[25];
	char _producer[25];
	char _type[25];
	int _year;
	double _price;
};

int _year = 2024;

int main() {
	// Открываем файл для записи в бинарном режиме
	ofstream _car_list ("C:/Users/User/Desktop/cars.txt", ios::binary);

	// Создаем объекты типа Car с информацией о различных машинах
	Car _cars[] =
	{
		{ "Mazda", "Japan", "Сrossover", 2022, 43000.0 },
		{ "BMW", "Germany", "SUV", 2015, 35000.0 },
		{ "Kia", "South Korea", "Сrossover", 2020, 32000.0 },
		{ "Hyundai", "South Korea", "Coupe", 2013, 18000.0 },
		{ "Aion S", "China", "Coupe", 2021, 35500.0 },
	};

	// Записываем данные о машинах в файл
	for (const Car& _car : _cars)
	{
		_car_list.write(reinterpret_cast <const char*> (&_car), sizeof(Car));
	}

	// Закрываем файл
	_car_list.close();

	// Открываем файл для чтения в бинарном режиме
	ifstream inFile("C:/Users/User/Desktop/cars.txt", ios::binary);
	Car car;

	// Читаем данные из файла и выводим информацию о машинах, удовлетворяющих условиям
	while (inFile.read(reinterpret_cast <char*> (&car), sizeof(Car))) {
		if ((_year - car._year >= 5) && (car._producer != "China")) {
			cout << "Brand: " << car._brand << endl;
			cout << "Producer: " << car._producer << endl;
			cout << "Type: " << car._type << endl;
			cout << "Year: " << car._year << endl;
			cout << "Price: " << car._price << " $" << endl << endl;
		}
	}

	// Закрываем файл после чтения
	inFile.close();

	return 0;
}
