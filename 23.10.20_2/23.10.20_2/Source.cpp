#include <iostream>
#include <string>

using namespace std;

class Array {

	int size;
	int* arr;

public:

	Array()
	{
		size = 0;
		arr = nullptr;
	}
	explicit Array(int size)
	{
		this->size = size;

		if (size > 0) {
			arr = new int[size] {};
		}
		else {
			arr = nullptr;
		}
	}
	Array(const Array& other)
	{
		this->size = other.size;
		this->arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}

	void FillRandom() {

		if (size <= 0) {

			cout << "The size of the array is incorrect!" << endl;
			return;
		}

		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
		}
	}
	void FillKeyboard() {

		if (size <= 0) {

			cout << "The size of the array is incorrect!" << endl;
			return;
		}

		int temp;

		for (int i = 0; i < size; i++)
		{
			cout << "Enter [" << i << "] :  "; cin >> temp;
			arr[i] = temp;
		}
	}

	void PrintAll() const
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Arr [" << i << "] = " << arr[i] << endl;
		}
		cout << endl;
	}

	int operator [] (int index){
		return arr[index];
	}
	void operator () (int to_add) {

		for (int i = 0; i < size; i++)
		{
			arr[i] += to_add;
		}
	}

	operator int() {

		int sum = 0;

		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}
	operator string()
	{
		string res = "";
		for (int i = 0; i < size; i++)
		{
			res += to_string(arr[i]) + " ";
		}
		return res;
	}

	~Array()
	{
		delete[]arr;
	}
};

void main() {

	/*
		До раніше створеного класу Array додайте перевантаження оператора[], ()

			[] – повертає елемент за вказаним індексом(по посиланню)
			() – збільшує всі елементи масиву на зазначену величину
	*/

	Array arr(10);
	arr.FillRandom();
	arr.PrintAll();
	cout << "ARR [5] = " << arr[5] << endl;
	cout << endl;
	arr(5);
	cout << "Arr (+5 to each element): ";
	arr.PrintAll();
}