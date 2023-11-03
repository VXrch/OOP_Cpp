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

	List()
	{
		head = nullptr;
	}
	void AddToHead(int value)
	{
		Node* newNode = new Node(value, head);
		head = newNode;
	}
	void AddToEnd(int value)
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
	void PrintList()
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->next;
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


void main() 
{
	List<int> list;
	
	/*for (int i = 0; i < 10; i++)
	{
		list.AddToHead(i);
	}

	list.PrintList();
	cout << endl;*/

	for (int i = 0; i < 10; i++)
	{
		list.AddToEnd(i + 10);
	}

	list.PrintList();
}