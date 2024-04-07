#pragma once

// Задание 1

class GeomAverage
{
private:
	float x;
	float y;

public:
	GeomAverage(float x, float y);
	GeomAverage();

	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();

	void Print();
	void Sqrt();

};