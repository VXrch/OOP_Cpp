#include <iostream>

using namespace std;

template <typename T>
class Queue {

	struct Element
	{
		T value;
		int priority;
	};

	Element* data;
	int top;
	int size;

public:

	Queue() : data(nullptr), top(0), size(0){}

	void PrintPriority(int elm) {

		switch (elm)
		{
		case 1: cout << "guest ";  break;
		case 2: cout << "administrator ";  break;
		case 3: cout << "manager "; break;
		case 4: cout << "director "; break;
		}
	}
	void Print() 
	{
		cout << "__________________ Queue __________________" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i + 1 << "] - " << data[i].value << " : "; PrintPriority(data[i].priority); cout << endl;
		}
		cout << "___________________________________________" << endl;
	}

	bool IsEmpty() {
		return size == 0;
	}

	void Enqueue(T value, int priority)
	{
		int index = 0;

		while (index < size && data[index].priority > priority) { index++; }
		size++;
		
		Element* temp = new Element[size];

		for (int i = 0; i < index; i++)
		{ 
			temp[i] = data[i]; 
		}

		temp[index] = Element{value, priority};

		for (int i = index; i < size - 1; i++) 
		{ 
			temp[i + 1] = data[i]; 
		}

		if (data != nullptr)
		{
			delete[]data;
		}
		data = temp;
	}
	Element Dequeue()
	{ 
		if (IsEmpty()) {
			return Element();
		}

		Element first = data[0];

		for (int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}

		size--;
		return first;
	}

	~Queue()
	{
		if (data != nullptr)
			delete[]data;
	}
};

void main() {

/*
					 ТЕМА: DYNAMIC DATA STRUCTURES. PRIORITY QUEUE. 
									Завдання 1:
		Розробити додаток, що імітує чергу друку принтера. 
		Програма надає меню з наступними можливостями:
			•Додати документ в чергу. 
				Користувач повинен ввести ім’я файлу та 
				вибрати свою посаду. В залежності від посади, 
				документу надається певний пріорітет 
				(до прикладу: гість – 1, адміністратор – 2, менеджер – 3,
				директор – 4 і тд.)
			•Виконати друк. Відображається на екран документ, 
				який наразі друкується (з максимальним пріорітетом).
				Для збереження колекції документів використати динамічну 
				структуру даних – Queue (черга з пріорітетним включенням).
*/

	Queue<string> queue;
	string filename;

	bool ext = false;
	int choice;

	while (!ext)
	{
		system("pause");
		system("cls");
		cout << "_-_-_-_-_-_-_-_-_-' PRINTER '-_-_-_-_-_-_-_-_-_" << endl;
		cout << "[0] - Exit" << endl;
		cout << "[1] - Add your document" << endl;
		cout << "[2] - Print document" << endl;
		cout << "[3] - Print all documents in queue" << endl;
		cout << "_-'  "; cin >> choice;

		if (choice == 0)
		{
			cout << "Bye!" << endl;
			ext = true;
		}
		else if (choice == 1)
		{
			cout << "Enter your post: " << endl;
			cout << "[1] - guest" << endl;
			cout << "[2] - administrator" << endl;
			cout << "[3] - manager" << endl;
			cout << "[4] - director" << endl;
			cout << "_-'  "; cin >> choice;

			cout << "Enter your filename (example.txt): "; cin >> filename;

			switch (choice)
			{
			case 1: queue.Enqueue(filename, 1); break;
			case 2: queue.Enqueue(filename, 2); break;
			case 3: queue.Enqueue(filename, 3); break;
			case 4: queue.Enqueue(filename, 4); break;
			default: cout << "Wrong number!" << endl; break;
			}
		}
		else if (choice == 2)
		{
			auto result = queue.Dequeue();
			cout << "File " << result.value << " : "; queue.PrintPriority(result.priority); cout << " was printed!" << endl;
		}
		else if (choice == 3) 
		{
			queue.Print();
		}
		else
		{
			cout << "Wrong number!" << endl;
		}
	}
}