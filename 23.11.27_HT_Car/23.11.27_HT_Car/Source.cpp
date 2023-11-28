#include <iostream>
#include "Classes_for_car.h"

using namespace std;

class Car
{
	Body body;
	Engine engine;
	Door doors[4];
	Wheel wheels[4];
	Headlight lights[2];

	Driver* driver;
	DrivingCategory car_category;

public:

	Car() : body(), engine(), car_category('B'), driver(nullptr) 
	{
		for (int i = 0; i < 2; i++)
		{
			doors[i] = Door();
			wheels[i] = Wheel();
		}
		for (int i = 0; i < 2; i++)
		{
			lights[i] = Headlight();
		}
	}
	Car(string type) : body(type), engine(type), car_category('B'), driver(nullptr)
	{
		for (int i = 0; i < 2; i++)
		{
			doors[i] = Door(type);
			wheels[i] = Wheel(type);
		}
		for (int i = 0; i < 2; i++)
		{
			lights[i] = Headlight(type);
		}
	}
	Car(string type, DrivingCategory dc) : body(type), engine(type), car_category(dc), driver(nullptr)
	{
		for (int i = 0; i < 2; i++)
		{
			doors[i] = Door(type);
			wheels[i] = Wheel(type);
		}
		for (int i = 0; i < 2; i++)
		{
			lights[i] = Headlight(type);
		}
	}
	Car(string type, DrivingCategory dc, Driver *driver) : body(type), engine(type), car_category(dc), driver(driver)
	{
		for (int i = 0; i < 2; i++)
		{
			doors[i] = Door(type);
			wheels[i] = Wheel(type);
		}
		for (int i = 0; i < 2; i++)
		{
			lights[i] = Headlight(type);
		}
	}

	void Print() const
	{
		cout << "_-_-_-_-_-_-_-| CAR INFO |__-_-_-_-_-_-_" << endl;
		body.Print();
		engine.Print();
		doors[0].Print();
		wheels[0].Print();
		lights[0].Print();
		car_category.Print();

		cout << "\nDriver:" << endl;
		if (driver != nullptr)
		{
			driver->Print();
		}
		else
		{
			cout << "None" << endl;
		}
	}

	bool AggregateDriver(Driver *driver)
	{
		if (driver->GetCategory() == car_category)
		{
			this->driver = driver;
			return true;
		}
		return false;
	}
	bool RemoveDriver()
	{
		if (driver != nullptr)
		{
			driver = nullptr;
			return true;
		}
		return false;
	}
};

void main()
{
	Car car1;
	cout << "car 1" << endl;
	car1.Print();

	cout << "-------------------------" << endl;

	DrivingCategory category('C', 1);

	Car car2("truck", category);
	cout << "car 2" << endl;
	car2.Print();

	cout << "-------------------------" << endl;

	Driver Sam("Sam", "Winchester", 23, 3, category);
	cout << "Create driver: " << endl;
	Sam.Print();

	cout << "-------------------------" << endl;
	
	car2.AggregateDriver(&Sam);
	cout << "Add Sam to car 2, print car 2 info after this: " << endl;
	car2.Print();

	cout << "-------------------------" << endl;

	car2.RemoveDriver();
	cout << "Remove him from this car and print info after: " << endl;
	car2.Print();
}