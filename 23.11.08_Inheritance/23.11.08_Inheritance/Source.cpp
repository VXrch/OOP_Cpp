#include <iostream>

using namespace std;

class Student
{
protected:

	string name;
	string surname;
	string speciality;
	int age;

public:

	Student() : name("No name"), surname("No surname"), speciality("No speciality"), age(0) {}
	Student(string n, string s, string spec, int age) : name(n), surname(s), speciality(spec), age(age) {}

	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Speciality: " << speciality << endl;
		cout << "Age: " << age << endl;
	}

	/*						Завдання N1
		Створіть клас Student, який міститиме інформацію
		про студента.
		За допомогою механізму успадкування, реалізуйте клас
		Aspirant(аспірант — студент, який готується до захисту
			кандидатської роботи) похідний від Student.
	*/

};

class Aspirant : public Student
{
	string workTheme;

public:

	Aspirant() : workTheme("No theme"), Student() {}
	Aspirant(string theme) : workTheme(theme), Student() {}
	Aspirant(string n, string s, string spec, int age, string theme) : workTheme(theme), Student(n, s, spec, age) {}

	void Print()
	{
		Student::Print();
		cout << "Aspirant work theme: " << workTheme << endl;
	}
};

void main()
{
	Student a("Oleg", "GRTas", "Inform", 23);
	a.Print();

	cout << "__________________" << endl;

	Aspirant b("Anya", "SDFGH", "Inform", 23, "WORK THEME");
	b.Print();
}