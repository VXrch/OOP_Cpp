#include <iostream>

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

	void Print()const
	{
		cout << "[ X : " << x << " ][ Y : " << y << " ]" << endl;
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

void main() {

	// ++ // -- // < // > // !

	Point a(2, 6);
	cout << "A ---> "; a.Print();

	Point b(5, 11);
	cout << "B ---> "; b.Print();
	cout << endl;

	bool res = a < b;
	cout << "A < B? ---> " << res;
	cout << endl;

	res = a > b;
	cout << "A > B? ---> " << res;
	cout << endl;

	cout << "!a = "; 
	a = !a; 
	a.Print();
	cout << endl;
}