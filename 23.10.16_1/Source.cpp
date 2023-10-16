#include <iostream>

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
	Array(int size)
	{
		this->size = size;
		
		if (size > 0){
			arr = new int[size] {};
		}
		else {
			arr = nullptr;
		}
	}
	Array(const Array &other)
	{
		this->size = other.size;
		this->arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}

	void FillRandom(){
	
		if (size <= 0){

			cout << "The size of the array is incorrect!" << endl;
			return;
		}

		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100;
		}
	}
	void FillKeyboard(){
	
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
	void SortMaxMin(){

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
		if (index >=0 && index <= size)
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

	~Array()
	{
		delete[]arr;
	}
};

void main() {
	/*						Конструктор копіювання, вказіник this

	Створіть клас Array - це клас динамічного масиву чисел з певним функціоналом.
		Властивостями класа буде вказівник на сам масив(int* arr) та його теперішній розмір(int size).

		Клас повинен дозволяти наступний функціонал :
			• Заповнити масив значеннями(випадковими, з клавіатури, по замовчуванню
			(заповнити масив 0))
			• Відображати вміст масиву
			Додавати елемент в масив
			Видаляти елемент з масива(по значенню або по індексу)
			Відсортувати масив(по спаданню / зростанню)
			• Визначати значення(мінімальне, максимальне та середнє арифметичне)

		Також передбачити набір конструкторів :
			Конструктор замовчуванням, який встановлювтиме початкові значення(заповнити масив 0))
			Конструктор, який прийматиме розмір масиву та заповнюватиме нулем всі елементи
			Конструктор копіювання, який буде копіювати всі дані об'єкта включаючи масив
			Також реалізувати деструктор в класі для уникнення втрати пам'яті. 
			Врахувати можливі помилки (видалення не існуючого елемента, порожній масив і тд.). Успіхів!
			Всі методі, які не змінюють оригінал мають бути CONST.
	*/
}