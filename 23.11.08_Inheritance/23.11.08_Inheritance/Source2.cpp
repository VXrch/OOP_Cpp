#include <iostream>

using namespace std;

class Passport
{
protected:

	string name;
	string surname;
	int age;
	string passportNumber;

public:

	Passport() : name("No name"), surname("No surname"), age(0) {}
	Passport(string n, string s, int age, string passportNumber) : name(n), surname(s), age(age), passportNumber(passportNumber){}

	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Age: " << age << endl;
		cout << "Passport number: " << passportNumber << endl;
	}

	/*						Завдання N2
			Створіть клас Passport (паспорт), який буде містити
			паспортну інформацію про громадянина України.

			За допомогою механізму успадкування, реалізуйте
			клас ForeignPassport (закордонний паспорт) похідний
			від Passport.

			Нагадаємо, що закордонний паспорт містить крім
			паспортних даних, також дані про візи, номер закордон-
			ного паспорта.
	*/

};

class ForeignPassport : public Passport
{
	string visa;

public:

	ForeignPassport() : visa("No visa"), Passport() {}
	ForeignPassport(string visa) : visa(visa), Passport() {}
	ForeignPassport(string n, string s, int age, string pn, string visa) : visa(visa), Passport(n, s, age, pn) {}

	void Print()
	{
		Passport::Print();
		cout << "Visa: " << visa << endl;
	}
};

void main()
{
	Passport a("Oleg", "GRTas", 23, "F567A3B");
	a.Print();

	cout << "__________________" << endl;

	ForeignPassport b("Anya", "SDFGH", 23, "A23B673", "United States");
	b.Print();
}