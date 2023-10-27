#include <iostream>

using namespace std;

template<typename T_arr>
class Array {

	int size;
	T_arr* arr;

public:

	Array() :size(0), arr(nullptr) {}
	explicit Array(int size)
	{
		this->size = size;

		if (size > 0) {
			arr = new T_arr[size] {};
		}
		else {
			arr = nullptr;
		}
	}
	Array(const Array& other)
	{
		this->size = other.size;
		this->arr = new T_arr[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = other.arr[i];
		}
	}
	Array(const initializer_list<T_arr>& list)
	{
		if (arr != nullptr) delete[]arr;

		this->size = list.size();
		arr = new T_arr[size];

		int i = 0;
		for (int element : list)
		{
			arr[i++] = element;
		}
	}

	void FillRandom();
	void FillKeyboard();

	void PrintAll() const;
	void PrintIndex(int index) const;

	void SortMinMax();
	void SortMaxMin();

	T_arr FindMax() const;
	T_arr FindMin() const;
	T_arr FindAverage() const;

	T_arr BinarySearch(T_arr arr[], int size, T_arr key);
	int GetSize() const
	{
		return size;
	}
	T_arr BinSearch(T_arr key) {
		T_arr res;
		res = BinarySearch(arr, size, key);
		return res;
	}

	void AddConcreteElement(T_arr to_add) {

		T_arr* temp = new T_arr[size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}

		temp[size] = to_add;

		delete[] arr;
		arr = temp;
		size++;
	}
	void AddRandomElement() {

		T_arr* temp = new T_arr[size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}

		temp[size] = rand() % 100;

		delete[] arr;
		arr = temp;
		size++;
	}
	void ChangeElementByIndex(int index) 
	{
		if (index < 0 || index >= size) {

			cout << "Wrong index!" << endl;
			return;
		}
		cout << "Enter new value (index = "<< index<<"): "; cin >> arr[index];
	}
	void DeleteElementByIndex(int index) {

		if (index < size || index >= size) {

			cout << "Wrong index!" << endl;
			return;
		}

		T_arr* temp = new T_arr[size - 1];

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
	void DeleteElementByValue(T_arr value) {

		if (value < size || value >= size) {

			cout << "Wrong index!" << endl;
			return;
		}

		T_arr* temp = new T_arr[size - 1];
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
		if (arr != nullptr) delete[]arr;
	}
};

void main() {

	/*			Шаблони класів.initializer_list
							Завдання 1:
		1. Перетворити раніше створений клас Array на шаблон, який дозволить
		   зберігати елементи будь - якого типу.Функціональність залишити на
		   тому ж рівні.

		2. Додати можливість створювати об'єкт та присвоювати йому 
		   значення шляхом спискової ініціалізації : { 1, 2, 3...}
		
		3. Реалізуйте шаблонні функції для пошуку максимуму,
		   мінімуму, сортування масиву(будь - яким алгоритмом
		   сортування), двійкового пошуку в масиві, заміни елемента
		   масиву на передане значення.
		
		# Ці методи винести за межі класу
	*/

	Array<int> intArr(10);
	intArr.FillRandom();
	intArr.PrintAll();
	intArr.ChangeElementByIndex(2);
	intArr.PrintAll();
	intArr.SortMinMax();
	intArr.PrintAll();

	int element;
	cout << "Enter element to search (binary): "; cin >> element;
	element = intArr.BinSearch(element);
	cout << "Index = " << element;

	cout << "\n\n\nFLOAT ARRAY ---> " << endl << endl;

	Array<float> floatArr(10);
	floatArr.FillRandom();
	floatArr.PrintAll();
	
	float result;

	result = floatArr.FindMax();
	cout << "Max: " << result << endl;
	result = floatArr.FindMin();
	cout << "Min: " << result << endl;

	floatArr.SortMaxMin();
	floatArr.PrintAll();
	
	floatArr.SortMinMax();
	floatArr.PrintAll();
}

template<typename T_arr>
T_arr Array<T_arr>::BinarySearch(T_arr arr[], int size, T_arr key)
{
	int B = 0, E = size - 1;
	while (true)
	{
		int p = (B + E) / 2;
		if (key > arr[p])
			B = p + 1;
		else if (key < arr[p])
			E = p - 1;
		else if (key == arr[p])
			return p;

		if (B > E)return -1;
	}
}

template<typename T_arr>
void Array<T_arr>::FillRandom() {

	if (size <= 0) {

		cout << "The size of the array is less than 1!" << endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

template<typename T_arr>
void Array<T_arr>::FillKeyboard() {

	if (size <= 0) {

		cout << "The size of the array less than 1!" << endl;
		return;
	}

	int temp;

	for (int i = 0; i < size; i++)
	{
		cout << "Enter [" << i << "] :  "; cin >> temp;
		arr[i] = temp;
	}
}

template<typename T_arr>
void Array<T_arr>::SortMinMax() {

	T_arr temp;

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

template<typename T_arr>
void Array<T_arr>::SortMaxMin() {

	T_arr temp;

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

template<typename T_arr>
void Array<T_arr>::PrintAll() const
{
	for (int i = 0; i < size; i++)
	{
		cout << "Arr [" << i << "] = " << arr[i] << endl;
	}
	cout << endl;
}

template<typename T_arr>
void Array<T_arr>::PrintIndex(int index) const
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

template<typename T_arr>
T_arr Array<T_arr>::FindMin() const
{
	T_arr min = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

template<typename T_arr>
T_arr Array<T_arr>::FindMax() const
{
	T_arr max = arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

template<typename T_arr>
T_arr Array<T_arr>::FindAverage() const
{
	T_arr sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	T_arr average = sum / (size - 1);

	return average;
}