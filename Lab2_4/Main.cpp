#include "Structure.h"

int main() {
	
	setlocale(LC_ALL, "ru");

	CDriver driver1;
	CDriver driver2;
	
	CCar car1(15000, 2009, 260);
	CPlane plane1;
	CPlane plane2(250000, 2006, 1480, 40000, 600);
	CShip ship1(320000, 2011, 37, 150, "Мурманск");
	
	car1.SetInfo(17500, 2009, 260);
	plane1.SetInfo(200000, 2008, 1400, 38000, 350);
	ship1.SetInfo(320000, 2013, 38, 150, "Мурманск");

	driver1.GetInfo(&car1);
	driver1.GetInfo(&plane1);
	driver2.GetInfo(&plane2);
	driver2.GetInfo(&ship1);

	return 0;
}