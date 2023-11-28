#pragma once
#include <iostream>

using namespace std;

class PartOfCar
{
protected:
	string type;

	PartOfCar() : type("standart") {}
	PartOfCar(string type) : type(type) {}
	
	virtual void Print() const = 0;

	string GetType() const
	{
		return type;
	}
	void SetType(string type)
	{
		this->type = type;
	}
};

class Engine : public PartOfCar
{
public:

	Engine() : PartOfCar() {}
	Engine(string type) : PartOfCar() {}

	void Print() const override
	{
		cout << "Engine type: " << type << endl;
	}
};

class Door : public PartOfCar
{
public:

	Door(): PartOfCar() {}
	Door(string type) : PartOfCar(type) {}

	void Print() const override
	{
		cout << "Door type: " << type << endl;
	}
};

class Wheel : public PartOfCar
{
public:

	Wheel() : PartOfCar() {}
	Wheel(string type) : PartOfCar(type) {}

	void Print() const override
	{
		cout << "Wheel type: " << type << endl;
	}
};

class Body : public PartOfCar
{
public:

	Body() : PartOfCar() {}
	Body(string type) : PartOfCar(type) {}

	void Print() const override
	{
		cout << "Body type: " << type << endl;
	}
};

class Headlight : public PartOfCar
{
public:

	Headlight() : PartOfCar() {}
	Headlight(string type) : PartOfCar(type) {}

	void Print() const override
	{
		cout << "Head light type: " << type << endl;
	}
};

class DrivingCategory
{
	char Letter;
	int Number;
	bool trailer;

public:

	DrivingCategory() : Letter('A'), Number(1), trailer(false) {}
	DrivingCategory(char Letter)
	{
		(IsValidLetter(Letter)) ? this->Letter = Letter : this->Letter = 'A';
		this->Number = 0;
	}
	DrivingCategory(char Letter, int Number)
	{
		(IsValidLetter(Letter)) ? this->Letter = Letter : this->Letter = 'A';
		(IsValidNumber(Number)) ? this->Number = Number : this->Number = 0;
		this->trailer = false;
	}
	DrivingCategory(char Letter, bool trailer)
	{
		(IsValidLetter(Letter)) ? this->Letter = Letter : this->Letter = 'A';
		this->trailer = trailer;
		this->Number = 0;
	}
	DrivingCategory(char Letter, int Number, bool trailer)
	{
		(IsValidLetter(Letter)) ? this->Letter = Letter : this->Letter = 'A';
		(IsValidNumber(Number)) ? this->Number = Number : this->Number = 0;
		this->trailer = trailer;
	}

	void Print() const
	{
		cout << "Category: " << Letter;
		if (Number == 1)
		{
			cout << Number;
		}
		if (trailer == true)
		{
			cout << "E";
		}
		cout << endl;
	}

	bool IsValidLetter(char l)
	{
		if (l == 'A' || l == 'B' || l == 'C' || l == 'D' || l == 'BE' || l == 'CE' || l == 'DE' || l == 'T')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsValidNumber(int n)
	{
		if (n == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator == (DrivingCategory temp)
	{
		if (temp.Letter == this->Letter && temp.Number == this->Number && temp.trailer == this->trailer)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Driver
{
	string name;
	string surname;
	int age;
	int experience;
	DrivingCategory drivingCategory;

public:

	Driver(): name("no name"), surname("no surname"), age(21), experience(0), drivingCategory('B', 1) {}
	Driver(string name, string surname, int age, int experience, DrivingCategory drivingCategory): name(name), surname(surname), age(age), experience(experience), drivingCategory(drivingCategory) {}

	void Print() const
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
		cout << "Experience: " << age << " years" << endl;
		drivingCategory.Print();
	}
	DrivingCategory GetCategory() const
	{
		return drivingCategory;
	}
};