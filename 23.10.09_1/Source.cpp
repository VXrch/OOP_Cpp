#include <iostream>
#include <string>

using namespace std;

struct Date
{
	unsigned int day;
	string month;
	unsigned int year;

	void EmptyInit() {
		day = 1;
		month = "01";
		year = 1001;
	}

	void Fill() {

		cout << "Day: "; cin >> day;
		cout << "Month: "; cin >> month;
		cout << "Year: "; cin >> year;
	}

	void Print() {

		cout << day << "/" << month << "/" << year << endl;
	}

	Date ReturnDate() {

		Date temp;

		cout << "Day: "; cin >> temp.day;
		cout << "Month: "; cin >> temp.month;
		cout << "Year: "; cin >> temp.year;

		return temp;
	}
};

struct University {

	string name;
	string city;
	string country;

	void EmptyInit() {

		name = "Name";
		city = "City";
		country = "Country";
	}

	void Fill() {

		cout << "Enter student's university name: "; getline(cin, name);
		cout << "Enter student's university city: "; getline(cin, city);
		cout << "Enter student's university country: "; getline(cin, country);
	}

	void Show() {
		cout << "University name: " << name << endl;
		cout << "University city: " << city << endl;
		cout << "University country: " << country << endl;
	}

	University ReturnUniversity() {

		University temp;

		cout << "Enter student's university name: "; getline(cin, temp.name);
		cout << "Enter student's university city: "; getline(cin, temp.city);
		cout << "Enter student's university country: "; getline(cin, temp.country);

		return temp;
	}
};

class Student
{
	string name;
	string surname;
	string lastname;
	Date birthday;
	string phone;
	string city;
	string country;
	University university;
	string group_number;

	int* marks;
	int countMarks;
	float average;

	void SetAverage() {
		
		float sum = 0;

		for (int i = 0; i < countMarks; i++)
		{
			sum += marks[i];
		}
		average = (float)sum / countMarks;
	}

public:

	Student()
	{
		name = "NoName";
		surname = "NoSurname";
		lastname = "NoLastname";
		birthday.EmptyInit();
		phone = "NoPhone";
		city = "NoCity";
		country = "NoCountry";
		university.EmptyInit();
		group_number = "NoGroup";
	}

	void InitFromKeyboard() {

		cout << "Enter student's name: "; getline(cin, name);
		cout << "Enter student's surname: "; getline(cin, surname);
		cout << "Enter student's lastname: "; getline(cin, lastname);
		birthday.Fill();
		cin.ignore();
		cout << "Enter student's phone number: "; getline(cin, phone);
		cout << "Enter student's group number: "; getline(cin, group_number);
		cout << "Enter student's city: "; getline(cin, city);
		cout << "Enter student's country: "; getline(cin, country);
		university.Fill();
	}
	void Show() {

		cout << endl;

		cout << "Enter student's name: " << name << endl;
		cout << "Enter student's surname: " << surname << endl;
		cout << "Enter student's lastname: " << lastname << endl;
		cout << "Birthday: ";  birthday.Print();
		cout << "Enter student's phone number: " << phone << endl;
		cout << "Enter student's group number: " << group_number << endl;
		cout << "Enter student's city: " << city << endl;
		cout << "Enter student's country: " << country << endl;
		university.Show();
		cout << "\nRating: " << average << endl;
		cout << "Marks: " << endl;
		for (int i = 0; i < countMarks; i++)
		{
			cout << marks[i] << "  ";
		}

		cout << endl;
	}

	void AddMark(int mark) {

		int* temp = new int[countMarks + 1];

		for (int i = 0; i < countMarks; i++)
		{
			temp[i] = marks[i];
		}

		temp[countMarks] = mark;

		if (marks != nullptr){
			delete[] marks;
		}

		marks = temp;
		countMarks += 1;
		SetAverage();
	}

	void Set_name(string name){
		this->name = name;
	}
	void Set_surname(string surname){
		this->surname = surname;
	}
	void Set_lastname(string lastname){
		this->lastname = lastname;
	}
	void Set_phone(string phone){
		this->phone = phone;
	}
	void Set_group_number(string group_number){
		this->group_number = group_number;
	}
	void Set_city(string city){
		this->city = city;
	}
	void Set_country(string country){
		this->country = country;
	}
	void Set_date(Date birthday) {
		this->birthday = birthday;
	}

	void Set_university_name(string university_name) {
		this->university.name = university_name;
	}
	void Set_university_city(string university_city) {
		this->university.city = university_city;
	}
	void Set_university_country(string university_country) {
		this->university.country = university_country;
	}
	void Set_university(University university) {
		this->university = university;
	}

	string Get_name() {
		return name;
	}
	string Get_surname() {
		return surname;
	}
	string Get_lastname() {
		return lastname;
	}
	string Get_phone() {
		return phone;
	}
	string Get_group_number() {
		return group_number;
	}
	string Get_city() {
		return city;
	}
	string Get_country() {
		return country;
	}
	Date Get_date() {
		return birthday;
	}
	University Get_university() {
		return university;
	}

	~Student()
	{
		cout << "Destructor" << endl;

		if (marks != nullptr) {
			delete[] marks;
		}
	}
};

void main() {

	Student st;
	st.Show();

	Student st2;
	st2.AddMark(7);
	st2.AddMark(10);
	st2.AddMark(5);
	st2.AddMark(8);
	st2.AddMark(7);
	st2.AddMark(9);
	st2.Show();

	/*st.InitFromKeyboard();
	st.Show();*/	
}