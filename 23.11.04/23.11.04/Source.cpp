#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class Point
{
	int x;
	int y;

public:

	Point(): x(0), y(0) {}
	explicit Point(int value) : x(value), y(value) {}
	Point(int x, int y) : x(x), y(y) {}
	Point(const Point& other) : x(other.x), y(other.y) {}

	void gotoxy() const
	{
		static HANDLE h = NULL;
		if (!h)
			h = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD c = { x, y };
		SetConsoleCursorPosition(h, c);
		cout << "[]";
	}
	
	void Fill()
	{
		cout << "X = "; cin >> x; 
		cout << "Y = "; cin >> y;
		cout << endl;
	}

	void SetX(int point)
	{
		x = point;
	}
	void SetY(int point)
	{
		y = point;
	}

	int GetX() const
	{
		return x;
	}
	int GetY() const
	{
		return y;
	}

	void Print()const
	{
		cout << "[ X : " << setw(2) << x << " ]" << "[ Y : " << setw(2) << y << " ]" << endl;
	}
	void Print(int post)const
	{
		cout << "[ X : " << setw(post) << x << " ]" << "[ Y : " << setw(post) << y << " ]" << endl;
	}

	bool operator<(const Point& other)const
	{
		return (this->x + this->y) < (other.x + other.y);
	}
	bool operator>(const Point& other)const
	{
		return (this->x + this->y) > (other.x + other.y);
	}

	Point operator!()
	{
		return Point(-x, -y);
	}
	
	Point operator --()
	{
		--this->x;
		--this->y;
		return *this;
	}
	Point operator --(int)
	{
		--this->x;
		--this->y;
		return *this;
	}
	Point operator ++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator ++(int)
	{
		this->x++;
		this->y++;
		return *this;
	}
};

class Vector {

	Point *coordinates;
	int size;

public:

	Vector() : coordinates(nullptr), size(0) {}
	Vector(int size)
	{
		this->size = size;
		coordinates = new Point[size];

		for (int i = 0; i < size; i++)
		{
			coordinates[i].Fill();
		}
	}
	Vector(const Vector& other)
	{
		this->size = other.size;
		this->coordinates = new Point[size];

		for (int i = 0; i < size; i++)
		{
			this->coordinates[i] = other.coordinates[i];
		}
	}
	Vector(Vector&& other) : coordinates(other.coordinates), size(other.size) 
	{
		other.coordinates = nullptr;
		other.size = 0;
	}

	int Symbhols() const
	{
		int count = 0, max_counter = 0;
		
		for (size_t i = 0; i < size; i++)
		{
			count = 0;

			int our_y = coordinates[i].GetY();
			while (our_y != 0) {
				our_y /= 10;
				++count;
			}
			if (max_counter < count)
				max_counter = count;			
		}
		for (int i = 0; i < size; i++)
		{
			count = 0;

			int our_x = coordinates[i].GetX();
			while (our_x != 0) {
				our_x /= 10;
				++count;
			}
			if (max_counter < count)
				max_counter = count;
		}
		
		return max_counter;
	}
	void Print() const
	{
		int symbhols = Symbhols();

		for (int i = 0; i < size; i++)
		{
			coordinates[i].Print(symbhols);
		}
	}

	void PrintInConsole()
	{
		for (int i = 0; i < size; i++)
		{
			coordinates[i].gotoxy();
		}
	}

	bool Find(Point coord) const
	{
		for (int i = 0; i < size; i++)
		{
			if (coordinates[i].GetX() == coord.GetX() && coordinates[i].GetY() == coord.GetY())
				return true;
		}
		return false;
	}
	bool Find(int x, int y) const
	{
		for (int i = 0; i < size; i++)
		{
			if (coordinates[i].GetX() == x && coordinates[i].GetY() == y)
				return true;
		}
		return false;
	}

	void Add()
	{
		Point* temp = new Point[size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = coordinates[i];
		}

		temp[size].Fill();

		delete []coordinates;
		coordinates = temp;
		size++;
	}
	void Add(int p1, int p2)
	{
		Point* temp = new Point[size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = coordinates[i];
		}

		temp[size].SetX(p1);
		temp[size].SetY(p2);

		delete []coordinates;
		coordinates = temp;
		size++;
	}

	void operator=(const Vector& other)
	{
		this->size = other.size;
		this->coordinates = new Point[size];

		for (int i = 0; i < size; i++)
		{
			this->coordinates[i] = other.coordinates[i];
		}
	}

	~Vector()
	{
		if (coordinates != nullptr)
		{
			delete[]coordinates;
		}
	}
};

void main() {

	Vector a;

	a.Add(5, 9);
	a.Add(7, 16);
	a.Add(13, 2);
	a.Add();

	a.Print();

	cout << "\n______________________________________" << endl;

	Vector b(2);
	a = b;

	cout << "A = " << endl; a.Print();
	cout << endl;
	cout << "B = " << endl; b.Print();

	cout << "\n______________________________________" << endl;

	bool found;
	
	Point coords;
	
	cout << "You need to find: " << endl; coords.Fill();
	found = a.Find(coords);
	cout << "Found : " << found;

	cout << endl;

	int x, y;
	cout << "You need to find: " << "\nX = "; cin >> x; cout << "\nY = "; cin >> y;
	found = a.Find(x, y);
	cout << "Found : " << found;

	cout << "\n______________________________________" << endl;

	cout << "Print in console any coordinates: "; coords.Fill();
	system("cls");
	coords.gotoxy();
	system("pause");
	system("cls");

	cout << "\n______________________________________" << endl;

	cout << "Enter 3 oordinates to print them in console: " << endl;
	Vector coordinates(3);
	system("cls");
	coordinates.PrintInConsole();
}