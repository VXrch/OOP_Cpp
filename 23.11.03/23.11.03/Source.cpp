#include <iostream>

using namespace std;

template <typename T>
class List {

	struct Node {

		T value;
		Node* next;
		Node(T value) : value(value), next(nullptr){}
		Node(T value, Node* next) : value(value), next(next){}
	};

	Node* head;

public:

	List() : head(nullptr) {}

	void Print()
	{
		Node* current = head;
		while (current != nullptr)
		{
			current->value.Print();
			current = current->next;
		}
	}

	bool IsEmpty()
	{
		return (head == nullptr);
	}

	void AddToHead(T value)
	{
		Node* newNode = new Node(value, head);
		head = newNode;
	}
	void AddToTail(T value)
	{
		if (head == nullptr)
		{
			Node* newNode = new Node(value);
			head = newNode;
		}
		else 
		{
			Node* newNode = new Node(value);

			Node* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			current->next = newNode;
		}
	}

	T GetElementByPosition(int pos)
	{
		Node* current = head;
		int i = 1;

		while (current != nullptr)
		{
			if (pos == i) 
				return current->value;

			current = current->next;
			i++;
		}
	}

	void DeleteFromHead()
	{
		if (head == nullptr)
		{
			cout << "The list is empty!" << endl;
			return;
		}

		Node* current = head;
		head = current->next;
		delete current;
	}
	void DeleteFromTail()
	{
		if (head == nullptr) 
		{
			cout << "The list is empty!" << endl;
			return;
		}

		if (head->next == nullptr) 
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* current = head;
			while (current->next->next != nullptr)
			{
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
		}
	}

	~List()
	{
		Node* current = nullptr;
		while (head != nullptr)
		{
			current = head;
			head = head->next;
			delete current;
		}
	}
};

struct Point 
{
	int x;
	int y;

	void Fill()
	{
		cout << "Enter X: "; cin >> x;
		cout << "Enter Y: "; cin >> y;
	}
	void Print()
	{
		cout << "[ X : " << x << " ][ Y : " << y << " ]" << endl;
	}
};

class Vector 
{
	List<Point> list;

public:

	void Print()
	{
		list.Print();
	}
	bool Empty()
	{
		return list.IsEmpty();
	}

	void AddToT(Point value)
	{
		list.AddToTail(value);
	}
	void AddToH(Point value)
	{
		list.AddToHead(value);
	}

	void GetElByPosition(int pos)
	{
		Point element = list.GetElementByPosition(pos);
		element.Print();
	}

	void DeleteFromT()
	{
		list.DeleteFromTail();
	}
	void DeleteFromH()
	{
		list.DeleteFromHead();
	}
};

void main() 
{
	/*					Завдання 1:
			Реалізувати клас Vector, який містить колекцію точок на площині.
				Точки зберігаються у вигляді списка(змінна типу List).
			Для класу потрібно реалізувати 
				- необхідний набір конструкторів,
				- методи для видалення
				- додавання нової точки на початок та в кінець
				- метод Print() для виводу точок на екран.
				- Написати метод видалення з голови.
	*/

	int choice, pos;
	bool ext = false;

	Point element;
	Vector list;

	while (!ext)
	{
		system("pause"); system("cls");
		cout << "_-_-_-_-_-_-_-'   HELLO   '-_-_-_-_-_-_-_" << endl;
		cout << "Choose your action: " << endl;
		cout << "[0] - Exit" << endl;
		cout << "[1] - Add element to head" << endl;
		cout << "[2] - Add element to Tail" << endl;
		cout << "[3] - Delete element from Tail" << endl;
		cout << "[4] - Delete element from head" << endl;
		cout << "[5] - Get element by position" << endl;
		cout << "[6] - Print all points" << endl;
		cout << "-+--+--->   "; cin >> choice;

		switch (choice)
		{
		case 0: cout << "Bye!" << endl; ext = true; break;
		case 1: element.Fill(); list.AddToH(element); break;
		case 2: element.Fill(); list.AddToT(element); break;
		case 3: 
			if (list.Empty())
				cout << "List is empty!" << endl;
			else
				list.DeleteFromT();

		case 4:
			if (list.Empty())
				cout << "List is empty!" << endl;
			else
				list.DeleteFromH();
			break;
		case 5:
			if (list.Empty())
				cout << "List is empty!" << endl;
			else 
			{
				cout << "Enter position to find: "; cin >> pos;
				list.GetElByPosition(pos);
			}
			break;
		case 6: 
			if (list.Empty())
				cout << "List is empty!" << endl;
			else
			{
				list.Print();
			}
			break;
		default: cout << "Wrong number!" << endl; break;
		}
	}
}