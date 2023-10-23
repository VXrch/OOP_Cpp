#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Airplane {

	string model;
	string type;
	int passengers;
	const int MAX_PASSENGERS;

public:

	Airplane() : MAX_PASSENGERS(100), model("no"), type("no"), passengers(0) {}
	explicit Airplane(int max_passangers) : MAX_PASSENGERS(max_passangers), model("no"), type("no"), passengers(0) {}

	friend ostream& operator << (ostream& out, const Airplane& point);
	friend istream& operator >>(istream& in, Airplane& other);

	operator string() {
		return model;
	}
};

ostream& operator << (ostream& out, const Airplane& other)
{
	out << "Model: " << other.model << endl << "Type: " << other.type << endl << "Passengers: " << other.passengers << endl << "MAX_PASSENGERS: " << other.MAX_PASSENGERS << endl;
	return out;
}
istream& operator >>(istream& in, Airplane& other)
{
	in >> other.model >> other.type >> other.passengers;
	return in;
}

void main() {

	/*
		До раніше створеного класу Airplane додайте
			• Перетворення об’єкту до типу string який буде повертати модель літака
			• Вивід об'єкта на екран за допомогою потоку ostream (оператор <<)
			• Заповнення об'єкта з клавіатури за допомогою потоку istream (оператор >>)
	*/

	Airplane airpln;
	cout << airpln << endl;

	string a = airpln;
	cout << "A (airplane to string): " << a << endl;

	cout << "Enter airplane info: " << endl;
	cin >> airpln;
	cout << "After \"cin\"" << airpln << endl;
}