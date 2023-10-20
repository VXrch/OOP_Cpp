#include <iostream>

using namespace std;

class Airplane {

	string model;
	string type;
	int passengers;
	const int MAX_PASSENGERS;

public:

	Airplane() : MAX_PASSENGERS(100), model("no"), type("no"), passengers(0) {}
	explicit Airplane(int max_passangers) : MAX_PASSENGERS(max_passangers), model("no"), type("no"), passengers(0) {}

	friend bool operator==(const Airplane& ths, const Airplane& other);
	friend bool operator>(const Airplane& ths, const Airplane& other);
	friend bool operator<(const Airplane& ths, const Airplane& other);
	friend bool operator>=(const Airplane& ths, const Airplane& other);
	friend bool operator<=(const Airplane& ths, const Airplane& other);

	int Get_passengers() {
		return passengers;
	}
	int Get_max_passengers() const {
		return MAX_PASSENGERS;
	}

	Airplane& operator++() {

		if (passengers < MAX_PASSENGERS)
		{
			++passengers;
		}
		return *this;
	}
	Airplane& operator--() {

		if (passengers > 0)
		{
			--passengers;
		}
		return *this;
	}
	Airplane& operator()(int number) {

		if (passengers < MAX_PASSENGERS && (number+passengers) <= MAX_PASSENGERS)
		{
			this->passengers += number;
		}
		return *this;
	}
};

bool operator==(const Airplane& ths, const Airplane& other) {

	return (ths.type == other.type);
}

bool operator>(const Airplane& ths, const Airplane& other) {

	return (ths.MAX_PASSENGERS > other.MAX_PASSENGERS);
}

bool operator<(const Airplane& ths, const Airplane& other) {

	return (ths.MAX_PASSENGERS < other.MAX_PASSENGERS);
}

bool operator>=(const Airplane& ths, const Airplane& other) {

	return (ths.MAX_PASSENGERS >= other.MAX_PASSENGERS);
}

bool operator<=(const Airplane& ths, const Airplane& other) {

	return (ths.MAX_PASSENGERS <= other.MAX_PASSENGERS);
}

void main() {

/*
	����: OPERATORS OVERLOADING
		�������� 1 :
		
		�������� ���� Airplane(����), ���� ���� ���� ������� �������������� :
			� ������
			� ���
			� ʳ������ ��������
			� ����������� ������� ��������
		�� ��������� �������������� ��������� ���������� :
			1. �������� �� ������ ���� �����(�������� == ) friend
			2. ��������� � ��������� �������� � ����� �����(�������� ++ �� --
				� ��������� ����)
			3. ��������� ���� ����� �� ����������� ������� ������� ��������
				�� �����(�������� > ) friend
			4. �������� ������� �������� �� ����� ��������(��������())
			
			�������������� ������� �������� �������� �� ��������� ������ �������.
			��� �������� ��������, ������� ��������� �� �� ����������� �����������
			������� ��������.
*/

	Airplane a;
	Airplane b(1000);
	Airplane c;

	cout << "A (max passengers) = " << a.Get_max_passengers() << endl;
	cout << "B (max passengers) = " << b.Get_max_passengers() << endl;
	cout << "C (max passengers) = " << c.Get_max_passengers() << endl;
	cout << endl;

	bool is_true;

	is_true = a < b;
	cout << "A < B (max_passangers) : " << is_true << endl;
	is_true = a > b;
	cout << "A > B (max_passangers) : " << is_true << endl;
	is_true = a == c;
	cout << "A == C (max_passangers) : " << is_true << endl;

	cout << endl;

	cout << "A (default) = " << a.Get_passengers() << endl;
	++a;
	cout << "A (++) = " << a.Get_passengers() << endl;
	--a;
	cout << "A (--) = " << a.Get_passengers() << endl;
	a(10);
	cout << "A (+10) = " << a.Get_passengers() << endl;
	a(100);
	cout << "A ( +100 --- bigger than MAX) = " << a.Get_passengers() << endl;
}