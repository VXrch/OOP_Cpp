#include <iostream>

using namespace std;

struct Vagon {

	int carriage_number;
	int seats_number;
	int max_passengers;
	int passengers_counter;

	Vagon()
	{
		carriage_number = 0;
		seats_number = 0;
		max_passengers = 0;
		passengers_counter = 0;
	}
	void Print()
	{
		cout << "Carriage number: " << carriage_number << endl;
		cout << "Seats number: " << seats_number << endl;
		cout << "Max of passengers: " << max_passengers << endl;
		cout << "Number of passengers: " << passengers_counter << endl;
	}
};

class List
{
	
	struct Node
	{
		Node* prev;
		Vagon value;
		Node* next;
	public:
		Node(Node* prev, Vagon value, Node* next) :prev(prev), value(value), next(next) {}
	};

	Node* head;
	Node* tail;
	int size;

public:

	List() : head(nullptr), tail(nullptr), size(0) {}

	void Print()
	{
		for (Node* i = head; i != nullptr; i = i->next)
		{
			i->value.Print();
		}

		cout << endl;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	bool IsValidPos(int pos)
	{
		if (pos < 0 || pos > size)
			return false;
		else
			return true;
	}

	void AddToHead(Vagon value)
	{
		Node* newNode = new Node(nullptr, value, head);

		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			head->prev = newNode;
			head = newNode;
		}

		size++;
	}
	void AddToTail(Vagon value)
	{
		Node* newNode = new Node(tail, value, nullptr);

		if (IsEmpty())
		{
			head = tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}

		size++;
	}
	void AddByPosition(int pos, Vagon value)
	{
		if (!IsValidPos(pos))
			return;

		else if (pos == 1)
		{
			AddToHead(value);
		}
		else if (pos == size)
		{
			AddToTail(value);
		}
		else
		{
			Node* current;

			if (pos <= size / 2)
			{
				current = head;
				for (int i = 1; i < pos; i++)
				{
					current = current->next;
				}
			}
			else
			{
				current = tail;
				for (int i = size; i > pos; i--)
				{
					current = current->prev;
				}
			}

			Node* newNode = new Node(current->prev, value, current);
			current->prev->next = newNode;
			current->prev = newNode;

			size++;
		}
	}

	Vagon GetElementByPosition(int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
	}
	int GetSize()
	{
		return size;
	}

	Vagon operator[](int pos)
	{
		Node* current = head;
		int i = 1;
		while (current != nullptr)
		{
			if (pos == i) return current->value;
			current = current->next;
			i++;
		}
	}

	void DeleteFromHead()
	{
		if (IsEmpty())
			return;

		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}

		size--;
	}
	void DeleteFromTail()
	{
		if (IsEmpty())
			return;

		if (head->next == nullptr)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}

		size--;
	}
	void DeleteByPosition(int pos)
	{
		if (pos < 1 || pos > size)return;
		else if (pos == 1)
		{
			DeleteFromHead(); 
		}
		else if (pos == size)
		{
			DeleteFromTail();
		}
		else
		{
			Node* current;

			if (pos <= size / 2)
			{
				current = head;
				for (int i = 1; i < pos; i++)
				{
					current = current->next;
				}
			}
			else
			{
				current = tail;
				for (int i = size; i > pos; i--)
				{
					current = current->prev;
				}
			}

			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
			size--;
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

class Train {

	string model;
	int countVagons;
	List* vagon;

public:

	Train()
	{
		model = "None";
		countVagons = 0;
		vagon = new List[countVagons];
	}
	Train(string model)
	{
		this->model = model;
		countVagons = 0;
		vagon = new List[countVagons];
	}
	Train(string model, int countVagons)
	{
		this->model = model;
		this->countVagons = countVagons;
		this->vagon = new List[countVagons];

		for (int i = 0; i < countVagons; i++)
		{
			vagon[i].AddToHead(Vagon());
		}
	}
	Train(const Train& other)
	{
		this->model = other.model;
		this->countVagons = other.countVagons;
		this->vagon = new List[other.countVagons];

		for (int i = 0; i < countVagons; i++)
		{
			this->vagon[i] = other.vagon[i];
		}
	}

	void AddCarriage() {

		List* temp = new List[countVagons + 1];

		for (int i = 0; i < countVagons; i++)
		{
			temp[i] = vagon[i];
		}

		Vagon a;
		temp[countVagons].AddToTail(a); 

		delete[]vagon;
		vagon = temp;
		countVagons++;
	}

	void Print() {

		cout << "Model: " << model << endl;
		cout << "Count vagons: " << countVagons << endl;
		for (int i = 0; i < countVagons; i++)
		{
			vagon[i].Print();
		}
	}

	void VagonAddress() {
		cout << "ADDRESS = " << &vagon << endl;
	}

	~Train()
	{
		delete[] vagon;
	}
};

void main()
{
		/*		Додати метод DeleteFromHead для класу двозв* язного списку.
									Завдання 2:
			Використати клас List для колекції вагонів в класі Train
			- Додати методи додавання вагона в початок / кінець
			- Видалення з початку / кінця.
			- Видалення по позиції
			- Додавання по позиції

				class Train
				{
					string model;
					int countVagons;
					List vagons;
				}
		*/

	List list;
	for (int i = 0; i < 10; i++)
	{
		list.AddToHead(Vagon());
	}
	list.Print();

	list.DeleteFromHead();
	list.Print();

	list.AddByPosition(3, Vagon ());
	list.Print();

	list.AddByPosition(3, Vagon());
	list.Print();
}