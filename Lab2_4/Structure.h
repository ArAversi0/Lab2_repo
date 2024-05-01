#pragma once

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::to_string;

class CVehicle
{
public:
	CVehicle();
	CVehicle(unsigned int price, unsigned short year, unsigned short speed);
	~CVehicle();

	virtual void GetInfo() = 0;

protected:
	class ÑÑoordinates
	{
	
	public:
		ÑÑoordinates();
		ÑÑoordinates(float x, float y, float z);
		~ÑÑoordinates();

		void SetCoors(float x, float y, float z);
		string GetCoors();

	private:
		float x;
		float y;
		float z;
	};
	unsigned int price;
	unsigned short year;
	unsigned short speed;
};

class CCar : public CVehicle
{
public:
	CCar();
	CCar(unsigned int price, unsigned short year, unsigned short speed);
	~CCar();

	void SetInfo(unsigned int price, unsigned short year, unsigned short speed);
	virtual void GetInfo() override;

private:

};

class CPlane : public CVehicle
{
public:
	CPlane();
	CPlane(unsigned int price, unsigned short year, unsigned short speed, unsigned int height, unsigned short passenger_num);
	~CPlane();

	void SetInfo(unsigned int price, unsigned short year, unsigned short speed, unsigned int height, unsigned short passenger_num);
	virtual void GetInfo() override;

private:
	unsigned int height;
	unsigned short passenger_num;
};

class CShip : public CVehicle
{
public:
	CShip();
	CShip(unsigned int price, unsigned short year, unsigned short speed, unsigned short passenger_num, string port_name);
	~CShip();

	void SetInfo(unsigned int price, unsigned short year, unsigned short speed, unsigned short passenger_num, string port_name);
	virtual void GetInfo() override;

private:
	unsigned short passenger_num;
	string port_name;
};

class CDriver
{
public:
	void GetInfo(CVehicle* veh);

private:

};


