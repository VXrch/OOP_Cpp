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

	void CreateCarriage() {

		cout << "Enter carriage number: "; cin >> carriage_number;
		cout << "Enter seats number: "; cin >> seats_number;
		cout << "Enter max number of passengers: "; cin >> max_passengers;
	}
	void Show() {

		cout << "Carriage number: " << carriage_number << endl;
		cout << "Seats number: " << seats_number << endl;
		cout << "Max of passengers: " << max_passengers << endl;
		cout << "Number of passengers: " << passengers_counter << endl;
	}
	void AddPassenger() {

		if (passengers_counter < max_passengers)
		{
			passengers_counter++;
		}
		else {
			cout << "The carriage is full!" << endl;
		}
	}
	bool Is_Full() {

		if (passengers_counter < max_passengers)
		{
			return false;
		}
		else {
			return true;
		}
	}
};

class Train {

	string model;
	int carriages;
	Vagon* vagon;

public:

	Train()
	{
		model = "None";
		carriages = 0;
		vagon = new Vagon[carriages];
	}
	Train(string model)
	{
		this->model = model;
		carriages = 0;
		vagon = new Vagon[carriages];
	}
	Train(string model, int carriages)
	{
		this->model = model;
		this->carriages = carriages;
		vagon = new Vagon[carriages];
		
		for (int i = 0; i < carriages; i++)
		{
			vagon[i].CreateCarriage();
		}
	}
	Train(const Train& other)
	{
		this->model = other.model;
		this->carriages = other.carriages;
		this->vagon = new Vagon[other.carriages];
		for (int i = 0; i < carriages; i++)
		{
			vagon[i] = other.vagon[i];
		}
	}

	void AddCarriage() {

		Vagon* temp = new Vagon[carriages + 1];

		for (int i = 0; i < carriages; i++)
		{
			temp[i] = vagon[i];
		}

		temp[carriages].CreateCarriage();

		delete[]vagon;
		vagon = temp;
		carriages++;
	}

	void Show() {

		cout << "Model: " << model << endl;
		cout << "Carriages: " << carriages << endl;
		for (int i = 0; i < carriages; i++)
		{
			vagon[i].Show();
		}
	}

	void AddPassengerToAnyCarriage() {

		bool is_added = false;

		for (int i = 0; i < carriages; i++)
		{
			if (vagon[i].Is_Full() == false) {

				vagon[i].AddPassenger(); 
				is_added = true;
				break;
			}
		}

		if (is_added == false){

			cout << "All carriages is full!" << endl;
		}
		else {
			cout << "Successed!" << endl;
		}
	}

	void AddPassengerToConcreteCarriage(int carriage_number) {

		for (int i = 0; i < carriages; i++)
		{
			if (vagon[i].carriage_number == carriage_number) {

				vagon[i].AddPassenger();
				break;
			}
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

void main() {

	/*
		Для масиву вагонів створити окрему структуру
			з наступними полями :
		struct Vagon
			номер вагону
			кількість місць
			кількість пасажирів

		class Train
			Створити клас Потяг.
				У класі оголосити поля(змінні члени класу) :
				модель
				кількість вагонів
				вказівник на масив вагонів(динамічний).Vagon* vagon;

			В класі потяг оголосити дефолтний конструктор
				і перезавантажений конструктор.
				Реалізувати метод Show()
				Реалізувати метод додавання вагону до динамічного масиву
				Реалізувати метод - додати 1 пасажира у вагон
				Реалізувати конструктор копіювання
	*/


	/*cout << "With model train: " << endl;
	Train first{ "AS22366736" };
	first.Show();
	cout << "\nAddCarriage: " << endl;

	first.AddCarriage();
	cout << "---------RESULT---------" << endl;
	first.Show();

	cout << "\nAddPassengerToAnyCarriage: " << endl;

	first.AddPassengerToAnyCarriage();
	cout << "---------RESULT---------" << endl;
	first.Show();

	cout << endl << endl;*/



	cout << "CREATE SECOND TRAIN: " << endl;
	Train second{ "OOOOO3345622", 2 };
	cout << "---------SHOW---------" << endl;
	second.Show();

	cout << "\nCreate new carriage: " << endl;
	second.AddCarriage();
	cout << "---------RESULT---------" << endl;
	second.Show();

	cout << "\nAdd passenger to concrete carriage: " << endl;
	int carriage_number;
	cout << "Enter carriage number: "; cin >> carriage_number;
	second.AddPassengerToConcreteCarriage(carriage_number);
	cout << "---------RESULT---------" << endl;
	second.Show();




	cout << "SECOND TRAIN VAGON[] "; second.VagonAddress();

	cout << endl << endl;

	cout << "COPY OF SECOND TRAIN: " << endl;
	Train copySecond{ second };
	cout << "---------RESULT---------" << endl;
	copySecond.Show();
	cout << "COPY OF SECOND TRAIN VAGON[] "; copySecond.VagonAddress();
}