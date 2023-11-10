#include <iostream>

using namespace std;

const double Pi = 3.1415926535;

class Shape 
{
protected:

	string name;
	string type;

public:

	Shape() : name(" "), type(" ") {}
	Shape(string name, string type) : name(name), type(type) {}

	virtual void Show() const
	{
		cout << "Shape name: " << name << endl;
		cout << "Shape type: " << name << endl;
	}
	virtual double GetArea() const
	{
		cout << "I can't get area because i don't know this shape!" << endl;
		return 0;
	}
};

class Rectngle : public Shape
{
	int sideA;
	int sideB;

public:

	Rectngle() : sideA(1), sideB(1) {}
	Rectngle(string name, string type, int sideA, int sideB) : sideA(sideA), sideB(sideB), Shape(name, type) {}

	void Show() const override
	{
		Shape::Show();
		cout << "Rectangle side A: " << sideA << endl;
		cout << "Rectangle side B: " << sideB << endl;
	}
	double GetArea() const override
	{
		return sideA * sideB;
	}
};

class Crcle : public Shape
{
	int radius;

public:

	Crcle() : radius(1) {}
	Crcle(string name, string type, int radius) : radius(radius), Shape(name, type) {}

	void Show() const override
	{
		Shape::Show();
		cout << "Circle radius: " << radius << endl;
	}
	double GetArea() const override
	{
		return (radius * radius) * Pi;
	}
};

class RightTriangle : public Shape
{
	int catenaryA;
	int catenaryB;
	int hypotenuse;

public:

	RightTriangle() : catenaryA(1), catenaryB(1), hypotenuse(2) {}
	RightTriangle(string name, string type, int catenaryA, int catenaryB, int hypotenuse) : catenaryA(catenaryA), catenaryB(catenaryB), hypotenuse(hypotenuse), Shape(name, type) {}

	void Show() const override
	{
		Shape::Show();
		cout << "Right triangle catenary A: " << catenaryA << endl;
		cout << "Right triangle catenary B: " << catenaryB << endl;
		cout << "Right triangle hypotenuse: " << hypotenuse << endl;
	}
	double GetArea() const override
	{
		return (catenaryA * catenaryB) / 2;
	}
};

class Triangle : public Shape
{
	int catenaryA;
	int catenaryB;
	int catenaryC;
	int height;

public:

	Triangle() : catenaryA(1), catenaryB(1), catenaryC(1), height(1) {}
	Triangle(string name, string type, int catenaryA, int catenaryB, int catenaryC, int height) : catenaryA(catenaryA), catenaryB(catenaryB), catenaryC(catenaryC), height(height), Shape(name, type) {}

	void Show() const override
	{
		Shape::Show();
		cout << "Right triangle catenary A: " << catenaryA << endl;
		cout << "Right triangle catenary B: " << catenaryB << endl;
		cout << "Right triangle catenary C: " << catenaryC << endl;
		cout << "Right triangle height: " << height << endl;
	}
	double GetArea() const override
	{
		return (catenaryA * height) / 2;
	}
};

class Trapezoid : public Shape
{
	int sideA;
	int sideB;
	int height;

public:

	Trapezoid() : sideA(1), sideB(1), height(1) {}
	Trapezoid(string name, string type, int sideA, int sideB, int height) : sideA(sideA), sideB(sideB), height(height), Shape(name, type) {}

	void Show() const override
	{
		Shape::Show();
		cout << "Trapezoid side A: " << sideA << endl;
		cout << "Trapezoid side B: " << sideB << endl;
		cout << "Trapezoid height: " << height << endl;
	}
	double GetArea() const override
	{
		return ((sideA + sideB) / 2) * height;
	}
};

void TestShape(Shape& x)
{
	x.Show();
	cout << x.GetArea() << endl;
}

void main()
{


	/*					Завдання 1:
		Створіть клас Shape який містить загальні параметри
			будь - якої фігури(ім'я, тип і тд).
			
		Визначте віртуальні методи :
				•Show – вивід на екран інформації про фігуру;
				•GetArea – обчислення площі фігури;

		Визначте похідні класи : 
			- прямокутник
			- коло
			- прямокутний трикутник
			- трикутник
			- трапеція зі своїми функціями площі
			
		Кожний з яких буде містити притаманні даній фігурі характеристики та перевизначати(override)
			алгоритми методів базового класу Shape.
		Також створити функцію TestShape, яка приймає фігуру та відображає її
			інформацію включаючи площу.
		В main протестувати роботу, передавши в функцію різні фігури.
	*/

	Rectngle a("Rectngle", "rectngle", 4, 8);
	TestShape(a);

	Crcle b;
	TestShape(b);

	RightTriangle c;
	TestShape(c);

	Trapezoid d;
	TestShape(d);

	Triangle e;
	TestShape(e);
}