#include <iostream>
#include <vector>
#include <ostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string FILENAME = "Data.txt";

template<typename T>
ostream& operator << (ostream& out, vector<T> v)
{
	for (int item : v)
	{
		out << setw(3) << item << "  ";
	}
	out << endl;
	return out;
}

struct Time
{
	int h, m, s;

	Time()
	{
		h = 0; m = 0; s = 0;
	}
	Time(int h, int m, int s)
	{
		this->h = h; this->m = m; this->s = s;
	}

	bool operator == (Time temp)
	{
		if (this->h == temp.h && this->m == temp.m && this->s == temp.s)
		{
			return true;
		}
		return false;
	}
	bool operator > (Time temp)
	{
		if (this->h > temp.h)
		{
			return true;
		}
		if (this->h == temp.h && this->m > temp.m)
		{
			return true;
		}
		if (this->h == temp.h && this->m == temp.m && this->s > temp.s)
		{
			return true;
		}
		return false;
	}
	bool operator < (Time temp)
	{
		if (this->h < temp.h)
		{
			return true;
		}
		if (this->h == temp.h && this->m < temp.m)
		{
			return true;
		}
		if (this->h == temp.h && this->m == temp.m && this->s < temp.s)
		{
			return true;
		}
		return false;
	}
};
ostream& operator << (ostream& out, Time t)
{
	cout << t.h << ":" << t.m << ":" << t.s;
	return out;
}

class Train
{
	int number;
	Time departureTime;
	string destination;

public:

	Train() : number(0), departureTime(), destination("none") {}
	Train(int number, Time departureTime, string destination) : number(number), departureTime(departureTime), destination(destination) {}
	Train(int number, int h, int m, int s, string destination) : number(number), departureTime(h, m, s), destination(destination) {}

	void Print()
	{
		cout << "Train number: " << number << endl;
		cout << "Departure time: " << departureTime << endl;
		cout << "Destination: " << destination << endl;
	}

	int GetNumber()
	{
		return number;
	}
	Time GetDepartureTime()
	{
		return departureTime;
	}
	int GetHours()
	{
		return departureTime.h;
	}
	int GetMinutes()
	{
		return departureTime.m;
	}
	int GetSeconds()
	{
		return departureTime.s;
	}
	string GetDestination()
	{
		return destination;
	}

	void SetNumber(int number)
	{
		this->number = number;
	}
	void SetDepartureTime(Time GetDepartureTime)
	{
		this->departureTime = departureTime;
	}
	void SetDepartureTime(int h, int m)
	{
		this->departureTime.h = h;
		this->departureTime.m = m;
	}
	void SetDepartureTime(int h)
	{
		this->departureTime.h = h;
	}
	void SetDestination(string destination)
	{
		this->destination = destination;
	}
};
class Railway
{
	vector<Train> trains;

public:

	void Print()
	{
		for (int i = 0; i < trains.size(); i++)
		{
			trains[i].Print(); 
			cout << "  -   -   -   -   -   -   -   -   -  " << endl;
		}
	}
	void Print(int number)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].GetNumber() == number)
			{
				trains[i].Print();
				cout << "  -   -   -   -   -   -   -   -   -  " << endl;
			}
		}
	}
	void Print(Time time) 
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].GetDepartureTime() == time)
			{
				trains[i].Print();
			}
		}
	}
	void Print(string destination)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].GetDestination() == destination)
			{
				trains[i].Print();
			}
		}
	}

	void SetTime(int number, Time time)
	{
		trains[number].SetDepartureTime(time);
	}
	void SetTime(int number, int h, int m)
	{
		trains[number].SetDepartureTime(h, m);
	}
	void SetTime(int number, int h)
	{
		trains[number].SetDepartureTime(h);
	}

	void SortByDepartureTime()
	{
		for (int i = 0; i < trains.size() - 1; i++)
		{
			if (trains[i].GetDepartureTime() < trains[i + 1].GetDepartureTime())
			{
				swap(trains[i], trains[i + 1]);
			}
		}
	}

	void AddTrain(Train train)
	{
		trains.push_back(train);
	}
	void DeleteTrain(int number)
	{
		for (int i = 0; i < trains.size(); i++)
		{
			if (trains[i].GetNumber() == number)
			{
				trains.erase(trains.begin() + i, trains.end() - i - 1);
			}
		}
	}
	void DeleteLastTrain()
	{
		trains.pop_back();
	}
	void DeleteFirstTrain()
	{
		trains.erase(trains.begin());
	}

	void ToFile()
	{
		ofstream outputFile(FILENAME);

		if (!outputFile.is_open())
		{
			cout << "Can't open file: " << FILENAME << endl;
			return;
		}

		for (int i = 0; i < trains.size(); i++)
		{
			outputFile << trains[i].GetNumber() << endl;
			outputFile << trains[i].GetHours() << endl;
			outputFile << trains[i].GetMinutes() << endl;
			outputFile << trains[i].GetSeconds() << endl;
			outputFile << trains[i].GetDestination() << endl;
			outputFile << "|" << endl;
		}

		outputFile.close();
	}
	void FromFile()
	{
		ifstream inputFile(FILENAME);

		if (!inputFile.is_open())
		{
			cout << "Can't open file: " << FILENAME << endl;
			return;
		}

		string number, hours, minutes, seconds, station, endtrain;
		int n, h, m, s;

		int i = 0;

		while (!inputFile.eof())
		{
			if (i == 4)
			{
				cout << "";
			}
			getline(inputFile, number);
			if (number.empty())
				break;
			n = stoi(number);
			getline(inputFile, hours); h = stoi(hours);
			getline(inputFile, minutes); m = stoi(minutes);
			getline(inputFile, seconds); s = stoi(seconds);
			getline(inputFile, station);
			getline(inputFile, endtrain);
			
			i++;

			Train train(n, h, m, s, station);
			trains.push_back(train);
		}

		inputFile.close();
	}
};

void main()
{
	/*vector<int> vctr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << vctr;*/

	/*vctr.erase((vctr.begin() + 2), (vctr.end() - 2));
	vctr.erase(vctr.end() - 1);
	cout << vctr;*/

	/*vctr.insert(vctr.end(), { 10, 10, 10, 10, 10 });*/
	/*for (int i = 0; i < 10; i++)
	{
		if (i == 4)
		{
			vctr.erase(vctr.begin() + i, vctr.end() - i - 1);
		}
	}
	cout << vctr;*/


	/*				STL Containers.vector
						Завдання :
	Написати програму «Автоматизована інформаційна система залізничного вокзалу».
		
	Система містить : відомості про відправлення потягів далекого прямування.

		Для кожного потяга вказуємо :
				номер;
				час відправлення;
				станцію призначення.

		Забезпечити наступний функціонал :
				Додати потяг в систему;
				Виведення інформації по всіх потягах;
				Виведення інформації по конкретному потяга(по номеру) -> (trains[i].getNumber() == number;)
				Відредагувати час відправлення потяга(по номеру);
				Відсортувати список потягів по часу відправлення; *****
				Показати список потягів по станції призначення;
				 Записати список в файл;
				 Зчитати список з файлу.

	Використовувати контейнерний клас vector.
	Для запису / читання потяга з файла перевантажити оператори << >>*/


	/*Railway trains;
	trains.FromFile();
	trains.Print();*/
}