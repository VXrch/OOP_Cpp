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
			arr[i] = rand() % 100;
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

	void SortMinMax() {

		int temp;

		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					temp = arr[i + 1];
					arr[i + 1] = arr[i];
					arr[i] = temp;
				}
			}
		}
	}
	void SortMaxMin() {

		int temp;

		for (int j = 0; j < size; j++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (arr[i] < arr[i + 1])
				{
					temp = arr[i + 1];
					arr[i + 1] = arr[i];
					arr[i] = temp;
				}
			}
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
	void PrintIndex(int index) const
	{
		if (index >= 0 && index <= size)
		{
			cout << "Arr [" << index << "] = " << arr[index] << endl;
		}
		else {
			cout << "Wrong index!" << endl;
		}
		cout << endl;
	}

	int FindMin() const
	{
		int min = 1000;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}

		return min;
	}
	int FindMax() const
	{
		int max = -1000;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] < max)
			{
				max = arr[i];
			}
		}

		return max;
	}
	int FindAverage() const
	{
		int sum = 0;

		for (int i = 0; i < size; i++)
		{
			sum += arr[i];
		}

		int average = sum / (size - 1);

		return average;
	}

	int GetSize() const
	{
		return size;
	}

	void AddConcreteElement(int to_add) {

		int* temp = new int[size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}

		temp[size] = to_add;

		delete[] arr;
		arr = temp;
		size++;
	}
	void AddElement(int to_add) {

		int* temp = new int[size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}

		temp[size] = rand() % 100;

		delete[] arr;
		arr = temp;
		size++;
	}
	void DeleteElementByIndex(int index) {

		if (index < size || index >= size) {

			cout << "Wrong index!" << endl;
			return;
		}

		int* temp = new int[size - 1];

		for (int i = 0; i < size; i++)
		{
			if (i != index) {
				temp[i] = arr[i];
			}
		}

		delete[] arr;
		arr = temp;
		size--;
	}
	void DeleteElementByValue(int value) {

		if (value < size || value >= size) {

			cout << "Wrong index!" << endl;
			return;
		}

		int* temp = new int[size - 1];
		bool deleted_value = false;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] != value && deleted_value == false) {

				temp[i] = arr[i];
				deleted_value = true;
			}
		}

		delete[] arr;
		arr = temp;
		size--;
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

void main()
{
	/*
		До раніше створеного класу Array додайте перетворення типів до int і string
			• Перетворення до int повертає суму елементів масиву.
			• Перетворення до string повертає значення елементів масива у вигляді рядка.
	*/

	Array arr(3);
	arr.FillKeyboard();

	int a = arr;
	cout << "Res (to int): " << a << endl;

	string b = arr;
	cout << "Res (to string): " << b << endl;
}