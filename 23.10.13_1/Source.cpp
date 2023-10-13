#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Abonent {

	string name;
	string home_phone_number;
	string work_phone;
	string cell_phone;
	string extra_info;

	static int AbonentsCounter;

public:

	Abonent() // Default
	{
		name = "no name";
		home_phone_number = "no phone number";
		work_phone = "no work number";
		cell_phone = "no cell phone";
		extra_info = "no extra info";

		AbonentsCounter++;
	}
	Abonent(string name) :Abonent() // 1
	{
		this->name = name;
	}
	Abonent(string name, string home_phone_number) :Abonent(name) // 2
	{
		this->home_phone_number = home_phone_number;
	}
	Abonent(string name, string home_phone_number, string work_phone) :Abonent(name, home_phone_number) // 3
	{
		this->work_phone = work_phone;
	}
	Abonent(string name, string home_phone_number, string work_phone, string cell_phone) :Abonent(name, home_phone_number, work_phone) // 4
	{
		this->cell_phone = cell_phone;
	}
	Abonent(string name, string home_phone_number, string work_phone, string cell_phone, string extra_info) :Abonent(name, home_phone_number, work_phone, cell_phone) // 5
	{
		this->extra_info = extra_info;
	}

	static void PrintCounter() {
		cout << "Abonents counter = " << AbonentsCounter << endl;
	}
	static int GetCounter() {
		return AbonentsCounter;
	}

	void FillAbonent() {

		cout << "name: "; cin >> name;
		cout << "home_phone_number: "; cin >> home_phone_number;
		cout << "work_phone: "; cin >> work_phone;
		cout << "cell_phone: "; cin >> cell_phone;
		cout << "extra_info: "; cin >> extra_info;
	}

	void Print() {

		cout << "name: " << name << endl;
		cout << "home_phone_number: " << home_phone_number << endl;
		cout << "work_phone: " << work_phone << endl;
		cout << "cell_phone: " << cell_phone << endl;
		cout << "extra_info: " << extra_info << endl;
	}

	string Get_name() {
		return name;
	}
	string Get_home_phone_number() {
		return home_phone_number;
	}
	string Get_work_phone() {
		return work_phone;
	}
	string Get_cell_phone() {
		return cell_phone;
	}
	string Get_extra_info() {
		return extra_info;
	}

	~Abonent()
	{
		AbonentsCounter--;
	}

	void SaveToFile(Abonent*& arr, int& size)
	{
		ofstream outFile("data.txt", ios::out | ios::trunc);

		if (outFile.is_open()) {

			for (int i = 0; i < size; ++i) {

				outFile << arr[i].name << ":" << arr[i].home_phone_number << ":" << arr[i].work_phone << ":" << arr[i].cell_phone << ":" << extra_info << "|";
			}
			outFile.close();

			cout << "Successfully!" << endl;
		}
		else {
			cout << "I can't open this file!" << endl;
		}
	}
	void FillFromFile(string nameF, string home_phone_numberF, string work_phoneF, string cell_phoneF, string extra_infoF) {
		name = nameF;
		home_phone_number = home_phone_numberF;
		work_phone = work_phoneF;
		cell_phone = cell_phoneF;
		extra_info = extra_infoF;
	}
	void FillFromFile(Abonent*& arr, int& size)
	{
		ifstream inFile("data.txt");

		if (inFile.is_open()) {

			while (!inFile.eof()) {

				string name;
				string home_phone_number;
				string work_phone;
				string cell_phone;
				string extra_info;
				char delimiter;

				inFile >> name >> delimiter >> home_phone_number >> delimiter >> work_phone >> delimiter >> cell_phone >> delimiter >> extra_info >> delimiter;
				if (inFile.eof()) break;

				Abonent readedDot;
				readedDot.FillFromFile(name, home_phone_number, work_phone, cell_phone, extra_info);

				Abonent* temp = new Abonent[size + 1];

				for (int i = 0; i < size; i++) {
					temp[i] = arr[i];
				}

				temp[size] = readedDot;

				delete[] arr;
				arr = temp;
				size++;
			}

			inFile.close();

			cout << "Successfully!" << endl;
		}
		else {
			cout << "I can't open this file!" << endl;
		}
	}
};

class PhoneBook {

	int abonents_counter;
	Abonent* abonents;

public:
	PhoneBook()
	{
	     abonents_counter = 0;
		abonents = new Abonent[abonents_counter];
	}

	void AddCounter() {
		abonents_counter = Abonent::GetCounter();
	}
	void MinusCounter() {
		abonents_counter = Abonent::GetCounter();
	}

	void Print() {

		for (int i = 0; i < abonents_counter; i++)
		{
			abonents[i].Print();
			cout << "----------------------------" << endl;
		}
	}

	void AddAbonent() {

		Abonent* temp = new Abonent[abonents_counter + 1];

		for (int i = 0; i < abonents_counter; i++)
		{
			temp[i] = abonents[i];
		}

		temp[abonents_counter].FillAbonent();

		delete[]abonents;
		abonents = temp;
		AddCounter();
	}
	void DeleteFirstAbonent() {

		Abonent* temp = new Abonent[abonents_counter - 1];

		for (int i = 1; i < abonents_counter; i++)
		{
			temp[i - 1] = abonents[i];
		}

		delete[]abonents;
		abonents = temp;
		MinusCounter();
	}

	void FindByName() {

		string temp;
		bool find = false;

		cout << "Enter name: "; getline(cin, temp);

		for (int i = 0; i < abonents_counter; i++)
		{
			if (abonents[i].Get_name() == temp)
			{
				abonents[i].Print(); find = true;
			}
		}

		if (find == false)
		{
			cout << "Person is not found!" << endl;
		}
	}

	~PhoneBook()
	{
		delete[]abonents;
	}
};

int Abonent::AbonentsCounter = 0;

void main() {

		/*
		Створіть додаток «Телефонна книга». 
			Необхідно зберігати дані про абонента (ПІБ, домашній телефон, робочий
			телефон, мобільний телефон, додаткова інформація про
			контакт) всередині відповідного класу(Abonent). 
			Наповніть клас 
				змінними-членами
				функціями-членами
				конструкторами
				використовуйте ініціалізатор

			Створити статичну змінну для кількості абонентів. 
			Використати делегування конструкторів.
				class PhoneBook
				{
				Abonent * abonents
				int countAbonent 
				}

			Надайте користувачеві можливість: 
				додавати нових абонентів
				видаляти абонентів
				шукати абонентів за ПІБ
				показувати всіх абонентів
 
		***зберігати інформацію в файл і завантажувати з файлу.
		*/

}