#include <iostream>
#include <fstream>

using namespace std;

const string FILENAME = "data.txt";

class Dot
{
	int x;
	int y;
	int z;
	int Id;

	bool IsUnick(Dot* arr, int size) {

		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size; i++)
			{
				if (arr[i].Id == arr[j].Id)
				{
					return false;
				}
			}
		}

		return true;
	}

public:
	void Print() {

		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
		cout << "Z: " << z << endl;
		cout << "ID: " << Id << endl;
	}
	void PrintX() {
		cout << "X: " << x << endl;
	}
	void PrintY() {
		cout << "Y: " << y << endl;
	}
	void PrintZ() {
		cout << "Z: " << z << endl;
	}

	int GetId() {
		return Id;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
	int GetZ() {
		return z;
	}

	int SetId(Dot* arr, int size) {

		bool correct_id;
		int temp_Id = size;

		do
		{
			correct_id = IsUnick(arr, size);

			if (correct_id == false)
			{
				temp_Id++;
			}

		} while (correct_id == false);

		return temp_Id;
	}

	void Fill() {

		cout << "X: "; cin >> x;
		cout << "Y: "; cin >> y;
		cout << "Z: "; cin >> z;
	}

	void FillX() {
		cout << "X: "; cin >> x;
	}
	void FillY() {
		cout << "Y: "; cin >> y;
	}
	void FillZ() {
		cout << "Z: "; cin >> z;
	}

	void SetId(int temp) {
		Id = temp;
	}
	void SetX(int temp) {
		x = temp;
	}
	void SetY(int temp) {
		y = temp;
	}
	void SetZ(int temp) {
		z = temp;
	}

	void FillFromFile(int xF, int yF, int zF, int IdF) {
		x = xF;
		y = yF;
		z = zF;
		Id = IdF;
	}

	void SaveToFile(Dot*& arr, int& size)
	{
		ofstream outFile("data.txt", ios::out | ios::trunc);

		if (outFile.is_open()) {

			for (int i = 0; i < size; ++i) {

				outFile << arr[i].x << ":" << arr[i].y << ":" << arr[i].z << ":" << arr[i].Id << "|";
			}
			outFile.close();

			cout << "Successfully!" << endl;
		}
		else {
			cout << "I can't open this file!" << endl;
		}
	}
};

void FillFromFile(Dot*& arr, int& size)
{
	ifstream inFile("data.txt");

	if (inFile.is_open()) {

		while (!inFile.eof()) {

			int x, y, z, Id;
			char delimiter;

			inFile >> x >> delimiter >> y >> delimiter >> z >> delimiter >> Id >> delimiter;
			if (inFile.eof()) break;

			Dot readedDot;
			readedDot.FillFromFile(x, y, z, Id);

			Dot* temp = new Dot[size + 1];

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

void AddNewElement(Dot*& arr, int& size) {

	Dot* temp = new Dot[size + 1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	temp[size].Fill();
	int temp_id = temp[size].SetId(arr, size);
	temp[size].SetId(temp_id);

	delete[]arr;
	arr = temp;
	size++;
}

void Print_all(Dot* arr, int size) {

	for (int i = 0; i < size; i++)
	{
		arr[i].Print();
		cout << endl << "-_-_-_-_-_-_-_-_-_-" << endl;
	}
}

void Push(Dot* arr, int size) {

	Dot temp;
	temp.SaveToFile(arr, size);
}

int Choose_id(Dot* arr, int size) {

	int id_to_work;
	int temp;

	for (int i = 0; i < size; i++)
	{
		arr[i].Print();
	}

	cout << "Enter Id: "; cin >> id_to_work;

	for (int i = 0; i < size; i++)
	{
		temp = arr[i].GetId();
		if (temp == id_to_work)
		{
			return i;
		}
	}

	cout << "Wrong id!" << endl;

	return -1;
}

void main() {

	/*	Завдання №2
		Реалізуйте клас «Точка».Необхідно зберігати координати
		x, y, z в змінних - членах класу.Реалізуйте функції - члени
		класу для введення даних, виведення даних, реалізуйте
		аксесор для доступу до змінних - членів, реалізуйте збе -
		реження в файл і завантаження даних з файлу.*/

	int choice;
	bool isExit = false;

	int size = 0;
	Dot* arr = new Dot[size];

	while (!isExit)
	{
		system("pause");
		system("cls");

		cout << "___--- MENU ---___" << endl;
		cout << "[1] - create" << endl;
		cout << "[2] - change X" << endl;
		cout << "[3] - change Y" << endl;
		cout << "[4] - change Z" << endl;
		cout << endl;
		cout << "[5] - print" << endl;
		cout << "[6] - print X" << endl;
		cout << "[7] - print Y" << endl;
		cout << "[8] - print Z" << endl;
		cout << endl;
		cout << "[9] - Set X" << endl;
		cout << "[10] - Set Y" << endl;
		cout << "[11] - Set Z" << endl;
		cout << endl;
		cout << "[12] - push to file" << endl;
		cout << "[13] - pull from file" << endl;
		cout << endl;
		cout << "[0] - EXIT" << endl;
		cout << endl;
		cout << "|:>  "; cin >> choice;


		switch (choice)
		{
		case 0: // EXIT
			isExit = true;
			break;
		case 1: // create
			AddNewElement(arr, size);
			break;
		case 2: // change X
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					arr[temp].FillX();
				}
			}
			break;
		case 3: // change Y
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					arr[temp].FillY();
				}
			}
			break;
		case 4: // change Z
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					arr[temp].FillZ();
				}
			}
			break;
		case 5: // print
			Print_all(arr, size);
			break;
		case 6: // print X
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					arr[temp].PrintX();
				}
			}
			break;
		case 7: // print Y
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					arr[temp].PrintY();
				}
			}
			break;
		case 8: // print Z
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					arr[temp].PrintZ();
				}
			}
			break;
		case 9: // Set X
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					int new_element;
					cout << "Enter new X: "; cin >> new_element;
					arr[temp].SetX(new_element);
				}
			}
			break;
		case 10: // Set Y
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					int new_element;
					cout << "Enter new Y: "; cin >> new_element;
					arr[temp].SetY(new_element);
				}
			}
			break;
		case 11: // Set Z
			if (size > 0)
			{
				int temp = Choose_id(arr, size);
				if (temp != -1)
				{
					int new_element;
					cout << "Enter new Z: "; cin >> new_element;
					arr[temp].SetZ(new_element);
				}
			}
			break;
		case 12: // push to file
			Push(arr, size);
			break;
		case 13: // pull from file
			FillFromFile(arr, size);
			break;
		default:
			break;
		}
	}

	delete[]arr;
}