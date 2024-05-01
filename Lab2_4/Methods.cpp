#include "Structure.h"

CVehicle::CVehicle()
{
	price = year = speed = 0;
}

CVehicle::CVehicle(unsigned int price, unsigned short year, unsigned short speed)
{
	this->price = price;
	this->year = year;
	this->speed = speed;
}

CVehicle::~CVehicle() {};

CVehicle::ССoordinates::ССoordinates()
{
	x = y = z = 0;
}

CVehicle::ССoordinates::ССoordinates(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void CVehicle::ССoordinates::SetCoors(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

CVehicle::ССoordinates::~ССoordinates() {};

string CVehicle::ССoordinates::GetCoors()
{
	return "X = " + to_string(x) + "; Y = " + to_string(y) + "; Z = " + to_string(z);
}

CCar::CCar():CVehicle() {};

CCar::CCar(unsigned int price, unsigned short year, unsigned short speed):CVehicle(price, year, speed) {};

CCar::~CCar() {};

CPlane::CPlane():CVehicle()
{
	height = passenger_num = 0;
}

CPlane::CPlane(unsigned int price, unsigned short year, unsigned short speed, 
	unsigned int height, unsigned short passenger_num):CVehicle(price, year, speed)
{
	this->height = height;
	this->passenger_num = passenger_num;
}

CPlane::~CPlane() {};

CShip::CShip() :CVehicle()
{
	passenger_num = 0;
	port_name = "";
}

CShip::CShip(unsigned int price, unsigned short year, unsigned short speed, 
	unsigned short passenger_num, string port_name) :CVehicle(price, year, speed)
{
	this->passenger_num = passenger_num;
	this->port_name = port_name;
}

CShip::~CShip() {};

void CCar::SetInfo(unsigned int price, unsigned short year, 
	unsigned short speed)
{
	this->price = price;
	this->year = year;
	this->speed = speed;
}

void CPlane::SetInfo(unsigned int price, unsigned short year, 
	unsigned short speed, unsigned int height, unsigned short passenger_num)
{
	this->price = price;
	this->year = year;
	this->speed = speed;
	this->height = height;
	this->passenger_num = passenger_num;
}

void CShip::SetInfo(unsigned int price, unsigned short year, 
	unsigned short speed, unsigned short passenger_num, string port_name)
{
	this->price = price;
	this->year = year;
	this->speed = speed;
	this->port_name = port_name;
	this->passenger_num = passenger_num;
}

void CCar::GetInfo()
{
	cout << "Price: " << price << "\n" << "Year: " << year 
		<< "\n" << "Speed: " << speed << endl << endl;
}

void CPlane::GetInfo()
{
	cout << "Price: " << price << "\n" << "Year: " << year << "\n" 
		<< "Speed: " << speed << "\n" << "Height: " << height 
		<< "\n" << "Nums of passengers: " << passenger_num << endl << endl;
}

void CShip::GetInfo()
{
	cout << "Price: " << price << "\n" << "Year: " << year << "\n" 
		<< "Speed: " << speed << "\n" << "Height: " << port_name << "\n" 
		<< "Nums of passengers: " << passenger_num << endl << endl;
}

void CDriver::GetInfo(CVehicle* veh)
{
	veh->GetInfo();
}