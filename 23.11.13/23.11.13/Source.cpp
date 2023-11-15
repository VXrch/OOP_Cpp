#include <iostream>
#include <windows.h>

using namespace std;

template <typename T>
class List
{
	struct Node
	{
		Node* prev;
		T value;
		Node* next;

	public:
		Node(Node* prev, T value, Node* next) :prev(prev), value(value), next(next) {}
	};

	Node* head;
	Node* tail;
	int size;

public:

	List() : head(nullptr), tail(nullptr), size(0) {}

	void Print() const
	{
		for (Node* i = head; i != nullptr; i = i->next)
		{
			i->value.Print();
		}

		cout << endl;
	}
	void ShortPrint() const
	{
		for (Node* i = head; i != nullptr; i = i->next)
		{
			i->value.PrintAge();
		}
	}
	bool IsEmpty() const
	{
		return head == nullptr;
	}
	bool IsValidPos(int pos) const
	{
		if (pos < 0 || pos > size)
			return false;
		else
			return true;
	}

	int GetSize() const
	{
		return size;
	}

	void SomeoneDied(T someone)
	{
		cout << "This " << someone.GetView() << " died of old age!" << endl;
	}
	
	bool IllAndDie()
	{
		int chance = rand() % 100;
		chance = rand() % 10;
		chance %= size + 1;

		if (chance == 1)
		{
			DeleteFromHead();
			return true;
		}
		else
		{
			return false;
		}
	}

	void Grow()
	{
		int iter = 0;
		for (Node* i = head; i != nullptr; i = i->next)
		{
			i->value.Grow();
		}

		bool found = false;
		for (int i = 0; i < size; i++)
		{
			iter = 0;
			if (found == true || i == 0)
			{
				for (Node* j = head; j != nullptr; j = j->next)
				{
					if (j->value.IsAlive() == false)
					{
						SomeoneDied(j->value);
						DeleteByPos(iter);
						found == true;
						i++;
						return;
					}
					iter++;
				}
			}
			else 
			{
				return;
			}
		}
	}
	void GrowOne()
	{
		head->value.Grow();
		if (head->value.IsAlive() == false)
		{
			SomeoneDied(head->value);
			DeleteFromHead();
		}
	}
	void AddAge(float age, int pos)
	{
		int iter = 0;
		for (Node* i = head; i != nullptr; i = i->next)
		{
			if (iter == pos)
			{
				i->value.AddAge(age);
				if (!i->value.IsAlive())
				{
					SomeoneDied(i->value);
					DeleteByPos(iter);
				}
			}
			iter++;
		}
	}

	void AddToTail(T value)
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
	void AddByPosition(int pos, T value)
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

	void DeleteFromTail()
	{
		if (IsEmpty()) return;

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
	void DeleteByPos(int pos)
	{
		if (pos < 0 || pos >= size)
			return;
		else if (pos == 0)
		{
			DeleteFromHead();
			return;
		}
		else if (pos == (size - 1))
		{
			DeleteFromTail();
			return;
		}
		else
		{
			Node* current;
			if (pos <= (size / 2) - 1)
			{
				current = head;
				for (int i = 1; i < pos; ++i)
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

	T operator[](int pos)
	{
		int iter = 0;

		for (Node* i = head; i != nullptr; i = i->next)
		{
			if (iter == pos)
			{
				return i->value;
			}
			iter++;
		}

		return T();
	}
};

class SomethingAlive
{
protected:

	float age;
	const float MAXAGE;
	string view;
	bool alive;

public:

	SomethingAlive() : age(0.1), MAXAGE(10), view("something"), alive(true) {}
	SomethingAlive(float age, float MAXAGE, string view) : age(age), MAXAGE(MAXAGE), view(view), alive(age < MAXAGE){}

	bool IsAlive()
	{
		return (age < MAXAGE);
	}
	virtual void Print() const
	{
		cout << "Age: " << age << endl;
		cout << "View: " << view << endl;
	}
	void PrintAge() const
	{
		cout << "AGE: " << age << endl;
	}

	string GetView()
	{
		return view;
	}
	void AddAge(float age)
	{
		this->age += age;
		alive = IsAlive();
	}
	virtual void Grow()
	{
		age += 0.1;
		alive = IsAlive();
	}
};

class Plant : public SomethingAlive
{
protected:

	bool poisonous;
	float height;
	const float MAXHEIGHT;
	float growthSpeed;

public:

	Plant() : poisonous(false), height(1), MAXHEIGHT(10), growthSpeed(0.1), SomethingAlive() {}
	Plant(string view): Plant() { this->view = view; }
	Plant(float age, float MAXAGE, string view, bool poisonous, float height, float MAXHEIGHT, float growthSpeed) : poisonous(poisonous), height(height), MAXHEIGHT(MAXHEIGHT), growthSpeed(growthSpeed), SomethingAlive(age, MAXAGE, view) {}

	void Print() const override
	{
		SomethingAlive::Print();
		cout << "Poisonous: " << poisonous << endl;
		cout << "Height: " << height << endl;
		cout << "MAX Height: " << MAXHEIGHT << endl;
	}
	void Grow() override
	{
		SomethingAlive::Grow();
		if(height == MAXHEIGHT)
			height += growthSpeed;
	}
};
class Grass : public Plant
{
public:
	Grass() : Plant("Grass") {}
};

class Animal : public SomethingAlive
{
protected:

	string name;
	string gender;

public:

	Animal() = delete;
	Animal(float age, float MAXAGE, string view, string name, string gender) : name(name), gender(gender), SomethingAlive(age, MAXAGE, view) {}

	string GetGender()
	{
		return gender;
	}
	float GetAge()
	{
		return age;
	}
};
class Fox : public Animal
{
public:
	Fox() : Animal(0.1, 4, "Fox", "Fox", "male") {}
	Fox(string gender) : Animal(0.1, 4, "Fox", "Fox", gender) {}
	Fox(int age) : Animal(age, 4, "Fox", "Fox", "male") {}
	Fox(int age, string gender) : Animal(age, 4, "Fox", "Fox", gender) {}
};
class Rabbit : public Animal
{
public:
	Rabbit() : Animal(0.1, 5, "Rabbit", "Rabbit", "male") {}
	Rabbit(string gender) : Animal(0.1, 5, "Rabbit", "Rabbit", gender) {}
	Rabbit(int age) : Animal(age, 5, "Rabbit", "Rabbit", "male") {}
	Rabbit(int age, string gender) : Animal(age, 5, "Rabbit", "Rabbit", gender) {}
};

class Life
{
	List<Fox> foxes;
	List<Rabbit> rabbits;
	List<Grass> grass;

public:

	Life()
	{
		for (int i = 0; i < 2; i++)
		{
			foxes.AddToTail(Fox());
			rabbits.AddToTail(Rabbit());
			grass.AddToTail(Grass());
		}
		for (int i = 0; i < 2; i++)
		{
			foxes.AddToTail(Fox("female"));
			rabbits.AddToTail(Rabbit("female"));
			grass.AddToTail(Grass());
		}
	}

	void Print() const
	{
		cout << "Foxes: "; foxes.Print();
		cout << "Rabbits: "; rabbits.Print();
		cout << "Grass: "; grass.Print();
	}
	void PrintRusults() const
	{
		cout << "Foxes: " << CountFoxes() << endl;
		cout << "Rabbits: " << CountRabbits() << endl;
		cout << "Grass: " << CountGrass() << endl;
	}
	void ShortPrint() const
	{
		foxes.ShortPrint();
		rabbits.ShortPrint();
		grass.ShortPrint();
	}
	void PrintFoxes() const
	{
		cout << "Foxes: "; foxes.Print(); cout << endl;
	}
	void PrintRabbits() const
	{
		cout << "Rabbits: "; rabbits.Print(); cout << endl;
	}
	void PrintGrass() const
	{
		cout << "Grass: "; grass.Print(); cout << endl;
	}

	void AddAgeForFirsts(float age)
	{
		foxes.AddAge(age, 1);
		rabbits.AddAge(age, 1);
		grass.AddAge(age, 1);
	}
	void AddAgeForOneFox(float age)
	{
		foxes.AddAge(age, 1);
	}
	void AddAgeForOneRabbit(float age)
	{
		rabbits.AddAge(age, 1);
	}
	void AddAgeForOneGrass(float age)
	{
		grass.AddAge(age, 1);
	}

	void AddAgeForFirst(float age, int pos)
	{
		foxes.AddAge(age, pos);
		rabbits.AddAge(age, pos);
		grass.AddAge(age, pos);
	}
	void AddAgeForOneFox(float age, int pos)
	{
		foxes.AddAge(age, pos);
	}
	void AddAgeForOneRabbit(float age, int pos)
	{
		rabbits.AddAge(age, pos);
	}
	void AddAgeForOneGrass(float age, int pos)
	{
		grass.AddAge(age, pos);
	}

	void GrowAll()
	{
		if (foxes.GetSize() != 0)
		{
			foxes.Grow();
		}
		if (rabbits.GetSize() != 0)
		{
			rabbits.Grow();
		}
		if (grass.GetSize() != 0)
		{
			grass.Grow();
		}
	}
	void GrowFoxes()
	{
		foxes.Grow();
	}
	void GrowOneFox()
	{
		foxes.GrowOne();
	}
	void GrowRabbits()
	{
		rabbits.Grow();
	}
	void GrowGrass()
	{
		grass.Grow();
	}

	string RandomiseGender()
	{
		int gender = 1 + rand() % 20;
		gender = 1 + rand() % 20;
		gender %= 2;

		if (gender == 1)
			return "male";
		else
			return "female";
	}
	int RandomiseNumber()
	{
		int chance = 5 + rand() % 150;
		chance -= rand() % 50;
		chance %= 10;
		return chance;
	}

	void BirthFox()
	{

		for (int i = 0; i < foxes.GetSize() - 1; i++)
		{
			if (foxes[i].GetGender() != foxes[i + 1].GetGender())
			{
				Fox NewFox(0.1, RandomiseGender());
				foxes.AddToTail(NewFox);
				return;
			}
		}
	}
	void BirthRabbit()
	{
		if (RandomiseNumber() == 1)
		{
			for (int i = 0; i < rabbits.GetSize() - 1; i++)
			{
				if (rabbits[i].GetGender() != rabbits[i + 1].GetGender())
				{
					Rabbit NewRabbit(0.1, RandomiseGender());
					rabbits.AddToTail(NewRabbit);
					cout << "+1 rabbit" << endl;
					return;
				}
			}
		}
	}
	void NewGrass()
	{
		cout << "+1 grass" << endl;
		grass.AddToTail(Grass());
	}

	void FoxAteRabbit()
	{
		rabbits.DeleteFromHead();
	}
	void RabbitAteGrass()
	{
		grass.DeleteFromHead();
	}

	int CountFoxes() const
	{
		return foxes.GetSize();
	}
	int CountRabbits() const
	{
		return rabbits.GetSize();
	}
	int CountGrass() const
	{
		return grass.GetSize();
	}

	int AdultFoxes()
	{
		int counter = 0;
		for (int i = 0; i < foxes.GetSize(); i++)
		{
			if (foxes[i].GetAge() >= 1)
			{
				counter++;
			}
		}
		return counter;
	}
	int AdultRabbits()
	{
		int counter = 0;
		for (int i = 0; i < rabbits.GetSize(); i++)
		{
			if (rabbits[i].GetAge() >= 1)
			{
				counter++;
			}
		}
		return counter;
	}

	void FoxIllAndDie()
	{
		if (foxes.IllAndDie())
		{
			cout << "One fox died of an illness!" << endl;
		}
	}
	void RabbitIllAndDie()
	{
		if (rabbits.IllAndDie())
		{
			cout << "One rabbit died of an illness!" << endl;
		}
	}
	void GrassIllAndDie()
	{
		if (grass.IllAndDie())
		{
			cout << "One grass died from the disease!" << endl;
		}
	}
};

void OneYear(Life& life)
{
	int repeted = 0;

	while (repeted < 365)
	{
		Sleep(1000);

		if (repeted == 20)
		{
			system("cls");
		}

		if (repeted == 38)
		{
			cout << "";
		}
		cout << "-_-_-_-_-_-_-_-_-_-_-| DAY " << repeted << " |-_-_-_-_-_-_-_-_-_-_-" << endl;

		if (life.CountFoxes() < 5)
		{
			life.BirthFox();
			cout << "+1 fox!" << endl;
		}
		life.BirthRabbit();
		life.NewGrass();

		if (life.CountFoxes() < life.CountRabbits())
		{
			cout << "A fox ate a rabbit!" << endl;
			life.FoxAteRabbit();
		}
		if (life.CountRabbits() < life.CountGrass())
		{
			cout << "A rabbit ate a grass!" << endl;
			life.RabbitAteGrass();
		}

		if (repeted % 50 == 0)
		{
			life.FoxIllAndDie();
			life.RabbitIllAndDie();
			life.GrassIllAndDie();
		}

		life.GrowAll();

		repeted++;
	}
}

void Results(Life life)
{
	life.PrintRusults();
}

void main()
{
	/*								#1 
		Створити клас тварини з місцем проживання(можна взяти створений на парі).
		Визначити наступні класи наслідники —
		- лисиця
		- кролик
		
		Створити клас Рослини і наслідник - трава.

		Лисиця їсть кролика.
		Кролик їсть траву. 
		Лисиця може вмерти — визначений вік.
		Кролик теж може померти.
		Крім цього визначений клас — життя, у якому вони взаємодіють між собою.
		Якщо в околицях більше трави, ніж кроликів, то трава залишається, інакше трава зїдена.
		Якщо лисиця занадто стара, вона може вмерти.
		Якщо лисиць дуже багато(більше 5 в околиці) лисиці більше не з'являються. 
		Якщо кроликів меньше ніж лисиць, то лис їсть кролика.

													#2
		Створити абстрактний клас Shape(фігура).Яка містить тип та чисто віртуальний метод Print(), для показу фігури на консоль.
		Реалізувати похідні класи :
		Line – містить координати початку та кінця(дві точки)
		Rectangle – містить координати верхнього лівого кута, ширину та довжину
		Polyline – містить масив точок

		Всі похідні класи повинні перевизначати метод Print(), друкуючи фігуру на консолі враховуючи її параметри.
		Додати деструктор  в класи, які його потребують.
		Для зручності можна створити структуру struct Point { int x, y };
	*/

	srand(time(NULL));

	Life life;

	OneYear(life);
	Results(life);

	/*life.ShortPrint();
	life.Grow();

	cout << "____________________________| AFTER |____________________________" << endl;
	life.ShortPrint();*/
}